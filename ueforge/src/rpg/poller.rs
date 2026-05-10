//! 1Hz worker that watches a slot-key resolver closure and drives
//! activate / deactivate transitions on a consumer-provided pair of
//! callbacks.
//!
//! The slot-key resolver is game-specific (Grounded 2 reads
//! `AInGameGameState.PlaythroughGuid` at +0x32C; another UE game
//! might read a different field). The consumer plugs that closure
//! in; the poller handles transition detection.
//!
//! ```ignore
//! ueforge::rpg::SlotPoller::spawn(
//!     std::time::Duration::from_secs(1),
//!     game::current_slot_key,        // -> Option<String>
//!     |slot| tracker::activate(slot),
//!     ||     tracker::deactivate(),
//! );
//! ```

use std::ffi::c_void;
use std::ptr;
use std::time::Duration;

use windows_sys::Win32::Foundation::CloseHandle;
use windows_sys::Win32::System::Threading::CreateThread;

pub struct SlotPoller;

impl SlotPoller {
    /// Spawn the watcher on a Win32 worker thread. The thread runs
    /// for the lifetime of the process; transitions fire as the
    /// resolver's return value changes.
    pub fn spawn<R, A, D>(interval: Duration, resolve: R, on_activate: A, on_deactivate: D)
    where
        R: Fn() -> Option<String> + Send + 'static,
        A: Fn(String) + Send + 'static,
        D: Fn() + Send + 'static,
    {
        // Box the closures behind a fat ptr so the C thread entry
        // can recover them.
        let cfg: Box<Cfg> = Box::new(Cfg {
            interval,
            resolve: Box::new(resolve),
            on_activate: Box::new(on_activate),
            on_deactivate: Box::new(on_deactivate),
        });
        let raw = Box::into_raw(cfg) as *mut c_void;
        unsafe {
            let h = CreateThread(
                ptr::null(),
                0,
                Some(thread_entry),
                raw,
                0,
                ptr::null_mut(),
            );
            if h.is_null() {
                // CreateThread failed -- reclaim the box.
                drop(Box::from_raw(raw as *mut Cfg));
                crate::log!("rpg/poller: CreateThread failed");
                return;
            }
            CloseHandle(h);
        }
    }
}

struct Cfg {
    interval: Duration,
    resolve: Box<dyn Fn() -> Option<String> + Send + 'static>,
    on_activate: Box<dyn Fn(String) + Send + 'static>,
    on_deactivate: Box<dyn Fn() + Send + 'static>,
}

unsafe extern "system" fn thread_entry(lpv: *mut c_void) -> u32 {
    let cfg = unsafe { Box::from_raw(lpv as *mut Cfg) };
    let _ = std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| run(*cfg)));
    0
}

fn run(cfg: Cfg) {
    crate::log!("rpg/poller: started, interval={:?}", cfg.interval);
    let mut last: Option<String> = None;
    loop {
        let cur = (cfg.resolve)();
        match (last.as_deref(), cur.as_deref()) {
            (None, Some(s)) => (cfg.on_activate)(s.to_string()),
            (Some(a), Some(b)) if a != b => {
                (cfg.on_deactivate)();
                (cfg.on_activate)(b.to_string());
            }
            (Some(_), None) => (cfg.on_deactivate)(),
            _ => {}
        }
        last = cur;
        std::thread::sleep(cfg.interval);
    }
}
