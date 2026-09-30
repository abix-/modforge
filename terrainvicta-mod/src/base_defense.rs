//! Every control point and hab of the player's counts as defended,
//! all the time, with no Defend Interests mission.
//!
//! TIMissionModifier_DefendedAsset gives the defender
//! TIMissionModifier_DefendedAsset (10) against Crackdown, Purge,
//! Control Space Asset and Sabotage Hab Module when the target is
//! defended, else 0. For the player's undefended control points and
//! habs this makes it the full value too.
//!
//! Coup counts defended control points in the nation instead
//! (TIMissionModifier_numDefendedControlPoints, +1 each). This adds
//! 1 for each undefended control point of the player's there, except
//! on the player's own coups.

use std::ffi::{CStr, c_void};
use std::os::raw::c_char;
use std::sync::atomic::{AtomicU32, Ordering};

use serde_json::{Value as Json, json};
use unityforge::hook::{HOOK_REGISTRY, patch_postfix_float_result};
use unityforge::mono::{LogLevel, MonoObject, invoke_static, json_handle, log, owned_object};

/// Share of the defended bonus the player's undefended assets get.
const SHARE: f32 = 1.0;

/// f32 bits of the game's TIMissionModifier_DefendedAsset; 0 = unread.
static DEFENDED_VALUE: AtomicU32 = AtomicU32::new(0);

pub fn install() {
    let patches: [(&str, extern "C" fn(*const c_void, *const c_char, f32) -> f32); 2] = [
        ("TIMissionModifier_DefendedAsset", on_defended_asset),
        ("TIMissionModifier_numDefendedControlPoints", on_coup_defense),
    ];
    for (class, f) in patches {
        match patch_postfix_float_result(class, "GetModifier", f) {
            Ok(hook) => HOOK_REGISTRY.register(hook),
            Err(e) => {
                log(
                    LogLevel::Warn,
                    &format!("terrainvicta-mod: base defense {class} patch failed: {e}"),
                );
                return;
            }
        }
    }
    log(
        LogLevel::Info,
        "terrainvicta-mod: base defense (always defended) armed",
    );
}

/// A field, or failing that a property getter.
fn member(obj: &MonoObject, name: &str) -> Result<Json, String> {
    obj.read_field(name)
        .or_else(|_| obj.invoke(&format!("get_{name}"), &json!([])))
}

fn member_object(obj: &MonoObject, name: &str) -> Result<Option<MonoObject>, String> {
    Ok(json_handle(&member(obj, name)?).map(owned_object))
}

fn is(obj: &MonoObject, name: &str) -> Result<bool, String> {
    Ok(member(obj, name)?.as_bool() == Some(true))
}

/// The call's arguments; every handle in them is owned here and
/// released when the returned objects drop.
fn take_args(args: *const c_char) -> Vec<Option<MonoObject>> {
    if args.is_null() {
        return Vec::new();
    }
    // SAFETY: the shim passes a NUL-terminated UTF-8 buffer that
    // stays pinned for the duration of the callback.
    let text = unsafe { CStr::from_ptr(args) }.to_string_lossy();
    let Ok(Json::Array(values)) = serde_json::from_str::<Json>(&text) else {
        return Vec::new();
    };
    values.iter().map(|v| json_handle(v).map(owned_object)).collect()
}

fn players(faction: Option<MonoObject>) -> Result<bool, String> {
    match faction {
        Some(f) => is(&f, "isActivePlayer"),
        None => Ok(false),
    }
}

fn defended_value() -> Result<f32, String> {
    let bits = DEFENDED_VALUE.load(Ordering::Relaxed);
    if bits != 0 {
        return Ok(f32::from_bits(bits));
    }
    let config = json_handle(&invoke_static(
        "PavonisInteractive.TerraInvicta.TemplateManager",
        "get_global",
        &json!([]),
    )?)
    .map(owned_object)
    .ok_or("TemplateManager.global is null")?;
    let value = config
        .read_field("TIMissionModifier_DefendedAsset")?
        .as_f64()
        .ok_or("TIMissionModifier_DefendedAsset: not a number")? as f32;
    DEFENDED_VALUE.store(value.to_bits(), Ordering::Relaxed);
    Ok(value)
}

fn warn(what: &str, e: String) {
    log(LogLevel::Warn, &format!("terrainvicta-mod: base defense {what}: {e}"));
}

/// GetModifier(attackingCouncilor, target, resourcesSpent, resource).
extern "C" fn on_defended_asset(instance: *const c_void, args: *const c_char, result: f32) -> f32 {
    drop(owned_object(instance as isize as i32));
    let args = take_args(args);
    if result != 0.0 {
        return result;
    }
    let Some(Some(target)) = args.get(1) else {
        return result;
    };
    let undefended_players = || -> Result<bool, String> {
        if is(target, "isControlPointState")? {
            let cp = member_object(target, "ref_controlPoint")?.ok_or("no control point")?;
            return Ok(!is(&cp, "defended")? && players(member_object(&cp, "faction")?)?);
        }
        if is(target, "isHabState")? {
            let hab = member_object(target, "ref_hab")?.ok_or("no hab")?;
            return Ok(!is(&hab, "coreDefended")? && players(member_object(&hab, "faction")?)?);
        }
        Ok(false)
    };
    match undefended_players().and_then(|yes| Ok(if yes { defended_value()? * SHARE } else { result })) {
        Ok(v) => v,
        Err(e) => {
            warn("defended asset", e);
            result
        }
    }
}

/// GetModifier(attackingCouncilor, target, resourcesSpent, resource).
extern "C" fn on_coup_defense(instance: *const c_void, args: *const c_char, result: f32) -> f32 {
    drop(owned_object(instance as isize as i32));
    let args = take_args(args);
    let (Some(Some(attacker)), Some(Some(target))) = (args.first(), args.get(1)) else {
        return result;
    };
    let extra = || -> Result<f32, String> {
        if players(member_object(attacker, "faction")?)? || !is(target, "isNationState")? {
            return Ok(0.0);
        }
        let nation = member_object(target, "ref_nation")?.ok_or("no nation")?;
        let points = member_object(&nation, "controlPoints")?.ok_or("no control points")?;
        let mut count = 0.0;
        for i in 0..points.list_len_or_zero()? {
            let Some(cp) = points.list_handle(i)?.map(owned_object) else {
                continue;
            };
            if !is(&cp, "defended")? && players(member_object(&cp, "faction")?)? {
                count += 1.0;
            }
        }
        Ok(count * SHARE)
    };
    match extra() {
        Ok(v) => result + v,
        Err(e) => {
            warn("coup", e);
            result
        }
    }
}
