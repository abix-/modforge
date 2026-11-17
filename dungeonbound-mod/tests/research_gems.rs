//! Research: gems (gem_db.gd). Operator 2026-11-16: "gems can go
//! inside other itmes. we gotta meke sure bot undestand hwo to use
//! gems proeprly". Prints the autoloads the gem step reaches and every
//! owned gem with what it adds. Read-only.

mod common;

use serde_json::json;

#[test]
fn research_owned_gems() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let root = common::op(&api, "tree", json!({"node": "/root", "depth": 1}));
    let names: Vec<&str> = root["nodes"]
        .as_array()
        .into_iter()
        .flatten()
        .filter_map(|n| n["path"].as_str())
        .collect();
    println!("== /root: {names:?}");
    let gemdb = common::op(
        &api,
        "get_property",
        json!({"node": "/root/LootDB", "property": "GemDB", "depth": 0}),
    );
    println!("== LootDB.GemDB: {}", gemdb["value"]);
    let inv = common::op(
        &api,
        "get_property",
        json!({"node": "/root/Global", "property": "inventory", "depth": 0}),
    )["value"]["id"]
        .clone();
    for grid in [0, 1, 2] {
        let rows = common::op(
            &api,
            "call_method",
            json!({"id": inv, "method": "placements_in", "args": [grid], "depth": 2}),
        )["result"]
            .clone();
        for p in rows.as_array().into_iter().flatten() {
            let id = &p["item"]["id"];
            let vars = common::script_vars(&api, id, 0);
            let get = |k: &str| {
                vars.iter()
                    .find(|v| v["name"] == json!(k))
                    .map(|v| v["value"].clone())
                    .unwrap_or_default()
            };
            if get("consume_effect") != json!("gem") {
                continue;
            }
            println!(
                "  grid {grid}: {} type {} rarity {} field {} amount {} status {}",
                get("display_name"),
                get("gem_type"),
                get("rarity"),
                get("gem_field"),
                get("gem_amount"),
                get("gem_status")
            );
        }
    }
}
