//! Did a luck change land, and does the stat pick it up?
//!
//! luck_add.rs (2026-10-03) made a typed StatModifier {stat 30, +1.0,
//! modifyType 0} and StatInventory.ChangeStat returned ok, but
//! PlayerStats.GetStat(Luck) still read 0 two seconds later. This adds
//! nothing. It prints StatInventory.permanentChanges (where a permanent
//! ChangeStat should be stored) and GetStat / GetRawStat /
//! GetUnclampedStat for Luck on the live PlayerStatsNew, then asks the
//! game to recompute (PlayerStatsNew.ForceUpdateStats) and reads them
//! again.
//!
//! ```text
//! k3sc cargo-lock test -p megabonk-mod --test luck_check -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, count_of, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

const LUCK: i64 = 30;

fn call(api: &Api<Value>, h: i64, method: &str, args: Value) -> Value {
    let r = api.op("invoke_method", json!({"handle": h, "method": method, "args": args}));
    if !r.ok {
        println!("  {method} failed: {:?}", r.error);
    }
    r.result
}

fn read_luck(api: &Api<Value>, stats: i64, label: &str) {
    for m in ["GetStat", "GetRawStat", "GetUnclampedStat"] {
        println!("  {label} {m}(Luck) = {}", call(api, stats, m, json!([LUCK])));
    }
    // luck_add.rs reads the static PlayerStats.GetStat; compare.
    let s = api.op(
        "invoke_static",
        json!({"class": "Il2CppAssets.Scripts.Inventory.Stats.PlayerStats", "method": "GetStat", "args": [LUCK]}),
    );
    println!("  {label} static PlayerStats.GetStat(Luck) = {}", s.result);
}

#[test]
fn luck_landed() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let gm = api.op("invoke_static", json!({"class": "Il2Cpp.GameManager", "method": "get_Instance", "args": []}));
    let gm = handle_of(&gm.result).expect("GameManager.Instance");
    let player = handle_of(&call(&api, gm, "get_player", json!([]))).expect("player (start a run first)");
    let inv = handle_of(&call(&api, player, "get_inventory", json!([]))).expect("player.inventory");
    let stat_inv = handle_of(&call(&api, inv, "get_statInventory", json!([]))).expect("statInventory");
    let stats = handle_of(&call(&api, inv, "get_playerStats", json!([]))).expect("playerStats");

    println!("== StatInventory.permanentChanges");
    if let Some(d) = handle_of(&call(&api, stat_inv, "get_permanentChanges", json!([]))) {
        println!("  count = {:?}", count_of(&api, d));
        println!("  has Luck = {}", call(&api, d, "ContainsKey", json!([LUCK])));
        // The value is a List<StatModifier>: each entry's fields.
        if let Some(list) = handle_of(&call(&api, d, "get_Item", json!([LUCK]))) {
            let n = count_of(&api, list).unwrap_or(0);
            println!("  [Luck] has {n} modifier(s)");
            for i in 0..n {
                if let Some(m) = handle_of(&call(&api, list, "get_Item", json!([i]))) {
                    println!("    {i}: {}", api.op("inspect_object", json!({"handle": m})).result["fields"]);
                    api.op("release_handle", json!({"handle": m}));
                }
            }
            api.op("release_handle", json!({"handle": list}));
        }
        api.op("release_handle", json!({"handle": d}));
    }

    // Does the live stat table have a Luck entry at all? In run 1 adds
    // only counted after the game had given luck (2026-10-03).
    println!("== PlayerStatsNew tables");
    for getter in ["get_stats", "get_rawStats", "get_statValuesMap"] {
        if let Some(d) = handle_of(&call(&api, stats, getter, json!([]))) {
            println!(
                "  {getter}: count {:?}, has Luck {}",
                count_of(&api, d),
                call(&api, d, "ContainsKey", json!([LUCK]))
            );
            api.op("release_handle", json!({"handle": d}));
        }
    }

    // How the change travels (2026-10-03, run 2: stored modifiers +20,
    // +1, +3.9 never reached GetStat). Each step read, nothing written:
    // - StatInventory.refreshStats: stats waiting after a ChangeStat
    // - PlayerStatsNew.queuedUpdateStats: stats waiting to recompute
    // - PlayerStats.GetStatComponents(Luck): what luck is built from
    // - the Luck entry in each PlayerStatsNew table
    println!("== waiting lists");
    for (owner, getter) in [(stat_inv, "get_refreshStats"), (stats, "get_queuedUpdateStats")] {
        if let Some(set) = handle_of(&call(&api, owner, getter, json!([]))) {
            println!(
                "  {getter}: count {:?}, has Luck {}",
                count_of(&api, set),
                call(&api, set, "Contains", json!([LUCK]))
            );
            api.op("release_handle", json!({"handle": set}));
        }
    }
    println!("== what luck is built from");
    let comps = api.op(
        "invoke_static",
        json!({"class": "Il2CppAssets.Scripts.Inventory.Stats.PlayerStats", "method": "GetStatComponents", "args": [LUCK]}),
    );
    match handle_of(&comps.result) {
        Some(c) => {
            println!("  GetStatComponents(Luck) = {}", api.op("inspect_object", json!({"handle": c})).result["fields"]);
            api.op("release_handle", json!({"handle": c}));
        }
        None => println!("  GetStatComponents(Luck) = {} {:?}", comps.result, comps.error),
    }
    for getter in ["get_statValuesMap", "get_rawStats", "get_stats"] {
        if let Some(d) = handle_of(&call(&api, stats, getter, json!([]))) {
            let v = call(&api, d, "get_Item", json!([LUCK]));
            match handle_of(&v) {
                Some(h) => {
                    println!("  {getter}[Luck] = {}", api.op("inspect_object", json!({"handle": h})).result["fields"]);
                    api.op("release_handle", json!({"handle": h}));
                }
                None => println!("  {getter}[Luck] = {v}"),
            }
            api.op("release_handle", json!({"handle": d}));
        }
    }

    // luck_set.rs (2026-10-03): hasModifications true, additive 25.9,
    // and GetStat(Luck) still 0.0. Where do the parts become the final
    // value? StatComponents' own methods, and what CheckFinalValue
    // makes of a luck of 2.0 (both pure reads of the game's math).
    println!("== final value");
    common::print_declared_methods(&api, "Il2CppAssets.Scripts.Inventory__Items__Pickups.Stats.StatComponents");
    println!("  CheckFinalValue(Luck, 2.0) = {}", call(&api, stats, "CheckFinalValue", json!([LUCK, 2.0])));
    // StatComponents.GetFinalValue(1 arg) is the sum: its parameter,
    // then what it makes of the live luck components.
    let ty = api.op(
        "invoke_static",
        json!({"class": "Il2CppSystem.Type", "method": "GetType",
               "args": ["Assets.Scripts.Inventory__Items__Pickups.Stats.StatComponents, Assembly-CSharp"]}),
    );
    if let Some(t) = handle_of(&ty.result)
        && let Some(m) = handle_of(&call(&api, t, "GetMethod", json!(["GetFinalValue"])))
        && let Some(ps) = handle_of(&call(&api, m, "GetParameters", json!([])))
        && let Some(p) = handle_of(&call(&api, ps, "get_Item", json!([0])))
    {
        let pt = handle_of(&call(&api, p, "get_ParameterType", json!([])));
        println!(
            "  GetFinalValue({} {})",
            pt.map(|h| call(&api, h, "get_FullName", json!([]))).unwrap_or(Value::Null),
            call(&api, p, "get_Name", json!([]))
        );
    }
    if let Some(d) = handle_of(&call(&api, stats, "get_statValuesMap", json!([])))
        && let Some(c) = handle_of(&call(&api, d, "get_Item", json!([LUCK])))
    {
        // GetFinalValue(StatComponents other): the parameter is a second
        // set of parts. With itself, and with a fresh default one.
        let fresh = api.op(
            "invoke_static",
            json!({"class": "System.Activator", "method": "CreateInstance",
                   "args": ["Il2CppAssets.Scripts.Inventory__Items__Pickups.Stats.StatComponents, Assembly-CSharp"]}),
        );
        let fresh = handle_of(&fresh.result);
        if let Some(f) = fresh {
            println!("  fresh StatComponents = {}", api.op("inspect_object", json!({"handle": f})).result["fields"]);
        }
        for (label, other) in [("itself", Some(c)), ("fresh", fresh)] {
            let Some(o) = other else { continue };
            let r = api.op("invoke_method", json!({"handle": c, "method": "GetFinalValue", "args": [{"$handle": o}]}));
            println!("  luck components GetFinalValue({label}) = {} {:?}", r.result, r.error);
        }
    }
    let base = api.op(
        "invoke_static",
        json!({"class": "Il2CppAssets.Scripts.Inventory__Items__Pickups.Stats.PlayerStatsNew", "method": "GetBaseValue", "args": [LUCK]}),
    );
    println!("  GetBaseValue(Luck) = {} {:?}", base.result, base.error);

    // GetFinalValue(other) with a fresh set (multiplicative 0.0) gives
    // 0.0, with luck's own set 0.259 (2026-10-03). The set UpdateStat
    // pairs luck with must come from something else the player carries:
    // every field of the inventory's parts whose type names a stat.
    if let Some(tomes) = handle_of(&call(&api, inv, "get_tomeInventory", json!([]))) {
        // ETome 13 is Luck.
        println!("== tomes: HasTome(Luck) = {}, GetNumTomes = {}, IsMaxed = {}",
            call(&api, tomes, "HasTome", json!([13])),
            call(&api, tomes, "GetNumTomes", json!([])),
            call(&api, tomes, "IsMaxed", json!([])));
        // How many tomes a run may hold: every plain field.
        let f = api.op("inspect_object", json!({"handle": tomes})).result;
        if let Some(fields) = f["fields"].as_object() {
            let plain: Vec<String> = fields
                .iter()
                .filter(|(_, v)| v.is_number() || v.is_boolean())
                .map(|(k, v)| format!("{k}={v}"))
                .collect();
            println!("   tomeInventory: {}", plain.join(", "));
        }
        // No instance field holds the limit: the static properties.
        let r = api.op("list_methods", json!({"class": "Il2CppAssets.Scripts.Inventory__Items__Pickups.TomeInventory"}));
        let empty = vec![];
        for m in r.result["methods"].as_array().unwrap_or(&empty) {
            let name = m["name"].as_str().unwrap_or("");
            if m["static"].as_bool() == Some(true) && name.starts_with("get_") {
                let v = api.op(
                    "invoke_static",
                    json!({"class": "Il2CppAssets.Scripts.Inventory__Items__Pickups.TomeInventory", "method": name, "args": []}),
                );
                println!("   static {name} = {}", v.result);
            }
        }
        api.op("release_handle", json!({"handle": tomes}));
    }

    println!("== stat-holding fields of the inventory's parts");
    for getter in [
        "get_itemInventory",
        "get_tomeInventory",
        "get_weaponInventory",
        "get_statusEffects",
        "get_passiveAbility",
        "get_characterData",
    ] {
        let Some(part) = handle_of(&call(&api, inv, getter, json!([]))) else {
            println!("  {getter}: none");
            continue;
        };
        let f = api.op("inspect_object", json!({"handle": part})).result;
        let mut shown = Vec::new();
        if let Some(fields) = f["fields"].as_object() {
            for (k, v) in fields {
                let ty = v.get("il2cpp_type").and_then(Value::as_str).unwrap_or("");
                if ty.contains("Stat") || k.to_ascii_lowercase().contains("stat") || k.to_ascii_lowercase().contains("luck") {
                    shown.push(format!("{k}: {}", if ty.is_empty() { v.to_string() } else { ty.to_string() }));
                }
            }
        }
        println!("  {getter} ({}): {}", f["type"], shown.join("; "));
        api.op("release_handle", json!({"handle": part}));
    }

    println!("== PlayerStatsNew, before recompute");
    read_luck(&api, stats, "before");
    call(&api, stats, "ForceUpdateStats", json!([]));
    println!("== PlayerStatsNew, after ForceUpdateStats");
    read_luck(&api, stats, "after");
    // 2026-10-03: a stored +20.0 Luck modifier read 0.0 even after
    // ForceUpdateStats; UpdateStat(EStat) recomputes the one stat.
    call(&api, stats, "UpdateStat", json!([LUCK]));
    println!("== PlayerStatsNew, after UpdateStat(Luck)");
    read_luck(&api, stats, "after UpdateStat");

    // 2026-10-03, second run: the stored +20.0 never reached GetStat,
    // where in the first run every add did. Is GameManager.player the
    // live player, or the dead run's? Compare with every live MyPlayer.
    println!("== players");
    println!("  GameManager.player = {}", api.op("inspect_object", json!({"handle": player})).result["fields"]["inventory"]);
    let players = common::find_instances(&api, "Il2CppAssets.Scripts.Actors.Player.MyPlayer", true).unwrap_or_default();
    println!("  live MyPlayer objects: {}", players.len());
    for v in &players {
        if let Some(h) = v.get("handle").and_then(Value::as_i64) {
            let f = api.op("inspect_object", json!({"handle": h})).result;
            println!("  MyPlayer ptr={} inventory={}", v.get("ptr").unwrap_or(&Value::Null), f["fields"]["inventory"]);
            api.op("release_handle", json!({"handle": h}));
        }
    }

    for h in [stats, stat_inv, inv, player, gm] {
        api.op("release_handle", json!({"handle": h}));
    }
}
