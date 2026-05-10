// Per-skill test: lifesteal.
//
// USER EXPECTATION: when the player deals damage, a fraction of
// damage dealt is healed back. Lifesteal is a Runtime effect (no
// CDO write); the observable is HP delta during a damage event.
//
// This test depends on `simulate_damage` and the kill_hook's
// damage trampoline counting toward lifesteal -- both not yet
// wired. Stays as a placeholder until the simulate ops land.

mod common;

#[test]
fn lifesteal_appears_in_skill_levels_after_spend() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };
    let s = api.snapshot();
    if s.player_state.as_ref().unwrap().skill_points < 1 {
        eprintln!("skipping: need a skill point");
        return;
    }
    let lvl0 = s.skill_level("lifesteal");
    api.skill_spend("lifesteal", 1);
    let lvl1 = api.snapshot().skill_level("lifesteal");
    assert_eq!(lvl1, lvl0 + 1);
    api.skill_refund("lifesteal", 1);
}

// TODO: full lifesteal observable test once simulate_damage exists:
//   - spend N points on lifesteal
//   - observe HP before
//   - simulate_damage(amount=10) on a target -> player deals damage
//   - observe HP after -> should have grown by ~ 10 * lifesteal_fraction
