//! Bring a real NPC into the world the way the game does: through one of
//! its own NPC spawner Blueprints (Abiotic_NPCSpawn_ParentBP_C children
//! such as NPCSpawn_QuillExor). The spawner class is loaded from the game
//! assets when it is not in memory, placed near a named player with the
//! engine's actor spawn, and told to spawn with its own DebugSpawn. The
//! NPC then arrives with everything the game gives it. A plain actor spawn
//! of NPC_Monster_Exor killed the game within two seconds (2026-09-13,
//! twice); spawners are the supported path. Everything through ueforge's
//! generic spawn, call and field tools.
use serde_json::{Value, json};
use std::time::Duration;
use ueforge::ue::UObject;

/// Where the game keeps its spawner Blueprints (asset registry, 2026-09-13).
const SPAWNER_PACKAGE_DIR: &str = "/Game/Blueprints/Environment/Spawns";
const SPAWNER_PARENT: &str = "Abiotic_NPCSpawn_ParentBP_C";

/// The loaded class for a Blueprint name, loading `<dir>/<name>` if needed. Game thread.
pub(crate) fn blueprint_class(dir: &str, name: &str) -> Result<&'static ueforge::ue::UClass, String> {
    let class_name = format!("{name}_C");
    if let Some(class) = ueforge::ue::find_class_fast(&class_name) { return Ok(class); }
    let address = ueforge::reflect::object_ref(&json!(format!("asset:{dir}/{name}.{class_name}")))?;
    ueforge::ue::find_class_fast(&class_name).ok_or_else(|| format!("{class_name} loaded at 0x{address:X} but is not findable as a class"))
}

/// The NPCs a spawner tracks: name, class, location.
unsafe fn current_npcs(spawner: &UObject) -> Result<Vec<Value>, String> {
    Ok(unsafe { ueforge::reflect::array_get(spawner, "CurrentNPCs", None)? }["elements"].as_array().into_iter().flatten()
        .filter_map(|npc| { let address = crate::ai_player::addr(npc); if address == 0 { None } else { Some(unsafe { crate::ai_player::describe(address) }) } }).collect())
}

/// Place a spawner Blueprint `distance` units along +X from a named player's
/// character (default 600) and make it spawn its NPC.
fn spawn(args: &Value) -> Result<Value, String> {
    let spawner = args["spawner"].as_str().filter(|s| !s.is_empty()).unwrap_or("NPCSpawn_QuillExor").to_owned();
    let player = args["near_player"].as_str().filter(|s| !s.is_empty()).ok_or("near_player must be a player name")?.to_owned();
    let distance = args["distance"].as_f64().unwrap_or(600.0);
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(30), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (_, character) = unsafe { crate::nav::player_character(&player)? };
        let (x, y, z) = unsafe { ueforge::ue::transform::world_location(character as *const UObject as *const u8) }.ok_or("player character has no location")?;
        let class = blueprint_class(SPAWNER_PACKAGE_DIR, &spawner)?.as_object().name();
        let location = (x + distance, y, z);
        let actor = unsafe { ueforge::spawn_ops::spawn_actor(character, &class, location, 180.0, &serde_json::Map::new())? };
        // SAFETY: a live actor the engine just finished spawning.
        let object = unsafe { &*(actor as *const UObject) };
        unsafe { ueforge::reflect::call(object, SPAWNER_PARENT, "DebugSpawn", &serde_json::Map::new())? };
        Ok(json!({"spawner": spawner, "actor": format!("0x{actor:X}"), "object": object.name(), "location": [location.0, location.1, location.2], "near_player": player, "npcs": unsafe { current_npcs(object)? }}))
    })
}

/// What a placed spawner has spawned so far, and its own gates, by the spawner actor's address.
fn spawned(args: &Value) -> Result<Value, String> {
    let actor = args["actor"].as_str().filter(|s| !s.is_empty()).ok_or("actor must be the spawner's address from npc.spawn")?.to_owned();
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        let spawner = ueforge::selector::resolve(&format!("addr:{actor}"))?;
        // SAFETY: game thread; a live spawner actor.
        let npcs = unsafe { current_npcs(spawner)? };
        let gates: Vec<String> = ["ManualSpawn", "OnlySpawnOnce", "HasSpawnedOnce", "AlwaysPassDistanceCheck", "ShouldSpawnSkipPlayerChecks", "Debug", "CanSpawnInLineOfSight", "SpawnWithEffect",
            "PlayersRequiredToSpawn", "NPCsAllowedFromSpawn", "NPC Level", "DirectorFailCounter", "PlayerWithinDistanceToSpawn", "SpawnCooldown_Default"].iter().map(|s| s.to_string()).collect();
        let gates = unsafe { ueforge::reflect::get_fields(spawner, &gates) }.unwrap_or_else(|e| json!(e));
        let rows = unsafe { ueforge::reflect::array_get(spawner, "NPCsToSpawn", None) }.map(|a| a["count"].clone()).unwrap_or(json!(0));
        Ok(json!({"spawner": spawner.name(), "count": npcs.len(), "npcs": npcs, "gates": gates, "npcs_to_spawn_entries": rows}))
    })
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new("npc.spawn", "Place one of the game's own NPC spawner Blueprints (loaded from the assets if needed) near a named player and make it spawn its NPC", "{spawner?: str, near_player: str, distance?: f64}", spawn),
        ueforge::ops::OpDef::new("npc.spawned", "What a placed spawner has spawned so far", "{actor: str}", spawned),
    ]);
}
