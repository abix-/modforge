//! Engine-agnostic RPG framework.
//!
//! Both ueforge (UE5) and unityforge (Unity Mono) compose
//! per-game RPG mods on top of this. Pure math (xp curve,
//! progress) + pure shapes (state, persistence) + engine-
//! generic traits (Effect, Trigger, SlotKeyResolver) live
//! here. Engine-specific implementations of those traits
//! live in the per-framework crate.

pub mod disabled;
pub mod effect;
pub mod engine;
pub mod format;
pub mod poller;
pub mod progress;
pub mod skill;
pub mod state;
pub mod store;
pub mod trigger;
pub mod vanilla;
pub mod xp;

pub use effect::{Effect, EffectDef};
pub use engine::Engine;
pub use skill::{SkillDef, SkillRegistry};
pub use trigger::{ON_SLOT_CHANGE, OnSlotChangeTrigger, Trigger, TriggerCtx, TriggerDef};
