//! The game still knows the player's character (operator 2026-10-02:
//! areas loaded alongside took over PlayerIdentity.identity, and the
//! save fell back to the name "Esko_Virtanen", SaveController.cs:486-498).
//! first_copy_wins now guards every class with a public static field of
//! its own type, PlayerIdentity included.
//!
//! Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_identity -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, call, call_static, copies, handle_of, ping_or_skip, top_path};
use serde_json::json;

#[test]
fn player_identity_is_the_players() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let t = handle_of(&call_static(&api, "System.Type", "GetType", json!(["PlayerIdentity, Assembly-CSharp"]))).expect("PlayerIdentity type");
    let f = handle_of(&call(&api, t, "GetField", json!(["identity"]))).expect("identity field");
    let id = handle_of(&call(&api, f, "GetValue", json!([null]))).expect("PlayerIdentity.identity is set");
    let first = api.op("read_field", json!({"handle": id, "field": "firstName"})).result;
    let last = api.op("read_field", json!({"handle": id, "field": "lastName"})).result;
    println!("PlayerIdentity.identity: {first} {last}  ({})", top_path(&api, id));
    println!("{} PlayerIdentity copies loaded", copies(&api, "PlayerIdentity").len());
    assert_eq!(first.as_str(), Some("Tom"), "the game's player identity is not the player's");
}
