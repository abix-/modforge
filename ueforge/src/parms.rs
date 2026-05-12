//! Test-side helpers for the `call` op's parm-buffer round-trip.
//!
//! Tests author `#[repr(C)] #[derive(zerocopy::FromBytes,
//! zerocopy::IntoBytes, zerocopy::Immutable, zerocopy::KnownLayout)]`
//! structs that mirror the SDK's UFunction parm layout, then use
//! these helpers to view them as bytes (for sending) and back
//! (for OUT params the engine wrote during the call).
//!
//! Compile-time layout verification via the zerocopy derives
//! makes both helpers SAFE: the trait bounds reject any parm
//! struct that has padding-with-pointers, non-POD fields, or
//! unknown alignment, before the bytes ever cross the FFI
//! boundary.

use zerocopy::{FromBytes, Immutable, IntoBytes, KnownLayout};

/// View a parm struct as bytes for `Api::call_ufunction`. Safe
/// because `T: IntoBytes` is the proof that every byte of `T`
/// is initialized + the layout is well-defined.
pub fn as_bytes<T: IntoBytes + Immutable>(parms: &T) -> &[u8] {
    parms.as_bytes()
}

/// Decode raw bytes back into a parm struct (e.g. to read OUT
/// parameters the engine wrote during the call). Safe because
/// `T: FromBytes` is the proof that any byte pattern of the
/// right length is a valid `T` (no validity invariants like
/// "non-null pointer" or "valid utf-8" allowed in `T`'s fields).
pub fn from_bytes<T: FromBytes + KnownLayout + Copy>(bytes: &[u8]) -> Result<T, String> {
    T::read_from_bytes(bytes).map_err(|e| {
        format!(
            "parm decode failed (bytes={} expected={}): {e}",
            bytes.len(),
            std::mem::size_of::<T>()
        )
    })
}
