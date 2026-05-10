// Per-skill test: move_speed.
//
// USER EXPECTATION: spending raises MaxWalkSpeed (and the other
// move-axis CMC fields). Toggling off reverts to vanilla. Toggling
// on restores the boost.

mod common;

#[test]
fn move_speed_grows_with_spend_and_responds_to_toggle() {
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
    let walk0 = cmc0.max_walk_speed;

    if s.player_state.as_ref().unwrap().skill_points < 1 {
        eprintln!("skipping: need a skill point");
        return;
    }

    api.skill_spend("move_speed", 1);
    let walk1 = api
        .snapshot()
        .live_player
        .as_ref()
        .unwrap()
        .cmc
        .as_ref()
        .unwrap()
        .max_walk_speed;
    assert!(walk1 > walk0, "walk speed did not grow: {walk0} -> {walk1}");

    // Toggle off should revert to vanilla.
    api.skill_toggle("move_speed", false);
    let walk2 = api
        .snapshot()
        .live_player
        .as_ref()
        .unwrap()
        .cmc
        .as_ref()
        .unwrap()
        .max_walk_speed;
    assert!(
        (walk2 - walk0).abs() < 0.5,
        "toggle off did not revert to vanilla: {walk0} vs {walk2}"
    );

    // Toggle back on -> boost restored.
    api.skill_toggle("move_speed", true);
    let walk3 = api
        .snapshot()
        .live_player
        .as_ref()
        .unwrap()
        .cmc
        .as_ref()
        .unwrap()
        .max_walk_speed;
    assert!(
        walk3 > walk0,
        "toggle on did not restore the boost: {walk0} -> {walk3}"
    );

    api.skill_refund("move_speed", 1);
}
