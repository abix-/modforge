//! How far from a crafting table can ingredients sit?
//!
//! Read-only on purpose: type walk, walk_class, inspect_object and
//! list_methods only. Nothing here can change game state.
//!
//! ```text
//! k3sc cargo-lock test -p thewalkingtrade-mod --test research_crafting -- --test-threads=1 --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when the game is not running.

mod common;
use common::{api, count_of, handle_of, ping_or_skip};
use serde_json::{Value, json};
use unityforge::client::Api;

const KEYWORDS: &[&str] = &["craft", "bench", "table", "station", "recipe", "workshop"];

fn release(api: &Api<Value>, h: i64) {
    api.op("release_handle", json!({"handle": h}));
}

/// Full names of every type in the assembly whose full name starts
/// with `prefix`, read through the IL2CPP AppDomain so each step
/// hands back a chainable handle.
fn game_type_names(api: &Api<Value>, prefix: &str) -> Vec<String> {
    let domain = api.op(
        "invoke_static",
        json!({"class": "Il2CppSystem.AppDomain", "method": "get_CurrentDomain", "args": []}),
    );
    let Some(domain_h) = handle_of(&domain.result) else {
        panic!("get_CurrentDomain: {:?} {:?}", domain.result, domain.error);
    };
    let asms = api.op(
        "invoke_method",
        json!({"handle": domain_h, "method": "GetAssemblies", "args": []}),
    );
    let asms_h = handle_of(&asms.result).expect("GetAssemblies carried no handle");
    let asm_count = count_of(api, asms_h).unwrap_or(0);
    let mut asm_h = None;
    for i in 0..asm_count {
        let item = api.op(
            "invoke_method",
            json!({"handle": asms_h, "method": "get_Item", "args": [i]}),
        );
        let Some(h) = handle_of(&item.result) else { continue };
        let full = api.op(
            "invoke_method",
            json!({"handle": h, "method": "get_FullName", "args": []}),
        );
        if full.result.as_str().unwrap_or("").starts_with(prefix) {
            asm_h = Some(h);
            break;
        }
        release(api, h);
    }
    release(api, asms_h);
    release(api, domain_h);
    let asm_h = asm_h.unwrap_or_else(|| panic!("no assembly starting {prefix}"));

    let types = api.op(
        "invoke_method",
        json!({"handle": asm_h, "method": "GetTypes", "args": []}),
    );
    let seq = handle_of(&types.result).expect("GetTypes carried no handle");
    let n = count_of(api, seq).unwrap_or(0);
    let mut out = Vec::new();
    for i in 0..n {
        let item = api.op(
            "invoke_method",
            json!({"handle": seq, "method": "get_Item", "args": [i]}),
        );
        let Some(th) = handle_of(&item.result) else { continue };
        let name = api.op(
            "invoke_method",
            json!({"handle": th, "method": "get_FullName", "args": []}),
        );
        release(api, th);
        if let Some(s) = name.result.as_str() {
            out.push(s.to_string());
        }
    }
    release(api, seq);
    release(api, asm_h);
    out
}

/// Names and type counts of every loaded assembly.
#[test]
fn assemblies() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let domain = api.op(
        "invoke_static",
        json!({"class": "Il2CppSystem.AppDomain", "method": "get_CurrentDomain", "args": []}),
    );
    let domain_h = handle_of(&domain.result).expect("get_CurrentDomain carried no handle");
    let asms = api.op(
        "invoke_method",
        json!({"handle": domain_h, "method": "GetAssemblies", "args": []}),
    );
    let asms_h = handle_of(&asms.result).expect("GetAssemblies carried no handle");
    let n = count_of(&api, asms_h).unwrap_or(0);
    for i in 0..n {
        let item = api.op(
            "invoke_method",
            json!({"handle": asms_h, "method": "get_Item", "args": [i]}),
        );
        let Some(h) = handle_of(&item.result) else { continue };
        let name = api.op(
            "invoke_method",
            json!({"handle": h, "method": "get_FullName", "args": []}),
        );
        println!("  {}", name.result.as_str().unwrap_or("?"));
        release(&api, h);
    }
    release(&api, asms_h);
    release(&api, domain_h);
}

/// Fields of one live crafting station, then its methods whose
/// names hint at how nearby items are found.
#[test]
fn craft_station() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let class = "Runtime.Item.CraftStationObject";
    let list = common::find_instances(&api, class, false).unwrap_or_default();
    println!("{class}: {} instance(s)", list.len());
    for (i, v) in list.iter().enumerate() {
        let Some(h) = handle_of(v) else { continue };
        if i == 0 {
            let f = common::fields(&api, h).unwrap_or(Value::Null);
            println!("{}", serde_json::to_string_pretty(&f).unwrap_or_default());
        }
        release(&api, h);
    }

    let full = format!("Il2Cpp{class}");
    let r = api.op("list_methods", json!({"class": full}));
    if !r.ok {
        println!("list_methods({full}) failed: {:?}", r.error);
        return;
    }
    let empty = vec![];
    for m in r.result["methods"].as_array().unwrap_or(&empty) {
        let name = m["name"].as_str().unwrap_or("");
        let l = name.to_ascii_lowercase();
        if ["range", "radius", "distance", "near", "overlap", "ingredient", "find", "around", "item"]
            .iter()
            .any(|k| l.contains(k))
        {
            println!(
                "method {name}({}) -> {}  [on {}]",
                m["params"].as_i64().unwrap_or(0),
                m["return"].as_str().unwrap_or("?"),
                m["declared_on"].as_str().unwrap_or("?")
            );
        }
    }
}

/// Size and centre of every box in each station's _itemsCollider:
/// the area items must sit in to count for crafting. Read-only.
#[test]
fn craft_station_item_boxes() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = common::find_instances(&api, "Runtime.Item.CraftStationObject", false)
        .unwrap_or_default();
    for (i, v) in list.iter().enumerate() {
        let Some(st) = handle_of(v) else { continue };
        let name = v.get("name").and_then(Value::as_str).unwrap_or("?");
        let level = api.op("read_field", json!({"handle": st, "field": "_level"}));
        println!("station {i} '{name}' level {}", level.result);
        let arr = api.op("read_field", json!({"handle": st, "field": "_itemsCollider"}));
        if let Some(ah) = handle_of(&arr.result) {
            let n = count_of(&api, ah).unwrap_or(0);
            for j in 0..n {
                let item = api.op(
                    "invoke_method",
                    json!({"handle": ah, "method": "get_Item", "args": [j]}),
                );
                let Some(bh) = handle_of(&item.result) else {
                    println!("  box {j} = {}", item.result);
                    continue;
                };
                let size = api.op("invoke_method", json!({"handle": bh, "method": "get_size", "args": []}));
                let center = api.op("invoke_method", json!({"handle": bh, "method": "get_center", "args": []}));
                let scale = api.op("invoke_method", json!({"handle": bh, "method": "get_transform", "args": []}));
                let lossy = handle_of(&scale.result).map(|th| {
                    let s = api.op("invoke_method", json!({"handle": th, "method": "get_lossyScale", "args": []}));
                    release(&api, th);
                    s.result
                });
                let go_name = api.op("invoke_method", json!({"handle": bh, "method": "ToString", "args": []})).result;
                println!(
                    "  box {j}: {go_name} size {}  center {}  world scale {:?}",
                    size.result, center.result, lossy
                );
                release(&api, bh);
            }
            release(&api, ah);
        }
        release(&api, st);
    }
}

/// Original _itemsCollider box sizes per station, read live by
/// craft_station_item_boxes on 2026-09-29.
const BOX_SIZES: &[(&str, &[(f64, f64, f64)])] = &[
    ("CraftingStationLevel1", &[(0.90, 2.19, 2.37)]),
    ("CraftingStationLevel2", &[(3.49, 4.00, 6.00)]),
    ("CraftingStationLevel3", &[(13.93, 6.06, 19.93)]),
    (
        "CraftingStationLevel4",
        &[(13.93, 6.06, 19.93), (10.93, 6.55, 42.61)],
    ),
];
const BOX_FACTOR: f64 = 50.0;

/// Sets every station's item boxes to BOX_FACTOR x the original
/// size. CHANGES GAME STATE. Targets are fixed from BOX_SIZES, so
/// a rerun stays at BOX_FACTOR x instead of compounding.
#[test]
fn craft_station_boxes_write() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = common::find_instances(&api, "Runtime.Item.CraftStationObject", false)
        .unwrap_or_default();
    for v in &list {
        let Some(st) = handle_of(v) else { continue };
        let name = v.get("name").and_then(Value::as_str).unwrap_or("?");
        let Some((_, sizes)) = BOX_SIZES.iter().find(|(n, _)| *n == name) else {
            println!("skip '{name}': no recorded box sizes");
            release(&api, st);
            continue;
        };
        let arr = api.op("read_field", json!({"handle": st, "field": "_itemsCollider"}));
        let Some(ah) = handle_of(&arr.result) else {
            release(&api, st);
            continue;
        };
        for (j, (x, y, z)) in sizes.iter().enumerate() {
            let item = api.op(
                "invoke_method",
                json!({"handle": ah, "method": "get_Item", "args": [j]}),
            );
            let Some(bh) = handle_of(&item.result) else { continue };
            let want = json!({"x": x * BOX_FACTOR, "y": y * BOX_FACTOR, "z": z * BOX_FACTOR});
            let w = api.op(
                "invoke_method",
                json!({"handle": bh, "method": "set_size", "args": [want]}),
            );
            assert!(w.ok, "{name} box {j} set_size failed: {:?}", w.error);
            let after = api.op("invoke_method", json!({"handle": bh, "method": "get_size", "args": []}));
            println!("{name} box {j}: size now {}", after.result);
            release(&api, bh);
        }
        release(&api, ah);
        release(&api, st);
    }
}

/// Game types about hired staff and their hours. Read-only.
#[test]
fn staff_types() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let mut names = game_type_names(&api, "Runtime,");
    names.sort();
    for n in names.iter().filter(|n| !n.contains('<')).filter(|n| {
        let l = n.to_ascii_lowercase();
        ["staff", "shift", "schedule", "workhour", "workinghour", "hire", "employ", "opening", "closing"]
            .iter()
            .any(|k| l.contains(k))
    }) {
        println!("  {n}");
    }
}

/// Fields and methods about working hours on live staff objects.
/// Read-only.
#[test]
fn staff_hours() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let is_hours = |n: &str| {
        let l = n.to_ascii_lowercase();
        ["hour", "time", "shift", "sleep", "rest", "day", "night", "work", "schedule", "off"]
            .iter()
            .any(|k| l.contains(k))
    };
    for class in [
        "Runtime.Staff.StaffManager",
        "Runtime.Mob.Staff.StaffMobObject",
        "Runtime.Staff.FloorWorkerStaffJob",
        "Runtime.Staff.ServiceStaffJob",
        "Runtime.Staff.SecurityStaffJob",
        "Runtime.Staff.HomeStaffJob",
        "Runtime.Staff.StaffJob",
    ] {
        let list = common::find_instances(&api, class, false).unwrap_or_default();
        println!("\n== {class}: {} instance(s)", list.len());
        for (i, v) in list.iter().enumerate() {
            let Some(h) = handle_of(v) else { continue };
            if i == 0 {
                let f = common::fields(&api, h).unwrap_or(Value::Null);
                if let Some(map) = f["fields"].as_object() {
                    for (k, fv) in map.iter().filter(|(k, _)| is_hours(k)) {
                        let shown = fv.get("str").cloned().unwrap_or_else(|| fv.clone());
                        println!("  field {k} = {shown}");
                    }
                }
            }
            release(&api, h);
        }
        let full = format!("Il2Cpp{class}");
        let r = api.op("list_methods", json!({"class": full}));
        let empty = vec![];
        for m in r.result["methods"].as_array().unwrap_or(&empty) {
            let name = m["name"].as_str().unwrap_or("");
            if m["declared_on"].as_str() == Some(full.as_str()) && is_hours(name) {
                println!(
                    "  method {name}({}) -> {}",
                    m["params"].as_i64().unwrap_or(0),
                    m["return"].as_str().unwrap_or("?")
                );
            }
        }
    }
}

/// Every stored field of one hired staff member, and of the
/// objects it points at directly. Read-only.
#[test]
fn staff_member() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = common::find_instances(&api, "Runtime.Mob.Staff.StaffMobObject", false)
        .unwrap_or_default();
    let Some(h) = list.first().and_then(handle_of) else {
        println!("no staff");
        return;
    };
    let f = common::fields(&api, h).unwrap_or(Value::Null);
    let Some(map) = f["fields"].as_object() else { return };
    for (k, v) in map {
        if v.as_str().is_some_and(|s| s.starts_with("<getter")) {
            continue;
        }
        let shown = v.get("str").cloned().unwrap_or_else(|| v.clone());
        println!("field {k} = {shown}");
        let l = k.to_ascii_lowercase();
        if ["job", "data", "runtime"].iter().any(|w| l.contains(w)) {
            if let Some(ch) = handle_of(v) {
                let cf = common::fields(&api, ch).unwrap_or(Value::Null);
                if let Some(cm) = cf["fields"].as_object() {
                    for (ck, cv) in cm {
                        if cv.as_str().is_some_and(|s| s.starts_with("<getter")) {
                            continue;
                        }
                        let cs = cv.get("str").cloned().unwrap_or_else(|| cv.clone());
                        println!("    {k}.{ck} = {cs}");
                    }
                }
                release(&api, ch);
            }
        }
    }
    for v in &list {
        if let Some(h) = handle_of(v) {
            release(&api, h);
        }
    }
}

/// Game types, and staff fields and methods, about staff fleeing
/// and not coming back until the next day. Read-only.
#[test]
fn staff_flee() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let is_flee = |n: &str| {
        let l = n.to_ascii_lowercase();
        ["flee", "fled", "fear", "panic", "scare", "escape", "return", "tomorrow", "morale", "leave", "absent", "away"]
            .iter()
            .any(|k| l.contains(k))
    };
    let mut names = game_type_names(&api, "Runtime,");
    names.sort();
    for n in names.iter().filter(|n| !n.contains('<')).filter(|n| is_flee(n)) {
        println!("type {n}");
    }
    for class in [
        "Runtime.Staff.StaffManager",
        "Runtime.Mob.Staff.StaffMobObject",
        "Runtime.Staff.StaffJob",
        "Runtime.Staff.FloorWorkerStaffJob",
        "Runtime.Staff.ServiceStaffJob",
        "Runtime.Staff.SecurityStaffJob",
        "Runtime.Staff.HomeStaffJob",
    ] {
        println!("\n== {class}");
        let list = common::find_instances(&api, class, false).unwrap_or_default();
        if let Some(h) = list.first().and_then(handle_of) {
            let f = common::fields(&api, h).unwrap_or(Value::Null);
            if let Some(map) = f["fields"].as_object() {
                for (k, fv) in map.iter().filter(|(k, _)| is_flee(k)) {
                    let shown = fv.get("str").cloned().unwrap_or_else(|| fv.clone());
                    println!("  field {k} = {shown}");
                }
            }
        }
        for v in &list {
            if let Some(h) = handle_of(v) {
                release(&api, h);
            }
        }
        let full = format!("Il2Cpp{class}");
        let r = api.op("list_methods", json!({"class": full}));
        let empty = vec![];
        for m in r.result["methods"].as_array().unwrap_or(&empty) {
            let name = m["name"].as_str().unwrap_or("");
            if is_flee(name) {
                println!(
                    "  method {name}({}) -> {}  [on {}]",
                    m["params"].as_i64().unwrap_or(0),
                    m["return"].as_str().unwrap_or("?"),
                    m["declared_on"].as_str().unwrap_or("?")
                );
            }
        }
    }
}

/// Game types about cleaners and body disposal, and the fields of
/// every live object of those types. Read-only.
#[test]
fn body_disposal() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let is_body = |n: &str| {
        let l = n.to_ascii_lowercase();
        ["clean", "body", "corpse", "dispos", "dead"].iter().any(|k| l.contains(k))
    };
    let mut names = game_type_names(&api, "Runtime,");
    names.sort();
    let hits: Vec<&String> = names.iter().filter(|n| !n.contains('<')).filter(|n| is_body(n)).collect();
    for n in &hits {
        println!("type {n}");
    }
    for n in &hits {
        let list = common::find_instances(&api, n, false).unwrap_or_default();
        if list.is_empty() {
            continue;
        }
        println!("\n== {n}: {} instance(s)", list.len());
        if let Some(h) = list.first().and_then(handle_of) {
            let f = common::fields(&api, h).unwrap_or(Value::Null);
            if let Some(map) = f["fields"].as_object() {
                for (k, fv) in map {
                    if fv.as_str().is_some_and(|s| s.starts_with("<getter")) {
                        continue;
                    }
                    let shown = fv.get("str").cloned().unwrap_or_else(|| fv.clone());
                    println!("  field {k} = {shown}");
                }
            }
        }
        for v in &list {
            if let Some(h) = handle_of(v) {
                release(&api, h);
            }
        }
    }
}

/// Every staff type, and the fields of each live StaffJobTypeData,
/// to find what greys out a job option. Read-only.
#[test]
fn staff_job_options() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let mut names = game_type_names(&api, "Runtime,");
    names.sort();
    for n in names.iter().filter(|n| !n.contains('<')).filter(|n| {
        let l = n.to_ascii_lowercase();
        l.contains("staff") || l.contains("policy") || l.contains("floorworker")
    }) {
        println!("type {n}");
    }
    let list = common::find_instances(&api, "Runtime.Staff.StaffJobTypeData", false)
        .unwrap_or_default();
    for v in &list {
        let Some(h) = handle_of(v) else { continue };
        println!("\n== StaffJobTypeData '{}'", v.get("name").and_then(Value::as_str).unwrap_or("?"));
        let f = common::fields(&api, h).unwrap_or(Value::Null);
        if let Some(map) = f["fields"].as_object() {
            for (k, fv) in map {
                if fv.as_str().is_some_and(|s| s.starts_with("<getter")) {
                    continue;
                }
                let shown = fv.get("str").cloned().unwrap_or_else(|| fv.clone());
                println!("  field {k} = {shown}");
            }
        }
        release(&api, h);
    }
}

/// Fields and own methods of the cleaner's job settings, perks and
/// staff levels. Read-only.
#[test]
fn cleaner_perks() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for class in [
        "Runtime.Staff.FloorWorkerJobSettings",
        "Runtime.Staff.View.FloorWorkerJobSettingsView",
        "Runtime.Staff.View.JobPerksView",
        "Runtime.Staff.View.JobPerksSettingsContainer",
        "Runtime.Mob.Goals.FloorWorkerWorkPolicy",
        "Runtime.Staff.StaffLevelData",
        "Runtime.Staff.StaffProgression",
    ] {
        let list = common::find_instances(&api, class, false).unwrap_or_default();
        println!("\n== {class}: {} instance(s)", list.len());
        if let Some(h) = list.first().and_then(handle_of) {
            let f = common::fields(&api, h).unwrap_or(Value::Null);
            if let Some(map) = f["fields"].as_object() {
                for (k, fv) in map {
                    if fv.as_str().is_some_and(|s| s.starts_with("<getter")) {
                        continue;
                    }
                    let shown = fv.get("str").cloned().unwrap_or_else(|| fv.clone());
                    println!("  field {k} = {shown}");
                }
            }
        }
        for v in &list {
            if let Some(h) = handle_of(v) {
                release(&api, h);
            }
        }
        let full = format!("Il2Cpp{class}");
        let r = api.op("list_methods", json!({"class": full}));
        let empty = vec![];
        for m in r.result["methods"].as_array().unwrap_or(&empty) {
            if m["declared_on"].as_str() == Some(full.as_str()) {
                println!(
                    "  method {}({}) -> {}",
                    m["name"].as_str().unwrap_or(""),
                    m["params"].as_i64().unwrap_or(0),
                    m["return"].as_str().unwrap_or("?")
                );
            }
        }
    }
}

/// Each perk container on the open cleaner settings window: what it
/// holds and which staff level unlocks it. Read-only.
#[test]
fn cleaner_perk_levels() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = common::find_instances(&api, "Runtime.Staff.View.FloorWorkerJobSettingsView", false)
        .unwrap_or_default();
    let Some(view) = list.first().and_then(handle_of) else {
        println!("no cleaner settings window");
        return;
    };
    let level = api.op("read_field", json!({"handle": view, "field": "_staffLevel"}));
    println!("_staffLevel = {}", level.result);
    let arr = api.op("read_field", json!({"handle": view, "field": "_perksSettingsContainers"}));
    let ah = handle_of(&arr.result).expect("_perksSettingsContainers carried no handle");
    let n = count_of(&api, ah).unwrap_or(0);
    for i in 0..n {
        let item = api.op("invoke_method", json!({"handle": ah, "method": "get_Item", "args": [i]}));
        let Some(ch) = handle_of(&item.result) else {
            println!("container {i} = {}", item.result);
            continue;
        };
        println!("\ncontainer {i}");
        let f = common::fields(&api, ch).unwrap_or(Value::Null);
        if let Some(map) = f["fields"].as_object() {
            for (k, fv) in map {
                let shown = fv.get("str").cloned().unwrap_or_else(|| fv.clone());
                println!("  field {k} = {shown}");
            }
        }
        release(&api, ch);
    }
    release(&api, ah);
    for v in &list {
        if let Some(h) = handle_of(v) {
            release(&api, h);
        }
    }
}

/// Game types about placing objects, and the stored fields of every
/// live one, to find why a held shelf shows red. Read-only; run it
/// while holding the shelf where it shows red.
#[test]
fn placement() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let is_place = |n: &str| {
        let l = n.to_ascii_lowercase();
        ["placement", "placeable", "placing", "buildmode", "blueprint", "ghost", "player.building.", "shelving.", "holding", "held"]
            .iter()
            .any(|k| l.contains(k))
    };
    let mut names = game_type_names(&api, "Runtime,");
    names.sort();
    let hits: Vec<&String> = names.iter().filter(|n| !n.contains('<')).filter(|n| is_place(n)).collect();
    for n in &hits {
        println!("type {n}");
    }
    for n in &hits {
        let list = common::find_instances(&api, n, false).unwrap_or_default();
        if list.is_empty() || list.len() > 20 {
            for v in &list {
                if let Some(h) = handle_of(v) {
                    release(&api, h);
                }
            }
            continue;
        }
        println!("\n== {n}: {} instance(s)", list.len());
        if let Some(h) = list.first().and_then(handle_of) {
            let f = common::fields(&api, h).unwrap_or(Value::Null);
            if let Some(map) = f["fields"].as_object() {
                for (k, fv) in map {
                    if fv.as_str().is_some_and(|s| s.starts_with("<getter")) {
                        continue;
                    }
                    let shown = fv.get("str").cloned().unwrap_or_else(|| fv.clone());
                    println!("  field {k} = {shown}");
                }
            }
        }
        for v in &list {
            if let Some(h) = handle_of(v) {
                release(&api, h);
            }
        }
    }
}

/// The held flimsy wooden shelf (the "(Clone)" one): its last
/// placement probe, and each placement rule on it with its fields.
/// Also the methods a placement rule has. Read-only; run it while
/// holding the shelf where it shows red.
#[test]
fn shelf_placement_rules() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let print_fields = |h: i64| {
        let f = common::fields(&api, h).unwrap_or(Value::Null);
        if let Some(map) = f["fields"].as_object() {
            for (k, fv) in map {
                if fv.as_str().is_some_and(|s| s.starts_with("<getter")) {
                    continue;
                }
                if ["m_CachedPtr", "pooledPtr", "isWrapped", "m_CancellationTokenSource"].contains(&k.as_str()) {
                    continue;
                }
                let shown = fv.get("str").cloned().unwrap_or_else(|| fv.clone());
                println!("    field {k} = {shown}");
            }
        }
    };
    let list = common::find_instances(&api, "Runtime.Player.Building.Buildable", false)
        .unwrap_or_default();
    for v in &list {
        let Some(h) = handle_of(v) else { continue };
        let name = v.get("name").and_then(Value::as_str).unwrap_or("?");
        if name == "FlimsyWoodenShelfItemPrefab(Clone)" {
            let secured = api.op("read_field", json!({"handle": h, "field": "_secured"}));
            let pos = api.op("read_field", json!({"handle": h, "field": "_lastPositioningResult"}));
            println!("== '{name}' secured {} last positioning {}", secured.result, pos.result);
            let probe = api.op("read_field", json!({"handle": h, "field": "<LastProbeResult>k__BackingField"}));
            println!("  last probe = {}", probe.result);
            if let Some(ph) = handle_of(&probe.result) {
                print_fields(ph);
                release(&api, ph);
            }
            let arr = api.op("read_field", json!({"handle": h, "field": "_buildableValidationStrategies"}));
            if let Some(ah) = handle_of(&arr.result) {
                let n = count_of(&api, ah).unwrap_or(0);
                for j in 0..n {
                    let item = api.op("invoke_method", json!({"handle": ah, "method": "get_Item", "args": [j]}));
                    let Some(sh) = handle_of(&item.result) else {
                        println!("  rule {j} = {}", item.result);
                        continue;
                    };
                    // Unity's ToString is "<object name> (<type>)".
                    let class = api.op("invoke_method", json!({"handle": sh, "method": "ToString", "args": []})).result;
                    let can = api.op("invoke_method", json!({"handle": sh, "method": "CanPlace", "args": [{"handle": h}]}));
                    println!("  rule {j}: {class} CanPlace = {} {:?}", can.result, can.error);
                    print_fields(sh);
                    for f in ["_radius", "_layerMask", "_blockingLayers"] {
                        let r = api.op("read_field", json!({"handle": sh, "field": f}));
                        println!("    {f} = {} {:?}", r.result, r.error);
                    }
                    let tags = api.op("read_field", json!({"handle": sh, "field": "_allowedTags"}));
                    if let Some(th) = handle_of(&tags.result) {
                        let n = count_of(&api, th).unwrap_or(0);
                        let items: Vec<Value> = (0..n)
                            .map(|k| api.op("invoke_method", json!({"handle": th, "method": "get_Item", "args": [k]})).result)
                            .collect();
                        println!("    _allowedTags = {items:?}");
                        release(&api, th);
                    }
                    // What is near this rule's point, on every layer.
                    let tr = api.op("invoke_method", json!({"handle": sh, "method": "get_transform", "args": []}));
                    if let Some(trh) = handle_of(&tr.result) {
                        let pos = api.op("invoke_method", json!({"handle": trh, "method": "get_position", "args": []}));
                        println!("    position = {}", pos.result);
                        let (x, y, z) = common::parse_vec3(&pos.result).unwrap_or_default();
                        let near = api.op(
                            "invoke_static",
                            json!({"class": "UnityEngine.Physics", "method": "OverlapSphere",
                                   "args": [{"x": x, "y": y, "z": z}, 0.5]}),
                        );
                        if let Some(nh) = handle_of(&near.result) {
                            let n = count_of(&api, nh).unwrap_or(0);
                            for k in 0..n {
                                let c = api.op("invoke_method", json!({"handle": nh, "method": "get_Item", "args": [k]}));
                                let Some(ch) = handle_of(&c.result) else { continue };
                                let name = api.op("invoke_method", json!({"handle": ch, "method": "ToString", "args": []})).result;
                                let go = api.op("invoke_method", json!({"handle": ch, "method": "get_gameObject", "args": []}));
                                let (layer, tag) = handle_of(&go.result)
                                    .map(|gh| {
                                        let l = api.op("invoke_method", json!({"handle": gh, "method": "get_layer", "args": []})).result;
                                        let t = api.op("invoke_method", json!({"handle": gh, "method": "get_tag", "args": []})).result;
                                        release(&api, gh);
                                        (l, t)
                                    })
                                    .unwrap_or_default();
                                // Bounds rule blocking mask 553731780, read live.
                                let blocks = layer.as_i64().is_some_and(|l| (553731780i64 >> l) & 1 == 1)
                                    && tag.as_str() != Some("AllowBuilding");
                                println!("      within 0.5: {name} layer {layer} tag {tag} blocks={blocks}");
                                release(&api, ch);
                            }
                            release(&api, nh);
                        } else {
                            println!("      OverlapSphere: {} {:?}", near.result, near.error);
                        }
                        release(&api, trh);
                    }
                    release(&api, sh);
                }
                release(&api, ah);
            }
        }
        release(&api, h);
    }
    // The rule settings, read through handles typed as each rule's own
    // class (the array above hands out base-class handles, which cannot
    // see them). One line per distinct setting.
    for (class, fields) in [
        ("Runtime.Player.Building.BoundsBuildableValidationStrategy", &["_blockingLayers"][..]),
        ("Runtime.Player.Building.PositionInsideLayerValidationStrategy", &["_radius", "_layerMask"][..]),
    ] {
        let list = common::find_instances(&api, class, false).unwrap_or_default();
        let mut seen = std::collections::BTreeSet::new();
        for v in &list {
            let Some(h) = handle_of(v) else { continue };
            let mut line = String::new();
            for f in fields {
                let r = api.op("read_field", json!({"handle": h, "field": f}));
                line.push_str(&format!(" {f}={} {:?}", r.result, r.error));
            }
            let tags = api.op("read_field", json!({"handle": h, "field": "_allowedTags"}));
            if let Some(th) = handle_of(&tags.result) {
                let n = count_of(&api, th).unwrap_or(0);
                let items: Vec<String> = (0..n)
                    .map(|k| api.op("invoke_method", json!({"handle": th, "method": "get_Item", "args": [k]})).result.to_string())
                    .collect();
                line.push_str(&format!(" _allowedTags={items:?}"));
                release(&api, th);
            }
            seen.insert(line);
            release(&api, h);
        }
        println!("{class}:");
        for l in seen {
            println!("  {l}");
        }
    }
    for layer in [2, 7, 9, 10, 11, 24, 26, 27] {
        let n = api.op("invoke_static", json!({"class": "UnityEngine.LayerMask", "method": "LayerToName", "args": [layer]}));
        println!("layer {layer} = {}", n.result);
    }

    let base = "Il2CppRuntime.Player.Building.BuildableValidationStrategy";
    let r = api.op("list_methods", json!({"class": base}));
    let empty = vec![];
    for m in r.result["methods"].as_array().unwrap_or(&empty) {
        if m["declared_on"].as_str() == Some(base) {
            println!(
                "method {}({}) -> {}",
                m["name"].as_str().unwrap_or(""),
                m["params"].as_i64().unwrap_or(0),
                m["return"].as_str().unwrap_or("?")
            );
        }
    }
}

/// Lowers the cleaner perk box that needs level 3 (body disposal) to
/// level 2, on every cleaner settings window including hidden ones.
/// CHANGES GAME STATE.
#[test]
fn cleaner_disposal_level_write() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = common::find_instances(&api, "Runtime.Staff.View.FloorWorkerJobSettingsView", true)
        .unwrap_or_default();
    for v in &list {
        let Some(view) = handle_of(v) else { continue };
        let arr = api.op("read_field", json!({"handle": view, "field": "_perksSettingsContainers"}));
        let ah = handle_of(&arr.result).expect("_perksSettingsContainers carried no handle");
        let n = count_of(&api, ah).unwrap_or(0);
        for i in 0..n {
            let item = api.op("invoke_method", json!({"handle": ah, "method": "get_Item", "args": [i]}));
            let Some(ch) = handle_of(&item.result) else { continue };
            let req = api.op("read_field", json!({"handle": ch, "field": "LevelRequirement"}));
            if req.result.as_i64() == Some(3) {
                let w = api.op("write_field", json!({"handle": ch, "field": "LevelRequirement", "value": 2}));
                assert!(w.ok, "write LevelRequirement failed: {:?}", w.error);
            }
            let after = api.op("read_field", json!({"handle": ch, "field": "LevelRequirement"}));
            println!("container {i}: LevelRequirement {} -> {}", req.result, after.result);
            release(&api, ch);
        }
        release(&api, ah);
        release(&api, view);
    }
}

/// Per staff member: the cleaning policy the search step holds and
/// what the body step allows, plus the own methods of both steps.
/// Read-only.
#[test]
fn cleaner_disposal_state() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for (class, fields) in [
        ("Runtime.Mob.Actions.SearchForCleanableMobActionState", &["_policy", "_mobObject"][..]),
        (
            "Runtime.Mob.Actions.ProcessRagdollCleanableMobActionState",
            &["_allowDispose", "_allowShred", "_floorWorkerLevel", "_targetRagdoll", "_mobObject"][..],
        ),
    ] {
        println!("\n== {class}");
        let list = common::find_instances(&api, class, false).unwrap_or_default();
        for (i, v) in list.iter().enumerate() {
            let Some(h) = handle_of(v) else { continue };
            let mut line = format!("  {i}:");
            for f in fields {
                let r = api.op("read_field", json!({"handle": h, "field": f}));
                let shown = if *f == "_mobObject" {
                    handle_of(&r.result)
                        .map(|mh| {
                            let s = api.op("invoke_method", json!({"handle": mh, "method": "ToString", "args": []}));
                            release(&api, mh);
                            s.result
                        })
                        .unwrap_or(r.result)
                } else {
                    r.result
                };
                line.push_str(&format!(" {f}={shown}"));
            }
            println!("{line}");
            release(&api, h);
        }
        let full = format!("Il2Cpp{class}");
        let r = api.op("list_methods", json!({"class": full}));
        let empty = vec![];
        for m in r.result["methods"].as_array().unwrap_or(&empty) {
            let name = m["name"].as_str().unwrap_or("");
            if m["declared_on"].as_str() == Some(full.as_str()) && !name.starts_with("get_") && !name.starts_with("set_") {
                println!("  method {name}({}) -> {}", m["params"].as_i64().unwrap_or(0), m["return"].as_str().unwrap_or("?"));
            }
        }
    }
}

/// Raw bytes of GameAssembly.dll on disk around the two cleaner level
/// checks found in the Cpp2IL dump (addresses at image base
/// 0x180000000): the `cmp r8d,3` in
/// FloorWorkerMobGoalState.GetCurrentPolicy and the `cmp edx,3` in
/// FloorWorkerJobSettings.HasAnyValidWork. Reads the file only; the
/// game does not need to run.
#[test]
fn cleaner_level_check_bytes() {
    use object::{Object, ObjectSection};
    let path = r"C:\Games\Steam\steamapps\common\The Walking Trade\GameAssembly.dll";
    let data = std::fs::read(path).expect("read GameAssembly.dll");
    let file = object::File::parse(&*data).expect("parse PE");
    println!("image base 0x{:X}", file.relative_address_base());
    for (what, va, before, after) in [
        ("GetCurrentPolicy cmp r8d,3", 0x1824E142Au64, 16u64, 48u64),
        ("HasAnyValidWork cmp edx,3", 0x1824A427Bu64, 9u64, 32u64),
    ] {
        let start = va - before;
        let section = file
            .sections()
            .find(|s| s.address() <= start && start + before + after <= s.address() + s.size())
            .expect("section holding the address");
        let (off, _) = section.file_range().expect("section file range");
        let at = (off + (start - section.address())) as usize;
        let bytes = &data[at..at + (before + after) as usize];
        let hex: Vec<String> = bytes.iter().map(|b| format!("{b:02X}")).collect();
        println!("{what}: from 0x{start:X} (site at +{before})\n  {}", hex.join(" "));
    }
}

/// Which methods one hired staff member's Damageable calls on its
/// Damaged and Died events, in subscription order. Read-only.
#[test]
fn staff_damage_handlers() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = common::find_instances(&api, "Runtime.Mob.Staff.StaffMobObject", false)
        .unwrap_or_default();
    let Some(staff) = list.first().and_then(handle_of) else {
        println!("no staff");
        return;
    };
    let dmg = api.op("read_field", json!({"handle": staff, "field": "_damageable"}));
    let dh = handle_of(&dmg.result).expect("_damageable carried no handle");
    // What no_death's owner check sees.
    let owner = api.op("invoke_method", json!({"handle": dh, "method": "get_Owner", "args": []}));
    println!("get_Owner = {} {:?}", owner.result, owner.error);
    if let Some(oh) = handle_of(&owner.result) {
        let s = api.op("invoke_method", json!({"handle": oh, "method": "ToString", "args": []}));
        println!("get_Owner.ToString = {} {:?}", s.result, s.error);
        release(&api, oh);
    }
    let health = api.op("invoke_method", json!({"handle": dh, "method": "get_Health", "args": []}));
    println!("get_Health = {} {:?}", health.result, health.error);
    for event in ["Damaged", "Died"] {
        let d = api.op("read_field", json!({"handle": dh, "field": event}));
        let Some(del) = handle_of(&d.result) else {
            println!("{event}: {} {:?}", d.result, d.error);
            continue;
        };
        let inv = api.op("invoke_method", json!({"handle": del, "method": "GetInvocationList", "args": []}));
        let ih = handle_of(&inv.result).expect("GetInvocationList carried no handle");
        let n = count_of(&api, ih).unwrap_or(0);
        for i in 0..n {
            let item = api.op("invoke_method", json!({"handle": ih, "method": "get_Item", "args": [i]}));
            let Some(h) = handle_of(&item.result) else { continue };
            let m = api.op("invoke_method", json!({"handle": h, "method": "get_Method", "args": []}));
            let (name, owner) = handle_of(&m.result)
                .map(|mh| {
                    let n = api.op("invoke_method", json!({"handle": mh, "method": "get_Name", "args": []})).result;
                    let t = api.op("invoke_method", json!({"handle": mh, "method": "get_DeclaringType", "args": []}));
                    let o = handle_of(&t.result)
                        .map(|th| {
                            let s = api.op("invoke_method", json!({"handle": th, "method": "get_FullName", "args": []})).result;
                            release(&api, th);
                            s
                        })
                        .unwrap_or_default();
                    release(&api, mh);
                    (n, o)
                })
                .unwrap_or_default();
            println!("{event} handler {i}: {owner} . {name}");
            release(&api, h);
        }
        release(&api, ih);
        release(&api, del);
    }
    release(&api, dh);
    for v in &list {
        if let Some(h) = handle_of(v) {
            release(&api, h);
        }
    }
}

/// Every multiplier skill upgrade in the live game: whether it is
/// unlocked and its Value. Read-only.
#[test]
fn multiplier_skill_nodes() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let mut names = game_type_names(&api, "Runtime,");
    names.sort();
    for n in names
        .iter()
        .filter(|n| {
            n.starts_with("Runtime.Progression.Skills.Nodes.")
                && (n.ends_with("MultiplierSkillNode") || n.ends_with("MaximumStaffCountSkillNode"))
        })
    {
        let list = common::find_instances(&api, n, true).unwrap_or_default();
        for v in &list {
            let Some(h) = handle_of(v) else { continue };
            // Interop names, as the live field dump prints them.
            let unlocked = api.op("read_field", json!({"handle": h, "field": "_IsUnlocked_k__BackingField"}));
            let value = api.op("read_field", json!({"handle": h, "field": "_Value_k__BackingField"}));
            let short = n.trim_start_matches("Runtime.Progression.Skills.Nodes.");
            println!("{short}: unlocked {} value {}", unlocked.result, value.result);
            release(&api, h);
        }
    }
}

/// The live crafting speed total (CraftingPlayerState's static
/// ModifiableFloat) and each multiplier in it. Read-only.
#[test]
fn crafting_speed_total() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let mf = api.op(
        "read_static",
        json!({"class": "Il2CppRuntime.Player.States.CraftingPlayerState", "field": "CraftingSpeedMultiplier"}),
    );
    println!("read_static = {} {:?}", mf.result, mf.error);
    let mf = if handle_of(&mf.result).is_some() {
        mf
    } else {
        api.op(
            "invoke_static",
            json!({"class": "Il2CppRuntime.Player.States.CraftingPlayerState", "method": "get_CraftingSpeedMultiplier", "args": []}),
        )
    };
    let Some(h) = handle_of(&mf.result) else {
        println!("no handle: {} {:?}", mf.result, mf.error);
        return;
    };
    let v = api.op("invoke_method", json!({"handle": h, "method": "get_Value", "args": []}));
    let base = api.op("read_field", json!({"handle": h, "field": "_baseValue"}));
    println!("CraftingSpeedMultiplier value {} base {}", v.result, base.result);
    let list = api.op("read_field", json!({"handle": h, "field": "_multiplicativeModifiers"}));
    if let Some(lh) = handle_of(&list.result) {
        let n = count_of(&api, lh).unwrap_or(0);
        for i in 0..n {
            let item = api.op("invoke_method", json!({"handle": lh, "method": "get_Item", "args": [i]}));
            let Some(ih) = handle_of(&item.result) else { continue };
            let s = api.op("invoke_method", json!({"handle": ih, "method": "ToString", "args": []}));
            let val = api.op("invoke_method", json!({"handle": ih, "method": "get_Value", "args": []}));
            println!("  multiplier {i}: {} value {}", s.result, val.result);
            release(&api, ih);
        }
        release(&api, lh);
    }
    release(&api, h);
}

/// Experiment: copy the owned crafting speed upgrade with
/// Object.Instantiate and add the copy to CraftingSpeedMultiplier.
/// CHANGES GAME STATE until restart (not the save). Expect the value
/// to go 0.75 -> 0.5625.
#[test]
fn crafting_speed_repeat_write() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let mf = api.op(
        "invoke_static",
        json!({"class": "Il2CppRuntime.Player.States.CraftingPlayerState", "method": "get_CraftingSpeedMultiplier", "args": []}),
    );
    let mh = handle_of(&mf.result).expect("CraftingSpeedMultiplier carried no handle");
    let before = api.op("invoke_method", json!({"handle": mh, "method": "get_Value", "args": []}));
    println!("before: {}", before.result);

    let list = common::find_instances(&api, "Runtime.Progression.Skills.Nodes.CraftingSpeedMultiplierSkillNode", true)
        .unwrap_or_default();
    let owned = list.iter().filter_map(handle_of).find(|h| {
        api.op("read_field", json!({"handle": h, "field": "_IsUnlocked_k__BackingField"}))
            .result
            .as_bool()
            == Some(true)
    });
    let Some(node) = owned else {
        println!("no owned crafting speed upgrade");
        return;
    };
    let copy = api.op(
        "invoke_static",
        json!({"class": "UnityEngine.Object", "method": "Instantiate", "args": [{"$handle": node}]}),
    );
    println!("Instantiate = {} {:?}", copy.result, copy.error);
    let Some(ch) = handle_of(&copy.result) else { return };
    let cv = api.op("invoke_method", json!({"handle": ch, "method": "get_Value", "args": []}));
    println!("copy value = {} {:?}", cv.result, cv.error);
    // Add has two overloads and the shim picks the additive one;
    // AddModifier(IModifierProvider) has one, and upgrades implement it.
    let add = api.op("invoke_method", json!({"handle": mh, "method": "AddModifier", "args": [{"$handle": ch}]}));
    println!("AddModifier = {} {:?}", add.result, add.error);
    let after = api.op("invoke_method", json!({"handle": mh, "method": "get_Value", "args": []}));
    println!("after: {}", after.result);
}

/// Whether a class search (walk_class, inactive included) returns
/// Instantiate'd upgrade copies typed as their own class, with their
/// own methods callable. Read-only.
#[test]
fn crafting_speed_copies_typed() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = common::find_instances(&api, "Runtime.Progression.Skills.Nodes.CraftingSpeedMultiplierSkillNode", true)
        .unwrap_or_default();
    for v in &list {
        let Some(h) = handle_of(v) else { continue };
        let name = v.get("name").cloned().unwrap_or_default();
        let val = api.op("invoke_method", json!({"handle": h, "method": "get_Value", "args": []}));
        let unl = api.op("invoke_method", json!({"handle": h, "method": "get_IsUnlocked", "args": []}));
        println!("{name} ptr {} value {} {:?} unlocked {}", v.get("ptr").cloned().unwrap_or_default(), val.result, val.error, unl.result);
        release(&api, h);
    }
}

/// Barbed wire: the damage tick interval (the float constant
/// DamageEntriesCoroutine hands WaitForSeconds, at VA 0x183648CF8 in
/// the 1.2.5 GameAssembly.dll) and the settings of every live
/// BarbedWireDamageTrigger. Read-only.
#[test]
fn barbed_wire() {
    use object::{Object, ObjectSection};
    let path = r"C:\Games\Steam\steamapps\common\The Walking Trade\GameAssembly.dll";
    let data = std::fs::read(path).expect("read GameAssembly.dll");
    let file = object::File::parse(&*data).expect("parse PE");
    let va = 0x183648CF8u64;
    let section = file
        .sections()
        .find(|s| s.address() <= va && va + 4 <= s.address() + s.size())
        .expect("section holding the constant");
    let (off, _) = section.file_range().expect("section file range");
    let at = (off + (va - section.address())) as usize;
    let tick = f32::from_le_bytes(data[at..at + 4].try_into().unwrap());
    println!("damage tick every {tick} s");

    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = common::find_instances(&api, "Runtime.Combat.BarbedWireDamageTrigger", true)
        .unwrap_or_default();
    for v in &list {
        let Some(h) = handle_of(v) else { continue };
        let mut line = format!("{}:", v.get("name").cloned().unwrap_or_default());
        for f in ["_speedMultiplier", "_damagePerTick", "_ownDamagePerTick", "_maximumSpeedEffectorLevel"] {
            let r = api.op("read_field", json!({"handle": h, "field": f}));
            line.push_str(&format!(" {f}={}", r.result));
        }
        let en = api.op("invoke_method", json!({"handle": h, "method": "get_enabled", "args": []}));
        line.push_str(&format!(" enabled={}", en.result));
        println!("{line}");
        release(&api, h);
    }
}

/// Every hire's cleaning search state: who it belongs to, their job,
/// the work policy, the skip counters FindMisplacedItem keeps, queue
/// and search timing. Read-only.
#[test]
fn cleaner_search_state() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = common::find_instances(&api, "Runtime.Mob.Actions.SearchForCleanableMobActionState", false)
        .unwrap_or_default();
    for (i, v) in list.iter().enumerate() {
        let Some(h) = handle_of(v) else { continue };
        let mob = api.op("read_field", json!({"handle": h, "field": "_mobObject"}));
        let (who, job) = handle_of(&mob.result)
            .map(|mh| {
                let n = api.op("invoke_method", json!({"handle": mh, "method": "get_Name", "args": []})).result;
                let j = api.op("invoke_method", json!({"handle": mh, "method": "get_Job", "args": []}));
                let js = handle_of(&j.result)
                    .map(|jh| {
                        let s = api.op("invoke_method", json!({"handle": jh, "method": "ToString", "args": []})).result;
                        release(&api, jh);
                        s
                    })
                    .unwrap_or(j.result);
                release(&api, mh);
                (n, js)
            })
            .unwrap_or_default();
        let mut line = format!("{i}: {who} job {job}");
        for f in [
            "_policy", "_isInQueue", "_timeSinceLastSearch", "_searchInterval", "_debugLogging",
            "_dbgNotCleanable", "_dbgUnreachable", "_dbgNoPlacement", "_dbgHome", "_dbgGenericNoSpace",
            "_dbgFloorNoDest",
        ] {
            let r = api.op("read_field", json!({"handle": h, "field": f}));
            line.push_str(&format!("\n    {f} = {}", r.result));
        }
        println!("{line}");
        release(&api, h);
    }
}

/// Every shelf: zone, whether the player dedicated it (assigned items
/// or types), what it inferred from its contents, and how many items
/// it holds. Read-only.
#[test]
fn shelf_survey() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = common::find_instances(&api, "Runtime.Item.Shelving.ShelfObject", false).unwrap_or_default();
    let name_of = |h: i64| {
        api.op("invoke_method", json!({"handle": h, "method": "ToString", "args": []})).result
    };
    for v in &list {
        let Some(h) = handle_of(v) else { continue };
        let item = api.op("read_field", json!({"handle": h, "field": "_itemObject"}));
        let zone = handle_of(&item.result)
            .map(|ih| {
                let z = api.op("invoke_method", json!({"handle": ih, "method": "get_CurrentWorldZone", "args": []})).result;
                release(&api, ih);
                z
            })
            .unwrap_or_default();
        let dedicated = api.op("invoke_method", json!({"handle": h, "method": "get_IsDedicated", "args": []})).result;
        let stock = api.op("read_field", json!({"handle": h, "field": "_currentStock"}));
        let stock_n = handle_of(&stock.result)
            .map(|sh| {
                let n = count_of(&api, sh).unwrap_or(-1);
                release(&api, sh);
                n
            })
            .unwrap_or(-1);
        let cfg = api.op("read_field", json!({"handle": h, "field": "_stockingConfig"}));
        let mut inferred = String::new();
        if let Some(ch) = handle_of(&cfg.result) {
            let spec = api.op("read_field", json!({"handle": ch, "field": "_inferredSpecificItem"}));
            let spec_name = handle_of(&spec.result)
                .map(|sh| {
                    let n = name_of(sh);
                    release(&api, sh);
                    n
                })
                .unwrap_or(spec.result);
            let has_type = api.op("read_field", json!({"handle": ch, "field": "_hasInferredItemType"})).result;
            let ty = api.op("read_field", json!({"handle": ch, "field": "_inferredItemTypeBacking"})).result;
            inferred = format!("inferred item {spec_name} type {ty} (has {has_type})");
            release(&api, ch);
        }
        println!(
            "{} zone {zone} dedicated {dedicated} kinds {stock_n} | {inferred}",
            name_of(h)
        );
        release(&api, h);
    }
}

/// Bandages end to end: every bandage item with the game's own
/// `DescribeCleanableState`, its zone and flags, and every shelf the
/// bandage is assigned to with the `IsUsableShelf` inputs and
/// `CanFitItem`. Read-only. `TWT_ITEM` picks another item (substring of
/// the item's object name, default "andage").
#[test]
fn item_shelving_trace() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let want = std::env::var("TWT_ITEM").unwrap_or_else(|_| "andage".into());
    let call = |h: i64, m: &str| api.op("invoke_method", json!({"handle": h, "method": m, "args": []}));
    let items = common::find_instances(&api, "Runtime.Item.ItemObject", false).unwrap_or_default();
    let mut data_h = None;
    let mut shelvable_h = None;
    let mut shown = 0;
    for v in &items {
        let Some(h) = handle_of(v) else { continue };
        let name = v.get("name").and_then(Value::as_str).unwrap_or("");
        if !name.contains(want.as_str()) || shown >= 12 {
            release(&api, h);
            continue;
        }
        shown += 1;
        let zone = call(h, "get_CurrentWorldZone").result;
        let unreachable = call(h, "get_IsCleanUnreachable").result;
        let no_place = call(h, "get_IsNoPlacementAvailable").result;
        let describe = call(h, "DescribeCleanableState");
        let shelf = call(h, "get_EffectiveShelf");
        let shelf_name = handle_of(&shelf.result)
            .map(|sh| {
                let s = call(sh, "ToString").result;
                release(&api, sh);
                s
            })
            .unwrap_or(shelf.result);
        println!(
            "{name}: zone {zone} unreachable {unreachable} noPlacement {no_place} shelf {shelf_name}\n    cleanable: {} {:?}",
            describe.result, describe.error
        );
        if data_h.is_none() {
            data_h = handle_of(&call(h, "get_Data").result);
            shelvable_h =
                handle_of(&api.op("read_field", json!({"handle": h, "field": "_shelvableObject"})).result);
        }
        release(&api, h);
    }
    let (Some(dh), Some(svh)) = (data_h, shelvable_h) else {
        println!("no '{want}' item found");
        return;
    };
    let shelves = common::find_instances(&api, "Runtime.Item.Shelving.ShelfObject", false).unwrap_or_default();
    for v in &shelves {
        let Some(h) = handle_of(v) else { continue };
        let assigned = api.op("invoke_method", json!({"handle": h, "method": "IsItemAssigned", "args": [{"$handle": dh}]}));
        if assigned.result.as_bool() == Some(true) {
            let enabled = call(h, "get_enabled").result;
            let cfg = api.op("read_field", json!({"handle": h, "field": "_stockingConfig"}));
            let item = api.op("read_field", json!({"handle": h, "field": "_itemObject"}));
            let zone = handle_of(&item.result)
                .map(|ih| {
                    let z = call(ih, "get_CurrentWorldZone").result;
                    release(&api, ih);
                    z
                })
                .unwrap_or(json!("no _itemObject"));
            let fit = api.op("invoke_method", json!({"handle": h, "method": "CanFitItem", "args": [{"$handle": svh}]}));
            println!(
                "shelf {} assigned: enabled {enabled} stockingConfig {} zone {zone} CanFitItem {} {:?}",
                call(h, "ToString").result,
                handle_of(&cfg.result).is_some(),
                fit.result,
                fit.error
            );
        }
        release(&api, h);
    }
}

/// A spiked wall's Damageable: health, max health, and the methods its
/// Damaged and Died events call, in order. Read-only.
#[test]
fn spiked_wall_handlers() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = common::find_instances(&api, "Runtime.Combat.SpikedWallDamageTrigger", false).unwrap_or_default();
    println!("{} spiked wall(s)", list.len());
    let Some(wall) = list.first().and_then(handle_of) else { return };
    let dmg = api.op("read_field", json!({"handle": wall, "field": "_damageable"}));
    let dh = handle_of(&dmg.result).expect("_damageable carried no handle");
    for m in ["get_Health", "get_MaxHealth", "ToString"] {
        let r = api.op("invoke_method", json!({"handle": dh, "method": m, "args": []}));
        println!("{m} = {}", r.result);
    }
    for event in ["Damaged", "Died"] {
        let d = api.op("read_field", json!({"handle": dh, "field": event}));
        let Some(del) = handle_of(&d.result) else {
            println!("{event}: {}", d.result);
            continue;
        };
        let inv = api.op("invoke_method", json!({"handle": del, "method": "GetInvocationList", "args": []}));
        let ih = handle_of(&inv.result).expect("GetInvocationList carried no handle");
        let n = count_of(&api, ih).unwrap_or(0);
        for i in 0..n {
            let item = api.op("invoke_method", json!({"handle": ih, "method": "get_Item", "args": [i]}));
            let Some(h) = handle_of(&item.result) else { continue };
            let m = api.op("invoke_method", json!({"handle": h, "method": "get_Method", "args": []}));
            if let Some(mh) = handle_of(&m.result) {
                let name = api.op("invoke_method", json!({"handle": mh, "method": "get_Name", "args": []})).result;
                let t = api.op("invoke_method", json!({"handle": mh, "method": "get_DeclaringType", "args": []}));
                let owner = handle_of(&t.result)
                    .map(|th| {
                        let s = api.op("invoke_method", json!({"handle": th, "method": "get_FullName", "args": []})).result;
                        release(&api, th);
                        s
                    })
                    .unwrap_or_default();
                println!("{event} handler {i}: {owner} . {name}");
                release(&api, mh);
            }
            release(&api, h);
        }
        release(&api, ih);
        release(&api, del);
    }
    release(&api, dh);
    for v in &list {
        if let Some(h) = handle_of(v) {
            release(&api, h);
        }
    }
}

/// Spiked wall contact code in GameAssembly.dll on disk (1.2.5): every
/// `movss xmm3, [rip+disp]` (F3 0F 10 1D) between the multiplier
/// branch (VA 0x182650F8E) and the method's shared exit
/// (0x1826511B6), with the address each loads and the bytes around it;
/// the two multiplier constants; and where a 0.1f sits in .rdata.
/// Reads the file only.
#[test]
fn spiked_wall_bytes() {
    use object::{Object, ObjectSection};
    let path = r"C:\Games\Steam\steamapps\common\The Walking Trade\GameAssembly.dll";
    let data = std::fs::read(path).expect("read GameAssembly.dll");
    let file = object::File::parse(&*data).expect("parse PE");
    let off_of = |va: u64| -> usize {
        let s = file
            .sections()
            .find(|s| s.address() <= va && va < s.address() + s.size())
            .expect("section for va");
        (s.file_range().expect("file range").0 + (va - s.address())) as usize
    };
    let f32_at = |va: u64| {
        let o = off_of(va);
        f32::from_le_bytes(data[o..o + 4].try_into().unwrap())
    };
    println!("[0x183648C1C] = {}", f32_at(0x183648C1C));
    println!("[0x183648E30] = {}", f32_at(0x183648E30));
    let (start, end) = (0x182650F8Eu64, 0x1826511B6u64);
    let (a, b) = (off_of(start), off_of(end));
    for i in a..b {
        if data[i..i + 4] == [0xF3, 0x0F, 0x10, 0x1D] {
            let va = start + (i - a) as u64;
            let disp = i32::from_le_bytes(data[i + 4..i + 8].try_into().unwrap());
            let target = (va as i64 + 8 + disp as i64) as u64;
            let hex: Vec<String> = data[i..i + 24].iter().map(|x| format!("{x:02X}")).collect();
            println!("movss xmm3 at 0x{va:X} loads 0x{target:X} = {} | {}", f32_at(target), hex.join(" "));
        }
    }
    // The wall's own load and the bytes around it, and how often
    // candidate patterns occur in .text (the mod's scan must match once).
    let wall = off_of(0x182651148);
    let before: Vec<String> = data[wall - 40..wall].iter().map(|x| format!("{x:02X}")).collect();
    println!("40 bytes before 0x182651148: {}", before.join(" "));
    // Every executable section, as patternsleuth's SectionKind::Text scan
    // sees it (IL2CPP code is not only in the section named .text).
    let code: Vec<&[u8]> = file
        .sections()
        .filter(|s| s.kind() == object::SectionKind::Text)
        .filter_map(|s| s.file_range().map(|(o, l)| &data[o as usize..(o + l) as usize]))
        .collect();
    let tail = "4C 8B 8A 28 02 00 00 89 44 24 38 48 8B 82 30 02";
    for take in [0usize, 8, 16, 24] {
        let pre: Vec<String> = data[wall - take..wall].iter().map(|x| format!("{x:02X}")).collect();
        let sig = format!("{} F3 0F 10 1D ?? ?? ?? ?? {tail}", pre.join(" ")).trim().to_string();
        let n: usize = code.iter().map(|c| modforge::patterns::find_all(c, &sig).len()).sum();
        println!("{take} bytes before: {n} match(es) | {sig}");
    }
    // The cleaner item step's SetDestination call (nav_snap.rs).
    let sig = "F3 44 0F 11 9C 24 C8 00 00 00 4C 8B 90 A8 02 00 00 48 8B 80 B0 02 00 00 48 89 44 24 20 45 33 C9 4C 8D 84 24 C0 00 00 00 48 8D 8C 24 80 00 00 00 41 FF D2";
    let n: usize = code.iter().map(|c| modforge::patterns::find_all(c, sig).len()).sum();
    println!("item step SetDestination pattern: {n} match(es)");
    // The mod's pattern: the 24-byte prefix with the je distance
    // wildcarded, so a small change inside the function still matches.
    let sig = "0F 84 ?? ?? ?? ?? 48 8B 16 4C 8D 44 24 30 F2 0F 10 00 48 8B CE 8B 40 08 F3 0F 10 1D ?? ?? ?? ?? 4C 8B 8A 28 02 00 00 89 44 24 38 48 8B 82 30 02";
    let n: usize = code.iter().map(|c| modforge::patterns::find_all(c, sig).len()).sum();
    println!("mod pattern: {n} match(es)");
    let rdata = file.sections().find(|s| s.name().ok() == Some(".rdata")).expect(".rdata");
    let (ro, rl) = rdata.file_range().expect("rdata range");
    let tenth = 0.1f32.to_le_bytes();
    let hits: Vec<u64> = (ro as usize..(ro + rl) as usize - 4)
        .step_by(4)
        .filter(|&i| data[i..i + 4] == tenth)
        .map(|i| rdata.address() + (i as u64 - ro))
        .take(5)
        .collect();
    println!("0.1f in .rdata at {:X?}", hits);
}

/// Every hire's walking navigator: the stuck-recovery settings and the
/// live stuck state. Read-only.
#[test]
fn staff_navigators() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    // TWT_NAV: part of the mob's object name (default "StaffMob" =
    // hires), or "stuck" for every navigator whose stuck timer runs
    // (customers, zombies, hires).
    let want = std::env::var("TWT_NAV").unwrap_or_else(|_| "StaffMob".into());
    let list = common::find_instances(&api, "Runtime.Mob.Navigation.RigidbodyNavigator", false).unwrap_or_default();
    let mut shown_config = false;
    for v in &list {
        let Some(h) = handle_of(v) else { continue };
        let name = v.get("name").and_then(Value::as_str).unwrap_or("");
        let keep = if want == "stuck" {
            api.op("read_field", json!({"handle": h, "field": "_stuckTimer"})).result.as_f64().unwrap_or(0.0) > 0.0
        } else {
            name.contains(want.as_str())
        };
        if !keep {
            release(&api, h);
            continue;
        }
        let rd = |f: &str| api.op("read_field", json!({"handle": h, "field": f})).result;
        if !shown_config {
            shown_config = true;
            let mut cfg = String::from("config:");
            for f in [
                "_stuckWindow", "_stuckMinProgress", "_stuckRepathTime", "_stuckRecoverTime",
                "_stuckGiveUpTime", "_stuckSnapRadius", "_overlapRecoveryMask", "_offMeshRecoveryRadius",
                "_offMeshMinWarpDistance", "_gapRecoveryEnabled",
            ] {
                cfg.push_str(&format!("\n    {f} = {}", rd(f)));
            }
            println!("{cfg}");
        }
        let owner = api.op("invoke_method", json!({"handle": h, "method": "GetComponent", "args": ["StaffMobObject"]}));
        let who = handle_of(&owner.result)
            .map(|oh| {
                let n = api.op("invoke_method", json!({"handle": oh, "method": "get_Name", "args": []})).result;
                release(&api, oh);
                n
            })
            .unwrap_or_default();
        let tr = api.op("invoke_method", json!({"handle": h, "method": "get_transform", "args": []}));
        let pos = handle_of(&tr.result)
            .map(|th| {
                let p = api.op("invoke_method", json!({"handle": th, "method": "get_position", "args": []})).result;
                release(&api, th);
                p
            })
            .unwrap_or_default();
        println!(
            "{name} {who} pos {pos} stuckTimer {} windowStuck {} repathIssued {} recoverIssued {} pathFailures {} currentPathIndex {}",
            rd("_stuckTimer"),
            rd("_lastWindowStuck"),
            rd("_stuckRepathIssued"),
            rd("_stuckRecoverIssued"),
            rd("_consecutivePathFailures"),
            rd("_currentPathIndex"),
        );
        release(&api, h);
    }
}

/// Watch a stuck hire's navigator once a second for 10 s: timer,
/// recovery flags, path failures, position. Then list every collider
/// within 1 m of it with layer and tag. Picks hires within 2 m of
/// `TWT_POS` ("x,z", from `staff_navigators`), since a looping stuck
/// timer can read 0 at any one moment. Read-only.
#[test]
fn stuck_probe() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    // TWT_HIRE (part of a hire's name, e.g. "opal") finds that hire's
    // position first; otherwise TWT_POS=x,z.
    let hire_pos = std::env::var("TWT_HIRE").ok().and_then(|want| {
        let hires = common::find_instances(&api, "Runtime.Mob.Staff.StaffMobObject", false).unwrap_or_default();
        let mut found = None;
        for v in &hires {
            let Some(h) = handle_of(v) else { continue };
            let n = api.op("invoke_method", json!({"handle": h, "method": "get_Name", "args": []})).result;
            if found.is_none() && n.as_str().is_some_and(|s| s.to_lowercase().contains(&want.to_lowercase())) {
                let goal = api.op("invoke_method", json!({"handle": h, "method": "get_CurrentGoal", "args": []}));
                let goal_s = handle_of(&goal.result)
                    .map(|gh| {
                        let s = api.op("invoke_method", json!({"handle": gh, "method": "ToString", "args": []})).result;
                        release(&api, gh);
                        s
                    })
                    .unwrap_or(goal.result);
                let tr = api.op("invoke_method", json!({"handle": h, "method": "get_transform", "args": []}));
                let p = handle_of(&tr.result)
                    .map(|th| {
                        let p = api.op("invoke_method", json!({"handle": th, "method": "get_position", "args": []})).result;
                        release(&api, th);
                        p
                    })
                    .unwrap_or_default();
                println!("hire {n} at {p}, current goal {goal_s}");
                found = common::parse_vec3(&p).map(|(x, _, z)| (x, z));
            }
            release(&api, h);
        }
        found
    });
    let (px, pz) = hire_pos
        .or_else(|| {
            let s = std::env::var("TWT_POS").ok()?;
            let (a, b) = s.split_once(',')?;
            Some((a.trim().parse::<f64>().ok()?, b.trim().parse::<f64>().ok()?))
        })
        .expect("set TWT_HIRE=<name> or TWT_POS=x,z");
    let pos_of = |h: i64| {
        let tr = api.op("invoke_method", json!({"handle": h, "method": "get_transform", "args": []}));
        handle_of(&tr.result)
            .map(|th| {
                let p = api.op("invoke_method", json!({"handle": th, "method": "get_position", "args": []})).result;
                release(&api, th);
                p
            })
            .unwrap_or_default()
    };
    let list = common::find_instances(&api, "Runtime.Mob.Navigation.RigidbodyNavigator", false).unwrap_or_default();
    let mut stuck = Vec::new();
    for v in &list {
        let Some(h) = handle_of(v) else { continue };
        let name = v.get("name").and_then(Value::as_str).unwrap_or("");
        let (x, _, z) = common::parse_vec3(&pos_of(h)).unwrap_or((1e9, 0.0, 1e9));
        // By hire name: that hire's navigator. By TWT_POS: any walker
        // (customer, zombie, hire) within 1 m.
        let near = (x - px).hypot(z - pz);
        let take = if hire_pos.is_some() { name.contains("StaffMob") && near < 2.0 } else { near < 1.0 };
        if take {
            stuck.push(h);
        } else {
            release(&api, h);
        }
    }
    println!("{} hire navigator(s) near ({px}, {pz})", stuck.len());
    // What the item step waits on: SetDestination's path request, then
    // the navigator's DestinationReached (docs/research.md).
    for &h in &stuck {
        let call = |m: &str| api.op("invoke_method", json!({"handle": h, "method": m, "args": []})).result;
        let path = api.op("invoke_method", json!({"handle": h, "method": "get_CurrentPath", "args": []}));
        let path_n = handle_of(&path.result)
            .map(|ph| {
                let n = count_of(&api, ph).unwrap_or(-1);
                release(&api, ph);
                n
            })
            .unwrap_or(-1);
        println!(
            "nav {h}: calculating {} moving {} unreachable {} reached {} destination {} path corners {path_n}",
            call("get_IsCalculatingPath"),
            call("get_IsMoving"),
            call("get_IsDestinationUnreachable"),
            call("HasReachedDestination"),
            call("get_DestinationPosition"),
        );
    }
    for s in 0..10 {
        for &h in &stuck {
            let rd = |f: &str| api.op("read_field", json!({"handle": h, "field": f})).result;
            println!(
                "t={s} nav {h}: pos {} stuckTimer {} windowStuck {} repath {} recover {} pathFailures {} pathIndex {}",
                pos_of(h),
                rd("_stuckTimer"),
                rd("_lastWindowStuck"),
                rd("_stuckRepathIssued"),
                rd("_stuckRecoverIssued"),
                rd("_consecutivePathFailures"),
                rd("_currentPathIndex"),
            );
        }
        std::thread::sleep(std::time::Duration::from_secs(1));
    }
    for &h in &stuck {
        let (x, y, z) = common::parse_vec3(&pos_of(h)).unwrap_or_default();
        let near = api.op(
            "invoke_static",
            json!({"class": "UnityEngine.Physics", "method": "OverlapSphere", "args": [{"x": x, "y": y + 0.9, "z": z}, 1.0]}),
        );
        println!("colliders within 1 m of nav {h}:");
        if let Some(nh) = handle_of(&near.result) {
            let n = count_of(&api, nh).unwrap_or(0);
            for k in 0..n {
                let c = api.op("invoke_method", json!({"handle": nh, "method": "get_Item", "args": [k]}));
                let Some(ch) = handle_of(&c.result) else { continue };
                let name = api.op("invoke_method", json!({"handle": ch, "method": "ToString", "args": []})).result;
                let trig = api.op("invoke_method", json!({"handle": ch, "method": "get_isTrigger", "args": []})).result;
                let go = api.op("invoke_method", json!({"handle": ch, "method": "get_gameObject", "args": []}));
                let (layer, tag) = handle_of(&go.result)
                    .map(|gh| {
                        let l = api.op("invoke_method", json!({"handle": gh, "method": "get_layer", "args": []})).result;
                        let t = api.op("invoke_method", json!({"handle": gh, "method": "get_tag", "args": []})).result;
                        release(&api, gh);
                        (l, t)
                    })
                    .unwrap_or_default();
                println!("    {name} layer {layer} tag {tag} trigger {trig}");
                release(&api, ch);
            }
            release(&api, nh);
        }
        release(&api, h);
    }
}

/// One hire's cleaning steps (TWT_HIRE, part of the name): which step
/// objects are enabled and what each is aimed at. Read-only.
#[test]
fn hire_action_state() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let want = std::env::var("TWT_HIRE").expect("set TWT_HIRE=<name>").to_lowercase();
    let str_of = |h: i64| api.op("invoke_method", json!({"handle": h, "method": "ToString", "args": []})).result;
    for (class, fields) in [
        ("Runtime.Mob.Actions.SearchForCleanableMobActionState", &["_isInQueue", "_timeSinceLastSearch"][..]),
        ("Runtime.Mob.Actions.MoveToCleanableMobActionState", &["_targetCleanable", "_isCompletingOrExited", "_currentPointOfInterest"][..]),
        ("Runtime.Mob.Actions.ProcessRagdollCleanableMobActionState", &["_targetRagdoll", "_isLooting", "_lootingEntity", "_allowDispose"][..]),
        (
            "Runtime.Mob.Actions.ProcessItemObjectCleanableMobActionState",
            &["_targetItem", "_retryCount", "_targetShelf", "_targetPallet", "_dropPosition", "_lastChosenTransform", "_shouldPlaceOnShelf", "_shouldPlaceOnPallet"][..],
        ),
    ] {
        let list = common::find_instances(&api, class, false).unwrap_or_default();
        for v in &list {
            let Some(h) = handle_of(v) else { continue };
            let mob = api.op("read_field", json!({"handle": h, "field": "_mobObject"}));
            let name = handle_of(&mob.result)
                .map(|mh| {
                    let n = api.op("invoke_method", json!({"handle": mh, "method": "get_Name", "args": []})).result;
                    release(&api, mh);
                    n
                })
                .unwrap_or_default();
            if name.as_str().is_some_and(|n| n.to_lowercase().contains(&want)) {
                let enabled = api.op("invoke_method", json!({"handle": h, "method": "get_enabled", "args": []})).result;
                let mut line = format!("{class} enabled {enabled}");
                for f in fields {
                    let r = api.op("read_field", json!({"handle": h, "field": f}));
                    let shown = handle_of(&r.result)
                        .map(|fh| {
                            let s = str_of(fh);
                            release(&api, fh);
                            s
                        })
                        .unwrap_or(r.result);
                    line.push_str(&format!("\n    {f} = {shown}"));
                }
                if class.ends_with("ProcessItemObjectCleanableMobActionState") {
                    let ft = api.op("read_field", json!({"handle": h, "field": "_failedTargets"}));
                    let n = handle_of(&ft.result)
                        .map(|fh| {
                            let n = count_of(&api, fh).unwrap_or(-1);
                            release(&api, fh);
                            n
                        })
                        .unwrap_or(-1);
                    line.push_str(&format!("\n    _failedTargets count = {n}"));
                }
                println!("{line}");
            }
            release(&api, h);
        }
    }
}

/// The path request queue: the game's own `GetDebugInfo`, the
/// processing flag, queue sizes and timeout settings. Read-only.
#[test]
fn nav_manager_state() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = common::find_instances(&api, "Runtime.Navigation.NavigationManager", false).unwrap_or_default();
    let Some(h) = list.first().and_then(handle_of) else {
        println!("no NavigationManager");
        return;
    };
    let info = api.op("invoke_method", json!({"handle": h, "method": "GetDebugInfo", "args": []}));
    println!("GetDebugInfo = {} {:?}", info.result, info.error);
    for f in ["_maxPathsPerFrame", "_maxSamplePositionsPerFrame", "_requestTimeout", "_isProcessing", "_isProcessingSamplePositions"] {
        println!("{f} = {}", api.op("read_field", json!({"handle": h, "field": f})).result);
    }
    for f in ["_queuedOwnersQueue", "_queuedOwners", "_activePathRequests", "_samplePositionRequests"] {
        let r = api.op("read_field", json!({"handle": h, "field": f}));
        let n = handle_of(&r.result)
            .map(|ch| {
                let n = count_of(&api, ch).unwrap_or(-1);
                release(&api, ch);
                n
            })
            .unwrap_or(-1);
        println!("{f} count = {n}");
    }
    for v in &list {
        if let Some(h) = handle_of(v) {
            release(&api, h);
        }
    }
}

/// Switch the game's own path-queue logging on (`TWT_ON=0` switches it
/// off): `NavigationManager._enableDebugLogs`, written to Player.log.
/// CHANGES GAME STATE until restart (a debug flag only).
#[test]
fn nav_debug_logs_write() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let on = std::env::var("TWT_ON").map(|v| v != "0").unwrap_or(true);
    let list = common::find_instances(&api, "Runtime.Navigation.NavigationManager", false).unwrap_or_default();
    let h = list.first().and_then(handle_of).expect("no NavigationManager");
    let w = api.op("write_field", json!({"handle": h, "field": "_enableDebugLogs", "value": on}));
    assert!(w.ok, "write failed: {:?}", w.error);
    let r = api.op("read_field", json!({"handle": h, "field": "_enableDebugLogs"}));
    println!("_enableDebugLogs = {}", r.result);
    for v in &list {
        if let Some(h) = handle_of(v) {
            release(&api, h);
        }
    }
}

/// Does a replaced path request leave a navigator stuck? On one hire
/// (`TWT_HIRE`, default "jeremy"): `SetDestination(A)` then at once
/// `SetDestination(B)` (the second cancels the first in
/// `NavigationManager.CalculatePathAsync`), then read for 5 s whether
/// the navigator stays calculating with an empty queue or moves.
/// CHANGES GAME STATE: the hire walks a few metres.
#[test]
fn path_replace_test() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let want = std::env::var("TWT_HIRE").unwrap_or_else(|_| "jeremy".into()).to_lowercase();
    let hires = common::find_instances(&api, "Runtime.Mob.Staff.StaffMobObject", false).unwrap_or_default();
    let mut hire = None;
    for v in &hires {
        let Some(h) = handle_of(v) else { continue };
        let n = api.op("invoke_method", json!({"handle": h, "method": "get_Name", "args": []})).result;
        if hire.is_none() && n.as_str().is_some_and(|s| s.to_lowercase().contains(&want)) {
            hire = Some(h);
        } else {
            release(&api, h);
        }
    }
    let hire = hire.expect("hire not found");
    let nav = handle_of(&api.op("invoke_method", json!({"handle": hire, "method": "get_Navigator", "args": []})).result)
        .expect("no navigator");
    let tr = handle_of(&api.op("invoke_method", json!({"handle": hire, "method": "get_transform", "args": []})).result)
        .expect("no transform");
    let pos = || api.op("invoke_method", json!({"handle": tr, "method": "get_position", "args": []})).result;
    let (x, y, z) = common::parse_vec3(&pos()).expect("position");
    let nm = common::find_instances(&api, "Runtime.Navigation.NavigationManager", false).unwrap_or_default();
    let nmh = nm.first().and_then(handle_of).expect("no NavigationManager");
    let state = |label: &str| {
        let calc = api.op("invoke_method", json!({"handle": nav, "method": "get_IsCalculatingPath", "args": []})).result;
        let moving = api.op("invoke_method", json!({"handle": nav, "method": "get_IsMoving", "args": []})).result;
        let dest = api.op("invoke_method", json!({"handle": nav, "method": "get_DestinationPosition", "args": []})).result;
        let q = api.op("invoke_method", json!({"handle": nmh, "method": "GetDebugInfo", "args": []})).result;
        println!("{label}: calculating {calc} moving {moving} pos {} dest {dest} | queue {q}", pos());
    };
    state("before");
    let a = json!({"x": x + 3.0, "y": y, "z": z});
    let b = json!({"x": x, "y": y, "z": z + 3.0});
    // TWT_DEST=x,y,z: one request to that exact point instead (the
    // destination a stuck hire's navigator was aiming at).
    if let Some((dx, dy, dz)) = std::env::var("TWT_DEST").ok().and_then(|s| {
        let p: Vec<f64> = s.split(',').filter_map(|t| t.trim().parse().ok()).collect();
        (p.len() == 3).then(|| (p[0], p[1], p[2]))
    }) {
        let r = api.op(
            "invoke_method",
            json!({"handle": nav, "method": "SetDestination", "args": [{"x": dx, "y": dy, "z": dz}, false]}),
        );
        println!("SetDestination ({dx}, {dy}, {dz}) {:?}", r.error);
        state("right after");
        for s in 1..=5 {
            std::thread::sleep(std::time::Duration::from_secs(1));
            state(&format!("t={s}"));
        }
        return;
    }
    // Both requests must reach the main-thread queue before the same
    // drain, or A finishes before B exists and nothing is replaced: send
    // them from two threads at once.
    let (ra, rb) = std::thread::scope(|s| {
        let ta = s.spawn(|| {
            common::api().op("invoke_method", json!({"handle": nav, "method": "SetDestination", "args": [a, false]}))
        });
        let tb = s.spawn(|| {
            common::api().op("invoke_method", json!({"handle": nav, "method": "SetDestination", "args": [b, false]}))
        });
        (ta.join().unwrap(), tb.join().unwrap())
    });
    println!("SetDestination A {:?} / B {:?}", ra.error, rb.error);
    state("right after");
    for s in 1..=5 {
        std::thread::sleep(std::time::Duration::from_secs(1));
        state(&format!("t={s}"));
    }
}

/// Where the cleaner's item step drops an item with no shelf or pallet:
/// `GetDefaultWarehousePosition` and `GetDefaultInsidePosition` called
/// live on an item step, then every collider within 1.5 m of each point.
/// Read-only.
#[test]
fn cleaner_default_drop() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = common::find_instances(&api, "Runtime.Mob.Actions.ProcessItemObjectCleanableMobActionState", false)
        .unwrap_or_default();
    let h = list.first().and_then(handle_of).expect("no item step");
    let mut points: Vec<(String, Value)> = ["GetDefaultWarehousePosition", "GetDefaultInsidePosition"]
        .iter()
        .map(|m| {
            let r = api.op("invoke_method", json!({"handle": h, "method": m, "args": []}));
            (m.to_string(), r.result)
        })
        .collect();
    // TWT_DEST=x,y,z adds a point to inspect (a stuck hire's destination).
    if let Ok(s) = std::env::var("TWT_DEST") {
        points.push(("TWT_DEST".into(), json!(format!("({s})"))));
    }
    for (m, p) in points {
        println!("{m} = {p}");
        let Some((x, y, z)) = common::parse_vec3(&p) else { continue };
        let near = api.op(
            "invoke_static",
            json!({"class": "UnityEngine.Physics", "method": "OverlapSphere", "args": [{"x": x, "y": y, "z": z}, 1.5]}),
        );
        if let Some(nh) = handle_of(&near.result) {
            let n = count_of(&api, nh).unwrap_or(0);
            for k in 0..n {
                let c = api.op("invoke_method", json!({"handle": nh, "method": "get_Item", "args": [k]}));
                let Some(ch) = handle_of(&c.result) else { continue };
                let name = api.op("invoke_method", json!({"handle": ch, "method": "ToString", "args": []})).result;
                let trig = api.op("invoke_method", json!({"handle": ch, "method": "get_isTrigger", "args": []})).result;
                let b = api.op("invoke_method", json!({"handle": ch, "method": "get_bounds", "args": []})).result;
                println!("    {name} trigger {trig} bounds {b}");
                release(&api, ch);
            }
            release(&api, nh);
        }
    }
    for v in &list {
        if let Some(h) = handle_of(v) {
            release(&api, h);
        }
    }
}

/// Every pallet: position, zone, and the inside edge point
/// `TrySelectPallet` sends a cleaner to. Read-only.
#[test]
fn pallet_edges() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = common::find_instances(&api, "Runtime.Item.Containers.PalletObject", false).unwrap_or_default();
    for v in &list {
        let Some(h) = handle_of(v) else { continue };
        let name = api.op("invoke_method", json!({"handle": h, "method": "ToString", "args": []})).result;
        let tr = api.op("invoke_method", json!({"handle": h, "method": "get_transform", "args": []}));
        let pos = handle_of(&tr.result)
            .map(|th| {
                let p = api.op("invoke_method", json!({"handle": th, "method": "get_position", "args": []})).result;
                release(&api, th);
                p
            })
            .unwrap_or_default();
        let edge = api.op("invoke_method", json!({"handle": h, "method": "GetInsideEdgeTransform", "args": []}));
        let edge_pos = handle_of(&edge.result)
            .map(|eh| {
                let t = api.op("invoke_method", json!({"handle": eh, "method": "get_Transform", "args": []}));
                let p = handle_of(&t.result)
                    .map(|th| {
                        let p = api.op("invoke_method", json!({"handle": th, "method": "get_position", "args": []})).result;
                        release(&api, th);
                        p
                    })
                    .unwrap_or(t.result);
                release(&api, eh);
                p
            })
            .unwrap_or(edge.result);
        println!("{name} at {pos} inside edge {edge_pos} {:?}", edge.error);
        release(&api, h);
    }
}

/// Shelves within 4 m of `TWT_DEST` (x,y,z): position, what their
/// buildable is attached to (`_host`), and each front point
/// (`_FrontTransforms`, where `TrySelectShelf` sends a cleaner).
/// Read-only.
#[test]
fn shelf_fronts_near() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let s = std::env::var("TWT_DEST").expect("set TWT_DEST=x,y,z");
    let p: Vec<f64> = s.split(',').filter_map(|t| t.trim().parse().ok()).collect();
    let (dx, dz) = (p[0], p[2]);
    let pos_of = |h: i64| {
        let tr = api.op("invoke_method", json!({"handle": h, "method": "get_transform", "args": []}));
        handle_of(&tr.result)
            .map(|th| {
                let p = api.op("invoke_method", json!({"handle": th, "method": "get_position", "args": []})).result;
                release(&api, th);
                p
            })
            .unwrap_or_default()
    };
    let list = common::find_instances(&api, "Runtime.Item.Shelving.ShelfObject", false).unwrap_or_default();
    for v in &list {
        let Some(h) = handle_of(v) else { continue };
        let pos = pos_of(h);
        let (x, _, z) = common::parse_vec3(&pos).unwrap_or((1e9, 0.0, 1e9));
        if (x - dx).hypot(z - dz) > 4.0 {
            release(&api, h);
            continue;
        }
        let name = api.op("invoke_method", json!({"handle": h, "method": "ToString", "args": []})).result;
        let b = api.op("read_field", json!({"handle": h, "field": "_buildable"}));
        let host = handle_of(&b.result)
            .map(|bh| {
                let r = api.op("read_field", json!({"handle": bh, "field": "_host"}));
                let s = handle_of(&r.result)
                    .map(|hh| {
                        let s = api.op("invoke_method", json!({"handle": hh, "method": "ToString", "args": []})).result;
                        release(&api, hh);
                        s
                    })
                    .unwrap_or(r.result);
                release(&api, bh);
                s
            })
            .unwrap_or_default();
        println!("{name} at {pos} host {host}");
        let fr = api.op("read_field", json!({"handle": h, "field": "_FrontTransforms_k__BackingField"}));
        if let Some(fh) = handle_of(&fr.result) {
            let n = count_of(&api, fh).unwrap_or(0);
            for k in 0..n {
                let it = api.op("invoke_method", json!({"handle": fh, "method": "get_Item", "args": [k]}));
                if let Some(ih) = handle_of(&it.result) {
                    let t = api.op("invoke_method", json!({"handle": ih, "method": "get_Transform", "args": []}));
                    let fp = handle_of(&t.result)
                        .map(|th| {
                            let p = api.op("invoke_method", json!({"handle": th, "method": "get_position", "args": []})).result;
                            release(&api, th);
                            p
                        })
                        .unwrap_or(t.result);
                    let flag = |m: &str| api.op("invoke_method", json!({"handle": ih, "method": m, "args": []})).result;
                    println!(
                        "    front {k}: {fp} zone {} blockedByObstacle {} blockedByWall {} agentUnreachable {}",
                        flag("get_CurrentZone"),
                        flag("IsBlockedByObstacle"),
                        flag("get_IsBlockedByWall"),
                        flag("get_IsAgentUnreachable"),
                    );
                    release(&api, ih);
                }
            }
            release(&api, fh);
        } else {
            println!("    fronts: {} {:?}", fr.result, fr.error);
        }
        release(&api, h);
    }
}

/// Do cleaner item trips fail during a window? When the item step's
/// `SetDestination` returns false it calls `MarkAgentUnreachable` on
/// the chosen front, which raises that front's `_agentUnreachableUntil`
/// (a game time). Reads it on every shelf front and pallet edge, plus
/// each cleaner search's `_dbgNoPlacement`, at the start and end of
/// `TWT_SECS` (default 60) of play, and prints what changed. Read-only.
#[test]
fn cleaner_unreachable_window() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let secs: u64 = std::env::var("TWT_SECS").ok().and_then(|s| s.parse().ok()).unwrap_or(60);
    let now = || {
        api.op("invoke_static", json!({"class": "UnityEngine.Time", "method": "get_timeAsDouble", "args": []}))
            .result
    };
    let mut fronts: Vec<(String, i64)> = Vec::new();
    for (class, field) in [
        ("Runtime.Item.Shelving.ShelfObject", "_FrontTransforms_k__BackingField"),
        ("Runtime.Item.Containers.PalletObject", "_EdgeTransforms_k__BackingField"),
    ] {
        let list = common::find_instances(&api, class, false).unwrap_or_default();
        for v in &list {
            let Some(h) = handle_of(v) else { continue };
            let name = api.op("invoke_method", json!({"handle": h, "method": "ToString", "args": []})).result;
            let fr = api.op("read_field", json!({"handle": h, "field": field}));
            if let Some(fh) = handle_of(&fr.result) {
                let n = count_of(&api, fh).unwrap_or(0);
                for k in 0..n {
                    let it = api.op("invoke_method", json!({"handle": fh, "method": "get_Item", "args": [k]}));
                    if let Some(ih) = handle_of(&it.result) {
                        fronts.push((format!("{name} front {k}"), ih));
                    }
                }
                release(&api, fh);
            } else {
                println!("{name}: {field} {} {:?}", fr.result, fr.error);
            }
            release(&api, h);
        }
    }
    let searches = common::find_instances(&api, "Runtime.Mob.Actions.SearchForCleanableMobActionState", false)
        .unwrap_or_default()
        .iter()
        .filter_map(handle_of)
        .collect::<Vec<_>>();
    let until = |ih: i64| api.op("read_field", json!({"handle": ih, "field": "_agentUnreachableUntil"})).result;
    let no_place = |sh: i64| api.op("read_field", json!({"handle": sh, "field": "_dbgNoPlacement"})).result;

    let t0 = now();
    let before: Vec<Value> = fronts.iter().map(|(_, ih)| until(*ih)).collect();
    let np0: Vec<Value> = searches.iter().map(|sh| no_place(*sh)).collect();
    println!("{} fronts, {} cleaner searches, game time {t0}; watching {secs} s", fronts.len(), searches.len());
    std::thread::sleep(std::time::Duration::from_secs(secs));
    let t1 = now();
    let mut marked = 0;
    for ((label, ih), b) in fronts.iter().zip(&before) {
        let a = until(*ih);
        if a != *b {
            marked += 1;
            println!("marked: {label} until {b} -> {a}");
        }
    }
    println!("game time {t0} -> {t1}: {marked} front(s) newly marked unreachable");
    for (sh, n0) in searches.iter().zip(&np0) {
        println!("cleaner search {sh}: _dbgNoPlacement {n0} -> {}", no_place(*sh));
    }
    for (_, ih) in &fronts {
        release(&api, *ih);
    }
    for sh in &searches {
        release(&api, *sh);
    }
}

/// The shelves parked at the world origin (within 4 m of 0,0,0, far
/// from the shop): where each sits in the scene (parent chain), whether
/// it is switched on, and whether it is in the game's own shelf set
/// `StageManager.Model.Shelves`, the set both cleaner steps go through.
/// Read-only.
#[test]
fn origin_shelves() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let call = |h: i64, m: &str| api.op("invoke_method", json!({"handle": h, "method": m, "args": []})).result;
    let id_of = |h: i64| call(h, "GetInstanceID").as_i64().unwrap_or(0);

    // Instance ids of every shelf in StageModel.Shelves.
    let mgr = common::find_instances(&api, "Runtime.Stage.StageManager", false).unwrap_or_default();
    let mh = mgr.iter().find_map(handle_of).expect("no StageManager");
    let model = handle_of(&api.op("read_field", json!({"handle": mh, "field": "_Model_k__BackingField"})).result)
        .expect("no StageModel");
    let set = handle_of(&api.op("read_field", json!({"handle": model, "field": "_Shelves_k__BackingField"})).result)
        .expect("no Shelves");
    let en = handle_of(&call(set, "GetEnumerator")).expect("no enumerator");
    let mut in_model = std::collections::BTreeSet::new();
    while call(en, "MoveNext").as_bool() == Some(true) {
        if let Some(sh) = handle_of(&call(en, "get_Current")) {
            in_model.insert(id_of(sh));
            release(&api, sh);
        }
    }
    for h in [en, set, model, mh] {
        release(&api, h);
    }
    println!("StageModel.Shelves holds {}", in_model.len());

    let list = common::find_instances(&api, "Runtime.Item.Shelving.ShelfObject", false).unwrap_or_default();
    let (mut at_origin, mut origin_in_model) = (0, 0);
    for v in &list {
        let Some(h) = handle_of(v) else { continue };
        let Some(tr) = handle_of(&call(h, "get_transform")) else {
            release(&api, h);
            continue;
        };
        let (x, _, z) = common::parse_vec3(&call(tr, "get_position")).unwrap_or((1e9, 0.0, 1e9));
        if x.hypot(z) > 4.0 {
            release(&api, tr);
            release(&api, h);
            continue;
        }
        at_origin += 1;
        let listed = in_model.contains(&id_of(h));
        origin_in_model += usize::from(listed);
        // Parent chain up to the scene root.
        let mut chain = Vec::new();
        let mut cur = tr;
        while let Some(p) = handle_of(&call(cur, "get_parent")) {
            chain.push(call(p, "ToString").as_str().unwrap_or("?").replace(" (UnityEngine.Transform)", ""));
            if cur != tr {
                release(&api, cur);
            }
            cur = p;
            if chain.len() > 12 {
                break;
            }
        }
        if cur != tr {
            release(&api, cur);
        }
        let go = handle_of(&call(h, "get_gameObject"));
        let active = go.map(|g| {
            let a = call(g, "get_activeInHierarchy");
            release(&api, g);
            a
        });
        println!(
            "{} in StageModel.Shelves {listed} active {:?} enabled {} parents [{}]",
            call(h, "ToString"),
            active,
            call(h, "get_enabled"),
            chain.join(" <- "),
        );
        release(&api, tr);
        release(&api, h);
    }
    println!("{at_origin} shelves at the origin, {origin_in_model} of them in StageModel.Shelves");
}

/// Can the floor under a point be found through the shim?
/// `Physics.RaycastAll(TWT_DEST, down, 5 m)`: each hit's collider,
/// point and distance. Read-only.
#[test]
fn floor_under_point() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let s = std::env::var("TWT_DEST").expect("set TWT_DEST=x,y,z");
    let p: Vec<f64> = s.split(',').filter_map(|t| t.trim().parse().ok()).collect();
    let r = api.op(
        "invoke_static",
        json!({"class": "UnityEngine.Physics", "method": "RaycastAll",
               "args": [{"x": p[0], "y": p[1], "z": p[2]}, {"x": 0.0, "y": -1.0, "z": 0.0}, 5.0]}),
    );
    println!("RaycastAll = {} {:?}", r.result, r.error);
    let Some(hh) = handle_of(&r.result) else { return };
    let n = count_of(&api, hh).unwrap_or(0);
    for k in 0..n {
        let it = api.op("invoke_method", json!({"handle": hh, "method": "get_Item", "args": [k]}));
        let Some(ih) = handle_of(&it.result) else {
            println!("hit {k}: {}", it.result);
            continue;
        };
        let point = api.op("invoke_method", json!({"handle": ih, "method": "get_point", "args": []}));
        let dist = api.op("invoke_method", json!({"handle": ih, "method": "get_distance", "args": []}));
        let col = api.op("invoke_method", json!({"handle": ih, "method": "get_collider", "args": []}));
        let cname = handle_of(&col.result)
            .map(|ch| {
                let s = api.op("invoke_method", json!({"handle": ch, "method": "ToString", "args": []})).result;
                release(&api, ch);
                s
            })
            .unwrap_or(col.result);
        println!("hit {k}: {cname} point {} {:?} distance {}", point.result, point.error, dist.result);
        release(&api, ih);
    }
    release(&api, hh);
}

/// The game's own search logging for one cleaner (`TWT_HIRE`, default
/// "caroline") for `TWT_SECS` (default 60): sets the search step's
/// `_debugLogging`, waits, sets it back. Each search then writes
/// `[SearchForCleanable:...] tiers -> dedicated=... consolidate=...
/// inference=...` to Player.log. CHANGES GAME STATE for the window (a
/// debug flag only).
#[test]
fn cleaner_search_log_window() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let want = std::env::var("TWT_HIRE").unwrap_or_else(|_| "caroline".into()).to_lowercase();
    let secs: u64 = std::env::var("TWT_SECS").ok().and_then(|s| s.parse().ok()).unwrap_or(60);
    let list = common::find_instances(&api, "Runtime.Mob.Actions.SearchForCleanableMobActionState", false)
        .unwrap_or_default();
    let mut target = None;
    for v in &list {
        let Some(h) = handle_of(v) else { continue };
        let mob = api.op("read_field", json!({"handle": h, "field": "_mobObject"}));
        let name = handle_of(&mob.result)
            .map(|mh| {
                let n = api.op("invoke_method", json!({"handle": mh, "method": "get_Name", "args": []})).result;
                release(&api, mh);
                n
            })
            .unwrap_or_default();
        if target.is_none() && name.as_str().is_some_and(|n| n.to_lowercase().contains(&want)) {
            target = Some(h);
        } else {
            release(&api, h);
        }
    }
    let h = target.expect("cleaner not found");
    let on = api.op("write_field", json!({"handle": h, "field": "_debugLogging", "value": true}));
    assert!(on.ok, "set failed: {:?}", on.error);
    println!("search logging on for {secs} s");
    std::thread::sleep(std::time::Duration::from_secs(secs));
    let off = api.op("write_field", json!({"handle": h, "field": "_debugLogging", "value": false}));
    println!("search logging off: {:?}", off.error);
    release(&api, h);
}

/// For one item kind (`TWT_ITEM`, part of the object name, default
/// "Gunpowder"): every shelf that accepts it and has room, and whether
/// `GetInsideFrontTransform` gives that shelf a standing spot (what the
/// cleaner item step needs and the search does not check). Read-only.
#[test]
fn item_shelf_candidates() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let want = std::env::var("TWT_ITEM").unwrap_or_else(|_| "Gunpowder".into());
    let call = |h: i64, m: &str| api.op("invoke_method", json!({"handle": h, "method": m, "args": []})).result;
    // Taken from a cleaner carrying one: a class search over every
    // ItemObject overflows the shim's 64 KB walk buffer.
    let steps = common::find_instances(&api, "Runtime.Mob.Actions.ProcessItemObjectCleanableMobActionState", false)
        .unwrap_or_default();
    let mut found = None;
    for v in &steps {
        let Some(h) = handle_of(v) else { continue };
        let t = api.op("read_field", json!({"handle": h, "field": "_targetItem"}));
        if let Some(th) = handle_of(&t.result) {
            let name = call(th, "ToString");
            if found.is_none() && name.as_str().is_some_and(|n| n.contains(want.as_str())) {
                found = Some(th);
            } else {
                release(&api, th);
            }
        }
        release(&api, h);
    }
    // Else one the item step just dropped (it carries the "no placement"
    // flag), from every item the game tracks: `StageManager.Model.Items`.
    // (`ItemObject.NoPlacementItems` comes back typed as an interface
    // the bridge cannot enumerate.)
    if found.is_none() {
        let mgr = common::find_instances(&api, "Runtime.Stage.StageManager", false).unwrap_or_default();
        let mh = mgr.iter().find_map(handle_of).expect("no StageManager");
        let model = handle_of(&api.op("read_field", json!({"handle": mh, "field": "_Model_k__BackingField"})).result)
            .expect("no StageModel");
        let items = handle_of(&api.op("read_field", json!({"handle": model, "field": "_Items_k__BackingField"})).result)
            .expect("no Items");
        let e = api.op("invoke_method", json!({"handle": items, "method": "GetEnumerator", "args": []}));
        let en = handle_of(&e.result).unwrap_or_else(|| panic!("GetEnumerator: {} {:?}", e.result, e.error));
        let mut n = 0;
        while found.is_none() && call(en, "MoveNext").as_bool() == Some(true) && n < 5000 {
            n += 1;
            if let Some(ih) = handle_of(&call(en, "get_Current")) {
                if call(ih, "ToString").as_str().is_some_and(|s| s.contains(want.as_str()))
                    && call(ih, "get_IsNoPlacementAvailable").as_bool() == Some(true)
                {
                    found = Some(ih);
                } else {
                    release(&api, ih);
                }
            }
        }
        println!("looked at {n} item(s)");
        for h in [en, items, model, mh] {
            release(&api, h);
        }
    }
    let item = found.expect("no cleaner is carrying such an item and none is flagged");
    println!("item {}", call(item, "ToString"));
    let data = handle_of(&call(item, "get_Data")).expect("no data");
    let sv = handle_of(&api.op("read_field", json!({"handle": item, "field": "_shelvableObject"})).result)
        .expect("not shelvable");
    println!("item zone {}", call(item, "get_CurrentWorldZone"));
    let tr = handle_of(&call(item, "get_transform")).expect("no transform");
    let (ix, iy, iz) = common::parse_vec3(&call(tr, "get_position")).expect("item position");
    let item_pos = json!({"x": ix, "y": iy, "z": iz});
    let shelves = common::find_instances(&api, "Runtime.Item.Shelving.ShelfObject", false).unwrap_or_default();
    for v in &shelves {
        let Some(h) = handle_of(v) else { continue };
        let cfg = handle_of(&api.op("read_field", json!({"handle": h, "field": "_stockingConfig"})).result);
        let accepts = cfg
            .map(|ch| {
                let a = api.op("invoke_method", json!({"handle": ch, "method": "AcceptsItem", "args": [{"$handle": data}]})).result;
                release(&api, ch);
                a
            })
            .unwrap_or_default();
        let fits = api.op("invoke_method", json!({"handle": h, "method": "CanFitItem", "args": [{"$handle": sv}]})).result;
        if accepts.as_bool() == Some(true) && fits.as_bool() == Some(true) {
            // The item step passes the cleaner's position; the item's is
            // the same place (it is being carried).
            let front = api.op("invoke_method", json!({"handle": h, "method": "GetInsideFrontTransform", "args": [item_pos]}));
            let fs = handle_of(&front.result)
                .map(|fh| {
                    let s = call(fh, "ToString");
                    release(&api, fh);
                    s
                })
                .unwrap_or(front.result);
            let own = handle_of(&api.op("read_field", json!({"handle": h, "field": "_itemObject"})).result)
                .map(|oh| {
                    let z = call(oh, "get_CurrentWorldZone");
                    release(&api, oh);
                    z
                })
                .unwrap_or_default();
            println!(
                "{} zone {own} enabled {} dedicated {}: standing spot {fs} {:?}",
                call(h, "ToString"),
                call(h, "get_enabled"),
                call(h, "get_IsDedicated"),
                front.error
            );
            // The four filters of GetInsideFrontTransform, per front:
            // zone Inside(0)/Warehouse(3), not blocked by an obstacle,
            // not marked unreachable, same zone as the shelf.
            let fr = api.op("read_field", json!({"handle": h, "field": "_FrontTransforms_k__BackingField"}));
            if let Some(fh) = handle_of(&fr.result) {
                for k in 0..count_of(&api, fh).unwrap_or(0) {
                    if let Some(ih) = handle_of(&api.op("invoke_method", json!({"handle": fh, "method": "get_Item", "args": [k]})).result) {
                        println!(
                            "    front {k}: zone {} blockedByObstacle {} agentUnreachable {}",
                            call(ih, "get_CurrentZone"),
                            call(ih, "IsBlockedByObstacle"),
                            call(ih, "get_IsAgentUnreachable"),
                        );
                        release(&api, ih);
                    }
                }
                release(&api, fh);
            }
        }
        release(&api, h);
    }
}

#[test]
fn crafting_types() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let mut names = game_type_names(&api, "Runtime,");
    println!("Runtime: {} types", names.len());
    let items = game_type_names(&api, "Runtime.Item.Abstractions,");
    println!("Runtime.Item.Abstractions: {} types", items.len());
    names.extend(items);
    let mut hits: Vec<&String> = names
        .iter()
        .filter(|n| !n.contains('<'))
        .filter(|n| {
            let l = n.to_ascii_lowercase();
            KEYWORDS.iter().any(|k| l.contains(k))
        })
        .collect();
    hits.sort();
    for n in hits {
        println!("  {n}");
    }
}
