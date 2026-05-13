//! Engine-agnostic standard Effect implementations.
//!
//! These effects are pure: `apply` does no engine writes, and
//! `format` uses only the pure helpers in [`crate::rpg::format`].
//! Both frameworks can use them unchanged via a blanket
//! `impl<E: Engine> Effect<E>`.

use crate::rpg::effect::Effect;
use crate::rpg::engine::Engine;
use crate::rpg::format::{PercentFormat, format_pct};
use crate::rpg::trigger::TriggerCtx;

/// No-op apply; format renders a multiplier-style string. Used
/// when the actual effect is implemented in a hot-path
/// trampoline (e.g. damage hook) that reads the skill level on
/// every fire and applies the bonus there. The catalog row
/// exists so the ImGui tab can render the right text and so
/// `list_ops` reports a stable kind.
pub struct RuntimeEffect {
    pub max_bonus: f32,
    pub format: PercentFormat,
}

impl<E: Engine> Effect<E> for RuntimeEffect {
    fn apply(&self, _level: u32, _max_level: u32, _ctx: &TriggerCtx<'_, E>) {
        // No-op. The hot-path callback owns the actual effect.
    }

    fn format(&self, level: u32, max_level: u32) -> String {
        format_pct(0.0, self.max_bonus, level, max_level, &self.format)
    }
}
