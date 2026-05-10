//! Untyped byte-level read/write helpers for UObject fields.
//!
//! `TypedField<T>` (in `ue::typed_field`) is the structured way to
//! reference a field; it carries `T` in the type system so callers
//! can't mix up f32 vs u32 sites. These helpers are the **untyped**
//! escape hatch: when the offset / type is decided at runtime, when
//! debug code reads many shapes through one path, or when game-side
//! apply code wants the cheapest possible read.
//!
//! All functions are safe-typed wrappers around `read_unaligned` /
//! `write_unaligned` on `obj.field_ptr(offset)`. The pointer is
//! valid as long as the &UObject is, which is the caller's
//! responsibility.

use crate::ue::UObject;

/// Read an `f32` at `offset` from `obj`. Unaligned-safe.
#[inline]
pub fn read_f32(obj: &UObject, offset: usize) -> f32 {
    unsafe { (obj.field_ptr(offset) as *const f32).read_unaligned() }
}

/// Write an `f32` to `obj` at `offset`. Unaligned-safe.
#[inline]
pub fn write_f32(obj: &UObject, offset: usize, value: f32) {
    unsafe { (obj.field_ptr(offset) as *mut f32).write_unaligned(value) }
}

/// Read a `u32` at `offset` from `obj`. Unaligned-safe.
#[inline]
pub fn read_u32(obj: &UObject, offset: usize) -> u32 {
    unsafe { (obj.field_ptr(offset) as *const u32).read_unaligned() }
}

/// Write a `u32` to `obj` at `offset`. Unaligned-safe.
#[inline]
pub fn write_u32(obj: &UObject, offset: usize, value: u32) {
    unsafe { (obj.field_ptr(offset) as *mut u32).write_unaligned(value) }
}

/// Read an `i32` at `offset` from `obj`.
#[inline]
pub fn read_i32(obj: &UObject, offset: usize) -> i32 {
    unsafe { (obj.field_ptr(offset) as *const i32).read_unaligned() }
}

/// Write an `i32` to `obj` at `offset`.
#[inline]
pub fn write_i32(obj: &UObject, offset: usize, value: i32) {
    unsafe { (obj.field_ptr(offset) as *mut i32).write_unaligned(value) }
}

/// Read a `bool` at `offset` from `obj` (UE stores bools as a
/// single byte).
#[inline]
pub fn read_bool(obj: &UObject, offset: usize) -> bool {
    unsafe { (obj.field_ptr(offset) as *const u8).read() != 0 }
}

/// Write a `bool` to `obj` at `offset` as a single byte.
#[inline]
pub fn write_bool(obj: &UObject, offset: usize, value: bool) {
    unsafe { (obj.field_ptr(offset) as *mut u8).write(if value { 1 } else { 0 }) }
}

/// Follow a `*mut UObject` ptr at `offset` from `parent`. Returns
/// `None` if the pointer is null.
///
/// Use this for component slots on actors:
/// `read_component_ptr(player, ASC_HEALTH_COMPONENT)` returns the
/// player's `UHealthComponent` (or `None` if not yet bound).
#[inline]
pub fn read_component_ptr(parent: &UObject, offset: usize) -> Option<&UObject> {
    unsafe {
        let p: *mut UObject = parent
            .field_ptr(offset)
            .cast::<*mut UObject>()
            .read_unaligned();
        p.as_ref()
    }
}
