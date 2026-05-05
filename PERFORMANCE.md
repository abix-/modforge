# Better Backpack performance notes (Rust)

Companion to `better-backpack-cpp/PERFORMANCE_AUDIT.md`, which catalogued
the issues we set out to fix when porting from C++. This doc states what
the Rust port actually costs to run, where the cost lives, and what could
still be tightened.

## TL;DR

In a normal play session this mod is invisible to a frame profile. The
ProcessEvent hook fires only on the open inventory widget (not the whole
UMG tree), the worker thread **terminates** once init completes (no
recurring rescan), and release builds compile out all trace logging.
Per-frame overhead at idle is **zero** (no thread, no work);
per-frame overhead with the inventory open is **sub-microsecond**;
worst-case overhead during active mouse-wheel scrolling is
**single-digit ms/sec** of CPU.

The original C++ tree had real perf concerns (broad hook surface,
unconditional logging on every dispatch, string allocations per call).
None of those carried over.

## Hot paths

### 1. ProcessEvent hook trampoline

`better-backpack/src/hook/process_event.rs::trampoline`. Fires whenever
the engine invokes `ProcessEvent` on an instance whose vtable matches one
of our installed hooks. Today that means **only**
`WBP_InventoryInterface_C`. A blueprint-generated widget that's only
present in `GObjects` while the inventory UI is open.

Per-call cost:

- one vtable read off `this` (8 bytes)
- `REGISTRY.lock()`, `Mutex` lock, uncontended (game thread only)
- linear scan over registry (currently 1 entry)
- pointer copy of the `Entry`, drop the lock
- `catch_unwind` around the user closure
- the closure itself: see (2) below
- on closure panic, fallthrough to engine original

Estimated wall cost in release: **~50-100 ns** per dispatch, dominated
by the mutex lock-unlock cycle (~10-20 ns x2) and the closure work.

### 2. Inventory-interface event handler

`better-backpack/src/inv_hook.rs::on_event`. The closure invoked by the
trampoline.

Per-call cost:

- second `Mutex` lock for `in_synthetic_refresh` (early-out path)
- one `usize` cast on the `&UFunction`
- 1-2 cached pointer-identity compares against `Construct`,
  `OnMouseWheel`, etc.
- dispatch to engine original via `original.call(...)`
- post-call: same identity check pattern; on a match, calls `rebind` or
  similar handler

The function-identity dispatch replaces what the C++ build did with
runtime `fn_name == "..."` string compares, one of the audit's named
issues.

### 3. Rebind (active scroll)

`inv_hook.rs::rebind`. Triggered by mouse-wheel ticks and post-refresh
events. Walks the visible 40-slot grid and rebinds each slot against an
absolute item index.

Per rebind:

- 1 field read for `ItemGrid` pointer
- 1 ProcessEvent for `PanelWidget::GetChildrenCount`
- 1 ProcessEvent for `WBP_InventoryInterface_C::GetInventoryItems`
- 40 iterations, each with:
  - 1 ProcessEvent for `PanelWidget::GetChildAt`
  - 1 ProcessEvent for `BPF_InventoryFunctions_C::GetItemInItemListSlot`
  - 1 ProcessEvent for `WBP_InventoryInterface_C::InitializeItemSlot`

Total: **~123 ProcessEvent calls per rebind**. UE's `ProcessEvent` is
single-digit microseconds, so a rebind takes **roughly 0.5-1 ms**.

Mouse-wheel ticks fire ~5-10 per second during continuous scrolling. So
worst-case scroll cost is **~5-10 ms/sec of CPU**, on the game thread,
during active scrolling only. Well under one frame at 60 fps; below
sample resolution at 144 fps.

### 4. Survival CDO patch (hunger + thirst)

`survival.rs::run`. One-shot at startup, same shape as the inventory
patch. Walks GObjects looking for SurvivalComponent-derived CDOs and
multiplies two `f32` fields per CDO by the user-configured multipliers.

Per scan:
- iterate every entry in GObjects (~125k)
- per entry: `IsA(SurvivalComponent)`, pointer-compare chain walk,
  typically 2-4 hops
- for the few matching CDOs: read + multiply + write each of two `f32`
  fields, then verify

Estimated wall cost: comparable to the inventory patch, 1-3 ms once
at startup. Runs only if at least one multiplier is `!= 1.0` (skipped
entirely otherwise). Default multipliers ship at `0.5`, so the patch
runs by default.

### 5. Rescan loop, removed

Earlier revisions of this doc described a 10 s rescan loop. **It's
gone.** The CDO patch is sticky for the lifetime of the DLL: UE doesn't
re-load CDOs from disk during a session, and every new
`UInventoryComponent` (including the one constructed when the player
loads a save) inherits its field defaults from the patched CDO. So a
single patch at startup is sufficient. The worker thread now terminates
after the inventory hook installs.

Net steady-state cost after init: zero threads running, zero CPU.

### 5. Logging

Compile-time gating:

- Trace lines in `inv_hook.rs` are wrapped in
  `if cfg!(debug_assertions)`. Release builds drop them at compile
  time, no string formatting, no I/O.
- The startup banner (image base, GObjects count, initial patch) and
  the rescan-found-something path are unconditional but fire **once at
  startup** and **only when something changes** respectively.
- The C++ tree's "log on every hook call" pattern was deliberately
  not ported.

Steady-state log volume in release: zero per frame, zero per second.

When something is logged: one syscall to `WriteConsoleA` against the
spawned debug console, one buffered file write to
`%TEMP%\BetterBackpack.log` followed by a flush. Fine.

## What was *not* done (deliberately)

These were identified in the C++ audit and dropped in the port rather
than ported with fixes:

- Hooking `Widget`, `UserWidget`, `GameUserWidget`, `PanelWidget`,
  `GridPanel`, `WidgetManager`, `BPF_InventoryFunctions_C`,
  `InventoryWidget`, `InGameMenuWidget`. The C++ tree installed
  ProcessEvent hooks on all of these for trace coverage. Nine of them
  exist solely as instrumentation; only `WBP_InventoryInterface_C` is
  load-bearing for the mod's actual behavior. Net effect: the Rust port
  intercepts roughly **0.1%** of the ProcessEvent dispatches the C++
  build did.
- `InspectLiveInventoryUiState`, the C++ tree walked all of `GObjects`
  twice per rescan tick to log live widget / window-stack state. We
  dropped it. If we ever need it back, gate it behind
  `cfg!(debug_assertions)` and run it at most once per session.
- The `g_inventoryViewportStart` `unordered_map<const UObject*, int>`
  in C++ was an unbounded leak, it grew for every widget the player
  ever opened. Rust uses a `Vec<(usize, i32)>` keyed by widget pointer
  and never prunes it either, but the leak is the same shape and the
  growth rate is bounded by how many distinct widget instances the
  player constructs in a session. In practice: a few dozen entries
  total. **Not** a problem in steady state but a tidy-up target if a
  session ever held thousands of distinct inventory widget instances.

## What could still be tightened

Strictly optional. None of these are visible in a profile today.

1. **Replace the two `Mutex` locks on the hot path with atomics.**
   `REGISTRY` could be an immutable `&'static [&'static Entry]` written
   once at startup; `in_synthetic_refresh` could be an
   `AtomicBool` (or even thread-local since the hook is single-threaded
   in practice). Saves ~20-40 ns per dispatch. Worth doing only if a
   profile ever puts the mutex on the radar.
2. **Cache `&UClass` for `InventoryComponent` once at startup**, so
   `patch::run` skips the `find_class_fast` call on every rescan. Today
   the function caches the result internally via `OnceLock` on the
   class pointer (`g_invClass` style), but the lookup walks `GObjects`
   the first time. We do that walk on the first rescan only; subsequent
   rescans use the cached pointer. Already optimal.
3. **(done)** AllocConsole is now gated behind the `console` Cargo
   feature (default on). `cargo build --release --no-default-features`
   produces a console-free shipping DLL.
4. **Add `FUObjectArray::AddUObjectCreateListener` integration** if a
   real CDO-revert scenario is ever observed in a play session. Today
   we patch once and exit; if a Blueprint hot-reload or replication
   path ever wipes the CDO, we'd silently miss it. The fix is the
   canonical UE4SS pattern, register a listener, filter by class
   pointer, defer a re-patch one tick. ~100 lines of work; not
   warranted unless the failure is observed.

## Methodology

These numbers are reasoned from the code, not measured on a live
profile. UE's `ProcessEvent` cost (single-digit microseconds in release
builds with no native function trampoline) is well-documented across UE
mod literature; the rest is straight pointer arithmetic and mutex
overhead, both well-known constants. A real Tracy / `tracing` capture
inside the game would replace the estimates with hard numbers if we
ever decide it matters.

## Confidence

Audit confidence: 8/10. The hot-path analysis follows directly from the
code; the dispatch volume reasoning follows from how the inventory
widget is used in-game. The unmeasured pieces are (a) actual
`ProcessEvent` cost in this specific build of UE 5.4 and (b) how often
the inventory UI dispatches per frame on a typical machine. Both are
the same order of magnitude as well-known UE benchmarks, but we have
not measured them ourselves.
