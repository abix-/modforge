//! End-to-end companion assignments and native knife combat.
mod common;
use common::{api, human_name};
use serde_json::{Value, json};
use std::time::{Duration, Instant};

fn checked(api: &modforge::client::Api<Value>, op: &str, args: Value) -> Value {
    let reply = api.op(op, args);
    assert!(reply.ok, "{op}: {:?}", reply.error);
    reply.result
}
fn command(api: &modforge::client::Api<Value>, command: &str, mut args: Value) {
    args["player"] = json!("Sophia"); args["command"] = json!(command);
    println!("command: {}", checked(api, "ai_player.command", args));
    checked(api, "ai_player.order_tick", json!({"player": "Sophia"}));
}
fn state(api: &modforge::client::Api<Value>) -> Value {
    checked(api, "ai_player.orders", json!({})).as_array().unwrap().iter().find(|r| r["name"] == "Sophia").unwrap().clone()
}

#[test]
#[ignore = "reads the native task state when a companion tree has not stopped"]
fn companion_abort_diagnostics() {
    let api = api();
    let status = checked(&api, "ai_player.status", json!({"player": "Sophia"}));
    if std::env::var_os("ABIOTIC_STOP_DIAGNOSTIC").is_some() {
        checked(&api, "bt.stop", json!({"controller": format!("addr:{}", status["controller"]["addr"].as_str().unwrap())}));
    }
    println!("status: {status}");
    println!("orders: {}", state(&api));
    let brain = status["brain"]["brain"]["addr"].as_str().unwrap();
    let fields = checked(&api, "object.get", json!({"object": format!("addr:{brain}"), "fields": ["NodeInstances"]}));
    println!("brain: {fields}");
    for node in fields["NodeInstances"].as_array().into_iter().flatten() {
        if !node["class"].as_str().unwrap_or("").starts_with("BTT_") { continue; }
        for function in ["IsTaskAborting", "IsTaskExecuting"] {
            let result = checked(&api, "object.call", json!({"object": format!("addr:{}", node["addr"].as_str().unwrap()), "class": "BTTask_BlueprintBase", "function": function, "params": {}}));
            println!("{} {function}: {result}", node["class"]);
        }
    }
}

#[test]
#[ignore = "verifies Sophia follows the human without damage observer initialization blocking movement"]
fn follows_human_after_damage_observer_initializes() {
    let api = api();
    let human = human_name(&api, "Sophia");
    checked(&api, "ai_player.start", json!({"name": "Sophia", "near_player": human, "distance": 400.0}));
    command(&api, "follow", json!({"target": human}));
    let deadline = Instant::now() + Duration::from_secs(15);
    loop {
        let orders = state(&api);
        assert_ne!(orders["action"]["kind"], "blocked", "orders blocked: {orders}");
        let status = checked(&api, "ai_player.status", json!({"player": "Sophia"}));
        if orders["action"]["kind"] == "following" {
            let position: [f64; 3] = serde_json::from_value(status["pawn"]["location"].clone()).unwrap();
            let target: [f64; 3] = serde_json::from_value(orders["action"]["position"].clone()).unwrap();
            // Native navigation tests horizontal arrival separately from height.
            let distance = (position[0] - target[0]).hypot(position[1] - target[1]);
            let radius = orders["action"]["radius"].as_f64().unwrap();
            if distance <= radius + 10.0 {
                println!("following {human}: distance={distance:.1}, radius={radius:.1}; orders={orders}");
                return;
            }
        }
        assert!(Instant::now() < deadline, "did not reach follow range: {status}; {orders}");
        std::thread::sleep(Duration::from_millis(250));
    }
}

#[test]
#[ignore = "verifies group commands, independent stance and saved orders across NPC replacement"]
fn groups_and_respawn_preserve_orders() {
    let api = api();
    let human = human_name(&api, "Sophia");
    checked(&api, "ai_player.start", json!({"name": "Sophia", "near_player": human, "distance": 200.0}));
    command(&api, "follow", json!({"target": human}));
    command(&api, "groups", json!({"groups": ["companions"]}));
    checked(&api, "ai_player.command", json!({"group": "companions", "command": "stance", "stance": "passive"}));
    assert_eq!(state(&api)["definition"]["stance"], "passive");
    let before = state(&api)["definition"].clone();
    let bad = api.op("ai_player.command", json!({"all": true, "command": "limits", "limits": {"chase_distance": -1.0}}));
    assert!(!bad.ok);
    assert_eq!(state(&api)["definition"], before, "rejected command changed intent");
    checked(&api, "ai_player.respawn", json!({"player": "Sophia"}));
    assert_eq!(state(&api)["definition"], before, "respawn lost saved orders");
    command(&api, "stance", json!({"stance": "defensive"}));
}

#[test]
#[ignore = "tests passive/defensive responses to attributed native point damage and return to the post"]
fn automatic_stances_and_return() {
    defense_and_return(true);
}

#[test]
#[ignore = "verifies the custom NPC defends itself and returns after recall"]
fn self_defense_and_return() {
    defense_and_return(false);
}

fn defense_and_return(protect_human: bool) {
    let api = api();
    let human = human_name(&api, "Sophia");
    checked(&api, "ai_player.start", json!({"name": "Sophia", "near_player": human, "distance": 200.0}));
    checked(&api, "ai_player.respawn", json!({"player": "Sophia"}));
    command(&api, "follow", json!({"target": human}));
    command(&api, "stance", json!({"stance": "passive"}));
    std::thread::sleep(Duration::from_secs(2));
    command(&api, "hold", json!({}));
    let hold = state(&api)["definition"]["assignment"].clone();
    let status = checked(&api, "ai_player.status", json!({"player": "Sophia"}));
    let sophia = status["pawn"]["addr"].as_str().unwrap();
    let players = checked(&api, "players", json!({}));
    let protected = players["players"].as_array().unwrap().iter().find(|p| p["name"] == human).unwrap()["character"].as_str().unwrap();
    let victims = if protect_human { vec![protected, sophia] } else { vec![sophia] };
    for victim in victims {
        command(&api, "stance", json!({"stance": "passive"}));
        let spawner = checked(&api, "npc.spawn", json!({"spawner": "NPCSpawn_Pest", "near_player": human, "distance": 400.0}));
        checked(&api, "object.set", json!({"object": format!("addr:{}", spawner["actor"].as_str().unwrap()), "fields": {"OnlySpawnOnce": true}}));
        let enemy = checked(&api, "object.call", json!({"object": format!("addr:{}", spawner["actor"].as_str().unwrap()), "class": "Abiotic_NPCSpawn_ParentBP_C", "function": "TrySpawnNPC", "params": {"IsNight": false, "ForceSuccessByTrigger": true, "CheckOnlyNoSpawn": false}}));
        assert_eq!(enemy["Success"], true);
        let enemy_addr = enemy["SpawnedNPC"]["addr"].as_str().unwrap();
        let enemy_selector = format!("addr:{enemy_addr}");
        std::thread::sleep(Duration::from_secs(1));
        let controller = checked(&api, "object.get", json!({"object": enemy_selector, "fields": ["Controller"]}))["Controller"]["addr"].as_str().unwrap().to_owned();
        checked(&api, "bt.stop", json!({"controller": format!("addr:{controller}")}));
        let position = &hold["position"];
        checked(&api, "object.call", json!({"object": enemy_selector, "class": "Actor", "function": "K2_TeleportTo", "params": {
            "DestLocation": {"X": position[0].as_f64().unwrap() - 400.0, "Y": position[1], "Z": position[2]}, "DestRotation": {"Pitch": 0.0, "Yaw": 0.0, "Roll": 0.0}}}));
        checked(&api, "ai_player.order_tick", json!({"player": "Sophia"}));
        let before = checked(&api, "object.get", json!({"object": format!("addr:{victim}"), "fields": ["TotalCombinedHealth"]}))["TotalCombinedHealth"].as_f64().unwrap();
        assert!(before > 40.0, "not enough health for the damage-response test");
        let damage = checked(&api, "object.call", json!({"object": "singleton:GameplayStatics", "class": "GameplayStatics", "function": "ApplyPointDamage", "params": {
            "DamagedActor": victim, "BaseDamage": 10.0, "HitFromDirection": {"X": 1.0, "Y": 0.0, "Z": 0.0}, "HitInfo": {"BoneName": "spine1"},
            "EventInstigator": controller, "DamageCauser": enemy_addr, "DamageTypeClass": "class:DamageType_Sharp_Pest_C"}}));
        println!("damage to {victim}: {damage}");
        std::thread::sleep(Duration::from_millis(400));
        assert_ne!(state(&api)["action"]["kind"], "attacking", "passive retaliation");
        command(&api, "stance", json!({"stance": "defensive"}));
        let defended = state(&api);
        assert_eq!(defended["action"]["kind"], "attacking", "did not defend {victim}: {defended}");
        assert_eq!(defended["definition"]["assignment"], hold);
        command(&api, "recall", json!({}));
        assert_eq!(state(&api)["action"]["kind"], "returning");
        command(&api, "stance", json!({"stance": "passive"}));
        checked(&api, "object.call", json!({"object": enemy_selector, "class": "Actor", "function": "K2_DestroyActor", "params": {}}));
        checked(&api, "object.call", json!({"object": format!("addr:{}", spawner["actor"].as_str().unwrap()), "class": "Actor", "function": "K2_DestroyActor", "params": {}}));
        let deadline = Instant::now() + Duration::from_secs(8);
        while state(&api)["action"]["kind"] != "holding" && Instant::now() < deadline { std::thread::sleep(Duration::from_millis(250)); }
        assert_eq!(state(&api)["action"]["kind"], "holding");
        let idle = checked(&api, "ai_player.status", json!({"player": "Sophia"}));
        assert_eq!(idle["brain"]["running"], false, "combat tree did not stop after recall");
    }
    command(&api, "follow", json!({"target": human}));
    command(&api, "stance", json!({"stance": "defensive"}));
}

#[test]
#[ignore = "verifies aggressive sight acquisition and that a target beyond the chase limit is released"]
fn aggressive_sight_and_chase_limits() {
    let api = api();
    let human = human_name(&api, "Sophia");
    checked(&api, "ai_player.start", json!({"name": "Sophia", "near_player": human, "distance": 200.0}));
    command(&api, "stance", json!({"stance": "passive"}));
    std::thread::sleep(Duration::from_secs(2));
    command(&api, "hold", json!({}));
    let status = checked(&api, "ai_player.status", json!({"player": "Sophia"}));
    let pawn = status["pawn"]["addr"].as_str().unwrap();
    let spawner = checked(&api, "npc.spawn", json!({"spawner": "NPCSpawn_Pest", "near_player": human, "distance": 400.0}));
    let enemy = checked(&api, "object.call", json!({"object": format!("addr:{}", spawner["actor"].as_str().unwrap()), "class": "Abiotic_NPCSpawn_ParentBP_C", "function": "TrySpawnNPC", "params": {"IsNight": false, "ForceSuccessByTrigger": true, "CheckOnlyNoSpawn": false}}));
    assert_eq!(enemy["Success"], true);
    let enemy_addr = enemy["SpawnedNPC"]["addr"].as_str().unwrap();
    let selector = format!("addr:{enemy_addr}");
    std::thread::sleep(Duration::from_secs(1));
    let controller = checked(&api, "object.get", json!({"object": selector, "fields": ["Controller"]}))["Controller"]["addr"].as_str().unwrap().to_owned();
    checked(&api, "bt.stop", json!({"controller": format!("addr:{controller}")}));
    // A small Pest can fall through a gap beside the human's platform while
    // the human-sized NPC stays above it. Use the Pest's settled floor and
    // account for each actor's capsule instead of testing across two floors.
    let movement = checked(&api, "object.get", json!({"object": selector, "fields": ["CharacterMovement"]}))["CharacterMovement"]["addr"].as_str().unwrap().to_owned();
    let deadline = Instant::now() + Duration::from_secs(10);
    loop {
        let mode = checked(&api, "object.get", json!({"object": format!("addr:{movement}"), "fields": ["MovementMode"]}))["MovementMode"].as_u64().unwrap();
        if mode == 1 || mode == 2 { break; }
        assert!(Instant::now() < deadline, "encounter enemy never landed, movement mode={mode}");
        std::thread::sleep(Duration::from_millis(250));
    }
    let ground = checked(&api, "object.call", json!({"object": selector, "class": "Actor", "function": "K2_GetActorLocation", "params": {}}))["ReturnValue"].clone();
    println!("encounter floor: {ground}");
    let half_height = |actor: &str| {
        let capsule = checked(&api, "object.get", json!({"object": format!("addr:{actor}"), "fields": ["CapsuleComponent"]}))["CapsuleComponent"]["addr"].as_str().unwrap().to_owned();
        checked(&api, "object.call", json!({"object": format!("addr:{capsule}"), "class": "CapsuleComponent", "function": "GetScaledCapsuleHalfHeight", "params": {}}))["ReturnValue"].as_f64().unwrap()
    };
    let placed = checked(&api, "object.call", json!({"object": format!("addr:{pawn}"), "class": "Actor", "function": "K2_TeleportTo", "params": {
        "DestLocation": {"X": ground["X"].as_f64().unwrap()-220.0, "Y": ground["Y"], "Z": ground["Z"].as_f64().unwrap()-half_height(enemy_addr)+half_height(pawn)}, "DestRotation": {"Pitch": 0.0, "Yaw": 0.0, "Roll": 0.0}}}));
    assert_eq!(placed["ReturnValue"], true, "could not place Sophia on the encounter floor");
    command(&api, "hold", json!({}));
    let post = state(&api)["definition"]["assignment"]["position"].clone();
    let deadline = Instant::now() + Duration::from_secs(8);
    while !state(&api)["targets"].as_array().unwrap().iter().any(|t| t["selector"] == selector) && Instant::now() < deadline { std::thread::sleep(Duration::from_millis(250)); }
    let seen = state(&api);
    println!("sight: {seen}");
    assert!(seen["targets"].as_array().unwrap().iter().any(|t| t["selector"] == selector), "native sight did not perceive the test enemy");
    assert!(seen["targets"].as_array().unwrap().iter().all(|t| !t["name"].as_str().unwrap_or("").contains("WaterCooler")), "furniture was offered as an enemy");
    let players = checked(&api, "players", json!({}));
    let human_pawn = players["players"].as_array().unwrap().iter().find(|p| p["name"] == human).unwrap()["character"].as_str().unwrap();
    let friendly = api.op("ai_player.command", json!({"player": "Sophia", "command": "attack", "target": format!("addr:{human_pawn}")}));
    assert!(!friendly.ok, "accepted an attack on the protected player");
    assert_ne!(seen["action"]["kind"], "attacking");
    command(&api, "stance", json!({"stance": "aggressive"}));
    let deadline = Instant::now() + Duration::from_secs(4);
    loop {
        let current = state(&api);
        if current["action"]["kind"] == "attacking" { break; }
        if Instant::now() >= deadline {
            let eyes = checked(&api, "object.call", json!({"object": format!("addr:{pawn}"), "class": "Actor", "function": "GetActorEyesViewPoint", "params": {}}));
            let enemy_position = checked(&api, "object.call", json!({"object": selector, "class": "Actor", "function": "K2_GetActorLocation", "params": {}}));
            let health = checked(&api, "object.get", json!({"object": selector, "fields": ["IsDead", "TotalCombinedHealth"]}));
            for object in [&selector, &format!("addr:{}", spawner["actor"].as_str().unwrap())] {
                checked(&api, "object.call", json!({"object": object, "class": "Actor", "function": "K2_DestroyActor", "params": {}}));
            }
            command(&api, "follow", json!({"target": human}));
            command(&api, "stance", json!({"stance": "defensive"}));
            panic!("aggressive did not acquire: {current}; eyes={eyes}; enemy={enemy_position}; health={health}");
        }
        std::thread::sleep(Duration::from_millis(100));
    }
    let chase = state(&api)["definition"]["limits"]["chase_distance"].as_f64().unwrap();
    checked(&api, "object.call", json!({"object": selector, "class": "Actor", "function": "K2_TeleportTo", "params": {
        "DestLocation": {"X": post[0], "Y": post[1].as_f64().unwrap()+chase+500.0, "Z": post[2]}, "DestRotation": {"Pitch": 0.0, "Yaw": 270.0, "Roll": 0.0}}}));
    checked(&api, "ai_player.order_tick", json!({"player": "Sophia"}));
    assert_eq!(state(&api)["action"]["kind"], "returning");
    command(&api, "stance", json!({"stance": "passive"}));
    for object in [selector, format!("addr:{}", spawner["actor"].as_str().unwrap())] {
        checked(&api, "object.call", json!({"object": object, "class": "Actor", "function": "K2_DestroyActor", "params": {}}));
    }
    command(&api, "follow", json!({"target": human}));
    command(&api, "stance", json!({"stance": "defensive"}));
}

#[test]
#[ignore = "spawns Sophia, verifies stable follow/hold, passive and explicit native knife combat"]
fn assignments_and_native_melee() {
    let api = api();
    let human = human_name(&api, "Sophia");
    let spawned = checked(&api, "ai_player.start", json!({"name": "Sophia", "near_player": human, "distance": 200.0}));
    println!("spawn: {spawned}");
    command(&api, "stance", json!({"stance": "passive"}));
    command(&api, "follow", json!({"target": human, "distance": 150.0}));
    std::thread::sleep(Duration::from_secs(4));
    let before = checked(&api, "ai_player.status", json!({"player": "Sophia"}));
    assert_eq!(before["brain"]["running"], false, "idle companion must not run the NPC tree");
    command(&api, "hold", json!({}));
    let hold = state(&api)["definition"]["assignment"].clone();
    for _ in 0..8 {
        std::thread::sleep(Duration::from_secs(1));
        let current = state(&api);
        assert_eq!(current["action"]["kind"], "holding", "{current}");
        assert_eq!(current["definition"]["assignment"], hold);
        let status = checked(&api, "ai_player.status", json!({"player": "Sophia"}));
        let position: [f64; 3] = serde_json::from_value(status["pawn"]["location"].clone()).unwrap();
        let post: [f64; 3] = serde_json::from_value(hold["position"].clone()).unwrap();
        assert!(modforge::ai_orders::distance(position, post) < 100.0, "wandered away: {status}");
    }
    let spawner = checked(&api, "npc.spawn", json!({"spawner": "NPCSpawn_Pest", "near_player": human, "distance": 400.0}));
    let enemy = checked(&api, "object.call", json!({"object": format!("addr:{}", spawner["actor"].as_str().unwrap()),
        "class": "Abiotic_NPCSpawn_ParentBP_C", "function": "TrySpawnNPC", "params": {"IsNight": false, "ForceSuccessByTrigger": true, "CheckOnlyNoSpawn": false}}));
    assert_eq!(enemy["Success"], true);
    let enemy_addr = enemy["SpawnedNPC"]["addr"].as_str().unwrap();
    let enemy_selector = format!("addr:{enemy_addr}");
    let status = checked(&api, "ai_player.status", json!({"player": "Sophia"}));
    let pawn = status["pawn"]["addr"].as_str().unwrap().to_owned();
    let position = &status["pawn"]["location"];
    let placed = checked(&api, "object.call", json!({"object": enemy_selector, "class": "Actor", "function": "K2_TeleportTo", "params": {
        "DestLocation": {"X": position[0].as_f64().unwrap()+130.0, "Y": position[1], "Z": position[2]}, "DestRotation": {"Pitch": 0.0, "Yaw": 180.0, "Roll": 0.0}}}));
    assert_eq!(placed["ReturnValue"], true);
    let enemy_controller = checked(&api, "object.get", json!({"object": enemy_selector, "fields": ["Controller"]}))["Controller"]["addr"].as_str().unwrap().to_owned();
    checked(&api, "object.call", json!({"object": format!("addr:{enemy_controller}"), "class": "Abiotic_AI_Controller_ParentBP_C", "function": "AddOrUpdatePotentialTarget", "params": {"PotentialTarget": pawn, "ForceSpotTargetImmediately": true}}));
    for _ in 0..4 {
        std::thread::sleep(Duration::from_secs(1));
        assert_ne!(state(&api)["action"]["kind"], "attacking", "Passive retaliated");
    }
    let initial = checked(&api, "object.get", json!({"object": enemy_selector, "fields": ["TotalCombinedHealth"]}))["TotalCombinedHealth"].as_f64().unwrap();
    assert!(initial > 0.0, "encounter target died before the attack order");
    checked(&api, "object.call", json!({"object": enemy_selector, "class": "Actor", "function": "K2_TeleportTo", "params": {
        "DestLocation": {"X": position[0].as_f64().unwrap()+130.0, "Y": position[1], "Z": position[2]}, "DestRotation": {"Pitch": 0.0, "Yaw": 180.0, "Roll": 0.0}}}));
    if std::env::var_os("ABIOTIC_STATIONARY_ENEMY").is_some() {
        let fields = checked(&api, "object.get", json!({"object": enemy_selector, "fields": ["Controller"]}));
        checked(&api, "bt.stop", json!({"controller": format!("addr:{}", fields["Controller"]["addr"].as_str().unwrap())}));
        checked(&api, "object.call", json!({"object": enemy_selector, "class": "Actor", "function": "K2_TeleportTo", "params": {
            "DestLocation": {"X": position[0].as_f64().unwrap()+130.0, "Y": position[1], "Z": position[2]}, "DestRotation": {"Pitch": 0.0, "Yaw": 180.0, "Roll": 0.0}}}));
    }
    if std::env::var_os("ABIOTIC_TEST_COMBAT_ENTRY").is_some() {
        let controller = format!("addr:{}", status["controller"]["addr"].as_str().unwrap());
        checked(&api, "object.call", json!({"object": controller, "class": "AIController", "function": "K2_SetFocus", "params": {"NewFocus": enemy_addr}}));
        checked(&api, "object.call", json!({"object": controller, "class": "Abiotic_AI_Controller_ParentBP_C", "function": "BT_SetCombatState", "params": {"State": true, "SkipAggroAnimation": true}}));
    }
    command(&api, "attack", json!({"target": enemy_selector}));
    let deadline = Instant::now() + Duration::from_secs(15);
    let mut hit = false;
    while Instant::now() < deadline {
        let current = state(&api);
        assert_eq!(current["definition"]["stance"], "passive");
        assert_eq!(current["definition"]["assignment"], hold);
        let enemy = checked(&api, "object.get", json!({"object": enemy_selector, "fields": ["TotalCombinedHealth", "LastPointDamage"]}));
        println!("action={} enemy_health={}", current["action"], enemy["TotalCombinedHealth"]);
        if enemy["TotalCombinedHealth"].as_f64().unwrap() < initial {
            let damage = enemy["LastPointDamage"].as_object().unwrap();
            let causer = damage.iter().find(|(k,_)| k.starts_with("DamageCauser_")).unwrap().1;
            assert_eq!(causer["addr"], pawn, "someone else damaged the encounter target: {enemy}");
            let kind = damage.iter().find(|(k,_)| k.starts_with("DamageType_")).unwrap().1;
            assert_eq!(kind["class"], "DamageType_Sharp_C");
            hit = true; break;
        }
        std::thread::sleep(Duration::from_millis(250));
    }
    assert!(hit, "native knife attack did not damage the target");
    command(&api, "recall", json!({}));
    assert_ne!(state(&api)["action"]["kind"], "attacking");
    for object in [enemy_selector, format!("addr:{}", spawner["actor"].as_str().unwrap())] {
        checked(&api, "object.call", json!({"object": object, "class": "Actor", "function": "K2_DestroyActor", "params": {}}));
    }
    command(&api, "follow", json!({"target": human}));
    command(&api, "stance", json!({"stance": "defensive"}));
}
