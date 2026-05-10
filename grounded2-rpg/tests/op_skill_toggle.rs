// Failing test: skill_toggle op.
//
// Drives the per-skill enable flag via the debug endpoint. When
// disabled, an active skill should observe as not-applied (e.g.
// vanilla mask restored for impact_resistance, vanilla mult for
// movement skills).
//
// Red until `skill_toggle` op exists; goes green when implemented.

mod common;

use serde_json::json;

#[test]
fn toggle_off_then_on_restores_state() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };

    // Use impact_resistance because its observed effect is in the
    // snapshot (live HC RequiredDamageTypeFlags). Need the skill at
    // least at level 1 to see the difference.
    let snap = api.snapshot();
    if snap.skill_level("impact_resistance") == 0 {
        api.skill_spend("impact_resistance", 1);
    }

    // Toggle off.
    let off = api.skill_toggle("impact_resistance", false);
    assert!(off.is_disabled("impact_resistance"));
    let mask_off = &off.live_hc().required_damage_type_flags;
    assert_ne!(
        mask_off, "0xFFFFFFFF",
        "toggle off did not clear the mask, got {mask_off}"
    );

    // Toggle on.
    let on = api.skill_toggle("impact_resistance", true);
    assert!(!on.is_disabled("impact_resistance"));
    assert_eq!(
        on.live_hc().required_damage_type_flags,
        "0xFFFFFFFF",
        "toggle on did not re-set the mask",
    );
}

#[test]
fn toggle_unknown_skill_returns_error() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };
    let r = api.op(
        "skill_toggle",
        json!({"id": "totally-not-a-skill", "enabled": false}),
    );
    assert!(!r.ok);
    let err = r.error.expect("error");
    assert!(err.contains("unknown skill"), "unexpected error: {err}");
}
