//! `modforge-op`: send one op to a running mod's control plane and print
//! its result, for every mod (operator 2026-11-23: "We just need to be
//! able to send an op and do the things that we need to... this all needs
//! to be in ops, in the mod"). Built once; a mod change never rebuilds it.
//!
//! ```text
//! modforge-op [--port N] [--endpoint /debug] [--timeout S] <op> [json]
//! modforge-op scene.start '{"scene":"DA_MinotaurHumanFemaleSceneA"}'
//! ```
//!
//! Prints the op's result as JSON (pretty) and exits 0; with the op's
//! error, or no answer, prints it to stderr and exits 1. Port 31340,
//! endpoint /debug and 60 s by default (mine: the port and endpoint the
//! ueforge mods here listen on; no mod config names a port).

use std::process::ExitCode;
use std::time::Duration;

use modforge::client::Api;
use serde_json::Value;

const PORT: u16 = 31340;
const ENDPOINT: &str = "/debug";
const TIMEOUT_S: u64 = 60;

fn usage() -> ExitCode {
    eprintln!("usage: modforge-op [--port N] [--endpoint /debug] [--timeout S] <op> [json]");
    ExitCode::FAILURE
}

fn main() -> ExitCode {
    let mut port = PORT;
    let mut endpoint = ENDPOINT.to_owned();
    let mut timeout = TIMEOUT_S;
    let mut rest: Vec<String> = Vec::new();
    let mut args = std::env::args().skip(1);
    while let Some(a) = args.next() {
        match a.as_str() {
            "--port" => match args.next().and_then(|v| v.parse().ok()) {
                Some(p) => port = p,
                None => return usage(),
            },
            "--endpoint" => match args.next() {
                Some(e) => endpoint = e,
                None => return usage(),
            },
            "--timeout" => match args.next().and_then(|v| v.parse().ok()) {
                Some(t) => timeout = t,
                None => return usage(),
            },
            "-h" | "--help" => return usage(),
            _ => rest.push(a),
        }
    }
    let (op, json) = match rest.as_slice() {
        [op] => (op.as_str(), "{}"),
        [op, json] => (op.as_str(), json.as_str()),
        _ => return usage(),
    };
    let args: Value = match serde_json::from_str(json) {
        Ok(v) => v,
        Err(e) => {
            eprintln!("modforge-op: the args are not JSON: {e}");
            return ExitCode::FAILURE;
        }
    };
    let api: Api<Value> = Api::at(port, endpoint).with_timeout(Duration::from_secs(timeout));
    match api.try_op(op, args) {
        Ok(r) if r.ok => {
            println!(
                "{}",
                serde_json::to_string_pretty(&r.result).unwrap_or_else(|_| r.result.to_string())
            );
            ExitCode::SUCCESS
        }
        Ok(r) => {
            eprintln!("{op}: {}", r.error.unwrap_or_else(|| "failed, no error given".into()));
            ExitCode::FAILURE
        }
        Err(e) => {
            eprintln!("{op}: {e}");
            ExitCode::FAILURE
        }
    }
}
