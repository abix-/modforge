//! Standalone-window ImGui backend (Phase A).
//!
//! `spawn` opens a top-level Win32 window with its own D3D11 device
//! + swap chain + ImGui context, running on a background thread
//! inside the consuming DLL. `shutdown` joins that thread and tears
//! down all native resources.
//!
//! Use this from native-PE mods (horsey-mod) where there is no host
//! runtime to share an ImGui context. UE4SS-based mods should stay
//! on the UE4SS bridge backend; see [`crate::ui`] module docs.
//!
//! Cargo feature: `native-ui`.

use crate::ui::TabDef;
use std::os::raw::c_char;

#[repr(C)]
struct TabAbi {
    name_ptr: *const c_char,
    name_len: usize,
    render_fn: Option<extern "C" fn()>,
}

// SAFETY: TabAbi is plain data and the slice we hand C is `'static`.
unsafe impl Sync for TabAbi {}
unsafe impl Send for TabAbi {}

unsafe extern "C" {
    fn modforge_native_ui_spawn(title_ptr: *const c_char, title_len: usize) -> bool;
    fn modforge_native_ui_shutdown();
    fn modforge_native_ui_is_visible() -> bool;
    fn modforge_native_ui_register_tabs(tabs: *const TabAbi, count: usize);
    fn modforge_native_ui_frame_count() -> u64;
}

/// Spawn the standalone ImGui window. Idempotent: a second call
/// while already running returns `true` without creating a second
/// window.
///
/// `title` is the OS-level window title. Tabs registered prior to
/// (or after) spawn appear in the window's tab bar.
pub fn spawn(title: &str) -> bool {
    // SAFETY: title is a borrowed UTF-8 slice; the C side copies it
    // into a wide string before returning.
    unsafe { modforge_native_ui_spawn(title.as_ptr() as *const c_char, title.len()) }
}

/// Tear the window down. Joins the render thread; safe to call from
/// any thread (callers must not call it from inside a tab `render`
/// callback).
pub fn shutdown() {
    // SAFETY: idempotent; checks an atomic before touching state.
    unsafe { modforge_native_ui_shutdown() }
}

/// True if a window with our class name currently exists on the
/// desktop. Used by the lifecycle harness test to confirm spawn /
/// shutdown reached their post-conditions.
pub fn is_visible() -> bool {
    // SAFETY: pure read of an atomic + a FindWindowW call.
    unsafe { modforge_native_ui_is_visible() }
}

/// Total frames the render loop has presented since spawn. Useful
/// for "is the render thread actually running?" diagnostics.
pub fn frame_count() -> u64 {
    // SAFETY: pure atomic read.
    unsafe { modforge_native_ui_frame_count() }
}

/// Register the static tab slice the render thread walks each frame.
/// Pointer ownership stays with the caller; the slice must live
/// `'static`. Passing an empty slice clears the registration.
pub fn register_tabs(tabs: &'static [TabDef]) {
    // Build a parallel `'static` Vec<TabAbi> the first time. Once
    // registered, the slice lives forever; subsequent register_tabs
    // calls leak a small Vec. Acceptable: this is mod-init code that
    // runs once.
    let abis: Vec<TabAbi> = tabs
        .iter()
        .map(|t| TabAbi {
            name_ptr: t.name.as_ptr() as *const c_char,
            name_len: t.name.len(),
            // SAFETY: ImGui tab render fns must be ABI-compatible with
            // `extern "C" fn()`. fn() in Rust is `extern "Rust"`; we
            // transmute to `extern "C"`. On x86_64 Windows both ABIs
            // pass no args so the call sequence is identical.
            render_fn: unsafe {
                std::mem::transmute::<fn(), extern "C" fn()>(t.render)
            }
            .into(),
        })
        .collect();
    let leaked: &'static [TabAbi] = Box::leak(abis.into_boxed_slice());
    // SAFETY: leaked slice outlives the program.
    unsafe { modforge_native_ui_register_tabs(leaked.as_ptr(), leaked.len()) }
}
