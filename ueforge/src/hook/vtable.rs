// Rewrite a single vtable slot. The `region` crate's
// `protect_with_handle` RAII guard flips the page from RX to RWX
// for the duration of the write and restores the previous
// protection on Drop. Returns the previous value so callers can
// restore.

use std::ffi::c_void;

/// Overwrite `*slot` with `new_value`. Caller must guarantee
/// `slot` is a live vtable entry pointer. Returns the previous
/// value, or `None` if the page-protection dance failed.
pub unsafe fn write_slot(slot: *mut *mut c_void, new_value: *mut c_void) -> Option<*mut c_void> {
    // SAFETY: caller guarantees `slot` points at a writable
    // vtable entry. `protect_with_handle` flips the page to
    // READ_WRITE_EXECUTE for `size_of::<*mut c_void>()` bytes;
    // the returned handle restores the previous protection when
    // it drops at end of scope. If the protect call fails we
    // return None without touching the slot.
    let _guard = unsafe {
        match region::protect_with_handle(
            slot as *const c_void,
            size_of::<*mut c_void>(),
            region::Protection::READ_WRITE_EXECUTE,
        ) {
            Ok(g) => g,
            Err(_) => return None,
        }
    };
    // SAFETY: page is now writable for `size_of::<*mut c_void>()`
    // bytes starting at `slot`. The read + write are within the
    // protected range.
    let prev = unsafe { *slot };
    // SAFETY: see above.
    unsafe { *slot = new_value };
    // `_guard` Drop restores the previous protection (typically
    // PAGE_EXECUTE_READ for a vtable page) before this fn returns.
    Some(prev)
}
