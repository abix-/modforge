//! Whether this process's game window is the window in front, read
//! straight from Windows (GetForegroundWindow) each time it is asked.
//!
//! "The game window" is a window of this process with a given class
//! (UnrealWindow for Unreal games), or a window it owns, so another
//! top-level window in the same process, such as UE4SS's mod window,
//! counts as not in front.

use windows_sys::Win32::Foundation::HWND;
use windows_sys::Win32::UI::WindowsAndMessaging::{
    GA_ROOTOWNER, GetAncestor, GetClassNameW, GetForegroundWindow, GetWindowThreadProcessId,
};

fn class_of(hwnd: HWND) -> String {
    let mut buf = [0u16; 64];
    // SAFETY: Windows writes at most buf.len() UTF-16 units into the live buffer.
    let n = unsafe { GetClassNameW(hwnd, buf.as_mut_ptr(), buf.len() as i32) };
    String::from_utf16_lossy(&buf[..n.max(0) as usize])
}

/// The window in front is this process's window of `class`, or one it
/// owns. One cheap call per check; safe from any thread.
pub fn game_in_front(class: &str) -> bool {
    // SAFETY: no arguments.
    let hwnd = unsafe { GetForegroundWindow() };
    if hwnd.is_null() {
        return false;
    }
    let mut pid = 0;
    // SAFETY: any HWND value is accepted; writes only to the live local.
    unsafe { GetWindowThreadProcessId(hwnd, &mut pid) };
    if pid != std::process::id() {
        return false;
    }
    // SAFETY: any HWND value is accepted.
    let root = unsafe { GetAncestor(hwnd, GA_ROOTOWNER) };
    class_of(hwnd) == class || (!root.is_null() && class_of(root) == class)
}
