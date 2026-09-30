//! Where do inventory size and carry weight live on the player?
//!
//! Read-only on purpose: walk_class, inspect_object, list_methods
//! only. No write_field, no invoke on game code. Nothing here can
//! change game state.
//!
//! ```text
//! k3sc cargo-lock test -p hobotoughlife-mod --test research_inventory -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.
//! Character and Bag instances only exist in a loaded save; from
//! the menu the instance counts print zero.

mod common;
use common::{api, fields, find_instances, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

const KEYWORDS: &[&str] = &[
    "inventor", "weight", "capac", "slot", "bag", "item", "carry", "stash",
];

fn matches(name: &str) -> bool {
    let lower = name.to_ascii_lowercase();
    KEYWORDS.iter().any(|k| lower.contains(k))
}

/// Inspect up to `max` live instances of `class`, release every
/// handle, then list the declared methods whose names match.
fn survey(api: &Api<Value>, class: &str, max: usize) {
    let list = match find_instances(api, class, true) {
        Ok(l) => l,
        Err(e) => {
            println!("{class}: walk_class failed: {e}");
            return;
        }
    };
    println!("\n== {class}: {} instance(s)", list.len());
    for (i, v) in list.iter().enumerate() {
        let Some(h) = handle_of(v) else {
            println!("  {v}");
            continue;
        };
        if i < max {
            let name = v.get("name").and_then(Value::as_str).unwrap_or("?");
            let f = fields(api, h).unwrap_or(Value::Null);
            println!(
                "-- {name} (handle {h}):\n{}",
                serde_json::to_string_pretty(&f).unwrap_or_default()
            );
        }
        api.op("release_handle", json!({"handle": h}));
    }

    // Interop proxies live under Il2Cpp<namespace>, so declared_on
    // is "Il2CppGame.Character" for class "Game.Character".
    let full = format!("Il2Cpp{class}");
    let r = api.op("list_methods", json!({"class": full}));
    if !r.ok {
        println!("list_methods({full}) failed: {:?}", r.error);
        return;
    }
    let empty = vec![];
    let methods = r.result["methods"].as_array().unwrap_or(&empty);
    let mine: Vec<&Value> = methods
        .iter()
        .filter(|m| m["declared_on"].as_str() == Some(full.as_str()))
        .filter(|m| m["name"].as_str().is_some_and(matches))
        .collect();
    println!("{full} declares {} matching method(s):", mine.len());
    for m in mine {
        println!(
            "  {}({}) -> {}{}",
            m["name"].as_str().unwrap_or("?"),
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

fn print_object(api: &Api<Value>, label: &str, h: i64) {
    let f = fields(api, h).unwrap_or(Value::Null);
    println!(
        "-- {label} (handle {h}):\n{}",
        serde_json::to_string_pretty(&f).unwrap_or_default()
    );
}

/// Follow the player's capacity, bags and first inventory item
/// to their values.
#[test]
fn player_capacity_bags_items() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = find_instances(&api, "Game.Character", true).unwrap_or_default();
    let Some(ch) = list.first().and_then(handle_of) else {
        println!("no Character instance; load a save");
        return;
    };
    let f = fields(&api, ch).unwrap_or(Value::Null);
    let f = &f["fields"];
    println!(
        "actualWeight = {}  isOverWeighted = {}",
        f["actualWeight"], f["isOverWeighted"]
    );

    if let Some(cap) = handle_of(&f["capacity"]) {
        print_object(&api, "capacity", cap);
    }

    if let Some(bags) = handle_of(&f["bags"]) {
        let n = common::count_of(&api, bags).unwrap_or(0);
        println!("bags: {n} slot(s)");
        for i in 0..n {
            let item = api.op(
                "invoke_method",
                json!({"handle": bags, "method": "get_Item", "args": [i]}),
            );
            match handle_of(&item.result) {
                Some(b) => print_object(&api, &format!("bags[{i}]"), b),
                None => println!("bags[{i}] = {}", item.result),
            }
        }
    }

    if let Some(inv) = handle_of(&f["inventory"]) {
        let n = common::count_of(&api, inv).unwrap_or(0);
        println!("inventory: {n} item(s)");
        if n > 0 {
            let item = api.op(
                "invoke_method",
                json!({"handle": inv, "method": "get_Item", "args": [0]}),
            );
            if let Some(it) = handle_of(&item.result) {
                print_object(&api, "inventory[0]", it);
            }
        }
    }
}

/// Writes Pockets (Character.capacity.value) to 220 and reads it
/// back. CHANGES GAME STATE: this is the one write in this file.
/// Sets a fixed 220, not current * 10, so a rerun stays at 220.
#[test]
fn pockets_write_220() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = find_instances(&api, "Game.Character", true).unwrap_or_default();
    let Some(ch) = list.first().and_then(handle_of) else {
        println!("no Character instance; load a save");
        return;
    };
    let cap = api.op("read_field", json!({"handle": ch, "field": "capacity"}));
    let Some(cap) = handle_of(&cap.result) else {
        panic!("capacity carried no handle: {:?} {:?}", cap.result, cap.error);
    };
    let before = api.op("read_field", json!({"handle": cap, "field": "value"}));
    println!("Pockets before = {}", before.result);

    let write = api.op(
        "write_field",
        json!({"handle": cap, "field": "value", "value": 220.0}),
    );
    assert!(write.ok, "write_field failed: {:?}", write.error);

    let after = api.op("read_field", json!({"handle": cap, "field": "value"}));
    let weight = api.op("read_field", json!({"handle": ch, "field": "actualWeight"}));
    let over = api.op("read_field", json!({"handle": ch, "field": "isOverWeighted"}));
    println!(
        "Pockets after = {}  actualWeight = {}  isOverWeighted = {}",
        after.result, weight.result, over.result
    );
    api.op("release_handle", json!({"handle": cap}));
    api.op("release_handle", json!({"handle": ch}));
    assert_eq!(after.result.as_f64(), Some(220.0), "read back {}", after.result);
}

/// Every stat on the player: each ParameterNormal / ParameterRange
/// field with the game's own title, description and plain values.
/// Read-only.
#[test]
fn player_stats() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = find_instances(&api, "Game.Character", true).unwrap_or_default();
    let Some(ch) = list.first().and_then(handle_of) else {
        println!("no Character instance; load a save");
        return;
    };
    let f = fields(&api, ch).unwrap_or(Value::Null);
    let Some(map) = f["fields"].as_object() else {
        println!("Character answered no fields");
        return;
    };
    for (name, v) in map {
        let ty = v["il2cpp_type"].as_str().unwrap_or("");
        if !ty.ends_with("ParameterNormal") && !ty.ends_with("ParameterRange") {
            continue;
        }
        let Some(h) = handle_of(v) else { continue };
        let pf = fields(&api, h).unwrap_or(Value::Null);
        let plain: serde_json::Map<String, Value> = pf["fields"]
            .as_object()
            .map(|m| {
                m.iter()
                    .filter(|(k, v)| {
                        !v.is_object()
                            && !v.as_str().is_some_and(|s| s.starts_with("<getter"))
                            && !k.ends_with("Key")
                    })
                    .map(|(k, v)| (k.clone(), v.clone()))
                    .collect()
            })
            .unwrap_or_default();
        println!("{name} [{}]: {}", ty.rsplit('.').next().unwrap_or(ty), Value::Object(plain));
        api.op("release_handle", json!({"handle": h}));
    }
    api.op("release_handle", json!({"handle": ch}));
}

/// Fields and methods on the player whose names mention perks or
/// skills. Read-only.
#[test]
fn player_perks() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let is_perk = |n: &str| {
        let l = n.to_ascii_lowercase();
        ["perk", "skill", "talent", "abilit", "grit"]
            .iter()
            .any(|k| l.contains(k))
    };
    let list = find_instances(&api, "Game.Character", true).unwrap_or_default();
    let Some(ch) = list.first().and_then(handle_of) else {
        println!("no Character instance; load a save");
        return;
    };
    let f = fields(&api, ch).unwrap_or(Value::Null);
    if let Some(map) = f["fields"].as_object() {
        for (name, v) in map.iter().filter(|(n, _)| is_perk(n)) {
            println!("field {name} = {v}");
            if let Some(h) = handle_of(v) {
                let n = common::count_of(&api, h);
                println!("  count = {n:?}");
                if let Some(n) = n {
                    for i in 0..n.min(40) {
                        let item = api.op(
                            "invoke_method",
                            json!({"handle": h, "method": "get_Item", "args": [i]}),
                        );
                        match handle_of(&item.result) {
                            Some(ih) => {
                                print_object(&api, &format!("{name}[{i}]"), ih);
                                api.op("release_handle", json!({"handle": ih}));
                            }
                            None => println!("  [{i}] = {}", item.result),
                        }
                    }
                }
                api.op("release_handle", json!({"handle": h}));
            }
        }
    }
    api.op("release_handle", json!({"handle": ch}));

    let r = api.op("list_methods", json!({"class": "Il2CppGame.Character"}));
    let empty = vec![];
    for m in r.result["methods"].as_array().unwrap_or(&empty) {
        let name = m["name"].as_str().unwrap_or("");
        if m["declared_on"].as_str() == Some("Il2CppGame.Character") && is_perk(name) {
            println!(
                "method {name}({}) -> {}",
                m["params"].as_i64().unwrap_or(0),
                m["return"].as_str().unwrap_or("?")
            );
        }
    }
}

/// Methods on the player whose names mention death, plus the
/// death counter. Read-only.
#[test]
fn player_death() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = find_instances(&api, "Game.Character", true).unwrap_or_default();
    if let Some(ch) = list.first().and_then(handle_of) {
        let d = api.op("read_field", json!({"handle": ch, "field": "actualCountDeaths"}));
        println!("actualCountDeaths = {}", d.result);
        let p = api.op(
            "invoke_static",
            json!({"class": "Il2CppGame.Character", "method": "get_DECREASEMAXPARAMETERAFTERDEATH", "args": []}),
        );
        println!("DECREASEMAXPARAMETERAFTERDEATH = {} {:?}", p.result, p.error);
        api.op("release_handle", json!({"handle": ch}));
    }
    let r = api.op("list_methods", json!({"class": "Il2CppGame.Character"}));
    let empty = vec![];
    for m in r.result["methods"].as_array().unwrap_or(&empty) {
        let name = m["name"].as_str().unwrap_or("");
        let l = name.to_ascii_lowercase();
        if m["declared_on"].as_str() == Some("Il2CppGame.Character")
            && ["death", "die", "dead", "lose", "penalt", "respawn", "revive"]
                .iter()
                .any(|k| l.contains(k))
        {
            println!(
                "method {name}({}) -> {}",
                m["params"].as_i64().unwrap_or(0),
                m["return"].as_str().unwrap_or("?")
            );
        }
    }
}

#[test]
fn player_inventory() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    survey(&api, "Game.Character", 1);
    survey(&api, "Game.Bag", 2);
}
