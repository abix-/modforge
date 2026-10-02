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
