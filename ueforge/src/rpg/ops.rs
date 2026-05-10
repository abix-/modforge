//! Generic RPG op handlers for the `/debug` HTTP endpoint.
//!
//! Every RPG mod's `/debug` dispatcher needs the same five
//! arms: `skill_toggle`, `skill_spend`, `skill_refund`,
//! `reload_slot`, `set_skill_points`. The arm bodies are pure
//! glue between [`crate::args`], the consumer's
//! `Tracker<A>` + `DisabledSkills`, and a JSON result envelope
//! -- nothing game-specific. Ship them once.
//!
//! ```ignore
//! match op.as_str() {
//!     "skill_toggle"     => to_response(&op, ueforge::rpg::ops::skill_toggle(&TRACKER, &DISABLED, &args)),
//!     "skill_spend"      => to_response(&op, ueforge::rpg::ops::skill_spend(&TRACKER, &args)),
//!     "skill_refund"     => to_response(&op, ueforge::rpg::ops::skill_refund(&TRACKER, &args)),
//!     "reload_slot"      => to_response(&op, ueforge::rpg::ops::reload_slot(&TRACKER)),
//!     "set_skill_points" => to_response(&op, ueforge::rpg::ops::set_skill_points(&TRACKER, &args)),
//!     // ...
//! }
//! ```
//!
//! Game-specific ops (kill simulation, status-effect application,
//! whatever) stay in the game crate; these are the universal
//! ones.

use serde_json::Value as Json;

use crate::args::{arg_bool, arg_str, arg_u64};
use super::{DisabledSkills, RpgApplier, Tracker, find_skill};

/// `op: "skill_toggle"`, `args: { id, enabled }`. Flips the
/// disabled-skills set and re-applies the skill so the change
/// is immediate. Returns `{ id, enabled }` reflecting the
/// post-toggle state.
pub fn skill_toggle<A: RpgApplier>(
    tracker: &Tracker<A>,
    disabled: &DisabledSkills,
    args: &Json,
) -> Result<Json, String> {
    let id = arg_str(args, "id")?;
    let enabled = arg_bool(args, "enabled")?;
    let skill = find_skill(tracker.catalog(), id)
        .ok_or_else(|| format!("unknown skill '{id}'"))?;
    let now_disabled = disabled.set(skill.id, !enabled);
    tracker.reapply_one(skill.id);
    Ok(serde_json::json!({"id": id, "enabled": !now_disabled}))
}

/// `op: "skill_spend"`, `args: { id, count }`. `count`
/// defaults to 1. Returns `{ id, requested, spent }`.
pub fn skill_spend<A: RpgApplier>(
    tracker: &Tracker<A>,
    args: &Json,
) -> Result<Json, String> {
    let id = arg_str(args, "id")?;
    let count = arg_u64(args, "count", Some(1))?;
    let count = u32::try_from(count)
        .map_err(|_| format!("count {count} > u32::MAX"))?;
    if find_skill(tracker.catalog(), id).is_none() {
        return Err(format!("unknown skill '{id}'"));
    }
    let spent = tracker.spend_skill_points(id, count);
    Ok(serde_json::json!({"id": id, "requested": count, "spent": spent}))
}

/// `op: "skill_refund"`, `args: { id, count }`. `count`
/// defaults to 1. Returns `{ id, requested, refunded }`.
pub fn skill_refund<A: RpgApplier>(
    tracker: &Tracker<A>,
    args: &Json,
) -> Result<Json, String> {
    let id = arg_str(args, "id")?;
    let count = arg_u64(args, "count", Some(1))?;
    let count = u32::try_from(count)
        .map_err(|_| format!("count {count} > u32::MAX"))?;
    if find_skill(tracker.catalog(), id).is_none() {
        return Err(format!("unknown skill '{id}'"));
    }
    let refunded = tracker.refund_skill_points(id, count);
    Ok(serde_json::json!({"id": id, "requested": count, "refunded": refunded}))
}

/// `op: "reload_slot"`. Re-applies every catalog skill against
/// the current state. Returns `{ reapplied: true }` on success
/// or `Err("no slot active; cannot reload")` when no slot is
/// loaded.
pub fn reload_slot<A: RpgApplier>(tracker: &Tracker<A>) -> Result<Json, String> {
    if tracker.reapply_all() {
        Ok(serde_json::json!({"reapplied": true}))
    } else {
        Err("no slot active; cannot reload".into())
    }
}

/// `op: "set_skill_points"`, `args: { count }`. Grants `count`
/// skill points without earning them. For dev / testing.
/// Returns `{ granted }`.
pub fn set_skill_points<A: RpgApplier>(
    tracker: &Tracker<A>,
    args: &Json,
) -> Result<Json, String> {
    let count = arg_u64(args, "count", None)?;
    let count = u32::try_from(count)
        .map_err(|_| format!("count {count} > u32::MAX"))?;
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
