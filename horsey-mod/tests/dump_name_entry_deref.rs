mod common;
use serde_json::json;

#[test]
fn dump() {
    let Some(game) = common::launch("dump_name_entry_deref") else { return };
    let r = game.op_json("horse.name_diag", &json!({"name_id": 250})).unwrap();
    let result = r.get("result").unwrap_or(&r);
    let first = result.get("first_qword").and_then(|v| v.as_str()).unwrap_or("0x0");
    eprintln!("entry first_qword: {first}");
    // Try reading 64 bytes at first_qword to see if it's a string
    let bytes_r = game.op_json("patterns.read_bytes", &json!({"addr": first, "n": 64})).unwrap();
    eprintln!("bytes @ first_qword: {}", bytes_r.get("result").unwrap_or(&bytes_r));
}
