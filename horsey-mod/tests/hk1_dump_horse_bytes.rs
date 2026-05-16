//! HK1 Stage S0.5: dump a target horse's HORSE_ALLOC_SIZE (0x498)
//! bytes for offline diffing. Pair with a second run where the user
//! has moved the same horse between containers (truck <-> pasture);
//! diff the two byte dumps to isolate the per-horse container flag.
//!
//! Env:
//!   HORSEY_HORSE=<name>     default "tomtato"
//!   HORSEY_DUMP_TAG=<label> default "snapshot"; included in output
//!                           so the user can correlate runs.

mod common;

use serde_json::{json, Value};

#[test]
fn dump_horse_bytes() {
    let Some(game) = common::launch("hk1_dump_horse_bytes") else { return; };
    let want = std::env::var("HORSEY_HORSE").unwrap_or_else(|_| "tomtato".to_string());
    let tag = std::env::var("HORSEY_DUMP_TAG").unwrap_or_else(|_| "snapshot".to_string());
    let h = common::find_owned(&game, &want)
        .unwrap_or_else(|| panic!("'{want}' not owned"));
    eprintln!("\n[{tag}] horse '{}' at {} (raw {:#x})", h.name, h.ptr_s, h.id);

    let resp = game.op_json("patterns.read_bytes", &json!({
        "addr": h.ptr_s,
        "n": 0x498u64,
    })).expect("patterns.read_bytes");
    let hex = resp.get("result").and_then(|r| r.get("bytes")).and_then(Value::as_str)
        .expect("no bytes field").to_string();

    let bytes: Vec<u8> = hex.split_whitespace()
        .map(|s| u8::from_str_radix(s, 16).unwrap_or(0))
        .collect();
    assert_eq!(bytes.len(), 0x498, "wrong byte count");

    // Render 32 bytes per row with absolute offsets. Easy to diff against
    // a second snapshot.
    eprintln!("\n[{tag}] bytes @ {} (rows of 32):", h.ptr_s);
    for (i, chunk) in bytes.chunks(32).enumerate() {
        let off = i * 32;
        let row: String = chunk.iter().map(|b| format!("{b:02x}")).collect::<Vec<_>>().join(" ");
        eprintln!("  +0x{off:03x}  {row}");
    }
    game.pass(&format!("dumped {} bytes for {} ({})", bytes.len(), h.name, tag));
}
