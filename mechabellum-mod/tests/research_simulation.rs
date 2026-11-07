//! Can the game's own fight simulation be run on the current deploy?
//!
//! Read-only. The names point at a deterministic fixed-point battle
//! (FixedMath, FastSimulationMatch, ReplaySimulateMatch,
//! ForecastAndSpeedUp, docs/research.md); these tests find the classes
//! and how a simulation is started.
//!
//! ```text
//! k3sc cargo-lock test -p mechabellum-mod --test research_simulation -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, ping_or_skip};

const WORDS: &[&str] = &["Simulat", "Forecast", "Replay", "SpeedUp", "FightRecord", "Snapshot", "Predict"];

/// Every type in the game's assemblies whose name holds one of WORDS.
#[test]
fn simulation_types() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for asm in ["GRFight", "GRCore", "GRClient", "GRServer", "FightAuth", "Assembly-CSharp"] {
        let names = unityforge::client::assembly_type_names(&api, asm).unwrap_or_default();
        let hits: Vec<&String> = names.iter().filter(|n| WORDS.iter().any(|w| n.contains(w))).collect();
        println!("{asm}: {} of {} types", hits.len(), names.len());
        for n in hits {
            println!("  {n}");
        }
    }
}

/// What a simulation takes: SimpleSimulator's and FastSimulationMatch's
/// method signatures, and BattleSetting's.
#[test]
fn simulation_signatures() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    unityforge::client::print_method_signatures(&api, "GameRiver.SimpleSimulator", "GRClient", &[]);
    unityforge::client::print_method_signatures(&api, "GameRiver.Client.FastSimulationMatch", "GRClient", &[]);
    unityforge::client::print_method_signatures(&api, "GameRiver.BattleSetting", "GRCore", &[]);
}

/// What goes in and comes out: PlayerRecord, BattleRecord, the fight
/// result, the snapshot system (it takes one for the async mode, Star
/// Expedition) and the replay test tool (a likely caller of the
/// simulator).
#[test]
fn record_signatures() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for (class, asm) in [
        ("GameRiver.PlayerRecord", "GRCore"),
        ("GameRiver.BattleRecord", "GRCore"),
        ("GameRiver.Fight.FightResult", "GRFight"),
        ("GameRiver.SnapshotSystem", "GRCore"),
        ("GameRiver.Client.Tool.ReplayTestTool", "GRClient"),
        ("GameRiver.Client.Tool.ReplayTestToolJob", "GRClient"),
    ] {
        unityforge::client::print_method_signatures(&api, class, asm, &[]);
    }
}

/// Declared methods of the simulation candidates. More names go in
/// MECHABELLUM_SIM_CLASSES (comma separated, with the Il2Cpp prefix).
#[test]
fn simulation_methods() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let mut classes: Vec<String> = [
        "Il2CppGameRiver.Client.FastSimulationMatch",
        "Il2CppGameRiver.Client.ReplaySimulateMatch",
        "Il2CppGameRiver.Client.ForecastAndSpeedUp",
    ]
    .iter()
    .map(|s| s.to_string())
    .collect();
    if let Ok(extra) = std::env::var("MECHABELLUM_SIM_CLASSES") {
        classes.extend(extra.split(',').map(|s| s.trim().to_string()).filter(|s| !s.is_empty()));
    }
    for c in &classes {
        unityforge::client::print_declared_methods(&api, c);
    }
}
