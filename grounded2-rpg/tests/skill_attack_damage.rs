// Per-skill test: attack_damage.
// USER EXPECTATION: spending points raises ASurvivalCharacter's
// CustomDamageMultiplier. Observable on the live pawn.

mod common;

#[test]
fn attack_damage_multiplier_grows_with_spend() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };
    let s = api.snapshot();
    let Some(asc) = s.live_player.as_ref().and_then(|lp| lp.asc.as_ref()) else {
        panic!("no live ASC");
    };
    let mult0 = asc.custom_damage_multiplier;

    if s.player_state.as_ref().unwrap().skill_points < 1 {
        eprintln!("skipping: need a skill point");
        return;
    }
    api.skill_spend("attack_damage", 1);
    let mult1 = api
        .snapshot()
        .live_player
        .as_ref()
        .unwrap()
        .asc
        .as_ref()
        .unwrap()
        .custom_damage_multiplier;
    assert!(
        mult1 > mult0,
        "custom_damage_multiplier did not grow: {mult0} -> {mult1}"
    );
    api.skill_refund("attack_damage", 1);
}
