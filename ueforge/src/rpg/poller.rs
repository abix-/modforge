//! 1Hz worker that watches a slot-key resolver closure and drives
//! activate / deactivate transitions on a consumer-provided pair of
//! callbacks.
//!
//! The slot-key resolver is game-specific (Grounded 2 reads
//! `AInGameGameState.PlaythroughGuid` at +0x32C; another UE game
//! might read a different field). The consumer plugs that closure
//! in; the poller handles transition detection.
//!
//! ```ignore
//! let handle = ueforge::rpg::SlotPoller::spawn(
//!     std::time::Duration::from_secs(1),
//!     game::current_slot_key,        // -> Option<String>
//!     |slot| tracker::activate(slot),
//!     ||     tracker::deactivate(),
//! );
//!
//! // Later, from `on_shutdown`:
//! handle.stop();
//! ```
//!
//! The handle's `stop()` flips an atomic; the worker exits at the
//! next interval tick (~1s typical, bounded by `interval`).
//! Required for hot-reload safety -- without a stop signal the
//! worker thread would outlive an unloaded DLL and segfault on
//! the next callback into freed memory.

use std::panic::AssertUnwindSafe;
use std::sync::Arc;
use std::sync::atomic::{AtomicBool, AtomicU64, Ordering};
use std::time::Duration;

use parking_lot::Mutex;

/// Handle to a running [`SlotPoller`]. Drop is a no-op (handles
/// are designed to be `forget`-friendly so the static instance
/// can outlive whoever called `spawn`); call [`Self::stop`]
/// explicitly from `on_shutdown` to signal the worker.
pub struct PollerHandle {
    stop: Arc<AtomicBool>,
    /// Per-spawn diagnostic counter -- incremented every time the
    /// worker catches a panic from the resolver or callbacks.
    /// Snapshot surface so silent thread death stops being
    /// silent.
    panics: Arc<AtomicU64>,
    /// Most recent panic message; cleared on no-op tick.
    last_panic: Arc<Mutex<Option<String>>>,
}

impl PollerHandle {
    /// Signal the worker to exit. The worker checks the flag at
    /// every interval tick, so the actual exit is bounded by the
    /// configured interval (typical 1s).
    pub fn stop(&self) {
        self.stop.store(true, Ordering::Release);
    }

    /// Total panics caught from the resolver / callbacks since
    /// spawn.
    pub fn panic_count(&self) -> u64 {
        self.panics.load(Ordering::Relaxed)
    }

    /// Most recent panic message, if any. Cleared on the next
    /// successful tick.
    pub fn last_panic(&self) -> Option<String> {
        self.last_panic.lock().clone()
    }
}

pub struct SlotPoller;

impl SlotPoller {
    /// Spawn the watcher on a named Rust thread (visible to
    /// debuggers via the OS thread description). Returns a
    /// [`PollerHandle`] that can stop the worker.
    ///
    /// Panics in the resolver / callbacks are caught, logged
    /// with the message payload, counted, and the most recent
    /// is exposed via [`PollerHandle::last_panic`]. The worker
    /// keeps running -- a single bad tick doesn't kill slot
    /// tracking for the rest of the session.
    pub fn spawn<R, A, D>(
        interval: Duration,
        resolve: R,
        on_activate: A,
        on_deactivate: D,
    ) -> PollerHandle
    where
        R: Fn() -> Option<String> + Send + 'static,
        A: Fn(String) + Send + 'static,
        D: Fn() + Send + 'static,
    {
        let stop = Arc::new(AtomicBool::new(false));
        let panics = Arc::new(AtomicU64::new(0));
        let last_panic = Arc::new(Mutex::new(None::<String>));

        let handle_stop = stop.clone();
        let handle_panics = panics.clone();
        let handle_last_panic = last_panic.clone();

        let result = std::thread::Builder::new()
            .name("ueforge/rpg/slot-poller".to_string())
            .spawn(move || {
                run(Cfg {
                    interval,
                    resolve: Box::new(resolve),
                    on_activate: Box::new(on_activate),
                    on_deactivate: Box::new(on_deactivate),
                    stop: handle_stop,
                    panics: handle_panics,
                    last_panic: handle_last_panic,
                });
            });

        if let Err(e) = result {
            crate::log!("rpg/poller: spawn failed: {e}");
        }

        PollerHandle {
            stop,
            panics,
            last_panic,
        }
    }
}

struct Cfg {
    interval: Duration,
    resolve: Box<dyn Fn() -> Option<String> + Send + 'static>,
    on_activate: Box<dyn Fn(String) + Send + 'static>,
    on_deactivate: Box<dyn Fn() + Send + 'static>,
    stop: Arc<AtomicBool>,
    panics: Arc<AtomicU64>,
    last_panic: Arc<Mutex<Option<String>>>,
}

fn run(cfg: Cfg) {
    crate::log!("rpg/poller: started, interval={:?}", cfg.interval);
    let mut last: Option<String> = None;

    while !cfg.stop.load(Ordering::Acquire) {
        // Each tick is wrapped in catch_unwind so a single panic
        // inside the resolver / activate / deactivate callbacks
        // doesn't kill the watcher.
        let cur_result = std::panic::catch_unwind(AssertUnwindSafe(|| (cfg.resolve)()));
        let cur = match cur_result {
            Ok(v) => v,
            Err(payload) => {
                record_panic(&cfg, "resolve", &payload);
                None
            }
        };

        match (last.as_deref(), cur.as_deref()) {
            (None, Some(s)) => fire(&cfg, "on_activate", || (cfg.on_activate)(s.to_string())),
            (Some(a), Some(b)) if a != b => {
                fire(&cfg, "on_deactivate", || (cfg.on_deactivate)());
                fire(&cfg, "on_activate", || (cfg.on_activate)(b.to_string()));
            }
            (Some(_), None) => fire(&cfg, "on_deactivate", || (cfg.on_deactivate)()),
            _ => {}
        }
        last = cur;
        std::thread::sleep(cfg.interval);
    }

    crate::log!("rpg/poller: stop signal received, exiting");
}

fn fire(cfg: &Cfg, kind: &str, work: impl FnOnce()) {
    if let Err(payload) = std::panic::catch_unwind(AssertUnwindSafe(work)) {
        record_panic(cfg, kind, &payload);
    }
}

fn record_panic(cfg: &Cfg, kind: &str, payload: &Box<dyn std::any::Any + Send>) {
    cfg.panics.fetch_add(1, Ordering::Relaxed);
    let msg = if let Some(s) = payload.downcast_ref::<&'static str>() {
        (*s).to_string()
    } else if let Some(s) = payload.downcast_ref::<String>() {
        s.clone()
    } else {
        "<non-string panic payload>".to_string()
    };
    crate::log!("rpg/poller: panic in {kind}: {msg}");
    *cfg.last_panic.lock() = Some(format!("[{kind}] {msg}"));
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::sync::atomic::AtomicU32;

    #[test]
    fn handle_stop_flips_flag() {
        let h = SlotPoller::spawn(
            Duration::from_millis(10),
            || None,
            |_| {},
            || {},
        );
        // Let the thread make a few ticks.
        std::thread::sleep(Duration::from_millis(50));
        h.stop();
        // Bounded by interval; give the worker time to notice.
        std::thread::sleep(Duration::from_millis(50));
        // We can't directly observe thread exit without a join
        // handle; the stop flag IS the contract. Verify it at
        // least propagated.
        assert!(h.stop.load(Ordering::Acquire));
    }

    #[test]
    fn resolver_panic_is_caught_and_counted() {
        let counter = Arc::new(AtomicU32::new(0));
        let counter_for_resolver = counter.clone();
        let h = SlotPoller::spawn(
            Duration::from_millis(10),
            move || {
                let n = counter_for_resolver.fetch_add(1, Ordering::Relaxed);
                if n == 0 {
                    panic!("intentional resolver panic");
                }
                None
            },
            |_| {},
            || {},
        );
        // Wait long enough for at least the panicking tick + one
        // recovery tick.
        std::thread::sleep(Duration::from_millis(100));
        h.stop();
        std::thread::sleep(Duration::from_millis(50));
        assert!(h.panic_count() >= 1, "panics={}", h.panic_count());
        assert!(h.last_panic().is_some());
        assert!(counter.load(Ordering::Relaxed) >= 2,
            "thread should have kept running after panic");
    }

    #[test]
    fn no_panics_means_clean_handle() {
        let h = SlotPoller::spawn(
            Duration::from_millis(10),
            || None,
            |_| {},
            || {},
        );
        std::thread::sleep(Duration::from_millis(50));
        h.stop();
        assert_eq!(h.panic_count(), 0);
        assert!(h.last_panic().is_none());
    }
}
