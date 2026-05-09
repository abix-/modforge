# Integration testing

> **Authoritative on:** the debug HTTP endpoint and Rust integration
> tests that run against a live, modded Grounded 2 instance. For the
> design rationale and the bandage regression that motivated this,
> see [`todo.md`](todo.md) "Integration testing" and
> [`damage.md`](damage.md) "Critical regression".

## What it is

The mod ships an opt-in HTTP server on `127.0.0.1:<port>`. One
endpoint, command-shaped:

```
POST /debug
Content-Type: application/json
Body: { "op": "<name>", "args": {...} }

Response:
{
  "ok":     bool,
  "op":     "<echoed>",
  "error":  null | "...",
  "result": <op-specific>,
  "state":  <full snapshot>
}
```

Every response includes a complete `state` snapshot, so a single
round-trip both runs the op and reads post-op state. Tests assert
against `state` deterministically.

## Enabling the endpoint

Off by default. Add to `<install>/Augusta/Binaries/WinGRTS/ue4ss/Mods/BetterBackpack/dlls/settings.json`:

```json
{
  "debug": { "http_port": 17171 }
}
```

Restart Grounded 2. Look for the log line `debug-http: listening on
127.0.0.1:17171` in `better_backpack.log` to confirm.

## Op set

The endpoint exposes **generic primitives**, not test-specific
ops. Per the `runtime-control-http` skill: ops in the mod are
either small conveniences over coherent gameplay actions, or
generic primitives that let tests do everything else without a
mod rebuild.

Sync (no PE; runs on listener thread):

| op | args | purpose |
| --- | --- | --- |
| `snapshot` | `null` | returns the state struct (one default useful read) |
| `skill_toggle` | `{id, enabled}` | flip per-skill enable flag, reapply |
| `skill_spend` | `{id, count}` | spend N points |
| `skill_refund` | `{id, count}` | refund N points (clamps at 0) |
| `reload_slot` | `null` | re-run the full apply walk |
| `set_skill_points` | `{count}` | grant N points (debug) |

PE-queued (drained from `kill_hook` trampoline with re-entrance
guard so recursive PE fan-out doesn't deadlock; 5s timeout):

| op | args | purpose |
| --- | --- | --- |
| **`call`** | `{class, function, instance_selector, parms_hex}` | **THE generic primitive.** Invoke any UFunction on any object with arbitrary parm bytes. Returns post-call parm bytes (engine writes OUT params). Tests use this for everything: AddHealth, ApplyDamageFromInfo, CreateAndAddEffect, anything in the SDK. New research scenarios = new test file, no mod rebuild. |

Selectors today: `live_player_hc`, `live_player`,
`first_class:<ClassName>`. Add more in the mod's
`resolve_instance` if the test needs a different lookup shape.

The earlier `simulate_add_health` / `simulate_apply_damage` /
`simulate_set_current_health` ops are deprecated; tests should
use `call`. They remain in the surface for back-compat but emit
errors directing callers to `call`.

### Why the generic shape

Adding a `simulate_X` op for every test idea required:
mod-side change -> rebuild -> redeploy -> game relaunch. Slow.

With `call`, a new experiment is a new `tests/<name>.rs` file:

```rust
#[repr(C)]
struct AddHealthParms { amount: f32, _pad: [u8;4], causer: usize }

let p = AddHealthParms { amount: 20.0, _pad: [0;4], causer: 0 };
let (after, state) = api.call_ufunction(
    "HealthComponent", "AddHealth", "live_player_hc",
    unsafe { common::parms_as_bytes(&p) },
)?;
assert!(state.live_hc().current_damage < before);
```

`tests/common/mod.rs` provides `call_ufunction`, `parms_as_bytes`,
`bytes_as_parms`, `hex_encode`, `hex_decode`. The struct layout
mirrors the SDK headers; tests own that knowledge so the mod
stays generic.

### Endpoint parity gap

The skill `runtime-control-http` requires the endpoint to expose
ALL state and drive ALL ops needed by tests. We are **not** at
1000% parity yet. Live audit + remaining work in
[`todo.md`](todo.md) "Endpoint parity gap (target: 1000%)".
Highlights:

- Player StatusEffects array missing from snapshot (only logged).
- `simulate_apply_damage` is a stub.
- `simulate_consume_item` / `simulate_kill` / `simulate_fall` not
  yet implemented (blocks several user-flow tests).
- Per-skill persist-across-reload tests not written.

## State snapshot

```jsonc
{
  "slot": "06d9929b" | null,
  "player_state": {                  // null if no save loaded
    "xp": 504,
    "level": 2,
    "skill_points": 150,
    "skill_levels": { "backpack": 100, "impact_resistance": 100, ... },
    "kill_count": 84,
    "last_killed": "BP_Spiderling_C"
  },
  "disabled_skills": ["impact_resistance"],
  "vanilla": {
    "hunger": -0.14,
    "thirst": -0.14,
    "fall_damage_ratio": ...,
    "max_health": ...,
    "hc_u32_masks": [
      { "offset": "0xFC", "value": "0x00000000" }
    ]
  },
  "live_player": {                   // null if no live pawn yet
    "instance_count": 1,
    "hc": {
      "required_damage_type_flags": "0xFFFFFFFF",
      "immunity_flags":             "0x00000000",
      "base_damage_reduction":      0.5,
      "max_health":                 200.0,
      "current_damage":             0.0
    }
  }
}
```

## Running tests

Tests live in `better-backpack/tests/`. Each `.rs` file is one test
binary. Shared client + types live in `tests/common/mod.rs`.

```bash
# 1. Launch Grounded 2 with the mod loaded and debug.http_port set.
# 2. Load a save and let the world spawn the player pawn.
# 3. From a separate terminal, in the repo root:

set BBP_DEBUG_PORT=17171
cargo test --test debug_snapshot -- --test-threads=1 --nocapture
```

Always pass `--test-threads=1`. Tests share global game state; running
concurrently races every op against every other op.

## Skipping vs failing

Tests use `common::Api::try_connect()` which returns `None` if
`BBP_DEBUG_PORT` is unset. A test that finds `None` should print a
skip note and return early, not fail. This keeps `cargo test` green
when there's no game running (CI, smoke check).

If you want a test to *require* the endpoint (e.g. the bandage
regression must not be silently skipped), call
`common::Api::require()` -- it panics with a clear "BBP_DEBUG_PORT
not set" message.

## Today's smoke test

`tests/debug_snapshot.rs` covers:

- `snapshot` op returns `ok=true`
- `slot` and `player_state` agree on whether a save is loaded
- live `hc.max_health` is in plausible range (`> 0 && < 100_000`)
- live `hc.current_damage <= max_health`
- unknown ops return `ok=false` with a useful error string

This is the floor. As we ship write ops, tests for individual
skills land alongside.

## What this catches that logs do not

Logs are write-only history; you have to read them, eyeball
patterns, hope you catch the right line. The snapshot endpoint
gives a queryable, structured view of *current* state -- which
mask is on the live HC right now, which skills are toggled off,
what vanilla baselines have been captured -- and tests assert
against it deterministically. The bandage regression that took
several in-game cycles to find would have surfaced as a one-line
failure the first time `impact_resistance` shipped as a binary
mask.
