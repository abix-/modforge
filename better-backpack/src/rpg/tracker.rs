// In-memory player state + the slot it's bound to. Drives reads /
// writes for the RPG loop:
//   - `world_loader` calls `activate_slot` when a save becomes active.
//   - `kill_hook` calls `record_kill` on every confirmed creature kill.
//
// State and persistence ride on `ueforge::rpg::SkillsState` +
// `SlotStore<SkillsState>`. The slot key is the G2 PlaythroughGuid
// resolved by `save_slot::current_slot_key`.

use parking_lot::Mutex;
use ueforge::rpg::{SkillsState, SlotStore};

use crate::rpg::apply;
use crate::rpg::xp;
use crate::settings::Settings;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum KillSource {
    Player,
    Buggy,
}

struct Tracker {
    slot: String,
    state: SkillsState,
    settings: Settings,
}

static TRACKER: Mutex<Option<Tracker>> = Mutex::new(None);
static STORE: SlotStore<SkillsState> = SlotStore::new("saves");

/// Bind the tracker to `slot` and load any prior state from disk.
pub fn activate_slot(slot: String, settings: Settings) {
    let mut state = STORE.load(&slot);
    // Catch up `level` from `xp` if a curve change or hand-edit left
    // them out of sync.
    let derived_level = xp::level_for_xp(state.xp);
    if state.level < derived_level {
        state.level = derived_level;
    }
    ueforge::log!(
        "rpg/state: activated slot={} level={} xp={} skill_points={}",
        short(&slot),
        state.level,
        state.xp,
        state.skill_points,
    );

    apply::apply(&state, &settings);

    *TRACKER.lock() = Some(Tracker {
        slot,
        state,
        settings,
    });
}

pub fn deactivate_slot() {
    let mut g = TRACKER.lock();
    if let Some(t) = g.take() {
        ueforge::log!("rpg/state: deactivated slot={}", short(&t.slot));
    }
}

pub fn current_slot() -> Option<String> {
    TRACKER.lock().as_ref().map(|t| t.slot.clone())
}

/// Read-only access to the active state. None if no slot is active.
pub fn with_state<R>(f: impl FnOnce(&SkillsState) -> R) -> Option<R> {
    let g = TRACKER.lock();
    g.as_ref().map(|t| f(&t.state))
}

pub fn spend_skill_point(skill: &crate::rpg::skills::Skill) -> bool {
    spend_skill_points(skill, 1) > 0
}

pub fn spend_skill_points(skill: &crate::rpg::skills::Skill, count: u32) -> u32 {
    let mut g = TRACKER.lock();
    let Some(tracker) = g.as_mut() else {
        ueforge::log!("rpg/state: spend({}) ignored, no slot active", skill.id);
        return 0;
    };
    if count == 0 {
        return 0;
    }
    let cur_level = tracker.state.level_of(skill.id);
    if cur_level >= skill.max_level {
        return 0;
    }
    let max_by_level = skill.max_level - cur_level;
    let spend = count.min(tracker.state.skill_points).min(max_by_level);
    if spend == 0 {
        return 0;
    }
    tracker.state.skill_points -= spend;
    let new_level = cur_level + spend;
    tracker
        .state
        .skill_levels
        .insert(skill.id.to_string(), new_level);
    apply::apply_one(&tracker.state, &tracker.settings, skill.id);
    STORE.save(&tracker.slot, &tracker.state);
    ueforge::log!(
        "rpg/state: spent {} on {}: level {} -> {} ({} points left)",
        spend,
        skill.id,
        cur_level,
        new_level,
        tracker.state.skill_points
    );
    spend
}

pub fn refund_skill_point(skill: &crate::rpg::skills::Skill) -> bool {
    refund_skill_points(skill, 1) > 0
}

pub fn refund_skill_points(skill: &crate::rpg::skills::Skill, count: u32) -> u32 {
    let mut g = TRACKER.lock();
    let Some(tracker) = g.as_mut() else {
        return 0;
    };
    if count == 0 {
        return 0;
    }
    let cur_level = tracker.state.level_of(skill.id);
    if cur_level == 0 {
        return 0;
    }
    let refund = count.min(cur_level);
    let new_level = cur_level - refund;
    if new_level == 0 {
        tracker.state.skill_levels.remove(skill.id);
    } else {
        tracker
            .state
            .skill_levels
            .insert(skill.id.to_string(), new_level);
    }
    tracker.state.skill_points = tracker.state.skill_points.saturating_add(refund);
    apply::apply_one(&tracker.state, &tracker.settings, skill.id);
    STORE.save(&tracker.slot, &tracker.state);
    ueforge::log!(
        "rpg/state: refunded {} from {}: level {} -> {} ({} points)",
        refund,
        skill.id,
        cur_level,
        new_level,
        tracker.state.skill_points
    );
    refund
}

pub fn reapply_one(skill_id: &str) {
    let g = TRACKER.lock();
    let Some(tracker) = g.as_ref() else { return };
    apply::apply_one(&tracker.state, &tracker.settings, skill_id);
}

/// Re-apply every CATALOG skill against the current state. Used by
/// the debug `reload_slot` op.
pub fn reapply_all() -> bool {
    let g = TRACKER.lock();
    let Some(tracker) = g.as_ref() else {
        return false;
    };
    apply::apply(&tracker.state, &tracker.settings);
    true
}

pub fn debug_grant_skill_points(count: u32) -> bool {
    let mut g = TRACKER.lock();
    let Some(tracker) = g.as_mut() else {
        return false;
    };
    tracker.state.skill_points = tracker.state.skill_points.saturating_add(count);
    STORE.save(&tracker.slot, &tracker.state);
    ueforge::log!(
        "rpg/state: DEBUG granted +{count} skill points (total {})",
        tracker.state.skill_points
    );
    true
}

/// Called from the kill hook on every confirmed creature kill.
pub fn record_kill(creature_class_name: &str, source: KillSource) {
    let mut g = TRACKER.lock();
    let Some(tracker) = g.as_mut() else {
        return;
    };

    let base_xp = xp::xp_for_creature(creature_class_name);
    let scaled = match source {
        KillSource::Player => base_xp,
        KillSource::Buggy => {
            let mult = tracker.settings.rpg.buggy_kill_xp_multiplier.max(0.0);
            (base_xp as f32 * mult).round() as u32
        }
    };

    tracker.state.xp = tracker.state.xp.saturating_add(scaled as u64);

    let new_level = xp::level_for_xp(tracker.state.xp);
    let levelled = new_level > tracker.state.level;
    if levelled {
        let gained = new_level - tracker.state.level;
        tracker.state.level = new_level;
        tracker.state.skill_points = tracker.state.skill_points.saturating_add(gained);
        ueforge::log!(
            "rpg/level: LEVEL UP! {} -> {} (+{} skill points; total {})",
            new_level - gained,
            new_level,
            gained,
            tracker.state.skill_points
        );
    }

    STORE.save(&tracker.slot, &tracker.state);

    ueforge::log!(
        "rpg/state: kill ({creature_class_name}) source={source:?} +{scaled} XP (total {}, level {})",
        tracker.state.xp,
        tracker.state.level
    );
}

fn short(slot: &str) -> &str {
    if slot.len() >= 8 { &slot[..8] } else { slot }
}
