//! Works the player's craft at a station (garden bed, autopsy table) with
//! the game's per-hit step, free of energy.
//!
//! The game's own work goes through ToolComponent.ApplyAction, which takes
//! energy and insanity and wears the tool, then PlayerCraftActivity.UseTool
//! (craft UpdateManual). This calls UseTool alone: the craft advances, with
//! no energy, no insanity and no tool wear.
//!
//! Setup is the game's: PlayerController.SetCraftActivity(station), then
//! OnStartActivity, which starts the next queued craft. The tool is the one
//! the game would ask for (WGOInteractionHandlerBase
//! .GetRequiredInteractionToolType), taken from the tool belt.
//!
//! Pacing is the player's. Every tool is animation driven: the hit comes
//! from the swing clip's event (PlayerView.SendWorkActionAnimationEvent,
//! CallEvent1), once per loop of the clip ToolComponent plays for that tool
//! (AnimationState = tool type + 19). The first hit lands at the event's
//! time in the clip, then one hit per clip length, in game time
//! (Time.time), and none while the game is paused, as WorkPlayerState does.
//! The clip is read live from the player's Animator.

use parking_lot::Mutex;
use serde_json::{Value as Json, json};
use std::sync::atomic::{AtomicBool, Ordering};
use unityforge::bridge::MonoHandle;
use unityforge::mono::{LogLevel, MonoObject, MonoType, invoke_static, log};

use crate::take_all::{arg, call};
use crate::tweaks::{main_game, read_handle};

/// Upper bound on hits in one tick, for catching up after a long frame.
const MAX_HITS_PER_TICK: usize = 4;
/// Upper bound on ticks a job waits for the player or the craft before it
/// is dropped and left for the player. Swing waits do not count.
const MAX_WAIT_TICKS: u32 = 3600;
/// The swing clip's hit event (PlayerView.SendWorkActionAnimationEvent).
const HIT_EVENT: &str = "CallEvent1";

/// True when the station's work is finished.
pub(crate) type Done = fn(&MonoObject) -> Result<bool, String>;

struct Job {
    /// Station WgoData handle, owned here.
    station: i32,
    label: &'static str,
    done: Done,
    waits: u32,
    /// Game time of the next hit; None until a swing starts.
    next_hit: Option<f32>,
}

/// Per tool type: (seconds to the hit in the clip, clip length).
static SWINGS: Mutex<Vec<(Json, (f32, f32))>> = Mutex::new(Vec::new());

static JOBS: Mutex<Vec<Job>> = Mutex::new(Vec::new());
static HAS_JOBS: AtomicBool = AtomicBool::new(false);

/// Works `station` from the next tick until `done(station)`. Takes
/// ownership of the station handle. `label` prefixes the log lines.
pub(crate) fn queue(station: MonoObject, label: &'static str, done: Done) {
    let h = station.handle().0;
    std::mem::forget(station);
    JOBS.lock().push(Job { station: h, label, done, waits: 0, next_hit: None });
    HAS_JOBS.store(true, Ordering::Release);
}

// Runs on the Unity main thread.
pub fn on_tick() {
    if !HAS_JOBS.load(Ordering::Acquire) {
        return;
    }
    // WorkPlayerState does no work while the game is paused.
    if invoke_static("MainGame", "get_IsGamePaused", &json!([])).ok() == Some(json!(true)) {
        return;
    }
    let now = match invoke_static("UnityEngine.Time", "get_time", &json!([])) {
        Ok(t) => t.as_f64().unwrap_or(0.0) as f32,
        Err(e) => {
            log(LogLevel::Warn, &format!("work: Time.time: {e}"));
            return;
        }
    };
    let jobs = std::mem::take(&mut *JOBS.lock());
    let mut left = Vec::new();
    for mut job in jobs {
        let station = unsafe { MonoObject::from_handle(MonoHandle(job.station)) };
        let keep = match work(&station, job.label, job.done, &mut job.next_hit, now) {
            Ok(Worked::Done) => {
                log(LogLevel::Info, &format!("{}: work done", job.label));
                false
            }
            Ok(Worked::NoTool) => false,
            Ok(Worked::Swinging) => true,
            Ok(Worked::Wait) => {
                job.waits += 1;
                if job.waits >= MAX_WAIT_TICKS {
                    log(LogLevel::Warn, &format!("{}: gave up after {MAX_WAIT_TICKS} ticks", job.label));
                    false
                } else {
                    true
                }
            }
            Err(e) => {
                log(LogLevel::Warn, &format!("{}: {e}", job.label));
                false
            }
        };
        if keep {
            std::mem::forget(station);
            left.push(job);
        }
    }
    let mut list = JOBS.lock();
    list.extend(left);
    HAS_JOBS.store(!list.is_empty(), Ordering::Release);
}

enum Worked {
    /// `done` returned true.
    Done,
    /// Mid swing: the next hit is due on a later tick.
    Swinging,
    /// Try again next tick: the player is working something themselves, or
    /// the craft is between steps (finishing, or waiting on its queue).
    Wait,
    /// No tool of the needed type on the belt; left for the player.
    NoTool,
}

/// Lands the hits due by `now` on the station's current craft.
fn work(
    station: &MonoObject,
    label: &str,
    done: Done,
    next_hit: &mut Option<f32>,
    now: f32,
) -> Result<Worked, String> {
    if done(station)? {
        return Ok(Worked::Done);
    }
    let mg = main_game()?;
    let player = read_handle(&mg, "playerController")?;
    let pwc = call(&player, "get_PlayerWorkComponent", json!([]))?.ok_or("no PlayerWorkComponent")?;
    let tc = call(&pwc, "get_ToolComponent", json!([]))?.ok_or("no ToolComponent")?;
    if tc.invoke("get_IsActionActive", &json!([]))? == json!(true)
        || !player.invoke("get_WorkerActivity", &json!([]))?.is_null()
    {
        return Ok(Worked::Wait);
    }
    player.invoke("SetCraftActivity", &json!([arg(station)]))?;
    let result = hits(&player, station, label, done, next_hit, now);
    player.invoke("ClearWorkActivity", &json!([]))?;
    result
}

fn hits(
    player: &MonoObject,
    station: &MonoObject,
    label: &str,
    done: Done,
    next_hit: &mut Option<f32>,
    now: f32,
) -> Result<Worked, String> {
    let activity = call(player, "get_WorkerActivity", json!([]))?.ok_or("no work activity")?;
    activity.invoke("OnStartActivity", &json!([]))?;
    let cc = read_handle(station, "craftComponent")?;

    for _ in 0..MAX_HITS_PER_TICK {
        if done(station)? {
            return Ok(Worked::Done);
        }
        // Between crafts the swing stops; the next craft starts a new one.
        if cc.invoke("get_IsFinishDelayed", &json!([]))? == json!(true) {
            *next_hit = None;
            return Ok(Worked::Wait);
        }
        let Some(el) = call(&cc, "get_CurrentCraftElement", json!([]))? else {
            *next_hit = None;
            return Ok(Worked::Wait);
        };
        let def = call(&el, "get_Def", json!([]))?.ok_or("craft has no Def")?;
        let Some((tool, tool_type)) = belt_tool(player, station, &def, label)? else {
            return Ok(Worked::NoTool);
        };
        let (to_hit, clip) = swing(&tool_type)?;
        let due = *next_hit.get_or_insert(now + to_hit);
        if now < due {
            return Ok(Worked::Swinging);
        }
        activity.invoke("UseTool", &json!([arg(&tool), 1]))?;
        *next_hit = Some(due + clip);
    }
    Ok(Worked::Swinging)
}

/// (seconds to the hit, clip length) of the swing the player plays for
/// `tool_type`, read from the player's Animator and kept.
fn swing(tool_type: &Json) -> Result<(f32, f32), String> {
    if let Some((_, s)) = SWINGS.lock().iter().find(|(t, _)| t == tool_type) {
        return Ok(*s);
    }
    // AnimationState for the tool (type + 19) and its clip.
    let clip = match tool_type.as_str() {
        Some("Axe") => "tool_axe_down",
        Some("Shovel") => "tool_shovel_down",
        Some("Pickaxe") => "tool_pickaxe_down",
        Some("Hammer") => "tool_hammer_down",
        Some("Hand") => "tool_hands_down",
        _ => return Err(format!("no swing clip for tool {tool_type}")),
    };
    let s = read_clip(clip)?;
    SWINGS.lock().push((tool_type.clone(), s));
    Ok(s)
}

fn read_clip(name: &str) -> Result<(f32, f32), String> {
    let walk = MonoType::find("PlayerView").ok_or("PlayerView type not found")?.walk(false)?;
    let pv = walk
        .get("instances")
        .and_then(Json::as_array)
        .and_then(|a| a.first())
        .and_then(|i| i.get("handle"))
        .and_then(Json::as_i64)
        .ok_or("no PlayerView")? as i32;
    let pv = unsafe { MonoObject::from_handle(MonoHandle(pv)) };
    let anim = read_handle(&pv, "playerAnimation")?;
    let animator = read_handle(&anim, "animator")?;
    let ctrl = call(&animator, "get_runtimeAnimatorController", json!([]))?.ok_or("no animator controller")?;
    let clips = call(&ctrl, "get_animationClips", json!([]))?.ok_or("no clips")?;
    let n = clips.invoke("get_Length", &json!([]))?.as_i64().unwrap_or(0);
    for i in 0..n {
        let Some(c) = call(&clips, "GetValue", json!([i]))? else {
            continue;
        };
        if c.invoke("get_name", &json!([]))? != json!(name) {
            continue;
        }
        let len = c.invoke("get_length", &json!([]))?.as_f64().ok_or("clip has no length")? as f32;
        let events = call(&c, "get_events", json!([]))?.ok_or("clip has no events")?;
        let m = events.invoke("get_Length", &json!([]))?.as_i64().unwrap_or(0);
        for j in 0..m {
            let Some(e) = call(&events, "GetValue", json!([j]))? else {
                continue;
            };
            if e.invoke("get_functionName", &json!([]))? == json!(HIT_EVENT) {
                let at = e.invoke("get_time", &json!([]))?.as_f64().ok_or("event has no time")? as f32;
                log(LogLevel::Info, &format!("work: {name} hit at {at}s every {len}s"));
                return Ok((at, len));
            }
        }
        return Err(format!("{name} has no {HIT_EVENT}"));
    }
    Err(format!("no clip {name}"))
}

/// WGOInteractionHandlerBase.GetRequiredInteractionToolType, then that type
/// from the tool belt, with the type. None when the belt has no such tool.
fn belt_tool(
    player: &MonoObject,
    station: &MonoObject,
    def: &MonoObject,
    label: &str,
) -> Result<Option<(MonoObject, Json)>, String> {
    let custom = def.read_field("customItemTypeAction")?;
    let tool_type = if custom != json!("None") && def.read_field("isAuto")? != json!(true) {
        custom
    } else {
        let wdef = call(station, "get_Definition", json!([]))?.ok_or("station has no Definition")?;
        read_handle(&wdef, "toolAction")?.read_field("actionableTool")?
    };
    let pd = read_handle(player, "playerData")?;
    let belt = read_handle(&pd, "toolBeltInventory")?;
    let belt_data = call(&belt, "get_Data", json!([]))?.ok_or("tool belt has no Data")?;
    let tool = call(&belt_data, "GetItemByType", json!([tool_type]))?.ok_or("no tool")?;
    if tool.invoke("get_IsEmpty", &json!([]))? == json!(true) {
        log(LogLevel::Info, &format!("{label}: no {tool_type} on the tool belt"));
        return Ok(None);
    }
    Ok(Some((tool, tool_type)))
}
