//! HTTP control plane. Mirrors grounded2-rpg's pattern but
//! starts empty — fields and ops grow as research lands.

use serde::Serialize;
use serde_json::Value as Json;

use ueforge::envelope::{OpResponse as UespyResponse, parse_request};

pub fn spawn(port: u16) {
    ueforge::spawn(
        ueforge::Config {
            port,
            endpoint: "/debug",
            thread_name: "ows-tweaks-debug",
            auth_token: None,
        },
        |body| {
            let resp = handle(body);
            serde_json::to_vec(&resp).unwrap_or_else(|_| b"{}".to_vec())
        },
        |msg| ueforge::log::log(format_args!("{msg}")),
    );
}

/// Game-specific snapshot fields. Empty for now; tests grow this
/// as they need observables.
#[derive(Serialize, Default)]
pub struct Snapshot {
    pub offsets_known: bool,
}

type OpResponse = UespyResponse<Snapshot>;

fn build_snapshot() -> Snapshot {
    Snapshot {
        offsets_known: ueforge::ue::try_runtime().is_some(),
    }
}

fn handle(body: &str) -> OpResponse {
    let (op, args) = match parse_request(body) {
        Ok(v) => v,
        Err(e) => return error_response("<parse-error>", e),
    };

    // Game-specific ops first (snapshot is the only one tweaks
    // owns today). Then ueforge's built-in op set covers
    // read/write_bytes, walk_class, fname_to_string, scan_*,
    // freeze*. Add tweaks-specific ops as new match arms.
    match op.as_str() {
        "snapshot" => return ok_response(&op, Json::Null),
        "" => {
            return error_response(
                "<missing>",
                "missing 'op' field; supported: snapshot + every ueforge built-in",
            );
        }
        _ => {}
    }
    if let Some(r) = ueforge::ops::handle_builtin(&op, &args, resolve_instance) {
        return to_response(&op, r);
    }
    error_response(&op, format!("unknown op '{}'", op))
}

fn ok_response(op: &str, result: Json) -> OpResponse {
    OpResponse::ok(op, result, build_snapshot())
}

fn to_response(op: &str, r: Result<Json, String>) -> OpResponse {
    OpResponse::from_result(op, r, build_snapshot())
}

fn error_response(op: &str, err: impl Into<String>) -> OpResponse {
    OpResponse::err(op, err, build_snapshot())
}

fn resolve_instance(s: &str) -> Result<&'static ueforge::ue::UObject, String> {
    if let Some(r) = ueforge::selector::resolve_generic(s) {
        return r;
    }
    Err(format!(
        "unknown selector '{s}'. supported: addr:0x<hex>, first_class:<Name>, \
         class:<Name>, singleton:<Name>"
    ))
}
