//! Shared helpers for the obenseuer-mod research tests: the unityforge
//! client on the mod's port. New research tests reuse them.
#![allow(dead_code, unused_imports)]

pub use unityforge::client::{find_instances, handle_of, parse_vec3, ping_or_skip};

use serde_json::Value;
use unityforge::client::Api;

pub fn api() -> Api<Value> {
    let port = std::env::var("OBENSEUER_MOD_PORT").ok().and_then(|p| p.parse().ok()).unwrap_or(17175);
    Api::at(port, "/op")
}

/// A component's object and its parents from the top down: "Top / ... /
/// Object". Releases every handle it takes; not the component's.
pub fn top_path(api: &Api<Value>, component: i64) -> String {
    let call = |h: i64, m: &str| api.op("invoke_method", serde_json::json!({"handle": h, "method": m, "args": []})).result;
    let mut names = Vec::new();
    let mut t = handle_of(&call(component, "get_transform"));
    while let Some(h) = t {
        names.push(call(h, "get_name").as_str().unwrap_or("?").to_string());
        let parent = handle_of(&call(h, "get_parent"));
        api.op("release_handle", serde_json::json!({"handle": h}));
        t = parent;
    }
    names.reverse();
    names.join(" / ")
}
