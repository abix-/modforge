// Failing test: skill_spend op.
//
// Spending a point should increment skill_levels[id] and decrement
// skill_points by `count`.
//
// Red until `skill_spend` op exists; goes green when implemented.

mod common;

use serde_json::json;

#[test]
fn spending_increments_level_and_decrements_points() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };

    let before = api.snapshot();
    let Some(ps_before) = before.player_state.as_ref() else {
        panic!("no slot loaded; load a save before running this test");
    };
    if ps_before.skill_points < 1 {
        panic!(
            "test needs at least 1 skill point; current = {}. Use the debug \
             grant op or earn one in-game.",
            ps_before.skill_points
        );
    }
    let level_before = before.skill_level("backpack");

    // Spend 1 on backpack.
    let after = api.skill_spend("backpack", 1);
    let level_after = after.skill_level("backpack");
    let points_after = after
        .player_state
        .as_ref()
        .expect("player_state")
        .skill_points;

    assert_eq!(level_after, level_before + 1, "level did not advance by 1");
    assert_eq!(
        points_after,
        ps_before.skill_points - 1,
        "skill_points did not decrement by 1"
    );

    // Restore: refund the point we just spent so the test is
    // idempotent for repeat runs.
    api.skill_refund("backpack", 1);
}

#[test]
fn spend_zero_is_noop() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };
    let before = api.snapshot();
    let r = api.op("skill_spend", json!({"id": "backpack", "count": 0}));
    assert!(r.ok, "spend 0 should not error: {:?}", r.error);
    let after = r.state;
    assert_eq!(
        before.skill_level("backpack"),
        after.skill_level("backpack")
    );
}
