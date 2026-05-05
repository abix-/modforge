# Features

This doc tracks what Better Backpack actually does today and how its
feature set compares to other Grounded 2 player-tweak mods (the closest
prior art being **Player Tweaks** by Caites on Nexus -- the de-facto
"all-in-one" mod for the game).

## What this mod does today

| Feature | Setting key | Default | Notes |
| --- | --- | --- | --- |
| Player main backpack capacity | `inventory.slot_count` | 100 | Vanilla 40. Mount/saddlebag (vanilla 30) preserved. |
| Hunger drain rate multiplier | `survival.hunger_multiplier` | 0.5 | 1.0 = vanilla. 0.0 = no hunger. |
| Thirst drain rate multiplier | `survival.thirst_multiplier` | 0.5 | 1.0 = vanilla. 0.0 = no thirst. |
| Inventory mouse-wheel scroll | (always on) | -- | Keeps 4x10 visible viewport, scrolls through extra slots. |
| Live "Better Backpack" console | `console` Cargo feature | on | Build-time, not user-tunable. |

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
- **Better Backpack** patches Class Default Objects from a runtime DLL.
  Numbers come from `settings.json` at DLL load. No pak conflicts.
  Survives game patches as long as the offsets in `sdk/offsets.rs`
  stay stable; on those rare patches that shift offsets, we update one
  Rust file and ship a new DLL.

## Distribution

Two shipping shapes have existed for this mod during development; the
second is the one that ends up on Nexus / Vortex:

1. **DLL + injector exe** (current dev shape). User runs `inject.exe`
   to load the DLL into a running game. Good for development
   iteration, bad for end users (manual step every session).
2. **DLL proxy named `winhttp.dll`** (target shape, see TODO #1). Drops
   into `Grounded2\Augusta\Binaries\Win64\`. Windows auto-loads it
   when the game starts because the filename matches a system DLL the
   game already imports; our DLL forwards the real `winhttp` exports
   to `C:\Windows\System32\winhttp.dll` so the game still has working
   network calls. This is how UE4SS, ReShade, ENB all distribute.
   Vortex installs it as a regular file drop.

## Comparison vs Player Tweaks (Caites, Nexus #13)

| Feature | Player Tweaks | Better Backpack | Notes |
| --- | --- | --- | --- |
| **Player main backpack slots** | not done (only buggy) | ✅ 40 → 100, scroll viewport | Their preset only touches the buggy/mount; ours touches the player main. |
| **Hunger rate** | not done | ✅ multiplier | -- |
| **Thirst rate** | not done | ✅ multiplier | -- |
| Sprint speed | 600 → 750 | not done | Likely a CDO float on the player character. |
| Walk speed | 350 → 450 | not done | -- |
| Swim speed | 500 → 600 | not done | -- |
| Max fly speed | 1600 → 1900 | not done | Buggy/glider context. |
| Climbable angle | 60° → 70° | not done | -- |
| Stamina regen rate | 40 → 80 (2x) | not done | -- |
| Exhausted delay | 2s → 1s | not done | -- |
| Death delay (downed window) | 120s → 360s | not done | -- |
| Perfect block window | 0.25s → 0.4s | not done | -- |
| Hauling stack size | 5 → 10 / 99 | not done | -- |
| Storage radii | 2x | not done | -- |
| Buggy inventory slots | 30 → 48 | not done | We only patch the player main inventory. |
| Live in-game config | ❌ baked into pak | ✅ settings.json | -- |
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
in `better-backpack/src/sdk/offsets.rs`. If they shift, dump a fresh
SDK and update both the platform-level offsets and any per-class field
offsets used by the patch modules. The layout tests in
`better-backpack/tests/layout.rs` catch our own struct shape; they do
**not** catch game-side offset drift.
