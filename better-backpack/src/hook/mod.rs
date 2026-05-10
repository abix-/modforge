// Re-export of ueforge's hook framework under the historic `hook` name.
// Implementation lives in `ueforge::hook`. This shim keeps existing
// `crate::hook::*` call sites working without churn.

pub use ueforge::hook::process_event;
pub use ueforge::hook::vtable;
pub use ueforge::hook::{OriginalProcessEvent, ProcessEventHook};
