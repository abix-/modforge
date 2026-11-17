//! Research: run the mod's own arrange op (src/arrange.rs) with force
//! and print its reasoning lines. Changes what is worn when the plan
//! beats it. Operator 2026-11-16: "we gotta use the item rigt???".

mod common;

use serde_json::json;

#[test]
fn research_arrange_now() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let r = common::op(&api, "arrange", json!({"force": true}));
    println!("changed: {}", r["changed"]);
    for l in r["lines"].as_array().into_iter().flatten() {
        println!("{}", l.as_str().unwrap_or("?"));
    }
}
