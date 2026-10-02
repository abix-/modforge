//! What an area's `__MAIN` object holds (operator 2026-10-02): every area
//! brings one (research_area_player_setup.rs found SoundscapeGlobal and
//! info_map in it). Lists everything under the current area's `__MAIN`:
//! each object, whether it is active, and its components, to decide
//! whether a mod can switch it off in an area loaded alongside.
//!
//! Read-only: invoke_static and invoke_method on getters only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_area_main -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running. Results go
//! to docs/area-main.txt.

mod common;
use common::{api, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

/// Stop listing after this many objects.
const MAX_OBJECTS: usize = 2000;

fn call(api: &Api<Value>, h: i64, method: &str, args: Value) -> Option<Value> {
    let r = api.op("invoke_method", json!({"handle": h, "method": method, "args": args}));
    r.ok.then_some(r.result)
}

fn release(api: &Api<Value>, h: i64) {
    api.op("release_handle", json!({"handle": h}));
}

/// The component type names on one object, except Transform.
fn components(api: &Api<Value>, go: i64, component_type: i64) -> Vec<String> {
    let Some(arr) = call(api, go, "GetComponents", json!([{"handle": component_type}])).as_ref().and_then(handle_of) else {
        return vec!["?".into()];
    };
    let n = api.op("read_field", json!({"handle": arr, "field": "Length"})).result.as_i64().unwrap_or(0);
    let mut out = Vec::new();
    for i in 0..n {
        let Some(c) = call(api, arr, "Get", json!([i])).as_ref().and_then(handle_of) else {
            out.push("(missing script)".into());
            continue;
        };
        if let Some(t) = call(api, c, "GetType", json!([])).as_ref().and_then(handle_of) {
            let name = call(api, t, "get_Name", json!([])).and_then(|v| v.as_str().map(String::from)).unwrap_or("?".into());
            if name != "Transform" && name != "RectTransform" {
                out.push(name);
            }
            release(api, t);
        }
        release(api, c);
    }
    release(api, arr);
    out
}

/// Lists a transform and everything under it, depth first.
fn walk(api: &Api<Value>, t: i64, depth: usize, component_type: i64, out: &mut Vec<String>) {
    if out.len() >= MAX_OBJECTS {
        return;
    }
    let name = call(api, t, "get_name", json!([])).and_then(|v| v.as_str().map(String::from)).unwrap_or("?".into());
    let go = call(api, t, "get_gameObject", json!([])).as_ref().and_then(handle_of);
    let (active, comps) = match go {
        Some(g) => {
            let a = call(api, g, "get_activeSelf", json!([])).and_then(|v| v.as_bool());
            let c = components(api, g, component_type);
            release(api, g);
            (a, c)
        }
        None => (None, Vec::new()),
    };
    let active = match active {
        Some(true) => "",
        Some(false) => " [off]",
        None => " [?]",
    };
    out.push(format!("{}{name}{active}  {}", "  ".repeat(depth), comps.join(", ")));
    let n = call(api, t, "get_childCount", json!([])).and_then(|v| v.as_i64()).unwrap_or(0);
    for i in 0..n {
        if let Some(child) = call(api, t, "GetChild", json!([i])).as_ref().and_then(handle_of) {
            walk(api, child, depth + 1, component_type, out);
            release(api, child);
        }
    }
}

#[test]
fn what_main_holds() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let area = api
        .op("invoke_static", json!({"class": "UnityEngine.Application", "method": "get_loadedLevelName", "args": []}))
        .result;
    let main = api.op("invoke_static", json!({"class": "UnityEngine.GameObject", "method": "Find", "args": ["__MAIN"]}));
    let main = handle_of(&main.result).unwrap_or_else(|| panic!("no __MAIN in {area}: {:?}", main.error));
    let ty = api.op("invoke_static", json!({"class": "System.Type", "method": "GetType", "args": ["UnityEngine.Component, UnityEngine.CoreModule"]}));
    let component_type = handle_of(&ty.result).expect("UnityEngine.Component type");
    let t = call(&api, main, "get_transform", json!([])).as_ref().and_then(handle_of).expect("__MAIN transform");

    let mut out = Vec::new();
    walk(&api, t, 0, component_type, &mut out);
    for h in [t, main, component_type] {
        release(&api, h);
    }

    let text = format!("__MAIN in {area}, {} objects ([off] = switched off)\n\n{}\n", out.len(), out.join("\n"));
    println!("{text}");
    let path = format!("{}/docs/area-main.txt", env!("CARGO_MANIFEST_DIR"));
    std::fs::write(&path, &text).expect("write the results");
    println!("written to {path}");
    assert!(out.len() > 1, "__MAIN has nothing under it");
}
