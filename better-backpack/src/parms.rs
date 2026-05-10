// #[repr(C)] mirrors of UFunction parameter layouts. Each one needs to
// match the engine's expectation byte-for-byte.

use std::ffi::c_void;

use ueforge::ue::{TArray, UObject};

pub const F_POINTER_EVENT_SIZE: usize = 0x80; // SlateCore_structs.hpp:836

#[repr(C)]
pub struct GetInventoryItemsParms {
    pub items: TArray<*mut UObject>,
}

#[repr(C)]
pub struct IntReturnParms {
    pub return_value: i32,
}

#[repr(C)]
pub struct GetChildAtParms {
    pub index: i32,
    pub _pad: i32,
    pub return_value: *mut UObject,
}

#[repr(C)]
pub struct SelectedIndexParms {
    pub index: i32,
}

#[repr(C)]
pub struct SetSelectedInventorySlotParms {
    pub slot: i32,
}

#[repr(C)]
pub struct GetItemInItemListSlotParms {
    pub item_list: TArray<*mut UObject>,
    pub index: i32,
    pub _pad: i32,
    pub world_context: *mut UObject,
    pub item: *mut UObject,
}

#[repr(C)]
pub struct InitializeItemSlotParms {
    pub item_slot: *mut UObject,
    pub item: *mut UObject,
}

#[repr(C)]
pub struct PointerEventGetWheelDeltaParms {
    pub input: [u8; F_POINTER_EVENT_SIZE],
    pub return_value: f32,
    pub _pad: u32,
}

#[repr(C)]
pub struct OnMouseWheelInputView {
    pub _my_geometry: [u8; 0x38],
    pub mouse_event: [u8; F_POINTER_EVENT_SIZE],
}

const _: () = {
    use std::mem::size_of;
    assert!(size_of::<GetChildAtParms>() == 0x10);
    assert!(size_of::<InitializeItemSlotParms>() == 0x10);
};

// Quiet "field is never read" warnings; consumed via raw pointer reads.
#[allow(dead_code)]
fn _force_use(_p: *mut c_void) {}
