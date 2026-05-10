// Per-skill test: backpack.
//
// USER EXPECTATION: spending points on Backpack increases the
// player's main inventory slot count. Refunding reverts it.
// Toggling has no effect (BackpackSlots variant doesn't honor the
// flag).

mod common;

#[test]
fn backpack_slot_count_tracks_level() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };

    let s = api.snapshot();
    if s.player_state.is_none() {
        panic!("no slot loaded");
    }

    let lvl0 = s.skill_level("backpack");
    let slots0 = s.inventory.current_slot_count;
    assert!(slots0 > 0, "inv hook never reported a slot count");

    // If we have a point to spend, spend it and assert slots grew.
    if s.player_state.as_ref().unwrap().skill_points >= 1 {
        let after = api.skill_spend("backpack", 1);
        let lvl1 = after.skill_level("backpack");
        let slots1 = after.inventory.current_slot_count;
        assert_eq!(lvl1, lvl0 + 1);
        assert!(
            slots1 >= slots0,
            "slots did not grow on spend: {slots0} -> {slots1}"
        );

        // Refund: slots should revert.
        let back = api.skill_refund("backpack", 1);
        assert_eq!(back.skill_level("backpack"), lvl0);
        assert_eq!(back.inventory.current_slot_count, slots0);
    }
}
