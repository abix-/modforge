//! Research: does a direct server-side attack call move the AI player's
//! weapon? Calls one of the player character's own attack functions on the
//! named player's character, after turning its controller toward a point.
//! Every call goes through ueforge's generic call by name; every read is a
//! field by name.
use serde_json::{Value, json};
use std::time::Duration;
use ueforge::ue::UObject;

/// Attack functions with no parameters, or only bools that default to false.
const ALLOWED: &[&str] = &["Try_AutoAttack", "Local_DoMeleeAttack_Event", "DetermineMeleeSwingTarget", "ForceBeginWindupAttack"];

/// Turn the controller's ControlRotation yaw toward `target` from `from`.
unsafe fn face(controller: &UObject, from: [f64; 3], target: [f64; 3]) -> Result<f64, String> {
    let yaw = (target[1] - from[1]).atan2(target[0] - from[0]).to_degrees();
    unsafe { ueforge::reflect::set_fields(controller, json!({"ControlRotation": {"Pitch": 0.0, "Yaw": yaw, "Roll": 0.0}}).as_object().unwrap())? };
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
        // Zero is a valid default for every parameter of the allowed functions.
        unsafe { ueforge::reflect::call(character, "Abiotic_PlayerCharacter_C", &function, &serde_json::Map::new())? };
        Ok(json!({"player": player, "function": function, "from": [from.0, from.1, from.2], "yaw": yaw, "state": "called"}))
    })
}

/// Research: the melee request the real client sends, Request_MeleeAttackDamage,
/// called on her character with a hit result the engine itself produced: a
/// line trace from her character toward the target. Reads the target's
/// TotalCombinedHealth before and after.
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
        let health = |o: &UObject| unsafe { ueforge::reflect::get_fields(o, &["TotalCombinedHealth".into()]) }.map(|f| f["TotalCombinedHealth"].clone()).unwrap_or(Value::Null);
        let before = health(enemy);
        // The engine's own trace fills the hit result, weak references included.
        let system = ueforge::selector::resolve("singleton:KismetSystemLibrary")?;
        let trace = unsafe { ueforge::reflect::call(system, "KismetSystemLibrary", "LineTraceSingle", json!({
            "WorldContextObject": format!("0x{:X}", character as *const UObject as u64),
            "Start": {"X": from.0, "Y": from.1, "Z": from.2}, "End": {"X": to.0, "Y": to.1, "Z": to.2},
            "TraceChannel": ueforge::ue::trace::CHANNEL_VISIBILITY, "bIgnoreSelf": true}).as_object().unwrap())? };
        let blocked = trace["ReturnValue"] == true;
        // Request_MeleeAttackDamage(Hit, Unarmed, DamageMultiplier, ForceDurabilityLoss, Offhand), layout read live 2026-09-13.
        unsafe { ueforge::reflect::call(character, "Abiotic_PlayerCharacter_C", "Request_MeleeAttackDamage",
            json!({"Hit": trace["OutHit"], "Unarmed": true, "DamageMultiplier": 1.0, "ForceDurabilityLoss": false, "Offhand": false}).as_object().unwrap())? };
        let after = health(enemy);
        Ok(json!({"player": player, "target": enemy.name(), "yaw": yaw, "trace_blocked": blocked, "damage_argument": args_damage, "health_before": before, "health_after": after, "state": "requested"}))
    })
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new(
            "ai_player.attack",
            "Research: call one of the character's own attack functions on the named player's character, facing a point first",
            "{player: str, function?: str, face?: [x, y, z]}",
            attack,
        ),
        ueforge::ops::OpDef::new(
            "ai_player.melee",
            "Research: the real client's melee request on her character with an engine line-trace hit on the target; reports the target's health before and after",
            "{player: str, target: str, damage?: f64}",
            melee,
        ),
    ]);
}
