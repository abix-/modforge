//! How does the Healing Factor perk work on the live player?
//!
//! The game's data (Data/Config):
//! - progression.xml perkHealingFactor: 5 ranks, needing Fortitude
//!   1/3/5/7/10. Each rank adds HealthChangeOT (health per second)
//!   .011/.022/.05/.1/.16, and none of it while the player has
//!   buffStatusHungry03 or buffStatusThirsty03.
//! - buffs.xml: the rank also sets $critHitNaturalHealingRate (how
//!   fast critical injuries heal on their own) to 1/1.2/1.4/1.6/1.8/2
//!   for ranks 0-5.
//! - Stat.Tick (Assembly-CSharp): every point of health regained
//!   costs food and water (FoodLossPerHealthPointGained,
//!   WaterLossPerHealthPointGained).
//!
//! This reads what the local player actually has: perk rank,
//! Fortitude, the hungry/thirsty buffs, the crit healing cvar, and
//! health, food and water sampled over 10 seconds.
//!
//! Read-only: read_field and getter calls only. Nothing here changes
//! game state.
//!
//! ```text
//! k3sc cargo-lock test -p sevendaystodie-mod --test research_healing_factor -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running; with
//! no save loaded there is no EntityPlayerLocal and it says so.

mod common;
use common::{api, call, field_handle, field_value, first_handle, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

fn level(api: &Api<Value>, progression: i64, name: &str) -> Value {
    let pv = call(api, progression, "GetProgressionValue", json!([name]));
    match common::handle_of(&pv) {
        Some(h) => {
            let lvl = field_value(api, h, "level");
            api.op("release_handle", json!({"handle": h}));
            lvl
        }
        None => pv,
    }
}

/// Value and ModifiedMax of one stat (Health, Food, Water).
fn stat(api: &Api<Value>, stats: i64, name: &str) -> (Value, Value) {
    let Some(h) = field_handle(api, stats, name) else {
        return (Value::Null, Value::Null);
    };
    let v = field_value(api, h, "Value");
    let max = field_value(api, h, "ModifiedMax");
    api.op("release_handle", json!({"handle": h}));
    (v, max)
}

#[test]
fn healing_factor_on_the_live_player() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let Some(player) = first_handle(&api, "EntityPlayerLocal") else {
        println!("SKIP: no EntityPlayerLocal; load a save first");
        return;
    };

    let progression = field_handle(&api, player, "Progression").expect("player.Progression");
    println!(
        "perkHealingFactor rank: {}",
        level(&api, progression, "perkHealingFactor")
    );
    println!("attFortitude level:     {}", level(&api, progression, "attFortitude"));

    let buffs = field_handle(&api, player, "Buffs").expect("player.Buffs");
    for b in ["buffStatusHungry03", "buffStatusThirsty03"] {
        println!("{b}: {}", call(&api, buffs, "HasBuff", json!([b])));
    }
    println!(
        "$critHitNaturalHealingRate: {}",
        call(&api, buffs, "GetCustomVar", json!(["$critHitNaturalHealingRate"]))
    );

    let stats = field_handle(&api, player, "entityStats").expect("player.entityStats");
    let sample = |api: &Api<Value>| {
        (
            stat(api, stats, "Health"),
            stat(api, stats, "Food"),
            stat(api, stats, "Water"),
        )
    };
    let (h0, f0, w0) = sample(&api);
    std::thread::sleep(std::time::Duration::from_secs(10));
    let (h1, f1, w1) = sample(&api);
    println!("over 10s (value / max):");
    println!("  Health {} / {} -> {} / {}", h0.0, h0.1, h1.0, h1.1);
    println!("  Food   {} / {} -> {} / {}", f0.0, f0.1, f1.0, f1.1);
    println!("  Water  {} / {} -> {} / {}", w0.0, w0.1, w1.0, w1.1);
    if let (Some(a), Some(b)) = (h0.0.as_f64(), h1.0.as_f64()) {
        println!("  health regen: {:.3} per second", (b - a) / 10.0);
    }

    for h in [stats, buffs, progression, player] {
        api.op("release_handle", json!({"handle": h}));
    }
}
