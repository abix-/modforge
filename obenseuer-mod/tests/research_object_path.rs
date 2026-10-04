//! An object by its path in an area (OBENSEUER_AREA, OBENSEUER_PATHS: paths
//! "Top / Child / ...", separated by ";"): for each level, whether it
//! exists, is switched on (activeSelf), and its components. Every object
//! with that name at a level is listed. Read-only.
//!
//! ```text
//! OBENSEUER_AREA="Open Sewer Tenement" OBENSEUER_PATHS="Deekula B Closed / Front_door_001_usable_changelevel (3)" k3sc cargo-lock test -p obenseuer-mod --test research_object_path -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;

use common::{api, call, call_static, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

fn children(api: &Api<Value>, go: i64) -> Vec<i64> {
    let t = handle_of(&call(api, go, "get_transform", json!([]))).expect("transform");
    let n = call(api, t, "get_childCount", json!([])).as_i64().unwrap_or(0);
    (0..n).filter_map(|i| handle_of(&call(api, t, "GetChild", json!([i])))).filter_map(|c| handle_of(&call(api, c, "get_gameObject", json!([])))).collect()
}

fn describe(api: &Api<Value>, go: i64) -> String {
    let on = call(api, go, "get_activeSelf", json!([]));
    let ty = handle_of(&call_static(api, "System.Type", "GetType", json!(["UnityEngine.Component, UnityEngine.CoreModule"]))).expect("Component type");
    let comps = handle_of(&call(api, go, "GetComponents", json!([{"handle": ty}])));
    let names: Vec<String> = comps
        .map(|a| {
            let n = api.op("read_field", json!({"handle": a, "field": "Length"})).result.as_i64().unwrap_or(0);
            (0..n)
                .filter_map(|i| handle_of(&call(api, a, "GetValue", json!([i]))))
                .map(|c| {
                    let ty = handle_of(&call(api, c, "GetType", json!([]))).map(|t| call(api, t, "get_Name", json!([]))).unwrap_or(Value::Null);
                    let enabled = api.op("invoke_method", json!({"handle": c, "method": "get_enabled", "args": []})).result;
                    format!("{}{}", ty.as_str().unwrap_or("?"), if enabled.as_bool() == Some(false) { " (off)" } else { "" })
                })
                .collect()
        })
        .unwrap_or_default();
    format!("on {on}, components [{}]", names.join(", "))
}

#[test]
fn object_path() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let area = std::env::var("OBENSEUER_AREA").expect("OBENSEUER_AREA");
    let paths = std::env::var("OBENSEUER_PATHS").expect("OBENSEUER_PATHS");
    let roots = handle_of(&call_static(&api, "Unityforge.Shim.SceneTools", "RootsOf", json!([area]))).expect("roots");
    let n = api.op("read_field", json!({"handle": roots, "field": "Length"})).result.as_i64().unwrap_or(0);
    let roots: Vec<i64> = (0..n).filter_map(|i| handle_of(&call(&api, roots, "GetValue", json!([i])))).collect();
    for path in paths.split(';').map(str::trim) {
        println!("== {path}");
        let mut level = roots.clone();
        for (depth, name) in path.split(" / ").enumerate() {
            let found: Vec<i64> = level.iter().copied().filter(|&g| call(&api, g, "get_name", json!([])).as_str() == Some(name)).collect();
            if found.is_empty() {
                let here: Vec<String> = level.iter().filter_map(|&g| call(&api, g, "get_name", json!([])).as_str().map(String::from)).collect();
                println!("  {}{name}: not found; here: {here:?}", "  ".repeat(depth));
                break;
            }
            for &g in &found {
                println!("  {}{name}: {}", "  ".repeat(depth), describe(&api, g));
            }
            level = found.iter().flat_map(|&g| children(&api, g)).collect();
        }
    }
}
