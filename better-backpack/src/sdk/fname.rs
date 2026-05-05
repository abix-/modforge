// FName: 8 bytes ({ comparison_index: i32, number: u32 }). To resolve it to
// a string we call the game's AppendString export at module_base +
// offsets.append_string. Matches Basic.hpp:341.

use crate::sdk::fstring::FString;
use crate::sdk::offsets::PlatformOffsets;

#[repr(C)]
#[derive(Clone, Copy, Debug)]
pub struct FName {
    pub comparison_index: i32,
    pub number: u32,
}

impl FName {
    pub fn is_none(self) -> bool {
        self.comparison_index == 0 && self.number == 0
    }
}

type AppendStringFn = unsafe extern "system" fn(*const FName, *mut FString);

#[derive(Clone, Copy)]
pub struct NameResolver {
    append_string: AppendStringFn,
}

impl NameResolver {
    pub unsafe fn new(image_base: usize, offsets: &PlatformOffsets) -> Self {
        let addr = image_base + offsets.append_string;
        let append_string: AppendStringFn = unsafe { std::mem::transmute(addr) };
        Self { append_string }
    }

    pub unsafe fn to_string(&self, name: FName) -> String {
        let mut out = FString::default();
        unsafe { (self.append_string)(&name as *const FName, &mut out as *mut FString) };
        out.as_string()
    }
}
