//! How does luck work? Where the luck number lives, what changes
//! it, and what reads it.
//!
//! Read-only. Two parts:
//! - the three classes named after luck (FallbackLuckArtifact,
//!   LuckOnEnemyVehicleKill, LuckPerLevel): every live instance
//!   inspected in full, plus their declared methods
//! - a scan of the likely owners (the manager, the castle, the
//!   artifact and module systems) for any field or method whose
//!   name contains "luck"
//!
//! ```text
//! k3sc cargo-lock test -p wanderburg-mod --test research_luck -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, find_instances, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

fn methods_matching(api: &Api<Value>, class: &str, needle: Option<&str>) {
    let r = api.op("list_methods", json!({"class": class}));
    if !r.ok {
        println!("  list_methods({class}) failed: {:?}", r.error);
        return;
    }
    let empty = vec![];
    for m in r.result["methods"].as_array().unwrap_or(&empty) {
        let name = m["name"].as_str().unwrap_or("?");
        let declared = m["declared_on"].as_str().unwrap_or("?");
        let mine = declared == class || declared.ends_with(&format!(".{class}"));
        let hit = needle.is_none_or(|n| name.to_ascii_lowercase().contains(n));
        if mine && hit && !name.starts_with("get_") && !name.starts_with("set_") {
            println!(
                "  {class}::{name}({}) -> {}{}",
                m["params"].as_i64().unwrap_or(0),
                m["return"].as_str().unwrap_or("?"),
                if m["static"].as_bool().unwrap_or(false) { " [static]" } else { "" }
            );
        }
    }
}

fn fields_matching(api: &Api<Value>, class: &str, needle: Option<&str>, max_instances: usize) {
    let list = match find_instances(api, class, true) {
        Ok(l) => l,
        Err(e) => {
            println!("  {class}: walk failed: {e}");
            return;
        }
    };
    println!("  {class}: {} instance(s)", list.len());
    for v in list.iter().take(max_instances) {
        let Some(h) = v.get("handle").and_then(Value::as_i64) else {
            continue;
        };
        let name = v.get("name").and_then(Value::as_str).unwrap_or("?");
        let r = api.op("inspect_object", json!({"handle": h}));
        if let Some(fields) = r.result.get("fields").and_then(Value::as_object) {
            for (k, val) in fields {
                if needle.is_none_or(|n| k.to_ascii_lowercase().contains(n)) {
                    let shown = match val {
                        Value::Object(o) => o
                            .get("il2cpp_type")
                            .and_then(Value::as_str)
                            .map(|t| format!("<{t}>"))
                            .unwrap_or_else(|| val.to_string()),
                        _ => val.to_string(),
                    };
                    println!("    {name}.{k} = {shown}");
                }
            }
        }
        api.op("release_handle", json!({"handle": h}));
    }
    for v in list.iter().skip(max_instances) {
        if let Some(h) = v.get("handle").and_then(Value::as_i64) {
            api.op("release_handle", json!({"handle": h}));
        }
    }
}

#[test]
fn luck_classes() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for class in ["FallbackLuckArtifact", "LuckOnEnemyVehicleKill", "LuckPerLevel"] {
        println!("\n== {class}");
        fields_matching(&api, class, None, 3);
        methods_matching(&api, class, None);
    }
}

/// The live luck number and the rarity weights it feeds.
#[test]
fn luck_value_and_weights() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    if let Some(gm) = common::first_handle(&api, "GM") {
        let r = api.op("invoke_method", json!({"handle": gm, "method": "get_CurrentLuck", "args": []}));
        println!("GM.CurrentLuck = {} (ok={})", r.result, r.ok);
        api.op("release_handle", json!({"handle": gm}));
    }
    println!("\n== rarity, weight and ramp fields");
    for class in ["GM", "ModuleSelection", "NewModuleOption", "ModuleUpgradeOption", "VehicleUpgrade", "AM"] {
        for needle in ["rarity", "weight", "ramp", "legendary", "epic", "chance"] {
            fields_matching(&api, class, Some(needle), 1);
        }
    }
    println!("\n== ModuleSelection methods");
    methods_matching(&api, "ModuleSelection", None);
}

#[test]
fn luck_owners() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    println!("\n== fields and methods containing 'luck'");
    for class in [
        "GM", "VM", "VS", "VP", "VMBaseStats", "AM", "MC", "ArtifactSystem", "ArtifactTagSystem",
        "ModuleSelection", "NewModuleOption", "ModuleUpgradeOption", "VehicleUpgrade",
        "RerollEnabler", "RerollButton", "StatisticsManager", "GameStatisticsTracker",
        "RunBalancingRecorder", "SaveGame", "PlayerPrefList", "Module2", "BonusVehicleStats",
    ] {
        fields_matching(&api, class, Some("luck"), 1);
        methods_matching(&api, class, Some("luck"));
    }
}
