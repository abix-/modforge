//! Process-global "disabled skills" set. Disabling treats a skill
//! as level 0 in the apply path without refunding the player's
//! points -- used for "drop a buff on demand" toggles in the ImGui
//! tab. Not persisted.
//!
//! Stored as `&'static str` IDs to match the way catalogs are
//! declared (one `pub const SKILL_FOO: &str = "foo";` per skill).
//!
//! Reads are lock-free (`ArcSwap<Arc<HashSet<...>>>`), one atomic
//! load + Arc clone + hashset lookup. Writes take a `parking_lot::
//! Mutex` only long enough to clone-modify-publish the new set.
//! The ImGui tab calls `is_disabled` per skill row per frame; the
//! apply path calls it per CDO walk. Both stay on the read-fast
//! path even with frequent toggles.

use std::collections::HashSet;
use std::sync::Arc;
use std::sync::OnceLock;

use arc_swap::ArcSwap;
use parking_lot::Mutex;

pub struct DisabledSkills {
    /// Read-fast snapshot. Trampolines / render path read this.
    snapshot: OnceLock<ArcSwap<HashSet<&'static str>>>,
    /// Writer guard. Held only to clone-modify-publish.
    write: Mutex<()>,
}

impl DisabledSkills {
    pub const fn new() -> Self {
        Self {
            snapshot: OnceLock::new(),
            write: Mutex::new(()),
        }
    }

    fn snapshot_cell(&self) -> &ArcSwap<HashSet<&'static str>> {
        self.snapshot
            .get_or_init(|| ArcSwap::from_pointee(HashSet::new()))
    }

    /// Read-only check. One atomic load + Arc clone + hashset
    /// lookup. Suitable for hot paths (ImGui per-row, apply per
    /// CDO).
    pub fn is_disabled(&self, id: &str) -> bool {
        self.snapshot_cell().load().contains(id)
    }

    /// Set the toggle. Returns the new disabled state (true =
    /// disabled). Takes the writer lock briefly while it
    /// clone-modify-publishes the new set; readers see the
    /// pre-publish set until the swap completes (atomic).
    pub fn set(&self, id: &'static str, disabled: bool) -> bool {
        let _guard = self.write.lock();
        let cell = self.snapshot_cell();
        let mut next: HashSet<&'static str> = (**cell.load()).clone();
        if disabled {
            next.insert(id);
        } else {
            next.remove(id);
        }
        let was_disabled = next.contains(id);
        cell.store(Arc::new(next));
        was_disabled
    }

    /// Snapshot of every currently-disabled skill ID.
    /// Cold-path -- clones into a sorted Vec.
    pub fn snapshot(&self) -> Vec<&'static str> {
        let s = self.snapshot_cell().load();
        let mut v: Vec<&'static str> = s.iter().copied().collect();
        v.sort_unstable();
        v
    }
}

impl Default for DisabledSkills {
    fn default() -> Self {
        Self::new()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn empty_initially() {
        let d = DisabledSkills::new();
        assert!(!d.is_disabled("anything"));
        assert!(d.snapshot().is_empty());
    }

    #[test]
    fn set_and_clear() {
        let d = DisabledSkills::new();
        assert!(d.set("foo", true));
        assert!(d.is_disabled("foo"));
        assert!(!d.set("foo", false));
        assert!(!d.is_disabled("foo"));
    }

    #[test]
    fn snapshot_sorts() {
        let d = DisabledSkills::new();
        d.set("zebra", true);
        d.set("apple", true);
        d.set("monkey", true);
        assert_eq!(d.snapshot(), vec!["apple", "monkey", "zebra"]);
    }

    #[test]
    fn const_constructible() {
        const _D: DisabledSkills = DisabledSkills::new();
    }
}
