// Failing test: simulate_heal op.
//
// Provokes a healing event on the player by routing through the
// same path real healing items use (ApplyDamage with negative
// damage, type_flags = 0). HP after should be HP before + amount,
// clamped to MaxHealth.
//
// Red until `simulate_heal` op exists AND the PE-thread queue
// drain is wired into a game-thread surface.

mod common;

#[test]
fn simulate_heal_increments_hp_when_no_block() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };

    // Make sure impact_resistance isn't blocking; this test isolates
    // the heal mechanic itself.
    api.skill_toggle("impact_resistance", false);

    let before = api.snapshot();
    if before.live_player.is_none() {
        panic!("no live player; load a save and spawn into the world");
    }

    // Take a little damage first so we have headroom to heal.
    let hp0 = before.hp();
    let max = before.live_hc().max_health;
    if (hp0 - max).abs() < 0.5 {
        // Player is at full HP; can't observe a heal. Skip with a
        // clear signal. This isn't a logic failure, just a setup
        // gap that needs the user to take some damage first or for
        // simulate_damage to land too.
        eprintln!("skipping: player at full HP, take some damage first");
        return;
    }

    let s = api.simulate_heal(20.0);
    let hp1 = s.hp();
    let delta = hp1 - hp0;
    assert!(
        (delta - 20.0).abs() < 0.5,
        "heal delta {delta} != 20.0; HP {} -> {}",
        hp0,
        hp1
    );
}
