//! Generic R4: locate a struct field offset by anchoring on a
//! .rdata string literal referenced by the function that ACCESSES
//! the field, then decoding the field-load instruction's disp.
//!
//! Recipe (e.g. YEAR offset from pause-menu printf):
//!   1. Scan .rdata for the format string literal
//!      (`MODFORGE_STRING_HEX`).
//!   2. Adjust for the lea-target offset
//!      (`MODFORGE_LEA_OFFSET`; default 0, e.g. -3 if MSVC's lea
//!      points 3 bytes before our anchor. See find_retire_horse_handler).
//!   3. find_xrefs to the lea target.
//!   4. For each xref site, scan a +/-`MODFORGE_WINDOW` byte window
//!      around it for `MODFORGE_DISP_OPCODE` (e.g. `8b 81` for
//!      `mov eax, [rcx + disp32]`). Decode each match's disp.
//!   5. Report the most common decoded value (the field offset).
//!
//! Env:
//!   MODFORGE_STRING_HEX        (required) hex bytes of the .rdata anchor literal
//!   MODFORGE_LEA_OFFSET        (optional, default 0; signed)
//!   MODFORGE_DISP_OPCODE       (required) e.g. "8b 81" for mov r32, [rcx+disp32]
//!   MODFORGE_DISP_OFF          (required) byte offset of disp inside the matched opcode
//!   MODFORGE_DISP_SIZE         (optional, default 4) 1 or 4
//!   MODFORGE_WINDOW            (optional, default 64) bytes around each xref
//!
//! Example (YEAR field via "Year %d" pause-menu printf):
//!   MODFORGE_STRING_HEX="59 65 61 72 20 25 64"
//!   MODFORGE_DISP_OPCODE="8b 81" MODFORGE_DISP_OFF=2

mod common;

use serde_json::json;
use std::collections::BTreeMap;

fn need(name: &str) -> Option<String> { std::env::var(name).ok().filter(|s| !s.is_empty()) }
fn parse_uint(s: &str) -> u64 {
    if let Some(stripped) = s.strip_prefix("0x").or_else(|| s.strip_prefix("0X")) {
        u64::from_str_radix(stripped, 16).unwrap_or(0)
    } else { s.parse().unwrap_or(0) }
}
fn parse_signed(s: &str) -> i64 {
    let neg = s.starts_with('-');
    let body = if neg { &s[1..] } else { s };
    let m = parse_uint(body) as i64;
    if neg { -m } else { m }
}

#[test]
fn decode_field_offset_via_string_anchor() {
    let Some(string_hex) = need("MODFORGE_STRING_HEX") else {
        eprintln!("skipping: set MODFORGE_STRING_HEX + MODFORGE_DISP_OPCODE + MODFORGE_DISP_OFF");
        return;
    };
    let lea_offset = need("MODFORGE_LEA_OFFSET").map(|s| parse_signed(&s)).unwrap_or(0);
    let disp_opcode = need("MODFORGE_DISP_OPCODE").expect("MODFORGE_DISP_OPCODE required");
    let disp_off = need("MODFORGE_DISP_OFF").map(|s| parse_uint(&s) as usize).expect("MODFORGE_DISP_OFF required");
    let disp_size = need("MODFORGE_DISP_SIZE").map(|s| parse_uint(&s) as usize).unwrap_or(4);
    assert!(matches!(disp_size, 1 | 4), "MODFORGE_DISP_SIZE must be 1 or 4");
    let window: u64 = need("MODFORGE_WINDOW").map(|s| parse_uint(&s)).unwrap_or(64);

    let Some(game) = common::launch("research_decode_field_offset") else { return; };

    // Step 1: rdata anchor.
    let r = game.op_json("mem.scan_rdata", &json!({"sig": string_hex})).expect("scan_rdata");
    let hits = r.get("result").and_then(|x| x.get("hits")).and_then(|v| v.as_array()).cloned().unwrap_or_default();
    assert!(!hits.is_empty(), "string {string_hex:?} not in .rdata");
    let str_addr = u64::from_str_radix(
        hits[0].get("addr").and_then(|v| v.as_str()).unwrap().trim_start_matches("0x"),
        16,
    ).unwrap();
    let lea_target = str_addr.wrapping_add_signed(lea_offset);
    game.log().event("ANCHOR", &format!("string@0x{str_addr:x} lea_target@0x{lea_target:x} (offset {lea_offset:+})"));

    // Step 2: find_xrefs to the lea target.
    let r = game.op_json("mem.find_xrefs", &json!({"target_addr": lea_target})).expect("find_xrefs");
    let xrefs = r.get("result").and_then(|x| x.get("hits")).and_then(|v| v.as_array()).cloned().unwrap_or_default();
    assert!(!xrefs.is_empty(), "no .text xrefs to 0x{lea_target:x}");
    game.log().event("XREFS", &format!("found {}", xrefs.len()));

    // Step 3: for each xref, read a window of bytes around it and
    // scan in-memory for `disp_opcode`. Decode disp at each match.
    fn parse_hex(s: &str) -> Vec<u8> {
        s.split_whitespace().filter_map(|t| u8::from_str_radix(t, 16).ok()).collect()
    }
    let opcode_bytes = parse_hex(&disp_opcode);
    let mut histogram: BTreeMap<i64, usize> = BTreeMap::new();
    for x in &xrefs {
        let instr_str = x.get("instr_addr").and_then(|v| v.as_str()).unwrap_or("0x0");
        let instr = u64::from_str_radix(instr_str.trim_start_matches("0x"), 16).unwrap_or(0);
        let lo = instr.saturating_sub(window);
        let total = (window * 2) as u32;
        // Chunk read at 4 KiB.
        let mut bytes: Vec<u8> = Vec::with_capacity(total as usize);
        let mut cursor = lo;
        let mut remaining = total;
        while remaining > 0 {
            let take = remaining.min(4096);
            let r = game.op_json("patterns.read_bytes", &json!({"addr": format!("0x{cursor:x}"), "n": take}))
                .expect("read_bytes");
            let s = r.get("result").and_then(|y| y.get("bytes")).and_then(|v| v.as_str()).unwrap_or("");
            let chunk = parse_hex(s);
            if chunk.is_empty() { break; }
            bytes.extend_from_slice(&chunk);
            cursor = cursor.wrapping_add(chunk.len() as u64);
            remaining = remaining.saturating_sub(chunk.len() as u32);
        }
        // Find every opcode match.
        for off in 0..bytes.len().saturating_sub(opcode_bytes.len() + disp_off + disp_size) {
            if bytes[off..off + opcode_bytes.len()] == opcode_bytes[..] {
                // disp_off is measured from start of the match (opcode is the
                // prefix), so disp starts at `off + disp_off`.
                let d_start = off + disp_off;
                if d_start + disp_size > bytes.len() { break; }
                let disp: i64 = if disp_size == 1 {
                    bytes[d_start] as i8 as i64
                } else {
                    i32::from_le_bytes([bytes[d_start], bytes[d_start+1], bytes[d_start+2], bytes[d_start+3]]) as i64
                };
                let match_addr = lo + off as u64;
                game.log().event(
                    "FIELD",
                    &format!("xref@0x{instr:x} match@0x{match_addr:x} disp={disp:#x} ({disp})"),
                );
                *histogram.entry(disp).or_insert(0) += 1;
            }
        }
    }

    let mut top: Vec<(i64, usize)> = histogram.into_iter().collect();
    top.sort_by(|a, b| b.1.cmp(&a.1));
    for (i, (disp, count)) in top.iter().take(5).enumerate() {
        game.log().event(
            "HISTOGRAM",
            &format!("[{i}] disp={disp:#x} ({disp}) count={count}"),
        );
    }
    if let Some((disp, count)) = top.first() {
        game.pass(&format!("top field offset: {disp:#x} ({disp}) with {count} matches"));
    } else {
        panic!("no disp matches found in any xref window");
    }
}
