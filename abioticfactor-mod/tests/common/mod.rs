//! Shared helpers for the abioticfactor-mod research tests.
//!
//! Abiotic Factor is UE 5.4.4 with AF-UE4SS. The control plane
//! lives on port 31260, endpoint /debug.
#![allow(dead_code, unused_imports)]

use serde_json::{json, Value};
use modforge::client::Api;

pub fn api() -> Api<Value> {
    let port = std::env::var("ABIOTICFACTOR_MOD_PORT")
        .ok()
        .and_then(|p| p.parse().ok())
        .unwrap_or(31260);
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
