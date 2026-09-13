//! Bring a real NPC into the world the way the game does: through one of
//! its own NPC spawner Blueprints (Abiotic_NPCSpawn_ParentBP_C children
//! such as NPCSpawn_QuillExor). The spawner class is loaded from the game
//! assets when it is not in memory, placed near a named player with the
//! engine's actor spawn, and told to spawn with its own DebugSpawn. The
//! NPC then arrives with everything the game gives it. A plain actor spawn
//! of NPC_Monster_Exor killed the game within two seconds (2026-09-13,
//! twice); spawners are the supported path.
use serde_json::{Value, json};
use std::time::Duration;
use ueforge::ue::UObject;

/// Where the game keeps its spawner Blueprints (asset registry, 2026-09-13).
const SPAWNER_PACKAGE_DIR: &str = "/Game/Blueprints/Environment/Spawns";
const SPAWNER_PARENT: &str = "Abiotic_NPCSpawn_ParentBP_C";

/// The loaded class for a Blueprint name, loading `<dir>/<name>` if needed. Game thread.
fn blueprint_class(dir: &str, name: &str) -> Result<&'static ueforge::ue::UClass, String> {
    let class_name = format!("{name}_C");
    if let Some(class) = ueforge::ue::find_class_fast(&class_name) { return Ok(class); }
    let package = ueforge::ue::fname::from_str(&format!("{dir}/{name}"), ueforge::ue::fname::FindName::Add).ok_or("package FName unavailable")?;
    let asset = ueforge::ue::fname::from_str(&class_name, ueforge::ue::fname::FindName::Add).ok_or("class FName unavailable")?;
    let address = ueforge::assets::load_asset(package.as_u64(), asset.as_u64())?;
    if address == 0 { return Err(format!("{dir}/{name}.{class_name} did not load")); }
    ueforge::ue::find_class_fast(&class_name).ok_or_else(|| format!("{class_name} loaded at 0x{address:X} but is not findable as a class"))
}

/// Read a reflected TArray of object pointers. Game thread.
unsafe fn object_array(object: &UObject, name: &str) -> Result<Vec<u64>, String> {
    let offset = ueforge::input::class_property_offset(object, name, 16)?;
    // SAFETY: a TArray header is data pointer, count, capacity on the live object.
    let (data, count) = unsafe {
        let header = object.field_ptr(offset);
        ((header as *const u64).read_unaligned(), (header.add(8) as *const i32).read_unaligned())
    };
    if data == 0 || count <= 0 { return Ok(Vec::new()); }
    // SAFETY: count pointers follow the data pointer.
    Ok((0..count as usize).map(|i| unsafe { ((data as *const u64).add(i)).read_unaligned() }).collect())
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
        let class = blueprint_class(SPAWNER_PACKAGE_DIR, &spawner)?;
        let location = (x + distance, y, z);
        // SAFETY: the player's live character is the world context; the class is loaded.
        let actor = unsafe { ueforge::ue::spawn::spawn_actor(character as *const UObject as *const u8, class as *const _ as u64, location, 180.0, 1.0) };
        if actor == 0 { return Err(format!("{spawner} did not spawn")); }
        // SAFETY: a live actor the engine just finished spawning.
        let object = unsafe { &*(actor as *const UObject) };
        unsafe { crate::perception::call_named(object, SPAWNER_PARENT, "DebugSpawn", &[])? };
        let npcs: Vec<String> = unsafe { object_array(object, "CurrentNPCs")? }.into_iter().filter(|p| *p != 0)
            // SAFETY: live NPC actors the spawner tracks.
            .map(|p| unsafe { &*(p as *const UObject) }.name()).collect();
        Ok(json!({"spawner": spawner, "actor": format!("0x{actor:X}"), "object": object.name(), "location": [location.0, location.1, location.2], "near_player": player, "npcs": npcs}))
    })
}

/// What a placed spawner has spawned so far, by the spawner actor's address.
fn spawned(args: &Value) -> Result<Value, String> {
    let actor = args["actor"].as_str().filter(|s| !s.is_empty()).ok_or("actor must be the spawner's address from npc.spawn")?.to_owned();
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        let spawner = ueforge::selector::resolve(&format!("addr:{actor}"))?;
        let name = spawner.name();
        // SAFETY: game thread; a live spawner actor.
        let npcs: Vec<Value> = unsafe { object_array(spawner, "CurrentNPCs")? }.into_iter().filter(|p| *p != 0).map(|p| {
            let npc = unsafe { &*(p as *const UObject) };
            let location = unsafe { ueforge::ue::transform::world_location(p as *const u8) };
            json!({"name": npc.name(), "class": npc.class().map(|c| c.as_object().name()).unwrap_or_default(), "location": location.map(|(x, y, z)| [x, y, z])})
        }).collect();
        Ok(json!({"spawner": name, "count": npcs.len(), "npcs": npcs}))
    })
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new("npc.spawn", "Place one of the game's own NPC spawner Blueprints (loaded from the assets if needed) near a named player and make it spawn its NPC", "{spawner?: str, near_player: str, distance?: f64}", spawn),
        ueforge::ops::OpDef::new("npc.spawned", "What a placed spawner has spawned so far", "{actor: str}", spawned),
    ]);
}
