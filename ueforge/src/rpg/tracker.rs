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
    /// effect with `TriggerCtx::SlotChange`.
    ///
    /// Only OnSlotChange-kinded skills are applied here. Event-
    /// driven skills (OnDamageDealt / OnDamageTaken / OnKill /
    /// OnFall) re-fire on their respective events via
    /// [`Self::fire`]; firing them with `SlotChange` would be a
    /// spurious wrong-variant call.
    fn apply_one_unlocked(&self, skill: &SkillDef, state: &SkillsState) {
        if skill.trigger.kind != "OnSlotChange" {
            return;
        }
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

    /// Fire `ctx` to every skill whose trigger kind matches the
    /// `ctx` variant. The event-driven dispatch surface for
    /// OnDamageDealt / OnDamageTaken / OnKill / OnFall.
    ///
    /// Hot-path safe:
    ///
    /// - The catalog is walked under a single `inner.lock()` to
    ///   snapshot `(skill, level)` pairs for subscribed skills,
    ///   then the lock is dropped before any [`Effect::apply`] runs.
    ///   So an effect that re-enters the tracker (e.g. an OnKill
    ///   effect calling [`Self::record_xp`]) does not deadlock.
    /// - Snapshots land in a fixed-size stack array, not a `Vec`.
    ///   `MAX_SUBS = 32` is well above the realistic per-trigger
    ///   subscriber count (catalogs run ~25 skills total).
    /// - No-slot / no-subscriber cases bail before touching the
    ///   `SkillsState`.
    ///
    /// Caller wires this from the trampoline that decoded the
    /// event: `tracker.fire(&TriggerCtx::Kill(&kill_event))`.
    pub fn fire(&self, ctx: &crate::rpg::TriggerCtx) {
        let kind = match ctx {
            crate::rpg::TriggerCtx::SlotChange => "OnSlotChange",
            crate::rpg::TriggerCtx::DamageDealt(_) => "OnDamageDealt",
            crate::rpg::TriggerCtx::DamageTaken(_) => "OnDamageTaken",
            crate::rpg::TriggerCtx::Kill(_) => "OnKill",
            crate::rpg::TriggerCtx::Fall(_) => "OnFall",
            crate::rpg::TriggerCtx::Tick { .. } => "Tick",
        };

        const MAX_SUBS: usize = 32;
        let mut subs: [(Option<&'static SkillDef>, u32); MAX_SUBS] =
            [(None, 0); MAX_SUBS];
        let mut n = 0usize;
        {
            let g = self.inner.lock();
            let Some(t) = g.as_ref() else { return };
            for skill in self.catalog.iter() {
                if skill.trigger.kind != kind {
                    continue;
                }
                if self.disabled.is_disabled(skill.id) {
                    continue;
                }
                let level = t.state.level_of(skill.id);
                if level == 0 {
                    continue;
                }
                if n < MAX_SUBS {
                    subs[n] = (Some(skill), level);
                    n += 1;
                }
            }
        }
        for i in 0..n {
            if let (Some(skill), level) = subs[i] {
                skill.effect.apply(level, skill.max_level, ctx);
            }
        }
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

#[cfg(test)]
mod tests {
    use super::*;
    use crate::rpg::{
        trigger, Effect, EffectDef, FallEvent, KillEvent, SkillDef, SkillRegistry,
        TriggerCtx,
    };
    use std::sync::atomic::{AtomicU32, Ordering};

    struct CountingEffect {
        fires: AtomicU32,
        last_level: AtomicU32,
    }

    impl Effect for CountingEffect {
        fn apply(&self, level: u32, _max_level: u32, _ctx: &TriggerCtx) {
            self.fires.fetch_add(1, Ordering::Relaxed);
            self.last_level.store(level, Ordering::Relaxed);
        }
        fn format(&self, _l: u32, _m: u32) -> String {
            String::new()
        }
    }

    // Statics for the fake catalog (effects need 'static).
    static FX_KILL: CountingEffect = CountingEffect {
        fires: AtomicU32::new(0),
        last_level: AtomicU32::new(0),
    };
    static FX_FALL: CountingEffect = CountingEffect {
        fires: AtomicU32::new(0),
        last_level: AtomicU32::new(0),
    };
    static FX_SLOT: CountingEffect = CountingEffect {
        fires: AtomicU32::new(0),
        last_level: AtomicU32::new(0),
    };

    static FIRE_CATALOG: SkillRegistry = SkillRegistry::new(&[
        SkillDef {
            id: "fire_kill",
            display_name: "kill",
            max_level: 10,
            effect: EffectDef::new("Counting", &FX_KILL),
            trigger: &trigger::ON_KILL,
        },
        SkillDef {
            id: "fire_fall",
            display_name: "fall",
            max_level: 10,
            effect: EffectDef::new("Counting", &FX_FALL),
            trigger: &trigger::ON_FALL,
        },
        SkillDef {
            id: "fire_slot",
            display_name: "slot",
            max_level: 10,
            effect: EffectDef::new("Counting", &FX_SLOT),
            trigger: &trigger::ON_SLOT_CHANGE,
        },
    ]);

    // Stable static byte buffer cast to `&UObject`. The fake
    // effects in this test never deref the reference; they only
    // increment counters. So the pointer just needs to be
    // non-null and well-aligned. Aligning to 16 covers UObject's
    // vtable + pointer fields.
    #[repr(C, align(16))]
    struct FakeObj([u8; 256]);
    static FAKE_OBJ: FakeObj = FakeObj([0; 256]);
    fn fake_uobject() -> &'static crate::ue::UObject {
        unsafe { &*(&FAKE_OBJ as *const FakeObj as *const crate::ue::UObject) }
    }

    fn reset_counters() {
        FX_KILL.fires.store(0, Ordering::Relaxed);
        FX_FALL.fires.store(0, Ordering::Relaxed);
        FX_SLOT.fires.store(0, Ordering::Relaxed);
        FX_KILL.last_level.store(0, Ordering::Relaxed);
        FX_FALL.last_level.store(0, Ordering::Relaxed);
        FX_SLOT.last_level.store(0, Ordering::Relaxed);
    }

    fn make_tracker() -> Tracker {
        // SlotStore writes under DLL dir; for these tests we
        // activate with an in-memory state by going through
        // activate_slot on a tempdir-backed store. The simpler
        // route: just call activate_slot then spend to set levels.
        Tracker::new(&FIRE_CATALOG, Curve::new(100.0, 1.8, 50), "fire_test_slots")
    }

    // The whole `fire` surface is exercised in one sequential
    // test. The Effect impls + catalog are `'static` and tests
    // run in parallel by default, so splitting into multiple
    // `#[test]` functions would cross-contaminate the shared
    // counters.
    #[test]
    fn fire_dispatches_by_kind_and_respects_state() {
        reset_counters();
        let t = make_tracker();

        // Phase 1: fire before slot active -> no fires.
        let fev = FallEvent {
            player: fake_uobject(),
            cmc: None,
            velocity_z_before: -500.0,
        };
        t.fire(&TriggerCtx::Fall(&fev));
        assert_eq!(FX_FALL.fires.load(Ordering::Relaxed), 0);

        // activate_slot applies only OnSlotChange-kinded skills.
        // Event-driven (FX_KILL / FX_FALL) are untouched.
        t.activate_slot("fire_test_slot".to_string());
        let kill_baseline = FX_KILL.fires.load(Ordering::Relaxed);
        let fall_baseline = FX_FALL.fires.load(Ordering::Relaxed);
        let slot_baseline = FX_SLOT.fires.load(Ordering::Relaxed);
        assert_eq!(kill_baseline, 0);
        assert_eq!(fall_baseline, 0);
        assert!(slot_baseline >= 1);

        // Phase 2: fire(Fall) at level 0 -> no additional fires.
        t.fire(&TriggerCtx::Fall(&fev));
        assert_eq!(FX_FALL.fires.load(Ordering::Relaxed), fall_baseline);

        // Phase 3: set levels directly + fire OnKill. Only the
        // OnKill skill fires (the kind filter on fire() works).
        {
            let mut g = t.inner.lock();
            let inner = g.as_mut().expect("activated");
            inner.state.skill_levels.insert("fire_kill".into(), 3);
            inner.state.skill_levels.insert("fire_fall".into(), 7);
            inner.state.skill_levels.insert("fire_slot".into(), 5);
        }
        let kev = KillEvent {
            victim: fake_uobject(),
            victim_class_name: "TestCreature",
            attacker: None,
            attacker_is_player: true,
            damage: 42.0,
        };
        t.fire(&TriggerCtx::Kill(&kev));
        assert_eq!(FX_KILL.fires.load(Ordering::Relaxed), kill_baseline + 1);
        assert_eq!(FX_KILL.last_level.load(Ordering::Relaxed), 3);
        assert_eq!(FX_FALL.fires.load(Ordering::Relaxed), fall_baseline);
        assert_eq!(FX_SLOT.fires.load(Ordering::Relaxed), slot_baseline);

        // Phase 4: OnFall fires the fall skill at its level.
        t.fire(&TriggerCtx::Fall(&fev));
        assert_eq!(FX_FALL.fires.load(Ordering::Relaxed), fall_baseline + 1);
        assert_eq!(FX_FALL.last_level.load(Ordering::Relaxed), 7);

        // Phase 5: disabled toggle suppresses the kill fire.
        t.disabled_skills().set("fire_kill", true);
        t.fire(&TriggerCtx::Kill(&kev));
        assert_eq!(FX_KILL.fires.load(Ordering::Relaxed), kill_baseline + 1);
    }
}
