//! Why LavaLamp.Update throws every frame (operator 2026-10-02: 3533
//! NullReferenceExceptions at LavaLamp.Update after a save made away from
//! home was loaded). Update reads `material` (LavaLamp.cs, Update), which
//! Start replaces with a new Material and OnDestroy destroys.
//!
//! Lists every LavaLamp: on or not, its material field, its top object.
//!
//! Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_lava_lamps -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, call, copies, ping_or_skip, top_path};
use serde_json::json;

#[test]
fn lava_lamps_listed() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let lamps = copies(&api, "LavaLamp");
    println!("{} LavaLamp", lamps.len());
    for (id, h) in lamps {
        let on = call(&api, h, "get_isActiveAndEnabled", json!([]));
        let material = api.op("read_field", json!({"handle": h, "field": "material"})).result;
        println!("  {id} on {on} material {material}  {}", top_path(&api, h));
    }
}
