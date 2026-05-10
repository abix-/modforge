//! Generic debug-endpoint scaffolding for UE4SS Rust mods.
//!
//! Every mod in this workspace exposes a `POST /debug` HTTP endpoint
//! routing op-dispatch JSON. The framework supplies all the
//! universal pieces -- op routing for the standard catalog, snapshot
//! view types, op-list metadata. Game crates supply the game-
//! specific simulate_* ops + the snapshot data that requires UE
//! class layout knowledge.
//!
//! ```ignore
//! use ueforge::debug::{StandardOps, dispatch_standard};
//!
//! fn handle(body: &str) -> OpResponse {
//!     let (op, args) = parse_request(body)?;
//!     // 1. Try the standard catalog (snapshot/skill_*/reload_slot/
//!     //    set_skill_points/call/read_bytes/write_bytes/walk_class/
//!     //    class_outer_samples/sample_thread_modules).
//!     if let Some(r) = dispatch_standard(&op, &args, &TRACKER,
//!         &DISABLED, &PE_QUEUE, resolve_instance) {
//!         return to_response(&op, r);
//!     }
//!     // 2. Game-specific ops.
//!     match op.as_str() {
//!         "simulate_add_health" => to_response(&op, op_add_health(&args)),
//!         _ => error_response(&op, "unknown op"),
//!     }
//! }
//! ```

use serde::Serialize;

use crate::rpg::{Skill, SkillsState};

/// Universal player-state view for the debug snapshot. Serde-
/// friendly mapping of `SkillsState` fields. `skill_levels` is a
/// JSON object so per-skill-id lookups in tests don't require a
/// linear scan.
#[derive(Serialize)]
pub struct PlayerStateView {
    pub xp: u64,
    pub level: u32,
    pub skill_points: u32,
    pub skill_levels: serde_json::Map<String, serde_json::Value>,
}

impl PlayerStateView {
    /// Build a view from a `SkillsState`. Allocates one
    /// `serde_json::Map` for the skill-levels field.
    pub fn from_state(s: &SkillsState) -> Self {
        let mut skill_levels = serde_json::Map::new();
        for (id, lv) in &s.skill_levels {
            skill_levels.insert(id.clone(), serde_json::Value::Number((*lv).into()));
        }
        PlayerStateView {
            xp: s.xp,
            level: s.level,
            skill_points: s.skill_points,
            skill_levels,
        }
    }
}

/// One row in a serializable catalog view. `effect_kind` is a
/// game-supplied identifier (typically the SkillEffect variant
/// name) so test assertions key off catalog rows without coupling
/// to the live enum layout.
#[derive(Serialize)]
pub struct CatalogEntry {
    pub id: &'static str,
    pub display_name: &'static str,
    pub max_level: u32,
    pub effect_kind: &'static str,
}

/// Map a game's `[Skill<E>]` slice into a serializable
/// `Vec<CatalogEntry>`. The `kind_fn` callback produces the
/// effect-kind string per row (game-specific match on the enum).
///
/// ```ignore
/// let view = ueforge::debug::catalog_view(skills::CATALOG, |e| match e {
///     SkillEffect::Standard(_) => "Standard",
///     SkillEffect::BackpackSlots { .. } => "BackpackSlots",
///     // ...
/// });
/// ```
pub fn catalog_view<E>(
    catalog: &'static [Skill<E>],
    kind_fn: impl Fn(&E) -> &'static str,
) -> Vec<CatalogEntry> {
    catalog
        .iter()
        .map(|s| CatalogEntry {
            id: s.id,
            display_name: s.display_name,
            max_level: s.max_level,
            effect_kind: kind_fn(&s.effect),
        })
        .collect()
}

/// The list of op names this framework's standard dispatcher
/// handles. Game crates extend with their own simulate_* ops and
/// concatenate the lists for the "supported ops" error message.
pub const STANDARD_OPS: &[&str] = &[
    "snapshot",
    "skill_toggle",
    "skill_spend",
    "skill_refund",
    "reload_slot",
    "set_skill_points",
    "call",
    "read_bytes",
    "write_bytes",
    "walk_class",
    "class_outer_samples",
    "sample_thread_modules",
];
