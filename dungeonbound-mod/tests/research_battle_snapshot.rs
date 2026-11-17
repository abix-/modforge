//! Research: everything one fight starts from, saved for the fight math
//! port (operator 2026-11-17: "go fix the fight math", scope
//! "Everything"). The hero (combatant_runtime.gd), every worn piece and
//! its placement row (inventory.gd placements_in EQUIP), and, during a
//! fight, the squad (combat_resolver.gd squad). Read-only. Writes
//! target/battle_snapshots/<seconds>.json; research_battle_log reads
//! what happened after.

mod common;

use modforge::client::Api;
use serde_json::{Map, Value, json};

const SCENE: &str = "/root/@Control@65/CurrentScene";

/// An object's script variables by name.
fn vars(api: &Api<Value>, id: &Value) -> Value {
    let mut m = Map::new();
    for p in common::script_vars(api, id, 1) {
        if let Some(n) = p["name"].as_str() {
            m.insert(n.to_string(), p["value"].clone());
        }
    }
    Value::Object(m)
}

fn prop(api: &Api<Value>, target: Value, property: &str) -> Value {
    let mut a = target;
    a["property"] = json!(property);
    a["depth"] = json!(0);
    common::op(api, "get_property", a)["value"].clone()
}

#[test]
fn research_battle_snapshot() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let run = prop(&api, json!({"node": "/root/Global"}), "current_run");
    let player = prop(&api, json!({"id": run["id"]}), "player");
    let inv = prop(&api, json!({"node": "/root/Global"}), "inventory");
    let rows = common::op(
        &api,
        "call_method",
        json!({"id": inv["id"], "method": "placements_in", "args": [0], "depth": 2}),
    );
    let mut worn = Vec::new();
    for row in rows["result"].as_array().into_iter().flatten() {
        let item = &row["item"];
        let mut r = row.clone();
        r["item"] = vars(&api, &item["id"]);
        worn.push(r);
    }
    let mut squad = Vec::new();
    if let Some(res) = common::node_with_script(&api, SCENE, "combat_resolver.gd", 3) {
        let s = prop(&api, json!({"id": res["id"]}), "squad");
        for f in s.as_array().into_iter().flatten() {
            if f["id"].is_null() {
                continue;
            }
            squad.push(vars(&api, &f["id"]));
        }
    }
    let snap = json!({"player": vars(&api, &player["id"]), "worn": worn, "squad": squad});
    let dir = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/battle_snapshots");
    std::fs::create_dir_all(&dir).expect("snapshot dir");
    let at = std::time::SystemTime::now()
        .duration_since(std::time::UNIX_EPOCH)
        .map_or(0, |d| d.as_secs());
    let path = dir.join(format!("{at}.json"));
    std::fs::write(&path, serde_json::to_string_pretty(&snap).expect("json")).expect("write");
    println!(
        "{} worn pieces, {} foes -> {}",
        worn.len(),
        squad.len(),
        path.display()
    );
    for w in &worn {
        let i = &w["item"];
        println!(
            "  {} | trigger {} {} every {} amount {} status {}",
            i["display_name"],
            i["trigger_type"],
            i["trigger_effect"],
            i["trigger_seconds"],
            i["trigger_amount"],
            i["trigger_status_id"]
        );
    }
}
