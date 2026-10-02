//! First copy wins (research, operator 2026-10-02): an area loaded
//! alongside another brings its own copies of classes that keep one copy
//! in a static `instance` field. Their Awake overwrites the field, then
//! info_game_logic destroys them, leaving the field on a destroyed object
//! (docs/loading-research.md).
//!
//! The usual Unity guard, which the game itself uses in LoadingScreen and
//! info_game_logic: a new copy that finds a live copy already in the field
//! does not start. Here a Harmony prefix on Awake and OnDestroy of every
//! such class: when the field already holds a live, different copy, the
//! original method is skipped and the new copy is disabled.
//!
//! Off until the `first_copy_wins` op turns it on; proven by
//! tests/research_first_copy_wins.rs.

use std::collections::BTreeMap;
use std::ffi::c_void;
use std::sync::Mutex;
use std::time::Duration;

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use unityforge::hook::{Hook, HookCtx, patch_prefix_ctx};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{MonoObject, invoke_static, json_handle, owned_object};

/// The patches while on.
static HOOKS: Mutex<Vec<Hook>> = Mutex::new(Vec::new());
/// Skipped calls while on: "Class.Method" -> count.
static SKIPPED: Mutex<BTreeMap<String, u64>> = Mutex::new(BTreeMap::new());
/// Guarded class -> the static field holding its one copy.
static FIELD_OF: Mutex<BTreeMap<String, String>> = Mutex::new(BTreeMap::new());
/// Top objects switched off: their names.
static SWITCHED_OFF: Mutex<Vec<String>> = Mutex::new(Vec::new());

/// One-copy fields not named `instance`: (type, assembly, field).
/// AstarPath.active: the NPC pathfinding grid
/// (research_first_copy_wins.rs: "No AstarPath object found").
const OTHER_FIELDS: &[(&str, &str, &str)] = &[("AstarPath", "AstarPathfindingProject", "active")];

/// Classes whose new copy marks an area's own setup: the new copy's top
/// object is switched off (research_area_player_setup.rs:
/// ThirdPersonCameraController under "Player And Camera", PauseMenu on
/// "Pause Menu(Clone)"; research_azure_sky.rs: TimeOfDayAzure under the
/// area's own "Game_Logic", whose Azure sky otherwise keeps writing the
/// game-wide lighting every frame).
const PLAYER_SETUP: &[&str] = &["ThirdPersonCameraController", "PauseMenu", "TimeOfDayAzure"];

/// What an area loaded alongside still lights the first with (operator
/// 2026-10-02: "the lighting seems off"): the name the
/// `alongside_off` op takes, and the Unity class.
const LIGHTING: &[(&str, &str)] = &[
    ("post_processing", "UnityEngine.Rendering.PostProcessing.PostProcessVolume"),
    ("lights", "UnityEngine.Light"),
    ("reflection_probes", "UnityEngine.ReflectionProbe"),
];
/// Ids of every LIGHTING component when first_copy_wins turned on, so
/// the ones an area loaded after it brought can be told apart.
static BEFORE: Mutex<BTreeMap<String, Vec<i64>>> = Mutex::new(BTreeMap::new());

pub fn install() {
    OP_REGISTRY.register(OpDef::new(
        "first_copy_wins",
        "Research: stop a second copy of a one-copy game class from taking over (on/off, and what it skipped)",
        r#"{"on": true|false}  (omit to only read)"#,
        |args| {
            let on = args.get("on").and_then(Json::as_bool);
            MAIN_QUEUE.run_result("first_copy_wins", Duration::from_secs(30), move || set(on))
        },
    ));
    OP_REGISTRY.register(OpDef::new(
        "alongside_off",
        "Research: switch off one kind of lighting an area loaded alongside brought (new since first_copy_wins turned on)",
        r#"{"what": "post_processing" | "lights" | "reflection_probes"}"#,
        |args| {
            let what = args.get("what").and_then(Json::as_str).unwrap_or("").to_string();
            MAIN_QUEUE.run_result("alongside_off", Duration::from_secs(30), move || alongside_off(&what))
        },
    ));
}

/// Disables every component of one LIGHTING kind that was not there when
/// first_copy_wins turned on.
fn alongside_off(what: &str) -> Result<Json, String> {
    let (_, class) = LIGHTING.iter().find(|(w, _)| *w == what).ok_or_else(|| format!("what: one of {LIGHTING:?}"))?;
    let before = BEFORE.lock().unwrap().get(*class).cloned().ok_or("turn first_copy_wins on before loading the area")?;
    let mut names = Vec::new();
    for c in crate::deposit::instances(class)? {
        let Some(id) = c.invoke("GetInstanceID", &json!([]))?.as_i64() else { continue };
        if before.contains(&id) || c.invoke("get_enabled", &json!([]))?.as_bool() != Some(true) {
            continue;
        }
        c.invoke("set_enabled", &json!([false]))?;
        names.push(c.invoke("get_name", &json!([]))?.as_str().unwrap_or("?").to_string());
    }
    Ok(json!({"switched off": names.len(), "names": names.iter().take(20).collect::<Vec<_>>()}))
}

/// Instance ids of every live component of a class.
fn ids(class: &str) -> Vec<i64> {
    crate::deposit::instances(class)
        .unwrap_or_default()
        .iter()
        .filter_map(|c| c.invoke("GetInstanceID", &json!([])).ok()?.as_i64())
        .collect()
}

pub(crate) fn set(on: Option<bool>) -> Result<Json, String> {
    let mut failed = Vec::new();
    match on {
        Some(true) if HOOKS.lock().unwrap().is_empty() => {
            SKIPPED.lock().unwrap().clear();
            SWITCHED_OFF.lock().unwrap().clear();
            *BEFORE.lock().unwrap() = LIGHTING.iter().map(|(_, class)| (class.to_string(), ids(class))).collect();
            let mut fields = one_copy_classes()?;
            fields.extend(OTHER_FIELDS.iter().map(|(t, _, f)| (t.to_string(), f.to_string())));
            *FIELD_OF.lock().unwrap() = fields.iter().cloned().collect();
            let mut hooks = Vec::new();
            for (class, _) in fields {
                for (method, cb) in [("Awake", on_awake as extern "C" fn(*const c_void) -> i32), ("OnDestroy", on_destroy)] {
                    match patch_prefix_ctx(&class, method, HookCtx::Instance, cb) {
                        Ok(h) => hooks.push(h),
                        Err(_) => failed.push(format!("{class}.{method}")),
                    }
                }
            }
            *HOOKS.lock().unwrap() = hooks;
        }
        Some(false) => HOOKS.lock().unwrap().clear(),
        _ => {}
    }
    Ok(json!({
        "on": !HOOKS.lock().unwrap().is_empty(),
        "patches": HOOKS.lock().unwrap().len(),
        "not patched (no such method)": failed.len(),
        "skipped": SKIPPED.lock().unwrap().clone(),
        "switched off": SWITCHED_OFF.lock().unwrap().clone(),
    }))
}

/// Every Assembly-CSharp class with a static `instance` field:
/// (class, "instance").
fn one_copy_classes() -> Result<Vec<(String, String)>, String> {
    let ty = obj(invoke_static("System.Type", "GetType", &json!(["Inventory, Assembly-CSharp"]))?)
        .ok_or("Assembly-CSharp not found")?;
    let types = obj(obj(ty.invoke("get_Assembly", &json!([]))?).ok_or("no assembly")?.invoke("GetTypes", &json!([]))?)
        .ok_or("no types")?;
    let n = types.read_field("Length")?.as_i64().unwrap_or(0);
    let mut out = Vec::new();
    for i in 0..n {
        let Some(t) = obj(types.invoke("Get", &json!([i]))?) else { continue };
        let Some(f) = obj(t.invoke("GetField", &json!(["instance"]))?) else { continue };
        if f.invoke("get_IsStatic", &json!([]))?.as_bool() == Some(true) {
            if let Some(name) = t.invoke("get_FullName", &json!([]))?.as_str() {
                out.push((name.to_string(), "instance".to_string()));
            }
        }
    }
    Ok(out)
}

extern "C" fn on_awake(ctx: *const c_void) -> i32 {
    skip_if_newcomer(ctx, "Awake", true)
}

extern "C" fn on_destroy(ctx: *const c_void) -> i32 {
    skip_if_newcomer(ctx, "OnDestroy", false)
}

/// 1 (skip the original) when the class's `instance` already holds a live
/// copy that is not this one.
fn skip_if_newcomer(ctx: *const c_void, method: &str, disable: bool) -> i32 {
    let h = ctx as isize as i32;
    if h == 0 {
        return 0;
    }
    let me = owned_object(h);
    match newcomer(&me) {
        Ok(Some(class)) => {
            if disable {
                let _ = me.invoke("set_enabled", &json!([false]));
                if PLAYER_SETUP.contains(&class.as_str()) {
                    switch_off_top_next_frame(&me);
                }
            }
            *SKIPPED.lock().unwrap().entry(format!("{class}.{method}")).or_default() += 1;
            1
        }
        _ => 0,
    }
}

/// The class name when another live copy is already the one copy.
fn newcomer(me: &MonoObject) -> Result<Option<String>, String> {
    let ty = obj(me.invoke("GetType", &json!([]))?).ok_or("no type")?;
    let class = ty.invoke("get_FullName", &json!([]))?.as_str().map(String::from).ok_or("no type name")?;
    let name = FIELD_OF.lock().unwrap().get(&class).cloned().unwrap_or_else(|| "instance".into());
    let field = obj(ty.invoke("GetField", &json!([name]))?).ok_or("no one-copy field")?;
    let current = field.invoke("GetValue", &json!([null]))?;
    // The shim names a destroyed Unity object "<null>".
    if current.get("name").and_then(Json::as_str) == Some("<null>") {
        return Ok(None);
    }
    let Some(current) = obj(current) else { return Ok(None) };
    let id = |o: &MonoObject| o.invoke("GetInstanceID", &json!([])).ok().and_then(|v| v.as_i64());
    if id(&current) == id(me) {
        return Ok(None);
    }
    Ok(Some(class))
}

/// Switches off the top object of a new copy one frame later: Unity can
/// refuse SetActive while the area is still starting.
fn switch_off_top_next_frame(me: &MonoObject) {
    let Some(top) = me
        .invoke("get_transform", &json!([]))
        .ok()
        .and_then(obj)
        .and_then(|t| t.invoke("get_root", &json!([])).ok())
        .and_then(obj)
        .and_then(|r| r.invoke("get_gameObject", &json!([])).ok())
        .and_then(obj)
    else {
        return;
    };
    let handle = top.handle().0;
    std::mem::forget(top); // the job below takes the handle over
    MAIN_QUEUE.push(move || {
        let top = owned_object(handle);
        let name = top.invoke("get_name", &json!([])).ok().and_then(|v| v.as_str().map(String::from)).unwrap_or("?".into());
        let done = match top.invoke("SetActive", &json!([false])) {
            Ok(_) => name,
            Err(e) => format!("{name} (failed: {e})"),
        };
        SWITCHED_OFF.lock().unwrap().push(done);
    });
}

fn obj(v: Json) -> Option<MonoObject> {
    json_handle(&v).map(owned_object)
}
