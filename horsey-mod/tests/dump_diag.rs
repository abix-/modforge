mod common;
use serde_json::json;

#[test]
fn dump() {
    let Some(game) = common::launch("dump_diag") else { return };
    let r = game.op_json("gamestate.diag", &json!({})).unwrap();
    let res = r.get("result").unwrap_or(&r);
    eprintln!("FULL result: {res}");
}
