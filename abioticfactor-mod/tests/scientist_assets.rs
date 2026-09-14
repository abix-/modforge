//! Read-only scientist asset inventory from the running game's registry.
mod common;
use serde_json::json;

/// The game answers whether the Pillager, whose animation asset Sophia wears, derives
/// from the base NPC she derives from.
#[test]
#[ignore = "requires the running game; asks the engine the Pillager's parent"]
fn pillager_is_base_npc_child() {
    let api = common::api();
    for (test, parent) in [("NPC_Pillager_ParentBP_C", "NPC_Base_ParentBP_C"), ("NPC_Coworker_C", "NPC_Base_ParentBP_C"), ("NarrativeNPC_Human_ParentBP_C", "NPC_Base_ParentBP_C"), ("NPC_Pillager_ParentBP_C", "Abiotic_PlayerCharacter_C")] {
        let reply = api.op("object.call", json!({"object": "singleton:KismetMathLibrary", "class": "KismetMathLibrary", "function": "ClassIsChildOf",
            "params": {"TestClass": format!("class:{test}"), "ParentClass": format!("class:{parent}")}}));
        assert!(reply.ok, "{test} child of {parent}: {:?}", reply.error);
        println!("{test} child of {parent}: {}", reply.result["ReturnValue"]);
    }
}

/// What Sophia's animation instance reads while she stands and while she walks:
/// its own variables, her velocity, and whether it can see her as its owner class.
#[test]
#[ignore = "requires the running game and a spawned Sophia; reads her animation instance twice around a follow"]
fn sophia_animation_instance() {
    let api = common::api();
    let status = api.op("ai_player.status", json!({"player": "Sophia"}));
    assert!(status.ok, "status: {:?}", status.error);
    let pawn = status.result["pawn"]["addr"].as_str().expect("Sophia pawn").to_owned();
    let mesh = api.op("object.get", json!({"object": format!("addr:{pawn}"), "fields": ["Mesh"]}));
    let mesh = mesh.result["Mesh"]["addr"].as_str().expect("mesh").to_owned();
    let anim = api.op("object.get", json!({"object": format!("addr:{mesh}"), "fields": ["AnimScriptInstance", "AnimClass", "AnimationMode"]}));
    println!("mesh animation: {}", anim.result);
    let instance = anim.result["AnimScriptInstance"]["addr"].as_str().expect("animation instance").to_owned();
    let human = common::human_name(&api, "Sophia");
    let follow = api.op("ai_player.follow", json!({"player": "Sophia", "target": human, "distance": 150.0}));
    println!("follow: {} {:?}", follow.result, follow.error);
    for pass in ["standing", "after follow"] {
        let fields = api.op("object.get", json!({"object": format!("addr:{instance}")}));
        assert!(fields.ok, "animation instance: {:?}", fields.error);
        let plain: serde_json::Map<String, serde_json::Value> = fields.result.as_object().expect("fields").iter()
            .filter(|(_, v)| v.is_number() || v.is_boolean() || v["addr"].is_string() || v.is_string())
            .map(|(k, v)| (k.clone(), if v["addr"].is_string() { json!(format!("{} {}", v["class"], v["name"])) } else { v.clone() })).collect();
        let velocity = api.op("object.call", json!({"object": format!("addr:{pawn}"), "class": "Actor", "function": "GetVelocity"}));
        println!("{pass}: velocity {} instance {}", velocity.result["ReturnValue"], serde_json::Value::Object(plain));
        std::thread::sleep(std::time::Duration::from_secs(3));
    }
}

#[test]
#[ignore = "requires the running game; lists scientist character assets"]
fn scientist_assets() {
    let api = common::api();
    for (op, args) in [("walk_class", json!({"class": "NarrativeNPC_Human_ParentBP_C", "max": 4096})), ("dump_data_table", json!({"table_name": "DT_NPC_Conversations", "max_rows": 4096}))] {
        let reply = api.op(op, args);
        assert!(reply.ok, "{op}: {:?}", reply.error);
        println!("{op}: {}", reply.result);
        if op == "walk_class" {
            for instance in reply.result["instances"].as_array().unwrap() {
                let detail = api.op("object.get", json!({"object": instance["addr_selector"]}));
                assert!(detail.ok, "inspect: {:?}", detail.error);
                println!("scientist: {}", detail.result);
                let customization = &detail.result["HumanCustomizationComponent"]["addr"];
                if let Some(address) = customization.as_str() {
                    let appearance = api.op("object.get", json!({"object": format!("addr:{address}")}));
                    assert!(appearance.ok, "appearance: {:?}", appearance.error);
                    println!("appearance: {}", appearance.result);
                }
            }
        }
    }
    // Blueprint assets carry the NPC names; the empty class name is not "any class".
    for (class, contains) in [("Blueprint", "NarrativeNPC"), ("Blueprint", "Janet"), ("SkeletalMesh", "Female"), ("SkeletalMesh", "Scientist"), ("AnimBlueprint", ""), ("Skeleton", ""), ("AnimSequence", "Scientist")] {
        let reply = api.op("asset_inventory", json!({"class": class, "contains": contains}));
        assert!(reply.ok, "{class}/{contains}: {:?}", reply.error);
        println!("{class}/{contains}: {}", reply.result);
    }
}
