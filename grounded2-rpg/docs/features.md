# Features

> **Authoritative on:** what Grounded 2 - RPG System actually does today,
> from a player perspective, and how it compares to other Grounded 2
> player-tweak mods. Implementation details live in
> [`rpg.md`](rpg.md) (RPG system) and the architecture sections of
> [`rust-port.md`](rust-port.md) / [`ue4ss-port.md`](ue4ss-port.md).

The closest prior art is **Player Tweaks** by Caites on Nexus, the
de-facto "all-in-one" mod for the game.

## What this mod does today

| Feature | Setting key | Default | Notes |
| --- | --- | --- | --- |
| Player main backpack capacity | `inventory.slot_count` | 100 | Vanilla 40. Mount/saddlebag (vanilla 30) preserved. |
| Hunger drain rate multiplier | `survival.hunger_multiplier` | 0.5 | 1.0 = vanilla. 0.0 = no hunger. |
| Thirst drain rate multiplier | `survival.thirst_multiplier` | 0.5 | 1.0 = vanilla. 0.0 = no thirst. |
| Inventory mouse-wheel scroll | (always on) |, | Keeps 4x10 visible viewport, scrolls through extra slots. |
| Live "Grounded 2 - RPG System" console | `console` Cargo feature | on | Build-time, not user-tunable. |

All numeric settings are runtime-configurable via
`<DLL_dir>/settings.json`. No rebuild needed.

## How we patch (vs how Player Tweaks does it)

- **Player Tweaks (Caites)** ships a pre-baked `.pak` with hardcoded
  values. Each preset is a separate file. To change a number you swap
  the `.pak`. No runtime config. Pak-based mods conflict at the
  data-table level (only the last loaded pak wins for any overlapping
  field), and break when a game patch shifts the underlying tables.
  Both failure modes are visible in the Nexus comments on Player
  Tweaks today.
- **Grounded 2 - RPG System** patches Class Default Objects from a runtime DLL.
  Numbers come from `settings.json` at DLL load. No pak conflicts.
  Survives game patches as long as the offsets in `sdk/offsets.rs`
  stay stable; on those rare patches that shift offsets, we update one
  Rust file and ship a new DLL.

## Distribution

Shipping shape: **UE4SS CPPMod**. The cdylib lands at
`<game>\Augusta\Binaries\WinGRTS\ue4ss\Mods\Grounded2RPG\dlls\main.dll`
and UE4SS handles loading via its standard CPPMod entry point. UE4SS
itself ships as a DLL proxy that the user installs first; we ride
on top.

Earlier shipping shapes that have been retired:

- DLL + injector exe (pre-UE4SS dev iteration shape, removed
  2026-05-10 with the rest of the C++/winhttp tree).
- DLL proxy named `winhttp.dll` (the originally-targeted shape; UE4SS
  fills this slot now, so we don't need our own).

## Why DLL (UE4SS CPPMod) and not pak

The full comparison of UE mod formats + capability matrix lives in
[`../../ueforge/docs/mod-formats.md`](../../ueforge/docs/mod-formats.md).
Background for anyone new to UE5 modding.

For *this mod's* features specifically: of our six features, **two
could be done as a pak** (the CDO numeric patches: backpack capacity
+ survival drain rates). **Four cannot**: mouse-wheel viewport
rebind (no execution surface), runtime-editable JSON settings
(paks bake at cook time), live debug console (no Win32 allocation),
and clean coexistence with other inventory mods (pak asset
replacement is last-loaded-wins). The scroll feature is the hard
"no". It's the reason this mod went DLL-first.

A pak version would be a stripped-down "capacity + drain rates"
preset with the same conflict footprint Player Tweaks users
complain about today. Not what we want to ship.

## Comparison vs Player Tweaks (Caites, Nexus #13)

| Feature | Player Tweaks | Grounded 2 - RPG System | Notes |
| --- | --- | --- | --- |
| **Player main backpack slots** | not done (only buggy) | ✅ 40 → 100, scroll viewport | Their preset only touches the buggy/mount; ours touches the player main. |
| **Hunger rate** | not done | ✅ multiplier |, |
| **Thirst rate** | not done | ✅ multiplier |, |
| Sprint speed | 600 → 750 | not done | Likely a CDO float on the player character. |
| Walk speed | 350 → 450 | not done |, |
| Swim speed | 500 → 600 | not done |, |
| Max fly speed | 1600 → 1900 | not done | Buggy/glider context. |
| Climbable angle | 60° → 70° | not done |, |
| Stamina regen rate | 40 → 80 (2x) | not done |, |
| Exhausted delay | 2s → 1s | not done |, |
| Death delay (downed window) | 120s → 360s | not done |, |
| Perfect block window | 0.25s → 0.4s | not done |, |
| Hauling stack size | 5 → 10 / 99 | not done |, |
| Storage radii | 2x | not done |, |
| Buggy inventory slots | 30 → 48 | not done | We only patch the player main inventory. |
| Live in-game config | ❌ baked into pak | ✅ settings.json |, |
| Multiplayer | works on host | works on host (others see no effect) | Same caveat. |

## What's worth porting?

Subjective. My take:

### Yes, port these

- **Stamina regen rate** + **exhausted delay**. Cheap to find via SDK
  (likely on `USurvivalComponent` next to the hunger/thirst settings,
  or on the player character). Big QoL win, similar shape to what we
  already do.
- **Sprint / walk / swim speed**. Probably floats on the player
  character or movement component CDO. Same one-shot CDO patch
  pattern.
- **Hauling stack size**. Common request, easy if it's a single int on
  the inventory or item component.
- **Death delay (downed timer)**. Likely a single float on the
  survival/health component.

### Maybe

- **Perfect block window**. Single float; trivial. But niche.
- **Climbable angle**. Single float.
- **Storage radii**. Useful for bases; offset hunt may take a minute.

### Probably skip

- **Buggy inventory size**. Player Tweaks already does this and ships
  separately; not worth duplicating unless we want the all-in-one
  experience.
- **Build cost / free building**. Different system entirely (recipe
  data tables). Bigger lift.
- **XP / unlock multipliers**. Different system; data tables again.
- **Day/night length, weather**. Out of scope.

### Pattern for adding any of the above

For any "tweak a CDO float" feature:

1. Find the field in the SDK (`grep -rn '<feature_name>'
   /c/Tools/work/sdk/SDK/`).
2. Note its containing class and offset.
3. Add a section to `settings.json` schema (e.g. `[movement]`).
4. Add a small module (`movement.rs`) that walks the relevant
   classes' CDOs and multiplies/replaces the field.
5. Call it once from the worker after the existing patches.

The SDK + offset hunt is the bulk of the work; the patch code is
template-able after that. Ten lines of Rust per new feature once the
offset is known.

## Versioning

When a Grounded 2 game patch ships, double-check the offset constants
in `grounded2-rpg/src/sdk/offsets.rs`. If they shift, dump a fresh
SDK and update both the platform-level offsets and any per-class field
offsets used by the patch modules. The layout tests in
`grounded2-rpg/tests/layout.rs` catch our own struct shape; they do
**not** catch game-side offset drift.
