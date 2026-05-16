mod common;
use serde_json::json;

#[test]
fn find() {
    let Some(game) = common::launch("scan_heap_tomtato") else { return };
    let r = game.op_json("mem.scan_heap_string", &json!({"needle": "tomtato", "max_hits": 20})).unwrap();
    eprintln!("{}", r.get("result").unwrap_or(&r));
}
