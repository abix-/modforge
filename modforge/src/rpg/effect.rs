//! Engine-generic Effect trait + EffectDef.
//!
//! Concrete effect implementations live in engine crates
//! (`ueforge::rpg::std_effect`, `unityforge::rpg::std_effect`).
//! Each impls `Effect<E>` for its engine type.
//!
//! ```ignore
//! // ueforge
//! pub struct PlayerFloatEffect { ... }
//! impl modforge::rpg::Effect<UeEngine> for PlayerFloatEffect {
//!     fn apply(&self, level, max, ctx: &TriggerCtx<'_, UeEngine>) { ... }
//!     fn format(&self, level, max) -> String { ... }
//! }
//! ```

use crate::rpg::engine::Engine;
use crate::rpg::trigger::TriggerCtx;

/// Per-skill behavior. Each engine's effects impl this for its
/// own [`Engine`] type. The framework holds catalog rows as
/// `&'static dyn Effect<E>` so dispatch is one indirect call
/// per fire (well below the per-frame budget for the cold
/// state-change path).
pub trait Effect<E: Engine>: Send + Sync + 'static {
    /// Apply the effect at `level`. `max_level` is the skill's
    /// configured cap (used to compute progress). `ctx` carries
    /// the engine event payload when the trigger fired.
    fn apply(&self, level: u32, max_level: u32, ctx: &TriggerCtx<'_, E>);

    /// Render the at-level effect text for the ImGui row.
    fn format(&self, level: u32, max_level: u32) -> String;
}

/// Catalog-row reference to an [`Effect`] implementation, plus
/// a kind tag for client discovery.
pub struct EffectDef<E: Engine> {
    pub kind: &'static str,
    pub imp: &'static dyn Effect<E>,
}

impl<E: Engine> EffectDef<E> {
    pub const fn new(kind: &'static str, imp: &'static dyn Effect<E>) -> Self {
        Self { kind, imp }
    }

    pub fn apply(&self, level: u32, max_level: u32, ctx: &TriggerCtx<'_, E>) {
        self.imp.apply(level, max_level, ctx);
    }

    pub fn format(&self, level: u32, max_level: u32) -> String {
        self.imp.format(level, max_level)
    }
}
