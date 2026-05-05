// Rewrite a single vtable slot, using VirtualProtect to flip the page from
// RX to RWX and back. Returns the previous value so callers can restore.

use std::ffi::c_void;

use windows_sys::Win32::System::Memory::{
    PAGE_EXECUTE_READWRITE, PAGE_PROTECTION_FLAGS, VirtualProtect,
};

/// Overwrite `*slot` with `new_value`. Caller must guarantee `slot` is a
/// live vtable entry pointer. Returns the previous value, or `None` if the
/// VirtualProtect dance failed.
pub unsafe fn write_slot(slot: *mut *mut c_void, new_value: *mut c_void) -> Option<*mut c_void> {
    let mut old_protect: PAGE_PROTECTION_FLAGS = 0;
    let ok = unsafe {
        VirtualProtect(
            slot as *const c_void,
            size_of::<*mut c_void>(),
            PAGE_EXECUTE_READWRITE,
            &mut old_protect,
        )
    };
    if ok == 0 {
        return None;
    }
    let prev = unsafe { *slot };
    unsafe { *slot = new_value };
    let mut ignored: PAGE_PROTECTION_FLAGS = 0;
    unsafe {
        VirtualProtect(
            slot as *const c_void,
            size_of::<*mut c_void>(),
            old_protect,
            &mut ignored,
        );
    }
    Some(prev)
}
