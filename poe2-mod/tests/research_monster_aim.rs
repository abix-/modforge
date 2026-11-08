//! Where monsters aim and walk, after ExileCore2's Actor.CurrentAction
//! (ActionWrapper Target, Destination, Skill) and Pathfinding
//! (WantMoveToPosition, DestinationNodes). ExileCore2 ships its
//! offsets scrambled; these were read from its compiled code
//! (ec2_native.txt, 2026-11-07):
//!
//! - Actor.get_CurrentAction: the action at Actor +0x230, else +0x238.
//! - ActionWrapper (0x118 bytes): Skill +0xD0, Target entity +0x108,
//!   Destination x, y ints +0x110, +0x114.
//! - Pathfinding (0x578 bytes): DestinationNodes +0x518 (moving when
//!   above 0), WantMoveToPosition ints +0x568, StayTime +0x574.
//!
//! ExileCore2 reads the actor skills at +0xB00 where GameHelper2 (and
//! poe2-mod) read +0xB08, so it may be a build behind: every offset
//! above is a claim this test checks. It also reports every place in
//! the action where the player's address sits, in case Target moved.
//!
//! Read-only. Run it while monsters attack the player:
//!
//! ```text
//! cargo run -p poe2-mod
//! k3sc cargo-lock test -p poe2-mod --test research_monster_aim -- --nocapture --test-threads=1
//! ```
//!
//! SKIPs (prints why and passes) when poe2-mod or the game is not running.

use modforge::memory_research::Remote;
use serde_json::{Value, json};
use std::collections::BTreeMap;
use std::time::Duration;

const ACTION: [u64; 2] = [0x230, 0x238];
const ACTION_SIZE: usize = 0x118;
const SKILL: usize = 0xD0;
const TARGET: usize = 0x108;
const DESTINATION: usize = 0x110;
const PATH_NODES: u64 = 0x518;
const WANT_MOVE_TO: u64 = 0x568;
const SAMPLES: usize = 20;
const EVERY: Duration = Duration::from_millis(250);
/// World units per grid cell (250 / 23).
const WORLD_PER_CELL: f32 = 250.0 / 23.0;

fn hex(v: &Value) -> u64 {
    match v {
        Value::Number(n) => n.as_u64().unwrap_or(0),
        Value::String(s) => u64::from_str_radix(s.trim_start_matches("0x"), 16).unwrap_or(0),
        _ => 0,
    }
}

fn int_at(b: &[u8], o: usize) -> i32 {
    i32::from_le_bytes(b[o..o + 4].try_into().unwrap())
}

fn word_at(b: &[u8], o: usize) -> u64 {
    u64::from_le_bytes(b[o..o + 8].try_into().unwrap())
}

#[test]
fn monsters_aim_at_the_player() {
    let r = Remote::at(17185);
    let me = match r.op("inspect", json!({})) {
        Ok(p) => p,
        Err(e) => {
            println!("SKIP: {e}");
            return;
        }
    };
    let player = hex(&me["address"]);
    println!("player {player:#x} at {}", me["entity"]["position"]);
    // How often each Target offset held the player, over every sample.
    let mut player_at: BTreeMap<usize, usize> = BTreeMap::new();
    let mut actions = 0;
    let mut targets_player = 0;
    for sample in 0..SAMPLES {
        let list = r.op("entities", json!({"path": "Metadata/Monsters"})).expect("entities");
        let monsters: Vec<Value> = list["awake"]["entities"]
            .as_array()
            .cloned()
            .unwrap_or_default()
            .into_iter()
            .filter(|e| e["life"]["health"]["current"].as_u64().unwrap_or(0) > 0 && e["friendly"] != true)
            .collect();
        for m in &monsters {
            let Ok(view) = r.op("inspect", json!({"id": m["id"]})) else {
                continue;
            };
            let parts = &view["parts"];
            let name = m["path"].as_str().unwrap_or("").rsplit('/').next().unwrap_or("").to_string();
            let pos = &m["position"];
            let cell = |i: usize| pos[i].as_f64().unwrap_or(0.0) as f32 / WORLD_PER_CELL;
            let mut line = format!("{sample:2} {name} at cell ({:.0}, {:.0})", cell(0), cell(1));
            if let Some(actor) = parts["Actor"].as_str().map(|s| hex(&json!(s))) {
                let w = r.words(actor + ACTION[0], 0x10);
                let action = if w[0] != 0 { w[0] } else { w[1] };
                if action != 0 {
                    actions += 1;
                    let b = r.bytes(action, ACTION_SIZE);
                    let target = word_at(&b, TARGET);
                    if target == player {
                        targets_player += 1;
                    }
                    for o in (0..ACTION_SIZE - 7).step_by(8) {
                        if word_at(&b, o) == player {
                            *player_at.entry(o).or_default() += 1;
                        }
                    }
                    line += &format!(
                        ", action {action:#x} target {target:#x}{} spot ({}, {}) skill {:#x}",
                        if target == player { " = PLAYER" } else { "" },
                        int_at(&b, DESTINATION),
                        int_at(&b, DESTINATION + 4),
                        word_at(&b, SKILL)
                    );
                }
            }
            if let Some(path) = parts["Pathfinding"].as_str().map(|s| hex(&json!(s))) {
                let b = r.bytes(path + PATH_NODES, 4);
                let goal = r.bytes(path + WANT_MOVE_TO, 8);
                line += &format!(
                    ", path nodes {} walk goal ({}, {})",
                    int_at(&b, 0),
                    int_at(&goal, 0),
                    int_at(&goal, 4)
                );
            }
            println!("{line}");
        }
        std::thread::sleep(EVERY);
    }
    println!("{actions} actions seen, {targets_player} with Target (+{TARGET:#x}) the player");
    println!("where the player's address sat in actions: {player_at:x?}");
    if actions == 0 {
        println!("SKIP: no monster was acting; fight something and run again");
        return;
    }
    assert!(
        targets_player > 0 || player_at.is_empty(),
        "the player sat in actions but never at +{TARGET:#x}: {player_at:x?}"
    );
}
