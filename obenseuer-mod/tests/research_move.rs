//! The move between two loaded areas (operator 2026-10-02): with the
//! Gatehouse loaded alongside (first copy wins, its own setup switched
//! off), put the player's character at the Gatehouse's player start
//! (its `info_player_spawn`) and see what works. The areas share one
//! world space, so the move is a position change; no scene load.
//!
//! Reloads the save first (src/investigate.rs), so it starts from one
//! clean area. Both areas stay loaded at the end; the player checks in the
//! game where they are, how it looks and whether they can move.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_move -- --nocapture
//! ```
//!
//! OBENSEUER_SECOND_AREA picks the area (default "Interior Tenement
//! Gatehouse"). SKIPs (prints why and passes) when the game is not running.

mod common;
use std::collections::HashSet;
use std::time::{Duration, Instant};

use common::{api, call, copies, handle_of, load_alongside, op, ping_or_skip, reload_save};
use serde_json::{Value, json};
use unityforge::client::Api;

fn position(api: &Api<Value>, h: i64) -> Value {
    let t = handle_of(&call(api, h, "get_transform", json!([]))).expect("transform");
    call(api, t, "get_position", json!([]))
}

#[test]
fn player_moved_into_the_second_area() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let second = std::env::var("OBENSEUER_SECOND_AREA").unwrap_or_else(|_| "Interior Tenement Gatehouse".into());

    reload_save(&api);
    let spawns_before: HashSet<i64> = copies(&api, "info_player_spawn").into_iter().map(|(id, _)| id).collect();
    let players_before: HashSet<i64> = copies(&api, "OpenSewerCharacterController").into_iter().map(|(id, _)| id).collect();
    let secs = load_alongside(&api, &second);
    println!("loaded {second} alongside in {secs:.2}s");

    let spawn = copies(&api, "info_player_spawn").into_iter().find(|(id, _)| !spawns_before.contains(id));
    let (_, spawn) = spawn.expect("the second area's info_player_spawn");
    let target = position(&api, spawn);
    let (_, player) = copies(&api, "OpenSewerCharacterController")
        .into_iter()
        .find(|(id, _)| players_before.contains(id))
        .expect("the first area's player character");
    println!("player at {}, the second area's start at {target}", position(&api, player));

    op(&api, "errors", json!({"mark": true}));
    let start = Instant::now();
    let t = handle_of(&call(&api, player, "get_transform", json!([]))).expect("player transform");
    call(&api, t, "set_position", json!([target]));
    if let Some(body) = handle_of(&call(&api, player, "GetComponent", json!(["Rigidbody"]))) {
        call(&api, body, "set_position", json!([target]));
        call(&api, body, "set_velocity", json!([{"x": 0.0, "y": 0.0, "z": 0.0}]));
    }
    println!("moved in {:.3}s; player now at {}", start.elapsed().as_secs_f64(), position(&api, player));

    std::thread::sleep(Duration::from_secs(3));
    println!("player 3 s later at {}", position(&api, player));
    let errors = op(&api, "errors", json!({}));
    println!("errors since the move: {}", errors["total"]);
    for g in errors["groups"].as_array().into_iter().flatten() {
        println!("  {}  {}  at {}", g["count"], g["error"], g["at"]);
    }
    println!("check in the game: where you are, how it looks, whether you can move");
}
