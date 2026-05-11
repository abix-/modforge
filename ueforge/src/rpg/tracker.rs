//! Generic RPG tracker. Owns slot binding, in-memory state,
//! disabled-skills toggle set, persistence. Drives every state-
//! changing operation (spend, refund, record_xp, slot
//! activate/deactivate) transactionally with disk save.
//!
//! ```ignore
//! static TRACKER: ueforge::rpg::Tracker = ueforge::rpg::Tracker::new(
//!     &CATALOG,                                  // &'static SkillRegistry
//!     ueforge::rpg::Curve::new(100.0, 1.8, 50),
//!     "saves",
//! );
//!
//! // From the slot poller:
//! TRACKER.activate_slot(playthrough_guid);
//!
//! // From the kill hook:
//! TRACKER.record_xp(base_xp);
//!
//! // From the ImGui tab:
//! TRACKER.spend_skill_points("attack_damage", 1);
//! ```
//!
//! No `<E>` type parameter, no `RpgApplier` trait. Each catalog
//! row's `EffectDef` carries a `&'static dyn Effect` that knows
//! how to apply itself. The tracker just calls
//! `skill.effect.apply(level, max_level)` on every state change.

use parking_lot::Mutex;

use super::{Curve, DisabledSkills, SkillDef, SkillRegistry, SkillsState, SlotStore};

pub struct Tracker {
    inner: Mutex<Option<TrackerInner>>,
    store: SlotStore<SkillsState>,
    catalog: &'static SkillRegistry,
    curve: Curve,
    disabled: DisabledSkills,
}

struct TrackerInner {
    slot: String,
    state: SkillsState,
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

impl Tracker {
    pub const fn new(
        catalog: &'static SkillRegistry,
        curve: Curve,
        store_subdir: &'static str,
    ) -> Self {
        Self {
            inner: Mutex::new(None),
            store: SlotStore::new(store_subdir),
            catalog,
            curve,
            disabled: DisabledSkills::new(),
        }
    }

    /// Borrow the skill registry. Use `.def(id)` for canonical
    /// lookup; `.entries()` for iteration.
    pub fn catalog(&self) -> &'static SkillRegistry {
        self.catalog
    }

    pub fn curve(&self) -> Curve {
        self.curve
    }

    /// Borrow the disabled-skills toggle set.
    pub fn disabled_skills(&self) -> &DisabledSkills {
        &self.disabled
    }

    /// Bind to `slot` and load any prior state. Re-applies every
    /// catalog skill so the world reflects current levels before
    /// the player resumes.
    pub fn activate_slot(&self, slot: String) {
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
        for skill in self.catalog.iter() {
            self.apply_one_unlocked(skill, &state);
        }
        *self.inner.lock() = Some(TrackerInner { slot, state });
    }

    /// Most recent save error from the underlying [`SlotStore`],
    /// if any. Cleared on the next successful save. Snapshot
    /// surface for tests and the debug HTTP endpoint.
    pub fn last_save_error(&self) -> Option<String> {
        self.store.last_error()
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

    /// Format the effect text for a skill at `level`. Doesn't
    /// require an active slot (catalog row alone is enough).
    pub fn format_effect(&self, skill: &SkillDef, level: u32) -> String {
        skill.effect.format(level, skill.max_level)
    }

    /// Apply one skill against a borrowed state, honoring the
    /// disabled toggle (treats disabled as level 0). Fires the
    /// effect with `TriggerCtx::SlotChange`. The trigger kind
    /// that CDO-write effects expect on slot activate / spend /
    /// refund / toggle.
    fn apply_one_unlocked(&self, skill: &SkillDef, state: &SkillsState) {
        let raw_level = state.level_of(skill.id);
        let effective_level = if self.disabled.is_disabled(skill.id) {
            0
        } else {
            raw_level
        };
        skill.effect.apply(
            effective_level,
            skill.max_level,
            &crate::rpg::TriggerCtx::SlotChange,
        );
    }

    /// Spend up to `count` points on `skill_id`. Returns the
    /// number actually spent (capped by `state.skill_points` and
    /// `skill.max_level`). Persists on success.
    ///
    /// Save-first, apply-second. If the disk save fails (full disk,
    /// EACCES, etc.) the in-memory mutation is rolled back and
    /// `apply` is NOT called. So the session reflects what is
    /// actually on disk. Returns 0 on save failure; the caller can
    /// read [`Self::last_save_error`] for the cause.
    pub fn spend_skill_points(&self, skill_id: &str, count: u32) -> u32 {
        let mut g = self.inner.lock();
        let Some(t) = g.as_mut() else {
            crate::log!("rpg/tracker: spend({}) ignored, no slot active", skill_id);
            return 0;
        };
        let Some(skill) = self.catalog.def(skill_id) else {
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
        let prev_skill_points = t.state.skill_points;
        let prev_level_entry = t.state.skill_levels.get(skill_id).copied();
        t.state.skill_points -= spend;
        let new_level = cur + spend;
        t.state.skill_levels.insert(skill_id.to_string(), new_level);
        if let Err(e) = self.store.save(&t.slot, &t.state) {
            t.state.skill_points = prev_skill_points;
            match prev_level_entry {
                Some(v) => {
                    t.state.skill_levels.insert(skill_id.to_string(), v);
                }
                None => {
                    t.state.skill_levels.remove(skill_id);
                }
            }
            crate::log!(
                "rpg/tracker: spend({}) save failed ({}); rolled back",
                skill_id,
                e
            );
            return 0;
        }
        self.apply_one_unlocked(skill, &t.state);
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
    /// number actually refunded. Save-first; on save failure, rolls
    /// back the in-memory mutation and returns 0.
    pub fn refund_skill_points(&self, skill_id: &str, count: u32) -> u32 {
        let mut g = self.inner.lock();
        let Some(t) = g.as_mut() else {
            return 0;
        };
        let Some(skill) = self.catalog.def(skill_id) else {
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
        let prev_skill_points = t.state.skill_points;
        let prev_level_entry = t.state.skill_levels.get(skill_id).copied();
        if new_level == 0 {
            t.state.skill_levels.remove(skill_id);
        } else {
            t.state
                .skill_levels
                .insert(skill_id.to_string(), new_level);
        }
        t.state.skill_points = t.state.skill_points.saturating_add(refund);
        if let Err(e) = self.store.save(&t.slot, &t.state) {
            t.state.skill_points = prev_skill_points;
            match prev_level_entry {
                Some(v) => {
                    t.state.skill_levels.insert(skill_id.to_string(), v);
                }
                None => {
                    t.state.skill_levels.remove(skill_id);
                }
            }
            crate::log!(
                "rpg/tracker: refund({}) save failed ({}); rolled back",
                skill_id,
                e
            );
            return 0;
        }
        self.apply_one_unlocked(skill, &t.state);
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
        let Some(skill) = self.catalog.def(skill_id) else {
            return;
        };
        self.apply_one_unlocked(skill, &t.state);
    }

    /// Re-apply every skill in the catalog. Used by the debug
    /// `reload_slot` op.
    pub fn reapply_all(&self) -> bool {
        let g = self.inner.lock();
        let Some(t) = g.as_ref() else { return false };
        for skill in self.catalog.iter() {
            self.apply_one_unlocked(skill, &t.state);
        }
        true
    }

    /// Award `awarded` XP and recompute level. Returns the
    /// XpResult so callers can log "LEVEL UP!" feedback. Returns
    /// `None` if no slot is active OR if the disk save failed (in
    /// which case the in-memory state is rolled back so the
    /// session matches what is actually persisted).
    pub fn record_xp(&self, awarded: u64) -> Option<XpResult> {
        let mut g = self.inner.lock();
        let t = g.as_mut()?;
        let old_level = t.state.level;
        let prev_xp = t.state.xp;
        let prev_skill_points = t.state.skill_points;
        t.state.xp = t.state.xp.saturating_add(awarded);
        let new_level = self.curve.level_for_xp(t.state.xp);
        let levelled = new_level > old_level;
        let points_gained = if levelled { new_level - old_level } else { 0 };
        if levelled {
            t.state.level = new_level;
            t.state.skill_points = t.state.skill_points.saturating_add(points_gained);
        }
        if let Err(e) = self.store.save(&t.slot, &t.state) {
            t.state.xp = prev_xp;
            t.state.level = old_level;
            t.state.skill_points = prev_skill_points;
            crate::log!("rpg/tracker: record_xp save failed ({e}); rolled back");
            return None;
        }
        if levelled {
            crate::log!(
                "rpg/tracker: LEVEL UP! {old_level} -> {new_level} (+{points_gained} skill points; total {})",
                t.state.skill_points
            );
        }
        Some(XpResult {
            awarded,
            total_xp: t.state.xp,
            old_level,
            new_level,
            points_gained,
        })
    }

    /// Grant `n` skill points without earning them. For dev /
    /// debug ops only. Save-first; rolls back on save fail.
    pub fn debug_grant_skill_points(&self, n: u32) -> bool {
        let mut g = self.inner.lock();
        let Some(t) = g.as_mut() else { return false };
        let prev_skill_points = t.state.skill_points;
        t.state.skill_points = t.state.skill_points.saturating_add(n);
        if let Err(e) = self.store.save(&t.slot, &t.state) {
            t.state.skill_points = prev_skill_points;
            crate::log!(
                "rpg/tracker: debug_grant_skill_points save failed ({e}); rolled back"
            );
            return false;
        }
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
