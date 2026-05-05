// Better Backpack -- Grounded 2 runtime DLL mod.
//
// Skeleton only at this stage: DllMain spawns a worker thread that does
// nothing yet. Real logic lands in subsequent steps of RUST_PORT_PLAN.md.

#![allow(clippy::missing_safety_doc)]

use std::ffi::c_void;
use std::ptr;

use windows_sys::Win32::Foundation::{CloseHandle, HMODULE};
use windows_sys::Win32::System::SystemServices::{DLL_PROCESS_ATTACH, DLL_PROCESS_DETACH};
use windows_sys::Win32::System::Threading::CreateThread;

#[allow(clippy::upper_case_acronyms)]
type BOOL = i32;
const TRUE: BOOL = 1;

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
    // step 4+: allocate console, init log, scan GObjects, install hooks.
    0
}
