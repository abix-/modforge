// Failing test: reload_slot op.
//
// Re-applies every catalog skill against the live game state.
// Mirrors what world_loader::activate_slot does at slot load.
// Used by tests to return the host to a known baseline.
//
// Red until `reload_slot` op exists; goes green when implemented.

mod common;

#[test]
fn reload_slot_succeeds_when_slot_active() {
    let Some(api) = common::Api::try_connect() else {
        eprintln!("skipping: BBP_DEBUG_PORT not set");
        return;
    };

    let before = api.snapshot();
    if before.slot.is_none() {
        panic!("no slot loaded; load a save before running this test");
    }

    let r = api.op("reload_slot", serde_json::Value::Null);
    assert!(r.ok, "reload_slot failed: {:?}", r.error);
    // Snapshot should still report the same slot bound.
    assert_eq!(r.state.slot, before.slot);
}
