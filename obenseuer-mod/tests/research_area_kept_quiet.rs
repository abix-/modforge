//! Keep a second area loaded alongside without it taking over (operator
//! 2026-10-02): load it, switch off its own player setup and its sound,
//! image effects and navigation, and point the game's one-copy `instance`
//! fields back at the first area's copies. Then the player checks in the
//! game that the HUD and the view are normal.
//!
//! What to switch off comes from research_area_player_setup.rs and
//! research_area_main.rs; which `instance` fields the second area takes
//! over (or leaves null) from research_area_takeover.rs.
//!
//! Start with only one area loaded (load a save first). Both areas stay
//! loaded when it ends; load a save again afterwards.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_area_kept_quiet -- --test-threads=1 --nocapture
//! ```
//!
//! OBENSEUER_SECOND_AREA picks the area (default "Interior Tenement
//! Gatehouse"). SKIPs (prints why and passes) when the game is not running.
//! Results go to docs/area-kept-quiet.txt.

mod common;
use std::collections::HashSet;
use std::time::{Duration, Instant};

use common::{api, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

/// Static one-copy fields a second area changed in
/// research_area_takeover.rs: (type, assembly, field).
const ONE_COPY: &[(&str, &str, &str)] = &[
    ("PlayerCamera", "Assembly-CSharp", "instance"),
    ("CameraRotate", "Assembly-CSharp", "instance"),
    ("CameraShake", "Assembly-CSharp", "instance"),
    ("SetControls", "Assembly-CSharp", "instance"),
    ("InteractObjects", "Assembly-CSharp", "instance"),
    ("ThirdPersonCameraCollision", "Assembly-CSharp", "instance"),
    ("ThirdPersonCameraController", "Assembly-CSharp", "instance"),
    ("UnityStandardAssets.Characters.ThirdPerson.FirstPersonSettings", "Assembly-CSharp", "instance"),
    ("PlayerAudioListener", "Assembly-CSharp", "instance"),
    ("FirstPersonHands", "Assembly-CSharp", "instance"),
    ("PlayerCameraAnimations", "Assembly-CSharp", "instance"),
    ("PauseMenu", "Assembly-CSharp", "instance"),
    ("DeathMessage", "Assembly-CSharp", "instance"),
    ("PauseMenuGlow", "Assembly-CSharp", "instance"),
    ("SoundscapeGlobal", "Assembly-CSharp", "instance"),
    ("info_map", "Assembly-CSharp", "instance"),
    ("LightsController", "Assembly-CSharp", "instance"),
    ("GeneratorPanel", "Assembly-CSharp", "instance"),
    ("GrowingPanel", "Assembly-CSharp", "instance"),
    ("ManufacturingPanel", "Assembly-CSharp", "instance"),
    ("ManufacturingProcessPanel", "Assembly-CSharp", "instance"),
    ("WindowNaturalLight", "Assembly-CSharp", "instance"),
    ("AstarPath", "AstarPathfindingProject", "active"),
];

fn op(api: &Api<Value>, name: &str, args: Value) -> Result<Value, String> {
    let r = api.op(name, args);
    if r.ok { Ok(r.result) } else { Err(r.error.unwrap_or_else(|| "failed".into())) }
}

fn call(api: &Api<Value>, h: i64, method: &str, args: Value) -> Result<Value, String> {
    op(api, "invoke_method", json!({"handle": h, "method": method, "args": args}))
}

fn obj(api: &Api<Value>, h: i64, method: &str) -> Option<i64> {
    call(api, h, method, json!([])).ok().as_ref().and_then(handle_of)
}

fn release(api: &Api<Value>, h: i64) {
    api.op("release_handle", json!({"handle": h}));
}

fn id_text(api: &Api<Value>, h: Option<i64>) -> String {
    match h {
        None => "null".into(),
        Some(h) => call(api, h, "GetInstanceID", json!([])).ok().and_then(|v| v.as_i64()).map_or("?".into(), |i| i.to_string()),
    }
}

/// Live copies of a class: (instance id, handle).
fn copies(api: &Api<Value>, class: &str) -> Vec<(i64, i64)> {
    let Ok(r) = op(api, "walk_class", json!({"class": class, "include_inactive": true})) else {
        return Vec::new();
    };
    let mut out = Vec::new();
    for i in r.get("instances").and_then(Value::as_array).cloned().unwrap_or_default() {
        let Some(h) = handle_of(&i) else { continue };
        match call(api, h, "GetInstanceID", json!([])).ok().and_then(|v| v.as_i64()) {
            Some(id) => out.push((id, h)),
            None => release(api, h),
        }
    }
    out
}

fn ids(api: &Api<Value>, class: &str) -> HashSet<i64> {
    let v = copies(api, class);
    v.iter().for_each(|(_, h)| release(api, *h));
    v.into_iter().map(|(id, _)| id).collect()
}

/// The copies of a class that were not there before: their handles.
fn new_copies(api: &Api<Value>, class: &str, before: &HashSet<i64>) -> Vec<i64> {
    let mut out = Vec::new();
    for (id, h) in copies(api, class) {
        if before.contains(&id) {
            release(api, h);
        } else {
            out.push(h);
        }
    }
    out
}

fn name_of(api: &Api<Value>, h: i64) -> String {
    call(api, h, "get_name", json!([])).ok().and_then(|v| v.as_str().map(String::from)).unwrap_or("?".into())
}

/// Switches off a game object; returns its name.
fn switch_off(api: &Api<Value>, go: i64) -> String {
    let name = name_of(api, go);
    match call(api, go, "SetActive", json!([false])) {
        Ok(_) => name,
        Err(e) => format!("{name} (SetActive failed: {e})"),
    }
}

/// A static field: (FieldInfo handle, value handle now).
fn static_field(api: &Api<Value>, ty: &str, assembly: &str, field: &str) -> Option<i64> {
    let t = op(api, "invoke_static", json!({"class": "System.Type", "method": "GetType", "args": [format!("{ty}, {assembly}")]}));
    let t = t.ok().as_ref().and_then(handle_of)?;
    let f = call(api, t, "GetField", json!([field])).ok().as_ref().and_then(handle_of);
    release(api, t);
    f
}

fn value(api: &Api<Value>, field: i64) -> Option<i64> {
    call(api, field, "GetValue", json!([null])).ok().as_ref().and_then(handle_of)
}

fn main_camera(api: &Api<Value>) -> String {
    let cam = op(api, "invoke_static", json!({"class": "UnityEngine.Camera", "method": "get_main", "args": []}));
    let cam = cam.ok().as_ref().and_then(handle_of);
    let text = id_text(api, cam);
    cam.into_iter().for_each(|h| release(api, h));
    text
}

/// Active and enabled audio listeners (Unity wants exactly one).
fn listeners(api: &Api<Value>) -> usize {
    let mut n = 0;
    for (_, h) in copies(api, "UnityEngine.AudioListener") {
        let on = call(api, h, "get_isActiveAndEnabled", json!([])).ok().and_then(|v| v.as_bool()).unwrap_or(false);
        n += on as usize;
        release(api, h);
    }
    n
}

#[test]
fn second_area_kept_quiet() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let second = std::env::var("OBENSEUER_SECOND_AREA").unwrap_or_else(|_| "Interior Tenement Gatehouse".into());
    let scenes = op(&api, "invoke_static", json!({"class": "UnityEngine.SceneManagement.SceneManager", "method": "get_sceneCount", "args": []}));
    assert_eq!(scenes.as_ref().ok().and_then(|v| v.as_i64()), Some(1), "need exactly one area loaded (load a save): {scenes:?}");

    let mut out = Vec::new();
    let mut say = |line: String| {
        println!("{line}");
        out.push(line);
    };

    // The one-copy fields and the first area's copies they point at now.
    let fields: Vec<(&str, Option<i64>, Option<i64>)> = ONE_COPY
        .iter()
        .map(|(ty, asm, f)| {
            let field = static_field(&api, ty, asm, f);
            let first = field.and_then(|f| value(&api, f));
            (*ty, field, first)
        })
        .collect();
    let marker_classes = ["ThirdPersonCameraController", "PauseMenu", "UnityEngine.Camera", "info_navigation", "SoundscapeGlobal"];
    let before: Vec<HashSet<i64>> = marker_classes.iter().map(|c| ids(&api, c)).collect();
    say(format!("main camera {}, audio listeners on {}", main_camera(&api), listeners(&api)));

    let start = Instant::now();
    let load = op(&api, "invoke_static", json!({"class": "UnityEngine.SceneManagement.SceneManager", "method": "LoadSceneAsync", "args": [second, "Additive"]}));
    let load = load.ok().as_ref().and_then(handle_of).expect("LoadSceneAsync gave an AsyncOperation");
    while !call(&api, load, "get_isDone", json!([])).ok().and_then(|v| v.as_bool()).unwrap_or(false) {
        assert!(start.elapsed() < Duration::from_secs(180), "{second} did not load in 180s");
        std::thread::sleep(Duration::from_millis(100));
    }
    release(&api, load);
    std::thread::sleep(Duration::from_secs(3));
    say(format!("loaded {second} alongside in {:.2}s", start.elapsed().as_secs_f64()));
    say(format!("main camera {}, audio listeners on {}", main_camera(&api), listeners(&api)));

    say("\nswitched off in the second area:".into());
    let mut off = Vec::new();
    for c in new_copies(&api, "ThirdPersonCameraController", &before[0]) {
        off.extend(obj(&api, c, "get_gameObject"));
    }
    for c in new_copies(&api, "PauseMenu", &before[1]) {
        off.extend(obj(&api, c, "get_gameObject"));
    }
    for c in new_copies(&api, "UnityEngine.Camera", &before[2]) {
        if name_of(&api, c).starts_with("screenshot_camera") {
            if let Some(parent) = obj(&api, c, "get_transform").and_then(|t| obj(&api, t, "get_parent")) {
                off.extend(obj(&api, parent, "get_gameObject"));
            }
        }
    }
    for c in new_copies(&api, "info_navigation", &before[3]) {
        off.extend(obj(&api, c, "get_gameObject"));
        // __MAIN's "Post Processing" next to it.
        let main = obj(&api, c, "get_transform").and_then(|t| obj(&api, t, "get_parent"));
        let post = main.and_then(|m| call(&api, m, "Find", json!(["Post Processing"])).ok().as_ref().and_then(handle_of));
        off.extend(post.and_then(|p| obj(&api, p, "get_gameObject")));
    }
    for c in new_copies(&api, "SoundscapeGlobal", &before[4]) {
        off.extend(obj(&api, c, "get_gameObject"));
    }
    let mut seen = HashSet::new();
    for go in off {
        let id = id_text(&api, Some(go));
        if seen.insert(id.clone()) {
            say(format!("  {} (id {id})", switch_off(&api, go)));
        }
    }

    say("\none-copy fields: first area's copy -> after the load -> after putting back".into());
    for (ty, field, first) in &fields {
        let Some(field) = field else {
            say(format!("  {ty:<40} field not found"));
            continue;
        };
        let after_load = value(&api, *field);
        let changed = id_text(&api, after_load) != id_text(&api, *first);
        if changed {
            let arg = first.map_or(json!(null), |h| json!({"handle": h}));
            if let Err(e) = call(&api, *field, "SetValue", json!([null, arg])) {
                say(format!("  {ty:<40} SetValue failed: {e}"));
            }
        }
        let now = value(&api, *field);
        say(format!(
            "  {ty:<40} {} -> {} -> {}{}",
            id_text(&api, *first),
            id_text(&api, after_load),
            id_text(&api, now),
            if changed { "  (put back)" } else { "" }
        ));
    }

    say(format!("\nmain camera {}, audio listeners on {}", main_camera(&api), listeners(&api)));
    let path = format!("{}/docs/area-kept-quiet.txt", env!("CARGO_MANIFEST_DIR"));
    std::fs::write(&path, out.join("\n") + "\n").expect("write the results");
    println!("\nwritten to {path}; both areas stay loaded: check the HUD and the view in the game");
}
