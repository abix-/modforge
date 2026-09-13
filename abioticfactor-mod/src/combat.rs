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

/// Research: the melee request the real client sends, Request_MeleeAttackDamage,
/// called on her server-side character with a hit result the engine itself
/// produced: a line trace from her character toward the target. Reads the
/// target's TotalCombinedHealth before and after. Answers whether the server
/// damages an enemy from such a hit at all, before the same request is
/// encoded over UDP.
fn melee(args: &Value) -> Result<Value, String> {
    let player = args["player"].as_str().filter(|s| !s.is_empty()).ok_or("player must be a player name")?.to_owned();
    let target = args["target"].as_str().filter(|s| !s.is_empty()).ok_or("target must be the enemy's address from ai_player.perceived")?.to_owned();
    // Exor melee damage from DT_NPCList (npc-ai.md) unless given.
    let args_damage = args["damage"].as_f64().unwrap_or(70.0);
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(10), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (controller, character) = unsafe { crate::nav::player_character(&player)? };
        let enemy = ueforge::selector::resolve(&format!("addr:{target}"))?;
        let from = unsafe { ueforge::ue::transform::world_location(character as *const UObject as *const u8) }.ok_or("character has no location")?;
        let to = unsafe { ueforge::ue::transform::world_location(enemy as *const UObject as *const u8) }.ok_or("target has no location")?;
        let yaw = unsafe { face(controller, [from.0, from.1, from.2], [to.0, to.1, to.2])? };
        let health_offset = ueforge::input::class_property_offset(enemy, "TotalCombinedHealth", 8)?;
        // SAFETY: a reflected double on the live enemy.
        let before = unsafe { (enemy.field_ptr(health_offset) as *const f64).read_unaligned() };
        // The engine's own trace fills the hit result, weak references included.
        let mut start = [0u8; 24];
        let mut end = [0u8; 24];
        for (i, v) in [from.0, from.1, from.2].iter().enumerate() { start[i * 8..][..8].copy_from_slice(&v.to_le_bytes()); }
        for (i, v) in [to.0, to.1, to.2].iter().enumerate() { end[i * 8..][..8].copy_from_slice(&v.to_le_bytes()); }
        let context = (character as *const UObject as u64).to_le_bytes();
        let (parms, ret) = unsafe { crate::host::call_static("KismetSystemLibrary", "LineTraceSingle",
            &[("WorldContextObject", &context), ("Start", &start), ("End", &end), ("TraceChannel", &[ueforge::ue::trace::CHANNEL_VISIBILITY]), ("bIgnoreSelf", &[1])])? };
        let blocked = parms[ret] != 0;
        let hit = parms[ueforge::ue::trace::offsets::OUT_HIT..ueforge::ue::trace::offsets::OUT_HIT + 248].to_vec();
        // Request_MeleeAttackDamage(Hit, Unarmed, DamageMultiplier, ForceDurabilityLoss, Offhand), layout read live 2026-09-13.
        let multiplier = 1.0f64.to_le_bytes();
        unsafe { crate::perception::call_named(character, "Abiotic_PlayerCharacter_C", "Request_MeleeAttackDamage",
            &[("Hit", &hit), ("Unarmed", &[1]), ("DamageMultiplier", &multiplier), ("ForceDurabilityLoss", &[0]), ("Offhand", &[0])])? };
        let after = unsafe { (enemy.field_ptr(health_offset) as *const f64).read_unaligned() };
        Ok(json!({"player": player, "target": enemy.name(), "yaw": yaw, "trace_blocked": blocked, "health_before": before, "health_after": after, "state": "requested"}))
    })
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new(
            "ai_player.attack",
            "Research: call one of the character's own attack functions on the named player's server-side character, facing a point first",
            "{player: str, function?: str, face?: [x, y, z]}",
            attack,
        ),
        ueforge::ops::OpDef::new(
            "ai_player.melee",
            "Research: the real client's melee request on her server-side character with an engine line-trace hit on the target; reports the target's health before and after",
            "{player: str, target: str}",
            melee,
        ),
    ]);
}
