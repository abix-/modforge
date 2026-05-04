# TODO

## Scrollable backpack viewport

Goal: keep the bigger backpack capacity patch, but stop growing the visible inventory to 6 rows. Instead, keep the inventory UI at a fixed 4x10 viewport and let the player scroll through the extra slots.

What is already known:

- The data-side capacity patch is still the right foundation:
  - `UInventoryComponent.DefaultMaxSize` at `0x01E0`
  - the DLL already patches player-owned inventories from 40 to `kSlotCount`
- The visible player inventory in this build is driven by `WBP_InventoryInterface_C`, not by directly patching arbitrary `UI_InventoryGrid_C` instances.
- `WBP_InventoryInterface_C` has:
  - `ItemGrid : UGridPanel*`
  - `OnMouseWheel(...)`
  - `PopulateItemGrid(int32 RowMax, int32 ColumnMax)`
  - `GetInventoryItems()`
  - `GetSelectedInventorySlotIndex()`
  - `SetSelectedInventorySlot(int32)`
- `BPF_InventoryFunctions_C::RefreshInventoryGrid(...)` and `PopulateInventoryGrid(...)` both support an explicit `ItemStartIndex`, which is the key primitive needed for virtual scrolling/paging.
- There is no reflected `UScrollBox` on `WBP_InventoryInterface_C`; v1 should treat this as a paged/virtualized 4x10 grid, not a literal Slate `ScrollBox` retrofit.
- The SDK already exposes the `ProcessEvent` vtable index in `Basic.hpp`, so a narrow `ProcessEvent` hook is feasible without adding MinHook or another dependency.
- The current `dllmain.cpp` intentionally avoids compiling large generated SDK translation units, so the implementation should continue using reflective `ProcessEvent` calls plus small local param structs.

Recommended v1 behavior:

- Keep total capacity at 60.
- Keep the visible viewport at vanilla height:
  - `kViewportRows = 4`
  - `kViewportColumns = 10`
  - visible page size = 40 slots
- Mouse wheel only for v1.
- One wheel notch moves one row:
  - 10 slots per step
- No on-screen scrollbar or page indicator in v1.
- Reset scroll offset when a fresh inventory widget is constructed/opened.

Implementation sketch:

1. Remove the current visible-side expansion behavior that forces six visible rows or relies on `UI_InventoryGrid_C.MaxRows` growth for the player inventory.
2. Keep the inventory capacity patch unchanged.
3. Add per-widget scroll state keyed by `UWBP_InventoryInterface_C*`:
   - `item_start_index`
   - `initialized`
   - optionally `last_selected_absolute_slot`
4. Hook `ProcessEvent` for `WBP_InventoryInterface_C` instances by patching the class vtable slot at `Offsets::ProcessEventIdx`.
5. Intercept `OnMouseWheel`:
   - call the original handler first
   - if the inventory widget is visible and slot count exceeds 40, adjust `item_start_index` by `+/-10`
   - clamp to valid bounds so the last slots remain reachable
   - call `GetInventoryItems()`
   - call `BPF_InventoryFunctions_C::RefreshInventoryGrid(ItemList, ItemGrid, 4, 10, item_start_index, this)`
6. Intercept `PopulateItemGrid`:
   - let the original build the normal grid
   - if `item_start_index != 0`, immediately reapply `RefreshInventoryGrid(...)` so inventory refreshes do not snap back to page 0
7. Preserve selection/focus across page changes:
   - read current visible selection with `GetSelectedInventorySlotIndex()`
   - translate to absolute slot index using the previous `item_start_index`
   - after refresh, if still visible, restore with `SetSelectedInventorySlot(relative_index)`
   - otherwise clamp to the nearest visible slot
8. Add a recursion/reentry guard so reflective calls made inside the hook do not recurse through the same hook path.

Open questions for later implementation:

- Does `OnMouseWheel` already consume wheel input for another purpose in the vanilla inventory? If yes, confirm the post-original refresh does not fight built-in behavior.
- Should the last page clamp to strict row boundaries or allow a partial final offset so slots 51-60 can sit at the bottom naturally? Default recommendation: allow the partial final offset if needed to guarantee the last slots are visible.
- Should keyboard/gamepad paging be added later through `OnKeyDown` / `OnAnalogValueChanged`? Not for v1.

Acceptance criteria when implemented:

- Inventory still has 60 total usable slots.
- Visible inventory remains 4 rows x 10 columns.
- Mouse wheel scrolls through the hidden slots in 10-slot increments.
- Slots 41-60 are reachable, clickable, draggable, and persist as before.
- Inventory refreshes caused by item movement or count changes do not reset the viewport to page 0.
- No duplicate slot widgets, no repeated grid growth, and no obvious flicker while scrolling.

### Current blocker: safe visible-side refresh / 6-row display

This is the immediate prerequisite work before the scroll viewport plan can be finished cleanly.

What has been verified:

- Data-side patch works reliably:
  - log shows player `InventoryComponent` instances patched `40 -> 60`
  - extra capacity exists in memory
- SDK-backed widget facts:
  - `WBP_InventoryInterface_C` is the player inventory widget and inherits from native `UInventoryWidget`
  - `WBP_InventoryInterface_C` directly owns `ItemGrid : UGridPanel*`
  - there is no reflected `UScrollBox` field on this widget
  - `PopulateItemGrid(int32 RowMax, int32 ColumnMax)` is a real reflected method on the widget
  - `BPF_InventoryFunctions_C::RefreshInventoryGrid(...)` and `PopulateInventoryGrid(...)` explicitly take `ItemStartIndex`, `RowMax`, `ColumnMax`, and `GridPanel`
  - `UObject::ProcessEvent` is dispatched through the universal SDK vtable slot `Offsets::ProcessEventIdx`
- Current runtime log from a real test now shows:
  - the broadened native widget hook now reaches live instances
  - `widget TRACE WBP_InventoryInterface_C ... Construct`
  - `initial patch round: 3 / 45 components patched`
  - `widget PATCH UI_InventoryGrid_C ... MaxRows: 3 -> 6 (CDO only)`
  - `initial widget patch round: 1 UUI_InventoryGrid_C objects bumped to MaxRows=6`
  - after opening/using inventory, still no `widget HOOK ... PopulateItemGrid(...)->(6, 10)` line
  - after opening/using inventory, no reflected `Populate*` / `Refresh*` / `OnInventoryChanged` path was seen on the live widget; only `Construct`
- Result: capacity patch succeeds, and the broadened native `ProcessEvent` hook does reach live `WBP_InventoryInterface_C` instances. However, the visible inventory redraw path still does not appear as a reflected Blueprint call with the expected method names. Current best conclusion: the real grid rebuild path is native or otherwise bypasses the reflected `ProcessEvent` methods we were targeting.

What has already failed:

- Calling `WBP_InventoryInterface_C::PopulateItemGrid(...)` directly from the DLL worker thread.
  - Visually promising, but it crashed in UMG/material lifecycle code.
  - Conclusion: do not call player inventory UMG rebuild functions from the worker thread.
- Relying on `UI_InventoryGrid_C.MaxRows` CDO patch alone.
  - This is not sufficient to make the live player inventory show 6 rows in the current build.
- First attempt at a `WBP_InventoryInterface_C::ProcessEvent` vtable hook.
  - Build succeeded.
  - Runtime evidence now says the hook *does* install.
  - However, neither `PopulateItemGrid` nor broader widget trace logging fires through that hook during actual inventory usage.
  - New conclusion: class lookup succeeded, but the BP CDO vtable is the wrong observation surface for live instances.
- Broadened native widget-chain `ProcessEvent` hook (`Widget` / `UserWidget` / `GameUserWidget` / `InventoryWidget` / `WBP_InventoryInterface_C`).
  - Build succeeded.
  - Runtime evidence now says live `WBP_InventoryInterface_C` instances do trace through this surface.
  - But the only observed reflected method during inventory open is `Construct`.
  - New conclusion: the inventory redraw/repopulation path is probably native-direct or otherwise not exposed as the reflected `Populate*` / `Refresh*` methods we expected.

Immediate next debugging steps:

1. Keep the broadened widget-chain `ProcessEvent` hook as the verified live-instance observation surface.
2. Stop assuming the redraw path must be a reflected Blueprint method on `WBP_InventoryInterface_C`.
3. Review SDK-native candidates that can rebuild the visible grid without a Blueprint `ProcessEvent` call:
   - `BPF_InventoryFunctions_C::RefreshInventoryGrid(...)`
   - `BPF_InventoryFunctions_C::PopulateInventoryGrid(...)`
   - `UGridPanel` child-management/update path
   - any native inventory/widget helpers adjacent to `UInventoryWidget` / `UWidgetManager` / `WBP_InventoryInterface_C`
4. Identify where the live widget gets its slot children populated after `Construct`, and hook or patch that native path instead of waiting for a reflected `Populate*` call.
5. Once the real redraw path is found, retarget the 6-row rewrite there.
6. After the visible 6-row path is understood, use the already-confirmed `ItemStartIndex` helpers for the later scrollable 4x10 viewport implementation.

Acceptance criteria for this blocker:

- Log shows the hook installation succeeded.
- Opening the inventory produces filtered trace lines from live `WBP_InventoryInterface_C` instances through the broadened native widget hook.
- The real player-inventory redraw path is identified, even if it is native and not a reflected Blueprint method.
- The inventory visibly shows 6 rows without calling UMG rebuilds from the worker thread.
- No `MaterialRenderProxy` / UMG lifecycle crash during inventory open, close, or item movement.

## Player thirst and hunger rate tweaks

Goal: let the user dial down (or off) how fast the player gets hungry and thirsty. Same vehicle as Better Backpack: a runtime patch via the injected DLL.

What we know so far (needs verification against the SDK):

- The hunger/thirst tick logic lives on the player character or a stat component, probably with float properties like `HungerRate`, `ThirstRate`, or modifier curves.
- The `USurvivalCheatManager` exposes `EnableThirstHunger(bool, ASurvivalPlayerCharacter*)` (visible from the SDK research). That toggles the systems off entirely. Useful as a sanity check that we're touching the right systems.
- The actual rate constants are likely on a stat/data component or a settings asset, not the BP itself.

Open questions:

- What's the property name and class for the hunger rate? (Search Dumper-7 SDK for "Hunger" / "Thirst" / "Starve" / "Dehydrate" properties on float types.)
- Are rates stored as scalar multipliers, per-second decay values, or curves (`UCurveFloat`)?
- Is there a single "stat decay multiplier" we can scale, or do we have to patch each stat independently?
- Do these values replicate in multiplayer? (Probably yes, server-authoritative.)

Implementation sketch:

- Add a `kHungerRateScale` / `kThirstRateScale` constant near the top of `dllmain.cpp` (default 1.0 = vanilla; 0.0 = disabled).
- Add a `PatchPlayerStatRates()` function that walks `GObjects` for the relevant stat component class, finds the rate properties (reflective if possible, hard-coded offset if necessary), and scales.
- Re-apply on the existing 10s rescan loop the same way the inventory patch does.
- Expose toggles via the same compile-time constants pattern, no settings.json yet.

Acceptance criteria when implemented:

- With the DLL injected and `kHungerRateScale = 0.5`, the player's hunger meter drops at half the vanilla rate. Empirically verifiable by sitting still in-game and timing the meter.
- With `kHungerRateScale = 0.0`, the meter does not drop at all.
- The other survival systems (temperature, stamina, health regen) are unaffected.
- Multiplayer behaviour documented (probably won't work for non-host clients).
