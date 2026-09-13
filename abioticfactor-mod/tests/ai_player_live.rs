//! Sophia in the hosted game, through the mod alone: join as the NPCs' AI
//! controller with a PlayerState (the Lyra bot pattern, npc-ai.md), stand
//! at the first world start, follow the human. Live; run with the hosted
//! save loaded and the human in the world.
//!
//! ```text
//! k3sc cargo-lock test -p abioticfactor-mod --test ai_player_live -- --nocapture
//! ```

mod common;
use common::{api, human_name, ping_or_skip};
use serde_json::{Value, json};

fn distance(a: &Value, b: &Value) -> f64 {
    (0..3).map(|i| a[i].as_f64().unwrap_or(0.0) - b[i].as_f64().unwrap_or(0.0)).map(|v| v * v).sum::<f64>().sqrt()
}

#[test]
#[ignore = "joins Sophia if needed and leaves her following the human; stop with follow_stop"]
fn follow_start() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    let human = human_name(&api, "Sophia");
    let joined = api.op("ai_player.start", json!({}));
    println!("ai_player.start: {}", if joined.ok { joined.result.to_string() } else { format!("{:?}", joined.error) });
    assert!(joined.ok, "ai_player.start: {:?}", joined.error);
    let following = api.op("ai_player.follow", json!({"target": human}));
    println!("ai_player.follow: {}", if following.ok { following.result.to_string() } else { format!("{:?}", following.error) });
    assert!(following.ok, "ai_player.follow: {:?}", following.error);
}

/// Her own tree: fight with the Exor's tree while enemies are counted,
/// otherwise follow the human. Joins with the Exor's controller class so
/// its tree asset and blackboard are in memory, gives her eyes, hands her
/// sightings to the controller every second, then builds and runs the tree.
#[test]
#[ignore = "joins Sophia with the Exor controller, gives her eyes, and runs her tree following the human; leave with ai_player.stop"]
fn tree_start() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    let human = human_name(&api, "Sophia");
    for (op, args) in [
        ("ai_player.start", json!({"controller_class": "AI_Controller_NPC_Exor_C"})),
        ("ai_player.perceive", json!({"player": "Sophia"})),
        ("ai_player.targets", json!({"on": true})),
        ("ai_player.tree", json!({"follow_key": "AllyTarget", "follow_player": human})),
    ] {
        let reply = api.op(op, args);
        println!("{op}: {}", if reply.ok { reply.result.to_string().chars().take(400).collect::<String>() } else { format!("{:?}", reply.error) });
        assert!(reply.ok, "{op}: {:?}", reply.error);
    }
}

#[test]
#[ignore = "prints where Sophia and the human are and the distance between them"]
fn where_is_she() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    let players = api.op("players", json!({}));
    assert!(players.ok, "players: {:?}", players.error);
    let rows = players.result["players"].as_array().cloned().unwrap_or_default();
    for p in &rows { println!("{} at {} faction {}", p["name"], p["location"], p["faction"]); }
    if let (Some(a), Some(b)) = (rows.iter().find(|p| p["name"] == "Sophia"), rows.iter().find(|p| p["name"] != "Sophia")) {
        println!("distance {:.0} units", distance(&a["location"], &b["location"]));
        // Is there a path between them on the host's navigation mesh?
        let path = api.op("nav.find_path", json!({"from": a["location"], "to": b["location"]}));
        println!("path: {}", if path.ok { format!("{} points", path.result["count"]) } else { format!("{:?}", path.error) });
    }
    let status = api.op("ai_player.status", json!({}));
    println!("status: {}", status.result);
}

/// Record what the game calls on her controller and body: the target
/// functions the decoded target choice names (npc-ai.md) and possession.
#[test]
#[ignore = "installs function watches on her controller and body; read with watch_log"]
fn watch_start() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    for (class, function) in [
        ("Abiotic_AI_Controller_ParentBP_C", "AddOrUpdatePotentialTarget"),
        ("Abiotic_AI_Controller_ParentBP_C", "CheckForNewBestTarget"),
        ("Abiotic_AI_Controller_ParentBP_C", "SetCurrentCombatTarget"),
        ("Abiotic_AI_Controller_ParentBP_C", "GetHostilityTowardsTarget"),
        ("Abiotic_PlayerCharacter_C", "ReceivePossessed"),
    ] {
        let reply = api.op("hook.watch", json!({"class": class, "function": function}));
        println!("hook.watch {class}::{function}: {}", if reply.ok { reply.result.to_string() } else { format!("{:?}", reply.error) });
    }
}

#[test]
#[ignore = "prints the recorded function calls"]
fn watch_log() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    let log = api.op("hook.log", json!({"limit": 60}));
    assert!(log.ok, "hook.log: {:?}", log.error);
    println!("watching: {}", log.result["watching"]);
    for call in log.result["calls"].as_array().into_iter().flatten() {
        println!("{}ms {} {}::{} {}", call["t_ms"], call["object"], call["class"], call["function"], call["params"]);
    }
    println!("{} calls", log.result["count"]);
}

#[test]
#[ignore = "stops Sophia following"]
fn follow_stop() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    let stopped = api.op("ai_player.follow", json!({"target": ""}));
    println!("ai_player.follow: {}", if stopped.ok { stopped.result.to_string() } else { format!("{:?}", stopped.error) });
    assert!(stopped.ok, "stop following: {:?}", stopped.error);
}

#[test]
fn sophia_joins_stands_at_the_world_start_and_follows() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    let human = human_name(&api, "Sophia");
    let joined = api.op("ai_player.start", json!({}));
    println!("ai_player.start: {}", if joined.ok { joined.result.to_string() } else { format!("{:?}", joined.error) });
    assert!(joined.ok, "ai_player.start: {:?}", joined.error);
    let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-mod/ai-player-join.json");
    std::fs::create_dir_all(path.parent().unwrap()).unwrap();
    std::fs::write(&path, serde_json::to_vec_pretty(&joined.result).unwrap()).unwrap();
    if joined.result["state"] == "joined" {
        assert_eq!(joined.result["pawn"]["class"], "Abiotic_PlayerCharacter_C", "the game mode did not give her the player class: {}", joined.result["pawn"]);
        assert_eq!(joined.result["teleported"], true, "TeleportPlayer to the world start refused");
    }

    // She is a player now: the players op lists her by the name on her PlayerState.
    let players = api.op("players", json!({}));
    assert!(players.ok, "players: {:?}", players.error);
    let names: Vec<&str> = players.result["players"].as_array().into_iter().flatten().filter_map(|p| p["name"].as_str()).collect();
    println!("players: {names:?}");
    assert!(names.contains(&"Sophia"), "Sophia is not in the player list: {names:?}");

    // Follow: every two seconds her AI controller walks her toward the human.
    let before = api.op("ai_player.status", json!({}));
    assert!(before.ok, "ai_player.status: {:?}", before.error);
    let start = before.result["pawn"]["location"].clone();
    let following = api.op("ai_player.follow", json!({"target": human}));
    println!("ai_player.follow: {}", if following.ok { following.result.to_string() } else { format!("{:?}", following.error) });
    assert!(following.ok, "ai_player.follow: {:?}", following.error);
    let mut last = start.clone();
    for second in 1..=10 {
        std::thread::sleep(std::time::Duration::from_secs(1));
        let now = api.op("ai_player.status", json!({}));
        assert!(now.ok, "ai_player.status: {:?}", now.error);
        last = now.result["pawn"]["location"].clone();
        println!("{second}s: {last} move_status {}", now.result["move_status"]);
    }
    let stopped = api.op("ai_player.follow", json!({"target": ""}));
    assert!(stopped.ok, "stop following: {:?}", stopped.error);
    let covered = distance(&start, &last);
    println!("followed {covered:.0} units in 10 s");
    assert!(covered > 100.0, "her body did not move: {covered:.0} units");
}
