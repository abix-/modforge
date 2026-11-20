//! Shared helpers for the pureskill-mod research tests.
//!
//! The unityforge client helpers are the whole research toolkit.
//! Each --test target compiles this module separately and no
//! target uses every helper, so dead_code is expected here.
#![allow(dead_code, unused_imports)]

pub use unityforge::client::{
    count_of, dump_sequence, field_exists, fields, find_instances, first_handle, handle_of,
    parse_vec3, ping_or_skip, print_declared_methods,
};

use serde_json::Value;
use unityforge::client::Api;

pub const GAME_DIR: &str = "C:/Games/Steam/steamapps/common/Pure Skill Demo";
pub const BEPINEX_LOG: &str =
    "C:/Games/Steam/steamapps/common/Pure Skill Demo/BepInEx/LogOutput.log";

pub fn api() -> Api<Value> {
    let port = std::env::var("PURESKILL_MOD_PORT")
        .ok()
        .and_then(|p| p.parse().ok())
        .unwrap_or(17187);
    Api::at(port, "/op")
}
