//! Two areas loaded at once (operator 2026-10-02: load one area, load
//! another, keep both loaded and review them in detail; no unloading).
//!
//! With the player in one area, loads a second area alongside it with
//! SceneManager.LoadSceneAsync(area, Additive) and reports, before and
//! after: scenes loaded, memory, every manager's live copies and which
//! copy the game's `instance` points at, the cameras, and where each
//! area's doors are (whether the two areas overlap in space). Both areas
//! stay loaded when the test ends, to look at in the game.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_two_areas -- --test-threads=1 --nocapture
//! ```
//!
//! OBENSEUER_SECOND_AREA picks the area to load (default "Interior Tenement
//! Gatehouse"). SKIPs (prints why and passes) when the game is not running.
//! Results go to output/two-areas.txt.

mod common;
use std::collections::HashSet;
use std::time::{Duration, Instant};

use common::{api, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

const MANAGERS: &[&str] = &[
    "SaveController",
    "LoadingScreen",
    "Inventory",
    "BackpackStorage",
    "PlayerStats",
    "TimeOfDayAzure",
    "Crime",
    "Money",
    "DifficultyController",
    "WaitingController",
    "TenementController",
    "GameUIController",
    "Notifications",
    "InteractObjects",
];

fn call(api: &Api<Value>, h: i64, method: &str, args: Value) -> Value {
    api.op("invoke_method", json!({"handle": h, "method": method, "args": args})).result
}

fn read(api: &Api<Value>, h: i64, field: &str) -> Value {
    api.op("read_field", json!({"handle": h, "field": field})).result
}

fn call_static(api: &Api<Value>, class: &str, method: &str, args: Value) -> Value {
    api.op("invoke_static", json!({"class": class, "method": method, "args": args})).result
}

fn release(api: &Api<Value>, h: i64) {
    api.op("release_handle", json!({"handle": h}));
}

fn instances(api: &Api<Value>, class: &str) -> Vec<Value> {
    let r = api.op("walk_class", json!({"class": class, "include_inactive": true}));
    r.result.get("instances").and_then(Value::as_array).cloned().unwrap_or_default()
}

fn id_of(api: &Api<Value>, h: i64) -> Option<i64> {
    call(api, h, "GetInstanceID", json!([])).as_i64()
}

/// Instance ids of every live copy of a class.
fn ids(api: &Api<Value>, class: &str) -> Vec<i64> {
    let mut out = Vec::new();
    for i in instances(api, class) {
        if let Some(h) = handle_of(&i) {
            out.extend(id_of(api, h));
            release(api, h);
        }
    }
    out.sort();
    out
}

/// The id of the copy the game's static `instance` field points at.
fn instance_id(api: &Api<Value>, class: &str) -> String {
    let ty = call_static(api, "System.Type", "GetType", json!([format!("{class}, Assembly-CSharp")]));
    let Some(ty) = handle_of(&ty) else { return "type not found".into() };
    let Some(f) = handle_of(&call(api, ty, "GetField", json!(["instance"]))) else {
        return "no static instance field".into();
    };
    let v = call(api, f, "GetValue", json!([null]));
    match handle_of(&v) {
        Some(h) => id_of(api, h).map_or("?".into(), |id| id.to_string()),
        None => "null".into(),
    }
}

fn position(api: &Api<Value>, h: i64) -> Option<[f64; 3]> {
    let t = handle_of(&call(api, h, "get_transform", json!([])))?;
    let p = call(api, t, "get_position", json!([]));
    Some([p["x"].as_f64()?, p["y"].as_f64()?, p["z"].as_f64()?])
}

/// Every door: (instance id, name, destination, position).
fn doors(api: &Api<Value>) -> Vec<(i64, String, String, [f64; 3])> {
    let mut out = Vec::new();
    for i in instances(api, "Changelevel") {
        let Some(h) = handle_of(&i) else { continue };
        let (Some(id), Some(p)) = (id_of(api, h), position(api, h)) else { continue };
        let to = read(api, h, "OtherLevel").as_str().unwrap_or("").to_string();
        out.push((id, i["name"].as_str().unwrap_or("?").to_string(), to, p));
    }
    out
}

/// Smallest box around a set of positions: (min, max).
fn bounds(points: &[[f64; 3]]) -> Option<([f64; 3], [f64; 3])> {
    let first = *points.first()?;
    let (mut lo, mut hi) = (first, first);
    for p in points {
        for k in 0..3 {
            lo[k] = lo[k].min(p[k]);
            hi[k] = hi[k].max(p[k]);
        }
    }
    Some((lo, hi))
}

fn memory(api: &Api<Value>) -> String {
    let allocated = call_static(api, "UnityEngine.Profiling.Profiler", "GetTotalAllocatedMemoryLong", json!([]));
    let reserved = call_static(api, "UnityEngine.Profiling.Profiler", "GetTotalReservedMemoryLong", json!([]));
    let managed = call_static(api, "System.GC", "GetTotalMemory", json!([false]));
    let mb = |v: &Value| v.as_f64().map_or("?".to_string(), |b| format!("{:.0} MB", b / 1048576.0));
    format!("allocated {}  reserved {}  managed {}", mb(&allocated), mb(&reserved), mb(&managed))
}

fn scene_count(api: &Api<Value>) -> Value {
    call_static(api, "UnityEngine.SceneManagement.SceneManager", "get_sceneCount", json!([]))
}

fn active_area(api: &Api<Value>) -> Value {
    call_static(api, "UnityEngine.Application", "get_loadedLevelName", json!([]))
}

#[test]
fn second_area_loaded_alongside_and_kept() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let second = std::env::var("OBENSEUER_SECOND_AREA").unwrap_or_else(|_| "Interior Tenement Gatehouse".into());
    let first = active_area(&api);
    assert_ne!(first.as_str(), Some(second.as_str()), "already in {second}; set OBENSEUER_SECOND_AREA to another area");

    let mut out = Vec::new();
    let mut say = |line: String| {
        println!("{line}");
        out.push(line);
    };

    say(format!("first area {first}, scenes loaded {}", scene_count(&api)));
    say(format!("memory before: {}", memory(&api)));
    let before: Vec<(String, Vec<i64>, String)> =
        MANAGERS.iter().map(|c| (c.to_string(), ids(&api, c), instance_id(&api, c))).collect();
    let cameras_before = ids(&api, "UnityEngine.Camera");
    let main_before = handle_of(&call_static(&api, "UnityEngine.Camera", "get_main", json!([]))).and_then(|h| id_of(&api, h));
    let doors_before = doors(&api);

    let start = Instant::now();
    let op = call_static(&api, "UnityEngine.SceneManagement.SceneManager", "LoadSceneAsync", json!([second, "Additive"]));
    let op = handle_of(&op).expect("LoadSceneAsync gave an AsyncOperation");
    while !call(&api, op, "get_isDone", json!([])).as_bool().unwrap_or(false) {
        assert!(start.elapsed() < Duration::from_secs(180), "{second} did not load in 180s");
        std::thread::sleep(Duration::from_millis(100));
    }
    say(format!("\nloaded {second} alongside in {:.2}s", start.elapsed().as_secs_f64()));
    std::thread::sleep(Duration::from_secs(3)); // let its Awake and Start run
    release(&api, op);

    say(format!("active area {}, scenes loaded {}", active_area(&api), scene_count(&api)));
    say(format!("memory after: {}", memory(&api)));

    say("\nmanagers: live copies before -> after; which copy `instance` points at before -> after".into());
    for (class, ids_before, inst_before) in &before {
        let ids_after = ids(&api, class);
        let inst_after = instance_id(&api, class);
        let switched = if inst_before == &inst_after { "same" } else { "SWITCHED" };
        say(format!(
            "  {class:<22} copies {} -> {}  {ids_before:?} -> {ids_after:?}  instance {inst_before} -> {inst_after} {switched}",
            ids_before.len(),
            ids_after.len()
        ));
    }

    let cameras_after = ids(&api, "UnityEngine.Camera");
    let main_after = handle_of(&call_static(&api, "UnityEngine.Camera", "get_main", json!([]))).and_then(|h| id_of(&api, h));
    say(format!(
        "\ncameras {} -> {}; main camera {main_before:?} -> {main_after:?}",
        cameras_before.len(),
        cameras_after.len()
    ));

    let old: HashSet<i64> = doors_before.iter().map(|d| d.0).collect();
    let doors_after = doors(&api);
    let new: Vec<_> = doors_after.iter().filter(|d| !old.contains(&d.0)).collect();
    say(format!("\ndoors: {} in {first}, {} new from {second}", doors_before.len(), new.len()));
    for (_, name, to, p) in &new {
        say(format!("  {name:<40} to {to:<35} at ({:.1}, {:.1}, {:.1})", p[0], p[1], p[2]));
    }
    let a = bounds(&doors_before.iter().map(|d| d.3).collect::<Vec<_>>());
    let b = bounds(&new.iter().map(|d| d.3).collect::<Vec<_>>());
    if let (Some((alo, ahi)), Some((blo, bhi))) = (a, b) {
        let overlap = (0..3).all(|k| alo[k] <= bhi[k] && blo[k] <= ahi[k]);
        say(format!("{first} doors span {alo:.1?} to {ahi:.1?}"));
        say(format!("{second} doors span {blo:.1?} to {bhi:.1?}"));
        say(format!("door areas overlap in space: {overlap}"));
    }

    let path = common::output_path("two-areas.txt");
    std::fs::write(&path, out.join("\n") + "\n").expect("write the results");
    println!("\nwritten to {path}; both areas stay loaded");
}
