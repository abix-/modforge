//! What happens to an area's arrival points while it is away
//! (docs/kept-areas.md): the kept door back failed with "no arrival point
//! ... named X: in \"\"": the entries are in the area's own list but their
//! Location reads as destroyed. Uses one kept door out of the area the
//! player is in (the game's own Interact), then reads the area left's own
//! PlayerLevelEntrypoints list: each entry, whether its Location is live,
//! and its scene. No door back.
//!
//! Changes the game: moves the player through one door.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_kept_arrivals -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use std::time::{Duration, Instant};

use common::{api, call, call_static, handle_of, op, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

/// The area's own arrival points: (name, Location live, Location's scene).
fn arrivals(api: &Api<Value>, area: &str) -> Vec<(String, bool, String)> {
    let Some(own) = handle_of(&call_static(api, "Unityforge.Shim.FirstCopyGuard", "AreaCopy", json!(["PlayerLevelEntrypoints", area]))) else {
        return Vec::new();
    };
    let Some(list) = handle_of(&api.op("read_field", json!({"handle": own, "field": "Entrypoints"})).result) else {
        return Vec::new();
    };
    let n = call(api, list, "get_Count", json!([])).as_i64().unwrap_or(0);
    let mut out = Vec::new();
    for i in 0..n {
        let Some(e) = handle_of(&call(api, list, "get_Item", json!([i]))) else { continue };
        let name = api.op("read_field", json!({"handle": e, "field": "Name"})).result.as_str().unwrap_or("").to_string();
        let location = handle_of(&api.op("read_field", json!({"handle": e, "field": "Location"})).result);
        let scene = location.map(|l| call_static(api, "Unityforge.Shim.SceneTools", "SceneOf", json!([{"handle": l}]))).and_then(|v| v.as_str().map(String::from)).unwrap_or_default();
        out.push((name, location.is_some(), scene));
    }
    out
}

fn summary(rows: &[(String, bool, String)]) -> String {
    let live = rows.iter().filter(|r| !r.2.is_empty()).count();
    let null = rows.iter().filter(|r| !r.1).count();
    let dead = rows.iter().filter(|r| r.1 && r.2.is_empty()).count();
    format!("{} entries: {live} with a live Location, {null} with none, {dead} with a destroyed one", rows.len())
}

#[test]
fn kept_arrivals() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let here = call_static(&api, "UnityEngine.Application", "get_loadedLevelName", json!([])).as_str().unwrap_or("").to_string();
    let kept = op(&api, "load_alongside", json!({}));
    let loaded: Vec<String> = kept["loaded"].as_object().map(|m| m.keys().cloned().collect()).unwrap_or_default();
    let before = arrivals(&api, &here);
    println!("{here} before leaving: {}", summary(&before));
    // A door of this area into an area kept loaded.
    let doors = api.op("walk_class", json!({"class": "Changelevel", "include_inactive": false}));
    let door = doors.result.get("instances").and_then(Value::as_array).cloned().unwrap_or_default().iter().filter_map(handle_of).find_map(|h| {
        let to = api.op("read_field", json!({"handle": h, "field": "OtherLevel"})).result.as_str().map(String::from)?;
        (loaded.contains(&to) && to != here && call(&api, h, "get_isActiveAndEnabled", json!([])).as_bool() == Some(true)).then_some((h, to))
    });
    let Some((door, to)) = door else {
        println!("no door here into an area kept loaded ({loaded:?})");
        return;
    };
    let trips = kept["trips"].as_array().map_or(0, |t| t.len());
    call(&api, door, "Interact", json!([]));
    let start = Instant::now();
    while op(&api, "load_alongside", json!({}))["trips"].as_array().map_or(0, |t| t.len()) <= trips {
        assert!(start.elapsed() < Duration::from_secs(30), "the door to {to} did not move the player");
        std::thread::sleep(Duration::from_millis(200));
    }
    std::thread::sleep(Duration::from_secs(2)); // the area left switched off, its lists and handlers out
    let after = arrivals(&api, &here);
    println!("{here} after leaving for {to}: {}", summary(&after));
    for (name, has, scene) in &after {
        if !scene.is_empty() {
            continue;
        }
        let was = before.iter().find(|b| &b.0 == name).map(|b| b.2.clone()).unwrap_or_default();
        println!("  {name}: Location {}, before leaving in {was:?}", if *has { "destroyed" } else { "null" });
    }
}
