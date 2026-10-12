//! Give the player the Luck tome the way the game does, and read luck.
//!
//! 2026-10-03: final luck is base x additive (luck_math.rs); the live
//! luck set has base 0, so the stored +24.9 additive counts as 0, and
//! this run has no luck tome (HasTome(Luck) false, luck_check.rs). In
//! run 1 added luck counted once a luck tome was held.
//!
//! `TomeInventory.AddTome(TomeData tomeData, List<StatModifier>
//! upgradeOffer, ERarity rarity)` (research_luck_write.rs). This finds
//! the game's own TomeData whose tome is Luck (ETome 13), passes an
//! empty upgrade list and rarity Common (ERarity 1), and prints
//! HasTome(Luck), the luck parts and GetStat(Luck) before and after.
//!
//! ```text
//! k3sc cargo-lock test -p megabonk-mod --test tome_add -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, find_instances, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

const LUCK_STAT: i64 = 30;
const LUCK_TOME: i64 = 13;
const COMMON: i64 = 1;
/// EStat 17 is Lifesteal.
const LIFESTEAL_STAT: i64 = 17;

/// MEGABONK_TOME picks the tome (ETome: 13 Luck, 18 Blood/lifesteal);
/// default Luck.
fn wanted_tome() -> i64 {
    std::env::var("MEGABONK_TOME").ok().and_then(|v| v.parse().ok()).unwrap_or(LUCK_TOME)
}

fn call(api: &Api<Value>, h: i64, method: &str, args: Value) -> Value {
    let r = api.op("invoke_method", json!({"handle": h, "method": method, "args": args}));
    if !r.ok {
        println!("  {method} failed: {:?}", r.error);
    }
    r.result
}

fn report(api: &Api<Value>, tomes: i64, stats: i64, label: &str) {
    println!(
        "{label}: HasTome({}) = {}, GetNumTomes = {}, GetStat(Lifesteal) = {}",
        wanted_tome(),
        call(api, tomes, "HasTome", json!([wanted_tome()])),
        call(api, tomes, "GetNumTomes", json!([])),
        call(api, stats, "GetStat", json!([LIFESTEAL_STAT]))
    );
    if let Some(map) = handle_of(&call(api, stats, "get_statValuesMap", json!([]))) {
        for (name, stat) in [("luck", LUCK_STAT), ("lifesteal", LIFESTEAL_STAT)] {
            if let Some(c) = handle_of(&call(api, map, "get_Item", json!([stat]))) {
                let f = &api.op("inspect_object", json!({"handle": c})).result["fields"];
                println!(
                    "{label}: {name} parts = base {} additive {} mult {}",
                    f["_baseValue_k__BackingField"], f["_additiveValue_k__BackingField"], f["_multiplicativeValue_k__BackingField"]
                );
            }
        }
    }
    println!("{label}: GetStat(Luck) = {}", call(api, stats, "GetStat", json!([LUCK_STAT])));
}

#[test]
fn add_luck_tome() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let gm = api.op("invoke_static", json!({"class": "Il2Cpp.GameManager", "method": "get_Instance", "args": []}));
    let gm = handle_of(&gm.result).expect("GameManager.Instance");
    let player = handle_of(&call(&api, gm, "get_player", json!([]))).expect("player (start a run first)");
    let inv = handle_of(&call(&api, player, "get_inventory", json!([]))).expect("player.inventory");
    let tomes = handle_of(&call(&api, inv, "get_tomeInventory", json!([]))).expect("tomeInventory");
    let stats = handle_of(&call(&api, inv, "get_playerStats", json!([]))).expect("playerStats");

    // The game's TomeData assets; the Luck one carries tome 13 in a
    // field whose name holds "tome".
    let list = find_instances(&api, "TomeData", true).expect("TomeData walk");
    println!("TomeData assets: {}", list.len());
    let mut luck_tome = None;
    for v in &list {
        let Some(h) = v.get("handle").and_then(Value::as_i64) else { continue };
        let f = api.op("inspect_object", json!({"handle": h})).result;
        let fields = f["fields"].as_object().cloned().unwrap_or_default();
        let id = fields
            .iter()
            .find(|(k, val)| k.to_ascii_lowercase().contains("tome") && val.is_number())
            .map(|(k, val)| (k.clone(), val.clone()));
        if luck_tome.is_none() {
            println!("  first TomeData fields: {}", serde_json::to_string(&f["fields"]).unwrap_or_default());
        }
        if let Some((k, val)) = &id
            && val.as_i64() == Some(wanted_tome())
        {
            println!("  tome: {}={val}, says {}", k, fields.get("description").cloned().unwrap_or_default());
            luck_tome = Some(h);
        }
    }
    let luck_tome = luck_tome.unwrap_or_else(|| panic!("no TomeData with tome {}", wanted_tome()));

    let made = api.op(
        "invoke_static",
        json!({"class": "System.Activator", "method": "CreateInstance",
               "args": ["Il2CppSystem.Collections.Generic.List`1[[Il2CppAssets.Scripts.Inventory__Items__Pickups.Stats.StatModifier, Assembly-CSharp]], Il2Cppmscorlib"]}),
    );
    let offer = handle_of(&made.result).unwrap_or_else(|| panic!("empty upgrade list: {} {:?}", made.result, made.error));

    report(&api, tomes, stats, "before");
    let r = api.op(
        "invoke_method",
        json!({"handle": tomes, "method": "AddTome", "args": [{"$handle": luck_tome}, {"$handle": offer}, COMMON]}),
    );
    println!("AddTome: ok={} {:?}", r.ok, r.error);
    std::thread::sleep(std::time::Duration::from_millis(500));
    report(&api, tomes, stats, "after");

    for v in &list {
        if let Some(h) = v.get("handle").and_then(Value::as_i64) {
            api.op("release_handle", json!({"handle": h}));
        }
    }
    for h in [offer, stats, tomes, inv, player, gm] {
        api.op("release_handle", json!({"handle": h}));
    }
    assert!(r.ok, "AddTome failed");
}
