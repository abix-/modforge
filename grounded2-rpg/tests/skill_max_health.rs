// Per-skill test: max_health.
// USER EXPECTATION: spending raises HC.MaxHealth additively
// (vanilla + max_bonus * progress).

mod common;

#[test]
fn max_health_increases_additively() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };
    let s = api.snapshot();
    let max0 = s.live_hc().max_health;

    if s.player_state.as_ref().unwrap().skill_points < 1 {
        eprintln!("skipping: need a skill point");
        return;
    }
    api.skill_spend("max_health", 1);
    let max1 = api.snapshot().live_hc().max_health;
    assert!(max1 > max0, "MaxHealth did not grow: {max0} -> {max1}");
    api.skill_refund("max_health", 1);
    let back = api.snapshot();
    assert!(
        (back.live_hc().max_health - max0).abs() < 0.5,
        "MaxHealth did not revert: {max0} vs {}",
        back.live_hc().max_health,
    );
}
