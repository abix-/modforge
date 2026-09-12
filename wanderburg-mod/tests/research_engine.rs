//! First contact with Wanderburg (Unity 6000.0.63f1, IL2CPP) over
//! the control plane.
//!
//! Answers, from the live game:
//! - does the shim load the Rust DLL and answer ping, and which
//!   runtime it reports (IL2CPP expected)
//! - which ops the control plane offers on this build
//! - does walk_class find live objects of a class every Unity
//!   game has (UnityEngine.Camera), proving the reflection bridge
//!
//! ```text
//! k3sc cargo-lock test -p wanderburg-mod --test research_engine -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running so
//! the workspace suite stays green.

mod common;
use common::{api, find_instances, ping_or_skip};
use serde_json::json;

#[test]
fn ping_and_ops() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let r = api.op("ping", json!({}));
    println!("ping ok={} result={}", r.ok, r.result);
    let r = api.op("list_ops", json!({}));
    println!("list_ops ok={} result={}", r.ok, r.result);
}

#[test]
fn walk_camera() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    match find_instances(&api, "UnityEngine.Camera", false) {
        Ok(list) => {
            println!("UnityEngine.Camera instances: {}", list.len());
            for v in &list {
                println!("  {v}");
            }
        }
        Err(e) => println!("walk_class UnityEngine.Camera failed: {e}"),
    }
}
