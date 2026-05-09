//! Smoke test: `/debug snapshot` round-trips, `walk_class` errors
//! cleanly when the UE runtime isn't initialized yet.
//!
//! Skips silently if `OWS_DEBUG_PORT` is unset (i.e. game not
//! running). Run with `--test-threads=1` since tests share game
//! state.

mod common;

use serde_json::json;

#[test]
fn snapshot_round_trips() {
    let Some(api) = common::try_api() else {
        eprintln!("OWS_DEBUG_PORT unset — skipping (game not running?)");
        return;
    };
    let snap = api.snapshot();
    eprintln!(
        "snapshot ok. offsets_known = {}. Once that flips to true, \
         walk_class / read_bytes are usable.",
        snap.offsets_known
    );
}

#[test]
fn unknown_op_errors_cleanly() {
    let Some(api) = common::try_api() else { return };
    let r = api.op("does_not_exist", json!({}));
    assert!(!r.ok, "unknown op should fail");
    assert!(
        r.error.as_deref().unwrap_or("").contains("unknown op"),
        "expected 'unknown op' in error, got {:?}",
        r.error
    );
}

#[test]
fn walk_class_responds_even_without_offsets() {
    // walk_class returns Err("uespy: ue runtime not initialized")
    // when offsets aren't filled in. This test just confirms the
    // dispatcher reaches the op and returns a structured response
    // — useful as the very first signal that the wiring is live.
    let Some(api) = common::try_api() else { return };
    let r = api.op("walk_class", json!({"class": "Object", "max": 1}));
    eprintln!("walk_class response: ok={}, error={:?}", r.ok, r.error);
    // No assertion: pass-through. After offsets land, expect ok=true.
}
