# Compound Interest Demo: research

Game folder: `C:\Games\Steam\steamapps\common\Compound Interest Demo`

## What the game is built on

A Rust game that sets up its own renderer with wgpu. It is not Unity,
Unreal or Godot, so neither ueforge (UE4SS) nor unityforge (Mono /
IL2CPP) applies. The route in is the one horsey-mod uses: a native PE,
an injected DLL, addresses found with patternsleuth.

Not yet proven: whether a framework (Bevy, macroquad, ggez) sits
underneath. See "Not yet proven" below.

## Evidence: the game's own log

From `logs/2026-09-29T04-13-21Z-17436.log`:

```
INFO [compoundinterest::scripts] [Scripts] /Users/evrimoztamur/Documents/Projects/Personal/compoundinterest/client\../data/scripts absent; using scripts embedded in the binary
INFO [shared::city::generator] [CityGen] Bridged orphan walkable component (1 tiles) with 1-tile span
INFO [symphonia_bundle_mp3::demuxer] estimating duration from bitrate, may be inaccurate for vbr files
INFO [compoundinterest::draw] Selected adapter: NVIDIA GeForce RTX 2080 Ti (backend: Vulkan)
INFO [compoundinterest::draw] [Renderer] surface=1280x720 format=Bgra8UnormSrgb view=Bgra8UnormSrgb max_texture_2d=8192
INFO [shared::game_manager::crew] [Populate] World populated: 6770 total entities
INFO [shared::market] [MoneyIndex] baseline captured: 30910 in circulation
INFO [shared::story::yield_state] [ScriptRuntime:disturbance/toll_booth] wait_combat resolved winner='hoodlum' (fought=true, decision=false)
```

What each line proves:

- `crate::module` targets are the Rust `log` crate. symphonia is a Rust
  audio crate. So the game is Rust.
- `compoundinterest::draw` picks the GPU adapter and sets up the surface
  itself. Under Bevy those lines would come from `bevy_render`.
- Two crates: `compoundinterest` (the client: draw, scripts, logging)
  and `shared` (city generator, game_manager, market, story). The
  `client\..` in the scripts path matches a `client` folder next to a
  `data` folder in the developer's tree.
- Story scripts run in a script runtime (`ScriptRuntime:<path>`), with
  script paths like `disturbance/toll_booth` and
  `intro/cistern_saints/intro_slides`.

## What is on disk

- `compoundinterest.exe`, 88,423,316 bytes, the whole game.
- `assets/obj`: `.obj` + `.mtl` models (afro, barrel, baseball_bat,
  briefcase, couchred, crowbar, filecabinet, ...).
- `assets/png`, `assets/wav`, `assets/slides`.
- `logs/`: one log per session, named by UTC time and process id.

No packed archive. Whether the game reads these files at runtime (so a
swapped file takes effect) is not tested.

## The scripts folder the game looks for

At startup the game looks for
`/Users/evrimoztamur/Documents/Projects/Personal/compoundinterest/client\../data/scripts`
and, finding nothing, uses the scripts built into the exe. The path is
the developer's Mac build folder, baked in at compile time.

Untested guess: on Windows a path starting with `/` resolves against the
current drive, so
`C:\Users\evrimoztamur\Documents\Projects\Personal\compoundinterest\data\scripts`
may be read if it exists. The script format is not known yet.

## Decompiling the exe

Not started.

## Not yet proven

- Whether a framework sits under the game (look for `bevy_`, `winit`,
  `macroquad` strings in the exe).
- The script format and whether the scripts folder override works.
- Whether loose assets are read at runtime.
