//! Six council seats: completes the two council seat projects for the
//! player through the mod's grant_council_seats op and checks the
//! game's own TIFactionState.maxCouncilSize reads 6.
//!
//! ```text
//! TERRAINVICTA_DEBUG_PORT=17179 cargo test -p terrainvicta-mod --test council_seats -- --nocapture
//! ```

mod common;
use common::api_or_skip;
use serde_json::json;

#[test]
fn player_has_six_council_seats() {
    let Some(api) = api_or_skip() else { return };
    let r = api.op("grant_council_seats", json!({}));
    assert!(r.ok, "grant_council_seats failed: {:?}", r.error);
    println!("{}", r.result);
    assert_eq!(r.result["max_council_size"], json!(6));
}
