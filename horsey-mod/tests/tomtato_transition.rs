//! Force a visible transition on tomtato: shrink -> grow.
mod common;
use serde_json::{json, Value};
use std::thread::sleep;
use std::time::Duration;

#[test]
fn cycle() {
    let Some(game) = common::launch("tomtato_transition") else { return };
    let owned = game.op_json("gamestate.owned_horses", &json!({})).unwrap();
    let horses = owned.get("result").and_then(|r| r.get("horses")).and_then(Value::as_array).cloned().unwrap_or_default();
    let mut id: Option<u64> = None;
    for h in &horses {
        if h.get("name").and_then(Value::as_str) == Some("tomtato") {
            let s = h.get("ptr").and_then(Value::as_str).unwrap_or("0x0");
            id = u64::from_str_radix(s.trim_start_matches("0x"), 16).ok();
            break;
        }
    }
    let id = id.expect("tomtato");

    let set = |m: u8, p: u8| {
        game.op_json("horse.ext.alleles.set", &json!({
            "horse_id": id, "ext_gene_idx": 0, "maternal": m, "paternal": p,
        })).unwrap()
    };

    eprintln!("step 1: shrink (allele 0,0 -> value 0)");
    let _ = set(0, 0);
    sleep(Duration::from_secs(2));

    eprintln!("step 2: tiny (allele 1,1 -> value 50)");
    let _ = set(1, 1);
    sleep(Duration::from_secs(2));

    eprintln!("step 3: normal (allele 2,2 -> value 100)");
    let _ = set(2, 2);
    sleep(Duration::from_secs(2));

    eprintln!("step 4: GIANT (allele 3,3 -> value 200)");
    let _ = set(3, 3);
    sleep(Duration::from_secs(3));

    eprintln!("done. tomtato should now be GIANT.");
}
