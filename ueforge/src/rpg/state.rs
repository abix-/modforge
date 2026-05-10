//! `SkillsState` -- the persisted shape every RPG mod needs:
//! cumulative XP, current level, unspent skill points, and a
//! `skill_id -> level` map. Open-shape `BTreeMap<String, u32>` so
//! games can add skills without breaking existing save files.
//!
//! Games that want extra fields (kill counters, diagnostic strings,
//! per-slot achievements) wrap this in their own struct rather than
//! extending it; [`SlotStore`](super::store::SlotStore) is generic
//! over the persisted struct.

use std::collections::BTreeMap;

use serde::{Deserialize, Serialize};

#[derive(Debug, Clone, Default, Serialize, Deserialize)]
pub struct SkillsState {
    /// Cumulative XP earned. Levels are derived via [`super::Curve`].
    #[serde(default)]
    pub xp: u64,
    /// Highest level granted. Stored separately from `xp` so a curve
    /// change doesn't retroactively de-level the player.
    #[serde(default)]
    pub level: u32,
    /// Unspent skill points.
    #[serde(default)]
    pub skill_points: u32,
    /// Per-skill levels. Skill IDs are stable strings (use the same
    /// constants you use for catalog rows + ImGui labels).
    #[serde(default)]
    pub skill_levels: BTreeMap<String, u32>,
}

impl SkillsState {
    /// Current level for a given skill id; 0 if never spent.
    pub fn level_of(&self, skill_id: &str) -> u32 {
        self.skill_levels.get(skill_id).copied().unwrap_or(0)
    }
}

// Mutation goes through `Tracker<A>` (`spend_skill_points`,
// `refund_skill_points`, `record_xp`, `debug_grant_skill_points`).
// Tracker mutates the in-memory state and immediately calls
// `store.save` under the same lock, so spend/refund are
// transactional with persistence.
//
// We deliberately do NOT expose `pub fn spend` / `pub fn refund`
// on SkillsState. An in-memory-only mutator is a trapdoor: the
// caller could forget to persist and a crash mid-session loses
// the change. If you want to spend/refund, go through the
// Tracker.
