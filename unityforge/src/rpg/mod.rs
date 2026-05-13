//! Unity-side RPG framework. Plugs the modforge engine-generic
//! traits into the Unity runtime via the bridge.
//!
//! Type aliases here pin `modforge::rpg`'s engine type
//! parameter to [`UnityEngine`] so catalog rows don't have to
//! name it.

pub mod engine;
pub mod skill;
pub mod slot_key;
pub mod std_effect;
pub mod tracker;

pub use engine::{UnityEngine, UnityEvent};
pub use skill::{SkillDef, SkillRegistry};
pub use slot_key::UnitySlotKey;
pub use std_effect::{
    UnityFieldAdditiveEffect, UnityFieldMultiplyEffect, UnityMethodInvokeEffect,
};
pub use tracker::Tracker;
