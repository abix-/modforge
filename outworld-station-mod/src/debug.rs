//! HTTP control plane. Mirrors grounded2-mod's pattern but
//! starts empty. Fields and ops grow as research lands.

use serde::Serialize;
use serde_json::Value as Json;

use ueforge::envelope::{OpResponse as UespyResponse, parse_request};

/// Register every ows-tweaks op + selector into the workspace
/// registries. Called once before the HTTP listener starts.
fn register_ops() {
    ueforge::selector::register_builtins();
    // No game-specific selectors yet for ows-tweaks.
    ueforge::ops::register_builtins();
    ueforge::ops::register_with_resolver(ueforge::selector::resolve);
}

pub fn spawn(port: u16) {
    register_ops();
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

    if op == "snapshot" {
        return ok_response(&op, Json::Null);
    }
    if op.is_empty() {
        return error_response(
            "<missing>",
            "missing 'op' field; try op:'list_ops' for the catalog",
        );
    }
    match ueforge::ops::OP_REGISTRY.dispatch(&op, &args) {
        Some(r) => to_response(&op, r),
        None => error_response(
            &op,
            format!("unknown op '{op}'; try op:'list_ops' for the catalog"),
        ),
    }
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

