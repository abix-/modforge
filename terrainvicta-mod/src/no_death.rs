//! The player's councilors do not die while on Earth.
//!
//! Every councilor death goes through TICouncilorState.KillCouncilor;
//! deaths from a mission's critical failure (Assault Alien Asset,
//! Assassinate, Detain, Control Space Asset, Seize Space Asset) go
//! through KillCouncilorOnMission first, which also posts the "killed"
//! notifications. Both are skipped for the player's councilors on
//! Earth: mission deaths, assassination, old age, attacks on a region,
//! event deaths. In space they still die: a councilor whose ship or
//! hab is destroyed (TISpaceShipState, TIHabState) would otherwise be
//! left aboard something that no longer exists.

use std::ffi::c_void;

use serde_json::{Value as Json, json};
use unityforge::hook::{HOOK_REGISTRY, HookCtx, patch_prefix_ctx};
use unityforge::mono::{LogLevel, MonoObject, json_handle, log, owned_object};

pub fn install() {
    for method in ["KillCouncilorOnMission", "KillCouncilor"] {
        match patch_prefix_ctx(
            "PavonisInteractive.TerraInvicta.TICouncilorState",
            method,
            HookCtx::Instance,
            on_kill,
        ) {
            Ok(hook) => HOOK_REGISTRY.register(hook),
            Err(e) => {
                log(
                    LogLevel::Warn,
                    &format!("terrainvicta-mod: no death {method} patch failed: {e}"),
                );
                return;
            }
        }
    }
    log(LogLevel::Info, "terrainvicta-mod: councilor death on Earth off (armed)");
}

/// A field, or failing that a property getter.
fn member(obj: &MonoObject, name: &str) -> Result<Json, String> {
    obj.read_field(name)
        .or_else(|_| obj.invoke(&format!("get_{name}"), &json!([])))
}

fn spared(councilor: &MonoObject) -> Result<bool, String> {
    let Some(faction) = json_handle(&member(councilor, "faction")?).map(owned_object) else {
        return Ok(false);
    };
    if member(&faction, "isActivePlayer")?.as_bool() != Some(true) {
        return Ok(false);
    }
    Ok(member(councilor, "OnEarth")?.as_bool() == Some(true))
}

extern "C" fn on_kill(ctx: *const c_void) -> i32 {
    let h = ctx as isize as i32;
    if h == 0 {
        return 0;
    }
    let councilor = owned_object(h);
    match spared(&councilor) {
        Ok(true) => {
            let name = member(&councilor, "displayName").unwrap_or(Json::Null);
            log(
                LogLevel::Info,
                &format!("terrainvicta-mod: {name} would have died; spared"),
            );
            1
        }
        Ok(false) => 0,
        Err(e) => {
            log(LogLevel::Warn, &format!("terrainvicta-mod: no death check: {e}"));
            0
        }
    }
}
