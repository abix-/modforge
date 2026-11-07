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
use common::{api, handle_of, ping_or_skip};
use serde_json::json;

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

/// The live match's battle setting and record: the runtime class of
/// match.battleInfo, its GetBattleRecord(), the record's player and
/// round counts, and each player's record name and round count.
#[test]
fn live_record() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let call = |h: i64, m: &str, args: serde_json::Value| api.op("invoke_method", json!({"handle": h, "method": m, "args": args}));
    let field = |h: i64, f: &str| handle_of(&api.op("read_field", json!({"handle": h, "field": f})).result);
    let panels = unityforge::client::find_instances(&api, "GameRiver.Client.ChooseRecommendFormPanel", true).unwrap_or_default();
    let Some(m) = panels.iter().filter_map(handle_of).find_map(|p| field(p, "match")) else {
        println!("no match open");
        return;
    };
    let info = api.op("read_field", json!({"handle": m, "field": "battleInfo"}));
    println!("battleInfo is {}", info.result["il2cpp_type"]);
    // battleInfo is a plain BattleInfo, not a BattleSetting, so it has
    // no GetBattleRecord (2026-11-07). The record should be on a match
    // module (SnapshotSystem.lastRecord) or the player's replaySystem.
    let mut record = None;
    if let Some(mods) = field(m, "modules") {
        for i in 0..common::count_of(&api, mods).unwrap_or(0) {
            let md = call(mods, "get_Item", json!([i]));
            println!("module {i}: {}", md.result["il2cpp_type"]);
            if md.result["il2cpp_type"].as_str().is_some_and(|t| t.ends_with("SnapshotSystem"))
                && let Some(h) = handle_of(&md.result)
            {
                let last = api.op("read_field", json!({"handle": h, "field": "lastRecord"}));
                println!("  SnapshotSystem.lastRecord -> {}", last.result["il2cpp_type"]);
                record = record.or(handle_of(&last.result));
            }
        }
    }
    if let Some(rs) = field(m, "localPlayerController").and_then(|pc| field(pc, "replaySystem")) {
        println!("--- localPlayerController.replaySystem:");
        for (k, v) in api.op("inspect_object", json!({"handle": rs})).result["fields"].as_object().cloned().unwrap_or_default() {
            println!("  {k} = {}", v.get("str").cloned().unwrap_or(v));
        }
        record = record.or(field(rs, "battleRecord")).or(field(rs, "record"));
    }
    unityforge::client::print_method_signatures(&api, "GameRiver.ReplaySystem", "GRCore", &[]);
    let Some(rec_h) = record else {
        println!("no battle record found");
        return;
    };
    for g in ["GetPlayerCount", "GetRoundCount", "IsValid", "GetGameMode", "GetMapID", "GetBattleID", "GetAvaliableStartRound"] {
        println!("  {g} = {}", call(rec_h, g, json!([])).result);
    }
    let players = call(rec_h, "GetPlayerCount", json!([])).result.as_i64().unwrap_or(0);
    for i in 0..players {
        let pr = call(rec_h, "GetPlayerRecord", json!([i]));
        let Some(pr_h) = handle_of(&pr.result) else { continue };
        println!(
            "  player {i}: {} rounds {} final {} ai {}",
            call(pr_h, "GetName", json!([])).result,
            call(pr_h, "GetRoundCount", json!([])).result,
            call(pr_h, "GetFinalRound", json!([])).result,
            call(pr_h, "IsAIRecord", json!([])).result,
        );
        if let Some(rr) = handle_of(&call(pr_h, "GetRoundRecord", json!([0])).result) {
            println!("    round 0 record:");
            for (k, v) in api.op("inspect_object", json!({"handle": rr})).result["fields"].as_object().cloned().unwrap_or_default() {
                println!("      {k} = {}", v.get("str").cloned().unwrap_or(v));
            }
        }
    }
}

/// Runs the game's own simulator on the live deploy, the way its fight
/// check does (FightAuth Main.SimpleAuth in the Cpp2IL dump): a
/// BattleSetting(matchType 2, matchSetting, record, singlePlayer
/// false, playerRecordIndex 0, startRound) handed to
/// MatchUtility.StartFastBattleSimulation, then the simulator's
/// GetFightResult. The record is a clone, so the live match is not
/// handed to the simulator. MECHABELLUM_SIM_START_ROUND overrides the
/// start round (default: the record's last round).
///
/// Needs the deploy screen open. This runs a whole fight on the main
/// thread; it can stall or crash the game.
#[test]
fn run_game_simulation() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let call = |h: i64, m: &str, args: serde_json::Value| api.op("invoke_method", json!({"handle": h, "method": m, "args": args}));
    let field = |h: i64, f: &str| handle_of(&api.op("read_field", json!({"handle": h, "field": f})).result);
    let dump = |label: &str, h: i64| {
        println!("{label}:");
        for (k, v) in api.op("inspect_object", json!({"handle": h})).result["fields"].as_object().cloned().unwrap_or_default() {
            println!("  {k} = {}", v.get("str").cloned().unwrap_or(v));
        }
    };
    let panels = unityforge::client::find_instances(&api, "GameRiver.Client.ChooseRecommendFormPanel", true).unwrap_or_default();
    let Some(m) = panels.iter().filter_map(handle_of).find_map(|p| field(p, "match")) else {
        println!("no match open");
        return;
    };

    // The record: the recorder's current one, else the snapshot's last.
    let recorder = field(m, "localPlayerController").and_then(|pc| field(pc, "replaySystem")).and_then(|rs| field(rs, "battleRecorder"));
    let mut record = recorder.and_then(|r| handle_of(&call(r, "GetCurrentRecord", json!([])).result));
    println!("battleRecorder.GetCurrentRecord -> {record:?}");
    if record.is_none()
        && let Some(mods) = field(m, "modules")
    {
        for i in 0..common::count_of(&api, mods).unwrap_or(0) {
            let md = call(mods, "get_Item", json!([i]));
            if md.result["il2cpp_type"].as_str().is_some_and(|t| t.ends_with("SnapshotSystem")) {
                record = handle_of(&md.result).and_then(|h| field(h, "lastRecord"));
            }
        }
        println!("SnapshotSystem.lastRecord -> {record:?}");
    }
    let Some(live_rec) = record else {
        println!("no battle record");
        return;
    };
    let clone = call(live_rec, "Clone", json!([]));
    println!("record.Clone -> {} {:?}", clone.result["il2cpp_type"], clone.error);
    let rec = handle_of(&clone.result).unwrap_or(live_rec);
    let rounds = call(rec, "GetRoundCount", json!([])).result.as_i64().unwrap_or(0);
    let map = call(rec, "GetMapID", json!([])).result.as_i64().unwrap_or(0);
    println!("record: {rounds} rounds, map {map}, players {}", call(rec, "GetPlayerCount", json!([])).result);

    // The match setting: the match's own, else the config's for the map.
    let mut setting = field(m, "matchSetting");
    println!("match.matchSetting -> {setting:?}");
    if setting.is_none() {
        let cfg = unityforge::client::first_handle_inactive(&api, "GameRiver.Config");
        setting = cfg.and_then(|c| {
            let r = call(c, "GetMatchSetting", json!([map]));
            println!("Config.GetMatchSetting({map}) -> {} {:?}", r.result["il2cpp_type"], r.error);
            handle_of(&r.result)
        });
    }
    let Some(ms) = setting else {
        println!("no match setting");
        return;
    };

    let start: i64 = std::env::var("MECHABELLUM_SIM_START_ROUND").ok().and_then(|s| s.parse().ok()).unwrap_or((rounds - 1).max(0));
    let ctor_args = json!([2, {"$handle": ms}, {"$handle": rec}, false, 0, start, null]).to_string();
    let bs = api.op(
        "invoke_static",
        json!({"class": "Unityforge.Shim.Il2CppBridge", "method": "NewObject", "args": ["Il2CppGameRiver.BattleSetting", ctor_args]}),
    );
    println!("new BattleSetting(start round {start}) -> {} {:?}", bs.result["il2cpp_type"], bs.error);
    let Some(bs_h) = handle_of(&bs.result) else { return };

    let t = std::time::Instant::now();
    let sim = api.op(
        "invoke_static",
        json!({"class": "Il2CppGameRiver.Client.MatchUtility", "method": "StartFastBattleSimulation", "args": [{"$handle": bs_h}], "timeout_s": 120}),
    );
    println!("StartFastBattleSimulation -> {} {:?} in {:.2}s", sim.result["il2cpp_type"], sim.error, t.elapsed().as_secs_f64());
    let Some(sim_h) = handle_of(&sim.result) else { return };
    let fr = call(sim_h, "GetFightResult", json!([]));
    println!("GetFightResult -> {} {:?}", fr.result["il2cpp_type"], fr.error);
    if let Some(fr_h) = handle_of(&fr.result) {
        dump("fight result", fr_h);
        if let Some(reports) = field(fr_h, "reports") {
            for i in 0..common::count_of(&api, reports).unwrap_or(0) {
                if let Some(r) = handle_of(&call(reports, "get_Item", json!([i])).result) {
                    dump(&format!("report {i}"), r);
                    if let Some(rec) = field(r, "_FightRecord_k__BackingField") {
                        dump(&format!("report {i} fight record"), rec);
                    }
                    if let Some(units) = field(r, "unitDatas") {
                        let n = common::count_of(&api, units).unwrap_or(0);
                        println!("report {i}: {n} unit datas");
                        for j in 0..n {
                            let Some(u) = handle_of(&call(units, "get_Item", json!([j])).result) else { continue };
                            let f = api.op("inspect_object", json!({"handle": u})).result["fields"].clone();
                            println!("  card {} at ({}, {}) rotated {} exp {}", f["id"], f["position"]["x"], f["position"]["y"], f["isRotate"], f["exp"]);
                        }
                    }
                }
            }
        }
    } else {
        println!("  {}", fr.result);
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
