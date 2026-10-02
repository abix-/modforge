//! Why the player cannot move (operator 2026-10-02: frozen after
//! research_area_kept_quiet.rs loaded a second area alongside).
//!
//! OpenSewerCharacterController stops movement while its disabledList is
//! not empty (ControlsDisabled, OpenSewerCharacterController.cs:198) and
//! while GameUIController.IsMenuVisible (line 354). Reads both, plus the
//! time scale and noclip state.
//!
//! Read-only: walk_class, read_field, invoke_method and invoke_static on
//! getters only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_player_frozen -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

fn call(api: &Api<Value>, h: i64, method: &str, args: Value) -> Value {
    let r = api.op("invoke_method", json!({"handle": h, "method": method, "args": args}));
    if r.ok { r.result } else { json!(format!("failed: {:?}", r.error)) }
}

fn read(api: &Api<Value>, h: i64, field: &str) -> Value {
    let r = api.op("read_field", json!({"handle": h, "field": field}));
    if r.ok { r.result } else { json!(format!("failed: {:?}", r.error)) }
}

fn first(api: &Api<Value>, class: &str) -> Vec<i64> {
    let r = api.op("walk_class", json!({"class": class, "include_inactive": true}));
    r.result.get("instances").and_then(Value::as_array).cloned().unwrap_or_default().iter().filter_map(handle_of).collect()
}

#[test]
fn why_the_player_cannot_move() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let scale = api.op("invoke_static", json!({"class": "UnityEngine.Time", "method": "get_timeScale", "args": []})).result;
    println!("time scale {scale}");

    for h in first(&api, "GameUIController") {
        println!("GameUIController: IsMenuVisible {}", call(&api, h, "get_IsMenuVisible", json!([])));
    }

    let players = first(&api, "OpenSewerCharacterController");
    println!("{} OpenSewerCharacterController", players.len());
    for h in players {
        println!("  ControlsDisabled {}  noclipEnabled {}", call(&api, h, "ControlsDisabled", json!([])), read(&api, h, "noclipEnabled"));
        let list = read(&api, h, "disabledList");
        let Some(list) = handle_of(&list) else {
            println!("  disabledList {list}");
            continue;
        };
        let n = call(&api, list, "get_Count", json!([])).as_i64().unwrap_or(0);
        println!("  disabledList has {n}:");
        for i in 0..n {
            let item = call(&api, list, "get_Item", json!([i]));
            let path = handle_of(&item).map(|g| {
                let mut names = Vec::new();
                let mut t = handle_of(&call(&api, g, "get_transform", json!([])));
                while let Some(th) = t {
                    names.push(call(&api, th, "get_name", json!([])).as_str().unwrap_or("?").to_string());
                    t = handle_of(&call(&api, th, "get_parent", json!([])));
                }
                names.reverse();
                let active = call(&api, g, "get_activeInHierarchy", json!([]));
                format!("{} (active {active})", names.join(" / "))
            });
            println!("    {}", path.unwrap_or_else(|| item.to_string()));
        }
    }
}
