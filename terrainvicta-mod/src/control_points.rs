//! Ten times the control point cap for the player's faction.
//!
//! Every use of the cap (the over-cap mission penalty, the Influence
//! cost of the next control point, the screens) reads
//! TIFactionState.GetControlPointMaintenanceFreebieCap, so one result
//! patch on it covers them all. AI factions keep the normal cap.
//!
//! The patch goes in on the first campaign load, not at mod start:
//! patching TIFactionState runs its static setup, which reads mission
//! templates (TIFactionState.friendlyCouncilorToCouncilorMissions)
//! that do not exist at the main menu. Run there, it throws and
//! leaves TIFactionState unusable for the whole session.

use std::ffi::c_void;
use std::sync::atomic::{AtomicBool, Ordering};
use std::time::Duration;

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use unityforge::hook::{HOOK_REGISTRY, HookCtx, patch_postfix_float_result, patch_prefix_ctx};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{LogLevel, invoke_static, json_handle, log, owned_object};

const CAP_MULTIPLIER: f32 = 10.0;

/// Set only inside the control_point_cap op, on the main thread, to
/// read the game's own cap with the patch passing it through.
static PASS_THROUGH: AtomicBool = AtomicBool::new(false);

/// The cap patch is in place (per mod generation).
static ARMED: AtomicBool = AtomicBool::new(false);

pub fn install() {
    match patch_prefix_ctx(
        "PavonisInteractive.TerraInvicta.TIMissionPhaseState",
        "PostVisualizerCreationInit_6",
        HookCtx::Instance,
        on_campaign_loaded,
    ) {
        Ok(hook) => HOOK_REGISTRY.register(hook),
        Err(e) => log(
            LogLevel::Warn,
            &format!("terrainvicta-mod: control point cap load patch failed: {e}"),
        ),
    }
    OP_REGISTRY.register(OpDef::new(
        "control_point_cap",
        "The player's control point cap as the game computes it and as the patch reports it",
        "{}",
        |_args| MAIN_QUEUE.run("control_point_cap", Duration::from_secs(5), player_caps)?,
    ));
    // A hot reload lands in a running campaign, where the load patch
    // above will not fire again; TIFactionState is already set up then.
    if campaign_loaded() {
        arm();
    }
}

fn campaign_loaded() -> bool {
    let Ok(control) = invoke_static("GameControl", "get_control", &json!([])) else {
        return false;
    };
    json_handle(&control)
        .map(owned_object)
        .and_then(|c| c.invoke("get_activePlayer", &json!([])).ok())
        .and_then(|p| json_handle(&p).map(owned_object))
        .is_some()
}

extern "C" fn on_campaign_loaded(ctx: *const c_void) -> i32 {
    drop(owned_object(ctx as isize as i32));
    arm();
    0
}

fn arm() {
    if ARMED.swap(true, Ordering::Relaxed) {
        return;
    }
    match patch_postfix_float_result(
        "PavonisInteractive.TerraInvicta.TIFactionState",
        "GetControlPointMaintenanceFreebieCap",
        on_cap,
    ) {
        Ok(hook) => {
            HOOK_REGISTRY.register(hook);
            log(
                LogLevel::Info,
                &format!("terrainvicta-mod: control point cap x{CAP_MULTIPLIER} armed"),
            );
        }
        Err(e) => log(
            LogLevel::Warn,
            &format!("terrainvicta-mod: control point cap patch failed: {e}"),
        ),
    }
}

fn player_caps() -> Result<Json, String> {
    let control = json_handle(&invoke_static("GameControl", "get_control", &json!([]))?)
        .map(owned_object)
        .ok_or("GameControl.control is null")?;
    let faction = json_handle(&control.invoke("get_activePlayer", &json!([]))?)
        .map(owned_object)
        .ok_or("no active player")?;
    let read = || faction.invoke("GetControlPointMaintenanceFreebieCap", &json!([]));
    PASS_THROUGH.store(true, Ordering::Relaxed);
    let game = read();
    PASS_THROUGH.store(false, Ordering::Relaxed);
    Ok(json!({"game_cap": game?, "patched_cap": read()?}))
}

extern "C" fn on_cap(instance: *const c_void, _args: *const std::os::raw::c_char, cap: f32) -> f32 {
    let h = instance as isize as i32;
    if h == 0 {
        return cap;
    }
    if PASS_THROUGH.load(Ordering::Relaxed) {
        drop(owned_object(h));
        return cap;
    }
    let faction = owned_object(h);
    match faction.invoke("get_isActivePlayer", &json!([])) {
        Ok(v) if v.as_bool() == Some(true) => cap * CAP_MULTIPLIER,
        Ok(_) => cap,
        Err(e) => {
            log(
                LogLevel::Warn,
                &format!("terrainvicta-mod: control point cap player check: {e}"),
            );
            cap
        }
    }
}
