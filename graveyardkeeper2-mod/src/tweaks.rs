use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use std::ffi::c_void;
use std::sync::atomic::{AtomicBool, Ordering};
use unityforge::hook::{HOOK_REGISTRY, patch_prefix};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{LogLevel, MonoObject, log};

const AUTO_INVENTORY_SIZE: i32 = 150;
const AUTO_SPEED: f32 = 1.5;

/// Set by the MainGame.AfterSceneHasLoaded hook, cleared once applied.
static AUTO_APPLY_PENDING: AtomicBool = AtomicBool::new(false);

pub fn install() {
    // MainGame.AfterSceneHasLoaded runs once the save's scene is loaded,
    // on both Continue and New Game. The tweaks are written on the next
    // tick, once the method has set the player up.
    match patch_prefix("MainGame", "AfterSceneHasLoaded", on_scene_loaded) {
        Ok(hook) => HOOK_REGISTRY.register(hook),
        Err(e) => log(LogLevel::Error, &format!("tweaks: hook failed: {e}")),
    }
    OP_REGISTRY.register(OpDef::new(
        "tweaks",
        "Read or write player tweaks (inventory_size, speed, energy, insanity). Pass no args to read all",
        "{inventory_size?: int, speed?: float, energy?: float, insanity?: float}",
        tweaks,
    ));
}

pub(crate) fn main_game() -> Result<MonoObject, String> {
    let j = unityforge::mono::invoke_static("MainGame", "get_Instance", &json!([]))?;
    let h = j
        .get("handle")
        .and_then(Json::as_i64)
        .ok_or("no MainGame instance")? as i32;
    Ok(unsafe { MonoObject::from_handle(unityforge::bridge::MonoHandle(h)) })
}

pub(crate) fn read_handle(obj: &MonoObject, field: &str) -> Result<MonoObject, String> {
    let j = obj.read_field(field)?;
    let h = j
        .get("handle")
        .and_then(Json::as_i64)
        .ok_or_else(|| format!("{field} has no handle"))? as i32;
    Ok(unsafe { MonoObject::from_handle(unityforge::bridge::MonoHandle(h)) })
}

extern "C" fn on_scene_loaded(_: *const c_void) -> i32 {
    AUTO_APPLY_PENDING.store(true, Ordering::Release);
    0
}

pub fn on_tick(_now: f32) {
    if !AUTO_APPLY_PENDING.swap(false, Ordering::Acquire) {
        return;
    }
    if let Err(e) = crate::stacks::apply() {
        log(LogLevel::Warn, &format!("stacks: {e}"));
    }
    match auto_apply() {
        Ok(()) => log(
            LogLevel::Info,
            &format!(
                "tweaks: auto-applied inventory_size={AUTO_INVENTORY_SIZE}, speed={AUTO_SPEED}"
            ),
        ),
        Err(e) => log(LogLevel::Warn, &format!("tweaks: auto-apply failed: {e}")),
    }
}

fn auto_apply() -> Result<(), String> {
    let mg = main_game()?;
    let pc = read_handle(&mg, "playerController")?;
    let pd = read_handle(&pc, "playerData")?;
    let inv = read_handle(&pd, "inventory")?;
    let inv_item = read_handle(&inv, "inventoryItem")?;
    let phys_json = pc.invoke("get_PhysicalBody", &json!([]))?;
    let phys_h = phys_json
        .get("handle")
        .and_then(Json::as_i64)
        .ok_or("PhysicalBody has no handle")? as i32;
    let phys = unsafe { MonoObject::from_handle(unityforge::bridge::MonoHandle(phys_h)) };

    inv_item.write_field("inventorySize", &json!(AUTO_INVENTORY_SIZE))?;
    phys.write_field("<SpeedMultiplier>k__BackingField", &json!(AUTO_SPEED))?;
    Ok(())
}

fn tweaks(args: &Json) -> Result<Json, String> {
    let set_inv = args.get("inventory_size").and_then(Json::as_i64).map(|v| v as i32);
    let set_speed = args.get("speed").and_then(Json::as_f64).map(|v| v as f32);
    let set_energy = args.get("energy").and_then(Json::as_f64).map(|v| v as f32);
    let set_insanity = args.get("insanity").and_then(Json::as_f64).map(|v| v as f32);

    MAIN_QUEUE.run(
        "tweaks",
        std::time::Duration::from_secs(2),
        move || -> Result<Json, String> {
            let mg = main_game()?;

            let pc = read_handle(&mg, "playerController")?;
            std::mem::forget(mg);
            let pd = read_handle(&pc, "playerData")?;
            let phys_json = pc.invoke("get_PhysicalBody", &json!([]))?;
            let phys_h = phys_json
                .get("handle")
                .and_then(Json::as_i64)
                .ok_or("PhysicalBody has no handle")? as i32;
            let phys = unsafe {
                MonoObject::from_handle(unityforge::bridge::MonoHandle(phys_h))
            };
            std::mem::forget(pc);

            // inventory size
            let inv = read_handle(&pd, "inventory")?;
            let inv_item = read_handle(&inv, "inventoryItem")?;
            std::mem::forget(inv);
            if let Some(size) = set_inv {
                if size < 20 {
                    return Err("inventory_size must be at least 20".into());
                }
                inv_item.write_field("inventorySize", &json!(size))?;
            }
            let cur_inv = inv_item.read_field("inventorySize")?;
            std::mem::forget(inv_item);

            // speed multiplier
            if let Some(spd) = set_speed {
                if spd < 0.1 {
                    return Err("speed must be at least 0.1".into());
                }
                phys.write_field("<SpeedMultiplier>k__BackingField", &json!(spd))?;
            }
            let cur_speed = phys.read_field("<SpeedMultiplier>k__BackingField")?;
            std::mem::forget(phys);

            // energy
            let res = read_handle(&pd, "res")?;
            std::mem::forget(pd);
            if let Some(nrg) = set_energy {
                res.invoke("SetWithoutSystemsCheck", &json!(["energy", nrg]))?;
            }
            let cur_energy = res.invoke("GetInt", &json!(["energy"]))?;
            if let Some(ins) = set_insanity {
                res.invoke("SetWithoutSystemsCheck", &json!(["insanity", ins]))?;
            }
            let cur_insanity = res.invoke("GetInt", &json!(["insanity"]))?;
            std::mem::forget(res);

            Ok(json!({
                "inventory_size": cur_inv,
                "speed": cur_speed,
                "energy": cur_energy,
                "insanity": cur_insanity,
            }))
        },
    )?
}
