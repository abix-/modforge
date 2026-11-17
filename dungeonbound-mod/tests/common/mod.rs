//! Shared helpers for the dungeonbound-mod research tests. The game
//! must be running with the mod deployed; tests skip otherwise.
#![allow(dead_code)]

use modforge::client::Api;
use serde_json::{Value, json};

pub fn api() -> Api<Value> {
    Api::at(31330, "/op").with_timeout(std::time::Duration::from_secs(15))
}

/// The control plane, or None (and a SKIP line) when the game is not up.
pub fn api_or_skip() -> Option<Api<Value>> {
    let api = api();
    match api.try_op("ping", json!({})) {
        Ok(r) if r.ok => Some(api),
        Ok(r) => {
            eprintln!("SKIP: ping failed: {:?}", r.error);
            None
        }
        Err(e) => {
            eprintln!(
                "SKIP: no control plane on 31330 ({e}); launch the game with the mod deployed"
            );
            None
        }
    }
}

/// The first node under `under` whose script path ends with `script`.
pub fn node_with_script(api: &Api<Value>, under: &str, script: &str, depth: u32) -> Option<Value> {
    let tree = op(api, "tree", json!({"node": under, "depth": depth}));
    tree["nodes"]
        .as_array()?
        .iter()
        .find(|n| n["script"].as_str().is_some_and(|s| s.ends_with(script)))
        .cloned()
}

/// An object's script variables (`inspect` rows marked `script`).
pub fn script_vars(api: &Api<Value>, id: &Value, depth: u32) -> Vec<Value> {
    let inspected = op(api, "inspect", json!({"id": id, "depth": depth}));
    inspected["properties"]
        .as_array()
        .map(|p| {
            p.iter()
                .filter(|p| p["script"] == json!(true))
                .cloned()
                .collect()
        })
        .unwrap_or_default()
}

/// Print an object's script methods as `name(arg: TYPE, ...) -> TYPE`.
pub fn print_methods(api: &Api<Value>, label: &str, id: &Value) {
    let methods = op(api, "list_methods", json!({"id": id, "script_only": true}));
    println!("{label}:");
    for m in methods["methods"].as_array().into_iter().flatten() {
        let params: Vec<String> = m["args"]
            .as_array()
            .into_iter()
            .flatten()
            .map(|a| {
                format!(
                    "{}: {}",
                    a["name"].as_str().unwrap_or("?"),
                    a["type"].as_str().unwrap_or("?")
                )
            })
            .collect();
        println!(
            "  {}({}) -> {}",
            m["name"].as_str().unwrap_or("?"),
            params.join(", "),
            m["return"]
        );
    }
}

/// True for a zero, empty or null value.
pub fn is_default(v: &Value) -> bool {
    match v {
        Value::Null => true,
        Value::Bool(b) => !b,
        Value::Number(n) => n.as_f64() == Some(0.0),
        Value::String(s) => s.is_empty() || s == "[]",
        Value::Array(a) => a.is_empty(),
        Value::Object(m) => {
            m.is_empty() || m.get("items") == Some(&json!(0)) || m.get("entries") == Some(&json!(0))
        }
    }
}

/// Run an op and return its result, failing the test on an error.
pub fn op(api: &Api<Value>, name: &str, args: Value) -> Value {
    let r = api
        .try_op(name, args)
        .unwrap_or_else(|e| panic!("{name}: {e}"));
    assert!(r.ok, "{name} failed: {:?}", r.error);
    r.result
}
