//! Every unit's stats, from the game's own config tables.
//!
//! Read-only. Finds the live GameRiver.Config, takes its
//! ConfigDataContainer's card list (what the player buys) and mech
//! list (the unit's body: life, damage, speed), joins them by
//! mechID and prints one row per card. The base for comparing units.
//!
//! ```text
//! k3sc cargo-lock test -p mechabellum-mod --test research_units -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, count_of, handle_of, ping_or_skip};
use serde_json::{Value, json};
use std::collections::HashMap;
use unityforge::client::Api;

fn call(api: &Api<Value>, h: i64, method: &str) -> Value {
    api.op("invoke_method", json!({"handle": h, "method": method, "args": []})).result
}

/// The live Config. It is a Unity object (base
/// GRSingletonMonoStatic<Config>, read by config_holder), so the
/// object search finds it.
fn config(api: &Api<Value>) -> Option<i64> {
    unityforge::client::first_handle_inactive(api, "GameRiver.Config")
}

/// Every element of an IL2CPP list handle.
fn items(api: &Api<Value>, list: i64) -> Vec<i64> {
    (0..count_of(api, list).unwrap_or(0))
        .filter_map(|i| {
            handle_of(&api.op("invoke_method", json!({"handle": list, "method": "get_Item", "args": [i]})).result)
        })
        .collect()
}

/// Config declares no static getter (2026-11-07). Where the game
/// keeps it: GameData's methods, the GRSingleton base's, and Config's
/// base type through the runtime's reflection.
#[test]
fn config_holder() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    unityforge::client::print_declared_methods(&api, "Il2CppGameRiver.GameData");
    unityforge::client::print_declared_methods(&api, "Il2CppGameRiver.GRSingleton`1");
    let ty = api.op(
        "invoke_static",
        json!({"class": "Il2CppSystem.Type", "method": "GetType", "args": ["GameRiver.Config, GRCore"]}),
    );
    if let Some(t) = handle_of(&ty.result) {
        let base = handle_of(&call(&api, t, "get_BaseType"));
        println!("Config base type: {}", base.map(|b| call(&api, b, "get_FullName")).unwrap_or(Value::Null));
    } else {
        println!("Type.GetType(Config) carried no handle: {:?}", ty.error);
    }
}

/// Damage per hit is not DPS. The attack interval and range should
/// be on the unit's main skill: Config.mechSkillDatas
/// (MechSkillGroupData). Its methods and SkillData's, then the
/// fields of the main skill of three lineup units (Star Expedition
/// ids: Vortex 5031001, Tarantula 5024001, Crawler 5010001).
#[test]
fn skill_table() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    unityforge::client::print_declared_methods(&api, "Il2CppGameRiver.MechSkillGroupData");
    unityforge::client::print_declared_methods(&api, "Il2CppGameRiver.SkillData");
    let cfg = config(&api).expect("live Config");
    let group = handle_of(&call(&api, cfg, "get_mechSkillDatas")).expect("Config.mechSkillDatas");
    println!("MechSkillGroupData fields:");
    for (k, v) in api.op("inspect_object", json!({"handle": group})).result["fields"].as_object().cloned().unwrap_or_default() {
        println!("  {k} = {}", v.get("str").cloned().unwrap_or(v));
    }
    // dataDic: skill id -> ConfigData (the concrete SkillData subclass).
    let dic = handle_of(&api.op("read_field", json!({"handle": group, "field": "dataDic"})).result).expect("dataDic");
    // Lineup units of the first three games (2026-11-07).
    for id in [
        5031001, 5024001, 5010001, 5030001, 5022001, 5021001, 5028001, 5013001, 5015001, 5020001, 5002001,
        5007001, 5009001, 5026001, 5008001, 5023001,
    ] {
        let r = api.op("invoke_method", json!({"handle": dic, "method": "get_Item", "args": [id]}));
        let Some(h) = handle_of(&r.result) else {
            println!("skill {id}: not in dataDic ({:?})", r.error);
            continue;
        };
        println!("--- skill {id} ({}):", r.result["il2cpp_type"]);
        // FPoint is fixed point: RawValue / 2^32 (attackAngle raw
        // 85899345920 reads 20, radius 8589934592 reads 2).
        for getter in [
            "GetAttackRange", "GetMinAttackRange", "GetAttackInterval", "GetAttackPoint",
            "GetAttackBackswing", "GetSplashRange", "GetDamageRate", "IsAirAttack",
            "IsGroundAttack", "IsMeleeAttack", "GetWeaponCount", "GetLoadingCapacity",
            "GetReloadingTime", "GetPrepareTime", "GetCoolingTime", "GetInitialCoolDownTime",
        ] {
            let v = call(&api, h, getter);
            let shown = v.get("RawValue").and_then(Value::as_i64).map(|raw| json!(raw as f64 / 4294967296.0)).unwrap_or(v);
            println!("  {getter} = {shown}");
        }
        let damage = api.op("invoke_method", json!({"handle": h, "method": "GetDamage", "args": [0]}));
        println!("  GetDamage(0) = {} {:?}", damage.result, damage.error);
    }
}

#[test]
fn unit_table() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let Some(cfg) = config(&api) else {
        unityforge::client::print_declared_methods(&api, "Il2CppGameRiver.Config");
        panic!("no live Config found");
    };
    let container = handle_of(&call(&api, cfg, "get_dataContainer")).expect("Config.dataContainer");
    let mechs: HashMap<i64, i64> = items(&api, handle_of(&call(&api, container, "get_mechDatas")).expect("mechDatas"))
        .into_iter()
        .filter_map(|m| api.op("read_field", json!({"handle": m, "field": "id"})).result.as_i64().map(|id| (id, m)))
        .collect();
    println!("{} mech rows", mechs.len());
    let cards = items(&api, handle_of(&call(&api, container, "get_cardDatas")).expect("cardDatas"));
    println!("{} card rows", cards.len());
    let mut first = true;
    for card in cards {
        let c = api.op("inspect_object", json!({"handle": card})).result["fields"].clone();
        if c["isTestUnit"] == json!(true) || c["isTestData"] == json!(true) {
            continue;
        }
        let Some(m) = c["mechID"].as_i64().and_then(|id| mechs.get(&id)) else {
            continue;
        };
        let mf = api.op("inspect_object", json!({"handle": m})).result["fields"].clone();
        if first {
            // One full mech row, so every stat field name is on record.
            println!("first mech row, all fields:\n{}", serde_json::to_string_pretty(&mf).unwrap_or_default());
            first = false;
        }
        println!(
            "card {} {} ({}) cost {} x{} | life {} damage {} speed {} fly {} type {} skill {} angle {}",
            c["id"], c["name"], c["subtitle"], c["baseMoney"], c["mechCount"],
            mf["life"], mf["damage"], mf["moveSpeed"], mf["isFly"], mf["mechType"], mf["mainSkillID"], mf["attackAngle"],
        );
    }
}
