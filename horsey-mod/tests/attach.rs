//! Attach to an already-running mod and probe `ping`. Faster than
//! the full Steam relaunch loop; useful when iterating on the
//! HTTP/op layer.
//!
//! Run with a live mod already injected:
//!   `cargo test -p horsey-mod --test attach -- --test-threads=1 --nocapture`

mod common;

use modforge::harness::GameHarness;
use serde_json::{Value, json};

#[test]
fn attach_and_ping() {
    if modforge::harness::should_skip() {
        eprintln!("MODFORGE_NO_GAME=1, skipping live-mod test");
        return;
    }
    let spec = common::spec();
    let game = GameHarness::attach_existing(&spec, "attach_and_ping")
        .expect("expected a running horsey-mod on 127.0.0.1:33077");

    let resp: Value = game
        .op_json("ping", &json!({}))
        .expect("ping op should succeed");

    game.pass(&format!("ping response: {resp}"));
    assert!(
        resp.is_object() || resp.is_null(),
        "ping returned non-object response: {resp}"
    );
}
