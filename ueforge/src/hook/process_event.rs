// RAII ProcessEventHook. Patches a class's vtable slot at
// ProcessEventIdx with a trampoline that dispatches to a user-provided
// handler closure. Drop restores the original.
//
// Multiple hooks can be installed against different classes -- the
// trampoline matches on the live vtable pointer of the incoming `this`.

use std::cell::Cell;
use std::ffi::c_void;
use std::sync::Arc;
use std::sync::LazyLock;
use std::sync::atomic::{AtomicBool, AtomicU64, AtomicUsize, Ordering};
use std::time::{Duration, Instant};

use arc_swap::ArcSwap;
use parking_lot::Mutex;

use crate::ue::{self, ProcessEventFn, UClass, UFunction, UObject, find_class_fast, try_runtime};

use super::vtable;

/// Wrapper around the original ProcessEvent function pointer. Calling it
/// dispatches into the engine's real implementation.
#[derive(Clone, Copy)]
pub struct OriginalProcessEvent {
    f: ProcessEventFn,
}

impl OriginalProcessEvent {
    pub unsafe fn call(&self, this: &UObject, function: &UFunction, parms: *mut c_void) {
        // Mark "handler already called engine" so the trampoline's
        // panic-recovery arm does NOT call the engine a second time
        // if the handler panics AFTER this returns. Double-call on
        // a kill multicast would double-credit XP.
        CALLED_ORIGINAL.with(|c| c.set(true));
        unsafe { (self.f)(this as *const UObject, function as *const UFunction, parms) };
    }
}

// Per-thread guard set by OriginalProcessEvent::call. The
// trampoline saves/restores around handler invocation so reentrant
// hook fires (handler calls a UFunction whose multicast re-enters
// the same trampoline) preserve the outer frame's flag correctly.
thread_local! {
    static CALLED_ORIGINAL: Cell<bool> = const { Cell::new(false) };
}

type Handler = Box<dyn Fn(&UObject, &UFunction, *mut c_void, OriginalProcessEvent) + Send + Sync>;

struct Entry {
    class_name: &'static str,
    slot: *mut *mut c_void,
    vtable: *mut *mut c_void,
    original: ProcessEventFn,
    handler: Handler,
    /// Number of trampolines currently inside this entry's
    /// handler (incremented at trampoline entry, decremented at
    /// exit). Drop spins on this until it hits 0 (with a
    /// timeout) so we don't unload code that's mid-execution.
    active_calls: AtomicUsize,
    /// Cumulative count of handler panics caught by the
    /// trampoline's `catch_unwind`. Without this, panics in
    /// trampolines are invisible to the snapshot endpoint --
    /// the game keeps running but the mod silently swallows
    /// errors. Surfaced via [`panic_count`] / [`panic_count_total`].
    panic_count: AtomicU64,
}

unsafe impl Send for Entry {}
unsafe impl Sync for Entry {}

// REGISTRY is the canonical mutable list, touched only by install/drop
// (cold paths). The trampoline reads SNAPSHOT -- an ArcSwap of the
// current entry list. Read is one atomic load + Arc clone, no mutex.
// Replaces the old hand-rolled AtomicPtr<&'static [...]> that leaked
// every install/drop.
static REGISTRY: Mutex<Vec<&'static Entry>> = Mutex::new(Vec::new());
static SNAPSHOT: LazyLock<ArcSwap<Vec<&'static Entry>>> =
    LazyLock::new(|| ArcSwap::from_pointee(Vec::new()));

/// Cumulative count of `Entry` allocations made by any hook install
/// in this process. Each install `Box::leak`s one entry that is
/// never freed (see "Hot-reload teardown" in hooks.md for why
/// reuse-across-DLL-unloads is unsafe). The counter lets dev
/// sessions detect runaway accumulation: a single hot-reload cycle
/// adds ~N entries (one per hook your mod installs), so 1000
/// reloads with 5 hooks per cycle is ~5000 leaked entries.
static LEAKED_ENTRY_COUNT: AtomicU64 = AtomicU64::new(0);

/// Cumulative count of leaked `Entry` allocations. See
/// [`LEAKED_ENTRY_COUNT`] for the why. Snapshot endpoints surface
/// this so dev sessions can watch for runaway growth across
/// hot-reload iterations.
pub fn leaked_entry_count() -> u64 {
    LEAKED_ENTRY_COUNT.load(Ordering::Relaxed)
}

/// Set during shutdown to short-circuit handler dispatch. New
/// trampoline fires call original directly without touching our
/// handler closure (which may be on the verge of being dropped).
/// Already-in-flight handlers continue normally.
pub(super) static SHUTTING_DOWN: AtomicBool = AtomicBool::new(false);

fn publish_snapshot(reg: &[&'static Entry]) {
    SNAPSHOT.store(Arc::new(reg.to_vec()));
}

pub struct ProcessEventHook {
    entry: &'static Entry,
}

impl ProcessEventHook {
    pub fn install<F>(class_name: &'static str, handler: F) -> Result<Self, &'static str>
    where
        F: Fn(&UObject, &UFunction, *mut c_void, OriginalProcessEvent) + Send + Sync + 'static,
    {
        let cls: &UClass = find_class_fast(class_name).ok_or("class not found")?;
        let cdo = cls.class_default_object().ok_or("class has no CDO")?;

        let vtable: *mut *mut c_void = unsafe {
            (cdo as *const UObject as *const u8)
                .add(ue::offsets::uobject::VTABLE)
                .cast::<*mut *mut c_void>()
                .read_unaligned()
        };
        if vtable.is_null() {
            return Err("vtable pointer is null");
        }

        let slot_idx = try_runtime()
            .ok_or("ueforge runtime not initialized; install hooks AFTER init_runtime")?
            .platform_offsets
            .process_event_idx;
        let slot = unsafe { vtable.add(slot_idx) };
        let original_raw = unsafe { *slot };
        if original_raw.is_null() {
            return Err("ProcessEvent slot is null");
        }
        let original: ProcessEventFn = unsafe { std::mem::transmute(original_raw) };

        // Leak the entry: lifetimes must outlive every dispatch, even if the
        // user drops the ProcessEventHook handle. Drop reverts the slot but
        // does not free the Entry, since racing dispatches may still hold a
        // reference, AND the heap-allocated handler closure is unsafe to free
        // across a DLL unload (its vtable points into freed module code).
        // Memory cost is bounded by the number of hook installs over the
        // process lifetime, instrumented via `LEAKED_ENTRY_COUNT`.
        let entry: &'static Entry = Box::leak(Box::new(Entry {
            class_name,
            slot,
            vtable,
            original,
            handler: Box::new(handler),
            active_calls: AtomicUsize::new(0),
            panic_count: AtomicU64::new(0),
        }));
        LEAKED_ENTRY_COUNT.fetch_add(1, Ordering::Relaxed);

        {
            let mut reg = REGISTRY.lock();
            reg.push(entry);
            publish_snapshot(&reg);
        }

        let prev = unsafe { vtable::write_slot(slot, trampoline as *mut c_void) };
        if prev.is_none() {
            // back out: remove from registry, leak entry (rare path)
            let mut reg = REGISTRY.lock();
            reg.retain(|e| !std::ptr::eq(*e, entry));
            publish_snapshot(&reg);
            return Err("VirtualProtect failed");
        }

        Ok(ProcessEventHook { entry })
    }

    pub fn class_name(&self) -> &'static str {
        self.entry.class_name
    }

    /// Cumulative count of handler panics caught by this hook's
    /// trampoline. For snapshot surfaces.
    pub fn panic_count(&self) -> u64 {
        self.entry.panic_count.load(Ordering::Relaxed)
    }

    /// Install the same handler against multiple class names (e.g.
    /// the three concrete player BP classes). Classes that fail to
    /// resolve are skipped with a log line; classes that fail at
    /// install (e.g. null vtable) propagate as an error.
    ///
    /// Returns `Ok(vec)` containing one hook per class that
    /// successfully installed; returns `Err("no classes installed")`
    /// if zero classes resolved.
    pub fn install_many<F>(
        class_names: &[&'static str],
        handler: F,
    ) -> Result<Vec<Self>, &'static str>
    where
        F: Fn(&UObject, &UFunction, *mut c_void, OriginalProcessEvent) + Send + Sync + Clone + 'static,
    {
        let mut hooks = Vec::with_capacity(class_names.len());
        for &class_name in class_names {
            if find_class_fast(class_name).is_none() {
                crate::log!("hook: class {} not loaded yet, skipping", class_name);
                continue;
            }
            let h = Self::install(class_name, handler.clone())?;
            hooks.push(h);
        }
        if hooks.is_empty() {
            return Err("no classes installed");
        }
        Ok(hooks)
    }
}

/// Sum of trampoline-caught handler panics across every currently
/// installed hook. Snapshot endpoints surface this as a single
/// number; if it's nonzero, a hook is silently failing.
pub fn panic_count_total() -> u64 {
    let snap = SNAPSHOT.load();
    snap.iter()
        .map(|e| e.panic_count.load(Ordering::Relaxed))
        .sum()
}

impl Drop for ProcessEventHook {
    fn drop(&mut self) {
        // 1. Restore the engine's original ProcessEvent slot.
        //    New PE calls go straight to the engine; our trampoline
        //    is no longer reached.
        unsafe {
            vtable::write_slot(self.entry.slot, self.entry.original as *mut c_void);
        }
        // 2. Remove from registry / snapshot so any straggler
        //    trampoline fires that already loaded SNAPSHOT but
        //    haven't found their entry will fall through.
        {
            let mut reg = REGISTRY.lock();
            reg.retain(|e| !std::ptr::eq(*e, self.entry));
            publish_snapshot(&reg);
        }
        // 3. Wait for in-flight trampolines that already entered
        //    the handler to drain. Bounded; if a trampoline is
        //    blocked on something, we'd rather leak the entry
        //    than deadlock the unloader.
        let deadline = Instant::now() + Duration::from_millis(500);
        while self.entry.active_calls.load(Ordering::Acquire) > 0
            && Instant::now() < deadline
        {
            std::thread::yield_now();
        }
        if self.entry.active_calls.load(Ordering::Acquire) > 0 {
            crate::log!(
                "hook: drop on {} timed out with {} active call(s); proceeding anyway",
                self.entry.class_name,
                self.entry.active_calls.load(Ordering::Relaxed)
            );
        }
    }
}

unsafe extern "system" fn trampoline(
    this: *const UObject,
    function: *const UFunction,
    parms: *mut c_void,
) {
    // Look up the entry whose vtable matches the incoming object's vtable.
    let live_vtable: *mut *mut c_void = unsafe {
        (this as *const u8)
            .add(ue::offsets::uobject::VTABLE)
            .cast::<*mut *mut c_void>()
            .read_unaligned()
    };

    let snap = SNAPSHOT.load();
    let entry = snap.iter().find(|e| e.vtable == live_vtable).copied();

    let Some(entry) = entry else {
        // Shouldn't happen -- a hooked vtable always has an entry. Fall
        // through silently to avoid bringing the game down.
        return;
    };

    let original = OriginalProcessEvent { f: entry.original };

    // Hot-reload guard: during shutdown, our handler closure may be
    // about to be dropped (the box backs onto the leaked Entry, but
    // the closure may capture state in `static`s about to disappear).
    // Skip the handler and forward to the engine to avoid touching
    // a dying state.
    if SHUTTING_DOWN.load(Ordering::Acquire) {
        unsafe { original.call(&*this, &*function, parms) };
        return;
    }

    entry.active_calls.fetch_add(1, Ordering::AcqRel);
    // Save/restore the flag around the handler so reentrant fires
    // (handler -> UFunction -> our hook again) don't corrupt the
    // outer frame's "called original" state.
    let prev_called = CALLED_ORIGINAL.with(|c| c.replace(false));
    let result = std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| unsafe {
        (entry.handler)(&*this, &*function, parms, original)
    }));
    let called_during = CALLED_ORIGINAL.with(|c| c.replace(prev_called));
    entry.active_calls.fetch_sub(1, Ordering::AcqRel);

    if result.is_err() {
        // Bump the per-entry panic counter so the snapshot
        // endpoint can surface "your handler is panicking N
        // times" instead of silently swallowing.
        entry.panic_count.fetch_add(1, Ordering::Relaxed);
        if !called_during {
            // Closure panicked BEFORE calling the engine; fall
            // through so the game keeps progressing. If the
            // handler had already called original, do NOT call it
            // again -- that would double-fire the multicast (e.g.
            // double-credit XP on a kill).
            unsafe { original.call(&*this, &*function, parms) };
        }
    }
}
