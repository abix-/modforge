//! Hot-path performance counter primitives.
//!
//! Pattern: declare an `AtomicU64` per call site. Bump on every
//! fire. Snapshot the values at T0 and T1; whichever counter has
//! the largest delta is the cycle thief. No locks, single relaxed
//! atomic op per bump, safe to call from any thread.
//!
//! Embedding crates declare their own counter statics (one per
//! call site) and call `bump` / `observe_peak` / `time_scope`
//! against them.

use std::sync::atomic::{AtomicU64, AtomicUsize, Ordering};
use std::time::Instant;

#[inline(always)]
pub fn bump(c: &AtomicU64) {
    c.fetch_add(1, Ordering::Relaxed);
}

/// Update a high-water-mark counter if `value` exceeds the current.
/// Lock-free via CAS retry. Cheap on the common path (single load
/// + single branch when nothing to do).
#[inline(always)]
pub fn observe_peak(p: &AtomicUsize, value: usize) {
    let mut cur = p.load(Ordering::Relaxed);
    while value > cur {
        match p.compare_exchange_weak(cur, value, Ordering::Relaxed, Ordering::Relaxed) {
            Ok(_) => break,
            Err(c) => cur = c,
        }
    }
}

/// RAII guard that adds the elapsed nanoseconds to `counter` when
/// dropped. Use at the start of any function whose wall time you
/// want to track.
///
/// ```ignore
/// fn hot_path() {
///     let _g = uespy::counters::time_scope(&MY_TIME_NS);
///     // ... work ...
/// } // _g drops here, counter += elapsed_ns
/// ```
pub struct TimeScope<'a> {
    counter: &'a AtomicU64,
    start: Instant,
}

impl Drop for TimeScope<'_> {
    fn drop(&mut self) {
        let ns = self.start.elapsed().as_nanos() as u64;
        self.counter.fetch_add(ns, Ordering::Relaxed);
    }
}

#[inline(always)]
pub fn time_scope(counter: &AtomicU64) -> TimeScope<'_> {
    TimeScope {
        counter,
        start: Instant::now(),
    }
}
