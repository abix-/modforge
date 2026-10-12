//! Shared helpers for the megabonk-mod research tests.
//!
//! The control plane is generic (handle chaining): the unityforge
//! client helpers are the whole research toolkit. New research
//! tests reuse them; do not copy them into a test file.
//!
//! Each --test target compiles this module separately and no
//! target uses every helper, so dead_code is expected here.
#![allow(dead_code, unused_imports)]

pub use unityforge::client::{
    count_of, dump_sequence, field_exists, fields, find_instances, first_handle, handle_of,
    parse_vec3, ping_or_skip, print_declared_methods,
};

use serde_json::{Value, json};
use unityforge::client::Api;

pub const GAME_DIR: &str = "C:/Games/Steam/steamapps/common/Megabonk";
pub const MELON_LOG: &str = "C:/Games/Steam/steamapps/common/Megabonk/MelonLoader/Latest.log";

pub fn api() -> Api<Value> {
    let port = std::env::var("MEGABONK_MOD_PORT")
        .ok()
        .and_then(|p| p.parse().ok())
        .unwrap_or(17183);
    Api::at(port, "/op")
}

fn invoke(api: &Api<Value>, h: i64, method: &str, args: Value) -> Value {
    api.op("invoke_method", json!({"handle": h, "method": method, "args": args})).result
}

/// The game-side System.Type of an Assembly-CSharp class, by its
/// IL2CPP name (no Il2Cpp prefix), as a handle.
fn game_type(api: &Api<Value>, class: &str) -> Option<i64> {
    let ty = api.op(
        "invoke_static",
        json!({"class": "Il2CppSystem.Type", "method": "GetType", "args": [format!("{class}, Assembly-CSharp")]}),
    );
    let h = handle_of(&ty.result);
    if h.is_none() {
        println!("  Type.GetType({class}) carried no handle: {:?}", ty.error);
    }
    h
}

/// Print every overload of `method` on `class` (IL2CPP name, no Il2Cpp
/// prefix): its parameters' type and name, through the runtime's own
/// reflection (GetMethods, GetParameters).
pub fn parameters(api: &Api<Value>, class: &str, method: &str) {
    let Some(ty_h) = game_type(api, class) else { return };
    let Some(methods) = handle_of(&invoke(api, ty_h, "GetMethods", json!([]))) else {
        println!("  GetMethods carried no handle");
        return;
    };
    let n = count_of(api, methods).unwrap_or(0);
    for i in 0..n {
        let Some(m) = handle_of(&invoke(api, methods, "get_Item", json!([i]))) else {
            continue;
        };
        if invoke(api, m, "get_Name", json!([])).as_str() != Some(method) {
            api.op("release_handle", json!({"handle": m}));
            continue;
        }
        let mut shown = Vec::new();
        if let Some(ps) = handle_of(&invoke(api, m, "GetParameters", json!([]))) {
            for j in 0..count_of(api, ps).unwrap_or(0) {
                let Some(p) = handle_of(&invoke(api, ps, "get_Item", json!([j]))) else {
                    continue;
                };
                let name = invoke(api, p, "get_Name", json!([]));
                let pty = handle_of(&invoke(api, p, "get_ParameterType", json!([])));
                let type_name = pty.map(|t| invoke(api, t, "get_FullName", json!([]))).unwrap_or(Value::Null);
                shown.push(format!("{} {}", type_name.as_str().unwrap_or("?"), name.as_str().unwrap_or("?")));
                if let Some(t) = pty {
                    api.op("release_handle", json!({"handle": t}));
                }
                api.op("release_handle", json!({"handle": p}));
            }
            api.op("release_handle", json!({"handle": ps}));
        }
        let ret = handle_of(&invoke(api, m, "get_ReturnType", json!([])))
            .map(|t| invoke(api, t, "get_FullName", json!([])))
            .unwrap_or(Value::Null);
        println!("  {class}.{method}({}) -> {}", shown.join(", "), ret.as_str().unwrap_or("?"));
        api.op("release_handle", json!({"handle": m}));
    }
    api.op("release_handle", json!({"handle": methods}));
    api.op("release_handle", json!({"handle": ty_h}));
}

/// An enum's value names in order (index i is value i for a plain
/// enum), through the runtime's own Enum.GetNames; walk_class lists
/// none for an enum.
pub fn enum_names(api: &Api<Value>, class: &str) -> Vec<String> {
    let mut out = Vec::new();
    let Some(ty_h) = game_type(api, class) else { return out };
    let names = api.op(
        "invoke_static",
        json!({"class": "Il2CppSystem.Enum", "method": "GetNames", "args": [{"$handle": ty_h}]}),
    );
    if let Some(seq) = handle_of(&names.result) {
        for i in 0..count_of(api, seq).unwrap_or(0) {
            out.push(invoke(api, seq, "get_Item", json!([i])).as_str().unwrap_or("?").to_string());
        }
        api.op("release_handle", json!({"handle": seq}));
    }
    api.op("release_handle", json!({"handle": ty_h}));
    out
}

/// Full names of every Assembly-CSharp type, closures left out.
/// The walk from wanderburg-mod/tests/research_types.rs: the
/// IL2CPP AppDomain, its assemblies, then GetTypes.
pub fn game_type_names(api: &Api<Value>) -> Vec<String> {
    let mut out = Vec::new();
    let domain = api.op(
        "invoke_static",
        json!({"class": "Il2CppSystem.AppDomain", "method": "get_CurrentDomain", "args": []}),
    );
    let Some(domain_h) = handle_of(&domain.result) else {
        println!("AppDomain.get_CurrentDomain carried no handle: {:?}", domain.error);
        return out;
    };
    let asms = api.op(
        "invoke_method",
        json!({"handle": domain_h, "method": "GetAssemblies", "args": []}),
    );
    let Some(asms_h) = handle_of(&asms.result) else {
        println!("GetAssemblies carried no handle: {:?}", asms.error);
        return out;
    };
    let asm_count = count_of(api, asms_h).unwrap_or(0);
    let mut asm_h = None;
    for i in 0..asm_count {
        let item = api.op(
            "invoke_method",
            json!({"handle": asms_h, "method": "get_Item", "args": [i]}),
        );
        let Some(h) = handle_of(&item.result) else {
            continue;
        };
        let full = api.op(
            "invoke_method",
            json!({"handle": h, "method": "get_FullName", "args": []}),
        );
        if full.result.as_str().unwrap_or("").starts_with("Assembly-CSharp,") {
            asm_h = Some(h);
            break;
        }
        api.op("release_handle", json!({"handle": h}));
    }
    api.op("release_handle", json!({"handle": asms_h}));
    api.op("release_handle", json!({"handle": domain_h}));
    let Some(asm_h) = asm_h else {
        println!("no assembly named Assembly-CSharp among {asm_count} assemblies");
        return out;
    };
    let types = api.op(
        "invoke_method",
        json!({"handle": asm_h, "method": "GetTypes", "args": []}),
    );
    let Some(seq) = handle_of(&types.result) else {
        println!("GetTypes carried no handle: {:?}", types.error);
        return out;
    };
    let n = count_of(api, seq).unwrap_or(0);
    println!("Assembly-CSharp: {n} types");
    for i in 0..n {
        let item = api.op(
            "invoke_method",
            json!({"handle": seq, "method": "get_Item", "args": [i]}),
        );
        let Some(th) = handle_of(&item.result) else {
            continue;
        };
        let name = api.op(
            "invoke_method",
            json!({"handle": th, "method": "get_FullName", "args": []}),
        );
        api.op("release_handle", json!({"handle": th}));
        if let Some(full) = name.result.as_str()
            && !full.contains('<')
        {
            out.push(full.to_string());
        }
    }
    api.op("release_handle", json!({"handle": seq}));
    api.op("release_handle", json!({"handle": asm_h}));
    out
}
