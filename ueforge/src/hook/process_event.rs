// RAII ProcessEventHook. Patches a class's vtable slot at
// ProcessEventIdx with a trampoline that dispatches to a user-provided
// handler closure. Drop restores the original.
//
// Multiple hooks can be installed against different classes. The
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

/// What a handler calls to let the call proceed: the remaining hook
/// entries on the same function table, in install order, and then the
/// engine's real ProcessEvent. Blueprint classes add no virtual
/// functions, so every actor built on one native class shares one
/// table (every character shares ACharacter's): hooks on different
/// classes land on the same slot, and each must still see the call.
/// A handler keeps its freedom to run before or after the rest, or to
/// skip it entirely.
#[derive(Clone, Copy)]
pub struct OriginalProcessEvent {
    f: ProcessEventFn,
    /// The entries still to run before the engine. Points into the
    /// snapshot the trampoline holds for the whole call, so it
    /// outlives every handler in the chain.
    rest: *const &'static HookDef,
    rest_len: usize,
}

impl OriginalProcessEvent {
    pub unsafe fn call(&self, this: &UObject, function: &UFunction, parms: *mut c_void) {
        // Mark "handler already passed the call on" so the dispatch's
        // panic-recovery arm does NOT pass it on a second time if the
        // handler panics AFTER this returns. Double-call on a kill
        // multicast would double-credit XP.
        CALLED_ORIGINAL.with(|c| c.set(true));
        // SAFETY: `rest` was built by `dispatch` from a snapshot slice
        // that its frame still holds; the entries are leaked and
        // 'static. `self.f` was captured from the engine's slot at
        // the first install on this table; it has the engine's
        // ProcessEvent ABI. Caller's `unsafe fn` contract requires
        // this/function to be live UObject + UFunction.
        unsafe {
            let rest = std::slice::from_raw_parts(self.rest, self.rest_len);
            dispatch(rest, self.f, this, function, parms);
        }
    }
}

/// Run `entries` on this call as a chain: the first entry's handler gets
/// an `original` that runs the remaining entries and then the engine.
/// With no entries left, the engine is called directly.
///
/// SAFETY: this/function are live engine-supplied pointers for the
/// duration of the call; `entries` are leaked 'static hook records;
/// `engine` is the engine's ProcessEvent for this table.
unsafe fn dispatch(
    entries: &[&'static HookDef],
    engine: ProcessEventFn,
    this: &UObject,
    function: &UFunction,
    parms: *mut c_void,
) {
    let Some((entry, rest)) = entries.split_first() else {
        unsafe { engine(this as *const UObject, function as *const UFunction, parms) };
        return;
    };
    let original = OriginalProcessEvent {
        f: engine,
        rest: rest.as_ptr(),
        rest_len: rest.len(),
    };

    entry.active_calls.fetch_add(1, Ordering::AcqRel);
    // Save/restore the flag around the handler so reentrant fires
    // (handler -> UFunction -> our hook again) don't corrupt the
    // outer frame's "passed on" state.
    let prev_called = CALLED_ORIGINAL.with(|c| c.replace(false));
    let result = std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| {
        (entry.handler)(this, function, parms, original)
    }));
    let called_during = CALLED_ORIGINAL.with(|c| c.replace(prev_called));
    entry.active_calls.fetch_sub(1, Ordering::AcqRel);

    if result.is_err() {
        // Bump the per-entry panic counter so the snapshot
        // endpoint can surface "your handler is panicking N
        // times" instead of silently swallowing.
        entry.panic_count.fetch_add(1, Ordering::Relaxed);
        if !called_during {
            // Closure panicked BEFORE passing the call on; the rest
            // of the chain and the engine still run so the game
            // keeps progressing. If the handler had already passed
            // it on, do NOT do so again. That would double-fire the
            // multicast (e.g. double-credit XP on a kill).
            unsafe { dispatch(rest, engine, this, function, parms) };
        }
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

/// Per-install hook record. The CRD-equivalent for the hook
/// subsystem. Declares which class is hooked, the original
/// vtable slot, the user handler, and the per-hook telemetry
/// (active calls, panic count). One `HookDef` is created per
/// `ProcessEventHook::install` call and lives for the rest of
/// the process (`Box::leak`-ed; see "Hot-reload teardown" in
/// hooks.md for why reuse across DLL unloads is unsafe).
///
/// Fields are private; accessor methods provide the read-only
/// view the snapshot endpoints need. Construction is internal.
/// the only path to a `HookDef` is through
/// [`ProcessEventHook::install`] / [`install_many`].
pub struct HookDef {
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
    /// trampolines are invisible to the snapshot endpoint.
    /// the game keeps running but the mod silently swallows
    /// errors. Surfaced via [`panic_count`] / [`panic_count_total`].
    panic_count: AtomicU64,
}

// SAFETY: HookDef carries raw pointers (slot, vtable) into UE
// engine memory; those pointers are only dereferenced from the
// trampoline / shutdown path under invariants documented in
// hooks.md. The handler closure is Send + Sync by trait bound.
// SAFETY: HookDef holds an immutable `&'static` slot pointer + raw
// vtable / original function pointers (read-only after install)
// plus AtomicUsize / AtomicU64 counters + a Send+Sync boxed
// handler. Nothing requires non-Sendability.
unsafe impl Send for HookDef {}
// SAFETY: see Send impl. The trampoline reads through SNAPSHOT
// (ArcSwap of leaked entries) without taking any lock; immutable
// fields are safe to share across the trampoline threads.
unsafe impl Sync for HookDef {}

impl HookDef {
    /// UE class whose vtable slot this hook patched. Stable for
    /// the lifetime of the hook.
    pub fn class_name(&self) -> &'static str {
        self.class_name
    }

    /// Trampolines currently inside this hook's handler closure.
    /// Drop spins on this until it reaches 0 (with a 500ms cap)
    /// before allowing the DLL to unload.
    pub fn active_calls(&self) -> usize {
        self.active_calls.load(Ordering::Relaxed)
    }

    /// Cumulative count of handler panics caught by this hook's
    /// trampoline. Nonzero = a handler is silently failing.
    pub fn panic_count(&self) -> u64 {
        self.panic_count.load(Ordering::Relaxed)
    }
}

// REGISTRY is the canonical mutable list, touched only by install/drop
// (cold paths). The trampoline reads SNAPSHOT. An ArcSwap of the
// current entry list. Read is one atomic load + Arc clone, no mutex.
// Replaces the old hand-rolled AtomicPtr<&'static [...]> that leaked
// every install/drop.
static REGISTRY: Mutex<Vec<&'static HookDef>> = Mutex::new(Vec::new());
static SNAPSHOT: LazyLock<ArcSwap<Vec<&'static HookDef>>> =
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

/// The snapshot is grouped by function table (a stable sort keeps
/// install order within a table), so the trampoline finds one table's
/// chain as a contiguous sub-slice without allocating on the hot path.
fn publish_snapshot(reg: &[&'static HookDef]) {
    let mut grouped = reg.to_vec();
    grouped.sort_by_key(|e| e.vtable as usize);
    SNAPSHOT.store(Arc::new(grouped));
}

pub struct ProcessEventHook {
    entry: &'static HookDef,
}

impl ProcessEventHook {
    pub fn install<F>(class_name: &'static str, handler: F) -> Result<Self, &'static str>
    where
        F: Fn(&UObject, &UFunction, *mut c_void, OriginalProcessEvent) + Send + Sync + 'static,
    {
        let cls: &UClass = find_class_fast(class_name).ok_or("class not found")?;
        let cdo = cls.class_default_object().ok_or("class has no CDO")?;
        Self::install_from(class_name, cdo, handler)
    }

    /// Install using the vtable of a specific live object instead
    /// of the class's CDO. Needed when `find_class_fast` resolves
    /// a stale reinstanced Blueprint class whose CDO vtable no
    /// live instance shares (misery research.md 22.13): patching
    /// the stale vtable installs cleanly but never fires. Reading
    /// the vtable from a live instance patches the table the
    /// engine actually dispatches through.
    pub fn install_for_object<F>(
        class_name: &'static str,
        obj: &UObject,
        handler: F,
    ) -> Result<Self, &'static str>
    where
        F: Fn(&UObject, &UFunction, *mut c_void, OriginalProcessEvent) + Send + Sync + 'static,
    {
        Self::install_from(class_name, obj, handler)
    }

    fn install_from<F>(
        class_name: &'static str,
        vtable_source: &UObject,
        handler: F,
    ) -> Result<Self, &'static str>
    where
        F: Fn(&UObject, &UFunction, *mut c_void, OriginalProcessEvent) + Send + Sync + 'static,
    {
        // SAFETY: vtable_source is a live UObject (a CDO or a live
        // instance). Reading its first 8 bytes as a vtable pointer
        // matches every C++ UE class layout on x86-64;
        // offsets::uobject::VTABLE is 0.
        let vtable: *mut *mut c_void = unsafe {
            (vtable_source as *const UObject as *const u8)
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
        // SAFETY: vtable points at the class's virtual-method
        // table; slot_idx is the platform-configured index of
        // ProcessEvent within that table.
        let slot = unsafe { vtable.add(slot_idx) };

        // The registry lock is held from here until the entry is
        // published and the slot patched, so two installs on one
        // table cannot both read the slot and both patch it.
        let mut reg = REGISTRY.lock();

        // A table already hooked keeps the engine pointer its first
        // entry captured; reading the slot now would capture our own
        // trampoline and the chain would call itself.
        let already = reg.iter().find(|e| e.vtable == vtable).map(|e| e.original);
        let original: ProcessEventFn = match already {
            Some(engine) => engine,
            None => {
                // SAFETY: vtable slots are pointer-sized; the slot
                // contains the engine's ProcessEvent function pointer.
                let original_raw = unsafe { *slot };
                if original_raw.is_null() {
                    return Err("ProcessEvent slot is null");
                }
                // SAFETY: original_raw is a *mut c_void that we know is
                // the engine's ProcessEvent fn pointer. Transmute to the
                // typed ProcessEventFn matches the engine's ABI signature.
                unsafe { std::mem::transmute(original_raw) }
            }
        };

        // Leak the entry: lifetimes must outlive every dispatch, even if the
        // user drops the ProcessEventHook handle. Drop reverts the slot but
        // does not free the Entry, since racing dispatches may still hold a
        // reference, AND the heap-allocated handler closure is unsafe to free
        // across a DLL unload (its vtable points into freed module code).
        // Memory cost is bounded by the number of hook installs over the
        // process lifetime, instrumented via `LEAKED_ENTRY_COUNT`.
        let entry: &'static HookDef = Box::leak(Box::new(HookDef {
            class_name,
            slot,
            vtable,
            original,
            handler: Box::new(handler),
            active_calls: AtomicUsize::new(0),
            panic_count: AtomicU64::new(0),
        }));
        LEAKED_ENTRY_COUNT.fetch_add(1, Ordering::Relaxed);

        reg.push(entry);
        publish_snapshot(&reg);

        if already.is_none() {
            // SAFETY: vtable::write_slot wraps the page-protection
            // dance via region::protect_with_handle. slot is the
            // ProcessEvent slot we just read from; trampoline is our
            // static fn whose ABI matches the engine's ProcessEventFn.
            let prev = unsafe { vtable::write_slot(slot, trampoline as *mut c_void) };
            if prev.is_none() {
                // back out: remove from registry, leak entry (rare path)
                reg.retain(|e| !std::ptr::eq(*e, entry));
                publish_snapshot(&reg);
                return Err("VirtualProtect failed");
            }
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
        F: Fn(&UObject, &UFunction, *mut c_void, OriginalProcessEvent)
            + Send
            + Sync
            + Clone
            + 'static,
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

/// Snapshot every currently-installed [`HookDef`]. Read-only;
/// returns owned `Vec<&'static HookDef>` so the caller can iterate
/// without holding the snapshot Arc. For debug surfaces.
pub fn installed_defs() -> Vec<&'static HookDef> {
    SNAPSHOT.load().iter().copied().collect()
}

impl Drop for ProcessEventHook {
    fn drop(&mut self) {
        // 1. Remove from registry / snapshot so new fires no longer
        //    run this handler, and restore the engine's original
        //    ProcessEvent slot only when this was the last entry on
        //    the table: other classes' hooks on the same table stay
        //    live. Under the registry lock, paired with install.
        // SAFETY: self.entry.slot was captured at install time +
        // remains valid for process lifetime (leaked HookDef);
        // self.entry.original is the engine fn pointer the first
        // entry on this table cached before patching.
        {
            let mut reg = REGISTRY.lock();
            reg.retain(|e| !std::ptr::eq(*e, self.entry));
            publish_snapshot(&reg);
            if !reg.iter().any(|e| e.vtable == self.entry.vtable) {
                unsafe {
                    vtable::write_slot(self.entry.slot, self.entry.original as *mut c_void);
                }
            }
        }
        // 3. Wait for in-flight trampolines that already entered
        //    the handler to drain. Bounded; if a trampoline is
        //    blocked on something, we'd rather leak the entry
        //    than deadlock the unloader.
        let deadline = Instant::now() + Duration::from_millis(500);
        while self.entry.active_calls.load(Ordering::Acquire) > 0 && Instant::now() < deadline {
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
    // SAFETY: `this` is the engine-supplied UObject pointer to
    // the trampoline. Reading its first 8 bytes as the vtable
    // matches the standard C++/UE class layout (UE puts the
    // vtable at offset 0).
    let live_vtable: *mut *mut c_void = unsafe {
        (this as *const u8)
            .add(ue::offsets::uobject::VTABLE)
            .cast::<*mut *mut c_void>()
            .read_unaligned()
    };

    // Every entry on this table, in install order: one contiguous run
    // of the grouped snapshot, no allocation. The snapshot Arc is held
    // for the whole call, so the slice the chain points into stays
    // alive through every handler.
    let snap = SNAPSHOT.load();
    let Some(start) = snap.iter().position(|e| e.vtable == live_vtable) else {
        // Shouldn't happen. A hooked vtable always has an entry. Fall
        // through silently to avoid bringing the game down.
        return;
    };
    let end = start
        + snap[start..]
            .iter()
            .take_while(|e| e.vtable == live_vtable)
            .count();
    let entries: &[&'static HookDef] = &snap[start..end];
    let engine = entries[0].original;

    // Hot-reload guard: during shutdown, our handler closures may be
    // about to be dropped (the box backs onto the leaked Entry, but
    // the closure may capture state in `static`s about to disappear).
    // Skip every handler and forward to the engine to avoid touching
    // a dying state.
    if SHUTTING_DOWN.load(Ordering::Acquire) {
        // SAFETY: engine is the captured fn ptr; this/function are
        // the engine-supplied call args, passed through unchanged.
        unsafe { engine(this, function, parms) };
        return;
    }

    // SAFETY: this/function are engine-supplied UObject + UFunction
    // pointers (live for the duration of the call); entries are
    // leaked 'static records; `entries` outlives the chain.
    unsafe { dispatch(entries, engine, &*this, &*function, parms) };
}
