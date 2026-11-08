//! Does poe2-mod get prices from poe.ninja?
//!
//! Asks the running poe2-mod for the `prices` op, which fetches every
//! poe.ninja exchange and stash overview for the league (GameHelper2
//! LootValue's types) and keeps them. Does not touch the game.
//!
//! ```text
//! cargo run -p poe2-mod            # in one terminal
//! k3sc cargo-lock test -p poe2-mod --test research_prices -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when poe2-mod is not running.

use modforge::client::Api;
use serde_json::{Value, json};

#[test]
fn fetches_poe_ninja_prices() {
    // One request per poe.ninja type, one after another.
    let api: Api<Value> = Api::at(17185, "/op").with_timeout(std::time::Duration::from_secs(120));
    let league = std::env::var("POE2_LEAGUE").unwrap_or_else(|_| "Forbidden Rites".into());
    let response = match api.try_op("prices", json!({"league": league})) {
        Ok(r) => r,
        Err(e) => {
            println!("SKIP: poe2-mod not running ({e})");
            return;
        }
    };
    assert!(response.ok, "prices op failed: {:?}", response.error);
    let r = response.result;
    println!("{}", serde_json::to_string_pretty(&r).unwrap());
    assert_eq!(r["failed"], json!([]), "some poe.ninja types failed");
    assert!(
        r["prices"].as_u64().unwrap_or(0) > 0,
        "no prices for league {league}"
    );
}
