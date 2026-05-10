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

    /// Spend one point on `skill_id` if there's a point available
    /// and the skill is below `max_level`. Returns true on success.
    pub fn spend(&mut self, skill_id: &str, max_level: u32) -> bool {
        if self.skill_points == 0 {
            return false;
        }
        let cur = self.level_of(skill_id);
        if cur >= max_level {
            return false;
        }
        self.skill_levels.insert(skill_id.to_string(), cur + 1);
        self.skill_points -= 1;
        true
    }

    /// Refund one point from `skill_id`. Returns true on success.
    pub fn refund(&mut self, skill_id: &str) -> bool {
        let cur = self.level_of(skill_id);
        if cur == 0 {
            return false;
        }
        self.skill_levels.insert(skill_id.to_string(), cur - 1);
        self.skill_points += 1;
        true
    }
}
