//! Game difficulty / drain-rate tweak framework. Pillar 3 of
//! ueforge's three opinionated UE5 mod modules (rpg / stacks /
//! difficulty).
//!
//! Most UE5 survival games expose difficulty as `f32` knobs on a
//! settings / component CDO: hunger drain, thirst drain, fall
//! damage multiplier, regen rate, etc. The universal pattern is
//! "capture vanilla per CDO, then `vanilla * multiplier` on every
//! apply, idempotently". This module wraps
//! [`ClassFieldTweak<f32>`] with that pattern so a difficulty
//! knob is one [`DifficultyKnob::new`] static + a multiplier
//! setter.
//!
//! ```ignore
//! use ueforge::difficulty::DifficultyKnob;
//!
//! pub static HUNGER: DifficultyKnob = DifficultyKnob::new(
//!     "SurvivalComponent",
//!     0x0140, // SurvivalComponent.HungerSettings.AdjustmentPerSecond
//! );
//!
//! // From `on_unreal_init`:
//! HUNGER.set_multiplier(0.5);  // half-rate hunger
//! HUNGER.apply_to_cdos();      // walks the class, writes CDOs
//!
//! // From a settings reload / tab slider:
//! HUNGER.set_multiplier(new_mult);
//! HUNGER.apply_to_cdos();
//! ```
//!
//! ### Multi-knob pattern
//!
//! For "hunger + thirst + fall damage" style multi-knob mods,
//! declare one `DifficultyKnob` per field and apply each. The
//! per-knob vanilla cache is independent so adding a knob never
//! disturbs existing ones.

use std::sync::atomic::{AtomicU32, Ordering};

use crate::ue::class_tweak::{ClassFieldTweak, ClassTweakStats};
use crate::ue::UObject;

/// One difficulty knob: a class+offset CDO field tweak with an
/// atomic f32 multiplier.
///
/// `apply_to_cdos` writes `vanilla * multiplier` to every CDO of
/// the configured class. `apply_to_all` writes to every instance
/// (CDOs + live), useful for fields the engine reads from live
/// instances rather than the CDO.
pub struct DifficultyKnob {
    inner: ClassFieldTweak<f32>,
    multiplier_bits: AtomicU32, // f32 bits
}

impl DifficultyKnob {
    pub const fn new(class_name: &'static str, field_offset: usize) -> Self {
        Self {
            inner: ClassFieldTweak::new(class_name, field_offset),
            multiplier_bits: AtomicU32::new(0x3F800000), // 1.0_f32
        }
    }

    pub fn multiplier(&self) -> f32 {
        f32::from_bits(self.multiplier_bits.load(Ordering::Relaxed))
    }

    /// Set the multiplier. Does NOT auto-apply -- callers
    /// typically follow with [`apply_to_cdos`](Self::apply_to_cdos).
    pub fn set_multiplier(&self, m: f32) {
        self.multiplier_bits.store(m.to_bits(), Ordering::Relaxed);
    }

    /// Apply to every CDO of the configured class. Skip-if-unity:
    /// when `multiplier == 1.0`, returns zero stats without
    /// touching the CDO chain.
    pub fn apply_to_cdos(&self) -> Result<ClassTweakStats, String> {
        self.apply_with_filter(|obj| obj.is_default_object())
    }

    /// Apply to every instance (CDOs + live). Use when the engine
    /// reads from live instances rather than walking the CDO
    /// chain (uncommon, but happens for replicated fields).
    pub fn apply_to_all(&self) -> Result<ClassTweakStats, String> {
        self.apply_with_filter(|_| true)
    }

    /// Apply with a custom filter (called against the live
    /// `&UObject`).
    pub fn apply_with_filter<F>(&self, filter: F) -> Result<ClassTweakStats, String>
    where
        F: Fn(&UObject) -> bool,
    {
        let m = self.multiplier();
        if (m - 1.0).abs() < f32::EPSILON {
            return Ok(ClassTweakStats::default());
        }
        self.inner.apply(filter, |vanilla| {
            if !vanilla.is_finite() || vanilla == 0.0 {
                None
            } else {
                Some(vanilla * m)
            }
        })
    }

    pub fn revert(&self) -> Result<usize, String> {
        self.inner.revert()
    }

    pub fn vanilla_count(&self) -> usize {
        self.inner.vanilla_count()
    }

    pub fn class_name(&self) -> &'static str {
        self.inner.class_name()
    }
    pub fn offset(&self) -> usize {
        self.inner.offset()
    }
}
