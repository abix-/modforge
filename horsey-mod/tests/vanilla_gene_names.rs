//! Verify vanilla gene names load from `<game>/data/genes.xml` and
//! that key sentinel names land at expected indices (XML order ==
//! engine flat index, per `FUN_1400a3eb0`'s lazy std::map insert).

mod common;

use serde_json::{json, Value};

#[test]
fn vanilla_gene_names_load() {
    let Some(game) = common::launch("vanilla_gene_names") else { return };

    let r = game.op_json("genes.vanilla.names", &json!({})).unwrap();
    let result = r.get("result").expect("no result");
    assert_eq!(result.get("loaded").and_then(Value::as_bool), Some(true), "names not loaded");
    let names: Vec<String> = result.get("names").and_then(Value::as_array)
        .cloned().unwrap_or_default().into_iter()
        .filter_map(|v| v.as_str().map(String::from)).collect();
    assert_eq!(names.len(), 240, "expected 240 names, got {}", names.len());

    eprintln!("first 10: {:?}", &names[..10]);
    eprintln!("last 10:  {:?}", &names[230..]);

    // From the local genes.xml the first three entries are SIZE,
    // ASPECT, SKINNY. Anchor the test on these so XML-order drift
    // would fail loudly.
    assert_eq!(names[0], "SIZE", "flat 0 should be SIZE");
    assert_eq!(names[1], "ASPECT", "flat 1 should be ASPECT");
    assert_eq!(names[2], "SKINNY", "flat 2 should be SKINNY");
}
