//! Sophia explores: she perceives, remembers what she perceived, and walks
//! to something she remembers but has not yet been to. Every cycle:
//!
//! 1. perceive (her own AIPerceptionComponent, nothing else),
//! 2. remember every perceived thing in her profile's seen.json,
//! 3. if she is not walking, pick the nearest remembered thing she has not
//!    visited and walk there over the host's navigation mesh; a thing she
//!    reaches, or cannot path to, is marked visited.
//!
//! Nothing here looks the world up; her knowledge is only what she has seen.
use abioticfactor_client::profile::Seen;
use serde_json::{Value, json};
use std::time::Duration;

const EXPLORE_PERIOD: Duration = Duration::from_secs(2);
/// Close enough to count as having been there.
const VISIT_DISTANCE: f64 = 300.0;

/// Remember what she perceives right now; returns how many things were new.
fn remember(walker: &crate::ai_player::Walker) -> Result<usize, String> {
    let rows = crate::perception::perceived_rows(&walker.name)?;
    let mut seen = Seen::load(&walker.directory).map_err(|e| e.to_string())?;
    let mut new = 0;
    for row in rows {
        let Some(location) = row.location else { continue };
        // Players are company, not places; everything else is worth remembering.
        if row.class == "Abiotic_PlayerCharacter_C" { continue; }
        if seen.note(&row.name, &row.class, location) { new += 1; }
    }
    seen.save(&walker.directory).map_err(|e| e.to_string())?;
    Ok(new)
}

fn flat_distance(a: &[f64; 3], b: &[f64; 3]) -> f64 {
    ((a[0] - b[0]).powi(2) + (a[1] - b[1]).powi(2)).sqrt()
}

/// One explore cycle: remember, then walk toward the nearest unvisited memory.
fn cycle(walker: &crate::ai_player::Walker, walking_to: &mut Option<String>) -> Result<(), String> {
    let new = remember(walker)?;
    if new > 0 { ueforge::log!("AI player {} saw {new} new things", walker.name); }
    let mut seen = Seen::load(&walker.directory).map_err(|e| e.to_string())?;
    // Where she is: the host's copy of her character, the same read follow uses.
    let here = crate::nav::plan(&walker.name, crate::nav::Goal::Point([0.0; 3]), f64::INFINITY)?.from;
    if let Some(name) = walking_to.as_ref() {
        // The path follower owns the walk: planned once, it reports arrived or
        // stuck itself. Re-planning every cycle would restart it and its stuck
        // detection, and she stood wedged against a table forever (2026-09-13).
        let status = walker.travel_status().unwrap_or_default();
        let done = status == "arrived" || status == "stuck" || status == "cancelled" || status == "standing";
        if name == WANDER {
            if done { ueforge::log!("AI player {} wander ended: {status}", walker.name); *walking_to = None; }
            if walking_to.is_some() { return Ok(()); }
        } else if let Some(thing) = seen.things.get_mut(name) {
            if done || flat_distance(&here, &thing.location) <= VISIT_DISTANCE {
                thing.visited = true;
                ueforge::log!("AI player {} finished with {name} ({}): {status}", walker.name, thing.class);
                *walking_to = None;
                seen.save(&walker.directory).map_err(|e| e.to_string())?;
            }
            if walking_to.is_some() { return Ok(()); }
        } else {
            *walking_to = None;
        }
    }
    let next = seen.things.iter().filter(|(_, t)| !t.visited)
        .min_by(|a, b| flat_distance(&here, &a.1.location).total_cmp(&flat_distance(&here, &b.1.location)))
        .map(|(name, thing)| (name.clone(), thing.location, thing.class.clone()));
    let Some((name, location, class)) = next else { return wander(walker, here, walking_to); };
    match crate::ai_player::plan_travel(&walker.name, &walker.commands, crate::nav::Goal::Point(location), VISIT_DISTANCE) {
        Ok(reply) if reply["state"] == "standing" => {
            // Already there: nothing to walk.
            if let Some(thing) = seen.things.get_mut(&name) { thing.visited = true; }
            seen.save(&walker.directory).map_err(|e| e.to_string())?;
        }
        Ok(_) => { ueforge::log!("AI player {} exploring toward {name} ({class})", walker.name); *walking_to = Some(name); }
        Err(error) => {
            ueforge::log!("AI player {} cannot reach {name} ({class}): {error}", walker.name);
            if let Some(thing) = seen.things.get_mut(&name) { thing.visited = true; }
            seen.save(&walker.directory).map_err(|e| e.to_string())?;
        }
    }
    Ok(())
}

/// Nothing remembered is left to visit: walk somewhere she has not looked,
/// a reachable point WANDER_DISTANCE away in a random direction, so new
/// things enter her sight. Directions the mesh cannot path to are skipped.
const WANDER_DISTANCE: f64 = 1200.0;
const WANDER_TRIES: usize = 8;

fn wander(walker: &crate::ai_player::Walker, here: [f64; 3], walking_to: &mut Option<String>) -> Result<(), String> {
    for _ in 0..WANDER_TRIES {
        let angle = fastrand::f64() * std::f64::consts::TAU;
        let goal = [here[0] + WANDER_DISTANCE * angle.cos(), here[1] + WANDER_DISTANCE * angle.sin(), here[2]];
        match crate::ai_player::plan_travel(&walker.name, &walker.commands, crate::nav::Goal::Point(goal), VISIT_DISTANCE) {
            Ok(reply) if reply["state"] == "travel_requested" => {
                ueforge::log!("AI player {} wandering {:.0} degrees to {:.0},{:.0}", walker.name, angle.to_degrees(), goal[0], goal[1]);
                // A wander target is a place, not a thing; it is done when the follower says so.
                *walking_to = Some(WANDER.into());
                return Ok(());
            }
            _ => continue,
        }
    }
    ueforge::log!("AI player {} found no reachable direction to wander", walker.name);
    Ok(())
}

/// The name a wander walk carries in `walking_to`; never a remembered thing.
const WANDER: &str = "(wander)";

/// Start or stop exploring. Starting takes her walking from follow.
fn explore(args: &Value) -> Result<Value, String> {
    if !args["on"].as_bool().unwrap_or(true) {
        crate::ai_player::release_walking()?;
        return Ok(json!({"exploring": false}));
    }
    let walker = crate::ai_player::take_walking()?;
    let reply = json!({"name": walker.name, "exploring": true, "period_seconds": EXPLORE_PERIOD.as_secs(), "memory": walker.directory.join("seen.json")});
    std::thread::Builder::new().name("abiotic-ai-player-explore".into()).spawn(move || {
        let mut walking_to = None;
        while walker.alive() {
            if let Err(error) = cycle(&walker, &mut walking_to) { ueforge::log!("AI player {} exploring: {error}", walker.name); }
            std::thread::sleep(EXPLORE_PERIOD);
        }
        ueforge::log!("AI player {} stopped exploring", walker.name);
    }).map_err(|e| e.to_string())?;
    Ok(reply)
}

/// What she remembers: every thing she has ever seen, with visited flags.
fn memory(_: &Value) -> Result<Value, String> {
    let walker = {
        // Reading memory must not take her walking; only the directory is needed.
        let directory = crate::ai_player::session_directory()?;
        Seen::load(&directory).map_err(|e| e.to_string())?
    };
    let visited = walker.things.values().filter(|t| t.visited).count();
    Ok(json!({"things": walker.things.len(), "visited": visited, "seen": walker.things}))
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new("ai_player.explore", "Explore: perceive, remember everything seen in the profile's seen.json, walk to the nearest remembered unvisited thing; on=false stops", "{on?: bool}", explore),
        ueforge::ops::OpDef::new("ai_player.memory", "Everything the AI player has ever perceived, with visited flags", "{}", memory),
    ]);
}
