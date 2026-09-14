//! Permanent encounter setup through the game's NPC spawner.
mod common;
use common::{api, human_name};
use serde_json::json;

fn checked(api: &modforge::client::Api<serde_json::Value>, op: &str, args: serde_json::Value) -> Result<serde_json::Value, String> {
    let reply = api.op(op, args);
    if reply.ok { Ok(reply.result) } else { Err(format!("{op}: {:?}", reply.error)) }
}

#[test]
#[ignore = "spawns an Exor near the human for Sophia's combat test"]
fn exor_near_player() {
    let api = api();
    let human = human_name(&api, "Sophia");
    let spawner = checked(&api, "npc.spawn", json!({"spawner": "NPCSpawn_QuillExor", "near_player": human, "distance": 600.0})).unwrap();
    let spawned = call(&api, spawner["actor"].as_str().unwrap(), "Abiotic_NPCSpawn_ParentBP_C", "TrySpawnNPC", json!({"IsNight": false, "ForceSuccessByTrigger": true, "CheckOnlyNoSpawn": false})).unwrap();
    println!("Exor: {spawned}");
    assert_eq!(spawned["Success"], true);
    assert_eq!(spawned["SpawnedNPC"]["class"], "NPC_Monster_Exor_C");
    let address = spawned["SpawnedNPC"]["addr"].as_str().unwrap();
    let state = checked(&api, "object.get", json!({"object": format!("addr:{address}"), "fields": ["TotalCombinedHealth", "Controller", "Faction"]})).unwrap();
    println!("Exor state: {state}");
    assert!(state["TotalCombinedHealth"].as_f64().unwrap() > 0.0);
    assert!(state["Controller"]["addr"].is_string());
}

#[test]
#[ignore = "doubles Sophia's current character movement walking speed"]
fn sophia_double_walk_speed() {
    let api = api();
    let status = checked(&api, "ai_player.status", json!({"player": "Sophia"})).unwrap();
    let pawn = status["pawn"]["addr"].as_str().unwrap();
    let fields = checked(&api, "object.get", json!({"object": format!("addr:{pawn}"), "fields": ["CharacterMovement"]})).unwrap();
    let movement = fields["CharacterMovement"]["addr"].as_str().unwrap();
    let selector = format!("addr:{movement}");
    let before = checked(&api, "object.get", json!({"object": format!("addr:{pawn}"), "fields": ["WalkSpeed"]})).unwrap()["WalkSpeed"].as_f64().unwrap();
    assert!(before > 0.0);
    println!("walk speed before: {before}");
    checked(&api, "object.set", json!({"object": format!("addr:{pawn}"), "fields": {"WalkSpeed": before * 2.0}})).unwrap();
    let set = checked(&api, "object.set", json!({"object": selector, "fields": {"MaxWalkSpeed": before * 2.0}})).unwrap();
    println!("set: {set}");
    std::thread::sleep(std::time::Duration::from_secs(2));
    let after = checked(&api, "object.get", json!({"object": selector, "fields": ["MaxWalkSpeed"]})).unwrap();
    println!("walk speed after: {after}");
    assert_eq!(after["MaxWalkSpeed"], before * 2.0);
}

#[test]
#[ignore = "spawns Sophia on the human faction and verifies the game treats them as friends"]
fn sophia_team_setup() {
    let api = api();
    let human = human_name(&api, "Sophia");
    checked(&api, "ai_player.start", json!({"name": "Sophia", "near_player": human, "distance": 200.0})).unwrap();
    let players = checked(&api, "players", json!({})).unwrap();
    let player = players["players"].as_array().unwrap().iter().find(|p| p["name"] == human).unwrap();
    let human_pawn = player["character"].as_str().unwrap();
    let status = checked(&api, "ai_player.status", json!({"player": "Sophia"})).unwrap();
    let pawn = status["pawn"]["addr"].as_str().unwrap();
    for _ in 0..10 {
        let faction = checked(&api, "object.get", json!({"object": format!("addr:{pawn}"), "fields": ["Faction"]})).unwrap();
        assert_eq!(faction["Faction"], player["faction"]);
        let friend = call(&api, pawn, "Abiotic_Character_ParentBP_C", "CheckFriendlyAllyOrHostile", json!({"PawnToTest": human_pawn})).unwrap();
        println!("faction: {faction}; relationship: {friend}");
        assert_eq!(friend["Friend"], true);
        let status = checked(&api, "ai_player.status", json!({"player": "Sophia"})).unwrap();
        assert_ne!(status["brain"]["blackboard"]["TargetActor"]["addr"], human_pawn);
        std::thread::sleep(std::time::Duration::from_secs(1));
    }
    println!("follow: {}", checked(&api, "ai_player.follow", json!({"player": "Sophia", "target": human, "distance": 150.0})).unwrap());
}

#[test]
#[ignore = "finds the game's Grunt spawner asset"]
fn grunt_spawner_asset() {
    println!("{}", checked(&api(), "asset_inventory", json!({"class": "BlueprintGeneratedClass", "contains": "NPCSpawn"})).unwrap());
}

#[test]
#[ignore = "replaces Sophia's current body with our custom NPC and enables follow"]
fn sophia_custom_near_player() {
    let api = api();
    let human = human_name(&api, "Sophia");
    checked(&api, "ai_player.stop", json!({"player": "Sophia"})).unwrap();
    let spawned = checked(&api, "ai_player.start", json!({"name": "Sophia", "near_player": human, "distance": 200.0})).unwrap();
    println!("Sophia custom NPC: {spawned}");
    assert_eq!(spawned["pawn"]["class"], "Modforge_AIPlayer_C");
    sophia_npc_follow_near_player();
    println!("health: {}", checked(&api, "object.get", json!({"object": format!("addr:{}", spawned["pawn"]["addr"].as_str().unwrap()), "fields": ["TotalCombinedHealth"]})).unwrap());
}

#[test]
#[ignore = "locates Sophia's NPC body and checks visibility and health"]
fn sophia_npc_location() {
    let api = api();
    println!("players: {}", checked(&api, "players", json!({})).unwrap());
    let status = checked(&api, "ai_player.status", json!({"player": "Sophia"})).unwrap();
    println!("Sophia: {status}");
    let pawn = status["pawn"]["addr"].as_str().unwrap();
    for field in ["TotalCombinedHealth", "IsDead", "bHidden", "Mesh", "RootComponent"] {
        println!("{field}: {:?}", checked(&api, "object.get", json!({"object": format!("addr:{pawn}"), "fields": [field]})));
    }
}

#[test]
#[ignore = "places Sophia's NPC body beside the human and enables follow"]
fn sophia_npc_follow_near_player() {
    let api = api();
    let human = human_name(&api, "Sophia");
    checked(&api, "ai_player.start", json!({"name": "Sophia", "near_player": human, "distance": 200.0})).unwrap();
    let players = checked(&api, "players", json!({})).unwrap();
    let player = players["players"].as_array().unwrap().iter().find(|p| p["name"] == human).unwrap();
    let position = &player["location"];
    let status = checked(&api, "ai_player.status", json!({"player": "Sophia"})).unwrap();
    let pawn = status["pawn"]["addr"].as_str().unwrap();
    let placed = call(&api, pawn, "Actor", "K2_TeleportTo", json!({"DestLocation": {"X": position[0].as_f64().unwrap() + 200.0, "Y": position[1], "Z": position[2]}, "DestRotation": {"Pitch": 0.0, "Yaw": 0.0, "Roll": 0.0}})).unwrap();
    assert_eq!(placed["ReturnValue"], true, "teleport: {placed}");
    println!("follow: {}", checked(&api, "ai_player.follow", json!({"player": "Sophia", "target": human, "distance": 150.0})).unwrap());
    println!("status: {}", checked(&api, "ai_player.status", json!({"player": "Sophia"})).unwrap());
}

#[test]
#[ignore = "spawns Sophia with an NPC body and tests combat against a Pest"]
fn sophia_npc_combat() {
    let api = api();
    struct ResumeBrain<'a>(&'a modforge::client::Api<serde_json::Value>, String);
    impl Drop for ResumeBrain<'_> {
        fn drop(&mut self) {
            if let Err(error) = call(self.0, &self.1, "BrainComponent", "RestartLogic", json!({})) {
                eprintln!("restore encounter participant: {error}");
            }
        }
    }
    let _paused = std::env::var("ABIOTIC_COMBAT_PAUSE_CONTROLLER").ok().map(|controller| {
        let fields = checked(&api, "object.get", json!({"object": format!("addr:{controller}"), "fields": ["BrainComponent"]})).unwrap();
        let brain = fields["BrainComponent"]["addr"].as_str().unwrap().to_owned();
        checked(&api, "bt.stop", json!({"controller": format!("addr:{controller}")})).unwrap();
        ResumeBrain(&api, brain)
    });
    let human = human_name(&api, "Sophia");
    if std::env::var_os("ABIOTIC_COMBAT_PAUSE_CONTROLLER").is_some() {
        checked(&api, "ai_player.stop", json!({"player": "Sophia"})).unwrap();
    }
    let sophia = checked(&api, "ai_player.start", json!({"name": "Sophia", "near_player": human, "distance": 900.0})).unwrap();
    println!("Sophia: {sophia}");
    let status = checked(&api, "ai_player.status", json!({"player": "Sophia"})).unwrap();
    let body = status["pawn"]["addr"].as_str().unwrap();
    let controller = status["controller"]["addr"].as_str().unwrap();
    assert!(status["pawn"]["class"].as_str().unwrap().starts_with("NPC_"), "Sophia must have an NPC body: {status}");
    let spawner = checked(&api, "npc.spawn", json!({"spawner": "NPCSpawn_Pest", "near_player": human, "distance": 1100.0})).unwrap();
    let pest = call(&api, spawner["actor"].as_str().unwrap(), "Abiotic_NPCSpawn_ParentBP_C", "TrySpawnNPC", json!({"IsNight": false, "ForceSuccessByTrigger": true, "CheckOnlyNoSpawn": false})).unwrap();
    let enemy = pest["SpawnedNPC"]["addr"].as_str().expect("spawned Pest");
    let health = || checked(&api, "object.get", json!({"object": format!("addr:{enemy}"), "fields": ["TotalCombinedHealth"]})).unwrap()["TotalCombinedHealth"].as_f64().unwrap();
    let initial = health();
    checked(&api, "ai_player.follow", json!({"player": "Sophia", "target": ""})).unwrap();
    let location = &status["pawn"]["location"];
    let placed = call(&api, enemy, "Actor", "K2_TeleportTo", json!({"DestLocation": {"X": location[0].as_f64().unwrap() + 130.0, "Y": location[1], "Z": location[2]}, "DestRotation": {"Pitch": 0.0, "Yaw": 180.0, "Roll": 0.0}})).unwrap();
    assert_eq!(placed["ReturnValue"], true);
    for _ in 0..20 {
        let setup = checked(&api, "object.get", json!({"object": format!("addr:{controller}"), "fields": ["SetupComplete", "MyPawn"]})).unwrap();
        println!("setup: {setup}");
        if setup["SetupComplete"] == true {
            assert_eq!(setup["MyPawn"]["addr"], body);
            break;
        }
        std::thread::sleep(std::time::Duration::from_millis(500));
    }
    call(&api, controller, "Abiotic_AI_Controller_ParentBP_C", "AddOrUpdatePotentialTarget", json!({"PotentialTarget": enemy, "ForceSpotTargetImmediately": true})).unwrap();
    let mut damaged = false;
    for _ in 0..30 {
        let current = health();
        let status = checked(&api, "ai_player.status", json!({"player": "Sophia"})).unwrap();
        println!("Pest health {initial} -> {current}; Sophia: {status}");
        if current < initial {
            let evidence = checked(&api, "object.get", json!({"object": format!("addr:{enemy}"), "fields": ["LastPointDamage"]})).unwrap();
            println!("damage evidence: {evidence}");
            let hit = evidence["LastPointDamage"].as_object().unwrap();
            assert_eq!(hit.iter().find(|(k,_)| k.starts_with("DamageCauser_")).unwrap().1["addr"], body);
            assert_eq!(hit.iter().find(|(k,_)| k.starts_with("DamageType_")).unwrap().1["class"], "DamageType_Sharp_C", "knife combat must not fire bullets");
            damaged = true;
            break;
        }
        std::thread::sleep(std::time::Duration::from_secs(1));
    }
    checked(&api, "ai_player.follow", json!({"player": "Sophia", "target": human, "distance": 150.0})).unwrap();
    assert!(damaged, "Sophia did not damage the Pest in 30 seconds");
}

fn call(api: &modforge::client::Api<serde_json::Value>, object: &str, class: &str, function: &str, params: serde_json::Value) -> Result<serde_json::Value, String> {
    checked(api, "object.call", json!({"object": format!("addr:{object}"), "class": class, "function": function, "params": params}))
}

#[test]
#[ignore = "spawns a Pest near the human for Sophia's combat encounter"]
fn pest_near_player() {
    let api = api();
    if let Ok(pest) = std::env::var("ABIOTIC_PEST_ACTOR") {
        verify_pest(&api, &pest);
        return;
    }
    let actor = match std::env::var("ABIOTIC_PEST_SPAWNER") {
        Ok(actor) => actor,
        Err(_) => {
            let human = human_name(&api, "Sophia");
            let spawned = api.op("npc.spawn", json!({"spawner": "NPCSpawn_Pest", "near_player": human, "distance": 400.0}));
            assert!(spawned.ok, "npc.spawn: {:?}", spawned.error);
            println!("spawn: {}", spawned.result);
            spawned.result["actor"].as_str().expect("spawner address").to_owned()
        }
    };
    // DebugSpawn only draws existing NPCs. TrySpawnNPC performs the spawn.
    let request = api.op("object.call", json!({"object": format!("addr:{actor}"), "class": "Abiotic_NPCSpawn_ParentBP_C", "function": "TrySpawnNPC",
        "params": {"IsNight": false, "ForceSuccessByTrigger": true, "CheckOnlyNoSpawn": false}}));
    assert!(request.ok, "TrySpawnNPC: {:?}", request.error);
    println!("TrySpawnNPC: {}", request.result);
    assert_eq!(request.result["Success"], true, "{}", request.result);
    assert_eq!(request.result["SpawnedNPC"]["class"], "NPC_Monster_Pest_C");
    verify_pest(&api, request.result["SpawnedNPC"]["addr"].as_str().expect("Pest address"));
}

fn verify_pest(api: &modforge::client::Api<serde_json::Value>, pest: &str) {
    let state = api.op("object.get", json!({"object": format!("addr:{pest}"), "fields": ["TotalCombinedHealth", "Controller"]}));
    assert!(state.ok, "Pest state: {:?}", state.error);
    println!("Pest {pest}: {}", state.result);
    assert!(state.result["TotalCombinedHealth"].as_f64().is_some_and(|health| health > 0.0), "Pest is not alive: {}", state.result);
    assert!(state.result["Controller"]["addr"].as_str().is_some(), "Pest has no controller: {}", state.result);
}
