mod common;
use serde_json::json;

#[test]
fn dump() {
    let Some(game) = common::launch("dump_cmp_neg1") else { return };
    let r = game.op_json("diag.scan_cmp_neg1", &json!({})).unwrap();
    eprintln!("{}", r.get("result").unwrap_or(&r));
}
