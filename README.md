# Grounded 2 Mods

Runtime DLL mod for Grounded 2 (Obsidian, Unreal Engine 5.4). Patches
the player's main backpack capacity and the per-second hunger / thirst
drain rates. Configurable at runtime via a JSON file. Survives game
patches as long as engine offsets don't shift; if they do, one Rust
file gets updated.

## Status

Functional and validated in-game on Grounded 2 v0.4.0.2 (Steam, April
2026). Open work is distribution: switching from the dev-time
`inject.exe` shape to a self-loading DLL proxy so the mod can ship
through Vortex / Nexus.

## Quick links

Each doc is the authority on one subject; the header on each
file states what.

| If you want | Read |
| --- | --- |
| Build, install, and run as a developer | [docs/building.md](docs/building.md) |
| The list of features and how they compare to other Grounded 2 mods | [docs/features.md](docs/features.md) |
| What this costs to run (CPU, threads, frame impact) | [docs/performance.md](docs/performance.md) |
| The RPG / level-up system (skills, XP, persistence, UI) | [docs/rpg.md](docs/rpg.md) |
| What's next | [TODO.md](TODO.md) |
| What's already done (chronological) | [docs/changelog.md](docs/changelog.md) |
| The C++-to-Rust port history | [docs/rust-port.md](docs/rust-port.md) |
| The pivot to a UE4SS C++ mod shape | [docs/ue4ss-port.md](docs/ue4ss-port.md) |
| The original C++ implementation (kept for reference) | [better-backpack-cpp/](better-backpack-cpp/) |

## Repo layout

```
grounded2mods/
  README.md                You are here.
  Cargo.toml               Workspace: better-backpack + injector.
  rust-toolchain.toml      Stable Rust, x86_64-pc-windows-msvc target.
  .cargo/config.toml       Workspace target dir override.

  better-backpack/         The mod itself (cdylib + rlib).
    src/
      lib.rs               DllMain + worker entry.
      sdk/                 Hand-written UE SDK shim.
      hook/                vtable patcher + RAII ProcessEventHook.
      log.rs               File + console log sink.
      patch.rs             Backpack DefaultMaxSize patcher.
      survival.rs          Hunger + thirst rate patcher.
      inv_hook.rs          WBP_InventoryInterface_C hook + viewport rebind.
      parms.rs             #[repr(C)] parms structs with layout asserts.
      settings.rs          JSON settings loader.
    tests/layout.rs        Static layout assertions.
    settings.example.json  Schema example to copy as settings.json.

  injector/                Standalone DLL injector (dev-time tool).
    src/main.rs            Process discovery + LoadLibrary remote thread.
    src/config.rs          inject.json loader.
    src/launcher.rs        Steam URI launch + process polling.
    inject.example.json    Schema example.

  better-backpack-cpp/     Original C++ implementation, kept for reference.

  scripts/                 Python utilities for cooked-asset inspection.

  docs/                    Subject-authority docs. Each file's
                           header states what it owns.
    building.md            Build / run / configure.
    features.md            Player-facing feature list + comparison
                           vs Player Tweaks (Caites).
    performance.md         Per-call costs, hot paths.
    rpg.md                 RPG / level-up system (skills, XP,
                           kill detection, persistence, UI).
    rust-port.md           C++ -> Rust port history.
    ue4ss-port.md          Pivot to UE4SS C++ mod shape.
    changelog.md           Chronological history of what's done.
  TODO.md                  What's next (only).
```

## TL;DR

- The mod is a Rust cdylib injected into the running game process.
- Runtime config via `<DLL_dir>/settings.json` (defaults baked in,
  file is optional). See `better-backpack/settings.example.json`.
- Default behavior with no settings file:
  - Player main backpack: 40 -> 100 slots, 4x10 viewport with
    mouse-wheel scrolling for the extra rows.
  - Mount/saddlebag (vanilla 30) preserved.
  - Hunger drain: 0.5x vanilla.
  - Thirst drain: 0.5x vanilla.
- Patches the Class Default Object once at DLL load. Sticky for the
  whole session: every subsequent save load constructs a new player
  inventory against the patched CDO. No rescan loop; worker thread
  exits after init.

## How to use it today (developer flow)

1. `cargo build --release` from the repo root. Outputs:
   - `target/x86_64-pc-windows-msvc/release/winhttp.dll`
   - `target/x86_64-pc-windows-msvc/release/inject.exe`
2. Launch Grounded 2 and load a save.
3. Run `inject.exe` from the same dir. With no Grounded process
   running it auto-launches via Steam (`steam://rungameid/3104110`),
   polls until the process appears, then injects.
4. A "Better Backpack" console window pops up showing live mod log.
   `<DLL_dir>/better_backpack.log` mirrors it.

Full instructions in [docs/building.md](docs/building.md).

## Distribution path (planned)

End users won't run inject.exe. The plan (see
[docs/ue4ss-port.md](docs/ue4ss-port.md) and the Distribution
section in [TODO.md](TODO.md)) is to ship as a **UE4SS C++ mod (CPPMod)**
keeping the source in Rust. UE4SS for Grounded 2 is already a
mature Vortex mod (Nexus #52); riding on it gets us Vortex
distribution out of the box, central engine-offset maintenance, and
the network effect of being inside the standard UE5 mod ecosystem.

Layout:

```
Augusta/Binaries/WinGRTS/ue4ss/Mods/BetterBackpack/
  dlls/main.dll          (Rust cdylib + tiny C++ shim derived from
                          RC::CppUserModBase, forwards UE4SS
                          lifecycle calls to extern "C" Rust)
  settings.json          (user-editable config)
```

We previously built a `winhttp.dll` proxy (commits 514e2b1..bfb3447)
that works correctly without UE4SS. It will be archived to
`archive/winhttp-proxy/` once the UE4SS path lands, kept as a
fallback if UE4SS ever turns out unstable for Grounded 2. See
[docs/features.md](docs/features.md) for the comparison of UE mod formats
and why DLL beats pak for our case.

## Game build referenced

```
Grounded 2 Steam, version ++Augusta+release-0.4.0.2-CL-2673661
UE 5.4 shipping, unencrypted IoStore.
SDK dump captured by Dumper-7, headers at C:\Tools\work\sdk\.
```

When the game patches and engine offsets shift, the constants in
`better-backpack/src/sdk/offsets.rs` need a one-time refresh from a
freshly dumped SDK. Mod logic stays the same.

## Credits

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
  [docs/features.md](docs/features.md).
- The author of [Bigger Backpack](https://www.nexusmods.com/grounded2/mods/37),
  whose mod's breakage motivated the rewrite this repo represents.
- The author of [RPG System](https://mods.factorio.com/mod/RPGsystem)
  for Factorio, the headline RPG-style level-up mod that inspired
  the direction this project is now taking. Our XP / level / skill /
  skill-point vocabulary is borrowed directly from theirs (and the
  broader Diablo-like RPG mod tradition on the Factorio mod portal).
- [Grounded 2](https://grounded2.obsidian.net/) by Obsidian
  Entertainment. We modify only what the official game ships under
  fair-use modding norms; no game assets are redistributed.
