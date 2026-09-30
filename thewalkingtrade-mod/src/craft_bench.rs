//! Crafting reach: a bench counts materials from `craft_bench_multiplier`
//! times its normal area, and nothing else about the bench changes.
//!
//! Vanilla (Cpp2IL dump 1.2.5; docs/research.md "How crafting finds its
//! materials"): every material lookup of a bench goes through
//! `ItemObjectProvider.GetConsumableItemsPresentFromBox` or
//! `...FromBoxes`, called only by `CraftStationObject`. Each does
//! `Physics.OverlapBox` over the bench's `_itemsCollider` bounds and
//! keeps items that exist, are not secured buildables, and have
//! `Quantity > 0`.
//!
//! The same boxes also block building and make items inside them
//! belong to the bench (never cleanable), so they are NOT resized for
//! good. A prefix grows each box by the multiplier for the length of
//! the lookup and a postfix puts the size back; no physics step runs in
//! between, so only the lookup sees the bigger box, with the game's own
//! filter.

use std::ffi::{CStr, c_void};
use std::os::raw::c_char;
use std::sync::Mutex;

use serde_json::{Value as Json, json};
use unityforge::hook::{HOOK_REGISTRY, HookCtx, patch_postfix_result, patch_prefix_ctx};
use unityforge::mono::{LogLevel, MonoObject, json_handle, log, owned_object};

use crate::ctx_object;
use crate::settings::settings;

const PROVIDER: &str = "Il2CppRuntime.Item.ItemObjectProvider";

/// Boxes grown by the prefix and their original size, restored by the
/// postfix of the same call.
static GROWN: Mutex<Vec<(MonoObject, Json)>> = Mutex::new(Vec::new());

pub fn install() {
    let results = [
        patch_prefix_ctx(PROVIDER, "GetConsumableItemsPresentFromBox", HookCtx::Arg0, grow_box),
        patch_prefix_ctx(PROVIDER, "GetConsumableItemsPresentFromBoxes", HookCtx::Arg0, grow_boxes),
        patch_postfix_result(PROVIDER, "GetConsumableItemsPresentFromBox", &json!({}), restore),
        patch_postfix_result(PROVIDER, "GetConsumableItemsPresentFromBoxes", &json!({}), restore),
    ];
    for r in results {
        match r {
            Ok(h) => HOOK_REGISTRY.register(h),
            Err(e) => log(LogLevel::Error, &format!("thewalkingtrade-mod: craft reach FAILED: {e}")),
        }
    }
}

extern "C" fn grow_box(ctx: *const c_void) -> i32 {
    let _m = modforge::counters::measure("twt: hook: craft lookup grow");
    let Some(b) = ctx_object(ctx) else { return 0 };
    if let Err(e) = grow(b) {
        log(LogLevel::Warn, &format!("thewalkingtrade-mod: craft reach: {e}"));
    }
    0
}

extern "C" fn grow_boxes(ctx: *const c_void) -> i32 {
    let _m = modforge::counters::measure("twt: hook: craft lookup grow");
    let Some(arr) = ctx_object(ctx) else { return 0 };
    let each = || -> Result<(), String> {
        let n = arr
            .invoke("get_Length", &json!([]))
            .or_else(|_| arr.invoke("get_Count", &json!([])))?
            .as_i64()
            .unwrap_or(0);
        for i in 0..n {
            if let Some(bh) = json_handle(&arr.invoke("get_Item", &json!([i]))?) {
                grow(owned_object(bh))?;
            }
        }
        Ok(())
    };
    if let Err(e) = each() {
        log(LogLevel::Warn, &format!("thewalkingtrade-mod: craft reach: {e}"));
    }
    0
}

/// Grow one BoxCollider by the multiplier and remember its size.
fn grow(b: MonoObject) -> Result<(), String> {
    let mult = settings().get().craft_bench_multiplier;
    let size = b.invoke("get_size", &json!([]))?;
    let (x, y, z) = modforge::client::parse_vec3(&size).ok_or_else(|| format!("size {size}"))?;
    b.invoke("set_size", &json!([{"x": x * mult, "y": y * mult, "z": z * mult}]))?;
    GROWN
        .lock()
        .map_err(|e| e.to_string())?
        .push((b, json!({"x": x, "y": y, "z": z})));
    Ok(())
}

/// Postfix: put every grown box back. Keeps the lookup's result.
extern "C" fn restore(
    _instance: *const c_void,
    args: *const c_char,
    _result: *const c_char,
    _out: *mut c_char,
    _cap: i32,
) -> i32 {
    let _m = modforge::counters::measure("twt: hook: craft lookup restore");
    // The argument handle is ours to release.
    // SAFETY: the shim passes NUL-terminated JSON valid for the call.
    let args = unsafe { CStr::from_ptr(args) }.to_str().unwrap_or("[]");
    if let Some(h) = serde_json::from_str::<Json>(args).ok().and_then(|a| a.get(0).and_then(json_handle)) {
        drop(owned_object(h));
    }
    let grown: Vec<_> = match GROWN.lock() {
        Ok(mut g) => g.drain(..).collect(),
        Err(_) => return -1,
    };
    for (b, size) in grown {
        if let Err(e) = b.invoke("set_size", &json!([size])) {
            log(LogLevel::Warn, &format!("thewalkingtrade-mod: craft reach restore: {e}"));
        }
    }
    -1
}
