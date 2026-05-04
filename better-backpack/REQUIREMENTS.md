# Better Backpack: mod requirements

A standalone mod for Grounded 2 that increases the player's main backpack capacity from vanilla (40 slots) to a configurable count (default 60). No dependencies on other mods.

This is the spiritual successor to the **Bigger Backpack** Nexus mod (`ContainerWidgetTweaks_00054_P`), which is broken in the current shipping build (`++Augusta+release-0.4.0.2-CL-2673661`). Our mod uses a different mechanism that actually works: an injected DLL that patches both the data side and the visible side at runtime. (The earlier prototype shipped as a pak; that approach was retired in favour of the DLL because shipping-build verification required runtime injection anyway.)

## Contents

- [Goal](#goal)
- [Functional requirements](#functional-requirements)
- [Non-goals](#non-goals)
- [Open questions (must answer before build)](#open-questions-must-answer-before-build)
- [Configuration: compile-time constants](#configuration-compile-time-constants)
- [Build pipeline](#build-pipeline)
- [Acceptance criteria](#acceptance-criteria)
- [Verification plan (how to tell if it works)](#verification-plan-how-to-tell-if-it-works)
- [Known constraints and risks](#known-constraints-and-risks)
- [Out of scope (do not build now)](#out-of-scope-do-not-build-now)
- [Repository layout](#repository-layout)

## Goal

Replicate "more usable backpack slots" without:

- Requiring **Player Tweaks** (or any of its variants) to be installed alongside.
- Requiring the existing **Bigger Backpack** Nexus widget mod to be installed alongside.
- Modifying any cooked vanilla file on disk.
- Distributing the patched binary; we ship a tiny DLL plus an injector and patch the live process.

## Functional requirements

1. **Capacity bump.** Increase the int32 value of `DefaultMaxSize` on every `UInventoryComponent` from `40` to `slot_count` (default `60`), but only for components whose full path includes `BP_SurvivalPlayerCharacter` (string-match on the outer chain). This excludes chests (`BP_Ominent_Chest*`), loot bags (`BP_LootBag*`, `BP_DeathLootBag*`), and the wearable backpack item (`BP_Backpack_Player*`), all of which also default to 40. Live patch on CDOs and on instances.
2. **Visible rendering of all N slots.** All `slot_count` slots must render in the player's inventory UI grid and be individually clickable, hover-able, and drag-target-able for items. No hidden slots accessible only indirectly via hot-pouch or building.
3. **No other gameplay changes.** Do not touch `MountInventoryComponent`'s `DefaultMaxSize` (vanilla 30; we explicitly skip the value 30). Do not touch stack sizes, tech tree, perks, recipes, or anything else gameplay related. Single-purpose mod.
4. **Configurable slot count.** Compiled-in constant `kSlotCount` at the top of `dllmain.cpp`. Edit + rebuild. Adding a `settings.json` reader is open for follow-up but not required.
5. **Standalone deployment.** A single `.dll` plus a single `.exe` injector, both produced by `build.bat`. No companion files. No depending on other mods being present.
6. **Survives no-mod sessions.** Removing the DLL (don't run `inject.exe`) means the game runs vanilla, with no save corruption, provided the player emptied any extra slots first.
7. **Save-load preservation.** Items placed in slots beyond vanilla 40 must persist across a save, quit, and reload cycle while the DLL is injected.

## Non-goals

- **No cheats.** This is not a Player Tweaks replacement. No perk unlocks, no recipe unlocks, no point grants.
- **No mount saddlebag changes.** That is `MountInventoryComponent`, a different sub-object and a separate concern.
- **No multiplayer host enforcement layer.** Server-side caps may override client-side capacity in multiplayer; that is a documented limitation, not something we work around.

## Open questions (must answer before build)

These were blockers for the original pak build pipeline. The answers transfer directly to the DLL because the underlying engine semantics are the same.

### Q1. How does `UI_InventoryGrid` decide how many slots to render? (ANSWERED)

The model is **option 2 from the original three-option list**: the grid renders `min(component.DefaultMaxSize, MaxRows * MaxColumns)`, where `MaxRows` lives on the host container widget (`UI_Container_BackpackSide`) and `MaxColumns` is its sibling.

Evidence:

- `UUI_InventoryGrid_C` has its own `MaxRows` and `MaxColumns` (offset 0x0388 and 0x0390, both `int32, Edit, BlueprintVisible`).
- The host widget `UI_Container_BackpackSide` ALSO has a `MaxRows` property that the broken Bigger Backpack mod overrides. It does NOT override `MaxColumns`. The host widget hosts the grid as a sub-widget and configures it via these two values.
- `UpdateRowsAndColumnsForInventory(InventoryComponent, out Columns, out Rows, out MaxSlots)` is a function on the grid widget. Naming and parameter shape are consistent with computing the effective grid based on both the widget's own MaxRows/MaxColumns and the component's MaxSize.
- The broken Bigger Backpack mod sets `UI_Container_BackpackSide.MaxRows = 6`. Assuming vanilla `MaxColumns = 8`, that gives 48 visible slots, not the advertised 60. This matches user reports that "only 40 are clickable" when the data-side cap is also vanilla 40: the visible cap is `min(40, 48) = 40`. With the 60-slot Player Tweaks variant data-side, the visible cap becomes `min(60, 48) = 48`. Neither configuration reaches 60 visible. The original mod's design only ever supported up to 48 visible.

For Better Backpack to render all 60 slots clickable, we do TWO things:

1. `UInventoryComponent.DefaultMaxSize` -> `slot_count` (60), on every live instance and CDO whose value is 40 AND whose outer chain contains `BP_SurvivalPlayerCharacter`.
2. Call `UWBP_InventoryInterface_C::PopulateItemGrid(RowMax=ceil(slot_count/10), ColumnMax=10)` via `ProcessEvent` on every live inventory-interface instance, once per instance. The Params struct (from `WBP_InventoryInterface_parameters.hpp`) is 0xB0 bytes with two int32 inputs at offsets 0x00 and 0x04.

For `slot_count = 60` and `ColumnMax = 10`, the call is `PopulateItemGrid(6, 10)`.

**Note on widgets that aren't the answer.** Earlier research focused on `UI_Container_BackpackSide` (what the broken Bigger Backpack pak mod patched). That class is not present in `GObjects` in this shipping build, before or after the inventory is opened. We then tried patching `UUI_InventoryGrid_C.MaxRows` at offset `0x0388`, which exists at runtime and includes a `Default__UI_InventoryGrid_C` CDO. That had no visible effect on the player inventory either, because the player inventory is rendered by `UWBP_InventoryInterface_C` directly, using its own `UGridPanel ItemGrid` (line 50 of `WBP_InventoryInterface_classes.hpp`) and the BP-callable method `PopulateItemGrid(RowMax, ColumnMax)` (line 205). The DLL still patches the `UUI_InventoryGrid_C` CDO as belt-and-braces in case a future build reintroduces a grid widget here, but the `PopulateItemGrid` call is what actually delivers six rows in-game.

### Q1a. Vanilla `MaxColumns` on `UI_InventoryGrid` (ANSWERED)

`MaxColumns = 10`, `MaxRows = 3` are the CDO defaults on `UI_InventoryGrid` itself. The host `UI_Container_BackpackSide` does not override `MaxColumns` (not in its Name Table), but does override `MaxRows = 4` to give the vanilla 4 x 10 = 40 visible slot grid.

Bigger Backpack mod's `MaxRows = 6` was therefore correctly designed for 60 visible slots (6 x 10). Earlier guess that BB was "designed for only 48 visible" was wrong; it was designed for 60 visible, but the visible count is clamped by the inventory component's `MaxSize` (vanilla 40), so without the 60-slot Player Tweaks variant providing data-side capacity, BB has zero visible effect.

For Better Backpack with `slot_count = 60`: set `UI_Container_BackpackSide.MaxRows = 6`.

For other slot counts: `target_max_rows = ceil(slot_count / 10)`.

### Q2. Vanilla `DefaultMaxSize` on player main backpack (ANSWERED)

Confirmed `40`. Read directly from vanilla `BP_SurvivalPlayerCharacter.uexp` via `scripts/read_property.py`.

### Q3. Vanilla `DefaultMaxSize` on `MountInventoryComponent` (ANSWERED)

Confirmed `30`. AIO Player Tweaks v13.1.6 bumps it to 48 (a real +18 saddlebag bump). Better Backpack leaves the vanilla 30 in place because mount capacity is out of scope; if a user wants both bigger main backpack AND bigger saddlebag, that becomes a future option (separate constant). The DLL's "skip values that aren't 40" rule means we never touch the mount.

### Q4. Hard caps on `DefaultMaxSize`. (Still open, in-game only)

Not statically determinable. Will need an in-game test. Acceptance test should include trying a value at the top of the requested range to confirm the game does not silently clamp.

## Configuration: compile-time constants

In `dllmain.cpp`:

```cpp
constexpr int32_t kSlotCount         = 60;  // target main-backpack DefaultMaxSize
constexpr int32_t kVanillaMain       = 40;  // value the DLL looks for; only patches matches
constexpr int32_t kVanillaMount      = 30;  // documented; never touched by name (we skip non-40 values)
constexpr int32_t kVanillaMaxColumns = 10;  // UI_InventoryGrid.MaxColumns
constexpr int32_t kTargetMaxRows     = ceil(kSlotCount / kVanillaMaxColumns); // = 6
```

Edit and rebuild. There is no runtime config reader. A `settings.json` follow-up would either parse at DLL load or get baked at build time; both are easy if needed.

## Build pipeline

1. **Inputs**
   - `dllmain.cpp` (the DLL logic).
   - `basic_impl.cpp` (slim re-impl of the SDK's `Basic.cpp` without the `Engine_classes.hpp` dependency that pulls in 290k lines of unused SDK function bodies).
   - `inject.c` (the injector).
   - The Dumper-7 SDK at `C:\Tools\work\sdk\`. Only `Basic.hpp`, `CoreUObject_structs.hpp`, `CoreUObject_classes.hpp` are included; `CoreUObject_functions.cpp` is the only SDK cpp file we compile.
2. **Build step (DLL)**
   - `cl.exe /LD /std:c++latest dllmain.cpp basic_impl.cpp CoreUObject_functions.cpp -> BetterBackpack.dll`
3. **Build step (injector)**
   - `cl.exe inject.c -> inject.exe`
4. **Output**
   - `dist/BetterBackpack.dll` (~40 KB, 64-bit)
   - `dist/inject.exe` (~15 KB, 64-bit console)
   - Cold build: ~30 seconds. Incremental: a couple of seconds.

The DLL has two patch surfaces:

1. **Data side**: `UInventoryComponent.DefaultMaxSize` at offset `0x01E0` (from `Maine_classes.hpp:29557`). Hard-coded write. Gated on the outer chain containing `BP_SurvivalPlayerCharacter`.
2. **Visible side**: `UWBP_InventoryInterface_C::PopulateItemGrid(6, 10)` invoked via `ProcessEvent`. Reflective UFunction call, no hard-coded offset. Once per live instance.

Plus a defensive CDO write on `UUI_InventoryGrid_C.MaxRows` at offset `0x0388` for future-proofing. No vanilla files on disk are touched.

## Acceptance criteria

The mod is "working" when, with the DLL injected and **no other mods** in the Paks folder, against game version `0.4.0.2`:

- The game launches without load-time errors.
- After injection, the player's inventory UI renders `ceil(slot_count / 10)` rows of 10 slots, all clickable.
- Items pick up into slots 1 through `slot_count` and the inventory does not refuse pickup until full.
- Items placed in slots 41 through `slot_count` survive save, quit, and reload (with the DLL re-injected on the next session).
- Not injecting the DLL (or removing it before relaunching) returns the player to a vanilla 40-slot inventory (with the standard caveat: empty extra slots before relying on this).

## Verification plan (how to tell if it works)

There are three layers of "works", each with a different test.

### Layer 1: did the DLL load at all?

If `inject.exe` reports `DLL mapped at HMODULE 0x...` and a new console window titled "Better Backpack" appears in the game process, the DLL is loaded. If the console doesn't appear or the log file at `%TEMP%\BetterBackpack.log` doesn't grow, the DLL got mapped but `DllMain` failed to spawn the worker thread.

What to check:
- **Console window** titled "Better Backpack Debug" appeared.
- **Log file** at `%TEMP%\BetterBackpack.log` exists and has a banner line.
- **`GObjects count = N`** prints with N > 0.

If layer 1 fails, layers 2 and 3 don't matter; check `%TEMP%\BetterBackpack.log` for the failing line.

### Layer 2: did the data-side change apply?

In the DLL log, look for `PATCH ... : 40 -> 60 (verify=60)` lines. There should be at least one. Typically a CDO line and a live instance line for the player's main inventory.

In-game: try to fill the inventory past 40 items. Then save, quit, reload (with the DLL still injected).

Expected:
- Pick up items 41 through 60 normally; the inventory does not refuse pickup at 40.
- Saving does not produce errors.
- Reloading the save shows items 41 through 60 still in their slots.

Failure modes:
- **No PATCH lines in log:** no `UInventoryComponent` had `DefaultMaxSize == 40`. Either the player wasn't spawned (you injected at the main menu instead of in a save), or the value was already changed by something else (another mod). The log dumps every component pre-patch so you can see what's there.
- **PATCH lines present but pickup refused at 40 in-game:** the running player pawn was spawned with a snapshot of the cap; replication or runtime initialiser is overriding our value. Try injecting before opening the inventory for the first time, or extend the DLL to also write to the live `MaxSize` runtime field if `UInventoryComponent` has one.
- **Items vanish after save/reload:** save serialization is rejecting capacities above some hard cap. Try a smaller `kSlotCount` (e.g. 50). This is the empirical answer to Q4.

### Layer 3: did the visible-side change apply?

Open the inventory UI in-game. Count the slots.

Expected with `kSlotCount = 60`:
- 6 rows of 10 slots, all rendered.
- All 60 slots clickable, hoverable, drag-target-able.

Failure modes:
- **4 rows visible (vanilla 40):** widget patch did not apply. In the DLL log, look for `widget initially patched: 0`. That means the widget class wasn't loaded at injection time. The DLL retries on every 10s rescan, so opening the inventory once and waiting 10s should fix it. If the log shows `widget: MaxRows FProperty not found`, the property name changed; rebuild Dumper-7 SDK headers and check the new field name.
- **6 rows visible but slots 41 through 60 greyed out / not interactive:** widget rendering applied but the inventory component is still vanilla 40. Layer 2 problem, not Layer 3.

### Quick combined test (5 minutes, no item-spawning required)

1. Build the DLL: `build.bat`.
2. Launch the game and load a save where the player has a near-full inventory.
3. Run `dist\inject.exe` from an Admin cmd.
4. Open the inventory. Count the rows.
   - Expect 6 rows. If you see 4, layer 3 failed (open the DLL log).
5. Drop everything into a chest, walk around picking up grass and sap stems past slot 40.
   - Expect pickup to keep working past 40. If items get refused at 40, layer 2 failed.
6. Save, quit to main menu, reload.
   - Expect items in slots 41+ to still be there. If gone, layer 2 has a serialization caveat (Q4).

Pass on all three steps means the mod works as designed.

### Static verification (does not require launching the game)

Before launching:

```cmd
dumpbin /headers dist\BetterBackpack.dll | findstr "machine"
:: Expect: 8664 machine (x64)

dumpbin /exports dist\BetterBackpack.dll
:: No exports expected. DllMain only.

dist\inject.exe nonexistent.dll
:: Expect: "[-] DLL not found: 'nonexistent.dll' (E2)"
:: Confirms the injector's path-resolution code path works.
```

If static checks pass and layer 1 fails, the issue is in `DllMain` or the worker thread (read the log, or attach a debugger to the game process and break on `DllMain`).

## Known constraints and risks

1. **DLL must be injected after the player pawn spawns.** `UInventoryComponent` instances don't exist at the main menu. The CDO does, so a CDO patch at main-menu inject would propagate to subsequently spawned pawns, but the live readout is empty until you load a save. We document "load a save first, then inject".
2. **UI render path was the original open unknown.** Resolved (Q1/Q1a). The widget patch is necessary for the visible slot count to scale beyond 40.
3. **Game patches may shift offsets.** `DefaultMaxSize` at offset `0x01E0` is hard-coded. A game update that changes `UInventoryComponent`'s field layout breaks the patch. The widget `MaxRows` is reflectively located by name and survives layout shifts. If the data side breaks, Dumper-7 needs a re-run against the new build to get the new offset.
4. **Hard caps unknown.** UE-side or Obsidian-side hard caps on inventory size may exist in C++ that the SDK does not expose. Verifiable only by in-game test. A sensible `slot_count` ceiling is probably 100 to 200; very large values may have undefined behaviour.
5. **Multiplayer.** Server-authoritative capacity enforcement may clamp client-side capacity in multiplayer sessions where the host does not have the same mod. Not in scope to work around.
6. **Re-injection during a single session.** Don't. The DLL holds an atomic running flag and an open log file handle; mapping it twice would double-spawn worker threads.
7. **Anti-cheat.** Grounded 2 has none listed. If that ever changes, this DLL would trip it.

## Out of scope (do not build now)

- Auto-launching the injector from a Vortex extension.
- A proxy-DLL trick (renaming our DLL to `dxgi.dll` etc. so Windows loads it on game start) to remove the manual inject step.
- A multi-mod combiner that merges this with a stack-size mod.
- A CI workflow that auto-builds and signs the DLL.
- A `settings.json` reader (would just be hardcoded constants moved to a file).

## Repository layout

```
better-backpack/
  REQUIREMENTS.md     (this file: design + research + verification plan)
  README.md           (user-facing: how to build and inject)
  dllmain.cpp         (DLL logic: console, log, GObjects walk, patch, rescan loop)
  basic_impl.cpp      (slim re-impl of SDK's Basic.cpp; avoids the 290k-line compile)
  inject.c            (the injector: CreateRemoteThread(LoadLibraryA))
  build.bat           (vcvars64 + cl.exe wrapper; ~30s cold)
  .gitignore          (build/, dist/, *.log, *.obj, *.pdb)
  dist/               (output: BetterBackpack.dll + inject.exe; gitignored)
  build/              (intermediate .obj/.pdb; gitignored)
```
