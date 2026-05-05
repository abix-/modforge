# Building Better Backpack (Rust)

The mod is a Cargo workspace with two crates:

- **better-backpack** -- the cdylib injected into the game process.
- **injector** -- the standalone exe that finds the running game and pokes
  `LoadLibraryA` to map the DLL.

Single `cargo build` produces both artifacts.

## Prerequisites

- Windows 10/11 x64.
- Rust toolchain. The repo pins `stable` via `rust-toolchain.toml` and
  installs the `x86_64-pc-windows-msvc` target automatically. Install
  `rustup` from <https://rustup.rs> if you don't have it.
- Visual Studio Build Tools 2019+ with the C++ workload (provides MSVC
  linker). Required by the MSVC target triple.

You do **not** need to install Dumper-7 or any C++ SDK headers. The Rust
crate carries a hand-written shim for the small subset of UE types we
touch (`better-backpack/src/sdk/`).

## Build

From the repo root:

```
cargo build --release
```

Outputs:

- `target/x86_64-pc-windows-msvc/release/winhttp.dll`
- `target/x86_64-pc-windows-msvc/release/inject.exe`

The build target dir is locked to `target/` via `.cargo/config.toml`. If
you have a global `~/.cargo/config.toml` redirecting builds elsewhere, the
project-level config wins.

## Package for Vortex / Nexus distribution

```
.\scripts\deploy.ps1
```

Default mode. Builds the release cdylib and writes
`dist\better-backpack-v<version>.zip` ready to upload to Nexus or
import into Vortex. The zip contains:

- `winhttp.dll` -- the mod proxy
- `settings.json` -- default config users can edit
- `setup.ps1` -- one-shot post-install script that copies
  `C:\Windows\System32\winhttp.dll` to the install folder as
  `winhttp_orig.dll`. This step is required because Vortex never
  touches system files; we ship the script so the user (or a Vortex
  install hook) can run it after deployment.
- `README.txt` -- end-user install + uninstall instructions.

`dist/` is gitignored.

## Direct local install (skip Vortex / Nexus)

```
.\scripts\deploy.ps1 -Install
```

Builds, locates the game's `Augusta\Binaries\Win64` (auto-detects from
the Steam library; pass `-GamePath` to override), copies our
`winhttp.dll` there, copies `C:\Windows\System32\winhttp.dll` alongside
as `winhttp_orig.dll`, and seeds a default `settings.json` if one
isn't already there. Launch the game normally.

Uninstall:

```
.\scripts\deploy.ps1 -Uninstall
```

Removes our `winhttp.dll`. Leaves `winhttp_orig.dll`, `settings.json`,
and `better_backpack.log` in place. Add `-PurgeOrig` to also remove
`winhttp_orig.dll`.

## Run via inject.exe (developer / iteration flow)

The injector path is the fastest dev loop -- you don't need to close
the game and redeploy to swap in a new build. It's also what runs if
you want to test without committing to a winhttp.dll proxy install.

Close any prior copy of the DLL first -- once mapped into the game
process, Windows holds the file lock until the process exits.

1. Launch Grounded 2. Steam build is `Grounded2-WinGRTS-Shipping.exe`;
   Xbox Game Pass is `Grounded2-WinGDK-Shipping.exe`. Either is auto
   detected.
2. Load a save and let the world finish loading.
3. From `target/x86_64-pc-windows-msvc/release/`, run `inject.exe`.
   With no arguments it:
   - Picks `winhttp.dll` next to itself as the DLL to inject.
   - If Grounded is already running, injects into that process.
   - Otherwise launches Grounded via Steam
     (`steam://rungameid/<steam_app_id>`), polls until the process
     appears, then injects. Configure via `inject.json` next to
     inject.exe (see `injector/inject.example.json`).
   - Pass `--no-launch` to disable auto-launch and require the game to
     already be running.

What you should see:

- A new console window titled "Better Backpack" pops up in the game
  process. It tails the live mod log.
- `<DLL_dir>\better_backpack.log` mirrors that output (file lives next
  to the DLL, not in `%TEMP%`).
- `inject.log` next to `inject.exe` captures the injector's own steps.
  inject.exe runs and exits without pausing -- read `inject.log` if you
  need to see what happened.

Expected first-run log markers:

```
=== Better Backpack DLL (rust) ===
platform = Steam, image_base = 0x..., GObjects = 0x...
GObjects populated, count = 1xxxxx
PATCH ...BP_SurvivalPlayerCharacter_C.InventoryComponent: 40 -> 100 (verify=100)
inv hook: installed on WBP_InventoryInterface_C
entering rescan loop (interval = 10s)
```

The inventory hook installs only after the inventory UI is opened in-game
at least once (that's when the WBP class enters `GObjects`). The worker
retries on every 10-second rescan tick.

If the player's inventory was constructed before the DLL loaded, the live
instance still has 40 slots; load a save fresh to spawn a new inventory
against the patched CDO.

## Quality gates

The same gates the maintainers run before pushing:

```
cargo build --release
cargo clippy --release --all-targets -- -D warnings
cargo test --release
```

All three must pass cleanly.

## Override the DLL path

```
inject.exe path\to\custom\winhttp.dll
```

Useful when iterating on the DLL without rebuilding the injector.

## Configuration

Runtime config lives in `<DLL_dir>\settings.json`. Defaults are baked
in, so the file is optional. Schema:

```json
{
  "inventory": {
    "slot_count": 100
  },
  "survival": {
    "thirst_multiplier": 0.5,
    "hunger_multiplier": 0.5
  }
}
```

- `slot_count` -- target main-backpack capacity. Mount/saddlebag
  (vanilla 30) is always preserved.
- `thirst_multiplier`, `hunger_multiplier` -- scale the per-second
  drain rate. `1.0` = vanilla, `0.5` = half rate, `0.0` = no drain.

Defaults (used when `settings.json` is missing or a key is absent):

- `slot_count = 100`
- `thirst_multiplier = 0.5`
- `hunger_multiplier = 0.5`

Copy `better-backpack/settings.example.json` to your install dir as
`settings.json` if you want to override these.

Compile-time constants:

- `patch.rs` -- `DEFAULT_SLOT_COUNT = 100` (fallback if settings load
  fails), `VANILLA_MAIN = 40`, `VANILLA_MOUNT = 30` (skip).
- `inv_hook.rs` -- viewport size (4 rows x 10 cols), scroll step (one row).
- `survival.rs` -- offsets for `USurvivalComponent` hunger/thirst
  fields.

## Cargo features

- `console` (default on) -- the DLL spawns a "Better Backpack" console
  window via `AllocConsole` for live log output. Useful for development.
  Build a console-free shipping DLL with:
  ```
  cargo build --release --no-default-features
  ```
  The file log at `<DLL_dir>\better_backpack.log` is unaffected.

Trace logging in `inv_hook.rs` is gated by `cfg!(debug_assertions)`. To
enable it, build without `--release`:

```
cargo build
```

Debug builds are larger and slower, but you'll see per-event scroll
diagnostics in the live console.

## Targeting a different game build

Engine offsets live in `better-backpack/src/sdk/offsets.rs` -- two named
constant blocks (`STEAM` and `XBOX`). They were captured from a Dumper-7
run against build 0.4.0.2. If a future game patch shifts offsets, dump
the new SDK and edit those blocks.

The platform is selected at runtime by matching the host process exe
name. Other builds will fall through to the `Steam` defaults with a
warning.

## C++ tree

The original C++ implementation lives at `better-backpack-cpp/` and is
preserved as a reference until full Rust parity is signed off. Its build
instructions live in `better-backpack-cpp/BUILDING.md`. Do not mix the
two outputs in the same session -- their DLLs share the same default
filename if you put them next to each other.
