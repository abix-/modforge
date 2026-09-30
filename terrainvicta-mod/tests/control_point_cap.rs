//! Ten times the control point cap: the player's cap as the game
//! computes it, and as every caller sees it through the patch.
//!
//! ```text
//! TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test control_point_cap -- --nocapture
//! ```

mod common;
use common::api_or_skip;
use serde_json::json;

#[test]
fn player_cap_is_ten_times() {
    let Some(api) = api_or_skip() else { return };
    let r = api.op("control_point_cap", json!({}));
    assert!(r.ok, "control_point_cap failed: {:?}", r.error);
    println!("{}", r.result);
    let game = r.result["game_cap"].as_f64().expect("game_cap");
    let patched = r.result["patched_cap"].as_f64().expect("patched_cap");
    assert!(
        (patched - game * 10.0).abs() < 0.01,
        "patched {patched} is not 10x game {game}"
    );
}
