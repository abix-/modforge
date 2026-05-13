//! Shutdown-handler registry. Moved into `modforge::shutdown`
//! during Phase 0b; the registry mechanics + the modforge
//! builtins (server, settings, scanner) live there. This module
//! re-exports the registry and adds ueforge's own
//! engine-specific `register_builtins` that registers the hook
//! shutdown handler at order 100 then chains to modforge's.

pub use modforge::shutdown::*;

/// Register every ueforge-shipped shutdown handler. Called once
/// from the `ueforge_mod_shutdown` macro path before
/// [`SHUTDOWN_REGISTRY::run_all`]. Registers UE-specific hooks
/// at order 100, then chains to modforge's builtins.
pub fn register_builtins() {
    SHUTDOWN_REGISTRY.register(ShutdownHandlerDef {
        name: "hook::shutdown_all",
        order: 100,
        run: || crate::hook::shutdown_all(),
    });
    modforge::shutdown::register_modforge_builtins();
}
