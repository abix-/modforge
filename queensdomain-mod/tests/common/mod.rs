//! Shared helpers for the queensdomain-mod research tests.
//!
//! Queens' Domain is UE 4.27 with UE4SS experimental-latest. The
//! control plane lives on port 31310, endpoint /debug.
#![allow(dead_code, unused_imports)]

use modforge::client::Api;
use serde_json::{Value, json};

pub fn api() -> Api<Value> {
    let port = std::env::var("QUEENSDOMAIN_MOD_PORT")
        .ok()
        .and_then(|p| p.parse().ok())
        .unwrap_or(31310);
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
