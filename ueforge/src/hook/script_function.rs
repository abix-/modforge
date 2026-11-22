//! Hooks on Blueprint functions: mod code that runs before or after a
//! named script function, however it was called.
//!
//! Every Blueprint function runs through the engine's
//! ProcessLocalScriptFunction (Context, FFrame& Stack, RESULT_DECL),
//! with Stack.Node the function being run: a Blueprint calling another
//! goes there directly, and an event from ProcessEvent goes there
//! through ProcessInternal, the `Func` of every script UFunction. UE4SS
//! hooks the same two (RE-UE4SS UE4SS/src/Signatures.cpp,
//! ProcessLocalScriptFunction and ProcessInternal); one detour on
//! ProcessLocalScriptFunction covers both here, since ProcessInternal
//! calls it.
//!
//! Found without a per-game address: ProcessInternal is the `Func` of
//! any Blueprint function the caller names, and ProcessLocalScriptFunction
//! is the function it calls whose body tests a script byte against
//! EX_Return (0x04). In Wicked Island (UE 5.6) that is ProcessInternal
//! exe+0x160d5c0 calling exe+0x160d6c0 (`cmp byte ptr [rcx],4`), read
//! from the exe 2026-11-21.

use std::ffi::c_void;
use std::sync::Arc;
use std::sync::LazyLock;
use std::sync::atomic::{AtomicBool, AtomicPtr, AtomicU64, Ordering};

use arc_swap::ArcSwap;
use parking_lot::Mutex;
use retour::GenericDetour;

use super::native_function::{Frame, NativeFn};
use crate::ue::{UFunction, UObject, find_class_fast, offsets};

/// Run the handler before the function's script, or after it returns.
#[derive(Clone, Copy, PartialEq, Eq, Debug)]
pub enum When {
    Before,
    After,
}

type Handler = dyn Fn(&UObject, Frame) + Send + Sync;

struct Entry {
    func: usize,
    name: String,
    when: When,
    handler: &'static Handler,
    calls: AtomicU64,
    panics: AtomicU64,
}

static ENTRIES: LazyLock<ArcSwap<Vec<&'static Entry>>> =
    LazyLock::new(|| ArcSwap::from_pointee(Vec::new()));
static WRITE: Mutex<()> = Mutex::new(());
static DETOUR: AtomicPtr<GenericDetour<NativeFn>> = AtomicPtr::new(std::ptr::null_mut());
static SHUTTING_DOWN: AtomicBool = AtomicBool::new(false);

unsafe extern "system" fn runner(ctx: *mut UObject, stack: *mut c_void, result: *mut c_void) {
    let d = DETOUR.load(Ordering::Acquire);
    if d.is_null() {
        return;
    }
    // SAFETY: published by install before the detour was enabled, and
    // never freed while enabled.
    let d = unsafe { &*d };
    let entries = ENTRIES.load();
    if entries.is_empty() || ctx.is_null() || SHUTTING_DOWN.load(Ordering::Acquire) {
        // SAFETY: the engine's arguments, unchanged.
        return unsafe { d.call(ctx, stack, result) };
    }
    let frame = Frame::new(stack);
    let node = frame.node().map_or(0, |f| f as *const UFunction as usize);
    if !entries.iter().any(|e| e.func == node) {
        // SAFETY: as above.
        return unsafe { d.call(ctx, stack, result) };
    }
    let run = |when: When| {
        for e in entries.iter().filter(|e| e.func == node && e.when == when) {
            e.calls.fetch_add(1, Ordering::Relaxed);
            // SAFETY: ctx is the engine's live object for this call.
            let obj = unsafe { &*ctx };
            if std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| (e.handler)(obj, frame)))
                .is_err()
            {
                e.panics.fetch_add(1, Ordering::Relaxed);
            }
        }
    };
    run(When::Before);
    // SAFETY: as above.
    unsafe { d.call(ctx, stack, result) };
    run(When::After);
}

fn read_bytes(addr: usize, len: usize) -> Option<Vec<u8>> {
    if !crate::winproc::is_addr_readable(addr) || !crate::winproc::is_addr_readable(addr + len - 1)
    {
        return None;
    }
    // SAFETY: both ends readable; code pages of the exe.
    Some(unsafe { std::slice::from_raw_parts(addr as *const u8, len) }.to_vec())
}

/// Whether the code at `f` tests a script byte against EX_Return in its
/// first bytes: `cmp byte ptr [reg],4` (80 /7 04, register-indirect).
fn tests_ex_return(f: usize) -> bool {
    let Some(b) = read_bytes(f, 0x80) else {
        return false;
    };
    b.windows(3).any(|w| {
        w[0] == 0x80 && (0x38..=0x3F).contains(&w[1]) && w[1] != 0x3C && w[1] != 0x3D && w[2] == 4
    })
}

/// ProcessLocalScriptFunction: of the direct calls in ProcessInternal's
/// first 0x100 bytes, the one that tests EX_Return.
fn find_runner(process_internal: usize) -> Option<usize> {
    let b = read_bytes(process_internal, 0x100)?;
    (0..b.len().saturating_sub(5))
        .filter(|&i| b[i] == 0xE8)
        .map(|i| {
            let rel = i32::from_le_bytes([b[i + 1], b[i + 2], b[i + 3], b[i + 4]]);
            (process_internal + i + 5).wrapping_add_signed(rel as isize)
        })
        .find(|&t| tests_ex_return(t))
}

/// Detour ProcessLocalScriptFunction, found through the Blueprint
/// function `class::function` (any loaded one). Once per process;
/// later calls return Ok.
pub fn install(class: &str, function: &str) -> Result<(), String> {
    let _g = WRITE.lock();
    if !DETOUR.load(Ordering::Acquire).is_null() {
        return Ok(());
    }
    let cls = find_class_fast(class).ok_or_else(|| format!("class {class} not loaded"))?;
    let f = cls
        .get_function(class, function)
        .ok_or_else(|| format!("no function {class}.{function}"))?;
    if f.function_flags() & offsets::FUNC_NATIVE != 0 {
        return Err(format!(
            "{class}.{function} is native, not a Blueprint function"
        ));
    }
    let fa = f as *const UFunction as usize;
    // SAFETY: Func is a pointer field of the live UFunction.
    let process_internal = unsafe { ((fa + offsets::ufunction::FUNC) as *const usize).read() };
    let target = find_runner(process_internal).ok_or_else(|| {
        format!("no call testing EX_Return in ProcessInternal at 0x{process_internal:x}")
    })?;
    // SAFETY: target is ProcessLocalScriptFunction, the FNativeFuncPtr shape.
    let t: NativeFn = unsafe { std::mem::transmute::<usize, NativeFn>(target) };
    // SAFETY: same signature on both sides.
    let detour =
        unsafe { GenericDetour::new(t, runner as NativeFn) }.map_err(|e| format!("detour: {e}"))?;
    let p = Box::into_raw(Box::new(detour));
    DETOUR.store(p, Ordering::Release);
    // SAFETY: writes the jump; the trampoline is published above.
    if let Err(e) = unsafe { (*p).enable() } {
        DETOUR.store(std::ptr::null_mut(), Ordering::Release);
        return Err(format!("enable: {e}"));
    }
    crate::log!(
        "script hook: ProcessInternal 0x{process_internal:x}, ProcessLocalScriptFunction 0x{target:x}"
    );
    Ok(())
}

/// Run `handler` with the object and frame each time the Blueprint
/// function `class::function` runs, before its script or after it.
/// Needs [`install`]; the class must be loaded.
pub fn on<F>(class: &str, function: &str, when: When, handler: F) -> Result<(), String>
where
    F: Fn(&UObject, Frame) + Send + Sync + 'static,
{
    let cls = find_class_fast(class).ok_or_else(|| format!("class {class} not loaded"))?;
    let f = cls
        .get_function(class, function)
        .ok_or_else(|| format!("no function {class}.{function}"))?;
    let handler: &'static Handler = Box::leak(Box::new(handler));
    let e: &'static Entry = Box::leak(Box::new(Entry {
        func: f as *const UFunction as usize,
        name: format!("{class}.{function}"),
        when,
        handler,
        calls: AtomicU64::new(0),
        panics: AtomicU64::new(0),
    }));
    let _g = WRITE.lock();
    let mut v: Vec<&'static Entry> = ENTRIES.load().as_ref().clone();
    v.push(e);
    ENTRIES.store(Arc::new(v));
    crate::log!("script hook: {class}.{function} {when:?}");
    Ok(())
}

/// Every hooked function: name, when, calls, handler panics.
pub fn installed() -> Vec<(String, When, u64, u64)> {
    ENTRIES
        .load()
        .iter()
        .map(|e| {
            (
                e.name.clone(),
                e.when,
                e.calls.load(Ordering::Relaxed),
                e.panics.load(Ordering::Relaxed),
            )
        })
        .collect()
}

/// Put ProcessLocalScriptFunction back. Run before the DLL unloads.
pub fn shutdown_all() {
    SHUTTING_DOWN.store(true, Ordering::Release);
    let _g = WRITE.lock();
    ENTRIES.store(Arc::new(Vec::new()));
    let p = DETOUR.load(Ordering::Acquire);
    if !p.is_null() {
        // SAFETY: restores the prologue; the box stays leaked, since a
        // call may still be inside the trampoline.
        let _ = unsafe { (*p).disable() };
        crate::log!("script hook: removed");
    }
}
