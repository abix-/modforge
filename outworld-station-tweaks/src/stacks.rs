//! Stack-size tweaks. Bumps `DT_Materials.MaxCanStack` for every
//! row by a configurable multiplier (persisted in
//! `<DLL_dir>/settings.json` via [`crate::settings`]).
//!
//! All the heavy lifting -- vanilla baseline snapshot, idempotent
//! re-apply, the on-first-sight polling worker, the multiplier
//! atomic, the apply-now / last-applied / ever-applied counters --
//! lives in `ueforge::stacks::StackTweak`. This module owns only
//! the game-specific bits (table name, field offset, skip rule,
//! settings echo).

use std::time::Duration;

use ueforge::stacks::StackTweak;

use crate::settings;

/// Default multiplier -- matches the "Better Item Stacks" pak mod.
pub const DEFAULT_MULTIPLIER: i32 = 4;
pub const MIN_MULTIPLIER: i32 = 1;
pub const MAX_MULTIPLIER: i32 = 64;

const STACK_OFFSET: usize = 0x48; // FSMaterialData::MaxCanStack
const POLL_TIMEOUT: Duration = Duration::from_secs(30);

/// The tweak. `vanilla <= 1` rule preserves equipment / non-stackable
/// rows (the table marks those with stack size 1).
static STACKS: StackTweak =
    StackTweak::new("DT_Materials", STACK_OFFSET, DEFAULT_MULTIPLIER, |v| v <= 1);

pub fn current_multiplier() -> i32 {
    settings::get().get().stacks.multiplier
}

pub fn set_multiplier(m: i32) {
    let clamped = m.clamp(MIN_MULTIPLIER, MAX_MULTIPLIER);
    settings::get().update(|s| s.stacks.multiplier = clamped);
    STACKS.set_multiplier(clamped);
}

pub fn last_applied_rows() -> usize {
    STACKS.last_applied_rows()
}

pub fn ever_applied() -> bool {
    STACKS.ever_applied()
}

pub fn vanilla_count() -> usize {
    STACKS.vanilla_count()
}

pub fn spawn_apply_worker() {
    // Sync the multiplier from settings before the worker fires,
    // so the first apply uses the persisted value.
    STACKS.set_multiplier(current_multiplier());
    ueforge::log::log(format_args!("stacks: worker armed"));
    STACKS.spawn_apply_worker(POLL_TIMEOUT);
}

pub fn apply_now() -> Result<usize, String> {
    STACKS.set_multiplier(current_multiplier());
    STACKS.apply_now()
}
