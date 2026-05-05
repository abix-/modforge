# Better Backpack performance audit

Audit of `dllmain.cpp` after the codex fixes that made the mod functional. The
mod works; the question is what it costs us per frame and where the fat is.

This doc is observation only. No code changes here -- those come after we agree
on what to cut.

## TL;DR

The hot path is `HookedInventoryInterfaceProcessEvent`. It runs on every
`ProcessEvent` call for any widget in 10 hooked classes -- including the very
generic `Widget`, `UserWidget`, `GameUserWidget`, `PanelWidget`, `GridPanel`,
and `WidgetManager`. That covers essentially the whole UMG tree. Every one of
those calls today does:

- linear scan over the 10-entry hook table (cheap, fine)
- one or more `obj->IsA(...)` virtual chain walks
- `obj->GetFullName()` -- heap-allocated `std::string`
- `function->GetName()` -- heap-allocated `std::string`
- `IsInventoryRelatedObjectName(...)` -- another `GetFullName()` plus 4 `find()`s
- conditional `Log(...)` calls that allocate a 4 KB stack buffer, format,
  fwrite + fflush to console + log file

All trace flags default to **on**. So even when the player isn't doing
anything, we're allocating + formatting + writing to disk on every UI
ProcessEvent dispatch. That is the perf smell.

## Hot path: per-call cost in `HookedInventoryInterfaceProcessEvent`

`dllmain.cpp:842-957`. Order of operations on every call:

1. `FindOriginalProcessEventForObject(obj)` -- linear scan, 10 vtable compares.
   Fine.
2. Reads vtable via `*reinterpret_cast<void***>(obj)`. Fine.
3. Branch `if (!g_inInvIfaceHook && !g_inSyntheticInventoryRefresh && obj && function)`.
4. Inside that branch, **unconditionally**:
   - `function->GetName()` -> `std::string fnName` (heap alloc)
   - `obj->IsA(invIfaceClass)` walk
   - `obj->IsA(inventoryBpfClass)` walk
   - `obj->GetFullName()` -> `std::string objName` (heap alloc), used by the
     panel/grid trace path
   - `obj->IsA(gridPanelClass)` walk
   - `obj->IsA(panelWidgetClass)` walk
   - `obj->IsA(widgetManagerClass)` walk
   - `obj->IsA(inGameMenuWidgetClass)` walk
   - `obj->IsA(invIfaceClass)` walk (a second time, in the menu trace block)
   - `IsInventoryRelatedObjectName(objName)` -> 4 `string::find` calls
5. Calls `original(obj, function, parms)`.
6. Post-call: another `obj->IsA(invIfaceClass)` walk, another
   `function->GetName()` allocation, then a chain of `fnName == "..."` string
   compares.

**Estimate.** Even with all trace gating returning false, every
`ProcessEvent` dispatch through a hooked vtable pays ~7 IsA walks + 2 string
allocs + 4 substring searches. If UMG is doing thousands of ProcessEvent
dispatches per frame (likely on a busy HUD), this is real time.

## Hot path: hook surface is too broad

`g_processEventHooks` (`dllmain.cpp:132-143`) hooks the CDOs of:

- `Widget`, `UserWidget`, `GameUserWidget` -- base classes of literally every
  UMG widget in the game
- `InventoryWidget`, `WBP_InventoryInterface_C`, `InGameMenuWidget` -- target
  classes (these we actually need)
- `WidgetManager`, `PanelWidget`, `GridPanel` -- generic containers, hit by
  every panel in every screen
- `BPF_InventoryFunctions_C` -- BP function library, fine

In Unreal, vtable patching at the CDO level affects every C++-level instance
that shares the same C++ vtable. Hooking `UWidget`'s ProcessEvent therefore
intercepts ProcessEvent for every UWidget-derived object in the process,
unless the subclass introduces its own override (rare for ProcessEvent).

Net effect: we are running our hook for the entire UI, not just inventory.

## Logging is unconditional

`g_invIfaceMethodTraceEnabled`, `g_inventoryGridTraceEnabled`,
`g_inventoryBpfTraceEnabled`, `g_inventoryMenuTraceEnabled` all default to
**true** (`dllmain.cpp:148-151`). There is no runtime toggle and no compile
flag.

Every `Log(...)` call:

- `GetLocalTime` syscall
- `sprintf_s` + `vsnprintf` against a 4 KB stack buffer
- `fwrite` + `fflush` to stdout (console)
- `fwrite` + `fflush` to disk file

`fflush` after every line means the disk write isn't buffered. On the busy
trace paths inside the inventory UI hooks, this is the dominant cost.

`scroll debug ...` log lines in `RebindInventoryViewport`,
`RebindInventoryViewportByAbsoluteSlots`, and the OnMouseWheel post-hook are
all useful when developing but redundant in a shipped build.

## Rescan loop

`DiagnosticLoop` (`dllmain.cpp:1106-1170`) sleeps `kRescanInterval` (10s) and
then:

1. `ScanInventoryComponents()` -- walks **all** of `GObjects` (typically 100k+
   entries mid-game), calling `IsA(invClass)` on each, plus `GetFullName()` on
   matches.
2. Re-patches any reverted player main-backpack components.
3. If hook surfaces aren't fully installed, retries install.
4. `InspectLiveInventoryUiState()` -- walks **all** of GObjects again twice
   (once for `WBP_InventoryInterface_C` instances, once for `WidgetManager`
   instances). For each match, calls `TryGetPanelChildrenCount` /
   `TryGetPanelChildAt`, which call `ProcessEvent` on the panel and therefore
   re-enter our own hook (guarded by `g_inInvIfaceHook`).

10s cadence is fine for the patch verification, but `InspectLiveInventoryUiState`
runs the same expensive walk every time even if nothing changed. The
`g_lastInventoryWidgetInspection` / `g_lastWidgetManagerInspection` strings
suppress *logging* of unchanged state, but the walk still happens.

## Memory leak: viewport-start map

`g_inventoryViewportStart` (`dllmain.cpp:156`) is a
`std::unordered_map<const SDK::UObject*, int32_t>`. It's keyed by raw widget
pointer and never pruned. Every time a player opens the inventory the engine
may construct a fresh `WBP_InventoryInterface_C` instance; entries accumulate
forever. The map itself is small (8 + 4 bytes per entry plus hash overhead),
so this is a slow leak, not a frame killer, but it grows for the lifetime of
the process.

There is also no synchronization on this map. The hook runs on the game
thread (UMG dispatch). The rescan worker thread doesn't touch it, so today
we're safe -- but anything we add on the worker side later needs to remember
this.

## Other observations

- `kInvIfaceItemGridOffset = 0x0430` and `kWidgetManagerWindowStackOffset =
  0x0050` are SDK-version dependent. If we ever rebuild the SDK against a
  patched game, these silently shift. Not a perf issue but a correctness
  landmine worth noting.
- `g_widgetProbeDumped` ensures the diagnostic class-name dump only runs once.
  Good.
- `EnsureInventoryInterfaceHookInstalled` correctly sets
  `g_processEventHooksInstalled` only when **all** surfaces are installed,
  but logs success on each individual hook installation. That's noisy on
  startup but not a perf problem.
- The post-call rebind block (`dllmain.cpp:902-952`) re-acquires
  `invIfaceClass` and re-tests `obj->IsA(invIfaceClass)` even though the
  pre-call block already did. Cheap to fix.

## Recommended changes (in priority order)

Not done yet -- listing for review.

1. **Default all trace flags off.** Single biggest win. Keep the flags as
   compile-time `constexpr bool` or a runtime env-var toggle so we can turn
   them back on for debugging without rebuilding.
2. **Early-out the hook on the common case.** First check: is `obj->IsA` of
   any of the *target* classes (invIface, invBpf, the inventory grid, the
   menu)? If not, skip every other branch and return after calling the
   original. Avoid the `GetName`/`GetFullName` allocations entirely on the
   non-matching path.
3. **Drop the generic hook surfaces** unless we actually need them. `Widget`,
   `UserWidget`, `GameUserWidget`, `PanelWidget`, `GridPanel`, `WidgetManager`
   -- if they're only providing trace coverage for development, ship without
   them. Keep `WBP_InventoryInterface_C`, `BPF_InventoryFunctions_C`, and the
   menu widget if those are required for behavior.
4. **Compare `UFunction*` identity instead of names.** Cache the
   `UFunction*` for each function we care about (PopulateItemGrid,
   OnMouseWheel, OnInventoryChanged, RefreshUI, RefreshMenuPage,
   OnInventoryCountChanged) once at hook install. Then a single pointer
   compare replaces every `fnName == "..."` chain plus its `GetName()`
   allocation.
5. **Stop running `InspectLiveInventoryUiState` on every rescan.** Only run
   it once on first successful hook install, or behind a debug flag.
6. **Prune `g_inventoryViewportStart`** -- either on a `Construct` /
   `Destruct` boundary, or by walking it on rescan and dropping entries whose
   key is no longer in `GObjects` / no longer an `InventoryInterface`.
7. **Consider raising `kRescanInterval`** to 30s once we're confident the
   patch sticks. The fast cadence was useful while we were verifying writes
   weren't being clobbered; it's overkill now.
8. **Buffer log writes.** If we keep any logging in the hot path, drop the
   per-line `fflush`. Flush periodically from the worker thread, or on
   process detach.

## Confidence

Audit confidence: 8/10. I read the whole file; the hot-path analysis follows
from the code. The "ProcessEvent hook fires for the whole UMG tree" claim
depends on the C++ vtable layout the SDK assumes -- it's the standard Unreal
shape but I have not verified it against this specific build's binary.
