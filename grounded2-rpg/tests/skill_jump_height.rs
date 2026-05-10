// Per-skill test: jump_height.
// USER EXPECTATION: spending raises CMC.JumpZVelocity.

mod common;

#[test]
fn jump_height_grows_with_spend() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };
    let s = api.snapshot();
    let v0 = s
        .live_player
        .as_ref()
        .and_then(|lp| lp.cmc.as_ref())
        .expect("no live CMC")
        .jump_z_velocity;

    if s.player_state.as_ref().unwrap().skill_points < 1 {
        eprintln!("skipping: need a skill point");
        return;
    }
    api.skill_spend("jump_height", 1);
    let v1 = api
        .snapshot()
        .live_player
        .as_ref()
        .unwrap()
        .cmc
        .as_ref()
        .unwrap()
        .jump_z_velocity;
    assert!(v1 > v0, "JumpZ did not grow: {v0} -> {v1}");
    api.skill_refund("jump_height", 1);
}
