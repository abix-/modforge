// Better Backpack -- Grounded 2 runtime DLL mod.
//
// Main flow:
//   1. DllMain spawns the worker thread and returns.
//   2. Worker initializes log, detects platform, init's the SDK runtime.
//   3. Waits for GObjects to populate.
//   4. Patches every player-owned UInventoryComponent's DefaultMaxSize.
//   5. Loops, rescanning every 10s and re-patching reverts.
//
// Inventory-interface ProcessEvent hook + viewport rebind land in step 6+.

#![allow(clippy::missing_safety_doc)]

pub mod hook;
pub mod inv_hook;
pub mod log;
pub mod parms;
pub mod patch;
pub mod sdk;

use std::ffi::{OsString, c_void};
use std::os::windows::ffi::OsStringExt;
use std::ptr;
use std::thread;
use std::time::Duration;

use windows_sys::Win32::Foundation::{CloseHandle, HMODULE};
use windows_sys::Win32::System::LibraryLoader::{GetModuleFileNameW, GetModuleHandleW};
use windows_sys::Win32::System::SystemServices::{DLL_PROCESS_ATTACH, DLL_PROCESS_DETACH};
use windows_sys::Win32::System::Threading::CreateThread;

use crate::sdk::offsets::{Platform, STEAM, XBOX};

#[allow(clippy::upper_case_acronyms)]
type BOOL = i32;
const TRUE: BOOL = 1;

const INIT_RETRY_DELAY: Duration = Duration::from_millis(500);
const INIT_MAX_RETRIES: u32 = 60;
const RESCAN_INTERVAL: Duration = Duration::from_secs(10);

#[unsafe(no_mangle)]
#[allow(non_snake_case)]
pub extern "system" fn DllMain(_hmod: HMODULE, reason: u32, _reserved: *mut c_void) -> BOOL {
    match reason {
        DLL_PROCESS_ATTACH => unsafe {
            let h = CreateThread(
                ptr::null(),
                0,
                Some(worker_entry),
                ptr::null(),
                0,
                ptr::null_mut(),
            );
            if !h.is_null() {
                CloseHandle(h);
            }
        },
        DLL_PROCESS_DETACH => {
            // future: signal worker shutdown, RAII drop hooks
        }
        _ => {}
    }
    TRUE
}

unsafe extern "system" fn worker_entry(_lpv: *mut c_void) -> u32 {
    let _ = std::panic::catch_unwind(|| unsafe { worker() });
    0
}

unsafe fn worker() {
    log::init();
    bbp_log!("=== Better Backpack DLL (rust) ===");
    bbp_log!("target slot_count = {}", patch::SLOT_COUNT);
    bbp_log!(
        "vanilla main = {}, vanilla mount = {} (left untouched)",
        patch::VANILLA_MAIN,
        patch::VANILLA_MOUNT
    );

    let image_base = unsafe { sdk_image_base() };
    let exe_name = host_exe_name().unwrap_or_default();
    let platform = match exe_name.as_str() {
        "Grounded2-WinGRTS-Shipping.exe" => Platform::Steam,
        "Grounded2-WinGDK-Shipping.exe" => Platform::Xbox,
        other => {
            bbp_log!(
                "WARN: unknown host exe '{}'; defaulting to Steam offsets",
                other
            );
            Platform::Steam
        }
    };
    let offsets = match platform {
        Platform::Steam => &STEAM,
        Platform::Xbox => &XBOX,
    };
    bbp_log!(
        "platform = {:?}, image_base = 0x{:x}, GObjects = 0x{:x}",
        platform,
        image_base,
        image_base + offsets.g_objects
    );

    let _rt = unsafe { sdk::init_runtime(image_base, offsets) };

    if !wait_for_gobjects(image_base, offsets) {
        bbp_log!(
            "FATAL: GObjects never populated after {} retries; aborting",
            INIT_MAX_RETRIES
        );
        return;
    }

    let initial = patch::run();
    bbp_log!(
        "initial patch round: scanned={}, patched={}, skipped_non_player={}",
        initial.scanned,
        initial.patched,
        initial.skipped_non_player
    );

    let mut inv_hook = match inv_hook::install() {
        Ok(h) => {
            bbp_log!("inv hook: installed on {}", h.class_name());
            Some(h)
        }
        Err(e) => {
            bbp_log!("inv hook: install pending ({}), will retry", e);
            None
        }
    };

    bbp_log!("entering rescan loop (interval = {:?})", RESCAN_INTERVAL);
    loop {
        thread::sleep(RESCAN_INTERVAL);
        let again = patch::run();
        if again.patched > 0 {
            bbp_log!(
                "rescan: patched={} (re-applied after revert)",
                again.patched
            );
        }
        if inv_hook.is_none() {
            inv_hook = match inv_hook::install() {
                Ok(h) => {
                    bbp_log!("inv hook: installed on {}", h.class_name());
                    Some(h)
                }
                Err(_) => None,
            };
        }
    }
}

fn wait_for_gobjects(image_base: usize, offsets: &sdk::PlatformOffsets) -> bool {
    for _ in 0..INIT_MAX_RETRIES {
        let view = unsafe { sdk::GObjectsView::from_image(image_base, offsets) };
        if view.is_valid() && view.num() > 0 {
            bbp_log!("GObjects populated, count = {}", view.num());
            return true;
        }
        thread::sleep(INIT_RETRY_DELAY);
    }
    false
}

unsafe fn sdk_image_base() -> usize {
    let h = unsafe { GetModuleHandleW(ptr::null()) };
    h as usize
}

fn host_exe_name() -> Option<String> {
    let mut buf = [0u16; 1024];
    let n = unsafe { GetModuleFileNameW(ptr::null_mut(), buf.as_mut_ptr(), buf.len() as u32) };
    if n == 0 {
        return None;
    }
    let path = OsString::from_wide(&buf[..n as usize])
        .to_string_lossy()
        .into_owned();
    let last = path.rsplit(['/', '\\']).next()?.to_string();
    Some(last)
}
