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
    // Bumped from the 5s default: ops that run a fresh GObjects
    // walk (discover_*` with `refresh=true`, struct_detail) take
    // multiple seconds on 175K-object games.
    ueforge::client::Api::try_connect(ENV_PORT, "/debug")
        .map(|a| a.with_timeout(std::time::Duration::from_secs(60)))
}

pub fn require_api() -> Api {
    ueforge::client::Api::require(ENV_PORT, "/debug")
        .with_timeout(std::time::Duration::from_secs(60))
}

pub fn op(api: &Api, op_name: &str, args: Value) -> ueforge::OpResponse<Snapshot> {
    api.op(op_name, args)
}
