//! Missions granted to the player's councilors through their orgs.
//!
//! An org's granted missions are its own list, TIOrgState.missionsGranted,
//! which GetPossibleMissionList adds to its councilor's missions. The
//! game does not save it ([fsIgnore]): every load rebuilds it from the
//! org's template (TIOrgState.InitRunTimeValues). So the grant_org_mission
//! op adds the mission to the list and records (org template name,
//! mission) in GRANTS_FILE, and every campaign load (and hot reload
//! into a running campaign) adds the recorded missions back to the
//! player's orgs.

use std::collections::BTreeMap;
use std::ffi::c_void;
use std::time::Duration;

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use unityforge::hook::{HOOK_REGISTRY, HookCtx, patch_prefix_ctx};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{LogLevel, MonoObject, invoke_static, json_handle, log, owned_object};

/// Relative to the game's folder, the process's working directory.
const GRANTS_FILE: &str = "BepInEx/config/terrainvicta-mod-grants.json";

/// Org template name to the mission dataNames granted to it.
type Grants = BTreeMap<String, Vec<String>>;

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
            &format!("terrainvicta-mod: org missions load patch failed: {e}"),
        ),
    }
    OP_REGISTRY.register(OpDef::new(
        "grant_org_mission",
        "Grant `mission` (dataName) through an active org to the `count` councilors with the highest `stat` that cannot run it yet; remembered across loads",
        "{mission: str, count: int, stat: str}",
        |args| {
            let mission = args.get("mission").and_then(Json::as_str).ok_or("missing mission")?.to_string();
            let count = args.get("count").and_then(Json::as_u64).ok_or("missing count")? as usize;
            let stat = args.get("stat").and_then(Json::as_str).ok_or("missing stat")?.to_string();
            MAIN_QUEUE.run("grant_org_mission", Duration::from_secs(20), move || grant(&mission, count, &stat))?
        },
    ));
    // A hot reload lands in a running campaign, where the load patch
    // will not fire again.
    if let Ok(Some(faction)) = player() {
        if let Err(e) = reapply(&faction) {
            log(LogLevel::Warn, &format!("terrainvicta-mod: org missions reapply: {e}"));
        }
    }
}

/// A field, or failing that a property getter.
fn member(obj: &MonoObject, name: &str) -> Result<Json, String> {
    obj.read_field(name)
        .or_else(|_| obj.invoke(&format!("get_{name}"), &json!([])))
}

fn member_object(obj: &MonoObject, name: &str) -> Result<Option<MonoObject>, String> {
    Ok(json_handle(&member(obj, name)?).map(owned_object))
}

fn list(obj: &MonoObject) -> Result<Vec<MonoObject>, String> {
    let mut out = Vec::new();
    for i in 0..obj.list_len_or_zero()? {
        if let Some(item) = obj.list_handle(i)?.map(owned_object) {
            out.push(item);
        }
    }
    Ok(out)
}

fn text(obj: &MonoObject, name: &str) -> String {
    member(obj, name).ok().and_then(|v| v.as_str().map(str::to_string)).unwrap_or_default()
}

fn player() -> Result<Option<MonoObject>, String> {
    let Some(control) = json_handle(&invoke_static("GameControl", "get_control", &json!([]))?).map(owned_object) else {
        return Ok(None);
    };
    member_object(&control, "activePlayer")
}

fn load_grants() -> Grants {
    std::fs::read_to_string(GRANTS_FILE)
        .ok()
        .and_then(|s| serde_json::from_str(&s).ok())
        .unwrap_or_default()
}

fn save_grants(grants: &Grants) -> Result<(), String> {
    let s = serde_json::to_string_pretty(grants).map_err(|e| e.to_string())?;
    std::fs::write(GRANTS_FILE, s).map_err(|e| format!("write {GRANTS_FILE}: {e}"))
}

fn possible_missions(councilor: &MonoObject) -> Result<Vec<MonoObject>, String> {
    let possible = json_handle(&councilor.invoke(
        "GetPossibleMissionList",
        &json!([true, false, true, null, false]),
    )?)
    .map(owned_object)
    .ok_or("no mission list")?;
    list(&possible)
}

/// The mission template named `mission`, from the player's orgs'
/// granted missions or any of its councilors' missions.
fn mission_template(faction: &MonoObject, mission: &str) -> Result<Option<MonoObject>, String> {
    let councilors = member_object(faction, "councilors")?.ok_or("no councilors")?;
    for c in list(&councilors)? {
        for m in possible_missions(&c)? {
            if text(&m, "dataName") == mission {
                return Ok(Some(m));
            }
        }
    }
    Ok(None)
}

/// Add `template` to the org's granted missions unless it has it.
fn add_to_org(org: &MonoObject, template: &MonoObject, mission: &str) -> Result<bool, String> {
    let granted = member_object(org, "missionsGranted")?.ok_or("org has no missionsGranted")?;
    if list(&granted)?.iter().any(|m| text(m, "dataName") == mission) {
        return Ok(false);
    }
    granted.invoke("Add", &json!([{"$handle": template.handle().0}]))?;
    Ok(true)
}

/// Add every recorded grant to the player's orgs of that template.
fn reapply(faction: &MonoObject) -> Result<usize, String> {
    let grants = load_grants();
    if grants.is_empty() {
        return Ok(0);
    }
    let mut added = 0;
    let councilors = member_object(faction, "councilors")?.ok_or("no councilors")?;
    for c in list(&councilors)? {
        let Some(orgs) = member_object(&c, "orgs")? else {
            continue;
        };
        for org in list(&orgs)? {
            let Some(missions) = grants.get(&text(&org, "templateName")) else {
                continue;
            };
            for mission in missions {
                if let Some(template) = mission_template(faction, mission)? {
                    if add_to_org(&org, &template, mission)? {
                        added += 1;
                    }
                }
            }
        }
    }
    log(
        LogLevel::Info,
        &format!("terrainvicta-mod: org missions reapplied ({added} added)"),
    );
    Ok(added)
}

extern "C" fn on_campaign_loaded(ctx: *const c_void) -> i32 {
    drop(owned_object(ctx as isize as i32));
    match player() {
        Ok(Some(faction)) => {
            if let Err(e) = reapply(&faction) {
                log(LogLevel::Warn, &format!("terrainvicta-mod: org missions reapply: {e}"));
            }
        }
        Ok(None) => {}
        Err(e) => log(LogLevel::Warn, &format!("terrainvicta-mod: org missions: {e}")),
    }
    0
}

fn stat_of(councilor: &MonoObject, stat: &str) -> Result<i64, String> {
    councilor
        .invoke("GetAttribute", &json!([stat, true, true, true, false, false, false]))?
        .as_i64()
        .ok_or_else(|| "GetAttribute: not a number".to_string())
}

fn grant(mission: &str, count: usize, stat: &str) -> Result<Json, String> {
    let faction = player()?.ok_or("no active player")?;
    let template = mission_template(&faction, mission)?
        .ok_or_else(|| format!("none of the player's councilors can run {mission}, so its template was not found"))?;
    let councilors = member_object(&faction, "councilors")?.ok_or("no councilors")?;
    let mut candidates = Vec::new();
    for c in list(&councilors)? {
        if possible_missions(&c)?.iter().any(|m| text(m, "dataName") == mission) {
            continue;
        }
        candidates.push((stat_of(&c, stat)?, c));
    }
    candidates.sort_by(|a, b| b.0.cmp(&a.0));
    let mut grants = load_grants();
    let mut done = Vec::new();
    for (value, c) in candidates.into_iter().take(count) {
        let who = text(&c, "displayName");
        let Some(orgs) = member_object(&c, "activeOrgs")? else {
            done.push(json!({"councilor": who, "skipped": "no active org"}));
            continue;
        };
        let Some(org) = list(&orgs)?.into_iter().next() else {
            done.push(json!({"councilor": who, "skipped": "no active org"}));
            continue;
        };
        add_to_org(&org, &template, mission)?;
        let entry = grants.entry(text(&org, "templateName")).or_default();
        if !entry.iter().any(|m| m == mission) {
            entry.push(mission.to_string());
        }
        let now_can = possible_missions(&c)?.iter().any(|m| text(m, "dataName") == mission);
        done.push(json!({
            "councilor": who,
            stat: value,
            "org": text(&org, "displayName"),
            "can_run_now": now_can,
        }));
    }
    save_grants(&grants)?;
    Ok(json!({"mission": mission, "granted": done, "file": GRANTS_FILE}))
}
