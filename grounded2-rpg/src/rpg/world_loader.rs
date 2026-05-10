// Eager state load on world entry.
//
// 1Hz poller (via ueforge::rpg::SlotPoller) that watches the G2 save
// slot resolver and drives tracker activate / deactivate transitions
// the moment the player enters or leaves the world.

use std::sync::OnceLock;
use std::time::Duration;

use ueforge::rpg::SlotPoller;

use crate::rpg::{save_slot, tracker};
use crate::settings::Settings;

const POLL_INTERVAL: Duration = Duration::from_secs(1);

static SETTINGS: OnceLock<Settings> = OnceLock::new();

pub fn spawn(settings: Settings) {
    let _ = SETTINGS.set(settings);
    SlotPoller::spawn(
        POLL_INTERVAL,
        || {
            ueforge::counters::bump(&crate::counters::WORLD_LOADER_POLLS);
            save_slot::current_slot_key()
        },
        |slot| tracker::activate_slot(slot, settings_clone()),
        || tracker::deactivate_slot(),
    );
}

/// Snapshot of settings loaded at init -- used by the debug endpoint.
pub fn loaded_settings() -> Option<Settings> {
    SETTINGS.get().cloned()
}

fn settings_clone() -> Settings {
    SETTINGS.get().cloned().unwrap_or_default()
}
