//! The AI player's eyes and ears: the same AIPerceptionComponent the enemies
//! carry, added to her character with sense configs copied from a live
//! enemy, all through ueforge's generic tools (component.add with fields set
//! before registration, object copy, calls by name). Perceived actors come
//! from GetCurrentlyPerceivedActors; nothing here scans the world.
use serde_json::{Value, json};
use std::time::Duration;
use ueforge::ue::UObject;

fn addr(value: &Value) -> u64 {
    value["addr"].as_str().and_then(|a| u64::from_str_radix(a.trim_start_matches("0x"), 16).ok()).unwrap_or(0)
}

/// A live enemy perception component and every sense config on it: the
/// source of her senses. The Exor soldier is the model (operator choice
/// 2026-09-13); when no Exor is loaded, the narrative human (the monsters'
/// own configs crashed the game when cloned three times). Game thread.
unsafe fn enemy_senses(source: &str) -> Result<(String, Vec<u64>), String> {
    let world = unsafe { &*(crate::nav::world_context()? as *const UObject) };
    let character = ueforge::ue::find_class_fast("Character").ok_or("Character class not found")?;
    let mut best: Option<(String, Vec<u64>)> = None;
    for actor in ueforge::ue::actor::actors_of_class(world, character)? {
        // SAFETY: each pointer came from GetAllActorsOfClass for the live world.
        let Some(actor) = (unsafe { actor.as_ref() }) else { continue };
        let class = actor.class().map(|c| c.as_object().name()).unwrap_or_default();
        if !class.starts_with("NPC_") && !class.starts_with("NarrativeNPC_") { continue; }
        if !source.is_empty() && !class.contains(source) { continue; }
        let component = addr(&unsafe { ueforge::reflect::get_fields(actor, &["AIPerception".into()]) }.map(|f| f["AIPerception"].clone()).unwrap_or(Value::Null));
        if component == 0 { continue; }
        // SAFETY: the live component.
        let configs: Vec<u64> = unsafe { ueforge::reflect::array_get(&*(component as *const UObject), "SensesConfig", None)? }["elements"].as_array().into_iter().flatten().map(addr).filter(|a| *a != 0).collect();
        if configs.is_empty() { continue; }
        let full = unsafe { &*(component as *const UObject) }.full_name();
        if class.contains("Exor") { return Ok((full, configs)); }
        let preferred = class.starts_with("NarrativeNPC_Human");
        if best.as_ref().is_none_or(|(name, _)| preferred && !name.contains("NarrativeNPC_Human")) { best = Some((full, configs)); }
    }
    best.ok_or("no live NPC with a perception component and sense configs".into())
}

/// Actors already registered as sight sources, so each is registered once.
static SOURCES: parking_lot::Mutex<std::collections::BTreeSet<u64>> = parking_lot::Mutex::new(std::collections::BTreeSet::new());

/// Make every loaded NPC visible to sight: the game registers furniture,
/// containers and players as stimuli sources but never its monsters
/// (2026-09-13). The engine's own RegisterPerceptionStimuliSource, once per
/// actor. Game thread. Returns how many were newly registered.
unsafe fn register_npc_sources() -> Result<usize, String> {
    let world = crate::nav::world_context()?;
    let world_object = unsafe { &*(world as *const UObject) };
    let character = ueforge::ue::find_class_fast("Character").ok_or("Character class not found")?;
    let system = ueforge::selector::resolve("singleton:AIPerceptionSystem")?;
    let mut registered = SOURCES.lock();
    let mut new = 0;
    for actor in ueforge::ue::actor::actors_of_class(world_object, character)? {
        let address = actor as u64;
        // SAFETY: each pointer came from GetAllActorsOfClass for the live world.
        let Some(object) = (unsafe { actor.as_ref() }) else { continue };
        if !object.class().map(|c| c.as_object().name()).unwrap_or_default().starts_with("NPC_") || registered.contains(&address) { continue; }
        let reply = unsafe { ueforge::reflect::call(system, "AIPerceptionSystem", "RegisterPerceptionStimuliSource",
            json!({"WorldContextObject": format!("0x{world:X}"), "Sense": "class:AISense_Sight", "Target": format!("0x{address:X}")}).as_object().unwrap())? };
        if reply["ReturnValue"] == true { registered.insert(address); new += 1; }
    }
    Ok(new)
}

fn sources(_: &Value) -> Result<Value, String> {
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, || {
        // SAFETY: game thread.
        let new = unsafe { register_npc_sources()? };
        Ok(json!({"newly_registered": new, "registered": SOURCES.lock().len()}))
    })
}

/// Her perception component, created once on her character.
static COMPONENT: parking_lot::Mutex<Option<u64>> = parking_lot::Mutex::new(None);

unsafe fn component_of(player: &str) -> Result<&'static UObject, String> {
    let address = COMPONENT.lock().ok_or_else(|| format!("{player} has no perception component; run ai_player.perceive first"))?;
    if !modforge::winproc::is_addr_readable(address as usize) { return Err("perception component is gone".into()); }
    // SAFETY: created by `add` and still readable.
    Ok(unsafe { &*(address as *const UObject) })
}

/// Put the enemies' perception component on the named player's character
/// with an enemy's sense configs: her own copies of the configs (spawned,
/// then every shared field copied), a hearing config from the class
/// defaults with the Peccary's numbers, and the component added with
/// SensesConfig set before it registers, because registration builds the
/// listener's sense filter from the configs present then (2026-09-13).
fn add(args: &Value) -> Result<Value, String> {
    let player = args["player"].as_str().filter(|s| !s.is_empty()).unwrap_or("Sophia").to_owned();
    let only: Vec<String> = args["senses"].as_array().into_iter().flatten().filter_map(|v| v.as_str().map(str::to_owned)).collect();
    let source = args["source"].as_str().unwrap_or("").to_owned();
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        if let Some(existing) = *COMPONENT.lock() {
            if modforge::winproc::is_addr_readable(existing as usize) {
                return Ok(json!({"player": player, "component": format!("0x{existing:X}"), "state": "already_added"}));
            }
        }
        // SAFETY: game thread.
        let (_, character) = unsafe { crate::nav::player_character(&player)? };
        let character_addr = character as *const UObject as u64;
        let (source, configs) = unsafe { enemy_senses(&source)? };
        let mut senses = Vec::new();
        let mut copies = Vec::new();
        for config in &configs {
            // SAFETY: a live sense config object from the enemy's component.
            let original = unsafe { &*(*config as *const UObject) };
            let class = original.class().ok_or("sense config has no class")?.as_object().name();
            if !only.is_empty() && !only.iter().any(|s| *s == class) { continue; }
            let copy = unsafe { ueforge::reflect::spawn_object(&class, character_addr)? };
            // SAFETY: the copy the engine just created, of the same class.
            let copied = unsafe { ueforge::reflect::copy_fields(original, &*(copy as *const UObject))? };
            ueforge::log!("perception: copied {copied} reflected fields of {class} from the enemy's config");
            senses.push(class);
            copies.push(copy);
        }
        // Hearing: only the monsters carry a hearing config and cloning theirs
        // crashed the game (2026-09-13), so hers is built from the engine class's
        // defaults with the Peccary's numbers (npc-ai.md) and full affiliation.
        if !senses.iter().any(|s| s == "AISenseConfig_Hearing") && (only.is_empty() || only.iter().any(|s| s == "AISenseConfig_Hearing")) {
            let hearing = unsafe { ueforge::reflect::spawn_object("AISenseConfig_Hearing", character_addr)? };
            // SAFETY: a fresh config object of a known class.
            unsafe { ueforge::reflect::set_fields(&*(hearing as *const UObject), json!({
                "Implementation": "class:AISense_Hearing", "HearingRange": 750.0, "LoSHearingRange": 0.0, "MaxAge": 1.0,
                "DetectionByAffiliation": {"bDetectEnemies": true, "bDetectNeutrals": true, "bDetectFriendlies": true}
            }).as_object().unwrap())? };
            senses.push("AISenseConfig_Hearing (defaults)".into());
            copies.push(hearing);
        }
        let fields = json!({"SensesConfig": copies.iter().map(|c| format!("0x{c:X}")).collect::<Vec<_>>()});
        let component = unsafe { ueforge::spawn_ops::add_component(character, "AIPerceptionComponent", fields.as_object().unwrap())? };
        *COMPONENT.lock() = Some(component);
        Ok(json!({"player": player, "component": format!("0x{component:X}"), "senses": senses, "senses_from": source, "state": "added"}))
    })
}

/// One perceived actor: address, class, name, location.
#[derive(Clone, Debug, serde::Serialize, serde::Deserialize)]
pub struct Perceived {
    pub addr: String,
    pub class: String,
    pub name: String,
    pub location: Option<[f64; 3]>,
}

/// What the perception component currently perceives: the engine's own
/// list, one game-thread job.
pub(crate) fn perceived_rows(player: &str) -> Result<Vec<Perceived>, String> {
    let player = player.to_owned();
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread. Newly loaded monsters become visible first.
        if let Err(error) = unsafe { register_npc_sources() } { ueforge::log!("perception: registering NPC sight sources: {error}"); }
        let component = unsafe { component_of(&player)? };
        let reply = unsafe { ueforge::reflect::call(component, "AIPerceptionComponent", "GetCurrentlyPerceivedActors", json!({"SenseToUse": null}).as_object().unwrap())? };
        let mut rows = Vec::new();
        for actor in reply["OutActors"].as_array().into_iter().flatten() {
            let address = addr(actor);
            if address == 0 { continue; }
            let location = unsafe { ueforge::ue::transform::world_location(address as *const u8) };
            rows.push(Perceived { addr: format!("0x{address:X}"), class: actor["class"].as_str().unwrap_or("").to_owned(), name: actor["name"].as_str().unwrap_or("").to_owned(), location: location.map(|(x, y, z)| [x, y, z]) });
        }
        Ok(json!(rows))
    }).and_then(|v| serde_json::from_value(v).map_err(|e| e.to_string()))
}

fn perceived(args: &Value) -> Result<Value, String> {
    let player = args["player"].as_str().filter(|s| !s.is_empty()).unwrap_or("Sophia");
    let rows = perceived_rows(player)?;
    Ok(json!({"player": player, "count": rows.len(), "perceived": rows}))
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new("ai_player.perceive", "Add the enemies' AIPerceptionComponent with an enemy's sense configs to the player's character", "{player?: str, senses?: [str], source?: str}", add),
        ueforge::ops::OpDef::new("ai_player.perceived", "Actors the player's perception component currently perceives", "{player?: str}", perceived),
        ueforge::ops::OpDef::new("ai_player.sources", "Register every loaded NPC as a sight stimuli source (the game only registers furniture, containers and players)", "{}", sources),
    ]);
}
