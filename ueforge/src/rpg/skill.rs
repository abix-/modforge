//! UE-side type aliases for the engine-generic skill catalog.
//!
//! The shapes (`SkillDef<E>`, `SkillRegistry<E>`) live in
//! [`modforge::rpg::skill`]. UE catalog rows use these aliases
//! so they don't have to name the engine type parameter.
//!
//! ```ignore
//! use ueforge::rpg::{EffectDef, SkillDef, SkillRegistry,
//!                    trigger::ON_SLOT_CHANGE};
//!
//! pub static CATALOG: SkillRegistry = SkillRegistry::new(&[
//!     SkillDef {
//!         id: "attack_damage",
//!         display_name: "Attack Damage",
//!         max_level: 100,
//!         effect: EffectDef::new("PlayerFloat", &ATTACK_DAMAGE_EFFECT),
//!         trigger: &ON_SLOT_CHANGE,
//!     },
//! ]);
//! ```

use crate::rpg::trigger::UeEngine;

pub type SkillDef = modforge::rpg::SkillDef<UeEngine>;
pub type SkillRegistry = modforge::rpg::SkillRegistry<UeEngine>;
