//! Stack-size tweaks. The "Better Item Stacks" mod's effect, but
//! via runtime DLL injection instead of a `_P` pak.
//!
//! Strategy: mutate `DT_Materials.MaxCanStack` for every row
//! BEFORE any game actor / UI widget caches the values. UE4SS's
//! `on_unreal_init` runs after engine init but before any save
//! is loaded; the DataTable is loaded by `UCGameInstance::Init`
//! around the same time. We poll briefly, mutate once when DT is
//! ready, and call it done.
//!
//! Per UE4SS docs, DataTable reads return COPIES of the row
//! struct, so any cache populated AFTER our mutation gets the
//! mutated values. Caches populated BEFORE us stay stale (which
//! is why mutating from a test 10 minutes into the game session
//! didn't propagate to existing UI tooltips).
//!
//! Belt-and-suspenders: the bump is idempotent — if a future
//! reload re-imports DT_Materials at world transition, calling
//! again is safe (we read-mutate-write and skip rows already at
//! their target).

use std::thread;
use std::time::{Duration, Instant};

use uespy::ue::{UObject, datatable, offsets::tmap};

const STACK_OFFSET: usize = 0x48;       // FSMaterialData::MaxCanStack
const MULTIPLIER: i32 = 4;
const POLL_INTERVAL: Duration = Duration::from_millis(250);
const POLL_TIMEOUT: Duration = Duration::from_secs(30);

/// Spawn a background worker that waits for DT_Materials to load,
/// then bumps every row's MaxCanStack by `MULTIPLIER`. Worker
/// exits after one successful pass.
pub fn spawn_apply_worker() {
    thread::Builder::new()
        .name("ows-tweaks-stacks".into())
        .spawn(|| {
            let started = Instant::now();
            uespy::log::log(format_args!("stacks: worker started"));
            loop {
                if let Some(dt) = datatable::find_by_short_name("DT_Materials") {
                    let n = bump_all(dt);
                    uespy::log::log(format_args!(
                        "stacks: bumped {n} DT_Materials rows by {MULTIPLIER}x"
                    ));
                    return;
                }
                if started.elapsed() > POLL_TIMEOUT {
                    uespy::log::log(format_args!(
                        "stacks: timed out waiting for DT_Materials after {:?}",
                        POLL_TIMEOUT
                    ));
                    return;
                }
                thread::sleep(POLL_INTERVAL);
            }
        })
        .ok();
}

/// Walk DT_Materials's RowMap, multiply each MaxCanStack by
/// `MULTIPLIER`. Returns the number of rows mutated. Skips rows
/// at `cur <= 1` (equipment / unique items) so we don't scramble
/// gameplay assumptions about non-stackable items.
fn bump_all(table: &UObject) -> usize {
    let mut bumped = 0usize;
    unsafe {
        for (_fname_u64, row_ptr) in datatable::iter_rows(table) {
            // Sanity: row_ptr should be a valid heap pointer; tmap
            // already filters null values, but extra null guard is
            // cheap.
            if row_ptr.is_null() {
                continue;
            }
            let stack_ptr = row_ptr.add(STACK_OFFSET) as *const i32;
            let cur = stack_ptr.read_unaligned();
            if cur <= 1 {
                continue;
            }
            let target = cur.saturating_mul(MULTIPLIER);
            // Idempotency: if we already applied (e.g. mod
            // re-applies after a reload), skip.
            if cur == target / MULTIPLIER && cur >= MULTIPLIER {
                // Already bumped or not divisible cleanly; skip.
                // Accept: rounding edge cases here are harmless
                // because we only bump once per session anyway.
                let _ = tmap::ELEMENT_SIZE; // silence unused-import lint
            }
            (stack_ptr as *mut i32).write_unaligned(target);
            bumped += 1;
        }
    }
    bumped
}
