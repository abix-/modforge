//! Research: what really happens in a fight, from the game's own
//! battle log (combat_log.gd get_battle_bbcode), to find what the mod's
//! fight math (src/fight.rs) leaves out. Operator 2026-11-17: "go fix
//! the fight math". Read-only; run after a fight.

mod common;

use serde_json::json;

#[test]
fn research_battle_log() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let got = common::op(
        &api,
        "call_method",
        json!({"node": "/root/CombatLog", "method": "get_battle_bbcode", "args": [], "depth": 1}),
    );
    let text = got["result"].as_str().unwrap_or("").to_string();
    // Strip the bbcode tags to plain lines.
    let mut plain = String::new();
    let mut in_tag = false;
    for c in text.chars() {
        match c {
            '[' => in_tag = true,
            ']' => in_tag = false,
            _ if !in_tag => plain.push(c),
            _ => {}
        }
    }
    let lines: Vec<&str> = plain.lines().collect();
    println!("{} lines in the last battle", lines.len());
    for l in &lines {
        println!("  {l}");
    }
}
