// In-memory PlayerState plus the slot it's bound to. Drives reads /
// writes for the RPG loop:
//   - `world_loader` calls `activate_slot` when a save becomes active.
//   - `kill_hook` calls `record_kill` on every confirmed creature kill.
//
// Eager activation is required because (future) level/perk ranks affect
// player stats from spawn, not from the first kill. We can't wait until
// the kill hook fires to load.

use std::sync::Mutex;

use crate::bbp_log;
use crate::rpg::state::{self, PlayerState};

struct Tracker {
    slot: String,
    state: PlayerState,
}

static TRACKER: Mutex<Option<Tracker>> = Mutex::new(None);

/// Bind the tracker to `slot` and load any prior state from disk.
/// Replaces any prior binding (caller is responsible for flushing the
/// outgoing slot first if needed).
pub fn activate_slot(slot: String) {
    let state = state::load_one(&slot);
    bbp_log!(
        "rpg/state: activated slot={} kills={} last={}",
        short(&slot),
        state.kill_count,
        if state.last_killed.is_empty() { "<none>" } else { state.last_killed.as_str() }
    );
    *lock() = Some(Tracker { slot, state });
}

/// Drop the active slot (e.g. player exited to main menu). Persisted
/// state is already on disk via `record_kill`'s flush, so no extra save
/// is needed here.
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

/// Called from the kill hook on every confirmed creature kill.
pub fn record_kill(creature_class_name: &str) {
    let mut g = lock();
    let Some(tracker) = g.as_mut() else {
        bbp_log!(
            "rpg/state: kill ({}) before slot active; dropping",
            creature_class_name
        );
        return;
    };
    tracker.state.kill_count += 1;
    tracker.state.last_killed = creature_class_name.to_string();
    let total = tracker.state.kill_count;
    state::save(&tracker.slot, &tracker.state);
    bbp_log!(
        "rpg/state: saved kill #{} ({}) to slot={}",
        total,
        creature_class_name,
        short(&tracker.slot)
    );
}

fn lock() -> std::sync::MutexGuard<'static, Option<Tracker>> {
    TRACKER.lock().expect("rpg tracker mutex poisoned")
}

fn short(slot: &str) -> &str {
    if slot.len() >= 8 { &slot[..8] } else { slot }
}
