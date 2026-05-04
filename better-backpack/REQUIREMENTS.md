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
2. **No other property changes.** Do not touch `MountInventoryComponent`'s `DefaultMaxSize`. Do not touch stack sizes, tech tree, perks, recipes, or anything else. Single-purpose mod.
3. **Configurable slot count.** The desired capacity is read from a `settings.json` file in the mod's source tree at **build time**. Re-running the build script regenerates the pak with the new value.
4. **Standalone deployment.** A single `.pak` plus `.ucas` plus `.utoc` triple, dropped into the game's `Augusta\Content\Paks\` directory or into Vortex as a self-contained mod. No companion files. No depending on other mods being present.
5. **Survives no-mod sessions.** If the user uninstalls the mod, the game returns to vanilla 40 slots with no save corruption (provided the player emptied any extra slots first, which is a standard UE pak override property).
6. **Save-load preservation.** Items placed in slots beyond vanilla 40 must persist across a save, quit, and reload cycle.

## Non-goals

- **No UI mod.** We do NOT modify the inventory widget. As a result, the inventory grid in the main inventory UI will visually max out at vanilla rendering capacity (likely 40 slots visible). The mod grows STORAGE: pickup and hold work for slots 41 through N, but those slots may not be individually clickable in the main grid. This is the same trade-off the broken Bigger Backpack mod made; we accept it.
- **No cheats.** This is not a Player Tweaks replacement. No perk unlocks, no recipe unlocks, no point grants.
- **No mount saddlebag changes.** That is `MountInventoryComponent`, a different sub-object and a separate concern.
- **No multiplayer host enforcement layer.** Server-side caps may override client-side capacity in multiplayer; that is a documented limitation, not something we work around.

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
   - Vanilla `BP_SurvivalPlayerCharacter` chunk (`aee653a2e9c280ed00000001`) extracted from `Augusta-WinGRTS.utoc` via `retoc to-legacy` once and cached.
2. **Patch step**
   - Locate the FName index for `DefaultMaxSize` in the vanilla `.uasset` Name Table.
   - Walk the `.uexp` for PropertyTag entries matching that FName plus `IntProperty` type.
   - The first hit is the main `InventoryComponent`'s `DefaultMaxSize`; patch its int32 value to `settings.slot_count`.
   - Leave the second hit (`MountInventoryComponent`) at its vanilla value.
3. **Repack**
   - `repak pack` the patched `.uasset` plus `.uexp` into a legacy pak.
   - `retoc to-zen --version UE5_6` to convert into the IoStore format the shipping game uses.
4. **Output**
   - `<output_basename>_<priority>_P.pak`
   - `<output_basename>_<priority>_P.ucas`
   - `<output_basename>_<priority>_P.utoc`
   - Drop into `dist/` for distribution.

## Acceptance criteria

The mod is "working" when, with the mod installed and **no other mods** in the Paks folder, against game version `0.4.0.2`:

- The game launches without load-time errors related to the modded asset.
- The player's backpack has effective storage of `slot_count` slots: items pick up and persist past slot 40.
- Items placed in slots 41 through `slot_count` survive save, quit, and reload.
- The first 40 slots remain visible and usable in the inventory UI (the rendering cap of the unmodded UI).
- Removing the mod returns the player to a vanilla 40-slot inventory (with the standard caveat: empty extra slots before uninstalling).

Stretch acceptance: optional pairing with the existing **Bigger Backpack** Nexus widget mod renders all 60 slots in the inventory UI grid. Verifying this is informational, not required.

## Known constraints and risks

1. **Single-asset override conflicts with AIO Player Tweaks.** Our mod and AIO Player Tweaks both override `BP_SurvivalPlayerCharacter` (chunk `aee653a2e9c280ed`). At runtime UE picks one based on load priority. Our mod at priority 99 will SHADOW AIO at priority 12, meaning if both are installed, AIO's cheat-tag commands will not fire because the BP that contains them is shadowed. This is acceptable per the "standalone, no reliance on other mods" requirement.
2. **UI render cap.** Without the existing Bigger Backpack widget mod, the inventory UI panel is laid out for 40 slots and does not auto-grow. Slots 41 through N work in storage but may not be individually clickable in the main UI grid (they remain accessible indirectly via building, hot-pouch, and similar, per the existing Bigger Backpack mod's known behaviour).
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
