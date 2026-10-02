//! Shared helpers for the sevendaystodie-mod research tests.
//!
//! The control plane is generic (handle chaining): the unityforge
//! client helpers are the whole research toolkit. New research
//! tests reuse them; do not copy them into a test file.
//!
//! Each --test target compiles this module separately and no
//! target uses every helper, so dead_code is expected here.
#![allow(dead_code, unused_imports)]

pub use unityforge::client::{fields, first_handle, handle_of, ping_or_skip};

use serde_json::{Value, json};
use unityforge::client::Api;

pub fn api() -> Api<Value> {
    let port = std::env::var("SEVENDAYSTODIE_MOD_PORT")
        .ok()
        .and_then(|p| p.parse().ok())
        .unwrap_or(17182);
    Api::at(port, "/op")
}

/// `read_field` that returns the handle of an object-valued field.
pub fn field_handle(api: &Api<Value>, handle: i64, field: &str) -> Option<i64> {
    let r = api.op("read_field", json!({"handle": handle, "field": field}));
    let h = handle_of(&r.result);
    if h.is_none() {
        println!("read_field {field}: {} {:?}", r.result, r.error);
    }
    h
}

/// `read_field` of a plain value (number, bool, string).
pub fn field_value(api: &Api<Value>, handle: i64, field: &str) -> Value {
    let r = api.op("read_field", json!({"handle": handle, "field": field}));
    if !r.ok {
        println!("read_field {field}: {:?}", r.error);
    }
    r.result
}

/// `invoke_method` returning the raw result (a value, or {"handle": n}).
pub fn call(api: &Api<Value>, handle: i64, method: &str, args: Value) -> Value {
    let r = api.op(
        "invoke_method",
        json!({"handle": handle, "method": method, "args": args}),
    );
    if !r.ok {
        println!("invoke_method {method}: {:?}", r.error);
    }
    r.result
}
