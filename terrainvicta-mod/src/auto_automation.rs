//! Every mission phase start turns automation back on for all the
//! player's active councilors, so offense mode plans for all of them
//! even after one was given a mission by hand (which turns it off).
//!
//! A prefix on TIMissionPhaseState.StartofTurnBookkeeping, the loop
//! that calls SelectPermanentDefenseModeMission for councilors with
//! automation on. It sets the flags the way
//! TICouncilorState.SetPermanentDefenseMode(true) does (automation on,
//! repeat order and permanent assignment off) but directly: that
//! method picks a mission itself during a phase, and the loop would
//! then pick a second.

use std::ffi::c_void;
use std::time::Duration;

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use unityforge::hook::{HOOK_REGISTRY, HookCtx, patch_prefix_ctx};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{LogLevel, MonoObject, invoke_static, json_handle, log, owned_object};

pub fn install() {
    match patch_prefix_ctx(
        "PavonisInteractive.TerraInvicta.TIMissionPhaseState",
        "StartofTurnBookkeeping",
        HookCtx::Instance,
        on_bookkeeping,
    ) {
        Ok(hook) => {
            HOOK_REGISTRY.register(hook);
            log(LogLevel::Info, "terrainvicta-mod: automation on at every phase start armed");
        }
        Err(e) => log(
            LogLevel::Warn,
            &format!("terrainvicta-mod: automation at phase start patch failed: {e}"),
        ),
    }
    OP_REGISTRY.register(OpDef::new(
        "enable_automation",
        "Turn automation on for all the player's active councilors now (what every phase start does); returns who was switched on",
        "{}",
        |_args| MAIN_QUEUE.run("enable_automation", Duration::from_secs(5), enable_all)?,
    ));
}

/// A field, or failing that a property getter.
fn member(obj: &MonoObject, name: &str) -> Result<Json, String> {
    obj.read_field(name)
        .or_else(|_| obj.invoke(&format!("get_{name}"), &json!([])))
}

fn text(obj: &MonoObject, name: &str) -> String {
    member(obj, name).ok().and_then(|v| v.as_str().map(str::to_string)).unwrap_or_default()
}

/// Set a bool that may be a field or an auto-property with a private
/// setter (whose backing field is `<name>k__BackingField`).
fn set_flag(obj: &MonoObject, name: &str, value: bool) -> Result<(), String> {
    obj.write_field(name, &json!(value))
        .or_else(|_| obj.write_field(&format!("<{name}>k__BackingField"), &json!(value)))
        .or_else(|_| obj.invoke(&format!("set_{name}"), &json!([value])).map(|_| ()))
}

fn enable_all() -> Result<Json, String> {
    let control = json_handle(&invoke_static("GameControl", "get_control", &json!([]))?)
        .map(owned_object)
        .ok_or("GameControl.control is null")?;
    let Some(faction) = json_handle(&member(&control, "activePlayer")?).map(owned_object) else {
        return Ok(json!({"switched_on": []}));
    };
    let councilors = json_handle(&member(&faction, "councilors")?)
        .map(owned_object)
        .ok_or("no councilors")?;
    let mut switched = Vec::new();
    for i in 0..councilors.list_len_or_zero()? {
        let Some(c) = councilors.list_handle(i)?.map(owned_object) else {
            continue;
        };
        if member(&c, "active")?.as_bool() != Some(true)
            || member(&c, "permanentDefenseMode")?.as_bool() == Some(true)
        {
            continue;
        }
        set_flag(&c, "permanentDefenseMode", true)?;
        set_flag(&c, "repeatOrder", false)?;
        set_flag(&c, "permanentAssignment", false)?;
        switched.push(text(&c, "displayName"));
    }
    if !switched.is_empty() {
        log(
            LogLevel::Info,
            &format!("terrainvicta-mod: automation switched back on: {}", switched.join(", ")),
        );
    }
    Ok(json!({"switched_on": switched}))
}

extern "C" fn on_bookkeeping(ctx: *const c_void) -> i32 {
    drop(owned_object(ctx as isize as i32));
    if let Err(e) = enable_all() {
        log(LogLevel::Warn, &format!("terrainvicta-mod: automation at phase start: {e}"));
    }
    0
}
