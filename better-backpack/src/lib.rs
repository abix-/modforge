// Better Backpack -- Grounded 2 runtime DLL mod.
//
// Main flow:
//   1. DllMain spawns the worker thread and returns.
//   2. Worker initializes log, detects platform, init's the SDK runtime.
//   3. Waits for GObjects to populate.
//   4. Patches the player UInventoryComponent CDO's DefaultMaxSize once.
//      Future instance constructions (including those triggered by save
//      loads) inherit from the patched CDO automatically -- no rescan
//      loop needed. UE doesn't re-load CDOs from disk during a session,
//      so the patch is sticky for the lifetime of the DLL.
//   5. Lazily installs the WBP_InventoryInterface_C ProcessEvent hook
//      with backoff retry until the inventory UI loads. Once installed,
//      the worker exits.
//
// Net runtime cost after init: zero. Worker thread terminates.

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
const HOOK_RETRY_BASE_DELAY_MS: u64 = 500;
const HOOK_RETRY_MAX_DELAY_MS: u64 = 5_000;
const HOOK_RETRY_TIMEOUT_SEC: u64 = 600; // 10 min hard cap before giving up

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

    // Install the inventory-interface hook with exponential backoff. The
    // class isn't loaded into GObjects until the inventory UI opens for
    // the first time. We retry until install succeeds or we hit the
    // timeout. After install, this thread exits and the mod's runtime
    // overhead drops to zero.
    match install_inv_hook_with_backoff() {
        Some(h) => {
            bbp_log!("inv hook: installed on {}", h.class_name());
            // Leak the hook so it lives for the lifetime of the process.
            // Drop-on-thread-exit would unhook the trampoline immediately.
            std::mem::forget(h);
        }
        None => {
            bbp_log!(
                "inv hook: gave up after {}s; scrolling will not work this session",
                HOOK_RETRY_TIMEOUT_SEC
            );
        }
    }

    bbp_log!("init complete; worker thread exiting");
}

fn install_inv_hook_with_backoff() -> Option<hook::ProcessEventHook> {
    let mut delay_ms = HOOK_RETRY_BASE_DELAY_MS;
    let deadline = std::time::Instant::now()
        + Duration::from_secs(HOOK_RETRY_TIMEOUT_SEC);
    let mut last_err: Option<&str> = None;
    loop {
        match inv_hook::install() {
            Ok(h) => return Some(h),
            Err(e) => {
                if last_err != Some(e) {
                    bbp_log!("inv hook: pending ({}), will retry", e);
                    last_err = Some(e);
                }
            }
        }
        if std::time::Instant::now() >= deadline {
            return None;
        }
        thread::sleep(Duration::from_millis(delay_ms));
        delay_ms = (delay_ms * 2).min(HOOK_RETRY_MAX_DELAY_MS);
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
