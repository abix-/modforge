// Re-export of uespy's hook framework under the historic `hook` name.
// Implementation lives in `uespy::hook`. This shim keeps existing
// `crate::hook::*` call sites working without churn.

pub use uespy::hook::process_event;
pub use uespy::hook::vtable;
pub use uespy::hook::{OriginalProcessEvent, ProcessEventHook};
