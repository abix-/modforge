//! Six council seats from the start.
//!
//! TIFactionState.maxCouncilSize is Min(6, 4 + the CouncilSize
//! effects). The only CouncilSize effect, Effect_IncreaseCouncilSize,
//! comes from the faction projects Clandestine Cells (5th seat) and
//! Covert Operations (6th). On every campaign load this completes both
//! for the player's faction the way the game's own giveproject command
//! does (TIFactionState.OnProjectComplete), which applies the effect.
//! The game saves completed projects, so each runs once per campaign.

use std::ffi::c_void;
use std::time::Duration;

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::hook::{HOOK_REGISTRY, HookCtx, patch_prefix_ctx};
use unityforge::mono::{LogLevel, MonoObject, invoke_static, json_handle, log, owned_object};

const NS: &str = "PavonisInteractive.TerraInvicta";

/// In prerequisite order: Covert Operations needs Clandestine Cells.
const SEAT_PROJECTS: [&str; 2] = ["Project_ClandestineCells", "Project_CovertOperations"];

pub fn install() {
    match patch_prefix_ctx(
        &format!("{NS}.TIMissionPhaseState"),
        "PostVisualizerCreationInit_6",
        HookCtx::Instance,
        on_campaign_loaded,
    ) {
        Ok(hook) => {
            HOOK_REGISTRY.register(hook);
            log(LogLevel::Info, "terrainvicta-mod: six council seats armed");
        }
        Err(e) => log(
            LogLevel::Warn,
            &format!("terrainvicta-mod: six council seats patch failed: {e}"),
        ),
    }
    OP_REGISTRY.register(OpDef::new(
        "grant_council_seats",
        "Complete the two council seat projects for the player now; returns the council seat count",
        "{}",
        |_args| MAIN_QUEUE.run("grant_council_seats", Duration::from_secs(5), grant_seats)?,
    ));
}

extern "C" fn on_campaign_loaded(ctx: *const c_void) -> i32 {
    // The handle is only the patch context; release it.
    drop(owned_object(ctx as isize as i32));
    if let Err(e) = grant_seats() {
        log(
            LogLevel::Warn,
            &format!("terrainvicta-mod: six council seats: {e}"),
        );
    }
    0
}

fn call_object(obj: &MonoObject, method: &str) -> Result<MonoObject, String> {
    json_handle(&obj.invoke(method, &json!([]))?)
        .map(owned_object)
        .ok_or_else(|| format!("{method} returned null"))
}

fn grant_seats() -> Result<Json, String> {
    let control = json_handle(&invoke_static("GameControl", "get_control", &json!([]))?)
        .map(owned_object)
        .ok_or("GameControl.control is null")?;
    let faction = call_object(&control, "get_activePlayer")?;
    let finished = call_object(&faction, "get_finishedProjectNames")?;
    let projects = json_handle(&invoke_static(
        &format!("{NS}.TIGlobalResearchState"),
        "GetAllProjects",
        &json!([]),
    )?)
    .map(owned_object)
    .ok_or("GetAllProjects returned null")?;

    for name in SEAT_PROJECTS {
        if finished.invoke("Contains", &json!([name]))?.as_bool() == Some(true) {
            continue;
        }
        let project = find_project(&projects, name)?;
        let slot = faction.invoke("GetSlotForProject", &json!([{"$handle": project.handle().0}]))?;
        faction.invoke(
            "OnProjectComplete",
            &json!([{"$handle": project.handle().0}, slot, false, false]),
        )?;
        log(LogLevel::Info, &format!("terrainvicta-mod: completed {name} for a council seat"));
    }
    let seats = faction.invoke("get_maxCouncilSize", &json!([]))?;
    log(LogLevel::Info, &format!("terrainvicta-mod: council seats: {seats}"));
    Ok(json!({"max_council_size": seats}))
}

fn find_project(projects: &MonoObject, name: &str) -> Result<MonoObject, String> {
    for i in 0..projects.list_len()? {
        let Some(project) = projects.list_handle(i)?.map(owned_object) else {
            continue;
        };
        if project.invoke("get_dataName", &json!([]))?.as_str() == Some(name) {
            return Ok(project);
        }
    }
    Err(format!("project {name} not found"))
}
