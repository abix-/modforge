//! Raise the player's luck stat the way the game does, and prove it.
//!
//! Read 2026-10-03 (research_stats.rs, research_luck_write.rs):
//! - luck is EStat 30, read with static `PlayerStats.GetStat(30)`
//! - the live stats: `GameManager.Instance.player` (MyPlayer)
//!   `.inventory` (PlayerInventory) `.statInventory` (StatInventory)
//! - `StatInventory.ChangeStat(StatModifier stat, bool permanent,
//!   float timeout, bool addToShrineLog)`
//! - a real upgrade's StatModifier: `{stat: 9, modification: 0.15,
//!   modifyType: 0}` (+0.15 SizeMultiplier)
//!
//! This makes a new StatModifier (Activator.CreateInstance), sets it
//! to Luck with `MEGABONK_LUCK_ADD` (default 1.0) and modifyType 0, calls
//! ChangeStat with permanent true, and asserts GetStat(Luck) went up.
//! Needs a run in progress.
//!
//! ```text
//! MEGABONK_LUCK_ADD=1 k3sc cargo-lock test -p megabonk-mod --test luck_add -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

const PLAYER_STATS: &str = "Il2CppAssets.Scripts.Inventory.Stats.PlayerStats";
const LUCK: i64 = 30;

fn call(api: &Api<Value>, h: i64, method: &str, args: Value) -> Value {
    api.op("invoke_method", json!({"handle": h, "method": method, "args": args})).result
}

/// The live PlayerInventory (GameManager.Instance.player.inventory).
fn inv_after(api: &Api<Value>) -> i64 {
    let gm = api.op("invoke_static", json!({"class": "Il2Cpp.GameManager", "method": "get_Instance", "args": []}));
    let gm = handle_of(&gm.result).expect("GameManager.Instance");
    let player = handle_of(&call(api, gm, "get_player", json!([]))).expect("player");
    handle_of(&call(api, player, "get_inventory", json!([]))).expect("inventory")
}

fn luck(api: &Api<Value>) -> f64 {
    let r = api.op("invoke_static", json!({"class": PLAYER_STATS, "method": "GetStat", "args": [LUCK]}));
    r.result.as_f64().unwrap_or_else(|| panic!("GetStat(Luck) gave {} {:?}", r.result, r.error))
}

#[test]
fn add_luck() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let before = luck(&api);
    println!("luck before: {before}");

    let gm = api.op("invoke_static", json!({"class": "Il2Cpp.GameManager", "method": "get_Instance", "args": []}));
    let gm = handle_of(&gm.result).expect("GameManager.Instance");
    let player = handle_of(&call(&api, gm, "get_player", json!([]))).expect("player (start a run first)");
    let inv = handle_of(&call(&api, player, "get_inventory", json!([]))).expect("player.inventory");
    let stat_inv = handle_of(&call(&api, inv, "get_statInventory", json!([]))).expect("inventory.statInventory");

    // MEGABONK_LUCK_TARGET sets the luck to reach instead. Final luck is
    // base x additive (luck_math.rs, 2026-10-03: base 0.005 x additive
    // 25.9 read 0.1295 live; run 1's "one tenth" was a base of 0.1), so
    // the add is the gap over the live base.
    let target: Option<f64> = std::env::var("MEGABONK_LUCK_TARGET").ok().and_then(|v| v.parse().ok());
    let add: f64 = match target {
        Some(t) => {
            let stats = handle_of(&call(&api, inv, "get_playerStats", json!([]))).expect("playerStats");
            let map = handle_of(&call(&api, stats, "get_statValuesMap", json!([]))).expect("statValuesMap");
            let parts = handle_of(&call(&api, map, "get_Item", json!([LUCK]))).expect("statValuesMap[Luck]");
            let base = api.op("inspect_object", json!({"handle": parts})).result["fields"]["_baseValue_k__BackingField"]
                .as_f64()
                .expect("luck base");
            for h in [parts, map, stats] {
                api.op("release_handle", json!({"handle": h}));
            }
            println!("luck base: {base}");
            assert!(base > 0.0, "luck base is {base}: no added luck can count until the game gives a base");
            (t - before) / base
        }
        None => std::env::var("MEGABONK_LUCK_ADD").ok().and_then(|v| v.parse().ok()).unwrap_or(1.0),
    };
    assert!(add > 0.0, "luck is already {before}, at or above the target {target:?}");
    println!("adding {add}");

    // The game-side Il2CppSystem.Activator hands back a plain
    // Il2CppSystem.Object proxy whose fields write_field cannot see
    // (2026-10-03). The host's System.Activator builds the interop
    // proxy itself (its parameterless ctor allocates the il2cpp
    // object), so the handle is typed StatModifier. The type crosses
    // as its assembly-qualified name (Newtonsoft turns the string
    // into a System.Type for the parameter).
    let made = api.op(
        "invoke_static",
        json!({"class": "System.Activator", "method": "CreateInstance",
               "args": ["Il2CppAssets.Scripts.Inventory__Items__Pickups.Stats.StatModifier, Assembly-CSharp"]}),
    );
    println!("CreateInstance: ok={} result={} error={:?}", made.ok, made.result, made.error);
    let m = handle_of(&made.result).unwrap_or_else(|| panic!("CreateInstance gave {} {:?}", made.result, made.error));
    let ty = m;
    // EStatModifyType: 0 Addition, 1 Multiplication, 2 Flat (read
    // 2026-10-03). MEGABONK_LUCK_TYPE picks it; default 0.
    let modify_type: i64 = std::env::var("MEGABONK_LUCK_TYPE").ok().and_then(|v| v.parse().ok()).unwrap_or(0);
    for (field, value) in [("stat", json!(LUCK)), ("modification", json!(add)), ("modifyType", json!(modify_type))] {
        let w = api.op("write_field", json!({"handle": m, "field": field, "value": value}));
        assert!(w.ok, "write {field}: {:?}", w.error);
    }
    let shown = api.op("inspect_object", json!({"handle": m}));
    println!("modifier: {}", shown.result["fields"]);

    let r = api.op(
        "invoke_method",
        json!({"handle": stat_inv, "method": "ChangeStat", "args": [{"$handle": m}, true, 0.0, false]}),
    );
    assert!(r.ok, "ChangeStat failed: {:?}", r.error);

    for h in [m, ty, stat_inv, inv, player, gm] {
        api.op("release_handle", json!({"handle": h}));
    }

    // The game applies stat changes through a queue (PlayerStatsNew
    // QueueUpdateStat / TryPopStatUpdatesQueue). On 2026-10-03 a +1.0
    // still read 0 after 2 s and 0.2 a minute later, so read until it
    // moves, up to 10 s.
    let mut after = luck(&api);
    for _ in 0..100 {
        if after > before {
            break;
        }
        std::thread::sleep(std::time::Duration::from_millis(100));
        after = luck(&api);
    }
    println!("luck after:  {after}");
    if let Some(stats) = handle_of(&call(&api, inv_after(&api), "get_playerStats", json!([])))
        && let Some(map) = handle_of(&call(&api, stats, "get_statValuesMap", json!([])))
        && let Some(parts) = handle_of(&call(&api, map, "get_Item", json!([LUCK])))
    {
        println!("luck parts after: {}", api.op("inspect_object", json!({"handle": parts})).result["fields"]);
    }
    println!("added {add}, luck went up {}", after - before);
    assert!(after > before, "luck did not go up: before {before}, after {after}");
}
