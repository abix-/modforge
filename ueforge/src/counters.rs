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
///     let _g = ueforge::counters::time_scope(&MY_TIME_NS);
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

/// Declare one or more `pub static AtomicU64` counter statics, each
/// initialized to zero.
///
/// ```ignore
/// ueforge::counter!(KILL_HOOK_FIRES);
/// ueforge::counter!(KILL_HOOK_PLAYER_FIRES);
/// ueforge::counter!(TIME_NS_DRAIN_PENDING);
///
/// fn on_event() {
///     ueforge::counters::bump(&KILL_HOOK_FIRES);
/// }
/// ```
///
/// The macro is intentionally minimal — counters are write-mostly,
/// the `AtomicU64` type is the contract, and the snapshot
/// aggregator (which reads them) is game-specific anyway.
#[macro_export]
macro_rules! counter {
    ($name:ident) => {
        pub static $name: ::std::sync::atomic::AtomicU64 =
            ::std::sync::atomic::AtomicU64::new(0);
    };
    ($name:ident, $($rest:ident),+ $(,)?) => {
        $crate::counter!($name);
        $crate::counter!($($rest),+);
    };
}

/// Same as [`counter!`] for `AtomicUsize` peak high-water-mark
/// counters consumed by [`observe_peak`].
#[macro_export]
macro_rules! peak {
    ($name:ident) => {
        pub static $name: ::std::sync::atomic::AtomicUsize =
            ::std::sync::atomic::AtomicUsize::new(0);
    };
    ($name:ident, $($rest:ident),+ $(,)?) => {
        $crate::peak!($name);
        $crate::peak!($($rest),+);
    };
}

/// Build a `serde_json::Value::Object` from a list of
/// `(static_ident => "json_key")` pairs by `load(Relaxed)`-ing each
/// counter (or peak) static. Centralizes the load + ordering
/// discipline so the snapshot endpoint is one short list per mod.
///
/// Accepts any static whose type implements `Load`-shape semantics
/// via `.load(Ordering::Relaxed)` returning a JSON-friendly integer
/// (`AtomicU64`, `AtomicUsize`, `AtomicI64`).
///
/// ```ignore
/// pub fn snapshot_json() -> serde_json::Value {
///     ueforge::counter_json! {
///         KILL_HOOK_FIRES        => "kill_hook_fires",
///         KILL_HOOK_PLAYER_FIRES => "kill_hook_player_fires",
///         DAMAGE_RING_PEAK       => "damage_ring_peak",  // AtomicUsize
///         TIME_NS_DRAIN_PENDING  => "time_ns_drain_pending",
///     }
/// }
/// ```
#[macro_export]
macro_rules! counter_json {
    ( $( $name:path => $key:literal ),* $(,)? ) => {
        ::serde_json::json!({
            $(
                $key: $name.load(::core::sync::atomic::Ordering::Relaxed),
            )*
        })
    };
}
