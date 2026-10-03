//! Areas kept loaded, and doors between them without a loading screen
//! (operator 2026-10-02; research in docs/loading-research.md).
//!
//! - `load_alongside {area}`: loads an area alongside the current one in
//!   the background, with first_copy_wins on so its own copies of the
//!   game's managers and setup stay off. Records which arrival points
//!   (PlayerLevelEntrypoints entries, which every door's Awake adds to the
//!   one list) belong to which area.
//! - A prefix on Changelevel.ChangeLevel: a door whose destination is a
//!   loaded area moves the player to that area's arrival point with the
//!   game's own Entrypoint.TeleportPlayer (PlayerLevelEntrypoints.cs) and
//!   skips the save and load. Every other door works as before.
//!
//! Not handled yet: the game's record of the current area (save area
//! name, area sky and radiation settings, which area's NPC pathfinding
//! and sounds are on).

use std::collections::BTreeMap;
use std::ffi::c_void;
use std::sync::Mutex;
use std::sync::atomic::{AtomicI64, AtomicU32, Ordering};
use std::time::Duration;

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use unityforge::hook::{Hook, HookCtx, patch_prefix_ctx};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{MonoObject, invoke_static, json_handle, owned_object};

use crate::first_copy_wins;

/// Area name -> instance ids of its arrival points' Location transforms.
static AREAS: Mutex<BTreeMap<String, Vec<i64>>> = Mutex::new(BTreeMap::new());
/// Areas loading now.
static LOADING: Mutex<Vec<String>> = Mutex::new(Vec::new());
/// The door prefix, on once an area is loaded alongside.
static DOOR_HOOK: Mutex<Option<Hook>> = Mutex::new(None);
/// What the door prefix did: "from door to area/arrival point (seconds)".
static TRIPS: Mutex<Vec<String>> = Mutex::new(Vec::new());
/// The area the player is in: the only one switched on.
static CURRENT: Mutex<Option<String>> = Mutex::new(None);
/// Every area's top object holding its screenshot cameras
/// (research_area_player_setup.rs); never switched on by the area swap.
const SCREENSHOT_ROOT: &str = "___Screenshot Taking Stuff";

pub fn install() {
    OP_REGISTRY.register(OpDef::new(
        "load_alongside",
        "Load an area alongside the current one; its doors and the current area's doors then move the player without a loading screen",
        r#"{"area": "Interior Tenement Gatehouse"}  (omit area to only read)"#,
        |args| {
            let area = args.get("area").and_then(Json::as_str).map(String::from);
            MAIN_QUEUE.run_result("load_alongside", Duration::from_secs(30), move || load_alongside(area))
        },
    ));
}

/// Forgets every loaded area and takes the door patch off, for
/// investigate.rs's recovery; the scene load that follows unloads them.
pub(crate) fn reset() {
    AREAS.lock().unwrap().clear();
    LOADING.lock().unwrap().clear();
    TRIPS.lock().unwrap().clear();
    QUEUE.lock().unwrap().clear();
    *CURRENT.lock().unwrap() = None;
    *DOOR_HOOK.lock().unwrap() = None;
    set_loading_priority(false);
}

/// Areas to load alongside next, nearest door first.
static QUEUE: Mutex<Vec<String>> = Mutex::new(Vec::new());
/// The game's one GameController at the last look; a new one means a
/// normal load replaced every area.
static LAST_CONTROLLER: AtomicI64 = AtomicI64::new(0);
static TICKS: AtomicU32 = AtomicU32::new(0);
/// Frames between looks.
const TICK_EVERY: u32 = 30;

/// From the mod's tick: after a normal load finished, plan the current
/// area's door destinations; load the next one when none is loading.
pub(crate) fn tick() {
    measure_frame();
    if TICKS.fetch_add(1, Ordering::Relaxed) % TICK_EVERY != 0 {
        return;
    }
    let cfg = crate::settings::get().get().kept_loaded.clone();
    if !cfg.auto {
        return;
    }
    // Arrived: the game's one GameController is a new object. Only a normal
    // load does that (save, menu, F7, a door into an area not kept
    // loaded); loads alongside keep the first copy (first_copy_wins).
    // Polling SaveController.Loading missed loads (research_always_on.rs).
    // Between a normal load destroying the old area and starting the new
    // one there is no live GameController: nothing may start loading then.
    let Some(controller) = live_one_copy("GameController").and_then(|g| g.invoke("GetInstanceID", &json!([])).ok()?.as_i64()) else {
        return;
    };
    if LAST_CONTROLLER.swap(controller, Ordering::Relaxed) != controller {
        let area = invoke_static("UnityEngine.Application", "get_loadedLevelName", &json!([])).ok().and_then(|v| v.as_str().map(String::from));
        reset();
        *CURRENT.lock().unwrap() = area.clone();
        plan_neighbours();
        unityforge::mono::log(
            unityforge::mono::LogLevel::Info,
            &format!("obenseuer-mod: kept_loaded: arrived in {area:?}; to load alongside: {:?}", QUEUE.lock().unwrap()),
        );
    }
    if CURRENT.lock().unwrap().is_none() || !LOADING.lock().unwrap().is_empty() {
        return;
    }
    let kept = AREAS.lock().unwrap().len().saturating_sub(1);
    if kept >= cfg.max_areas {
        return;
    }
    let next = {
        let areas = AREAS.lock().unwrap();
        let mut queue = QUEUE.lock().unwrap();
        queue.retain(|a| !areas.contains_key(a));
        (!queue.is_empty()).then(|| queue.remove(0))
    };
    if let Some(area) = next {
        if let Err(e) = load_alongside(Some(area.clone())) {
            unityforge::mono::log(unityforge::mono::LogLevel::Warn, &format!("obenseuer-mod: load {area} alongside: {e}"));
        }
    }
}

/// The current area's door destinations, nearest door first. Only the
/// current area is switched on, so its doors are the active ones.
fn plan_neighbours() {
    let current = CURRENT.lock().unwrap().clone();
    let me = obj(invoke_static("UnityEngine.Camera", "get_main", &json!([])).unwrap_or_default()).and_then(|c| position(&c));
    let mut doors: Vec<(f64, String)> = Vec::new();
    for d in crate::deposit::instances("Changelevel").unwrap_or_default() {
        let Some(to) = d.read_field("OtherLevel").ok().and_then(|v| v.as_str().map(String::from)) else { continue };
        if to.is_empty() || Some(&to) == current.as_ref() {
            continue;
        }
        let dist = match (me, position(&d)) {
            (Some(a), Some(b)) => (0..3).map(|i| (a[i] - b[i]).powi(2)).sum::<f64>(),
            _ => f64::MAX,
        };
        doors.push((dist, to));
    }
    doors.sort_by(|a, b| a.0.total_cmp(&b.0));
    let mut queue = Vec::new();
    for (_, to) in doors {
        if !queue.contains(&to) {
            queue.push(to);
        }
    }
    *QUEUE.lock().unwrap() = queue;
}

/// Measuring the slowdown while an area loads alongside (operator
/// 2026-10-02: "still noticeable delay when loading"): the longest frame
/// while anything loads alongside, and when the load started.
static LONGEST_FRAME: Mutex<f64> = Mutex::new(0.0);
static LAST_FRAME: Mutex<Option<std::time::Instant>> = Mutex::new(None);
static LOAD_STARTED: Mutex<Option<std::time::Instant>> = Mutex::new(None);

/// Every frame: the time since the last one, kept while loading alongside.
fn measure_frame() {
    let now = std::time::Instant::now();
    let last = LAST_FRAME.lock().unwrap().replace(now);
    if let Some(last) = last {
        if !LOADING.lock().unwrap().is_empty() {
            let mut longest = LONGEST_FRAME.lock().unwrap();
            *longest = longest.max((now - last).as_secs_f64());
        }
    }
}

/// The game's background loading priority before the mod lowered it.
static PREVIOUS_PRIORITY: Mutex<Option<Json>> = Mutex::new(None);

/// Background loading's time per frame: Low (2 ms) while an area loads
/// alongside, so play stays smooth; the game's own value (its loading
/// screen loads fast) when nothing is loading alongside. Unity:
/// Application.backgroundLoadingPriority.
fn set_loading_priority(low: bool) {
    const APP: &str = "UnityEngine.Application";
    let mut previous = PREVIOUS_PRIORITY.lock().unwrap();
    if low {
        if previous.is_none() {
            *previous = invoke_static(APP, "get_backgroundLoadingPriority", &json!([])).ok();
        }
        let _ = invoke_static(APP, "set_backgroundLoadingPriority", &json!(["Low"]));
    } else if LOADING.lock().unwrap().is_empty() {
        if let Some(p) = previous.take() {
            let _ = invoke_static(APP, "set_backgroundLoadingPriority", &json!([p]));
        }
    }
}

fn position(o: &MonoObject) -> Option<[f64; 3]> {
    let t = obj(o.invoke("get_transform", &json!([])).ok()?)?;
    let p = t.invoke("get_position", &json!([])).ok()?;
    Some([p["x"].as_f64()?, p["y"].as_f64()?, p["z"].as_f64()?])
}

fn load_alongside(area: Option<String>) -> Result<Json, String> {
    if let Some(area) = area {
        if AREAS.lock().unwrap().contains_key(&area) || LOADING.lock().unwrap().contains(&area) {
            return Err(format!("{area} is already loaded or loading"));
        }
        *LOAD_STARTED.lock().unwrap() = Some(std::time::Instant::now());
        *LONGEST_FRAME.lock().unwrap() = 0.0;
        let before = arrival_point_ids()?;
        let current = invoke_static("UnityEngine.Application", "get_loadedLevelName", &json!([]))?
            .as_str()
            .map(String::from)
            .ok_or("no current area name")?;
        AREAS.lock().unwrap().entry(current.clone()).or_insert_with(|| before.clone());
        CURRENT.lock().unwrap().get_or_insert(current);
        set_loading_priority(true);
        let load = obj(invoke_static("UnityEngine.SceneManagement.SceneManager", "LoadSceneAsync", &json!([area, "Additive"]))?)
            .ok_or_else(|| format!("LoadSceneAsync({area}) gave nothing"))?;
        LOADING.lock().unwrap().push(area.clone());
        let handle = load.handle().0;
        std::mem::forget(load); // finish_load_when_done takes it over
        finish_load_when_done(area, handle, before);
    }
    Ok(json!({
        "loaded": AREAS.lock().unwrap().iter().map(|(a, ids)| (a.clone(), ids.len())).collect::<BTreeMap<_, _>>(),
        "loading": LOADING.lock().unwrap().clone(),
        "current": CURRENT.lock().unwrap().clone(),
        "queue": QUEUE.lock().unwrap().clone(),
        "auto": crate::settings::get().get().kept_loaded.auto,
        "doors on": DOOR_HOOK.lock().unwrap().is_some(),
        "trips": TRIPS.lock().unwrap().clone(),
    }))
}

/// Checks the load once a frame; when done, records the area's arrival
/// points and turns the door prefix on.
fn finish_load_when_done(area: String, handle: i32, before: Vec<i64>) {
    MAIN_QUEUE.push(move || {
        let load = owned_object(handle);
        if load.invoke("get_isDone", &json!([])).ok().and_then(|v| v.as_bool()) != Some(true) {
            std::mem::forget(load);
            finish_load_when_done(area, handle, before);
            return;
        }
        if !LOADING.lock().unwrap().contains(&area) {
            return; // reset() while it loaded
        }
        let new: Vec<i64> = arrival_point_ids().unwrap_or_default().into_iter().filter(|id| !before.contains(id)).collect();
        LOADING.lock().unwrap().retain(|a| *a != area);
        // Loaded but switched off until the player walks in: areas can be
        // built in the same place (the player's building inside and out).
        let switching = std::time::Instant::now();
        let _ = switch_area(&area, false);
        let switching = switching.elapsed().as_secs_f64();
        // No area names on screen: they would spoil places not found yet.
        crate::deposit::notify("Areas", "Nearby area ready");
        let load = LOAD_STARTED.lock().unwrap().take().map_or(0.0, |t| t.elapsed().as_secs_f64());
        unityforge::mono::log(
            unityforge::mono::LogLevel::Info,
            &format!(
                "obenseuer-mod: kept_loaded: {area} ready: load {load:.2}s, longest frame while loading {:.3}s, switching it off {switching:.3}s",
                *LONGEST_FRAME.lock().unwrap()
            ),
        );
        set_loading_priority(false);
        AREAS.lock().unwrap().insert(area, new);
        let mut hook = DOOR_HOOK.lock().unwrap();
        if hook.is_none() {
            *hook = patch_prefix_ctx("Changelevel", "ChangeLevel", HookCtx::Instance, on_door).ok();
        }
    });
}

/// The Location transform ids of every arrival point in the game's one
/// PlayerLevelEntrypoints list.
fn arrival_point_ids() -> Result<Vec<i64>, String> {
    let mut out = Vec::new();
    for e in arrival_points()? {
        if let Some(id) = location_id(&e) {
            out.push(id);
        }
    }
    Ok(out)
}

/// The game's one copy of a class: its static `instance`.
fn one_copy(class: &str) -> Result<MonoObject, String> {
    live_one_copy(class).ok_or_else(|| format!("{class}.instance is null or destroyed"))
}

/// The one copy, unless it is null or destroyed (the shim names a destroyed
/// Unity object "<null>").
fn live_one_copy(class: &str) -> Option<MonoObject> {
    let ty = obj(invoke_static("System.Type", "GetType", &json!([format!("{class}, Assembly-CSharp")])).ok()?)?;
    let field = obj(ty.invoke("GetField", &json!(["instance"])).ok()?)?;
    let v = field.invoke("GetValue", &json!([null])).ok()?;
    if v.get("name").and_then(Json::as_str) == Some("<null>") {
        return None;
    }
    obj(v)
}

fn arrival_points() -> Result<Vec<MonoObject>, String> {
    let list = obj(one_copy("PlayerLevelEntrypoints")?.read_field("Entrypoints")?).ok_or("no Entrypoints list")?;
    let n = list.invoke("get_Count", &json!([]))?.as_i64().unwrap_or(0);
    let mut out = Vec::new();
    for i in 0..n {
        out.extend(obj(list.invoke("get_Item", &json!([i]))?));
    }
    Ok(out)
}

fn location_id(entry: &MonoObject) -> Option<i64> {
    obj(entry.read_field("Location").ok()?)?.invoke("GetInstanceID", &json!([])).ok()?.as_i64()
}

extern "C" fn on_door(ctx: *const c_void) -> i32 {
    let h = ctx as isize as i32;
    if h == 0 {
        return 0;
    }
    let door = owned_object(h);
    match door_into_loaded_area(&door) {
        Ok(true) => 1,
        _ => 0,
    }
}

/// True when the door's destination is a loaded area and the player was
/// moved to its arrival point.
fn door_into_loaded_area(door: &MonoObject) -> Result<bool, String> {
    let to = door.read_field("OtherLevel")?.as_str().unwrap_or("").to_string();
    let arrival = door.read_field("OtherEntrypoint")?.as_str().unwrap_or("").to_string();
    let Some(ids) = AREAS.lock().unwrap().get(&to).cloned() else {
        return Ok(false);
    };
    let start = std::time::Instant::now();
    for e in arrival_points()? {
        let name = e.read_field("Name")?.as_str().unwrap_or("").to_string();
        if name != arrival || !location_id(&e).is_some_and(|id| ids.contains(&id)) {
            continue;
        }
        switch_area(&to, true)?;
        e.invoke("TeleportPlayer", &json!([]))?;
        let from = CURRENT.lock().unwrap().replace(to.clone());
        if let Some(from) = from.filter(|f| *f != to) {
            switch_area(&from, false)?;
        }
        // DoorChangelevel.OpenDoor disabled the controls for this door
        // before calling ChangeLevel (DoorChangelevel.cs:206); a scene
        // load would have thrown that away, the move does not.
        let door_object = obj(door.invoke("get_gameObject", &json!([]))?).ok_or("door has no game object")?;
        one_copy("GameController")?.invoke("ControlsEnabled", &json!([{"handle": door_object.handle().0}, false]))?;
        plan_neighbours();
        let secs = start.elapsed().as_secs_f64();
        crate::deposit::notify("Areas", &format!("No loading screen ({secs:.2}s)"));
        let from = door.invoke("get_name", &json!([]))?.as_str().unwrap_or("?").to_string();
        TRIPS.lock().unwrap().push(format!("{from} to {to}/{arrival} ({secs:.3}s)"));
        return Ok(true);
    }
    TRIPS.lock().unwrap().push(format!("no arrival point {arrival} in {to}; normal door"));
    Ok(false)
}

/// Switches an area's top objects on or off (SceneTools.RootsOf in the
/// shim). Never switches on what first_copy_wins switched off (the area's
/// own game logic, player and pause menu), and never switches off the top
/// objects of the live player and managers.
fn switch_area(area: &str, on: bool) -> Result<(), String> {
    let roots = obj(invoke_static("Unityforge.Shim.SceneTools", "RootsOf", &json!([area]))?)
        .ok_or_else(|| format!("no top objects for {area}"))?;
    let never_on = first_copy_wins::switched_off_ids();
    let keep = if on { Vec::new() } else { live_roots() };
    let n = roots.read_field("Length")?.as_i64().unwrap_or(0);
    for i in 0..n {
        let Some(root) = obj(roots.invoke("GetValue", &json!([i]))?) else { continue };
        let Some(id) = root.invoke("GetInstanceID", &json!([]))?.as_i64() else { continue };
        if never_on.contains(&id) || keep.contains(&id) {
            continue;
        }
        // An area's screenshot cameras: on in the outdoor area, and drawn
        // over the player's camera (research_cameras.rs).
        if on && root.invoke("get_name", &json!([]))?.as_str() == Some(SCREENSHOT_ROOT) {
            continue;
        }
        root.invoke("SetActive", &json!([on]))?;
    }
    Ok(())
}

/// Top objects holding the live player and managers.
fn live_roots() -> Vec<i64> {
    first_copy_wins::PLAYER_SETUP
        .iter()
        .filter_map(|class| {
            let t = obj(one_copy(class).ok()?.invoke("get_transform", &json!([])).ok()?)?;
            let root = obj(t.invoke("get_root", &json!([])).ok()?)?;
            obj(root.invoke("get_gameObject", &json!([])).ok()?)?.invoke("GetInstanceID", &json!([])).ok()?.as_i64()
        })
        .collect()
}

fn obj(v: Json) -> Option<MonoObject> {
    json_handle(&v).map(owned_object)
}
