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

| If you want | Read |
| --- | --- |
| Build, install, and run as a developer | [BUILDING.md](BUILDING.md) |
| The list of features and how they compare to other Grounded 2 mods | [FEATURES.md](FEATURES.md) |
| What this costs to run (CPU, threads, frame impact) | [PERFORMANCE.md](PERFORMANCE.md) |
| Open work and the distribution plan | [TODO.md](TODO.md) |
| The C++-to-Rust port history and the bugs we hit | [RUST_PORT_PLAN.md](RUST_PORT_PLAN.md) |
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

  BUILDING.md              Build / run / configure.
  FEATURES.md              What the mod does + comparison table of UE
                           mod formats and feature parity vs Player
                           Tweaks (Caites).
  PERFORMANCE.md           Per-call costs, hot paths, what was
                           deliberately not ported from the C++ tree.
  RUST_PORT_PLAN.md        The 11-step migration plan and the bugs
                           found during testing.
  TODO.md                  Open work (distribution + future feature
                           ports).
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
   - `target/x86_64-pc-windows-msvc/release/better_backpack.dll`
   - `target/x86_64-pc-windows-msvc/release/inject.exe`
2. Launch Grounded 2 and load a save.
3. Run `inject.exe` from the same dir. With no Grounded process
   running it auto-launches via Steam (`steam://rungameid/3104110`),
   polls until the process appears, then injects.
4. A "Better Backpack" console window pops up showing live mod log.
   `<DLL_dir>/better_backpack.log` mirrors it.

Full instructions in [BUILDING.md](BUILDING.md).

## Distribution path (planned)

End users won't run inject.exe. The plan (see
[TODO.md](TODO.md) #1) is to repackage the DLL as a Windows
**DLL proxy** named `winhttp.dll` -- dropped into the game's
`Augusta\Binaries\Win64\` folder, Windows auto-loads it at game start
(same-directory takes precedence over System32), our `DllMain`
worker thread runs immediately, and we forward all real `winhttp`
exports to the system copy so game network calls keep working. This
is the same shape UE4SS, ReShade, and ENB use. Vortex installs it as
a regular file drop. See [FEATURES.md](FEATURES.md) for the full
comparison of UE mod formats and why proxy beats pak for our case.

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
  on Nexus -- whose feature list is the reference point in
  [FEATURES.md](FEATURES.md).
- The author of [Bigger Backpack](https://www.nexusmods.com/grounded2/mods/37),
  whose mod's breakage motivated the rewrite this repo represents.
- [Grounded 2](https://grounded2.obsidian.net/) by Obsidian
  Entertainment. We modify only what the official game ships under
  fair-use modding norms; no game assets are redistributed.
