// Per-skill test: leap_distance.
// USER EXPECTATION: spending raises CMC.AirControl,
// AirControlBoostMultiplier, AirControlBoostVelocityThreshold.

mod common;

#[test]
fn leap_distance_grows_air_control_fields() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };
    let s = api.snapshot();
    let cmc0 = s
        .live_player
        .as_ref()
        .and_then(|lp| lp.cmc.as_ref())
        .expect("no live CMC");
    let ac0 = cmc0.air_control;
    let acb0 = cmc0.air_control_boost_multiplier;
    let act0 = cmc0.air_control_boost_velocity_threshold;

    if s.player_state.as_ref().unwrap().skill_points < 1 {
        eprintln!("skipping: need a skill point");
        return;
    }
    api.skill_spend("leap_distance", 1);
    let s1 = api.snapshot();
    let cmc1 = s1
        .live_player
        .as_ref()
        .unwrap()
        .cmc
        .as_ref()
        .unwrap();
    assert!(cmc1.air_control > ac0, "AirControl did not grow");
    assert!(
        cmc1.air_control_boost_multiplier > acb0,
        "AirControlBoostMult did not grow"
    );
    assert!(
        cmc1.air_control_boost_velocity_threshold > act0,
        "AirControlBoostThreshold did not grow"
    );
    api.skill_refund("leap_distance", 1);
}
