// Per-skill test: health_regen.
// USER EXPECTATION: spending raises CombatRegenTickPercentage and
// lowers CombatRegenTickRate (more frequent ticks) on UGlobalCombatData.
// Toggle off reverts to vanilla.

mod common;

#[test]
fn health_regen_changes_tick_pct_and_rate() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };
    let s = api.snapshot();
    let Some(g0) = s.cdo.global_combat_data.as_ref() else {
        panic!("no GlobalCombatData instance");
    };
    let pct0 = g0.combat_regen_tick_percentage;
    let rate0 = g0.combat_regen_tick_rate;
    let delay0 = g0.combat_regen_delay;

    if s.player_state.as_ref().unwrap().skill_points < 1 {
        eprintln!("skipping: need a skill point");
        return;
    }
    api.skill_spend("health_regen", 1);
    let s1 = api.snapshot();
    let g1 = s1.cdo.global_combat_data.as_ref().unwrap();
    assert!(
        g1.combat_regen_tick_percentage > pct0,
        "tick_pct did not grow: {pct0} -> {}",
        g1.combat_regen_tick_percentage
    );
    assert!(
        g1.combat_regen_tick_rate < rate0,
        "tick_rate did not drop: {rate0} -> {}",
        g1.combat_regen_tick_rate
    );
    assert_eq!(
        g1.combat_regen_delay, delay0,
        "regen_delay should not change"
    );

    // Toggle off -> revert.
    api.skill_toggle("health_regen", false);
    let s2 = api.snapshot();
    let g2 = s2.cdo.global_combat_data.as_ref().unwrap();
    assert!(
        (g2.combat_regen_tick_percentage - pct0).abs() < 1e-3,
        "tick_pct did not revert on toggle off: vanilla {pct0} vs {}",
        g2.combat_regen_tick_percentage
    );
    assert!(
        (g2.combat_regen_tick_rate - rate0).abs() < 1e-3,
        "tick_rate did not revert on toggle off"
    );

    api.skill_toggle("health_regen", true);
    api.skill_refund("health_regen", 1);
}
