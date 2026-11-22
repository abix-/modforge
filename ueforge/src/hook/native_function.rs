//! Hook on a native UFunction: mod code that runs around every call of
//! an engine function the script VM makes, wherever the call comes from.
//!
//! A ProcessEventHook sees only calls that go through ProcessEvent. A
//! Blueprint calling a native function (EX_FinalFunction and friends)
//! does not: the VM calls the UFunction's `Func` thunk directly. This
//! swaps that thunk for a trampoline, as UE4SS's RegisterHook does for
//! a /Script/ function, so a handler sees every such call with the
//! object it runs on and the caller's FFrame, and decides when to run
//! the engine's thunk (before, after, or not at all).
//!
//! Found 2026-11-21 in Wicked Island: a Blueprint (AC_Sex_C "Update
//! Actor Lock") calls SceneComponent.K2_SetWorldTransform every frame
//! and puts an enemy's body back at its stored size; no ProcessEvent
//! hook sees it.
//!
//! Only native functions (FUNC_Native): a Blueprint function's own
//! `Func` is not called when another Blueprint calls it locally.
//!
//! The thunk's arguments carry no UFunction, so each installed hook
//! gets one of a fixed set of trampolines, each knowing its own slot.

use std::cell::Cell;
use std::ffi::c_void;
use std::sync::atomic::{AtomicBool, AtomicPtr, AtomicU64, AtomicUsize, Ordering};
use std::time::{Duration, Instant};

use parking_lot::Mutex;

use crate::ue::{UFunction, UObject, find_class_fast, offsets};

/// `FNativeFuncPtr`: (Context, FFrame& Stack, RESULT_DECL).
pub type NativeFn = unsafe extern "system" fn(*mut UObject, *mut c_void, *mut c_void);

/// The caller's script frame, as the thunk got it.
#[derive(Clone, Copy)]
pub struct Frame(*mut c_void);

impl Frame {
    pub(crate) fn new(p: *mut c_void) -> Self {
        Self(p)
    }

    /// The raw FFrame pointer, to hand back to the engine.
    pub fn as_ptr(&self) -> *mut c_void {
        self.0
    }

    fn read(&self, off: usize) -> usize {
        if self.0.is_null() {
            return 0;
        }
        // SAFETY: the engine's live FFrame for the whole call; the
        // offsets are FFrame's (offsets::fframe).
        unsafe {
            (self.0 as *const u8)
                .add(off)
                .cast::<usize>()
                .read_unaligned()
        }
    }

    /// The script function running the call (FFrame::Node).
    pub fn node(&self) -> Option<&'static UFunction> {
        let p = self.read(offsets::fframe::NODE);
        // SAFETY: Node is the live UFunction the VM is executing.
        (p != 0).then(|| unsafe { &*(p as *const UFunction) })
    }

    /// The object that script function runs on (FFrame::Object).
    pub fn object(&self) -> Option<&'static UObject> {
        let p = self.read(offsets::fframe::OBJECT);
        // SAFETY: Object is the live UObject the frame runs on.
        (p != 0).then(|| unsafe { &*(p as *const UObject) })
    }
}

/// The engine's thunk, for a handler to run the call.
#[derive(Clone, Copy)]
pub struct OriginalNative {
    f: NativeFn,
}

impl OriginalNative {
    /// # Safety
    /// The arguments the handler got, unchanged.
    pub unsafe fn call(&self, context: &UObject, frame: Frame, result: *mut c_void) {
        CALLED_ORIGINAL.with(|c| c.set(true));
        // SAFETY: the engine's thunk with the engine's arguments.
        unsafe { (self.f)(context as *const UObject as *mut UObject, frame.0, result) }
    }
}

thread_local! {
    static CALLED_ORIGINAL: Cell<bool> = const { Cell::new(false) };
}

type Handler = dyn Fn(&UObject, Frame, *mut c_void, OriginalNative) + Send + Sync;

struct Slot {
    /// The hooked UFunction's address, 0 when the slot is free.
    func: AtomicUsize,
    /// The engine's thunk the slot replaced.
    original: AtomicUsize,
    /// Leaked: a call may still hold it after the hook is dropped, and
    /// freeing a closure across a DLL unload is unsafe (process_event.rs).
    handler: AtomicPtr<Box<Handler>>,
    active: AtomicUsize,
    panics: AtomicU64,
    calls: AtomicU64,
    name: Mutex<String>,
}

impl Slot {
    const fn new() -> Self {
        Self {
            func: AtomicUsize::new(0),
            original: AtomicUsize::new(0),
            handler: AtomicPtr::new(std::ptr::null_mut()),
            active: AtomicUsize::new(0),
            panics: AtomicU64::new(0),
            calls: AtomicU64::new(0),
            name: Mutex::new(String::new()),
        }
    }
}

const SLOT_COUNT: usize = 16;
static SLOTS: [Slot; SLOT_COUNT] = [const { Slot::new() }; SLOT_COUNT];
static INSTALL: Mutex<()> = Mutex::new(());
static SHUTTING_DOWN: AtomicBool = AtomicBool::new(false);

/// SAFETY: engine-supplied thunk arguments.
unsafe fn enter(i: usize, context: *mut UObject, stack: *mut c_void, result: *mut c_void) {
    let slot = &SLOTS[i];
    let raw = slot.original.load(Ordering::Acquire);
    if raw == 0 {
        // A trampoline is only ever written after its original is set.
        return;
    }
    // SAFETY: the engine's thunk, read from the UFunction at install.
    let f: NativeFn = unsafe { std::mem::transmute::<usize, NativeFn>(raw) };
    let h = slot.handler.load(Ordering::Acquire);
    if h.is_null() || context.is_null() || SHUTTING_DOWN.load(Ordering::Acquire) {
        // SAFETY: passed through unchanged.
        unsafe { f(context, stack, result) };
        return;
    }
    slot.calls.fetch_add(1, Ordering::Relaxed);
    slot.active.fetch_add(1, Ordering::AcqRel);
    let prev = CALLED_ORIGINAL.with(|c| c.replace(false));
    let r = std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| {
        // SAFETY: the leaked handler; context is the engine's live object.
        unsafe { (*h)(&*context, Frame(stack), result, OriginalNative { f }) }
    }));
    let called = CALLED_ORIGINAL.with(|c| c.replace(prev));
    slot.active.fetch_sub(1, Ordering::AcqRel);
    if r.is_err() {
        slot.panics.fetch_add(1, Ordering::Relaxed);
        if !called {
            // SAFETY: passed through unchanged; the call must still run.
            unsafe { f(context, stack, result) };
        }
    }
}

macro_rules! trampolines {
    ($($name:ident = $i:expr),* $(,)?) => {
        $(
            unsafe extern "system" fn $name(c: *mut UObject, s: *mut c_void, r: *mut c_void) {
                // SAFETY: the engine's thunk arguments.
                unsafe { enter($i, c, s, r) }
            }
        )*
        static TRAMPOLINES: [NativeFn; SLOT_COUNT] = [$($name),*];
    };
}

trampolines!(
    t0 = 0,
    t1 = 1,
    t2 = 2,
    t3 = 3,
    t4 = 4,
    t5 = 5,
    t6 = 6,
    t7 = 7,
    t8 = 8,
    t9 = 9,
    t10 = 10,
    t11 = 11,
    t12 = 12,
    t13 = 13,
    t14 = 14,
    t15 = 15,
);

fn func_cell(func: usize) -> &'static AtomicUsize {
    // SAFETY: UFunction::Func is a pointer-sized, 8-aligned field of a
    // UFunction that lives for the process (offsets::ufunction::FUNC).
    unsafe { &*((func + offsets::ufunction::FUNC) as *const AtomicUsize) }
}

/// An installed hook. Dropping it puts the engine's thunk back.
pub struct NativeFunctionHook {
    slot: usize,
}

impl NativeFunctionHook {
    /// Hook `class::function`, a native function. The handler gets the
    /// object the call runs on, the caller's frame, the result pointer
    /// and the engine's thunk; it must call `original.call` for the
    /// engine's code to run.
    pub fn install<F>(class: &str, function: &str, handler: F) -> Result<Self, String>
    where
        F: Fn(&UObject, Frame, *mut c_void, OriginalNative) + Send + Sync + 'static,
    {
        let cls = find_class_fast(class).ok_or_else(|| format!("class {class} not found"))?;
        let f = cls
            .get_function(class, function)
            .ok_or_else(|| format!("no function {class}.{function}"))?;
        if f.function_flags() & offsets::FUNC_NATIVE == 0 {
            return Err(format!(
                "{class}.{function} is not native: a Blueprint calling a Blueprint function skips its Func"
            ));
        }
        let addr = f as *const UFunction as usize;
        let _g = INSTALL.lock();
        if SLOTS.iter().any(|s| s.func.load(Ordering::Acquire) == addr) {
            return Err(format!("{class}.{function} is already hooked"));
        }
        let i = SLOTS
            .iter()
            .position(|s| s.func.load(Ordering::Acquire) == 0)
            .ok_or("every native hook slot is taken")?;
        let slot = &SLOTS[i];
        let cell = func_cell(addr);
        let original = cell.load(Ordering::Acquire);
        if original == 0 {
            return Err(format!("{class}.{function} has no thunk"));
        }
        let boxed: Box<Box<Handler>> = Box::new(Box::new(handler));
        slot.handler.store(Box::into_raw(boxed), Ordering::Release);
        slot.original.store(original, Ordering::Release);
        slot.panics.store(0, Ordering::Relaxed);
        slot.calls.store(0, Ordering::Relaxed);
        *slot.name.lock() = format!("{class}.{function}");
        slot.func.store(addr, Ordering::Release);
        cell.store(TRAMPOLINES[i] as usize, Ordering::Release);
        crate::log!("native hook: {class}.{function} in slot {i}");
        Ok(Self { slot: i })
    }
}

impl Drop for NativeFunctionHook {
    fn drop(&mut self) {
        let _g = INSTALL.lock();
        let slot = &SLOTS[self.slot];
        let addr = slot.func.load(Ordering::Acquire);
        if addr == 0 {
            return;
        }
        let cell = func_cell(addr);
        // Put the engine's thunk back only if ours is still there.
        let _ = cell.compare_exchange(
            TRAMPOLINES[self.slot] as usize,
            slot.original.load(Ordering::Acquire),
            Ordering::AcqRel,
            Ordering::Acquire,
        );
        slot.handler.store(std::ptr::null_mut(), Ordering::Release);
        let deadline = Instant::now() + Duration::from_millis(500);
        while slot.active.load(Ordering::Acquire) > 0 && Instant::now() < deadline {
            std::thread::yield_now();
        }
        // The original stays set: a call already past the thunk swap
        // still reads it.
        slot.func.store(0, Ordering::Release);
        crate::log!("native hook: removed {}", slot.name.lock());
    }
}

static HANDLES: Mutex<Vec<NativeFunctionHook>> = Mutex::new(Vec::new());

/// Keep a hook for the session; [`shutdown_all`] removes it before the
/// DLL unloads.
pub fn register(h: NativeFunctionHook) {
    HANDLES.lock().push(h);
}

/// Every installed hook: function, calls, handler panics.
pub fn installed() -> Vec<(String, u64, u64)> {
    SLOTS
        .iter()
        .filter(|s| s.func.load(Ordering::Acquire) != 0)
        .map(|s| {
            (
                s.name.lock().clone(),
                s.calls.load(Ordering::Relaxed),
                s.panics.load(Ordering::Relaxed),
            )
        })
        .collect()
}

/// Put every engine thunk back. Run before the DLL unloads.
pub fn shutdown_all() {
    SHUTTING_DOWN.store(true, Ordering::Release);
    let handles = std::mem::take(&mut *HANDLES.lock());
    drop(handles);
}
