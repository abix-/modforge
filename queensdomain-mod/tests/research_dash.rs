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

/// Blueprint functions of `class_addr` by name: walks UStruct::Children
/// (+0x48 on UE 4.27) along UField::Next (+0x28).
fn class_functions(api: &Api, class_addr: u64) -> Vec<(u64, String)> {
    let mut out = Vec::new();
    let mut f = ptr(api, class_addr, 0x48);
    for _ in 0..2000 {
        if f == 0 {
            break;
        }
        out.push((f, common::object_name(api, f)));
        f = ptr(api, f, 0x28);
    }
    out
}

/// Name of an FField (FProperty) at `p`: FField::NamePrivate at +0x28
/// on UE 4.27 (vtable, ClassPrivate, Owner 16 bytes, Next, Name).
fn ffield_name(api: &Api, p: u64) -> Option<String> {
    let b = modforge::client::read_bytes(api, p, 0x28, 8);
    if b.len() < 8 {
        return None;
    }
    let r = api.op("fname_to_string", json!({"fname": modforge::client::from_le_u64(&b, 0)}));
    let s = r.result.get("string")?.as_str()?.to_string();
    (!s.is_empty() && !s.starts_with('<') && s != "None" && s.is_ascii()).then_some(s)
}

/// Where does the dash get its distance? Reads UStruct::Script
/// (TArray of bytecode at +0x60 on UE 4.27, checked by the last byte
/// being EX_EndOfScript 0x53) of each dash function on the player's
/// Blueprint class, and lists what it touches, without a full
/// disassembler:
/// - float constants (EX_FloatConst 0x1E + f32),
/// - properties after variable opcodes (0x00 local, 0x01 instance,
///   0x48 local out, 0x6C default, 0x42 struct member) as FField
///   names,
/// - objects after 0x20 EX_ObjectConst, 0x1C EX_FinalFunction and
///   0x68 EX_CallMath as UObject names.
/// Pointer candidates are kept only when they fall in the range the
/// heap pointers seen so far fall in, and each is resolved once.
#[test]
fn dash_code() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 2).into_iter().next() else {
        println!("no player");
        return;
    };
    let mut class = ptr(&api, player, 0x10);
    let names = [
        "SetUpDashParameters", "GetDashDist", "CorrectDashDistance", "UpdateCurrentDashMove",
        "BeginWindDash", "Calculate Charge Multiplier", "CalculateChargeMultiplier_Impure",
        "Flying Sword Move Is Unlocked", "GetFlyingSwordChargeCount", "ShouldUseOffhandFSDash",
    ];
    let mut funcs = Vec::new();
    for _ in 0..6 {
        if class == 0 {
            break;
        }
        for (f, n) in class_functions(&api, class) {
            if names.contains(&n.as_str()) {
                funcs.push((f, n));
            }
        }
        class = ptr(&api, class, 0x40);
    }
    for (f, name) in funcs {
        scan_script(&api, f, &name);
    }
}

/// Print what one UFunction's bytecode touches; see dash_code.
fn scan_script(api: &Api, f: u64, name: &str) {
    let heap = |p: u64| (0x100_0000_0000..0x7FF0_0000_0000).contains(&p);
    let mut cache: std::collections::HashMap<u64, Option<String>> = Default::default();
    {
        let h = modforge::client::read_bytes(&api, f, 0x60, 16);
        let data = modforge::client::from_le_u64(&h, 0);
        let num = i32::from_le_bytes(h[8..12].try_into().unwrap()).clamp(0, 1 << 20) as u64;
        let code = modforge::client::read_bytes(&api, data, 0, num);
        println!(
            "== {name}: {num} bytes of bytecode, ends with {:#04x}",
            code.last().copied().unwrap_or(0)
        );
        let mut floats = Vec::new();
        let mut props = Vec::new();
        let mut objs = Vec::new();
        for i in 0..code.len().saturating_sub(4) {
            let op = code[i];
            if op == 0x1E {
                let v = f32_at(&code, i + 1);
                if v.is_finite() && (v == 0.0 || (v.abs() > 1e-3 && v.abs() < 1e6)) {
                    floats.push(v);
                }
            }
            if i + 9 > code.len() {
                continue;
            }
            let p = modforge::client::from_le_u64(&code, i + 1);
            if !heap(p) {
                continue;
            }
            match op {
                0x00 | 0x01 | 0x48 | 0x6C | 0x42 => {
                    let n = cache.entry(p).or_insert_with(|| ffield_name(&api, p)).clone();
                    if let Some(n) = n {
                        if !props.contains(&n) {
                            props.push(n);
                        }
                    }
                }
                0x20 | 0x1C | 0x68 => {
                    let n = cache
                        .entry(p | 1 << 63)
                        .or_insert_with(|| {
                            let s = common::object_name(&api, p);
                            (!s.starts_with('<') && s != "?" && s != "None").then_some(s)
                        })
                        .clone();
                    if let Some(n) = n {
                        let tag = format!("{n} ({})", common::class_of(&api, p));
                        if !objs.contains(&tag) {
                            objs.push(tag);
                        }
                    }
                }
                _ => {}
            }
        }
        println!("   floats: {floats:?}");
        println!("   variables: {}", props.join(", "));
        println!("   objects and calls: {}", objs.join(", "));
    }
}

/// GetDashDist (see dash_code) returns the player config's
/// "FS Grounded Distance" or "FS Air Distance", picked by
/// CurrentFSMoveIsGrounded and scaled by HeavyFlyingSwordDistMult
/// under the heavy status. Find every loaded class whose fields
/// include "FS Air Distance", and dump every live object of it,
/// CDOs excluded, with every field.
#[test]
fn player_config() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for (_, name) in instances(&api, "BlueprintGeneratedClass", 20000) {
        if !name.to_ascii_lowercase().contains("config") {
            continue;
        }
        let fs = fields(&api, &name);
        if !fs.iter().any(|f| f.0 == "FS Air Distance") {
            continue;
        }
        let live = instances(&api, &name, 8);
        println!("== {name}: {} fields, {} live", fs.len(), live.len());
        for (addr, obj) in live {
            println!("   {obj} @ {addr:#x}");
            dump(&api, addr, &name, None);
        }
    }
    // GetPlayerConfig returns the PlayerBalance object (class
    // PlayerBalance_C). Its dash, flying-sword and distance fields:
    for (addr, obj) in instances(&api, "PlayerBalance_C", 4) {
        println!("== {obj} @ {addr:#x}");
        dump(&api, addr, "PlayerBalance_C", Some(&["fs ", "dash", "distance", "heavy", "flying", "charge", "wind", "air"]));
    }
    // No config class carries the field directly, so follow the
    // getter GetDashDist calls: every function of PlayerConfigGetter_C.
    for (addr, name) in instances(&api, "BlueprintGeneratedClass", 20000) {
        if name == "PlayerConfigGetter_C" {
            for (f, n) in class_functions(&api, addr) {
                scan_script(&api, f, &n);
            }
        }
    }
}

/// Does DashSpeedMult change how far the dash goes? Writes
/// FS_PlayerChar_C::DashSpeedMult on the live player (env
/// DASH_SPEED_MULT, default 1.0, the game's own value) and reads it
/// back. A live memory change: lost on restart. Run dash_sampler
/// after to measure.
#[test]
#[ignore = "writes to the game; run by name"]
fn set_dash_speed_mult() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let want: f32 = std::env::var("DASH_SPEED_MULT").ok().and_then(|v| v.parse().ok()).unwrap_or(1.0);
    let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 2).into_iter().next() else {
        println!("no player");
        return;
    };
    let Some(off) = field_off(&api, "FS_PlayerChar_C", "DashSpeedMult") else {
        println!("DashSpeedMult not found");
        return;
    };
    let before = f32_at(&modforge::client::read_bytes(&api, player, off, 4), 0);
    let ok = modforge::client::write_bytes(&api, player, off, &want.to_le_bytes());
    let after = f32_at(&modforge::client::read_bytes(&api, player, off, 4), 0);
    println!("DashSpeedMult {before} -> {after} (write ok: {ok})");
    assert_eq!(after, want);
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
                if let Some(m) = o("FS_PlayerChar_C", "DashSpeedMult") {
                    let b = modforge::client::read_bytes(&api, player, m, 4);
                    if b.len() == 4 {
                        println!("   DashSpeedMult now {}", f32_at(&b, 0));
                    }
                }
            }
            track.clear();
        }
        prev_dashing = d;
    }
    println!("{polls} polls in 90 s");
}
