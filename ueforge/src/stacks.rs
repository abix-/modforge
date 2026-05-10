//! Inventory stack-size tweak framework. One of ueforge's
//! opinionated UE5 mod modules (rpg / stacks / difficulty /
//! inventory / damage).
//!
//! Every UE5 survival / crafting game ships a "max stack size"
//! integer per item row in a `DT_Materials`-shaped data table.
//! Boosting those values is one of the most common QoL mods. This
//! module owns the universal pattern so a game-side stacks tweak
//! is one [`StackTweak::new`] static + a multiplier knob.
//!
//! ```ignore
//! use ueforge::stacks::StackTweak;
//!
//! pub static STACKS: StackTweak = StackTweak::new(
//!     "DT_Materials",  // data table short name
//!     0x48,            // offset of MaxCanStack within the row struct
//!     4,               // default multiplier
//!     |v| v <= 1,      // skip equipment / non-stackable rows
//! );
//!
//! // From `on_unreal_init`:
//! STACKS.spawn_apply_worker(std::time::Duration::from_secs(30));
//!
//! // From the ImGui tab:
//! ueforge::ui::slider_i32("Multiplier", STACKS.current_multiplier(), 1, 64);
//! if ueforge::ui::button("Apply") {
//!     let _ = STACKS.apply_now();
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

/// Stack-size tweak: a [`FieldTweak<i32>`] keyed to a data-table
/// + integer offset, with a per-instance atomic multiplier and
/// last-apply counters.
pub struct StackTweak {
    inner: FieldTweak<i32>,
    multiplier: AtomicI32,
    skip_predicate: fn(i32) -> bool,
    last_applied: AtomicUsize,
    ever_applied: AtomicBool,
}

impl StackTweak {
    /// Configure a stack tweak. `skip_predicate` runs against the
    /// VANILLA row value; rows where it returns true are left
    /// untouched (typical: `|v| v <= 1` to preserve equipment
    /// items the table marks as non-stackable).
    pub const fn new(
        table_name: &'static str,
        field_offset: usize,
        default_multiplier: i32,
        skip_predicate: fn(i32) -> bool,
    ) -> Self {
        Self {
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

    /// Set the multiplier. Does NOT auto-reapply -- callers
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
