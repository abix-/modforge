// Better Backpack -- Grounded 2 runtime DLL mod.
//
// Skeleton at this stage: DllMain spawns a worker thread. The worker
// detects the host platform (Steam vs Xbox), initializes the SDK runtime,
// then waits for GObjects. Real patch logic lands in subsequent steps.

#![allow(clippy::missing_safety_doc)]

pub mod sdk;

use std::ffi::{OsString, c_void};
use std::os::windows::ffi::OsStringExt;
use std::ptr;
use std::thread;
use std::time::Duration;

use windows_sys::Win32::Foundation::{CloseHandle, HMODULE};
use windows_sys::Win32::System::LibraryLoader::GetModuleFileNameW;
use windows_sys::Win32::System::SystemServices::{DLL_PROCESS_ATTACH, DLL_PROCESS_DETACH};
use windows_sys::Win32::System::Threading::CreateThread;

use crate::sdk::offsets::{Platform, STEAM, XBOX};

#[allow(clippy::upper_case_acronyms)]
type BOOL = i32;
const TRUE: BOOL = 1;

const INIT_RETRY_DELAY: Duration = Duration::from_millis(500);
const INIT_MAX_RETRIES: u32 = 60;

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
    let image_base = unsafe { sdk_image_base() };
    let exe_name = host_exe_name().unwrap_or_default();
    let platform = match exe_name.as_str() {
        "Grounded2-WinGRTS-Shipping.exe" => Platform::Steam,
        "Grounded2-WinGDK-Shipping.exe" => Platform::Xbox,
        _ => Platform::Steam, // best guess
    };
    let offsets = match platform {
        Platform::Steam => &STEAM,
        Platform::Xbox => &XBOX,
    };
    let _rt = unsafe { sdk::init_runtime(image_base, offsets) };

    // Wait for GObjects to populate. Subsequent steps will do the actual
    // scan + patch + hook installation.
    for _ in 0..INIT_MAX_RETRIES {
        let view = unsafe { sdk::GObjectsView::from_image(image_base, offsets) };
        if view.is_valid() && view.num() > 0 {
            break;
        }
        thread::sleep(INIT_RETRY_DELAY);
    }
}

unsafe fn sdk_image_base() -> usize {
    use windows_sys::Win32::System::LibraryLoader::GetModuleHandleW;
    let h = unsafe { GetModuleHandleW(ptr::null()) };
    h as usize
}

fn host_exe_name() -> Option<String> {
    let mut buf = [0u16; 1024];
    let n = unsafe { GetModuleFileNameW(ptr::null_mut(), buf.as_mut_ptr(), buf.len() as u32) };
    if n == 0 {
        return None;
    }
    let path = OsString::from_wide(&buf[..n as usize]).to_string_lossy().into_owned();
    let last = path.rsplit(['/', '\\']).next()?.to_string();
    Some(last)
}
