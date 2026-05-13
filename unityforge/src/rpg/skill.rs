//! Unity-side type aliases for the engine-generic catalog.

use crate::rpg::engine::UnityEngine;

pub type SkillDef = modforge::rpg::SkillDef<UnityEngine>;
pub type SkillRegistry = modforge::rpg::SkillRegistry<UnityEngine>;
