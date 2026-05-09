//! `UDataTable` row helpers.
//!
//! A `UDataTable` carries a `TMap<FName, uint8*>` named `RowMap`
//! at `+0x30`. Each value pointer points at the row struct's bytes,
//! which the caller decodes with a `#[repr(C)]` struct mirroring
//! the row's `RowStruct` layout (per-game).
//!
//! Helpers here cover the two common shapes:
//! - "I have an FName, give me the row pointer."
//! - "Give me every row as `(name, ptr)` so I can scan."
//!
//! Plus a class-name-to-instance helper built on `walk_class`'s
//! engine pieces so a test can do
//!
//! ```ignore
//! let dt = uespy::ue::datatable::find_by_short_name("DT_Materials")
//!     .ok_or("no DT_Materials")?;
//! let row = uespy::ue::datatable::row_value_by_fname(dt, my_fname)
//!     .ok_or("row not in table")?;
//! // SAFETY: row points at FRowStruct bytes (per game)
//! let v: u32 = unsafe { (row.add(STACK_OFFSET) as *const u32).read_unaligned() };
//! ```

use crate::ue::offsets::datatable as off;
use crate::ue::{self, UObject, fname::FName, tmap};

/// Pointer to the row struct's bytes for the given FName, or
/// `None` if the table has no such row.
///
/// # Safety
/// `table` must be a live `UDataTable`. The returned pointer is
/// only valid until GObjects / the table is mutated.
pub unsafe fn row_value_by_fname(table: &UObject, row_name: FName) -> Option<*const u8> {
    let key: u64 = unsafe { std::mem::transmute_copy(&row_name) };
    unsafe { tmap::find_value_by_fname_key(table, off::ROW_MAP, key) }
}

/// Iterate every `(FName-as-u64, row_ptr)` pair in the table's
/// RowMap. Free / unallocated slots are filtered by null value
/// pointer; callers should additionally validate the FName by
/// resolving it against the global name resolver before treating
/// the key as canonical.
///
/// # Safety
/// `table` must be a live `UDataTable`.
pub unsafe fn iter_rows(table: &UObject) -> impl Iterator<Item = (u64, *const u8)> + '_ {
    let inner = unsafe { tmap::slots(table, off::ROW_MAP) };
    inner.filter_map(move |(_, element)| unsafe {
        let key: u64 = (element as *const u64).read_unaligned();
        let value: *const u8 =
            (element.add(crate::ue::offsets::tmap::PAIR_VALUE) as *const *const u8)
                .read_unaligned();
        if value.is_null() {
            None
        } else {
            Some((key, value))
        }
    })
}

/// Find the first non-CDO `UDataTable` instance whose short name
/// matches `name`. Walks GObjects; cost is one full pass. Returns
/// the live UObject reference (lifetime extended to `'static`,
/// caller is on a game-thread / quiescent-period stability
/// contract — see `uespy::selector::resolve_generic`).
pub fn find_by_short_name(name: &str) -> Option<&'static UObject> {
    let rt = ue::try_runtime()?;
    let class = ue::find_class_fast("DataTable")?;
    let view = unsafe { ue::GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return None;
    }
    for obj in view.iter() {
        if !obj.is_a(class) {
            continue;
        }
        if obj.is_default_object() {
            continue;
        }
        if obj.name() == name {
            // SAFETY: lifetime extension — see selector::resolve_generic.
            let extended: &'static UObject =
                unsafe { std::mem::transmute::<&UObject, &'static UObject>(obj) };
            return Some(extended);
        }
    }
    None
}
