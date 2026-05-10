//! Generic op handlers. Each takes the JSON `args` blob from a
//! request and returns the JSON `result` blob (or an error string).
//! Snapshot building, the envelope, and the dispatch match arm
//! belong to the embedding crate.
//!
//! Selector-resolving ops accept a closure so the game's
//! game-specific selectors plug in. The convention:
//!
//! ```ignore
//! fn resolve(s: &str) -> Result<&'static UObject, String> {
//!     if let Some(r) = ueforge::selector::resolve_generic(s) {
//!         return r;
//!     }
//!     match s {
//!         "live_player" => ...,
//!         _ => Err(...),
//!     }
//! }
//!
//! match op {
//!     "read_bytes" => ueforge::ops::read_bytes(&args, resolve),
//!     ...
//! }
//! ```

use std::ffi::c_void;

use serde_json::Value as Json;

use crate::args::{arg_str, arg_u64};
use crate::hex;
use crate::ue::{self, UObject, fname::FName};

/// Dispatch an op name + args to ueforge's built-in handlers.
/// Returns `Some(result)` if the op is one ueforge owns, or
/// `None` if the embedding crate should handle it.
///
/// Use as the first match arm in your debug dispatcher:
///
/// ```ignore
/// fn handle(body: &str) -> OpResponse<Snapshot> {
///     let (op, args) = parse_request(body)?;
///     if let Some(r) = ueforge::ops::handle_builtin(&op, &args, resolve_instance) {
///         return OpResponse::from_result(&op, r, build_snapshot());
///     }
///     // Game-specific ops below...
/// }
/// ```
///
/// Built-in ops dispatched here:
/// - `read_bytes`, `write_bytes`, `walk_class`, `fname_to_string`
///   (the generic primitives)
/// - `scan_memory`, `scan_rescan`, `scan_session`, `scan_close`
///   (Cheat-Engine-style scanner)
/// - `freeze`, `unfreeze`, `freeze_list`
///
/// Note `snapshot` and `call` are NOT in this set — `snapshot`'s
/// state shape is per-game, and `call` needs the game's PE
/// queue + selector resolver. Game crates wire those manually.
pub fn handle_builtin<F>(
    op: &str,
    args: &Json,
    resolve: F,
) -> Option<Result<Json, String>>
where
    F: Fn(&str) -> Result<&'static UObject, String>,
{
    Some(match op {
        "read_bytes" => read_bytes(args, &resolve),
        "write_bytes" => write_bytes(args, &resolve),
        "walk_class" => walk_class(args),
        "fname_to_string" => fname_to_string(args),
        "inspect_address" => inspect_address(args),
        "scan_memory" => crate::scanner::scan_memory(args),
        "scan_rescan" => crate::scanner::scan_rescan(args),
        "scan_session" => crate::scanner::scan_session(args),
        "scan_close" => crate::scanner::scan_close(args),
        "freeze" => crate::scanner::freeze(args),
        "unfreeze" => crate::scanner::unfreeze(args),
        "freeze_list" => crate::scanner::freeze_list(args),
        _ => return None,
    })
}

/// Cap on `read_bytes` length / `write_bytes` payload (1 MiB).
/// Sized to comfortably cover any UE struct walk while preventing
/// pathological reads from hanging the listener.
pub const BYTE_OP_CAP: usize = 0x10_0000;

pub fn read_bytes<F>(args: &Json, resolve: F) -> Result<Json, String>
where
    F: FnOnce(&str) -> Result<&'static UObject, String>,
{
    let selector = arg_str(args, "instance_selector")?.to_string();
    let offset = arg_u64(args, "offset", Some(0))? as usize;
    let length = arg_u64(args, "length", None)? as usize;
    if length > BYTE_OP_CAP {
        return Err(format!("length {length} > 1MB cap"));
    }
    let obj = resolve(&selector)?;
    let mut out = vec![0u8; length];
    unsafe {
        let base = obj.field_ptr(offset);
        std::ptr::copy_nonoverlapping(base, out.as_mut_ptr(), length);
    }
    Ok(serde_json::json!({
        "selector": selector,
        "offset": format!("0x{offset:X}"),
        "length": length,
        "bytes_hex": hex::encode(&out),
    }))
}

pub fn write_bytes<F>(args: &Json, resolve: F) -> Result<Json, String>
where
    F: FnOnce(&str) -> Result<&'static UObject, String>,
{
    let selector = arg_str(args, "instance_selector")?.to_string();
    let offset = arg_u64(args, "offset", Some(0))? as usize;
    let bytes = hex::decode(arg_str(args, "bytes_hex")?)?;
    if bytes.len() > BYTE_OP_CAP {
        return Err(format!("bytes len {} > 1MB cap", bytes.len()));
    }
    let obj = resolve(&selector)?;
    unsafe {
        let dst = obj.field_ptr(offset) as *mut u8;
        std::ptr::copy_nonoverlapping(bytes.as_ptr(), dst, bytes.len());
    }
    Ok(serde_json::json!({
        "selector": selector,
        "offset": format!("0x{offset:X}"),
        "wrote_bytes": bytes.len(),
    }))
}

/// Walk `GObjects`, return up to `max` non-CDO instances of the
/// named class (CDOs included if `include_cdo: true`). Pure
/// engine traversal — no host hooks needed.
pub fn walk_class(args: &Json) -> Result<Json, String> {
    let class_name = arg_str(args, "class")?.to_string();
    let max = arg_u64(args, "max", Some(256))? as usize;
    let include_cdo = args
        .get("include_cdo")
        .and_then(Json::as_bool)
        .unwrap_or(false);

    let rt = ue::try_runtime().ok_or("ueforge: ue runtime not initialized")?;
    let class = ue::find_class_fast(&class_name)
        .ok_or_else(|| format!("class '{class_name}' not found"))?;
    let view = unsafe { ue::GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return Err("gobjects view invalid".to_string());
    }

    let mut hits = Vec::with_capacity(max);
    let mut total = 0usize;
    for obj in view.iter() {
        if !obj.is_a(class) {
            continue;
        }
        if !include_cdo && obj.is_default_object() {
            continue;
        }
        total += 1;
        if hits.len() >= max {
            continue;
        }
        let addr = obj as *const UObject as usize;
        hits.push(serde_json::json!({
            "addr": format!("0x{addr:X}"),
            "addr_selector": format!("addr:0x{addr:X}"),
            "name": obj.name(),
            "full_name": obj.full_name(),
            "is_cdo": obj.is_default_object(),
        }));
    }
    Ok(serde_json::json!({
        "class": class_name,
        "total": total,
        "returned": hits.len(),
        "instances": hits,
    }))
}

/// Resolve an FName (passed as a u64 — the 8 bytes that make up
/// `{ comparison_index: i32, number: u32 }`) to its display
/// string. Useful from tests that walk TMap<FName, ...> bytes
/// and need to show readable keys instead of raw u64s.
///
/// Args: `{ "fname": <u64> }` (decimal or 0x-prefixed hex via JSON).
/// Result: `{ "string": "<name>" }`.
pub fn fname_to_string(args: &Json) -> Result<Json, String> {
    let raw = arg_u64(args, "fname", None)?;
    let fname: FName = unsafe { std::mem::transmute_copy(&raw) };
    let rt = ue::try_runtime().ok_or("ueforge: ue runtime not initialized")?;
    let s = unsafe { rt.name_resolver.to_string(fname) };
    Ok(serde_json::json!({ "string": s }))
}

/// Given a raw memory address, find the UObject (if any) that
/// contains it. Walks GObjects, computes each object's
/// `[base, base + class.properties_size)` range, returns the
/// first match.
///
/// Args: `{ "addr": "0x<hex>" }`.
///
/// Result on hit:
/// ```json
/// {
///   "found": true,
///   "addr": "0x...",
///   "instance_addr": "0x...",
///   "class": "DataTable",
///   "instance_name": "DT_Materials",
///   "instance_full_name": "DataTable /Game/Data/DT_Materials...",
///   "offset_in_instance": "0x48",
///   "instance_size": 624
/// }
/// ```
///
/// On miss: `{ "found": false, "addr": "0x..." }`. Misses are
/// expected for raw allocator buffers, save blobs, and other
/// non-UObject memory the scanner finds.
pub fn inspect_address(args: &Json) -> Result<Json, String> {
    let addr_str = arg_str(args, "addr")?;
    let target = parse_addr(addr_str)?;

    let rt = ue::try_runtime().ok_or("ueforge: ue runtime not initialized")?;
    let view = unsafe { ue::GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return Err("gobjects view invalid".into());
    }

    for obj in view.iter() {
        let base = obj as *const UObject as usize;
        let Some(class) = obj.class() else { continue };
        let size = class.properties_size() as usize;
        if size == 0 || size > 0x100_0000 {
            continue; // sanity: skip absurd sizes
        }
        if target >= base && target < base + size {
            return Ok(serde_json::json!({
                "found": true,
                "addr": format!("0x{target:X}"),
                "instance_addr": format!("0x{base:X}"),
                "instance_addr_selector": format!("addr:0x{base:X}"),
                "class": class.as_object().name(),
                "instance_name": obj.name(),
                "instance_full_name": obj.full_name(),
                "offset_in_instance": format!("0x{:X}", target - base),
                "instance_size": size,
            }));
        }
    }
    Ok(serde_json::json!({
        "found": false,
        "addr": format!("0x{target:X}"),
        "note": "address not within any UObject (raw allocator memory, save blob, or non-UObject struct)",
    }))
}

fn parse_addr(s: &str) -> Result<usize, String> {
    let hex = s
        .strip_prefix("0x")
        .or_else(|| s.strip_prefix("0X"))
        .unwrap_or(s);
    usize::from_str_radix(hex, 16).map_err(|e| format!("bad address '{s}': {e}"))
}

/// Engine portion of the `call` op: resolve the UFunction by
/// `(class_name, function_name)`, invoke `process_event` against
/// `instance` with the given parm bytes (mutated in place by UE
/// for OUT params), and return the post-call buffer as hex.
///
/// Must be called from the game thread. Game-side op handler
/// resolves the instance selector itself (it may be game-specific)
/// and enqueues a closure that calls this on the host's PE queue.
pub fn exec_call(
    instance: &UObject,
    class_name: &str,
    function_name: &str,
    mut parms: Vec<u8>,
) -> Result<Json, String> {
    let class = ue::find_class_fast(class_name)
        .ok_or_else(|| format!("class '{class_name}' not found"))?;
    let func = class.get_function(class_name, function_name).ok_or_else(|| {
        format!("function '{function_name}' not found on '{class_name}'")
    })?;
    unsafe {
        instance.process_event(func, parms.as_mut_ptr() as *mut c_void);
    }
    Ok(serde_json::json!({
        "parms_hex_after": hex::encode(&parms),
    }))
}
