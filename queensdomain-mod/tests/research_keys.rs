//! Where are the keys?
//!
//! The operator is looking for a key and cannot find it. This test
//! lists every loaded Blueprint class with "key" in its name, every
//! live object of those classes with its level, position and
//! distance from the player, and the fields of each key class.
//!
//! Positions: UE 4.27 stores FVector as three f32. The offsets of
//! Actor::RootComponent and SceneComponent::RelativeLocation are
//! read from the reflected fields, not assumed.
//!
//! ```text
//! k3sc cargo-lock test -p queensdomain-mod --test research_keys -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, dump, fields, instances, ping_or_skip};
use serde_json::json;

fn field_off(api: &modforge::client::Api<serde_json::Value>, class: &str, name: &str) -> Option<u64> {
    fields(api, class).into_iter().find(|f| f.0 == name).map(|f| f.1)
}

fn position(api: &modforge::client::Api<serde_json::Value>, actor: u64, root: u64, loc: u64) -> Option<[f32; 3]> {
    let b = modforge::client::read_bytes(api, actor, root, 8);
    if b.len() < 8 {
        return None;
    }
    let comp = modforge::client::from_le_u64(&b, 0);
    if comp == 0 {
        return None;
    }
    let v = modforge::client::read_bytes(api, comp, loc, 12);
    if v.len() < 12 {
        return None;
    }
    let f = |i: usize| f32::from_le_bytes(v[i..i + 4].try_into().unwrap());
    Some([f(0), f(4), f(8)])
}

/// The guide says "key to the shrine": SwordShrineKey_BP_C. Print
/// whether its root is attached to anything (if not, its relative
/// location is its world location), its fields through the class
/// chain, and its direction from the player relative to where the
/// player's camera faces (Controller::ControlRotation yaw).
#[test]
fn shrine_key() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let off = |c: &str, n: &str| field_off(&api, c, n);
    let (Some(root), Some(loc), Some(parent), Some(ctrl), Some(rot)) = (
        off("Actor", "RootComponent"),
        off("SceneComponent", "RelativeLocation"),
        off("SceneComponent", "AttachParent"),
        off("Pawn", "Controller"),
        off("Controller", "ControlRotation"),
    ) else {
        println!("a reflected offset was not found");
        return;
    };
    let Some((key, full)) = instances(&api, "SwordShrineKey_BP_C", 4).into_iter().next() else {
        println!("SwordShrineKey_BP_C is not loaded (picked up, or its level is unloaded)");
        return;
    };
    println!("key: {full}");
    let kroot = modforge::client::from_le_u64(&modforge::client::read_bytes(&api, key, root, 8), 0);
    let kparent =
        modforge::client::from_le_u64(&modforge::client::read_bytes(&api, kroot, parent, 8), 0);
    println!(
        "key root {kroot:#x} attached to {}",
        if kparent == 0 { "nothing".to_string() } else { common::object_name(&api, kparent) }
    );
    let cls = modforge::client::from_le_u64(&modforge::client::read_bytes(&api, key, 0x10, 8), 0);
    let mut chain = vec![common::object_name(&api, cls)];
    chain.extend(common::super_chain(&api, cls));
    println!("chain: {}", chain.join(" <- "));
    for c in chain.iter().take_while(|c| c.as_str() != "Actor") {
        dump(&api, key, c, None);
    }

    let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 2).into_iter().next() else {
        println!("no player");
        return;
    };
    let (Some(k), Some(p)) = (position(&api, key, root, loc), position(&api, player, root, loc)) else {
        println!("no positions");
        return;
    };
    let pc = modforge::client::from_le_u64(&modforge::client::read_bytes(&api, player, ctrl, 8), 0);
    let r = modforge::client::read_bytes(&api, pc, rot, 12);
    let yaw = f32::from_le_bytes(r[4..8].try_into().unwrap());
    let (dx, dy, dz) = (k[0] - p[0], k[1] - p[1], k[2] - p[2]);
    let bearing = dy.atan2(dx).to_degrees();
    let mut rel = bearing - yaw;
    while rel > 180.0 {
        rel -= 360.0;
    }
    while rel < -180.0 {
        rel += 360.0;
    }
    println!(
        "player {p:?} camera yaw {yaw:.0}; key {k:?}\n\
         flat distance {:.0} m, height {:+.0} m, bearing {bearing:.0}, \
         {rel:+.0} deg from where the camera faces (+ is right)",
        (dx * dx + dy * dy).sqrt() / 100.0,
        dz / 100.0
    );
}

/// How does the player get from 100_GR down into 110_GR_dungeon,
/// where the shrine key is? List every live object in those two
/// levels whose class chain names a way between places (door,
/// ladder, lift, gate, hatch, stairs, teleport, entrance, drop,
/// streaming), with distance from the player and from the key.
#[test]
fn shrine_route() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let (Some(root), Some(loc)) = (
        field_off(&api, "Actor", "RootComponent"),
        field_off(&api, "SceneComponent", "RelativeLocation"),
    ) else {
        return;
    };
    let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 2).into_iter().next() else {
        return;
    };
    let Some(p) = position(&api, player, root, loc) else { return };
    let k = instances(&api, "SwordShrineKey_BP_C", 2)
        .first()
        .and_then(|(a, _)| position(&api, *a, root, loc));
    println!("player {p:?}  key {k:?}");
    let dist = |a: [f32; 3], b: [f32; 3]| {
        ((a[0] - b[0]).powi(2) + (a[1] - b[1]).powi(2) + (a[2] - b[2]).powi(2)).sqrt() / 100.0
    };
    let mut seen = std::collections::HashSet::new();
    let mut rows = Vec::new();
    for needle in [
        "Door", "Ladder", "Elevator", "Lift", "Gate", "Hatch", "Stair", "Teleport", "Entrance",
        "Drop", "Streaming", "Shortcut", "Lever", "Bridge", "Rope", "Hole",
    ] {
        let r = api.op("walk_class_chain", json!({"needle": needle, "max": 3000}));
        for i in r
            .result
            .get("instances")
            .and_then(|v| v.as_array())
            .into_iter()
            .flatten()
        {
            let full = i.get("full_name").and_then(|v| v.as_str()).unwrap_or("");
            if !(full.contains("/100_GR.") || full.contains("/110_GR_dungeon.")) {
                continue;
            }
            // Only actors directly in the level, not their components.
            let after = full.split("PersistentLevel.").nth(1).unwrap_or("");
            if after.contains('.') {
                continue;
            }
            let Some(addr) = i
                .get("addr")
                .and_then(|a| a.as_str())
                .and_then(|a| u64::from_str_radix(a.trim_start_matches("0x"), 16).ok())
            else {
                continue;
            };
            // DropDown_Markup: over 300 ledge markers in 100_GR, which
            // drown out every lift and gate.
            if full.starts_with("DropDown_Markup") || !seen.insert(addr) {
                continue;
            }
            let Some(pos) = position(&api, addr, root, loc) else { continue };
            let to_key = k.map(|k| dist(pos, k)).unwrap_or(f32::NAN);
            rows.push((dist(pos, p), to_key, pos, full.to_string()));
        }
    }
    let yaw = field_off(&api, "Pawn", "Controller")
        .zip(field_off(&api, "Controller", "ControlRotation"))
        .map(|(ctrl, rot)| {
            let pc =
                modforge::client::from_le_u64(&modforge::client::read_bytes(&api, player, ctrl, 8), 0);
            let r = modforge::client::read_bytes(&api, pc, rot, 12);
            f32::from_le_bytes(r[4..8].try_into().unwrap())
        })
        .unwrap_or(0.0);
    let turn = |pos: [f32; 3]| {
        let mut a = (pos[1] - p[1]).atan2(pos[0] - p[0]).to_degrees() - yaw;
        while a > 180.0 {
            a -= 360.0;
        }
        while a < -180.0 {
            a += 360.0;
        }
        a
    };
    if let Some(k) = k {
        println!("key: {:+.0} deg from camera (+ is right)", turn(k));
    }
    rows.sort_by(|a, b| a.0.partial_cmp(&b.0).unwrap());
    println!("{} ways found, nearest the player first:", rows.len());
    for (dp, dk, pos, full) in &rows {
        println!(
            "  {dp:>5.0} m from you {:>+5.0} deg  {dk:>5.0} m from key  z {:>6.0}  {full}",
            turn(*pos),
            pos[2] / 100.0
        );
    }
}

#[test]
fn keys() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let (Some(root), Some(loc)) = (
        field_off(&api, "Actor", "RootComponent"),
        field_off(&api, "SceneComponent", "RelativeLocation"),
    ) else {
        println!("RootComponent or RelativeLocation not found in reflection");
        return;
    };
    println!("Actor::RootComponent +{root:#x}, SceneComponent::RelativeLocation +{loc:#x}");

    let player = instances(&api, "FS_Full_PlayerChar_C", 2)
        .first()
        .and_then(|(a, _)| position(&api, *a, root, loc));
    println!("player at {player:?}");

    let bps = instances(&api, "BlueprintGeneratedClass", 20000);
    let key_classes: Vec<String> = bps
        .iter()
        .map(|(_, n)| n.clone())
        .filter(|n| {
            let l = n.to_ascii_lowercase();
            l.contains("key") && !l.contains("keyboard") && !l.contains("monkey")
        })
        .collect();
    println!("== {} key classes", key_classes.len());
    for class in &key_classes {
        let r = api.op("walk_class", json!({"class": class, "max": 50}));
        let live: Vec<(u64, String)> = r
            .result
            .get("instances")
            .and_then(|v| v.as_array())
            .into_iter()
            .flatten()
            .filter_map(|i| {
                let a = i.get("addr")?.as_str()?;
                Some((
                    u64::from_str_radix(a.trim_start_matches("0x"), 16).ok()?,
                    i.get("full_name")?.as_str()?.to_string(),
                ))
            })
            .collect();
        println!("-- {class}: {} live", live.len());
        for (addr, full) in &live {
            let pos = position(&api, *addr, root, loc);
            let dist = match (pos, player) {
                (Some(p), Some(q)) => {
                    let d = ((p[0] - q[0]).powi(2) + (p[1] - q[1]).powi(2) + (p[2] - q[2]).powi(2)).sqrt();
                    format!("{:.0} m away, dz {:+.0} m", d / 100.0, (p[2] - q[2]) / 100.0)
                }
                _ => "no position".to_string(),
            };
            println!("   {full}\n      at {pos:?}  {dist}");
        }
        if let Some((addr, _)) = live.first() {
            dump(&api, *addr, class, None);
        }
    }
}
