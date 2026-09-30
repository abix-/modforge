//! Smoke test: the injected DLL answers on the control plane and has
//! registered the reload protocol.
//!
//! ```text
//! JA3_DEBUG_PORT=33079 k3sc cargo-lock test -p jaggedalliance3-mod --test smoke -- --test-threads=1 --nocapture
//! ```

mod common;
use common::api_or_skip;
use serde_json::json;

#[test]
fn ping() {
    let Some(api) = api_or_skip() else { return };
    let r = api.op("ping", json!({}));
    assert!(r.ok, "ping failed: {:?}", r.error);
    assert_eq!(r.result, json!("pong"));
}

#[test]
fn list_ops_includes_reload_protocol() {
    let Some(api) = api_or_skip() else { return };
    let r = api.op("list_ops", json!({}));
    assert!(r.ok, "list_ops failed: {:?}", r.error);
    let names: Vec<String> = r.result["ops"]
        .as_array()
        .cloned()
        .unwrap_or_default()
        .iter()
        .filter_map(|op| op["name"].as_str().map(str::to_string))
        .collect();
    println!("{} ops registered: {names:?}", names.len());
    assert!(names.iter().any(|n| n == "_shutdown"), "no _shutdown op");
}
