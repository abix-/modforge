// Per-skill test: glide_speed.
// USER EXPECTATION: spending raises CMC.MaxFlySpeed and CustomFlySpeedMultiplier.

mod common;

#[test]
fn glide_speed_grows_with_spend() {
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
    let fs0 = cmc0.max_fly_speed;
    let cfm0 = cmc0.custom_fly_speed_multiplier;

    if s.player_state.as_ref().unwrap().skill_points < 1 {
        eprintln!("skipping: need a skill point");
        return;
    }
    api.skill_spend("glide_speed", 1);
    let s1 = api.snapshot();
    let cmc1 = s1.live_player.as_ref().unwrap().cmc.as_ref().unwrap();
    assert!(cmc1.max_fly_speed > fs0, "MaxFlySpeed did not grow");
    assert!(
        cmc1.custom_fly_speed_multiplier > cfm0,
        "CustomFlyMultiplier did not grow"
    );
    api.skill_refund("glide_speed", 1);
}
