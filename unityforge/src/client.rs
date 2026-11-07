//! Blocking test client for Unity mods.
//!
//! Re-exports everything from `modforge::client` and adds
//! Unity-specific research helpers (IL2CPP name fallback,
//! include_inactive scans).

pub use modforge::client::*;

use serde::de::DeserializeOwned;
use serde_json::{Value, json};

/// Find all live instances of a Unity class. Tries the `Il2Cpp`
/// prefixed name first (IL2CPP games), then the plain name.
///
/// `include_inactive`: when true, the shim scans inactive
/// GameObjects too (some managers park on inactive objects).
pub fn find_instances<S: DeserializeOwned>(
    api: &Api<S>,
    class: &str,
    include_inactive: bool,
) -> Result<Vec<Value>, String> {
    for name in [format!("Il2Cpp{class}"), class.to_string()] {
        let r = match api.try_op(
            "walk_class",
            json!({"class": name, "include_inactive": include_inactive}),
        ) {
            Ok(r) if r.ok => r,
            Ok(r) => {
                let err = r.error.unwrap_or_else(|| "op not ok".into());
                println!("find_instances({name}) failed: {err}");
                continue;
            }
            Err(e) => return Err(format!("transport: {e}")),
        };

        let instances = r
            .result
            .get("instances")
            .and_then(Value::as_array)
            .cloned()
            .or_else(|| r.result.as_array().cloned())
            .unwrap_or_default();

        println!("find_instances({name}): {} instance(s)", instances.len());
        return Ok(instances);
    }
    Err(format!(
        "{class}: neither Il2Cpp{class} nor {class} resolved"
    ))
}

/// Find the first live instance handle of a class.
pub fn first_handle<S: DeserializeOwned>(api: &Api<S>, class: &str) -> Option<i64> {
    first_handle_opts(api, class, false)
}

/// Find the first live instance handle, scanning inactive objects too.
pub fn first_handle_inactive<S: DeserializeOwned>(api: &Api<S>, class: &str) -> Option<i64> {
    first_handle_opts(api, class, true)
}

fn first_handle_opts<S: DeserializeOwned>(
    api: &Api<S>,
    class: &str,
    include_inactive: bool,
) -> Option<i64> {
    match find_instances(api, class, include_inactive) {
        Ok(instances) => {
            let h = instances.first().and_then(|i| handle_of(i));
            if h.is_none() {
                println!("{class}: resolves, zero live instances");
            }
            h
        }
        Err(e) => {
            println!("{class}: find_instances failed ({e})");
            None
        }
    }
}

/// Full names of every type in the IL2CPP assembly whose simple name
/// is `assembly` (for example "Assembly-CSharp"), compiler-generated
/// closures left out. None when no loaded assembly has that name.
///
/// The walk goes through the IL2CPP side of the runtime: the
/// interop proxy Il2CppSystem.AppDomain, whose assemblies and types
/// are IL2CPP objects and chain like any game object. Host-side
/// System.Reflection objects come back stringified, not as handles.
/// Moved here from megabonk-mod and wanderburg-mod's research tests.
///
/// Asks the shim first (Il2CppBridge.AssemblyTypeNames, one call for
/// the whole assembly); the walk below, one round trip per type, is
/// for a shim loaded before that method existed.
pub fn assembly_type_names<S: DeserializeOwned>(api: &Api<S>, assembly: &str) -> Option<Vec<String>> {
    let one = api.op(
        "invoke_static",
        json!({"class": "Unityforge.Shim.Il2CppBridge", "method": "AssemblyTypeNames", "args": [assembly]}),
    );
    if let Some(text) = one.result.as_str() {
        if text.is_empty() {
            println!("{assembly}: no loaded assembly by that name");
            return None;
        }
        return Some(text.lines().map(str::to_string).collect());
    }
    let err = one.error.unwrap_or_default();
    if !err.contains("not found") {
        println!("{assembly}: AssemblyTypeNames failed: {err}");
        return None;
    }
    println!("AssemblyTypeNames not in the running shim ({err}); walking type by type");
    assembly_type_names_walk(api, assembly)
}

fn assembly_type_names_walk<S: DeserializeOwned>(api: &Api<S>, assembly: &str) -> Option<Vec<String>> {
    let invoke = |h: i64, method: &str, args: Value| {
        api.op("invoke_method", json!({"handle": h, "method": method, "args": args}))
    };
    let release = |h: i64| {
        api.op("release_handle", json!({"handle": h}));
    };
    let domain = api.op(
        "invoke_static",
        json!({"class": "Il2CppSystem.AppDomain", "method": "get_CurrentDomain", "args": []}),
    );
    let Some(domain_h) = handle_of(&domain.result) else {
        println!("AppDomain.get_CurrentDomain carried no handle: {:?}", domain.error);
        return None;
    };
    let asms = invoke(domain_h, "GetAssemblies", json!([]));
    release(domain_h);
    let Some(asms_h) = handle_of(&asms.result) else {
        println!("GetAssemblies carried no handle: {:?}", asms.error);
        return None;
    };
    let prefix = format!("{assembly},");
    let mut asm_h = None;
    for i in 0..count_of(api, asms_h).unwrap_or(0) {
        let Some(h) = handle_of(&invoke(asms_h, "get_Item", json!([i])).result) else {
            continue;
        };
        if invoke(h, "get_FullName", json!([])).result.as_str().unwrap_or("").starts_with(&prefix) {
            asm_h = Some(h);
            break;
        }
        release(h);
    }
    release(asms_h);
    let asm_h = asm_h?;
    let types = invoke(asm_h, "GetTypes", json!([]));
    release(asm_h);
    let Some(seq) = handle_of(&types.result) else {
        println!("{assembly}: GetTypes carried no handle: {:?}", types.error);
        return None;
    };
    let mut out = Vec::new();
    for i in 0..count_of(api, seq).unwrap_or(0) {
        let Some(th) = handle_of(&invoke(seq, "get_Item", json!([i])).result) else {
            continue;
        };
        let name = invoke(th, "get_FullName", json!([]));
        release(th);
        if let Some(full) = name.result.as_str()
            && !full.contains('<')
        {
            out.push(full.to_string());
        }
    }
    release(seq);
    Some(out)
}

/// True when inspect_object on a live instance of `class` lists
/// `field`. Prints the verdict either way.
pub fn field_exists<S: DeserializeOwned>(api: &Api<S>, class: &str, field: &str) -> bool {
    let Some(handle) = first_handle(api, class) else {
        println!("  {class}.{field}: NO LIVE INSTANCE (class may still exist)");
        return false;
    };
    let read = api.op("read_field", json!({"handle": handle, "field": field}));
    if read.ok {
        println!("  {class}.{field} = {}", read.result);
        true
    } else {
        println!("  {class}.{field}: MISSING ({:?})", read.error);
        false
    }
}
