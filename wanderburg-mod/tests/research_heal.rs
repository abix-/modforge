//! Does VM.Heal(amount) raise the castle's health, and is it
//! capped at maxHP? Proves the write path on this game before the
//! regen in src/regen.rs relies on it.
//!
//! This test CHANGES game state: it heals the player's castle by
//! 10 once. Run it inside a run with the game window focused.
//!
//! ```text
//! k3sc cargo-lock test -p wanderburg-mod --test research_heal -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, first_handle, ping_or_skip};
use serde_json::{Value, json};

#[test]
fn heal_once() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let Some(vm) = first_handle(&api, "VM") else {
        println!("no live VM (not in a run, or the game is not ticking)");
        return;
    };
    let read = |field: &str| -> Value {
        api.op("read_field", json!({"handle": vm, "field": field})).result
    };
    let before = read("currentHP");
    let max = read("maxHP");
    println!("before: currentHP={before} maxHP={max}");
    let r = api.op("invoke_method", json!({"handle": vm, "method": "Heal", "args": [10.0]}));
    println!("Heal(10): ok={} result={} error={:?}", r.ok, r.result, r.error);
    let after = read("currentHP");
    println!("after:  currentHP={after} maxHP={max}");
    api.op("release_handle", json!({"handle": vm}));
}
