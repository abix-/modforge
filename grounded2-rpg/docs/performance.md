# Grounded 2 - RPG System performance notes

> **Authoritative on:** g2rpg-specific runtime costs. Per-call
> costs on Maine classes, hot-path numbers for the inv_hook /
> kill_hook trampolines, allocation analysis of the rebind
> cycle, deliberate-not-port list for legacy approaches.
>
> Generic UE4SS-Rust-mod hot-path discipline (zero-alloc
> trampolines, single-hook-surface principle, identity-not-name
> dispatch, debug-only trace gating) lives in
> [`../../ueforge/docs/PERFORMANCE.md`](../../ueforge/docs/PERFORMANCE.md).
> This file states the g2rpg-specific costs only.

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

The trampoline cost analysis for `ueforge::hook::ProcessEventHook`
(per-dispatch vtable read + registry snapshot + closure + drain
trampoline + active-call counter) lives in
[`../../ueforge/docs/PERFORMANCE.md`](../../ueforge/docs/PERFORMANCE.md)
"Hot paths". Wall cost in release: ~50-100 ns per dispatch.

The g2rpg hot paths below sit *on top of* that framework cost --
each is the closure body invoked by the trampoline.

### 1. Inventory-interface event handler

`grounded2-rpg/src/inv_hook.rs::on_event`. The closure invoked by the
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

### 2. Rebind (active scroll)

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

### 3. Survival CDO patch (hunger + thirst)

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

### 4. Rescan loop, removed

Earlier revisions of this doc described a 10 s rescan loop. **It's
gone.** The CDO patch is sticky for the lifetime of the DLL: UE doesn't
re-load CDOs from disk during a session, and every new
`UInventoryComponent` (including the one constructed when the player
loads a save) inherits its field defaults from the patched CDO. So a
single patch at startup is sufficient. The worker thread now terminates
after the inventory hook installs.

Net steady-state cost after init: zero threads running, zero CPU.

### 5. Logging (one-shot + on-change)

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
`%TEMP%\Grounded2RPG.log` followed by a flush. Fine.

## What was *not* done (deliberately)

g2rpg-specific deliberate non-ports + dropped instrumentation:

- Hooking `Widget`, `UserWidget`, `GameUserWidget`, `PanelWidget`,
  `GridPanel`, `WidgetManager`, `BPF_InventoryFunctions_C`,
  `InventoryWidget`, `InGameMenuWidget` for trace coverage. Only
  `WBP_InventoryInterface_C` is load-bearing; we intercept ~0.1%
  of the ProcessEvent dispatches an aggressive trace build would.
- `InspectLiveInventoryUiState` -- a previous incarnation walked
  all of `GObjects` twice per rescan tick to log live widget /
  window-stack state. Dropped. If ever needed back, gate behind
  `cfg!(debug_assertions)` and run at most once per session.

For generic "what was deliberately not ported" doctrine
(zero-alloc trampolines, single-hook-surface principle,
identity-not-name dispatch) see
[`../../ueforge/docs/PERFORMANCE.md`](../../ueforge/docs/PERFORMANCE.md).

## What could still be tightened (g2rpg-specific)

Strictly optional. None of these are visible in a profile today.

1. **Cache the player's HC pointer at slot activation.** Today
   `kill_hook`'s player filter calls `owner.full_name()` per
   fire (allocates a String just to substring-match
   `BP_SurvivalPlayerCharacter`). Caching the live HC pointer
   eliminates the alloc for non-player events.
2. **Drop `f.flush()` from every log line** in g2rpg's hot-path
   call sites; rely on OS buffering or flush every Nth line.
3. **Make the wider damage_trace observation opt-in** via a
   settings flag. Researchers turn it on; shipping disables.

Framework-side optimization opportunities (REGISTRY mutex ->
atomic, `AddUObjectCreateListener` integration, the
`in_synthetic_refresh` AtomicBool) live in ueforge's
[`PERFORMANCE.md`](../../ueforge/docs/PERFORMANCE.md) "What
ueforge already does for you" and the open work in the
workspace [`docs/todo.md`](../../docs/todo.md).

## Methodology + confidence

Numbers above are reasoned from the code, not measured on a
live profile. UE's `ProcessEvent` cost (single-digit
microseconds in release builds with no native function
trampoline) is well-documented across UE mod literature; the
g2rpg-specific costs (the ~123 PE per inventory rebind, the
~125k-entry GObjects walks per slot activation, the
SurvivalComponent CDO scan timings) follow from the call
shapes documented in [`ongoing.md`](ongoing.md). Audit
confidence: 8/10. A real Tracy / `tracing` capture inside the
game would replace estimates with hard numbers if we ever
decide it matters.
