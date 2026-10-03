//! Which cameras are drawing (operator 2026-10-02: after a door move with
//! the area swap, "my camera isnt right"). Lists every camera, switched on
//! or off, with its draw order, tag and parent objects, the main camera,
//! and the player character's state. A handful of cameras, so one
//! question each is fast.
//!
//! Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_cameras -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, call, call_static, copies, handle_of, ping_or_skip, top_path};
use serde_json::json;

#[test]
fn cameras_listed() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let main = handle_of(&call_static(&api, "UnityEngine.Camera", "get_main", json!([])));
    println!("main camera: {}", main.map_or("none".into(), |h| top_path(&api, h)));
    for (id, h) in copies(&api, "UnityEngine.Camera") {
        println!(
            "camera {id}: drawing {} depth {} tag {}  {}",
            call(&api, h, "get_isActiveAndEnabled", json!([])),
            call(&api, h, "get_depth", json!([])),
            call(&api, h, "get_tag", json!([])),
            top_path(&api, h)
        );
    }
    for (id, h) in copies(&api, "OpenSewerCharacterController") {
        println!("player character {id}: on {}  {}", call(&api, h, "get_isActiveAndEnabled", json!([])), top_path(&api, h));
    }
}
