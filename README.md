# RPG System

A Factorio-style RPG / level-up mod for **Grounded 2**, loaded by
UE4SS as a CPPMod (Rust + a tiny C++ shim).

Kill creatures -> earn XP -> level up -> spend skill points -> level
up your player. The catalog is classless and flat: build a tank,
glass cannon, hauler, or speed demon by spending points wherever you
want.

## Inspiration

Two of my favorite games already have RPG mods I love. This is
those, ported into Grounded 2:

- [**RPG System**](https://mods.factorio.com/mod/RPGsystem) for
  Factorio.
- [**RimWorld RPG Mod**](https://steamcommunity.com/sharedfiles/filedetails/?id=2891939858)
  (a.k.a. Combat Skills RPG) for RimWorld.

Same loop in both: kills become XP, XP becomes levels, levels
become a stronger character. Vocabulary (XP, level, skill, skill
point) is borrowed verbatim from RPG System for Factorio.

The other heavy reference is the Counter-Strike line of
[War3CS / War3FT](https://war3cs2.wiki.gg/) Warcraft mods, where
players spend a flat skill catalog to specialize.

## Skill catalog

Currently 11 skills, target ~25. Each skill caps at level 100 with a
`sqrt(level / 100)` diminishing-returns curve. See
[`docs/rpg.md`](docs/rpg.md) for the full catalog with per-skill
math.

| Skill | Domain | Final value at level 100 |
| ----- | ------ | ----------------------- |
| Backpack | survival | +460 slots (40 vanilla -> 500) |
| Hunger Resistance | survival | -75% drain |
| Thirst Resistance | survival | -75% drain |
| Attack Damage | combat | +300% damage |
| Armor | combat | -50% damage taken |
| Move Speed | movement | +300% walk + sprint + swim |
| Jump Height | movement | +300% jump-Z velocity |
| Glide Speed | movement | +300% MaxFlySpeed |
| Fall Damage Resistance | survival | full immunity |
| Impact Damage Resistance | survival | full immunity to rock / hazard / environmental damage |
| Lifesteal | combat | +90% of damage dealt healed back |

Skills are spent through an "RPG" tab in the UE4SS ImGui debug
overlay (default `Insert` key in-game).

## Status

As of 2026-05-05, against Grounded 2 Steam
`++Augusta+release-0.4.0.2-CL-2673661`:

- UE4SS CPPMod load path working.
- Full RPG loop live: XP, levels, skill points, persistence keyed
  to playthrough GUID, Buggy kill attribution, ImGui `RPG` tab.
- Fall Damage Resistance landed via velocity-stomp on `OnLanded`.
- Impact Damage Resistance landed via
  `UHealthComponent.RequiredDamageTypeFlags = 0xFFFFFFFF` -- the
  native ApplyDamage gate rejects damage with `type_flags = 0`
  (fall, environmental, hazard zones) while creature attacks pass
  through normally. See [`docs/damage.md`](docs/damage.md) for the
  deep dive on the three Grounded 2 damage paths.
- Open work: live-instance writes for remaining combat skills,
  catalog expansion, packaging cleanup. See
  [`docs/todo.md`](docs/todo.md).

## Install

The shipping shape is a UE4SS C++ mod. Drop the DLL into UE4SS's
`Mods/` directory; UE4SS handles loading.

For development:

```sh
cargo deploy install -p grounded2-rpg
```

This builds `main.dll`, copies it into the detected Steam install,
seeds `settings.json`, and ensures the mod is registered in
`mods.txt`. Pure Rust -- no PowerShell. The `cargo deploy` alias
points at the `ueforge-deploy` binary; mod-side install metadata
lives under `[package.metadata.ueforge]` in each mod's `Cargo.toml`.

Full build details: [`docs/building.md`](docs/building.md).

## Config

Runtime config in `<install-dir>/dlls/settings.json`. Defaults are
vanilla-base; skills layer on top.

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

| Doc | What lives there |
| --- | ---------------- |
| [`docs/rpg.md`](docs/rpg.md) | RPG / skill subsystem: catalog, math, ImGui tab, persistence, code map |
| [`docs/damage.md`](docs/damage.md) | Grounded 2 damage internals: fall path, environmental path, multicast surfaces, kill detection |
| [`docs/inventory.md`](docs/inventory.md) | Backpack and inventory grid mechanics |
| [`docs/grounded-engine.md`](docs/grounded-engine.md) | Grounded 2 / UE5 platform: pak format, exe names, GObjects offsets, shipping caveats |
| [`docs/building.md`](docs/building.md) | Build, install, deploy |
| [`docs/features.md`](docs/features.md) | User-facing feature list and comparison to Player Tweaks |
| [`docs/changelog.md`](docs/changelog.md) | Done milestones |
| [`docs/todo.md`](docs/todo.md) | Open work |
| [`docs/ue4ss-port.md`](docs/ue4ss-port.md), [`docs/rust-port.md`](docs/rust-port.md) | Loader / port history |

## Internal naming note

The on-disk artifact names still refer to the project's earlier
identity (`Grounded2RPG` mod folder, `grounded2-rpg/` Rust
crate, `grounded2_rpg.log`). The user-facing brand and display
name is "RPG System"; an internal rename pass is tracked in
[`docs/todo.md`](docs/todo.md). It does not affect functionality,
only the on-disk file names.

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
- **4sval** for [FModel](https://github.com/4sval/FModel), used for
  cooked asset inspection.
- **Caites** for [Player Tweaks](https://www.nexusmods.com/grounded2/mods/13)
  on Nexus, whose feature list is the reference point in
  [`docs/features.md`](docs/features.md).
- The author of [Bigger Backpack](https://www.nexusmods.com/grounded2/mods/37),
  whose mod's breakage in the current shipping build motivated the
  data-side + visible-side patching pattern documented in
  [`docs/inventory.md`](docs/inventory.md).
- The author of [**RPG System**](https://mods.factorio.com/mod/RPGsystem)
  for Factorio -- the headline RPG-style level-up mod whose name and
  vocabulary this mod borrows verbatim. The XP / level / skill /
  skill-point loop is theirs.
- The author of [**RimWorld RPG Mod / Combat Skills RPG**](https://steamcommunity.com/sharedfiles/filedetails/?id=2891939858)
  for RimWorld -- the second of the two existing RPG-mod
  inspirations.
- The authors of the [War3CS / War3FT](https://war3cs2.wiki.gg/)
  Counter-Strike Warcraft mod line, whose flat-skill-catalog pattern
  shapes the catalog layout.
- [Grounded 2](https://grounded2.obsidian.net/) by Obsidian
  Entertainment. We modify only what the official game ships under
  fair-use modding norms; no game assets are redistributed.
