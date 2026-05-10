//! Stack-size tweaks. Bumps `DT_Materials.MaxCanStack` for every
//! row by a configurable multiplier (persisted in
//! `<DLL_dir>/settings.json` via [`crate::settings`]).
//!
//! All the heavy lifting — vanilla baseline snapshot, idempotent
//! re-apply, the on-first-sight polling worker — lives in
//! `uespy::ue::datatable::FieldTweak<i32>`. This module owns
//! only the game-specific bits: the table name, the
//! `MaxCanStack` field offset, the `vanilla <= 1 → skip`
//! equipment-preserving rule, and the multiplier knob the tab
//! UI exposes.

use std::sync::atomic::{AtomicUsize, Ordering};
use std::time::Duration;

use uespy::ue::datatable::FieldTweak;

use crate::settings;

/// Default multiplier — matches the existing community
/// "Better Item Stacks" pak mod's behavior.
pub const DEFAULT_MULTIPLIER: i32 = 4;
pub const MIN_MULTIPLIER: i32 = 1;
pub const MAX_MULTIPLIER: i32 = 64;

const STACK_OFFSET: usize = 0x48; // FSMaterialData::MaxCanStack
const POLL_TIMEOUT: Duration = Duration::from_secs(30);

/// The tweak. Captures vanilla once, idempotent across multiplier
/// changes. `static` so `apply_when_ready` (which spawns a
/// thread holding `&'static self`) can use it.
static STACK_TWEAK: FieldTweak<i32> = FieldTweak::new("DT_Materials", STACK_OFFSET);

/// Last-apply row count for the tab status line.
static LAST_APPLIED: AtomicUsize = AtomicUsize::new(0);
static EVER_APPLIED: std::sync::atomic::AtomicBool =
    std::sync::atomic::AtomicBool::new(false);

pub fn current_multiplier() -> i32 {
    settings::get().get().stacks.multiplier
}

pub fn set_multiplier(m: i32) {
    let clamped = m.clamp(MIN_MULTIPLIER, MAX_MULTIPLIER);
    settings::get().update(|s| s.stacks.multiplier = clamped);
}

pub fn last_applied_rows() -> usize {
    LAST_APPLIED.load(Ordering::Relaxed)
}

pub fn ever_applied() -> bool {
    EVER_APPLIED.load(Ordering::Relaxed)
}

pub fn vanilla_count() -> usize {
    STACK_TWEAK.vanilla_count()
}

/// Spawn the initial apply worker. Runs once on first sight of
/// `DT_Materials` (or times out at 30s).
pub fn spawn_apply_worker() {
    uespy::log::log(format_args!("stacks: worker armed"));
    STACK_TWEAK.apply_when_ready(
        POLL_TIMEOUT,
        |vanilla| vanilla.saturating_mul(current_multiplier()),
        |vanilla| vanilla <= 1, // equipment / non-stackable
    );
    // Note: apply_when_ready logs internally on success / failure;
    // we set EVER_APPLIED + LAST_APPLIED in apply_now since the
    // worker writes asynchronously. The first tab-driven Apply
    // (or a slider drag) will refresh those counters.
}

/// Re-apply the current multiplier. Called from the tab on a
/// button click. Returns row count or an error string.
pub fn apply_now() -> Result<usize, String> {
    let m = current_multiplier();
    let n = STACK_TWEAK.apply(
        |vanilla| vanilla.saturating_mul(m),
        |vanilla| vanilla <= 1,
    )?;
    LAST_APPLIED.store(n, Ordering::Relaxed);
    EVER_APPLIED.store(true, Ordering::Relaxed);
    Ok(n)
}
