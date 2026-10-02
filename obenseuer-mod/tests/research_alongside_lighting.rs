//! Which part of an area loaded alongside changes the first area's
//! lighting (operator 2026-10-02: after research_first_copy_wins.rs the
//! game worked but "the lighting seems off"). Two steps, run one at a
//! time while the player looks: switch off the second area's image
//! effects volumes, then its lights (the `alongside_off` op,
//! src/first_copy_wins.rs; only components that appeared after
//! first_copy_wins turned on).
//!
//! Run after research_first_copy_wins.rs, with both areas loaded:
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_alongside_lighting step1 -- --nocapture
//! k3sc cargo-lock test -p obenseuer-mod --test research_alongside_lighting step2 -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, ping_or_skip};
use serde_json::json;

fn switch_off(what: &str) {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let scenes = api.op("invoke_static", json!({"class": "UnityEngine.SceneManagement.SceneManager", "method": "get_sceneCount", "args": []}));
    assert_eq!(scenes.result.as_i64(), Some(2), "run research_first_copy_wins.rs first: two areas loaded");
    let r = api.op("alongside_off", json!({"what": what}));
    assert!(r.ok, "alongside_off {what}: {:?}", r.error);
    println!("{what}: {}", r.result);
    let errors = api.op("errors", json!({}));
    println!("errors since the load: {}", errors.result["total"]);
}

#[test]
fn step1_post_processing_off() {
    switch_off("post_processing");
}

#[test]
fn step2_lights_off() {
    switch_off("lights");
}

#[test]
fn step3_reflection_probes_off() {
    switch_off("reflection_probes");
}
