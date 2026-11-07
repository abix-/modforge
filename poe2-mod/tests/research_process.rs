//! Can poe2-mod find Path of Exile 2 and read its memory?
//!
//! Read-only. Asks the running poe2-mod for the `game` op: it opens the
//! game with read access only, reads the exe's PE header from memory and
//! checks the build stamp equals the one in the file on disk.
//!
//! ```text
//! cargo run -p poe2-mod            # in one terminal, game running
//! k3sc cargo-lock test -p poe2-mod --test research_process -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when poe2-mod or the game is not running.

use modforge::client::Api;
use serde_json::{Value, json};

#[test]
fn reads_game_build_stamp() {
    let api: Api<Value> = Api::at(17185, "/op");
    let response = match api.try_op("game", json!({})) {
        Ok(r) => r,
        Err(e) => {
            println!("SKIP: poe2-mod not running ({e})");
            return;
        }
    };
    assert!(response.ok, "game op failed: {:?}", response.error);
    let game = response.result;
    println!("{}", serde_json::to_string_pretty(&game).unwrap());
    if game["running"] != json!(true) {
        println!("SKIP: game not running");
        return;
    }
    assert_eq!(game["access"], json!("0x410"), "must open read-only");
    assert_eq!(
        game["stamp_in_memory"], game["stamp_on_disk"],
        "build stamp read from memory differs from the exe on disk"
    );
}
