//! Tiny `Json` arg helpers used by op handlers. Pure — no I/O, no
//! UE deps. Lifted verbatim from `grounded2-rpg/src/debug.rs`.

use serde_json::Value as Json;

pub fn arg_str<'a>(args: &'a Json, name: &str) -> Result<&'a str, String> {
    args.get(name)
        .and_then(Json::as_str)
        .ok_or_else(|| format!("missing arg '{name}' (string)"))
}

pub fn arg_u64(args: &Json, name: &str, default: Option<u64>) -> Result<u64, String> {
    match args.get(name).and_then(Json::as_u64) {
        Some(v) => Ok(v),
        None => default.ok_or_else(|| format!("missing arg '{name}' (u64)")),
    }
}

pub fn arg_bool(args: &Json, name: &str) -> Result<bool, String> {
    args.get(name)
        .and_then(Json::as_bool)
        .ok_or_else(|| format!("missing arg '{name}' (bool)"))
}

pub fn arg_f64(args: &Json, name: &str) -> Result<f64, String> {
    args.get(name)
        .and_then(Json::as_f64)
        .ok_or_else(|| format!("missing arg '{name}' (number)"))
}
