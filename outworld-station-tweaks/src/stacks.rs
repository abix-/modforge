//! Stack-size tweaks. Bumps `DT_Materials.MaxCanStack` for every
//! row by a configurable multiplier (persisted in
//! `<DLL_dir>/settings.json` via [`crate::settings`]).
//!
//! All the heavy lifting. Vanilla baseline snapshot, idempotent
//! re-apply, the multiplier atomic. lives in
//! `ueforge::tweak::TweakDef`. This module owns only the game-
//! specific bits (table name, field name, defaults, settings echo)
//! plus local apply-counters for the status surface.

use std::sync::atomic::{AtomicBool, AtomicUsize, Ordering};
use std::time::Duration;

use ueforge::tweak::{TweakDef, TweakOp};

use crate::settings;

/// Default multiplier. Matches the "Better Item Stacks" pak mod.
pub const DEFAULT_MULTIPLIER: i32 = 4;
pub const MIN_MULTIPLIER: i32 = 1;
pub const MAX_MULTIPLIER: i32 = 64;

const POLL_TIMEOUT: Duration = Duration::from_secs(30);

/// Unified static tweak for DT_Materials.MaxCanStack. Offset is
/// resolved from the discovery cache by FIELD NAME (no more
/// hand-typed 0x48). Multiply skips vanilla=0; the table also
/// uses 1 for non-stackable rows which the framework's
/// dynamic_apply_i32 leaves alone via skip_i32(vanilla, Multiply).
static MATERIALS_TWEAK: TweakDef = TweakDef::data_table_i32(
    "materials",
    "DT_Materials",
    "MaxCanStack",
    TweakOp::Multiply,
    DEFAULT_MULTIPLIER,
);

static LAST_APPLIED_ROWS: AtomicUsize = AtomicUsize::new(0);
static EVER_APPLIED: AtomicBool = AtomicBool::new(false);

pub fn current_multiplier() -> i32 {
    settings::get().get().stacks.multiplier
}

pub fn set_multiplier(m: i32) {
    let clamped = m.clamp(MIN_MULTIPLIER, MAX_MULTIPLIER);
    settings::get().update(|s| s.stacks.multiplier = clamped);
    MATERIALS_TWEAK.store_i32(clamped);
}

pub fn last_applied_rows() -> usize {
    LAST_APPLIED_ROWS.load(Ordering::Relaxed)
}

pub fn ever_applied() -> bool {
    EVER_APPLIED.load(Ordering::Relaxed)
}

pub fn vanilla_count() -> usize {
    MATERIALS_TWEAK.vanilla_count()
}

pub fn spawn_apply_worker() {
    // Sync the multiplier from settings before the worker fires,
    // so the first apply uses the persisted value.
    MATERIALS_TWEAK.store_i32(current_multiplier());
    ueforge::log::log(format_args!("stacks: worker armed"));
    ueforge::ue::datatable::on_first_sight("DT_Materials", POLL_TIMEOUT, |_dt| {
        // Discovery may not have walked this table yet on the
        // first apply path (TweakDef resolves offsets via the
        // discovery cache). Refresh if needed.
        if ueforge::data_table::resolve_field("DT_Materials", "MaxCanStack").is_none() {
            let _ = ueforge::discovery::refresh();
        }
        match MATERIALS_TWEAK.apply() {
            Ok(n) => {
                LAST_APPLIED_ROWS.store(n, Ordering::Relaxed);
                EVER_APPLIED.store(true, Ordering::Relaxed);
                ueforge::log::log(format_args!(
                    "stacks: applied multiplier={} to {n} rows",
                    current_multiplier()
                ));
            }
            Err(e) => ueforge::log::log(format_args!("stacks: apply failed: {e}")),
        }
    });
}

pub fn apply_now() -> Result<usize, String> {
    MATERIALS_TWEAK.store_i32(current_multiplier());
    let n = MATERIALS_TWEAK.apply()?;
    LAST_APPLIED_ROWS.store(n, Ordering::Relaxed);
    EVER_APPLIED.store(true, Ordering::Relaxed);
    Ok(n)
}
