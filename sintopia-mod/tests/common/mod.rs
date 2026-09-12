//! Shared helpers for the sintopia-mod research tests.
//!
//! Sintopia is UE 5.2.1 with stock UE4SS. The control plane
//! lives on port 31270, endpoint /debug.
#![allow(dead_code, unused_imports)]

use modforge::client::Api;
use serde_json::{json, Value};

pub const GAME_DIR: &str = "C:/Games/Steam/steamapps/common/Sintopia";
pub const UE4SS_LOG: &str =
    "C:/Games/Steam/steamapps/common/Sintopia/Sintopia/Binaries/Win64/ue4ss/UE4SS.log";

pub fn api() -> Api<Value> {
    let port = std::env::var("SINTOPIA_MOD_PORT")
        .ok()
        .and_then(|p| p.parse().ok())
        .unwrap_or(31270);
    Api::at(port, "/debug").with_timeout(std::time::Duration::from_secs(30))
}

pub fn ping_or_skip(api: &Api<Value>) -> Option<()> {
    match api.try_op("list_ops", json!({})) {
        Ok(r) if r.ok => Some(()),
        Ok(_) => {
            eprintln!("SKIP: control plane answered but list_ops failed");
            None
        }
        Err(e) => {
            eprintln!(
                "SKIP: no control plane answering ({e}); launch the game with the mod loaded"
            );
            None
        }
    }
}
