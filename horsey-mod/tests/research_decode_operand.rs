//! Generic: read N bytes at a runtime address (or PE RVA) and
//! decode as a signed/unsigned integer. Use to pull operands
//! (disp8, disp32, imm32, etc.) out of an instruction whose
//! address you've already located.
//!
//! Env:
//!   MODFORGE_ADDR    absolute runtime addr   (or)
//!   MODFORGE_RVA     PE-relative virtual address
//!   MODFORGE_OFFSET  byte offset inside the instruction (default 0)
//!   MODFORGE_SIZE    1 | 2 | 4 | 8 (default 4)
//!   MODFORGE_SIGNED  1 to print signed decimal too (default 0)

mod common;

use serde_json::json;

fn need(name: &str) -> Option<String> { std::env::var(name).ok().filter(|s| !s.is_empty()) }
fn parse_hex_or_dec(s: &str) -> u64 {
    if let Some(stripped) = s.strip_prefix("0x").or_else(|| s.strip_prefix("0X")) {
        u64::from_str_radix(stripped, 16).unwrap_or(0)
    } else {
        s.parse().unwrap_or(0)
    }
}

#[test]
fn decode_operand_at_address() {
    let addr_env = need("MODFORGE_ADDR").map(|s| parse_hex_or_dec(&s));
    let rva_env = need("MODFORGE_RVA").map(|s| parse_hex_or_dec(&s));
    if addr_env.is_none() && rva_env.is_none() {
        eprintln!("skipping: set MODFORGE_ADDR or MODFORGE_RVA");
        return;
    }
    let offset = need("MODFORGE_OFFSET").map(|s| parse_hex_or_dec(&s) as usize).unwrap_or(0);
    let size = need("MODFORGE_SIZE").map(|s| parse_hex_or_dec(&s) as usize).unwrap_or(4);
    let want_signed = need("MODFORGE_SIGNED").map(|s| s == "1" || s == "true").unwrap_or(false);
    assert!(matches!(size, 1 | 2 | 4 | 8), "MODFORGE_SIZE must be 1/2/4/8");

    let Some(game) = common::launch("research_decode_operand") else { return; };
    let addr = if let Some(a) = addr_env {
        a
    } else {
        let r = game.op_json("targets.resolve.gamestate_ptr", &json!({})).expect("ok");
        let ib = u64::from_str_radix(
            r.get("result").unwrap().get("image_base").unwrap().as_str().unwrap().trim_start_matches("0x"),
            16,
        ).unwrap();
        ib + (rva_env.unwrap() - 0x140000000)
    };
    let read_addr = addr.wrapping_add(offset as u64);
    let r = game
        .op_json("patterns.read_bytes", &json!({"addr": format!("0x{read_addr:x}"), "n": size as u32}))
        .expect("read_bytes");
    let s = r.get("result").and_then(|x| x.get("bytes")).and_then(|v| v.as_str()).unwrap_or("");
    let bytes: Vec<u8> = s.split_whitespace().filter_map(|t| u8::from_str_radix(t, 16).ok()).collect();
    assert_eq!(bytes.len(), size, "short read");
    let unsigned: u64 = bytes.iter().rev().fold(0u64, |a, &b| (a << 8) | b as u64);
    let mut report = format!(
        "addr=0x{addr:x}+0x{offset:x}=0x{read_addr:x} size={size} bytes={s} unsigned=0x{unsigned:x} ({unsigned})"
    );
    if want_signed {
        let signed = match size {
            1 => (bytes[0] as i8) as i64,
            2 => i16::from_le_bytes([bytes[0], bytes[1]]) as i64,
            4 => i32::from_le_bytes([bytes[0], bytes[1], bytes[2], bytes[3]]) as i64,
            8 => i64::from_le_bytes([bytes[0], bytes[1], bytes[2], bytes[3], bytes[4], bytes[5], bytes[6], bytes[7]]),
            _ => 0,
        };
        report.push_str(&format!(" signed={signed} ({signed:#x})"));
    }
    game.log().event("DECODE", &report);
    game.pass(&format!("decoded {size}B at 0x{read_addr:x}: unsigned=0x{unsigned:x}"));
}
