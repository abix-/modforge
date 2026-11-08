//! Which awake entities are chests (a Chest part, so chest_opened is
//! read), their paths, opened flag, and whether pickup takes their
//! label or clicks it on the screen. The operator saw a woodsman's
//! locker left shut (2026-11-07), so every chest type is taken now.
//! Read-only.
//!
//! ```text
//! cargo run -p poe2-mod            # game in play, chests near
//! k3sc cargo-lock test -p poe2-mod --test research_chests -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when poe2-mod or the game is not running.

use modforge::memory_research::Remote;
use serde_json::json;

#[test]
fn every_chest_near() {
    let r = Remote::at(17185);
    let list = match r.op("entities", json!({"path": "Metadata"})) {
        Ok(l) => l,
        Err(e) => {
            println!("SKIP: {e}");
            return;
        }
    };
    let labels = r.op("ground_labels", json!({})).expect("ground_labels");
    let mut taken: Vec<u64> = labels["labels"]
        .as_array()
        .cloned()
        .unwrap_or_default()
        .iter()
        .filter(|l| l["candidate"]["rule"] == "chest")
        .filter_map(|l| l["candidate"]["key"].as_u64())
        .collect();
    // Chests with no label, clicked on the screen instead.
    taken.extend(
        labels["chests_without_label"]
            .as_array()
            .cloned()
            .unwrap_or_default()
            .iter()
            .filter_map(|c| c["key"].as_u64()),
    );
    let mut chests = 0;
    for e in list["awake"]["entities"]
        .as_array()
        .cloned()
        .unwrap_or_default()
    {
        if e["chest_opened"].is_null() {
            continue;
        }
        chests += 1;
        let address = e["address"].as_u64().unwrap_or(0);
        println!(
            "{} {} opened {} valid {}",
            if taken.contains(&address) {
                "TAKEN"
            } else {
                "     "
            },
            e["path"],
            e["chest_opened"],
            e["valid"],
        );
    }
    println!("{chests} chests");
}
