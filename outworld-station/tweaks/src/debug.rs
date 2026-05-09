//! HTTP control plane. Mirrors better-backpack's pattern but
//! starts empty — fields and ops grow as research lands.

use serde::Serialize;
use serde_json::Value as Json;

use uespy::envelope::{OpResponse as UespyResponse, parse_request};

pub fn spawn(port: u16) {
    uespy::spawn(
        uespy::Config {
            port,
            endpoint: "/debug",
            thread_name: "ows-tweaks-debug",
        },
        |body| {
            let resp = handle(body);
            serde_json::to_vec(&resp).unwrap_or_else(|_| b"{}".to_vec())
        },
        |msg| uespy::log::log(format_args!("{msg}")),
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
        offsets_known: uespy::ue::try_runtime().is_some(),
    }
}

fn handle(body: &str) -> OpResponse {
    let (op, args) = match parse_request(body) {
        Ok(v) => v,
        Err(e) => return error_response("<parse-error>", e),
    };

    match op.as_str() {
        "snapshot" => ok_response(&op, Json::Null),
        "read_bytes" => to_response(&op, uespy::ops::read_bytes(&args, resolve_instance)),
        "write_bytes" => to_response(&op, uespy::ops::write_bytes(&args, resolve_instance)),
        "walk_class" => to_response(&op, uespy::ops::walk_class(&args)),
        "" => error_response(
            "<missing>",
            "missing 'op' field; supported: snapshot, read_bytes, write_bytes, walk_class",
        ),
        other => error_response(other, format!("unknown op '{other}'")),
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

fn resolve_instance(s: &str) -> Result<&'static uespy::ue::UObject, String> {
    if let Some(r) = uespy::selector::resolve_generic(s) {
        return r;
    }
    Err(format!(
        "unknown selector '{s}'. supported: addr:0x<hex>, first_class:<Name>, \
         class:<Name>, singleton:<Name>"
    ))
}
