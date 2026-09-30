//! Read-only scientist asset inventory from the running game's registry.
mod common;
use serde_json::json;

/// The game answers whether the Pillager, whose animation asset Sophia wears, derives
/// from the base NPC she derives from.
#[test]
#[ignore = "requires the running game; asks the engine the Pillager's parent"]
fn pillager_is_base_npc_child() {
    let api = common::api();
    for (test, parent) in [
        ("NPC_Pillager_ParentBP_C", "NPC_Base_ParentBP_C"),
        ("NPC_Coworker_C", "NPC_Base_ParentBP_C"),
        ("NarrativeNPC_Human_ParentBP_C", "NPC_Base_ParentBP_C"),
        ("NPC_Pillager_ParentBP_C", "Abiotic_PlayerCharacter_C"),
    ] {
        let reply = api.op("object.call", json!({"object": "singleton:KismetMathLibrary", "class": "KismetMathLibrary", "function": "ClassIsChildOf",
            "params": {"TestClass": format!("class:{test}"), "ParentClass": format!("class:{parent}")}}));
        assert!(reply.ok, "{test} child of {parent}: {:?}", reply.error);
        println!("{test} child of {parent}: {}", reply.result["ReturnValue"]);
    }
}

/// What the game already has for looking into another character: follower and
/// container widgets, the player's NPC interaction functions, the skills widgets.
#[test]
#[ignore = "requires the running game; lists follower, container, inventory and skill widgets and the player's NPC interaction functions"]
fn other_character_inventory_prior_art() {
    let api = common::api();
    for contains in [
        "Follower",
        "Container",
        "Inventory",
        "Skill",
        "Equip",
        "Corpse",
        "Backpack",
    ] {
        let reply = api.op(
            "asset_inventory",
            json!({"class": "WidgetBlueprintGeneratedClass", "contains": contains}),
        );
        assert!(reply.ok, "widgets {contains}: {:?}", reply.error);
        let names: Vec<&str> = reply.result["assets"]
            .as_array()
            .into_iter()
            .flatten()
            .filter_map(|a| a["name"].as_str())
            .collect();
        println!("widgets {contains}: {names:?}");
        let reply = api.op(
            "asset_inventory",
            json!({"class": "Blueprint", "contains": contains}),
        );
        let names: Vec<&str> = reply.result["assets"]
            .as_array()
            .into_iter()
            .flatten()
            .filter_map(|a| a["name"].as_str())
            .collect();
        println!("blueprints {contains}: {names:?}");
    }
    for function in [
        "Request_FollowerInitialInteractPress",
        "NPC_InteractWith",
        "NPC_CanInteractWith",
        "CreateInventoryWidget",
        "Request_StopUsingContainer",
        "Request_TryTakeAllItemFromContainer",
    ] {
        let reply = api.op(
            "function_parameters",
            json!({"class": "Abiotic_PlayerCharacter_C", "function": function}),
        );
        println!(
            "player {function}: {}",
            if reply.ok {
                reply.result.to_string()
            } else {
                format!("{:?}", reply.error)
            }
        );
    }
}

/// How a container opens its inventory for the player: the functions on the
/// deployed container, the pet container, the container panel widget, and
/// the player's own open/use path.
#[test]
#[ignore = "requires the running game; lists the container open path"]
fn container_open_path() {
    let api = common::api();
    for class in [
        "Deployed_Container_ParentBP_C",
        "Deployed_PetContainer_ParentBP_C",
        "W_Inventory_Container_C",
        "Abiotic_InventoryComponent_C",
        "W_PlayerInventory_Main_C",
        "Abiotic_PlayerCharacter_C",
        "Abiotic_Character_ParentBP_C",
    ] {
        let reply = api.op("class_functions_by_name", json!({"class": class}));
        let names: Vec<&str> = reply.result["functions"]
            .as_array()
            .into_iter()
            .flatten()
            .filter_map(|f| f["name"].as_str())
            .filter(|n| {
                class.starts_with("Deployed")
                    || class.starts_with("W_Inventory_Container")
                    || ["Container", "Open", "Use", "Interact", "Equip"]
                        .iter()
                        .any(|p| n.contains(p))
            })
            .collect();
        println!(
            "{class} ({}): {names:?}",
            if reply.ok { "ok" } else { "error" }
        );
    }
    for (class, function) in [
        ("Abiotic_PlayerCharacter_C", "InteractWith_A"),
        ("Abiotic_PlayerCharacter_C", "Request_InteractA"),
        ("Abiotic_Character_ParentBP_C", "InteractWith_A"),
    ] {
        let reply = api.op(
            "function_parameters",
            json!({"class": class, "function": function}),
        );
        println!(
            "{class}::{function}: {}",
            if reply.ok {
                reply.result.to_string()
            } else {
                format!("{:?}", reply.error)
            }
        );
    }
}

/// Does the function watch see the human's character at all: its tick and a
/// direct reflected call, recorded for half a second.
#[test]
#[ignore = "requires the running game; checks the function watch on the human's character"]
fn watch_sees_the_human() {
    let api = common::api();
    let players = api.op("players", json!({}));
    let human = players.result["players"]
        .as_array()
        .expect("players")
        .iter()
        .find(|p| p["name"] != "Sophia")
        .expect("human")
        .clone();
    let character = human["character"].as_str().expect("character").to_owned();
    for function in ["ReceiveTick", "CanInteractRightNow", "NPC_CanInteractWith"] {
        let reply = api.op(
            "hook.watch",
            json!({"class": "Abiotic_PlayerCharacter_C", "function": function}),
        );
        println!("watch {function}: {} {:?}", reply.result, reply.error);
    }
    api.op("hook.log", json!({"clear": true}));
    let direct = api.op("object.call", json!({"object": format!("addr:{character}"), "class": "Abiotic_PlayerCharacter_C", "function": "NPC_CanInteractWith"}));
    println!(
        "direct NPC_CanInteractWith: {} {:?}",
        direct.result, direct.error
    );
    std::thread::sleep(std::time::Duration::from_millis(500));
    let log = api.op("hook.log", json!({"limit": 512}));
    let calls = log.result["calls"].as_array().cloned().unwrap_or_default();
    println!("{} calls recorded", calls.len());
    for entry in calls.iter().take(8) {
        println!(
            "{} {} {}::{}",
            entry["t_ms"], entry["object"], entry["class"], entry["function"]
        );
    }
    api.op(
        "hook.unwatch",
        json!({"class": "Abiotic_PlayerCharacter_C"}),
    );
}

/// Who sets the inventory screen's ActiveContainer: every function on the
/// inventory screen, and the player's client and server functions that name
/// a container, with their parameters.
#[test]
#[ignore = "requires the running game; lists the inventory screen's functions and the player's container functions"]
fn container_open_functions() {
    let api = common::api();
    let boxy = api.op(
        "asset_inventory",
        json!({"class": "Blueprint", "contains": "Container_Boxy"}),
    );
    println!("boxy container asset: {}", boxy.result["assets"]);
    let screen = api.op(
        "class_functions_by_name",
        json!({"class": "W_PlayerInventory_Main_C"}),
    );
    let names: Vec<&str> = screen.result["functions"]
        .as_array()
        .into_iter()
        .flatten()
        .filter_map(|f| f["name"].as_str())
        .filter(|n| !n.starts_with("BndEvt"))
        .collect();
    println!("inventory screen functions: {names:?}");
    let player = api.op(
        "class_functions_by_name",
        json!({"class": "Abiotic_PlayerCharacter_C"}),
    );
    let names: Vec<&str> = player.result["functions"]
        .as_array()
        .into_iter()
        .flatten()
        .filter_map(|f| f["name"].as_str())
        .filter(|n| {
            n.contains("Container")
                || ((n.starts_with("Client")
                    || n.starts_with("Server")
                    || n.starts_with("Request"))
                    && (n.contains("Open") || n.contains("Interact") || n.contains("Use")))
        })
        .collect();
    println!("player container functions: {names:?}");
    for function in names.iter().filter(|n| n.contains("Container")) {
        let reply = api.op(
            "function_parameters",
            json!({"class": "Abiotic_PlayerCharacter_C", "function": function}),
        );
        println!("player {function}: {}", reply.result["parameters"]);
    }
    for class in [
        "W_PlayerInventory_Main_C",
        "Abiotic_InventoryComponent_C",
        "Deployed_Container_ParentBP_C",
    ] {
        let functions = api.op("class_functions_by_name", json!({"class": class}));
        for function in functions.result["functions"]
            .as_array()
            .into_iter()
            .flatten()
            .filter_map(|f| f["name"].as_str())
            .filter(|n| n.contains("Container") && !n.starts_with("BndEvt"))
        {
            let reply = api.op(
                "function_parameters",
                json!({"class": class, "function": function}),
            );
            println!("{class}::{function}: {}", reply.result["parameters"]);
        }
    }
}

/// The game's state while the human has a container open: the container panel's
/// fields, the fields on the human's character naming a container, and the
/// in-use fields on the nearest container. Read after an 8 second wait.
#[test]
#[ignore = "requires the running game; the human keeps a container open while this reads the panel, the character and the container"]
fn container_open_state() {
    let api = common::api();
    println!("open a container and keep it open: reading in 8 seconds");
    std::thread::sleep(std::time::Duration::from_secs(8));
    let players = api.op("players", json!({}));
    let human = players.result["players"]
        .as_array()
        .expect("players")
        .iter()
        .find(|p| p["name"] != "Sophia")
        .expect("human")
        .clone();
    let character = human["character"].as_str().expect("character").to_owned();
    let interesting = |name: &str| {
        [
            "Container",
            "Interact",
            "Using",
            "Used",
            "Inventory",
            "Widget",
        ]
        .iter()
        .any(|p| name.contains(p))
    };
    let show = |label: &str, fields: &serde_json::Value| {
        let picked: serde_json::Map<String, serde_json::Value> = fields
            .as_object()
            .into_iter()
            .flatten()
            .filter(|(k, _)| interesting(k))
            .map(|(k, v)| {
                (
                    k.clone(),
                    if v["addr"].is_string() {
                        json!(format!("{} {} {}", v["class"], v["name"], v["addr"]))
                    } else {
                        v.clone()
                    },
                )
            })
            .collect();
        println!("{label}: {}", serde_json::Value::Object(picked));
    };
    let reference = |name: &str| {
        [
            "Inventory",
            "Container",
            "Owner",
            "Reference",
            "Character",
            "Target",
            "Component",
        ]
        .iter()
        .any(|p| name.contains(p))
    };
    let panels = api.op(
        "walk_class",
        json!({"class": "W_Inventory_Container_C", "max": 16}),
    );
    for panel in panels.result["instances"].as_array().into_iter().flatten() {
        let fields = api.op("object.get", json!({"object": panel["addr_selector"]}));
        let picked: serde_json::Map<String, serde_json::Value> = fields
            .result
            .as_object()
            .into_iter()
            .flatten()
            .filter(|(k, v)| reference(k) && !k.starts_with("Button") && !v.is_null())
            .map(|(k, v)| {
                (
                    k.clone(),
                    if v["addr"].is_string() {
                        json!(format!("{} {} {}", v["class"], v["name"], v["addr"]))
                    } else {
                        v.clone()
                    },
                )
            })
            .collect();
        println!(
            "panel {} {}: {}",
            panel["name"],
            panel["addr"],
            serde_json::Value::Object(picked)
                .to_string()
                .chars()
                .take(1500)
                .collect::<String>()
        );
    }
    let fields = api.op("object.get", json!({"object": format!("addr:{character}")}));
    show("human character", &fields.result);
    // The thing the human is looking at, and the main inventory screen's container fields.
    if let Some(target) = fields.result["BestInteractable_InteractA"]["addr"].as_str() {
        let target_fields = api.op("object.get", json!({"object": format!("addr:{target}")}));
        println!(
            "looked at: {} {}",
            fields.result["BestInteractable_InteractA"]["class"],
            fields.result["BestInteractable_InteractA"]["name"]
        );
        show("looked at", &target_fields.result);
    }
    if let Some(screen) = fields.result["InventoryReference"]["addr"].as_str() {
        let screen_fields = api.op("object.get", json!({"object": format!("addr:{screen}")}));
        let picked: serde_json::Map<String, serde_json::Value> = screen_fields
            .result
            .as_object()
            .into_iter()
            .flatten()
            .filter(|(k, v)| k.contains("Container") && !v.is_null())
            .map(|(k, v)| {
                (
                    k.clone(),
                    if v["addr"].is_string() {
                        json!(format!("{} {} {}", v["class"], v["name"], v["addr"]))
                    } else {
                        v.clone()
                    },
                )
            })
            .collect();
        println!(
            "inventory screen container fields: {}",
            serde_json::Value::Object(picked)
        );
    }
    let context = u64::from_str_radix(character.trim_start_matches("0x"), 16).unwrap();
    let actors = api.op(
        "actors_of_class",
        json!({"world_context": context, "class": "Deployed_Container_ParentBP_C"}),
    );
    let distance = |a: &serde_json::Value| {
        (0..3)
            .map(|i| {
                (a["location"][i].as_f64().unwrap_or(0.0)
                    - human["location"][i].as_f64().unwrap_or(0.0))
                .powi(2)
            })
            .sum::<f64>()
    };
    if let Some(container) = actors.result["actors"]
        .as_array()
        .into_iter()
        .flatten()
        .min_by(|a, b| distance(a).total_cmp(&distance(b)))
    {
        println!(
            "nearest container: {} {} at {:.0} units",
            container["class"],
            container["name"],
            distance(container).sqrt()
        );
        let fields = api.op(
            "object.get",
            json!({"object": format!("addr:{}", container["addr"].as_str().unwrap_or("0x0"))}),
        );
        show("container", &fields.result);
    }
}

/// The game opening a real container for the human, recorded: every call on
/// the nearest deployed container, on the container panel, and the player's
/// container calls, around the player's own Request_InteractA. Closes it after.
#[test]
#[ignore = "requires the running game; opens the nearest container on the human's screen for two seconds and records the calls"]
fn container_open_recorded() {
    let api = common::api();
    let players = api.op("players", json!({}));
    let human = players.result["players"]
        .as_array()
        .expect("players")
        .iter()
        .find(|p| p["name"] != "Sophia")
        .expect("human")
        .clone();
    let character = human["character"].as_str().expect("character").to_owned();
    let context = u64::from_str_radix(character.trim_start_matches("0x"), 16).unwrap();
    let actors = api.op(
        "actors_of_class",
        json!({"world_context": context, "class": "Deployed_Container_ParentBP_C"}),
    );
    assert!(actors.ok, "containers: {:?}", actors.error);
    let distance = |a: &serde_json::Value| {
        (0..3)
            .map(|i| {
                (a["location"][i].as_f64().unwrap_or(0.0)
                    - human["location"][i].as_f64().unwrap_or(0.0))
                .powi(2)
            })
            .sum::<f64>()
    };
    let container = actors.result["actors"]
        .as_array()
        .expect("actors")
        .iter()
        .min_by(|a, b| distance(a).total_cmp(&distance(b)))
        .expect("a container")
        .clone();
    println!(
        "container: {} {} at {:.0} units",
        container["class"],
        container["name"],
        distance(&container).sqrt()
    );
    // Named functions only: a class-wide watch on a blueprint class records every
    // actor sharing the native function table and floods the log with ticks.
    let watched = [
        (
            "Deployed_Container_ParentBP_C",
            [
                "InteractWith_A",
                "CanInteractWith_A",
                "OnContainerBeingUsed",
                "Server_CheckContainerUsage",
                "ValidateContainerUsage",
                "GetContainerInventory",
                "OnRep_IsContainerBeingUsed",
                "Server_UserLeftContainer",
            ]
            .as_slice(),
        ),
        (
            "W_Inventory_Container_C",
            [
                "SetInventoryReference",
                "Construct",
                "RefreshContainerInfoAndGrid",
                "InventoryUpdated",
            ]
            .as_slice(),
        ),
        (
            "Abiotic_PlayerCharacter_C",
            [
                "Request_InteractA",
                "InteractWith_A",
                "Request_StopUsingContainer",
                "CreateInventoryWidget",
                "Local_TryInteraction",
                "Local_Try_StartInteraction",
                "Request_TryTakeAllItemFromContainer",
            ]
            .as_slice(),
        ),
    ];
    for (class, functions) in watched {
        for function in functions {
            let reply = api.op("hook.watch", json!({"class": class, "function": function}));
            assert!(reply.ok, "watch {class}::{function}: {:?}", reply.error);
        }
    }
    api.op("hook.log", json!({"clear": true}));
    // The human opens and closes a container by hand within the window, so the
    // recorded path is the game's own from the interact key onward.
    println!("open and close a container in the game now: recording for 15 seconds");
    std::thread::sleep(std::time::Duration::from_secs(15));
    let log = api.op("hook.log", json!({"limit": 512}));
    for entry in log.result["calls"].as_array().into_iter().flatten() {
        println!(
            "{} {} {}::{} {}",
            entry["t_ms"],
            entry["object"],
            entry["class"],
            entry["function"],
            entry["params"]
                .to_string()
                .chars()
                .take(300)
                .collect::<String>()
        );
    }
    for (class, _) in watched {
        api.op("hook.unwatch", json!({"class": class}));
    }
    let inventory = api.op("object.call", json!({"object": format!("addr:{}", container["addr"].as_str().unwrap_or("0x0")), "class": "Deployed_Container_ParentBP_C", "function": "GetContainerInventory"}));
    println!(
        "nearest container's GetContainerInventory: {} {:?}",
        inventory.result, inventory.error
    );
    let _ = character;
}

/// What Sophia's animation instance reads while she stands and while she walks:
/// its own variables, her velocity, and whether it can see her as its owner class.
#[test]
#[ignore = "requires the running game and a spawned Sophia; reads her animation instance twice around a follow"]
fn sophia_animation_instance() {
    let api = common::api();
    let status = api.op("ai_player.status", json!({"player": "Sophia"}));
    assert!(status.ok, "status: {:?}", status.error);
    let pawn = status.result["pawn"]["addr"]
        .as_str()
        .expect("Sophia pawn")
        .to_owned();
    let mesh = api.op(
        "object.get",
        json!({"object": format!("addr:{pawn}"), "fields": ["Mesh"]}),
    );
    let mesh = mesh.result["Mesh"]["addr"]
        .as_str()
        .expect("mesh")
        .to_owned();
    let anim = api.op("object.get", json!({"object": format!("addr:{mesh}"), "fields": ["AnimScriptInstance", "AnimClass", "AnimationMode"]}));
    println!("mesh animation: {}", anim.result);
    let instance = anim.result["AnimScriptInstance"]["addr"]
        .as_str()
        .expect("animation instance")
        .to_owned();
    let human = common::human_name(&api, "Sophia");
    let follow = api.op(
        "ai_player.follow",
        json!({"player": "Sophia", "target": human, "distance": 150.0}),
    );
    println!("follow: {} {:?}", follow.result, follow.error);
    for pass in ["standing", "after follow"] {
        let fields = api.op("object.get", json!({"object": format!("addr:{instance}")}));
        assert!(fields.ok, "animation instance: {:?}", fields.error);
        let plain: serde_json::Map<String, serde_json::Value> = fields
            .result
            .as_object()
            .expect("fields")
            .iter()
            .filter(|(_, v)| {
                v.is_number() || v.is_boolean() || v["addr"].is_string() || v.is_string()
            })
            .map(|(k, v)| {
                (
                    k.clone(),
                    if v["addr"].is_string() {
                        json!(format!("{} {}", v["class"], v["name"]))
                    } else {
                        v.clone()
                    },
                )
            })
            .collect();
        let velocity = api.op(
            "object.call",
            json!({"object": format!("addr:{pawn}"), "class": "Actor", "function": "GetVelocity"}),
        );
        println!(
            "{pass}: velocity {} instance {}",
            velocity.result["ReturnValue"],
            serde_json::Value::Object(plain)
        );
        std::thread::sleep(std::time::Duration::from_secs(3));
    }
}

#[test]
#[ignore = "requires the running game; lists scientist character assets"]
fn scientist_assets() {
    let api = common::api();
    for (op, args) in [
        (
            "walk_class",
            json!({"class": "NarrativeNPC_Human_ParentBP_C", "max": 4096}),
        ),
        (
            "dump_data_table",
            json!({"table_name": "DT_NPC_Conversations", "max_rows": 4096}),
        ),
    ] {
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
                    let appearance =
                        api.op("object.get", json!({"object": format!("addr:{address}")}));
                    assert!(appearance.ok, "appearance: {:?}", appearance.error);
                    println!("appearance: {}", appearance.result);
                }
            }
        }
    }
    // Blueprint assets carry the NPC names; the empty class name is not "any class".
    for (class, contains) in [
        ("Blueprint", "NarrativeNPC"),
        ("Blueprint", "Janet"),
        ("SkeletalMesh", "Female"),
        ("SkeletalMesh", "Scientist"),
        ("AnimBlueprint", ""),
        ("Skeleton", ""),
        ("AnimSequence", "Scientist"),
    ] {
        let reply = api.op(
            "asset_inventory",
            json!({"class": class, "contains": contains}),
        );
        assert!(reply.ok, "{class}/{contains}: {:?}", reply.error);
        println!("{class}/{contains}: {}", reply.result);
    }
}
