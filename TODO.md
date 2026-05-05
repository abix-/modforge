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

- Keep total capacity at 100.
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

- Inventory still has 100 total usable slots.
- Visible inventory remains 4 rows x 10 columns.
- Mouse wheel scrolls through the hidden slots in 10-slot increments.
- Slots 41-100 are reachable, clickable, draggable, and persist as before.
- Inventory refreshes caused by item movement or count changes do not reset the viewport to page 0.
- No duplicate slot widgets, no repeated grid growth, and no obvious flicker while scrolling.

Current viability assessment:

- The scroll plan remains viable.
- The scroll plan is now experimentally proven.
- Reason:
  - data-side capacity patch to 100 is already working
  - `WBP_InventoryInterface_C` is confirmed as the player inventory widget
  - the widget directly owns `ItemGrid`
  - `BPF_InventoryFunctions_C::RefreshInventoryGrid(...)` and `PopulateInventoryGrid(...)` both take `ItemStartIndex`
  - live inspection proves the rendered grid is a fixed pool of `40` `UI_ItemSlot_C` children
  - `OnMouseWheel` is now confirmed to fire on the live `WBP_InventoryInterface_C`
  - forced-step proof mode now successfully calls `GetInventoryItems()`, `RefreshInventoryGrid(...)`, and `SetSelectedInventorySlot(...)`
  - runtime log now proves viewport state advances, e.g. `mouse-wheel start=10 -> 20`
- Interpretation:
  - the game already has the core paging/virtualized-grid primitive needed for scrolling
  - the current inventory UI appears to be fixed-pool/rebind based rather than dynamically growing to more visible slots
  - scrolling does not require solving visible 6-row expansion first
  - scrolling only requires one safe game-thread redraw path for rebinding the normal 4x10 viewport at a different `ItemStartIndex`
- Current blocker for implementation:
  - the actual safe native redraw path is still unidentified
  - reflected widget hooks, reflected inventory Blueprint helpers, and reflected `GridPanel` child ops have all failed to expose the live redraw path
- Strategic conclusion:
  - forcing a visible 6-row layout is looking fragile because the live `ItemGrid` is currently built as a `40`-child slot pool
  - the scroll plan is the correct end state
  - rebinding the existing 40 visible slots is confirmed to work
  - the remaining work is slot-semantics correctness, not feasibility

Hard requirement:

- Scrolling must preserve absolute slot positions exactly.
- Scrolling is per row (`+/-10` slots), not per page.
- If an item lives in absolute backpack slot `N`, then whenever the viewport includes slot `N`, that item must appear in the relative position derived from `N - itemStartIndex`:
  - row = `(N - itemStartIndex) / 10`
  - col = `(N - itemStartIndex) % 10`
- Empty slots must remain visibly empty.
- No item may visually compact upward, slide into the first visible slot, or otherwise change relative position merely because the viewport moved.
- Any implementation that scrolls by rows but compacts items through empty slots is not acceptable.

### Current blocker: safe visible-side refresh / 6-row display

This is the immediate prerequisite work before the scroll viewport plan can be finished cleanly.

What has been verified:

- Data-side patch works reliably:
  - log shows player `InventoryComponent` instances patched to target, e.g. `40 -> 100`
  - extra capacity exists in memory
- SDK-backed widget facts:
  - `WBP_InventoryInterface_C` is the player inventory widget and inherits from native `UInventoryWidget`
  - `WBP_InventoryInterface_C` directly owns `ItemGrid : UGridPanel*`
  - there is no reflected `UScrollBox` field on this widget
  - `PopulateItemGrid(int32 RowMax, int32 ColumnMax)` is a real reflected method on the widget
  - `BPF_InventoryFunctions_C::RefreshInventoryGrid(...)` and `PopulateInventoryGrid(...)` explicitly take `ItemStartIndex`, `RowMax`, `ColumnMax`, and `GridPanel`
  - `UObject::ProcessEvent` is dispatched through the universal SDK vtable slot `Offsets::ProcessEventIdx`
- Current runtime log from a real test now shows:
  - `WBP_InGameMenu_Augusta_C ... ActivateInGameMenuScreenOfTag`
  - the broadened native widget hook now reaches live instances
  - `widget TRACE WBP_InventoryInterface_C ... Construct`
  - `widget TRACE WBP_InventoryInterface_C ... OnMouseWheel`
  - `initial patch round: 3 / 45 components patched`
  - `widget PATCH UI_InventoryGrid_C ... MaxRows: 3 -> 6 (CDO only)`
  - `initial widget patch round: 1 UUI_InventoryGrid_C objects bumped to MaxRows=6`
  - after opening/using inventory, still no `widget HOOK ... PopulateItemGrid(...)->(6, 10)` line
  - after opening/using inventory, no reflected `Populate*` / `Refresh*` / `OnInventoryChanged` path was seen on the live widget; only `Construct`
  - after widening traces to SDK-backed native-adjacent candidates, still no:
    - `inventory BPF TRACE ... RefreshInventoryGrid`
    - `inventory BPF TRACE ... PopulateInventoryGrid`
    - `inventory GRID TRACE ... AddChildToGrid`
    - `inventory GRID TRACE ... ClearChildren`
  - direct live-state inspection now shows:
    - `WBP_InventoryInterface_C` is the live rendered inventory page inside the in-game menu
    - its `ItemGrid` exists and contains exactly `40` child widgets
    - those children are concrete `UI_ItemSlot_C` instances
    - runtime code repeatedly queries `ItemGrid.GetChildrenCount()` and `ItemGrid.GetChildAt(...)`
  - forced-step scroll proof now shows:
    - `GetInventoryItems ok, count=39`
    - `calling RefreshInventoryGrid rows=4 cols=10 start=20`
    - `RefreshInventoryGrid returned`
    - `SetSelectedInventorySlot(0) ok`
    - `scroll refresh ... mouse-wheel start=10 -> 20`
- Result: capacity patch succeeds, the broadened native `ProcessEvent` hook reaches live `WBP_InventoryInterface_C` instances, `OnMouseWheel` is confirmed on the live widget, and the viewport rebind path is now proven end-to-end. The live inventory UI operates on a fixed pool of 40 visible slot widgets, and `RefreshInventoryGrid(..., ItemStartIndex)` can successfully page that viewport across the 100-slot backing inventory.
  - The 100-slot build is now active and the extra slots are visible/reachable.
  - However, the current scroll behavior does not match expected backpack slot semantics: items can appear to move upward in the visible grid as the viewport changes.
- Updated conclusion: the current implementation is mechanically scrolling, but the helper in use is not preserving exact absolute slot positions the way the final UX should.

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
- Broadened traces on likely SDK-backed rebuild helpers:
  - `BPF_InventoryFunctions_C::{RefreshInventoryGrid, PopulateInventoryGrid, PlaceSlotInGrid, CreateItemSlotForItem}`
  - `UGridPanel::AddChildToGrid`
  - `UPanelWidget::{ClearChildren, GetChildrenCount, GetChildAt}`
  - Runtime evidence still showed none of these while opening inventory.
  - New conclusion: slot population is likely happening through deeper native inventory/window code, not through reflected Blueprint helper calls or reflected `GridPanel` child ops.
- Direct live-state inspection of the rendered inventory:
  - `WBP_InventoryInterface_C.ItemGrid` has exactly `40` children at runtime
  - those children are `UI_ItemSlot_C` widgets
  - the menu system activates the inventory page through `WBP_InGameMenu_Augusta_C::ActivateInGameMenuScreenOfTag`
  - runtime code queries `GetChildrenCount` / `GetChildAt` on that existing grid
  - New conclusion: the live inventory UI is operating on a fixed pool of visible slot widgets, which makes viewport rebinding/paging a stronger path than trying to make the page grow taller.
- First scroll-implementation pass:
  - `OnMouseWheel` trace now proves wheel input reaches the live inventory widget.
- First forced-step scroll proof pass:
  - `OnMouseWheel` trace proves wheel input reaches the live inventory widget.
  - The refresh chain now succeeds end-to-end in proof mode.
  - New conclusion: the scroll architecture is correct and working. The remaining implementation task is proper wheel-direction decoding and cleanup of the temporary proof-mode behavior.
- Current semantic issue after the 100-slot build:
  - The rebuilt DLL is active and the larger slot count is present.
  - But scrolling via `RefreshInventoryGrid(..., ItemStartIndex)` is not preserving the expected "absolute slot stays in its absolute position, including empties" behavior.
  - Visible symptom: items from later rows can appear in the first visible slot when paging.
  - New conclusion: `RefreshInventoryGrid(...)` is good enough to prove viewport rebinding works, but it is probably the wrong final helper for backpack-slot semantics.
- Additional clarification from live testing:
  - The expected behavior is stricter than generic paging.
  - Scrolling is per row, but visible placement must still come from absolute slot index math, not item compaction.
  - This is a hard UX requirement, not a nice-to-have.

Immediate next debugging steps:

1. Keep the broadened widget-chain `ProcessEvent` hook as the verified live-instance observation surface.
2. Stop assuming the redraw path must be a reflected Blueprint method on `WBP_InventoryInterface_C`.
3. Review SDK-native candidates adjacent to the now-eliminated reflected paths:
   - `UInventoryWidget`
   - `UWidgetManager`
   - inventory-open / window-stack code around the in-game menu
   - native item-slot setup helpers adjacent to `WBP_InventoryInterface_C`
4. Keep viewport rebinding for the existing 40-slot grid as the implementation path; do not return to 6-row visible expansion work.
5. Replace the current item-list-centric rebind helper with a slot-position-aware rebind path.
6. For each visible index `i`, bind the widget against absolute slot `itemStartIndex + i`.
7. Preserve empty slots as empty instead of allowing items to compact upward visually.
8. Reuse the existing 40 `UI_ItemSlot_C` children, but drive them from explicit absolute-slot mapping rather than relying on `RefreshInventoryGrid(...)` as the final renderer.
9. Treat "item stays in the correct row/column derived from its absolute slot for the current viewport" as the acceptance gate for the scroll feature.
10. After slot semantics are correct, verify user-facing behavior:
   - wheel up vs wheel down
   - close/reopen resets to page 0
   - items keep expected absolute slot positions while scrolled
   - drag/drop and click behavior on slots 41-100
   - boundary behavior at first and last page

Acceptance criteria for this blocker:

- Log shows the hook installation succeeded.
- Opening the inventory produces filtered trace lines from live `WBP_InventoryInterface_C` instances through the broadened native widget hook.
- The real player-inventory rebind/redraw path for the existing 40 visible slot widgets is identified, even if it is deeper native inventory/window code and not a reflected Blueprint or `GridPanel` method.
- Mouse wheel input is confirmed to reach the live inventory widget.
- The mod can drive a rebinding-based viewport update through `RefreshInventoryGrid(..., ItemStartIndex)` without calling unsafe UMG rebuilds from the worker thread.
- The final implementation preserves absolute slot semantics: empty slots remain empty, and items do not visually compact upward when paging.
- The final implementation preserves exact slot-derived row/column placement for every absolute backpack slot while scrolling by rows.
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
