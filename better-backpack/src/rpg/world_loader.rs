// Eager state load on world entry.
//
// At worker startup the player is usually still at the main menu --
// AInGameGameState doesn't exist yet, so save_slot::current_slot_key()
// returns None. The kill hook can run as soon as the player enters the
// world, and (future) perk-driven CDO patches need to apply at world
// entry too -- before the first kill, before any combat. So we can't
// wait for record_kill to lazy-load.
//
// This module spawns a low-frequency poller that watches
// save_slot::current_slot_key() and drives tracker transitions:
//   None    -> Some(s):   tracker::activate_slot(s, settings)
//   Some(a) -> Some(b):   tracker::deactivate_slot(); activate_slot(b, settings)
//   Some(s) -> None:      tracker::deactivate_slot()
//
// Polling at 1Hz: imperceptible cost, fast enough that the player
// can't kill anything before activation lands.

use std::ffi::c_void;
use std::ptr;
use std::sync::OnceLock;
use std::time::Duration;

use windows_sys::Win32::Foundation::CloseHandle;
use windows_sys::Win32::System::Threading::CreateThread;

use crate::bbp_log;
use crate::rpg::{save_slot, tracker};
use crate::settings::RpgSettings;

const POLL_INTERVAL_MS: u64 = 1_000;

static SETTINGS: OnceLock<RpgSettings> = OnceLock::new();

pub fn spawn(settings: RpgSettings) {
    let _ = SETTINGS.set(settings);
    unsafe {
        let h = CreateThread(
            ptr::null(),
            0,
            Some(thread_entry),
            ptr::null(),
            0,
            ptr::null_mut(),
        );
        if !h.is_null() {
            CloseHandle(h);
        }
    }
}

unsafe extern "system" fn thread_entry(_lpv: *mut c_void) -> u32 {
    let _ = std::panic::catch_unwind(run);
    0
}

fn run() {
    bbp_log!("rpg/world_loader: poller started");
    let mut last: Option<String> = None;
    loop {
        let cur = save_slot::current_slot_key();
        match (last.as_deref(), cur.as_deref()) {
            (None, Some(s)) => {
                tracker::activate_slot(s.to_string(), settings_clone());
            }
            (Some(a), Some(b)) if a != b => {
                tracker::deactivate_slot();
                tracker::activate_slot(b.to_string(), settings_clone());
            }
            (Some(_), None) => {
                tracker::deactivate_slot();
            }
            _ => {}
        }
        last = cur;
        std::thread::sleep(Duration::from_millis(POLL_INTERVAL_MS));
    }
}

fn settings_clone() -> RpgSettings {
    SETTINGS.get().cloned().unwrap_or_default()
}
