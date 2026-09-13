//! How do the game's own NPCs get around, and what of it can Sophia reuse?
//!
//! Read-only discovery against the hosted save: the navigation system and
//! its meshes, every AI controller with its pawn, and the path-following,
//! brain (behavior tree) and blackboard components those controllers run.
//! Nothing here moves anyone.
//!
//! ```text
//! cargo test -p abioticfactor-mod --test research_npc_navigation -- --nocapture
//! ```

mod common;
#[path = "common/spawn_trace.rs"]
mod spawn_trace;
use common::{api, ping_or_skip};
use modforge::client::Api;
use serde_json::{Value, json};
use std::collections::BTreeMap;

/// Class name histogram of every non-default object whose class chain contains `needle`.
fn classes(api: &Api<Value>, needle: &str) -> (u64, BTreeMap<String, usize>) {
    let reply = api.op("walk_class_chain", json!({"needle": needle, "max": 2048}));
    assert!(reply.ok, "{needle}: {:?}", reply.error);
    let total = reply.result["total"].as_u64().unwrap_or(0);
    let mut histogram = BTreeMap::new();
    for instance in reply.result["instances"].as_array().into_iter().flatten() {
        if instance["is_cdo"] == true { continue; }
        let class = instance["full_name"].as_str().unwrap_or("").split_whitespace().next().unwrap_or("").to_owned();
        *histogram.entry(class).or_insert(0) += 1;
    }
    (total, histogram)
}

/// Does the host's navigation mesh connect the two player characters? Asks the
/// engine for the path between them through nav.find_path and prints it.
#[test]
fn path_between_player_characters() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    let first = api.op("walk_class_chain", json!({"needle": "Abiotic_PlayerCharacter_C", "max": 8}));
    assert!(first.ok, "characters: {:?}", first.error);
    let context = first.result["instances"].as_array().into_iter().flatten()
        .find(|i| i["is_cdo"] == false).and_then(|i| i["addr"].as_str())
        .map(|a| u64::from_str_radix(a.trim_start_matches("0x"), 16).expect("hex address"))
        .expect("a live player character as world context");
    let actors = api.op("actors_of_class", json!({"world_context": context, "class": "Abiotic_PlayerCharacter_C"}));
    assert!(actors.ok, "actors: {:?}", actors.error);
    let rows = actors.result["actors"].as_array().cloned().unwrap_or_default();
    for row in &rows { println!("character {} at {}", row["name"], row["location"]); }
    assert!(rows.len() >= 2, "need the human and Sophia in the world: {}", actors.result);
    let (from, to) = (rows[0]["location"].clone(), rows[1]["location"].clone());
    let path = api.op("nav.find_path", json!({"from": from, "to": to}));
    assert!(path.ok, "nav.find_path: {:?}", path.error);
    println!("path {} -> {}: {}", rows[0]["name"], rows[1]["name"], path.result);
    let back = api.op("nav.find_path", json!({"from": to, "to": from}));
    assert!(back.ok, "nav.find_path back: {:?}", back.error);
    println!("path back: {} points", back.result["count"]);
}

/// Will the server move a pawn owned by a remote UDP player when the engine's
/// own path following is asked to? Requests SimpleMoveToLocation on Sophia's
/// server-side controller toward the human and watches her server position.
#[test]
#[ignore = "moves Sophia through the engine's path following; needs her mod-owned session running"]
fn engine_path_following_moves_udp_player() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    // Players by the name on their player state; never by position.
    let players = |api: &Api<Value>| {
        let reply = api.op("players", json!({}));
        assert!(reply.ok, "players: {:?}", reply.error);
        reply.result["players"].as_array().cloned().unwrap_or_default()
    };
    let rows = players(&api);
    let sophia = rows.iter().find(|p| p["name"] == "Sophia").expect("Sophia is in the game").clone();
    let human = rows.iter().find(|p| p["name"] != "Sophia").expect("the human is in the game").clone();
    println!("Sophia at {} (character {}), {} at {}", sophia["location"], sophia["character"], human["name"], human["location"]);
    let start = sophia["location"].clone();
    let human_start = human["location"].clone();
    let requested = api.op("nav.simple_move_to", json!({"player": "Sophia", "to": human["location"]}));
    assert!(requested.ok, "simple_move_to: {:?}", requested.error);
    assert_eq!(requested.result["character"], sophia["character"], "the move must target Sophia's character");
    println!("requested: {}", requested.result);
    let distance = |a: &Value, b: &Value| (0..3).map(|i| (a[i].as_f64().unwrap() - b[i].as_f64().unwrap()).powi(2)).sum::<f64>().sqrt();
    let mut moved = 0.0f64;
    for second in 1..=15 {
        std::thread::sleep(std::time::Duration::from_secs(1));
        let now = players(&api);
        let sophia_now = now.iter().find(|p| p["name"] == "Sophia").expect("Sophia still present");
        let human_now = now.iter().find(|p| p["name"] == human["name"]).expect("human still present");
        let delta = distance(&sophia_now["location"], &start);
        moved = moved.max(delta);
        println!("{second}s: Sophia at {} moved {delta:.1}; {} moved {:.1}", sophia_now["location"], human["name"], distance(&human_now["location"], &human_start));
    }
    println!("engine path following moved the UDP player's body: {} (max {moved:.1} units)", moved > 100.0);
}

/// How do NPCs follow a player? Lists the loaded behavior tree assets, every
/// task, decorator and service node inside them (their full names carry the
/// owning tree), the blackboard assets, and the fields of the Carbuncle
/// controller and pawn, the tamable creature that follows its owner.
#[test]
fn npc_follow_behaviour() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    for needle in ["BehaviorTree", "BlackboardData"] {
        let reply = api.op("walk_class_chain", json!({"needle": needle, "max": 256}));
        assert!(reply.ok, "{needle}: {:?}", reply.error);
        for instance in reply.result["instances"].as_array().into_iter().flatten() {
            let name = instance["full_name"].as_str().unwrap_or("");
            if name.starts_with(needle) && instance["is_cdo"] == false { println!("{needle} asset: {name}"); }
        }
    }
    let mut by_tree: BTreeMap<String, Vec<String>> = BTreeMap::new();
    for needle in ["BTTask_", "BTDecorator_", "BTService_", "BTComposite_"] {
        let reply = api.op("walk_class_chain", json!({"needle": needle, "max": 4096}));
        assert!(reply.ok, "{needle}: {:?}", reply.error);
        for instance in reply.result["instances"].as_array().into_iter().flatten() {
            if instance["is_cdo"] == true { continue; }
            let full = instance["full_name"].as_str().unwrap_or("");
            let (class, path) = full.split_once(' ').unwrap_or((full, ""));
            // /Game/.../BT_Pest.BT_Pest:BTTask_MoveTo_0 -> tree BT_Pest, node BTTask_MoveTo_0
            let tree = path.rsplit('/').next().unwrap_or(path).split(['.', ':']).nth(1).unwrap_or(path).to_owned();
            let node = path.rsplit(':').next().unwrap_or(path);
            by_tree.entry(tree).or_default().push(format!("{class} {node}"));
        }
    }
    for (tree, nodes) in &by_tree {
        println!("tree {tree}: {} nodes", nodes.len());
        for node in nodes { println!("    {node}"); }
    }
    // Every AI controller class, parents included (their default objects are in the chain),
    // with the functions that choose targets, fight, and perceive.
    let reply = api.op("walk_class_chain", json!({"needle": "AI_Controller", "max": 2048}));
    assert!(reply.ok, "AI controllers: {:?}", reply.error);
    let mut controller_classes = std::collections::BTreeSet::new();
    for instance in reply.result["instances"].as_array().into_iter().flatten() {
        let full = instance["full_name"].as_str().unwrap_or("");
        let class = full.split_whitespace().next().unwrap_or("").to_owned();
        if instance["is_cdo"] == true { controller_classes.insert(full.rsplit(['.', ':']).next().unwrap_or("").trim_start_matches("Default__").to_owned()); }
        controller_classes.insert(class);
    }
    for class in &controller_classes {
        let functions = api.op("class_functions_by_name", json!({"class": class}));
        if !functions.ok { println!("{class}: {:?}", functions.error); continue; }
        let names: Vec<&str> = functions.result["functions"].as_array().into_iter().flatten().filter_map(|f| f["name"].as_str())
            .filter(|n| ["Target", "Combat", "Attack", "Hostil", "Percep", "Aggro", "Threat", "Damage", "Sense", "Alert"].iter().any(|p| n.contains(p))).collect();
        println!("{class} combat functions: {names:?}");
    }
    for needle in ["Carbuncle"] {
        let (total, histogram) = classes(&api, needle);
        println!("{needle} live classes ({total} objects): {histogram:?}");
        for class in histogram.keys() {
            let detail = api.op("discover_class_detail", json!({"name": class}));
            assert!(detail.ok, "{class}: {:?}", detail.error);
            let fields: Vec<String> = detail.result["fields"].as_array().into_iter().flatten()
                .map(|f| format!("{}@{}", f["name"].as_str().unwrap_or(""), f["offset"])).collect();
            println!("{class} fields: {fields:?}");
            let functions = api.op("class_functions_by_name", json!({"class": class}));
            assert!(functions.ok, "{class}: {:?}", functions.error);
            let names: Vec<&str> = functions.result["functions"].as_array().into_iter().flatten().filter_map(|f| f["name"].as_str()).collect();
            println!("{class} functions: {names:?}");
        }
    }
}

/// How does a player character fight? Sophia is a player, so her attacks are
/// the player character's own functions sent over UDP. Lists the character,
/// controller and equipped-item functions about attacking, blocking, aiming
/// and taking damage, with their network flags.
#[test]
fn player_combat_functions() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    let words = ["Attack", "Fire", "Melee", "Swing", "Weapon", "Block", "Aim", "Damage", "Hit", "Throw", "Reload", "Equip", "Holster", "Combat", "Targetable"];
    for class in ["Abiotic_PlayerCharacter_C", "Abiotic_PlayerController_C", "Abiotic_CharacterBase_C", "AbioticCharacter", "Abiotic_InventoryComponent_C"] {
        let functions = api.op("class_functions_by_name", json!({"class": class}));
        if !functions.ok { println!("{class}: {:?}", functions.error); continue; }
        println!("{class}:");
        for function in functions.result["functions"].as_array().into_iter().flatten() {
            let name = function["name"].as_str().unwrap_or("");
            if words.iter().any(|w| name.contains(w)) { println!("    {function}"); }
        }
    }
    // The enemy character's health fields, for watching an attack land.
    println!("live Pest classes: {:?}", classes(&api, "Pest").1);
    let pests = api.op("walk_class_chain", json!({"needle": "NPC_Monster_Pest_C", "max": 64}));
    // Exact class match: the AI controller's class name contains the character's, so a substring match picks the controller.
    if let Some(pest) = pests.result["instances"].as_array().into_iter().flatten().find(|i| i["is_cdo"] == false && i["full_name"].as_str().is_some_and(|n| n.starts_with("NPC_Monster_Pest_C "))) {
        let address = u64::from_str_radix(pest["addr"].as_str().unwrap().trim_start_matches("0x"), 16).unwrap();
        let fields = spawn_trace::object_fields(&api, address).expect("pest fields");
        let health: Vec<_> = fields.iter().filter(|(n, _, _)| n.contains("Health") || n.contains("HP") || n.contains("Dead")).collect();
        println!("Pest character health fields: {health:?}");
        println!("Pest character all fields: {}", fields.iter().map(|(n, k, o)| format!("{n}:{k}@{o}")).collect::<Vec<_>>().join(" "));
    }
    // Exact parameter layouts of the melee path, for calling them on the game thread.
    for function in ["Request_MeleeAttackDamage", "Request_MeleeAttackFX", "Local_DoMeleeAttack_Event", "DetermineMeleeSwingTarget", "Try_AutoAttack", "Calculate Next Melee Data", "Request_RangedAttack", "Request_FireProjectileWeapon"] {
        let reply = api.op("function_parameters", json!({"class": "Abiotic_PlayerCharacter_C", "function": function}));
        println!("{function}: {}", if reply.ok { reply.result.to_string() } else { format!("{:?}", reply.error) });
    }
}

/// The Exor soldiers are the armed humanoid enemies, the model for how a real
/// fighting NPC is set up. Lists everything loaded whose class or path names
/// them: controllers, characters, trees, perception and sense config objects.
#[test]
fn exor_soldier_setup() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    for needle in ["Exor", "Soldier", "Order", "Military", "Symphonist", "AISenseConfig", "AIPerceptionComponent"] {
        let reply = api.op("walk_class_chain", json!({"needle": needle, "max": 512}));
        assert!(reply.ok, "{needle}: {:?}", reply.error);
        let mut names: BTreeMap<String, usize> = BTreeMap::new();
        for instance in reply.result["instances"].as_array().into_iter().flatten() {
            let full = instance["full_name"].as_str().unwrap_or("");
            let key = if instance["is_cdo"] == true { format!("default {full}") } else { full.split_whitespace().next().unwrap_or("").to_owned() };
            *names.entry(key).or_insert(0) += 1;
        }
        println!("{needle}: {} objects", reply.result["total"]);
        for (name, count) in names { println!("    {count} x {name}"); }
    }
    // The NPC data: tables named like NPCs or spawns, and their rows, where the soldiers are defined.
    let tables = api.op("discover_data_tables", json!({"refresh": true}));
    assert!(tables.ok, "tables: {:?}", tables.error);
    println!("data tables: {}", tables.result);
    let names: Vec<String> = serde_json::to_string(&tables.result).unwrap_or_default()
        .split('"').filter(|s| s.starts_with("DT_")).map(str::to_owned).collect();
    for table in names.iter().filter(|t| ["NPC", "Spawn", "Enemy", "Monster", "Creature"].iter().any(|w| t.contains(w))) {
        let rows = api.op("list_row_names", json!({"table_name": table}));
        println!("{table} rows: {}", rows.result);
    }
    // The soldier rows in full, decoded field by field: character class, controller, numbers.
    let rows = spawn_trace::table_rows(&api, "DT_NPCList", &["Exor", "Exor_Armored", "Exor_Monk", "Exor_Pikeman", "Grunt", "Grunt_Captain", "Pest"]).expect("NPC rows");
    println!("NPC rows: {}", serde_json::to_string_pretty(&rows).unwrap());
}

/// The perception numbers enemies use: every live sight and hearing config with
/// its owner. Sophia's perception component copies the fighting humanoid's values.
#[test]
fn npc_perception_configs() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    let configs = spawn_trace::perception_configs(&api).expect("perception configs");
    // Collapse identical setups so the table is readable: one line per distinct numbers, with owner classes.
    let mut distinct: BTreeMap<String, Vec<String>> = BTreeMap::new();
    for row in configs.as_array().into_iter().flatten() {
        // Owner path: ...PersistentLevel.AI_Controller_X_C_123.AIPerception.AISenseConfig_Sight_0 -> AI_Controller_X_C
        let owner = row["owner"].as_str().unwrap_or("").split(['.', ':']).find(|s| s.contains("_C_") && s.rsplit('_').next().is_some_and(|d| d.chars().all(|c| c.is_ascii_digit())))
            .map(|s| s.rsplit_once('_').map(|(c, _)| c).unwrap_or(s)).unwrap_or("").to_owned();
        let mut numbers = row.clone();
        numbers.as_object_mut().unwrap().remove("owner");
        distinct.entry(numbers.to_string()).or_default().push(owner);
    }
    for (numbers, owners) in distinct {
        let mut owners = owners; owners.sort(); owners.dedup();
        println!("{numbers}\n    on {owners:?}");
    }
}

#[test]
fn npc_navigation_systems() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    for needle in ["NavigationSystemV1", "RecastNavMesh", "NavMeshBoundsVolume", "NavLinkProxy", "NavModifierVolume"] {
        let (total, histogram) = classes(&api, needle);
        println!("{needle}: {total} objects, live classes {histogram:?}");
    }
    let (total, controllers) = classes(&api, "AIController");
    println!("AIController chain: {total} objects, live classes {controllers:?}");
    for needle in ["PathFollowingComponent", "BrainComponent", "BlackboardComponent", "CrowdFollowingComponent", "AIPerceptionComponent"] {
        let (total, histogram) = classes(&api, needle);
        println!("{needle}: {total} objects, live classes {histogram:?}");
    }
    // The functions each live AI controller class exposes, filtered to movement and pathing.
    for class in controllers.keys() {
        let reply = api.op("class_functions_by_name", json!({"class": class}));
        assert!(reply.ok, "{class}: {:?}", reply.error);
        let names: Vec<&str> = reply.result["functions"].as_array().into_iter().flatten()
            .filter_map(|f| f["name"].as_str())
            .filter(|n| ["Move", "Path", "Nav", "Patrol", "Wander", "Chase", "Target", "Follow"].iter().any(|part| n.contains(part)))
            .collect();
        println!("{class} movement functions: {names:?}");
        let detail = api.op("discover_class_detail", json!({"name": class}));
        assert!(detail.ok, "{class} detail: {:?}", detail.error);
        let mut summary = detail.result.clone();
        if let Some(object) = summary.as_object_mut() { object.remove("fields"); object.remove("functions"); }
        println!("{class} detail: {summary}");
    }
    // Which behavior tree asset each brain runs, from the component's reflected fields.
    let brains = api.op("walk_class_chain", json!({"needle": "BehaviorTreeComponent", "max": 64}));
    assert!(brains.ok, "brains: {:?}", brains.error);
    let detail = api.op("discover_class_detail", json!({"name": "BehaviorTreeComponent"}));
    assert!(detail.ok, "BehaviorTreeComponent detail: {:?}", detail.error);
    let fields: Vec<String> = detail.result["fields"].as_array().into_iter().flatten()
        .map(|f| format!("{}@{}", f["name"].as_str().unwrap_or(""), f["offset"])).collect();
    println!("BehaviorTreeComponent fields: {fields:?}");
    for brain in brains.result["instances"].as_array().into_iter().flatten().take(12) {
        println!("brain: {}", brain["full_name"].as_str().unwrap_or(""));
    }
}
