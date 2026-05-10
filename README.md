# Grounded 2 - RPG System

A Factorio-style RPG / level-up mod for **Grounded 2**, loaded by
UE4SS as a CPPMod (Rust + a tiny C++ shim).

Kill creatures -> earn XP -> level up -> spend skill points ->
level up your player. The catalog is classless and flat: build a
tank, glass cannon, hauler, or speed demon by spending points
wherever you want.

## Inspiration

- [**RPG System**](https://mods.factorio.com/mod/RPGsystem) for
  Factorio.
- [**RimWorld RPG Mod**](https://steamcommunity.com/sharedfiles/filedetails/?id=2891939858)
  (a.k.a. Combat Skills RPG) for RimWorld.

Same loop: kills become XP, XP becomes levels, levels become a
stronger character. Vocabulary (XP, level, skill, skill point)
borrowed verbatim from RPG System for Factorio. The
flat-skill-catalog shape comes from
[War3CS / War3FT](https://war3cs2.wiki.gg/).

## Skill catalog

Currently 13 skills, target ~25. Each caps at level 100 with a
`sqrt(level / 100)` diminishing-returns curve. Full math in
[`grounded2-rpg/docs/rpg.md`](grounded2-rpg/docs/rpg.md).

| Skill | Domain | Final value at level 100 |
| --- | --- | --- |
| Backpack | survival | +460 slots (40 vanilla -> 500) |
| Hunger Resistance | survival | -75% drain |
| Thirst Resistance | survival | -75% drain |
| Attack Damage | combat | +300% damage |
| Armor | combat | -50% damage taken |
| Move Speed | movement | +300% walk + sprint + swim |
| Jump Height | movement | +300% jump-Z velocity |
| Glide Speed | movement | +300% MaxFlySpeed |
| Leap Distance | movement | +500% air control |
| Fall Damage Resistance | survival | full immunity |
| Impact Damage Resistance | survival | full immunity to environmental / hazard damage |
| Lifesteal | combat | +90% of damage dealt healed back |
| Max Health | combat | +200 HP |
| Health Regen | combat | +500% out-of-combat regen tick + 6× rate |

Skills are spent through an "RPG" tab in the UE4SS ImGui debug
overlay (default `Insert` key in-game). Each skill row has +1 /
+10 / -1 / -10 buttons + an on-toggle that drops the buff
without refunding points.

## Repository layout

This is a Cargo workspace with multiple crates:

| Crate | Purpose |
| --- | --- |
| [`ueforge/`](ueforge/) | The UE4SS Rust mod framework. Lifecycle, UE SDK shim, hooks, HTTP control plane, ImGui bindings, RPG framework, build/deploy plumbing, doctrine docs. |
| [`grounded2-rpg/`](grounded2-rpg/) | Grounded 2 mod -- this repo's headline product. Built on ueforge. |
| [`outworld-station-tweaks/`](outworld-station-tweaks/) | A second UE5 mod (Outworld Station). Validates ueforge against another UE5 game. |
| [`ueforge-deploy/`](ueforge-deploy/) | The `cargo deploy` CLI binary. |

`ueforge` is reusable for any UE4SS Rust mod. The G2-specific
content (offsets, skill effect variants, catalog rows, hooks,
parm structs) lives in `grounded2-rpg/`. Most of what looks like
infrastructure here is actually framework code consumable by any
future UE-mod consumer.

## Status (2026-05-10)

Tested against Grounded 2 Steam build
`++Augusta+release-0.4.0.2-CL-2673661`.

- UE4SS CPPMod load path working.
- Full RPG loop live: XP, levels, skill points, persistence
  keyed to playthrough GUID, Buggy kill attribution, ImGui
  `RPG` tab.
- Major dedup wave landed 2026-05-10 -- ~17 commits promoting
  load-bearing infrastructure from `grounded2-rpg/` into
  `ueforge/`. The mod crate now contains only G2-specific
  content. Build-clean release; **in-game smoke test pending**.
- Fall Damage Resistance -- velocity-stomp on `OnLanded` (works
  for fall landings; collisions handled by Impact Damage Resistance).
- Impact Damage Resistance -- `Runtime` intercept on
  `ApplyDamageFromInfo` that scales environmental damage by
  `(1 - reduction * progress)`. Bandages, creature combat, and
  fall damage are unaffected. Status-effect-system migration is
  in flight to make this scaling proper-multiplicative; see
  [`grounded2-rpg/docs/damage.md`](grounded2-rpg/docs/damage.md).
- Open work: live-instance writes for remaining combat skills,
  status-effect-backed skill rewrite, catalog expansion,
  Vortex / Nexus packaging. See [`docs/todo.md`](docs/todo.md).

## Install

The shipping shape is a UE4SS C++ mod. Drop the DLL into
UE4SS's `Mods/` directory; UE4SS handles loading.

For development, clone with submodules (Dear ImGui v1.92.1 lives
in a submodule):

```sh
git clone --recurse-submodules <repo>
# or, if you already cloned:
git submodule update --init --recursive
```

Then:

```sh
cargo deploy install -p grounded2-rpg
```

Builds `main.dll`, copies it into the autodetected Steam
install, seeds `settings.json`, registers the mod in
`mods.txt`. Pure Rust -- no PowerShell. Mod-side install
metadata lives under `[package.metadata.ueforge]` in the
crate's `Cargo.toml`.

`cargo deploy package -p grounded2-rpg` produces a
Vortex-installable zip in `dist/`.

Build details:
[`grounded2-rpg/docs/building.md`](grounded2-rpg/docs/building.md).

## Config

Runtime config in `<install-dir>/dlls/settings.json`.
Defaults are vanilla-base; skills layer on top.

```json
{
  "inventory":  { "slot_count": 40 },
  "survival":   { "hunger_multiplier": 1.0, "thirst_multiplier": 1.0 },
  "rpg":        { "buggy_kill_xp_multiplier": 1.0 }
}
```

Skill levels then add (backpack) or further multiply (survival
drains) on top of the user's base.

## Docs

Per-crate documentation is co-located with each crate's source.
Workspace-level concerns (cross-cutting open work, chronology)
live at the repo root.

### Workspace

| Doc | What lives there |
| --- | --- |
| [`docs/README.md`](docs/README.md) | Workspace docs index |
| [`docs/todo.md`](docs/todo.md) | Open work across all crates |
| [`docs/changelog.md`](docs/changelog.md) | Chronology of milestones |

### ueforge framework

| Doc | What lives there |
| --- | --- |
| [`ueforge/README.md`](ueforge/README.md) | Framework entry point + audit table |
| [`ueforge/docs/PERFORMANCE.md`](ueforge/docs/PERFORMANCE.md) | Hot-path discipline doctrine |
| [`ueforge/docs/RESEARCH.md`](ueforge/docs/RESEARCH.md) | TDD investigation methodology |
| [`ueforge/docs/`](ueforge/docs/) | Per-subsystem reference: lifecycle, ue-sdk, hooks, pe-queue, counters, rpg, http, imgui, settings, worker, data-table, memory-tools |

### grounded2-rpg

| Doc | What lives there |
| --- | --- |
| [`grounded2-rpg/docs/README.md`](grounded2-rpg/docs/README.md) | bbp docs index + "where to look first" matrix |
| [`grounded2-rpg/docs/rpg.md`](grounded2-rpg/docs/rpg.md) | RPG subsystem: catalog, math, persistence, code map |
| [`grounded2-rpg/docs/damage.md`](grounded2-rpg/docs/damage.md) | Grounded 2 damage internals: combat, fall, environmental, status effects, instigator resolution |
| [`grounded2-rpg/docs/inventory.md`](grounded2-rpg/docs/inventory.md) | Backpack patch + viewport rebind |
| [`grounded2-rpg/docs/engine.md`](grounded2-rpg/docs/engine.md) | UE5 platform: pak, exes, GObjects, shipping caveats |
| [`grounded2-rpg/docs/performance.md`](grounded2-rpg/docs/performance.md) | What the mod costs to run |
| [`grounded2-rpg/docs/ongoing.md`](grounded2-rpg/docs/ongoing.md) | Code that runs continuously |
| [`grounded2-rpg/docs/testing.md`](grounded2-rpg/docs/testing.md) | Debug HTTP endpoint + integration tests |
| [`grounded2-rpg/docs/features.md`](grounded2-rpg/docs/features.md) | User-facing features |
| [`grounded2-rpg/docs/building.md`](grounded2-rpg/docs/building.md) | Build, install, deploy |
| [`grounded2-rpg/docs/rust-port.md`](grounded2-rpg/docs/rust-port.md) | Historical: C++ -> Rust port |
| [`grounded2-rpg/docs/ue4ss-port.md`](grounded2-rpg/docs/ue4ss-port.md) | Historical: custom DLL injection -> UE4SS CPPMod |

## Credits

- **UE4SS-RE** for [RE-UE4SS](https://github.com/UE4SS-RE/RE-UE4SS),
  the CPPMod host we target for loading, UI integration, and
  standard Grounded 2 mod distribution.
- **x0reaxeax** for [Grounded2Minimal](https://github.com/x0reaxeax/Grounded2Minimal)
  (DLL-injection pattern) and [G2Dumper](https://github.com/x0reaxeax/G2Dumper).
- **Encryqed** for [Dumper-7](https://github.com/Encryqed/Dumper-7),
  the SDK generator that produced our reference headers.
- **RLGingerBiscuit** for [G2Utils](https://github.com/RLGingerBiscuit/G2Utils),
  which corroborated class names and inventory component bindings.
- **Trumank** for [retoc](https://github.com/trumank/retoc) and
  [repak](https://github.com/trumank/repak), used during early
  pak-prototype work.
- **4sval** for [FModel](https://github.com/4sval/FModel), used
  for cooked asset inspection.
- **Caites** for [Player Tweaks](https://www.nexusmods.com/grounded2/mods/13)
  on Nexus, whose feature list is the reference point in
  [`grounded2-rpg/docs/features.md`](grounded2-rpg/docs/features.md).
- The author of [Bigger Backpack](https://www.nexusmods.com/grounded2/mods/37),
  whose mod's breakage in the current shipping build motivated
  the data-side + visible-side patching pattern documented in
  [`grounded2-rpg/docs/inventory.md`](grounded2-rpg/docs/inventory.md).
- The author of [**RPG System**](https://mods.factorio.com/mod/RPGsystem)
  for Factorio -- the headline RPG-style level-up mod whose
  name and vocabulary this mod borrows verbatim. The XP /
  level / skill / skill-point loop is theirs.
- The author of [**RimWorld RPG Mod / Combat Skills RPG**](https://steamcommunity.com/sharedfiles/filedetails/?id=2891939858)
  for RimWorld -- the second of the two existing RPG-mod
  inspirations.
- The authors of the [War3CS / War3FT](https://war3cs2.wiki.gg/)
  Counter-Strike Warcraft mod line, whose flat-skill-catalog
  pattern shapes the catalog layout.
- [Grounded 2](https://grounded2.obsidian.net/) by Obsidian
  Entertainment. We modify only what the official game ships
  under fair-use modding norms; no game assets are
  redistributed.
