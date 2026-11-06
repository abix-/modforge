//! Fixed changes to the game's numbers, put back on every game load so
//! they survive a restart. Each one was first proven live by a research
//! test, named on its row.
//!
//! K8s slot: Def=ClassNamedFieldTweak (ueforge), Registry=apply_all
//! (bare list), Instance=its per-object vanilla map, Controller=apply_all.
//!
//! apply_all walks the objects once per tweak, so it runs once per game
//! load (from the weapon level watcher when it finds a new save), never on
//! a timer. Each tweak keeps the vanilla value it first saw per object, so
//! running it again does not compound.

use ueforge::data_table::ClassNamedFieldTweak;

/// Weapons whose max level is above 5 go to 100; the 1, 2 and 5 ones stay.
/// Proven by research_weapons.rs set_weapon_max_level.
static MAX_LEVEL: ClassNamedFieldTweak<i32> = ClassNamedFieldTweak::new("FS_WeaponStats", "MaxWeaponLevel");
const MAX_LEVEL_TO: i32 = 100;
const MAX_LEVEL_KEEP_AT_OR_BELOW: i32 = 5;

/// Air dash distance 675 to 1000. Proven by research_dash.rs set_dash_distance.
static AIR_DASH: ClassNamedFieldTweak<f32> = ClassNamedFieldTweak::new("PlayerBalance_C", "FS Air Distance");
const AIR_DASH_TO: f32 = 1000.0;

pub fn apply_all() {
    let live = |o: &ueforge::ue::UObject| !o.is_default_object();
    log(
        "max level",
        MAX_LEVEL.apply(live, |v| (v > MAX_LEVEL_KEEP_AT_OR_BELOW).then_some(MAX_LEVEL_TO)),
    );
    log("air dash", AIR_DASH.apply(live, |_| Some(AIR_DASH_TO)));
}

fn log(what: &str, r: Result<ueforge::ue::class_tweak::ClassTweakStats, String>) {
    match r {
        Ok(s) => ueforge::log!("tweaks: {what}: {} objects, {} changed", s.considered, s.patched),
        Err(e) => ueforge::log!("tweaks: {what}: {e}"),
    }
}
