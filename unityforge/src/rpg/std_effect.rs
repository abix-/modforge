//! Standard Unity Effect implementations.
//!
//! Three shapes cover the bulk of Unity RPG skills:
//!
//! - [`UnityFieldAdditiveEffect`]. Capture vanilla on first
//!   apply; write `vanilla + max_bonus * progress`. Use for
//!   stacking-style fields (max health, carry capacity).
//! - [`UnityFieldMultiplyEffect`]. Capture vanilla; write
//!   `vanilla * (1 + max_bonus * progress)`. Use for
//!   multiplicative buffs (damage, speed, drop value).
//! - [`UnityMethodInvokeEffect`]. Fire a method on slot
//!   change. Use when the effect is "tell the game to recompute
//!   X" (e.g. UI refresh, recalculate stats).
//!
//! Each calls through the runtime-tagged bridge so the same
//! struct works on Mono and IL2CPP without recompilation; the
//! active shim populates the bridge entries.
//!
//! All three cache the resolved `MonoType` (lazy `OnceLock`)
//! so the hot path is one bridge call to fetch the singleton
//! instance + the field/method op, not a full type lookup.

use std::sync::OnceLock;

use modforge::rpg::{Effect, TriggerCtx, vanilla::VanillaCache};
use modforge::rpg::progress::sqrt_progress;
use modforge::rpg::format;
use serde_json::json;

use crate::mono::MonoType;
use crate::rpg::engine::UnityEngine;

/// `vanilla + max_bonus * progress` on a singleton field.
///
/// Captures the engine's first-seen value into `vanilla` and
/// writes from that baseline thereafter, so toggling /
/// refunding restores the true engine value, not whatever the
/// mod last wrote.
pub struct UnityFieldAdditiveEffect {
    pub class_name: &'static str,
    pub field_name: &'static str,
    pub max_bonus: f32,
    pub format_word: &'static str,
    pub vanilla: &'static VanillaCache<&'static str, f32>,
    pub type_cache: OnceLock<MonoType>,
}

impl UnityFieldAdditiveEffect {
    pub const fn new(
        class_name: &'static str,
        field_name: &'static str,
        max_bonus: f32,
        format_word: &'static str,
        vanilla: &'static VanillaCache<&'static str, f32>,
    ) -> Self {
        Self {
            class_name,
            field_name,
            max_bonus,
            format_word,
            vanilla,
            type_cache: OnceLock::new(),
        }
    }
}

impl Effect<UnityEngine> for UnityFieldAdditiveEffect {
    fn apply(&self, level: u32, max_level: u32, _ctx: &TriggerCtx<'_, UnityEngine>) {
        let progress = sqrt_progress(level, max_level);
        let ty = match self.type_cache.get() {
            Some(t) => t,
            None => {
                let Some(t) = MonoType::find(self.class_name) else {
                    return;
                };
                self.type_cache.get_or_init(|| t)
            }
        };
        let Some(obj) = ty.singleton_instance() else {
            return;
        };
        let cur = match obj.read_field(self.field_name).ok().and_then(|v| v.as_f64()) {
            Some(v) => v as f32,
            None => return,
        };
        let baseline = if cur.is_finite() && cur != 0.0 {
            self.vanilla.get_or_init(self.field_name, cur)
        } else {
            self.vanilla.get(self.field_name).unwrap_or(cur)
        };
        let target = baseline + self.max_bonus * progress;
        let _ = obj.write_field(self.field_name, &json!(target));
    }

    fn format(&self, level: u32, max_level: u32) -> String {
        format::format_additive_f32_as_int(
            self.max_bonus,
            level,
            max_level,
            self.format_word,
        )
    }
}

/// `vanilla * (1 + max_bonus * progress)` on a singleton field.
pub struct UnityFieldMultiplyEffect {
    pub class_name: &'static str,
    pub field_name: &'static str,
    pub max_bonus: f32,
    pub format_word: &'static str,
    pub vanilla: &'static VanillaCache<&'static str, f32>,
    pub type_cache: OnceLock<MonoType>,
}

impl UnityFieldMultiplyEffect {
    pub const fn new(
        class_name: &'static str,
        field_name: &'static str,
        max_bonus: f32,
        format_word: &'static str,
        vanilla: &'static VanillaCache<&'static str, f32>,
    ) -> Self {
        Self {
            class_name,
            field_name,
            max_bonus,
            format_word,
            vanilla,
            type_cache: OnceLock::new(),
        }
    }
}

impl Effect<UnityEngine> for UnityFieldMultiplyEffect {
    fn apply(&self, level: u32, max_level: u32, _ctx: &TriggerCtx<'_, UnityEngine>) {
        let progress = sqrt_progress(level, max_level);
        let mult = 1.0 + self.max_bonus * progress;
        let ty = match self.type_cache.get() {
            Some(t) => t,
            None => {
                let Some(t) = MonoType::find(self.class_name) else {
                    return;
                };
                self.type_cache.get_or_init(|| t)
            }
        };
        let Some(obj) = ty.singleton_instance() else {
            return;
        };
        let cur = match obj.read_field(self.field_name).ok().and_then(|v| v.as_f64()) {
            Some(v) => v as f32,
            None => return,
        };
        let baseline = if cur.is_finite() && cur != 0.0 {
            self.vanilla.get_or_init(self.field_name, cur)
        } else {
            self.vanilla.get(self.field_name).unwrap_or(cur)
        };
        let target = baseline * mult;
        let _ = obj.write_field(self.field_name, &json!(target));
    }

    fn format(&self, level: u32, max_level: u32) -> String {
        format::format_multiplier(self.max_bonus, level, max_level, self.format_word)
    }
}

/// Invoke a parameterless method on a singleton on slot change.
/// Use when the engine has a "recompute X" function the effect
/// just needs to tell to run.
pub struct UnityMethodInvokeEffect {
    pub class_name: &'static str,
    pub method_name: &'static str,
    pub format_text: &'static str,
    pub type_cache: OnceLock<MonoType>,
}

impl UnityMethodInvokeEffect {
    pub const fn new(
        class_name: &'static str,
        method_name: &'static str,
        format_text: &'static str,
    ) -> Self {
        Self {
            class_name,
            method_name,
            format_text,
            type_cache: OnceLock::new(),
        }
    }
}

impl Effect<UnityEngine> for UnityMethodInvokeEffect {
    fn apply(&self, _level: u32, _max_level: u32, _ctx: &TriggerCtx<'_, UnityEngine>) {
        let ty = match self.type_cache.get() {
            Some(t) => t,
            None => {
                let Some(t) = MonoType::find(self.class_name) else {
                    return;
                };
                self.type_cache.get_or_init(|| t)
            }
        };
        let Some(obj) = ty.singleton_instance() else {
            return;
        };
        let _ = obj.invoke(self.method_name, &json!([]));
    }

    fn format(&self, _level: u32, _max_level: u32) -> String {
        self.format_text.to_string()
    }
}
