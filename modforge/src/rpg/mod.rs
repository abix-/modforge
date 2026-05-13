//! Engine-agnostic RPG framework.
//!
//! Both ueforge (UE5) and unityforge (Unity Mono) compose
//! per-game RPG mods on top of this. Pure math (xp curve,
//! progress) + pure shapes (state, persistence) + engine-
//! generic traits (Effect, Trigger, SlotKeyResolver) live
//! here. Engine-specific implementations of those traits
//! live in the per-framework crate.

pub mod disabled;
pub mod format;
pub mod progress;
pub mod state;
pub mod vanilla;
pub mod xp;
