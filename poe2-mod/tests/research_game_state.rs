//! Do the static patterns find the game's globals, and does the game
//! state read right?
//!
//! Read-only. Asks the running poe2-mod for `statics` (every pattern
//! from GameHelper2 and ExileCore2, searched in the game's exe read from
//! memory) and `game_state` (the current state, read like GameHelper2's
//! GameStates).
//!
//! ```text
//! cargo run -p poe2-mod            # in one terminal, game running
//! k3sc cargo-lock test -p poe2-mod --test research_game_state -- --nocapture
//! ```
//!
//! Run it at the login screen, in a loading screen and in a zone: the
//! state should read LoginState, AreaLoadingState and InGameState.
//! SKIPs (prints why and passes) when poe2-mod or the game is not running.

use modforge::client::Api;
use serde_json::{Value, json};

fn op(name: &str) -> Option<Value> {
    let api: Api<Value> = Api::at(17185, "/op");
    match api.try_op(name, json!({})) {
        Ok(r) if r.ok => Some(r.result),
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
fn game_states_pattern_found_by_both_tools() {
    let Some(statics) = op("statics") else { return };
    println!("{}", serde_json::to_string_pretty(&statics).unwrap());
    assert_eq!(
        statics["agree"]["Game States"],
        json!(true),
        "GameHelper2's and ExileCore2's Game States patterns must find one address"
    );
}

#[test]
fn reads_current_game_state() {
    let Some(state) = op("game_state") else {
        return;
    };
    println!("{}", serde_json::to_string_pretty(&state).unwrap());
    assert!(
        state["current_name"].is_string(),
        "current state {} is none of the thirteen states",
        state["current"]
    );
}
