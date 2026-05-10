// Per-skill test: thirst.
// USER EXPECTATION: same shape as hunger, on the thirst drain.

mod common;

#[test]
fn thirst_drain_decreases_with_spend() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };

    let s = api.snapshot();
    let Some(survival) = s.cdo.survival.as_ref() else {
        panic!("SurvivalComponent CDO not loaded yet");
    };
    let drain0 = survival.thirst_adjustment_per_second;
    assert!(drain0 < 0.0);

    if s.player_state.as_ref().unwrap().skill_points < 1 {
        eprintln!("skipping: need a skill point");
        return;
    }
    api.skill_spend("thirst", 1);
    let after = api.snapshot();
    let drain1 = after
        .cdo
        .survival
        .as_ref()
        .unwrap()
        .thirst_adjustment_per_second;
    assert!(drain1 > drain0, "thirst drain did not decrease");

    api.skill_refund("thirst", 1);
    let back = api.snapshot();
    let drain2 = back
        .cdo
        .survival
        .as_ref()
        .unwrap()
        .thirst_adjustment_per_second;
    assert!(
        (drain2 - drain0).abs() < 1e-4,
        "drain did not revert: vanilla {drain0} vs {drain2}"
    );
}
