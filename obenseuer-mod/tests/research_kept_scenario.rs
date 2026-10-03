//! The automatic check for areas kept loaded (docs/loading-research.md,
//! "The lifecycle rules kept areas break"): the game is played through the
//! kept-area paths without the player, and must end with every one-copy
//! field live and the player's identity intact. Every game error logged
//! along the way is listed, to gate on once the game's own errors are
//! known.
//!
//! 1. reload the save (a normal load), wait for areas kept loaded
//! 2. use a door of the home area into a kept area (the game's own
//!    Interact, as the use key calls it), then a door back
//! 3. save into the slot "ModTest" (not one of the player's), load it
//! 4. load the player's own save again (the save name is theirs again)
//!
//! Changes the game: loads, moves the player, writes Saves/<character>/ModTest.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_kept_scenario -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use std::time::{Duration, Instant};

use common::{WATCHED, api, call, call_static, handle_of, instance_now, op, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

fn wait_for(what: &str, secs: u64, mut done: impl FnMut() -> bool) {
    let start = Instant::now();
    while !done() {
        assert!(start.elapsed() < Duration::from_secs(secs), "{what}: not within {secs}s");
        std::thread::sleep(Duration::from_millis(200));
    }
    println!("{what} ({:.1}s)", start.elapsed().as_secs_f64());
}

fn kept(api: &Api<Value>) -> Value {
    op(api, "load_alongside", json!({}))
}

/// Waits for a normal load to finish: the game's one GameController is a
/// new live object.
fn wait_for_normal_load(api: &Api<Value>, old_controller: &str) {
    wait_for("normal load finished", 120, || {
        let now = instance_now(api, "GameController");
        now != old_controller && now.parse::<i64>().is_ok()
    });
}

/// An active door (switched-on Changelevel) leading to `to`.
fn door_to(api: &Api<Value>, to: &str) -> Option<i64> {
    let r = api.op("walk_class", json!({"class": "Changelevel", "include_inactive": false}));
    r.result.get("instances").and_then(Value::as_array).cloned().unwrap_or_default().iter().filter_map(handle_of).find(|h| {
        api.op("read_field", json!({"handle": h, "field": "OtherLevel"})).result.as_str() == Some(to)
            && call(api, *h, "get_isActiveAndEnabled", json!([])).as_bool() == Some(true)
    })
}

fn use_door(api: &Api<Value>, to: &str) {
    let trips = kept(api)["trips"].as_array().map_or(0, |t| t.len());
    let door = door_to(api, to).unwrap_or_else(|| panic!("no door to {to} here"));
    call(api, door, "Interact", json!([]));
    wait_for(&format!("moved to {to}"), 30, || {
        let k = kept(api);
        k["trips"].as_array().map_or(0, |t| t.len()) > trips && k["current"].as_str() == Some(to)
    });
    println!("  trip: {}", kept(api)["trips"].as_array().and_then(|t| t.last().cloned()).unwrap_or_default());
}

#[test]
fn kept_areas_played_through() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    op(&api, "errors", json!({"mark": true}));

    // 1. A normal load, then areas kept loaded around the home area.
    let controller = instance_now(&api, "GameController");
    let loading = op(&api, "reload_save", json!({}))["loading"].as_str().unwrap_or("").to_string();
    let players_save = loading.rsplit('/').next().unwrap_or("").to_string();
    wait_for_normal_load(&api, &controller);
    wait_for("areas kept loaded around home", 180, || {
        let k = kept(&api);
        k["loaded"].as_object().map_or(0, |m| m.len()) >= 2 && k["loading"].as_array().is_some_and(|l| l.is_empty())
    });
    let k = kept(&api);
    let home = k["current"].as_str().unwrap_or("").to_string();
    let away = k["loaded"]
        .as_object()
        .into_iter()
        .flatten()
        .map(|(a, _)| a.clone())
        .find(|a| *a != home && door_to(&api, a).is_some())
        .expect("a kept area a home door leads to");
    println!("home {home}, away {away}");

    // 2. Out and back through doors.
    use_door(&api, &away);
    std::thread::sleep(Duration::from_secs(2));
    use_door(&api, &home);
    std::thread::sleep(Duration::from_secs(2));

    // 3. Save into the test slot and load it.
    call_static(&api, "SaveController", "SaveGame", json!(["ModTest", "", "NONE"]));
    let controller = instance_now(&api, "GameController");
    op(&api, "reload_save", json!({}));
    wait_for_normal_load(&api, &controller);
    std::thread::sleep(Duration::from_secs(3));

    // Checks.
    let dead: Vec<String> = WATCHED.iter().map(|c| (c, instance_now(&api, c))).filter(|(_, v)| v.parse::<i64>().is_err()).map(|(c, v)| format!("{c}: {v}")).collect();
    let t = handle_of(&call_static(&api, "System.Type", "GetType", json!(["PlayerIdentity, Assembly-CSharp"]))).expect("PlayerIdentity");
    let f = handle_of(&call(&api, t, "GetField", json!(["identity"]))).expect("identity field");
    let me = handle_of(&call(&api, f, "GetValue", json!([null]))).map(|h| api.op("read_field", json!({"handle": h, "field": "firstName"})).result);
    let errors = op(&api, "errors", json!({}));
    println!("\none-copy fields not live: {dead:?}");
    println!("player identity first name: {me:?}");
    println!("game errors during the run: {}", errors["total"]);
    for g in errors["groups"].as_array().into_iter().flatten() {
        println!("  {}  {}  at {}", g["count"], g["error"], g["at"]);
    }

    // Back to the player's own save, so their next save goes to their slot.
    let controller = instance_now(&api, "GameController");
    let back = op(&api, "reload_save", json!({"save": players_save}));
    wait_for_normal_load(&api, &controller);
    println!("back on the player's save: {}", back["loading"]);
    assert!(dead.is_empty(), "one-copy fields not live: {dead:?}");
    assert_eq!(me.as_ref().and_then(|v| v.as_str()), Some("Tom"), "player identity lost");
}
