//! What a second area loaded alongside brings that takes over the first
//! (operator 2026-10-02: after loading Interior Tenement Gatehouse
//! alongside Open Sewer Tenement the HUD was gone and the player seemed to
//! be somewhere else).
//!
//! Before and after loading the second area with
//! SceneManager.LoadSceneAsync(area, Additive), compares:
//! - every Assembly-CSharp class with a static `instance` field: its live
//!   copies and which copy `instance` points at
//! - Unity's cameras, canvases, audio listeners, event systems and lights,
//!   with each new one's settings
//! - where the main camera is (the player's view)
//!
//! Start with only one area loaded (load a save first). Both areas stay
//! loaded when it ends; load a save again afterwards.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_area_takeover -- --test-threads=1 --nocapture
//! ```
//!
//! OBENSEUER_SECOND_AREA picks the area (default "Interior Tenement
//! Gatehouse"). SKIPs (prints why and passes) when the game is not running.
//! Results go to docs/area-takeover.txt.

mod common;
use std::collections::HashSet;
use std::time::{Duration, Instant};

use common::{api, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

const UNITY_TYPES: &[&str] = &[
    "UnityEngine.Camera",
    "UnityEngine.Canvas",
    "UnityEngine.AudioListener",
    "UnityEngine.EventSystems.EventSystem",
    "UnityEngine.Light",
];

/// One answer from the game; Err names a failed read instead of guessing.
fn op(api: &Api<Value>, name: &str, args: Value) -> Result<Value, String> {
    let r = api.op(name, args);
    if r.ok { Ok(r.result) } else { Err(r.error.unwrap_or_else(|| "failed".into())) }
}

fn call(api: &Api<Value>, h: i64, method: &str, args: Value) -> Result<Value, String> {
    op(api, "invoke_method", json!({"handle": h, "method": method, "args": args}))
}

fn call_static(api: &Api<Value>, class: &str, method: &str, args: Value) -> Result<Value, String> {
    op(api, "invoke_static", json!({"class": class, "method": method, "args": args}))
}

fn release(api: &Api<Value>, h: i64) {
    api.op("release_handle", json!({"handle": h}));
}

fn handle(v: Result<Value, String>) -> Result<i64, String> {
    let v = v?;
    handle_of(&v).ok_or_else(|| format!("no object: {v}"))
}

fn id_of(api: &Api<Value>, h: i64) -> Result<i64, String> {
    call(api, h, "GetInstanceID", json!([]))?.as_i64().ok_or_else(|| "GetInstanceID not a number".into())
}

/// Live copies of a class: (instance id, object name, handle).
fn copies(api: &Api<Value>, class: &str) -> Vec<(i64, String, i64)> {
    let Ok(r) = op(api, "walk_class", json!({"class": class, "include_inactive": true})) else {
        return Vec::new();
    };
    let mut out = Vec::new();
    for i in r.get("instances").and_then(Value::as_array).cloned().unwrap_or_default() {
        let Some(h) = handle_of(&i) else { continue };
        match id_of(api, h) {
            Ok(id) => out.push((id, i["name"].as_str().unwrap_or("?").to_string(), h)),
            Err(_) => release(api, h),
        }
    }
    out
}

/// Which copy a static `instance` field points at.
fn instance_now(api: &Api<Value>, field: i64) -> String {
    match call(api, field, "GetValue", json!([null])) {
        Ok(v) => match handle_of(&v) {
            Some(h) => {
                let s = id_of(api, h).map_or_else(|e| format!("read failed ({e})"), |id| id.to_string());
                release(api, h);
                s
            }
            None => format!("{v}"),
        },
        Err(e) => format!("read failed ({e})"),
    }
}

/// Every Assembly-CSharp class with a static `instance` field:
/// (full name, FieldInfo handle).
fn singleton_classes(api: &Api<Value>) -> Vec<(String, i64)> {
    let ty = handle(call_static(api, "System.Type", "GetType", json!(["Inventory, Assembly-CSharp"]))).expect("Inventory type");
    let asm = handle(call(api, ty, "get_Assembly", json!([]))).expect("Assembly-CSharp");
    let types = handle(call(api, asm, "GetTypes", json!([]))).expect("its types");
    let n = op(api, "read_field", json!({"handle": types, "field": "Length"})).ok().and_then(|v| v.as_i64()).unwrap_or(0);
    let mut out = Vec::new();
    for i in 0..n {
        let Ok(t) = handle(call(api, types, "Get", json!([i]))) else { continue };
        if let Ok(f) = handle(call(api, t, "GetField", json!(["instance"]))) {
            let is_static = call(api, f, "get_IsStatic", json!([])).ok().and_then(|v| v.as_bool()).unwrap_or(false);
            let name = call(api, t, "get_FullName", json!([])).ok().and_then(|v| v.as_str().map(String::from));
            match (is_static, name) {
                (true, Some(name)) => out.push((name, f)),
                _ => release(api, f),
            }
        }
        release(api, t);
    }
    println!("{n} types in Assembly-CSharp, {} with a static instance field", out.len());
    out
}

/// Settings of one new Unity object, for the report.
fn details(api: &Api<Value>, class: &str, h: i64) -> String {
    let get = |m: &str| call(api, h, m, json!([])).map_or("?".to_string(), |v| v.to_string());
    let active = handle(call(api, h, "get_gameObject", json!([])))
        .and_then(|g| call(api, g, "get_activeInHierarchy", json!([])))
        .map_or("?".to_string(), |v| v.to_string());
    match class {
        "UnityEngine.Camera" => format!(
            "active {active} enabled {} depth {} display {} tag {}",
            get("get_enabled"),
            get("get_depth"),
            get("get_targetDisplay"),
            get("get_tag")
        ),
        "UnityEngine.Canvas" => format!(
            "active {active} enabled {} renderMode {} sortingOrder {}",
            get("get_enabled"),
            get("get_renderMode"),
            get("get_sortingOrder")
        ),
        "UnityEngine.Light" => format!("active {active} enabled {} type {}", get("get_enabled"), get("get_type")),
        _ => format!("active {active} enabled {}", get("get_enabled")),
    }
}

fn main_camera(api: &Api<Value>) -> String {
    let Ok(cam) = handle(call_static(api, "UnityEngine.Camera", "get_main", json!([]))) else {
        return "no main camera".into();
    };
    let id = id_of(api, cam).map_or("?".to_string(), |i| i.to_string());
    let pos = handle(call(api, cam, "get_transform", json!([])))
        .and_then(|t| call(api, t, "get_position", json!([])))
        .map_or("?".to_string(), |p| p.to_string());
    release(api, cam);
    format!("id {id} at {pos}")
}

#[test]
fn what_a_second_area_takes_over() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let second = std::env::var("OBENSEUER_SECOND_AREA").unwrap_or_else(|_| "Interior Tenement Gatehouse".into());
    let scenes = call_static(&api, "UnityEngine.SceneManagement.SceneManager", "get_sceneCount", json!([]));
    assert_eq!(scenes.as_ref().ok().and_then(|v| v.as_i64()), Some(1), "need exactly one area loaded (load a save): {scenes:?}");
    let first = call_static(&api, "UnityEngine.Application", "get_loadedLevelName", json!([])).unwrap_or_default();

    let mut out = Vec::new();
    let mut say = |line: String| {
        println!("{line}");
        out.push(line);
    };

    let singletons = singleton_classes(&api);
    let classes: Vec<String> =
        singletons.iter().map(|(n, _)| n.clone()).chain(UNITY_TYPES.iter().map(|s| s.to_string())).collect();
    let before: Vec<HashSet<i64>> = classes
        .iter()
        .map(|c| {
            let v = copies(&api, c);
            v.iter().for_each(|(_, _, h)| release(&api, *h));
            v.iter().map(|(id, _, _)| *id).collect()
        })
        .collect();
    let instance_before: Vec<String> = singletons.iter().map(|(_, f)| instance_now(&api, *f)).collect();
    say(format!("first area {first}; main camera {}", main_camera(&api)));

    let start = Instant::now();
    let load = handle(call_static(&api, "UnityEngine.SceneManagement.SceneManager", "LoadSceneAsync", json!([second, "Additive"])))
        .expect("LoadSceneAsync gave an AsyncOperation");
    while !call(&api, load, "get_isDone", json!([])).ok().and_then(|v| v.as_bool()).unwrap_or(false) {
        assert!(start.elapsed() < Duration::from_secs(180), "{second} did not load in 180s");
        std::thread::sleep(Duration::from_millis(100));
    }
    release(&api, load);
    say(format!("loaded {second} alongside in {:.2}s", start.elapsed().as_secs_f64()));
    std::thread::sleep(Duration::from_secs(3)); // its Awake and Start
    say(format!("main camera now {}", main_camera(&api)));

    say("\nclasses with new copies (name: new copies, settings; instance before -> after):".into());
    for (i, class) in classes.iter().enumerate() {
        let now = copies(&api, class);
        let new: Vec<_> = now.iter().filter(|(id, _, _)| !before[i].contains(id)).collect();
        let inst = singletons.get(i).map(|(_, f)| (instance_before[i].clone(), instance_now(&api, *f)));
        let switched = inst.as_ref().is_some_and(|(a, b)| a != b);
        if !new.is_empty() || switched {
            let inst_text = inst.map_or(String::new(), |(a, b)| format!("; instance {a} -> {b}"));
            say(format!("  {class}: {} before, {} new{inst_text}", before[i].len(), new.len()));
            for (id, name, h) in &new {
                say(format!("    {name} (id {id}) {}", details(&api, class, *h)));
            }
        }
        now.iter().for_each(|(_, _, h)| release(&api, *h));
    }
    for (_, f) in &singletons {
        release(&api, *f);
    }

    let path = format!("{}/docs/area-takeover.txt", env!("CARGO_MANIFEST_DIR"));
    std::fs::write(&path, out.join("\n") + "\n").expect("write the results");
    println!("\nwritten to {path}; both areas stay loaded, load a save afterwards");
}
