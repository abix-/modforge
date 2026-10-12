//! The player's live stats, every one, by name.
//!
//! Read-only. `PlayerStatsNew.GetStat(EStat)` on the live player for
//! every EStat (names from the runtime's own Enum.GetNames). Used to see
//! why the player dies (defense, difficulty, enemy damage).
//!
//! ```text
//! k3sc cargo-lock test -p megabonk-mod --test stats_now -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, enum_names, handle_of, ping_or_skip};
use serde_json::json;

#[test]
fn every_stat() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let names = enum_names(&api, "Assets.Scripts.Menu.Shop.EStat");
    let call = |h: i64, m: &str, args: serde_json::Value| {
        api.op("invoke_method", json!({"handle": h, "method": m, "args": args})).result
    };
    let gm = handle_of(&api.op("invoke_static", json!({"class": "Il2Cpp.GameManager", "method": "get_Instance", "args": []})).result)
        .expect("GameManager.Instance");
    let player = handle_of(&call(gm, "get_player", json!([]))).expect("player (start a run first)");
    let inv = handle_of(&call(player, "get_inventory", json!([]))).expect("inventory");
    let stats = handle_of(&call(inv, "get_playerStats", json!([]))).expect("playerStats");
    for (i, n) in names.iter().enumerate() {
        println!("{i:2} {n:28} {}", call(stats, "GetStat", json!([i])));
    }
}
