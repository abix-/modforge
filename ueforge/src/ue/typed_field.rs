//! Typed offset wrapper.
//!
//! A `const`-constructible pair of `(byte_offset, T)` that documents
//! a UObject field at the static-declaration site. Read and write
//! still require `unsafe` (Rust can't prove the offset matches the
//! object's class); the win is that the offset and type travel
//! together everywhere instead of being duplicated at each call site
//! as a raw cast.
//!
//! Replaces the:
//!
//! ```ignore
//! unsafe { (obj.field_ptr(offset) as *const f32).read_unaligned() }
//! unsafe { (obj.field_ptr(offset) as *mut f32).write_unaligned(v) }
//! ```
//!
//! pattern that fills `apply.rs` / `kill_hook.rs` / `fall_hook.rs`
//! in every UE4SS-Rust mod.
//!
//! ```ignore
//! const MAX_HEALTH: TypedField<f32> = TypedField::at(0x0328);
//!
//! let v = unsafe { MAX_HEALTH.read(hc) };
//! unsafe { MAX_HEALTH.write(hc, v + 100.0) };
//! ```
//!
//! Centralizes the `read_unaligned` / `write_unaligned` discipline
//! and gives one place to add bounds validation against
//! [`UClass::properties_size`] later.

use std::marker::PhantomData;

use crate::ue::UObject;

#[derive(Debug)]
pub struct TypedField<T> {
    offset: usize,
    _phantom: PhantomData<fn() -> T>,
}

// Manual impls because PhantomData<fn() -> T> is invariant; we want
// TypedField to be Copy/Clone regardless of T.
impl<T> Copy for TypedField<T> {}
impl<T> Clone for TypedField<T> {
    fn clone(&self) -> Self {
        *self
    }
}

impl<T: Copy> TypedField<T> {
    /// Declare the field at byte `offset` from the start of the
    /// containing UObject. By convention you write these as `const`s
    /// or `static`s next to the class they belong to.
    pub const fn at(offset: usize) -> Self {
        Self {
            offset,
            _phantom: PhantomData,
        }
    }

    pub const fn offset(&self) -> usize {
        self.offset
    }

    /// Read `T` from `obj` at this field's offset.
    ///
    /// # Safety
    ///
    /// The caller asserts:
    /// - `obj` is a valid UObject of a class that places `T` at this
    ///   offset.
    /// - The bytes at the offset encode a valid `T`.
    pub unsafe fn read(&self, obj: &UObject) -> T {
        unsafe { obj.read_field(self.offset) }
    }

    /// Write `value` to `obj` at this field's offset.
    ///
    /// # Safety
    ///
    /// Same as [`Self::read`].
    pub unsafe fn write(&self, obj: &UObject, value: T) {
        unsafe { obj.write_field(self.offset, value) }
    }

    /// Raw mutable byte pointer to this field on `obj`. Use when the
    /// field is a heterogeneous struct best read field-by-field, or
    /// when you need to alias it with multiple typed views.
    ///
    /// # Safety
    ///
    /// The pointer is valid as long as `obj` is alive. Caller is
    /// responsible for choosing the right access width / alignment.
    pub unsafe fn ptr(&self, obj: &UObject) -> *mut u8 {
        unsafe { obj.field_ptr(self.offset) }
    }
}

/// Read a `*mut UObject` field at this offset and return a `&UObject`
/// view if non-null. Used for component-pointer fields like
/// `ASurvivalCharacter.HealthComponent` (UObject* at +0x1340).
///
/// Specialized impl for `TypedField<*mut UObject>` so the deref
/// stays inside the framework -- callers don't redo `field_ptr +
/// cast + read_unaligned + as_ref` per field.
impl TypedField<*mut UObject> {
    /// Follow this component pointer. Returns None if the pointer
    /// is null.
    ///
    /// # Safety
    ///
    /// `obj` must be a valid UObject of a class with a `*mut UObject`
    /// at this offset.
    pub unsafe fn deref<'a>(&self, obj: &'a UObject) -> Option<&'a UObject> {
        unsafe {
            let p: *mut UObject = obj
                .field_ptr(self.offset)
                .cast::<*mut UObject>()
                .read_unaligned();
            p.as_ref()
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn const_constructible() {
        const F: TypedField<f32> = TypedField::at(0x328);
        assert_eq!(F.offset(), 0x328);
    }

    #[test]
    fn copy_clone() {
        let a: TypedField<u32> = TypedField::at(0x10);
        let b = a;
        let c = b;
        assert_eq!(a.offset(), c.offset());
    }

    #[test]
    fn distinct_types_distinct_fields() {
        // Compile check: `TypedField<f32>` and `TypedField<u32>` are
        // different types even at the same offset, so accidental
        // mismatches between declared and read type are caught.
        let f: TypedField<f32> = TypedField::at(0x10);
        let u: TypedField<u32> = TypedField::at(0x10);
        assert_eq!(f.offset(), u.offset());
        // (No way to assign `f = u` -- that's the protection.)
    }
}
