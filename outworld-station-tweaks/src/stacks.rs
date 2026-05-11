//! Stack-size tweaks. Bumps `DT_Materials.MaxCanStack` for every
//! row by a configurable multiplier (persisted in
//! `<DLL_dir>/settings.json` via [`crate::settings`]).
//!
//! All the heavy lifting. Vanilla baseline snapshot, idempotent
//! re-apply, the on-first-sight polling worker, the multiplier
//! atomic, the apply-now / last-applied / ever-applied counters.
//! lives in `ueforge::stacks::StackDef` + `StackRegistry`. This
//! module owns only the game-specific bits (table name, field
//! offset, skip rule, settings echo).

use std::time::Duration;

use ueforge::stacks::{StackDef, StackRegistry};

use crate::settings;

/// Default multiplier. Matches the "Better Item Stacks" pak mod.
pub const DEFAULT_MULTIPLIER: i32 = 4;
pub const MIN_MULTIPLIER: i32 = 1;
pub const MAX_MULTIPLIER: i32 = 64;

const STACK_OFFSET: usize = 0x48; // FSMaterialData::MaxCanStack
const POLL_TIMEOUT: Duration = Duration::from_secs(30);

/// Per-table StackDef instance. Add a new `static FOO_DEF: StackDef`
/// + a `&FOO_DEF` entry in `STACKS` below to register a new table.
/// The `vanilla <= 1` skip preserves equipment / non-stackable rows.
static MATERIALS_DEF: StackDef = StackDef::new(
    "materials",
    "DT_Materials",
    STACK_OFFSET,
    DEFAULT_MULTIPLIER,
    |v| v <= 1,
);

/// Workspace-standard stack registry for ows-tweaks. Slice of
/// `&'static StackDef` refs. Each Def above is its own named
/// static, so the registry literal stays inline without needing
/// to hoist a temporary array.
pub static STACKS: StackRegistry = StackRegistry::new(&[&MATERIALS_DEF]);

fn materials() -> &'static StackDef {
    STACKS.def("materials").expect("materials Def registered above")
}

pub fn current_multiplier() -> i32 {
    settings::get().get().stacks.multiplier
}

pub fn set_multiplier(m: i32) {
    let clamped = m.clamp(MIN_MULTIPLIER, MAX_MULTIPLIER);
    settings::get().update(|s| s.stacks.multiplier = clamped);
    materials().set_multiplier(clamped);
}

pub fn last_applied_rows() -> usize {
    materials().last_applied_rows()
}

pub fn ever_applied() -> bool {
    materials().ever_applied()
}

pub fn vanilla_count() -> usize {
    materials().vanilla_count()
}

pub fn spawn_apply_worker() {
    // Sync the multiplier from settings before the worker fires,
    // so the first apply uses the persisted value.
    materials().set_multiplier(current_multiplier());
    ueforge::log::log(format_args!("stacks: workers armed"));
    STACKS.spawn_apply_workers(POLL_TIMEOUT);
}

pub fn apply_now() -> Result<usize, String> {
    materials().set_multiplier(current_multiplier());
    materials().apply_now()
}
