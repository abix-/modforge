//! Each area's sound (docs/sound.md): for every area loaded, its
//! SoundscapeGlobal (playAtStart, day and night soundscapes and their area),
//! and what SoundscapeController plays now (global, current, background,
//! the trigger the player is in). Read-only.
//!
//! ```text
//! k3sc cargo-lock test -p obenseuer-mod --test research_soundscape -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;

use common::{api, call, call_static, handle_of, instance_of, op, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

fn read(api: &Api<Value>, h: i64, field: &str) -> Value {
    api.op("read_field", json!({"handle": h, "field": field})).result
}

/// "name (area)" of a component held in `field`, or null.
fn named(api: &Api<Value>, h: i64, field: &str) -> String {
    match handle_of(&read(api, h, field)) {
        Some(c) => {
            let name = call(api, c, "get_name", json!([]));
            let area = call_static(api, "Unityforge.Shim.SceneTools", "SceneOf", json!([{"handle": c}]));
            format!("{} ({})", name.as_str().unwrap_or("?"), area.as_str().unwrap_or("?"))
        }
        None => "null".to_string(),
    }
}

#[test]
fn soundscape() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let kept = op(&api, "load_alongside", json!({}));
    println!("current {}", kept["current"]);
    for (area, _) in kept["loaded"].as_object().into_iter().flatten() {
        let Some(g) = handle_of(&call_static(&api, "Unityforge.Shim.FirstCopyGuard", "AreaCopy", json!(["SoundscapeGlobal", area]))) else {
            println!("{area}: no SoundscapeGlobal");
            continue;
        };
        println!(
            "{area}: playAtStart={} day={} night={} current={}",
            read(&api, g, "playAtStart"),
            named(&api, g, "soundscapeDay"),
            named(&api, g, "soundscapeNight"),
            named(&api, g, "currentSoundscape")
        );
    }
    let live = instance_of(&api, "SoundscapeGlobal").ok().flatten();
    println!("\nSoundscapeGlobal.instance in {:?}", live.map(|h| call_static(&api, "Unityforge.Shim.SceneTools", "SceneOf", json!([{"handle": h}]))));
    let sc = instance_of(&api, "SoundscapeController").ok().flatten().expect("SoundscapeController.instance");
    for f in ["currentGlobalSoundscape", "currentSoundscape", "currentBackgroundSoundscape", "currentTrigger"] {
        println!("SoundscapeController.{f} = {}", named(&api, sc, f));
    }
    if let Some(list) = handle_of(&read(&api, sc, "soundscapeAreas")) {
        println!("SoundscapeController.soundscapeAreas count {}", call(&api, list, "get_Count", json!([])));
    }
    if let Some(t) = instance_of(&api, "TimeOfDayAzure").ok().flatten() {
        println!("clock {}", read(&api, t, "currentTimeAndDay"));
    }
}
