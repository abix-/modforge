//! Shared helpers for the wanderburg-mod research tests.
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

pub const GAME_DIR: &str = "C:/Games/Steam/steamapps/common/Wanderburg Game";
pub const MELON_LOG: &str =
    "C:/Games/Steam/steamapps/common/Wanderburg Game/MelonLoader/Latest.log";

pub fn api() -> Api<Value> {
    let port = std::env::var("WANDERBURG_MOD_PORT")
        .ok()
        .and_then(|p| p.parse().ok())
        .unwrap_or(17177);
    Api::at(port, "/op")
}
