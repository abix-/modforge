//! Hurt hires flee, heal, and return to work the same day.
//!
//! Vanilla (read from the Cpp2IL dump): at low HP a hire's
//! `StaffLowHpMobGoalState` calls `StaffMobObject.FleeForDay`, which
//! calls `StaffManager.FleeForDay(staff)`: stop the job, assign a
//! `FledHomeStaffJob`, add a `GoHomeMobGoal`, toast "won't return till
//! tomorrow". The hire walks out of the store; `GoHomeMobGoalState`
//! then calls `StaffMobObject.Despawn`. Nothing heals them at home;
//! `OnDayPassed` brings them back next day waiting for a job.
//!
//! This mod:
//! - prefix on `StaffManager.FleeForDay`: save a clone of the hire's
//!   current job (`StaffJobCloner.Clone`), keyed by instance id. The
//!   flee itself still runs.
//! - prefix on `StaffMobObject.Despawn`: when a hire with a saved job
//!   and a `FledHomeStaffJob` reaches home, heal to full, clear the
//!   low-HP trigger, give the saved job back with `AssignJob`, and
//!   skip the despawn. `GoHomeMobGoalState` listens for `JobAssigned`
//!   while active and switches the hire to that job's goal.

use std::collections::HashMap;
use std::ffi::c_void;
use std::sync::{LazyLock, Mutex};

use serde_json::json;
use unityforge::hook::{HOOK_REGISTRY, HookCtx, patch_prefix_ctx};

use crate::ctx_object;
use unityforge::mono::{
    LogLevel, MonoObject, invoke_static, json_handle, keep_through_reload, log, owned_object, take_kept,
};

/// Saved job clone per hire instance id. The MonoObject keeps the
/// clone alive until it is handed back.
static SAVED: LazyLock<Mutex<HashMap<i64, MonoObject>>> =
    LazyLock::new(|| Mutex::new(HashMap::new()));

pub fn install() {
    for (class, method, ctx, cb) in [
        (
            "Il2CppRuntime.Staff.StaffManager",
            "FleeForDay",
            HookCtx::Arg0,
            on_flee as extern "C" fn(*const c_void) -> i32,
        ),
        (
            "Il2CppRuntime.Mob.Staff.StaffMobObject",
            "Despawn",
            HookCtx::Instance,
            on_despawn,
        ),
    ] {
        match patch_prefix_ctx(class, method, ctx, cb) {
            Ok(h) => HOOK_REGISTRY.register(h),
            Err(e) => log(
                LogLevel::Error,
                &format!("thewalkingtrade-mod: patch {class}.{method} FAILED: {e}"),
            ),
        }
    }
    take_over_saved();
    modforge::shutdown::SHUTDOWN_REGISTRY.register(modforge::shutdown::ShutdownHandlerDef {
        name: "twt flee_return: hand saved jobs over",
        order: 50,
        run: hand_over_saved,
    });
}

/// `modforge::handoff` key: `[[hire instance id, kept job handle], ...]`.
const HANDOFF: &str = "twt_flee_return_saved";

/// Hot reload: keep every saved job through the swap and leave the
/// list for the next generation, so a hire who fled before the reload
/// still comes back healed to that job.
fn hand_over_saved() {
    let saved: Vec<(i64, MonoObject)> = SAVED.lock().map(|mut s| s.drain().collect()).unwrap_or_default();
    let mut kept = Vec::new();
    for (id, job) in saved {
        match keep_through_reload(job) {
            Ok(h) => kept.push(json!([id, h])),
            Err(e) => log(LogLevel::Warn, &format!("thewalkingtrade-mod: flee: saved job dropped: {e}")),
        }
    }
    if !kept.is_empty() {
        modforge::handoff::put(HANDOFF, &json!(kept));
    }
}

/// The saved jobs a previous generation handed over, if any.
fn take_over_saved() {
    let Some(list) = modforge::handoff::take(HANDOFF) else { return };
    let mut n = 0;
    if let Ok(mut saved) = SAVED.lock() {
        for pair in list.as_array().into_iter().flatten() {
            if let (Some(id), Some(h)) = (pair[0].as_i64(), pair[1].as_i64()) {
                saved.insert(id, take_kept(h as i32));
                n += 1;
            }
        }
    }
    log(LogLevel::Info, &format!("thewalkingtrade-mod: flee: took over {n} saved job(s)"));
}

fn instance_id(staff: &MonoObject) -> Result<i64, String> {
    staff
        .invoke("GetInstanceID", &json!([]))?
        .as_i64()
        .ok_or_else(|| "GetInstanceID returned no number".to_string())
}

fn name_of(staff: &MonoObject) -> String {
    staff
        .invoke("get_Name", &json!([]))
        .ok()
        .and_then(|v| v.as_str().map(str::to_string))
        .unwrap_or_else(|| "?".into())
}

extern "C" fn on_flee(ctx: *const c_void) -> i32 {
    let _m = modforge::counters::measure("twt: hook: flee");
    let Some(staff) = ctx_object(ctx) else { return 0 };
    if let Err(e) = save_job(&staff) {
        log(LogLevel::Warn, &format!("thewalkingtrade-mod: flee: save job: {e}"));
    }
    // Never skip: the hire still flees.
    0
}

fn save_job(staff: &MonoObject) -> Result<(), String> {
    let id = instance_id(staff)?;
    let job = staff.invoke("get_Job", &json!([]))?;
    let Some(jh) = json_handle(&job) else {
        return Err("hire has no job".into());
    };
    let job = owned_object(jh);
    if is_fled_job(&job)? {
        return Ok(());
    }
    let clone = invoke_static(
        "Il2CppRuntime.Staff.StaffJobCloner",
        "Clone",
        &json!([{"$handle": jh}]),
    )?;
    let ch = json_handle(&clone).ok_or("StaffJobCloner.Clone returned no job")?;
    SAVED.lock().unwrap().insert(id, owned_object(ch));
    log(
        LogLevel::Info,
        &format!("thewalkingtrade-mod: {} fled; job saved", name_of(staff)),
    );
    Ok(())
}

fn is_fled_job(job: &MonoObject) -> Result<bool, String> {
    let s = job.invoke("ToString", &json!([]))?;
    Ok(s.as_str().is_some_and(|s| s.contains("FledHomeStaffJob")))
}

extern "C" fn on_despawn(ctx: *const c_void) -> i32 {
    let _m = modforge::counters::measure("twt: hook: hire despawn");
    let Some(staff) = ctx_object(ctx) else { return 0 };
    match return_to_work(&staff) {
        Ok(true) => 1,
        Ok(false) => 0,
        Err(e) => {
            log(LogLevel::Warn, &format!("thewalkingtrade-mod: return: {e}"));
            0
        }
    }
}

/// Heal and hand the saved job back. Ok(true) means the despawn is
/// skipped because the hire is going back to work.
fn return_to_work(staff: &MonoObject) -> Result<bool, String> {
    let id = instance_id(staff)?;
    if !SAVED.lock().unwrap().contains_key(&id) {
        return Ok(false);
    }
    let job = staff.invoke("get_Job", &json!([]))?;
    let Some(jh) = json_handle(&job) else { return Ok(false) };
    if !is_fled_job(&owned_object(jh))? {
        // Despawned for another reason (fired, day end): forget it.
        SAVED.lock().unwrap().remove(&id);
        return Ok(false);
    }
    let Some(saved) = SAVED.lock().unwrap().remove(&id) else { return Ok(false) };

    let dmg = staff.read_field("_damageable")?;
    let dh = json_handle(&dmg).ok_or("hire has no _damageable")?;
    let dmg = owned_object(dh);
    let max = dmg.invoke("get_MaxHealth", &json!([]))?;
    dmg.invoke("SetHealth", &json!([max]))?;
    staff.write_field("_lowHpTriggered", &json!(false))?;

    let sh = saved.handle().0;
    staff.invoke("AssignJob", &json!([{"$handle": sh}, false]))?;
    log(
        LogLevel::Info,
        &format!(
            "thewalkingtrade-mod: {} healed to {} and back to work",
            name_of(staff),
            max
        ),
    );
    Ok(true)
}
