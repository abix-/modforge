//! What is around the player (operator 2026-10-02: after a door move into
//! the outdoor area loaded alongside, the tenement building looked all
//! black and the door back in was missing).
//!
//! One call to the mod's `near_player` op (src/investigate.rs), which does
//! the scan inside the game in one frame: doors to other areas near the
//! camera with their state, and drawn objects counted by their baked
//! lighting index against the baked lighting list's length (Bakery fills
//! LightmapSettings.lightmaps; an index past the list draws black). An
//! earlier version asked the game per object and ran for minutes.
//!
//! Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_near_player -- --nocapture
//! ```
//!
//! OBENSEUER_NEAR_METRES (default 20). SKIPs (prints why and passes) when
//! the game is not running. Results go to docs/near-player.txt.

mod common;
use common::{api, op, ping_or_skip};
use serde_json::json;

#[test]
fn what_is_near_the_player() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let metres: f64 = std::env::var("OBENSEUER_NEAR_METRES").ok().and_then(|v| v.parse().ok()).unwrap_or(20.0);
    let near = op(&api, "near_player", json!({"metres": metres}));
    let text = serde_json::to_string_pretty(&near).unwrap();
    println!("{text}");
    let path = format!("{}/docs/near-player.txt", env!("CARGO_MANIFEST_DIR"));
    std::fs::write(&path, text + "\n").expect("write the results");
    println!("written to {path}");
}
