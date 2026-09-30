//! The player's councilors are never detained.
//!
//! Every detention, from an enemy Detain Councilor mission or from
//! being caught on a failed mission (Assassinate, Coup, Steal Project,
//! Sabotage, ...), goes through TICouncilorState.DetainCouncilor. This
//! skips it for the player's councilors. Its only caller that reads
//! the returned release date is the enemy's Detain mission, which puts
//! it in the enemy's result text; skipped, that date is blank.

use std::ffi::c_void;

use serde_json::{Value as Json, json};
use unityforge::hook::{HOOK_REGISTRY, HookCtx, patch_prefix_ctx};
use unityforge::mono::{LogLevel, MonoObject, json_handle, log, owned_object};

pub fn install() {
    match patch_prefix_ctx(
        "PavonisInteractive.TerraInvicta.TICouncilorState",
        "DetainCouncilor",
        HookCtx::Instance,
        on_detain,
    ) {
        Ok(hook) => {
            HOOK_REGISTRY.register(hook);
            log(LogLevel::Info, "terrainvicta-mod: councilor detention immunity armed");
        }
        Err(e) => log(
            LogLevel::Warn,
            &format!("terrainvicta-mod: detention immunity patch failed: {e}"),
        ),
    }
}

/// A field, or failing that a property getter.
fn member(obj: &MonoObject, name: &str) -> Result<Json, String> {
    obj.read_field(name)
        .or_else(|_| obj.invoke(&format!("get_{name}"), &json!([])))
}

fn players_councilor(councilor: &MonoObject) -> Result<bool, String> {
    let Some(faction) = json_handle(&member(councilor, "faction")?).map(owned_object) else {
        return Ok(false);
    };
    Ok(faction.invoke("get_isActivePlayer", &json!([]))?.as_bool() == Some(true))
}

extern "C" fn on_detain(ctx: *const c_void) -> i32 {
    let h = ctx as isize as i32;
    if h == 0 {
        return 0;
    }
    let councilor = owned_object(h);
    match players_councilor(&councilor) {
        Ok(true) => {
            let name = member(&councilor, "displayName").unwrap_or(Json::Null);
            log(
                LogLevel::Info,
                &format!("terrainvicta-mod: {name} would have been detained; immune"),
            );
            1
        }
        Ok(false) => 0,
        Err(e) => {
            log(
                LogLevel::Warn,
                &format!("terrainvicta-mod: detention immunity check: {e}"),
            );
            0
        }
    }
}
