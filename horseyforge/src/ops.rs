//! Horsey-specific ops registered on modforge's global op
//! registry. Every op here is a closure that reads or writes the
//! game state via `gamestate.rs` / `horse.rs`.
//!
//! Wire format: requests are JSON `{"op":"name","args":{...}}`,
//! posted to `127.0.0.1:33077/op` with the auth header
//! `X-Ueforge-Auth: <token>` (token is in `horseyforge.auth`).
//!
//! Each op returns a `Json` result; the envelope around it
//! (`{"ok":..., "op":..., "result":..., "state":...}`) is added
//! by lib.rs's handler.

use modforge::ops::{OpDef, OP_REGISTRY};
use serde_json::{json, Value as Json};

use crate::fatigue;
use crate::gamestate;
use crate::horse;

/// Register every Horsey op on the modforge global registry.
/// Called once from the worker thread at DLL init.
pub fn register_all() {
    OP_REGISTRY.register_many(vec![
        OpDef::new("ping", "Liveness check", "", |_| Ok(json!("pong"))),

        // ===== Hot-reload protocol =====
        //
        // The injector (`horseyforge-inject.exe --reload`) issues this op
        // before remotely calling FreeLibrary on our HMODULE. After the
        // op returns we drop every SpawnHandle in modforge's registry
        // so the HTTP listener thread joins and releases port 33077.
        //
        // We schedule the actual shutdown on a fresh thread so we can
        // RETURN the success response to the client first. If we
        // shut the server down before returning, the client never
        // sees the OK and may panic.
        OpDef::new(
            "_shutdown",
            "Stop the HTTP server. Used by the injector before unloading the DLL for hot-reload.",
            "",
            |_| {
                std::thread::Builder::new()
                    .name("horseyforge-shutdown".into())
                    .spawn(|| {
                        // Tiny delay so the in-flight HTTP response
                        // has time to flush to the client socket.
                        std::thread::sleep(std::time::Duration::from_millis(100));
                        modforge::log!("horseyforge: _shutdown -> dropping server");
                        modforge::server::shutdown_all();
                    })
                    .ok();
                Ok(json!({"shutting_down": true}))
            },
        ),

        OpDef::new(
            "list_ops",
            "List every op registered on the global registry.",
            "",
            |_| Ok(OP_REGISTRY.list_json()),
        ),

        // ===== GameState reads =====
        OpDef::new(
            "game.read",
            "Read the high-level game state snapshot.",
            "",
            |_| {
                Ok(json!({
                    "money": gamestate::money(),
                    "year": gamestate::year(),
                    "sleeps": gamestate::sleeps(),
                    "races": gamestate::races(),
                    "horse_count": gamestate::horse_count(),
                    "world_loaded": gamestate::ptr() != 0,
                    "no_tire": gamestate::no_tire(),
                    "debug_mode": gamestate::debug_mode(),
                }))
            },
        ),

        // ===== Money cheats =====
        OpDef::new(
            "game.money.get",
            "Read current money.",
            "",
            |_| Ok(json!({"money": gamestate::money()})),
        ),
        OpDef::new(
            "game.money.set",
            "Set money to a specific value.",
            "{value: u32}",
            |args| {
                let v = args_u32(args, "value")?;
                let ok = gamestate::set_money(v);
                Ok(json!({"set": ok, "money": gamestate::money()}))
            },
        ),
        OpDef::new(
            "game.money.add",
            "Add to money (negative subtracts; saturates at 0).",
            "{value: i32}",
            |args| {
                let delta = args_i32(args, "value")?;
                let current = gamestate::money().unwrap_or(0) as i64;
                let new_val = (current + delta as i64).max(0).min(u32::MAX as i64) as u32;
                let ok = gamestate::set_money(new_val);
                Ok(json!({"set": ok, "money": gamestate::money()}))
            },
        ),

        // ===== Year =====
        OpDef::new(
            "game.year.get",
            "Read current year (0-indexed; displayed +1 in-game).",
            "",
            |_| Ok(json!({"year": gamestate::year()})),
        ),
        OpDef::new(
            "game.year.set",
            "Set the year.",
            "{value: u32}",
            |args| {
                let v = args_u32(args, "value")?;
                let ok = gamestate::set_year(v);
                Ok(json!({"set": ok, "year": gamestate::year()}))
            },
        ),

        // ===== Cheats =====
        OpDef::new(
            "cheats.no_tire.get",
            "Read the No Tire toggle (true = fatigue disabled).",
            "",
            |_| Ok(json!({"no_tire": gamestate::no_tire()})),
        ),
        OpDef::new(
            "cheats.no_tire.set",
            "Enable / disable the GAME's built-in No Tire cheat. Note: \
this zeroes BOTH tired flags so the sleep gate breaks. Prefer \
fatigue.suppressor.set which only zeroes the race-eligibility flag.",
            "{enabled: bool}",
            |args| {
                let v = args_bool(args, "enabled")?;
                gamestate::set_no_tire(v);
                Ok(json!({"no_tire": gamestate::no_tire()}))
            },
        ),
        OpDef::new(
            "fatigue.suppressor.get",
            "Read whether horseyforge's split-flag fatigue suppressor is on.",
            "",
            |_| Ok(json!({"enabled": fatigue::is_enabled()})),
        ),
        OpDef::new(
            "fatigue.suppressor.set",
            "Toggle horseyforge's split-flag fatigue suppressor. On = race \
gate passes (no tire), sleep gate still works.",
            "{enabled: bool}",
            |args| {
                let v = args_bool(args, "enabled")?;
                fatigue::set_enabled(v);
                Ok(json!({"enabled": fatigue::is_enabled()}))
            },
        ),
        OpDef::new(
            "cheats.debug_mode.get",
            "Read the debug-mode-active flag.",
            "",
            |_| Ok(json!({"debug_mode": gamestate::debug_mode()})),
        ),
        OpDef::new(
            "cheats.debug_mode.set",
            "Force debug mode on / off (skips the 'type \"debug\" in pause menu' unlock).",
            "{enabled: bool}",
            |args| {
                let v = args_bool(args, "enabled")?;
                gamestate::set_debug_mode(v);
                Ok(json!({"debug_mode": gamestate::debug_mode()}))
            },
        ),

        // ===== Horse roster =====
        OpDef::new(
            "horses.count",
            "Number of horses in the roster (36-byte records).",
            "",
            |_| Ok(json!({"count": gamestate::horse_count()})),
        ),
        OpDef::new(
            "horses.roster_addr",
            "Memory address of the roster entry at index `i`.",
            "{index: usize}",
            |args| {
                let i = args_usize(args, "index")?;
                let p = gamestate::horse_roster_entry(i);
                Ok(json!({"address": p.map(|a| format!("0x{:x}", a))}))
            },
        ),
        OpDef::new(
            "horses.live",
            "Walk gamestate+0x130/+0x138 and return every live horse with its full state. Powers the roster UI.",
            "",
            |_| {
                let n = gamestate::live_horse_count();
                let mut out = Vec::with_capacity(n);
                for i in 0..n {
                    let Some(h) = gamestate::live_horse_ptr(i) else { continue };
                    if h == 0 { continue; }
                    out.push(json!({
                        "index": i,
                        "address": format!("0x{:x}", h),
                        "age": horse::age(h),
                        "max_age": horse::max_age(h),
                        "skill": horse::skill(h),
                        "tired_a": horse::tired_a(h),
                        "tired_b": horse::tired_b(h),
                        "species": horse::species(h),
                        "name_id": horse::name_id(h),
                        "litter_stat": horse::litter_stat(h),
                    }));
                }
                Ok(json!({
                    "count": n,
                    "horses": out,
                }))
            },
        ),

        // ===== Direct horse-object accessors =====
        // Each takes a horse pointer (hex string) obtained from a hook.
        // For now the only path to get one of these is via a function
        // hook (which we'll add in the next phase). When that lands,
        // these become useful.
        OpDef::new(
            "horse.read",
            "Read all known fields of a horse at given address.",
            "{addr: hex-string}",
            |args| {
                let h = args_hex_addr(args, "addr")?;
                Ok(json!({
                    "address": format!("0x{:x}", h),
                    "age": horse::age(h),
                    "max_age": horse::max_age(h),
                    "skill": horse::skill(h),
                    "tired_a": horse::tired_a(h),
                    "tired_b": horse::tired_b(h),
                    "species": horse::species(h),
                    "name_id": horse::name_id(h),
                    "litter_stat": horse::litter_stat(h),
                }))
            },
        ),
        OpDef::new(
            "horse.set_age",
            "Set a horse's age field.",
            "{addr: hex-string, value: i32}",
            |args| {
                let h = args_hex_addr(args, "addr")?;
                let v = args_i32(args, "value")?;
                let ok = horse::set_age(h, v);
                Ok(json!({"set": ok, "age": horse::age(h)}))
            },
        ),
        OpDef::new(
            "horse.set_max_age",
            "Set a horse's max-age (lifespan) field.",
            "{addr: hex-string, value: i32}",
            |args| {
                let h = args_hex_addr(args, "addr")?;
                let v = args_i32(args, "value")?;
                let ok = horse::set_max_age(h, v);
                Ok(json!({"set": ok, "max_age": horse::max_age(h)}))
            },
        ),
        OpDef::new(
            "horse.clear_tiredness",
            "Zero out the tired flags on a horse.",
            "{addr: hex-string}",
            |args| {
                let h = args_hex_addr(args, "addr")?;
                let ok = horse::clear_tiredness(h);
                Ok(json!({"set": ok}))
            },
        ),
    ]);
    modforge::log!("horseyforge: registered ops");
}

// =============================================================================
// Argument helpers (mirroring modforge::args style)
// =============================================================================

fn args_u32(args: &Json, key: &str) -> Result<u32, String> {
    args.get(key)
        .and_then(Json::as_u64)
        .map(|v| v as u32)
        .ok_or_else(|| format!("missing or non-u32 arg: {key}"))
}

fn args_i32(args: &Json, key: &str) -> Result<i32, String> {
    args.get(key)
        .and_then(Json::as_i64)
        .map(|v| v as i32)
        .ok_or_else(|| format!("missing or non-i32 arg: {key}"))
}

fn args_usize(args: &Json, key: &str) -> Result<usize, String> {
    args.get(key)
        .and_then(Json::as_u64)
        .map(|v| v as usize)
        .ok_or_else(|| format!("missing or non-usize arg: {key}"))
}

fn args_bool(args: &Json, key: &str) -> Result<bool, String> {
    args.get(key)
        .and_then(Json::as_bool)
        .ok_or_else(|| format!("missing or non-bool arg: {key}"))
}

fn args_hex_addr(args: &Json, key: &str) -> Result<usize, String> {
    let s = args
        .get(key)
        .and_then(Json::as_str)
        .ok_or_else(|| format!("missing or non-string arg: {key}"))?;
    let s = s.strip_prefix("0x").unwrap_or(s);
    usize::from_str_radix(s, 16).map_err(|e| format!("bad hex addr in {key}: {e}"))
}
