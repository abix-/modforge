//! Shutdown registry. Lives in `modforge::shutdown`; modforge's own
//! jobs (server, pollers, settings watchers, byte patches, scanner)
//! record their undos there as they start. This module re-exports
//! the registry and adds ueforge's hook teardown at order 100.

pub use modforge::shutdown::*;

/// Register ueforge's hook teardown. Called once from the
/// `ueforge_mod_shutdown` macro path before
/// [`SHUTDOWN_REGISTRY::run_all`].
pub fn register_builtins() {
    SHUTDOWN_REGISTRY.register(ShutdownHandlerDef {
        name: "hook::shutdown_all",
        order: 100,
        run: || crate::hook::shutdown_all(),
    });
    SHUTDOWN_REGISTRY.register(ShutdownHandlerDef {
        name: "hook::native_function::shutdown_all",
        order: 100,
        run: || crate::hook::native_function::shutdown_all(),
    });
    SHUTDOWN_REGISTRY.register(ShutdownHandlerDef {
        name: "hook::script_function::shutdown_all",
        order: 100,
        run: || crate::hook::script_function::shutdown_all(),
    });
}
