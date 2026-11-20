//! Use-based skills (topside todo 31; authority.md "RPG": crafting,
//! combat, medicine, construction, research, improved with practice; the
//! player and NPCs one path). Doing a thing gives its skill experience;
//! the level comes from the experience by modforge rpg's curve, and what
//! a level is worth by rpg's diminishing returns (sqrt progress). Skyrim
//! and Kenshi level skills by use the same way. Engine-free.

use std::collections::BTreeMap;

use serde::{Deserialize, Serialize};

use crate::rpg::progress::sqrt_progress;
use crate::rpg::xp::Curve;

/// The curve every skill climbs: Claude's numbers, for the operator to
/// change (rpg's default shape, 20 xp to the first level, 100 levels).
pub const CURVE: Curve = Curve::new(20.0, 1.8, 100);

/// One person's skills: each skill's experience.
#[derive(Clone, Debug, Default, PartialEq, Serialize, Deserialize)]
pub struct Skills {
    pub xp: BTreeMap<String, u64>,
}

impl Skills {
    /// Practise a skill.
    pub fn practise(&mut self, skill: &str, xp: u64) {
        *self.xp.entry(skill.to_string()).or_default() += xp;
    }

    /// A skill's level, 1 untrained.
    pub fn level(&self, skill: &str) -> u32 {
        CURVE.level_for_xp(self.xp.get(skill).copied().unwrap_or(0))
    }

    /// How far toward mastery a skill is, 0 to 1, diminishing.
    pub fn mastery(&self, skill: &str) -> f32 {
        sqrt_progress(self.level(skill) - 1, CURVE.max_level - 1)
    }
}

/// Quality odds leaned by skill: each better tier's weight grows with
/// mastery, up to `lean` times (Claude's rule), the worst tier kept.
pub fn lean_odds(odds: &[u64], mastery: f32, lean: f32) -> Vec<u64> {
    odds.iter()
        .enumerate()
        .map(|(tier, weight)| if tier == 0 { *weight } else { (*weight as f32 * (1.0 + mastery * lean * tier as f32)).round() as u64 })
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn use_raises_a_skill_and_better_skill_does_better() {
        let mut skills = Skills::default();
        assert_eq!(skills.level("crafting"), 1);
        assert_eq!(skills.mastery("crafting"), 0.0);
        skills.practise("crafting", 2_000);
        assert!(skills.level("crafting") > 1);
        assert!(skills.mastery("crafting") > 0.0);
        let odds = [100, 10, 1];
        let leaned = lean_odds(&odds, skills.mastery("crafting"), 2.0);
        assert_eq!(leaned[0], 100);
        assert!(leaned[2] > odds[2] || leaned[1] > odds[1]);
    }
}
