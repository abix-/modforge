# Grounded 2 integration testing

> **Authoritative on:** g2rpg-specific test setup. The env var
> name, the endpoint enable path, the bandage-regression test,
> the per-skill scenario harness use sites.
>
> Generic framework material (the `Api<S>` client,
> `research` / `diff` / `scenario` helpers, run patterns,
> standard ops, snapshot shape rules) lives in
> [`../../ueforge/docs/testing.md`](../../ueforge/docs/testing.md).
> Read that first.

## Enabling the endpoint

Off by default. Add to
`<install>/Augusta/Binaries/WinGRTS/ue4ss/Mods/Grounded2Mod/dlls/settings.json`:

```json
{ "debug": { "http_port": 17171 } }
```

Restart Grounded 2. Look for the log line
`debug-http: listening on 127.0.0.1:17171` in
`grounded2_mod.log` to confirm.

## Connect environment variable

```sh
set BBP_DEBUG_PORT=17171
cargo test --target x86_64-pc-windows-msvc \
  --test debug_snapshot -- --test-threads=1 --nocapture
```

`BBP_DEBUG_PORT` is the env var `common::Api::try_connect`
reads. Unset = test skips cleanly.

## g2rpg-specific snapshot shape

The full snapshot includes Maine class field reads + the
RPG-side state:

```jsonc
{
  "slot": "06d9929b" | null,
  "player_state": {
    "xp": 504, "level": 2, "skill_points": 150,
    "skill_levels": { "backpack": 100, "impact_resistance": 100, ... },
    "kill_count": 84, "last_killed": "BP_Spiderling_C"
  },
  "disabled_skills": ["impact_resistance"],
  "vanilla": {
    "hunger": -0.14, "thirst": -0.14,
    "fall_damage_ratio": ..., "max_health": ...,
    "hc_u32_masks": [ { "offset": "0xFC", "value": "0x00000000" } ]
  },
  "live_player": {                   // null if no live pawn yet
    "instance_count": 1,
    "hc": {
      "required_damage_type_flags": "0xFFFFFFFF",
      "immunity_flags":             "0x00000000",
      "base_damage_reduction":      0.5,
      "max_health":                 200.0,
      "current_damage":             0.0
    },
    "cmc": { /* CMC fields */ },
    "asc": { /* ASurvivalCharacter fields */ }
  },
  /* + the ProcessSnapshot block (counters, process_*, game_population) */
}
```

Live-player fields are Maine class layouts; their offsets +
collectors live in `grounded2-mod/src/debug.rs`. See
[`rpg.md`](rpg.md) for the catalog state model and
[`damage.md`](damage.md) for what `hc_u32_masks` /
`required_damage_type_flags` mean.

## Per-skill scenario tests

`tests/skill_*.rs` use the framework's
[`scenario`](../../ueforge/docs/testing.md#scenario) DSL.
Adding a new skill is one `.rs` file:

```rust
mod common;
use ueforge::client::scenario;

#[test]
fn new_skill_grows_field() {
    let Some(api) = common::Api::try_connect() else { return };
    scenario::for_skill(api.inner(), "new_skill_id")
        .reads(|s: &common::Snapshot| {
            Some(s.live_player.as_ref()?.<game_field>)
        })
        .should_grow_when_spent();
}
```

Existing examples cover grow / shrink / revert-on-refund /
revert-on-toggle-off across the 13-skill catalog.

## Bandage regression

`tests/bandage_regression.rs` is a state-locking fence. It
guards against any future change that reintroduces a binary
mask or other heal-blocking gate while `impact_resistance` is
enabled. The previous bug
(`RequiredDamageTypeFlags = 0xFFFFFFFF`) blocked bandages
because their HoT tick (Type=Health status effect) routed
through native code that consults the mask.

What it asserts (post-fix 2026-05-09):

1. mask is NOT `0xFFFFFFFF` when `impact_resistance` is
   enabled at any level.
2. Calling `AddHealth` on the player heals normally with
   `impact_resistance` enabled.

Stays in the suite forever as a fence. See
[`damage.md`](damage.md) "Critical regression" for the full
incident story.

## Today's smoke test

`tests/debug_snapshot.rs`:

- `snapshot` op returns `ok=true`
- `slot` and `player_state` agree on whether a save is loaded
- live `hc.max_health` is plausible (`> 0 && < 100_000`)
- live `hc.current_damage <= max_health`
- unknown ops return `ok=false` with a useful error string

This is the floor. As new write ops ship, tests for
individual skills land alongside.

## See also

- [`../../ueforge/docs/testing.md`](../../ueforge/docs/testing.md)
 . Framework: client, research/diff/scenario helpers, run patterns
- [`rpg.md`](rpg.md). Catalog and persistence
- [`damage.md`](damage.md). Damage internals (bandage regression context)
