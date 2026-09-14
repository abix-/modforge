//! AI players in this game: persistent named characters (modforge::persona;
//! Sophia is the first, Charles next) spawned with NPC bodies on the host,
//! driven by the game's own NPC controller. The
//! engine-generic parts live in ueforge (spawn_ops::join_ai_player, the
//! behavior tree builder, loops, reflection); this module holds only what
//! is Abiotic Factor: the controller class names, the world starts, the
//! character's own teleport and respawn calls, the target hand-off into the
//! game's controller.
//!
//! Every op takes `player`, the character's name; it defaults to the one
//! AI player joined when there is exactly one. Sessions are kept by name,
//! so more than one can be in the world at once.
//!
//! Our custom class inherits the game's NPC base and uses the base controller.
//! The former RestartPlayer path produced a player body that failed NPC setup.
use parking_lot::Mutex;
use serde_json::{Value, json};
use std::collections::BTreeMap;
use std::time::Duration;
use ueforge::ue::UObject;

/// The first persistent named character; `ai_player.start {name}` picks another.
pub(crate) const DEFAULT_NAME: &str = "Sophia";
const DEFAULT_APPEARANCE: &str = "female";
/// The game's world start actors, which its own spawn flow teleports a new
/// player to (history/lan-spawn.md: Abiotic_WorldStart, TeleportPlayer).
const WORLD_START_CLASS: &str = "Abiotic_WorldStart_C";
const FOLLOW_DISTANCE: f64 = 300.0;
const TARGETS_PERIOD_MS: u64 = 1000;

#[derive(Clone)]
struct Session {
    /// Her persona directory: identity, journal and what she has seen live here.
    directory: std::path::PathBuf,
    controller: u64,
    identity: ueforge::ue::uobject::ObjectIdentity,
}

impl Session {
    /// Resolve through the engine object array before touching cached memory.
    /// Game thread only; a readable address can belong to a destroyed actor.
    unsafe fn live_controller(&self) -> Option<&'static UObject> {
        unsafe { self.identity.resolve() }
    }
}

static SESSIONS: Mutex<BTreeMap<String, Session>> = Mutex::new(BTreeMap::new());

/// The player an op means: the given name, or the one AI player joined.
pub(crate) fn player_name(args: &Value) -> Result<String, String> {
    if let Some(name) = args["player"].as_str().filter(|s| !s.is_empty()) { return Ok(name.to_owned()); }
    let sessions = SESSIONS.lock();
    match sessions.len() {
        0 => Err("no AI player has joined; run ai_player.start".into()),
        1 => Ok(sessions.keys().next().cloned().unwrap()),
        _ => Err(format!("more than one AI player is in the world; say which: {:?}", sessions.keys().collect::<Vec<_>>())),
    }
}

/// A player's persona directory, for reading memory without touching her walking.
pub(crate) fn session_directory(name: &str) -> Result<std::path::PathBuf, String> {
    SESSIONS.lock().get(name).map(|s| s.directory.clone()).ok_or_else(|| format!("{name} has not joined; run ai_player.start"))
}

/// The loops that own a player's walking; starting one stops the other.
const WALKING_LOOPS: [&str; 2] = ["follow", "explore"];

pub(crate) fn loop_name(player: &str, purpose: &str) -> String { format!("{player}:{purpose}") }

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

/// A player's controller and pawn from her session. The controller must
/// still be an object of its class: destroyed controllers leave readable,
/// reused memory behind (2026-09-13). Game thread.
pub(crate) unsafe fn session_controller(name: &str) -> Result<(&'static UObject, u64), String> {
    let session = SESSIONS.lock().get(name).cloned().ok_or_else(|| format!("{name} has not joined; run ai_player.start"))?;
    // SAFETY: called on the game thread; resolves the engine-owned object first.
    let controller = unsafe { session.live_controller() }.ok_or_else(|| format!("{name}'s controller is gone; run ai_player.start"))?;
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

/// Spawn a named AI player beside the human using our custom NPC type.
/// Keep its own initialized AI controller. Idempotent while joined.
fn start(args: &Value) -> Result<Value, String> {
    let name = args["name"].as_str().filter(|s| !s.is_empty()).unwrap_or(DEFAULT_NAME).to_owned();
    let existing = SESSIONS.lock().get(&name).cloned();
    if let Some(session) = existing {
        let address = session.controller;
        let active = ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
            // SAFETY: resolve and inspect the controller on the game thread.
            let active = match unsafe { session.live_controller() } {
                Some(controller) => (unsafe { object_ptr(controller, "Pawn")? }) != 0,
                None => false,
            };
            Ok(json!(active))
        })?;
        if active == true { return Ok(json!({"name": name, "controller": format!("0x{address:X}"), "state": "already_joined"})); }
        stop(&json!({"player": name}))?;
    }
    let directory = match args["profile_dir"].as_str().filter(|s| !s.is_empty()) { Some(dir) => std::path::PathBuf::from(dir), None => modforge::persona::directory(&name).map_err(|e| e.to_string())? };
    let profile = modforge::persona::Profile::load_or_create(&directory, &name, args["appearance"].as_str().unwrap_or(DEFAULT_APPEARANCE)).map_err(|e| e.to_string())?;
    let near_player = args["near_player"].as_str().filter(|s| !s.is_empty()).map(str::to_owned);
    let distance = args["distance"].as_f64().unwrap_or(300.0);
    let name_for_job = profile.name.clone();
    let reply = ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(30), crate::DRAIN_HINT, move || {
        let name = name_for_job;
        // SAFETY: game thread.
        let human = match near_player {
            Some(player) => player,
            None => unsafe { crate::nav::players()? }.into_iter().map(|(player, _)| player).find(|player| *player != name).ok_or("no human player in the game")?,
        };
        let (_, human_character) = unsafe { crate::nav::player_character(&human)? };
        let faction = unsafe { ueforge::reflect::get_fields(human_character, &["Faction".into()])? }["Faction"].clone();
        if !faction.is_u64() { return Err("human player faction unavailable".into()); }
        let (x, y, z) = unsafe { ueforge::ue::transform::world_location(human_character as *const UObject as *const u8) }.ok_or("player character has no location")?;
        // SAFETY: one game-thread job initializes the custom body and controller
        // before their first combat tick, including allegiance to this human.
        let (pawn, controller) = unsafe { crate::body::spawn(human_character, (x + distance, y, z), faction.clone())? };
        // SAFETY: the native base initialized this NPC and its movement component.
        unsafe {
            let body = &*(pawn as *const UObject);
            let movement = object_ptr(body, "CharacterMovement")?;
            if movement == 0 { return Err("spawned NPC has no movement component".into()); }
            let speed = ueforge::reflect::get_fields(body, &["WalkSpeed".into()])?["WalkSpeed"].as_f64().ok_or("NPC walk speed missing")? * 2.0;
            ueforge::reflect::set_fields(body, json!({"WalkSpeed": speed}).as_object().unwrap())?;
            ueforge::reflect::set_fields(&*(movement as *const UObject), json!({"MaxWalkSpeed": speed}).as_object().unwrap())?;
        }
        let weapon = match unsafe { crate::weapon::equip(&*(pawn as *const UObject)) } {
            Ok(weapon) => weapon,
            Err(error) => {
                for actor in [pawn, controller] {
                    // SAFETY: these actors were created by this game-thread job.
                    unsafe { ueforge::reflect::call(&*(actor as *const UObject), "Actor", "K2_DestroyActor", &serde_json::Map::new()) }
                        .map_err(|cleanup| format!("{error}; spawn cleanup failed: {cleanup}"))?;
                }
                return Err(error);
            }
        };
        // RunBehaviorTree creates the blackboard and brain before the first tick.
        // Stop it in this same job so the shared orders path takes control.
        let controller_object = unsafe { &*(controller as *const UObject) };
        let initial_tree = unsafe { object_ptr(controller_object, "BehaviorTree")? };
        if initial_tree == 0 { return Err("spawned controller has no tree asset".into()); }
        let initialized = unsafe { ueforge::reflect::call(controller_object, "AIController", "RunBehaviorTree", json!({"BTAsset": format!("0x{initial_tree:X}")}).as_object().unwrap())? };
        if initialized["ReturnValue"] != true { return Err("spawned controller initialization failed".into()); }
        let brain = unsafe { object_ptr(controller_object, "BrainComponent")? };
        if brain == 0 { return Err("spawned NPC brain missing".into()); }
        unsafe { ueforge::reflect::call(&*(brain as *const UObject), "BrainComponent", "StopLogic", json!({"Reason": "AI player orders initializing"}).as_object().unwrap())? };
        Ok(json!({"name": name, "controller": unsafe { describe(controller) }, "pawn": unsafe { describe(pawn) },
            "controller_index": unsafe { (&*(controller as *const UObject)).index() },
            "near_player": human, "faction": faction, "weapon": weapon, "body": "npc", "state": "joined"}))
    })?;
    let controller = addr(&reply["controller"]);
    if let Err(error) = modforge::persona::remember(&directory, "joined", reply["world_start"]["name"].as_str().unwrap_or("")) { ueforge::log!("AI player {name} journal: {error}"); }
    let controller_index = reply["controller_index"].as_i64().ok_or("controller index missing")? as i32;
    let controller_name = reply["controller"]["name"].as_str().ok_or("controller name missing")?.to_owned();
    let identity = ueforge::ue::uobject::ObjectIdentity { address: controller, index: controller_index, name: controller_name };
    SESSIONS.lock().insert(name.clone(), Session { directory, controller, identity });
    // The current spawn operation creates an ally. Orders themselves do not
    // require human allegiance or a Follow assignment.
    let defaults = modforge::ai_orders::OrdersDef {
        assignment: modforge::ai_orders::Assignment::Follow {
            player: reply["near_player"].as_str().ok_or("spawn has no human")?.into(),
        },
        stance: modforge::ai_orders::Stance::Defensive,
        limits: modforge::ai_orders::Limits {
            follow_distance: 150.0, hold_radius: 75.0, chase_distance: 1200.0, pursuit_timeout: 20.0,
        },
        groups: vec![],
    };
    if let Err(error) = crate::orders::start(&name, defaults) {
        stop(&json!({"player": name})).map_err(|cleanup| format!("{error}; cleanup: {cleanup}"))?;
        return Err(error);
    }
    Ok(reply)
}

/// A player's brain, read from the engine: the controller's BehaviorTree
/// asset, its BrainComponent and whether it runs, and the blackboard's
/// combat keys the decoded target choice writes (npc-ai.md). Game thread.
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

fn status(args: &Value) -> Result<Value, String> {
    let name = match player_name(args) { Ok(name) => name, Err(_) => return Ok(json!({"state": "not_joined", "players": SESSIONS.lock().keys().collect::<Vec<_>>()})) };
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (controller, pawn) = unsafe { session_controller(&name)? };
        let moving = unsafe { ueforge::reflect::call(controller, "AIController", "GetMoveStatus", &serde_json::Map::new())? }["ReturnValue"].clone();
        Ok(json!({"name": name, "controller": unsafe { describe(controller as *const UObject as u64) }, "pawn": unsafe { describe(pawn) },
            "move_status": moving, "brain": unsafe { brain_state(controller) }, "loops": ueforge::loops::list(), "players": SESSIONS.lock().keys().collect::<Vec<_>>(), "state": "joined"}))
    })
}

/// Leave: stop her loops, destroy her body and controller with the engine's own DestroyActor.
fn stop(args: &Value) -> Result<Value, String> {
    let name = match player_name(args) { Ok(name) => name, Err(_) => return Ok(json!({"state": "not_joined"})) };
    crate::orders::stop(&name);
    let Some(session) = SESSIONS.lock().remove(&name) else { return Ok(json!({"name": name, "state": "not_joined"})); };
    for purpose in WALKING_LOOPS.iter().chain(["targets"].iter()) { ueforge::loops::stop(&loop_name(&name, purpose)); }
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread; reject a collected or replaced controller.
        let Some(controller) = (unsafe { session.live_controller() }) else { return Ok(json!({"name": name, "state": "already_gone"})); };
        let pawn = unsafe { object_ptr(controller, "Pawn")? };
        if pawn != 0 { unsafe { ueforge::reflect::call(&*(pawn as *const UObject), "Actor", "K2_DestroyActor", &serde_json::Map::new())? }; }
        unsafe { ueforge::reflect::call(controller, "Actor", "K2_DestroyActor", &serde_json::Map::new())? };
        Ok(json!({"name": name, "state": "left"}))
    })
}

/// Replace the NPC body while retaining the named persona and saved orders.
fn respawn(args: &Value) -> Result<Value, String> {
    let name = player_name(args)?;
    let directory = session_directory(&name)?;
    stop(&json!({"player": name}))?;
    start(&json!({"name": name, "profile_dir": directory, "distance": 200.0}))
}

/// One walk request through a player's AI controller's own path following:
/// MoveToActor for a player, MoveToLocation for a point. The engine's result:
/// 0 failed (no path), 1 already at goal, 2 request accepted.
pub(crate) fn walk_to(name: &str, goal: crate::nav::Goal, acceptance: f64) -> Result<Value, String> {
    if crate::orders::active(name) { return Err("AI player assignments own movement; use Follow or Hold".into()); }
    let name = name.to_owned();
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (controller, _) = unsafe { session_controller(&name)? };
        let reply = match goal {
            crate::nav::Goal::Player(player) => {
                // Following must not replace the melee tree's approach to its target.
                let combat = unsafe { ueforge::behavior_tree::blackboard_get(controller, &["CombatMode".into(), "TargetActor".into()])? };
                if combat["CombatMode"] == true && addr(&combat["TargetActor"]) != 0 {
                    return Ok(json!({"state": "fighting"}));
                }
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

/// A player's path following state, from the engine: "arrived" when idle
/// (the last move finished or failed), otherwise "moving".
pub(crate) fn move_status(name: &str) -> Result<String, String> {
    let name = name.to_owned();
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (controller, _) = unsafe { session_controller(&name)? };
        let reply = unsafe { ueforge::reflect::call(controller, "AIController", "GetMoveStatus", &serde_json::Map::new())? };
        Ok(json!(if reply["ReturnValue"].as_u64().unwrap_or(0) == 0 { "arrived" } else { "moving" }))
    }).map(|v| v.as_str().unwrap_or("arrived").to_owned())
}

/// Stop a player's other walking loop, so follow and explore never fight over her.
pub(crate) fn take_walking(name: &str, owner: &str) {
    for purpose in WALKING_LOOPS.iter().filter(|p| **p != owner) { ueforge::loops::stop(&loop_name(name, purpose)); }
}

/// Stop a player's walking loops and stand still.
pub(crate) fn release_walking(name: &str) -> Result<(), String> {
    if crate::orders::active(name) { return crate::orders::command(&json!({"player": name, "command": "hold"})).map(|_| ()); }
    for purpose in WALKING_LOOPS { ueforge::loops::stop(&loop_name(name, purpose)); }
    let name = name.to_owned();
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (controller, _) = unsafe { session_controller(&name)? };
        unsafe { ueforge::reflect::call(controller, "Controller", "StopMovement", &serde_json::Map::new())? };
        Ok(json!({}))
    }).map(|_| ())
}

/// One follow step: walk to the named target while farther than `distance`.
fn walk(args: &Value) -> Result<Value, String> {
    let name = player_name(args)?;
    let target = args["target"].as_str().filter(|s| !s.is_empty()).ok_or("target must be a player name")?.to_owned();
    walk_to(&name, crate::nav::Goal::Player(target), args["distance"].as_f64().unwrap_or(FOLLOW_DISTANCE))
}

/// Follow a named target: the player's follow loop runs ai_player.walk
/// every two seconds; the engine plans the path and walks it. An empty
/// target stops.
fn follow(args: &Value) -> Result<Value, String> {
    let name = player_name(args)?;
    let target = args["target"].as_str().unwrap_or("").to_owned();
    crate::orders::command(&json!({"player": name, "command": if target.is_empty() { "hold" } else { "follow" },
        "target": target, "distance": args["distance"].as_f64().unwrap_or(FOLLOW_DISTANCE)}))
}

/// One eyes-to-brain step: everything the player's perception lists goes
/// into her controller's own potential target list through
/// AddOrUpdatePotentialTarget, the way the NPC body's perception event feeds
/// an Exor's controller. The controller's target choice then filters by
/// faction and picks.
fn hand_targets(args: &Value) -> Result<Value, String> {
    let name = player_name(args)?;
    let rows = crate::perception::perceived_rows(&name)?;
    let actors: Vec<u64> = rows.iter().filter_map(|r| u64::from_str_radix(r.addr.trim_start_matches("0x"), 16).ok()).collect();
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (controller, pawn) = unsafe { session_controller(&name)? };
        let mut handed = 0;
        for actor in actors.iter().filter(|a| **a != pawn) {
            unsafe { ueforge::reflect::call(controller, "Abiotic_AI_Controller_ParentBP_C", "AddOrUpdatePotentialTarget", json!({"PotentialTarget": format!("0x{actor:X}"), "ForceSpotTargetImmediately": false}).as_object().unwrap())? };
            handed += 1;
        }
        Ok(json!({"name": name, "handed": handed}))
    })
}

/// Eyes to brain as a loop: the player's targets loop runs ai_player.hand_targets every second; on=false stops it.
fn targets(args: &Value) -> Result<Value, String> {
    let name = player_name(args)?;
    if !args["on"].as_bool().unwrap_or(true) { return Ok(json!({"name": name, "targets": false, "stopped": ueforge::loops::stop(&loop_name(&name, "targets"))})); }
    ueforge::loops::start(&loop_name(&name, "targets"), "ai_player.hand_targets", json!({"player": name}), Duration::from_millis(TARGETS_PERIOD_MS))
}

/// Research: teleport a player's body beside a named player or to a world start.
fn place(args: &Value) -> Result<Value, String> {
    let name = player_name(args)?;
    let index = args["world_start"].as_u64().unwrap_or(0) as usize;
    let near_player = args["near_player"].as_str().filter(|s| !s.is_empty()).map(str::to_owned);
    let distance = args["distance"].as_f64().unwrap_or(600.0);
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (_, pawn) = unsafe { session_controller(&name)? };
        if pawn == 0 { return Err(format!("{name} has no body")); }
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
        Ok(json!({"name": name, "destination": destination, "teleported": teleported, "pawn": unsafe { describe(pawn) }}))
    })
}

/// Run a behavior tree on a player's controller through the engine's own
/// RunBehaviorTree: the controller class's tree by default (the Exor's
/// controller carries BT_Main_Exor), or a named asset path.
fn brain(args: &Value) -> Result<Value, String> {
    let name = player_name(args)?;
    if crate::orders::active(&name) { return Err("AI player orders own the behavior tree".into()); }
    let asset = args["tree"].as_str().filter(|s| !s.is_empty()).map(|s| format!("asset:{s}"));
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(30), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (controller, _) = unsafe { session_controller(&name)? };
        let tree = match asset { Some(path) => ueforge::reflect::object_ref(&json!(path))?, None => unsafe { object_ptr(controller, "BehaviorTree")? } };
        if tree == 0 { return Err("no behavior tree: the controller class names none and no tree was given".into()); }
        let reply = unsafe { ueforge::reflect::call(controller, "AIController", "RunBehaviorTree", json!({"BTAsset": format!("0x{tree:X}")}).as_object().unwrap())? };
        // SAFETY: the live tree asset.
        Ok(json!({"name": name, "tree": unsafe { &*(tree as *const UObject) }.full_name(), "started": reply["ReturnValue"], "brain": unsafe { brain_state(controller) }}))
    })
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new("ai_player.start", "Spawn a named character (default Sophia) with our custom NPC body and the base AI controller beside the human", "{name?: str, appearance?: str, near_player?: str, profile_dir?: str, distance?: f64}", start),
        ueforge::ops::OpDef::new("ai_player.status", "An AI player's state: controller, body, move status, brain, blackboard, loops; and who is joined", "{player?: str}", status),
        ueforge::ops::OpDef::new("ai_player.stop", "Leave: stop the player's loops, destroy her body and controller", "{player?: str}", stop),
        ueforge::ops::OpDef::new("ai_player.respawn", "The respawn screen's player start request on the player's body", "{player?: str}", respawn),
        ueforge::ops::OpDef::new("ai_player.walk", "One walk step: MoveToActor toward a named target while farther than distance", "{player?: str, target: str, distance?: f64}", walk),
        ueforge::ops::OpDef::new("ai_player.follow", "Follow a named target: the player's follow loop runs ai_player.walk every two seconds; empty target stops", "{player?: str, target: str, distance?: f64}", follow),
        ueforge::ops::OpDef::new("ai_player.hand_targets", "One eyes-to-brain step: hand everything the player's perception lists to her controller's AddOrUpdatePotentialTarget", "{player?: str}", hand_targets),
        ueforge::ops::OpDef::new("ai_player.targets", "Eyes to brain as a loop, every second; on=false stops", "{player?: str, on?: bool}", targets),
        ueforge::ops::OpDef::new("ai_player.brain", "Run a behavior tree on the player's controller: the controller class's own tree, or a named asset path", "{player?: str, tree?: str}", brain),
        ueforge::ops::OpDef::new("ai_player.place", "Research: teleport the player's body beside a named player or to a world start with the character's own TeleportPlayer", "{player?: str, near_player?: str, distance?: f64, world_start?: u64}", place),
    ]);
}
