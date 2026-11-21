//! One of Obenseuer's own police NPCs thinking through its modforge
//! Persona (docs/persona.md). It keeps its body and its job: its
//! Act_Police activity still patrols, questions and chases. Its Persona
//! remembers where it saw the player, and its brain decides only what the
//! job does not: the job is where it is asked to be, so with nothing
//! pressing the brain waits and leaves the job alone; hurt or threatened,
//! the brain's walk is carried out by the NPC's own controller.
//!
//! Operator, 2026-11-20: "taking one of the existing NPCs in these games
//! and making it smart... enhancing the existing gameplay instead of
//! adding crazy new things." Which calls are used is Claude's reading of
//! the decompiled game, not yet seen in the game.

use std::sync::Mutex;
use std::time::{Duration, SystemTime, UNIX_EPOCH};

use glam::Vec3;
use modforge::actor::ActorId;
use modforge::brain::{Brain, Do, Perception};
use modforge::memory::Known;
use modforge::ops::{OP_REGISTRY, OpDef};
use modforge::persona::{Persona, PersonaBinder, Profile, key_of};
use modforge::statetree::StateTree;
use modforge::survival::Need;
use serde_json::{Value as Json, json};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{LogLevel, MonoObject, json_handle, log, owned_object};

use crate::deposit::first_instance;

/// Think every this many frames (about twice a second at 60 fps). Claude's number.
const THINK_EVERY: u64 = 30;
/// Save the person every this many thinks. Claude's number.
const SAVE_EVERY: u64 = 20;
/// `Act_Police.State.ChasePlayer` (NPC/Act_Police.cs: Idle, Stand, Patrol,
/// Wander, ChasePlayer, ...).
const CHASE_PLAYER: i64 = 4;

/// The police NPC being a person, by its NPC id, with its Persona.
struct Hosted {
    id: i64,
    persona: Persona,
    brain: StateTree<Brain>,
    roll: modforge::monument::Roll,
    thinks: u64,
}

static HOSTED: Mutex<Option<Hosted>> = Mutex::new(None);
static FRAMES: std::sync::atomic::AtomicU64 = std::sync::atomic::AtomicU64::new(0);

pub fn install() {
    OP_REGISTRY.register(OpDef::new(
        "police_person",
        "Make one police NPC a modforge person (its job kept, its Persona thinking on top); on=false stops and saves it",
        "{on?: bool, id?: int}",
        |args| {
            let args = args.clone();
            MAIN_QUEUE.run_result("police_person", Duration::from_secs(5), move || command(&args))
        },
    ));
}

/// Called every frame on the main thread.
pub(crate) fn tick() {
    if FRAMES.fetch_add(1, std::sync::atomic::Ordering::Relaxed) % THINK_EVERY != 0 {
        return;
    }
    let mut hosted = HOSTED.lock().unwrap_or_else(|e| e.into_inner());
    let Some(person) = hosted.as_mut() else {
        return;
    };
    if let Err(error) = think(person) {
        log(LogLevel::Warn, &format!("obenseuer-mod: police person {}: {error}", person.id));
    }
}

fn command(args: &Json) -> Result<Json, String> {
    let mut hosted = HOSTED.lock().unwrap_or_else(|e| e.into_inner());
    if args["on"] == false {
        let Some(person) = hosted.take() else {
            return Ok(json!({"hosted": null}));
        };
        save(&person)?;
        return Ok(json!({"stopped": person.id}));
    }
    let police = police_activities()?;
    let job = match args["id"].as_i64() {
        Some(id) => police.into_iter().find(|p| npc_id(p).ok() == Some(id)).ok_or(format!("no police NPC {id}"))?,
        None => police.into_iter().next().ok_or("no police NPC on duty")?,
    };
    let id = npc_id(&job)?;
    let name = format!("police {id}");
    let directory = modforge::persona::directory(&name).map_err(|e| e.to_string())?;
    Profile::load_or_create(&directory, &name, "police").map_err(|e| e.to_string())?;
    let persona = Persona::load(&directory).map_err(|e| e.to_string())?;
    *hosted = Some(Hosted {
        id,
        persona,
        brain: brain_tree(),
        roll: modforge::monument::Roll::new(key_of(&name)),
        thinks: 0,
    });
    Ok(json!({"hosted": id, "folder": directory.display().to_string()}))
}

/// Its tree: the states every game shares (modforge brain).
fn brain_tree() -> StateTree<Brain> {
    let mut s = vec![modforge::brain::root()];
    modforge::brain::fighting_states(&mut s);
    modforge::brain::eat_carried_state(&mut s);
    modforge::brain::need_states(&mut s);
    modforge::brain::asked_states(&mut s);
    modforge::brain::look_states(&mut s);
    modforge::brain::wander_state(&mut s);
    StateTree { states: s }
}

/// Every running police job (`Crime.activePolices`, crime.md).
fn police_activities() -> Result<Vec<MonoObject>, String> {
    let crime = first_instance("Crime")?;
    let list = obj(&crime.read_field("activePolices")?).ok_or("Crime has no activePolices list")?;
    let count = list.list_len()?;
    let mut out = Vec::new();
    for i in 0..count {
        if let Some(handle) = list.list_handle(i)? {
            out.push(owned_object(handle));
        }
    }
    Ok(out)
}

/// The NPC id of a police job's NPC (`Activity._NPC`, `NPCController.ID`).
fn npc_id(job: &MonoObject) -> Result<i64, String> {
    let npc = obj(&job.read_field("_NPC")?).ok_or("police job has no NPC")?;
    npc.invoke("get_ID", &json!([]))?.as_i64().ok_or_else(|| "NPC ID is not a number".into())
}

fn think(person: &mut Hosted) -> Result<(), String> {
    let job = police_activities()?
        .into_iter()
        .find(|p| npc_id(p).ok() == Some(person.id))
        .ok_or("off duty or not in this area")?;
    let npc = obj(&job.read_field("_NPC")?).ok_or("police job has no NPC")?;
    let here = vec3(&obj(&npc.invoke("get_transform", &json!([]))?).ok_or("no transform")?.invoke("get_position", &json!([]))?)?;
    let fov = obj(&job.read_field("fov")?);
    let seen = match &fov {
        Some(fov) => fov.invoke("CheckIfPlayerIsDetected", &json!([true]))? == true,
        None => false,
    };
    let now = SystemTime::now().duration_since(UNIX_EPOCH).map_or(0, |d| d.as_secs());
    let player = if seen {
        let locator = first_instance("PlayerLocator")?;
        let at = vec3(&locator.invoke("get_playerHeadPosition", &json!([]))?)?;
        person.persona.memory.see(key_of("player"), "player", at, now);
        Some(at)
    } else {
        None
    };
    let chasing = job.read_field("state")?.as_i64() == Some(CHASE_PLAYER);
    let mut binder = PoliceBinder {
        now,
        position: here,
        health_fraction: health_fraction(&npc)?,
        hostile: player.filter(|_| chasing).map(|at| (ActorId(key_of("player")), at)),
        decided: Vec::new(),
    };
    modforge::persona::think(&mut binder, &mut person.persona, &person.brain, &mut person.roll);
    // Its job moves it; the brain's walk is carried out only when it is
    // not the job's own chase.
    let go = binder.decided.iter().rev().find_map(|a| match *a {
        modforge::actions::Action::Go { x, y, z } => Some(Vec3::new(x, y, z)),
        _ => None,
    });
    if let Some(go) = go.filter(|_| !chasing) {
        npc.invoke("SetTargetPosition", &json!([{"x": go.x, "y": go.y, "z": go.z}, 0.5, null]))?;
    }
    person.thinks += 1;
    if person.thinks % SAVE_EVERY == 0 {
        save(person)?;
    }
    Ok(())
}

/// Its health as a part of its most: the game's `NPC.NPCStats` (Health,
/// MaxHealth) when the NPC carries one, else whole. No game code changes
/// NPCStats (read in the decompiled code), so this stays 1 until
/// something hurts it.
fn health_fraction(npc: &MonoObject) -> Result<f32, String> {
    let Some(stats) = obj(&npc.invoke("GetComponent", &json!(["NPCStats"]))?) else {
        return Ok(1.0);
    };
    let health = stats.read_field("Health")?.as_f64().ok_or("NPCStats Health is not a number")?;
    let most = stats.read_field("MaxHealth")?.as_f64().ok_or("NPCStats MaxHealth is not a number")?;
    Ok(if most > 0.0 { (health / most) as f32 } else { 1.0 })
}

fn save(person: &Hosted) -> Result<(), String> {
    let directory = modforge::persona::directory(&format!("police {}", person.id)).map_err(|e| e.to_string())?;
    person.persona.save(&directory).map_err(|e| e.to_string())
}

/// What the police NPC senses this think, and what its brain decided.
struct PoliceBinder {
    now: u64,
    position: Vec3,
    health_fraction: f32,
    hostile: Option<(ActorId, Vec3)>,
    decided: Vec<modforge::actions::Action>,
}

impl PersonaBinder for PoliceBinder {
    fn perceive<'a>(&'a self, persona: &'a Persona, worth: &'a dyn Fn(&Known, Need) -> f32) -> Perception<'a> {
        Perception {
            now: self.now,
            position: self.position,
            yaw: 0.0,
            health_fraction: self.health_fraction,
            needs: persona.needs,
            home: None,
            behaviour: modforge::actor::Behaviour::Hunter,
            at_home: false,
            asleep: false,
            hostile: self.hostile,
            game: &(),
            night: false,
            carries_food: false,
            carries_drink: false,
            bags_full: false,
            memory: &persona.memory,
            personality: &persona.personality,
            worth,
            standable: &|_| true,
            reachable: &Vec::new,
            unknown: &|_| false,
            // Its job is where it is asked to be: with nothing pressing
            // the brain waits and the job moves it.
            asked: Some(self.position),
            trader: None,
        }
    }

    /// Nothing in Obenseuer answers its needs yet.
    fn worth(&self, _: &Known, _: Need) -> f32 {
        0.0
    }

    fn act(&mut self, actions: Vec<modforge::actions::Action>, _: Option<Do>) {
        self.decided = actions;
    }
}

/// A Unity Vector3 as the game returns it ({"x", "y", "z"}); Unity is y
/// up in metres, as the brain is.
fn vec3(v: &Json) -> Result<Vec3, String> {
    let c = |k: &str| v.get(k).and_then(Json::as_f64).map(|f| f as f32).ok_or_else(|| format!("vector has no {k}: {v}"));
    Ok(Vec3::new(c("x")?, c("y")?, c("z")?))
}

fn obj(v: &Json) -> Option<MonoObject> {
    json_handle(v).map(owned_object)
}
