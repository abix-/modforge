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
