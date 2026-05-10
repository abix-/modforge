//! Generic RPG tracker. Owns slot binding, in-memory state,
//! Applier instance, persistence. Drives every state-changing
//! operation (spend, refund, record_xp, slot activate/deactivate)
//! transactionally with disk save.
//!
//! Game crates instantiate one `static`:
//!
//! ```ignore
//! static TRACKER: ueforge::rpg::Tracker<GameApplier> =
//!     ueforge::rpg::Tracker::new(CATALOG, ueforge::rpg::Curve::new(100.0, 1.8, 50), "saves");
//!
//! // From the slot poller:
//! TRACKER.activate_slot(playthrough_guid, GameApplier { settings });
//!
//! // From the kill hook:
//! TRACKER.record_xp(base_xp);
//!
//! // From the ImGui tab:
//! TRACKER.spend_skill_points(skill, 1);
//! ```

use parking_lot::Mutex;

use super::{Curve, RpgApplier, Skill, SkillsState, SlotStore};

pub struct Tracker<A: RpgApplier> {
    inner: Mutex<Option<TrackerInner<A>>>,
    store: SlotStore<SkillsState>,
    catalog: &'static [Skill<A::Effect>],
    curve: Curve,
}

struct TrackerInner<A: RpgApplier> {
    slot: String,
    state: SkillsState,
    applier: A,
}

/// What happened to the player's level on a record_xp call. Use by
/// the kill hook for "LEVEL UP!" log lines and feedback effects.
#[derive(Debug, Clone, Copy)]
pub struct XpResult {
    pub awarded: u64,
    pub total_xp: u64,
    pub old_level: u32,
    pub new_level: u32,
    pub points_gained: u32,
}

impl XpResult {
    pub fn levelled(&self) -> bool {
        self.new_level > self.old_level
    }
}

impl<A: RpgApplier> Tracker<A> {
    pub const fn new(
        catalog: &'static [Skill<A::Effect>],
        curve: Curve,
        store_subdir: &'static str,
    ) -> Self {
        Self {
            inner: Mutex::new(None),
            store: SlotStore::new(store_subdir),
            catalog,
            curve,
        }
    }

    pub fn catalog(&self) -> &'static [Skill<A::Effect>] {
        self.catalog
    }

    pub fn curve(&self) -> Curve {
        self.curve
    }

    /// Bind to `slot` and load any prior state. Calls
    /// `applier.apply_all` on the loaded state so the world
    /// reflects current skill levels before the player resumes.
    pub fn activate_slot(&self, slot: String, applier: A) {
        let mut state = self.store.load(&slot);
        let derived = self.curve.level_for_xp(state.xp);
        if state.level < derived {
            state.level = derived;
        }
        crate::log!(
            "rpg/tracker: activated slot={} level={} xp={} skill_points={}",
            short(&slot),
            state.level,
            state.xp,
            state.skill_points,
        );
        applier.apply_all(&state, self.catalog);
        *self.inner.lock() = Some(TrackerInner {
            slot,
            state,
            applier,
        });
    }

    pub fn deactivate_slot(&self) {
        let mut g = self.inner.lock();
        if let Some(t) = g.take() {
            crate::log!("rpg/tracker: deactivated slot={}", short(&t.slot));
        }
    }

    pub fn current_slot(&self) -> Option<String> {
        self.inner.lock().as_ref().map(|t| t.slot.clone())
    }

    /// Read-only snapshot of the current state. None if no slot.
    pub fn with_state<R>(&self, f: impl FnOnce(&SkillsState) -> R) -> Option<R> {
        self.inner.lock().as_ref().map(|t| f(&t.state))
    }

    /// Format the effect text for a skill at `level` via the
    /// Applier. None if no slot is active.
    pub fn format_effect(
        &self,
        skill: &Skill<A::Effect>,
        level: u32,
    ) -> Option<String> {
        self.inner
            .lock()
            .as_ref()
            .map(|t| t.applier.format_effect(skill, level))
    }

    /// Spend up to `count` points on `skill_id`. Returns the
    /// number actually spent (capped by `state.skill_points` and
    /// `skill.max_level`). Persists on success.
    pub fn spend_skill_points(&self, skill_id: &str, count: u32) -> u32 {
        let mut g = self.inner.lock();
        let Some(t) = g.as_mut() else {
            crate::log!("rpg/tracker: spend({}) ignored, no slot active", skill_id);
            return 0;
        };
        let Some(skill) = super::find_skill(self.catalog, skill_id) else {
            crate::log!("rpg/tracker: unknown skill id '{}'", skill_id);
            return 0;
        };
        if count == 0 {
            return 0;
        }
        let cur = t.state.level_of(skill_id);
        if cur >= skill.max_level {
            return 0;
        }
        let max_by_level = skill.max_level - cur;
        let spend = count.min(t.state.skill_points).min(max_by_level);
        if spend == 0 {
            return 0;
        }
        t.state.skill_points -= spend;
        let new_level = cur + spend;
        t.state.skill_levels.insert(skill_id.to_string(), new_level);
        t.applier.apply_skill(&t.state, skill);
        self.store.save(&t.slot, &t.state);
        crate::log!(
            "rpg/tracker: spent {} on {}: level {} -> {} ({} points left)",
            spend,
            skill_id,
            cur,
            new_level,
            t.state.skill_points
        );
        spend
    }

    /// Refund up to `count` points from `skill_id`. Returns the
    /// number actually refunded.
    pub fn refund_skill_points(&self, skill_id: &str, count: u32) -> u32 {
        let mut g = self.inner.lock();
        let Some(t) = g.as_mut() else {
            return 0;
        };
        let Some(skill) = super::find_skill(self.catalog, skill_id) else {
            return 0;
        };
        if count == 0 {
            return 0;
        }
        let cur = t.state.level_of(skill_id);
        if cur == 0 {
            return 0;
        }
        let refund = count.min(cur);
        let new_level = cur - refund;
        if new_level == 0 {
            t.state.skill_levels.remove(skill_id);
        } else {
            t.state
                .skill_levels
                .insert(skill_id.to_string(), new_level);
        }
        t.state.skill_points = t.state.skill_points.saturating_add(refund);
        t.applier.apply_skill(&t.state, skill);
        self.store.save(&t.slot, &t.state);
        crate::log!(
            "rpg/tracker: refunded {} from {}: level {} -> {} ({} points)",
            refund,
            skill_id,
            cur,
            new_level,
            t.state.skill_points
        );
        refund
    }

    /// Re-apply a single skill to the live world (used by the
    /// "on" toggle in the ImGui tab to drop / restore the buff
    /// without changing the level).
    pub fn reapply_one(&self, skill_id: &str) {
        let g = self.inner.lock();
        let Some(t) = g.as_ref() else { return };
        let Some(skill) = super::find_skill(self.catalog, skill_id) else {
            return;
        };
        t.applier.apply_skill(&t.state, skill);
    }

    /// Re-apply every skill in the catalog. Used by the debug
    /// `reload_slot` op.
    pub fn reapply_all(&self) -> bool {
        let g = self.inner.lock();
        let Some(t) = g.as_ref() else { return false };
        t.applier.apply_all(&t.state, self.catalog);
        true
    }

    /// Award `awarded` XP and recompute level. Returns the
    /// XpResult so callers can log "LEVEL UP!" feedback.
    pub fn record_xp(&self, awarded: u64) -> Option<XpResult> {
        let mut g = self.inner.lock();
        let t = g.as_mut()?;
        let old_level = t.state.level;
        t.state.xp = t.state.xp.saturating_add(awarded);
        let new_level = self.curve.level_for_xp(t.state.xp);
        let levelled = new_level > old_level;
        let points_gained = if levelled { new_level - old_level } else { 0 };
        if levelled {
            t.state.level = new_level;
            t.state.skill_points = t.state.skill_points.saturating_add(points_gained);
            crate::log!(
                "rpg/tracker: LEVEL UP! {old_level} -> {new_level} (+{points_gained} skill points; total {})",
                t.state.skill_points
            );
        }
        self.store.save(&t.slot, &t.state);
        Some(XpResult {
            awarded,
            total_xp: t.state.xp,
            old_level,
            new_level,
            points_gained,
        })
    }

    /// Grant `n` skill points without earning them. For dev /
    /// debug ops only.
    pub fn debug_grant_skill_points(&self, n: u32) -> bool {
        let mut g = self.inner.lock();
        let Some(t) = g.as_mut() else { return false };
        t.state.skill_points = t.state.skill_points.saturating_add(n);
        self.store.save(&t.slot, &t.state);
        crate::log!(
            "rpg/tracker: DEBUG granted +{n} skill points (total {})",
            t.state.skill_points
        );
        true
    }
}

fn short(slot: &str) -> &str {
    if slot.len() >= 8 { &slot[..8] } else { slot }
}
