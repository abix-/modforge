//! How to raise the luck stat the way the game does.
//!
//! Read-only. Luck is EStat 30 and reads 0.0 through
//! `PlayerStats.GetStat` (research_stats.rs, 2026-10-03). Changes to a
//! stat go through `StatInventory.ChangeStat` (4 arguments) and
//! `PlayerStatsNew.ApplyStatModifier` (5); StatInventory and
//! PlayerStatsNew are not Unity objects (find_instances found 0), so
//! this test finds:
//! - the parameter types and names of both methods, through the
//!   runtime's own reflection (Type.GetMethods, GetParameters)
//! - the live PlayerInventory and its fields, the object
//!   `PlayerStatsNew.playerInventory` points at
//!
//! ```text
//! k3sc cargo-lock test -p megabonk-mod --test research_luck_write -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, find_instances, handle_of, parameters, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

fn call(api: &Api<Value>, h: i64, method: &str, args: Value) -> Value {
    api.op("invoke_method", json!({"handle": h, "method": method, "args": args})).result
}

#[test]
fn luck_write_path() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    println!("== parameters");
    parameters(
        &api,
        "Assets.Scripts.Inventory__Items__Pickups.Stats.StatInventory",
        "ChangeStat",
    );
    parameters(
        &api,
        "Assets.Scripts.Inventory__Items__Pickups.Stats.PlayerStatsNew",
        "ApplyStatModifier",
    );
    // A luck tome (ETome 13) is the likely game-side luck that made
    // added luck count in run 1 (2026-10-03).
    parameters(&api, "Assets.Scripts.Inventory__Items__Pickups.TomeInventory", "AddTome");
    parameters(&api, "Assets.Scripts.Inventory__Items__Pickups.TomeInventory", "HasTome");

    // ChangeStat(StatModifier stat, bool permanent, float timeout,
    // bool addToShrineLog), read 2026-10-03. What a StatModifier holds:
    println!("\n== StatModifier fields (walk_class)");
    let r = api.op(
        "walk_class",
        json!({"class": "Il2CppAssets.Scripts.Inventory__Items__Pickups.Stats.StatModifier"}),
    );
    println!("{}", serde_json::to_string(&r.result).unwrap_or_default());

    // A StatModifier made with Activator.CreateInstance comes back as a
    // plain Il2CppSystem.Object proxy whose fields write_field cannot
    // see (luck_add.rs, 2026-10-03). Its own methods: a copy or a
    // factory would hand back a typed one.
    println!("\n== StatModifier methods");
    common::print_declared_methods(&api, "Il2CppAssets.Scripts.Inventory__Items__Pickups.Stats.StatModifier");

    // walk_class listed nothing for StatModifier, so read a real one:
    // UpgradeData.upgradeModifiers is a List<StatModifier>.
    println!("\n== a live StatModifier (from UpgradeData.upgradeModifiers)");
    let ups = find_instances(&api, "Il2CppAssets.Scripts.Inventory__Items__Pickups.Upgrades.UpgradeData", true)
        .unwrap_or_default();
    if let Some(u) = ups.first().and_then(|v| v.get("handle")).and_then(Value::as_i64)
        && let Some(list) = handle_of(&call(&api, u, "get_upgradeModifiers", json!([])))
        && let Some(m) = handle_of(&call(&api, list, "get_Item", json!([0])))
    {
        let r = api.op("inspect_object", json!({"handle": m}));
        println!("{}", serde_json::to_string_pretty(&r.result).unwrap_or_default());
        api.op("release_handle", json!({"handle": m}));
        api.op("release_handle", json!({"handle": list}));
    } else {
        println!("  no UpgradeData with a first modifier");
    }
    for v in &ups {
        if let Some(h) = v.get("handle").and_then(Value::as_i64) {
            api.op("release_handle", json!({"handle": h}));
        }
    }

    // The live player: GameManager.Instance (static) -> player.
    println!("\n== GameManager.Instance.player fields");
    let gm = api.op("invoke_static", json!({"class": "Il2Cpp.GameManager", "method": "get_Instance", "args": []}));
    if let Some(gm_h) = handle_of(&gm.result) {
        if let Some(p) = handle_of(&call(&api, gm_h, "get_player", json!([]))) {
            let r = api.op("inspect_object", json!({"handle": p}));
            println!("{}", serde_json::to_string_pretty(&r.result).unwrap_or_default());
            api.op("release_handle", json!({"handle": p}));
        } else {
            println!("  get_player carried no handle (not in a run?)");
        }
        api.op("release_handle", json!({"handle": gm_h}));
    } else {
        println!("  GameManager.get_Instance carried no handle: {:?}", gm.error);
    }

    // Who holds the live StatInventory: PlayerInventory under its
    // interop name, and its properties (statics first) so a path from
    // a static or a Unity object shows.
    for class in ["Il2Cpp.PlayerInventory", "Il2Cpp.MyPlayer", "Il2Cpp.GameManager"] {
        println!("\n== {class} properties");
        let r = api.op("list_methods", json!({"class": class}));
        if !r.ok {
            println!("  list_methods failed: {:?}", r.error);
            continue;
        }
        let empty = vec![];
        for m in r.result["methods"].as_array().unwrap_or(&empty) {
            let name = m["name"].as_str().unwrap_or("?");
            if name.starts_with("get_") {
                println!(
                    "  {name} -> {}{}",
                    m["return"].as_str().unwrap_or("?"),
                    if m["static"].as_bool().unwrap_or(false) { " [static]" } else { "" }
                );
            }
        }
        let list = find_instances(&api, class, true).unwrap_or_default();
        println!("  live instances: {}", list.len());
        for v in &list {
            if let Some(h) = v.get("handle").and_then(Value::as_i64) {
                api.op("release_handle", json!({"handle": h}));
            }
        }
    }
}
