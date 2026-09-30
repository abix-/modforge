//! Ten times the org budget (Administration for org control) of the
//! player's councilors.
//!
//! Every read of a councilor's org budget calls
//! TICouncilorState.GetAttribute(Administration, ...,
//! adminForOrgControl: true): availableAdministration (adding orgs),
//! the org screen's x/n title, its confirm check, and the org removal
//! checks. The patch multiplies that result for the player's
//! councilors. GetAttribute is one of the game's busiest methods, so
//! the shim filters on its arguments (0 = attribute, 4 =
//! adminForOrgControl) and only those reads reach Rust.

use std::ffi::c_void;
use std::os::raw::c_char;
use std::sync::atomic::{AtomicBool, Ordering};
use std::time::Duration;

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use unityforge::hook::{HOOK_REGISTRY, patch_postfix_int_result};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{LogLevel, invoke_static, json_handle, log, owned_object};

const MULTIPLIER: i32 = 10;
/// CouncilorAttribute.Administration.
const ADMINISTRATION: i64 = 5;

/// Set only inside the org_budget op, on the main thread, to read the
/// game's own budget with the patch passing it through.
static PASS_THROUGH: AtomicBool = AtomicBool::new(false);

pub fn install() {
    match patch_postfix_int_result(
        "PavonisInteractive.TerraInvicta.TICouncilorState",
        "GetAttribute",
        &json!({"0": ADMINISTRATION, "4": true}),
        on_org_budget,
    ) {
        Ok(hook) => {
            HOOK_REGISTRY.register(hook);
            log(
                LogLevel::Info,
                &format!("terrainvicta-mod: org budget x{MULTIPLIER} armed"),
            );
        }
        Err(e) => log(
            LogLevel::Warn,
            &format!("terrainvicta-mod: org budget patch failed: {e}"),
        ),
    }
    OP_REGISTRY.register(OpDef::new(
        "org_budget",
        "Org budget of the player's first councilor as the game computes it and as the patch reports it",
        "{}",
        |_args| MAIN_QUEUE.run("org_budget", Duration::from_secs(5), budgets)?,
    ));
}

fn budgets() -> Result<Json, String> {
    let control = json_handle(&invoke_static("GameControl", "get_control", &json!([]))?)
        .map(owned_object)
        .ok_or("GameControl.control is null")?;
    let faction = json_handle(&control.invoke("get_activePlayer", &json!([]))?)
        .map(owned_object)
        .ok_or("no active player")?;
    let councilors = json_handle(&faction.read_field("councilors")?)
        .map(owned_object)
        .ok_or("no councilors")?;
    let councilor = councilors
        .list_handle(0)?
        .map(owned_object)
        .ok_or("no councilor")?;
    let read = || {
        councilor.invoke(
            "GetAttribute",
            &json!(["Administration", true, true, true, true, false, false]),
        )
    };
    PASS_THROUGH.store(true, Ordering::Relaxed);
    let game = read();
    PASS_THROUGH.store(false, Ordering::Relaxed);
    Ok(json!({"game_budget": game?, "patched_budget": read()?}))
}

extern "C" fn on_org_budget(instance: *const c_void, _args: *const c_char, budget: i32) -> i32 {
    let h = instance as isize as i32;
    if h == 0 {
        return budget;
    }
    let councilor = owned_object(h);
    if PASS_THROUGH.load(Ordering::Relaxed) {
        return budget;
    }
    let players = || -> Result<bool, String> {
        let faction = councilor
            .read_field("faction")
            .or_else(|_| councilor.invoke("get_faction", &json!([])))?;
        let Some(faction) = json_handle(&faction).map(owned_object) else {
            return Ok(false);
        };
        Ok(faction.invoke("get_isActivePlayer", &json!([]))?.as_bool() == Some(true))
    };
    match players() {
        Ok(true) => budget.saturating_mul(MULTIPLIER),
        Ok(false) => budget,
        Err(e) => {
            log(LogLevel::Warn, &format!("terrainvicta-mod: org budget player check: {e}"));
            budget
        }
    }
}
