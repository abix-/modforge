//! Ten times the org budget: the player's first councilor's
//! Administration for org control as the game computes it, and as
//! every caller sees it through the patch.
//!
//! ```text
//! TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test org_budget -- --nocapture
//! ```

mod common;
use common::api_or_skip;
use serde_json::json;

#[test]
fn player_org_budget_is_ten_times() {
    let Some(api) = api_or_skip() else { return };
    let r = api.op("org_budget", json!({}));
    assert!(r.ok, "org_budget failed: {:?}", r.error);
    println!("{}", r.result);
    let game = r.result["game_budget"].as_i64().expect("game_budget");
    let patched = r.result["patched_budget"].as_i64().expect("patched_budget");
    assert_eq!(patched, game * 10, "patched {patched} is not 10x game {game}");
}
