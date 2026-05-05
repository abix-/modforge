# TODO

Current state: Rust port of the mod is feature-complete on the runtime
side. Open work is **distribution**: switching from "drop a winhttp.dll
proxy in the game folder" to "ship as a UE4SS C++ mod, but keep the
mod source 100% Rust." Plan in [UE4SS_PORT_PLAN.md](UE4SS_PORT_PLAN.md).

## 1. Repackage as a UE4SS CPPMod

Why: see `UE4SS_PORT_PLAN.md` (steelman in 11 points). Short
version: UE4SS is the convention for UE5 game mods, distribution
via Vortex is already solved on that path (UE4SS for Grounded 2 is
Vortex mod #52), and we delete our winhttp proxy forwarders +
setup.ps1 + winhttp_orig.dll dance.

Source language stays Rust. UE4SS's CPPMod ABI is C++ inheritance,
so we add a ~30-line C++ shim that derives from
`RC::CppUserModBase` and forwards lifecycle calls to two
`extern "C"` Rust functions. Mod logic stays Rust.

Earlier drafts of this plan claimed there was a "legacy free-function
CPPMod ABI" we could use to stay 100% Rust. There isn't. The
inheritance ABI is the only path. The 30 lines of C++ are loader
handshake -- they don't compete with the 1500+ lines of Rust mod
logic for any meaningful property.

Sequence (full detail in `UE4SS_PORT_PLAN.md`):

- [x] Step 1: Clone RE-UE4SS to `C:\code\RE-UE4SS` for headers.
  (Submodule attempt blocked by upstream's broken UEPseudo
  reference.)
- [ ] Step 2: Generate `UE4SS.lib` import library from the user's
  installed `UE4SS.dll` via `dumpbin /exports` -> `.def` ->
  `lib /def:`. Verified the DLL exports the symbols we need
  (`??0CppUserModBase@RC@@QEAA@XZ`, virtual destructor, all base
  virtuals).
- [ ] Step 3: Add the C++ shim source. Extend `build.rs` to compile
  it via `cc::Build` against the headers in `C:\code\RE-UE4SS` and
  link against `UE4SS.lib`. Drop the winhttp forwarder generation.
- [ ] Step 4: Rename cdylib output from `winhttp` to `main`. Add
  two `#[no_mangle] extern "C"` Rust entry points
  (`better_backpack_start`, `better_backpack_stop`). Move worker
  startup out of `DllMain` into `better_backpack_start`. Drop
  `wait_for_gobjects` -- UE4SS calls our `on_unreal_init` after
  the engine has finished initializing.
- [ ] Step 5: Rewrite `deploy.ps1` for the UE4SS mod folder layout.
  Default mode produces a zip mirroring
  `Augusta/Binaries/WinGRTS/ue4ss/Mods/BetterBackpack/`.
- [ ] Step 6: Update `BUILDING.md`, `README.md`, `FEATURES.md`,
  `PERFORMANCE.md` to reflect the UE4SS load model.
- [ ] Step 7: In-game smoke test under UE4SS.
- [ ] Step 8: Archive the winhttp proxy material to
  `archive/winhttp-proxy/`. Keep it as a tested fallback in case
  UE4SS turns out unstable for Grounded 2.

The current winhttp.dll proxy work (already shipped, commits
514e2b1..bfb3447) is **not wasted**: it's the tested fallback.
Archive, not delete.

## 2. (later) Port more Player Tweaks features

See `FEATURES.md` for the comparison table and the prioritized list.
Quick wins identified: stamina regen, sprint/walk/swim speed, hauling
stack size, death delay. Each is the same shape as the existing
hunger/thirst patch -- find the offset in the SDK, add a section to
`settings.json`, write a 50-line module. Order them by user demand.

## Out of scope (kept for context)

- Visible 6-row inventory grow. Replaced by paged 4x10 viewport. Working.
- Multiplayer correctness for hunger/thirst. Stats almost certainly
  replicate server-authoritatively, so non-host clients won't see the
  effect. Document, don't fight.

## Done

- Rust port of the mod (RUST_PORT_PLAN.md steps 1-8, 11).
- Backpack capacity patch -> 100 slots (settings-driven), validated
  in-game.
- `WBP_InventoryInterface_C` ProcessEvent hook + viewport rebind.
- Mouse-wheel scrolling preserves absolute slot positions (empty slots
  stay empty, no upward compaction).
- Worker thread terminates after init -- no recurring overhead.
- `inject.exe` writes its own log, exits without pausing.
- `inject.exe` auto-launches the game via Steam (or fallback exe) when
  it's not already running, then polls until the process appears, then
  injects. `--no-launch` to opt out. Configured via `inject.json` next
  to inject.exe (`inject.example.json` is the schema). Default Steam
  app id: `3104110`.
- `settings.json` next to the DLL controls slot count + thirst/hunger
  multipliers. `better-backpack/settings.example.json` is the schema.
  Defaults: slot_count=100, thirst/hunger multipliers=0.5.
- Hunger and thirst rate patch via `survival.rs` -- patches every
  SurvivalComponent CDO's `HungerSettings.AdjustmentPerSecond` and
  `ThirstSettings.AdjustmentPerSecond` floats by the configured
  multipliers.
- DLL log file moved from `%TEMP%\BetterBackpack.log` to
  `<DLL_dir>\better_backpack.log`. Both binaries now log next to
  themselves.
- `AllocConsole` gated behind a Cargo `console` feature. Default-on so
  development still gets the live window; `cargo build --release
  --no-default-features` produces a console-free shipping build.
- `BUILDING.md` + `PERFORMANCE.md` at repo root.
- ProcessEvent hot path is mutex-free: REGISTRY snapshot is published as
  a leaked `&'static [&'static Entry]` via `AtomicPtr`, trampoline does
  one atomic load + slice scan. `in_synthetic_refresh` is `AtomicBool`.
