// RAII ProcessEventHook. Patches a class's vtable slot at
// ProcessEventIdx with a trampoline that dispatches to a user-provided
// handler closure. Drop restores the original.
//
// Multiple hooks can be installed against different classes -- the
// trampoline matches on the live vtable pointer of the incoming `this`.

use std::ffi::c_void;
use std::sync::Mutex;

use crate::sdk::{
    self, ProcessEventFn, UClass, UFunction, UObject, find_class_fast, runtime,
};

use super::vtable;

/// Wrapper around the original ProcessEvent function pointer. Calling it
/// dispatches into the engine's real implementation.
#[derive(Clone, Copy)]
pub struct OriginalProcessEvent {
    f: ProcessEventFn,
}

impl OriginalProcessEvent {
    pub unsafe fn call(&self, this: &UObject, function: &UFunction, parms: *mut c_void) {
        unsafe { (self.f)(this as *const UObject, function as *const UFunction, parms) };
    }
}

type Handler = Box<dyn Fn(&UObject, &UFunction, *mut c_void, OriginalProcessEvent) + Send + Sync>;

struct Entry {
    class_name: &'static str,
    slot: *mut *mut c_void,
    vtable: *mut *mut c_void,
    original: ProcessEventFn,
    handler: Handler,
}

unsafe impl Send for Entry {}
unsafe impl Sync for Entry {}

static REGISTRY: Mutex<Vec<&'static Entry>> = Mutex::new(Vec::new());

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
                .add(sdk::offsets::uobject::VTABLE)
                .cast::<*mut *mut c_void>()
                .read_unaligned()
        };
        if vtable.is_null() {
            return Err("vtable pointer is null");
        }

        let slot_idx = runtime().platform_offsets.process_event_idx;
        let slot = unsafe { vtable.add(slot_idx) };
        let original_raw = unsafe { *slot };
        if original_raw.is_null() {
            return Err("ProcessEvent slot is null");
        }
        let original: ProcessEventFn = unsafe { std::mem::transmute(original_raw) };

        // Leak the entry: lifetimes must outlive every dispatch, even if the
        // user drops the ProcessEventHook handle. Drop reverts the slot but
        // does not free the Entry, since racing dispatches may still hold a
        // reference. Memory cost is bounded (we hook a handful of classes).
        let entry: &'static Entry = Box::leak(Box::new(Entry {
            class_name,
            slot,
            vtable,
            original,
            handler: Box::new(handler),
        }));

        REGISTRY.lock().unwrap().push(entry);

        let prev = unsafe { vtable::write_slot(slot, trampoline as *mut c_void) };
        if prev.is_none() {
            // back out: remove from registry, leak entry (rare path)
            let mut reg = REGISTRY.lock().unwrap();
            reg.retain(|e| !std::ptr::eq(*e, entry));
            return Err("VirtualProtect failed");
        }

        Ok(ProcessEventHook { entry })
    }

    pub fn class_name(&self) -> &'static str {
        self.entry.class_name
    }
}

impl Drop for ProcessEventHook {
    fn drop(&mut self) {
        unsafe {
            vtable::write_slot(self.entry.slot, self.entry.original as *mut c_void);
        }
        let mut reg = REGISTRY.lock().unwrap();
        reg.retain(|e| !std::ptr::eq(*e, self.entry));
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
            .add(sdk::offsets::uobject::VTABLE)
            .cast::<*mut *mut c_void>()
            .read_unaligned()
    };

    let entry = {
        let reg = REGISTRY.lock().unwrap();
        reg.iter()
            .find(|e| e.vtable == live_vtable)
            .copied()
    };

    let Some(entry) = entry else {
        // Shouldn't happen -- a hooked vtable always has an entry. Fall
        // through silently to avoid bringing the game down.
        return;
    };

    let original = OriginalProcessEvent { f: entry.original };
    let result = std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| unsafe {
        (entry.handler)(&*this, &*function, parms, original)
    }));
    if result.is_err() {
        // Closure panicked; fall through to original to keep the game alive.
        unsafe { original.call(&*this, &*function, parms) };
    }
}
