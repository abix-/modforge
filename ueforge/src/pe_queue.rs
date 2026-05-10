//! Game-thread job queue.
//!
//! Many UE engine APIs (`UObject::ProcessEvent`, anything that
//! triggers replication, blueprint events, network RPCs) are only
//! safe to call from the game thread. The HTTP listener runs on a
//! worker thread, so `op` handlers that need to invoke those APIs
//! enqueue a job here and block on a reply channel until the game
//! thread drains and runs the job.
//!
//! The "game thread" is whatever thread drains this queue. In a UE
//! mod that's typically inside a ProcessEvent trampoline that fires
//! many times per second (a damage multicast, a tick UFunction, an
//! input handler — pick one that's hot enough).
//!
//! Re-entrance: jobs themselves can trigger ProcessEvent fan-out
//! that re-enters the trampoline that's draining us. The `DRAINING`
//! flag is the guard — re-entered drains see the flag and skip,
//! letting the outer drain finish without recursion.
//!
//! Counters / timing belong in the game crate. `len()` is a
//! lock-free hot-path check so the trampoline can early-exit when
//! the queue is empty. `drain()` returns `DrainStats` so the game
//! can feed its own metrics.

use std::sync::Arc;
use std::sync::atomic::{AtomicBool, AtomicUsize, Ordering};
use std::sync::mpsc::{Sender, channel};
use std::time::Duration;

use parking_lot::Mutex;

use serde_json::Value as Json;

pub type Job = Box<dyn FnOnce() -> Result<Json, String> + Send>;

/// Default cap on `Queue::inner.len()`. Above this, `enqueue`
/// rejects with a "queue full" error rather than letting an
/// HTTP-side burst pile entries until OOM. Tunable via
/// `Queue::with_capacity`. 1024 is ~100x the largest realistic
/// burst from the test client today.
pub const DEFAULT_MAX_DEPTH: usize = 1024;

struct Pending {
    job: Job,
    reply: Sender<Result<Json, String>>,
    /// Set to true if the enqueue caller already gave up
    /// (`recv_timeout` fired). The drain checks this BEFORE running
    /// the job and skips it -- so a non-idempotent op like
    /// `spend_points` can't run after the client thinks it timed
    /// out and retried.
    cancelled: Arc<AtomicBool>,
}

pub struct Queue {
    inner: Mutex<Vec<Pending>>,
    /// Lock-free shadow of `inner.len()`. Updated under the mutex.
    /// Lets `drain` early-exit with one relaxed atomic load on the
    /// hot path, avoiding the mutex acquire that fires 1000+/sec
    /// from a per-frame trampoline.
    size: AtomicUsize,
    /// Re-entrance guard. See module doc.
    draining: AtomicBool,
    /// Max enqueued jobs. New `enqueue` calls beyond this fail
    /// fast with a "queue full" error so we don't run the host
    /// process out of memory under load.
    max_depth: usize,
}

#[derive(Default, Debug, Clone, Copy)]
pub struct DrainStats {
    /// Queue depth observed at the start of this drain.
    pub peak: usize,
    /// Number of jobs actually executed.
    pub drained: usize,
    /// True if the call early-exited because another drain was in
    /// progress (re-entrance) — *not* because the queue was empty.
    pub reentered: bool,
}

impl Queue {
    pub const fn new() -> Self {
        Self {
            inner: Mutex::new(Vec::new()),
            size: AtomicUsize::new(0),
            draining: AtomicBool::new(false),
            max_depth: DEFAULT_MAX_DEPTH,
        }
    }

    pub const fn with_capacity(max_depth: usize) -> Self {
        Self {
            inner: Mutex::new(Vec::new()),
            size: AtomicUsize::new(0),
            draining: AtomicBool::new(false),
            max_depth,
        }
    }

    /// Lock-free queue depth. Cheap enough to call every frame.
    pub fn len(&self) -> usize {
        self.size.load(Ordering::Acquire)
    }

    pub fn is_empty(&self) -> bool {
        self.len() == 0
    }

    /// Enqueue a job and block the caller on the reply channel up
    /// to `timeout`. Returns the job's result on success, or an
    /// error string on queue-full, timeout, or job failure.
    ///
    /// If `recv_timeout` fires, the job is **cancelled**: the
    /// drain side checks the cancel flag before invoking the
    /// closure and skips it. This prevents non-idempotent ops
    /// (`spend_points`, `write_bytes`, `call`) from running AFTER
    /// the HTTP client gave up and the user retried -- which used
    /// to silently double-execute.
    pub fn enqueue<F>(&self, job: F, timeout: Duration) -> Result<Json, String>
    where
        F: FnOnce() -> Result<Json, String> + Send + 'static,
    {
        let cancelled = Arc::new(AtomicBool::new(false));
        let (tx, rx) = channel();
        {
            let mut q = self.inner.lock();
            if q.len() >= self.max_depth {
                return Err(format!(
                    "ueforge: PE queue full ({} >= cap {})",
                    q.len(),
                    self.max_depth
                ));
            }
            q.push(Pending {
                job: Box::new(job),
                reply: tx,
                cancelled: cancelled.clone(),
            });
            self.size.store(q.len(), Ordering::Release);
        }
        match rx.recv_timeout(timeout) {
            Ok(r) => r,
            Err(_) => {
                // Mark the job cancelled so a later drain skips it.
                cancelled.store(true, Ordering::Release);
                Err(format!(
                    "ueforge: timed out after {:?} waiting for game-thread drain",
                    timeout
                ))
            }
        }
    }

    /// Drain and execute every pending job. Call from the game
    /// thread (typically inside a PE trampoline). Cheap when empty
    /// thanks to the lock-free `size` shadow.
    ///
    /// **Canonical drain site.** Pick a UFunction the engine fires
    /// many times per second on the game thread (a damage multicast,
    /// a tick, an input handler) and install a `ProcessEventHook` on
    /// its owning class. From the trampoline body:
    ///
    /// ```ignore
    /// // 1. Cheap empty-check via the lock-free size shadow.
    /// if my_pe_queue.is_empty() {
    ///     // ... real hook work ...
    ///     return original.call(this, function, parms);
    /// }
    /// // 2. Drain. Re-entrance guard inside drain() handles the
    ///    case where a job triggers PE fan-out that re-enters this
    ///    same trampoline.
    /// let stats = my_pe_queue.drain();
    /// // 3. (Optional) feed counters from `stats.peak` /
    ///    `stats.drained` for diagnostic snapshots.
    /// ```
    ///
    /// Picking the drain site matters for cadence: a damage
    /// multicast fires only when the player takes / deals damage,
    /// so off-combat ops can stall for seconds. A character tick
    /// hook fires every frame regardless and is the safer default
    /// for general-purpose drains.
    pub fn drain(&self) -> DrainStats {
        if self.size.load(Ordering::Acquire) == 0 {
            return DrainStats::default();
        }
        if self.draining.swap(true, Ordering::AcqRel) {
            return DrainStats {
                reentered: true,
                ..Default::default()
            };
        }
        let drained = {
            let mut q = self.inner.lock();
            let peak = q.len();
            let taken = std::mem::take(&mut *q);
            self.size.store(0, Ordering::Release);
            (peak, taken)
        };
        let (peak, jobs) = drained;
        let mut count = 0usize;
        for p in jobs {
            // Skip cancelled jobs (caller's enqueue timed out and
            // gave up). Running them anyway would double-execute
            // non-idempotent ops on the next retry.
            if p.cancelled.load(Ordering::Acquire) {
                continue;
            }
            let r = (p.job)();
            let _ = p.reply.send(r);
            count += 1;
        }
        self.draining.store(false, Ordering::Release);
        DrainStats {
            peak,
            drained: count,
            reentered: false,
        }
    }
}

impl Default for Queue {
    fn default() -> Self {
        Self::new()
    }
}

/// `Queue` paired with the standard performance-counter trio
/// (drain calls, drained commands, peak depth, time spent
/// draining). Wraps `Queue::drain` so trampoline drain sites are
/// one line + automatic perf instrumentation -- no more pairing a
/// static Queue with four hand-declared `counter!` statics + a
/// 20-line `drain_pending` wrapper.
///
/// ```ignore
/// static SITE: ueforge::pe_queue::DrainSite = ueforge::pe_queue::DrainSite::new();
///
/// // From a trampoline (game thread):
/// SITE.drain();
///
/// // From an HTTP op (worker thread):
/// SITE.queue().enqueue(|| { /* mutate game state */ }, Duration::from_secs(5))?;
/// ```
pub struct DrainSite {
    queue: Queue,
    drain_calls: std::sync::atomic::AtomicU64,
    drained_cmds: std::sync::atomic::AtomicU64,
    peak: std::sync::atomic::AtomicUsize,
    time_ns: std::sync::atomic::AtomicU64,
}

impl DrainSite {
    pub const fn new() -> Self {
        Self {
            queue: Queue::new(),
            drain_calls: std::sync::atomic::AtomicU64::new(0),
            drained_cmds: std::sync::atomic::AtomicU64::new(0),
            peak: std::sync::atomic::AtomicUsize::new(0),
            time_ns: std::sync::atomic::AtomicU64::new(0),
        }
    }

    /// Borrow the inner Queue for `enqueue` calls from the HTTP
    /// listener side.
    pub fn queue(&self) -> &Queue {
        &self.queue
    }

    /// Drain the queue. Hot-path-safe (one atomic load + branch
    /// when empty). Bumps the drain-calls counter on every
    /// invocation; bumps drained-cmds + observes peak only when
    /// work was actually done. Skips the time-scope on the empty
    /// path so the steady-state cost is just one load.
    pub fn drain(&self) -> DrainStats {
        self.drain_calls
            .fetch_add(1, std::sync::atomic::Ordering::Relaxed);
        if self.queue.is_empty() {
            return DrainStats::default();
        }
        let _t = crate::counters::time_scope(&self.time_ns);
        let stats = self.queue.drain();
        if !stats.reentered {
            crate::counters::observe_peak(&self.peak, stats.peak);
            self.drained_cmds
                .fetch_add(stats.drained as u64, std::sync::atomic::Ordering::Relaxed);
        }
        stats
    }

    pub fn drain_calls(&self) -> u64 {
        self.drain_calls
            .load(std::sync::atomic::Ordering::Relaxed)
    }
    pub fn drained_cmds(&self) -> u64 {
        self.drained_cmds
            .load(std::sync::atomic::Ordering::Relaxed)
    }
    pub fn peak(&self) -> usize {
        self.peak.load(std::sync::atomic::Ordering::Relaxed)
    }
    pub fn time_ns(&self) -> u64 {
        self.time_ns.load(std::sync::atomic::Ordering::Relaxed)
    }

    pub fn len(&self) -> usize {
        self.queue.len()
    }

    pub fn is_empty(&self) -> bool {
        self.queue.is_empty()
    }
}

impl Default for DrainSite {
    fn default() -> Self {
        Self::new()
    }
}
