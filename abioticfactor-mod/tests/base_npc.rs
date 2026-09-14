//! Base NPC body research and acceptance. Run live tests serially.
mod common;
use common::api;
use serde_json::json;

#[test]
#[ignore = "uses the normal respawn request when the human is dead before live acceptance"]
fn human_respawn_for_live_acceptance() {
    let api = api();
    let human = common::human_name(&api, "Sophia");
    let checked = |op: &str, args| {
        let reply = api.op(op, args);
        assert!(reply.ok, "{op}: {:?}", reply.error);
        reply.result
    };
    let health = || {
        let players = checked("players", json!({}));
        let actor = players["players"].as_array().unwrap().iter().find(|p| p["name"] == human).unwrap()["character"].as_str().unwrap();
        checked("object.get", json!({"object": format!("addr:{actor}"), "fields": ["TotalCombinedHealth"]}))["TotalCombinedHealth"].as_f64().unwrap()
    };
    if health() > 0.0 { return; }
    // Same arguments as the widget's RespawnAtOrigin button.
    checked("object.call", json!({"object": "first_class:W_RespawnOptions_C", "class": "W_RespawnOptions_C", "function": "RequestRespawn", "params": {"RevivedOnSpot": false, "UsePlayerStartOnly": true, "DestinationID": "None"}}));
    let deadline = std::time::Instant::now() + std::time::Duration::from_secs(15);
    while health() <= 0.0 {
        assert!(std::time::Instant::now() < deadline, "normal respawn did not complete");
        std::thread::sleep(std::time::Duration::from_millis(250));
    }
    println!("normal respawn completed: human health={}", health());
}

#[test]
#[ignore = "reads custom-body collision, eye height and mesh placement"]
fn custom_body_geometry() {
    let api = api();
    let checked = |op: &str, args| {
        let reply = api.op(op, args);
        assert!(reply.ok, "{op}: {:?}", reply.error);
        reply.result
    };
    let status = checked("ai_player.status", json!({"player": "Sophia"}));
    let players = checked("players", json!({}));
    println!("players: {players}");
    let controller = checked("object.call", json!({"object": "singleton:GameplayStatics", "class": "GameplayStatics", "function": "GetPlayerController", "params": {"WorldContextObject": status["pawn"]["addr"], "PlayerIndex": 0}}));
    let controller = controller["ReturnValue"]["addr"].as_str().unwrap();
    println!("local controller {controller}: {}", checked("object.get", json!({"object": format!("addr:{controller}"), "fields": ["Pawn", "PlayerCharacter", "MyPlayerCharacter", "PlayerHUDRef"]})));
    let pests = checked("walk_class", json!({"class": "NPC_Monster_Pest_C", "max": 128}));
    for pest in pests["instances"].as_array().unwrap() {
        let selector = pest["addr_selector"].as_str().unwrap();
        let position = checked("object.call", json!({"object": selector, "class": "Actor", "function": "K2_GetActorLocation", "params": {}}));
        let p = &position["ReturnValue"];
        if (p["X"].as_f64().unwrap() - status["pawn"]["location"][0].as_f64().unwrap()).hypot(p["Y"].as_f64().unwrap() - status["pawn"]["location"][1].as_f64().unwrap()) < 800.0 {
            println!("nearby enemy {selector}: {position}; {}", checked("object.get", json!({"object": selector, "fields": ["IsDead", "TotalCombinedHealth"]})));
        }
    }
    let human = common::human_name(&api, "Sophia");
    let human_address = players["players"].as_array().unwrap().iter().find(|p| p["name"] == human).unwrap()["character"].as_str().unwrap();
    for actor in [format!("addr:{}", status["pawn"]["addr"].as_str().unwrap()), format!("addr:{human_address}"), "singleton:Modforge_AIPlayer_C".into(), "singleton:NPC_Base_ParentBP_C".into()] {
        let fields = checked("object.get", json!({"object": actor, "fields": ["CapsuleComponent", "Mesh", "BaseEyeHeight", "TotalCombinedHealth", "IsDead"]}));
        println!("{actor}: {fields}");
        for (field, names) in [("CapsuleComponent", vec!["CapsuleRadius", "CapsuleHalfHeight", "RelativeScale3D"]), ("Mesh", vec!["RelativeLocation", "RelativeScale3D", "RelativeRotation"])] {
            let component = fields[field]["addr"].as_str().unwrap();
            println!("{field}: {}", checked("object.get", json!({"object": format!("addr:{component}"), "fields": names})));
        }
        if actor.starts_with("addr:") {
            println!("eyes: {}", checked("object.call", json!({"object": actor, "class": "Actor", "function": "GetActorEyesViewPoint", "params": {}})));
        }
    }
}

#[test]
#[ignore = "checks the engine component calls used to construct our NPC body"]
fn body_component_api() {
    let api = api();
    for (class, function) in [
        ("SkeletalMeshComponent", "SetSkeletalMeshAsset"),
        ("SkeletalMeshComponent", "SetAnimClass"),
        ("SkeletalMeshComponent", "GetAnimInstance"),
        ("SceneComponent", "K2_SetRelativeLocation"),
        ("SceneComponent", "K2_AttachToComponent"),
        ("SkinnedMeshComponent", "SetLeaderPoseComponent"),
        ("Controller", "Possess"),
    ] {
        let reply = api.op("function_parameters", json!({"class": class, "function": function}));
        assert!(reply.ok, "{class}::{function}: {:?}", reply.error);
        println!("{class}::{function}: {}", reply.result);
    }
}

#[test]
fn derived_class_native_bindings() {
    let path = std::path::Path::new("C:/Games/Steam/steamapps/common/AbioticFactor/AbioticFactor/Binaries/Win64/AbioticFactor-Win64-Shipping.pdb");
    for (class, method, rva) in [
        ("UClass", "SetSuperStruct", 0x119c610),
        ("UBlueprintGeneratedClass", "Bind", 0x3415500),
        ("UStruct", "StaticLink", 0x119ccc0),
        ("UClass", "CreateDefaultObject", 0x1188950),
        ("UBlueprintGeneratedClass", "UpdateCustomPropertyListForPostConstruction", 0x34447b0),
    ] {
        let mut symbols = ueforge::symbols::functions(path, class, method).unwrap();
        if symbols.is_empty() {
            symbols = ueforge::symbols::procedures(path, &format!("{class}::{method}")).unwrap();
        }
        assert_eq!(symbols.len(), 1, "{class}::{method}: {symbols:?}");
        assert_eq!(symbols[0].rva, rva, "{class}::{method} changed");
        println!("{class}::{method}: 0x{:X} {}", symbols[0].rva, symbols[0].decorated);
    }
    let construction = ueforge::symbols::procedures(path, "StaticConstructObject_Internal").unwrap();
    assert_eq!(construction.len(), 1);
    assert_eq!(construction[0].rva, 0x12e14a0);
    for (name, size, fields) in [
        ("FStaticConstructObjectParameters", 144, vec![("Class", 0), ("Outer", 8), ("Name", 16), ("SetFlags", 24), ("InternalSetFlags", 28), ("bCopyTransientsFromClassDefaults", 32), ("bAssumeTemplateIsArchetype", 33), ("Template", 40), ("InstanceGraph", 48), ("ExternalPackage", 56), ("PropertyInitCallback", 64), ("SubobjectOverrides", 128)]),
        ("UClass", 512, vec![("ClassFlags", 0xd4), ("ClassWithin", 0xe0), ("ClassConfigName", 0xe8)]),
    ] {
        let layout = ueforge::symbols::layout(path, name).unwrap();
        assert_eq!(layout.size, size, "{name} size changed");
        for (field, offset) in fields {
            assert_eq!(layout.fields.iter().find(|f| f.name == field).unwrap().offset, offset, "{name}.{field} moved");
        }
    }
}

#[test]
fn native_property_copy_matches_shipped_symbols() {
    let path = std::path::Path::new("C:/Games/Steam/steamapps/common/AbioticFactor/AbioticFactor/Binaries/Win64/AbioticFactor-Win64-Shipping.pdb");
    let symbols = ueforge::symbols::functions(path, "FProperty", "CopyCompleteValueToScriptVM").unwrap();
    assert_eq!(symbols.len(), 1);
    assert_eq!(symbols[0].rva, 0x124f750);
}

#[test]
#[ignore = "replaces Sophia with the custom NPC and verifies human rendering, initialization and follow"]
fn custom_body_follows_human() {
    let api = api();
    let human = common::human_name(&api, "Sophia");
    let checked = |op: &str, args| {
        let reply = api.op(op, args);
        assert!(reply.ok, "{op}: {:?}", reply.error);
        reply.result
    };
    checked("ai_player.stop", json!({"player": "Sophia"}));
    let spawn = checked("ai_player.start", json!({"name": "Sophia", "near_player": human, "distance": 400.0}));
    println!("custom spawn: {spawn}");
    assert_eq!(spawn["pawn"]["class"], "Modforge_AIPlayer_C");
    assert_eq!(spawn["controller"]["class"], "Abiotic_AI_Controller_ParentBP_C");
    for (class, expected) in [("NPC_Base_ParentBP_C", true), ("NPC_Soldier_Grunt_C", false)] {
        let instances = checked("walk_class", json!({"class": class, "max": 4096}));
        let matches = instances["instances"].as_array().unwrap().iter().any(|p| p["addr"] == spawn["pawn"]["addr"]);
        assert_eq!(matches, expected, "engine inheritance check for {class}");
    }
    let npcs = checked("walk_class", json!({"class": "NPC_Base_ParentBP_C", "max": 4096}));
    let registered = checked("ai_player.sources", json!({}));
    assert_eq!(registered["npcs"], npcs["total"], "custom NPC must be included in sight source registration");
    checked("ai_player.command", json!({"player": "Sophia", "command": "follow", "target": human}));
    let deadline = std::time::Instant::now() + std::time::Duration::from_secs(20);
    loop {
        let status = checked("ai_player.status", json!({"player": "Sophia"}));
        let orders = checked("ai_player.orders", json!({}));
        let order = orders.as_array().unwrap().iter().find(|r| r["name"] == "Sophia").unwrap();
        assert_ne!(order["action"]["kind"], "blocked", "{order}");
        if order["action"]["kind"] == "following" {
            let p = &status["pawn"]["location"];
            let t = &order["action"]["position"];
            let distance = (p[0].as_f64().unwrap()-t[0].as_f64().unwrap()).hypot(p[1].as_f64().unwrap()-t[1].as_f64().unwrap());
            if distance <= order["action"]["radius"].as_f64().unwrap() + 10.0 {
                let fields = checked("object.get", json!({"object": format!("addr:{}", status["pawn"]["addr"].as_str().unwrap()), "fields": ["Mesh", "TotalCombinedHealth", "WalkSpeed", "IsPerformingSpawnFX"]}));
                assert!(fields["TotalCombinedHealth"].as_f64().unwrap() > 0.0);
                let mesh = fields["Mesh"]["addr"].as_str().unwrap();
                let anim = checked("object.call", json!({"object": format!("addr:{mesh}"), "class": "SkeletalMeshComponent", "function": "GetAnimInstance", "params": {}}));
                assert_eq!(anim["ReturnValue"]["class"], "NPC_Coworker_AnimBP_C");
                let animation = checked("object.get", json!({"object": format!("addr:{}", anim["ReturnValue"]["addr"].as_str().unwrap()), "fields": ["CharacterParent", "Speed"]}));
                assert_eq!(animation["CharacterParent"]["addr"], status["pawn"]["addr"]);
                println!("base NPC following at {distance:.1}: {fields}; animation={animation}; orders={order}");
                return;
            }
        }
        assert!(std::time::Instant::now() < deadline, "base follow timed out: {status}; {order}");
        std::thread::sleep(std::time::Duration::from_millis(250));
    }
}

#[test]
#[ignore = "loads human animation assets for base NPC compatibility research"]
fn human_animation_assets() {
    let api = api();
    for (package, asset) in [
        ("/Game/Models/Characters/Scientist/Male/ABF_Zombie_AnimBP", "ABF_Zombie_AnimBP_C"),
        ("/Game/Models/Characters/Scientist/Male/NPC_Coworker_AnimBP", "NPC_Coworker_AnimBP_C"),
    ] {
        let result = api.op("load_asset", json!({"package": package, "asset": asset}));
        assert!(result.ok, "{asset}: {:?}", result.error);
        assert_eq!(result.result["loaded"], true, "{asset}");
        println!("{asset}: {}", result.result);
    }
}
