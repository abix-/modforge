mod common;
use serde_json::json;

#[test]
fn dump_build() {
    let Some(game) = common::launch("dump_build") else { return };
    let r = game.op_json("game.build_info", &json!({})).unwrap();
    eprintln!("BUILD INFO: {r}");
}
