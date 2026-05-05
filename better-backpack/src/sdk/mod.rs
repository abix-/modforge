// Minimal Unreal Engine SDK shim. Mirrors enough of the Dumper-7 surface
// for our hooks and patches: UObject + UClass + UFunction + FName + FString
// + TArray + GObjects walker + find_class_fast.
//
// All `unsafe` lives in this module. Higher-level code (patch.rs, inv_hook,
// etc.) uses the safe wrappers.

#![allow(dead_code)] // skeleton state; consumed by upcoming hook + patch modules

pub mod fname;
pub mod fstring;
pub mod offsets;
pub mod tarray;
pub mod uobject;

pub use fname::FName;
pub use fstring::FString;
pub use offsets::{Platform, PlatformOffsets};
pub use tarray::TArray;
pub use uobject::{
    GObjectsView, ProcessEventFn, Runtime, UClass, UFunction, UObject, find_class_fast,
    init_runtime, runtime, try_runtime,
};
