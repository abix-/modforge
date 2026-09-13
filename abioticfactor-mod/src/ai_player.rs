//! Sophia, the AI player: the NPCs' AI controller joined as a player, on the
//! host, with no network client.
//!
//! Epic's Lyra (LyraBotCreationComponent::SpawnOneBot), OpenTournament and
//! ShooterGame all make a bot the same way: spawn the AI controller class
//! with bWantsPlayerState so it gets a PlayerState, then hand it to the game
//! mode's RestartPlayer, which spawns the ordinary player pawn class and
//! possesses it. Player features come from the pawn and the PlayerState; NPC
//! features from the AI controller. Abiotic_PlayerCharacter_C already names
//! Abiotic_AI_Controller_ParentBP_C as its AI controller class (npc-ai.md),
//! so nothing new is built: the game's classes, the engine's spawn, the game
//! mode's own player spawn, the AI controller's own path following.
//!
//! Identity and memory come from her profile (profile.rs). Her name goes on
//! the PlayerState, so every lookup by player name (nav.rs) finds her the
//! way it finds the human.
use parking_lot::Mutex;
use serde_json::{Value, json};
use std::{sync::Arc, time::Duration};
use ueforge::ue::UObject;

/// The NPCs' controller, which the player character class already names.
const CONTROLLER_CLASS: &str = "Abiotic_AI_Controller_ParentBP_C";
/// The game's world start actors, which its own spawn flow teleports a new
/// player to (lan-spawn.md: Abiotic_WorldStart, Array_Random, TeleportPlayer).
const WORLD_START_CLASS: &str = "Abiotic_WorldStart_C";
const FOLLOW_DISTANCE: f64 = 300.0;
const FOLLOW_PERIOD: Duration = Duration::from_secs(2);

struct Session {
    name: String,
    /// Her profile: identity, journal and what she has seen live here.
    directory: std::path::PathBuf,
    controller: u64,
    /// True while a loop (follow or explore) owns her walking.
    following: Arc<std::sync::atomic::AtomicBool>,
}

static SESSION: Mutex<Option<Session>> = Mutex::new(None);

/// What a walking loop needs: her name, profile directory, and the flag that
/// says the loop still owns her walking.
pub(crate) struct Walker {
    pub name: String,
    pub directory: std::path::PathBuf,
    pub owns: Arc<std::sync::atomic::AtomicBool>,
}

impl Walker {
    /// Still the owner, and she is still in the world.
    pub fn alive(&self) -> bool {
        self.owns.load(std::sync::atomic::Ordering::Relaxed)
            && SESSION.lock().as_ref().is_some_and(|s| s.name == self.name && modforge::winproc::is_addr_readable(s.controller as usize))
    }
}

/// Hand her walking to a new loop: the previous loop's flag goes false, so
/// follow and explore never fight over her. One owner at a time.
pub(crate) fn take_walking() -> Result<Walker, String> {
    let mut session = SESSION.lock();
    let Some(session) = session.as_mut() else { return Err("Sophia has not joined; run ai_player.start".into()); };
    session.following.store(false, std::sync::atomic::Ordering::Relaxed);
    let owns = Arc::new(std::sync::atomic::AtomicBool::new(true));
    session.following = owns.clone();
    Ok(Walker { name: session.name.clone(), directory: session.directory.clone(), owns })
}

/// Her profile directory, for reading memory without touching her walking.
pub(crate) fn session_directory() -> Result<std::path::PathBuf, String> {
    SESSION.lock().as_ref().map(|s| s.directory.clone()).ok_or("Sophia has not joined; run ai_player.start".into())
}

/// Stop whichever loop owns her walking and stand still.
pub(crate) fn release_walking() -> Result<(), String> {
    {
        let session = SESSION.lock();
        let Some(session) = session.as_ref() else { return Err("Sophia has not joined; run ai_player.start".into()); };
        session.following.store(false, std::sync::atomic::Ordering::Relaxed);
    }
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, || {
        // SAFETY: game thread.
        let (controller, _) = unsafe { session_controller()? };
        unsafe { crate::perception::call_named(controller, "Controller", "StopMovement", &[])? };
        Ok(json!({}))
    }).map(|_| ())
}

/// A reflected object pointer field. Game thread.
unsafe fn object_ptr(object: &UObject, name: &str) -> Result<u64, String> {
    let offset = ueforge::input::class_property_offset(object, name, 8)?;
    // SAFETY: an eight-byte reflected field on a live object.
    Ok(unsafe { (object.field_ptr(offset) as *const u64).read_unaligned() })
}

/// Name, class and location of a live actor, or null for a null pointer.
unsafe fn describe(actor: u64) -> Value {
    if actor == 0 { return Value::Null; }
    // SAFETY: a non-null actor pointer the engine handed back.
    let object = unsafe { &*(actor as *const UObject) };
    let location = unsafe { ueforge::ue::transform::world_location(actor as *const u8) };
    json!({"addr": format!("0x{actor:X}"), "name": object.name(), "class": object.class().map(|c| c.as_object().name()).unwrap_or_default(), "location": location.map(|(x, y, z)| [x, y, z])})
}

/// Her controller and pawn from the session. Game thread.
unsafe fn session_controller() -> Result<(&'static UObject, u64), String> {
    let address = SESSION.lock().as_ref().map(|s| s.controller).ok_or("Sophia has not joined; run ai_player.start")?;
    if !modforge::winproc::is_addr_readable(address as usize) { return Err("Sophia's controller is gone".into()); }
    // SAFETY: the controller start() spawned, still readable.
    let controller = unsafe { &*(address as *const UObject) };
    let pawn = unsafe { object_ptr(controller, "Pawn")? };
    Ok((controller, pawn))
}

fn vector_bytes(v: [f64; 3]) -> [u8; 24] {
    let mut bytes = [0u8; 24];
    for (i, value) in v.iter().enumerate() { bytes[i * 8..][..8].copy_from_slice(&value.to_le_bytes()); }
    bytes
}

/// The location of one of the game's world starts. Game thread.
unsafe fn world_start(index: usize) -> Result<(u64, [f64; 3]), String> {
    let world = unsafe { &*(crate::nav::world_context()? as *const UObject) };
    let class = ueforge::ue::find_class_fast(WORLD_START_CLASS).ok_or_else(|| format!("{WORLD_START_CLASS} not found"))?;
    let starts = ueforge::ue::actor::actors_of_class(world, class)?;
    let start = *starts.get(index).ok_or_else(|| format!("world start {index} of {} does not exist", starts.len()))?;
    let (x, y, z) = unsafe { ueforge::ue::transform::world_location(start as *const u8) }.ok_or("world start has no location")?;
    Ok((start as u64, [x, y, z]))
}

/// The character's own TeleportPlayer, the call the decoded player spawn
/// flow makes to place a body. Game thread. Returns the engine's result.
unsafe fn teleport(pawn: &UObject, location: [f64; 3]) -> Result<bool, String> {
    let (parms, ret) = unsafe { crate::perception::call_named(pawn, "Abiotic_PlayerCharacter_C", "TeleportPlayer",
        &[("DestLocation", &vector_bytes(location)), ("DestRotation", &[0u8; 24]), ("Force", &[1]), ("SkipAdjustment", &[0]), ("ExitChairs", &[0])])? };
    Ok(parms.get(ret).copied().unwrap_or(0) != 0)
}

/// Join: spawn her AI controller with a PlayerState carrying her name, let
/// the game mode spawn and possess her player character, and place her at
/// the game's first world start. Idempotent while she is in the world.
fn start(args: &Value) -> Result<Value, String> {
    if let Some(session) = SESSION.lock().as_ref() {
        if modforge::winproc::is_addr_readable(session.controller as usize) {
            return Ok(json!({"name": session.name, "controller": format!("0x{:X}", session.controller), "state": "already_joined"}));
        }
    }
    let directory = match args["profile_dir"].as_str().filter(|s| !s.is_empty()) { Some(dir) => std::path::PathBuf::from(dir), None => crate::profile::directory().map_err(|e| e.to_string())? };
    let profile = crate::profile::Profile::load_or_create(&directory).map_err(|e| e.to_string())?;
    let name = profile.name.clone();
    let near_player = args["near_player"].as_str().filter(|s| !s.is_empty()).map(str::to_owned);
    let name_for_job = name.clone();
    let reply = ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(30), crate::DRAIN_HINT, move || {
        let name = name_for_job;
        // SAFETY: game thread.
        let human = match near_player {
            Some(player) => player,
            None => unsafe { crate::nav::players()? }.into_iter().map(|(player, _)| player).find(|player| *player != name).ok_or("no human player in the game")?,
        };
        let (_, human_character) = unsafe { crate::nav::player_character(&human)? };
        let human_ptr = human_character as *const UObject as *const u8;
        let (x, y, z) = unsafe { ueforge::ue::transform::world_location(human_ptr) }.ok_or("player character has no location")?;
        let class = ueforge::ue::find_class_fast(CONTROLLER_CLASS).ok_or_else(|| format!("{CONTROLLER_CLASS} is not loaded"))?;
        let location = (x + 300.0, y, z);
        // Deferred, so bWantsPlayerState is set before PostInitializeComponents,
        // where AAIController creates its PlayerState (AIController.cpp, UE 5.4).
        let actor = unsafe { ueforge::ue::spawn::begin_spawn(human_ptr, class as *const _ as u64, location, 180.0, 1.0) };
        if actor == 0 { return Err(format!("{CONTROLLER_CLASS} did not begin spawning")); }
        // SAFETY: an actor the engine created and has not finished.
        let controller = unsafe { &*(actor as *const UObject) };
        unsafe { ueforge::input::write_class_bool(controller, "bWantsPlayerState", true)? };
        if unsafe { ueforge::ue::spawn::finish_spawn(actor, location, 180.0, 1.0) } == 0 { return Err(format!("{CONTROLLER_CLASS} did not finish spawning")); }
        // The controller Blueprint's defaults leave PathFollowingComponent null
        // even though its class carries the subobject, and OnPossess initializes
        // the component only when the pointer is set. So set it before possession
        // through the engine's own SetPathFollowingComponent.
        let following_class = ueforge::ue::find_class_fast("PathFollowingComponent").ok_or("PathFollowingComponent class not found")?;
        let following_class_bytes = (following_class as *const _ as u64).to_le_bytes();
        let (parms, ret) = unsafe { crate::perception::call_named(controller, "Actor", "GetComponentByClass", &[("ComponentClass", &following_class_bytes)])? };
        let following = u64::from_le_bytes(parms[ret..ret + 8].try_into().unwrap());
        if following == 0 { return Err("the controller carries no PathFollowingComponent subobject".into()); }
        unsafe { crate::perception::call_named(controller, "AIController", "SetPathFollowingComponent", &[("NewPFComponent", &following.to_le_bytes())])? };
        // Her name on the PlayerState: what the player list, and every lookup by name, reads.
        let player_state = unsafe { object_ptr(controller, "PlayerState")? };
        if player_state == 0 { return Err("the AI controller got no PlayerState".into()); }
        // SAFETY: the PlayerState the controller just created.
        let state = unsafe { &*(player_state as *const UObject) };
        let name_offset = ueforge::input::class_property_offset(state, "PlayerNamePrivate", 16)?;
        unsafe { crate::host::write_fstring(state, name_offset, &name)? };
        // The game mode's own player spawn: default pawn class, player start, possession.
        let (parms, ret) = unsafe { crate::host::call_static("GameplayStatics", "GetGameMode", &[("WorldContextObject", &(human_ptr as u64).to_le_bytes())])? };
        let game_mode = u64::from_le_bytes(parms[ret..ret + 8].try_into().unwrap());
        if game_mode == 0 { return Err("GetGameMode returned null".into()); }
        // SAFETY: the live game mode.
        unsafe { crate::perception::call_named(&*(game_mode as *const UObject), "GameModeBase", "RestartPlayer", &[("NewPlayer", &actor.to_le_bytes())])? };
        let pawn = unsafe { object_ptr(controller, "Pawn")? };
        if pawn == 0 { return Err("RestartPlayer gave the controller no pawn".into()); }
        // The body waits at the world start holding spot; the player controller's
        // spawn flow would teleport it down, so do that one step here.
        let (start, start_location) = unsafe { world_start(0)? };
        // SAFETY: the pawn RestartPlayer just spawned.
        let teleported = unsafe { teleport(&*(pawn as *const UObject), start_location)? };
        Ok(json!({"name": name, "controller": unsafe { describe(actor) }, "player_state": format!("0x{player_state:X}"), "pawn": unsafe { describe(pawn) },
            "world_start": unsafe { describe(start) }, "teleported": teleported, "near_player": human, "state": "joined"}))
    })?;
    let controller = u64::from_str_radix(reply["controller"]["addr"].as_str().unwrap_or("0x0").trim_start_matches("0x"), 16).map_err(|e| e.to_string())?;
    if let Err(error) = crate::profile::remember(&directory, "joined", &reply["world_start"]["name"].as_str().unwrap_or("").to_owned()) { ueforge::log!("AI player {name} journal: {error}"); }
    *SESSION.lock() = Some(Session { name, directory, controller, following: Arc::new(std::sync::atomic::AtomicBool::new(false)) });
    Ok(reply)
}

fn status() -> Result<Value, String> {
    let (name, following) = {
        let session = SESSION.lock();
        let Some(session) = session.as_ref() else { return Ok(json!({"state": "not_joined"})); };
        (session.name.clone(), session.following.load(std::sync::atomic::Ordering::Relaxed))
    };
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (controller, pawn) = unsafe { session_controller()? };
        let (parms, ret) = unsafe { crate::perception::call_named(controller, "AIController", "GetMoveStatus", &[])? };
        Ok(json!({"name": name, "controller": unsafe { describe(controller as *const UObject as u64) }, "pawn": unsafe { describe(pawn) }, "walking_owned": following, "move_status": parms.get(ret).copied().unwrap_or(255), "state": "joined"}))
    })
}

/// Leave: destroy her body and controller with the engine's own DestroyActor.
fn stop() -> Result<Value, String> {
    let Some(session) = SESSION.lock().take() else { return Ok(json!({"state": "not_joined"})); };
    session.following.store(false, std::sync::atomic::Ordering::Relaxed);
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        if !modforge::winproc::is_addr_readable(session.controller as usize) { return Ok(json!({"state": "already_gone"})); }
        // SAFETY: game thread; the controller start() spawned.
        let controller = unsafe { &*(session.controller as *const UObject) };
        let pawn = unsafe { object_ptr(controller, "Pawn")? };
        if pawn != 0 { unsafe { crate::perception::call_named(&*(pawn as *const UObject), "Actor", "K2_DestroyActor", &[])? }; }
        unsafe { crate::perception::call_named(controller, "Actor", "K2_DestroyActor", &[])? };
        Ok(json!({"name": session.name, "state": "left"}))
    })
}

/// The respawn request a dead player's respawn screen sends for the player
/// start button: Request_RespawnPlayerCharacter(false, true, None).
fn respawn() -> Result<Value, String> {
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, || {
        // SAFETY: game thread.
        let (_, pawn) = unsafe { session_controller()? };
        if pawn == 0 { return Err("Sophia has no body to respawn".into()); }
        unsafe { crate::perception::call_named(&*(pawn as *const UObject), "Abiotic_PlayerCharacter_C", "Request_RespawnPlayerCharacter",
            &[("RevivedOnSpot", &[0]), ("UsePlayerStartOnly", &[1]), ("DestinationID", &[0u8; 8])])? };
        Ok(json!({"state": "requested", "pawn": unsafe { describe(pawn) }}))
    })
}

/// One walk request through her AI controller's own path following:
/// MoveToActor for a player, MoveToLocation for a point. The engine's result:
/// 0 failed (no path), 1 already at goal, 2 request accepted.
pub(crate) fn walk_to(goal: crate::nav::Goal, acceptance: f64) -> Result<Value, String> {
    let radius = (acceptance as f32).to_le_bytes();
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (controller, _) = unsafe { session_controller()? };
        let (parms, ret) = match goal {
            crate::nav::Goal::Player(player) => {
                let (_, target) = unsafe { crate::nav::player_character(&player)? };
                unsafe { crate::perception::call_named(controller, "AIController", "MoveToActor",
                    &[("Goal", &(target as *const UObject as u64).to_le_bytes()), ("AcceptanceRadius", &radius), ("bStopOnOverlap", &[1]), ("bUsePathfinding", &[1]), ("bCanStrafe", &[1]), ("FilterClass", &[0u8; 8]), ("bAllowPartialPath", &[1])])? }
            }
            crate::nav::Goal::Point(point) => unsafe { crate::perception::call_named(controller, "AIController", "MoveToLocation",
                &[("Dest", &vector_bytes(point)), ("AcceptanceRadius", &radius), ("bStopOnOverlap", &[1]), ("bUsePathfinding", &[1]), ("bProjectDestinationToNavigation", &[1]), ("bCanStrafe", &[1]), ("FilterClass", &[0u8; 8]), ("bAllowPartialPath", &[1])])? },
        };
        match parms.get(ret).copied().unwrap_or(255) {
            1 => Ok(json!({"state": "standing"})),
            2 => Ok(json!({"state": "travel_requested"})),
            other => Err(format!("the AI controller refused the move (result {other}): no path")),
        }
    })
}

/// Her path following state, from the engine: "arrived" when idle (the
/// last move finished or failed), otherwise "moving".
pub(crate) fn move_status() -> Result<String, String> {
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, || {
        // SAFETY: game thread.
        let (controller, _) = unsafe { session_controller()? };
        let (parms, ret) = unsafe { crate::perception::call_named(controller, "AIController", "GetMoveStatus", &[])? };
        Ok(json!(if parms.get(ret).copied().unwrap_or(0) == 0 { "arrived" } else { "moving" }))
    }).map(|v| v.as_str().unwrap_or("arrived").to_owned())
}

/// Follow a named player: every FOLLOW_PERIOD, walk to them while they are
/// farther than `distance`, otherwise stand still. An empty player name stops.
fn follow(args: &Value) -> Result<Value, String> {
    let target = args["player"].as_str().unwrap_or("").to_owned();
    let distance = args["distance"].as_f64().unwrap_or(FOLLOW_DISTANCE);
    if target.is_empty() {
        release_walking()?;
        return Ok(json!({"following": null}));
    }
    let walker = take_walking()?;
    let followed = target.clone();
    let reply = json!({"name": walker.name, "following": target, "distance": distance, "period_seconds": FOLLOW_PERIOD.as_secs()});
    std::thread::Builder::new().name("abiotic-ai-player-follow".into()).spawn(move || {
        while walker.alive() {
            // One game-thread job per cycle: the engine plans the path and walks it.
            if let Err(error) = walk_to(crate::nav::Goal::Player(followed.clone()), distance) {
                ueforge::log!("AI player {} following {followed}: {error}", walker.name);
            }
            std::thread::sleep(FOLLOW_PERIOD);
        }
        ueforge::log!("AI player {} stopped following {followed}", walker.name);
    }).map_err(|e| e.to_string())?;
    Ok(reply)
}

/// Research: teleport her body beside a named player or to a world start.
fn place(args: &Value) -> Result<Value, String> {
    let index = args["world_start"].as_u64().unwrap_or(0) as usize;
    let near_player = args["near_player"].as_str().filter(|s| !s.is_empty()).map(str::to_owned);
    let distance = args["distance"].as_f64().unwrap_or(600.0);
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (_, pawn) = unsafe { session_controller()? };
        if pawn == 0 { return Err("Sophia has no body".into()); }
        let (destination, location) = match near_player.as_deref() {
            Some(near) => {
                let (_, human) = unsafe { crate::nav::player_character(near)? };
                let (x, y, z) = unsafe { ueforge::ue::transform::world_location(human as *const UObject as *const u8) }.ok_or("player character has no location")?;
                (json!({"near_player": near, "distance": distance}), [x + distance, y, z])
            }
            None => { let (start, location) = unsafe { world_start(index)? }; (unsafe { describe(start) }, location) }
        };
        // SAFETY: her live pawn.
        let teleported = unsafe { teleport(&*(pawn as *const UObject), location)? };
        Ok(json!({"destination": destination, "teleported": teleported, "pawn": unsafe { describe(pawn) }}))
    })
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new("ai_player.start", "Join: spawn Sophia's AI controller with a PlayerState carrying her name, let the game mode spawn and possess her player character, place her at the first world start", "{near_player?: str, profile_dir?: str}", start),
        ueforge::ops::OpDef::new("ai_player.status", "Whether Sophia is in the world: her controller, body, walking owner and move status", "{}", |_| status()),
        ueforge::ops::OpDef::new("ai_player.stop", "Leave: destroy her body and controller", "{}", |_| stop()),
        ueforge::ops::OpDef::new("ai_player.respawn", "The respawn screen's player start request on her body", "{}", |_| respawn()),
        ueforge::ops::OpDef::new("ai_player.follow", "Follow a named player: walk to them every two seconds while farther than distance; empty player stops", "{player: str, distance?: f64}", follow),
        ueforge::ops::OpDef::new("ai_player.place", "Research: teleport her body beside a named player or to a world start with the character's own TeleportPlayer", "{near_player?: str, distance?: f64, world_start?: u64}", place),
    ]);
}
