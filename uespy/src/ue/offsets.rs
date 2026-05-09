// SDK-version-coupled offset constants. Cross-checked against
// `C:\Tools\work\sdk\SDK\Basic.hpp` from Dumper-7.
//
// Two builds: Steam and Xbox Game Pass. We pick at runtime by matching the
// host process exe name -- see `detect_platform`.

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Platform {
    Steam,
    Xbox,
}

#[derive(Debug, Clone, Copy)]
pub struct PlatformOffsets {
    pub g_objects: usize,
    pub append_string: usize,
    pub g_names: usize,
    pub g_world: usize,
    pub process_event: usize,
    pub process_event_idx: usize,
}

pub const STEAM: PlatformOffsets = PlatformOffsets {
    g_objects: 0x09F6_7028,
    append_string: 0x0125_2060,
    g_names: 0x09E4_A7B8,
    g_world: 0x09C7_A2E0,
    process_event: 0x0146_E7B0,
    process_event_idx: 0x4C,
};

pub const XBOX: PlatformOffsets = PlatformOffsets {
    g_objects: 0x09F3_6F28,
    append_string: 0x0125_0F80,
    g_names: 0x09E1_A6B8,
    g_world: 0x09C4_A2C0,
    process_event: 0x0146_D530,
    process_event_idx: 0x4C,
};

impl Platform {
    pub fn offsets(self) -> &'static PlatformOffsets {
        match self {
            Platform::Steam => &STEAM,
            Platform::Xbox => &XBOX,
        }
    }
}

// Field offsets inside UObject and its derived classes. These are stable
// across the two platforms because they're determined by the C++ class
// layout, not by where the binary places statics.

pub mod uobject {
    pub const VTABLE: usize = 0x00;
    pub const FLAGS: usize = 0x08;
    pub const INDEX: usize = 0x0C;
    pub const CLASS: usize = 0x10;
    pub const NAME: usize = 0x18;
    pub const OUTER: usize = 0x20;
    pub const SIZE: usize = 0x28;
}

pub mod ufield {
    pub const NEXT: usize = 0x28;
    pub const SIZE: usize = 0x30;
}

pub mod ustruct {
    pub const SUPER_STRUCT: usize = 0x40;
    pub const CHILDREN: usize = 0x48;
    pub const SIZE: usize = 0xB0;
}

pub mod uclass {
    pub const CAST_FLAGS: usize = 0xD8;
    pub const CLASS_DEFAULT_OBJECT: usize = 0x110;
    pub const SIZE: usize = 0x200;
}

pub mod ufunction {
    pub const FUNCTION_FLAGS: usize = 0xB0;
    pub const SIZE: usize = 0xE0;
}

pub mod tuobject_array {
    pub const OBJECTS: usize = 0x00;
    pub const MAX_ELEMENTS: usize = 0x08;
    pub const NUM_ELEMENTS: usize = 0x0C;
}

pub mod fuobject_item {
    pub const OBJECT: usize = 0x00;
    pub const SIZE: usize = 0x18;
}

// FUNC_Native flag, set when calling FString-returning BlueprintPure
// statics so the engine doesn't try to allocate result params.
pub const FUNC_NATIVE: u32 = 0x400;
