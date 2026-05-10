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

use std::sync::Mutex;
use std::sync::atomic::{AtomicBool, AtomicUsize, Ordering};
use std::sync::mpsc::{Sender, channel};
use std::time::Duration;

use serde_json::Value as Json;

pub type Job = Box<dyn FnOnce() -> Result<Json, String> + Send>;

struct Pending {
    job: Job,
    reply: Sender<Result<Json, String>>,
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
    /// error string on poisoning, timeout, or job failure.
    pub fn enqueue<F>(&self, job: F, timeout: Duration) -> Result<Json, String>
    where
        F: FnOnce() -> Result<Json, String> + Send + 'static,
    {
        let (tx, rx) = channel();
        {
            let mut q = self.inner.lock().map_err(|_| "ueforge queue poisoned")?;
            q.push(Pending {
                job: Box::new(job),
                reply: tx,
            });
            self.size.store(q.len(), Ordering::Release);
        }
        match rx.recv_timeout(timeout) {
            Ok(r) => r,
            Err(_) => Err(format!(
                "ueforge: timed out after {:?} waiting for game-thread drain",
                timeout
            )),
        }
    }

    /// Drain and execute every pending job. Call from the game
    /// thread (typically inside a PE trampoline). Cheap when empty
    /// thanks to the lock-free `size` shadow.
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
            let mut q = match self.inner.lock() {
                Ok(g) => g,
                Err(_) => {
                    self.draining.store(false, Ordering::Release);
                    return DrainStats::default();
                }
            };
            let peak = q.len();
            let taken = std::mem::take(&mut *q);
            self.size.store(0, Ordering::Release);
            (peak, taken)
        };
        let (peak, jobs) = drained;
        let mut count = 0usize;
        for p in jobs {
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
