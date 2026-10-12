//! Which number is the run timer.
//!
//! Read-only. GameManager.Instance's plain numeric fields read twice, 2
//! seconds apart; the ones that moved are the clock candidates.
//!
//! ```text
//! k3sc cargo-lock test -p megabonk-mod --test research_timer -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, find_instances, game_type_names, handle_of, ping_or_skip};
use serde_json::{Map, Value, json};

/// 2026-10-03: holding GameManager.gameTimer still did not stop the
/// on-screen countdown. Which live object's numbers move with it: every
/// type named after timer, clock or countdown, numbers read 2 s apart,
/// plus GameManager.GetAliveTime / GetStageTimeMax.
#[test]
fn countdown_source() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let gm = handle_of(&api.op("invoke_static", json!({"class": "Il2Cpp.GameManager", "method": "get_Instance", "args": []})).result)
        .expect("GameManager.Instance");
    let gm_reads = || {
        ["GetAliveTime", "GetStageTimeMax", "get_gameTimer"]
            .iter()
            .map(|m| format!("{m}={}", api.op("invoke_method", json!({"handle": gm, "method": m, "args": []})).result))
            .collect::<Vec<_>>()
            .join(", ")
    };
    let names: Vec<String> = game_type_names(&api)
        .into_iter()
        .filter(|n| {
            let s = n.rsplit('.').next().unwrap_or(n).to_ascii_lowercase();
            s.contains("timer") || s.contains("clock") || s.contains("countdown")
        })
        .collect();
    println!("types: {names:?}");
    let mut handles = Vec::new();
    for n in &names {
        for v in find_instances(&api, n, false).unwrap_or_default() {
            if let Some(h) = v.get("handle").and_then(Value::as_i64) {
                handles.push((n.clone(), h));
            }
        }
    }
    let read = |h: i64| -> Map<String, Value> {
        api.op("inspect_object", json!({"handle": h})).result["fields"]
            .as_object()
            .cloned()
            .unwrap_or_default()
            .into_iter()
            .filter(|(_, v)| v.is_number())
            .collect()
    };
    // GameTimer.lastStageSeconds counted down with the on-screen clock
    // (2026-10-03): its methods and every field, to find its source.
    common::print_declared_methods(&api, "Il2Cpp.GameTimer");
    if let Some((_, h)) = handles.iter().find(|(n, _)| n == "GameTimer") {
        println!("GameTimer fields: {}", api.op("inspect_object", json!({"handle": h})).result["fields"]);
    }
    let before: Vec<_> = handles.iter().map(|(_, h)| read(*h)).collect();
    let gm_before = gm_reads();
    std::thread::sleep(std::time::Duration::from_secs(2));
    println!("GameManager: {gm_before}\n          -> {}", gm_reads());
    for ((n, h), a) in handles.iter().zip(before) {
        let b = read(*h);
        for (k, v) in &a {
            let after = b.get(k).cloned().unwrap_or(Value::Null);
            if after != *v {
                println!("{n}.{k}: {v} -> {after}  <- moved");
            }
        }
    }
}

/// GameTimer showed run 14:47 / stage 5:03 left while
/// GameManager.gameTimer read 155 s (2026-10-03), so the display reads
/// another clock. Every static float getter of every type with "time"
/// in its short name, read 2 s apart, plus GameTimer.GetForcedTime.
#[test]
fn static_clocks() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let names: Vec<String> = game_type_names(&api)
        .into_iter()
        .filter(|n| n.rsplit('.').next().unwrap_or(n).to_ascii_lowercase().contains("time"))
        .collect();
    let mut getters = Vec::new();
    for n in &names {
        let interop = if n.contains('.') { format!("Il2Cpp{n}") } else { format!("Il2Cpp.{n}") };
        let r = api.op("list_methods", json!({"class": interop}));
        let empty = vec![];
        for m in r.result["methods"].as_array().unwrap_or(&empty) {
            if m["static"].as_bool() == Some(true)
                && m["params"].as_i64() == Some(0)
                && matches!(m["return"].as_str(), Some("Single" | "Double" | "Int32"))
            {
                getters.push((interop.clone(), m["name"].as_str().unwrap_or("").to_string()));
            }
        }
    }
    let read = |(c, m): &(String, String)| api.op("invoke_static", json!({"class": c, "method": m, "args": []})).result;
    let timer = find_instances(&api, "Il2Cpp.GameTimer", false)
        .unwrap_or_default()
        .first()
        .and_then(|v| v.get("handle"))
        .and_then(Value::as_i64);
    let forced = || timer.map(|h| api.op("invoke_method", json!({"handle": h, "method": "GetForcedTime", "args": []})).result);
    let a: Vec<Value> = getters.iter().map(read).collect();
    let fa = forced();
    std::thread::sleep(std::time::Duration::from_secs(2));
    println!("GameTimer.GetForcedTime: {fa:?} -> {:?}", forced());
    for (g, before) in getters.iter().zip(a) {
        let after = read(g);
        let moved = if after != before { "  <- moved" } else { "" };
        println!("{}.{}: {before} -> {after}{moved}", g.0, g.1);
    }
}

#[test]
fn timer_fields() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let gm = handle_of(&api.op("invoke_static", json!({"class": "Il2Cpp.GameManager", "method": "get_Instance", "args": []})).result)
        .expect("GameManager.Instance");
    let read = || -> Map<String, Value> {
        api.op("inspect_object", json!({"handle": gm})).result["fields"]
            .as_object()
            .cloned()
            .unwrap_or_default()
            .into_iter()
            .filter(|(_, v)| v.is_number() || v.is_boolean())
            .collect()
    };
    let a = read();
    std::thread::sleep(std::time::Duration::from_secs(2));
    let b = read();
    for (k, v) in &a {
        let after = b.get(k).cloned().unwrap_or(Value::Null);
        let moved = if after != *v { "  <- moved" } else { "" };
        println!("{k} = {v} -> {after}{moved}");
    }
    println!("\n== GameManager methods named after time or timer");
    let r = api.op("list_methods", json!({"class": "Il2Cpp.GameManager"}));
    let empty = vec![];
    for m in r.result["methods"].as_array().unwrap_or(&empty) {
        let n = m["name"].as_str().unwrap_or("");
        if n.to_ascii_lowercase().contains("time") || n.to_ascii_lowercase().contains("pause") {
            println!("  {n}({}) -> {}", m["params"], m["return"]);
        }
    }
}
