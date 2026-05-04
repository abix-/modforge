# Better Backpack: mod requirements

A standalone mod for Grounded 2 that increases the player's main backpack capacity from vanilla (40 slots) to a configurable count (default 60). No dependencies on other mods.

This is the spiritual successor to the **Bigger Backpack** Nexus mod (`ContainerWidgetTweaks_00054_P`), which is broken in the current shipping build (`++Augusta+release-0.4.0.2-CL-2673661`). Our mod uses a different mechanism that actually works.

## Goal

Replicate "more usable backpack slots" without:

- Requiring **Player Tweaks** (or any of its variants) to be installed alongside.
- Requiring the existing **Bigger Backpack** Nexus widget mod to be installed alongside.
- Requiring any external DLL injector or runtime hook.
- Modifying any vanilla file beyond the single Blueprint that owns the inventory component.

## Functional requirements

1. **Capacity bump.** Increase the int32 value of `DefaultMaxSize` on the **main** `InventoryComponent` sub-object of `BP_SurvivalPlayerCharacter` from vanilla's `40` to a configurable value (default `60`).
2. **Visible rendering of all N slots.** All `slot_count` slots must render in the player's inventory UI grid and be individually clickable, hover-able, and drag-target-able for items. No hidden slots accessible only indirectly via hot-pouch or building.
3. **No other gameplay changes.** Do not touch `MountInventoryComponent`'s `DefaultMaxSize`. Do not touch stack sizes, tech tree, perks, recipes, or anything else gameplay related. Single-purpose mod.
4. **Configurable slot count.** The desired capacity is read from a `settings.json` file in the mod's source tree at **build time**. Re-running the build script regenerates the pak with the new value.
5. **Standalone deployment.** A single `.pak` plus `.ucas` plus `.utoc` triple, dropped into the game's `Augusta\Content\Paks\` directory or into Vortex as a self-contained mod. No companion files. No depending on other mods being present.
6. **Survives no-mod sessions.** If the user uninstalls the mod, the game returns to vanilla 40 slots with no save corruption (provided the player emptied any extra slots first, which is a standard UE pak override property).
7. **Save-load preservation.** Items placed in slots beyond vanilla 40 must persist across a save, quit, and reload cycle.

## Non-goals

- **No cheats.** This is not a Player Tweaks replacement. No perk unlocks, no recipe unlocks, no point grants.
- **No mount saddlebag changes.** That is `MountInventoryComponent`, a different sub-object and a separate concern.
- **No multiplayer host enforcement layer.** Server-side caps may override client-side capacity in multiplayer; that is a documented limitation, not something we work around.

## Open questions (must answer before build)

These are blockers for the build pipeline. The first one is the largest unknown.

### Q1. How does `UI_InventoryGrid` decide how many slots to render? (ANSWERED)

The model is **option 2 from the original three-option list**: the grid renders `min(component.DefaultMaxSize, MaxRows * MaxColumns)`, where `MaxRows` lives on the host container widget (`UI_Container_BackpackSide`) and `MaxColumns` is its sibling.

Evidence:

- `UUI_InventoryGrid_C` has its own `MaxRows` and `MaxColumns` (offset 0x0388 and 0x0390, both `int32, Edit, BlueprintVisible`).
- The host widget `UI_Container_BackpackSide` ALSO has a `MaxRows` property that the broken Bigger Backpack mod overrides. It does NOT override `MaxColumns`. The host widget hosts the grid as a sub-widget and configures it via these two values.
- `UpdateRowsAndColumnsForInventory(InventoryComponent, out Columns, out Rows, out MaxSlots)` is a function on the grid widget. Naming and parameter shape are consistent with computing the effective grid based on both the widget's own MaxRows/MaxColumns and the component's MaxSize.
- The broken Bigger Backpack mod sets `UI_Container_BackpackSide.MaxRows = 6`. Assuming vanilla `MaxColumns = 8`, that gives 48 visible slots, not the advertised 60. This matches user reports that "only 40 are clickable" when the data-side cap is also vanilla 40: the visible cap is `min(40, 48) = 40`. With the 60-slot Player Tweaks variant data-side, the visible cap becomes `min(60, 48) = 48`. Neither configuration reaches 60 visible. The original mod's design only ever supported up to 48 visible.

For Better Backpack to render all 60 slots clickable, the build must override BOTH:

1. `BP_SurvivalPlayerCharacter`: bump main `InventoryComponent.DefaultMaxSize` to `slot_count` (60).
2. `UI_Container_BackpackSide`: bump `MaxRows` to `ceil(slot_count / MaxColumns)`.

For `slot_count = 60` and assumed `MaxColumns = 8`, set `MaxRows = 8` (giving 64 grid positions, of which 60 are usable).

If `slot_count` is configured differently in `settings.json`, the build script must compute `MaxRows` from `slot_count` and the actual vanilla `MaxColumns` value.

### Q1a. Vanilla `MaxColumns` on `UI_InventoryGrid` (ANSWERED)

`MaxColumns = 10`, `MaxRows = 3` are the CDO defaults on `UI_InventoryGrid` itself. The host `UI_Container_BackpackSide` does not override `MaxColumns` (not in its Name Table), but does override `MaxRows = 4` to give the vanilla 4 x 10 = 40 visible slot grid.

Bigger Backpack mod's `MaxRows = 6` was therefore correctly designed for 60 visible slots (6 x 10). Earlier guess that BB was "designed for only 48 visible" was wrong; it was designed for 60 visible, but the visible count is clamped by the inventory component's `MaxSize` (vanilla 40), so without the 60-slot Player Tweaks variant providing data-side capacity, BB has zero visible effect.

For Better Backpack with `slot_count = 60`: set `UI_Container_BackpackSide.MaxRows = 6` (matches BB's value).

For other slot counts: `target_max_rows = ceil(slot_count / 10)`.

### Q2. Vanilla `DefaultMaxSize` on player main backpack (ANSWERED)

Confirmed `40`. Read directly from vanilla `BP_SurvivalPlayerCharacter.uexp` via `scripts/read_property.py`.

### Q3. Vanilla `DefaultMaxSize` on `MountInventoryComponent` (ANSWERED)

Confirmed `30`. AIO Player Tweaks v13.1.6 bumps it to 48 (a real +18 saddlebag bump). Better Backpack leaves the vanilla 30 in place because mount capacity is out of scope; if a user wants both bigger main backpack AND bigger saddlebag, they install AIO separately and accept that AIO's BP override gets shadowed by ours (so saddlebag returns to vanilla 30 unless we also patch the mount value into our override).

Decision for Better Backpack: leave the saddlebag at vanilla 30 in our override. If a user wants 48 saddlebag too, that becomes a separate `settings.json` field in a future iteration.

### Q4. Hard caps on `DefaultMaxSize`. (Still open, in-game only)

Not statically determinable. Will need an in-game test. Acceptance test should include trying a value at the top of the requested range to confirm the game does not silently clamp.

## Configuration: `settings.json`

A JSON file in the mod source tree (NOT inside the deployed pak; `.pak` files are immutable cooked binaries):

```json
{
  "slot_count": 60,
  "target_game_version": "0.4.0.2",
  "load_priority": 99,
  "output_basename": "BetterBackpack"
}
```

Field semantics:

| Field                  | Type   | Default              | Notes |
|------------------------|--------|----------------------|-------|
| `slot_count`           | int    | `60`                 | Final `DefaultMaxSize` value the mod sets. Vanilla is 40. |
| `target_game_version`  | string | `"0.4.0.2"`          | Documentation only. If the SDK or vanilla asset layout changes, the build script should warn. |
| `load_priority`        | int    | `99`                 | Number embedded in the output pak's filename (`<basename>_<priority>_P.pak`). Higher loads later, wins on chunk-ID conflicts. |
| `output_basename`      | string | `"BetterBackpack"`   | Output filename stem. |

## Build pipeline

1. **Inputs**
   - `settings.json` (slot count and metadata).
   - Vanilla `BP_SurvivalPlayerCharacter` chunk (`aee653a2e9c280ed00000001`).
   - Vanilla `UI_Container_BackpackSide` chunk (`9776fd889ac44a7c00000001`).
   - Both extracted from `Augusta-WinGRTS.utoc` and converted to legacy via `retoc to-legacy`, cached.
2. **Patch step (BP_SurvivalPlayerCharacter)**
   - Locate the FName index for `DefaultMaxSize` in the vanilla `.uasset` Name Table.
   - Walk the `.uexp` for PropertyTag entries matching that FName plus `IntProperty` type.
   - The first hit is the main `InventoryComponent`'s `DefaultMaxSize`; patch its int32 value to `settings.slot_count`.
   - Leave the second hit (`MountInventoryComponent`) at its vanilla value.
3. **Patch step (UI_Container_BackpackSide)**
   - Read vanilla `MaxColumns` from this widget's `.uexp` (one-shot lookup, cached).
   - Compute `target_max_rows = ceil(settings.slot_count / vanilla_max_columns)`.
   - Patch the `MaxRows` int32 in the widget's `.uexp` to `target_max_rows`.
   - Leave `MaxColumns` at vanilla.
4. **Repack**
   - `repak pack` the patched `.uasset` plus `.uexp` files (both assets) into a single legacy pak.
   - `retoc to-zen --version UE5_6` to convert into the IoStore format the shipping game uses.
5. **Output**
   - Loose files (for non-Vortex / manual install):
     - `<output_basename>_<priority>_P.pak`
     - `<output_basename>_<priority>_P.ucas`
     - `<output_basename>_<priority>_P.utoc`
   - Vortex-installable archive (recommended):
     - `<output_basename>-<slot_count>slots.zip`
     - Internal layout: `Augusta/Content/Paks/<output_basename>_<priority>_P.{pak,ucas,utoc}`
     - User drags the zip onto Vortex, or uses Mods -> Install From File. Vortex extracts into its own staging dir and deploys via symlink/copy into the game's Paks folder.
   - All artifacts go to `dist/` for distribution.

The output pak contains exactly two overridden assets: the player Blueprint (data-side capacity) and the host backpack container widget (visible-side row count). No other vanilla files are touched.

## Acceptance criteria

The mod is "working" when, with the mod installed and **no other mods** in the Paks folder, against game version `0.4.0.2`:

- The game launches without load-time errors related to the modded asset.
- The player's inventory UI renders `ceil(slot_count / 10)` rows of 10 slots, all clickable.
- Items pick up into slots 1 through `slot_count` and the inventory does not refuse pickup until full.
- Items placed in slots 41 through `slot_count` survive save, quit, and reload.
- Removing the mod returns the player to a vanilla 40-slot inventory (with the standard caveat: empty extra slots before uninstalling).

## Verification plan (how to tell if it works)

There are three layers of "works", each with a different test.

### Layer 1: did the mod load at all?

This is the most basic signal. If the game launches normally and there are no load errors, the pak got mounted. If the game crashes at launch or fails to load a save, the pak is malformed or our chunk ID conflicts with something else.

What to check:
- **Game launches** to the main menu without crashing.
- **Saves load** without "asset failed to load" popups.
- **Game log file** at `%LOCALAPPDATA%\Augusta\Saved\Logs\Augusta.log` (open in a text editor, search for `LogPak` and `LogIoStore`). Look for the line that mounts our pak. Look for any errors mentioning `BP_SurvivalPlayerCharacter` or `UI_Container_BackpackSide`.

If layer 1 fails, layers 2 and 3 don't matter; revert and debug.

### Layer 2: did the visible-side change apply?

Open the inventory UI in-game. Count the slots.

Expected with `slot_count = 60`:
- 6 rows of 10 slots, all rendered.
- All 60 slots clickable, hoverable, drag-target-able.

Failure modes:
- **4 rows visible (vanilla 40):** widget patch did not apply. Possible causes: priority too low, vanilla `MaxRows` is not 4 in your build, our zip's path layout is wrong, Vortex did not deploy the file.
- **6 rows visible but slots 41 through 60 greyed out / not interactive:** widget rendering applied but the inventory component is still vanilla 40, so the grid clamps the extra slots.

### Layer 3: did the data-side change apply?

Try to fill the inventory past 40 items. Then save, quit, reload.

Expected:
- Pick up items 41 through 60 normally; the inventory does not refuse pickup at 40.
- Saving does not produce errors.
- Reloading the save shows items 41 through 60 still in their slots.

Failure modes:
- **Pickup refused at slot 40:** data patch did not apply. Most likely the widget patch DID apply (you see 60 slots) but the BP patch did not, so storage caps at vanilla 40.
- **Items vanish after save/reload:** save serialization is rejecting capacities above some hard cap, OR the patched component's MaxSize is being reset by some runtime initialiser. Try a smaller slot_count (e.g. 50) to see if there's a ceiling. (This is the empirical answer to Q4.)

### Quick combined test (5 minutes, no item-spawning required)

1. Install the mod via Vortex.
2. Launch a save where the player normally has a near-full inventory.
3. Press the inventory key. Count the rows.
   - Expect 6 rows. If you see 4, layer 2 failed.
4. Drop everything into a chest, walk around picking up grass and sap stems until past slot 40.
   - Expect pickup to keep working past 40. If items get refused at 40, layer 3 failed.
5. Save, quit to main menu, reload.
   - Expect items in slots 41+ to still be there. If gone, layer 3 has a serialization caveat.

Pass on all three steps means the mod works as designed.

### Static verification (does not require launching the game)

Before launching, you can sanity-check the build artifacts:

```bash
# Confirm the patched values are actually written.
python ../scripts/read_property.py \
  better-backpack/build/Augusta/Content/Blueprints/Player/BP_SurvivalPlayerCharacter.uasset \
  better-backpack/build/Augusta/Content/Blueprints/Player/BP_SurvivalPlayerCharacter.uexp \
  DefaultMaxSize
# Expect: hit 1 VALUE=60 (slot_count), hit 2 VALUE=30 (mount, vanilla)

python ../scripts/read_property.py \
  better-backpack/build/Augusta/Content/UI/Container/UI_Container_BackpackSide.uasset \
  better-backpack/build/Augusta/Content/UI/Container/UI_Container_BackpackSide.uexp \
  MaxRows
# Expect: hit 1 VALUE=6 (target_max_rows for slot_count=60)

# Confirm the output container has the right format.
retoc info dist/BetterBackpack_00099_P.utoc
# Expect: version: ReplaceIoChunkHashWithIoHash
#         container_header_version: Some(SoftPackageReferencesOffset)
#         packages: 2
```

If static checks pass and layer 1 fails, the issue is upstream of the mod (Vortex deploy, game version mismatch, or chunk-ID collision with another mod).

Stretch acceptance: optional pairing with the existing **Bigger Backpack** Nexus widget mod is redundant once Better Backpack is installed; both touch `UI_Container_BackpackSide` and the higher-priority one wins. Verifying that pairing does not break anything is informational, not required.

## Known constraints and risks

1. **Single-asset override conflicts with AIO Player Tweaks.** Our mod and AIO Player Tweaks both override `BP_SurvivalPlayerCharacter` (chunk `aee653a2e9c280ed`). At runtime UE picks one based on load priority. Our mod at priority 99 will SHADOW AIO at priority 12, meaning if both are installed, AIO's cheat-tag commands will not fire because the BP that contains them is shadowed. This is acceptable per the "standalone, no reliance on other mods" requirement.
2. **UI render path is the open unknown.** See Q1 above. Until that is answered, we do not know if data-side capacity is sufficient for visible rendering, or whether we also need to override one or more widgets. The build pipeline is structured to add the widget overrides cleanly if needed.
3. **Game patches may shift offsets.** The build pipeline re-derives byte offsets at build time from the vanilla asset's FName table, not from a hardcoded offset. So a game patch that re-orders FNames will not break the build as long as `DefaultMaxSize` and `IntProperty` still exist in the table.
4. **Hard caps unknown.** UE-side or Obsidian-side hard caps on inventory size may exist in C++ that the SDK does not expose. Verifiable only by in-game test. A sensible `slot_count` ceiling is probably 100 to 200; very large values may have undefined behaviour.
5. **Multiplayer.** Server-authoritative capacity enforcement may clamp client-side capacity in multiplayer sessions where the host does not have the same mod. Not in scope to work around.

## Out of scope (do not build now)

- A companion UI widget mod that grows the inventory grid beyond 40 visible slots.
- A multi-mod combiner that merges this with a stack-size mod into a single pak.
- A runtime DLL hook approach that does not require pak patching at all.
- A CI workflow that auto-builds and signs the mod pak.

## Repository layout (target)

```
better-backpack/
  REQUIREMENTS.md          (this file)
  settings.json            (the user-editable config)
  build.py                 (the build script, not yet written)
  dist/                    (output paks, TBD whether gitignored)
  vanilla/                 (cached vanilla extraction, gitignored)
```

Build script and `settings.json` to be written in the next session, after this requirements doc is approved.
