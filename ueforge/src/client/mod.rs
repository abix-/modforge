//! Blocking test client for `ueforge`-embedded mods.
//!
//! Activated by the `client` feature (set in your `[dev-dependencies]`
//! line: `ueforge = { path = "...", features = ["client"] }`).
//!
//! `Api<S>` mirrors the server's `OpResponse<S>` envelope from
//! [`crate::envelope`] and provides a `ureq`-backed POST loop for
//! tests to drive ops, snapshot state, and call UFunctions.
//!
//! Run pattern (after launching the game with the mod's debug
//! endpoint enabled):
//!
//! ```text
//! set MY_MOD_DEBUG_PORT=17171
//! cargo test --test foo. --test-threads=1 --nocapture
//! ```
//!
//! Tests share a single global game state, so always pass
//! `--test-threads=1`.

use std::marker::PhantomData;
use std::time::Duration;

use serde::de::DeserializeOwned;
use serde_json::{Value, json};

use crate::envelope::OpResponse;

pub mod diff;
pub mod perf;
pub mod research;
pub mod scenario;

/// Default request timeout. A test driving a slow PE-drain op
/// (e.g. one that waits for a frame to fire before the queue
/// drains) can exceed 5s; override per-Api with `with_timeout`.
pub const DEFAULT_TIMEOUT_SECS: u64 = 5;

pub struct Api<S> {
    port: u16,
    endpoint: String,
    agent: ureq::Agent,
    timeout: Duration,
    auth_token: Option<String>,
    _phantom: PhantomData<S>,
}

impl<S: DeserializeOwned> Api<S> {
    /// Connect at an explicit port. Default timeout
    /// `DEFAULT_TIMEOUT_SECS`. Chain `.with_timeout(...)` to
    /// override.
    pub fn at(port: u16, endpoint: impl Into<String>) -> Self {
        let timeout = Duration::from_secs(DEFAULT_TIMEOUT_SECS);
        let agent = ureq::AgentBuilder::new().timeout(timeout).build();
        Self {
            port,
            endpoint: endpoint.into(),
            agent,
            timeout,
            auth_token: None,
            _phantom: PhantomData,
        }
    }

    /// Override the per-request timeout.
    pub fn with_timeout(self, timeout: Duration) -> Self {
        let agent = ureq::AgentBuilder::new().timeout(timeout).build();
        Self {
            port: self.port,
            endpoint: self.endpoint,
            agent,
            timeout,
            auth_token: self.auth_token,
            _phantom: PhantomData,
        }
    }

    /// Attach a per-launch auth token. Sent as
    /// `X-Ueforge-Auth: <token>` on every request. Pair with
    /// `server::Config::auth_token` to gate the endpoint.
    pub fn with_auth(mut self, token: impl Into<String>) -> Self {
        self.auth_token = Some(token.into());
        self
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
    /// env var is missing.
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
    /// JSON errors. These are infrastructure failures, not test
    /// failures, and a panic surfaces them clearly. Use
    /// [`Self::try_op`] to handle them as `Err` instead.
    pub fn op(&self, op: &str, args: Value) -> OpResponse<S> {
        self.try_op(op, args).unwrap_or_else(|e| panic!("{e}"))
    }

    /// Result-returning variant of [`Self::op`]. Tests that want
    /// to assert on transport failures (e.g. "the listener
    /// disappeared after a `simulate_crash` op") can use this
    /// instead of letting the helper panic.
    pub fn try_op(&self, op: &str, args: Value) -> Result<OpResponse<S>, String> {
        let body = json!({ "op": op, "args": args });
        let url = format!("http://127.0.0.1:{}{}", self.port, self.endpoint);
        let mut req = self.agent.post(&url);
        if let Some(token) = &self.auth_token {
            req = req.set("X-Ueforge-Auth", token);
        }
        let res = req
            .send_json(body)
            .map_err(|e| format!("ueforge::client POST {url} failed: {e}"))?;
        res.into_json::<OpResponse<S>>()
            .map_err(|e| format!("ueforge::client: response not valid JSON: {e}"))
    }

    /// Run an op, assert `ok=true`, return the post-op state.
    pub fn op_ok(&self, op: &str, args: Value) -> S {
        let r = self.op(op, args);
        assert!(r.ok, "op {op} failed: {:?}", r.error);
        r.state
    }

    /// `op("snapshot", null)` shortcut.
    pub fn snapshot(&self) -> S {
        self.op("snapshot", Value::Null).state
    }

    /// Snapshot without typed deserialization. Returns the raw
    /// `state` `Value`. Use when generic helpers
    /// ([`crate::client::diff`]) want to read fields by JSON
    /// path without the per-mod `Snapshot` shape getting in the
    /// way. Cheaper than `snapshot` + `serde_json::to_value`
    /// round-trip.
    pub fn snapshot_value(&self) -> Value {
        let body = json!({ "op": "snapshot", "args": Value::Null });
        let url = format!("http://127.0.0.1:{}{}", self.port, self.endpoint);
        let mut req = self.agent.post(&url);
        if let Some(token) = &self.auth_token {
            req = req.set("X-Ueforge-Auth", token);
        }
        let res = req
            .send_json(body)
            .unwrap_or_else(|e| panic!("snapshot_value POST {url} failed: {e}"));
        let envelope: Value = res
            .into_json()
            .unwrap_or_else(|e| panic!("snapshot_value: response not JSON: {e}"));
        envelope.get("state").cloned().unwrap_or(Value::Null)
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

    /// Typed `call_ufunction`. Game-side parm struct is a
    /// `#[repr(C)] T`; this method serializes it via
    /// `parms::as_bytes`, calls the engine, decodes the
    /// post-call buffer back into `T`, and returns it (so OUT
    /// fields the engine wrote are visible).
    ///
    /// # Safety
    /// `T` MUST be a `#[repr(C)]` POD struct matching the
    /// UFunction's parm layout exactly.
    pub unsafe fn call_ufunction_typed<T: Copy>(
        &self,
        class: &str,
        function: &str,
        instance_selector: &str,
        parms: T,
    ) -> Result<(T, S), String> {
        let bytes = unsafe { crate::parms::as_bytes(&parms) };
        let (after, state) = self.call_ufunction(class, function, instance_selector, bytes)?;
        let out: T = unsafe { crate::parms::from_bytes(&after)? };
        Ok((out, state))
    }

    // ---- Standard RPG-op shortcuts ----------------------------
    //
    // Every mod that wires up `ueforge::rpg::ops` gets these for
    // free. The shortcuts call `op_ok` (panic on failure) and
    // return the post-op state. Use the raw `op` method if you
    // need to inspect failures.

    pub fn skill_spend(&self, id: &str, count: u32) -> S {
        self.op_ok("skill_spend", json!({"id": id, "count": count}))
    }

    pub fn skill_refund(&self, id: &str, count: u32) -> S {
        self.op_ok("skill_refund", json!({"id": id, "count": count}))
    }

    pub fn skill_toggle(&self, id: &str, enabled: bool) -> S {
        self.op_ok("skill_toggle", json!({"id": id, "enabled": enabled}))
    }

    pub fn set_skill_points(&self, count: u32) -> S {
        self.op_ok("set_skill_points", json!({"count": count}))
    }

    pub fn reload_slot(&self) -> S {
        self.op_ok("reload_slot", Value::Null)
    }

    /// Current `skill_levels.<id>` from the snapshot (raw value
    /// path). 0 if missing.
    pub fn skill_level(&self, id: &str) -> u32 {
        self.snapshot_value()
            .get("player_state")
            .and_then(|p| p.get("skill_levels"))
            .and_then(|m| m.get(id))
            .and_then(|n| n.as_u64())
            .map(|n| n as u32)
            .unwrap_or(0)
    }

    /// Current `skill_points` from the snapshot. 0 if missing.
    pub fn skill_points(&self) -> u32 {
        self.snapshot_value()
            .get("player_state")
            .and_then(|p| p.get("skill_points"))
            .and_then(|n| n.as_u64())
            .map(|n| n as u32)
            .unwrap_or(0)
    }

    pub fn port(&self) -> u16 {
        self.port
    }

    pub fn endpoint(&self) -> &str {
        &self.endpoint
    }
}
