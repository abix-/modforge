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
