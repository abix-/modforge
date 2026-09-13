//! An AI controller that joins as a player: the engine's own kind of bot.
//!
//! Epic's Lyra (LyraBotCreationComponent::SpawnOneBot), OpenTournament and
//! ShooterGame all do it the same way: spawn the AI controller class with
//! bWantsPlayerState so it gets a PlayerState, then hand it to the game
//! mode's RestartPlayer, which spawns the ordinary player pawn class and
//! possesses it. Player features come from the pawn and the PlayerState;
//! NPC features from the AI controller. Abiotic_PlayerCharacter_C already
//! names Abiotic_AI_Controller_ParentBP_C as its AI controller class (FModel
//! export, 2026-09-13), so nothing new is built here: the game's classes,
//! the engine's spawn, the game mode's own player spawn.
use serde_json::{Value, json};
use std::time::Duration;
use ueforge::ue::UObject;

/// The NPCs' controller, which the player character class already names.
const CONTROLLER_CLASS: &str = "Abiotic_AI_Controller_ParentBP_C";

/// A reflected object pointer field. Game thread.
unsafe fn object_ptr(object: &UObject, name: &str) -> Result<u64, String> {
    let offset = ueforge::input::class_property_offset(object, name, 8)?;
    // SAFETY: an eight-byte reflected field on a live object.
    Ok(unsafe { (object.field_ptr(offset) as *const u64).read_unaligned() })
}

/// A reflected FString field. Game thread.
unsafe fn fstring(object: &UObject, name: &str) -> Result<String, String> {
    let offset = ueforge::input::class_property_offset(object, name, 16)?;
    // SAFETY: an FString header (data pointer, count, capacity) on a live object.
    let (data, count) = unsafe {
        let header = object.field_ptr(offset);
        ((header as *const *const u16).read_unaligned(), (header.add(8) as *const i32).read_unaligned())
    };
    if data.is_null() || count <= 1 { return Ok(String::new()); }
    if count > 256 { return Err(format!("{name}: oversized string ({count})")); }
    // SAFETY: count UTF-16 units including the terminator.
    let units = unsafe { std::slice::from_raw_parts(data, count as usize - 1) };
    Ok(String::from_utf16_lossy(units))
}

/// Name, class and location of a live actor, or null for a null pointer.
unsafe fn describe(actor: u64) -> Value {
    if actor == 0 { return Value::Null; }
    // SAFETY: a non-null actor pointer the engine just handed back.
    let object = unsafe { &*(actor as *const UObject) };
    let location = unsafe { ueforge::ue::transform::world_location(actor as *const u8) };
    json!({"addr": format!("0x{actor:X}"), "name": object.name(), "class": object.class().map(|c| c.as_object().name()).unwrap_or_default(), "location": location.map(|(x, y, z)| [x, y, z])})
}

/// Spawn the AI controller with a PlayerState near a named player and run
/// the game mode's RestartPlayer for it. Reports what the engine made.
fn join(args: &Value) -> Result<Value, String> {
    let player = args["near_player"].as_str().filter(|s| !s.is_empty()).ok_or("near_player must be a player name")?.to_owned();
    let distance = args["distance"].as_f64().unwrap_or(300.0);
    let class_name = args["controller_class"].as_str().filter(|s| !s.is_empty()).unwrap_or(CONTROLLER_CLASS).to_owned();
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(30), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (_, human) = unsafe { crate::nav::player_character(&player)? };
        let human_ptr = human as *const UObject as *const u8;
        let (x, y, z) = unsafe { ueforge::ue::transform::world_location(human_ptr) }.ok_or("player character has no location")?;
        let class = ueforge::ue::find_class_fast(&class_name).ok_or_else(|| format!("{class_name} is not loaded"))?;
        let location = (x + distance, y, z);
        // Deferred, so bWantsPlayerState is set before PostInitializeComponents,
        // where AAIController creates its PlayerState (AIController.cpp, UE 5.4).
        let actor = unsafe { ueforge::ue::spawn::begin_spawn(human_ptr, class as *const _ as u64, location, 180.0, 1.0) };
        if actor == 0 { return Err(format!("{class_name} did not begin spawning")); }
        // SAFETY: an actor the engine created and has not finished.
        let controller = unsafe { &*(actor as *const UObject) };
        let (bit_offset, mask) = ueforge::input::class_bool_property(controller, "bWantsPlayerState")?;
        // SAFETY: the byte the property describes on the live controller.
        let before = unsafe { (controller.field_ptr(bit_offset) as *const u8).read_unaligned() };
        unsafe { ueforge::input::write_class_bool(controller, "bWantsPlayerState", true)? };
        let after_write = unsafe { (controller.field_ptr(bit_offset) as *const u8).read_unaligned() };
        let finished = unsafe { ueforge::ue::spawn::finish_spawn(actor, location, 180.0, 1.0) };
        if finished == 0 { return Err(format!("{class_name} did not finish spawning")); }
        let after_finish = unsafe { (controller.field_ptr(bit_offset) as *const u8).read_unaligned() };
        let wants_player_state = json!({"offset": bit_offset, "mask": mask, "byte_before": before, "byte_after_write": after_write, "byte_after_finish": after_finish, "value_after_finish": after_finish & mask != 0});
        let player_state = unsafe { object_ptr(controller, "PlayerState")? };
        let player_state_name = if player_state == 0 { String::new() } else {
            // SAFETY: the PlayerState the controller just created.
            unsafe { fstring(&*(player_state as *const UObject), "PlayerNamePrivate")? }
        };
        // The game mode's own player spawn: default pawn class, player start, possession.
        let (parms, ret) = unsafe { crate::host::call_static("GameplayStatics", "GetGameMode", &[("WorldContextObject", &(human_ptr as u64).to_le_bytes())])? };
        let game_mode = u64::from_le_bytes(parms[ret..ret + 8].try_into().unwrap());
        if game_mode == 0 { return Err("GetGameMode returned null".into()); }
        // SAFETY: the live game mode.
        let game_mode_object = unsafe { &*(game_mode as *const UObject) };
        unsafe { crate::perception::call_named(game_mode_object, "GameModeBase", "RestartPlayer", &[("NewPlayer", &actor.to_le_bytes())])? };
        let pawn = unsafe { object_ptr(controller, "Pawn")? };
        Ok(json!({
            "controller": unsafe { describe(actor) },
            "player_state": if player_state == 0 { Value::Null } else { json!({"addr": format!("0x{player_state:X}"), "name": player_state_name}) },
            "pawn": unsafe { describe(pawn) },
            "wants_player_state": wants_player_state,
            "game_mode": game_mode_object.class().map(|c| c.as_object().name()).unwrap_or_default(),
            "near_player": player,
        }))
    })
}

/// The game's world start actors, which its own spawn flow teleports a new
/// player to (lan-spawn.md: Abiotic_WorldStart, Array_Random, TeleportPlayer).
const WORLD_START_CLASS: &str = "Abiotic_WorldStart_C";

/// A reflected bool's value. Game thread.
unsafe fn bool_field(object: &UObject, name: &str) -> Result<bool, String> {
    let (offset, mask) = ueforge::input::class_bool_property(object, name)?;
    // SAFETY: the byte the property describes on the live object.
    Ok(unsafe { std::ptr::read_volatile(object.field_ptr(offset)) } & mask != 0)
}

/// What the character's server-side possession handler left behind, read by name.
unsafe fn possession_state(pawn: &UObject) -> Value {
    let mut state = serde_json::Map::new();
    for name in ["MyPlayerState", "MyPlayerController"] {
        state.insert(name.into(), match unsafe { object_ptr(pawn, name) } { Ok(p) => unsafe { describe(p) }, Err(e) => json!(e) });
    }
    for name in ["IsDead", "IsDBNO", "IsDisabled", "ServerLevelLoaded", "OwningLevelLoaded", "HasRecentlyTeleported"] {
        state.insert(name.into(), match unsafe { bool_field(pawn, name) } { Ok(v) => json!(v), Err(e) => json!(e) });
    }
    Value::Object(state)
}

/// Place a bot's body at one of the game's world starts with the character's
/// own TeleportPlayer, the call the decoded player spawn flow makes.
fn place(args: &Value) -> Result<Value, String> {
    let controller = args["controller"].as_str().filter(|s| !s.is_empty()).ok_or("controller must be the address from ai_player.bot")?.to_owned();
    let index = args["world_start"].as_u64().unwrap_or(0) as usize;
    let force = args["force"].as_bool().unwrap_or(true);
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(30), crate::DRAIN_HINT, move || {
        let controller = ueforge::selector::resolve(&format!("addr:{controller}"))?;
        // SAFETY: game thread; the controller ai_player.bot returned.
        let pawn = unsafe { object_ptr(controller, "Pawn")? };
        if pawn == 0 { return Err("the controller has no pawn".into()); }
        let pawn_object = unsafe { &*(pawn as *const UObject) };
        let before = unsafe { possession_state(pawn_object) };
        let world = unsafe { &*(crate::nav::world_context()? as *const UObject) };
        let class = ueforge::ue::find_class_fast(WORLD_START_CLASS).ok_or_else(|| format!("{WORLD_START_CLASS} not found"))?;
        let starts = ueforge::ue::actor::actors_of_class(world, class)?;
        let start = *starts.get(index).ok_or_else(|| format!("world start {index} of {} does not exist", starts.len()))?;
        let (x, y, z) = unsafe { ueforge::ue::transform::world_location(start as *const u8) }.ok_or("world start has no location")?;
        let mut location = [0u8; 24];
        for (i, v) in [x, y, z].iter().enumerate() { location[i * 8..][..8].copy_from_slice(&v.to_le_bytes()); }
        let rotation = [0u8; 24];
        let (parms, ret) = unsafe { crate::perception::call_named(pawn_object, "Abiotic_PlayerCharacter_C", "TeleportPlayer",
            &[("DestLocation", &location), ("DestRotation", &rotation), ("Force", &[force as u8]), ("SkipAdjustment", &[0]), ("ExitChairs", &[0])])? };
        let teleported = parms.get(ret).copied().unwrap_or(0) != 0;
        Ok(json!({
            "pawn_before": unsafe { describe(pawn) },
            "possession_before": before,
            "world_starts": starts.len(),
            "world_start": unsafe { describe(start as u64) },
            "teleported": teleported,
            "pawn_after": unsafe { describe(pawn) },
            "possession_after": unsafe { possession_state(pawn_object) },
        }))
    })
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new("ai_player.bot", "Spawn the NPCs' AI controller with a PlayerState near a named player and run the game mode's RestartPlayer for it, the way Lyra spawns a bot", "{near_player: str, distance?: f64, controller_class?: str}", join),
        ueforge::ops::OpDef::new("ai_player.bot_place", "Read the bot pawn's possession state and teleport it to one of the game's world starts with the character's own TeleportPlayer", "{controller: str, world_start?: u64, force?: bool}", place),
    ]);
}
