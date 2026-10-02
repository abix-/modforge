//! How Obenseuer sizes a home with levels and rooms: its stairs, steps,
//! landings, rooms, ceilings and doorways, measured from the running game
//! (topside's stairwell, operator 2026-10-01).
//!
//! Read-only: walk_class, invoke_method, invoke_static on getters only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_apartment -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, handle_of, ping_or_skip};
use serde_json::json;

/// The numbers in a bounds string: "Center: (x, y, z), Extents: (x, y, z)".
fn bounds_of(text: &str) -> Option<([f64; 3], [f64; 3])> {
    let nums: Vec<f64> = text
        .split(|c: char| !(c.is_ascii_digit() || c == '.' || c == '-'))
        .filter_map(|s| s.parse().ok())
        .collect();
    (nums.len() == 6).then(|| ([nums[0], nums[1], nums[2]], [nums[3] * 2.0, nums[4] * 2.0, nums[5] * 2.0]))
}

/// Every collider within 12 m of the player's camera: its name, type,
/// centre and size in metres, sorted by name, in
/// docs/apartment-colliders.txt.
#[test]
fn every_collider_near_the_player_measured() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let camera = api.op("invoke_static", json!({"class": "UnityEngine.Camera", "method": "get_main", "args": []}));
    let t = handle_of(&camera.result).and_then(|h| handle_of(&api.op("invoke_method", json!({"handle": h, "method": "get_transform", "args": []})).result));
    let p = t.map(|t| api.op("invoke_method", json!({"handle": t, "method": "get_position", "args": []})).result).expect("the camera's position");
    let near = api.op("invoke_static", json!({"class": "UnityEngine.Physics", "method": "OverlapSphere", "args": [p.clone(), 12.0]}));
    let list = handle_of(&near.result).expect("OverlapSphere gave colliders");
    let n = unityforge::client::count_of(&api, list).unwrap_or(0);
    let mut rows = Vec::new();
    for i in 0..n {
        let item = api.op("invoke_method", json!({"handle": list, "method": "GetValue", "args": [i]}));
        let Some(h) = handle_of(&item.result) else { continue };
        let name = item.result["name"].as_str().unwrap_or("?").to_string();
        let kind = item.result["type"].as_str().unwrap_or("?").to_string();
        let b = api.op("invoke_method", json!({"handle": h, "method": "get_bounds", "args": []}));
        if let Some((c, s)) = b.result.as_str().and_then(bounds_of) {
            rows.push(format!(
                "{name:<40} {kind:<14} centre ({:7.2}, {:7.2}, {:7.2})  size ({:5.2}, {:5.2}, {:5.2})",
                c[0], c[1], c[2], s[0], s[1], s[2]
            ));
        }
        api.op("release_handle", json!({"handle": h}));
    }
    rows.sort();
    let path = format!("{}/docs/apartment-colliders.txt", env!("CARGO_MANIFEST_DIR"));
    let text = format!("camera at {p}\n{} colliders within 12 m (y is up)\n\n{}\n", rows.len(), rows.join("\n"));
    std::fs::write(&path, text).expect("write the measurements");
    println!("{} colliders measured into {path}", rows.len());
    assert!(!rows.is_empty(), "no collider measured");
}

/// The shape of what the game answers: the camera, one renderer as
/// `walk_class` lists it, and its bounds as `invoke_method` returns them.
#[test]
fn the_answers_shape() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let camera = api.op("invoke_static", json!({"class": "UnityEngine.Camera", "method": "get_main", "args": []}));
    println!("camera: {:?} {:?}", camera.result, camera.error);
    if let Some(h) = handle_of(&camera.result) {
        let t = api.op("invoke_method", json!({"handle": h, "method": "get_transform", "args": []}));
        println!("camera transform: {:?} {:?}", t.result, t.error);
        if let Some(t) = handle_of(&t.result) {
            let p = api.op("invoke_method", json!({"handle": t, "method": "get_position", "args": []}));
            println!("camera position: {:?} {:?}", p.result, p.error);
        }
    }
    let near = api.op(
        "invoke_static",
        json!({"class": "UnityEngine.Physics", "method": "OverlapSphere", "args": [{"x": 97.28, "y": -94.63, "z": 11.8}, 12.0]}),
    );
    println!("colliders near: {:?} {:?}", near.result, near.error);
    if let Some(h) = handle_of(&near.result) {
        let n = unityforge::client::count_of(&api, h);
        println!("count: {n:?}");
        let first = api.op("invoke_method", json!({"handle": h, "method": "GetValue", "args": [0]}));
        println!("first: {:?} {:?}", first.result, first.error);
        if let Some(c) = handle_of(&first.result) {
            let b = api.op("invoke_method", json!({"handle": c, "method": "get_bounds", "args": []}));
            println!("collider bounds: {:?} {:?}", b.result, b.error);
        }
    }
    let renderers = api.op("walk_class", json!({"class": "UnityEngine.MeshRenderer"}));
    let list = renderers.result.as_array().cloned().unwrap_or_default();
    println!("renderers: {} (error {:?}); first: {:?}", list.len(), renderers.error, list.first());
    if let Some(h) = list.first().and_then(handle_of) {
        let b = api.op("invoke_method", json!({"handle": h, "method": "get_bounds", "args": []}));
        println!("bounds: {:?} {:?}", b.result, b.error);
        let g = api.op("invoke_method", json!({"handle": h, "method": "get_gameObject", "args": []}));
        println!("gameObject: {:?} {:?}", g.result, g.error);
        if let Some(g) = handle_of(&g.result) {
            let n = api.op("invoke_method", json!({"handle": g, "method": "get_name", "args": []}));
            println!("name: {:?} {:?}", n.result, n.error);
        }
    }
}
