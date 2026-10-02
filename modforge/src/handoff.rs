//! Plain data one DLL generation leaves for the next across a hot
//! reload. Each generation has its own statics, so anything a mod
//! must carry over (ids of objects it kept, counts, flags) goes
//! through here: the old generation `put`s it at shutdown, the new
//! one `take`s it at init.
//!
//! Stored in the process environment, which belongs to the process
//! and outlives any DLL. Prior art: nginx hands its listening sockets
//! to the new binary during a binary upgrade through the `NGINX`
//! environment variable.
//!
//! Engine objects are not data: on Unity keep them with
//! `unityforge::mono::keep_through_reload` and hand over the ids.

use serde_json::Value as Json;

fn var(key: &str) -> String {
    format!("MODFORGE_HANDOFF_{key}")
}

/// Leave `value` under `key` for the next generation (replaces any
/// earlier value).
pub fn put(key: &str, value: &Json) {
    // SAFETY: Windows `SetEnvironmentVariableW` is thread-safe; the
    // only readers are this module's `take` and the OS.
    unsafe { std::env::set_var(var(key), value.to_string()) };
}

/// Take what the previous generation left under `key`, once: the
/// value is removed so a later generation does not take it again.
pub fn take(key: &str) -> Option<Json> {
    let name = var(key);
    let s = std::env::var(&name).ok()?;
    // SAFETY: as in `put`.
    unsafe { std::env::remove_var(&name) };
    serde_json::from_str(&s).ok()
}
