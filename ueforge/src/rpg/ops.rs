//! Generic RPG op handlers for the `/debug` HTTP endpoint.
//!
//! Every RPG mod's `/debug` dispatcher needs the same five
//! arms: `skill_toggle`, `skill_spend`, `skill_refund`,
//! `reload_slot`, `set_skill_points`. Game crates register all
//! five into [`crate::ops::OP_REGISTRY`] in one call:
//!
//! ```ignore
//! ueforge::rpg::ops::register(&TRACKER);
//! ```
//!
//! After that, `OP_REGISTRY.dispatch(op, args)` covers them
//! alongside every other registered op.

use serde_json::Value as Json;

use crate::args::{arg_bool, arg_str, arg_u64};
use crate::ops::{OP_REGISTRY, OpDef};
use super::Tracker;

/// Register the standard RPG op set against the workspace
/// [`OP_REGISTRY`] with the game's static `Tracker` captured.
/// Call once at worker init.
///
/// Registers: `skill_toggle`, `skill_spend`, `skill_refund`,
/// `reload_slot`, `set_skill_points`.
pub fn register(tracker: &'static Tracker) {
    OP_REGISTRY.register_many([
        OpDef::new(
            "skill_toggle",
            "Enable / disable a skill without changing its level",
            "{id: str, enabled: bool}",
            move |args| skill_toggle(tracker, args),
        ),
        OpDef::new(
            "skill_spend",
            "Spend N skill points on a skill",
            "{id: str, count?: u32}",
            move |args| skill_spend(tracker, args),
        ),
        OpDef::new(
            "skill_refund",
            "Refund N points from a skill",
            "{id: str, count?: u32}",
            move |args| skill_refund(tracker, args),
        ),
        OpDef::new(
            "reload_slot",
            "Re-apply every catalog skill against current state",
            "{}",
            move |_args| reload_slot(tracker),
        ),
        OpDef::new(
            "set_skill_points",
            "Grant N unspent skill points (debug)",
            "{count: u64}",
            move |args| set_skill_points(tracker, args),
        ),
    ]);
}

/// `op: "skill_toggle"`, `args: { id, enabled }`. Flips the
/// disabled-skills set and re-applies the skill so the change
/// is immediate. Returns `{ id, enabled }` reflecting the
/// post-toggle state.
pub fn skill_toggle(tracker: &Tracker, args: &Json) -> Result<Json, String> {
    let id = arg_str(args, "id")?;
    let enabled = arg_bool(args, "enabled")?;
    let skill = tracker
        .catalog()
        .def(id)
        .ok_or_else(|| format!("unknown skill '{id}'"))?;
    let now_disabled = tracker.disabled_skills().set(skill.id, !enabled);
    tracker.reapply_one(skill.id);
    Ok(serde_json::json!({"id": id, "enabled": !now_disabled}))
}

/// `op: "skill_spend"`, `args: { id, count }`. `count`
/// defaults to 1. Returns `{ id, requested, spent }`.
pub fn skill_spend(tracker: &Tracker, args: &Json) -> Result<Json, String> {
    let id = arg_str(args, "id")?;
    let count = arg_u64(args, "count", Some(1))?;
    let count = u32::try_from(count).map_err(|_| format!("count {count} > u32::MAX"))?;
    if tracker.catalog().def(id).is_none() {
        return Err(format!("unknown skill '{id}'"));
    }
    let spent = tracker.spend_skill_points(id, count);
    Ok(serde_json::json!({"id": id, "requested": count, "spent": spent}))
}

/// `op: "skill_refund"`, `args: { id, count }`. `count`
/// defaults to 1. Returns `{ id, requested, refunded }`.
pub fn skill_refund(tracker: &Tracker, args: &Json) -> Result<Json, String> {
    let id = arg_str(args, "id")?;
    let count = arg_u64(args, "count", Some(1))?;
    let count = u32::try_from(count).map_err(|_| format!("count {count} > u32::MAX"))?;
    if tracker.catalog().def(id).is_none() {
        return Err(format!("unknown skill '{id}'"));
    }
    let refunded = tracker.refund_skill_points(id, count);
    Ok(serde_json::json!({"id": id, "requested": count, "refunded": refunded}))
}

/// `op: "reload_slot"`. Re-applies every catalog skill against
/// the current state.
pub fn reload_slot(tracker: &Tracker) -> Result<Json, String> {
    if tracker.reapply_all() {
        Ok(serde_json::json!({"reapplied": true}))
    } else {
        Err("no slot active; cannot reload".into())
    }
}

/// `op: "set_skill_points"`, `args: { count }`. Grants `count`
/// skill points without earning them. For dev / testing.
pub fn set_skill_points(tracker: &Tracker, args: &Json) -> Result<Json, String> {
    let count = arg_u64(args, "count", None)?;
    let count = u32::try_from(count).map_err(|_| format!("count {count} > u32::MAX"))?;
    if !tracker.debug_grant_skill_points(count) {
        return Err("no slot active".into());
    }
    Ok(serde_json::json!({"granted": count}))
}

/// The set of op names this module handles. Useful for
/// dispatchers that want to advertise their full op list.
pub const OP_NAMES: &[&str] = &[
    "skill_toggle",
    "skill_spend",
    "skill_refund",
    "reload_slot",
    "set_skill_points",
];
