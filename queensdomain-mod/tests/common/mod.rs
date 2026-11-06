//! Shared helpers for the queensdomain-mod research tests.
//!
//! Queens' Domain is UE 4.27 with UE4SS experimental-latest. The
//! control plane lives on port 31310, endpoint /debug.
#![allow(dead_code, unused_imports)]

use modforge::client::Api;
use serde_json::{Value, json};

pub fn api() -> Api<Value> {
    let port = std::env::var("QUEENSDOMAIN_MOD_PORT")
        .ok()
        .and_then(|p| p.parse().ok())
        .unwrap_or(31310);
    Api::at(port, "/debug").with_timeout(std::time::Duration::from_secs(30))
}

fn hex_addr(v: &Value) -> Option<u64> {
    u64::from_str_radix(v.as_str()?.trim_start_matches("0x"), 16).ok()
}

/// Live (non-CDO) objects of a class: (address, object name).
pub fn instances(api: &Api<Value>, class: &str, max: u64) -> Vec<(u64, String)> {
    let r = api.op("walk_class", json!({"class": class, "max": max}));
    r.result
        .get("instances")
        .and_then(|v| v.as_array())
        .into_iter()
        .flatten()
        .filter_map(|i| {
            Some((
                hex_addr(i.get("addr")?)?,
                i.get("name")?.as_str()?.to_string(),
            ))
        })
        .collect()
}

/// Name of the object at `addr` (UObject::NamePrivate, +0x18).
pub fn object_name(api: &Api<Value>, addr: u64) -> String {
    let b = modforge::client::read_bytes(api, addr, 0, 0x20);
    if b.len() < 0x20 {
        return "?".to_string();
    }
    let fname = modforge::client::from_le_u64(&b, 0x18);
    let r = api.op("fname_to_string", json!({"fname": fname}));
    r.result
        .get("string")
        .and_then(|s| s.as_str())
        .unwrap_or("?")
        .to_string()
}

/// Class name of the object at `addr` (UObject::ClassPrivate, +0x10).
pub fn class_of(api: &Api<Value>, addr: u64) -> String {
    let b = modforge::client::read_bytes(api, addr, 0, 0x18);
    if b.len() < 0x18 {
        return "?".to_string();
    }
    object_name(api, modforge::client::from_le_u64(&b, 0x10))
}

/// A class's own reflected fields: (name, offset, element size).
pub fn fields(api: &Api<Value>, class: &str) -> Vec<(String, u64, u64)> {
    let r = api.op("discover_class_detail", json!({"name": class}));
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

/// A field's bytes shown without a type: 1 byte as an integer, 4 as
/// f32 when it looks like one else i32, 8 as a pointer with the
/// pointed-to object's name, 12 as three f32.
pub fn show(api: &Api<Value>, b: &[u8], off: u64, size: u64) -> String {
    let (o, s) = (off as usize, size as usize);
    if b.len() < o + s {
        return "?".to_string();
    }
    let f32_at = |p: usize| f32::from_le_bytes(b[p..p + 4].try_into().unwrap());
    match s {
        1 => format!("{}", b[o]),
        4 => {
            let f = f32_at(o);
            let i = i32::from_le_bytes(b[o..o + 4].try_into().unwrap());
            if f.is_finite() && f.abs() > 1e-6 && f.abs() < 1e7 {
                format!("{f}")
            } else {
                format!("{i}")
            }
        }
        8 => {
            let p = modforge::client::from_le_u64(b, o);
            if p == 0 {
                "null".to_string()
            } else if p > 0x10000 && p < 0x7FFF_FFFF_FFFF {
                format!("{p:#x} ({})", object_name(api, p))
            } else {
                format!("{p:#x}")
            }
        }
        12 => format!("({}, {}, {})", f32_at(o), f32_at(o + 4), f32_at(o + 8)),
        _ => format!("[{s} bytes]"),
    }
}

/// Every field of `class` on the object at `addr`, with values.
pub fn dump(api: &Api<Value>, addr: u64, class: &str, filter: Option<&[&str]>) {
    let fs = fields(api, class);
    let end = fs.iter().map(|f| f.1 + f.2).max().unwrap_or(0);
    let b = modforge::client::read_bytes(api, addr, 0, end);
    println!("-- {class} @ {addr:#x} ({} fields)", fs.len());
    for (name, off, size) in &fs {
        if let Some(words) = filter {
            let l = name.to_ascii_lowercase();
            if !words.iter().any(|w| l.contains(w)) {
                continue;
            }
        }
        println!("   +{off:#06x} {name:<40} {}", show(api, &b, *off, *size));
    }
}

/// Read an FString {TCHAR* data, i32 num, i32 max} at `addr`.
pub fn fstring_at(api: &Api<Value>, addr: u64) -> Option<String> {
    let h = modforge::client::read_bytes(api, addr, 0, 16);
    if h.len() < 16 {
        return None;
    }
    let data = modforge::client::from_le_u64(&h, 0);
    let num = i32::from_le_bytes(h[8..12].try_into().unwrap());
    if data == 0 || !(1..4096).contains(&num) {
        return None;
    }
    let b = modforge::client::read_bytes(api, data, 0, num as u64 * 2);
    let u: Vec<u16> = b
        .chunks_exact(2)
        .map(|c| u16::from_le_bytes([c[0], c[1]]))
        .take_while(|&c| c != 0)
        .collect();
    Some(String::from_utf16_lossy(&u))
}

fn ptr_at(api: &Api<Value>, addr: u64, off: u64) -> Option<u64> {
    let b = modforge::client::read_bytes(api, addr, off, 8);
    if b.len() < 8 {
        return None;
    }
    let p = modforge::client::from_le_u64(&b, 0);
    (p > 0x10000 && p < 0x7FFF_FFFF_FFFF).then_some(p)
}

/// Display string of a string-table FText field at `obj + off`.
/// Measured on Queens' Domain 2026-11-05 (research_charms
/// text_layout_probe): FText +0x0 text data; text data +0x18 the
/// string-table entry (key FString at +0x20); entry +0x38 the
/// display string holder, FString at +0x10. Returns the key when the
/// display string is missing.
pub fn ftext(api: &Api<Value>, obj: u64, off: u64) -> Option<String> {
    let data = ptr_at(api, obj, off)?;
    let entry = ptr_at(api, data, 0x18)?;
    if let Some(s) = ptr_at(api, entry, 0x38).and_then(|d| fstring_at(api, d + 0x10)) {
        return Some(s);
    }
    fstring_at(api, entry + 0x20)
}

/// Parent class names, nearest first, from UStruct::SuperStruct
/// (+0x40 on UE 4.27). `class_addr` is the UClass object.
pub fn super_chain(api: &Api<Value>, class_addr: u64) -> Vec<String> {
    let mut out = Vec::new();
    let mut p = class_addr;
    for _ in 0..12 {
        let b = modforge::client::read_bytes(api, p, 0, 0x48);
        if b.len() < 0x48 {
            break;
        }
        let sup = modforge::client::from_le_u64(&b, 0x40);
        if sup == 0 {
            break;
        }
        out.push(object_name(api, sup));
        p = sup;
    }
    out
}

pub fn ping_or_skip(api: &Api<Value>) -> Option<()> {
    match api.try_op("list_ops", json!({})) {
        Ok(r) if r.ok => Some(()),
        Ok(_) => {
            eprintln!("SKIP: control plane answered but list_ops failed");
            None
        }
        Err(e) => {
            eprintln!(
                "SKIP: no control plane answering ({e}); launch the game with the mod loaded"
            );
            None
        }
    }
}
