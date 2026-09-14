//! An AI player's behavior tree: a description handed to ueforge's in-memory
//! tree builder (ueforge::behavior_tree). The default description, read
//! from the Exor's own tree on 2026-09-13 (tests/research_tree.rs):
//!
//! ```text
//! Selector
//!   RunBehavior BT_Main_Exor   [PotentialCombatTargetCount != 0, abort both ways]
//!   MoveTo <follow key>        (the human, 300 units)
//! ```
//!
//! The Exor tree's own idle branch is gated on PotentialCombatTargetCount
//! equal to 0 (BTDecorator_Blackboard, OperationType 0, IntValue 0, read
//! live); this gate is the inverse, so a sighting pulls her into the
//! Exor's whole combat tree and a cleared count drops her back to
//! following. A different tree is a different description passed to
//! `ai_player.tree` as `root`; no rebuild.
use serde_json::{Value, json};
use std::time::Duration;
use ueforge::ue::UObject;

use crate::ai_player::{object_ptr, session_controller};

/// The default description: fight with the Exor's tree, otherwise follow.
pub fn default_root(exor_tree: u64, follow_key: &str, follow_radius: f64) -> Value {
    json!({
        "class": "BTComposite_Selector",
        "children": [
            {"class": "BTTask_RunBehavior", "fields": {"BehaviorAsset": format!("0x{exor_tree:X}")},
             "decorators": [{"class": "BTDecorator_Blackboard", "fields": {
                 "BlackboardKey": {"SelectedKeyName": "PotentialCombatTargetCount"},
                 "OperationType": 1, "IntValue": 0, "NotifyObserver": 1, "FlowAbortMode": 3}}]},
            {"class": "BTTask_MoveTo", "fields": {"BlackboardKey": {"SelectedKeyName": follow_key}, "AcceptableRadius": follow_radius}}
        ]
    })
}

/// Op: build and run her tree. `root` overrides the default description;
/// `follow_key` must be an object key of the Exor blackboard (bt.keys),
/// `follow_player` the human, written into that key once the tree runs.
fn run(args: &Value) -> Result<Value, String> {
    let name = crate::ai_player::player_name(args)?;
    if crate::orders::active(&name) { return Err("AI player orders own the behavior tree".into()); }
    let follow_key = args["follow_key"].as_str().filter(|s| !s.is_empty()).unwrap_or("AllyTarget").to_owned();
    let follow_radius = args["follow_radius"].as_f64().unwrap_or(300.0);
    let follow_player = args["follow_player"].as_str().filter(|s| !s.is_empty()).map(str::to_owned);
    let root_override = args["root"].as_object().map(|o| Value::Object(o.clone()));
    ueforge::debug::enqueue_pe(&crate::DRAIN, Duration::from_secs(30), crate::DRAIN_HINT, move || {
        // SAFETY: game thread.
        let (controller, _) = unsafe { session_controller(&name)? };
        let controller_addr = controller as *const UObject as u64;
        let exor_tree = unsafe { object_ptr(controller, "BehaviorTree")? };
        if exor_tree == 0 { return Err("the controller class names no behavior tree; join with AI_Controller_NPC_Exor_C".into()); }
        // SAFETY: the live Exor tree asset.
        let blackboard = unsafe { object_ptr(&*(exor_tree as *const UObject), "BlackboardAsset")? };
        if blackboard == 0 { return Err("the Exor tree has no blackboard asset".into()); }
        let keys = unsafe { ueforge::behavior_tree::blackboard_keys(blackboard)? };
        match keys.iter().find(|(k, _)| k == &follow_key) {
            None => return Err(format!("the blackboard has no key {follow_key}; its keys are {keys:?}")),
            Some((_, key_type)) if key_type != "BlackboardKeyType_Object" => return Err(format!("{follow_key} is a {key_type} key, not an object key; MoveTo needs an actor or vector key")),
            Some(_) => {}
        }
        let root = root_override.unwrap_or_else(|| default_root(exor_tree, &follow_key, follow_radius));
        let tree = unsafe { ueforge::behavior_tree::build(controller_addr, blackboard, &root)? };
        let started = unsafe { ueforge::reflect::call(controller, "AIController", "RunBehaviorTree", json!({"BTAsset": format!("0x{tree:X}")}).as_object().unwrap())? }["ReturnValue"].as_bool().unwrap_or(false);
        let follow_actor = match follow_player.as_deref() {
            Some(player) => {
                let actor = unsafe { crate::nav::player_character(player)? }.1 as *const UObject as u64;
                unsafe { ueforge::behavior_tree::blackboard_set(controller, json!({&follow_key: format!("0x{actor:X}")}).as_object().unwrap())? };
                Some(player.to_owned())
            }
            None => None,
        };
        Ok(json!({"name": name, "tree": format!("0x{tree:X}"), "started": started, "follow_key": follow_key, "follow_player": follow_actor, "root": root}))
    })
}

pub fn register() {
    ueforge::ops::OP_REGISTRY.register_many([
        ueforge::ops::OpDef::new("ai_player.tree", "Build an AI player's behavior tree in memory (default: fight with the Exor's tree while enemies are counted, otherwise follow the actor in follow_key) and run it; root overrides the description", "{player?: str, follow_key?: str, follow_player?: str, follow_radius?: f64, root?: node}", run),
    ]);
}
