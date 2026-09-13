//! Sophia's eyes and ears: the same AIPerceptionComponent the enemies carry,
//! added to her server-side controller through the engine's own calls
//! (Actor::AddComponentByClass, AIPerceptionComponent::ConfigureSense) with
//! sense configs borrowed from a live enemy component. Perceived actors come
//! from GetCurrentlyPerceivedActors; nothing here scans the world.
use serde_json::{Value, json};
use std::time::Duration;
use ueforge::ue::UObject;

/// Call `class::function` on `target`, filling parameters by name from the
/// reflected layout, the way host::call_static does for static functions.
/// Game thread. Returns the parameter block and the ReturnValue offset.
pub(crate) unsafe fn call_named(target: &UObject, class: &str, function: &str, set: &[(&str, &[u8])]) -> Result<(Vec<u8>, usize), String> {
    let uclass = ueforge::ue::find_class_fast(class).ok_or_else(|| format!("class '{class}' not found"))?;
    let func = uclass.get_function(class, function).ok_or_else(|| format!("function '{class}::{function}' not found"))?;
    let params = func.iter_parameters();
    let mut parms = vec![0u8; func.parms_size().max(1) as usize];
    for (name, bytes) in set {
        let param = params.iter().find(|p| p.name == *name).ok_or_else(|| format!("{class}::{function} has no parameter {name}"))?;
        if param.element_size as usize != bytes.len() {
            return Err(format!("{class}::{function} parameter {name} is {} bytes, not {}", param.element_size, bytes.len()));
        }
        parms[param.offset as usize..][..bytes.len()].copy_from_slice(bytes);
    }
    let ret = params.iter().find(|p| p.name == "ReturnValue").map_or(0, |p| p.offset as usize);
    // SAFETY: game thread; the block is sized from the function's own ParmsSize and filled by reflected offsets.
    unsafe { target.process_event(func, parms.as_mut_ptr().cast()) };
    Ok((parms, ret))
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

/// A live enemy perception component and every sense config on it: the
/// source of Sophia's senses. The Exor soldier is the model (operator choice
/// 2026-09-13); when no Exor is loaded, the live enemy carrying the most
/// senses, so sight and hearing both come along.
unsafe fn enemy_senses(source: &str) -> Result<(String, Vec<u64>), String> {
    // Live world actors only, from the engine's own list: a walk over every
    // object in memory also returns components of dead NPCs awaiting garbage
    // collection, and copying their configs crashed the game (2026-09-13).
    let world = unsafe { &*(crate::nav::world_context()? as *const UObject) };
    let character = ueforge::ue::find_class_fast("Character").ok_or("Character class not found")?;
    let actors = ueforge::ue::actor::actors_of_class(world, character)?;
    let mut best: Option<(String, Vec<u64>)> = None;
    for actor in actors {
        // SAFETY: each pointer came from GetAllActorsOfClass for the live world.
        let Some(actor) = (unsafe { actor.as_ref() }) else { continue };
        let class = actor.class().map(|c| c.as_object().name()).unwrap_or_default();
        if !class.starts_with("NPC_") && !class.starts_with("NarrativeNPC_") { continue; }
        if !source.is_empty() && !class.contains(source) { continue; }
        let Ok(offset) = ueforge::input::class_property_offset(actor, "AIPerception", 8) else { continue };
        // SAFETY: the reflected component pointer on a live actor.
        let component = unsafe { (actor.field_ptr(offset) as *const u64).read_unaligned() };
        if component == 0 { continue; }
        let component = unsafe { &*(component as *const UObject) };
        let configs = unsafe { object_array(component, "SensesConfig")? };
        if configs.is_empty() { continue; }
        let full = component.full_name();
        if class.contains("Exor") { return Ok((full, configs)); }
        // Cloning the monsters' configs (Pest, Peccary) crashed the game three
        // times on 2026-09-13 and the narrative human's did not; until that is
        // understood the human is the default source, the Exor when alive.
        let preferred = class.starts_with("NarrativeNPC_Human");
        if best.as_ref().is_none_or(|(name, _)| preferred && !name.contains("NarrativeNPC_Human")) { best = Some((full, configs)); }
    }
    best.ok_or("no live NPC with a perception component and sense configs".into())
}

/// Sophia's perception component, created once on her server-side controller.
static COMPONENT: parking_lot::Mutex<Option<u64>> = parking_lot::Mutex::new(None);

unsafe fn component_of(player: &str) -> Result<&'static UObject, String> {
    let address = COMPONENT.lock().ok_or_else(|| format!("{player} has no perception component; run ai_player.perceive first"))?;
    if !modforge::winproc::is_addr_readable(address as usize) { return Err("perception component is gone".into()); }
    // SAFETY: created by `add` and still readable.
    Ok(unsafe { &*(address as *const UObject) })
}

/// Put the enemies' perception component on the named player's server-side
/// controller and give it an enemy's sense configs.
fn add(args: &Value) -> Result<Value, String> {
    let player = args["player"].as_str().filter(|s| !s.is_empty()).unwrap_or("Sophia").to_owned();
    // Optional: only these sense config classes (isolation runs); default all of them.
    let only: Vec<String> = args["senses"].as_array().into_iter().flatten().filter_map(|v| v.as_str().map(str::to_owned)).collect();
    // Isolation knobs: which enemy's component to copy from (substring of its full name), and
    // whether to share its config objects instead of cloning them (the path that worked 2026-09-13).
    let source = args["source"].as_str().unwrap_or("").to_owned();
    let share = args["share"].as_bool().unwrap_or(false);
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        if let Some(existing) = *COMPONENT.lock() {
            if modforge::winproc::is_addr_readable(existing as usize) {
                return Ok(json!({"player": player, "component": format!("0x{existing:X}"), "state": "already_added"}));
            }
        }
        // SAFETY: game thread.
        let (_, character) = unsafe { crate::nav::player_character(&player)? };
        let (source, configs) = unsafe { enemy_senses(&source)? };
        let class = ueforge::ue::find_class_fast("AIPerceptionComponent").ok_or("AIPerceptionComponent class not found")?;
        let class_bytes = (class as *const _ as u64).to_le_bytes();
        // On her character, where the enemies carry theirs. Deferred finish:
        // the component registers only after its sense configs are in place,
        // because registration builds the listener's sense filter from the
        // configs present at that moment; configs added later are ignored and
        // the listener perceives nothing (observed 2026-09-13).
        let (parms, ret) = unsafe { call_named(character, "Actor", "AddComponentByClass", &[("Class", &class_bytes), ("bManualAttachment", &[0]), ("bDeferredFinish", &[1])])? };
        let component = u64::from_le_bytes(parms[ret..ret + 8].try_into().unwrap());
        if component == 0 { return Err("AddComponentByClass returned null".into()); }
        // Remember it before configuring, so a failed configure step does not add a second one.
        *COMPONENT.lock() = Some(component);
        // SAFETY: a component the engine just created, not yet registered.
        let component_object = unsafe { &*(component as *const UObject) };
        // Her own copies of the enemy's configs: the engine creates each one
        // (GameplayStatics::SpawnObject, owned by her component), then the
        // enemy's values are copied over. Sharing the enemy's objects is not
        // something the engine ever does, and the one run that did so crashed.
        let offset = ueforge::input::class_property_offset(component_object, "SensesConfig", 16)?;
        let mut senses = Vec::new();
        let mut copies = Vec::new();
        for config in &configs {
            // SAFETY: a live sense config object from the enemy's component.
            let source = unsafe { &*(*config as *const UObject) };
            let class = source.class().ok_or("sense config has no class")?;
            if !only.is_empty() && !only.iter().any(|s| *s == class.as_object().name()) { continue; }
            if share {
                senses.push(class.as_object().name());
                copies.push(*config);
                continue;
            }
            let outer = (component as u64).to_le_bytes();
            let class_bytes = (class as *const _ as u64).to_le_bytes();
            let (parms, ret) = unsafe { crate::host::call_static("GameplayStatics", "SpawnObject", &[("ObjectClass", &class_bytes), ("Outer", &outer)])? };
            let copy = u64::from_le_bytes(parms[ret..ret + 8].try_into().unwrap());
            if copy == 0 { return Err(format!("SpawnObject returned null for {}", class.as_object().name())); }
            // Same class, so the same layout: copy each reflected property's bytes,
            // walking the class chain. Never a whole-object copy; the class size
            // accessor returned garbage for Blueprint classes today.
            let mut current = Some(class);
            let mut copied = 0usize;
            while let Some(c) = current {
                for property in c.cached_native_properties().iter() {
                    let (offset, size) = (property.offset as usize, property.element_size as usize);
                    if offset < ueforge::ue::offsets::uobject::SIZE || size == 0 || size > 4096 { continue; }
                    // SAFETY: a reflected field of both live objects of this class.
                    unsafe { std::ptr::copy_nonoverlapping((*config as *const u8).add(offset), (copy as *mut u8).add(offset), size) };
                    copied += 1;
                }
                current = c.super_class();
            }
            ueforge::log!("perception: copied {copied} reflected fields of {} from the enemy's config", class.as_object().name());
            senses.push(class.as_object().name());
            copies.push(copy);
        }
        unsafe {
            let header = component_object.field_ptr(offset);
            ueforge::ue::tarray::grow_raw(header, 8, copies.len() as i32)?;
            let data = (header as *const *mut u64).read_unaligned();
            for (index, copy) in copies.iter().enumerate() { data.add(index).write_unaligned(*copy); }
            ((header as usize + 8) as *mut i32).write_unaligned(copies.len() as i32);
        }
        // Now register: the engine's FinishAddComponent runs OnRegister, which
        // builds the sense filter from SensesConfig and registers the listener.
        let component_bytes = component.to_le_bytes();
        unsafe { call_named(character, "Actor", "FinishAddComponent", &[("Component", &component_bytes), ("bManualAttachment", &[0])])? };
        Ok(json!({"player": player, "component": format!("0x{component:X}"), "senses": senses, "senses_from": source, "state": "added"}))
    })
}

/// What the perception component currently perceives: the engine's own list.
fn perceived(args: &Value) -> Result<Value, String> {
    let player = args["player"].as_str().filter(|s| !s.is_empty()).unwrap_or("Sophia").to_owned();
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let component = unsafe { component_of(&player)? };
        let (parms, _) = unsafe { call_named(component, "AIPerceptionComponent", "GetCurrentlyPerceivedActors", &[("SenseToUse", &0u64.to_le_bytes())])? };
        let function = ueforge::ue::find_class_fast("AIPerceptionComponent").and_then(|c| c.get_function("AIPerceptionComponent", "GetCurrentlyPerceivedActors")).ok_or("GetCurrentlyPerceivedActors")?;
        let out = function.iter_parameters().into_iter().find(|p| p.name == "OutActors").ok_or("OutActors parameter")?.offset as usize;
        let data = u64::from_le_bytes(parms[out..out + 8].try_into().unwrap());
        let count = i32::from_le_bytes(parms[out + 8..out + 12].try_into().unwrap());
        let mut rows = Vec::new();
        for index in 0..count.max(0) as usize {
            // SAFETY: the engine filled OutActors with count actor pointers.
            let actor = unsafe { ((data as *const u64).add(index)).read_unaligned() };
            if actor == 0 { continue; }
            let object = unsafe { &*(actor as *const UObject) };
            let location = unsafe { ueforge::ue::transform::world_location(actor as *const u8) };
            rows.push(json!({"class": object.class().map(|c| c.as_object().name()).unwrap_or_default(), "name": object.name(), "location": location.map(|(x, y, z)| [x, y, z])}));
        }
        Ok(json!({"player": player, "count": rows.len(), "perceived": rows}))
    })
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new("ai_player.perceive", "Add the enemies' AIPerceptionComponent with an enemy's sense configs to the player's server-side controller", "{player?: str}", add),
        ueforge::ops::OpDef::new("ai_player.perceived", "Actors the player's perception component currently perceives", "{player?: str}", perceived),
    ]);
}
