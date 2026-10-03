//! Every watched manager's one copy right now (common::WATCHED and
//! SoundscapeController): its instance id, or why
//! not, with the bridge's error. Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_managers_live -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;

use common::{WATCHED, api, instance_now, ping_or_skip};

#[test]
fn managers_live() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for class in WATCHED.iter().copied().chain(["SoundscapeController", "OpenSewerCharacterController"]) {
        println!("{class}: {}", instance_now(&api, class));
    }
}
