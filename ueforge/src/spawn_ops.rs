//! Spawning as data: an actor with fields set before construction, a
//! component with fields set before registration, and the bot join every
//! Unreal shooter uses (Lyra's LyraBotCreationComponent::SpawnOneBot): an AI
//! controller spawned with bWantsPlayerState so it gets a PlayerState, its
//! path following component set before possession, its PlayerState named,
//! then the game mode's own RestartPlayer, which spawns the default pawn
//! class and possesses it.
use crate::reflect;
use crate::ue::UObject;
use serde_json::{Value, json};

fn location_of(value: &Value) -> Result<(f64, f64, f64), String> {
    let list = value.as_array().filter(|v| v.len() == 3).ok_or("location must be [x, y, z]")?;
    Ok((list[0].as_f64().unwrap_or(0.0), list[1].as_f64().unwrap_or(0.0), list[2].as_f64().unwrap_or(0.0)))
}

/// Spawn an actor of a class at a location, writing `fields` between the
/// deferred begin and the finish so construction sees them. Game thread.
///
/// # Safety
/// `context` must be a live actor.
pub unsafe fn spawn_actor(context: &UObject, class: &str, location: (f64, f64, f64), yaw: f64, fields: &serde_json::Map<String, Value>) -> Result<u64, String> {
    let class_ptr = crate::ue::find_class_fast(class).ok_or_else(|| format!("class {class} not found"))?;
    let actor = unsafe { crate::ue::spawn::begin_spawn(context.as_ptr(), class_ptr as *const _ as u64, location, yaw, 1.0) };
    if actor == 0 { return Err(format!("{class} did not begin spawning")); }
    // SAFETY: an actor the engine created and has not finished.
    unsafe { reflect::set_fields(&*(actor as *const UObject), fields)? };
    if unsafe { crate::ue::spawn::finish_spawn(actor, location, yaw, 1.0) } == 0 { return Err(format!("{class} did not finish spawning")); }
    Ok(actor)
}

/// Add a component of a class to an actor, writing `fields` before the
/// engine registers it (Actor::AddComponentByClass deferred, then
/// FinishAddComponent). Game thread.
///
/// # Safety
/// `actor` must be live.
pub unsafe fn add_component(actor: &UObject, class: &str, fields: &serde_json::Map<String, Value>) -> Result<u64, String> {
    let reply = unsafe { reflect::call(actor, "Actor", "AddComponentByClass", json!({"Class": format!("class:{class}"), "bManualAttachment": false, "bDeferredFinish": true}).as_object().unwrap())? };
    let component = reply["ReturnValue"]["addr"].as_str().and_then(|a| u64::from_str_radix(a.trim_start_matches("0x"), 16).ok()).unwrap_or(0);
    if component == 0 { return Err(format!("AddComponentByClass returned null for {class}")); }
    // SAFETY: the component the engine just created, not yet registered.
    unsafe { reflect::set_fields(&*(component as *const UObject), fields)? };
    unsafe { reflect::call(actor, "Actor", "FinishAddComponent", json!({"Component": format!("0x{component:X}"), "bManualAttachment": false}).as_object().unwrap())? };
    Ok(component)
}

/// The bot join. Returns the controller, its PlayerState and its pawn. Game thread.
///
/// # Safety
/// `context` must be a live actor in the world the bot joins.
pub unsafe fn join_ai_player(context: &UObject, controller_class: &str, location: (f64, f64, f64), name: &str) -> Result<(u64, u64, u64), String> {
    // bWantsPlayerState before PostInitializeComponents, where AAIController creates its PlayerState.
    let controller = unsafe { spawn_actor(context, controller_class, location, 0.0, json!({"bWantsPlayerState": true}).as_object().unwrap())? };
    // SAFETY: the controller the engine just finished.
    let controller_object = unsafe { &*(controller as *const UObject) };
    // A Blueprint controller's defaults may leave PathFollowingComponent null even
    // though its class carries the subobject, and OnPossess initializes the
    // component only when the pointer is set; so set it before possession.
    let following = unsafe { reflect::call(controller_object, "Actor", "GetComponentByClass", json!({"ComponentClass": "class:PathFollowingComponent"}).as_object().unwrap())? };
    let following = following["ReturnValue"]["addr"].as_str().and_then(|a| u64::from_str_radix(a.trim_start_matches("0x"), 16).ok()).unwrap_or(0);
    if following != 0 {
        unsafe { reflect::call(controller_object, "AIController", "SetPathFollowingComponent", json!({"NewPFComponent": format!("0x{following:X}")}).as_object().unwrap())? };
    }
    let player_state = unsafe { reflect::get_fields(controller_object, &["PlayerState".into()])? }["PlayerState"]["addr"].as_str().and_then(|a| u64::from_str_radix(a.trim_start_matches("0x"), 16).ok()).unwrap_or(0);
    if player_state == 0 { return Err("the AI controller got no PlayerState".into()); }
    // SAFETY: the PlayerState the controller just created.
    unsafe { reflect::set_fields(&*(player_state as *const UObject), json!({"PlayerNamePrivate": name}).as_object().unwrap())? };
    let statics = crate::selector::resolve("singleton:GameplayStatics")?;
    let game_mode = unsafe { reflect::call(statics, "GameplayStatics", "GetGameMode", json!({"WorldContextObject": format!("0x{:X}", context.as_ptr() as u64)}).as_object().unwrap())? };
    let game_mode = game_mode["ReturnValue"]["addr"].as_str().and_then(|a| u64::from_str_radix(a.trim_start_matches("0x"), 16).ok()).unwrap_or(0);
    if game_mode == 0 { return Err("GetGameMode returned null".into()); }
    // SAFETY: the live game mode.
    unsafe { reflect::call(&*(game_mode as *const UObject), "GameModeBase", "RestartPlayer", json!({"NewPlayer": format!("0x{controller:X}")}).as_object().unwrap())? };
    let pawn = unsafe { reflect::get_fields(controller_object, &["Pawn".into()])? }["Pawn"]["addr"].as_str().and_then(|a| u64::from_str_radix(a.trim_start_matches("0x"), 16).ok()).unwrap_or(0);
    if pawn == 0 { return Err("RestartPlayer gave the controller no pawn".into()); }
    Ok((controller, player_state, pawn))
}

pub fn register_ops(drain: &'static crate::pe_queue::GameThread, hint: &'static str) {
    use crate::ops::{OP_REGISTRY, OpDef};
    let job = move |timeout: u64, f: Box<dyn FnOnce() -> Result<Value, String> + Send>| -> Result<Value, String> {
        crate::debug::enqueue_pe(drain, std::time::Duration::from_secs(timeout), hint, f)
    };
    OP_REGISTRY.register_many([
        OpDef::new("actor.spawn", "Spawn an actor of a class at a location, with fields written before construction (deferred spawn); context is any live actor in the world", "{class: str, context: selector, location: [x, y, z], yaw?: f64, fields?: {name: value}}", move |args| {
            let class = args["class"].as_str().ok_or("class is required")?.to_owned();
            let context = args["context"].as_str().ok_or("context must be a selector")?.to_owned();
            let location = location_of(&args["location"])?;
            let yaw = args["yaw"].as_f64().unwrap_or(0.0);
            let fields = args["fields"].as_object().cloned().unwrap_or_default();
            job(30, Box::new(move || { let context = crate::selector::resolve(&context)?; let actor = unsafe { spawn_actor(context, &class, location, yaw, &fields)? }; Ok(json!({"addr": format!("0x{actor:X}"), "class": class})) }))
        }),
        OpDef::new("component.add", "Add a component of a class to an actor, with fields written before the engine registers it", "{actor: selector, class: str, fields?: {name: value}}", move |args| {
            let actor = args["actor"].as_str().ok_or("actor must be a selector")?.to_owned();
            let class = args["class"].as_str().ok_or("class is required")?.to_owned();
            let fields = args["fields"].as_object().cloned().unwrap_or_default();
            job(30, Box::new(move || { let actor = crate::selector::resolve(&actor)?; let component = unsafe { add_component(actor, &class, &fields)? }; Ok(json!({"addr": format!("0x{component:X}"), "class": class})) }))
        }),
        OpDef::new("player.join_ai", "Join an AI player the way Lyra spawns a bot: an AI controller with a PlayerState carrying name, path following set, then the game mode's RestartPlayer spawns and possesses the default pawn", "{controller_class: str, context: selector, location: [x, y, z], name: str}", move |args| {
            let class = args["controller_class"].as_str().ok_or("controller_class is required")?.to_owned();
            let context = args["context"].as_str().ok_or("context must be a selector")?.to_owned();
            let location = location_of(&args["location"])?;
            let name = args["name"].as_str().ok_or("name is required")?.to_owned();
            job(30, Box::new(move || {
                let context = crate::selector::resolve(&context)?;
                let (controller, player_state, pawn) = unsafe { join_ai_player(context, &class, location, &name)? };
                Ok(json!({"controller": format!("0x{controller:X}"), "player_state": format!("0x{player_state:X}"), "pawn": format!("0x{pawn:X}"), "name": name}))
            }))
        }),
    ]);
}
