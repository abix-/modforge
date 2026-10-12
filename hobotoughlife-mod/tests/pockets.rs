//! The pockets feature through its op, against the live game.
//!
//! ```text
//! k3sc cargo-lock test -p hobotoughlife-mod --test pockets -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs when the game is not running; needs a loaded save.

mod common;
use common::{api, ping_or_skip};
use serde_json::json;

/// Enabled through the op, Pockets reads back the mod's size (220).
/// CHANGES GAME STATE: writes Pockets.
#[test]
fn pockets_op_applies_size() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let read = api.op("pockets", json!({}));
    println!("before: {} {:?}", read.result, read.error);
    let set = api.op("pockets", json!({"enabled": true}));
    println!("after enabled=true: {} {:?}", set.result, set.error);
    assert!(set.ok, "op failed: {:?}", set.error);
    assert_eq!(set.result["pockets"].as_f64(), Some(220.0), "{}", set.result);
}
