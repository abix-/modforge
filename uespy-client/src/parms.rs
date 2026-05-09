//! Test-side helpers for the `call` op's parm-buffer round-trip.
//!
//! Tests author `#[repr(C)]` structs that mirror the SDK's
//! UFunction parm layout, then use these helpers to view them as
//! bytes (for sending) and back (for OUT params the engine wrote
//! during the call).

use std::mem::{MaybeUninit, size_of};

/// View a parm struct as bytes for `Api::call_ufunction`.
///
/// # Safety
/// `T` must be a plain-old-data struct with no padding traps and
/// no references / non-owned pointers. Use `#[repr(C)]` and
/// explicit pad fields.
pub unsafe fn as_bytes<T: Sized>(parms: &T) -> &[u8] {
    unsafe { std::slice::from_raw_parts(parms as *const T as *const u8, size_of::<T>()) }
}

/// Decode raw bytes back into a parm struct (e.g. to read OUT
/// parameters the engine wrote during the call).
///
/// # Safety
/// Same constraints as `as_bytes`. `bytes.len()` must equal
/// `size_of::<T>()`.
pub unsafe fn from_bytes<T: Sized + Copy>(bytes: &[u8]) -> Result<T, String> {
    if bytes.len() != size_of::<T>() {
        return Err(format!(
            "parm size mismatch: bytes={} expected={}",
            bytes.len(),
            size_of::<T>()
        ));
    }
    let mut t = MaybeUninit::<T>::uninit();
    unsafe {
        std::ptr::copy_nonoverlapping(bytes.as_ptr(), t.as_mut_ptr() as *mut u8, bytes.len());
        Ok(t.assume_init())
    }
}
