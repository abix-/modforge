//! Does an AI controller join this game as a player? The Lyra bot pattern
//! (spawn the AI controller with a PlayerState, run the game mode's
//! RestartPlayer) applied to Abiotic Factor's own classes. Live; run with the
//! hosted save loaded and the human standing somewhere open.
//!
//! ```text
//! k3sc cargo-lock test -p abioticfactor-mod --test research_bot_player -- --nocapture
//! ```
//!
//! Pass: the controller has a PlayerState, its Pawn is an
//! Abiotic_PlayerCharacter_C, and the human sees a second character. Fail
//! output names which of those the game refused.

mod common;
use common::{api, human_name, ping_or_skip};
use serde_json::json;

#[test]
fn ai_controller_joins_as_a_player() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    let human = human_name(&api, "Sophia");
    let reply = api.op("ai_player.bot", json!({"near_player": human}));
    println!("ai_player.bot: {}", if reply.ok { reply.result.to_string() } else { format!("{:?}", reply.error) });
    assert!(reply.ok, "ai_player.bot: {:?}", reply.error);
    let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client/bot-join.json");
    std::fs::write(&path, serde_json::to_vec_pretty(&reply.result).unwrap()).unwrap();
    let result = &reply.result;
    assert!(!result["player_state"].is_null(), "the AI controller got no PlayerState");
    assert_eq!(result["pawn"]["class"], "Abiotic_PlayerCharacter_C", "RestartPlayer did not give it the player pawn class: {}", result["pawn"]);

    // The body waits at the world start holding spot; the player controller's
    // Request_SpawnMeInWorld would teleport it down. Do that one step with the
    // character's own TeleportPlayer and read what possession left behind.
    let signature = api.op("function_parameters", json!({"class": "Abiotic_PlayerCharacter_C", "function": "TeleportPlayer"}));
    println!("TeleportPlayer live parameters: {}", if signature.ok { signature.result.to_string() } else { format!("{:?}", signature.error) });
    let controller = result["controller"]["addr"].as_str().unwrap().to_owned();
    let placed = api.op("ai_player.bot_place", json!({"controller": controller}));
    println!("ai_player.bot_place: {}", if placed.ok { placed.result.to_string() } else { format!("{:?}", placed.error) });
    assert!(placed.ok, "ai_player.bot_place: {:?}", placed.error);
    let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client/bot-place.json");
    std::fs::write(&path, serde_json::to_vec_pretty(&placed.result).unwrap()).unwrap();
    assert_eq!(placed.result["teleported"], true, "TeleportPlayer refused");
}
