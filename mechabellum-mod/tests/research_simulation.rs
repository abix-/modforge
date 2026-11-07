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

/// Where a copy of the record keeps each player's units, and whether
/// moving one in the copy moves it in the simulation without touching
/// the live record. The copy is CloneableObject.GetDeepCopy (Cpp2IL
/// dump, GRUtility CloneableObject`1).
#[test]
fn record_copy_units() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let call = |h: i64, m: &str, args: serde_json::Value| api.op("invoke_method", json!({"handle": h, "method": m, "args": args}));
    let field = |h: i64, f: &str| handle_of(&api.op("read_field", json!({"handle": h, "field": f})).result);
    let fields = |h: i64| api.op("inspect_object", json!({"handle": h})).result["fields"].as_object().cloned().unwrap_or_default();
    let dump = |label: &str, h: i64| {
        println!("{label}:");
        for (k, v) in fields(h) {
            println!("  {k} = {}", v.get("str").cloned().unwrap_or(v));
        }
    };
    let panels = unityforge::client::find_instances(&api, "GameRiver.Client.ChooseRecommendFormPanel", true).unwrap_or_default();
    let Some(m) = panels.iter().filter_map(handle_of).find_map(|p| field(p, "match")) else {
        println!("no match open");
        return;
    };
    let Some(live) = field(m, "localPlayerController")
        .and_then(|pc| field(pc, "replaySystem"))
        .and_then(|rs| field(rs, "battleRecorder"))
        .and_then(|r| handle_of(&call(r, "GetCurrentRecord", json!([])).result))
    else {
        println!("no battle record");
        return;
    };
    let copy = call(live, "GetDeepCopy", json!([]));
    println!("GetDeepCopy -> {} {:?}", copy.result["il2cpp_type"], copy.error);
    let Some(rec) = handle_of(&copy.result) else { return };
    let rounds = call(rec, "GetRoundCount", json!([])).result.as_i64().unwrap_or(0);
    // GetPlayerRecord has a PlayerController overload the int binds to
    // wrongly; the list field is the same data.
    let got = field(rec, "playerRecords").map(|l| call(l, "get_Item", json!([0])));
    let Some(pr) = got.as_ref().and_then(|g| handle_of(&g.result)) else {
        println!("playerRecords[0] -> {:?}", got.map(|g| (g.result, g.error)));
        dump("battle record copy", rec);
        return;
    };
    dump("player record 0", pr);
    let Some(rr) = handle_of(&call(pr, "GetRoundRecord", json!([rounds - 1])).result) else {
        println!("no round record {}", rounds - 1);
        return;
    };
    dump(&format!("round record {}", rounds - 1), rr);
    let Some(units) = field(rr, "playerData").and_then(|pd| field(pd, "units")) else {
        println!("no playerData.units");
        return;
    };
    let pos = |rec_h: i64| -> serde_json::Value {
        let u = field(rec_h, "playerRecords")
            .and_then(|l| handle_of(&call(l, "get_Item", json!([0])).result))
            .and_then(|p| handle_of(&call(p, "GetRoundRecord", json!([rounds - 1])).result))
            .and_then(|r| field(r, "playerData"))
            .and_then(|pd| field(pd, "units"))
            .and_then(|l| handle_of(&call(l, "get_Item", json!([0])).result));
        u.map(|u| fields(u).get("position").cloned().unwrap_or_default()).unwrap_or_default()
    };
    let Some(u0) = handle_of(&call(units, "get_Item", json!([0])).result) else { return };
    let before = fields(u0)["position"].clone();
    let (x, y) = (before["x"].as_i64().unwrap_or(0), before["y"].as_i64().unwrap_or(0));
    let w = api.op("write_field", json!({"handle": u0, "field": "position", "value": {"x": x - 200, "y": y}}));
    println!("copy unit 0 at ({x}, {y}), write x {} -> ok {} {:?}", x - 200, w.ok, w.error);
    println!("copy unit 0 now {}", pos(rec));
    println!("live unit 0 now {}", pos(live));

    let ms = unityforge::client::first_handle_inactive(&api, "GameRiver.Config")
        .and_then(|c| handle_of(&call(c, "GetMatchSetting", json!([call(rec, "GetMapID", json!([])).result])).result));
    let Some(ms) = ms else {
        println!("no match setting");
        return;
    };
    let ctor = json!([2, {"$handle": ms}, {"$handle": rec}, false, 0, rounds - 1, null]).to_string();
    let bs = api.op("invoke_static", json!({"class": "Unityforge.Shim.Il2CppBridge", "method": "NewObject", "args": ["Il2CppGameRiver.BattleSetting", ctor]}));
    let Some(bs) = handle_of(&bs.result) else {
        println!("BattleSetting: {:?}", bs.error);
        return;
    };
    let sim = api.op("invoke_static", json!({"class": "Il2CppGameRiver.Client.MatchUtility", "method": "StartFastBattleSimulation", "args": [{"$handle": bs}], "timeout_s": 120}));
    let Some(fr) = handle_of(&sim.result).and_then(|s| handle_of(&call(s, "GetFightResult", json!([])).result)) else {
        println!("simulation: {:?}", sim.error);
        return;
    };
    let Some(reports) = field(fr, "reports") else { return };
    for i in 0..common::count_of(&api, reports).unwrap_or(0) {
        let Some(r) = handle_of(&call(reports, "get_Item", json!([i])).result) else { continue };
        let f = fields(r);
        println!("report {i}: alive {} score {}", f["_AliveMechCount_k__BackingField"], f["_Score_k__BackingField"]);
        if let Some(ul) = field(r, "unitDatas") {
            for j in 0..common::count_of(&api, ul).unwrap_or(0) {
                let Some(u) = handle_of(&call(ul, "get_Item", json!([j])).result) else { continue };
                let uf = fields(u);
                println!("  card {} at ({}, {})", uf["id"], uf["position"]["x"], uf["position"]["y"]);
            }
        }
    }
}

/// Can a bought unit be added to a copy of the record? A new
/// NewUnitData (it has a public empty constructor and setters for
/// Index, Position, IsRotate, SellSupply; Cpp2IL dump GRCore
/// NewUnitData) with the card id, the player data's next unitIndex,
/// added to playerData.units, supply taken off. Then the copy is
/// simulated and our report should list one more card. Card and spot:
/// MECHABELLUM_BUY_CARD (default 5028 Hound), at (-200, -200).
#[test]
fn bought_unit_in_copy() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let call = |h: i64, m: &str, args: serde_json::Value| api.op("invoke_method", json!({"handle": h, "method": m, "args": args}));
    let field = |h: i64, f: &str| handle_of(&api.op("read_field", json!({"handle": h, "field": f})).result);
    let fields = |h: i64| api.op("inspect_object", json!({"handle": h})).result["fields"].as_object().cloned().unwrap_or_default();
    let card: i64 = std::env::var("MECHABELLUM_BUY_CARD").ok().and_then(|s| s.parse().ok()).unwrap_or(5028);
    let panels = unityforge::client::find_instances(&api, "GameRiver.Client.ChooseRecommendFormPanel", true).unwrap_or_default();
    let Some(m) = panels.iter().filter_map(handle_of).find_map(|p| field(p, "match")) else {
        println!("no match open");
        return;
    };
    let Some(rec) = field(m, "localPlayerController")
        .and_then(|pc| field(pc, "replaySystem"))
        .and_then(|rs| field(rs, "battleRecorder"))
        .and_then(|r| handle_of(&call(r, "GetCurrentRecord", json!([])).result))
        .and_then(|live| handle_of(&call(live, "GetDeepCopy", json!([])).result))
    else {
        println!("no record copy");
        return;
    };
    let seat = fields(rec)["_Seat_k__BackingField"].as_i64().unwrap_or(0);
    let round = call(rec, "GetRoundCount", json!([])).result.as_i64().unwrap_or(1) - 1;
    let Some(pd) = field(rec, "playerRecords")
        .and_then(|l| handle_of(&call(l, "get_Item", json!([seat])).result))
        .and_then(|p| handle_of(&call(p, "GetRoundRecord", json!([round])).result))
        .and_then(|r| field(r, "playerData"))
    else {
        println!("no player data");
        return;
    };
    let pdf = fields(pd);
    println!("seat {seat} round {round}: supply {} unitIndex {} reactorCore {}", pdf["supply"], pdf["unitIndex"], pdf["reactorCore"]);
    let Some(units) = field(pd, "units") else { return };
    let before = common::count_of(&api, units).unwrap_or(0);
    let nu = api.op("invoke_static", json!({"class": "Unityforge.Shim.Il2CppBridge", "method": "NewObject", "args": ["Il2CppGameRiver.NewUnitData", "[]"]}));
    let Some(u) = handle_of(&nu.result) else {
        println!("new NewUnitData: {:?}", nu.error);
        return;
    };
    let index = pdf["unitIndex"].as_i64().unwrap_or(before);
    for (f, v) in [("id", json!(card)), ("index", json!(index)), ("position", json!({"x": -200, "y": -200})), ("sellSupply", json!(100))] {
        let w = api.op("write_field", json!({"handle": u, "field": f, "value": v}));
        println!("  set {f} = {v}: ok {} {:?}", w.ok, w.error);
    }
    let add = call(units, "Add", json!([{"$handle": u}]));
    println!("units.Add: {:?}; {} -> {} units", add.error, before, common::count_of(&api, units).unwrap_or(0));
    api.op("write_field", json!({"handle": pd, "field": "unitIndex", "value": index + 1}));

    let ms = unityforge::client::first_handle_inactive(&api, "GameRiver.Config")
        .and_then(|c| handle_of(&call(c, "GetMatchSetting", json!([call(rec, "GetMapID", json!([])).result])).result));
    let Some(ms) = ms else { return };
    let ctor = json!([2, {"$handle": ms}, {"$handle": rec}, false, seat, round, null]).to_string();
    let bs = handle_of(&api.op("invoke_static", json!({"class": "Unityforge.Shim.Il2CppBridge", "method": "NewObject", "args": ["Il2CppGameRiver.BattleSetting", ctor]})).result);
    let Some(bs) = bs else { return };
    let sim = api.op("invoke_static", json!({"class": "Il2CppGameRiver.Client.MatchUtility", "method": "StartFastBattleSimulation", "args": [{"$handle": bs}], "timeout_s": 120}));
    let Some(fr) = handle_of(&sim.result).and_then(|s| handle_of(&call(s, "GetFightResult", json!([])).result)) else {
        println!("simulation: {:?}", sim.error);
        return;
    };
    let Some(reports) = field(fr, "reports") else { return };
    for i in 0..common::count_of(&api, reports).unwrap_or(0) {
        let Some(r) = handle_of(&call(reports, "get_Item", json!([i])).result) else { continue };
        let f = fields(r);
        println!("report {i}: alive {} score {}", f["_AliveMechCount_k__BackingField"], f["_Score_k__BackingField"]);
        if let Some(ul) = field(r, "unitDatas") {
            for j in 0..common::count_of(&api, ul).unwrap_or(0) {
                let Some(x) = handle_of(&call(ul, "get_Item", json!([j])).result) else { continue };
                let xf = fields(x);
                println!("  card {} at ({}, {}) index {}", xf["id"], xf["position"]["x"], xf["position"]["y"], xf["index"]);
            }
        }
    }
}

/// The mod's plan_placement op on the live deploy: the start and best
/// placement with their simulated outcomes. Nothing on the field moves.
/// MECHABELLUM_PLAN_BUDGET sets the number of tries (default 80).
#[test]
fn plan_placement_op() {
    let api = api().with_timeout(std::time::Duration::from_secs(900));
    if ping_or_skip(&api).is_none() {
        return;
    }
    let budget: u64 = std::env::var("MECHABELLUM_PLAN_BUDGET").ok().and_then(|s| s.parse().ok()).unwrap_or(80);
    let r = api.op("plan_placement", json!({"budget": budget}));
    if !r.ok {
        println!("plan_placement: {:?}", r.error);
        return;
    }
    println!("{}", serde_json::to_string_pretty(&r.result).unwrap_or_default());
}

/// The mod's plan_deploy op: every way to spend the supply in the shop,
/// each with a placement search, best first. Nothing is bought or moved.
/// MECHABELLUM_PLAN_BUDGET sets tries per choice (default 30).
#[test]
fn plan_deploy_op() {
    let api = api().with_timeout(std::time::Duration::from_secs(1800));
    if ping_or_skip(&api).is_none() {
        return;
    }
    let budget: u64 = std::env::var("MECHABELLUM_PLAN_BUDGET").ok().and_then(|s| s.parse().ok()).unwrap_or(30);
    let r = api.op("plan_deploy", json!({"budget": budget}));
    if !r.ok {
        println!("plan_deploy: {:?}", r.error);
        return;
    }
    println!("{}", serde_json::to_string_pretty(&r.result).unwrap_or_default());
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
