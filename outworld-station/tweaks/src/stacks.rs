//! Stack-size tweaks. Bumps `DT_Materials.MaxCanStack` for every
//! row by a configurable multiplier. Mutations land *before* any
//! actor / UI widget caches the row (the
//! `on_unreal_init`-poll-mutate pattern in uespy's README). Tab
//! UI re-applies on demand so the user can change the multiplier
//! mid-session.
//!
//! Vanilla baseline is captured on first apply so subsequent
//! changes compute `cur = vanilla * mult` instead of compounding
//! (`cur = cur * mult` would double-bump after each change).

use std::collections::HashMap;
use std::sync::atomic::{AtomicI32, AtomicUsize, Ordering};
use std::sync::{Mutex, OnceLock};
use std::time::Duration;

use uespy::ue::{UObject, datatable};

const STACK_OFFSET: usize = 0x48;       // FSMaterialData::MaxCanStack
const POLL_TIMEOUT: Duration = Duration::from_secs(30);

/// Default multiplier. Matches the existing community
/// "Better Item Stacks" pak mod's behavior.
pub const DEFAULT_MULTIPLIER: i32 = 4;
pub const MIN_MULTIPLIER: i32 = 1;
pub const MAX_MULTIPLIER: i32 = 64;

/// Live multiplier. Tab UI mutates; apply_now reads.
static MULTIPLIER: AtomicI32 = AtomicI32::new(DEFAULT_MULTIPLIER);

/// Per-row vanilla MaxCanStack. Keyed by the FName u64 from the
/// RowMap. Populated once on first apply; subsequent applies
/// compute `vanilla * mult` from this snapshot rather than
/// re-reading current values (which would already be mutated).
static VANILLA: OnceLock<Mutex<HashMap<u64, i32>>> = OnceLock::new();

/// Last-apply row count (for the status line).
static LAST_APPLIED: AtomicUsize = AtomicUsize::new(0);

/// Whether `apply_now` has succeeded at least once.
static EVER_APPLIED: std::sync::atomic::AtomicBool =
    std::sync::atomic::AtomicBool::new(false);

pub fn current_multiplier() -> i32 {
    MULTIPLIER.load(Ordering::Relaxed)
}

pub fn set_multiplier(m: i32) {
    MULTIPLIER.store(m.clamp(MIN_MULTIPLIER, MAX_MULTIPLIER), Ordering::Relaxed);
}

pub fn last_applied_rows() -> usize {
    LAST_APPLIED.load(Ordering::Relaxed)
}

pub fn ever_applied() -> bool {
    EVER_APPLIED.load(Ordering::Relaxed)
}

pub fn vanilla_count() -> usize {
    VANILLA
        .get()
        .map(|m| m.lock().map(|g| g.len()).unwrap_or(0))
        .unwrap_or(0)
}

/// Spawn the initial apply worker. Wires to
/// `uespy::ue::datatable::on_first_sight`, which polls for
/// `DT_Materials` and fires our callback once on the first
/// sighting (or times out). Subsequent re-applies come from
/// the ImGui tab.
pub fn spawn_apply_worker() {
    uespy::log::log(format_args!("stacks: worker armed"));
    datatable::on_first_sight("DT_Materials", POLL_TIMEOUT, |dt| {
        match apply_with_table(dt, current_multiplier()) {
            Ok(n) => uespy::log::log(format_args!(
                "stacks: applied {}x to {n} rows on first sight",
                current_multiplier()
            )),
            Err(e) => uespy::log::log(format_args!("stacks: apply failed: {e}")),
        }
    });
}

/// Re-apply the current multiplier. Called from the tab on a
/// button click. Returns how many rows were mutated, or an
/// error string.
pub fn apply_now() -> Result<usize, String> {
    let dt = datatable::find_by_short_name("DT_Materials")
        .ok_or("DT_Materials not found (game still loading?)")?;
    apply_with_table(dt, current_multiplier())
}

/// Walk `DT_Materials`'s RowMap and write
/// `vanilla[fname] * mult` to each row's MaxCanStack. On the
/// first call, the current value IS treated as vanilla (we
/// snapshot it before writing). Equipment items at vanilla <= 1
/// are recorded but not mutated, so changing the multiplier
/// later doesn't accidentally make non-stackable items stackable.
fn apply_with_table(table: &UObject, mult: i32) -> Result<usize, String> {
    let vanilla_map = VANILLA.get_or_init(|| Mutex::new(HashMap::new()));
    let mut van = vanilla_map.lock().map_err(|_| "vanilla map poisoned")?;

    let mut bumped = 0usize;
    unsafe {
        for (fname, row_ptr) in datatable::iter_rows(table) {
            if row_ptr.is_null() {
                continue;
            }
            let stack_ptr = row_ptr.add(STACK_OFFSET) as *mut i32;
            let cur = stack_ptr.read_unaligned();

            // Capture vanilla on first sight of this fname. Once
            // captured, the entry is the source of truth.
            let vanilla_val = *van.entry(fname).or_insert(cur);

            if vanilla_val <= 1 {
                // Equipment / unique items — never multiply.
                continue;
            }
            let target = vanilla_val.saturating_mul(mult);
            if cur != target {
                stack_ptr.write_unaligned(target);
            }
            bumped += 1;
        }
    }

    LAST_APPLIED.store(bumped, Ordering::Relaxed);
    EVER_APPLIED.store(true, Ordering::Relaxed);
    Ok(bumped)
}
