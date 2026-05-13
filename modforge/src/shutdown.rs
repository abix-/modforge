//! Shutdown-handler registry. The workspace-standard
//! `<Subject>Def` + `<Subject>Registry` for the
//! `ueforge_mod_shutdown` teardown sequence.
//!
//! ```text
//! K8s slot: Def=ShutdownHandlerDef, Registry=ShutdownRegistry
//!           (SHUTDOWN_REGISTRY singleton),
//!           Instance=per-call invocation, Controller=run_all()
//! ```
//!
//! Per [architecture.md](../docs/architecture.md), the framework's
//! shutdown sequence used to be a hardcoded match-equivalent
//! inside the `ueforge_mod_shutdown` macro: every new ueforge
//! subsystem that spawned threads had to edit the macro to add
//! its `shutdown_all()` line. Easy to forget; the cost showed
//! up as a hot-reload thread leak.
//!
//! Now the macro just runs `SHUTDOWN_REGISTRY.run_all()`. Each
//! ueforge subsystem registers itself via [`register_builtins`]
//! (called by the macro before the run). Game crates extend the
//! same registry from their `worker()` init for game-specific
//! cleanup (e.g. a custom poller's stop flag).
//!
//! ## Ordering
//!
//! Each handler carries an `order: u32`. `run_all` sorts ascending
//! before running, so lower numbers fire first. The framework's
//! built-ins use `100, 200, 300, 400` to leave room between them
//! for game-specific handlers that must interleave (e.g. a custom
//! poller that should stop BEFORE hooks tear down). Game crates
//! typically want their own cleanup at `50` (before framework)
//! or `500+` (after framework).
//!
//! ## Why not Drop?
//!
//! Drop runs at unpredictable times relative to UE4SS's
//! `FreeLibrary` call. The shutdown registry is invoked
//! synchronously from `ueforge_mod_shutdown` BEFORE the DLL
//! unloads, so handlers can safely touch heap memory + spin on
//! atomics. After `run_all` returns, no thread is on a stack in
//! our DLL via a registered subsystem.

use parking_lot::Mutex;

/// One shutdown step.
pub struct ShutdownHandlerDef {
    /// Used in the log line emitted before each step runs.
    pub name: &'static str,
    /// Lower runs first. Framework built-ins use multiples of
    /// 100 to leave gaps for game-specific interleaving.
    pub order: u32,
    /// Cleanup function. Must be sync; idempotent + safe-to-call-
    /// when-nothing-was-spawned (the registry `run_all` calls it
    /// unconditionally).
    pub run: fn(),
}

/// Workspace-standard registry of shutdown handlers.
pub struct ShutdownRegistry {
    entries: Mutex<Vec<ShutdownHandlerDef>>,
}

impl ShutdownRegistry {
    pub const fn new() -> Self {
        Self {
            entries: Mutex::new(Vec::new()),
        }
    }

    pub fn register(&self, def: ShutdownHandlerDef) {
        self.entries.lock().push(def);
    }

    pub fn register_many<I: IntoIterator<Item = ShutdownHandlerDef>>(&self, defs: I) {
        let mut g = self.entries.lock();
        for d in defs {
            g.push(d);
        }
    }

    /// Run every registered handler in `order` ascending. Logs
    /// each step. Stable sort: handlers at the same `order`
    /// preserve registration order.
    pub fn run_all(&self) {
        let snapshot: Vec<ShutdownHandlerDef> = {
            let mut g = self.entries.lock();
            // Stable sort by order. Handlers don't move; we just
            // observe them in order.
            g.sort_by_key(|d| d.order);
            // Take the entries out so handlers can re-register if
            // they want (rare; mostly defensive against double-run
            // during weird hot-reload races).
            std::mem::take(&mut *g)
        };
        let n = snapshot.len();
        for d in &snapshot {
            crate::log!("shutdown: '{}' (order {})", d.name, d.order);
            (d.run)();
        }
        crate::log!("shutdown: {n} handler(s) complete");
    }

    pub fn names(&self) -> Vec<&'static str> {
        self.entries.lock().iter().map(|d| d.name).collect()
    }

    pub fn len(&self) -> usize {
        self.entries.lock().len()
    }

    pub fn is_empty(&self) -> bool {
        self.entries.lock().is_empty()
    }
}

impl Default for ShutdownRegistry {
    fn default() -> Self {
        Self::new()
    }
}

/// Process-wide shutdown registry singleton.
pub static SHUTDOWN_REGISTRY: ShutdownRegistry = ShutdownRegistry::new();

/// Register modforge's own shutdown handlers (server, settings,
/// scanner). Each per-framework crate has its own
/// `register_builtins` that calls this PLUS its own
/// engine-specific handlers (hooks, etc.) in the right order.
///
/// Order convention:
/// - `100`. Hooks (per-framework; must run before any thread
///   join so trampolines stop firing first)
/// - `200`. HTTP listeners
/// - `300`. `Settings::watch` mtime pollers
/// - `400`. Scanner freeze sweeper
///
/// Game crates that need to interleave (e.g. their own poller
/// that drains via the framework's main-thread queue, must stop
/// BEFORE hooks tear down) register at `50` from `worker()`.
pub fn register_modforge_builtins() {
    SHUTDOWN_REGISTRY.register_many([
        ShutdownHandlerDef {
            name: "server::shutdown_all",
            order: 200,
            run: || crate::server::shutdown_all(),
        },
        ShutdownHandlerDef {
            name: "rpg::poller::shutdown_all",
            order: 250,
            run: || crate::rpg::poller::shutdown_all(),
        },
        ShutdownHandlerDef {
            name: "settings::shutdown_all",
            order: 300,
            run: || crate::settings::shutdown_all(),
        },
        ShutdownHandlerDef {
            name: "scanner::shutdown_sweeper_if_running",
            order: 400,
            run: || crate::scanner::shutdown_sweeper_if_running(),
        },
    ]);
}
