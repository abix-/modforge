//! Shared helpers for the dungeonbound-mod research tests. The game
//! must be running with the mod deployed; tests skip otherwise.
#![allow(dead_code)]

use modforge::client::Api;
use serde_json::{Value, json};

pub fn api() -> Api<Value> {
    Api::at(31330, "/op").with_timeout(std::time::Duration::from_secs(15))
}

/// The control plane, or None (and a SKIP line) when the game is not up.
pub fn api_or_skip() -> Option<Api<Value>> {
    let api = api();
    match api.try_op("ping", json!({})) {
        Ok(r) if r.ok => Some(api),
        Ok(r) => {
            eprintln!("SKIP: ping failed: {:?}", r.error);
            None
        }
        Err(e) => {
            eprintln!(
                "SKIP: no control plane on 31330 ({e}); launch the game with the mod deployed"
            );
            None
        }
    }
}

/// Run an op and return its result, failing the test on an error.
pub fn op(api: &Api<Value>, name: &str, args: Value) -> Value {
    let r = api
        .try_op(name, args)
        .unwrap_or_else(|e| panic!("{name}: {e}"));
    assert!(r.ok, "{name} failed: {:?}", r.error);
    r.result
}
