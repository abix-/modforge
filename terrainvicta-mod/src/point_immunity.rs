//! The player's control points cannot be taken by Purge, Coup,
//! Enthrall or Terrorize, and every other loss is logged.
//!
//! Most control point owner changes go through
//! TINationState.ChangeControlPointOwner(index, cause, faction). This
//! skips it when the point is the player's, the new owner is not, and
//! the cause is one of BLOCKED, logging the attempt. Wars, revolutions,
//! nations merging or splitting and the rest still change owners.
//!
//! The loss log: every owner change ends in TIControlPoint.SetFaction,
//! including two that bypass ChangeControlPointOwner (a nation's
//! control points rebuilt, TINationState.cs:9538; an alien army
//! founding the Alien Administration, TIRegionState.cs:1351). Its
//! prefix logs each of the player's points going to someone else, with
//! the cause ChangeControlPointOwner noted just before (or "set
//! directly"). A point removed from its nation outright
//! (TIControlPoint.RemoveControlPointFromNation) is logged too.

use std::ffi::{CStr, c_void};
use std::os::raw::c_char;
use std::sync::atomic::{AtomicI64, Ordering};

use serde_json::{Value as Json, json};
use unityforge::hook::{HOOK_REGISTRY, HookCtx, patch_prefix_ctx, patch_prefix_instance_args};
use unityforge::mono::{LogLevel, MonoObject, json_handle, log, owned_object};

/// ControlPointChangeCause values blocked against the player: Coup,
/// Politics (Purge), Enthrall (the aliens' Enthrall Elites, which
/// gives the point to their human supporters), Terrorize (the aliens'
/// Terrorize Region, which gives it to a pro-alien faction).
const BLOCKED: [i64; 4] = [4, 5, 9, 10];

/// ControlPointChangeCause names by value.
const CAUSES: [&str; 14] = [
    "None",
    "RegimeChange",
    "Liberation",
    "Revolution",
    "Coup",
    "Politics (Purge or Control Nation)",
    "Independence",
    "Annexation",
    "Trade",
    "Enthrall",
    "Terrorize",
    "Victory",
    "Event",
    "Growth",
];

/// The cause of the owner change ChangeControlPointOwner is making,
/// for SetFaction's log; -1 when the change did not come through it.
static PENDING_CAUSE: AtomicI64 = AtomicI64::new(-1);

fn cause_name(cause: i64) -> String {
    usize::try_from(cause)
        .ok()
        .and_then(|i| CAUSES.get(i))
        .map(|s| s.to_string())
        .unwrap_or_else(|| "set directly".into())
}

pub fn install() {
    install_loss_log();
    // Two overloads; the private (TIControlPoint, ...) one calls this
    // public (int, ...) one, so this catches every change.
    match patch_prefix_instance_args(
        "PavonisInteractive.TerraInvicta.TINationState",
        "ChangeControlPointOwner(System.Int32,ControlPointChangeCause,PavonisInteractive.TerraInvicta.TIFactionState)",
        on_change_owner,
    ) {
        Ok(hook) => {
            HOOK_REGISTRY.register(hook);
            log(LogLevel::Info, "terrainvicta-mod: control point immunity (Purge, Coup, Enthrall, Terrorize) armed");
        }
        Err(e) => log(
            LogLevel::Warn,
            &format!("terrainvicta-mod: control point immunity patch failed: {e}"),
        ),
    }
}

/// A field, or failing that a property getter.
fn member(obj: &MonoObject, name: &str) -> Result<Json, String> {
    obj.read_field(name)
        .or_else(|_| obj.invoke(&format!("get_{name}"), &json!([])))
}

fn text(obj: &MonoObject, name: &str) -> String {
    member(obj, name).ok().and_then(|v| v.as_str().map(str::to_string)).unwrap_or_default()
}

fn is_player(faction: Option<&MonoObject>) -> bool {
    faction.is_some_and(|f| member(f, "isActivePlayer").ok().and_then(|v| v.as_bool()) == Some(true))
}

/// Whether to block this change, and a description for the log.
fn blocked(nation: &MonoObject, args: &[Json], new_owner: Option<&MonoObject>) -> Result<Option<String>, String> {
    let cause = args.get(1).and_then(Json::as_i64).unwrap_or(-1);
    if !BLOCKED.contains(&cause) {
        return Ok(None);
    }
    if is_player(new_owner) {
        return Ok(None);
    }
    let index = args.first().and_then(Json::as_i64).ok_or("no control point index")?;
    let Some(point) = json_handle(&nation.invoke("GetControlPoint", &json!([index]))?).map(owned_object) else {
        return Ok(None);
    };
    let owner = json_handle(&member(&point, "faction")?).map(owned_object);
    if !is_player(owner.as_ref()) {
        return Ok(None);
    }
    Ok(Some(format!(
        "{} kept: {} by {} blocked",
        text(&point, "displayName"),
        cause_name(cause),
        new_owner.map(|f| text(f, "displayName")).unwrap_or_else(|| "nobody".into()),
    )))
}

extern "C" fn on_change_owner(instance: *const c_void, args: *const c_char) -> i32 {
    let nation = owned_object(instance as isize as i32);
    // SAFETY: the shim passes a NUL-terminated UTF-8 buffer that stays
    // pinned for the duration of the callback.
    let text_args = if args.is_null() {
        String::new()
    } else {
        unsafe { CStr::from_ptr(args) }.to_string_lossy().into_owned()
    };
    let args: Vec<Json> = match serde_json::from_str::<Json>(&text_args) {
        Ok(Json::Array(a)) => a,
        _ => Vec::new(),
    };
    // The new owner's handle is ours to release.
    let new_owner = args.get(2).and_then(json_handle).map(owned_object);
    match blocked(&nation, &args, new_owner.as_ref()) {
        Ok(Some(what)) => {
            log(LogLevel::Info, &format!("terrainvicta-mod: {what}"));
            1
        }
        Ok(None) => {
            // Going ahead: note the cause for SetFaction's loss log.
            PENDING_CAUSE.store(args.get(1).and_then(Json::as_i64).unwrap_or(-1), Ordering::Relaxed);
            0
        }
        Err(e) => {
            log(LogLevel::Warn, &format!("terrainvicta-mod: control point immunity: {e}"));
            0
        }
    }
}

// ---- the loss log -------------------------------------------------------

fn install_loss_log() {
    match patch_prefix_instance_args(
        "PavonisInteractive.TerraInvicta.TIControlPoint",
        "SetFaction",
        on_set_faction,
    ) {
        Ok(hook) => HOOK_REGISTRY.register(hook),
        Err(e) => log(
            LogLevel::Warn,
            &format!("terrainvicta-mod: control point loss log (SetFaction) failed: {e}"),
        ),
    }
    match patch_prefix_ctx(
        "PavonisInteractive.TerraInvicta.TIControlPoint",
        "RemoveControlPointFromNation",
        HookCtx::Instance,
        on_remove_point,
    ) {
        Ok(hook) => HOOK_REGISTRY.register(hook),
        Err(e) => log(
            LogLevel::Warn,
            &format!("terrainvicta-mod: control point loss log (RemoveControlPointFromNation) failed: {e}"),
        ),
    }
}

/// "<point> in <nation>".
fn where_is(point: &MonoObject) -> String {
    let nation = json_handle(&member(point, "nation").unwrap_or(Json::Null))
        .map(owned_object)
        .map(|n| text(&n, "displayName"))
        .unwrap_or_default();
    format!("{} in {nation}", text(point, "displayName"))
}

fn players_point(point: &MonoObject) -> bool {
    let owner = json_handle(&member(point, "faction").unwrap_or(Json::Null)).map(owned_object);
    is_player(owner.as_ref())
}

/// TIControlPoint.SetFaction(newFaction, newCampaign).
extern "C" fn on_set_faction(instance: *const c_void, args: *const c_char) -> i32 {
    let cause = PENDING_CAUSE.swap(-1, Ordering::Relaxed);
    let point = owned_object(instance as isize as i32);
    // SAFETY: the shim passes a NUL-terminated UTF-8 buffer that stays
    // pinned for the duration of the callback.
    let text_args = if args.is_null() {
        String::new()
    } else {
        unsafe { CStr::from_ptr(args) }.to_string_lossy().into_owned()
    };
    let new_owner = match serde_json::from_str::<Json>(&text_args) {
        Ok(Json::Array(a)) => a.first().and_then(json_handle).map(owned_object),
        _ => None,
    };
    if players_point(&point) && !is_player(new_owner.as_ref()) {
        log(
            LogLevel::Info,
            &format!(
                "terrainvicta-mod: LOST {}: cause {}, to {}",
                where_is(&point),
                cause_name(cause),
                new_owner.as_ref().map(|f| text(f, "displayName")).unwrap_or_else(|| "nobody".into()),
            ),
        );
    }
    0
}

extern "C" fn on_remove_point(ctx: *const c_void) -> i32 {
    let point = owned_object(ctx as isize as i32);
    if players_point(&point) {
        log(
            LogLevel::Info,
            &format!(
                "terrainvicta-mod: LOST {}: removed (the nation's control points were rebuilt)",
                where_is(&point)
            ),
        );
    }
    0
}
