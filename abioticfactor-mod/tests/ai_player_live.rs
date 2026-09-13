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
    let following = api.op("ai_player.follow", json!({"player": human}));
    println!("ai_player.follow: {}", if following.ok { following.result.to_string() } else { format!("{:?}", following.error) });
    assert!(following.ok, "ai_player.follow: {:?}", following.error);
}

#[test]
#[ignore = "stops Sophia following"]
fn follow_stop() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    let stopped = api.op("ai_player.follow", json!({"player": ""}));
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
    let following = api.op("ai_player.follow", json!({"player": human}));
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
    let stopped = api.op("ai_player.follow", json!({"player": ""}));
    assert!(stopped.ok, "stop following: {:?}", stopped.error);
    let covered = distance(&start, &last);
    println!("followed {covered:.0} units in 10 s");
    assert!(covered > 100.0, "her body did not move: {covered:.0} units");
}
