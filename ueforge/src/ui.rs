//! ImGui bindings for UE4SS mod tabs. Game mods call these from
//! `render` callbacks registered via [`crate::mod_main::ue4ss_mod`].
//!
//! Every function takes a Rust `&str` and forwards to the C++
//! ImGui via a UTF-8 byte range, so labels round-trip without
//! null-termination management.
//!
//! Surface starts small and grows on demand. For anything missing,
//! the C side bridge file is `ueforge/cpp/ueforge_ui.cpp`; add the
//! extern "C" wrapper there and the safe wrapper here.

use std::os::raw::{c_char, c_int};

unsafe extern "C" {
    fn ueforge_ui_text(s: *const c_char, n: usize);
    fn ueforge_ui_text_disabled(s: *const c_char, n: usize);
    fn ueforge_ui_text_colored(s: *const c_char, n: usize, r: f32, g: f32, b: f32, a: f32);

    fn ueforge_ui_button(s: *const c_char, n: usize, w: f32, h: f32) -> bool;
    fn ueforge_ui_small_button(s: *const c_char, n: usize) -> bool;
    fn ueforge_ui_checkbox(s: *const c_char, n: usize, v: *mut bool) -> bool;
    fn ueforge_ui_slider_float(s: *const c_char, n: usize, v: *mut f32, lo: f32, hi: f32) -> bool;
    fn ueforge_ui_slider_int(s: *const c_char, n: usize, v: *mut c_int, lo: c_int, hi: c_int) -> bool;
    fn ueforge_ui_input_int(s: *const c_char, n: usize, v: *mut c_int) -> bool;
    fn ueforge_ui_collapsing_header(s: *const c_char, n: usize) -> bool;

    fn ueforge_ui_progress_bar(fraction: f32, overlay: *const c_char, overlay_n: usize);
    fn ueforge_ui_separator();
    fn ueforge_ui_spacing();
    fn ueforge_ui_same_line(x: f32);
    fn ueforge_ui_new_line();
    fn ueforge_ui_indent(w: f32);
    fn ueforge_ui_unindent(w: f32);
    fn ueforge_ui_dummy(w: f32, h: f32);
    fn ueforge_ui_set_next_item_width(w: f32);

    fn ueforge_ui_begin_disabled(disabled: bool);
    fn ueforge_ui_end_disabled();

    fn ueforge_ui_tree_node(s: *const c_char, n: usize) -> bool;
    fn ueforge_ui_tree_pop();

    fn ueforge_ui_begin_group();
    fn ueforge_ui_end_group();
}

#[inline]
fn raw(s: &str) -> (*const c_char, usize) {
    (s.as_ptr() as *const c_char, s.len())
}

// ---- text ----

pub fn text(s: &str) {
    let (p, n) = raw(s);
    unsafe { ueforge_ui_text(p, n) }
}

pub fn text_disabled(s: &str) {
    let (p, n) = raw(s);
    unsafe { ueforge_ui_text_disabled(p, n) }
}

/// `(r, g, b, a)` in 0.0–1.0.
pub fn text_colored(s: &str, color: (f32, f32, f32, f32)) {
    let (p, n) = raw(s);
    unsafe { ueforge_ui_text_colored(p, n, color.0, color.1, color.2, color.3) }
}

// ---- buttons / interactive ----

pub fn button(label: &str) -> bool {
    let (p, n) = raw(label);
    unsafe { ueforge_ui_button(p, n, 0.0, 0.0) }
}

/// Button with an explicit `(width, height)`. Use `0.0` for
/// auto-fit on either axis.
pub fn button_sized(label: &str, w: f32, h: f32) -> bool {
    let (p, n) = raw(label);
    unsafe { ueforge_ui_button(p, n, w, h) }
}

pub fn small_button(label: &str) -> bool {
    let (p, n) = raw(label);
    unsafe { ueforge_ui_small_button(p, n) }
}

pub fn checkbox(label: &str, v: &mut bool) -> bool {
    let (p, n) = raw(label);
    unsafe { ueforge_ui_checkbox(p, n, v as *mut bool) }
}

pub fn slider_f32(label: &str, v: &mut f32, lo: f32, hi: f32) -> bool {
    let (p, n) = raw(label);
    unsafe { ueforge_ui_slider_float(p, n, v as *mut f32, lo, hi) }
}

pub fn slider_i32(label: &str, v: &mut i32, lo: i32, hi: i32) -> bool {
    let (p, n) = raw(label);
    unsafe { ueforge_ui_slider_int(p, n, v as *mut c_int, lo as c_int, hi as c_int) }
}

pub fn input_i32(label: &str, v: &mut i32) -> bool {
    let (p, n) = raw(label);
    unsafe { ueforge_ui_input_int(p, n, v as *mut c_int) }
}

pub fn collapsing_header(label: &str) -> bool {
    let (p, n) = raw(label);
    unsafe { ueforge_ui_collapsing_header(p, n) }
}

// ---- layout / spacing ----

pub fn progress_bar(fraction: f32, overlay: Option<&str>) {
    match overlay {
        Some(s) => {
            let (p, n) = raw(s);
            unsafe { ueforge_ui_progress_bar(fraction, p, n) }
        }
        None => unsafe { ueforge_ui_progress_bar(fraction, std::ptr::null(), 0) },
    }
}

pub fn separator() { unsafe { ueforge_ui_separator() } }
pub fn spacing()   { unsafe { ueforge_ui_spacing() } }
pub fn new_line()  { unsafe { ueforge_ui_new_line() } }
pub fn dummy(w: f32, h: f32) { unsafe { ueforge_ui_dummy(w, h) } }
pub fn set_next_item_width(w: f32) { unsafe { ueforge_ui_set_next_item_width(w) } }

/// Place the next widget on the same line as the previous one.
/// `x = 0.0` uses ImGui's default spacing.
pub fn same_line() { unsafe { ueforge_ui_same_line(0.0) } }
pub fn same_line_at(x: f32) { unsafe { ueforge_ui_same_line(x) } }

pub fn indent()   { unsafe { ueforge_ui_indent(0.0) } }
pub fn unindent() { unsafe { ueforge_ui_unindent(0.0) } }
pub fn indent_by(w: f32)   { unsafe { ueforge_ui_indent(w) } }
pub fn unindent_by(w: f32) { unsafe { ueforge_ui_unindent(w) } }

// ---- groups ----

pub fn begin_disabled(disabled: bool) { unsafe { ueforge_ui_begin_disabled(disabled) } }
pub fn end_disabled()                 { unsafe { ueforge_ui_end_disabled() } }

/// RAII guard pattern for `begin_disabled` / `end_disabled`.
/// Works around the easy bug of forgetting `end_disabled` on an
/// early-return path.
pub struct Disabled;
impl Disabled {
    pub fn new(disabled: bool) -> Self { begin_disabled(disabled); Self }
}
impl Drop for Disabled {
    fn drop(&mut self) { end_disabled(); }
}

pub fn begin_group() { unsafe { ueforge_ui_begin_group() } }
pub fn end_group()   { unsafe { ueforge_ui_end_group() } }

pub struct Group;
impl Group {
    pub fn new() -> Self { begin_group(); Self }
}
impl Default for Group {
    fn default() -> Self { Self::new() }
}
impl Drop for Group {
    fn drop(&mut self) { end_group(); }
}

// ---- trees ----

/// Open a tree node; returns `true` if children should be rendered.
/// Pair with [`tree_pop`] when the return is true.
pub fn tree_node(label: &str) -> bool {
    let (p, n) = raw(label);
    unsafe { ueforge_ui_tree_node(p, n) }
}
pub fn tree_pop() { unsafe { ueforge_ui_tree_pop() } }
