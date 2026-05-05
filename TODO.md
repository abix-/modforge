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

Format: **JSON** next to the DLL (`better_backpack/settings.json`).

Shape:

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

Notes:

- Mount/saddlebag (vanilla 30) is always preserved regardless of
  `slot_count`.
- Multipliers: `1.0` = vanilla, `0.5` = half rate, `0.0` = paused.
- JSON has no comments; we'll document the schema in `README.md` so users
  know what's editable.

Wire-up:

- New `settings.rs` module with a `Settings` struct + nested
  `Inventory` / `Survival` sections.
- `Settings::load()` reads `<DLL_dir>/settings.json`, returns defaults on
  missing or malformed file (with a log line so the user can tell).
- Add `serde = { version = "1", features = ["derive"] }` and
  `serde_json = "1"` to better-backpack's deps.
- Read once at worker init; pass into `patch::run` and the new
  `survival::run`.
- Log the resolved settings on startup so the live console shows what's
  active.

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

## 4. Log to the binary's own directory

Currently:

- `inject.exe` writes `inject.log` next to itself. Already correct.
- `better_backpack.dll` writes `%TEMP%\BetterBackpack.log`. **Move this**
  to `<DLL_dir>\better_backpack.log`.

Net effect: both binaries log to wherever they live. User running them
from `target\x86_64-pc-windows-msvc\release\` sees:

```
target/x86_64-pc-windows-msvc/release/
  better_backpack.dll
  better_backpack.log     <- NEW location
  inject.exe
  inject.log              <- already here
  settings.json           <- when feature 1 lands
```

Wire-up:

- In `log::init`, replace the `GetTempPathA` lookup with
  `GetModuleFileNameW(<our HMODULE>, ...)` -> strip filename -> append
  `better_backpack.log`. Need to capture the DLL's HMODULE in `DllMain`
  before spawning the worker so we can pass it through.
- Update `BUILDING.md` (and the future README) to point at the new path.
- Settings file (feature 1) lives in the same directory by the same
  rule: next to the DLL.

## 5. Polish (lower priority)

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
