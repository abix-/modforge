// Per-skill test: impact_resistance.
//
// USER EXPECTATION: at level >0 with skill enabled,
// HC.RequiredDamageTypeFlags = 0xFFFFFFFF on the live HC. At level
// 0 OR disabled, vanilla mask is restored.
//
// See `bandage_regression.rs` for the user-observable interaction
// fence (this skill must not block healing).

mod common;

#[test]
fn impact_resistance_writes_mask_and_toggle_clears_it() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };
    let s0 = api.snapshot();
    if s0.live_player.is_none() {
        panic!("no live player");
    }

    if s0.skill_level("impact_resistance") == 0 {
        if s0.player_state.as_ref().unwrap().skill_points < 1 {
            eprintln!("skipping: need a skill point to take the skill");
            return;
        }
        api.skill_spend("impact_resistance", 1);
    }
    api.skill_toggle("impact_resistance", true);

    let on = api.snapshot();
    assert_eq!(
        on.live_hc().required_damage_type_flags,
        "0xFFFFFFFF",
        "mask not active when skill is enabled"
    );

    api.skill_toggle("impact_resistance", false);
    let off = api.snapshot();
    assert_ne!(
        off.live_hc().required_damage_type_flags,
        "0xFFFFFFFF",
        "mask did not clear on toggle off"
    );

    api.skill_toggle("impact_resistance", true);
}
