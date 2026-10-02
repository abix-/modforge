//! What Obenseuer keeps about the player's crimes (the "wanted level"
//! for the modforge pane's mini HUD, operator 2026-10-02): the Crime
//! object's fields and the crime records it holds, read from the
//! running game.
//!
//! Read-only: walk_class and inspect_object only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_crime -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, find_instances, handle_of, ping_or_skip};
use serde_json::json;

/// Undo what the first run of crime_fields_read did to the save: it called
/// CalculateBribe, which stored a bribe price in latestBribe that only a
/// paid bribe clears. Puts latestBribe back to 0, as the game has it
/// before the police first ask. Changes the game, so it only runs on
/// purpose:
///
/// ```text
/// k3sc cargo-lock test -p obenseuer-mod --test research_crime -- --ignored bribe_price_cleared --nocapture
/// ```
#[test]
#[ignore]
fn bribe_price_cleared() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let found = find_instances(&api, "Crime", true).expect("walk_class Crime");
    let h = found.first().and_then(handle_of).expect("the game has a Crime object");
    let before = api.op("read_field", json!({"handle": h, "field": "latestBribe"}));
    api.op("write_field", json!({"handle": h, "field": "latestBribe", "value": 0}));
    let after = api.op("read_field", json!({"handle": h, "field": "latestBribe"}));
    println!("latestBribe: {} -> {}", before.result, after.result);
    api.op("release_handle", json!({"handle": h}));
    assert_eq!(after.result, json!(0), "latestBribe is back to 0");
}

/// The mini HUD's crime op answers from the running game, as the
/// Claude Code modforge pane asks it.
#[test]
fn crime_hud_op_answers() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let r = api.try_op("crime", json!({}));
    match &r {
        Ok(ok) => println!("crime op: ok={} error={:?} result={}", ok.ok, ok.error, ok.result),
        Err(e) => println!("crime op failed: {e}"),
    }
    let r = r.expect("the crime op answered");
    assert!(r.result.get("fine").is_some(), "the answer has the fine: {}", r.result);
}

/// Every Crime object the game has and every field on it, printed whole.
#[test]
fn crime_fields_read() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let found = find_instances(&api, "Crime", true).expect("walk_class Crime");
    println!("{} Crime objects", found.len());
    assert!(!found.is_empty(), "the game has a Crime object");
    for c in &found {
        let h = handle_of(c).expect("a handle for the Crime object");
        let dump = api.op("inspect_object", json!({"handle": h}));
        println!("{}", serde_json::to_string_pretty(&dump.result).unwrap_or_default());
        // How many crimes are on record and how many police are after the
        // player, and every crime record whole.
        for list in ["crimeRecord", "activePolices"] {
            let field = dump.result["properties"]
                .as_array()
                .and_then(|ps| ps.iter().find(|p| p["name"] == list))
                .and_then(|p| handle_of(&p["value"]));
            let Some(l) = field else { continue };
            let n = api.op("invoke_method", json!({"handle": l, "method": "get_Count", "args": []}));
            println!("{list}: {} entries", n.result);
            for i in 0..n.result.as_i64().unwrap_or(0) {
                let item = api.op("invoke_method", json!({"handle": l, "method": "get_Item", "args": [i]}));
                let Some(ih) = handle_of(&item.result) else { continue };
                let one = api.op("inspect_object", json!({"handle": ih}));
                println!("{list}[{i}]: {}", one.result);
                api.op("release_handle", json!({"handle": ih}));
            }
        }
        // The game's own answers for the player's standing. Each read in
        // the decompiled Crime and found to change nothing. Never
        // CalculateBribe: it stores its price in latestBribe, which only a
        // paid bribe clears (operator's save, 2026-10-02).
        for m in [
            "GetCrimeAmount",
            "GetCrimeFineAmount",
            "GetSentenceLengthInHours",
            "GetSentenceLengthString",
            "CanPayFine",
            "CanBribe",
            "HasStolenGoods",
            "CountStolenGoodsValue",
            "get_ArrestInProgress",
        ] {
            let r = api.op("invoke_method", json!({"handle": h, "method": m, "args": []}));
            println!("{m}: {}", r.result);
        }
        api.op("release_handle", json!({"handle": h}));
    }
    // What a crime record is, whether or not the player has one now.
    let methods = api.op("list_methods", json!({"class": "CrimeRecord"}));
    println!("CrimeRecord: {}", methods.result);
    // How the game turns the records into a fine, prison time or arrest.
    let methods = api.op("list_methods", json!({"class": "Crime"}));
    println!("Crime methods: {}", methods.result);
}
