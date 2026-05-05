# TODO

Current state: Rust port of the mod is feature-complete. All planned
work done. Nothing actionable left -- only future feature ideas if any
come up.

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
