# TODO

Current state: Rust port of the mod is functional in-game. Backpack
capacity, scrolling, settings file, hunger/thirst rate patch, and
log-next-to-DLL all working. See `RUST_PORT_PLAN.md` for the migration
steps and `PERFORMANCE.md` for the runtime cost analysis.

What's left:

## 1. Auto-launch from inject.exe

Right now `inject.exe` requires Grounded to already be running. User
wants `inject.exe` to launch the game then inject.

Open design questions:

- Steam vs Xbox launch path. Steam uses `steam://rungameid/<appid>` (need
  to confirm Grounded 2's Steam app id and put it in settings). Xbox
  Game Pass UWP launches are trickier; possibly via the
  `gamingservices`-style protocol URI.
- Direct exe launch as fallback: if Steam isn't running, accept a path
  to `Grounded2-WinGRTS-Shipping.exe`? Bypasses Steam overlay /
  achievements.

Proposed flow:

- `inject.exe` reads `<inject.exe dir>/inject.json`:
  ```json
  {
    "launch": {
      "steam_app_id": 12345,
      "fallback_exe": "",
      "poll_interval_ms": 250,
      "poll_timeout_sec": 60
    }
  }
  ```
- New behavior with no args:
  1. If a target Grounded process is already running -> inject.
  2. Otherwise launch via `steam://rungameid/<id>`. Fall back to
     `fallback_exe` if Steam is unavailable.
  3. Poll `CreateToolhelp32Snapshot` every `poll_interval_ms` until the
     process appears or `poll_timeout_sec` elapses.
  4. Once found, inject as before.
- Add `--no-launch` to disable the launch step.
- Existing positional DLL path arg still works.

Note: keep JSON consistent with the DLL's `settings.json` (no TOML).

## 2. Polish (lower priority)

- Gate `AllocConsole` behind a Cargo feature (`console`, default off for
  shipping). The file log is the durable record; the console window is
  developer-only.
- Replace the two `Mutex` locks in the ProcessEvent hot path with
  atomics. Saves ~20-40 ns per dispatch. Strictly tidy-up; not
  user-visible.

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
- `BUILDING.md` + `PERFORMANCE.md` at repo root.
