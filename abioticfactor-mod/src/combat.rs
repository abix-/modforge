//! Research: does a direct server-side attack call move the AI player's
//! weapon? Calls one of the player character's own attack functions on the
//! named player's server-side character, after turning its controller toward
//! a point. Everything is resolved through the cached lookups in nav.rs.
use serde_json::{Value, json};
use std::time::Duration;
use ueforge::ue::UObject;

/// Attack functions with no parameters, or only bools that default to false.
const ALLOWED: &[&str] = &["Try_AutoAttack", "Local_DoMeleeAttack_Event", "DetermineMeleeSwingTarget", "ForceBeginWindupAttack"];

/// Turn the controller's ControlRotation yaw toward `target` from `from`.
unsafe fn face(controller: &UObject, from: [f64; 3], target: [f64; 3]) -> Result<f64, String> {
    let offset = ueforge::input::class_property_offset(controller, "ControlRotation", 24)?;
    let yaw = (target[1] - from[1]).atan2(target[0] - from[0]).to_degrees();
    // SAFETY: FRotator is three doubles: pitch, yaw, roll; the field belongs to the live controller.
    unsafe {
        let rotation = controller.field_ptr(offset) as *mut f64;
        rotation.write_unaligned(0.0);
        rotation.add(1).write_unaligned(yaw);
        rotation.add(2).write_unaligned(0.0);
    }
    Ok(yaw)
}

fn attack(args: &Value) -> Result<Value, String> {
    let player = args["player"].as_str().filter(|s| !s.is_empty()).ok_or("player must be a player name")?.to_owned();
    let function = args["function"].as_str().unwrap_or("Try_AutoAttack").to_owned();
    if !ALLOWED.contains(&function.as_str()) { return Err(format!("function must be one of {ALLOWED:?}")); }
    let target = args["face"].as_array().filter(|v| v.len() == 3)
        .map(|v| [v[0].as_f64(), v[1].as_f64(), v[2].as_f64()]).and_then(|v| Some([v[0]?, v[1]?, v[2]?]));
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (controller, character) = unsafe { crate::nav::player_character(&player)? };
        let from = unsafe { ueforge::ue::transform::world_location(character as *const UObject as *const u8) }.ok_or("character has no location")?;
        let yaw = match target { Some(t) => Some(unsafe { face(controller, [from.0, from.1, from.2], t)? }), None => None };
        // SAFETY: zero is a valid default for every parameter of the allowed functions.
        unsafe { ueforge::ue::pe_call::call_ufunction_zeroed(character, "Abiotic_PlayerCharacter_C", &function)? };
        Ok(json!({"player": player, "function": function, "from": [from.0, from.1, from.2], "yaw": yaw, "state": "called"}))
    })
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register(ueforge::ops::OpDef::new(
        "ai_player.attack",
        "Research: call one of the character's own attack functions on the named player's server-side character, facing a point first",
        "{player: str, function?: str, face?: [x, y, z]}",
        attack,
    ));
}
