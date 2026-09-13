//! Permanent controls for mod-owned UDP AI players. Sophia is the first instance.
#[path = "common/spawn_trace.rs"]
#[allow(dead_code)]
mod spawn_trace;
use modforge::client::Api;
use serde_json::{Value, json};
use std::time::{Duration, Instant};

fn api() -> Api<Value> {
    Api::at(31260, "/debug").with_timeout(Duration::from_secs(10))
}

#[test]
#[ignore = "starts Sophia once through the installed host mod; leaves her connected for user verification"]
fn ai_player_joins_from_host_mod() {
    let api = api();
    let before = api.op("ai_player.status", json!({}));
    assert!(before.ok, "status: {:?}", before.error);
    assert_eq!(before.result["state"], "stopped", "do not replace an existing session");
    let profile_dir = abioticfactor_client::profile::directory().expect("Sophia instance profile");
    let started = api.op("ai_player.start", json!({"profile_dir":profile_dir}));
    assert!(started.ok, "start: {:?}", started.error);
    let deadline = Instant::now() + Duration::from_secs(45);
    loop {
        let status = api.op("ai_player.status", json!({}));
        assert!(status.ok, "status: {:?}", status.error);
        assert_ne!(status.result["state"], "finished", "UDP session exited: {}", status.result);
        if status.result["udp"]["possession_confirmed"] == true {
            println!("Mod-owned UDP possession confirmed; user verifies spawn: {}", status.result);
            return;
        }
        assert!(Instant::now() < deadline, "no possession confirmation: {}", status.result);
        std::thread::sleep(Duration::from_millis(500));
    }
}

#[test]
#[ignore = "prints every player in the hosted game by name with its host-side location"]
fn ai_player_host_players() {
    let players = api().op("players", json!({}));
    assert!(players.ok, "players: {:?}", players.error);
    for player in players.result["players"].as_array().into_iter().flatten() {
        println!("{} at {} character {}", player["name"], player["location"], player["character"]);
    }
}

#[test]
#[ignore = "gives Sophia the enemies' perception component and prints what she currently perceives"]
fn ai_player_host_perceive() {
    let api = api();
    // ABIOTIC_SENSES=AISenseConfig_Sight,AISenseConfig_Hearing limits which of the enemy's senses she gets (isolation runs).
    let senses: Vec<String> = std::env::var("ABIOTIC_SENSES").ok().into_iter().flat_map(|s| s.split(',').map(str::to_owned).collect::<Vec<_>>()).collect();
    // ABIOTIC_SOURCE picks the enemy component to copy from; ABIOTIC_SHARE=1 shares its config objects instead of cloning.
    let source = std::env::var("ABIOTIC_SOURCE").unwrap_or_default();
    let share = std::env::var("ABIOTIC_SHARE").is_ok_and(|v| v == "1");
    let added = api.op("ai_player.perceive", json!({"player": "Sophia", "senses": senses, "source": source, "share": share}));
    assert!(added.ok, "ai_player.perceive: {:?}", added.error);
    println!("{}", added.result);
    std::thread::sleep(std::time::Duration::from_secs(2));
    let seen = api.op("ai_player.perceived", json!({"player": "Sophia"}));
    assert!(seen.ok, "ai_player.perceived: {:?}", seen.error);
    println!("{}", seen.result);
}

#[test]
#[ignore = "spawns a real Exor soldier from the game assets near the human, gives Sophia the Exor's senses, prints what she perceives"]
fn ai_player_host_exor() {
    let api = api();
    let human = human_name(&api, "Sophia");
    let spawned = api.op("npc.spawn", json!({"spawner": "NPCSpawn_QuillExor", "near_player": human}));
    assert!(spawned.ok, "npc.spawn: {:?}", spawned.error);
    println!("{}", spawned.result);
    // The spawner may spawn with an effect delay rather than inside DebugSpawn; poll it.
    let mut npcs = json!({});
    for _ in 0..10 {
        std::thread::sleep(std::time::Duration::from_secs(2));
        let reply = api.op("npc.spawned", json!({"actor": spawned.result["actor"]}));
        assert!(reply.ok, "npc.spawned: {:?}", reply.error);
        npcs = reply.result;
        if npcs["count"].as_u64().unwrap_or(0) > 0 { break; }
    }
    println!("{npcs}");
    let added = api.op("ai_player.perceive", json!({"player": "Sophia"}));
    assert!(added.ok, "ai_player.perceive: {:?}", added.error);
    println!("{}", added.result);
    std::thread::sleep(std::time::Duration::from_secs(3));
    let seen = api.op("ai_player.perceived", json!({"player": "Sophia"}));
    assert!(seen.ok, "ai_player.perceived: {:?}", seen.error);
    println!("{}", seen.result);
}

#[test]
#[ignore = "reads the installed mod's Sophia UDP status"]
fn ai_player_host_status() {
    let status = api().op("ai_player.status", json!({}));
    assert!(status.ok, "status: {:?}", status.error);
    println!("{}", status.result);
}

#[test]
#[ignore = "sends Sophia's UDP respawn request through the installed host mod; user verifies her new body"]
fn ai_player_host_respawn() {
    let api = api();
    let before = api.op("ai_player.status", json!({}));
    assert!(before.ok, "status: {:?}", before.error);
    assert_eq!(before.result["state"], "running", "needs a running session: {}", before.result);
    let requested = api.op("ai_player.respawn", json!({}));
    assert!(requested.ok, "respawn: {:?}", requested.error);
    assert_eq!(requested.result["state"], "respawn_requested");
    let deadline = Instant::now() + Duration::from_secs(20);
    loop {
        let status = api.op("ai_player.status", json!({}));
        assert!(status.ok, "status: {:?}", status.error);
        assert_ne!(status.result["state"], "finished", "UDP session exited after respawn request: {}", status.result);
        let changed = status.result["udp"]["pawn"] != before.result["udp"]["pawn"]
            || status.result["udp"]["position"] != before.result["udp"]["position"];
        if changed || Instant::now() >= deadline {
            println!("before: {}\nafter: {}\nobserved pawn/position change: {changed}", before.result, status.result);
            return;
        }
        std::thread::sleep(Duration::from_millis(500));
    }
}

#[test]
#[ignore = "walks Sophia to the human over the host's navigation mesh; user watches her arrive"]
fn ai_player_host_travel() {
    let api = api();
    let status = api.op("ai_player.status", json!({}));
    assert!(status.ok, "status: {:?}", status.error);
    assert_eq!(status.result["state"], "running", "needs a running session: {}", status.result);
    let name = status.result["name"].as_str().expect("session player name").to_owned();
    // Players by the name on their player state, never by position.
    let players = |api: &Api<Value>| {
        let reply = api.op("players", json!({}));
        assert!(reply.ok, "players: {:?}", reply.error);
        reply.result["players"].as_array().cloned().unwrap_or_default()
    };
    let rows = players(&api);
    let ai_player = rows.iter().find(|p| p["name"] == name).expect("the AI player is in the game").clone();
    let human = rows.iter().find(|p| p["name"] != name).expect("the human is in the game").clone();
    println!("{name} at {}, {} at {}", ai_player["location"], human["name"], human["location"]);
    let requested = api.op("ai_player.travel", json!({"to_player": human["name"]}));
    assert!(requested.ok, "travel: {:?}", requested.error);
    println!("path: {}", requested.result["points"]);
    let deadline = Instant::now() + Duration::from_secs(90);
    loop {
        let status = api.op("ai_player.status", json!({}));
        assert!(status.ok, "status: {:?}", status.error);
        assert_ne!(status.result["state"], "finished", "UDP session exited during travel: {}", status.result);
        let travel = status.result["udp"]["travel"].as_str().unwrap_or("").to_owned();
        let host = players(&api).into_iter().find(|p| p["name"] == name).expect("AI player still present");
        println!("{travel}: host position {}, UDP position {}", host["location"], status.result["udp"]["position"]);
        if ["arrived", "stuck", "cancelled"].contains(&travel.as_str()) || Instant::now() >= deadline {
            println!("final: {}", status.result);
            assert_eq!(travel, "arrived", "{name} did not arrive");
            return;
        }
        std::thread::sleep(Duration::from_secs(2));
    }
}

/// The human is the one player whose name is not the session's.
fn human_name(api: &Api<Value>, session_name: &str) -> String {
    let reply = api.op("players", json!({}));
    assert!(reply.ok, "players: {:?}", reply.error);
    reply.result["players"].as_array().into_iter().flatten()
        .find(|p| p["name"] != session_name).expect("the human is in the game")["name"].as_str().unwrap().to_owned()
}

#[test]
#[ignore = "starts Sophia following the human and leaves her following; stop with ai_player_host_follow_stop"]
fn ai_player_host_follow_start() {
    let api = api();
    let status = api.op("ai_player.status", json!({}));
    assert!(status.ok, "status: {:?}", status.error);
    assert_eq!(status.result["state"], "running", "needs a running session: {}", status.result);
    let name = status.result["name"].as_str().expect("session player name").to_owned();
    let started = api.op("ai_player.follow", json!({"player": human_name(&api, &name)}));
    assert!(started.ok, "follow: {:?}", started.error);
    println!("{}", started.result);
}

#[test]
#[ignore = "stops Sophia following"]
fn ai_player_host_follow_stop() {
    let stopped = api().op("ai_player.follow", json!({"player": ""}));
    assert!(stopped.ok, "stop following: {:?}", stopped.error);
    println!("{}", stopped.result);
}

#[test]
#[ignore = "Sophia follows the human for a minute like a dog; user watches"]
fn ai_player_host_follow() {
    let api = api();
    let status = api.op("ai_player.status", json!({}));
    assert!(status.ok, "status: {:?}", status.error);
    assert_eq!(status.result["state"], "running", "needs a running session: {}", status.result);
    let name = status.result["name"].as_str().expect("session player name").to_owned();
    let players = |api: &Api<Value>| {
        let reply = api.op("players", json!({}));
        assert!(reply.ok, "players: {:?}", reply.error);
        reply.result["players"].as_array().cloned().unwrap_or_default()
    };
    let human = human_name(&api, &name);
    let started = api.op("ai_player.follow", json!({"player": human}));
    assert!(started.ok, "follow: {:?}", started.error);
    println!("{}", started.result);
    let gap = |rows: &[Value]| {
        let at = |who: &str| rows.iter().find(|p| p["name"] == who).and_then(|p| p["location"].as_array().cloned()).expect("player location");
        let (a, b) = (at(&name), at(&human));
        ((a[0].as_f64().unwrap() - b[0].as_f64().unwrap()).powi(2) + (a[1].as_f64().unwrap() - b[1].as_f64().unwrap()).powi(2)).sqrt()
    };
    // The players listing scans the object list on the game thread; read it sparingly.
    for second in (2..=60).step_by(2) {
        std::thread::sleep(Duration::from_secs(2));
        let status = api.op("ai_player.status", json!({}));
        assert_ne!(status.result["state"], "finished", "UDP session exited while following: {}", status.result);
        if second % 10 == 0 {
            println!("{second}s: gap {:.0} units, travel {}", gap(&players(&api)), status.result["udp"]["travel"]);
        } else {
            println!("{second}s: travel {}", status.result["udp"]["travel"]);
        }
    }
    let stopped = api.op("ai_player.follow", json!({"player": ""}));
    assert!(stopped.ok, "stop following: {:?}", stopped.error);
    println!("stopped following: {}", stopped.result);
}

/// Does a direct server-side attack call land? Walks Sophia to the nearest
/// live Pest, faces it, calls the character's own attack function repeatedly,
/// and watches the Pest's TotalCombinedHealth.
#[test]
#[ignore = "walks Sophia to the nearest Pest and attacks it through the character's own functions; user watches"]
fn ai_player_host_attack() {
    let api = api();
    let function = std::env::var("ABIOTIC_ATTACK_FUNCTION").unwrap_or_else(|_| "Try_AutoAttack".into());
    let status = api.op("ai_player.status", json!({}));
    assert!(status.ok, "status: {:?}", status.error);
    assert_eq!(status.result["state"], "running", "needs a running session: {}", status.result);
    let name = status.result["name"].as_str().expect("session player name").to_owned();
    let players = api.op("players", json!({}));
    let sophia = players.result["players"].as_array().into_iter().flatten().find(|p| p["name"] == name).expect("AI player in game").clone();
    let sophia_at = sophia["location"].as_array().expect("AI player location").iter().map(|v| v.as_f64().unwrap()).collect::<Vec<_>>();
    let context = u64::from_str_radix(sophia["character"].as_str().unwrap().trim_start_matches("0x"), 16).unwrap();
    let pests = api.op("actors_of_class", json!({"world_context": context, "class": "NPC_Monster_Pest_C"}));
    assert!(pests.ok, "pests: {:?}", pests.error);
    let distance = |p: &Value| p.as_array().map(|p| (0..2).map(|i| (p[i].as_f64().unwrap() - sophia_at[i]).powi(2)).sum::<f64>().sqrt()).unwrap_or(f64::MAX);
    let mut candidates: Vec<Value> = pests.result["actors"].as_array().cloned().unwrap_or_default();
    candidates.sort_by(|a, b| distance(&a["location"]).partial_cmp(&distance(&b["location"])).unwrap());
    assert!(!candidates.is_empty(), "no Pest loaded");
    let pest_address = |p: &Value| u64::from_str_radix(p["addr"].as_str().unwrap().trim_start_matches("0x"), 16).unwrap();
    let fields = spawn_trace::object_fields(&api, pest_address(&candidates[0])).expect("pest fields");
    let offset = |field: &str| fields.iter().find(|(n, _, _)| n == field).map(|(_, _, o)| *o).expect(field);
    let (health_offset, dead_offset) = (offset("TotalCombinedHealth"), offset("IsDead"));
    let read_f64 = |address: u64| -> f64 {
        let reply = api.op("read_bytes", json!({"instance_selector": format!("addr:0x{address:X}"), "length": 8}));
        f64::from_le_bytes(hex::decode(reply.result["bytes_hex"].as_str().unwrap()).unwrap().try_into().unwrap())
    };
    let read_u8 = |address: u64| -> u8 {
        let reply = api.op("read_bytes", json!({"instance_selector": format!("addr:0x{address:X}"), "length": 1}));
        hex::decode(reply.result["bytes_hex"].as_str().unwrap()).unwrap()[0]
    };
    let pest = candidates.iter().find(|p| read_u8(pest_address(p) + u64::from(dead_offset)) == 0).expect("a live Pest").clone();
    let (pest_at, pest_addr) = (pest["location"].clone(), pest_address(&pest));
    println!("{name} at {sophia_at:?}; nearest live Pest {} at {pest_at} ({:.0} units), health {:.1}", pest["name"], distance(&pest_at), read_f64(pest_addr + u64::from(health_offset)));
    // Walk to it.
    let walk = api.op("ai_player.travel", json!({"to": pest_at}));
    assert!(walk.ok, "travel: {:?}", walk.error);
    let deadline = Instant::now() + Duration::from_secs(60);
    loop {
        let status = api.op("ai_player.status", json!({}));
        let travel = status.result["udp"]["travel"].as_str().unwrap_or("").to_owned();
        if ["arrived", "stuck", "cancelled"].contains(&travel.as_str()) || Instant::now() >= deadline { println!("walk ended: {travel}"); break; }
        std::thread::sleep(Duration::from_secs(1));
    }
    // Attack while reading health.
    let before = read_f64(pest_addr + u64::from(health_offset));
    let mut lowest = before;
    for swing in 1..=12 {
        let hit = api.op("ai_player.attack", json!({"player": name, "function": function, "face": pest_at}));
        assert!(hit.ok, "attack: {:?}", hit.error);
        std::thread::sleep(Duration::from_millis(700));
        let health = read_f64(pest_addr + u64::from(health_offset));
        lowest = lowest.min(health);
        println!("swing {swing} ({function}): Pest health {health:.1}, dead {}", read_u8(pest_addr + u64::from(dead_offset)));
    }
    println!("Pest health before {before:.1}, lowest after {lowest:.1}; direct attack call landed: {}", lowest < before);
}

#[test]
#[ignore = "stops Sophia's mod-owned UDP session and waits for its worker"]
fn ai_player_host_stop() {
    let stopped = api().op("ai_player.stop", json!({}));
    assert!(stopped.ok, "stop: {:?}", stopped.error);
    assert_eq!(stopped.result["state"], "stopped");
    println!("{}", stopped.result);
}
