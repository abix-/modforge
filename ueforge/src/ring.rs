//! Bounded drop-oldest ring buffer for capturing hook events.
//!
//! Pattern: a hook trampoline (damage multicast, tick, anything
//! firing many times per second) calls `Ring::push(event)`. The
//! ring keeps at most `capacity` items, dropping the oldest on
//! overflow so a long session can't exhaust memory. The
//! `/debug snapshot` op clones the contents into the response.
//!
//! Mutex-protected (`parking_lot::Mutex`, no poisoning). Push is
//! rare relative to gameplay; clone is once per snapshot request
//! (low rate). If contention ever shows up, swap to a lock-free
//! SPSC and a per-frame drain.

use parking_lot::Mutex;

pub struct Ring<T> {
    inner: Mutex<Vec<T>>,
    capacity: usize,
}

impl<T> Ring<T> {
    pub const fn new(capacity: usize) -> Self {
        Self {
            inner: Mutex::new(Vec::new()),
            capacity,
        }
    }

    /// Append an item. If the ring is at capacity, the oldest
    /// item is dropped first. Returns the new length.
    pub fn push(&self, item: T) -> usize {
        let mut g = self.inner.lock();
        g.push(item);
        let n = g.len();
        if n > self.capacity {
            g.drain(0..n - self.capacity);
        }
        g.len()
    }

    /// Snapshot a copy of the ring contents.
    pub fn snapshot(&self) -> Vec<T>
    where
        T: Clone,
    {
        self.inner.lock().clone()
    }

    pub fn len(&self) -> usize {
        self.inner.lock().len()
    }

    pub fn is_empty(&self) -> bool {
        self.len() == 0
    }

    pub fn capacity(&self) -> usize {
        self.capacity
    }
}
