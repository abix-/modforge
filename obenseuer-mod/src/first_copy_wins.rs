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
//! On from mod start (see install); the `first_copy_wins` op reads what it
//! did. Proven by tests/research_first_copy_wins.rs.

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
/// The same objects' instance ids: an area's own setup, never switched
/// back on (kept_loaded.rs).
static SWITCHED_OFF_IDS: Mutex<Vec<i64>> = Mutex::new(Vec::new());

pub(crate) fn switched_off_ids() -> Vec<i64> {
    SWITCHED_OFF_IDS.lock().unwrap().clone()
}

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
/// OpenSewerCharacterController: the player character, a top object of its
/// own in the player's building (research_cameras.rs), kept on by the area
/// swap.
pub(crate) const PLAYER_SETUP: &[&str] = &["ThirdPersonCameraController", "PauseMenu", "TimeOfDayAzure", "OpenSewerCharacterController"];

/// Patched once when the mod starts, and left on: Harmony patches cost
/// what they cost (pardeike/Harmony#609, "It is as fast as you can get
/// it"), so BepInEx mods patch once at start (MSchmoecker/FasterLoading,
/// Plugin.Awake), never per load. Patching on every save load froze the
/// game 0.62 s. The guard does nothing while no live copy exists, which is
/// all of normal play.
pub fn install() {
    let start = std::time::Instant::now();
    match turn_on() {
        Ok(n) => unityforge::mono::log(
            unityforge::mono::LogLevel::Info,
            &format!("obenseuer-mod: first_copy_wins on: {n} patches in {:.3}s", start.elapsed().as_secs_f64()),
        ),
        Err(e) => unityforge::mono::log(unityforge::mono::LogLevel::Error, &format!("obenseuer-mod: first_copy_wins failed: {e}")),
    }
    OP_REGISTRY.register(OpDef::new(
        "first_copy_wins",
        "Stops a second copy of a one-copy game class from taking over: its patches, and what it skipped",
        "{}",
        |_| MAIN_QUEUE.run_result("first_copy_wins", Duration::from_secs(5), state),
    ));
}

/// Patches Awake and OnDestroy of every one-copy class. Returns the count.
fn turn_on() -> Result<usize, String> {
    let mut fields = one_copy_classes()?;
    fields.extend(OTHER_FIELDS.iter().map(|(t, _, f)| (t.to_string(), f.to_string())));
    *FIELD_OF.lock().unwrap() = fields.iter().cloned().collect();
    let mut hooks = Vec::new();
    for (class, _) in fields {
        for (method, cb) in [("Awake", on_awake as extern "C" fn(*const c_void) -> i32), ("OnDestroy", on_destroy)] {
            // Classes without that method: nothing to patch.
            if let Ok(h) = patch_prefix_ctx(&class, method, HookCtx::Instance, cb) {
                hooks.push(h);
            }
        }
    }
    let n = hooks.len();
    *HOOKS.lock().unwrap() = hooks;
    Ok(n)
}

fn state() -> Result<Json, String> {
    Ok(json!({
        "patches": HOOKS.lock().unwrap().len(),
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
    // A live copy the game keeps through scene changes (LoadingScreen,
    // SaveController, InputManager...) guards itself: the new copy's own
    // Awake destroys it (LoadingScreen.cs:83). Let it run.
    let kept = invoke_static("Unityforge.Shim.SceneTools", "KeptThroughLoads", &json!([{"handle": current.handle().0}]))?;
    if kept.as_bool() == Some(true) {
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
        if let Some(id) = top.invoke("GetInstanceID", &json!([])).ok().and_then(|v| v.as_i64()) {
            SWITCHED_OFF_IDS.lock().unwrap().push(id);
        }
    });
}

fn obj(v: Json) -> Option<MonoObject> {
    json_handle(&v).map(owned_object)
}
