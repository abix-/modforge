//! Does every reader read the running game right?
//!
//! Read-only. Asks the running poe2-mod for each reader's command and
//! prints what it read, for the operator to hold against the screen.
//! A command that fails fails its test.
//!
//! ```text
//! cargo run -p poe2-mod            # in one terminal, game running, in a zone
//! k3sc cargo-lock test -p poe2-mod --test research_readers -- --nocapture --test-threads=1
//! ```
//!
//! SKIPs (prints why and passes) when poe2-mod or the game is not running.

use modforge::client::Api;
use serde_json::{Value, json};
use std::time::Duration;

/// Longest printout per command; the rest is cut.
const PRINT_LIMIT: usize = 6000;

fn op(name: &str, args: Value) -> Option<Value> {
    let api: Api<Value> = Api::at(17185, "/op").with_timeout(Duration::from_secs(120));
    match api.try_op(name, args) {
        Ok(r) if r.ok => {
            let text = serde_json::to_string_pretty(&r.result).unwrap();
            let cut = text.char_indices().nth(PRINT_LIMIT).map_or(text.len(), |(i, _)| i);
            println!("== {name}\n{}", &text[..cut]);
            if cut < text.len() {
                println!("... ({} more bytes)", text.len() - cut);
            }
            Some(r.result)
        }
        Ok(r) if format!("{:?}", r.error).contains("game not running") => {
            println!("SKIP: game not running");
            None
        }
        Ok(r) => panic!("{name} failed: {:?}", r.error),
        Err(e) => {
            println!("SKIP: poe2-mod not running ({e})");
            None
        }
    }
}

#[test]
fn zone() {
    op("zone", json!({}));
}

#[test]
fn player() {
    op("player", json!({}));
}

#[test]
fn entities() {
    op("entities", json!({}));
}

#[test]
fn kinds() {
    op("kinds", json!({}));
}

#[test]
fn health_bars() {
    op("health_bars", json!({}));
}

#[test]
fn buff_bar() {
    op("buff_bar", json!({}));
}

#[test]
fn inventories() {
    op("inventories", json!({}));
}

#[test]
fn ground_items() {
    op("items", json!({}));
}

#[test]
fn ui() {
    op("ui", json!({}));
}

#[test]
fn camera() {
    op("camera", json!({}));
}

#[test]
fn terrain() {
    op("terrain", json!({}));
}

#[test]
fn radar() {
    op("radar", json!({}));
}

#[test]
fn ritual() {
    op("ritual", json!({}));
}

#[test]
fn atlas() {
    op("atlas", json!({}));
}

#[test]
fn preload() {
    // No preload list ships yet; an empty one still reads the counter
    // and this area's files.
    op("preload", json!({"defs": []}));
}
