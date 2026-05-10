// VTable patching primitives + RAII ProcessEvent hook.

#![allow(dead_code)]

pub mod process_event;
pub mod vtable;

pub use process_event::{OriginalProcessEvent, ProcessEventHook};
