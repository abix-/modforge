//! Generic RPG ops re-exported for unityforge consumers.
//!
//! ```ignore
//! unityforge::rpg::ops::register(&TRACKER);
//! ```
//!
//! Adds `skill_toggle`, `skill_spend`, `skill_refund`,
//! `reload_slot`, `set_skill_points` to the workspace
//! [`modforge::ops::OP_REGISTRY`].

pub use modforge::rpg::ops::*;
