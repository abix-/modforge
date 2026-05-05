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

- `target/x86_64-pc-windows-msvc/release/better_backpack.dll`
- `target/x86_64-pc-windows-msvc/release/inject.exe`

The build target dir is locked to `target/` via `.cargo/config.toml`. If
you have a global `~/.cargo/config.toml` redirecting builds elsewhere, the
project-level config wins.

## Run

Close any prior copy of the DLL first -- once mapped into the game
process, Windows holds the file lock until the process exits.

1. Launch Grounded 2. Steam build is `Grounded2-WinGRTS-Shipping.exe`;
   Xbox Game Pass is `Grounded2-WinGDK-Shipping.exe`. Either is auto
   detected.
2. Load a save and let the world finish loading.
3. From `target/x86_64-pc-windows-msvc/release/`, run `inject.exe`. With
   no arguments it picks `better_backpack.dll` next to itself.

What you should see:

- A new console window titled "Better Backpack" pops up in the game
  process. It tails the live mod log.
- `%TEMP%\BetterBackpack.log` mirrors that output.
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
inject.exe path\to\custom\better_backpack.dll
```

Useful when iterating on the DLL without rebuilding the injector.

## Configuration

Compile-time constants live in `better-backpack/src/`:

- `patch.rs` -- `SLOT_COUNT = 100` (target capacity), `VANILLA_MAIN = 40`,
  `VANILLA_MOUNT = 30` (skip).
- `inv_hook.rs` -- viewport size (4 rows x 10 cols), scroll step (one row).

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
