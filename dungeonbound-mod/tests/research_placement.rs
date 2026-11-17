//! Placement bonuses: what the spots of the worn pieces add by the
//! game's own fold (from_player with the placements, less without) and
//! by the mod's port of the rules (placement.rs). Operator 2026-11-17:
//! "planner needs to take into account adjacney onuses on some itesm
//! too". Fields the game changes and the mod does not are the gaps
//! (grown stats are one; the trigger runes are another).

mod common;

use serde_json::json;

#[test]
fn research_placement() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let r = common::op(&api, "spots", json!({}));
    println!("board: {}", r["board"]);
    println!("empty cells: {}", r["empty"]);
    for w in r["worn"].as_array().into_iter().flatten() {
        println!("worn: {w}");
    }
    let game = r["game"].as_object().cloned().unwrap_or_default();
    let ours = r["mod"].as_object().cloned().unwrap_or_default();
    let mut keys: Vec<&String> = game.keys().chain(ours.keys()).collect();
    keys.sort();
    keys.dedup();
    let mut off = 0;
    for k in keys {
        let g = game.get(k).and_then(|v| v.as_f64()).unwrap_or(0.0);
        let m = ours.get(k).and_then(|v| v.as_f64()).unwrap_or(0.0);
        let same = (g - m).abs() <= 1.0 + g.abs() * 0.01;
        if !same {
            off += 1;
        }
        println!(
            "{k:<28} game {g:>10.3}  mod {m:>10.3}  {}",
            if same { "same" } else { "DIFFERENT" }
        );
    }
    println!("{off} fields differ");
}
