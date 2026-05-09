// Per-skill test: armor.
// USER EXPECTATION: spending points raises HC.BaseDamageReduction.

mod common;

#[test]
fn armor_raises_base_damage_reduction() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };
    let s = api.snapshot();
    let bdr0 = s.live_hc().base_damage_reduction;

    if s.player_state.as_ref().unwrap().skill_points < 1 {
        eprintln!("skipping: need a skill point");
        return;
    }
    api.skill_spend("armor", 1);
    let bdr1 = api.snapshot().live_hc().base_damage_reduction;
    assert!(bdr1 > bdr0, "BDR did not grow: {bdr0} -> {bdr1}");
    api.skill_refund("armor", 1);
}
