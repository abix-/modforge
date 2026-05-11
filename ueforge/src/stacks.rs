//! Inventory stack-size tweak framework. One of ueforge's
//! opinionated UE5 mod modules (rpg / stacks / difficulty /
//! inventory / damage).
//!
//! ```text
//! K8s slot: Def=StackDef, Registry=StackRegistry,
//!           Instance=per-row cached vanilla in StackDef.inner,
//!           Controller=StackDef::apply_now / StackRegistry::apply_all_now
//! ```
//!
//! Every UE5 survival / crafting game ships a "max stack size"
//! integer per item row in a `DT_Materials`-shaped data table.
//! Boosting those values is one of the most common QoL mods. This
//! module owns the universal pattern so a game-side stacks tweak
//! is one [`StackDef::new`] static + a multiplier knob.
//!
//! ```ignore
//! use ueforge::stacks::{StackDef, StackRegistry};
//!
//! pub static STACKS: StackRegistry = StackRegistry::new(&[
//!     StackDef::new(
//!         "materials",     // stable id for registry lookup
//!         "DT_Materials",  // data-table short name
//!         0x48,            // offset of MaxCanStack within the row struct
//!         4,               // default multiplier
//!         |v| v <= 1,      // skip equipment / non-stackable rows
//!     ),
//! ]);
//!
//! // From `on_unreal_init`:
//! STACKS.spawn_apply_workers(std::time::Duration::from_secs(30));
//!
//! // From the ImGui tab:
//! let materials = STACKS.def("materials").unwrap();
//! ueforge::ui::slider_i32("Multiplier", materials.current_multiplier(), 1, 64);
//! if ueforge::ui::button("Apply") {
//!     let _ = materials.apply_now();
//! }
//! ```
//!
//! The wrapped primitive is [`crate::ue::datatable::FieldTweak<i32>`]:
//! it captures vanilla on first sight per row, mutates idempotently,
//! and survives multiplier changes (every apply re-bases on the
//! captured vanilla, never compounding).

use std::sync::atomic::{AtomicBool, AtomicI32, AtomicUsize, Ordering};
use std::time::Duration;

use crate::ue::datatable::FieldTweak;

/// One stack-size tweak. The Def in the workspace's
/// Def/Registry/Instance/Controller pattern: declared once at
/// compile time, holds both the immutable config + the runtime
/// state (vanilla cache, multiplier atomic, apply counters).
pub struct StackDef {
    /// Stable id for [`StackRegistry::def`] lookup. Lowercase
    /// snake_case by convention (`"materials"`, `"crops"`).
    pub id: &'static str,
    inner: FieldTweak<i32>,
    multiplier: AtomicI32,
    skip_predicate: fn(i32) -> bool,
    last_applied: AtomicUsize,
    ever_applied: AtomicBool,
}

impl StackDef {
    /// Configure a stack tweak. `skip_predicate` runs against the
    /// VANILLA row value; rows where it returns true are left
    /// untouched (typical: `|v| v <= 1` to preserve equipment
    /// items the table marks as non-stackable).
    pub const fn new(
        id: &'static str,
        table_name: &'static str,
        field_offset: usize,
        default_multiplier: i32,
        skip_predicate: fn(i32) -> bool,
    ) -> Self {
        Self {
            id,
            inner: FieldTweak::new(table_name, field_offset),
            multiplier: AtomicI32::new(default_multiplier),
            skip_predicate,
            last_applied: AtomicUsize::new(0),
            ever_applied: AtomicBool::new(false),
        }
    }

    pub fn current_multiplier(&self) -> i32 {
        self.multiplier.load(Ordering::Relaxed)
    }

    /// Set the multiplier. Does NOT auto-reapply. Callers
    /// typically push a settings update + then call
    /// [`apply_now`](Self::apply_now) (or wait for the next
    /// `apply_when_ready` worker fire).
    pub fn set_multiplier(&self, m: i32) {
        self.multiplier.store(m, Ordering::Relaxed);
    }

    pub fn last_applied_rows(&self) -> usize {
        self.last_applied.load(Ordering::Relaxed)
    }

    pub fn ever_applied(&self) -> bool {
        self.ever_applied.load(Ordering::Relaxed)
    }

    pub fn vanilla_count(&self) -> usize {
        self.inner.vanilla_count()
    }

    /// Spawn the initial-apply worker. Polls for the table, runs
    /// once when it loads, then exits. Multiplier reads are
    /// deferred until apply time so a settings update before the
    /// table loads still takes effect.
    pub fn spawn_apply_worker(&'static self, timeout: Duration) {
        let skip = self.skip_predicate;
        self.inner.apply_when_ready(
            timeout,
            move |vanilla| vanilla.saturating_mul(self.current_multiplier()),
            skip,
        );
    }

    /// Apply the current multiplier now. Returns the row count
    /// touched, or an error string if the table isn't loaded yet.
    pub fn apply_now(&self) -> Result<usize, String> {
        let m = self.current_multiplier();
        let skip = self.skip_predicate;
        let n = self
            .inner
            .apply(move |vanilla| vanilla.saturating_mul(m), skip)?;
        self.last_applied.store(n, Ordering::Relaxed);
        self.ever_applied.store(true, Ordering::Relaxed);
        Ok(n)
    }

    /// Revert every captured row to its vanilla value.
    pub fn revert(&self) -> Result<usize, String> {
        self.inner.revert()
    }
}

/// Workspace-standard `<Subject>Registry` for stacks. Stores
/// `&[&'static StackDef]` (slice of refs) so consumers can
/// declare each Def as its own named static + inline the
/// registry literal without hitting Rust's const-eval Drop
/// restriction. See architecture.md "Naming contract".
pub struct StackRegistry {
    entries: &'static [&'static StackDef],
}

impl StackRegistry {
    pub const fn new(entries: &'static [&'static StackDef]) -> Self {
        Self { entries }
    }

    /// Look up by `id`. Linear scan; registries are tiny.
    pub fn def(&self, id: &str) -> Option<&'static StackDef> {
        for d in self.entries {
            if d.id == id {
                return Some(*d);
            }
        }
        None
    }

    pub fn entries(&self) -> &'static [&'static StackDef] {
        self.entries
    }

    pub fn iter(&self) -> std::slice::Iter<'_, &'static StackDef> {
        self.entries.iter()
    }

    pub fn len(&self) -> usize {
        self.entries.len()
    }

    pub fn is_empty(&self) -> bool {
        self.entries.is_empty()
    }

    /// Spawn an `apply_when_ready` worker for every Def. Each worker
    /// polls independently for its table.
    pub fn spawn_apply_workers(&'static self, timeout: Duration) {
        for def in self.entries {
            def.spawn_apply_worker(timeout);
        }
    }

    /// Apply every Def now. Returns one `(id, Result)` per Def so
    /// the caller can log per-table outcomes.
    pub fn apply_all_now(&self) -> Vec<(&'static str, Result<usize, String>)> {
        self.entries
            .iter()
            .map(|d| (d.id, d.apply_now()))
            .collect()
    }

    /// Revert every Def. Returns one `(id, Result)` per Def.
    pub fn revert_all(&self) -> Vec<(&'static str, Result<usize, String>)> {
        self.entries.iter().map(|d| (d.id, d.revert())).collect()
    }
}

impl<'a> IntoIterator for &'a StackRegistry {
    type Item = &'static StackDef;
    type IntoIter = std::iter::Copied<std::slice::Iter<'a, &'static StackDef>>;
    fn into_iter(self) -> Self::IntoIter {
        self.entries.iter().copied()
    }
}
