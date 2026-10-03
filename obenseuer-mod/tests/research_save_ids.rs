//! Design question 2, second half (docs/kept-areas.md, history, "Proper
//! design"): do every area's own copies of the live player and managers
//! save under the same GUIDs? research_live_roots_saving.rs found the live
//! top objects (Game_Logic, Player, Player Camera Base) hold area-file
//! scripts too (relays, PersistLocation). Saving them with another area
//! is right only if that area's own copies use the same GUIDs.
//!
//! Lists the GUID of every copy (live and the switched-off copies of areas
//! kept loaded) of a few such classes, with each copy's top object path.
//!
//! Read-only. Needs areas kept loaded.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_save_ids -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, call, copies, ping_or_skip, top_path};
use serde_json::json;

#[test]
fn copies_save_ids() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for class in ["PlayerStats", "Inventory", "PersistLocation", "SleepEventController", "DestructibleList"] {
        let list = copies(&api, class);
        println!("\n{class}: {} copies", list.len());
        for (_, h) in list.iter().take(12) {
            let guid = api.op("read_field", json!({"handle": h, "field": "GUID"})).result;
            let on = call(&api, *h, "get_isActiveAndEnabled", json!([]));
            println!("  GUID {guid:<40} on {on:<5} {}", top_path(&api, *h));
        }
    }
}
