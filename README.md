# abix's UE5 mods (ueforge + game-side mods)

A workspace of Unreal Engine 5 mods that all run on top of one
shared Rust framework: **`ueforge`**. Each game-side mod is a
thin consumer of the framework that contributes only
game-specific knowledge (UE class names, field offsets,
UFunction parm shapes, gameplay design).

```
┌─────────────────────────────────────────────────────────┐
│                       ueforge                           │
│  RPG · Stacks · Difficulty · Inventory · Damage         │
│  + UE SDK shim + Hooks + Debug HTTP + ImGui + Build     │
│  + Settings + Hot-reload + Test client                  │
└──────────────────────┬──────────────────────────────────┘
                       │
        ┌──────────────┼──────────────┬───────────────┐
        │              │              │               │
   ┌────▼────┐   ┌─────▼─────┐   ┌────▼────┐    ┌─────▼─────┐
   │grounded2│   │  outworld │   │  (next  │    │  (next    │
   │  -rpg   │   │  -station │   │   UE5   │    │   UE5     │
   │         │   │  -tweaks  │   │  game)  │    │   game)   │
   └─────────┘   └───────────┘   └─────────┘    └───────────┘
```

The repo's headline product is `ueforge`. Game-side mods are
consumers that prove the framework's reach and inherit every
upgrade.

## ueforge -- the framework

`ueforge` is a UE4SS Rust mod framework. It owns every pattern
that every UE5 mod reimplements: lifecycle (`ue4ss_mod!` macro,
C++ shim, hot-reload via Ctrl+R), UE SDK shim (UObject /
UClass / UFunction / GObjects / TypedField), hooks
(ProcessEvent vtable patches + per-hook drain on shutdown),
debug HTTP endpoint with op routing + auth, ImGui bindings,
build/deploy plumbing, settings with hot-reload, the test
client.

**The five opinionated pillars** ship the most common UE5 mod
shapes:

| Pillar | Module | What you write per-game |
|---|---|---|
| RPG | `ueforge::rpg` | A catalog of `Skill<E>` rows. 9 of the 10 universal skill shapes are covered by the `StandardEffect` variant menu. |
| Stacks | `ueforge::stacks` | `StackTweak::new(table, offset, default_mult, skip)` static |
| Difficulty | `ueforge::difficulty` | `DifficultyKnob::new(class, offset)` per knob |
| Inventory | `ueforge::inventory::viewport` | A `ViewportBinder` trait impl (parm shapes + bind_slot logic) |
| Damage | `ueforge::damage` | A `DamageBinder` trait impl (Critical / Evasion in `before`, Lifesteal / Thorns / kill credit in `after`) |

Pillars are independent; mods opt in to whatever they use. A
pure stack-size tweak doesn't pay for an RPG. An RPG-only mod
doesn't pay for inventory paging.

**Test framework**: `ueforge::client::{research, diff, scenario}`
collapses test boilerplate to Pester-style one-liners:

```rust
scenario::for_skill(api.inner(), "attack_damage")
    .reads(|s| Some(s.live_player.as_ref()?.asc.as_ref()?.custom_damage_multiplier))
    .should_grow_when_spent();
```

See [`ueforge/README.md`](ueforge/README.md) for the full
audit table (every framework surface mapped to game-side
consumers) and [`ueforge/docs/`](ueforge/docs/) for per-subsystem
deep dives.

## Game-side mods

### grounded2-rpg

A Factorio-style RPG / level-up mod for **Grounded 2**. The
first ueforge consumer and the workspace's most-tested mod.

- 13 skills, target ~25. `sqrt(level / 100)` diminishing returns.
- ImGui tab in UE4SS overlay; default `Insert` to summon.
- Per-playthrough persistence via UE5 save GUID.
- Combat skills (Attack Damage, Armor, Max Health, Health
  Regen, Lifesteal, Impact Damage Resistance), survival
  skills (Hunger / Thirst Resistance, Fall Damage Resistance,
  Backpack), movement skills (Move Speed, Jump Height, Glide,
  Leap Distance).
- Status-effect-system migration in flight for
  status-shaped skills (Crit / Thorns / Evasion will land
  there too).

Catalog + math + persistence: [`grounded2-rpg/docs/rpg.md`](grounded2-rpg/docs/rpg.md).
Damage internals (combat / fall / environmental, status effects,
instigator resolution): [`grounded2-rpg/docs/damage.md`](grounded2-rpg/docs/damage.md).
Build / deploy: [`grounded2-rpg/docs/building.md`](grounded2-rpg/docs/building.md).

### outworld-station-tweaks

A second UE5 mod (for **Outworld Station**) that validates
ueforge against another game. Currently ships the **stacks**
pillar: `DT_Materials.MaxCanStack` multiplier via
`ueforge::stacks::StackTweak`. Future tweaks land here.

Source: [`outworld-station-tweaks/`](outworld-station-tweaks/).
Research notes (DT walks, class lookups): the test crate's
`explore_*` tests.

### Future mods

Adding a new UE5 game mod to this workspace is the design
target. The framework's audit table in
[`ueforge/README.md`](ueforge/README.md) lists every reusable
surface; per-game crates supply only the rows under "Game-
specific" (per-build offsets, BP class names, UFunction parm
shapes, gameplay design).

## Repository layout

```
.
├── ueforge/                  -- the framework (60+ modules, 5 pillars)
├── grounded2-rpg/            -- Grounded 2 RPG / level-up mod
├── outworld-station-tweaks/  -- Outworld Station tweaks (stacks)
├── docs/                     -- workspace-level (todo, changelog)
├── Cargo.toml                -- workspace manifest
└── README.md                 -- this file
```

Per-crate docs are co-located in each crate's `docs/` folder.

## Install (per game)

Each game-side mod targets UE4SS. After installing UE4SS for
your game, deploy any of the mods:

```sh
# Grounded 2
cargo deploy install -p grounded2-rpg

# Outworld Station
cargo deploy install -p outworld-station-tweaks
```

`cargo deploy install -p <mod>` builds `main.dll`, auto-detects
the Steam install for that game (via the `[package.metadata.ueforge]`
config in the crate's Cargo.toml), copies the DLL + a default
settings.json into UE4SS's `Mods/` directory, and registers the
mod in `mods.txt`.

For redistribution: `cargo deploy package -p <mod>` produces a
Vortex-installable zip in `dist/`.

### Hot-update (Ctrl+R while the game runs)

UE4SS supports cpp-mod hot-update natively. The dev loop is:

```
1. edit Rust
2. cargo deploy install -p <mod>     # writes main-new.dll
3. alt-tab to the game, press Ctrl+R  # ~1-2s reload
4. test
```

UE4SS unloads the old DLL, the framework swaps the side-file
into place during `on_shutdown`, UE4SS reloads the new image.
Hook teardown + thread joins + vtable restoration all framework-
side (see [`ueforge/docs/lifecycle.md`](ueforge/docs/lifecycle.md)
"Hot-reload"). State on disk (save slots, settings) survives.

## Status (2026-05-10)

- **ueforge**: five pillars shipped, hot-reload (Phase A + B)
  complete, Pester-style test DSL complete. Build-clean release.
  62 unit tests passing.
- **grounded2-rpg**: 13 skills live including Lifesteal in the
  damage hook. Tested against Grounded 2 Steam build
  `++Augusta+release-0.4.0.2-CL-2673661`. In-game smoke test
  of the post-pillar architecture pending.
- **outworld-station-tweaks**: stacks tweak shipped, validates
  the framework on a second UE5 game.

Open work tracked in [`docs/todo.md`](docs/todo.md), ordered by
leverage. Chronology of milestones in
[`docs/changelog.md`](docs/changelog.md).

## Build prerequisites

- Windows 10/11 x64
- Rust toolchain (rustup; stable pinned via `rust-toolchain.toml`)
- Visual Studio Build Tools 2022+ with the C++ workload
- The target game's UE4SS install
- For framework dev: clone with submodules (`--recurse-submodules`)
  -- Dear ImGui v1.92.1 lives in a submodule.

## Docs

Workspace-level (this repo's open work + chronology) lives at
the root:

- [`docs/README.md`](docs/README.md) -- workspace docs index
- [`docs/todo.md`](docs/todo.md) -- open work across all crates
- [`docs/changelog.md`](docs/changelog.md) -- milestones, newest first

Framework docs are in [`ueforge/docs/`](ueforge/docs/):

- [`ueforge/README.md`](ueforge/README.md) -- entry point + audit
  table mapping every framework surface to game-side consumers
- [`ueforge/docs/PERFORMANCE.md`](ueforge/docs/PERFORMANCE.md) -- hot-path doctrine
- [`ueforge/docs/RESEARCH.md`](ueforge/docs/RESEARCH.md) -- TDD investigation methodology
- [`ueforge/docs/lifecycle.md`](ueforge/docs/lifecycle.md) -- `ue4ss_mod!`, hot-reload, build/deploy
- [`ueforge/docs/ue-sdk.md`](ueforge/docs/ue-sdk.md) -- UE SDK shim
- [`ueforge/docs/hooks.md`](ueforge/docs/hooks.md) -- ProcessEvent + hook teardown
- [`ueforge/docs/rpg.md`](ueforge/docs/rpg.md) -- RPG pillar
- [`ueforge/docs/testing.md`](ueforge/docs/testing.md) -- test client + research/diff/scenario DSL
- (and the rest -- per-subsystem reference)

Per-mod docs live next to the mod's source.

## Credits

- **UE4SS-RE** for [RE-UE4SS](https://github.com/UE4SS-RE/RE-UE4SS),
  the CPPMod host every mod here targets.
- **x0reaxeax** for [Grounded2Minimal](https://github.com/x0reaxeax/Grounded2Minimal)
  and [G2Dumper](https://github.com/x0reaxeax/G2Dumper).
- **Encryqed** for [Dumper-7](https://github.com/Encryqed/Dumper-7),
  the SDK generator that produced reference headers for every
  game we target.
- **RLGingerBiscuit** for [G2Utils](https://github.com/RLGingerBiscuit/G2Utils),
  which corroborated class names + inventory bindings on
  Grounded 2.
- **Trumank** for [retoc](https://github.com/trumank/retoc) and
  [repak](https://github.com/trumank/repak), used during early
  pak-prototype work.
- **4sval** for [FModel](https://github.com/4sval/FModel), used
  for cooked asset inspection.
- **Caites** for [Player Tweaks](https://www.nexusmods.com/grounded2/mods/13)
  on Nexus, whose feature list shaped the Grounded 2 catalog.
- The author of [Bigger Backpack](https://www.nexusmods.com/grounded2/mods/37),
  whose mod's breakage motivated the data-side + visible-side
  patching pattern.
- The author of [**RPG System**](https://mods.factorio.com/mod/RPGsystem)
  for Factorio -- the headline RPG-style level-up mod whose
  vocabulary `grounded2-rpg` borrows verbatim.
- The author of [**RimWorld RPG Mod / Combat Skills RPG**](https://steamcommunity.com/sharedfiles/filedetails/?id=2891939858).
- The authors of the [War3CS / War3FT](https://war3cs2.wiki.gg/)
  Counter-Strike Warcraft mod line, whose flat-skill-catalog
  pattern shapes the RPG catalog layout.
- The game studios whose UE5 titles we mod (Obsidian Entertainment
  for [Grounded 2](https://grounded2.obsidian.net/) and the
  Outworld Station team). We modify only what the official games
  ship under fair-use modding norms; no game assets are
  redistributed.
