//! Safe Rust wrappers over the `modforge_ui_*` extern C surface
//! exposed by the native-ui backend.
//!
//! Mirrors the shape of `ueforge::ui::*` so tab `render` bodies stay
//! BYTE-IDENTICAL across backends. Phase B will promote
//! `ueforge::ui::*` to re-export this module instead of running its
//! own copy.
//!
//! ## Lifetime contract
//!
//! These functions are valid ONLY from inside a tab `render: fn()`
//! callback dispatched by the native backend's render loop. Calling
//! them from any other thread is undefined behavior: ImGui state is
//! owned by the render thread.

use std::os::raw::{c_char, c_int};

unsafe extern "C" {
    fn modforge_ui_text(s: *const c_char, n: usize);
    fn modforge_ui_text_disabled(s: *const c_char, n: usize);
    fn modforge_ui_button(s: *const c_char, n: usize, w: f32, h: f32) -> bool;
    fn modforge_ui_checkbox(s: *const c_char, n: usize, v: *mut bool) -> bool;
    fn modforge_ui_slider_float(
        s: *const c_char,
        n: usize,
        v: *mut f32,
        lo: f32,
        hi: f32,
    ) -> bool;
    fn modforge_ui_slider_int(
        s: *const c_char,
        n: usize,
        v: *mut c_int,
        lo: c_int,
        hi: c_int,
    ) -> bool;
    fn modforge_ui_separator();
    fn modforge_ui_spacing();
    fn modforge_ui_same_line(x: f32);
}

#[inline]
fn raw(s: &str) -> (*const c_char, usize) {
    (s.as_ptr() as *const c_char, s.len())
}

/// Render a plain text line.
pub fn text(s: &str) {
    let (p, n) = raw(s);
    // SAFETY: the C side reads the UTF-8 range and never retains it.
    unsafe { modforge_ui_text(p, n) }
}

/// Render text in the disabled-text style.
pub fn text_disabled(s: &str) {
    let (p, n) = raw(s);
    // SAFETY: same as `text`.
    unsafe { modforge_ui_text_disabled(p, n) }
}

/// Auto-sized button. Returns true on the frame it was clicked.
pub fn button(label: &str) -> bool {
    let (p, n) = raw(label);
    // SAFETY: same FFI contract as `text`.
    unsafe { modforge_ui_button(p, n, 0.0, 0.0) }
}

/// Button with explicit `(width, height)`. Use `0.0` for auto-fit.
pub fn button_sized(label: &str, w: f32, h: f32) -> bool {
    let (p, n) = raw(label);
    // SAFETY: same FFI contract as `text`.
    unsafe { modforge_ui_button(p, n, w, h) }
}

/// Editable boolean. Returns true on the frame the user toggled it.
pub fn checkbox(label: &str, v: &mut bool) -> bool {
    let (p, n) = raw(label);
    // SAFETY: `v` is a unique mut borrow; the C side writes at most once.
    unsafe { modforge_ui_checkbox(p, n, v as *mut bool) }
}

/// Editable float in `[lo, hi]`.
pub fn slider_f32(label: &str, v: &mut f32, lo: f32, hi: f32) -> bool {
    let (p, n) = raw(label);
    // SAFETY: `v` is a unique mut borrow; the C side writes at most once.
    unsafe { modforge_ui_slider_float(p, n, v as *mut f32, lo, hi) }
}

/// Editable int in `[lo, hi]`.
pub fn slider_i32(label: &str, v: &mut i32, lo: i32, hi: i32) -> bool {
    let (p, n) = raw(label);
    // SAFETY: `v` is a unique mut borrow; the C side writes at most once.
    unsafe { modforge_ui_slider_int(p, n, v as *mut c_int, lo as c_int, hi as c_int) }
}

/// Horizontal rule.
pub fn separator() {
    // SAFETY: parameter-less ImGui call.
    unsafe { modforge_ui_separator() }
}

/// Blank vertical gap.
pub fn spacing() {
    // SAFETY: parameter-less ImGui call.
    unsafe { modforge_ui_spacing() }
}

/// Continue on the previous line. `x = 0.0` uses ImGui's default
/// spacing.
pub fn same_line() {
    // SAFETY: parameter-less ImGui call.
    unsafe { modforge_ui_same_line(0.0) }
}
