//! Shared helpers for the mechabellum-mod research tests.
//!
//! The control plane is generic (handle chaining): the unityforge
//! client helpers are the whole research toolkit. New research
//! tests reuse them; do not copy them into a test file.
//!
//! Each --test target compiles this module separately and no
//! target uses every helper, so dead_code is expected here.
#![allow(dead_code, unused_imports)]

pub use unityforge::client::{count_of, handle_of, ping_or_skip};

use serde_json::Value;
use unityforge::client::Api;

pub const GAME_DIR: &str = "C:/Games/Steam/steamapps/common/Mechabellum";
pub const MELON_LOG: &str = "C:/Games/Steam/steamapps/common/Mechabellum/MelonLoader/Latest.log";

pub fn api() -> Api<Value> {
    let port = std::env::var("MECHABELLUM_MOD_PORT")
        .ok()
        .and_then(|p| p.parse().ok())
        .unwrap_or(17184);
    Api::at(port, "/op")
}
