//! Unity-side generic primitive op handlers. Register against
//! the shared `modforge::ops::OP_REGISTRY`.
//!
//! Ops shipped here mirror the ueforge surface where the concept
//! maps cleanly, and add Unity-flavored variants where it does
//! not:
//!   - walk_class, inspect_object, list_singletons
//!   - read_field, write_field, invoke_method
//!   - list_ops, list_selectors (auto-generated)

use serde_json::{Value as Json, json};

use modforge::args::{arg_str, arg_u64};
use modforge::ops::{OP_REGISTRY, OpDef};

use crate::bridge::MonoHandle;
use crate::main_thread_queue::MAIN_QUEUE;
use crate::mono::{MonoObject, MonoType};

/// Register every framework-shipped Unity op. Game crates call
/// this once at worker init, typically before their own
/// per-game `OP_REGISTRY.register(...)` calls.
pub fn register_builtins() {
    OP_REGISTRY.register_many([
        OpDef::new(
            "ping",
            "Liveness probe",
            "{}",
            |_args| Ok(json!({"pong": true})),
        ),
        OpDef::new(
            "walk_class",
            "Enumerate every live instance of a Mono type",
            "{class: str, include_inactive?: bool}",
            walk_class,
        ),
        OpDef::new(
            "inspect_object",
            "Dump an object's fields + property values",
            "{handle: i32}",
            inspect_object,
        ),
        OpDef::new(
            "read_field",
            "Read a typed field on a Mono object handle",
            "{handle: i32, field: str}",
            read_field,
        ),
        OpDef::new(
            "write_field",
            "Write a typed field on a Mono object handle (main-thread queued)",
            "{handle: i32, field: str, value: any}",
            write_field,
        ),
        OpDef::new(
            "invoke_method",
            "Invoke a method on a Mono object handle (main-thread queued)",
            "{handle: i32, method: str, args?: array}",
            invoke_method,
        ),
        OpDef::new(
            "list_singletons",
            "Get the live Singleton<T>.Instance for each named type",
            "{types: [str]}",
            list_singletons,
        ),
        OpDef::new(
            "list_ops",
            "Auto-generated catalog of every registered debug op",
            "{}",
            |_args| Ok(OP_REGISTRY.list_json()),
        ),
        OpDef::new(
            "op_metrics",
            "Per-op latency metrics (sorted by total_ns)",
            "{}",
            |_args| Ok(modforge::ops::metrics_json()),
        ),
        OpDef::new(
            "list_selectors",
            "Auto-generated catalog of every registered selector kind",
            "{}",
            |_args| Ok(crate::selector::list_json()),
        ),
        OpDef::new(
            "list_methods",
            "Enumerate methods on a type (walks inheritance chain)",
            "{class: str}",
            list_methods,
        ),
    ]);
}

fn walk_class(args: &Json) -> Result<Json, String> {
    let class = arg_str(args, "class")?;
    let include_inactive = args
        .get("include_inactive")
        .and_then(Json::as_bool)
        .unwrap_or(false);
    let ty = MonoType::find(class).ok_or_else(|| format!("type '{class}' not found"))?;
    ty.walk(include_inactive)
}

fn list_methods(args: &Json) -> Result<Json, String> {
    use std::ffi::CString;
    let class = arg_str(args, "class")?;
    let bridge = crate::bridge::try_get()?;
    let c_name = CString::new(class).map_err(|e| format!("bad class: {e}"))?;
    let mut buf = vec![0u8; 65536];
    let n = (bridge.list_methods)(
        c_name.as_ptr(),
        buf.as_mut_ptr() as *mut std::os::raw::c_char,
        buf.len() as i32,
    );
    if n < 0 {
        return Err("list_methods: buffer too small".into());
    }
    buf.truncate(n as usize);
    serde_json::from_slice::<Json>(&buf).map_err(|e| format!("list_methods json: {e}"))
}

fn inspect_object(args: &Json) -> Result<Json, String> {
    let h = arg_u64(args, "handle", None)? as i32;
    // SAFETY: caller asserts handle is live; if not, the shim's
    // dictionary lookup returns null and the op surfaces an
    // error.
    let obj = unsafe { MonoObject::from_handle(MonoHandle(h)) };
    let r = obj.dump();
    std::mem::forget(obj); // don't release; caller may reuse the handle
    r
}

fn read_field(args: &Json) -> Result<Json, String> {
    let h = arg_u64(args, "handle", None)? as i32;
    let field = arg_str(args, "field")?;
    let obj = unsafe { MonoObject::from_handle(MonoHandle(h)) };
    let r = obj.read_field(field);
    std::mem::forget(obj);
    r
}

fn write_field(args: &Json) -> Result<Json, String> {
    // Field writes go through the main thread to avoid race
    // conditions with the game's Update loop.
    let h = arg_u64(args, "handle", None)? as i32;
    let field = arg_str(args, "field")?.to_string();
    let value = args.get("value").cloned().unwrap_or(Json::Null);

    // For an HTTP request we want a synchronous answer. Use a
    // bounded oneshot via parking_lot.
    use std::sync::Arc;
    use parking_lot::Mutex;
    let result: Arc<Mutex<Option<Result<(), String>>>> = Arc::new(Mutex::new(None));
    let r2 = result.clone();
    MAIN_QUEUE.push(move || {
        let obj = unsafe { MonoObject::from_handle(MonoHandle(h)) };
        let res = obj.write_field(&field, &value);
        std::mem::forget(obj);
        *r2.lock() = Some(res);
    });

    // Poll for up to ~1 second. The shim ticks at frame rate
    // (~16ms); 1s is generous for a single field write.
    let deadline = std::time::Instant::now() + std::time::Duration::from_secs(1);
    loop {
        if let Some(r) = result.lock().take() {
            return r.map(|_| json!({"written": true}));
        }
        if std::time::Instant::now() >= deadline {
            return Err("write_field: main-thread queue timed out".into());
        }
        std::thread::sleep(std::time::Duration::from_millis(5));
    }
}

fn invoke_method(args: &Json) -> Result<Json, String> {
    let h = arg_u64(args, "handle", None)? as i32;
    let method = arg_str(args, "method")?.to_string();
    let m_args = args.get("args").cloned().unwrap_or(Json::Array(vec![]));

    use std::sync::Arc;
    use parking_lot::Mutex;
    let result: Arc<Mutex<Option<Result<Json, String>>>> = Arc::new(Mutex::new(None));
    let r2 = result.clone();
    MAIN_QUEUE.push(move || {
        let obj = unsafe { MonoObject::from_handle(MonoHandle(h)) };
        let res = obj.invoke(&method, &m_args);
        std::mem::forget(obj);
        *r2.lock() = Some(res);
    });

    let deadline = std::time::Instant::now() + std::time::Duration::from_secs(2);
    loop {
        if let Some(r) = result.lock().take() {
            return r;
        }
        if std::time::Instant::now() >= deadline {
            return Err("invoke_method: main-thread queue timed out".into());
        }
        std::thread::sleep(std::time::Duration::from_millis(5));
    }
}

fn list_singletons(args: &Json) -> Result<Json, String> {
    let types = args
        .get("types")
        .and_then(Json::as_array)
        .ok_or("missing arg 'types' (array of class names)")?;
    let mut out = Vec::with_capacity(types.len());
    for t in types {
        let Some(name) = t.as_str() else {
            continue;
        };
        let entry = match MonoType::find(name) {
            None => json!({"class": name, "found": false}),
            Some(ty) => match ty.singleton_instance() {
                None => json!({"class": name, "found": false, "type_found": true}),
                Some(obj) => {
                    let h = obj.handle();
                    std::mem::forget(obj); // keep alive; caller may inspect_object
                    json!({"class": name, "found": true, "handle": h.0})
                }
            },
        };
        out.push(entry);
    }
    Ok(json!({"singletons": out}))
}
