mod common;
use serde_json::json;

#[test]
fn dump_name_diag() {
    let Some(game) = common::launch("dump_name_diag") else { return };
    for nid in [250u32, 251, 272] {
        let r = game.op_json("horse.name_diag", &json!({"name_id": nid})).unwrap();
        eprintln!("\nname_id={nid}: {}", r.get("result").unwrap_or(&r));
    }
}
