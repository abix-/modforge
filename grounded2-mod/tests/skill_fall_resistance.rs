// Per-skill test: fall_resistance.
//
// USER EXPECTATION: spending lowers FallDamageRatio on the live
// pawn (toward 0), drops the FallDamageMultiplier on GMS / SMMC,
// and at >0 levels disables bTakeFallDamage. The actual mitigation
// in-game is handled by the velocity-stomp on OnLanded; the field
// writes are belt-and-suspenders we still expect to land.

mod common;

#[test]
fn fall_resistance_lowers_ratio_and_multipliers() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };
    let s = api.snapshot();
    let asc0 = s
        .live_player
        .as_ref()
        .and_then(|lp| lp.asc.as_ref())
        .expect("no live ASC");
    let ratio0 = asc0.fall_damage_ratio;
    let gms0 = s
        .cdo
        .game_mode_settings
        .as_ref()
        .map(|g| g.fall_damage_multiplier);
    let smmc0 = s
        .cdo
        .survival_mode_manager
        .as_ref()
        .map(|m| m.custom_fall_damage_multiplier);

    if s.player_state.as_ref().unwrap().skill_points < 1 {
        eprintln!("skipping: need a skill point");
        return;
    }
    api.skill_spend("fall_resistance", 1);
    let s1 = api.snapshot();
    let asc1 = s1.live_player.as_ref().unwrap().asc.as_ref().unwrap();
    assert!(
        asc1.fall_damage_ratio < ratio0 || ratio0 == 0.0,
        "fall_damage_ratio did not drop: {ratio0} -> {}",
        asc1.fall_damage_ratio
    );

    if let (Some(g0), Some(g1)) = (gms0, s1.cdo.game_mode_settings.as_ref()) {
        assert!(
            g1.fall_damage_multiplier < g0,
            "GMS FallDamageMultiplier did not drop: {} -> {}",
            g0,
            g1.fall_damage_multiplier
        );
    }
    if let (Some(m0), Some(m1)) = (smmc0, s1.cdo.survival_mode_manager.as_ref()) {
        assert!(
            m1.custom_fall_damage_multiplier < m0,
            "SMMC FallDamageMultiplier did not drop: {} -> {}",
            m0,
            m1.custom_fall_damage_multiplier
        );
    }

    api.skill_refund("fall_resistance", 1);
}
