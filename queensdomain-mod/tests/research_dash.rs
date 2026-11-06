//! How far does Endu's Wind Dash carry the player?
//!
//! Blueprint logic is compiled bytecode, so this reads the numbers
//! the dash runs on and measures real dashes:
//! - `dash_params`: every player field about dashing, flying, wind,
//!   wings, coyote time and snapping, with values; the DashForceCurve
//!   keys (time, value); the player's movement settings (gravity,
//!   jump, air control, walk speed).
//! - `dash_sampler`: polls the player for 90 seconds while the
//!   operator dashes, and prints each dash's start, end, horizontal
//!   and vertical distance, duration and the peak height reached.
//!
//! ```text
//! k3sc cargo-lock test -p queensdomain-mod --test research_dash -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, dump, fields, instances, ping_or_skip};
use serde_json::json;

type Api = modforge::client::Api<serde_json::Value>;

fn field_off(api: &Api, class: &str, name: &str) -> Option<u64> {
    fields(api, class).into_iter().find(|f| f.0 == name).map(|f| f.1)
}

fn struct_fields(api: &Api, name: &str) -> Vec<(String, u64, u64)> {
    let r = api.op("discover_struct_detail", json!({"name": name}));
    r.result
        .get("fields")
        .and_then(|v| v.as_array())
        .into_iter()
        .flatten()
        .filter_map(|f| {
            Some((
                f.get("name")?.as_str()?.to_string(),
                f.get("offset")?.as_u64()?,
                f.get("element_size")?.as_u64()?,
            ))
        })
        .collect()
}

fn f32_at(b: &[u8], o: usize) -> f32 {
    f32::from_le_bytes(b[o..o + 4].try_into().unwrap())
}

fn ptr(api: &Api, addr: u64, off: u64) -> u64 {
    let b = modforge::client::read_bytes(api, addr, off, 8);
    if b.len() < 8 { 0 } else { modforge::client::from_le_u64(&b, 0) }
}

/// Keys of a UCurveFloat: FloatCurve (FRichCurve) -> Keys (TArray of
/// FRichCurveKey). Offsets and the key size come from reflection
/// (UStruct::PropertiesSize at +0x58 on UE 4.27).
fn curve_keys(api: &Api, curve: u64) -> Vec<(f32, f32)> {
    let Some(fc) = field_off(api, "CurveFloat", "FloatCurve") else { return vec![] };
    let Some(keys) = struct_fields(api, "RichCurve").into_iter().find(|f| f.0 == "Keys").map(|f| f.1) else {
        return vec![];
    };
    let kf = struct_fields(api, "RichCurveKey");
    let (Some(t), Some(v)) = (
        kf.iter().find(|f| f.0 == "Time").map(|f| f.1 as usize),
        kf.iter().find(|f| f.0 == "Value").map(|f| f.1 as usize),
    ) else {
        return vec![];
    };
    let Some((saddr, _)) = instances(api, "ScriptStruct", 20000).into_iter().find(|(_, n)| n == "RichCurveKey") else {
        return vec![];
    };
    let sb = modforge::client::read_bytes(api, saddr, 0x58, 4);
    let stride = i32::from_le_bytes(sb[..4].try_into().unwrap()) as usize;
    let h = modforge::client::read_bytes(api, curve, fc + keys, 16);
    let data = modforge::client::from_le_u64(&h, 0);
    let num = i32::from_le_bytes(h[8..12].try_into().unwrap()).clamp(0, 64) as usize;
    let b = modforge::client::read_bytes(api, data, 0, (num * stride) as u64);
    (0..num)
        .filter(|i| b.len() >= i * stride + stride)
        .map(|i| (f32_at(&b, i * stride + t), f32_at(&b, i * stride + v)))
        .collect()
}

#[test]
fn dash_params() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 2).into_iter().next() else {
        println!("no player");
        return;
    };
    let words = ["dash", "fly", "flying", "wind", "wing", "coyote", "snap", "plunge", "air", "jump", "glide", "fall"];
    dump(&api, player, "FS_PlayerChar_C", Some(&words));
    for class in ["FS_PlayerCharacter", "Character"] {
        dump(&api, player, class, Some(&words));
    }
    if let Some(off) = field_off(&api, "FS_PlayerChar_C", "DashForceCurve") {
        let c = ptr(&api, player, off);
        if c != 0 {
            println!("== DashForceCurve {} keys (time s, value)", common::object_name(&api, c));
            for (t, v) in curve_keys(&api, c) {
                println!("   {t:.3}  {v:.3}");
            }
        }
    }
    if let Some(off) = field_off(&api, "Character", "CharacterMovement") {
        let m = ptr(&api, player, off);
        if m != 0 {
            let words = ["gravity", "jump", "aircontrol", "maxwalkspeed", "maxflyspeed", "falling", "braking", "maxacceleration", "lateral"];
            dump(&api, m, "CharacterMovementComponent", Some(&words));
        }
    }
}

/// Read once per poll: position, Dashing flag, dash times.
struct Probe {
    root: u64,
    loc: u64,
    dashing: u64,
    start: u64,
    end: u64,
    travelled: u64,
}

#[test]
fn dash_sampler() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 2).into_iter().next() else {
        println!("no player");
        return;
    };
    let o = |c: &str, n: &str| field_off(&api, c, n);
    let (Some(root), Some(loc), Some(dashing), Some(start), Some(end), Some(travelled)) = (
        o("Actor", "RootComponent"),
        o("SceneComponent", "RelativeLocation"),
        o("FS_PlayerChar_C", "Dashing"),
        o("FS_PlayerChar_C", "DashStartTime"),
        o("FS_PlayerChar_C", "LastDashEndTime"),
        o("FS_PlayerChar_C", "DashDistanceTravelled"),
    ) else {
        println!("a reflected offset was not found");
        return;
    };
    let p = Probe { root, loc, dashing, start, end, travelled };
    let comp = ptr(&api, player, p.root);
    let read = || -> Option<([f32; 3], u8, f32, f32, f32)> {
        let v = modforge::client::read_bytes(&api, comp, p.loc, 12);
        let d = modforge::client::read_bytes(&api, player, p.dashing, 1);
        let s = modforge::client::read_bytes(&api, player, p.start, 4);
        let e = modforge::client::read_bytes(&api, player, p.end, 4);
        let t = modforge::client::read_bytes(&api, player, p.travelled, 4);
        if v.len() < 12 || d.is_empty() || s.len() < 4 || e.len() < 4 || t.len() < 4 {
            return None;
        }
        Some(([f32_at(&v, 0), f32_at(&v, 4), f32_at(&v, 8)], d[0], f32_at(&s, 0), f32_at(&e, 0), f32_at(&t, 0)))
    };
    println!("sampling 90 s: dash now");
    let t0 = std::time::Instant::now();
    let mut last_end = read().map(|r| r.3).unwrap_or(0.0);
    let mut track: Vec<(f32, [f32; 3])> = Vec::new();
    let mut prev_dashing = 0u8;
    let mut polls = 0u32;
    while t0.elapsed().as_secs() < 90 {
        let Some((pos, d, s, e, trav)) = read() else { continue };
        polls += 1;
        let now = t0.elapsed().as_secs_f32();
        if d != 0 {
            if prev_dashing == 0 {
                track.clear();
            }
            track.push((now, pos));
        }
        if e != last_end {
            last_end = e;
            track.push((now, pos));
            if let (Some(a), Some(b)) = (track.first(), track.last()) {
                let (dx, dy, dz) = (b.1[0] - a.1[0], b.1[1] - a.1[1], b.1[2] - a.1[2]);
                let peak = track.iter().map(|x| x.1[2]).fold(f32::MIN, f32::max) - a.1[2];
                println!(
                    "dash: game time {s:.2}..{e:.2} ({:.2} s); sampled {:.2} m flat, {:+.2} m height, peak {:+.2} m, game travelled {:.2} m, {} samples",
                    e - s,
                    (dx * dx + dy * dy).sqrt() / 100.0,
                    dz / 100.0,
                    peak / 100.0,
                    trav / 100.0,
                    track.len()
                );
            }
            track.clear();
        }
        prev_dashing = d;
    }
    println!("{polls} polls in 90 s");
}
