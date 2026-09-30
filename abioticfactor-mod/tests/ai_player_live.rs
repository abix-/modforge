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
    (0..3)
        .map(|i| a[i].as_f64().unwrap_or(0.0) - b[i].as_f64().unwrap_or(0.0))
        .map(|v| v * v)
        .sum::<f64>()
        .sqrt()
}

#[test]
#[ignore = "joins Sophia if needed and leaves her following the human; stop with follow_stop"]
fn follow_start() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let human = human_name(&api, "Sophia");
    let joined = api.op("ai_player.start", json!({}));
    println!(
        "ai_player.start: {}",
        if joined.ok {
            joined.result.to_string()
        } else {
            format!("{:?}", joined.error)
        }
    );
    assert!(joined.ok, "ai_player.start: {:?}", joined.error);
    let following = api.op("ai_player.follow", json!({"target": human}));
    println!(
        "ai_player.follow: {}",
        if following.ok {
            following.result.to_string()
        } else {
            format!("{:?}", following.error)
        }
    );
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
    if ping_or_skip(&api).is_none() {
        return;
    }
    let human = human_name(&api, "Sophia");
    for (op, args) in [
        (
            "ai_player.start",
            json!({"controller_class": "AI_Controller_NPC_Exor_C"}),
        ),
        // Beside the human: the world start has no path to every area the human may be in.
        (
            "ai_player.place",
            json!({"player": "Sophia", "near_player": human, "distance": 400.0}),
        ),
        ("ai_player.perceive", json!({"player": "Sophia"})),
        ("ai_player.targets", json!({"on": true})),
        (
            "ai_player.tree",
            json!({"follow_key": "AllyTarget", "follow_player": human}),
        ),
    ] {
        let reply = api.op(op, args);
        println!(
            "{op}: {}",
            if reply.ok {
                reply
                    .result
                    .to_string()
                    .chars()
                    .take(400)
                    .collect::<String>()
            } else {
                format!("{:?}", reply.error)
            }
        );
        assert!(reply.ok, "{op}: {:?}", reply.error);
    }
}

#[test]
#[ignore = "prints where Sophia and the human are and the distance between them"]
fn where_is_she() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let players = api.op("players", json!({}));
    assert!(players.ok, "players: {:?}", players.error);
    let rows = players.result["players"]
        .as_array()
        .cloned()
        .unwrap_or_default();
    for p in &rows {
        println!(
            "{} at {} faction {}",
            p["name"], p["location"], p["faction"]
        );
    }
    if let (Some(a), Some(b)) = (
        rows.iter().find(|p| p["name"] == "Sophia"),
        rows.iter().find(|p| p["name"] != "Sophia"),
    ) {
        println!(
            "distance {:.0} units",
            distance(&a["location"], &b["location"])
        );
        // Is there a path between them on the host's navigation mesh?
        let path = api.op(
            "nav.find_path",
            json!({"from": a["location"], "to": b["location"]}),
        );
        println!(
            "path: {}",
            if path.ok {
                format!("{} points", path.result["count"])
            } else {
                format!("{:?}", path.error)
            }
        );
    }
    let status = api.op("ai_player.status", json!({}));
    println!("status: {}", status.result);
    // What she perceives, against the NPCs actually near her.
    let seen = api.op("ai_player.perceived", json!({"player": "Sophia"}));
    println!("perceived: {}", seen.result["perceived"]);
    let her = status.result["pawn"]["location"].clone();
    let pawn = u64::from_str_radix(
        status.result["pawn"]["addr"]
            .as_str()
            .unwrap_or("0x0")
            .trim_start_matches("0x"),
        16,
    )
    .unwrap_or(0);
    let npcs = api.op(
        "actors_of_class",
        json!({"world_context": pawn, "class": "Character"}),
    );
    let mut near: Vec<(f64, String, String)> = npcs.result["actors"]
        .as_array()
        .into_iter()
        .flatten()
        .filter(|a| a["class"].as_str().is_some_and(|c| c.starts_with("NPC_")))
        .map(|a| {
            (
                distance(&her, &a["location"]),
                a["class"].as_str().unwrap_or("").to_owned(),
                a["name"].as_str().unwrap_or("").to_owned(),
            )
        })
        .collect();
    near.sort_by(|a, b| a.0.total_cmp(&b.0));
    if near.is_empty() {
        println!(
            "actors_of_class reply: {}",
            npcs.result
                .to_string()
                .chars()
                .take(300)
                .collect::<String>()
        );
    }
    for (d, class, name) in near.iter().take(6) {
        println!("npc {d:.0} units: {class} {name}");
    }
    // Her eyes: where she faces, what her sight config says, whether the component is live.
    let controller = status.result["controller"]["addr"]
        .as_str()
        .unwrap_or("0x0")
        .to_owned();
    let facing = api.op(
        "object.get",
        json!({"object": format!("addr:{controller}"), "fields": ["ControlRotation"]}),
    );
    println!("control rotation: {}", facing.result);
    let root = api.op(
        "object.get",
        json!({"object": format!("addr:0x{pawn:X}"), "fields": ["RootComponent"]}),
    );
    if let Some(root_addr) = root.result["RootComponent"]["addr"].as_str() {
        let rotation = api.op(
            "object.get",
            json!({"object": format!("addr:{root_addr}"), "fields": ["RelativeRotation"]}),
        );
        println!("body rotation: {}", rotation.result);
    }
    if let Some((_, _, name)) = near.first() {
        let pest = npcs.result["actors"]
            .as_array()
            .into_iter()
            .flatten()
            .find(|a| a["name"] == *name)
            .cloned()
            .unwrap_or(Value::Null);
        let (dx, dy) = (
            pest["location"][0].as_f64().unwrap_or(0.0) - her[0].as_f64().unwrap_or(0.0),
            pest["location"][1].as_f64().unwrap_or(0.0) - her[1].as_f64().unwrap_or(0.0),
        );
        println!(
            "direction to nearest npc: yaw {:.0}",
            dy.atan2(dx).to_degrees()
        );
    }
    let component = api.op("ai_player.perceive", json!({"player": "Sophia"}));
    if let Some(component) = component.result["component"].as_str() {
        let fields = api.op("object.get", json!({"object": format!("addr:{component}"), "fields": ["bRegistered", "bIsActive", "AIOwner"]}));
        println!("perception component: {}", fields.result);
        let senses = api.op(
            "array.get",
            json!({"object": format!("addr:{component}"), "field": "SensesConfig"}),
        );
        for sense in senses.result["elements"].as_array().into_iter().flatten() {
            if let Some(addr) = sense["addr"].as_str() {
                let config = api.op("object.get", json!({"object": format!("addr:{addr}")}));
                println!(
                    "sense {}: {}",
                    sense["class"],
                    config
                        .result
                        .to_string()
                        .chars()
                        .take(500)
                        .collect::<String>()
                );
            }
        }
    }
    let sources = api.op("ai_player.sources", json!({}));
    println!("sources: {}", sources.result);
}

/// Record what the game calls on her controller and body: the target
/// functions the decoded target choice names (npc-ai.md) and possession.
#[test]
#[ignore = "installs function watches on her controller and body; read with watch_log"]
fn watch_start() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for (class, function) in [
        (
            "Abiotic_AI_Controller_ParentBP_C",
            "AddOrUpdatePotentialTarget",
        ),
        ("Abiotic_AI_Controller_ParentBP_C", "CheckForNewBestTarget"),
        ("Abiotic_AI_Controller_ParentBP_C", "SetCurrentCombatTarget"),
        (
            "Abiotic_AI_Controller_ParentBP_C",
            "GetHostilityTowardsTarget",
        ),
        ("Abiotic_PlayerCharacter_C", "ReceivePossessed"),
    ] {
        let reply = api.op("hook.watch", json!({"class": class, "function": function}));
        println!(
            "hook.watch {class}::{function}: {}",
            if reply.ok {
                reply.result.to_string()
            } else {
                format!("{:?}", reply.error)
            }
        );
    }
}

#[test]
#[ignore = "prints the recorded function calls"]
fn watch_log() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let log = api.op("hook.log", json!({"limit": 60}));
    assert!(log.ok, "hook.log: {:?}", log.error);
    println!("watching: {}", log.result["watching"]);
    for call in log.result["calls"].as_array().into_iter().flatten() {
        println!(
            "{}ms {} {}::{} {}",
            call["t_ms"], call["object"], call["class"], call["function"], call["params"]
        );
    }
    println!("{} calls", log.result["count"]);
}

#[test]
#[ignore = "teleports Sophia beside the human (ABIOTIC_DISTANCE units along +X, default 50)"]
fn place_near() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let human = human_name(&api, "Sophia");
    let distance: f64 = std::env::var("ABIOTIC_DISTANCE")
        .ok()
        .and_then(|d| d.parse().ok())
        .unwrap_or(50.0);
    let placed = api.op(
        "ai_player.place",
        json!({"player": "Sophia", "near_player": human, "distance": distance}),
    );
    println!(
        "ai_player.place: {}",
        if placed.ok {
            placed.result.to_string()
        } else {
            format!("{:?}", placed.error)
        }
    );
    assert!(placed.ok, "ai_player.place: {:?}", placed.error);
}

/// Her sight config copied from the narrative human detects enemies only;
/// with no team ids in this game everyone is neutral, so nothing is seen.
/// Set all three affiliation flags on the live config and rebuild the
/// listener, then read what she perceives. Generic ops, no rebuild.
#[test]
#[ignore = "sets Sophia's sight config to detect enemies, neutrals and friendlies, rebuilds her listener, reads what she sees"]
fn eyes_detect_everyone() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let component = api.op("ai_player.perceive", json!({"player": "Sophia"}));
    let component = component.result["component"]
        .as_str()
        .expect("her perception component")
        .to_owned();
    let senses = api.op(
        "array.get",
        json!({"object": format!("addr:{component}"), "field": "SensesConfig"}),
    );
    for sense in senses.result["elements"].as_array().into_iter().flatten() {
        let addr = sense["addr"].as_str().unwrap_or("0x0");
        let set = api.op("object.set", json!({"object": format!("addr:{addr}"), "fields": {"DetectionByAffiliation": {"bDetectEnemies": true, "bDetectNeutrals": true, "bDetectFriendlies": true}}}));
        println!(
            "set {} affiliation: {}",
            sense["class"],
            if set.ok {
                set.result.to_string()
            } else {
                format!("{:?}", set.error)
            }
        );
    }
    let rebuilt = api.op("object.call", json!({"object": format!("addr:{component}"), "class": "AIPerceptionComponent", "function": "RequestStimuliListenerUpdate"}));
    println!(
        "RequestStimuliListenerUpdate: {}",
        if rebuilt.ok {
            rebuilt.result.to_string()
        } else {
            format!("{:?}", rebuilt.error)
        }
    );
    std::thread::sleep(std::time::Duration::from_secs(2));
    let seen = api.op("ai_player.perceived", json!({"player": "Sophia"}));
    println!("perceived: {}", seen.result["perceived"]);
}

/// Why a monster in her cone and range is not perceived: is there line of
/// sight (a visibility trace from her to it), and is it registered as a
/// sight source (the engine's registration call answers true only when it
/// was not registered before).
#[test]
#[ignore = "traces line of sight from Sophia to the nearest NPC and checks its sight source registration"]
fn sight_check() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let status = api.op("ai_player.status", json!({}));
    let her = status.result["pawn"]["location"].clone();
    let pawn = status.result["pawn"]["addr"]
        .as_str()
        .unwrap_or("0x0")
        .to_owned();
    let pawn_addr = u64::from_str_radix(pawn.trim_start_matches("0x"), 16).unwrap_or(0);
    let npcs = api.op(
        "actors_of_class",
        json!({"world_context": pawn_addr, "class": "Character"}),
    );
    let mut near: Vec<(f64, Value)> = npcs.result["actors"]
        .as_array()
        .into_iter()
        .flatten()
        .filter(|a| a["class"].as_str().is_some_and(|c| c.starts_with("NPC_")))
        .map(|a| (distance(&her, &a["location"]), a.clone()))
        .collect();
    near.sort_by(|a, b| a.0.total_cmp(&b.0));
    let Some((d, npc)) = near.first() else {
        println!("no NPC near");
        return;
    };
    println!("nearest: {} {} at {d:.0} units", npc["class"], npc["name"]);
    let eye = json!({"X": her[0].as_f64().unwrap_or(0.0), "Y": her[1].as_f64().unwrap_or(0.0), "Z": her[2].as_f64().unwrap_or(0.0) + 60.0});
    let target = json!({"X": npc["location"][0], "Y": npc["location"][1], "Z": npc["location"][2].as_f64().unwrap_or(0.0) + 40.0});
    let trace = api.op("object.call", json!({"object": "singleton:KismetSystemLibrary", "class": "KismetSystemLibrary", "function": "LineTraceSingle",
        "params": {"WorldContextObject": pawn, "Start": eye, "End": target, "TraceChannel": 3, "bTraceComplex": false, "bIgnoreSelf": true, "ActorsToIgnore": [pawn]}}));
    println!(
        "visibility trace blocked: {} hit: {}",
        trace.result["ReturnValue"], trace.result["OutHit"]["HitObjectHandle"]
    );
    let registered = api.op("object.call", json!({"object": "singleton:AIPerceptionSystem", "class": "AIPerceptionSystem", "function": "RegisterPerceptionStimuliSource",
        "params": {"WorldContextObject": pawn, "Sense": "class:AISense_Sight", "Target": npc["addr"]}}));
    println!(
        "register as sight source now: {} (true means it was not registered before)",
        registered.result["ReturnValue"]
    );
}

#[test]
#[ignore = "stops Sophia following"]
fn follow_stop() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let stopped = api.op("ai_player.follow", json!({"target": ""}));
    println!(
        "ai_player.follow: {}",
        if stopped.ok {
            stopped.result.to_string()
        } else {
            format!("{:?}", stopped.error)
        }
    );
    assert!(stopped.ok, "stop following: {:?}", stopped.error);
}

#[test]
fn sophia_joins_stands_at_the_world_start_and_follows() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let human = human_name(&api, "Sophia");
    let joined = api.op("ai_player.start", json!({}));
    println!(
        "ai_player.start: {}",
        if joined.ok {
            joined.result.to_string()
        } else {
            format!("{:?}", joined.error)
        }
    );
    assert!(joined.ok, "ai_player.start: {:?}", joined.error);
    let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
        .join("../target/abioticfactor-mod/ai-player-join.json");
    std::fs::create_dir_all(path.parent().unwrap()).unwrap();
    std::fs::write(&path, serde_json::to_vec_pretty(&joined.result).unwrap()).unwrap();
    if joined.result["state"] == "joined" {
        assert_eq!(
            joined.result["pawn"]["class"], "Abiotic_PlayerCharacter_C",
            "the game mode did not give her the player class: {}",
            joined.result["pawn"]
        );
        assert_eq!(
            joined.result["teleported"], true,
            "TeleportPlayer to the world start refused"
        );
    }

    // She is a player now: the players op lists her by the name on her PlayerState.
    let players = api.op("players", json!({}));
    assert!(players.ok, "players: {:?}", players.error);
    let names: Vec<&str> = players.result["players"]
        .as_array()
        .into_iter()
        .flatten()
        .filter_map(|p| p["name"].as_str())
        .collect();
    println!("players: {names:?}");
    assert!(
        names.contains(&"Sophia"),
        "Sophia is not in the player list: {names:?}"
    );

    // Follow: every two seconds her AI controller walks her toward the human.
    let before = api.op("ai_player.status", json!({}));
    assert!(before.ok, "ai_player.status: {:?}", before.error);
    let start = before.result["pawn"]["location"].clone();
    let following = api.op("ai_player.follow", json!({"target": human}));
    println!(
        "ai_player.follow: {}",
        if following.ok {
            following.result.to_string()
        } else {
            format!("{:?}", following.error)
        }
    );
    assert!(following.ok, "ai_player.follow: {:?}", following.error);
    let mut last = start.clone();
    for second in 1..=10 {
        std::thread::sleep(std::time::Duration::from_secs(1));
        let now = api.op("ai_player.status", json!({}));
        assert!(now.ok, "ai_player.status: {:?}", now.error);
        last = now.result["pawn"]["location"].clone();
        println!(
            "{second}s: {last} move_status {}",
            now.result["move_status"]
        );
    }
    let stopped = api.op("ai_player.follow", json!({"target": ""}));
    assert!(stopped.ok, "stop following: {:?}", stopped.error);
    let covered = distance(&start, &last);
    println!("followed {covered:.0} units in 10 s");
    assert!(covered > 100.0, "her body did not move: {covered:.0} units");
}
