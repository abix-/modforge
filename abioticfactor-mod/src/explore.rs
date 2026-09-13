//! An AI player explores: she perceives, remembers what she perceived in her
//! persona's seen.json, and walks to something she remembers but has not
//! yet been to. The player's explore loop runs one cycle
//! (ai_player.explore_cycle) every two seconds:
//!
//! 1. perceive (her own AIPerceptionComponent, nothing else),
//! 2. remember every perceived thing,
//! 3. if she is not walking, pick the nearest remembered thing she has not
//!    visited and walk there over the host's navigation mesh; a thing she
//!    reaches, or cannot path to, is marked visited.
//!
//! Nothing here looks the world up; her knowledge is only what she has seen.
use modforge::persona::Seen;
use parking_lot::Mutex;
use serde_json::{Value, json};
use std::collections::BTreeMap;
use std::time::Duration;

const EXPLORE_PERIOD_MS: u64 = 2000;
/// Close enough to count as having been there.
const VISIT_DISTANCE: f64 = 300.0;
/// Nothing remembered is left to visit: walk somewhere she has not looked,
/// a reachable point this far away in a random direction, so new things
/// enter her sight. Directions the mesh cannot path to are skipped.
const WANDER_DISTANCE: f64 = 1200.0;
const WANDER_TRIES: usize = 8;
/// The name a wander walk carries in `walking_to`; never a remembered thing.
const WANDER: &str = "(wander)";

/// What each player's current walk is toward, between cycles.
static WALKING_TO: Mutex<BTreeMap<String, String>> = Mutex::new(BTreeMap::new());

/// Remember what she perceives right now; returns how many things were new.
fn remember(name: &str, directory: &std::path::Path) -> Result<usize, String> {
    let rows = crate::perception::perceived_rows(name)?;
    let mut seen = Seen::load(directory).map_err(|e| e.to_string())?;
    let mut new = 0;
    for row in rows {
        let Some(location) = row.location else { continue };
        // Players are company, not places; everything else is worth remembering.
        if row.class == "Abiotic_PlayerCharacter_C" { continue; }
        if seen.note(&row.name, &row.class, location) { new += 1; }
    }
    seen.save(directory).map_err(|e| e.to_string())?;
    Ok(new)
}

fn flat_distance(a: &[f64; 3], b: &[f64; 3]) -> f64 {
    ((a[0] - b[0]).powi(2) + (a[1] - b[1]).powi(2)).sqrt()
}

/// One explore cycle: remember, then walk toward the nearest unvisited memory.
fn cycle(args: &Value) -> Result<Value, String> {
    let name = crate::ai_player::player_name(args)?;
    let directory = crate::ai_player::session_directory(&name)?;
    let new = remember(&name, &directory)?;
    if new > 0 { ueforge::log!("AI player {name} saw {new} new things"); }
    let mut seen = Seen::load(&directory).map_err(|e| e.to_string())?;
    // Where she is: the host's copy of her character, the same read follow uses.
    let here = crate::nav::plan(&name, crate::nav::Goal::Point([0.0; 3]), f64::INFINITY)?.from;
    let current = WALKING_TO.lock().get(&name).cloned();
    if let Some(target) = current {
        // The AI controller's path following owns the walk: requested once, it
        // goes idle when it arrives or gives up. Re-requesting every cycle would
        // restart it, and she stood wedged against a table forever (2026-09-13).
        let status = crate::ai_player::move_status(&name)?;
        let done = status == "arrived";
        if target == WANDER {
            if done { ueforge::log!("AI player {name} wander ended"); WALKING_TO.lock().remove(&name); } else { return Ok(json!({"walking_to": WANDER, "status": status})); }
        } else if let Some(thing) = seen.things.get_mut(&target) {
            if done || flat_distance(&here, &thing.location) <= VISIT_DISTANCE {
                thing.visited = true;
                ueforge::log!("AI player {name} finished with {target} ({}): {status}", thing.class);
                WALKING_TO.lock().remove(&name);
                seen.save(&directory).map_err(|e| e.to_string())?;
            } else {
                return Ok(json!({"walking_to": target, "status": status}));
            }
        } else {
            WALKING_TO.lock().remove(&name);
        }
    }
    let next = seen.things.iter().filter(|(_, t)| !t.visited)
        .min_by(|a, b| flat_distance(&here, &a.1.location).total_cmp(&flat_distance(&here, &b.1.location)))
        .map(|(name, thing)| (name.clone(), thing.location, thing.class.clone()));
    let Some((target, location, class)) = next else { return wander(&name, here); };
    match crate::ai_player::walk_to(&name, crate::nav::Goal::Point(location), VISIT_DISTANCE) {
        Ok(reply) if reply["state"] == "standing" => {
            if let Some(thing) = seen.things.get_mut(&target) { thing.visited = true; }
            seen.save(&directory).map_err(|e| e.to_string())?;
            Ok(json!({"visited_standing": target}))
        }
        Ok(_) => { ueforge::log!("AI player {name} exploring toward {target} ({class})"); WALKING_TO.lock().insert(name, target.clone()); Ok(json!({"walking_to": target})) }
        Err(error) => {
            ueforge::log!("AI player {name} cannot reach {target} ({class}): {error}");
            if let Some(thing) = seen.things.get_mut(&target) { thing.visited = true; }
            seen.save(&directory).map_err(|e| e.to_string())?;
            Ok(json!({"unreachable": target}))
        }
    }
}

fn wander(name: &str, here: [f64; 3]) -> Result<Value, String> {
    for _ in 0..WANDER_TRIES {
        let angle = fastrand::f64() * std::f64::consts::TAU;
        let goal = [here[0] + WANDER_DISTANCE * angle.cos(), here[1] + WANDER_DISTANCE * angle.sin(), here[2]];
        if let Ok(reply) = crate::ai_player::walk_to(name, crate::nav::Goal::Point(goal), VISIT_DISTANCE) {
            if reply["state"] == "travel_requested" {
                ueforge::log!("AI player {name} wandering {:.0} degrees to {:.0},{:.0}", angle.to_degrees(), goal[0], goal[1]);
                WALKING_TO.lock().insert(name.to_owned(), WANDER.into());
                return Ok(json!({"walking_to": WANDER, "degrees": angle.to_degrees()}));
            }
        }
    }
    ueforge::log!("AI player {name} found no reachable direction to wander");
    Ok(json!({"wander": "no reachable direction"}))
}

/// Start or stop exploring. Starting takes the player's walking from follow.
fn explore(args: &Value) -> Result<Value, String> {
    let name = crate::ai_player::player_name(args)?;
    WALKING_TO.lock().remove(&name);
    if !args["on"].as_bool().unwrap_or(true) {
        crate::ai_player::release_walking(&name)?;
        return Ok(json!({"name": name, "exploring": false}));
    }
    crate::ai_player::take_walking(&name, "explore");
    ueforge::loops::start(&crate::ai_player::loop_name(&name, "explore"), "ai_player.explore_cycle", json!({"player": name}), Duration::from_millis(EXPLORE_PERIOD_MS))
}

/// What she remembers: every thing she has ever seen, with visited flags.
fn memory(args: &Value) -> Result<Value, String> {
    let name = crate::ai_player::player_name(args)?;
    let seen = Seen::load(&crate::ai_player::session_directory(&name)?).map_err(|e| e.to_string())?;
    let visited = seen.things.values().filter(|t| t.visited).count();
    Ok(json!({"name": name, "things": seen.things.len(), "visited": visited, "seen": seen.things}))
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new("ai_player.explore", "Explore as a loop: perceive, remember everything seen in the persona's seen.json, walk to the nearest remembered unvisited thing; on=false stops", "{player?: str, on?: bool}", explore),
        ueforge::ops::OpDef::new("ai_player.explore_cycle", "One explore step (the explore loop runs it every two seconds)", "{player?: str}", cycle),
        ueforge::ops::OpDef::new("ai_player.memory", "Everything an AI player has ever perceived, with visited flags", "{player?: str}", memory),
    ]);
}
