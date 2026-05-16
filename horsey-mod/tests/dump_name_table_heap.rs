mod common;
use serde_json::json;

#[test]
fn dump() {
    let Some(game) = common::launch("dump_name_table_heap") else { return };
    // Hit 3 was at 0x25bc6095a30 (tomtato as MSVC std::string SSO).
    // Verify by reading 0x100 bytes at hit address (covers 2 entries).
    // BUT the heap address is per-launch (ASLR + allocator); we need
    // the user's CURRENT address. Re-scan first.
    let s = game.op_json("mem.scan_heap_string", &json!({"needle": "tomtato", "max_hits": 20})).unwrap();
    let hits = s.get("result").and_then(|r| r.get("hits")).and_then(|h| h.as_array()).cloned().unwrap_or_default();
    eprintln!("scan returned {} hits", hits.len());
    for h in &hits {
        let addr_s = h.get("addr").and_then(|v| v.as_str()).unwrap_or("0x0");
        let addr = usize::from_str_radix(addr_s.trim_start_matches("0x"), 16).unwrap_or(0);
        // Read 0x100 bytes starting at the hit (cover up to 2 entries forward).
        let r = game.op_json("patterns.read_bytes", &json!({"addr": addr_s, "n": 0x100})).unwrap();
        let bytes_s = r.get("result").and_then(|rr| rr.get("bytes")).and_then(|b| b.as_str()).unwrap_or("");
        let bytes: Vec<u8> = bytes_s.split_whitespace().map(|b| u8::from_str_radix(b, 16).unwrap()).collect();
        if bytes.len() < 0x20 { eprintln!("hit {addr_s}: short read"); continue; }
        // Treat hit address as entry start. Layout: tomtato\0 [+0..+8], pad, size at +0x10, capacity at +0x18.
        let size = u64::from_le_bytes(bytes[0x10..0x18].try_into().unwrap());
        let cap  = u64::from_le_bytes(bytes[0x18..0x20].try_into().unwrap());
        let ascii: String = bytes[..16].iter()
            .map(|b| if (0x20..0x7f).contains(b) { *b as char } else { '.' })
            .collect();
        eprintln!("hit @ {addr_s}: inline=[{ascii}] size_at+0x10={size} cap_at+0x18={cap}");
        // Now try the assumption: entry at addr, next entry at addr+0x88.
        if bytes.len() >= 0x88 + 0x20 {
            let next_bytes = &bytes[0x88..0x88+0x20];
            let next_size = u64::from_le_bytes(next_bytes[0x10..0x18].try_into().unwrap());
            let next_cap  = u64::from_le_bytes(next_bytes[0x18..0x20].try_into().unwrap());
            let next_ascii: String = next_bytes[..16].iter()
                .map(|b| if (0x20..0x7f).contains(b) { *b as char } else { '.' })
                .collect();
            eprintln!("  +0x88: inline=[{next_ascii}] size={next_size} cap={next_cap}");
        }
        eprintln!();
        let _ = addr;
    }
}
