//! Generic: scan `.text` for a sig but return only hits whose
//! address falls inside a specified byte window. Use to scope a
//! pattern search to one function's body (start = function entry,
//! end = entry + body size).
//!
//! Env:
//!   MODFORGE_SIG          (required) IDA-style sig with `??` wildcards
//!   MODFORGE_WINDOW_START (required) absolute addr or RVA (0x140000000+)
//!   MODFORGE_WINDOW_LEN   (required) bytes
//!   MODFORGE_DISP32_OFF   (optional, default 2) byte offset of disp32 in sig
//!   MODFORGE_INSTR_LEN    (optional, default sig length) for next_ip calc
//!   MODFORGE_MAX_HITS     (optional, default 256)

mod common;

use serde_json::json;

fn need(name: &str) -> Option<String> { std::env::var(name).ok().filter(|s| !s.is_empty()) }
fn parse_uint(s: &str) -> u64 {
    if let Some(stripped) = s.strip_prefix("0x").or_else(|| s.strip_prefix("0X")) {
        u64::from_str_radix(stripped, 16).unwrap_or(0)
    } else { s.parse().unwrap_or(0) }
}

#[test]
fn scan_within_window() {
    let Some(sig) = need("MODFORGE_SIG") else {
        eprintln!("skipping: set MODFORGE_SIG + MODFORGE_WINDOW_START + MODFORGE_WINDOW_LEN");
        return;
    };
    let start_raw = need("MODFORGE_WINDOW_START").map(|s| parse_uint(&s)).expect("MODFORGE_WINDOW_START required");
    let win_len = need("MODFORGE_WINDOW_LEN").map(|s| parse_uint(&s)).expect("MODFORGE_WINDOW_LEN required");
    let disp_off = need("MODFORGE_DISP32_OFF").map(|s| parse_uint(&s) as u32).unwrap_or(2);
    // Default instr_len: count bytes in the sig string. If wildcards == disp32, that's fine.
    let sig_byte_count = sig.split_whitespace().count() as u32;
    let instr_len = need("MODFORGE_INSTR_LEN").map(|s| parse_uint(&s) as u32).unwrap_or(sig_byte_count);
    let max_hits = need("MODFORGE_MAX_HITS").map(|s| parse_uint(&s) as u32).unwrap_or(256);

    let Some(game) = common::launch("research_scan_in_window") else { return; };
    // Rebase if start_raw looks like an RVA (in image-base range).
    let start = if start_raw < 0x200000000 {
        let r = game.op_json("targets.resolve.gamestate_ptr", &json!({})).expect("ok");
        let ib = u64::from_str_radix(
            r.get("result").unwrap().get("image_base").unwrap().as_str().unwrap().trim_start_matches("0x"),
            16,
        ).unwrap();
        ib + (start_raw - 0x140000000)
    } else {
        start_raw
    };
    let end = start + win_len;
    game.log().event(
        "WINDOW",
        &format!("start=0x{start:x} end=0x{end:x} (len=0x{win_len:x}) sig={sig:?}"),
    );

    let resp = game
        .op_json(
            "patterns.sleuth.scan_all",
            &json!({
                "sig": sig,
                "disp32_offset": disp_off,
                "instr_len": instr_len,
                "context_bytes": 16u32,
                "max_hits": max_hits,
            }),
        )
        .expect("patterns.sleuth.scan_all must succeed");
    let result = resp.get("result").expect("result");
    let hits = result.get("hits").and_then(|v| v.as_array()).cloned().unwrap_or_default();
    let mut in_window = 0usize;
    for h in &hits {
        let a_str = h.get("instr_addr").and_then(|v| v.as_str()).unwrap_or("0x0");
        let a = u64::from_str_radix(a_str.trim_start_matches("0x"), 16).unwrap_or(0);
        if a >= start && a < end {
            in_window += 1;
            game.log().event(
                "IN_WINDOW",
                &format!(
                    "instr@{} target={} ctx={}",
                    a_str,
                    h.get("decoded_target").and_then(|v| v.as_str()).unwrap_or("?"),
                    h.get("context_hex").and_then(|v| v.as_str()).unwrap_or("?"),
                ),
            );
        }
    }
    game.pass(&format!(
        "scan global={} window={} (start=0x{start:x} len=0x{win_len:x})",
        hits.len(), in_window
    ));
}
