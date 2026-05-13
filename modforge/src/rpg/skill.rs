//! Engine-generic skill catalog row + registry.
//!
//! ```ignore
//! use modforge::rpg::{EffectDef, SkillDef, SkillRegistry,
//!                     trigger::ON_SLOT_CHANGE};
//! use my_framework::MyEngine;
//!
//! pub static CATALOG: SkillRegistry<MyEngine> = SkillRegistry::new(&[
//!     SkillDef {
//!         id: "attack_damage",
//!         display_name: "Attack Damage",
//!         max_level: 100,
//!         effect: EffectDef::new("PlayerFloat", &ATTACK_DAMAGE_EFFECT),
//!         trigger: &ON_SLOT_CHANGE,
//!     },
//! ]);
//! ```

use std::marker::PhantomData;

use crate::rpg::effect::EffectDef;
use crate::rpg::engine::Engine;
use crate::rpg::trigger::TriggerDef;

/// Skill catalog row. Generic over the engine because the
/// [`EffectDef`] it carries dispatches an engine-specific
/// [`crate::rpg::Effect`].
pub struct SkillDef<E: Engine> {
    pub id: &'static str,
    pub display_name: &'static str,
    pub max_level: u32,
    pub effect: EffectDef<E>,
    pub trigger: &'static TriggerDef,
}

/// Skill registry over a `'static` catalog slice.
pub struct SkillRegistry<E: Engine> {
    entries: &'static [SkillDef<E>],
    _engine: PhantomData<E>,
}

impl<E: Engine> SkillRegistry<E> {
    pub const fn new(entries: &'static [SkillDef<E>]) -> Self {
        Self {
            entries,
            _engine: PhantomData,
        }
    }

    pub fn def(&self, id: &str) -> Option<&'static SkillDef<E>> {
        self.entries.iter().find(|s| s.id == id)
    }

    pub fn entries(&self) -> &'static [SkillDef<E>] {
        self.entries
    }

    pub fn len(&self) -> usize {
        self.entries.len()
    }

    pub fn is_empty(&self) -> bool {
        self.entries.is_empty()
    }

    pub fn iter(&self) -> std::slice::Iter<'_, SkillDef<E>> {
        self.entries.iter()
    }
}

impl<'a, E: Engine> IntoIterator for &'a SkillRegistry<E> {
    type Item = &'a SkillDef<E>;
    type IntoIter = std::slice::Iter<'a, SkillDef<E>>;
    fn into_iter(self) -> Self::IntoIter {
        self.entries.iter()
    }
}
