// Spike B: live PlayerState held in-process. The kill hook calls
// `record_kill` on every confirmed kill; we lazy-resolve the save slot
// (since the save isn't loaded at worker startup -- it's loaded when
// the player picks a slot from the main menu) and flush to disk after
// every change.
//
// Lazy slot resolution: at first record_kill, query
// `save_slot::current_slot_key()`. If None, log the kill but skip
// persistence -- we'll re-attempt on the next kill. Once a slot is
// found, we cache the `(slot, state)` pair.

use std::sync::Mutex;

use crate::bbp_log;
use crate::rpg::state::{self, PlayerState};

struct Tracker {
    slot: Option<String>,
    state: PlayerState,
}

static TRACKER: Mutex<Option<Tracker>> = Mutex::new(None);

/// Called from the kill hook on every confirmed creature kill.
pub fn record_kill(creature_class_name: &str) {
    let mut guard = match TRACKER.lock() {
        Ok(g) => g,
        Err(_) => return, // poisoned -- never happens, just bail
    };

    if guard.is_none() {
        // First kill: try to resolve slot + load prior state.
        let (slot, state) = match state::load_for_current_slot() {
            Some(pair) => (Some(pair.0), pair.1),
            None => (None, PlayerState::default()),
        };
        *guard = Some(Tracker { slot, state });
    }
    let tracker = guard.as_mut().unwrap();

    // If we never found a slot, retry resolution on each kill -- the
    // player may have transitioned from main menu to in-world between
    // kills.
    if tracker.slot.is_none()
        && let Some((slot, state)) = state::load_for_current_slot()
    {
        tracker.slot = Some(slot);
        tracker.state = state;
    }

    tracker.state.kill_count += 1;
    tracker.state.last_killed = creature_class_name.to_string();

    let total = tracker.state.kill_count;
    if let Some(slot) = tracker.slot.as_deref() {
        state::save(slot, &tracker.state);
        bbp_log!(
            "rpg/state: saved kill #{} ({}) to slot={}",
            total,
            creature_class_name,
            short(slot)
        );
    } else {
        bbp_log!(
            "rpg/state: kill #{} ({}) -- no save slot active, persistence deferred",
            total,
            creature_class_name
        );
    }
}

fn short(slot: &str) -> &str {
    if slot.len() >= 8 { &slot[..8] } else { slot }
}
