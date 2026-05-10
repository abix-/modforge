//! UE5 status-effect surface: data-table row mutation +
//! `CreateAndAddEffect` UFunction invocation.
//!
//! UE5 RPGs route gear / perk / status effects through one of
//! two patterns. The canonical one (used by Maine, and by every
//! game that copies it) is **row-driven**:
//!
//! 1. A `UDataTable` (e.g. `Table_StatusEffects`) holds rows of
//!    a `UScriptStruct` whose layout includes a `Type` (enum) +
//!    `Value` (f32) field.
//! 2. The game adds an effect to a target by calling a UFunction
//!    on the target's `UStatusEffectComponent` (or the game's
//!    analogue), passing an `FDataTableRowHandle` `(table*, row_fname)`.
//! 3. The component reads the row's Value and applies the
//!    effect.
//!
//! We can change a stat dynamically by mutating the row's Value
//! field BEFORE calling `CreateAndAddEffect`. Then every consumer
//! of that row -- our skill, AND any vanilla actor that uses the
//! same row -- sees the new value. Pick a benign / unused row
//! per skill to avoid cross-contamination.
//!
//! ```ignore
//! use ueforge::ue::{ClassRef, status_effect, TypedField};
//!
//! static SE_COMPONENT: ClassRef = ClassRef::new("StatusEffectComponent");
//!
//! // Update the row...
//! unsafe {
//!     status_effect::write_row_value(row_ptr, status_effect::DEFAULT_VALUE_OFFSET, 0.5);
//! }
//!
//! // ...then add the effect to the player's component.
//! let func = SE_COMPONENT.find_function("CreateAndAddEffect").unwrap();
//! status_effect::create_and_add_effect(
//!     player_sec, func, table, row_fname,
//! );
//! ```

use std::ffi::c_void;

use crate::ue::{UFunction, UObject};

/// Default byte offset of the `Value: f32` field within a UE5
/// status-effect row struct (`FStatusEffectData` in Maine; varies
/// per game). Override with the game's actual struct offset if it
/// differs.
pub const DEFAULT_VALUE_OFFSET: usize = 0x34;

/// Default byte offset of the `Type: u8` field (the
/// `EStatusEffectType` enum) within a UE5 status-effect row
/// struct.
pub const DEFAULT_TYPE_OFFSET: usize = 0x30;

/// Read the f32 value field at `offset` from a status-effect
/// row's raw bytes.
///
/// # Safety
/// `row_ptr` must be a live pointer into a `UDataTable` row
/// whose backing struct has an `f32` at `offset`.
pub unsafe fn read_row_value(row_ptr: *const u8, offset: usize) -> f32 {
    unsafe { (row_ptr.add(offset) as *const f32).read_unaligned() }
}

/// Read the u8 stat-type field at `offset` from a status-effect
/// row's raw bytes.
///
/// # Safety
/// Same as [`read_row_value`].
pub unsafe fn read_row_type(row_ptr: *const u8, offset: usize) -> u8 {
    unsafe { (row_ptr.add(offset) as *const u8).read_unaligned() }
}

/// Mutate a status-effect row's f32 value in-place. Returns the
/// previous value.
///
/// # Safety
/// Same as [`read_row_value`]. Mutating a shared row affects
/// every consumer of that row -- pick a benign / per-skill row
/// to avoid cross-contamination.
pub unsafe fn write_row_value(
    row_ptr: *const u8,
    offset: usize,
    new_value: f32,
) -> f32 {
    unsafe {
        let p = row_ptr.add(offset) as *mut f32;
        let prev = p.read_unaligned();
        p.write_unaligned(new_value);
        prev
    }
}

/// `FDataTableRowHandle` parm shape for `CreateAndAddEffect`.
///
/// Cooked UE5 layout:
///
/// ```text
/// FDataTableRowHandle StatusEffectRowHandle  // 16 bytes
///   - UDataTable* DataTable                  // 8 bytes
///   - FName       RowName                    // 8 bytes (u64)
/// class UStatusEffect* ReturnValue           // 8 bytes (OUT)
/// ```
///
/// Total: 24 bytes. Used as the parm buffer for the UFunction
/// call.
#[repr(C)]
struct CreateAndAddEffectParms {
    data_table: *const UObject,
    row_fname: u64,
    return_value: *mut UObject,
}

/// Invoke a `CreateAndAddEffect`-shaped UFunction on `component`
/// with the given table + row FName. Returns the
/// `UStatusEffect*` the engine wrote to the OUT parm (or null
/// if the engine refused).
///
/// `function_ptr` is the resolved `&UFunction` -- typically
/// cached at install via `ClassRef::find_function("CreateAndAddEffect")`.
///
/// MUST be called on the game thread (process_event re-enters
/// the engine's PE machinery). Enqueue via `Queue` if calling
/// from off-thread.
pub fn create_and_add_effect(
    component: &UObject,
    function_ptr: &UFunction,
    table: &UObject,
    row_fname: u64,
) -> *mut UObject {
    let mut parms = CreateAndAddEffectParms {
        data_table: table as *const UObject,
        row_fname,
        return_value: std::ptr::null_mut(),
    };
    unsafe {
        component.process_event(function_ptr, &mut parms as *mut _ as *mut c_void);
    }
    parms.return_value
}

/// `RemoveEffect`-style invocation. Many games expose a
/// `RemoveStatusEffect(FDataTableRowHandle)` UFunction that
/// undoes a previous add. Same parm shape.
pub fn remove_effect(
    component: &UObject,
    function_ptr: &UFunction,
    table: &UObject,
    row_fname: u64,
) {
    let mut parms = CreateAndAddEffectParms {
        data_table: table as *const UObject,
        row_fname,
        return_value: std::ptr::null_mut(),
    };
    unsafe {
        component.process_event(function_ptr, &mut parms as *mut _ as *mut c_void);
    }
}
