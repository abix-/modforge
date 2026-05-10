// `GameApplier` -- the bbp impl of `ueforge::rpg::RpgApplier`.
// Wraps the settings the apply path needs and dispatches each
// SkillEffect variant to the existing `apply::apply_skill` and
// `skills::format_effect`.
//
// Owned by the static `Tracker<GameApplier>`; constructed at slot
// activation with the freshly loaded settings.

use ueforge::rpg::{RpgApplier, Skill, SkillsState};

use crate::rpg::skills::{self, SkillEffect};
use crate::settings::Settings;

pub struct GameApplier {
    pub settings: Settings,
}

impl RpgApplier for GameApplier {
    type Effect = SkillEffect;

    fn apply_skill(&self, state: &SkillsState, skill: &Skill<SkillEffect>) {
        crate::rpg::apply::apply_one(state, &self.settings, skill.id);
    }

    fn format_effect(&self, skill: &Skill<SkillEffect>, level: u32) -> String {
        skills::format_effect(skill.id, level)
    }
}
