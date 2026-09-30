//! Shared helpers for the graveyardkeeper2-mod research tests.
//!
//! Each --test target compiles this module separately and no
//! target uses every helper, so dead_code is expected here.
#![allow(dead_code, unused_imports)]

pub use unityforge::client::{
    count_of, dump_sequence, field_exists, fields, find_instances, first_handle, handle_of,
    ping_or_skip, print_declared_methods,
};

use serde_json::Value;
use unityforge::client::Api;

pub fn api() -> Api<Value> {
    let port = std::env::var("GRAVEYARDKEEPER2_MOD_PORT")
        .ok()
        .and_then(|p| p.parse().ok())
        .unwrap_or(17178);
    Api::at(port, "/op")
}
