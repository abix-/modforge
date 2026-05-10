//! Op request / response envelope.
//!
//! Wire shape:
//! ```json
//! request:  { "op": "<name>", "args": {...} }
//! response: { "ok": bool, "op": "<echoed>", "error": null|string,
//!             "result": <op-specific>, "state": <snapshot> }
//! ```
//!
//! `OpResponse` is generic over `S: Serialize` so each game crate
//! supplies its own snapshot type. The envelope stays uniform; the
//! payload is whatever that game wants to expose.

use serde::{Deserialize, Serialize};
use serde_json::Value as Json;

#[derive(Serialize, Deserialize)]
pub struct OpResponse<S> {
    pub ok: bool,
    pub op: String,
    pub error: Option<String>,
    #[serde(default = "default_result")]
    pub result: Json,
    pub state: S,
}

fn default_result() -> Json {
    Json::Null
}

impl<S> OpResponse<S> {
    pub fn ok(op: &str, result: Json, state: S) -> Self {
        Self {
            ok: true,
            op: op.to_string(),
            error: None,
            result,
            state,
        }
    }

    pub fn err(op: &str, msg: impl Into<String>, state: S) -> Self {
        Self {
            ok: false,
            op: op.to_string(),
            error: Some(msg.into()),
            result: Json::Null,
            state,
        }
    }

    pub fn from_result(op: &str, r: Result<Json, String>, state: S) -> Self {
        match r {
            Ok(v) => Self::ok(op, v, state),
            Err(e) => Self::err(op, e, state),
        }
    }
}

/// Parse a request body into `(op, args)`. `args` defaults to `Null`
/// if missing. The op string is empty when the field is absent so
/// callers can produce a uniform "missing op" error.
pub fn parse_request(body: &str) -> Result<(String, Json), String> {
    let v: Json = serde_json::from_str(body).map_err(|e| format!("body json: {e}"))?;
    let op = v.get("op").and_then(Json::as_str).unwrap_or("").to_string();
    let args = v.get("args").cloned().unwrap_or(Json::Null);
    Ok((op, args))
}
