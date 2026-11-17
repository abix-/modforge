//! Research: the enemy in a fight, its stats and its items.
//!
//! The crawl scene's combat resolver (combat_resolver.gd) holds the
//! enemies as `squad`, each a combatant like the player
//! (current_run.player). Prints each one's set script variables, and
//! the objects behind its loadout and source data. Read-only.

mod common;

use serde_json::{Value, json};

const SCENE: &str = "/root/@Control@65/CurrentScene";

fn print_set_vars(api: &modforge::client::Api<Value>, label: &str, id: &Value) -> Vec<Value> {
    let vars = common::script_vars(api, id, 2);
    println!("{label}:");
    for v in vars.iter().filter(|v| !common::is_default(&v["value"])) {
        let s = v["value"].to_string();
        let s = if s.len() > 600 {
            format!(
                "{}... ({} chars)",
                &s[..s.floor_char_boundary(600)],
                s.len()
            )
        } else {
            s
        };
        println!("  {} [{}] = {}", v["name"], v["type"], s);
    }
    vars
}

/// The fight code's methods with arguments: the combat resolver, the
/// combatant, and the battle speed control that holds the damage
/// estimate button.
#[test]
fn research_fight_methods() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    for script in [
        "combat_resolver.gd",
        "battle_speed_control.gd",
        "enemy_display_3d.gd",
    ] {
        let Some(node) = common::node_with_script(&api, SCENE, script, 4) else {
            println!("{script}: not in the scene");
            continue;
        };
        common::print_methods(&api, script, &node["id"]);
    }
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
    common::print_methods(&api, "combatant_runtime.gd", &player["value"]["id"]);
}

/// The damage estimate panel (the battle speed control's damage
/// button): its tabs and the text each tab shows. Opens and closes
/// the panel; does not touch the run.
#[test]
fn research_damage_estimate() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let Some(control) = common::node_with_script(&api, SCENE, "battle_speed_control.gd", 4) else {
        eprintln!("SKIP: no battle speed control in the scene");
        return;
    };
    let call = |method: &str, args: Value| {
        common::op(
            &api,
            "call_method",
            json!({"id": control["id"], "method": method, "args": args, "depth": 3}),
        )["result"]
            .clone()
    };
    let tabs = call("damage_tabs", json!([]));
    println!("damage tabs {tabs}");
    for tab in tabs.as_array().into_iter().flatten() {
        let tab = tab["id"].as_str().unwrap_or("");
        let modal = call("open_damage", json!([tab]));
        std::thread::sleep(std::time::Duration::from_millis(300));
        println!("tab {tab:?} modal {}", modal["path"]);
        let screen = common::op(&api, "screen", json!({"text_only": true}));
        let under = modal["path"].as_str().unwrap_or("?");
        for n in screen["nodes"].as_array().into_iter().flatten() {
            if n["path"].as_str().is_some_and(|p| p.starts_with(under)) {
                println!("  {:?}", n["text"].as_str().unwrap_or(""));
            }
        }
        call("close_modal", json!([]));
    }
}

/// The squads the resolver has ready for coming fights, and the
/// floor's guardian: enemy data known before the fight starts.
#[test]
fn research_prepared_squads() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let Some(resolver) = common::node_with_script(&api, SCENE, "combat_resolver.gd", 3) else {
        eprintln!("SKIP: no combat resolver in the current scene (not in a crawl)");
        return;
    };
    let prepared = common::op(
        &api,
        "get_property",
        json!({"id": resolver["id"], "property": "_prepared_squads", "depth": 2}),
    );
    println!("_prepared_squads = {}", prepared["value"]);
    if let Some(squads) = prepared["value"].as_object() {
        for (key, list) in squads {
            for (i, r) in list.as_array().into_iter().flatten().enumerate() {
                if r["id"].is_i64() {
                    print_set_vars(&api, &format!("prepared {key} #{i}"), &r["id"]);
                }
            }
        }
    }
    let guardian = common::op(
        &api,
        "get_property",
        json!({"id": resolver["id"], "property": "_guardian", "depth": 0}),
    );
    if guardian["value"]["id"].is_i64() {
        print_set_vars(&api, "guardian", &guardian["value"]["id"]);
    }
}

#[test]
fn research_enemy_squad() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let Some(resolver) = common::node_with_script(&api, SCENE, "combat_resolver.gd", 3) else {
        eprintln!("SKIP: no combat resolver in the current scene (not in a crawl)");
        return;
    };
    let squad = common::op(
        &api,
        "get_property",
        json!({"id": resolver["id"], "property": "squad", "depth": 1}),
    );
    let members = squad["value"].as_array().cloned().unwrap_or_default();
    println!("squad: {} enemies", members.len());
    if members.is_empty() {
        eprintln!("SKIP: the resolver's squad is empty (not in a fight)");
        return;
    }

    for (i, m) in members.iter().enumerate() {
        let vars = print_set_vars(&api, &format!("enemy {i}"), &m["id"]);
        for name in ["source_data", "monster_loadout", "rival_loadout", "stats"] {
            let obj = vars
                .iter()
                .find(|v| v["name"] == json!(name))
                .and_then(|v| v["value"]["id"].as_i64());
            if let Some(id) = obj {
                let inner = print_set_vars(&api, &format!("enemy {i} {name}"), &json!(id));
                // source_data.stats: the enemy kind's base stats.
                if let Some(stats) = inner
                    .iter()
                    .find(|v| v["name"] == json!("stats"))
                    .and_then(|v| v["value"]["id"].as_i64())
                {
                    print_set_vars(&api, &format!("enemy {i} {name}.stats"), &json!(stats));
                }
            }
        }
    }

    // What the enemy display shows, to check the numbers above.
    let screen = common::op(&api, "screen", json!({"text_only": true}));
    println!("enemy hud text:");
    for n in screen["nodes"].as_array().into_iter().flatten() {
        let path = n["path"].as_str().unwrap_or("");
        if path.contains("Enemy3DHudLayer") || path.contains("EnemyHud") {
            println!("  {:?} {}", n["text"].as_str().unwrap_or(""), path);
        }
    }
}
