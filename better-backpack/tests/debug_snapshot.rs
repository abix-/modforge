// Smoke test for the debug HTTP endpoint.
//
// Verifies that:
//   - the endpoint responds to a `snapshot` op
//   - the response has the expected shape
//   - if a save slot is loaded, player_state is populated
//   - if the player is live in-world, live_player.hc is populated
//
// Skips with a clear message when BBP_DEBUG_PORT is unset.

mod common;

#[test]
fn snapshot_returns_well_formed_state() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };

    let resp = api.op("snapshot", serde_json::Value::Null);
    assert!(resp.ok, "snapshot op failed: {:?}", resp.error);
    assert_eq!(resp.op, "snapshot");

    let s = resp.state;
    eprintln!("snapshot: {:#?}", s);

    // Slot binding implies player_state is also populated (or vice
    // versa); both should agree.
    assert_eq!(
        s.slot.is_some(),
        s.player_state.is_some(),
        "slot/player_state disagree on whether a save is loaded",
    );

    // If we have a live player, sanity-check its HC reads.
    if let Some(live) = s.live_player {
        assert!(live.instance_count >= 1, "live_player but no instances");
        let hc = live.hc.expect("live player should have hc fields");
        // MaxHealth is positive on any live player; if not, our offset
        // is wrong or we're reading the wrong object.
        assert!(
            hc.max_health > 0.0 && hc.max_health < 100_000.0,
            "max_health out of range: {}",
            hc.max_health
        );
        // CurrentDamage is bounded below by 0 (no negative damage
        // accumulation possible) and above by max_health.
        assert!(
            hc.current_damage >= 0.0 && hc.current_damage <= hc.max_health + 1.0,
            "current_damage out of range: {} (max_health={})",
            hc.current_damage,
            hc.max_health,
        );
        // RequiredDamageTypeFlags should parse as 0xXXXXXXXX.
        assert!(hc.required_damage_type_flags.starts_with("0x"));
        assert_eq!(hc.required_damage_type_flags.len(), 10);
    }
}

#[test]
fn unknown_op_is_an_error_not_a_panic() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };

    let resp = api.op("totally-bogus-op", serde_json::Value::Null);
    assert!(!resp.ok);
    assert_eq!(resp.op, "totally-bogus-op");
    let err = resp.error.expect("error string");
    assert!(err.contains("unknown op"), "unexpected error: {err}");
    // State snapshot should still be present even on error -- the
    // contract is "every response includes state".
    let _ = resp.state.live_player;
}
