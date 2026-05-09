//! uespy-client: shared blocking test client for `uespy`-embedded mods.
//!
//! Mirrors the wire envelope (`OpResponse<S>`) and provides a tiny
//! `Api<S>` wrapper over `ureq`. Game-specific test crates supply
//! their own `Snapshot` type and parameterize over it:
//!
//! ```ignore
//! use uespy_client::Api;
//! type GameApi = Api<MySnapshot>;
//! ```
//!
//! Run pattern (after launching the game with the mod's debug
//! endpoint enabled):
//!
//! ```text
//! set BBP_DEBUG_PORT=17171
//! cargo test --test foo -- --test-threads=1 --nocapture
//! ```
//!
//! Tests share a single global game state, so always pass
//! `--test-threads=1`.

use std::marker::PhantomData;
use std::time::Duration;

use serde::Deserialize;
use serde::de::DeserializeOwned;
use serde_json::{Value, json};

pub mod hex;
pub mod parms;
pub mod perf;

pub use serde_json;

/// Wire shape mirroring `uespy::OpResponse<S>` on the server side.
#[derive(Debug, Deserialize)]
pub struct OpResponse<S> {
    pub ok: bool,
    pub op: String,
    pub error: Option<String>,
    #[serde(default = "default_value")]
    pub result: Value,
    pub state: S,
}

fn default_value() -> Value {
    Value::Null
}

/// Default request timeout. A test driving a slow PE-drain op
/// (e.g. one that waits for a frame to fire before the queue
/// drains) can exceed 5s; override per-Api with `with_timeout`.
pub const DEFAULT_TIMEOUT_SECS: u64 = 5;

pub struct Api<S> {
    port: u16,
    endpoint: String,
    agent: ureq::Agent,
    timeout: Duration,
    _phantom: PhantomData<S>,
}

impl<S: DeserializeOwned> Api<S> {
    /// Connect at an explicit port. Default timeout
    /// `DEFAULT_TIMEOUT_SECS` — chain `.with_timeout(...)` to
    /// override.
    pub fn at(port: u16, endpoint: impl Into<String>) -> Self {
        let timeout = Duration::from_secs(DEFAULT_TIMEOUT_SECS);
        let agent = ureq::AgentBuilder::new().timeout(timeout).build();
        Self {
            port,
            endpoint: endpoint.into(),
            agent,
            timeout,
            _phantom: PhantomData,
        }
    }

    /// Override the per-request timeout. Returns a fresh `Api` so
    /// it composes with `try_connect` / `at` / `require`.
    pub fn with_timeout(self, timeout: Duration) -> Self {
        let agent = ureq::AgentBuilder::new().timeout(timeout).build();
        Self {
            port: self.port,
            endpoint: self.endpoint,
            agent,
            timeout,
            _phantom: PhantomData,
        }
    }

    pub fn timeout(&self) -> Duration {
        self.timeout
    }

    /// Connect using a port from the named environment variable.
    /// Returns `None` if the env var is unset or unparseable, so
    /// tests can skip cleanly when the mod isn't running.
    pub fn try_connect(env_var: &str, endpoint: impl Into<String>) -> Option<Self> {
        let port = std::env::var(env_var).ok()?.parse::<u16>().ok()?;
        Some(Self::at(port, endpoint))
    }

    /// Like `try_connect` but panics with a clear message when the
    /// env var is missing. Use when the test absolutely requires
    /// the endpoint and you want a loud failure on misconfig.
    pub fn require(env_var: &str, endpoint: impl Into<String>) -> Self {
        let endpoint = endpoint.into();
        Self::try_connect(env_var, endpoint.clone()).unwrap_or_else(|| {
            panic!(
                "{env_var} not set. Launch the game with the mod's debug \
                 endpoint enabled, then export {env_var}=<port> before \
                 running tests."
            )
        })
    }

    /// POST a request, parse the response. Panics on transport or
    /// JSON errors — these are infrastructure failures, not test
    /// failures, and a panic surfaces them clearly.
    pub fn op(&self, op: &str, args: Value) -> OpResponse<S> {
        let body = json!({ "op": op, "args": args });
        let url = format!("http://127.0.0.1:{}{}", self.port, self.endpoint);
        let res = self
            .agent
            .post(&url)
            .send_json(body)
            .unwrap_or_else(|e| panic!("uespy-client POST {url} failed: {e}"));
        res.into_json::<OpResponse<S>>()
            .expect("uespy-client: response was not valid JSON")
    }

    /// Run an op, assert `ok=true`, return the post-op state.
    /// Use when the op is expected to succeed and the test only
    /// cares about the resulting state.
    pub fn op_ok(&self, op: &str, args: Value) -> S {
        let r = self.op(op, args);
        assert!(r.ok, "op {op} failed: {:?}", r.error);
        r.state
    }

    /// `op("snapshot", null)` shortcut. Returns just the state.
    pub fn snapshot(&self) -> S {
        self.op("snapshot", Value::Null).state
    }

    /// Generic UFunction call. The endpoint exposes one `call` op;
    /// every UE-side experiment goes through it. Tests build the
    /// parm bytes from `#[repr(C)]` structs that mirror the SDK,
    /// hex-encode, send, decode the post-call buffer.
    pub fn call_ufunction(
        &self,
        class: &str,
        function: &str,
        instance_selector: &str,
        parms_bytes: &[u8],
    ) -> Result<(Vec<u8>, S), String> {
        let parms_hex = hex::encode(parms_bytes);
        let r = self.op(
            "call",
            json!({
                "class": class,
                "function": function,
                "instance_selector": instance_selector,
                "parms_hex": parms_hex,
            }),
        );
        if !r.ok {
            return Err(r.error.unwrap_or_else(|| "<no error>".into()));
        }
        let after_hex = r
            .result
            .get("parms_hex_after")
            .and_then(|v| v.as_str())
            .ok_or_else(|| "no parms_hex_after in result".to_string())?;
        let after = hex::decode(after_hex).map_err(|e| format!("bad hex: {e}"))?;
        Ok((after, r.state))
    }

    pub fn port(&self) -> u16 {
        self.port
    }

    pub fn endpoint(&self) -> &str {
        &self.endpoint
    }
}
