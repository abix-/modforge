//! What is on the lineup screen at the start of a game?
//!
//! Read-only. The candidates are the "choose" windows from
//! research_types. Prints which are live and, for the first live
//! one, every field that holds something, so the choices on screen
//! can be read without a screenshot.
//!
//! ```text
//! k3sc cargo-lock test -p mechabellum-mod --test research_lineup -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::find_instances;

const CANDIDATES: &[&str] = &[
    "GameRiver.Client.ChooseAdvanceTeamWindow",
    "GameRiver.Client.ChooseRecommendFormPanel",
    "GameRiver.Client.ChooseReinforcementWindow",
    "GameRiver.Client.CardSelectionView",
    "GameRiver.Client.ConstructionSelectionView",
];

/// Fields of an object, skipping getters, with nested objects shown
/// by their type name. Returns the raw map too, for chaining.
fn show(api: &unityforge::client::Api<Value>, h: i64, indent: &str) -> serde_json::Map<String, Value> {
    let map = api.op("inspect_object", json!({"handle": h})).result["fields"]
        .as_object()
        .cloned()
        .unwrap_or_default();
    for (k, v) in &map {
        let shown = match v {
            Value::Object(o) => o.get("str").cloned().unwrap_or(v.clone()),
            _ => v.clone(),
        };
        if shown.as_str().is_some_and(|s| s.starts_with("<getter")) || k.starts_with("m_") || k.starts_with('_') {
            continue;
        }
        println!("{indent}{k} = {shown}");
    }
    map
}

/// The live lineup window's choices: each AdvanceTeamIcon in
/// advanceTeamIcons, its fields, and the fields of every game
/// object it holds that is not a Unity component.
#[test]
fn lineup_choices() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let windows = find_instances(&api, "GameRiver.Client.ChooseAdvanceTeamWindow", false).unwrap_or_default();
    let live = windows.iter().filter_map(handle_of).find(|&h| {
        api.op("read_field", json!({"handle": h, "field": "isInit"})).result == json!(true)
    });
    let Some(win) = live else {
        println!("no live lineup window (isInit true); open the lineup screen");
        return;
    };
    let icons = api.op("read_field", json!({"handle": win, "field": "advanceTeamIcons"}));
    let icons_h = handle_of(&icons.result).expect("advanceTeamIcons handle");
    let n = common::count_of(&api, icons_h).unwrap_or(0);
    println!("{n} choices");
    for i in 0..n {
        let item = api.op("invoke_method", json!({"handle": icons_h, "method": "get_Item", "args": [i]}));
        let Some(icon) = handle_of(&item.result) else { continue };
        // Chain of field reads ending in a handle; None if any link is empty.
        let path = |start: i64, fields: &[&str]| -> Option<i64> {
            let mut h = start;
            for f in fields {
                h = handle_of(&api.op("read_field", json!({"handle": h, "field": f})).result)?;
            }
            Some(h)
        };
        // Text on screen: TMP_Text and GRText both answer get_text.
        let text = |start: i64, fields: &[&str]| -> String {
            path(start, fields)
                .map(|h| api.op("invoke_method", json!({"handle": h, "method": "get_text", "args": []})).result)
                .map(|v| v.as_str().unwrap_or("?").to_string())
                .unwrap_or_else(|| "-".to_string())
        };
        println!("=== choice {i}");
        println!("  reactor core text: {}", text(icon, &["reactorCoreText"]));
        for slot in ["asyncUnitTop", "asyncUnitBottom"] {
            println!(
                "  {slot}: {} x {}",
                text(icon, &[slot, "nameText"]),
                text(icon, &[slot, "countText"])
            );
            if let Some(card) = path(icon, &[slot, "cardData"]) {
                show(&api, card, "     card ");
            }
        }
        if let Some(team) = path(icon, &["openingData", "advanceTeam"]) {
            println!("  advanceTeam:");
            show(&api, team, "     ");
        }
        api.op("release_handle", json!({"handle": icon}));
    }
    api.op("release_handle", json!({"handle": icons_h}));
}

/// Where unit stats live: the declared methods of the config and
/// unit data classes in GRCore.
#[test]
fn stat_sources() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for class in [
        "Il2CppGameRiver.Config",
        "Il2CppGameRiver.ConfigData",
        "Il2CppGameRiver.ConfigDataContainer",
        "Il2CppGameRiver.CardData",
        "Il2CppGameRiver.MechData",
        "Il2CppGameRiver.WeaponData",
        "Il2CppGameRiver.MechUtility",
    ] {
        unityforge::client::print_declared_methods(&api, class);
    }
}

#[test]
fn lineup_screen() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for class in CANDIDATES {
        let Ok(instances) = find_instances(&api, class, false) else {
            continue;
        };
        for v in &instances {
            let Some(h) = handle_of(v) else { continue };
            let fields = api.op("inspect_object", json!({"handle": h})).result;
            println!("--- {class} handle {h}:");
            if let Some(map) = fields["fields"].as_object() {
                for (k, v) in map {
                    let shown = match v {
                        Value::Object(o) => o.get("str").cloned().unwrap_or(v.clone()),
                        _ => v.clone(),
                    };
                    if shown.as_str().is_some_and(|s| s.starts_with("<getter")) {
                        continue;
                    }
                    println!("  {k} = {shown}");
                }
            }
        }
    }
}

/// The mod's lineup op: every choice on screen with its units and
/// totals, most damage per second first.
#[test]
fn lineup_op() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let r = api.op("lineup", json!({}));
    if !r.ok {
        println!("lineup: {:?}", r.error);
        return;
    }
    for c in r.result.as_array().into_iter().flatten() {
        let t = &c["totals"];
        println!("choice {}: life {:.0}, dps {:.0}, hits air {}", c["choice"], t["life"].as_f64().unwrap_or(0.0), t["dps"].as_f64().unwrap_or(0.0), t["hits_air"]);
        for u in c["units"].as_array().into_iter().flatten() {
            println!(
                "  {} (card {}) x{} life {:.0} dps {:.0} range {} splash {} air {}",
                u["name"], u["card"], u["count"], u["life"].as_f64().unwrap_or(0.0), u["dps"].as_f64().unwrap_or(0.0), u["range"], u["splash"], u["hits_air"]
            );
        }
    }
}
