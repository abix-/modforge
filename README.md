# grounded2mods

Grounded 2 UE4SS CPPMod written mostly in Rust. Current focus is a
Factorio-style RPG / level-up system: kills grant XP, XP grants levels
and skill points, and skill levels patch player stats in-game.

## Status

Current state as of 2026-05-05:

- UE4SS load path is working in-game on Grounded 2 Steam
  `++Augusta+release-0.4.0.2-CL-2673661`.
- The RPG loop is live: XP, levels, skill points, persistence, Buggy
  kill attribution, and the UE4SS ImGui RPG tab.
- The backpack skill, hunger/thirst resistance, and several combat /
  movement skills are implemented.
- Open work is testing, live-instance writes for some skills, catalog
  expansion, and packaging cleanup. See [TODO.md](TODO.md).

This repo no longer targets a standalone end-user injector flow as the
primary path. The shipping shape is a **UE4SS C++ mod (CPPMod)** with a
tiny C++ shim and the mod logic in Rust.

## What It Does

- Tracks creature kills and awards XP.
- Levels the player with a cumulative `100 * N^1.8` XP curve, capped at
  level 50.
- Grants skill points on level-up.
- Persists RPG state per playthrough GUID under
  `Mods/BetterBackpack/dlls/saves/<guid>.json`.
- Applies skill values to game CDOs on save activation.
- Exposes an `RPG` tab in the UE4SS overlay with `+1` / `+10` spend
  buttons.

Current skill catalog is documented in [docs/rpg.md](docs/rpg.md).

## Install Layout

UE4SS expects the mod DLL here:

```text
Augusta/Binaries/WinGRTS/ue4ss/Mods/BetterBackpack/
  dlls/main.dll
  dlls/settings.json
  dlls/better_backpack.log
  dlls/cpp_shim.log
  dlls/saves/
```

`dlls/` is required by UE4SS for CPPMods. `main.dll` must stay there.
Runtime companion files are kept next to it.

## Developer Flow

Build:

```powershell
cargo build --release
```

Direct local install into the detected Steam copy:

```powershell
.\scripts\deploy.ps1 -Install
```

That installs `main.dll`, seeds `dlls/settings.json` if missing, and
ensures `BetterBackpack : 1` is present in `mods.txt`.

Full build / install details live in [docs/building.md](docs/building.md).

## Config

Runtime config lives at:

```text
Augusta/Binaries/WinGRTS/ue4ss/Mods/BetterBackpack/dlls/settings.json
```

Defaults are vanilla-base:

- `inventory.slot_count = 40`
- `survival.hunger_multiplier = 1.0`
- `survival.thirst_multiplier = 1.0`
- `rpg.buggy_kill_xp_multiplier = 1.0`

Skills layer on top of those base values. Schema example:
[better-backpack/settings.example.json](better-backpack/settings.example.json).

## Docs

- [docs/building.md](docs/building.md): build, install, package
- [docs/rpg.md](docs/rpg.md): RPG system, skills, XP, persistence, UI
- [docs/ue4ss-port.md](docs/ue4ss-port.md): UE4SS CPPMod shape and port history
- [docs/changelog.md](docs/changelog.md): completed work
- [TODO.md](TODO.md): open work only
- [.claude/project_state.md](.claude/project_state.md): current handoff / session state

## Repo Layout

```text
grounded2mods/
  better-backpack/        Main mod crate (Rust + C++ shim + vendored imgui)
  injector/               Old dev-time injector crate, kept for iteration history
  docs/                   Subject-authority docs
  scripts/deploy.ps1      Build/package/install helper for UE4SS layout
  better-backpack-cpp/    Original C++ implementation kept for reference
  TODO.md                 Open work
```

## Notes

- Some skill effects are still CDO-only. Spending a point may require a
  reload to affect the current live pawn until live-instance writes are
  implemented.
- Lifesteal is in the catalog but its live damage hook work is still
  pending.
- When the game updates and offsets shift, refresh
  [better-backpack/src/sdk/offsets.rs](better-backpack/src/sdk/offsets.rs).

## Credits

- [UE4SS-RE / RE-UE4SS](https://github.com/UE4SS-RE/RE-UE4SS)
- [Encryqed / Dumper-7](https://github.com/Encryqed/Dumper-7)
- [x0reaxeax / Grounded2Minimal](https://github.com/x0reaxeax/Grounded2Minimal)
- [RLGingerBiscuit / G2Utils](https://github.com/RLGingerBiscuit/G2Utils)
- [Factorio RPG System](https://mods.factorio.com/mod/RPGsystem) for the design inspiration
