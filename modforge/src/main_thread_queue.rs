//! Main-thread job queue. Parallel to `ueforge::pe_queue`.
//!
//! HTTP POST handlers run on the listener thread. Anything that
//! touches engine state (Mono through the unityforge bridge, Godot
//! objects through godotforge) must run on the engine's main thread
//! or the engine crashes. The pattern: POST handlers queue closures
//! here; the forge's per-frame callback (Unity `Update`, Godot
//! `_process`) drains the queue every frame.
//!
//! Lock-free fast path: an `AtomicUsize` shadow of the queue
//! length lets the per-frame drain bail with a single relaxed
//! load when nothing is queued.

use std::sync::atomic::{AtomicUsize, Ordering};

use parking_lot::Mutex;

type Job = Box<dyn FnOnce() + Send + 'static>;

pub struct MainThreadQueue {
    inner: Mutex<Vec<Job>>,
    pending: AtomicUsize,
}

impl MainThreadQueue {
    pub const fn new() -> Self {
        Self {
            inner: Mutex::new(Vec::new()),
            pending: AtomicUsize::new(0),
        }
    }

    /// Enqueue a job. Returns the new pending count.
    pub fn push<F>(&self, job: F) -> usize
    where
        F: FnOnce() + Send + 'static,
    {
        let mut g = self.inner.lock();
        g.push(Box::new(job));
        let n = g.len();
        self.pending.store(n, Ordering::Relaxed);
        n
    }

    /// Drain up to `budget` jobs. Returns how many ran. Called
    /// once per frame from the engine's per-frame callback.
    pub fn drain(&self, budget: usize) -> usize {
        // Fast path: nothing to do.
        if self.pending.load(Ordering::Relaxed) == 0 {
            return 0;
        }

        let mut jobs: Vec<Job> = Vec::with_capacity(budget);
        {
            let mut g = self.inner.lock();
            let take = g.len().min(budget);
            jobs.extend(g.drain(0..take));
            let remaining = g.len();
            self.pending.store(remaining, Ordering::Relaxed);
        }

        let n = jobs.len();
        for job in jobs {
            let _ = std::panic::catch_unwind(std::panic::AssertUnwindSafe(job));
        }
        n
    }

    /// Enqueue `f` and block until the drain runs it, up to
    /// `timeout`. The run-on-main-and-wait pattern every op that
    /// touches the engine needs (on IL2CPP an off-main native call
    /// is a process crash, not an exception).
    pub fn run<T, F>(&self, label: &str, timeout: std::time::Duration, f: F) -> Result<T, String>
    where
        T: Send + 'static,
        F: FnOnce() -> T + Send + 'static,
    {
        use std::sync::Arc;
        let result: Arc<Mutex<Option<T>>> = Arc::new(Mutex::new(None));
        let r2 = result.clone();
        self.push(move || {
            *r2.lock() = Some(f());
        });
        let deadline = std::time::Instant::now() + timeout;
        loop {
            if let Some(r) = result.lock().take() {
                return Ok(r);
            }
            if std::time::Instant::now() >= deadline {
                return Err(format!("{label}: main-thread queue timed out"));
            }
            std::thread::sleep(std::time::Duration::from_millis(5));
        }
    }

    /// Run a fallible main-thread operation and flatten its result.
    pub fn run_result<T, F>(
        &self,
        label: &str,
        timeout: std::time::Duration,
        f: F,
    ) -> Result<T, String>
    where
        T: Send + 'static,
        F: FnOnce() -> Result<T, String> + Send + 'static,
    {
        self.run(label, timeout, f)?
    }

    pub fn len(&self) -> usize {
        self.pending.load(Ordering::Relaxed)
    }

    pub fn is_empty(&self) -> bool {
        self.len() == 0
    }
}

impl Default for MainThreadQueue {
    fn default() -> Self {
        Self::new()
    }
}

pub static MAIN_QUEUE: MainThreadQueue = MainThreadQueue::new();

#[cfg(test)]
mod tests {
    use super::*;
    use std::time::Duration;

    #[test]
    fn drain_runs_jobs_up_to_budget_and_keeps_the_rest() {
        let q = MainThreadQueue::new();
        let ran = std::sync::Arc::new(AtomicUsize::new(0));
        for _ in 0..5 {
            let r = ran.clone();
            q.push(move || {
                r.fetch_add(1, Ordering::Relaxed);
            });
        }
        assert_eq!(q.drain(3), 3);
        assert_eq!(ran.load(Ordering::Relaxed), 3);
        assert_eq!(q.len(), 2);
        assert_eq!(q.drain(10), 2);
        assert!(q.is_empty());
    }

    #[test]
    fn run_times_out_when_nothing_drains() {
        let q = MainThreadQueue::new();
        let r = q.run("t", Duration::from_millis(20), || 1);
        assert_eq!(r, Err("t: main-thread queue timed out".to_string()));
    }
}
