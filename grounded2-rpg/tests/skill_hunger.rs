// Per-skill test: hunger (and thirst, by symmetry).
//
// USER EXPECTATION: spending points on Hunger Resistance reduces
// the rate at which hunger drains. The SurvivalComponent CDO's
// AdjustmentPerSecond is the observable.

mod common;

#[test]
fn hunger_drain_decreases_with_spend() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };

    let s = api.snapshot();
    let Some(survival) = s.cdo.survival.as_ref() else {
        panic!("SurvivalComponent CDO not loaded yet");
    };
    let drain0 = survival.hunger_adjustment_per_second;
    assert!(drain0 < 0.0, "hunger drain should be negative, got {drain0}");

    let lvl_start = s.skill_level("hunger");
    if s.player_state.as_ref().unwrap().skill_points < 1 {
        eprintln!("skipping: need a skill point");
        return;
    }
    let after = api.skill_spend("hunger", 1);
    let drain1 = after
        .cdo
        .survival
        .as_ref()
        .expect("survival cdo")
        .hunger_adjustment_per_second;

    // Drain rate is negative; "less drain" = closer to 0 (greater value).
    assert!(
        drain1 > drain0,
        "drain did not decrease: {drain0} -> {drain1} after spend"
    );

    api.skill_refund("hunger", 1);
    let back = api.snapshot();
    assert_eq!(back.skill_level("hunger"), lvl_start);
    let drain2 = back
        .cdo
        .survival
        .as_ref()
        .expect("survival cdo")
        .hunger_adjustment_per_second;
    assert!(
        (drain2 - drain0).abs() < 1e-4,
        "drain did not revert after refund: vanilla {drain0} vs after-refund {drain2}"
    );
}
