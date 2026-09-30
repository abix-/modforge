//! HarmonyLib wrapper. Each `Hook` represents one prefix/postfix
//! patch on a managed method. The Rust callback is an `extern
//! "C" fn` pointer; the shim wraps it in a managed delegate so
//! HarmonyLib can target it.
//!
//! K8s slot: Def=HookDef, Registry=HookRegistry
//!           (HOOK_REGISTRY singleton),
//!           Instance=PatchHandle, Controller=trampoline + Drop

use std::ffi::{CString, c_void};

use parking_lot::Mutex;

use crate::bridge::{self, PatchHandle};

/// One installed Harmony patch.
pub struct Hook {
    handle: PatchHandle,
    pub class_name: String,
    pub method_name: String,
    pub when: HookWhen,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum HookWhen {
    Prefix,
    Postfix,
}

impl Hook {
    pub fn handle(&self) -> PatchHandle {
        self.handle
    }
}

impl Drop for Hook {
    fn drop(&mut self) {
        if let Some(bridge) = bridge::get() {
            (bridge.harmony_unpatch)(self.handle);
        }
    }
}

/// Install a prefix patch. The trampoline must be an `extern "C"
/// fn(*const c_void) -> i32`. Returning non-zero from a prefix
/// tells HarmonyLib to skip the original method.
pub fn patch_prefix(
    class_name: &str,
    method_name: &str,
    prefix_fn: extern "C" fn(*const c_void) -> i32,
) -> Result<Hook, String> {
    let bridge = bridge::try_get()?;
    let c_class = CString::new(class_name).map_err(|e| format!("bad class: {e}"))?;
    let c_method = CString::new(method_name).map_err(|e| format!("bad method: {e}"))?;
    let handle = (bridge.harmony_patch_prefix)(c_class.as_ptr(), c_method.as_ptr(), prefix_fn);
    if handle.0 == 0 {
        return Err(format!(
            "harmony_patch_prefix({class_name}, {method_name}) failed"
        ));
    }
    Ok(Hook {
        handle,
        class_name: class_name.to_string(),
        method_name: method_name.to_string(),
        when: HookWhen::Prefix,
    })
}

/// Which object a `patch_prefix_ctx` callback receives as its
/// context handle.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum HookCtx {
    /// `__instance` of the patched (instance) method.
    Instance = 0,
    /// The method's first argument, REFERENCE type only. For a
    /// value-type first argument the shim refuses (a boxed copy
    /// would be handed over and every mutation silently lost;
    /// live-verified 2026-07-04 on the struct Injury). Use
    /// `Args0` for value types.
    Arg0 = 1,
    /// The method's first argument via Harmony's `__args` array,
    /// which writes element changes back to the real arguments
    /// after the patch. Works for value types (mutating the boxed
    /// element's fields lands in the real argument on write-back).
    /// Needs Harmony 2.1+ (`__args`); the survivalist shim embeds
    /// 2.4.2.
    Args0 = 2,
}

/// Install a prefix patch whose callback receives a context
/// object (per `ctx`) as a FRESH handle in the `*const c_void`
/// parameter: cast the pointer value to i32 and wrap with
/// `MonoObject::from_handle` (Drop releases the handle; the
/// callback owns it). 0 means the context object was null.
/// Returning non-zero still skips the original method.
pub fn patch_prefix_ctx(
    class_name: &str,
    method_name: &str,
    ctx: HookCtx,
    prefix_fn: extern "C" fn(*const c_void) -> i32,
) -> Result<Hook, String> {
    let bridge = bridge::try_get()?;
    let c_class = CString::new(class_name).map_err(|e| format!("bad class: {e}"))?;
    let c_method = CString::new(method_name).map_err(|e| format!("bad method: {e}"))?;
    let handle = (bridge.harmony_patch_prefix_ctx)(
        c_class.as_ptr(),
        c_method.as_ptr(),
        ctx as i32,
        prefix_fn,
    );
    if handle.0 == 0 {
        return Err(format!(
            "harmony_patch_prefix_ctx({class_name}, {method_name}, {ctx:?}) failed"
        ));
    }
    Ok(Hook {
        handle,
        class_name: class_name.to_string(),
        method_name: method_name.to_string(),
        when: HookWhen::Prefix,
    })
}

/// Install a prefix patch whose callback receives BOTH the
/// patched method's `__instance` (a FRESH handle in the first
/// parameter, same ownership contract as `patch_prefix_ctx`;
/// 0 for a static method) and the call's arguments serialized
/// to JSON UTF-8 in the second (Harmony's `__args`: primitives,
/// enums as numbers, strings by value; other objects as
/// `{"handle": n}` handles the callback also owns). The JSON
/// pointer is only valid for the duration of the callback.
/// Returning non-zero skips the original method. Needs a v7+
/// shim.
pub fn patch_prefix_instance_args(
    class_name: &str,
    method_name: &str,
    prefix_fn: extern "C" fn(*const c_void, *const std::os::raw::c_char) -> i32,
) -> Result<Hook, String> {
    let bridge = bridge::try_get()?;
    let patch = bridge.harmony_patch_prefix_instance_args.ok_or_else(|| {
        "harmony_patch_prefix_instance_args: shim is pre-v7; rebuild and redeploy the C# shim"
            .to_string()
    })?;
    let c_class = CString::new(class_name).map_err(|e| format!("bad class: {e}"))?;
    let c_method = CString::new(method_name).map_err(|e| format!("bad method: {e}"))?;
    let handle = patch(c_class.as_ptr(), c_method.as_ptr(), prefix_fn);
    if handle.0 == 0 {
        return Err(format!(
            "harmony_patch_prefix_instance_args({class_name}, {method_name}) failed"
        ));
    }
    Ok(Hook {
        handle,
        class_name: class_name.to_string(),
        method_name: method_name.to_string(),
        when: HookWhen::Prefix,
    })
}

/// Install a postfix patch on a method returning `float` that can
/// replace its result. The callback receives the `__instance` as
/// a FRESH handle (same ownership contract as `patch_prefix_ctx`;
/// 0 for a static method), the arguments as JSON (same convention
/// and ownership as `patch_prefix_instance_args`; the pointer is
/// valid only during the callback), and the original result, and
/// returns the result the caller sees. Needs a v8+ shim.
pub fn patch_postfix_float_result(
    class_name: &str,
    method_name: &str,
    postfix_fn: extern "C" fn(*const c_void, *const std::os::raw::c_char, f32) -> f32,
) -> Result<Hook, String> {
    let bridge = bridge::try_get()?;
    let patch = bridge.harmony_patch_postfix_float_result.ok_or_else(|| {
        "harmony_patch_postfix_float_result: shim is pre-v8; rebuild and redeploy the C# shim"
            .to_string()
    })?;
    let c_class = CString::new(class_name).map_err(|e| format!("bad class: {e}"))?;
    let c_method = CString::new(method_name).map_err(|e| format!("bad method: {e}"))?;
    let handle = patch(c_class.as_ptr(), c_method.as_ptr(), postfix_fn);
    if handle.0 == 0 {
        return Err(format!(
            "harmony_patch_postfix_float_result({class_name}, {method_name}) failed"
        ));
    }
    Ok(Hook {
        handle,
        class_name: class_name.to_string(),
        method_name: method_name.to_string(),
        when: HookWhen::Postfix,
    })
}

/// Install a postfix patch on a method returning `int` that can
/// replace its result, same callback contract as
/// [`patch_postfix_float_result`]. `filter` is a JSON object
/// `{"<arg index>": value}` (number for enum or integer arguments,
/// bool for bool ones) that the shim checks before calling Rust;
/// the callback runs only when every listed argument matches. Use
/// it on hot methods. Needs a v9+ shim.
pub fn patch_postfix_int_result(
    class_name: &str,
    method_name: &str,
    filter: &serde_json::Value,
    postfix_fn: extern "C" fn(*const c_void, *const std::os::raw::c_char, i32) -> i32,
) -> Result<Hook, String> {
    let bridge = bridge::try_get()?;
    let patch = bridge.harmony_patch_postfix_int_result.ok_or_else(|| {
        "harmony_patch_postfix_int_result: shim is pre-v9; rebuild and redeploy the C# shim"
            .to_string()
    })?;
    let c_class = CString::new(class_name).map_err(|e| format!("bad class: {e}"))?;
    let c_method = CString::new(method_name).map_err(|e| format!("bad method: {e}"))?;
    let c_filter = CString::new(filter.to_string()).map_err(|e| format!("bad filter: {e}"))?;
    let handle = patch(c_class.as_ptr(), c_method.as_ptr(), c_filter.as_ptr(), postfix_fn);
    if handle.0 == 0 {
        return Err(format!(
            "harmony_patch_postfix_int_result({class_name}, {method_name}) failed"
        ));
    }
    Ok(Hook {
        handle,
        class_name: class_name.to_string(),
        method_name: method_name.to_string(),
        when: HookWhen::Postfix,
    })
}

/// Install a postfix patch on a method of ANY return type that can
/// replace its result. The callback receives the `__instance` as a
/// FRESH handle (same ownership contract as `patch_prefix_ctx`; 0 for
/// a static method), the arguments and the original result as JSON
/// (the args convention of `patch_prefix_instance_args`; handles in
/// them are owned by the callback; valid only during the callback),
/// and an output buffer. Write the replacement result there as JSON
/// (`{"$handle": n}` for a live object) with [`write_result`] and
/// return what it returns, or return -1 to keep the original. The
/// `filter` is the same as [`patch_postfix_int_result`]'s. Needs a
/// v10+ shim.
pub fn patch_postfix_result(
    class_name: &str,
    method_name: &str,
    filter: &serde_json::Value,
    postfix_fn: bridge::PostfixResultFn,
) -> Result<Hook, String> {
    let bridge = bridge::try_get()?;
    let patch = bridge.harmony_patch_postfix_result.ok_or_else(|| {
        "harmony_patch_postfix_result: shim is pre-v10; rebuild and redeploy the C# shim".to_string()
    })?;
    let c_class = CString::new(class_name).map_err(|e| format!("bad class: {e}"))?;
    let c_method = CString::new(method_name).map_err(|e| format!("bad method: {e}"))?;
    let c_filter = CString::new(filter.to_string()).map_err(|e| format!("bad filter: {e}"))?;
    let handle = patch(c_class.as_ptr(), c_method.as_ptr(), c_filter.as_ptr(), postfix_fn);
    if handle.0 == 0 {
        return Err(format!(
            "harmony_patch_postfix_result({class_name}, {method_name}) failed"
        ));
    }
    Ok(Hook {
        handle,
        class_name: class_name.to_string(),
        method_name: method_name.to_string(),
        when: HookWhen::Postfix,
    })
}

/// Write a replacement result into a `patch_postfix_result`
/// callback's output buffer. Returns the length to hand back to
/// the shim, or -1 (keep the original) when it does not fit.
///
/// # Safety
/// `out` and `cap` must be the buffer the shim passed to the
/// callback.
pub unsafe fn write_result(out: *mut std::os::raw::c_char, cap: i32, value: &serde_json::Value) -> i32 {
    let s = value.to_string();
    if out.is_null() || s.len() > cap.max(0) as usize {
        return -1;
    }
    // SAFETY: caller guarantees out..out+cap is the shim's buffer.
    unsafe { std::ptr::copy_nonoverlapping(s.as_ptr(), out as *mut u8, s.len()) };
    s.len() as i32
}

/// Install a postfix patch. The trampoline must be an `extern
/// "C" fn(*const c_void)`.
pub fn patch_postfix(
    class_name: &str,
    method_name: &str,
    postfix_fn: extern "C" fn(*const c_void),
) -> Result<Hook, String> {
    let bridge = bridge::try_get()?;
    let c_class = CString::new(class_name).map_err(|e| format!("bad class: {e}"))?;
    let c_method = CString::new(method_name).map_err(|e| format!("bad method: {e}"))?;
    let handle = (bridge.harmony_patch_postfix)(c_class.as_ptr(), c_method.as_ptr(), postfix_fn);
    if handle.0 == 0 {
        return Err(format!(
            "harmony_patch_postfix({class_name}, {method_name}) failed"
        ));
    }
    Ok(Hook {
        handle,
        class_name: class_name.to_string(),
        method_name: method_name.to_string(),
        when: HookWhen::Postfix,
    })
}

/// Workspace-standard registry for live hooks. Game crates push
/// here at worker init; `shutdown_all` releases them all on mod
/// teardown.
pub struct HookRegistry {
    entries: Mutex<Vec<Hook>>,
}

impl HookRegistry {
    pub const fn new() -> Self {
        Self {
            entries: Mutex::new(Vec::new()),
        }
    }

    pub fn register(&self, hook: Hook) {
        self.entries.lock().push(hook);
    }

    pub fn shutdown_all(&self) {
        let n = self.entries.lock().len();
        self.entries.lock().clear();
        if n > 0 {
            crate::mono::log(
                crate::mono::LogLevel::Info,
                &format!("unityforge: dropped {n} hook(s)"),
            );
        }
    }

    pub fn len(&self) -> usize {
        self.entries.lock().len()
    }

    pub fn is_empty(&self) -> bool {
        self.entries.lock().is_empty()
    }
}

impl Default for HookRegistry {
    fn default() -> Self {
        Self::new()
    }
}

pub static HOOK_REGISTRY: HookRegistry = HookRegistry::new();
