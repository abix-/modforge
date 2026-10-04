//! Areas kept loaded, and doors between them without a loading screen
//! (operator 2026-10-02; design and its history in docs/kept-areas.md).
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
use unityforge::hook::{Hook, HookCtx, patch_prefix_ctx, patch_prefix_instance_args};
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
/// Area -> ids of the top objects the area swap switched off (and only
/// those are switched back on).
static SWAPPED_OFF: Mutex<BTreeMap<String, Vec<i64>>> = Mutex::new(BTreeMap::new());
/// Every area's top object holding its screenshot cameras
/// (research_area_player_setup.rs); never switched on by the area swap.
const SCREENSHOT_ROOT: &str = "___Screenshot Taking Stuff";

pub fn install() {
    // Design step 4: after every game save, the areas kept loaded are
    // written too.
    match unityforge::hook::patch_postfix("SaveController", "SaveGame", on_save_done) {
        Ok(h) => unityforge::hook::HOOK_REGISTRY.register(h),
        Err(e) => unityforge::mono::log(unityforge::mono::LogLevel::Error, &format!("obenseuer-mod: kept_loaded: SaveGame patch failed: {e}")),
    }
    // The door patch, once at mod start (Harmony patches cost what they
    // cost; patch once at start, as first_copy_wins does). It was put on
    // after the first area loaded alongside, so the first door after a
    // save load was the game's normal load. It does nothing with kept
    // areas off.
    match patch_prefix_ctx("Changelevel", "ChangeLevel", HookCtx::Instance, on_door) {
        Ok(h) => *DOOR_HOOK.lock().unwrap() = Some(h),
        Err(e) => unityforge::mono::log(unityforge::mono::LogLevel::Error, &format!("obenseuer-mod: kept_loaded: door patch failed: {e}")),
    }
    // Followers (docs/kept-areas.md, rule 1, which copy): the player's area
    // for them is the area the player is in.
    match patch_prefix_instance_args("NPC.NPCSceneUtilities", "OnFollowingTarget", on_following_target) {
        Ok(h) => unityforge::hook::HOOK_REGISTRY.register(h),
        Err(e) => unityforge::mono::log(unityforge::mono::LogLevel::Error, &format!("obenseuer-mod: kept_loaded: follower patch failed: {e}")),
    }
    OP_REGISTRY.register(OpDef::new(
        "load_alongside",
        "Load an area alongside the current one; its doors and the current area's doors then move the player without a loading screen",
        r#"{"area": "Interior Tenement Gatehouse", "auto": true}  (omit both to only read; auto sets the kept_loaded.auto setting, saved)"#,
        |args| {
            let area = args.get("area").and_then(Json::as_str).map(String::from);
            if let Some(auto) = args.get("auto").and_then(Json::as_bool) {
                crate::settings::get().update(|s| s.kept_loaded.auto = auto);
            }
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
    SWAPPED_OFF.lock().unwrap().clear();
    DATA_APPLIED.lock().unwrap().clear();
    *HOME.lock().unwrap() = None;
    for (_, (l, g)) in std::mem::take(&mut *CAPTURED.lock().unwrap()) {
        drop(owned_object(l)); // release the kept handles
        drop(owned_object(g));
    }
    *CURRENT.lock().unwrap() = None;
    if let Some(d) = PENDING_DOOR.lock().unwrap().take() {
        drop(owned_object(d.door_object)); // release the kept handle
    }
    set_loading_priority(None);
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
        // The game loaded this area's saved data itself, and its scene holds
        // the live player and managers.
        DATA_APPLIED.lock().unwrap().extend(area.clone());
        *HOME.lock().unwrap() = area.clone();
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
    if cfg.max_areas > 0 && kept >= cfg.max_areas {
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

/// The game process's memory in use (its working set), e.g. "4.8 GB", from
/// Windows: the game's Mono reports 0 for Process.WorkingSet64.
fn game_memory() -> String {
    #[repr(C)]
    #[derive(Default)]
    struct ProcessMemoryCounters {
        cb: u32,
        page_fault_count: u32,
        peak_working_set_size: usize,
        working_set_size: usize,
        quota_peak_paged_pool_usage: usize,
        quota_paged_pool_usage: usize,
        quota_peak_non_paged_pool_usage: usize,
        quota_non_paged_pool_usage: usize,
        pagefile_usage: usize,
        peak_pagefile_usage: usize,
    }
    #[link(name = "kernel32")]
    unsafe extern "system" {
        fn GetCurrentProcess() -> isize;
        fn K32GetProcessMemoryInfo(process: isize, counters: *mut ProcessMemoryCounters, cb: u32) -> i32;
    }
    let mut c = ProcessMemoryCounters { cb: std::mem::size_of::<ProcessMemoryCounters>() as u32, ..Default::default() };
    // SAFETY: c is a ProcessMemoryCounters of the size passed; the pseudo
    // handle needs no closing.
    let ok = unsafe { K32GetProcessMemoryInfo(GetCurrentProcess(), &mut c, c.cb) };
    if ok == 0 { "?".into() } else { format!("{:.2} GB", c.working_set_size as f64 / 1073741824.0) }
}

/// The game's background loading priority before the mod lowered it.
static PREVIOUS_PRIORITY: Mutex<Option<Json>> = Mutex::new(None);

/// Background loading's time per frame: Low (2 ms) while an area loads
/// alongside, so play stays smooth; the game's own value (its loading
/// screen loads fast) when nothing is loading alongside. Unity:
/// Application.backgroundLoadingPriority.
/// `Some(level)`: Unity ThreadPriority name, "Low" for background loads,
/// "High" for a door waiting behind the loading screen. `None`: the
/// game's own value back once nothing loads alongside.
fn set_loading_priority(level: Option<&str>) {
    const APP: &str = "UnityEngine.Application";
    let mut previous = PREVIOUS_PRIORITY.lock().unwrap();
    if let Some(level) = level {
        if previous.is_none() {
            *previous = invoke_static(APP, "get_backgroundLoadingPriority", &json!([])).ok();
        }
        let _ = invoke_static(APP, "set_backgroundLoadingPriority", &json!([level]));
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
        first_copy_wins::take_prefix_secs();
        let before = arrival_point_ids()?;
        let current = invoke_static("UnityEngine.Application", "get_loadedLevelName", &json!([]))?
            .as_str()
            .map(String::from)
            .ok_or("no current area name")?;
        AREAS.lock().unwrap().entry(current.clone()).or_insert_with(|| before.clone());
        CURRENT.lock().unwrap().get_or_insert(current);
        set_loading_priority(Some("Low"));
        // Nothing in the area starts until the player walks in: the shim
        // switches its top objects off in sceneLoaded, before any Start
        // (an area's start sequence ran and left the screen black, docs
        // "Black screen from an area loaded alongside").
        invoke_static("Unityforge.Shim.SceneTools", "LoadQuietly", &json!([area]))?;
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
        // Loaded but switched off until the player walks in (areas can be
        // built in the same place, the player's building inside and out):
        // the shim switched it off before any Start (LoadQuietly). Record
        // what it switched off, so walking in switches exactly that on.
        let switching = std::time::Instant::now();
        let off = taken_switched_off(&area);
        SWAPPED_OFF.lock().unwrap().insert(area.clone(), off);
        let switching = switching.elapsed().as_secs_f64();
        // No area names on screen: they would spoil places not found yet.
        crate::deposit::notify("Areas", "Nearby area ready");
        let load = LOAD_STARTED.lock().unwrap().take().map_or(0.0, |t| t.elapsed().as_secs_f64());
        unityforge::mono::log(
            unityforge::mono::LogLevel::Info,
            &format!(
                "obenseuer-mod: kept_loaded: {area} ready: load {load:.2}s, longest frame while loading {:.3}s (first_copy_wins prefix {:.3}s of the load), switching it off {switching:.3}s, game memory {}",
                *LONGEST_FRAME.lock().unwrap(),
                first_copy_wins::take_prefix_secs(),
                game_memory()
            ),
        );
        set_loading_priority(None);
        AREAS.lock().unwrap().insert(area.clone(), new);
        // A door waiting for this area moves the player in one frame later:
        // the area's player setup is switched off by jobs its Awakes queued
        // (first_copy_wins switch_off_top_next_frame), which run after this
        // one. Moving in now switched its Game_Logic on for a frame (a
        // MoneyPanel.OnDisable error in the first-door-at-once check).
        MAIN_QUEUE.push(move || finish_pending_door(&area));
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

/// The area an arrival point's location is in; None when it is destroyed.
fn location_area(entry: &MonoObject) -> Option<String> {
    let location = obj(entry.read_field("Location").ok()?)?;
    let area = invoke_static("Unityforge.Shim.SceneTools", "SceneOf", &json!([{"handle": location.handle().0}])).ok()?;
    area.as_str().filter(|a| !a.is_empty()).map(String::from)
}

fn location_id(entry: &MonoObject) -> Option<i64> {
    obj(entry.read_field("Location").ok()?)?.invoke("GetInstanceID", &json!([])).ok()?.as_i64()
}

/// Prefix on `NPCSceneUtilities.OnFollowingTarget(npc, followTarget)`
/// (NPCSceneUtilities.cs:11-20): the game takes the player's area from the
/// follow target's scene, and the live player stays in the scene the save
/// loaded into. When the target is switched on in another scene than the
/// active one (the live player away from that area), the method's own
/// steps run with the area the player is in and the original is skipped;
/// otherwise the original runs.
extern "C" fn on_following_target(_instance: *const c_void, args: *const std::os::raw::c_char) -> i32 {
    if args.is_null() || !crate::settings::get().get().kept_loaded.auto {
        return 0;
    }
    let text = unsafe { std::ffi::CStr::from_ptr(args) }.to_string_lossy().into_owned();
    let Ok(Json::Array(a)) = serde_json::from_str::<Json>(&text) else { return 0 };
    // The callback owns the argument handles.
    let npc = a.first().and_then(json_handle).map(owned_object);
    let target = a.get(1).and_then(json_handle).map(owned_object);
    match (npc, target) {
        (Some(npc), Some(target)) => follow_in_players_area(&npc, &target).unwrap_or(0),
        _ => 0,
    }
}

fn follow_in_players_area(npc: &MonoObject, target: &MonoObject) -> Result<i32, String> {
    let scene = invoke_static("Unityforge.Shim.SceneTools", "SceneOf", &json!([{"handle": target.handle().0}]))?;
    let active = invoke_static("UnityEngine.Application", "get_loadedLevelName", &json!([]))?;
    if scene == active || target.invoke("get_activeInHierarchy", &json!([]))?.as_bool() != Some(true) {
        return Ok(0);
    }
    let active = active.as_str().unwrap_or("").to_string();
    let state = obj(npc.read_field("state")?).ok_or("NPC has no state")?;
    let on_path = !state.read_field("activePath")?.is_null();
    let heading_here = state.read_field("targetScene")?.as_str() == Some(active.as_str());
    if state.read_field("currentScene")?.as_str() != Some(active.as_str()) && !(on_path && heading_here) {
        let entry = state.read_field("targetEntrypoint")?;
        invoke_static("NPC.NPCSceneUtilities", "CalculateNPCTransition", &json!([{"handle": npc.handle().0}, active, entry]))?;
    }
    Ok(1)
}

extern "C" fn on_door(ctx: *const c_void) -> i32 {
    let h = ctx as isize as i32;
    // Kept areas off: the game's own door.
    if h == 0 || !crate::settings::get().get().kept_loaded.auto {
        return 0;
    }
    let door = owned_object(h);
    match door_into_loaded_area(&door) {
        Ok(true) => 1,
        Ok(false) => 0,
        Err(e) => {
            // The game's own door runs: a normal load that unloads every
            // kept area. Say why.
            unityforge::mono::log(unityforge::mono::LogLevel::Warn, &format!("obenseuer-mod: kept_loaded: door failed, normal load instead: {e}"));
            0
        }
    }
}

/// True when the door's destination is a loaded area and the player was
/// moved to its arrival point.
fn door_into_loaded_area(door: &MonoObject) -> Result<bool, String> {
    let to = door.read_field("OtherLevel")?.as_str().unwrap_or("").to_string();
    let arrival = door.read_field("OtherEntrypoint")?.as_str().unwrap_or("").to_string();
    if to.is_empty() {
        return Ok(false);
    }
    let door_object = obj(door.invoke("get_gameObject", &json!([]))?).ok_or("door has no game object")?;
    let door_name = door.invoke("get_name", &json!([]))?.as_str().unwrap_or("?").to_string();
    if AREAS.lock().unwrap().contains_key(&to) {
        return move_into(&to, &arrival, &door_object, &door_name);
    }
    // Not loaded yet: load it alongside at full speed behind the game's
    // loading screen and move in when it is ready. Never the game's normal
    // load, which would unload every area (operator 2026-10-02: areas stay
    // loaded once seen).
    let screen = one_copy("LoadingScreen")?;
    screen.invoke("Fade", &json!([true, true, 0.0, true, ""]))?;
    let handle = door_object.handle().0;
    std::mem::forget(door_object); // the pending move takes it over
    *PENDING_DOOR.lock().unwrap() = Some(PendingDoor { to: to.clone(), arrival, door_object: handle, door_name });
    if !LOADING.lock().unwrap().contains(&to) {
        load_alongside(Some(to.clone()))?;
    }
    set_loading_priority(Some("High"));
    unityforge::mono::log(unityforge::mono::LogLevel::Info, &format!("obenseuer-mod: kept_loaded: door into {to}, not loaded yet: loading it behind the loading screen"));
    Ok(true)
}

/// A door used into an area still loading: moved into when it is ready.
struct PendingDoor {
    to: String,
    arrival: String,
    door_object: i32,
    door_name: String,
}

static PENDING_DOOR: Mutex<Option<PendingDoor>> = Mutex::new(None);

/// After `area` finished loading: a door waiting for it moves the player in
/// and the loading screen fades.
fn finish_pending_door(area: &str) {
    let pending = {
        let mut p = PENDING_DOOR.lock().unwrap();
        if p.as_ref().is_some_and(|d| d.to == area) { p.take() } else { None }
    };
    let Some(d) = pending else { return };
    let door_object = owned_object(d.door_object);
    let moved = move_into(&d.to, &d.arrival, &door_object, &d.door_name);
    if !matches!(moved, Ok(true)) {
        unityforge::mono::log(unityforge::mono::LogLevel::Warn, &format!("obenseuer-mod: kept_loaded: move into {area} failed: {moved:?}"));
        // The door disabled the controls (DoorChangelevel.cs:206): give them back.
        if let Ok(game) = one_copy("GameController") {
            let _ = game.invoke("ControlsEnabled", &json!([{"handle": door_object.handle().0}, false]));
        }
    }
    if let Ok(screen) = one_copy("LoadingScreen") {
        let _ = screen.invoke("Fade", &json!([false, true, 0.0, false, ""]));
    }
}

/// Moves the player into a loaded area at its arrival point `arrival`:
/// that area becomes the active scene and switches on, the player is
/// teleported, the area left switches off.
fn move_into(to: &str, arrival: &str, door_object: &MonoObject, door_name: &str) -> Result<bool, String> {
    let to = to.to_string();
    if !AREAS.lock().unwrap().contains_key(&to) {
        return Ok(false);
    }
    let start = std::time::Instant::now();
    // The door's arrival point, from the area's own PlayerLevelEntrypoints
    // (its arrival points; docs/kept-areas.md rule 1, which copy). Found
    // before anything changes: with none, the game's normal load runs.
    let Some(point) = arrival_point(&to, arrival)? else {
        TRIPS.lock().unwrap().push(format!("no arrival point {arrival} in {to}"));
        return Ok(false);
    };
    // The door as the game's (docs/kept-areas.md, the door): rule 3's steps
    // on the area left while it is on, the player moves out to the arrival
    // point, and after a physics step (its zones see the player leave) the
    // area switches off and rule 2 runs on the area entered.
    let from = CURRENT.lock().unwrap().clone().filter(|f| *f != to);
    let steps = from.as_ref().map(|f| leave_steps(f));
    point.invoke("TeleportPlayer", &json!([]))?;
    let fixed = invoke_static("UnityEngine.Time", "get_fixedTime", &json!([]))?.as_f64().unwrap_or(0.0);
    // A handle of its own for the job below (the caller releases its own);
    // the job takes it over.
    let held = obj(door_object.invoke("get_gameObject", &json!([]))?).ok_or("door has no game object")?;
    let door = held.handle().0;
    std::mem::forget(held);
    let moved = Moved { from, to, arrival: arrival.to_string(), door, door_name: door_name.to_string(), start, steps: format!("{steps:?}") };
    after_physics_step(moved, fixed);
    Ok(true)
}

/// A door move waiting for a physics step.
struct Moved {
    from: Option<String>,
    to: String,
    arrival: String,
    door: i32,
    door_name: String,
    start: std::time::Instant,
    steps: String,
}

/// Once Unity has run a physics step since `fixed` (its zones saw the
/// player leave the area), the area left switches off and the area
/// entered switches on.
fn after_physics_step(moved: Moved, fixed: f64) {
    MAIN_QUEUE.push(move || {
        let now = invoke_static("UnityEngine.Time", "get_fixedTime", &json!([])).ok().and_then(|v| v.as_f64()).unwrap_or(fixed + 1.0);
        if now <= fixed {
            after_physics_step(moved, fixed);
            return;
        }
        let door_object = owned_object(moved.door);
        if let Some(from) = &moved.from {
            let off = leave_finish(from);
            unityforge::mono::log(unityforge::mono::LogLevel::Info, &format!("obenseuer-mod: kept_loaded: left {from}: {}, {off:?}", moved.steps));
        }
        if let Err(e) = enter_area(&moved.to) {
            unityforge::mono::log(unityforge::mono::LogLevel::Warn, &format!("obenseuer-mod: kept_loaded: entering {} failed: {e}", moved.to));
        }
        // DoorChangelevel.OpenDoor disabled the controls for this door
        // before calling ChangeLevel (DoorChangelevel.cs:206); a scene load
        // would have thrown that away, the move does not.
        if let Ok(game) = one_copy("GameController") {
            let _ = game.invoke("ControlsEnabled", &json!([{"handle": door_object.handle().0}, false]));
        }
        plan_neighbours();
        let secs = moved.start.elapsed().as_secs_f64();
        crate::deposit::notify("Areas", &format!("No loading screen ({secs:.2}s)"));
        TRIPS.lock().unwrap().push(format!("{} to {}/{} ({secs:.3}s)", moved.door_name, moved.to, moved.arrival));
    });
}

/// Rule 2 (docs/kept-areas.md): entering an area, the game's own steps
/// after a load (SaveController.cs:640-664) in the table's order. Steps 1,
/// 2 and 10 now; 3, 4 and 6 the next frame (after the area's objects
/// started, as in a normal load); 8, 9 and 12 the frame after.
fn enter_area(area: &str) -> Result<(), String> {
    // Step 2 before the switch-on of step 1, as in a load (Awake sets
    // `instance` before OnEnable): its area-owned managers are the game's,
    // so one that checks `instance` in OnEnable finds itself.
    invoke_static("Unityforge.Shim.FirstCopyGuard", "EnterArea", &json!([area]))?;
    // Its navigation, before it switches on (docs/kept-areas.md, rule 1,
    // which copy): in the game a new area's pathfinder holds its map from
    // the start; loaded a frame later, animals got paths on the previous
    // area's map.
    let nav = load_navigation(area);
    if let Err(e) = &nav {
        unityforge::mono::log(unityforge::mono::LogLevel::Warn, &format!("obenseuer-mod: kept_loaded: {area}: navigation: {e}"));
    }
    // The sound starts from nothing, as the game's rebuilt
    // SoundscapeController does (docs/sound.md), before the area's objects
    // start and pick their sound.
    if let Err(e) = fresh_sound() {
        unityforge::mono::log(unityforge::mono::LogLevel::Warn, &format!("obenseuer-mod: kept_loaded: {area}: sound: {e}"));
    }
    // Step 1: the area is the active scene (objects the game creates go
    // into it) and switches on: its objects start.
    invoke_static("Unityforge.Shim.SceneTools", "SetActive", &json!([area]))?;
    switch_area(area, true)?;
    // The waypoint graph from its switched-on waypoints (the navigation
    // file went in before switching on).
    if nav.is_ok() {
        if let Err(e) = map_waypoints() {
            unityforge::mono::log(unityforge::mono::LogLevel::Warn, &format!("obenseuer-mod: kept_loaded: {area}: waypoints: {e}"));
        }
    }
    // Step 10 (the player at the arrival point) is done by the door before
    // the area left switches off (docs/kept-areas.md, the door).
    *CURRENT.lock().unwrap() = Some(area.to_string());
    let area = area.to_string();
    MAIN_QUEUE.push(move || {
        // The frame its objects start. On a later visit, the area-owned
        // managers whose Start pushes the area's settings into the live
        // set run it again, as on every visit in the game (Unity runs Start
        // once; on the first visit Unity runs it): info_game_logic (sky,
        // radiation), SoundscapeGlobal (the area's sound). Then the
        // handlers taken out when it was left go back (docs/kept-areas.md,
        // rule 1, which copy and game-wide events).
        let later = DATA_APPLIED.lock().unwrap().iter().any(|a| *a == area);
        let mut subscribed_again = Vec::new();
        if later {
            for (class, method, subscribes) in RUN_AGAIN {
                if let Err(e) = invoke_static("Unityforge.Shim.SceneTools", "RunAgain", &json!([area, "Inventory, Assembly-CSharp", class, method])) {
                    unityforge::mono::log(unityforge::mono::LogLevel::Warn, &format!("obenseuer-mod: kept_loaded: {area}: {class}.{method} failed: {e}"));
                }
                if !subscribes.is_empty() {
                    subscribed_again.push(*subscribes);
                }
            }
            if let Err(e) = build_space_again(&area) {
                unityforge::mono::log(unityforge::mono::LogLevel::Warn, &format!("obenseuer-mod: kept_loaded: {area}: build space: {e}"));
            }
        }
        if let Err(e) = map_again() {
            unityforge::mono::log(unityforge::mono::LogLevel::Warn, &format!("obenseuer-mod: kept_loaded: {area}: map: {e}"));
        }
        let back = invoke_static("Unityforge.Shim.EventTools", "EnterArea", &json!([area, subscribed_again.join(",")]));
        // Step 3, then 4 and 6 on the first visit.
        let started = fire_save_event("LoadingStarted");
        let data = saved_data_first_frame(&area);
        MAIN_QUEUE.push(move || {
            // Step 7 was the frame between; 8 on the first visit, 9, 12.
            let rest = saved_data_next_frame(&area);
            // Its list entries back, after its load steps (a timer's
            // OnLoading puts itself back with the time passed).
            let entries = invoke_static("Unityforge.Shim.EventTools", "EnterAreaLists", &json!([area]));
            let changed = area_change_phase(&area, "OnMapChanged");
            let done = fire_save_event("LoadingDone");
            unityforge::mono::log(
                unityforge::mono::LogLevel::Info,
                &format!(
                    "obenseuer-mod: kept_loaded: entered {area}: event handlers back {back:?}, list entries back {entries:?}, LoadingStarted {started:?}, saved data {data:?} {rest:?}, OnMapChanged {changed:?}, LoadingDone {done:?}"
                ),
            );
        });
    });
    Ok(())
}

/// The arrival point named `arrival` in `area`'s own PlayerLevelEntrypoints
/// list whose location is a live object in that area. Not ids recorded when
/// the area loaded: the game re-creates a door during play and its Awake
/// adds a fresh arrival point (Changelevel.cs:49), and a recorded one went
/// stale (second visit to Open Sewer Tenement). None, logged, when there is
/// no such point.
fn arrival_point(area: &str, arrival: &str) -> Result<Option<MonoObject>, String> {
    let own = obj(invoke_static("Unityforge.Shim.FirstCopyGuard", "AreaCopy", &json!(["PlayerLevelEntrypoints", area]))?)
        .ok_or_else(|| format!("no PlayerLevelEntrypoints in {area}"))?;
    let list = obj(own.read_field("Entrypoints")?).ok_or("no Entrypoints list")?;
    let n = list.invoke("get_Count", &json!([]))?.as_i64().unwrap_or(0);
    let mut named = Vec::new();
    for i in 0..n {
        let Some(e) = obj(list.invoke("get_Item", &json!([i]))?) else { continue };
        if e.read_field("Name")?.as_str() != Some(arrival) {
            continue;
        }
        let at = location_area(&e);
        if at.as_deref() == Some(area) {
            return Ok(Some(e));
        }
        named.push(format!("in {:?}", at.unwrap_or_default()));
    }
    unityforge::mono::log(
        unityforge::mono::LogLevel::Warn,
        &format!("obenseuer-mod: kept_loaded: no arrival point {arrival} in {area}, normal load instead; its list: {n} arrival points, named {arrival}: {named:?}"),
    );
    Ok(None)
}

/// Switches an area's top objects on or off (SceneTools.RootsOf in the
/// shim). Never switches on what first_copy_wins switched off (the area's
/// own game logic, player and pause menu), and never switches off the top
/// objects of the live player and managers.
fn switch_area(area: &str, on: bool) -> Result<(), String> {
    let never_on = first_copy_wins::switched_off_ids();
    let keep = if on { Vec::new() } else { live_roots() };
    // Switching on restores only what the swap switched off: the game
    // keeps some top objects off itself ("Test", "_LIGHT_BLOCKERS" in the
    // player's building; research_areas_on.rs), and switching everything
    // on put their strangers in the lobby.
    let was_on = if on { SWAPPED_OFF.lock().unwrap().remove(area).unwrap_or_default() } else { Vec::new() };
    if on {
        // Its objects start now; their OnDestroy runs again (first_copy_wins).
        invoke_static("Unityforge.Shim.SceneTools", "Entered", &json!([area]))?;
    }
    let mut turned_off = Vec::new();
    for root in roots(area)? {
        let Some(id) = root.invoke("GetInstanceID", &json!([]))?.as_i64() else { continue };
        if never_on.contains(&id) || keep.contains(&id) {
            continue;
        }
        if on {
            // An area's screenshot cameras: on in the outdoor area, and
            // drawn over the player's camera (research_cameras.rs).
            if was_on.contains(&id) && root.invoke("get_name", &json!([]))?.as_str() != Some(SCREENSHOT_ROOT) {
                root.invoke("SetActive", &json!([true]))?;
            }
        } else if root.invoke("get_activeSelf", &json!([]))?.as_bool() == Some(true) {
            root.invoke("SetActive", &json!([false]))?;
            turned_off.push(id);
        }
    }
    if !on {
        SWAPPED_OFF.lock().unwrap().entry(area.to_string()).or_default().extend(turned_off);
    }
    Ok(())
}

/// Areas whose saved data went in since the last normal load.
static DATA_APPLIED: Mutex<Vec<String>> = Mutex::new(Vec::new());

/// Design step 2 (docs/kept-areas.md, history, "Proper design"): the area's
/// saved data goes into its objects as LoadSaveGameDifferentScene does
/// (SaveController.cs:641-654), once per normal load, the frame after the
/// area switched on (a normal load starts the objects first and loads the
/// data the next frame, question 1). Reads `<area>.tnmt` and `Globals.tnmt`
/// from the save folder the game last loaded or saved, with the game's own
/// Deserialize, into the game's temp lists, then runs the load phases and
/// OnMapChanged on the area's top objects.
/// The first frame of it (SaveController.cs:641-643): the files read into
/// the game's temp lists, the Primary to Tertiary phases.
fn saved_data_first_frame(area: &str) -> Result<String, String> {
    if DATA_APPLIED.lock().unwrap().iter().any(|a| a == area) {
        // A later visit: in the game every visit is a fresh load, so its
        // load steps run every time (docs/kept-areas.md, rule 2). The data
        // is what the area held when it was left: the entries captured then
        // hold its live objects (rule 3), so the steps restore nothing stale
        // and do their work (delayed outputs restarted, door locks synced,
        // relays fired on load...). The DestructibleList steps and the steps
        // that create objects are not run: those objects are still there.
        let entries = fill_from_captured(area)?;
        for phase in ["OnLoadingGamePrimary", "OnLoadingGameSecondary", "OnLoadingGameTertiary"] {
            run_phase(area, phase, true)?;
        }
        return Ok(format!("{entries} area entries captured when it was left"));
    }
    let folder = save_static("LastSaveFolderPath")?.as_str().map(String::from).ok_or("no save folder yet")?;
    let header_type = obj(invoke_static("System.Type", "GetType", &json!(["SaveController+SaveDataHeader, Assembly-CSharp"]))?)
        .ok_or("SaveDataHeader type not found")?;
    let read = |file: &str| -> Result<Option<MonoObject>, String> {
        let path = format!("{folder}/{file}");
        let Ok(text) = std::fs::read_to_string(&path) else { return Ok(None) };
        // The game's files start with a UTF-8 byte order mark, which its
        // own reader (SaveController.ReadSaveFile, File.ReadAllText) drops
        // and its parser rejects ("invalid token"). Read here, not through
        // ReadSaveFile: its 2 MB result would not fit the bridge's return
        // buffer.
        let text = text.trim_start_matches('\u{feff}');
        let header = invoke_static("SaveController", "Deserialize", &json!([file, {"handle": header_type.handle().0}, text, null]))?;
        Ok(obj(header).and_then(|h| obj(h.read_field("Data").ok()?)))
    };
    let level = read(&format!("{area}.tnmt"))?;
    let globals = read("Globals.tnmt")?;
    let entries = level.as_ref().and_then(|l| l.invoke("get_Count", &json!([])).ok()?.as_i64()).unwrap_or(0);
    set_save_static("tempSavedata_Level", level.as_ref())?;
    set_save_static("tempSavedata_Global", globals.as_ref())?;
    for phase in ["OnLoadingGamePrimary", "OnLoadingGameSecondary", "OnLoadingGameTertiary"] {
        run_phase(area, phase, false)?;
    }
    // Step 6 (644 is step 5, not run): the area's DestructibleList (the
    // game's since step 2) restores dropped items, then the check that
    // removes destroyed map items, over switched-off objects too (645-646).
    let list = one_copy("DestructibleList")?;
    list.invoke("OnLoadingGameDestructibleList", &json!([]))?;
    run_phase(area, "OnLoadingGameDestructibleListCheck", false)?;
    Ok(format!("{entries} area entries from {area}.tnmt"))
}

/// The next frame (SaveController.cs:647-649, 660-661): OnLoadingGame and
/// LatePrimary from the same temp lists, then the lists cleared.
fn saved_data_next_frame(area: &str) -> Result<(), String> {
    let again = DATA_APPLIED.lock().unwrap().iter().any(|a| a == area);
    for phase in ["OnLoadingGame", "OnLoadingGameLatePrimary"] {
        run_phase(area, phase, again)?;
    }
    // Step 8: the check again (650), on the first visit.
    if !again {
        run_phase(area, "OnLoadingGameDestructibleListCheck", false)?;
    }
    for name in ["tempSavedata_Level", "tempSavedata_Global"] {
        if let Some(list) = obj(save_static(name)?) {
            list.invoke("Clear", &json!([]))?;
        }
    }
    if !again {
        DATA_APPLIED.lock().unwrap().push(area.to_string());
    }
    Ok(())
}

/// The game's temp lists filled with the entries captured when the player
/// left `area` (rule 3), for its load steps on a later visit. Returns how
/// many area entries.
fn fill_from_captured(area: &str) -> Result<i64, String> {
    let (level_entries, global_entries) = CAPTURED.lock().unwrap().get(area).copied().ok_or_else(|| format!("nothing captured for {area}"))?;
    let level = obj(save_static("tempSavedata_Level")?).ok_or("no level list")?;
    let global = obj(save_static("tempSavedata_Global")?).ok_or("no global list")?;
    level.invoke("Clear", &json!([]))?;
    global.invoke("Clear", &json!([]))?;
    level.invoke("AddRange", &json!([{"handle": level_entries}]))?;
    global.invoke("AddRange", &json!([{"handle": global_entries}]))?;
    Ok(level.invoke("get_Count", &json!([]))?.as_i64().unwrap_or(0))
}

/// One of the game's save or load phases (SaveController.LoadSaveType) on
/// an area's top objects, as the game's ExecuteSaveLoadFunctions calls them
/// (every SavableScript under them whose object is on,
/// SaveController.cs:1113-1198; the shim's EventTools.RunStep). `again`: a
/// load phase on a later visit, which skips the classes whose step creates
/// objects and the live player and managers (not the area's content; in
/// the area the save loaded) (docs/kept-areas.md, rule 2).
fn run_phase(area: &str, phase: &str, again: bool) -> Result<(), String> {
    let skip = if again { CREATES_OBJECTS } else { "" };
    invoke_static("Unityforge.Shim.EventTools", "RunStep", &json!(["Inventory, Assembly-CSharp", area, phase, "", skip, again]))?;
    Ok(())
}

/// Classes whose load step creates objects (docs/save.md, load steps that
/// create objects): on a later visit those objects are still there.
const CREATES_OBJECTS: &str = "CollectibleItemSpawner,FurnitureBlueprintSpawner,FurnitureManager,ParcelLocker,RatFightArena";

/// The area the save loaded into: its scene holds the live player and
/// managers (Game_Logic, Player...), switched on wherever the player is.
static HOME: Mutex<Option<String>> = Mutex::new(None);

/// An area-change phase (OnMapChanging, OnMapChanged) as a door runs it:
/// on the area, and on the home area (only its live player and managers
/// are on away from home: the NPC director and the rest live there, where
/// the game has them in the active area). The objects kept through scene
/// changes get OnMapChanging only, as in the game (SaveController.cs:446-447;
/// OnMapChanged runs on the active area alone, 653).
fn area_change_phase(area: &str, phase: &str) -> Result<(), String> {
    run_phase(area, phase, false)?;
    if let Some(home) = HOME.lock().unwrap().clone().filter(|h| h != area) {
        run_phase(&home, phase, false)?;
    }
    if phase == "OnMapChanging" {
        invoke_static("SaveController", "ExecuteDontDestroyOnLoadSaveLoadFunctions", &json!([phase]))?;
    }
    Ok(())
}

/// Fires one of SaveController's static events (PlayerWillChangeLevel:
/// stop sitting, stop climbing) the way the game does, when it has any
/// listener.
fn fire_save_event(name: &str) -> Result<(), String> {
    if let Some(handler) = obj(save_static(name)?) {
        handler.invoke("Invoke", &json!([]))?;
    }
    Ok(())
}

/// Area -> its save entries captured when the player left it, (area file,
/// global file), as arrays of the game's ObjectDataHeader; written at the
/// game's next save (design step 4). Handles kept alive here.
static CAPTURED: Mutex<BTreeMap<String, (i32, i32)>> = Mutex::new(BTreeMap::new());

/// Rule 3, step 11 (docs/kept-areas.md): after the player moved out and a
/// physics step passed, the area left switches off, not unloaded (always,
/// or it would stay on over the one entered: areas are built in the same
/// place), and its handlers on game-wide events are taken out as its unload
/// would (rule 1, game-wide events). Returns how many handlers.
fn leave_finish(area: &str) -> Result<String, String> {
    switch_area(area, false)?;
    // Every handler, the clock's too: in the game an area not loaded does
    // not run; its load steps catch it up from `savedTimeAndDay` (rule 2,
    // time while away).
    let out = invoke_static("Unityforge.Shim.EventTools", "LeaveArea", &json!(["Inventory, Assembly-CSharp", area, "", ""]))?;
    // Its objects (and timers calling back into them) out of the game-wide
    // lists, as its destruction would (rule 1, game-wide lists).
    let entries = invoke_static("Unityforge.Shim.EventTools", "LeaveAreaLists", &json!(["Inventory, Assembly-CSharp", area]))?;
    Ok(format!("event handlers out {out}, list entries out {entries}"))
}

/// The area's navigation file into the one pathfinder, as
/// info_navigation.LoadCO does (info_navigation.cs:85-111):
/// `AstarPath.active.data.DeserializeGraphs(bytes)`, then
/// `WaypointGraph.instance.MapWaypoints()`; its info_navigation is marked
/// loaded so its OnEnable does not load it again. Without a file, its
/// OnEnable does what the game does (rebuilds the map).
fn load_navigation(area: &str) -> Result<(), String> {
    let nav = obj(invoke_static("Unityforge.Shim.FirstCopyGuard", "AreaCopy", &json!(["info_navigation", area]))?);
    let assets = invoke_static("UnityEngine.Application", "get_streamingAssetsPath", &json!([]))?;
    let path = format!("{}/NavigationData/{area}.nav", assets.as_str().unwrap_or(""));
    let Some(bytes) = obj(invoke_static("Unityforge.Shim.FileTools", "ReadBytes", &json!([path]))?) else {
        if let Some(nav) = nav {
            nav.write_field("loaded", &json!(false))?;
        }
        return Ok(());
    };
    let ty = obj(invoke_static("System.Type", "GetType", &json!(["AstarPath, AstarPathfindingProject"]))?).ok_or("no AstarPath type")?;
    let field = obj(ty.invoke("GetField", &json!(["active"]))?).ok_or("no AstarPath.active")?;
    let astar = obj(field.invoke("GetValue", &json!([null]))?).ok_or("no live AstarPath")?;
    let data = obj(astar.read_field("data")?).ok_or("no pathfinder data")?;
    data.invoke("DeserializeGraphs", &json!([{"handle": bytes.handle().0}]))?;
    if let Some(nav) = nav {
        nav.write_field("loaded", &json!(true))?;
    }
    Ok(())
}

/// The NPC waypoint graph of the area the player is in, as info_navigation
/// .LoadCO does after the navigation file (info_navigation.cs:105):
/// `WaypointGraph.instance.MapWaypoints()`. It maps switched-on waypoints
/// only (FindObjectsOfType, docs/pathfinding.md), so it runs after the area
/// switched on.
fn map_waypoints() -> Result<(), String> {
    if let Some(waypoints) = obj(invoke_static("System.Type", "GetType", &json!(["NPC.WaypointGraph, Assembly-CSharp"]))?)
        .and_then(|t| obj(t.invoke("GetField", &json!(["instance"])).ok()?))
        .and_then(|f| obj(f.invoke("GetValue", &json!([null])).ok()?))
    {
        waypoints.invoke("MapWaypoints", &json!([]))?;
    }
    Ok(())
}

/// What area objects do in Start, which the game does on every load of the
/// area and Unity only once per object, run again on every later visit
/// (docs/kept-areas.md, rule 2), as (class, method; subclasses too):
/// - Start of area-owned managers that push the area's settings into the
///   live set: info_game_logic (sky, radiation), SoundscapeGlobal (sound),
///   NPCManager (reconciles the area's NPCs).
/// - Coroutines started in Start that run for good, stopped by Unity when
///   the area switched off.
/// - What fires at Start (docs/relays.md, when things fire): the relay
///   start delay (fires `triggerAtStart`; not Start: RelayTimer's would
///   restart its timer), and the Start of the relays whose Start only does
///   that.
/// - Shops (docs/economy.md, Trade): StartDelay fires the open or closed
///   relay for the hours (Trade.cs:224-237).
///
/// The third value names the handler ("Class.Method") the work subscribes
/// again, as a fresh object's does: the one taken out when the area was
/// left is not put back (EventTools.EnterArea), or it would be there twice.
const RUN_AGAIN: &[(&str, &str, &str)] = &[
    ("info_game_logic", "Start", ""),
    ("SoundscapeGlobal", "Start", "SoundscapeGlobal.DeltaSeconds"),
    ("NPCManager", "Start", ""),
    ("BottleRecyclingLights", "Blinking", ""),
    ("BottleRecyclingLightsUI", "Blinking", ""),
    ("PulseLight", "LightEffect", ""),
    ("RagdollAnimation", "StepTimer", ""),
    ("Relay", "StartDelay", ""),
    ("RelayAuto", "Start", ""),
    ("RelayDialogueVariable", "Start", ""),
    ("RelayRandom", "Start", ""),
    ("RelayRandomValue", "Start", ""),
    ("RelayTaskStatus", "Start", ""),
    ("RelayWeekdays", "Start", "RelayWeekdays.DeltaSeconds"),
    ("Trade", "StartDelay", "Trade.DeltaSeconds"),
];

/// The build space the player is in (docs/building.md): the game's load
/// makes the area's FurnitureManager saved as `isActive` the active one
/// (FurnitureManager.cs:175-178). On a later visit FurnitureManager's load
/// step is skipped (it creates objects), so only that part is done here.
fn build_space_again(area: &str) -> Result<(), String> {
    let managers = obj(invoke_static("Unityforge.Shim.SceneTools", "ComponentsIn", &json!([area, "Inventory, Assembly-CSharp", "FurnitureManager"]))?).ok_or("no manager list")?;
    let n = managers.read_field("Length")?.as_i64().unwrap_or(0);
    for i in 0..n {
        let Some(manager) = obj(managers.invoke("GetValue", &json!([i]))?) else { continue };
        if manager.read_field("isActive")?.as_bool() == Some(true) {
            let ty = obj(invoke_static("System.Type", "GetType", &json!(["BuildingSystem, Assembly-CSharp"]))?).ok_or("no BuildingSystem type")?;
            let field = obj(ty.invoke("GetField", &json!(["activeManager"]))?).ok_or("no BuildingSystem.activeManager")?;
            field.invoke("SetValue", &json!([null, {"handle": manager.handle().0}]))?;
        }
    }
    Ok(())
}

/// The map (docs/map.md): in the game the map panel and MapController are
/// rebuilt with every area, so their Start runs on every load: Map.Start
/// shows the area's map image, MapController.Start picks the area's map
/// record and puts its landmarks on the panel. Here the panel is kept, so
/// it is set back to a fresh panel first (markers removed, the reveal layer
/// off, the player arrow on, the map shown), then both Starts run again.
fn map_again() -> Result<(), String> {
    let controller = one_copy("MapController")?;
    // The panel MapController puts the landmarks on.
    let map = obj(controller.read_field("map")?).ok_or("no MapController.map")?;
    let markers = obj(map.read_field("landmarks")?).ok_or("no landmarks list")?;
    let n = markers.invoke("get_Count", &json!([]))?.as_i64().unwrap_or(0);
    for i in 0..n {
        if let Some(marker) = obj(markers.invoke("get_Item", &json!([i]))?) {
            invoke_static("UnityEngine.Object", "Destroy", &json!([{"handle": marker.handle().0}]))?;
        }
    }
    markers.invoke("Clear", &json!([]))?;
    obj(map.read_field("selectedLandmarks")?).ok_or("no selectedLandmarks list")?.invoke("Clear", &json!([]))?;
    let reveal = obj(map.read_field("revealingImage")?).ok_or("no revealingImage")?;
    obj(reveal.invoke("get_gameObject", &json!([]))?).ok_or("no reveal object")?.invoke("SetActive", &json!([false]))?;
    obj(map.read_field("playerMarker")?).ok_or("no playerMarker")?.invoke("SetActive", &json!([true]))?;
    map.invoke("ShowMainMap", &json!([]))?;
    map.invoke("Start", &json!([]))?;
    controller.invoke("Start", &json!([]))?;
    Ok(())
}

/// The sound (docs/sound.md): SoundscapeController is rebuilt with every
/// area in the game, so after a door it holds no global, current or
/// background soundscape and no trigger. Here it is kept, so those are set
/// back to nothing; the area's soundscapes, triggers and SoundscapeGlobal
/// then set them as on a load.
fn fresh_sound() -> Result<(), String> {
    let sc = one_copy("SoundscapeController")?;
    for field in ["currentGlobalSoundscape", "previousSoundscape", "currentSoundscape", "currentBackgroundSoundscape", "currentBackgroundLocation", "currentTrigger"] {
        sc.write_field(field, &Json::Null)?;
    }
    Ok(())
}

/// Steps 1 to 10 of rule 3.
fn leave_steps(area: &str) -> Result<String, String> {
    // Step 1.
    fire_save_event("PlayerWillChangeLevel")?;
    // Step 2.
    area_change_phase(area, "OnMapChanging")?;
    // The game's temp lists, emptied as SaveGame makes new ones (449-450).
    let level = obj(save_static("tempSavedata_Level")?).ok_or("no level list")?;
    let global = obj(save_static("tempSavedata_Global")?).ok_or("no global list")?;
    level.invoke("Clear", &json!([]))?;
    global.invoke("Clear", &json!([]))?;
    // Step 3: its listeners show what they hide so it is saved
    // (FadeGameObjectController ShowAll, SMVHierarchy).
    fire_save_event("SavingStarted")?;
    // Step 4.
    for phase in ["OnSavingGamePrimary", "OnSavingGameSecondary", "OnSavingGameTertiary"] {
        run_phase(area, phase, false)?;
    }
    // Step 5: the area's DestructibleList (still the game's: the area
    // entered becomes the game's only in rule 2, step 2).
    one_copy("DestructibleList")?.invoke("OnSavingGameDestructibleList", &json!([]))?;
    // Step 6 for the area's NPCs (the rest of 6 is game-wide data, not run).
    let npcs = npcs_leave(area)?;
    // Step 7.
    for phase in ["OnSavingGame", "OnSavingGameLatePrimary"] {
        run_phase(area, phase, false)?;
    }
    // Step 10 (8 and 9 are not run): SavingStarted's listeners hide again.
    fire_save_event("SavingDone")?;
    let level_entries = obj(level.invoke("ToArray", &json!([]))?).ok_or("no level entries")?;
    let global_entries = obj(global.invoke("ToArray", &json!([]))?).ok_or("no global entries")?;
    let counts = (level.invoke("get_Count", &json!([]))?, global.invoke("get_Count", &json!([]))?);
    level.invoke("Clear", &json!([]))?;
    global.invoke("Clear", &json!([]))?;
    let kept = (level_entries.handle().0, global_entries.handle().0);
    std::mem::forget(level_entries); // kept in CAPTURED until replaced or reset
    std::mem::forget(global_entries);
    if let Some((l, g)) = CAPTURED.lock().unwrap().insert(area.to_string(), kept) {
        drop(owned_object(l));
        drop(owned_object(g));
    }
    Ok(format!("{} area entries, {} global entries, {npcs} NPCs recorded", counts.0, counts.1))
}

/// Rule 3, step 6 for NPCs (docs/kept-areas.md, NPCs): each NPC object of
/// the area left is recorded by the game's `NPCData.OnSavingGame` (its area
/// and position), then its data stops pointing at it, as destroying it in
/// the game's unload would (`scheduler.OnDestroy()` unsubscribes its
/// schedule). Returns how many.
fn npcs_leave(area: &str) -> Result<usize, String> {
    let Some(manager) = obj(invoke_static("Unityforge.Shim.FirstCopyGuard", "AreaCopy", &json!(["NPCManager", area]))?) else {
        return Ok(0);
    };
    let list = obj(manager.invoke("GetAllNPCs", &json!([]))?).ok_or("no NPC list")?;
    let n = list.invoke("get_Count", &json!([]))?.as_i64().unwrap_or(0);
    let mut done = 0;
    for i in 0..n {
        let Some(info) = obj(list.invoke("get_Item", &json!([i]))?) else { continue };
        let Some(controller) = obj(info.read_field("npcController")?) else { continue };
        let Some(data) = obj(controller.read_field("Data")?) else { continue };
        data.invoke("OnSavingGame", &json!([]))?;
        if let Some(schedule) = obj(data.read_field("scheduler")?) {
            schedule.invoke("OnDestroy", &json!([]))?;
            schedule.write_field("NPC", &Json::Null)?;
        }
        data.write_field("controller", &Json::Null)?;
        done += 1;
    }
    Ok(done)
}

/// After every game save (SaveController.SaveGame, which writes only the
/// active area's file and globals from the active scene's objects,
/// SaveController.cs:438-475): write what it could not see.
extern "C" fn on_save_done(_ctx: *const c_void) {
    if CAPTURED.lock().unwrap().is_empty() {
        return;
    }
    let start = std::time::Instant::now();
    let result = write_kept_areas();
    unityforge::mono::log(
        unityforge::mono::LogLevel::Info,
        &format!("obenseuer-mod: kept_loaded: save: {result:?} ({:.2}s)", start.elapsed().as_secs_f64()),
    );
}

/// Design step 4. Save entries hold the live objects (ObjectDataHeader.Data
/// is the component, SaveController.cs:54-65) and are serialized when
/// written, so entries captured when the player left an area save that
/// area's state now, switched off or not.
fn write_kept_areas() -> Result<String, String> {
    let character = save_static("CharacterName")?.as_str().map(String::from).ok_or("no character name")?;
    let save = save_static("SaveName")?.as_str().map(String::from).ok_or("no save name")?;
    let data_path = invoke_static("UnityEngine.Application", "get_persistentDataPath", &json!([]))?.as_str().map(String::from).ok_or("no data path")?;
    let folder = format!("{data_path}/Saves/{character}/{save}");
    let active = invoke_static("UnityEngine.Application", "get_loadedLevelName", &json!([]))?.as_str().map(String::from).ok_or("no active area")?;
    let captured: Vec<(String, (i32, i32))> = CAPTURED.lock().unwrap().iter().map(|(a, h)| (a.clone(), *h)).collect();
    let names = (save.as_str(), character.as_str());
    let mut written = Vec::new();
    // 1. Every area captured when the player left it, but the one the game
    //    just wrote.
    for (area, (level, _)) in &captured {
        if *area != active {
            write_merged(&format!("{folder}/{area}.tnmt"), entries_of(*level)?, Some(area), names)?;
            written.push(area.clone());
        }
    }
    // 3. Away from home the active area's own player copy is off, so the
    //    game wrote no position for it: its position entries, pointed at the
    //    live player.
    if HOME.lock().unwrap().as_deref().is_some_and(|h| h != active) {
        let position = player_position_entries(&active)?;
        if !position.is_empty() {
            write_merged(&format!("{folder}/{active}.tnmt"), position, Some(&active), names)?;
        }
    }
    // 2. Global entries of every area captured (the live managers among
    //    them, captured when the player left home). The file's header keeps
    //    the area to load and its arrival point.
    let mut globals = Vec::new();
    for (_, (_, global)) in &captured {
        globals.extend(entries_of(*global)?);
    }
    write_merged(&format!("{folder}/Globals.tnmt"), globals, None, names)?;
    Ok(format!("{} areas written ({}), globals merged, into {folder}", written.len(), written.join(", ")))
}

/// The entries of a kept array of ObjectDataHeader (kept handle not
/// released).
fn entries_of(handle: i32) -> Result<Vec<MonoObject>, String> {
    unityforge::mono::with_object(handle, |arr| {
        let n = arr.read_field("Length")?.as_i64().unwrap_or(0);
        let mut out = Vec::new();
        for i in 0..n {
            out.extend(obj(arr.invoke("GetValue", &json!([i]))?));
        }
        Ok(out)
    })
}

/// Writes `path` as the game writes a save file (SaveDataHeader through its
/// Serialize, SaveController.cs:460-475): `entries`, then the file's own
/// entries whose GUID is not among them. `level`: the header's LevelName,
/// or the file's own (with its NewlevelEntrypoint) when None.
fn write_merged(path: &str, entries: Vec<MonoObject>, level: Option<&str>, (save, character): (&str, &str)) -> Result<(), String> {
    let header_type = obj(invoke_static("System.Type", "GetType", &json!(["SaveController+SaveDataHeader, Assembly-CSharp"]))?)
        .ok_or("SaveDataHeader type not found")?;
    // The game's own list between saves as the scratch list (empty then,
    // cleared after).
    let scratch = obj(save_static("tempSavedata_Level")?).ok_or("no scratch list")?;
    scratch.invoke("Clear", &json!([]))?;
    let mut guids = std::collections::HashSet::new();
    for e in &entries {
        if let Some(g) = e.read_field("GUID")?.as_str() {
            guids.insert(g.to_string());
        }
        scratch.invoke("Add", &json!([{"handle": e.handle().0}]))?;
    }
    let mut level_name = level.map(String::from);
    let mut entrypoint = "NONE".to_string();
    if let Ok(text) = std::fs::read_to_string(path) {
        let text = text.trim_start_matches('\u{feff}');
        let file = path.rsplit('/').next().unwrap_or(path);
        if let Some(existing) = obj(invoke_static("SaveController", "Deserialize", &json!([file, {"handle": header_type.handle().0}, text, null]))?) {
            if level_name.is_none() {
                level_name = existing.read_field("LevelName")?.as_str().map(String::from);
                entrypoint = existing.read_field("NewlevelEntrypoint")?.as_str().unwrap_or("NONE").to_string();
            }
            if let Some(data) = obj(existing.read_field("Data")?) {
                let n = data.invoke("get_Count", &json!([]))?.as_i64().unwrap_or(0);
                for i in 0..n {
                    let Some(e) = obj(data.invoke("get_Item", &json!([i]))?) else { continue };
                    let g = e.read_field("GUID")?.as_str().unwrap_or("").to_string();
                    if !guids.contains(&g) {
                        scratch.invoke("Add", &json!([{"handle": e.handle().0}]))?;
                    }
                }
            }
        }
    }
    let level_name = level_name.ok_or_else(|| format!("no area name for {path}"))?;
    let header = obj(invoke_static("SaveController+SaveDataHeader", ".ctor", &json!([{"handle": scratch.handle().0}, save, level_name, character, entrypoint]))?)
        .ok_or("SaveDataHeader not made")?;
    let written = invoke_static(
        "Unityforge.Shim.FileTools",
        "SerializeToFile",
        &json!(["SaveController", "Serialize", {"handle": header_type.handle().0}, {"handle": header.handle().0}, path]),
    );
    scratch.invoke("Clear", &json!([]))?;
    if written?.as_bool() != Some(true) {
        return Err(format!("{path} not written"));
    }
    Ok(())
}

/// Save entries for the area's own player position objects
/// (PersistLocation on its switched-off player copy, under its own GUIDs,
/// research_save_ids.rs), each pointing at the live player's matching
/// PersistLocation (by object name: ECM_Player, Player Camera Base).
fn player_position_entries(area: &str) -> Result<Vec<MonoObject>, String> {
    let home = HOME.lock().unwrap().clone().ok_or("no home area")?;
    let live: BTreeMap<String, MonoObject> = components_under(&home, "PersistLocation")?
        .into_iter()
        .filter(|c| c.invoke("get_isActiveAndEnabled", &json!([])).ok().and_then(|v| v.as_bool()) == Some(true))
        .filter_map(|c| Some((object_name(&c)?, c)))
        .collect();
    let mut out = Vec::new();
    for own in components_under(area, "PersistLocation")? {
        let (Some(name), Some(guid)) = (object_name(&own), own.read_field("GUID")?.as_str().map(String::from)) else { continue };
        let Some(live) = live.get(&name) else { continue };
        if let Some(entry) = obj(invoke_static("SaveController+ObjectDataHeader", ".ctor", &json!([{"handle": live.handle().0}, guid]))?) {
            out.push(entry);
        }
    }
    Ok(out)
}

/// Every component of a class under an area's top objects, on or off.
fn components_under(area: &str, class: &str) -> Result<Vec<MonoObject>, String> {
    let ty = obj(invoke_static("System.Type", "GetType", &json!([format!("{class}, Assembly-CSharp")]))?).ok_or_else(|| format!("{class} type"))?;
    let mut out = Vec::new();
    for root in roots(area)? {
        let Some(arr) = obj(root.invoke("GetComponentsInChildren", &json!([{"handle": ty.handle().0}, true]))?) else { continue };
        let n = arr.read_field("Length")?.as_i64().unwrap_or(0);
        for i in 0..n {
            out.extend(obj(arr.invoke("GetValue", &json!([i]))?));
        }
    }
    Ok(out)
}

fn object_name(c: &MonoObject) -> Option<String> {
    obj(c.invoke("get_gameObject", &json!([])).ok()?)?.invoke("get_name", &json!([])).ok()?.as_str().map(String::from)
}

/// A static field of SaveController, public or private.
fn save_static(field: &str) -> Result<Json, String> {
    save_field(field)?.invoke("GetValue", &json!([null]))
}

fn set_save_static(field: &str, value: Option<&MonoObject>) -> Result<(), String> {
    // An area with no saved file gets an empty list, as the game does
    // (SaveController.cs:1311).
    let v = match value {
        Some(o) => json!({"handle": o.handle().0}),
        None => {
            let list = obj(save_static(field)?).ok_or("no list to empty")?;
            list.invoke("Clear", &json!([]))?;
            json!({"handle": list.handle().0})
        }
    };
    save_field(field)?.invoke("SetValue", &json!([null, v]))?;
    Ok(())
}

fn save_field(field: &str) -> Result<MonoObject, String> {
    let ty = obj(invoke_static("System.Type", "GetType", &json!(["SaveController, Assembly-CSharp"]))?).ok_or("SaveController type")?;
    obj(ty.invoke("GetField", &json!([field, "Public, NonPublic, Static"]))?).ok_or_else(|| format!("SaveController.{field} not found"))
}

/// Ids of the top objects the shim's LoadQuietly switched off in an area.
fn taken_switched_off(area: &str) -> Vec<i64> {
    let Some(arr) = invoke_static("Unityforge.Shim.SceneTools", "TakeSwitchedOff", &json!([area])).ok().and_then(obj) else {
        return Vec::new();
    };
    let n = arr.read_field("Length").ok().and_then(|v| v.as_i64()).unwrap_or(0);
    (0..n)
        .filter_map(|i| obj(arr.invoke("GetValue", &json!([i])).ok()?)?.invoke("GetInstanceID", &json!([])).ok()?.as_i64())
        .collect()
}

/// An area's top objects, on or off (SceneTools.RootsOf in the shim).
fn roots(area: &str) -> Result<Vec<MonoObject>, String> {
    let arr = obj(invoke_static("Unityforge.Shim.SceneTools", "RootsOf", &json!([area]))?)
        .ok_or_else(|| format!("no top objects for {area}"))?;
    let n = arr.read_field("Length")?.as_i64().unwrap_or(0);
    let mut out = Vec::new();
    for i in 0..n {
        out.extend(obj(arr.invoke("GetValue", &json!([i]))?));
    }
    Ok(out)
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
