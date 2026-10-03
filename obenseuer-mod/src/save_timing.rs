//! Logs how long SaveController.SaveGame takes: the full save the game
//! writes at every door between areas (results in docs/doors.md, where a
//! door's time goes).

use std::ffi::c_void;
use std::sync::Mutex;
use std::time::Instant;

use unityforge::hook::{HOOK_REGISTRY, patch_postfix, patch_prefix};
use unityforge::mono::{LogLevel, log};

static STARTED: Mutex<Option<Instant>> = Mutex::new(None);

pub fn install() {
    for hook in [
        patch_prefix("SaveController", "SaveGame", on_save_start),
        patch_postfix("SaveController", "SaveGame", on_save_end),
    ] {
        match hook {
            Ok(h) => HOOK_REGISTRY.register(h),
            Err(e) => log(LogLevel::Warn, &format!("obenseuer-mod: save timing patch failed: {e}")),
        }
    }
}

extern "C" fn on_save_start(_ctx: *const c_void) -> i32 {
    *STARTED.lock().unwrap() = Some(Instant::now());
    0
}

extern "C" fn on_save_end(_ctx: *const c_void) {
    if let Some(t) = STARTED.lock().unwrap().take() {
        log(
            LogLevel::Info,
            &format!("obenseuer-mod: save took {:.3}s", t.elapsed().as_secs_f64()),
        );
    }
}
