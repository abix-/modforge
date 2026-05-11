//! Per-key vanilla-baseline cache.
//!
//! `VanillaCache<K, V>` captures the un-modified value of a field
//! the *first* time the apply path observes it, then returns that
//! value forever after. Lets level/refund/toggle paths restore the
//! true baseline without re-reading whatever the mod has already
//! overwritten.
//!
//! Pattern in apply code:
//!
//! ```ignore
//! static MOVEMENT_VANILLA: VanillaCache<usize, f32> = VanillaCache::new();
//!
//! // First time we touch `offset`, the engine value is captured.
//! // Subsequent reads return the same captured baseline regardless
//! // of what the mod has written to the field.
//! let baseline = MOVEMENT_VANILLA.get_or_init(offset, current_value);
//! let new_value = baseline * scale;
//! write_field(obj, offset, new_value);
//! ```
//!
//! Replaces `Mutex<Vec<(K, V)>>` + `set_if_unset` + `get` boilerplate
//! that every RPG mod ends up writing on top of `apply.rs`.
//!
//! For single-baseline cases (one `K` makes no sense), reach for
//! `std::sync::OnceLock<V>` directly. Already canonical.

use parking_lot::Mutex;

pub struct VanillaCache<K, V> {
    entries: Mutex<Vec<(K, V)>>,
}

impl<K, V> Default for VanillaCache<K, V> {
    fn default() -> Self {
        Self::new()
    }
}

impl<K, V> VanillaCache<K, V> {
    pub const fn new() -> Self {
        Self {
            entries: Mutex::new(Vec::new()),
        }
    }

    /// Number of distinct keys captured so far.
    pub fn len(&self) -> usize {
        self.entries.lock().len()
    }

    pub fn is_empty(&self) -> bool {
        self.entries.lock().is_empty()
    }

    /// Drop every captured baseline. Useful for re-snapshotting
    /// after a slot reload that rebound the underlying objects.
    pub fn clear(&self) {
        self.entries.lock().clear();
    }
}

impl<K: Eq + Copy, V: Copy> VanillaCache<K, V> {
    /// Capture `value` for `key` if not already captured. Returns
    /// the stored baseline. The previously-captured value if `key`
    /// was already seen, else `value`.
    pub fn get_or_init(&self, key: K, value: V) -> V {
        let mut g = self.entries.lock();
        if let Some((_, existing)) = g.iter().find(|(k, _)| *k == key) {
            return *existing;
        }
        g.push((key, value));
        value
    }

    /// Capture `value` for `key` only if `key` was not yet seen.
    /// Returns true on insert, false if already present.
    pub fn set_if_unset(&self, key: K, value: V) -> bool {
        let mut g = self.entries.lock();
        if g.iter().any(|(k, _)| *k == key) {
            return false;
        }
        g.push((key, value));
        true
    }

    /// Look up the captured baseline. None if the key has not been
    /// seen yet.
    pub fn get(&self, key: K) -> Option<V> {
        self.entries
            .lock()
            .iter()
            .find(|(k, _)| *k == key)
            .map(|(_, v)| *v)
    }

    /// Snapshot of the entire cache. Cold-path use only. Clones
    /// the backing vector under the lock.
    pub fn snapshot(&self) -> Vec<(K, V)> {
        self.entries.lock().clone()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn first_call_captures() {
        let c: VanillaCache<usize, f32> = VanillaCache::new();
        assert_eq!(c.get_or_init(0x10, 1.5), 1.5);
        assert_eq!(c.get(0x10), Some(1.5));
        assert_eq!(c.len(), 1);
    }

    #[test]
    fn subsequent_calls_return_baseline() {
        let c: VanillaCache<usize, f32> = VanillaCache::new();
        c.get_or_init(0x10, 1.5);
        // Even when later code passes a different value, the
        // baseline wins.
        assert_eq!(c.get_or_init(0x10, 99.0), 1.5);
        assert_eq!(c.len(), 1);
    }

    #[test]
    fn distinct_keys_distinct_baselines() {
        let c: VanillaCache<usize, f32> = VanillaCache::new();
        c.get_or_init(0x10, 1.5);
        c.get_or_init(0x20, 2.5);
        assert_eq!(c.get(0x10), Some(1.5));
        assert_eq!(c.get(0x20), Some(2.5));
        assert_eq!(c.len(), 2);
    }

    #[test]
    fn set_if_unset_returns_insert_flag() {
        let c: VanillaCache<&str, u32> = VanillaCache::new();
        assert!(c.set_if_unset("a", 7));
        assert!(!c.set_if_unset("a", 99));
        assert_eq!(c.get("a"), Some(7));
    }

    #[test]
    fn clear_resets() {
        let c: VanillaCache<usize, f32> = VanillaCache::new();
        c.get_or_init(0x10, 1.5);
        c.clear();
        assert!(c.is_empty());
        assert_eq!(c.get_or_init(0x10, 9.0), 9.0);
    }

    #[test]
    fn snapshot_clones_entries() {
        let c: VanillaCache<usize, f32> = VanillaCache::new();
        c.get_or_init(0x10, 1.5);
        c.get_or_init(0x20, 2.5);
        let snap = c.snapshot();
        assert_eq!(snap.len(), 2);
    }

    #[test]
    fn const_constructible() {
        const _C: VanillaCache<usize, f32> = VanillaCache::new();
    }
}
