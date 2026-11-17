//! Research: where does the game keep the player's character, its
//! equipment and its stats?
//!
//! Prints the script variables of /root/Global (game_state.gd) and of
//! every other autoload whose variable names mention equipment,
//! stats or the character. Read-only.

mod common;

use serde_json::{Value, json};

fn script_vars(api: &modforge::client::Api<Value>, node: &str, depth: u32) -> Vec<Value> {
    let inspected = common::op(api, "inspect", json!({"node": node, "depth": depth}));
    inspected["properties"]
        .as_array()
        .map(|p| {
            p.iter()
                .filter(|p| p["script"] == json!(true))
                .cloned()
                .collect()
        })
        .unwrap_or_default()
}

fn short(v: &Value) -> String {
    let s = v.to_string();
    if s.len() > 1500 {
        let cut = (0..=1500)
            .rev()
            .find(|&i| s.is_char_boundary(i))
            .unwrap_or(0);
        format!("{}... ({} chars)", &s[..cut], s.len())
    } else {
        s
    }
}

#[test]
fn research_global_state() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let vars = script_vars(&api, "/root/Global", 1);
    println!("/root/Global: {} script variables", vars.len());
    for v in &vars {
        println!("  {} [{}] = {}", v["name"], v["type"], short(&v["value"]));
    }
    assert!(!vars.is_empty(), "Global has no script variables");
}

/// Global.inventory (the selected character's) and Global.current_run.
#[test]
fn research_inventory_and_run() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    for property in ["inventory", "current_run"] {
        let got = common::op(
            &api,
            "get_property",
            json!({"node": "/root/Global", "property": property, "depth": 0}),
        );
        let id = got["value"]["id"].clone();
        let inspected = common::op(&api, "inspect", json!({"id": id, "depth": 3}));
        println!(
            "Global.{property}: {} script {}",
            inspected["class"], inspected["script"]
        );
        for p in inspected["properties"].as_array().expect("properties") {
            if p["script"] == json!(true) {
                println!("  {} [{}] = {}", p["name"], p["type"], short(&p["value"]));
            }
        }
    }
}

fn print_script_vars(api: &modforge::client::Api<Value>, label: &str, id: &Value, depth: u32) {
    let inspected = common::op(api, "inspect", json!({"id": id, "depth": depth}));
    println!(
        "{label}: {} script {}",
        inspected["class"], inspected["script"]
    );
    for p in inspected["properties"].as_array().expect("properties") {
        if p["script"] == json!(true) {
            println!("  {} [{}] = {}", p["name"], p["type"], short(&p["value"]));
        }
    }
}

/// current_run.player (the fighter's stats) and each owned item.
#[test]
fn research_player_and_items() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let run = common::op(
        &api,
        "get_property",
        json!({"node": "/root/Global", "property": "current_run", "depth": 0}),
    );
    let player = common::op(
        &api,
        "get_property",
        json!({"id": run["value"]["id"], "property": "player", "depth": 0}),
    );
    print_script_vars(&api, "current_run.player", &player["value"]["id"], 2);

    let inv = common::op(
        &api,
        "get_property",
        json!({"node": "/root/Global", "property": "inventory", "depth": 0}),
    );
    let owned = common::op(
        &api,
        "get_property",
        json!({"id": inv["value"]["id"], "property": "owned_items", "depth": 1}),
    );
    for (name, item) in owned["value"].as_object().expect("owned_items") {
        print_script_vars(&api, &format!("item {name}"), &item["id"], 1);
    }
}

/// Nodes in the current scene whose path or script names a fighter.
#[test]
fn research_enemy_on_screen() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let tree = common::op(
        &api,
        "tree",
        json!({"node": "/root/@Control@65/CurrentScene", "depth": 6}),
    );
    let words = [
        "enemy", "foe", "fighter", "hero", "battle", "combat", "unit", "opponent",
    ];
    for n in tree["nodes"].as_array().expect("nodes") {
        let text = format!("{} {}", n["path"], n["script"]).to_lowercase();
        if words.iter().any(|w| text.contains(w)) {
            println!("{} [{}] {}", n["path"], n["class"], n["script"]);
        }
    }
}

/// The fight: the combat resolver's and enemy display's script
/// variables in the current crawl scene, found by script path.
#[test]
fn research_fight_nodes() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let tree = common::op(
        &api,
        "tree",
        json!({"node": "/root/@Control@65/CurrentScene", "depth": 3}),
    );
    for n in tree["nodes"].as_array().expect("nodes") {
        let script = n["script"].as_str().unwrap_or("");
        if script.ends_with("combat_resolver.gd") || script.ends_with("enemy_display_3d.gd") {
            print_script_vars(&api, script, &n["id"], 1);
        }
    }
}

/// The game's own QA automation: its script methods.
#[test]
fn research_qa_driver() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let methods = common::op(
        &api,
        "list_methods",
        json!({"node": "/root/QADriver", "script_only": true}),
    );
    for m in methods["methods"].as_array().expect("methods") {
        let args: Vec<String> = m["args"]
            .as_array()
            .map(|a| {
                a.iter()
                    .map(|x| {
                        format!(
                            "{}: {}",
                            x["name"].as_str().unwrap_or("?"),
                            x["type"].as_str().unwrap_or("?")
                        )
                    })
                    .collect()
            })
            .unwrap_or_default();
        println!("{}({})", m["name"].as_str().unwrap_or("?"), args.join(", "));
    }
    print_script_vars(
        &api,
        "QADriver",
        &common::op(
            &api,
            "inspect",
            json!({"node": "/root/QADriver", "depth": 0}),
        )["id"],
        1,
    );
}

#[test]
fn research_character_words_in_autoloads() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let autoloads = common::op(&api, "autoloads", json!({}));
    let words = [
        "equip",
        "stat",
        "character",
        "hero",
        "player",
        "inventory",
        "item",
        "slot",
        "hp",
        "atk",
    ];
    for n in autoloads["nodes"].as_array().expect("nodes") {
        let path = n["path"].as_str().unwrap_or("");
        if path == "/root/Global" {
            continue;
        }
        let vars = script_vars(&api, path, 0);
        let hits: Vec<&Value> = vars
            .iter()
            .filter(|v| {
                let name = v["name"].as_str().unwrap_or("").to_lowercase();
                words.iter().any(|w| name.contains(w))
            })
            .collect();
        if hits.is_empty() {
            continue;
        }
        println!("{path}:");
        for v in hits {
            println!("  {} [{}] = {}", v["name"], v["type"], short(&v["value"]));
        }
    }
}
