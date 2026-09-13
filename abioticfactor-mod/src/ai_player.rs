//! The AI player: the NPCs' AI controller joined as a player, on the host,
//! with no network client. Sophia is the first named profile; the system
//! supports one session at a time, more remains future work.
//!
//! Epic's Lyra (LyraBotCreationComponent::SpawnOneBot), OpenTournament and
//! ShooterGame all make a bot the same way, and ueforge::spawn_ops does it:
//! spawn the AI controller class with bWantsPlayerState so it gets a
//! PlayerState, then hand it to the game mode's RestartPlayer, which spawns
//! the ordinary player pawn class and possesses it. Player features come from
//! the pawn and the PlayerState; NPC features from the AI controller.
//! Abiotic_PlayerCharacter_C already names Abiotic_AI_Controller_ParentBP_C
//! as its AI controller class (npc-ai.md), so nothing new is built.
//!
//! Everything here goes through ueforge's generic tools: calls by name,
//! fields by name, loops as data. Identity and memory come from her profile
//! (profile.rs). Her name goes on the PlayerState, so every lookup by player
//! name (nav.rs) finds her the way it finds the human.
use parking_lot::Mutex;
use serde_json::{Value, json};
use std::time::Duration;
use ueforge::ue::UObject;

/// The NPCs' controller, which the player character class already names.
const CONTROLLER_CLASS: &str = "Abiotic_AI_Controller_ParentBP_C";
/// Where the game keeps its NPC and AI controller Blueprints (FModel export).
const NPC_PACKAGE_DIR: &str = "/Game/Blueprints/Characters/NPCs";
/// The game's world start actors, which its own spawn flow teleports a new
/// player to (history/lan-spawn.md: Abiotic_WorldStart, TeleportPlayer).
const WORLD_START_CLASS: &str = "Abiotic_WorldStart_C";
const FOLLOW_DISTANCE: f64 = 300.0;
const FOLLOW_PERIOD_MS: u64 = 2000;
const TARGETS_PERIOD_MS: u64 = 1000;

struct Session {
    name: String,
    /// Her profile: identity, journal and what she has seen live here.
    directory: std::path::PathBuf,
    controller: u64,
}

static SESSION: Mutex<Option<Session>> = Mutex::new(None);

/// The loops that own her walking; starting one stops the other.
pub(crate) const WALKING_LOOPS: [&str; 2] = ["follow", "explore"];

pub(crate) fn session_name() -> Result<String, String> {
    SESSION.lock().as_ref().map(|s| s.name.clone()).ok_or("the AI player has not joined; run ai_player.start".into())
}

/// Her profile directory, for reading memory without touching her walking.
pub(crate) fn session_directory() -> Result<std::path::PathBuf, String> {
    SESSION.lock().as_ref().map(|s| s.directory.clone()).ok_or("the AI player has not joined; run ai_player.start".into())
}

pub(crate) fn addr(value: &Value) -> u64 {
    value["addr"].as_str().and_then(|a| u64::from_str_radix(a.trim_start_matches("0x"), 16).ok()).unwrap_or(0)
}

/// A reflected object pointer field. Game thread.
pub(crate) unsafe fn object_ptr(object: &UObject, name: &str) -> Result<u64, String> {
    Ok(addr(&unsafe { ueforge::reflect::get_fields(object, &[name.to_owned()])? }[name]))
}

/// Name, class and location of a live actor, or null for a null pointer.
pub(crate) unsafe fn describe(actor: u64) -> Value {
    if actor == 0 { return Value::Null; }
    // SAFETY: a non-null actor pointer the engine handed back.
    let object = unsafe { &*(actor as *const UObject) };
    let location = unsafe { ueforge::ue::transform::world_location(actor as *const u8) };
    json!({"addr": format!("0x{actor:X}"), "name": object.name(), "class": object.class().map(|c| c.as_object().name()).unwrap_or_default(), "location": location.map(|(x, y, z)| [x, y, z])})
}

/// Her controller and pawn from the session. The controller must still be
/// an object of its class: destroyed controllers leave readable, reused
/// memory behind (2026-09-13). Game thread.
pub(crate) unsafe fn session_controller() -> Result<(&'static UObject, u64), String> {
    let (address, name) = SESSION.lock().as_ref().map(|s| (s.controller, s.name.clone())).ok_or("the AI player has not joined; run ai_player.start")?;
    if !modforge::winproc::is_addr_readable(address as usize) { return Err(format!("{name}'s controller is gone")); }
    // SAFETY: the controller start() spawned, still readable; the class check rejects reused memory.
    let controller = unsafe { &*(address as *const UObject) };
    if !controller.class().map(|c| c.as_object().name()).unwrap_or_default().contains("Controller") { return Err(format!("{name}'s controller was destroyed; run ai_player.start again")); }
    let pawn = unsafe { object_ptr(controller, "Pawn")? };
    Ok((controller, pawn))
}

fn vector(v: [f64; 3]) -> Value { json!({"X": v[0], "Y": v[1], "Z": v[2]}) }

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
    let reply = unsafe { ueforge::reflect::call(pawn, "Abiotic_PlayerCharacter_C", "TeleportPlayer",
        json!({"DestLocation": vector(location), "DestRotation": {"Pitch": 0.0, "Yaw": 0.0, "Roll": 0.0}, "Force": true, "SkipAdjustment": false, "ExitChairs": false}).as_object().unwrap())? };
    Ok(reply["ReturnValue"] == true)
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
    // Which of the game's AI controllers she gets: the parent by default, or a
    // monster's own (AI_Controller_NPC_Exor_C carries the Exor's behavior tree).
    let controller_class = args["controller_class"].as_str().filter(|s| !s.is_empty()).unwrap_or(CONTROLLER_CLASS).to_owned();
    let name_for_job = name.clone();
    let reply = ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(30), crate::DRAIN_HINT, move || {
        let name = name_for_job;
        // SAFETY: game thread.
        let human = match near_player {
            Some(player) => player,
            None => unsafe { crate::nav::players()? }.into_iter().map(|(player, _)| player).find(|player| *player != name).ok_or("no human player in the game")?,
        };
        let (_, human_character) = unsafe { crate::nav::player_character(&human)? };
        let (x, y, z) = unsafe { ueforge::ue::transform::world_location(human_character as *const UObject as *const u8) }.ok_or("player character has no location")?;
        // The controller classes live beside the NPCs; a monster's controller is loaded from the assets when no such monster is in memory.
        crate::npcs::blueprint_class(NPC_PACKAGE_DIR, controller_class.trim_end_matches("_C"))?;
        let (actor, player_state, pawn) = unsafe { ueforge::spawn_ops::join_ai_player(human_character, &controller_class, (x + 300.0, y, z), &name)? };
        // The body waits at the world start holding spot; the player controller's
        // spawn flow would teleport it down, so do that one step here.
        let (start, start_location) = unsafe { world_start(0)? };
        // SAFETY: the pawn RestartPlayer just spawned.
        let teleported = unsafe { teleport(&*(pawn as *const UObject), start_location)? };
        Ok(json!({"name": name, "controller": unsafe { describe(actor) }, "player_state": format!("0x{player_state:X}"), "pawn": unsafe { describe(pawn) },
            "world_start": unsafe { describe(start) }, "teleported": teleported, "near_player": human, "state": "joined"}))
    })?;
    let controller = addr(&reply["controller"]);
    if let Err(error) = crate::profile::remember(&directory, "joined", reply["world_start"]["name"].as_str().unwrap_or("")) { ueforge::log!("AI player {name} journal: {error}"); }
    *SESSION.lock() = Some(Session { name, directory, controller });
    Ok(reply)
}

/// Her brain, read from the engine: the controller's BehaviorTree asset,
/// its BrainComponent and whether it runs, and the blackboard's combat keys
/// the decoded target choice writes (npc-ai.md). Game thread.
pub(crate) unsafe fn brain_state(controller: &UObject) -> Value {
    let fields = unsafe { ueforge::reflect::get_fields(controller, &["BehaviorTree".into(), "BrainComponent".into()]) }.unwrap_or(Value::Null);
    let brain = addr(&fields["BrainComponent"]);
    let running = if brain == 0 { Value::Null } else {
        // SAFETY: the live brain component.
        unsafe { ueforge::reflect::call(&*(brain as *const UObject), "BrainComponent", "IsRunning", &serde_json::Map::new()) }.map(|r| r["ReturnValue"].clone()).unwrap_or_else(|e| json!(e))
    };
    let keys: Vec<String> = ["TargetActor", "AllyTarget", "TargetLocked", "CanSeeTarget", "HasHeardSound", "CombatMode", "PotentialCombatTargetCount"].iter().map(|k| k.to_string()).collect();
    let blackboard = unsafe { ueforge::behavior_tree::blackboard_get(controller, &keys) }.unwrap_or_else(|e| json!(e));
    json!({"behavior_tree": fields["BehaviorTree"], "brain": fields["BrainComponent"], "running": running, "blackboard": blackboard})
}

fn status() -> Result<Value, String> {
    let name = match session_name() { Ok(name) => name, Err(_) => return Ok(json!({"state": "not_joined"})) };
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (controller, pawn) = unsafe { session_controller()? };
        let moving = unsafe { ueforge::reflect::call(controller, "AIController", "GetMoveStatus", &serde_json::Map::new())? }["ReturnValue"].clone();
        Ok(json!({"name": name, "controller": unsafe { describe(controller as *const UObject as u64) }, "pawn": unsafe { describe(pawn) },
            "move_status": moving, "brain": unsafe { brain_state(controller) }, "loops": ueforge::loops::list(), "state": "joined"}))
    })
}

/// Leave: stop her loops, destroy her body and controller with the engine's own DestroyActor.
fn stop() -> Result<Value, String> {
    let Some(session) = SESSION.lock().take() else { return Ok(json!({"state": "not_joined"})); };
    for name in WALKING_LOOPS.iter().chain(["targets"].iter()) { ueforge::loops::stop(name); }
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        if !modforge::winproc::is_addr_readable(session.controller as usize) { return Ok(json!({"state": "already_gone"})); }
        // SAFETY: game thread; the controller start() spawned.
        let controller = unsafe { &*(session.controller as *const UObject) };
        let pawn = unsafe { object_ptr(controller, "Pawn")? };
        if pawn != 0 { unsafe { ueforge::reflect::call(&*(pawn as *const UObject), "Actor", "K2_DestroyActor", &serde_json::Map::new())? }; }
        unsafe { ueforge::reflect::call(controller, "Actor", "K2_DestroyActor", &serde_json::Map::new())? };
        Ok(json!({"name": session.name, "state": "left"}))
    })
}

/// The respawn request a dead player's respawn screen sends for the player
/// start button: Request_RespawnPlayerCharacter(false, true, None).
fn respawn() -> Result<Value, String> {
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, || {
        // SAFETY: game thread.
        let (_, pawn) = unsafe { session_controller()? };
        if pawn == 0 { return Err("the AI player has no body to respawn".into()); }
        unsafe { ueforge::reflect::call(&*(pawn as *const UObject), "Abiotic_PlayerCharacter_C", "Request_RespawnPlayerCharacter",
            json!({"RevivedOnSpot": false, "UsePlayerStartOnly": true, "DestinationID": "None"}).as_object().unwrap())? };
        Ok(json!({"state": "requested", "pawn": unsafe { describe(pawn) }}))
    })
}

/// One walk request through her AI controller's own path following:
/// MoveToActor for a player, MoveToLocation for a point. The engine's result:
/// 0 failed (no path), 1 already at goal, 2 request accepted.
pub(crate) fn walk_to(goal: crate::nav::Goal, acceptance: f64) -> Result<Value, String> {
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (controller, _) = unsafe { session_controller()? };
        let reply = match goal {
            crate::nav::Goal::Player(player) => {
                let (_, target) = unsafe { crate::nav::player_character(&player)? };
                unsafe { ueforge::reflect::call(controller, "AIController", "MoveToActor", json!({"Goal": format!("0x{:X}", target as *const UObject as u64), "AcceptanceRadius": acceptance,
                    "bStopOnOverlap": true, "bUsePathfinding": true, "bCanStrafe": true, "FilterClass": null, "bAllowPartialPath": true}).as_object().unwrap())? }
            }
            crate::nav::Goal::Point(point) => unsafe { ueforge::reflect::call(controller, "AIController", "MoveToLocation", json!({"Dest": vector(point), "AcceptanceRadius": acceptance,
                "bStopOnOverlap": true, "bUsePathfinding": true, "bProjectDestinationToNavigation": true, "bCanStrafe": true, "FilterClass": null, "bAllowPartialPath": true}).as_object().unwrap())? },
        };
        match reply["ReturnValue"].as_u64().unwrap_or(255) {
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
        let reply = unsafe { ueforge::reflect::call(controller, "AIController", "GetMoveStatus", &serde_json::Map::new())? };
        Ok(json!(if reply["ReturnValue"].as_u64().unwrap_or(0) == 0 { "arrived" } else { "moving" }))
    }).map(|v| v.as_str().unwrap_or("arrived").to_owned())
}

/// Stop the other walking loop and stand still, so follow and explore never fight over her.
pub(crate) fn take_walking(owner: &str) -> Result<(), String> {
    for name in WALKING_LOOPS.iter().filter(|n| **n != owner) { ueforge::loops::stop(name); }
    Ok(())
}

pub(crate) fn release_walking() -> Result<(), String> {
    for name in WALKING_LOOPS { ueforge::loops::stop(name); }
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, || {
        // SAFETY: game thread.
        let (controller, _) = unsafe { session_controller()? };
        unsafe { ueforge::reflect::call(controller, "Controller", "StopMovement", &serde_json::Map::new())? };
        Ok(json!({}))
    }).map(|_| ())
}

/// One follow step: walk to the named player while farther than `distance`.
fn walk(args: &Value) -> Result<Value, String> {
    let player = args["player"].as_str().filter(|s| !s.is_empty()).ok_or("player must be a player name")?.to_owned();
    let distance = args["distance"].as_f64().unwrap_or(FOLLOW_DISTANCE);
    walk_to(crate::nav::Goal::Player(player), distance)
}

/// Follow a named player: the "follow" loop runs ai_player.walk every two
/// seconds; the engine plans the path and walks it. An empty player stops.
fn follow(args: &Value) -> Result<Value, String> {
    let target = args["player"].as_str().unwrap_or("").to_owned();
    if target.is_empty() { release_walking()?; return Ok(json!({"following": null})); }
    session_name()?;
    take_walking("follow")?;
    ueforge::loops::start("follow", "ai_player.walk", json!({"player": target, "distance": args["distance"].as_f64().unwrap_or(FOLLOW_DISTANCE)}), Duration::from_millis(FOLLOW_PERIOD_MS))
}

/// One eyes-to-brain step: everything her perception lists goes into her
/// controller's own potential target list through AddOrUpdatePotentialTarget,
/// the way the NPC body's perception event feeds an Exor's controller. The
/// controller's target choice then filters by faction and picks.
fn hand_targets(_: &Value) -> Result<Value, String> {
    let name = session_name()?;
    let rows = crate::perception::perceived_rows(&name)?;
    let actors: Vec<u64> = rows.iter().filter_map(|r| u64::from_str_radix(r.addr.trim_start_matches("0x"), 16).ok()).collect();
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (controller, pawn) = unsafe { session_controller()? };
        let mut handed = 0;
        for actor in actors.iter().filter(|a| **a != pawn) {
            unsafe { ueforge::reflect::call(controller, "Abiotic_AI_Controller_ParentBP_C", "AddOrUpdatePotentialTarget", json!({"PotentialTarget": format!("0x{actor:X}"), "ForceSpotTargetImmediately": false}).as_object().unwrap())? };
            handed += 1;
        }
        Ok(json!({"handed": handed}))
    })
}

/// Eyes to brain as a loop: the "targets" loop runs ai_player.hand_targets every second; on=false stops it.
fn targets(args: &Value) -> Result<Value, String> {
    if !args["on"].as_bool().unwrap_or(true) { return Ok(json!({"targets": false, "stopped": ueforge::loops::stop("targets")})); }
    session_name()?;
    ueforge::loops::start("targets", "ai_player.hand_targets", json!({}), Duration::from_millis(TARGETS_PERIOD_MS))
}

/// Research: teleport her body beside a named player or to a world start.
fn place(args: &Value) -> Result<Value, String> {
    let index = args["world_start"].as_u64().unwrap_or(0) as usize;
    let near_player = args["near_player"].as_str().filter(|s| !s.is_empty()).map(str::to_owned);
    let distance = args["distance"].as_f64().unwrap_or(600.0);
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (_, pawn) = unsafe { session_controller()? };
        if pawn == 0 { return Err("the AI player has no body".into()); }
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

/// Run a behavior tree on her controller through the engine's own
/// RunBehaviorTree: the controller class's tree by default (the Exor's
/// controller carries BT_Main_Exor), or a named asset path.
fn brain(args: &Value) -> Result<Value, String> {
    let asset = args["tree"].as_str().filter(|s| !s.is_empty()).map(|s| format!("asset:{s}"));
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(30), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (controller, _) = unsafe { session_controller()? };
        let tree = match asset { Some(path) => ueforge::reflect::object_ref(&json!(path))?, None => unsafe { object_ptr(controller, "BehaviorTree")? } };
        if tree == 0 { return Err("no behavior tree: the controller class names none and no tree was given".into()); }
        let reply = unsafe { ueforge::reflect::call(controller, "AIController", "RunBehaviorTree", json!({"BTAsset": format!("0x{tree:X}")}).as_object().unwrap())? };
        // SAFETY: the live tree asset.
        Ok(json!({"tree": unsafe { &*(tree as *const UObject) }.full_name(), "started": reply["ReturnValue"], "brain": unsafe { brain_state(controller) }}))
    })
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new("ai_player.start", "Join: spawn the AI player's controller with a PlayerState carrying her name, let the game mode spawn and possess her player character, place her at the first world start", "{near_player?: str, profile_dir?: str, controller_class?: str}", start),
        ueforge::ops::OpDef::new("ai_player.status", "Whether the AI player is in the world: her controller, body, move status, brain, blackboard and loops", "{}", |_| status()),
        ueforge::ops::OpDef::new("ai_player.stop", "Leave: stop her loops, destroy her body and controller", "{}", |_| stop()),
        ueforge::ops::OpDef::new("ai_player.respawn", "The respawn screen's player start request on her body", "{}", |_| respawn()),
        ueforge::ops::OpDef::new("ai_player.walk", "One walk step: MoveToActor toward a named player while farther than distance", "{player: str, distance?: f64}", walk),
        ueforge::ops::OpDef::new("ai_player.follow", "Follow a named player: the follow loop runs ai_player.walk every two seconds; empty player stops", "{player: str, distance?: f64}", follow),
        ueforge::ops::OpDef::new("ai_player.hand_targets", "One eyes-to-brain step: hand everything her perception lists to her controller's AddOrUpdatePotentialTarget", "{}", hand_targets),
        ueforge::ops::OpDef::new("ai_player.targets", "Eyes to brain as a loop, every second; on=false stops", "{on?: bool}", targets),
        ueforge::ops::OpDef::new("ai_player.brain", "Run a behavior tree on her controller: the controller class's own tree, or a named asset path", "{tree?: str}", brain),
        ueforge::ops::OpDef::new("ai_player.place", "Research: teleport her body beside a named player or to a world start with the character's own TeleportPlayer", "{near_player?: str, distance?: f64, world_start?: u64}", place),
    ]);
}
