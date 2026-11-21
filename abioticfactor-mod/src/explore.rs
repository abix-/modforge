//! An AI player explores: she perceives, remembers what she perceived in her
//! persona's memory (modforge `Memory`, the one a brain reads), and walks to
//! something she remembers but has not yet been to. The player's explore
//! loop runs one cycle (ai_player.explore_cycle) every two seconds:
//!
//! 1. perceive (her own AIPerceptionComponent, nothing else),
//! 2. remember every perceived thing (a known thing, by its actor's name),
//! 3. if she is not walking, pick the nearest known thing she has not
//!    checked and walk there over the host's navigation mesh; a thing she
//!    reaches, or cannot path to, is checked.
//!
//! Nothing here looks the world up; her knowledge is only what she has seen.
use glam::Vec3;
use modforge::memory::Memory;
use modforge::persona::{key_of, load_memory, save_memory};
use parking_lot::Mutex;
use serde_json::{Value, json};
use std::collections::BTreeMap;
use std::time::{Duration, SystemTime, UNIX_EPOCH};

const EXPLORE_PERIOD_MS: u64 = 2000;
/// Close enough to count as having been there.
const VISIT_DISTANCE: f64 = 300.0;
/// Nothing remembered is left to visit: walk somewhere she has not looked,
/// a reachable point this far away in a random direction, so new things
/// enter her sight. Directions the mesh cannot path to are skipped.
const WANDER_DISTANCE: f64 = 1200.0;
const WANDER_TRIES: usize = 8;
/// What each player's current walk is toward, between cycles: a known
/// thing's key, or None for a wander.
static WALKING_TO: Mutex<BTreeMap<String, Option<u64>>> = Mutex::new(BTreeMap::new());

/// Her clock for memory: seconds since 1970, the same across sessions.
pub(crate) fn now() -> u64 {
    SystemTime::now().duration_since(UNIX_EPOCH).map_or(0, |d| d.as_secs())
}

/// The game's position as memory keeps it (glam, as every modforge person).
fn to_vec3(p: [f64; 3]) -> Vec3 {
    Vec3::new(p[0] as f32, p[1] as f32, p[2] as f32)
}

fn to_point(p: Vec3) -> [f64; 3] {
    [f64::from(p.x), f64::from(p.y), f64::from(p.z)]
}

/// Remember what she perceives right now; returns how many things were new.
fn remember(name: &str, memory: &mut Memory) -> Result<usize, String> {
    let rows = crate::perception::perceived_rows(name)?;
    let now = now();
    let mut new = 0;
    for row in rows {
        let Some(location) = row.location else {
            continue;
        };
        // Players are company, not places; everything else is worth remembering.
        if row.class == "Abiotic_PlayerCharacter_C" {
            continue;
        }
        let key = key_of(&row.name);
        if !memory.knows(key) {
            new += 1;
        }
        memory.see(key, &row.class, to_vec3(location), now);
    }
    Ok(new)
}

fn flat_distance(a: &[f64; 3], b: &[f64; 3]) -> f64 {
    ((a[0] - b[0]).powi(2) + (a[1] - b[1]).powi(2)).sqrt()
}

/// One explore cycle: remember, then walk toward the nearest unchecked memory.
fn cycle(args: &Value) -> Result<Value, String> {
    let name = crate::ai_player::player_name(args)?;
    let directory = crate::ai_player::session_directory(&name)?;
    let mut memory = load_memory(&directory).map_err(|e| e.to_string())?;
    let new = remember(&name, &mut memory)?;
    if new > 0 {
        ueforge::log!("AI player {name} saw {new} new things");
    }
    let save = |memory: &Memory| save_memory(&directory, memory).map_err(|e| e.to_string());
    save(&memory)?;
    // Where she is: the host's copy of her character, the same read follow uses.
    let here = crate::nav::plan(&name, crate::nav::Goal::Point([0.0; 3]), f64::INFINITY)?.from;
    let current = WALKING_TO.lock().get(&name).copied();
    if let Some(target) = current {
        // The AI controller's path following owns the walk: requested once, it
        // goes idle when it arrives or gives up. Re-requesting every cycle would
        // restart it, and she stood wedged against a table forever (2026-09-13).
        let status = crate::ai_player::move_status(&name)?;
        let done = status == "arrived";
        match target.and_then(|key| memory.known.iter().find(|k| k.key == key).cloned()) {
            None if target.is_none() => {
                if done {
                    ueforge::log!("AI player {name} wander ended");
                    WALKING_TO.lock().remove(&name);
                } else {
                    return Ok(json!({"walking_to": "wander", "status": status}));
                }
            }
            Some(thing) => {
                if done || flat_distance(&here, &to_point(thing.position)) <= VISIT_DISTANCE {
                    memory.visited(thing.key, now());
                    ueforge::log!("AI player {name} finished with {} ({}): {status}", thing.key, thing.kind);
                    WALKING_TO.lock().remove(&name);
                    save(&memory)?;
                } else {
                    return Ok(json!({"walking_to": thing.key, "status": status}));
                }
            }
            None => {
                WALKING_TO.lock().remove(&name);
            }
        }
    }
    let next = memory
        .known
        .iter()
        .filter(|k| k.checked_at.is_none())
        .min_by(|a, b| {
            flat_distance(&here, &to_point(a.position)).total_cmp(&flat_distance(&here, &to_point(b.position)))
        })
        .map(|k| (k.key, to_point(k.position), k.kind.clone()));
    let Some((target, location, class)) = next else {
        return wander(&name, here);
    };
    match crate::ai_player::walk_to(&name, crate::nav::Goal::Point(location), VISIT_DISTANCE) {
        Ok(reply) if reply["state"] == "standing" => {
            memory.visited(target, now());
            save(&memory)?;
            Ok(json!({"visited_standing": target}))
        }
        Ok(_) => {
            ueforge::log!("AI player {name} exploring toward {target} ({class})");
            WALKING_TO.lock().insert(name, Some(target));
            Ok(json!({"walking_to": target}))
        }
        Err(error) => {
            ueforge::log!("AI player {name} cannot reach {target} ({class}): {error}");
            memory.visited(target, now());
            save(&memory)?;
            Ok(json!({"unreachable": target}))
        }
    }
}

fn wander(name: &str, here: [f64; 3]) -> Result<Value, String> {
    for _ in 0..WANDER_TRIES {
        let angle = fastrand::f64() * std::f64::consts::TAU;
        let goal = [
            here[0] + WANDER_DISTANCE * angle.cos(),
            here[1] + WANDER_DISTANCE * angle.sin(),
            here[2],
        ];
        if let Ok(reply) =
            crate::ai_player::walk_to(name, crate::nav::Goal::Point(goal), VISIT_DISTANCE)
        {
            if reply["state"] == "travel_requested" {
                ueforge::log!(
                    "AI player {name} wandering {:.0} degrees to {:.0},{:.0}",
                    angle.to_degrees(),
                    goal[0],
                    goal[1]
                );
                WALKING_TO.lock().insert(name.to_owned(), None);
                return Ok(json!({"walking_to": "wander", "degrees": angle.to_degrees()}));
            }
        }
    }
    ueforge::log!("AI player {name} found no reachable direction to wander");
    Ok(json!({"wander": "no reachable direction"}))
}

/// Start or stop exploring. Starting takes the player's walking from follow.
fn explore(args: &Value) -> Result<Value, String> {
    let name = crate::ai_player::player_name(args)?;
    if crate::orders::active(&name) {
        return Err("AI player has an assignment; exploration is not an assignment yet".into());
    }
    WALKING_TO.lock().remove(&name);
    if !args["on"].as_bool().unwrap_or(true) {
        crate::ai_player::release_walking(&name)?;
        return Ok(json!({"name": name, "exploring": false}));
    }
    crate::ai_player::take_walking(&name, "explore");
    ueforge::loops::start(
        &crate::ai_player::loop_name(&name, "explore"),
        "ai_player.explore_cycle",
        json!({"player": name}),
        Duration::from_millis(EXPLORE_PERIOD_MS),
    )
}

/// What she remembers: every thing she knows, and which she has been to.
fn memory(args: &Value) -> Result<Value, String> {
    let name = crate::ai_player::player_name(args)?;
    let memory = load_memory(&crate::ai_player::session_directory(&name)?).map_err(|e| e.to_string())?;
    let visited = memory.known.iter().filter(|k| k.checked_at.is_some()).count();
    Ok(json!({"name": name, "things": memory.known.len(), "visited": visited, "known": memory.known}))
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new("ai_player.explore", "Explore as a loop: perceive, remember everything seen in the persona's memory, walk to the nearest known thing not yet been to; on=false stops", "{player?: str, on?: bool}", explore),
        ueforge::ops::OpDef::new("ai_player.explore_cycle", "One explore step (the explore loop runs it every two seconds)", "{player?: str}", cycle),
        ueforge::ops::OpDef::new("ai_player.memory", "Everything an AI player has ever perceived, with visited flags", "{player?: str}", memory),
    ]);
}
