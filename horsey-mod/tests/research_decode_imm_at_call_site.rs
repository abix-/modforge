//! Generic R4: for every `call MODFORGE_TARGET_FN` in .text, walk
//! backward a small window for a `mov reg, imm32` opcode and
//! decode the imm. Use to recover struct sizes from allocator
//! calls.
//!
//! Example: HORSE struct size 0x498 is passed to the allocator at
//! every horse construction:
//!   mov ecx, 0x498        ; b9 98 04 00 00      (5 bytes; ecx imm32)
//!   call FUN_1402c704c    ; e8 disp32           (5 bytes)
//!
//! Anchoring on `e8 X<allocator_addr>` xrefs to the allocator,
//! then decoding the imm32 right before each call, surfaces every
//! struct size the game allocates. Cluster + histogram to find a
//! specific size.
//!
//! Env:
//!   MODFORGE_TARGET_FN          (required) absolute addr or RVA of the function
//!   MODFORGE_IMM_OPCODE         (required) e.g. "b9" (mov ecx imm32),
//!                                          "ba" (mov edx imm32), "68" (push imm32)
//!   MODFORGE_IMM_OFF            (optional, default 1) offset of imm inside match
//!   MODFORGE_IMM_SIZE           (optional, default 4) bytes
//!   MODFORGE_LOOKBACK           (optional, default 16) bytes before each call

mod common;

use serde_json::json;
use std::collections::BTreeMap;

fn need(name: &str) -> Option<String> { std::env::var(name).ok().filter(|s| !s.is_empty()) }
fn parse_uint(s: &str) -> u64 {
    if let Some(stripped) = s.strip_prefix("0x").or_else(|| s.strip_prefix("0X")) {
        u64::from_str_radix(stripped, 16).unwrap_or(0)
    } else { s.parse().unwrap_or(0) }
}
fn parse_hex(s: &str) -> Vec<u8> {
    s.split_whitespace().filter_map(|t| u8::from_str_radix(t, 16).ok()).collect()
}

#[test]
fn decode_imm_at_call_site() {
    let Some(target_raw) = need("MODFORGE_TARGET_FN").map(|s| parse_uint(&s)) else {
        eprintln!("skipping: set MODFORGE_TARGET_FN + MODFORGE_IMM_OPCODE");
        return;
    };
    let imm_opcode = need("MODFORGE_IMM_OPCODE").expect("MODFORGE_IMM_OPCODE required");
    let imm_off = need("MODFORGE_IMM_OFF").map(|s| parse_uint(&s) as usize).unwrap_or(1);
    let imm_size = need("MODFORGE_IMM_SIZE").map(|s| parse_uint(&s) as usize).unwrap_or(4);
    let lookback = need("MODFORGE_LOOKBACK").map(|s| parse_uint(&s) as u32).unwrap_or(16);
    assert!(matches!(imm_size, 1 | 4), "MODFORGE_IMM_SIZE must be 1 or 4");

    let Some(game) = common::launch("research_decode_imm_at_call_site") else { return; };
    // Rebase if it looks like an RVA.
    let target = if target_raw < 0x200000000 {
        let r = game.op_json("targets.resolve.gamestate_ptr", &json!({})).expect("ok");
        let ib = u64::from_str_radix(
            r.get("result").unwrap().get("image_base").unwrap().as_str().unwrap().trim_start_matches("0x"),
            16,
        ).unwrap();
        ib + (target_raw - 0x140000000)
    } else {
        target_raw
    };
    game.log().event("TARGET", &format!("call site: 0x{target:x}"));

    // find_xrefs to the function (find_xrefs covers `e8 disp32` call too? No.
    // E8-call uses RIP-rel disp32 just like `48 8b 05 disp32`. find_xrefs
    // takes target addr; we want to find every e8 instruction whose disp32
    // resolves to target. Use patterns.sleuth.scan_all directly with
    // `e8 X<target>` constraint (patternsleuth's xref syntax).
    let sig = format!("e8 X0x{target:x}");
    let resp = game
        .op_json("patterns.sleuth.scan_all", &json!({
            "sig": sig, "disp32_offset": 1u32, "instr_len": 5u32, "context_bytes": 16u32, "max_hits": 4096u32,
        }))
        .expect("scan_all");
    let calls = resp.get("result").and_then(|x| x.get("hits")).and_then(|v| v.as_array()).cloned().unwrap_or_default();
    game.log().event("CALLS", &format!("found {}", calls.len()));
    assert!(!calls.is_empty(), "no `e8 disp32` callers of 0x{target:x}");

    let opcode_bytes = parse_hex(&imm_opcode);
    let mut histogram: BTreeMap<i64, usize> = BTreeMap::new();
    for c in &calls {
        let a_str = c.get("instr_addr").and_then(|v| v.as_str()).unwrap_or("0x0");
        let a = u64::from_str_radix(a_str.trim_start_matches("0x"), 16).unwrap_or(0);
        // Read lookback bytes immediately before the call.
        let lo = a.saturating_sub(lookback as u64);
        let r = game
            .op_json("patterns.read_bytes", &json!({"addr": format!("0x{lo:x}"), "n": lookback}))
            .expect("read_bytes");
        let s = r.get("result").and_then(|y| y.get("bytes")).and_then(|v| v.as_str()).unwrap_or("");
        let bytes = parse_hex(s);
        // Walk backward; find the LAST opcode match before the call.
        if bytes.len() < opcode_bytes.len() + imm_off + imm_size { continue; }
        let max_off = bytes.len().saturating_sub(opcode_bytes.len() + imm_off + imm_size);
        let mut found: Option<(usize, i64)> = None;
        for off in (0..=max_off).rev() {
            if bytes[off..off + opcode_bytes.len()] == opcode_bytes[..] {
                let d_start = off + imm_off;
                let val: i64 = if imm_size == 1 {
                    bytes[d_start] as i8 as i64
                } else {
                    i32::from_le_bytes([bytes[d_start], bytes[d_start+1], bytes[d_start+2], bytes[d_start+3]]) as i64
                };
                found = Some((off, val));
                break;
            }
        }
        if let Some((off, val)) = found {
            let match_addr = lo + off as u64;
            game.log().event(
                "ARG",
                &format!("call@0x{a:x} arg@0x{match_addr:x} imm={val:#x} ({val})"),
            );
            *histogram.entry(val).or_insert(0) += 1;
        }
    }

    let mut top: Vec<(i64, usize)> = histogram.into_iter().collect();
    top.sort_by(|a, b| b.1.cmp(&a.1));
    for (i, (val, count)) in top.iter().take(10).enumerate() {
        game.log().event(
            "HISTOGRAM",
            &format!("[{i}] imm={val:#x} ({val}) count={count}"),
        );
    }
    game.pass(&format!("scanned {} call sites; {} distinct imm values", calls.len(), top.len()));
}
