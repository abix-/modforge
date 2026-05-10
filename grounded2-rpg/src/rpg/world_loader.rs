// Eager state load on world entry.
//
// 1Hz poller (via ueforge::rpg::SlotPoller) that watches the G2 save
// slot resolver and drives tracker activate / deactivate transitions
// the moment the player enters or leaves the world.

use std::sync::OnceLock;
use std::time::Duration;

use ueforge::rpg::{PollerHandle, SlotPoller};

use crate::rpg::{save_slot, tracker};
use crate::settings::Settings;

const POLL_INTERVAL: Duration = Duration::from_secs(1);

static SETTINGS: OnceLock<Settings> = OnceLock::new();
static POLLER: OnceLock<PollerHandle> = OnceLock::new();

pub fn spawn(settings: Settings) {
    let _ = SETTINGS.set(settings);
    let handle = SlotPoller::spawn(
        POLL_INTERVAL,
        || {
            ueforge::counters::bump(&crate::counters::WORLD_LOADER_POLLS);
            save_slot::current_slot_key()
        },
        |slot| tracker::activate_slot(slot, settings_clone()),
        || tracker::deactivate_slot(),
    );
    let _ = POLLER.set(handle);
}

/// Signal the poller to exit. Called from the mod's `on_shutdown`
/// hook so the worker thread doesn't outlive the unloaded DLL.
/// Bounded by `POLL_INTERVAL` (~1s).
pub fn shutdown() {
    if let Some(p) = POLLER.get() {
        p.stop();
    }
}

/// Most recent panic from the poller's resolver / activate /
/// deactivate callbacks. Snapshot surface; cleared on no-op tick.
pub fn last_panic() -> Option<String> {
    POLLER.get().and_then(|p| p.last_panic())
}

/// Total panics caught from the poller since spawn.
pub fn panic_count() -> u64 {
    POLLER.get().map(|p| p.panic_count()).unwrap_or(0)
}

/// Snapshot of settings loaded at init -- used by the debug endpoint.
pub fn loaded_settings() -> Option<Settings> {
    SETTINGS.get().cloned()
}

fn settings_clone() -> Settings {
    SETTINGS.get().cloned().unwrap_or_default()
}
