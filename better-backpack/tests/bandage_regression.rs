// Regression fence: impact_resistance must not block healing.
//
// USER EXPECTATION: bandages (and other healing items) work
// regardless of which RPG skills are active. The mod's skills are
// not allowed to break gameplay items the user has earned.
//
// Failure mode this catches: impact_resistance writes
// RequiredDamageTypeFlags = 0xFFFFFFFF, which makes the native
// ApplyDamage gate reject anything with type_flags = 0. Bandages
// route healing through ApplyDamage with negative damage and zero
// type_flags, hitting the same gate.
//
// This test must STAY in the suite forever. Whoever reintroduces
// a binary mask (or any other heal-blocking gate) trips it.
//
// Red until `simulate_heal` op exists. Once it does, will go red
// again with the current implementation (bug present), then green
// after the status-effect migration.

mod common;

#[test]
fn impact_resistance_does_not_block_bandages() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };

    let snap = api.snapshot();
    if snap.live_player.is_none() {
        panic!("no live player; load a save and spawn into the world");
    }

    // Setup: max impact_resistance, ensure it's enabled.
    let cur_lvl = snap.skill_level("impact_resistance");
    let to_spend = 100u32.saturating_sub(cur_lvl);
    if to_spend > 0 {
        // Best-effort: only spend what we have points for.
        let avail = snap
            .player_state
            .as_ref()
            .map(|p| p.skill_points)
            .unwrap_or(0);
        let n = to_spend.min(avail);
        if n > 0 {
            api.skill_spend("impact_resistance", n);
        }
    }
    api.skill_toggle("impact_resistance", true);

    let mid = api.snapshot();
    assert!(
        !mid.is_disabled("impact_resistance"),
        "test setup failed: impact_resistance still disabled"
    );
    assert_eq!(
        mid.live_hc().required_damage_type_flags,
        "0xFFFFFFFF",
        "test setup failed: mask not active"
    );

    // Take some damage (or assume the player is below full HP) and
    // attempt to heal.
    let hp0 = mid.hp();
    let max = mid.live_hc().max_health;
    if (hp0 - max).abs() < 0.5 {
        eprintln!(
            "skipping: player at full HP ({hp0}/{max}); take some damage first"
        );
        return;
    }

    let after = api.simulate_heal(20.0);
    let hp1 = after.hp();
    let delta = hp1 - hp0;

    assert!(
        (delta - 20.0).abs() < 0.5,
        "FENCE VIOLATED: impact_resistance is blocking healing. \
         Heal delta = {delta}, expected ~20.0. \
         HP {} -> {} with mask = {}",
        hp0,
        hp1,
        after.live_hc().required_damage_type_flags,
    );
}
