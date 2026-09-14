//! Companion weapon attachment and melee diagnostics.
mod common;
use common::api;
use serde_json::json;

#[test]
#[ignore = "reads native companion perception, damage and melee inputs"]
fn companion_order_inputs() {
    let api = api();
    let status = api.op("ai_player.status", json!({"player": "Sophia"}));
    assert!(status.ok, "{:?}", status.error);
    let pawn = status.result["pawn"]["addr"].as_str().unwrap();
    let controller = status.result["controller"]["addr"].as_str().unwrap();
    let players = api.op("players", json!({}));
    assert!(players.ok);
    let human = players.result["players"][0]["character"].as_str().unwrap();
    for actor in [pawn, human] {
        let fields = api.op("object.get", json!({"object": format!("addr:{actor}"), "fields": ["TotalCombinedHealth", "LastPointDamage", "AIPerception"]}));
        println!("actor {actor}: {} {:?}", fields.result, fields.error);
    }
    let relation = api.op("object.call", json!({"object": format!("addr:{pawn}"), "class": "Abiotic_Character_ParentBP_C", "function": "CheckFriendlyAllyOrHostile", "params": {"PawnToTest": human}}));
    assert!(relation.ok, "{:?}", relation.error);
    println!("relationship: {}", relation.result);
    let board = api.op("bb.get", json!({"controller": format!("addr:{controller}")}));
    assert!(board.ok);
    println!("blackboard: {}", board.result);
}

#[test]
#[ignore = "verifies companion cleanup after the engine destroys and collects its actors"]
fn destroyed_companion_cleanup() {
    let api = api();
    let name = "KnifeLifecycleTest";
    let started = api.op("ai_player.start", json!({"name": name, "distance": 200.0}));
    assert!(started.ok, "{:?}", started.error);
    let status = api.op("ai_player.status", json!({"player": name}));
    assert!(status.ok);
    for field in ["pawn", "controller"] {
        let address = status.result[field]["addr"].as_str().unwrap();
        let destroyed = api.op("object.call", json!({"object": format!("addr:{address}"), "class": "Actor", "function": "K2_DestroyActor", "params": {}}));
        assert!(destroyed.ok, "{:?}", destroyed.error);
    }
    let collected = api.op("object.call", json!({"object": "singleton:KismetSystemLibrary", "class": "KismetSystemLibrary", "function": "CollectGarbage", "params": {}}));
    assert!(collected.ok, "{:?}", collected.error);
    let stopped = api.op("ai_player.stop", json!({"player": name}));
    assert!(stopped.ok, "{:?}", stopped.error);
    println!("cleanup: {}", stopped.result);
    let replacement = api.op("ai_player.start", json!({"name": name, "distance": 200.0}));
    assert!(replacement.ok, "replacement after GC: {:?}", replacement.error);
    assert_eq!(replacement.result["pawn"]["class"], "Modforge_AIPlayer_C");
    assert!(api.op("ai_player.stop", json!({"player": name})).ok);
    let healthy = api.op("list_ops", json!({}));
    assert!(healthy.ok);
}

#[test]
#[ignore = "tests the native melee tree on Sophia's existing Grunt body and controller"]
fn kitchen_knife_melee_tree() {
    let api = api();
    let status = api.op("ai_player.status", json!({"player": "Sophia"}));
    assert!(status.ok);
    let controller = format!("addr:{}", status.result["controller"]["addr"].as_str().unwrap());
    let tree = "asset:/Game/Blueprints/AI/Zombie/BT_Main_Zombie.BT_Main_Zombie";
    let assigned = api.op("object.set", json!({"object": controller, "fields": {"BehaviorTree": tree}}));
    assert!(assigned.ok, "{:?}", assigned.error);
    let started = api.op("bt.run", json!({"controller": controller, "tree": tree}));
    assert!(started.ok, "{:?}", started.error);
    assert_eq!(started.result["started"], true);
}

#[test]
#[ignore = "reads the soldier's ranged combat decisions and cached NPC data"]
fn kitchen_knife_combat_state() {
    let api = api();
    let status = api.op("ai_player.status", json!({"player": "Sophia"}));
    assert!(status.ok);
    for (op, args) in [
        ("object.get", json!({"object": format!("addr:{}", status.result["pawn"]["addr"].as_str().unwrap()), "fields": ["NPCData"]})),
        ("bb.get", json!({"controller": format!("addr:{}", status.result["controller"]["addr"].as_str().unwrap())})),
        ("asset_inventory", json!({"class": "Blueprint", "contains": "Ranged"})),
        ("asset_inventory", json!({"class": "BehaviorTree", "contains": ""})),
    ] {
        let reply = api.op(op, args);
        assert!(reply.ok, "{op}: {:?}", reply.error);
        println!("{op}: {}", reply.result);
    }
}

#[test]
#[ignore = "spawns Sophia with her default knife and verifies attachment and melee configuration"]
fn kitchen_knife_equipped() {
    let api = api();
    let started = api.op("ai_player.start", json!({"player": "Sophia", "distance": 200.0}));
    assert!(started.ok, "start: {:?}", started.error);
    println!("start: {}", started.result);
    let equipped = api.op("ai_player.equip_knife", json!({"player": "Sophia"}));
    assert!(equipped.ok, "equip: {:?}", equipped.error);
    println!("weapon: {}", equipped.result);
    assert_eq!(equipped.result["item"], "knife");
    assert!(equipped.result["damage"].as_f64().unwrap() > 0.0);
    let status = api.op("ai_player.status", json!({"player": "Sophia"}));
    assert!(status.ok);
    let pawn = status.result["pawn"]["addr"].as_str().unwrap();
    assert_eq!(status.result["pawn"]["class"], "Modforge_AIPlayer_C");
    let state = api.op("object.get", json!({"object": format!("addr:{pawn}"), "fields": ["Mesh", "NPCData", "WalkSpeed", "CharacterMovement"]}));
    assert!(state.ok, "{:?}", state.error);
    assert_eq!(state.result["WalkSpeed"], 260.0);
    let movement = state.result["CharacterMovement"]["addr"].as_str().unwrap();
    let speed = api.op("object.get", json!({"object": format!("addr:{movement}"), "fields": ["MaxWalkSpeed"]}));
    assert!(speed.ok);
    assert_eq!(speed.result["MaxWalkSpeed"], 260.0);
    let npc = state.result["NPCData"].as_object().unwrap();
    assert_eq!(npc.iter().find(|(k,_)| k.starts_with("HasRangedAttack_")).unwrap().1, false);
    assert_eq!(npc.iter().find(|(k,_)| k.starts_with("MeleeAttackDamagePerHit_")).unwrap().1, &equipped.result["damage"]);
    let mesh = equipped.result["component"].as_str().unwrap();
    let attachment = api.op("object.get", json!({"object": format!("addr:{mesh}"), "fields": ["StaticMesh", "AttachParent", "AttachSocketName"]}));
    assert!(attachment.ok, "{:?}", attachment.error);
    println!("attachment: {}", attachment.result);
    assert_eq!(attachment.result["AttachParent"]["addr"], state.result["Mesh"]["addr"]);
    assert_eq!(attachment.result["AttachSocketName"], equipped.result["socket"]);
    assert!(attachment.result["StaticMesh"]["name"].as_str().unwrap().contains("SM_Knife_01"));
    let human = common::human_name(&api, "Sophia");
    let follow = api.op("ai_player.follow", json!({"player": "Sophia", "target": human, "distance": 150.0, "period_ms": 2000}));
    assert!(follow.ok, "follow: {:?}", follow.error);
}

#[test]
#[ignore = "reads kitchen knife assets and Sophia's weapon attachment"]
fn kitchen_knife_setup() {
    let api = api();
    for class in ["StaticMesh", "SkeletalMesh"] {
        let reply = api.op("asset_inventory", json!({"class": class, "contains": "Knife"}));
        assert!(reply.ok, "{:?}", reply.error);
        println!("assets {class}: {}", reply.result);
    }
    let rows = api.op("list_row_names", json!({"table_name": "ItemTable_Global"}));
    assert!(rows.ok);
    println!("knife rows: {:?}", rows.result["rows"].as_array().unwrap().iter().filter(|r| r.as_str().unwrap_or("").to_lowercase().contains("knife")).collect::<Vec<_>>());
    let status = api.op("ai_player.status", json!({"player": "Sophia"}));
    assert!(status.ok);
    let pawn = status.result["pawn"]["addr"].as_str().unwrap();
    let state = api.op("object.get", json!({"object": format!("addr:{pawn}"), "fields": ["Mesh", "NPCData", "MeleeOriginBone", "MeleeTraceRadius"]}));
    assert!(state.ok, "{:?}", state.error);
    println!("Sophia: {}", state.result);
    for (class, function) in [("SceneComponent", "K2_AttachToComponent"), ("SceneComponent", "SetVisibility"), ("StaticMeshComponent", "SetStaticMesh")] {
        let schema = api.op("function_parameters", json!({"class": class, "function": function}));
        assert!(schema.ok);
        println!("{function}: {}", schema.result);
    }
}
