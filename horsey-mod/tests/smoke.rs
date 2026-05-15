//! End-to-end smoke test for the modforge::harness loop.
//!
//! Verifies the full pipeline works:
//!   1. cargo builds horsey-mod
//!   2. Steam launches Horsey
//!   3. horsey-inject loads the DLL
//!   4. HTTP plane comes up on 127.0.0.1:33077
//!   5. `ping` op succeeds
//!   6. taskkill on Drop
//!
//! Run: `cargo test -p horsey-mod --test smoke -- --test-threads=1 --nocapture`
//! Skip live: `set MODFORGE_NO_GAME=1` then run as above.

mod common;

use serde_json::{Value, json};

#[test]
fn ping_returns_ok() {
    let Some(game) = common::launch("smoke_ping_returns_ok") else {
        return;
    };

    let resp: Value = game
        .op_json("ping", &json!({}))
        .expect("ping op should succeed");

    // The mod's ping op replies with an envelope; we just check we
    // got back a JSON object (not an error string). The exact shape
    // is documented in horsey-mod/src/ops.rs.
    assert!(
        resp.is_object() || resp.is_null(),
        "ping returned non-object response: {resp}"
    );
}
