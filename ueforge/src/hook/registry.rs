//! Global registry of installed `ProcessEventHook`s. Game crates
//! used to `mem::forget` hook handles to keep them alive past
//! `worker()` thread exit; that broke hot-reload because the
//! handles' `Drop` (which restores vtable slots + drains
//! in-flight trampolines) never ran.
//!
//! The registry replaces `mem::forget` -- handles live in a
//! `static Mutex<Vec<ProcessEventHook>>`, so they survive the
//! init thread but are reachable for orderly teardown on
//! shutdown.
//!
//! `shutdown_all()` is wired into the framework's
//! `ueforge_mod_shutdown` (via [`crate::mod_main`]) and runs
//! after the game's `on_shutdown` callback returns. It:
//!
//! 1. Sets `process_event::SHUTTING_DOWN = true` so any new
//!    trampoline fires forward to the engine's original
//!    ProcessEvent without touching our handler closures.
//! 2. Drops every registered `ProcessEventHook`. Each Drop
//!    restores its class's vtable slot to the engine's
//!    original + waits up to 500ms for in-flight trampolines
//!    on that hook to drain.
//!
//! After this returns, no code in our DLL is on a thread's
//! stack via a PE trampoline; UE4SS can FreeLibrary safely.

use parking_lot::Mutex;

use super::process_event::{ProcessEventHook, SHUTTING_DOWN};

static REGISTRY: Mutex<Vec<ProcessEventHook>> = Mutex::new(Vec::new());

/// Register one hook with the global teardown registry. Replaces
/// `mem::forget(hook)` -- the handle stays alive past worker exit
/// (it's held in a static), but [`shutdown_all`] can find and
/// drop it.
pub fn register(hook: ProcessEventHook) {
    REGISTRY.lock().push(hook);
}

/// Register many hooks (e.g. the multi-class handle list returned
/// by `ProcessEventHook::install_many`).
pub fn register_many<I: IntoIterator<Item = ProcessEventHook>>(hooks: I) {
    let mut g = REGISTRY.lock();
    for h in hooks {
        g.push(h);
    }
}

/// Drop every registered hook in registration order, after
/// flipping the global `SHUTTING_DOWN` flag. Called by the
/// framework's shutdown path.
pub fn shutdown_all() {
    SHUTTING_DOWN.store(true, std::sync::atomic::Ordering::Release);
    // Take handles out before iterating so we don't hold the
    // registry lock while waiting for trampoline drains.
    let handles: Vec<ProcessEventHook> = std::mem::take(&mut *REGISTRY.lock());
    let n = handles.len();
    drop(handles);
    crate::log!("hook: shutdown_all dropped {n} hook(s)");
}
