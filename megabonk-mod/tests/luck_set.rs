//! Set luck so the game counts it, and read it back.
//!
//! Found 2026-10-03 (luck_check.rs): luck is built from the StatComponents
//! in PlayerStatsNew.statValuesMap[Luck] (the same object
//! PlayerStats.GetStatComponents(Luck) returns): base 0.0, additive 25.9,
//! multiplicative 1.0, hasModifications false, and GetStat(Luck) read 0.0.
//! With hasModifications false the additions are not counted. In run 1
//! luck picked up in the game set it, and every add after counted at one
//! tenth.
//!
//! This sets hasModifications true and the additive to
//! `MEGABONK_LUCK_ADDITIVE` (default 20.0, luck 2.0 at one tenth), asks the
//! game to recompute luck (PlayerStatsNew.UpdateStat(Luck)), and prints
//! the components and GetStat(Luck) after.
//!
//! ```text
//! MEGABONK_LUCK_ADDITIVE=20 k3sc cargo-lock test -p megabonk-mod --test luck_set -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

const LUCK: i64 = 30;

fn call(api: &Api<Value>, h: i64, method: &str, args: Value) -> Value {
    let r = api.op("invoke_method", json!({"handle": h, "method": method, "args": args}));
    assert!(r.ok, "{method} failed: {:?}", r.error);
    r.result
}

#[test]
fn set_luck() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let additive: f64 = std::env::var("MEGABONK_LUCK_ADDITIVE").ok().and_then(|v| v.parse().ok()).unwrap_or(20.0);

    let gm = api.op("invoke_static", json!({"class": "Il2Cpp.GameManager", "method": "get_Instance", "args": []}));
    let gm = handle_of(&gm.result).expect("GameManager.Instance");
    let player = handle_of(&call(&api, gm, "get_player", json!([]))).expect("player (start a run first)");
    let inv = handle_of(&call(&api, player, "get_inventory", json!([]))).expect("player.inventory");
    let stats = handle_of(&call(&api, inv, "get_playerStats", json!([]))).expect("playerStats");
    let map = handle_of(&call(&api, stats, "get_statValuesMap", json!([]))).expect("statValuesMap");
    let comps = handle_of(&call(&api, map, "get_Item", json!([LUCK]))).expect("statValuesMap[Luck]");

    println!("before: {}", api.op("inspect_object", json!({"handle": comps})).result["fields"]);
    println!("before GetStat(Luck) = {}", call(&api, stats, "GetStat", json!([LUCK])));

    for (field, value) in [("hasModifications", json!(true)), ("_additiveValue_k__BackingField", json!(additive))] {
        let w = api.op("write_field", json!({"handle": comps, "field": field, "value": value}));
        assert!(w.ok, "write {field}: {:?}", w.error);
    }
    call(&api, stats, "UpdateStat", json!([LUCK]));

    println!("after:  {}", api.op("inspect_object", json!({"handle": comps})).result["fields"]);
    let luck = call(&api, stats, "GetStat", json!([LUCK]));
    println!("after GetStat(Luck) = {luck}");

    for h in [comps, map, stats, inv, player, gm] {
        api.op("release_handle", json!({"handle": h}));
    }
    assert!(luck.as_f64().unwrap_or(0.0) > 0.0, "luck still {luck}");
}
