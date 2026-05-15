//! Locate RETIRE_HORSE_HANDLER's true entry by anchoring on a
//! unique format-string literal inside the function. Decomp
//! (`research/decompiled/funcs/1400d/1400df280_FUN_1400df280.c`)
//! shows the function calls FUN_1400c4320 with format strings
//! "retired %s (useless) age %d ch %d", "(bails)", "(old)". The
//! first is unique to this function.
//!
//! Steps:
//!   1. Scan .rdata for the literal bytes of "retired %s (useless)".
//!   2. find_xrefs to that address. The matching `lea reg,
//!      [rip+disp32]` is inside RETIRE_HORSE_HANDLER.
//!   3. From the xref site, walk backward in .text to the nearest
//!      function prologue. That's the function entry.

mod common;

use serde_json::json;

#[test]
fn locate_retire_horse_handler() {
    let Some(game) = common::launch("find_retire_horse_handler") else { return; };

    // Image base for RVA reporting.
    let r = game.op_json("targets.resolve.gamestate_ptr", &json!({})).expect("gs_ptr");
    let ib = u64::from_str_radix(
        r.get("result").unwrap().get("image_base").unwrap().as_str().unwrap().trim_start_matches("0x"),
        16,
    ).unwrap();
    game.log().event("RETIRE", &format!("image_base=0x{ib:x}"));

    // Step 1: rdata scan.
    let sig = "72 65 74 69 72 65 64 20 25 73 20 28 75 73 65 6c 65 73 73 29";
    let resp = game.op_json("mem.scan_rdata", &json!({"sig": sig})).expect("scan_rdata");
    let hits = resp.get("result").and_then(|r| r.get("hits")).and_then(|v| v.as_array()).cloned().unwrap_or_default();
    assert!(!hits.is_empty(), "string not in .rdata; sig wrong or build moved literal");
    let str_addr_str = hits[0].get("addr").and_then(|v| v.as_str()).expect("hit addr");
    let str_addr = u64::from_str_radix(str_addr_str.trim_start_matches("0x"), 16).unwrap();
    game.log().event("RETIRE", &format!("string @ 0x{str_addr:x}"));

    // MSVC's lea points at the START of the format string, which
    // is "%s retired %s (useless)...". 3 bytes before our anchor
    // (which matched the substring starting at "retired").
    let target_addr = str_addr.wrapping_sub(3);

    // Step 2: find_xrefs against the format-string start.
    let resp = game.op_json("mem.find_xrefs", &json!({"target_addr": target_addr})).expect("find_xrefs");
    let xrefs = resp.get("result").and_then(|r| r.get("hits")).and_then(|v| v.as_array()).cloned().unwrap_or_default();
    // Diagnostic: if no xrefs, print bytes around the string and
    // probe addresses near it (MSVC sometimes references via a
    // size-prefix header offset before the literal).
    if xrefs.is_empty() {
        let before = str_addr.saturating_sub(32);
        let r = game.op_json("patterns.read_bytes", &json!({"addr": format!("0x{before:x}"), "n": 96u32})).expect("read_bytes");
        let bytes = r.get("result").and_then(|x| x.get("bytes")).and_then(|v| v.as_str()).unwrap_or("");
        game.log().event("RDATA_NEIGHBORHOOD", &format!("addr=0x{before:x} (str-32 to str+64): {bytes}"));
        for delta in [-32_i64, -24, -16, -8, -4, -1, 1, 4, 8, 16, 24, 32].iter() {
            let probe = str_addr.wrapping_add_signed(*delta);
            let r = game.op_json("mem.find_xrefs", &json!({"target_addr": probe})).expect("find_xrefs");
            let n = r.get("result").and_then(|x| x.get("hits")).and_then(|v| v.as_array()).map(|a| a.len()).unwrap_or(0);
            game.log().event("PROBE", &format!("target=0x{probe:x} (str{delta:+}) xrefs={n}"));
        }
    }
    assert!(!xrefs.is_empty(), "no .text xrefs to format string {str_addr:x}");
    for x in &xrefs {
        game.log().event(
            "XREF",
            &format!(
                "instr@{} ({}): {}",
                x.get("instr_addr").and_then(|v| v.as_str()).unwrap_or("?"),
                x.get("opcode_class").and_then(|v| v.as_str()).unwrap_or("?"),
                x.get("context_hex").and_then(|v| v.as_str()).unwrap_or("?"),
            ),
        );
    }

    // Step 3: for each xref, walk back through .text in 4KB chunks
    // looking for an int3-padded function boundary (`cc cc cc cc`.
    // at least 3 int3 bytes in a row immediately precede a real
    // function entry in MSVC output). The first valid prologue
    // AFTER the boundary is the true function entry.
    fn is_prologue(b: &[u8]) -> bool {
        if b.len() < 6 { return false; }
        if b[0] == 0x48 && b[1] == 0x89 && b[2] == 0x5c && b[3] == 0x24 { return true; }
        if b[0] == 0x48 && b[1] == 0x8b && b[2] == 0xc4 {
            return matches!(b[3], 0x55 | 0x53 | 0x56 | 0x57 | 0x40..=0x4f);
        }
        if b[0] == 0x57 && b[1] == 0x41 && matches!(b[2], 0x54..=0x57) {
            return matches!(b[3], 0x41 | 0x48 | 0x55 | 0x56 | 0x57);
        }
        if b[0] == 0x48 && b[1] == 0x89 && matches!(b[2], 0x6c | 0x74 | 0x7c) && b[3] == 0x24 { return true; }
        if b[0] == 0x53 && matches!(b[1], 0x55 | 0x56 | 0x57) { return true; }
        if b[0] == 0x56 && b[1] == 0x57 && b[2] == 0x48 {
            return matches!(b[3], 0x83 | 0x81);
        }
        // 41 56 48 ... (push r14; ...): seen in RETIRE-like functions.
        if b[0] == 0x41 && matches!(b[1], 0x54 | 0x55 | 0x56 | 0x57) { return true; }
        // 40 53 (push rbx with REX); 40 55 (push rbp with REX).
        if b[0] == 0x40 && matches!(b[1], 0x53 | 0x55 | 0x56 | 0x57) { return true; }
        false
    }

    for x in &xrefs {
        let instr_str = x.get("instr_addr").and_then(|v| v.as_str()).unwrap_or("0x0");
        let instr = u64::from_str_radix(instr_str.trim_start_matches("0x"), 16).unwrap_or(0);
        // Read 8 KiB before the xref site to cover RETIRE_HORSE_HANDLER's
        // 4364-byte body plus margin. Chunk the read at 4 KiB.
        const READ_BACK: u64 = 8192;
        let lo = instr.saturating_sub(READ_BACK);
        let mut bytes: Vec<u8> = Vec::with_capacity(READ_BACK as usize);
        let mut cursor = lo;
        let total_to_read = READ_BACK;
        while (bytes.len() as u64) < total_to_read {
            let remaining = total_to_read - bytes.len() as u64;
            let take = remaining.min(4096) as u32;
            let r = game
                .op_json("patterns.read_bytes", &json!({"addr": format!("0x{cursor:x}"), "n": take}))
                .expect("read_bytes");
            let s = r.get("result").and_then(|x| x.get("bytes")).and_then(|v| v.as_str()).unwrap_or("");
            let chunk: Vec<u8> = s.split_whitespace().filter_map(|t| u8::from_str_radix(t, 16).ok()).collect();
            if chunk.is_empty() { break; }
            bytes.extend_from_slice(&chunk);
            cursor = cursor.wrapping_add(chunk.len() as u64);
        }

        // Walk backward; find the LAST int3-padding run (3+ consecutive 0xcc).
        // The function we want starts AFTER that padding.
        let mut padding_end: Option<usize> = None;
        for off in (0..bytes.len().saturating_sub(3)).rev() {
            if bytes[off] == 0xcc && bytes[off + 1] == 0xcc && bytes[off + 2] == 0xcc {
                padding_end = Some(off + 3);
                break;
            }
        }
        let scan_from = padding_end.unwrap_or(0);
        // Find the first valid prologue at or after scan_from.
        let mut entry_off: Option<usize> = None;
        for off in scan_from..bytes.len().saturating_sub(6) {
            if bytes[off] == 0xcc { continue; }
            if is_prologue(&bytes[off..]) {
                entry_off = Some(off);
                break;
            }
        }
        if let Some(off) = entry_off {
            let entry_addr = lo + off as u64;
            let dist = instr.wrapping_sub(entry_addr);
            let preview: String = bytes[off..(off + 32).min(bytes.len())]
                .iter().map(|b| format!("{b:02x}")).collect::<Vec<_>>().join(" ");
            let entry_rva = 0x140000000_u64 + entry_addr.wrapping_sub(ib);
            game.log().event(
                "ENTRY",
                &format!(
                    "xref@0x{instr:x} -> entry=0x{entry_addr:x} rva=0x{entry_rva:x} (dist=-0x{dist:x}, after-cc-padding) bytes={preview}"
                ),
            );
        } else {
            game.log().event("ENTRY", &format!("xref@0x{instr:x} -> no prologue after cc-padding in 8KB"));
        }
    }
    game.pass("RETIRE_HORSE_HANDLER probe complete; see ENTRY lines in log");
}
