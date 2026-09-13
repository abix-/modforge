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

/// How does the game bring an NPC from its asset into the world? Live spawner
/// objects and every function about spawning NPCs on them, the game mode,
/// the game state and the engine's asset loading library.
#[test]
fn npc_spawn_functions() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    let (total, spawners) = classes(&api, "Spawn");
    println!("Spawn chain: {total} objects, live classes {spawners:?}");
    let mut wanted: Vec<String> = spawners.keys().cloned().collect();
    wanted.extend(["Abiotic_Survival_GameMode_C", "Abiotic_Survival_GameState_C", "Abiotic_GameInstance_C", "KismetSystemLibrary", "GameplayStatics"].map(str::to_owned));
    for class in wanted {
        let reply = api.op("class_functions_by_name", json!({"class": class}));
        if !reply.ok { continue; }
        let names: Vec<&str> = reply.result["functions"].as_array().into_iter().flatten()
            .filter_map(|f| f["name"].as_str())
            .filter(|n| n.contains("Spawn") || n.contains("LoadAsset") || n.contains("LoadClass") || n.contains("NPC"))
            .collect();
        if !names.is_empty() { println!("{class}: {names:?}"); }
    }
}

/// Who counts as an enemy to a perception component: the affiliation bits
/// on every live sense config (detect enemies / neutrals / friendlies), the
/// team id on every live AI controller and player controller, and the
/// perception component fields on Sophia's controller.
#[test]
fn perception_affiliation_and_teams() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    let read = |address: u64, length: usize| -> Vec<u8> {
        let reply = api.op("read_bytes", json!({"instance_selector": format!("addr:0x{address:X}"), "length": length}));
        assert!(reply.ok, "read_bytes: {:?}", reply.error);
        hex::decode(reply.result["bytes_hex"].as_str().expect("bytes_hex")).expect("hex")
    };
    let addr = |i: &Value| u64::from_str_radix(i["addr"].as_str().unwrap().trim_start_matches("0x"), 16).unwrap();
    // FAISenseAffiliationFilter is one byte of bitfields: enemies (1), neutrals (2), friendlies (4).
    for needle in ["AISenseConfig_Sight", "AISenseConfig_Hearing"] {
        let reply = api.op("walk_class_chain", json!({"needle": needle, "max": 256}));
        assert!(reply.ok, "{needle}: {:?}", reply.error);
        for instance in reply.result["instances"].as_array().into_iter().flatten().filter(|i| i["is_cdo"] == false) {
            let address = addr(instance);
            let fields = spawn_trace::object_fields(&api, address).expect("config fields");
            let Some((_, _, offset)) = fields.iter().find(|(n, _, _)| n == "DetectionByAffiliation") else { continue };
            let bits = read(address + u64::from(*offset), 1)[0];
            println!("{needle} affiliation 0b{bits:03b} (enemies {}, neutrals {}, friendlies {}) on {}", bits & 1, (bits >> 1) & 1, (bits >> 2) & 1, instance["full_name"].as_str().unwrap_or(""));
        }
    }
    // Team ids: AIController carries a TeamID byte (255 = no team); the game may set it per NPC.
    for needle in ["AIController", "Abiotic_PlayerController_C"] {
        let reply = api.op("walk_class_chain", json!({"needle": needle, "max": 128}));
        assert!(reply.ok, "{needle}: {:?}", reply.error);
        for instance in reply.result["instances"].as_array().into_iter().flatten().filter(|i| i["is_cdo"] == false) {
            let address = addr(instance);
            let fields = spawn_trace::object_fields(&api, address).expect("controller fields");
            let team: Vec<String> = fields.iter().filter(|(n, _, _)| n.contains("Team") || n.contains("Faction") || n.contains("Affiliation"))
                .map(|(n, k, o)| format!("{n}:{k}={:?}", read(address + u64::from(*o), if k == "ByteProperty" || k == "BoolProperty" { 1 } else { 4 }))).collect();
            println!("{} team fields {team:?}", instance["full_name"].as_str().unwrap_or("").split_whitespace().next().unwrap_or(""));
        }
    }
    // The NPC character's faction byte, which the hostility check reads.
    let characters = api.op("walk_class_chain", json!({"needle": "NPC_", "max": 64}));
    for instance in characters.result["instances"].as_array().into_iter().flatten().filter(|i| i["is_cdo"] == false && i["full_name"].as_str().is_some_and(|n| n.starts_with("NPC_"))) {
        let address = addr(instance);
        let fields = spawn_trace::object_fields(&api, address).expect("character fields");
        let faction: Vec<String> = fields.iter().filter(|(n, _, _)| n.contains("Faction") || n.contains("Team") || n.contains("Hostil"))
            .map(|(n, k, o)| format!("{n}:{k}@{o}={:?}", read(address + u64::from(*o), if k == "ByteProperty" || k == "BoolProperty" || k == "EnumProperty" { 1 } else { 4 }))).collect();
        println!("{} faction fields {faction:?}", instance["full_name"].as_str().unwrap_or("").split_whitespace().next().unwrap_or(""));
        break;
    }
}

/// How the game's own NPC spawner works: its class chain, every field and
/// function on it and its parents, and TrySpawnNPC's parameters. A plain
/// actor spawn of NPC_Monster_Exor killed the game within two seconds
/// (2026-09-13, twice), so NPCs go through this instead.
#[test]
fn npc_spawner_setup() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    // A live spawner's every reflected field, parents included, plus its class chain.
    let spawners = api.op("walk_class_chain", json!({"needle": "NPCSpawn_Pest_C", "max": 8}));
    assert!(spawners.ok, "spawners: {:?}", spawners.error);
    if let Some(live) = spawners.result["instances"].as_array().into_iter().flatten().find(|i| i["is_cdo"] == false && i["full_name"].as_str().is_some_and(|n| n.starts_with("NPCSpawn_Pest_C "))) {
        println!("live spawner: {} chain {}", live["full_name"], live["chain"]);
        let address = u64::from_str_radix(live["addr"].as_str().unwrap().trim_start_matches("0x"), 16).unwrap();
        let fields = spawn_trace::object_fields(&api, address).expect("spawner fields");
        println!("spawner fields: {}", fields.iter().map(|(n, k, o)| format!("{n}:{k}@{o}")).collect::<Vec<_>>().join(" "));
    }
    // discover_class_detail returns nothing for these Blueprint classes; walk the
    // live spawner's class chain (UObject class at +16, UStruct super at +64,
    // FName at +24) and ask each class for its own functions.
    let read = |address: u64, length: usize| -> Vec<u8> {
        let reply = api.op("read_bytes", json!({"instance_selector": format!("addr:0x{address:X}"), "length": length}));
        assert!(reply.ok, "read_bytes: {:?}", reply.error);
        hex::decode(reply.result["bytes_hex"].as_str().expect("bytes_hex")).expect("hex")
    };
    let name_of = |object: u64| -> String {
        let fname = u64::from_le_bytes(read(object + 24, 8).try_into().unwrap());
        api.op("fname_to_string", json!({"fname": fname})).result["string"].as_str().unwrap_or("?").to_owned()
    };
    let live = spawners.result["instances"].as_array().into_iter().flatten().find(|i| i["is_cdo"] == false && i["full_name"].as_str().is_some_and(|n| n.starts_with("NPCSpawn_Pest_C "))).expect("a live pest spawner");
    let address = u64::from_str_radix(live["addr"].as_str().unwrap().trim_start_matches("0x"), 16).unwrap();
    let mut class = u64::from_le_bytes(read(address + 16, 8).try_into().unwrap());
    let mut chain = Vec::new();
    while class != 0 && chain.len() < 12 {
        chain.push(name_of(class));
        class = u64::from_le_bytes(read(class + 64, 8).try_into().unwrap());
    }
    println!("spawner class chain: {chain:?}");
    for class in &chain {
        let reply = api.op("class_functions_by_name", json!({"class": class}));
        if !reply.ok { println!("{class}: {:?}", reply.error); continue; }
        let functions: Vec<&str> = reply.result["functions"].as_array().into_iter().flatten().filter_map(|f| f["name"].as_str()).collect();
        println!("{class} functions: {functions:?}");
        for function in functions.iter().filter(|f| f.contains("Spawn")) {
            let parameters = api.op("function_parameters", json!({"class": class, "function": function}));
            println!("{class}::{function}: {}", if parameters.ok { parameters.result.to_string() } else { format!("{:?}", parameters.error) });
        }
    }
}

/// The Exor from the game assets: find its Blueprint in the asset registry,
/// load it into memory through the engine's own loader, then list every
/// Exor object that appeared, including the perception component template
/// and its sense configs that Sophia borrows.
#[test]
fn exor_from_assets() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    let inventory = api.op("asset_inventory", json!({"class": "Blueprint", "contains": "Exor"}));
    assert!(inventory.ok, "asset_inventory: {:?}", inventory.error);
    let assets = inventory.result["assets"].as_array().cloned().unwrap_or_default();
    for asset in &assets { println!("asset {} in {}", asset["name"], asset["package"]); }
    let exor = assets.iter().find(|a| a["name"] == "NPC_Monster_Exor").expect("NPC_Monster_Exor Blueprint in the registry");
    // Cooked builds strip the Blueprint object; the generated class is what loads.
    let class = format!("{}_C", exor["name"].as_str().unwrap());
    let loaded = api.op("load_asset", json!({"package": exor["package"], "asset": class}));
    assert!(loaded.ok, "load_asset: {:?}", loaded.error);
    println!("loaded {class}: {}", loaded.result);
    assert_eq!(loaded.result["loaded"], true, "the Exor class did not load");
    let objects = api.op("walk_class_chain", json!({"needle": "Exor", "max": 512}));
    assert!(objects.ok, "walk_class_chain: {:?}", objects.error);
    println!("Exor objects now: {}", objects.result["total"]);
    for instance in objects.result["instances"].as_array().into_iter().flatten() {
        let full = instance["full_name"].as_str().unwrap_or("");
        if full.contains("Perception") || full.contains("AISense") || full.starts_with("NPC_Monster_Exor_C ") || full.starts_with("BlueprintGeneratedClass") {
            println!("    {full}");
        }
    }
    let configs = spawn_trace::perception_configs(&api).expect("perception configs");
    for row in configs.as_array().into_iter().flatten() {
        if row["owner"].as_str().unwrap_or("").contains("Exor") { println!("Exor sense: {row}"); }
    }
}

/// Read one numeric field of a live object through the control plane.
fn read_number(api: &Api<Value>, object: u64, kind: &str, offset: u32) -> f64 {
    let length = if kind == "DoubleProperty" { 8 } else { 4 };
    let reply = api.op("read_bytes", json!({"instance_selector": format!("addr:0x{:X}", object + offset as u64), "length": length}));
    assert!(reply.ok, "read_bytes: {:?}", reply.error);
    let bytes = hex::decode(reply.result["bytes_hex"].as_str().expect("bytes_hex")).expect("hex");
    match kind {
        "DoubleProperty" => f64::from_le_bytes(bytes.try_into().unwrap()),
        "IntProperty" => i32::from_le_bytes(bytes.try_into().unwrap()) as f64,
        _ => f32::from_le_bytes(bytes.try_into().unwrap()) as f64,
    }
}

/// Does a direct server-side attack call on Sophia's UDP-owned character hurt
/// an enemy? Finds the nearest non-player character to Sophia, reads its
/// health field, calls ai_player.attack facing it, and reads the health again.
/// Bring Sophia within melee range of an enemy before running this.
#[test]
#[ignore = "swings Sophia's weapon at the nearest enemy; needs her mod-owned session running and an enemy in melee range"]
fn sophia_melee_attack_lands() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    let players = api.op("players", json!({}));
    assert!(players.ok, "players: {:?}", players.error);
    let sophia = players.result["players"].as_array().into_iter().flatten().find(|p| p["name"] == "Sophia").expect("Sophia is in the game").clone();
    let at = |v: &Value| -> [f64; 3] { let a = v.as_array().expect("location"); [a[0].as_f64().unwrap(), a[1].as_f64().unwrap(), a[2].as_f64().unwrap()] };
    let from = at(&sophia["location"]);
    let context = u64::from_str_radix(sophia["character"].as_str().unwrap().trim_start_matches("0x"), 16).unwrap();
    // Every character in the world except players; the nearest one is the target.
    let actors = api.op("actors_of_class", json!({"world_context": context, "class": "Character"}));
    assert!(actors.ok, "actors_of_class: {:?}", actors.error);
    let mut enemies: Vec<(f64, Value)> = actors.result["actors"].as_array().into_iter().flatten()
        .filter(|a| !a["class"].as_str().unwrap_or("").contains("PlayerCharacter") && a["location"].is_array())
        .map(|a| { let p = at(&a["location"]); (((p[0] - from[0]).powi(2) + (p[1] - from[1]).powi(2)).sqrt(), a.clone()) }).collect();
    enemies.sort_by(|a, b| a.0.total_cmp(&b.0));
    for (distance, enemy) in enemies.iter().take(5) { println!("{:.0} units: {} at {}", distance, enemy["class"], enemy["location"]); }
    let (mut distance, enemy) = enemies.first().expect("a non-player character in the world").clone();
    // Walk to it: stop any follow loop, travel to the enemy, wait until within melee range.
    let stopped = api.op("ai_player.follow", json!({"player": ""}));
    assert!(stopped.ok, "follow stop: {:?}", stopped.error);
    let travel = api.op("ai_player.travel", json!({"to": enemy["location"]}));
    assert!(travel.ok, "ai_player.travel: {:?}", travel.error);
    println!("walking to {}: {}", enemy["class"], travel.result["points"].as_array().map_or(0, |p| p.len()));
    let deadline = std::time::Instant::now() + std::time::Duration::from_secs(90);
    while distance > 250.0 && std::time::Instant::now() < deadline {
        std::thread::sleep(std::time::Duration::from_secs(2));
        let players = api.op("players", json!({}));
        let here = players.result["players"].as_array().into_iter().flatten().find(|p| p["name"] == "Sophia").map(|p| at(&p["location"])).expect("Sophia");
        let there = at(&enemy["location"]);
        distance = ((here[0] - there[0]).powi(2) + (here[1] - there[1]).powi(2)).sqrt();
        println!("Sophia at {here:?}, {distance:.0} units from the enemy");
    }
    assert!(distance <= 300.0, "nearest enemy {} is still {distance:.0} units away after the walk", enemy["class"]);
    let address = u64::from_str_radix(enemy["addr"].as_str().unwrap().trim_start_matches("0x"), 16).unwrap();
    let fields = spawn_trace::object_fields(&api, address).expect("enemy fields");
    let health: Vec<_> = fields.iter().filter(|(n, k, _)| n.contains("Health") && ["FloatProperty", "DoubleProperty", "IntProperty"].contains(&k.as_str())).cloned().collect();
    println!("{} health fields: {health:?}", enemy["class"]);
    // Live 2026-09-13: the NPC character carries TotalCombinedHealth (double) plus CurrentHealth_<limb> floats.
    let (name, kind, offset) = health.iter().find(|(n, _, _)| n == "TotalCombinedHealth")
        .or_else(|| health.iter().find(|(n, _, _)| n.starts_with("CurrentHealth_") && !n.contains("Texture")))
        .expect("TotalCombinedHealth or a CurrentHealth_ limb field").clone();
    let before = read_number(&api, address, &kind, offset);
    println!("{name} before: {before}");
    let attack = api.op("ai_player.attack", json!({"player": "Sophia", "face": enemy["location"]}));
    assert!(attack.ok, "ai_player.attack: {:?}", attack.error);
    println!("attack: {}", attack.result);
    std::thread::sleep(std::time::Duration::from_secs(2));
    let after = read_number(&api, address, &kind, offset);
    println!("{name} after: {after} (before {before})");
    assert!(after < before, "{} {name} did not drop: {before} -> {after}; the direct server-side call does not land, attacks go over UDP", enemy["class"]);
}
