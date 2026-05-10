//! Shared test helpers. Connects to a live OWS Tweaks instance
//! over `/debug`. Set `OWS_DEBUG_PORT=17172` (matching
//! `src/lib.rs::on_unreal_init`) before running tests.

#![allow(dead_code)]

use serde::Deserialize;
use serde_json::Value;

const ENV_PORT: &str = "OWS_DEBUG_PORT";

#[derive(Debug, Deserialize, Default)]
pub struct Snapshot {
    #[serde(default)]
    pub offsets_known: bool,
}

pub type Api = ueforge::client::Api<Snapshot>;

pub fn try_api() -> Option<Api> {
    ueforge::client::Api::try_connect(ENV_PORT, "/debug")
}

pub fn require_api() -> Api {
    ueforge::client::Api::require(ENV_PORT, "/debug")
}

pub fn op(api: &Api, op_name: &str, args: Value) -> ueforge::OpResponse<Snapshot> {
    api.op(op_name, args)
}
