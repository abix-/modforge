# TODO

Current state: Rust port of the mod is feature-complete on the runtime
side. Open work is **distribution**: switching from "drop a winhttp.dll
proxy in the game folder" to "ship as a UE4SS C++ mod, but keep the
mod source 100% Rust." Plan in [UE4SS_PORT_PLAN.md](UE4SS_PORT_PLAN.md).

## 1. Repackage as a UE4SS CPPMod (Rust-only)

Why: see UE4SS_PORT_PLAN.md (steelman in 11 points). Short version:
UE4SS is the convention for UE5 game mods, distribution / Vortex is
already solved on that path, and we get to delete our winhttp proxy
forwarders + setup.ps1 + winhttp_orig.dll dance.

Hard constraint: stay all-Rust. No C++ shim, no Lua port. UE4SS loads
our Rust cdylib via the legacy free-function CPPMod ABI; if that
doesn't work in the current UE4SS, we synthesize a vtable in Rust
to satisfy the modern `CppUserModBase` ABI without adding C++.

Sequence (full detail in UE4SS_PORT_PLAN.md):

1. Smoke-test: minimal "hello" Rust cdylib loaded by UE4SS for
   Grounded 2. Gates the whole plan.
2. Confirm legacy ABI works. If not, build a Rust-only vtable shim.
3. Add `start_mod`/`uninstall_mod` exports. Worker moves out of
   DllMain into start_mod.
4. Drop winhttp proxy plumbing (def file, build.rs cc dep,
   forwarders).
5. Rewrite deploy.ps1 for UE4SS Mods folder layout
   (`BetterBackpack/dlls/main.dll`).
6. Doc updates.
7. In-game smoke test of the full mod under UE4SS.
8. Archive winhttp proxy material into `archive/winhttp-proxy/` --
   keep it as a working fallback if UE4SS ever turns out unstable.

The current winhttp.dll proxy work (steps 1-3 of the previous TODO,
already shipped) is **not wasted**: it's the tested fallback. We
archive it, we don't delete it.

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
