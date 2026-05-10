//! Host process detection helpers.
//!
//! Two pieces:
//! - `host_image_base` — `GetModuleHandleW(null)` cast as
//!   `usize`. The image base of the main exe; offsets in
//!   [`PlatformOffsets`] are relative to this.
//! - `host_exe_name` — basename of the running exe, e.g.
//!   `"Grounded2-WinGRTS-Shipping.exe"` or
//!   `"OutworldStation-Win64-Shipping.exe"`.
//! - `detect_platform` — match the exe basename against a
//!   game-supplied table of `(exe_substring, PlatformOffsets)`
//!   pairs. Substring match (not equality) so suffixed exes
//!   (e.g. `Foo-Win64-Shipping-debug.exe`) still match.
//!
//! Game crates declare their offset tables and pass them in at
//! init time:
//!
//! ```ignore
//! use ueforge::ue::{PlatformOffsets, platform};
//!
//! const STEAM: PlatformOffsets = PlatformOffsets { /* ... */ };
//! const XBOX:  PlatformOffsets = PlatformOffsets { /* ... */ };
//!
//! const PLATFORMS: &[(&str, &PlatformOffsets)] = &[
//!     ("WinGRTS-Shipping.exe", &STEAM),
//!     ("WinGDK-Shipping.exe",  &XBOX),
//! ];
//!
//! let offsets = platform::detect(PLATFORMS).unwrap_or(&STEAM);
//! ```

use std::ffi::OsString;
use std::os::windows::ffi::OsStringExt;
use std::ptr;

use windows_sys::Win32::System::LibraryLoader::{GetModuleFileNameW, GetModuleHandleW};

use crate::ue::offsets::PlatformOffsets;

/// `GetModuleHandleW(null)` cast to `usize`. Used as the base for
/// every offset in [`PlatformOffsets`].
pub fn host_image_base() -> usize {
    let h = unsafe { GetModuleHandleW(ptr::null()) };
    h as usize
}

/// Basename of the host process exe, e.g.
/// `"OutworldStation-Win64-Shipping.exe"`.
pub fn host_exe_name() -> Option<String> {
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

/// Match the host exe's basename against a list of
/// `(substring, offsets)` pairs. Returns the first matching
/// `&PlatformOffsets`. Caller falls back to a default on `None`.
pub fn detect<'a>(
    table: &[(&str, &'a PlatformOffsets)],
) -> Option<&'a PlatformOffsets> {
    let exe = host_exe_name()?;
    table
        .iter()
        .find(|(needle, _)| exe.contains(needle))
        .map(|(_, off)| *off)
}
