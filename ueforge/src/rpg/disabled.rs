//! Process-global "disabled skills" set. Disabling treats a skill
//! as level 0 in the apply path without refunding the player's
//! points -- used for "drop a buff on demand" toggles in the ImGui
//! tab. Not persisted.
//!
//! Stored as `&'static str` IDs to match the way catalogs are
//! declared (one `pub const SKILL_FOO: &str = "foo";` per skill).

use std::collections::HashSet;
use std::sync::OnceLock;

use parking_lot::Mutex;

pub struct DisabledSkills {
    inner: OnceLock<Mutex<HashSet<&'static str>>>,
}

impl DisabledSkills {
    pub const fn new() -> Self {
        Self {
            inner: OnceLock::new(),
        }
    }

    fn lock(&self) -> parking_lot::MutexGuard<'_, HashSet<&'static str>> {
        self.inner.get_or_init(|| Mutex::new(HashSet::new())).lock()
    }

    pub fn is_disabled(&self, id: &str) -> bool {
        self.lock().contains(id)
    }

    /// Set the toggle. Returns the new disabled state (true =
    /// disabled).
    pub fn set(&self, id: &'static str, disabled: bool) -> bool {
        let mut g = self.lock();
        if disabled {
            g.insert(id);
        } else {
            g.remove(id);
        }
        g.contains(id)
    }

    pub fn snapshot(&self) -> Vec<&'static str> {
        let mut v: Vec<&'static str> = self.lock().iter().copied().collect();
        v.sort_unstable();
        v
    }
}

impl Default for DisabledSkills {
    fn default() -> Self {
        Self::new()
    }
}
