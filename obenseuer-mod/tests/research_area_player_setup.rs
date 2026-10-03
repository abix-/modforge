//! Where a second area's own player setup sits (operator 2026-10-02): the
//! classes research_area_takeover.rs found duplicated by loading an area
//! alongside, each new copy followed up its parent objects to the top, and
//! the same for the first area's copies to compare. If they share one top
//! object per area, a mod can switch off just that one.
//!
//! Start with only one area loaded (load a save first). Both areas stay
//! loaded when it ends; load a save again afterwards.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_area_player_setup -- --test-threads=1 --nocapture
//! ```
//!
//! OBENSEUER_SECOND_AREA picks the area (default "Interior Tenement
//! Gatehouse"). SKIPs (prints why and passes) when the game is not running.
//! Results go to output/area-player-setup.txt.

mod common;
use std::collections::{BTreeMap, HashSet};
use std::time::{Duration, Instant};

use common::{api, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

/// The classes research_area_takeover.rs found a second area duplicates.
const DUPLICATED: &[&str] = &[
    "PlayerCamera",
    "CameraRotate",
    "CameraShake",
    "SetControls",
    "InteractObjects",
    "ThirdPersonCameraCollision",
    "ThirdPersonCameraController",
    "UnityStandardAssets.Characters.ThirdPerson.FirstPersonSettings",
    "PlayerAudioListener",
    "FirstPersonHands",
    "PlayerCameraAnimations",
    "PauseMenu",
    "DeathMessage",
    "PauseMenuGlow",
    "SoundscapeGlobal",
    "info_map",
    "KeyBindingsMenu",
    "LoadMenu",
    "UnityEngine.Camera",
    "UnityEngine.AudioListener",
    "UnityEngine.Canvas",
];

fn op(api: &Api<Value>, name: &str, args: Value) -> Result<Value, String> {
    let r = api.op(name, args);
    if r.ok { Ok(r.result) } else { Err(r.error.unwrap_or_else(|| "failed".into())) }
}

fn call(api: &Api<Value>, h: i64, method: &str) -> Result<Value, String> {
    op(api, "invoke_method", json!({"handle": h, "method": method, "args": []}))
}

fn release(api: &Api<Value>, h: i64) {
    api.op("release_handle", json!({"handle": h}));
}

/// Live copies of a class: (instance id, handle).
fn copies(api: &Api<Value>, class: &str) -> Vec<(i64, i64)> {
    let Ok(r) = op(api, "walk_class", json!({"class": class, "include_inactive": true})) else {
        return Vec::new();
    };
    let mut out = Vec::new();
    for i in r.get("instances").and_then(Value::as_array).cloned().unwrap_or_default() {
        let Some(h) = handle_of(&i) else { continue };
        match call(api, h, "GetInstanceID").ok().and_then(|v| v.as_i64()) {
            Some(id) => out.push((id, h)),
            None => release(api, h),
        }
    }
    out
}

/// The object's parent objects from the top down: "Top / ... / Object",
/// and the top object's id.
fn chain(api: &Api<Value>, component: i64) -> (String, i64) {
    let mut names = Vec::new();
    let mut top = 0;
    let mut t = call(api, component, "get_transform").ok().as_ref().and_then(handle_of);
    while let Some(h) = t {
        let name = call(api, h, "get_name").ok().and_then(|v| v.as_str().map(String::from)).unwrap_or("?".into());
        names.push(name);
        if let Some(g) = call(api, h, "get_gameObject").ok().as_ref().and_then(handle_of) {
            top = call(api, g, "GetInstanceID").ok().and_then(|v| v.as_i64()).unwrap_or(0);
            release(api, g);
        }
        let parent = call(api, h, "get_parent").ok().as_ref().and_then(handle_of);
        release(api, h);
        t = parent;
    }
    names.reverse();
    (names.join(" / "), top)
}

#[test]
fn second_area_player_setup_parents() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let second = std::env::var("OBENSEUER_SECOND_AREA").unwrap_or_else(|_| "Interior Tenement Gatehouse".into());
    let scenes = op(&api, "invoke_static", json!({"class": "UnityEngine.SceneManagement.SceneManager", "method": "get_sceneCount", "args": []}));
    assert_eq!(scenes.as_ref().ok().and_then(|v| v.as_i64()), Some(1), "need exactly one area loaded (load a save): {scenes:?}");

    let before: Vec<HashSet<i64>> = DUPLICATED
        .iter()
        .map(|c| {
            let v = copies(&api, c);
            v.iter().for_each(|(_, h)| release(&api, *h));
            v.into_iter().map(|(id, _)| id).collect()
        })
        .collect();

    let start = Instant::now();
    let load = op(&api, "invoke_static", json!({"class": "UnityEngine.SceneManagement.SceneManager", "method": "LoadSceneAsync", "args": [second, "Additive"]}));
    let load = load.ok().as_ref().and_then(handle_of).expect("LoadSceneAsync gave an AsyncOperation");
    while !call(&api, load, "get_isDone").ok().and_then(|v| v.as_bool()).unwrap_or(false) {
        assert!(start.elapsed() < Duration::from_secs(180), "{second} did not load in 180s");
        std::thread::sleep(Duration::from_millis(100));
    }
    release(&api, load);
    std::thread::sleep(Duration::from_secs(3));

    let mut out = Vec::new();
    let mut say = |line: String| {
        println!("{line}");
        out.push(line);
    };
    say(format!("loaded {second} alongside in {:.2}s\n", start.elapsed().as_secs_f64()));

    // top object id -> (top name, which area's copy, lines)
    let mut tops: BTreeMap<(String, i64), Vec<String>> = BTreeMap::new();
    for (i, class) in DUPLICATED.iter().enumerate() {
        for (id, h) in copies(&api, class) {
            let new = !before[i].contains(&id);
            // Of the 670 canvases only the new ones matter.
            if *class == "UnityEngine.Canvas" && !new {
                release(&api, h);
                continue;
            }
            let (path, top) = chain(&api, h);
            release(&api, h);
            let area = if new { "second" } else { "first" };
            let top_name = path.split(" / ").next().unwrap_or("?").to_string();
            tops.entry((format!("{area}: {top_name}"), top)).or_default().push(format!("{class}: {path}"));
        }
    }

    say("top objects, by area (first = already loaded, second = loaded alongside):".into());
    for ((label, id), lines) in &tops {
        say(format!("\n{label} (top object id {id}), {} parts:", lines.len()));
        for l in lines {
            say(format!("  {l}"));
        }
    }

    let path = common::output_path("area-player-setup.txt");
    std::fs::write(&path, out.join("\n") + "\n").expect("write the results");
    println!("\nwritten to {path}; both areas stay loaded, load a save afterwards");
}
