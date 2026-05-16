mod common;
use serde_json::json;

#[test]
fn dump() {
    let Some(game) = common::launch("dump_apply_gene") else { return };
    // image_base for this run. Pull from build_info.
    let bi = game.op_json("game.build_info", &json!({})).unwrap();
    let base = bi.get("result").and_then(|r| r.get("image_base")).and_then(|v| v.as_str()).unwrap_or("0x0");
    let base = usize::from_str_radix(base.trim_start_matches("0x"), 16).unwrap();
    let rva = 0x9f670usize;
    // Read 64 bytes starting 16 before the suspected entry to see the function entry boundary.
    let addr = base + rva - 16;
    let r = game.op_json("patterns.read_bytes", &json!({"addr": format!("0x{addr:x}"), "n": 80})).unwrap();
    let bytes = r.get("result").and_then(|rr| rr.get("bytes")).and_then(|b| b.as_str()).unwrap_or("");
    eprintln!("bytes at runtime base+0x{rva:x}-0x10..+0x40 (80 bytes):");
    for (i, b) in bytes.split_whitespace().enumerate() {
        let off = i as isize - 16;
        if i % 16 == 0 { eprint!("\n+0x{off:+04}: "); }
        eprint!("{b} ");
    }
    eprintln!();
}
