//! Game difficulty / drain-rate tweak framework. One of
//! ueforge's opinionated UE5 mod modules (rpg / stacks /
//! difficulty / inventory / damage).
//!
//! ```text
//! K8s slot: Def=DifficultyDef, Registry=DifficultyRegistry,
//!           Instance=per-CDO cached vanilla in DifficultyDef.inner,
//!           Controller=DifficultyDef::apply_to_cdos / DifficultyRegistry::apply_all_to_cdos
//! ```
//!
//! Most UE5 survival games expose difficulty as `f32` knobs on a
//! settings / component CDO: hunger drain, thirst drain, fall
//! damage multiplier, regen rate, etc. The universal pattern is
//! "capture vanilla per CDO, then `vanilla * multiplier` on every
//! apply, idempotently". This module wraps
//! [`ClassFieldTweak<f32>`] with that pattern so a difficulty
//! knob is one [`DifficultyDef::new`] static + a multiplier
//! setter.
//!
//! ```ignore
//! use ueforge::difficulty::{DifficultyDef, DifficultyRegistry};
//!
//! pub static SURVIVAL: DifficultyRegistry = DifficultyRegistry::new(&[
//!     DifficultyDef::new("hunger", "SurvivalComponent", 0x0140),
//!     DifficultyDef::new("thirst", "SurvivalComponent", 0x0188),
//! ]);
//!
//! // From `on_unreal_init`:
//! SURVIVAL.def("hunger").unwrap().set_multiplier(0.5);
//! SURVIVAL.apply_all_to_cdos();
//!
//! // From a settings reload / tab slider:
//! SURVIVAL.def("hunger").unwrap().set_multiplier(new_mult);
//! SURVIVAL.apply_all_to_cdos();
//! ```
//!
//! Each Def's vanilla cache is independent so adding a knob never
//! disturbs existing ones.

use std::sync::atomic::{AtomicU32, Ordering};

use crate::ue::UObject;
use crate::ue::class_tweak::{ClassFieldTweak, ClassTweakStats};

/// One difficulty knob: a class+offset CDO field tweak with an
/// atomic `f32` multiplier. The Def in the workspace's
/// Def/Registry/Instance/Controller pattern.
///
/// `apply_to_cdos` writes `vanilla * multiplier` to every CDO of
/// the configured class. `apply_to_all` writes to every instance
/// (CDOs + live), useful for fields the engine reads from live
/// instances rather than the CDO.
pub struct DifficultyDef {
    /// Stable id for [`DifficultyRegistry::def`] lookup.
    pub id: &'static str,
    inner: ClassFieldTweak<f32>,
    multiplier_bits: AtomicU32, // f32 bits
}

impl DifficultyDef {
    pub const fn new(
        id: &'static str,
        class_name: &'static str,
        field_offset: usize,
    ) -> Self {
        Self {
            id,
            inner: ClassFieldTweak::new(class_name, field_offset),
            multiplier_bits: AtomicU32::new(0x3F800000), // 1.0_f32
        }
    }

    pub fn multiplier(&self) -> f32 {
        f32::from_bits(self.multiplier_bits.load(Ordering::Relaxed))
    }

    /// Set the multiplier. Does NOT auto-apply. Callers
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

/// Workspace-standard `<Subject>Registry` for difficulty knobs.
/// Stores `&[&'static DifficultyDef]` (slice of refs) so consumers
/// can declare each Def as its own named static + inline the
/// registry literal without hitting Rust's const-eval Drop
/// restriction. See architecture.md "Naming contract".
pub struct DifficultyRegistry {
    entries: &'static [&'static DifficultyDef],
}

impl DifficultyRegistry {
    pub const fn new(entries: &'static [&'static DifficultyDef]) -> Self {
        Self { entries }
    }

    /// Look up by `id`. Linear scan; registries are tiny.
    pub fn def(&self, id: &str) -> Option<&'static DifficultyDef> {
        for d in self.entries {
            if d.id == id {
                return Some(*d);
            }
        }
        None
    }

    pub fn entries(&self) -> &'static [&'static DifficultyDef] {
        self.entries
    }

    pub fn iter(&self) -> std::slice::Iter<'_, &'static DifficultyDef> {
        self.entries.iter()
    }

    pub fn len(&self) -> usize {
        self.entries.len()
    }

    pub fn is_empty(&self) -> bool {
        self.entries.is_empty()
    }

    /// Apply every Def's `apply_to_cdos`. Returns one
    /// `(id, Result)` per Def for per-knob telemetry.
    pub fn apply_all_to_cdos(
        &self,
    ) -> Vec<(&'static str, Result<ClassTweakStats, String>)> {
        self.entries
            .iter()
            .map(|d| (d.id, d.apply_to_cdos()))
            .collect()
    }

    /// Apply every Def's `apply_to_all` (CDOs + live).
    pub fn apply_all(
        &self,
    ) -> Vec<(&'static str, Result<ClassTweakStats, String>)> {
        self.entries
            .iter()
            .map(|d| (d.id, d.apply_to_all()))
            .collect()
    }

    pub fn revert_all(&self) -> Vec<(&'static str, Result<usize, String>)> {
        self.entries.iter().map(|d| (d.id, d.revert())).collect()
    }
}

impl<'a> IntoIterator for &'a DifficultyRegistry {
    type Item = &'static DifficultyDef;
    type IntoIter = std::iter::Copied<std::slice::Iter<'a, &'static DifficultyDef>>;
    fn into_iter(self) -> Self::IntoIter {
        self.entries.iter().copied()
    }
}
