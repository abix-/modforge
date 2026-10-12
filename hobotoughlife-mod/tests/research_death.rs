//! How does death lower the player's stats?
//!
//! Read-only: read_field, inspect_object, list_methods only.
//!
//! ```text
//! k3sc cargo-lock test -p hobotoughlife-mod --test research_death -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs when the game is not running; needs a loaded save.

mod common;
use common::{api, fields, find_instances, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

fn print_methods(api: &Api<Value>, class: &str, filter: impl Fn(&str) -> bool) {
    let r = api.op("list_methods", json!({"class": class}));
    if !r.ok {
        println!("list_methods({class}) failed: {:?}", r.error);
        return;
    }
    let empty = vec![];
    for m in r.result["methods"].as_array().unwrap_or(&empty) {
        let name = m["name"].as_str().unwrap_or("");
        if m["declared_on"].as_str() == Some(class) && filter(name) {
            println!(
                "  {class}.{name}({}) -> {}{}",
                m["params"].as_i64().unwrap_or(0),
                m["return"].as_str().unwrap_or("?"),
                if m["static"].as_bool().unwrap_or(false) {
                    " [static]"
                } else {
                    ""
                }
            );
        }
    }
}

/// Every field of the player's Health stat (nothing filtered) and
/// every method declared on the stat classes.
#[test]
fn stat_classes() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = find_instances(&api, "Game.Character", true).unwrap_or_default();
    let Some(ch) = list.first().and_then(handle_of) else {
        println!("no Character instance; load a save");
        return;
    };
    for stat in ["health", "attack"] {
        let h = api.op("read_field", json!({"handle": ch, "field": stat}));
        if let Some(h) = handle_of(&h.result) {
            let f = fields(&api, h).unwrap_or(Value::Null);
            println!(
                "-- {stat}:\n{}",
                serde_json::to_string_pretty(&f).unwrap_or_default()
            );
            api.op("release_handle", json!({"handle": h}));
        }
    }
    api.op("release_handle", json!({"handle": ch}));

    for class in [
        "Il2CppGame.ParameterRange",
        "Il2CppGame.ParameterNormal",
        "Il2CppGame.Parameter",
    ] {
        println!("== {class}");
        print_methods(&api, class, |_| true);
    }
}

/// The stats the game calls primary, and what the player's
/// permanent stat changes hold right now.
#[test]
fn primary_and_permanent_changes() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = find_instances(&api, "Game.Character", true).unwrap_or_default();
    let Some(ch) = list.first().and_then(handle_of) else {
        println!("no Character instance; load a save");
        return;
    };
    let p = api.op(
        "invoke_method",
        json!({"handle": ch, "method": "GetPrimaryParameterTypes", "args": []}),
    );
    println!("GetPrimaryParameterTypes = {} {:?}", p.result, p.error);
    if let Some(arr) = handle_of(&p.result) {
        let n = common::count_of(&api, arr).unwrap_or(0);
        for i in 0..n {
            let it = api.op(
                "invoke_method",
                json!({"handle": arr, "method": "get_Item", "args": [i]}),
            );
            println!("  primary[{i}] = {}", it.result);
        }
        api.op("release_handle", json!({"handle": arr}));
    }

    let d = api.op("read_field", json!({"handle": ch, "field": "permanentParameterChanges"}));
    println!("permanentParameterChanges = {}", d.result);
    if let Some(dict) = handle_of(&d.result) {
        println!("  count = {:?}", common::count_of(&api, dict));
        let f = fields(&api, dict).unwrap_or(Value::Null);
        println!("{}", serde_json::to_string_pretty(&f).unwrap_or_default());
        api.op("release_handle", json!({"handle": dict}));
    }
    let s = api.op(
        "invoke_method",
        json!({"handle": ch, "method": "GetParameterChangesSaveData", "args": []}),
    );
    println!("GetParameterChangesSaveData = {} {:?}", s.result, s.error);
    if let Some(l) = handle_of(&s.result) {
        let n = common::count_of(&api, l).unwrap_or(0);
        for i in 0..n {
            let it = api.op(
                "invoke_method",
                json!({"handle": l, "method": "get_Item", "args": [i]}),
            );
            match handle_of(&it.result) {
                Some(h) => {
                    let f = fields(&api, h).unwrap_or(Value::Null);
                    println!("  change[{i}] = {}", f["fields"]);
                    api.op("release_handle", json!({"handle": h}));
                }
                None => println!("  change[{i}] = {}", it.result),
            }
        }
        api.op("release_handle", json!({"handle": l}));
    }
    api.op("release_handle", json!({"handle": ch}));
}

/// Where the death penalty lands. Run once before a death and once
/// after; the difference is what death changed. Read-only (the
/// Get* calls only read).
#[test]
fn death_snapshot() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = find_instances(&api, "Game.Character", true).unwrap_or_default();
    let Some(ch) = list.first().and_then(handle_of) else {
        println!("no Character instance; load a save");
        return;
    };
    let call = |h: i64, m: &str| {
        api.op("invoke_method", json!({"handle": h, "method": m, "args": []}))
            .result
    };
    let read = |h: i64, f: &str| api.op("read_field", json!({"handle": h, "field": f})).result;

    println!(
        "actualCountDeaths = {}  GetDeathCountData = {}",
        read(ch, "actualCountDeaths"),
        call(ch, "GetDeathCountData")
    );
    // The six primary stats, by Character.GetPrimaryParameterTypes.
    for stat in ["health", "freshness", "food", "morale", "warm", "wet"] {
        let Some(h) = handle_of(&read(ch, stat)) else {
            println!("{stat}: no handle");
            continue;
        };
        println!(
            "{stat}: value = {}  actualMax = {}  GetMax = {}  GetActualMax = {}",
            read(h, "value"),
            read(h, "actualMax"),
            call(h, "GetMax"),
            call(h, "GetActualMax")
        );
        api.op("release_handle", json!({"handle": h}));
    }

    let perm = read(ch, "permanentParameterChanges");
    if let Some(d) = handle_of(&perm) {
        println!("permanentParameterChanges count = {:?}", common::count_of(&api, d));
        api.op("release_handle", json!({"handle": d}));
    }
    let saved = call(ch, "GetParameterChangesSaveData");
    if let Some(l) = handle_of(&saved) {
        let n = common::count_of(&api, l).unwrap_or(0);
        for i in 0..n {
            let it = api.op(
                "invoke_method",
                json!({"handle": l, "method": "get_Item", "args": [i]}),
            );
            if let Some(h) = handle_of(&it.result) {
                let f = fields(&api, h).unwrap_or(Value::Null);
                println!("  permanent change[{i}] = {}", f["fields"]);
                api.op("release_handle", json!({"handle": h}));
            }
        }
        api.op("release_handle", json!({"handle": l}));
    }
    let items = read(ch, "deathItems");
    if let Some(d) = handle_of(&items) {
        println!("deathItems count = {:?}", common::count_of(&api, d));
        api.op("release_handle", json!({"handle": d}));
    }
    api.op("release_handle", json!({"handle": ch}));
}

/// Methods on the player that mention max, parameters or stats:
/// candidates for where the death count lowers a stat's max.
#[test]
fn character_max_methods() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    print_methods(&api, "Il2CppGame.Character", |n| {
        let l = n.to_ascii_lowercase();
        ["max", "param", "stat", "death", "die", "respawn"]
            .iter()
            .any(|k| l.contains(k))
    });
}
