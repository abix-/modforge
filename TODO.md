# TODO

Current state: Rust port of the mod is functional in-game (slot count = 100,
mouse-wheel scroll working, hook installs, DLL injection via `inject.exe`
exits cleanly with no recurring overhead). See `RUST_PORT_PLAN.md` for the
finished migration steps and `PERFORMANCE.md` for the runtime cost
analysis.

What's left:

## 1. Settings file

Replace the compile-time constants with a settings file the user can edit
without rebuilding. Keep defaults baked in so the mod still works with no
file present.

Format: TOML next to the DLL (`better_backpack.toml`) -- TOML is
human-editable, native to the Rust ecosystem, and avoids JSON's
no-comments problem.

Shape:

```toml
[inventory]
slot_count = 100         # vanilla 40, mount 30 always preserved

[survival]
thirst_multiplier = 0.5  # 1.0 = vanilla, 0.5 = half rate, 0.0 = paused
hunger_multiplier = 0.5
```

Wire-up:

- New `settings.rs` module with `Settings` struct, `Settings::load()` that
  reads the TOML file from `<DLL_dir>/better_backpack.toml`, falls back to
  defaults on missing/malformed file.
- Read once at worker init; pass into `patch::run` and the new
  `survival::run`.
- Log the resolved settings on startup so the live console shows what's
  active.
- Add `toml = "0.9"` (or current latest) to the better-backpack
  dependencies. No serde_derive needed -- a flat struct with
  `toml::from_str` is fine.

## 2. Thirst + hunger rate patch

Found via SDK: `USurvivalComponent` (`Maine.SurvivalComponent`) holds
`ThirstSettings` at offset `+0x0180` and `HungerSettings` at offset
`+0x0138`. Both are `FSurvivalTraitSettings` (0x48 bytes). The
drain rate is `AdjustmentPerSecond` at struct-offset `+0x08` (a `float`,
typically negative).

Absolute offsets within USurvivalComponent:
- HungerSettings.AdjustmentPerSecond = `+0x0140`
- ThirstSettings.AdjustmentPerSecond = `+0x0188`

Implementation:

- Add `survival.rs`. Walks every UClass that derives from
  `SurvivalComponent` (native + any BP-derived overrides) and patches
  each CDO's two AdjustmentPerSecond floats by the multipliers from
  settings.
- One-shot, same sticky-CDO model as the inventory patch -- runs once,
  inherits to every save load.
- Idempotent guard: store the original value detected on first patch in
  a static so re-injection in the same session can't compound. (Or
  simpler: if the field's already been multiplied -- check magnitude --
  skip.)
- Log `THIRST PATCH <full_name>: -X.XXX -> -Y.YYY` and same for hunger.

## 3. Auto-launch from inject.exe

Right now `inject.exe` requires Grounded to already be running. User
wants `inject.exe` to launch the game and then inject.

Open design questions:

- Steam vs Xbox launch path. Steam uses `steam://rungameid/<appid>` (need
  to confirm Grounded 2's Steam app ID and add to settings). Xbox Game
  Pass UWP launches are trickier (can't be started from a generic exe;
  protocol URI needed).
- Direct exe launch as fallback: if user has Steam closed, do we accept
  the path to `Grounded2-WinGRTS-Shipping.exe` directly? Bypasses Steam
  achievements / overlay if so.

Proposed flow:

- `inject.exe` reads `<inject.exe dir>/inject.toml`:
  ```toml
  [launch]
  steam_app_id = 12345          # Grounded 2 Steam app id
  fallback_exe = ""             # optional direct path
  poll_interval_ms = 250
  poll_timeout_sec = 60
  ```
- New behavior with no args:
  1. If a target Grounded process is already running -> inject (existing
     behavior).
  2. Otherwise launch via `steam://rungameid/<id>`. Fall back to
     `fallback_exe` if Steam unavailable.
  3. Poll `CreateToolhelp32Snapshot` every `poll_interval_ms` until the
     process appears or `poll_timeout_sec` elapses.
  4. Once found, inject as before.
- Add `--no-launch` to disable the launch step (keep current behavior).
- Existing positional DLL path arg still works.

## 4. Polish (lower priority)

- Gate `AllocConsole` behind a Cargo feature (`console`, default off for
  shipping). The file log is the durable record; the console window is
  developer-only.
- Replace the two `Mutex` locks in the ProcessEvent hot path with
  atomics (`AtomicBool` for `in_synthetic_refresh`, immutable
  `&'static [&'static Entry]` for the registry). Saves ~20-40 ns per
  dispatch. Strictly tidy-up; not user-visible.

## Out of scope (kept for context)

- Visible 6-row inventory grow. Replaced by paged 4x10 viewport. Working.
- Multiplayer correctness for hunger/thirst. Stats almost certainly
  replicate server-authoritatively, so non-host clients won't see the
  effect. Document, don't fight.

## Done

- Rust port of the mod (RUST_PORT_PLAN.md steps 1-8, 11).
- Backpack capacity patch -> 100 slots, validated in-game.
- `WBP_InventoryInterface_C` ProcessEvent hook + viewport rebind.
- Mouse-wheel scrolling preserves absolute slot positions (empty slots
  stay empty, no upward compaction).
- Worker thread terminates after init -- no recurring overhead.
- `inject.exe` writes its own log, pauses before exit by default.
- `BUILDING.md` + `PERFORMANCE.md` at repo root.
