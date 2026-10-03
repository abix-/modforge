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
/// Top objects switched off: their names.
static SWITCHED_OFF: Mutex<Vec<String>> = Mutex::new(Vec::new());
/// The same objects' instance ids: an area's own setup, never switched
/// back on (kept_loaded.rs).
static SWITCHED_OFF_IDS: Mutex<Vec<i64>> = Mutex::new(Vec::new());

pub(crate) fn switched_off_ids() -> Vec<i64> {
    SWITCHED_OFF_IDS.lock().unwrap().clone()
}

/// Assemblies whose one-copy classes are guarded, each named by one of its
/// types: the game's, and the NPC pathfinding's (AstarPath.active,
/// research_first_copy_wins.rs: "No AstarPath object found").
const ONE_COPY_ASSEMBLIES: &[&str] = &["Inventory, Assembly-CSharp", "AstarPath, AstarPathfindingProject"];

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
/// Area-owned managers (docs/kept-areas.md, rule 1, which copy): they hold
/// their area's own data, so they are the area's content, and the game uses
/// the copy of the area the player is in.
const AREA_OWNED: &[&str] = &[
    "PlayerLevelEntrypoints",
    "DestructibleList",
    "SleepEventController",
    "NPCManager",
    "info_game_logic",
    "info_map",
    "info_water_source",
];

pub fn install() {
    let start = std::time::Instant::now();
    if let Err(e) = invoke_static("Unityforge.Shim.FirstCopyGuard", "SetAreaOwned", &json!([ONE_COPY_ASSEMBLIES[0], AREA_OWNED.join(",")])) {
        unityforge::mono::log(unityforge::mono::LogLevel::Error, &format!("obenseuer-mod: area-owned managers not set: {e}"));
    }
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
    let mut one_copy = Vec::new();
    for assembly in ONE_COPY_ASSEMBLIES {
        one_copy.extend(class_list("OneCopyClasses", assembly)?);
    }
    // OnDestroy also on every class whose OnDestroy can only undo what its
    // Start did (no Awake): objects in areas never entered never started
    // (docs, "The lifecycle rules kept areas break", rule 2).
    let mut on_destroy_classes: std::collections::BTreeSet<String> = one_copy.iter().cloned().collect();
    on_destroy_classes.extend(class_list("StartWithoutAwakeClasses", ONE_COPY_ASSEMBLIES[0])?);
    let mut hooks = Vec::new();
    // Classes without that method: nothing to patch.
    for class in &one_copy {
        if let Ok(h) = patch_prefix_ctx(class, "Awake", HookCtx::Instance, on_awake) {
            hooks.push(h);
        }
    }
    for class in &on_destroy_classes {
        if let Ok(h) = patch_prefix_ctx(class, "OnDestroy", HookCtx::Instance, on_destroy) {
            hooks.push(h);
        }
    }
    let n = hooks.len();
    *HOOKS.lock().unwrap() = hooks;
    // OnDisable of objects that never started: run, with only its exception
    // swallowed (FirstCopyGuard.FinishOnDisableOfNeverStarted; docs rule 2).
    let on_disable = invoke_static("Unityforge.Shim.FirstCopyGuard", "FinishOnDisableOfNeverStarted", &json!([ONE_COPY_ASSEMBLIES[0]]))?
        .as_i64()
        .unwrap_or(0) as usize;
    Ok(n + on_disable)
}

fn state() -> Result<Json, String> {
    Ok(json!({
        "patches": HOOKS.lock().unwrap().len(),
        "OnDisable exceptions swallowed (never started)": invoke_static("Unityforge.Shim.FirstCopyGuard", "get_SwallowedOnDisable", &json!([])).ok(),
        "skipped": SKIPPED.lock().unwrap().clone(),
        "switched off": SWITCHED_OFF.lock().unwrap().clone(),
    }))
}

/// Every class in an assembly with a one copy: a public static field or
/// property of its own type, whatever the name (FirstCopyGuard.OneCopyClasses
/// in the shim). Found by name only first ("instance", then AstarPath's
/// "active"); PlayerIdentity's "identity" was missed and areas loaded
/// alongside took over the player's identity (the save fell back to the
/// name "Esko_Virtanen"). RVOSimulator's "active" is a property: missed,
/// NPCs entering a kept area found no simulator (RemoveAgent threw).
/// `list`: FirstCopyGuard.OneCopyClasses or StartWithoutAwakeClasses.
fn class_list(list: &str, assembly_of_type: &str) -> Result<Vec<String>, String> {
    let arr = obj(invoke_static("Unityforge.Shim.FirstCopyGuard", list, &json!([assembly_of_type]))?)
        .ok_or("no class list")?;
    let n = arr.read_field("Length")?.as_i64().unwrap_or(0);
    let mut out = Vec::new();
    for i in 0..n {
        if let Some(name) = arr.invoke("GetValue", &json!([i]))?.as_str() {
            out.push(name.to_string());
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
    let start = std::time::Instant::now();
    let r = skip_if_newcomer_inner(ctx, method, disable);
    PREFIX_NANOS.fetch_add(start.elapsed().as_nanos() as u64, std::sync::atomic::Ordering::Relaxed);
    r
}

/// Time spent in the prefix since the last take (kept_loaded logs it per
/// area loaded alongside: how much of the load's longest frame is the
/// mod's own).
static PREFIX_NANOS: std::sync::atomic::AtomicU64 = std::sync::atomic::AtomicU64::new(0);

pub(crate) fn take_prefix_secs() -> f64 {
    PREFIX_NANOS.swap(0, std::sync::atomic::Ordering::Relaxed) as f64 / 1e9
}

fn skip_if_newcomer_inner(ctx: *const c_void, method: &str, disable: bool) -> i32 {
    let h = ctx as isize as i32;
    if h == 0 {
        return 0;
    }
    let me = owned_object(h);
    // Awake: only a new copy is held back. OnDestroy: a new copy, or an
    // object that never started (FirstCopyGuard.SkipOnDestroy).
    let check = if method == "OnDestroy" { "SkipOnDestroy" } else { "Newcomer" };
    match newcomer(&me, check) {
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
/// The class name when another live copy is already the one copy, in one
/// call to the shim's FirstCopyGuard.Newcomer (which also lets the managers
/// the game keeps through scene changes destroy their own new copies,
/// LoadingScreen.cs:83). Done from here it took about eight bridge calls.
fn newcomer(me: &MonoObject, check: &str) -> Result<Option<String>, String> {
    let class = invoke_static("Unityforge.Shim.FirstCopyGuard", check, &json!([{"handle": me.handle().0}]))?;
    Ok(class.as_str().filter(|c| !c.is_empty()).map(String::from))
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
