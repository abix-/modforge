//! Players by name and paths on the host's navigation mesh. Every player,
//! human or AI, is found the same way: the name on the PlayerState of a
//! live controller. Path queries go through ueforge::nav
//! (NavigationSystemV1::FindPathToLocationSynchronously) on the game thread;
//! an AI player's walking is her AI controller's own path following
//! (ai_player.rs), which plans for itself.
use modforge::route::Position;
use serde_json::{Value, json};
use std::time::Duration;
use ueforge::ue::UObject;

fn position(args: &Value, key: &str) -> Result<Position, String> {
    let list = args[key].as_array().filter(|v| v.len() == 3).ok_or(format!("{key} must be [x, y, z]"))?;
    let f = |i: usize| list[i].as_f64().ok_or(format!("{key}[{i}] must be a number"));
    Ok(Position::new(f(0)?, f(1)?, f(2)?))
}

pub fn position_of(list: &[f64; 3]) -> Position {
    Position::new(list[0], list[1], list[2])
}

/// The world context object for path queries, found once. Any live world
/// object serves; resolving it by class walks the whole object list, so that
/// happens only when the cached pointer is gone (world change).
static CONTEXT: parking_lot::Mutex<Option<u64>> = parking_lot::Mutex::new(None);

pub(crate) fn world_context() -> Result<u64, String> {
    let mut cache = CONTEXT.lock();
    if let Some(address) = *cache {
        if modforge::winproc::is_addr_readable(address as usize) { return Ok(address); }
    }
    let address = ueforge::selector::resolve("first_class:Abiotic_PlayerCharacter_C")? as *const UObject as u64;
    *cache = Some(address);
    Ok(address)
}

/// Path points from the host's navigation mesh, computed on the game thread.
pub fn path_points(from: Position, to: Position) -> Result<Vec<[f64; 3]>, String> {
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        let path = ueforge::nav::find_path(world_context()?, from, to)?;
        let points: Vec<[f64; 3]> = path.points().iter().map(|p| [p.position.x, p.position.y, p.position.z]).collect();
        Ok(json!(points))
    }).and_then(|v| serde_json::from_value(v).map_err(|e| e.to_string()))
}

fn find_path(args: &Value) -> Result<Value, String> {
    let points = path_points(position(args, "from")?, position(args, "to")?)?;
    Ok(json!({"count": points.len(), "points": points}))
}

/// Read a reflected object pointer field. Game thread.
unsafe fn object_field(object: &UObject, name: &str) -> Result<u64, String> {
    let offset = ueforge::input::class_property_offset(object, name, 8)?;
    // SAFETY: the reflected field is pointer sized and belongs to the live object.
    Ok(unsafe { (object.field_ptr(offset) as *const u64).read_unaligned() })
}

/// Every live player, by the name on the player state of its controller. Game thread.
pub(crate) unsafe fn players() -> Result<Vec<(String, &'static UObject)>, String> {
    let mut found = Vec::new();
    // Humans hold player controllers; AI players hold the NPCs' AI controller
    // with a PlayerState carrying their name (ai_player.rs). Both are players here.
    for pointer in ueforge::ue::actor::find_objects_by_chain("Abiotic_PlayerController_C").into_iter()
        .chain(ueforge::ue::actor::find_objects_by_chain("Abiotic_AI_Controller_ParentBP_C")) {
        // SAFETY: the pointer came from the live object list.
        let controller = unsafe { &*(pointer as *const UObject) };
        if let Some(name) = unsafe { controller_name(controller)? } { found.push((name, controller)); }
    }
    Ok(found)
}

/// Player controllers already found by name. A full object scan costs a frame
/// hitch on the game thread, so it happens once per player, not per lookup.
static CONTROLLERS: parking_lot::Mutex<std::collections::BTreeMap<String, u64>> = parking_lot::Mutex::new(std::collections::BTreeMap::new());

/// The name on a controller's player state, without any object scan. Game thread.
unsafe fn controller_name(controller: &UObject) -> Result<Option<String>, String> {
    let state = unsafe { object_field(controller, "PlayerState")? };
    if state == 0 { return Ok(None); }
    // SAFETY: a non-null replicated player state pointer.
    let state = unsafe { &*(state as *const UObject) };
    let offset = ueforge::input::class_property_offset(state, "PlayerNamePrivate", 16)?;
    // SAFETY: PlayerNamePrivate is an FString on the live player state.
    Ok(Some(unsafe { &*(state.field_ptr(offset) as *const ueforge::ue::FString) }.as_string()))
}

unsafe fn player_controller_named(name: &str) -> Result<&'static UObject, String> {
    let cached = CONTROLLERS.lock().get(name).copied();
    if let Some(address) = cached {
        if modforge::winproc::is_addr_readable(address as usize) {
            // SAFETY: found by an earlier scan and still readable; the name check below rejects a reused address.
            let controller = unsafe { &*(address as *const UObject) };
            if unsafe { controller_name(controller)? }.as_deref() == Some(name) { return Ok(controller); }
        }
        CONTROLLERS.lock().remove(name);
    }
    let players = unsafe { players()? };
    let mut cache = CONTROLLERS.lock();
    for (player, controller) in &players { cache.insert(player.clone(), *controller as *const UObject as u64); }
    players.iter().find(|(player, _)| player == name).map(|(_, controller)| *controller)
        .ok_or_else(|| format!("no player controller named {name}; players present: {:?}", players.iter().map(|(p, _)| p).collect::<Vec<_>>()))
}

/// The named player's cached controller and its live character. Game thread.
pub(crate) unsafe fn player_character(name: &str) -> Result<(&'static UObject, &'static UObject), String> {
    let controller = unsafe { player_controller_named(name)? };
    // A player controller keeps its character in PlayerCharacter; an AI controller has only Pawn.
    let character = match unsafe { object_field(controller, "PlayerCharacter") } {
        Ok(character) => character,
        Err(_) => unsafe { object_field(controller, "Pawn")? },
    };
    if character == 0 { return Err(format!("{name}'s controller has no character")); }
    // SAFETY: a non-null character pointer the controller replicates.
    Ok((controller, unsafe { &*(character as *const UObject) }))
}

/// The named player's character location, read on the game thread from the cached controller.
unsafe fn character_location(name: &str) -> Result<[f64; 3], String> {
    let (_, character) = unsafe { player_character(name)? };
    // SAFETY: a live character actor.
    let (x, y, z) = unsafe { ueforge::ue::transform::world_location(character as *const UObject as *const u8) }.ok_or("character has no world location")?;
    Ok([x, y, z])
}

/// Where a walk should end.
pub enum Goal {
    Point([f64; 3]),
    Player(String),
}

/// One plan for one walk, produced by a single game-thread job.
#[derive(serde::Serialize, serde::Deserialize)]
pub struct Plan {
    pub from: [f64; 3],
    pub to: [f64; 3],
    /// Empty when the goal is already within `stand_within` units.
    pub points: Vec<[f64; 3]>,
}

pub fn flat_distance(a: &[f64; 3], b: &[f64; 3]) -> f64 {
    ((a[0] - b[0]).powi(2) + (a[1] - b[1]).powi(2)).sqrt()
}

/// Plan a walk for the named player in one game-thread job: read the start
/// from its cached controller, resolve the goal (a point, or another player's
/// cached controller), and unless the goal is within `stand_within`, ask the
/// host navigation mesh for the path. Nothing here scans the object list
/// after the first call for each player.
pub fn plan(name: &str, goal: Goal, stand_within: f64) -> Result<Plan, String> {
    let name = name.to_owned();
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let from = unsafe { character_location(&name)? };
        let to = match goal { Goal::Point(p) => p, Goal::Player(other) => unsafe { character_location(&other)? } };
        let points = if flat_distance(&from, &to) <= stand_within { Vec::new() } else {
            let path = ueforge::nav::find_path(world_context()?, position_of(&from), position_of(&to))?;
            path.points().iter().map(|p| [p.position.x, p.position.y, p.position.z]).collect()
        };
        Ok(json!(Plan { from, to, points }))
    }).and_then(|v| serde_json::from_value(v).map_err(|e| e.to_string()))
}

/// Who is in the hosted game: each player's name, controller, character and character location.
fn list_players(_: &Value) -> Result<Value, String> {
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, || {
        let mut rows = Vec::new();
        // SAFETY: game thread.
        for (name, controller) in unsafe { players()? } {
            // A player controller keeps its character in PlayerCharacter; an AI player's controller has only Pawn.
            let character = match unsafe { object_field(controller, "PlayerCharacter") } { Ok(c) => c, Err(_) => unsafe { object_field(controller, "Pawn")? } };
            // SAFETY: a live character actor or null.
            let location = if character == 0 { None } else { unsafe { ueforge::ue::transform::world_location(character as *const u8) } };
            // The Faction byte on the character decides who counts as an enemy (npc-ai.md).
            let faction = if character == 0 { None } else {
                let character = unsafe { &*(character as *const UObject) };
                ueforge::input::class_property_offset(character, "Faction", 1).ok().map(|offset| unsafe { std::ptr::read_volatile(character.field_ptr(offset)) })
            };
            rows.push(json!({"name": name, "controller": format!("0x{:X}", controller as *const UObject as u64),
                "character": format!("0x{character:X}"), "location": location.map(|(x, y, z)| [x, y, z]), "faction": faction}));
        }
        Ok(json!({"count": rows.len(), "players": rows}))
    })
}

/// Research: ask the engine's own path following to move a named player's
/// controller, the way Blueprint's SimpleMoveToLocation does for any controller.
/// Answers whether the server will move a pawn owned by a remote (UDP) player.
fn simple_move_to(args: &Value) -> Result<Value, String> {
    let player = args["player"].as_str().filter(|s| !s.is_empty()).ok_or("player must be a player name")?.to_owned();
    let to = position(args, "to")?;
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let controller = unsafe { player_controller_named(&player)? };
        let character = unsafe { object_field(controller, "PlayerCharacter")? };
        if character == 0 { return Err(format!("{player}'s controller has no character")); }
        // SAFETY: a live character actor.
        let location = unsafe { ueforge::ue::transform::world_location(character as *const u8) };
        let controller = controller as *const UObject as u64;
        let library = ueforge::selector::resolve("singleton:AIBlueprintHelperLibrary")?;
        // SAFETY: game thread; parameters are filled by reflected name and type.
        unsafe { ueforge::reflect::call(library, "AIBlueprintHelperLibrary", "SimpleMoveToLocation", json!({"Controller": format!("0x{controller:X}"), "Goal": {"X": to.x, "Y": to.y, "Z": to.z}}).as_object().unwrap())? };
        Ok(json!({"player": player, "controller": format!("0x{controller:X}"), "character": format!("0x{character:X}"),
            "character_location": location.map(|(x, y, z)| [x, y, z]), "goal": [to.x, to.y, to.z], "state": "move_requested"}))
    })
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new(
            "nav.find_path",
            "Path between two world points on the host's navigation mesh (research)",
            "{from: [x, y, z], to: [x, y, z]}",
            find_path,
        ),
        ueforge::ops::OpDef::new(
            "players",
            "Every player in the hosted game: name, controller, character and location",
            "{}",
            list_players,
        ),
        ueforge::ops::OpDef::new(
            "nav.simple_move_to",
            "Research: engine SimpleMoveToLocation on a named player's controller",
            "{player: str, to: [x, y, z]}",
            simple_move_to,
        ),
    ]);
}
