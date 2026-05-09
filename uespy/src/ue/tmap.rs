//! `TMap<K, V>` walker.
//!
//! UE's `TMap` is `TSet<TPair<K, V>>` whose element type is
//! `TSetElement<TPair> { pair: 16, HashNextId: i32, HashIndex: i32 } = 24 bytes`.
//! The set's storage is a `TSparseArray` whose slots are a union of
//! the element + a 2-i32 free-list link, sized to the larger = 24 bytes.
//! Free slots can hold any 8 bytes in the first 8; we walk all slots
//! linearly and key-match (false hits on a real key colliding with
//! free-list links are vanishingly unlikely; if observed, gate via
//! the AllocationFlags `TBitArray` at `+0x10` of the TMap).
//!
//! Layout has been stable through UE 5.0-5.4. Constants live in
//! [`crate::ue::offsets::tmap`] so callers can override per game
//! if a future engine bump shifts them.
//!
//! Pure pointer math + `read_unaligned`. No allocations on the
//! happy path. Safe to call from any thread that's already serving
//! as game-thread (drained via `uespy::Queue`).

use crate::ue::UObject;
use crate::ue::offsets::tmap as off;

/// Walk every `TPair<K, V>` slot in a `TMap` field stored at
/// `offset` inside the given object. Yields `(slot_index, slot_ptr)`
/// pairs. Each `slot_ptr` is the start of the 24-byte
/// `TSetElement<TPair>` slot — the first 8 bytes are the key
/// (`K = FName` u64 in DataTable cases), the next 8 are the value.
///
/// Slot bytes for free entries don't satisfy the type invariant —
/// callers must filter by key match or by inspecting the allocation
/// flags TBitArray at `+0x10` of the TMap (not implemented here;
/// the linear scan + key match is the expected pattern).
///
/// # Safety
/// `obj` must be a live UObject and `offset` must point at a valid
/// TMap field. The returned pointer is valid until GObjects /
/// owning UPackage is mutated. Callers typically dereference the
/// 8-byte key + 8-byte value-pointer immediately and don't hold
/// the slot pointer across drains.
pub unsafe fn slots(obj: &UObject, offset: usize) -> impl Iterator<Item = (usize, *const u8)> {
    let (data_ptr, count) = unsafe { header(obj, offset) };
    (0..count.min(off::MAX_LINEAR_SCAN))
        .filter(move |_| !data_ptr.is_null())
        .map(move |i| (i, unsafe { data_ptr.add(i * off::ELEMENT_SIZE) }))
}

/// Read the TMap header at `obj.field_ptr(offset)`: returns
/// `(data_ptr, num_slots)`. `num_slots` includes both occupied
/// and free slots (the `TSparseArray` is dense in storage).
///
/// # Safety
/// Same as [`slots`].
pub unsafe fn header(obj: &UObject, offset: usize) -> (*const u8, usize) {
    unsafe {
        let row_map = obj.field_ptr(offset);
        let data_ptr = (row_map as *const *const u8).read_unaligned();
        let data_num = (row_map.add(off::DATA_NUM) as *const i32).read_unaligned();
        if data_ptr.is_null() || data_num <= 0 {
            (std::ptr::null(), 0)
        } else {
            (data_ptr, data_num as usize)
        }
    }
}

/// Find the slot whose `FName` key (u64-encoded) equals
/// `row_name`. Returns the value pointer (second 8 bytes of the
/// pair) when found.
///
/// # Safety
/// Same as [`slots`].
pub unsafe fn find_value_by_fname_key(
    obj: &UObject,
    offset: usize,
    row_name: u64,
) -> Option<*const u8> {
    unsafe {
        for (_, element) in slots(obj, offset) {
            let key: u64 = (element as *const u64).read_unaligned();
            if key == row_name {
                let value: *const u8 =
                    (element.add(off::PAIR_VALUE) as *const *const u8).read_unaligned();
                if !value.is_null() {
                    return Some(value);
                }
            }
        }
        None
    }
}
