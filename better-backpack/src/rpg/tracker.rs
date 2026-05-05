// In-memory PlayerState plus the slot it's bound to. Drives reads /
// writes for the RPG loop:
//   - `world_loader` calls `activate_slot` when a save becomes active.
//   - `kill_hook` calls `record_kill` on every confirmed creature kill,
//     specifying the kill source (player vs Buggy) so we can apply the
//     right XP multiplier.
//
// Eager activation is required because (future) skill ranks affect
// player stats from spawn, not from the first kill.

use std::sync::Mutex;

use crate::bbp_log;
use crate::rpg::apply;
use crate::rpg::state::{self, PlayerState};
use crate::rpg::xp;
use crate::settings::Settings;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum KillSource {
    Player,
    Buggy,
}

struct Tracker {
    slot: String,
    state: PlayerState,
    settings: Settings,
}

static TRACKER: Mutex<Option<Tracker>> = Mutex::new(None);

/// Bind the tracker to `slot` and load any prior state from disk.
/// Replaces any prior binding. Triggers `apply::apply` so skill ranks
/// are reflected in CDOs immediately.
pub fn activate_slot(slot: String, settings: Settings) {
    let mut state = state::load_one(&slot);
    // If the loaded state has xp but no level (first run after schema
    // bump, or hand-edited file), recompute level from xp.
    let derived_level = xp::level_for_xp(state.xp);
    if state.level < derived_level {
        state.level = derived_level;
    }
    bbp_log!(
        "rpg/state: activated slot={} level={} xp={} skill_points={} kills={} last={}",
        short(&slot),
        state.level,
        state.xp,
        state.skill_points,
        state.kill_count,
        if state.last_killed.is_empty() { "<none>" } else { state.last_killed.as_str() }
    );

    apply::apply(&state, &settings);

    *lock() = Some(Tracker {
        slot,
        state,
        settings,
    });
}

/// Drop the active slot. Persisted state is already on disk via
/// `record_kill`'s flush, so no extra save here.
pub fn deactivate_slot() {
    let mut g = lock();
    if let Some(t) = g.take() {
        bbp_log!("rpg/state: deactivated slot={}", short(&t.slot));
    }
}

/// Returns the slot key currently bound, if any.
pub fn current_slot() -> Option<String> {
    lock().as_ref().map(|t| t.slot.clone())
}

/// Run a read-only closure against the active PlayerState. Returns
/// None if no slot is active. Cheap, no clone of the state.
pub fn with_state<R>(f: impl FnOnce(&PlayerState) -> R) -> Option<R> {
    let g = lock();
    g.as_ref().map(|t| f(&t.state))
}

/// Spend one skill point on `skill`. Returns true if applied, false if
/// preconditions fail (no slot, no points, rank already at max).
pub fn spend_skill_point(skill: &crate::rpg::skills::Skill) -> bool {
    let mut g = lock();
    let Some(tracker) = g.as_mut() else {
        bbp_log!("rpg/state: spend({}) ignored, no slot active", skill.id);
        return false;
    };
    if tracker.state.skill_points == 0 {
        bbp_log!("rpg/state: spend({}) ignored, no skill points", skill.id);
        return false;
    }
    let cur_rank = tracker
        .state
        .skill_ranks
        .get(skill.id)
        .copied()
        .unwrap_or(0);
    if cur_rank >= skill.max_rank {
        bbp_log!(
            "rpg/state: spend({}) ignored, already at max rank {}",
            skill.id,
            skill.max_rank
        );
        return false;
    }
    tracker.state.skill_points -= 1;
    let new_rank = cur_rank + 1;
    tracker
        .state
        .skill_ranks
        .insert(skill.id.to_string(), new_rank);
    crate::rpg::apply::apply(&tracker.state, &tracker.settings);
    crate::rpg::state::save(&tracker.slot, &tracker.state);
    bbp_log!(
        "rpg/state: spent point on {}: rank {} -> {} ({} points left)",
        skill.id,
        cur_rank,
        new_rank,
        tracker.state.skill_points
    );
    true
}

/// Called from the kill hook on every confirmed creature kill.
pub fn record_kill(creature_class_name: &str, source: KillSource) {
    let mut g = lock();
    let Some(tracker) = g.as_mut() else {
        bbp_log!(
            "rpg/state: kill ({}) before slot active; dropping",
            creature_class_name
        );
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

    tracker.state.kill_count += 1;
    tracker.state.last_killed = creature_class_name.to_string();
    tracker.state.xp = tracker.state.xp.saturating_add(scaled as u64);

    let new_level = xp::level_for_xp(tracker.state.xp);
    let levelled = new_level > tracker.state.level;
    if levelled {
        let gained = new_level - tracker.state.level;
        tracker.state.level = new_level;
        tracker.state.skill_points = tracker.state.skill_points.saturating_add(gained);
        bbp_log!(
            "rpg/level: LEVEL UP! {} -> {} (+{} skill points; total {})",
            new_level - gained,
            new_level,
            gained,
            tracker.state.skill_points
        );
    }

    state::save(&tracker.slot, &tracker.state);

    bbp_log!(
        "rpg/state: kill #{} ({}) source={:?} +{} XP (total {}, level {})",
        tracker.state.kill_count,
        creature_class_name,
        source,
        scaled,
        tracker.state.xp,
        tracker.state.level
    );
}

fn lock() -> std::sync::MutexGuard<'static, Option<Tracker>> {
    TRACKER.lock().expect("rpg tracker mutex poisoned")
}

fn short(slot: &str) -> &str {
    if slot.len() >= 8 { &slot[..8] } else { slot }
}
