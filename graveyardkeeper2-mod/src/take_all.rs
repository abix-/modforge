//! Auto "take all" for auto crafters (furnace, distillation cube, ...).
//!
//! The game waits for the player to press the action key on a station
//! whose status is ReadyToFinishAutoCraft. This runs the same steps as
//! CraftInteractionHandler.Interact2 the moment the status is set, so
//! the output drops on the ground at the station wherever the player is.
//!
//! Trigger: a prefix on CraftComponent.set_Status notes the station when
//! the new value is ReadyToFinishAutoCraft, and a prefix on
//! CraftComponent.Init notes every station a save sets up, for ones that
//! were saved while waiting. The steps run on the next tick, because the
//! game is still inside PreFinishUpdate or the load at that point.

use parking_lot::Mutex;
use serde_json::{Value as Json, json};
use std::ffi::{CStr, c_char, c_void};
use std::sync::atomic::{AtomicBool, Ordering};
use unityforge::bridge::MonoHandle;
use unityforge::hook::{HOOK_REGISTRY, patch_prefix_instance_args};
use unityforge::mono::{LogLevel, MonoObject, log};

use crate::tweaks::{main_game, read_handle};

/// CraftComponentStatus.ReadyToFinishAutoCraft.
const READY_TO_FINISH_AUTO_CRAFT: i64 = 7;
/// CraftComponentStatus.Finished: a growing crop has just become its
/// _ready object (see harvest.rs).
const FINISHED: i64 = 2;

/// CraftComponent handles whose status just became ready, owned here.
static PENDING: Mutex<Vec<i32>> = Mutex::new(Vec::new());
/// CraftComponent handles a save just set up, owned here. They wait for
/// the player's current game scene: take all run while the scene is
/// still loading threw after the drops and left the player as worker.
static LOADED: Mutex<Vec<i32>> = Mutex::new(Vec::new());
static HAS_PENDING: AtomicBool = AtomicBool::new(false);

pub fn install() {
    type Prefix = extern "C" fn(*const c_void, *const c_char) -> i32;
    let hooks: [(&str, Prefix); 2] = [("set_Status", on_set_status), ("Init", on_init)];
    for (method, prefix) in hooks {
        match patch_prefix_instance_args("CraftComponent", method, prefix) {
            Ok(hook) => HOOK_REGISTRY.register(hook),
            Err(e) => log(LogLevel::Error, &format!("take_all: hook {method} failed: {e}")),
        }
    }
}

fn queue(list: &Mutex<Vec<i32>>, h: i32) {
    list.lock().push(h);
    HAS_PENDING.store(true, Ordering::Release);
}

/// CraftComponent.Init runs for every station as a save sets it up, with
/// the saved status already in place. take_all skips any not waiting.
extern "C" fn on_init(instance: *const c_void, _args: *const c_char) -> i32 {
    let h = instance as usize as i32;
    if h != 0 {
        queue(&LOADED, h);
    }
    0
}

extern "C" fn on_set_status(instance: *const c_void, args: *const c_char) -> i32 {
    let h = instance as usize as i32;
    if h == 0 {
        return 0;
    }
    let status = if args.is_null() {
        None
    } else {
        unsafe { CStr::from_ptr(args) }
            .to_str()
            .ok()
            .and_then(|s| serde_json::from_str::<Json>(s).ok())
            .and_then(|j| j.get(0).and_then(Json::as_i64))
    };
    if matches!(status, Some(READY_TO_FINISH_AUTO_CRAFT | FINISHED)) {
        queue(&PENDING, h);
    } else {
        drop(unsafe { MonoObject::from_handle(MonoHandle(h)) });
    }
    0
}

/// The player's current game scene is set, so the save is loaded.
fn scene_ready() -> bool {
    main_game()
        .and_then(|mg| read_handle(&mg, "playerController"))
        .and_then(|pc| read_handle(&pc, "currentGameScene"))
        .is_ok()
}

// The hooks and the tick all run on the Unity main thread.
pub fn on_tick() {
    if !HAS_PENDING.load(Ordering::Acquire) {
        return;
    }
    let mut pending = std::mem::take(&mut *PENDING.lock());
    if !LOADED.lock().is_empty() && scene_ready() {
        pending.append(&mut LOADED.lock());
    }
    HAS_PENDING.store(!LOADED.lock().is_empty(), Ordering::Release);
    for h in pending {
        let cc = unsafe { MonoObject::from_handle(MonoHandle(h)) };
        if let Err(e) = take_all(&cc) {
            log(LogLevel::Warn, &format!("take_all: {e}"));
        }
        if let Err(e) = crate::harvest::harvest(&cc) {
            log(LogLevel::Warn, &format!("harvest: {e}"));
        }
    }
}

pub(crate) fn obj(j: Json) -> Option<MonoObject> {
    let h = j.get("handle").and_then(Json::as_i64)? as i32;
    Some(unsafe { MonoObject::from_handle(MonoHandle(h)) })
}

pub(crate) fn call(o: &MonoObject, method: &str, args: Json) -> Result<Option<MonoObject>, String> {
    Ok(obj(o.invoke(method, &args)?))
}

pub(crate) fn arg(o: &MonoObject) -> Json {
    json!({"$handle": o.handle().0})
}

/// CraftInteractionHandler.Interact2, the auto crafter branch.
fn take_all(cc: &MonoObject) -> Result<(), String> {
    if cc.read_field("status")? != json!("ReadyToFinishAutoCraft") {
        return Ok(());
    }
    if cc.invoke("get_IsDestroyingCraftActive", &json!([]))? == json!(true) {
        return Ok(());
    }
    // HasOneTimeCraftStarted
    if cc.invoke("get_IsStarted", &json!([]))? == json!(true) {
        if let Some(el) = call(cc, "get_CurrentCraftElement", json!([]))? {
            if let Some(def) = call(&el, "get_Def", json!([]))? {
                if def.read_field("isOneTimeCraft").ok() == Some(json!(true)) {
                    return Ok(());
                }
            }
        }
    }
    let wgo = read_handle(cc, "craftableObject")?;
    let def = call(&wgo, "get_Definition", json!([]))?.ok_or("station has no Definition")?;
    if def.read_field("isAutoCrafter")? != json!(true) {
        return Ok(());
    }
    // IsConveyorAutoCrafter
    if def.read_field("conveyorType")? == json!("Workbench") {
        return Ok(());
    }

    let mg = main_game()?;
    let player = read_handle(&mg, "playerController")?;
    let set_worker = wgo.invoke("get_Worker", &json!([]))?.is_null();
    if set_worker {
        wgo.invoke("TrySetWorker", &json!([arg(&player), null]))?;
    }

    cc.invoke("ContinueAutoCraft", &json!([]))?;

    let inv = call(&wgo, "get_CraftableObjectCraftInventory", json!([]))?
        .ok_or("station has no craft inventory")?;
    let data = call(&inv, "get_Data", json!([]))?.ok_or("craft inventory has no Data")?;
    let items = call(&data, "RemoveAllItems", json!([]))?.ok_or("RemoveAllItems returned null")?;
    let n = items.read_field("_size")?.as_i64().unwrap_or(0);
    for i in 0..n {
        if let Some(item) = call(&items, "get_Item", json!([i]))? {
            wgo.invoke("MakeDrop", &json!([arg(&item)]))?;
        }
    }

    wgo.invoke("DropStoredTechPoints", &json!([]))?;
    if set_worker {
        wgo.invoke("ClearWorker", &json!([]))?;
    }

    let id = wgo.read_field("id").unwrap_or(Json::Null);
    log(LogLevel::Info, &format!("take_all: {id} dropped {n} item stack(s)"));
    Ok(())
}
