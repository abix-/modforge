// Re-export of uespy's UE bindings under the historic `sdk` name.
// All implementation lives in `uespy::ue`. This shim keeps existing
// `crate::sdk::Foo` call sites working without churn.

pub use uespy::ue::{fname, fstring, offsets, tarray, uobject};

pub use fname::FName;
pub use fstring::FString;
pub use offsets::{Platform, PlatformOffsets};
pub use tarray::TArray;
pub use uobject::{
    GObjectsView, ProcessEventFn, Runtime, UClass, UFunction, UObject, find_class_fast,
    init_runtime, runtime, try_runtime,
};
