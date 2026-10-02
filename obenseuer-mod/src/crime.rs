//! Crime: the player's standing with the police, for the mini HUD
//! (operator 2026-10-02). Every number is the game's own answer, read
//! from its Crime object's getters on the main thread. Read-only.
//! Proven by tests/research_crime.rs.

use std::time::Duration;

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Map, Value as Json, json};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{json_handle, owned_object};

use crate::deposit::first_instance;

/// What the HUD shows, and the Crime getter that answers it. Each one
/// read in the decompiled Crime and found to change nothing.
/// CalculateBribe is NOT one: it stores the price it works out in
/// latestBribe, which only a paid bribe clears, so the HUD reads that
/// field instead.
const GETTERS: [(&str, &str); 6] = [
    ("fine", "GetCrimeFineAmount"),
    ("can pay fine", "CanPayFine"),
    ("sentence hours", "GetSentenceLengthInHours"),
    ("not tried a bribe yet", "CanBribe"),
    ("stolen goods value", "CountStolenGoodsValue"),
    ("arrest in progress", "get_ArrestInProgress"),
];

pub fn install() {
    OP_REGISTRY.register(
        OpDef::new(
            "crime",
            "Your standing with the police: fine, sentence, bribe, stolen goods, police after you",
            "{}",
            |_| MAIN_QUEUE.run_result("crime", Duration::from_secs(2), read),
        )
        .hud(),
    );
}

fn read() -> Result<Json, String> {
    let crime = first_instance("Crime")?;
    let mut out = Map::new();
    for (label, getter) in GETTERS {
        out.insert(label.to_string(), crime.invoke(getter, &json!([]))?);
    }
    let police = json_handle(&crime.read_field("activePolices")?)
        .map(owned_object)
        .ok_or("Crime has no activePolices list")?;
    out.insert("police after you".to_string(), police.invoke("get_Count", &json!([]))?);
    out.insert("times in jail".to_string(), crime.read_field("timesInJail")?);
    // 0 until the police dialog asks the game for a bribe price.
    out.insert("bribe price".to_string(), crime.read_field("latestBribe")?);
    Ok(Json::Object(out))
}
