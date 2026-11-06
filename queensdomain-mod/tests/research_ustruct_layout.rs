//! Where do PropertiesSize, ChildProperties and the FProperty fields
//! live on this game's UE 4.27?
//!
//! Queens' Domain is the first UE4 game in the workspace, and the
//! layout src/lib.rs boots with (PropertiesSize +0x58, ElementSize
//! +0x3C) is read off the 4.27 source, not measured. Same method as
//! sintopia-mod/tests/research_ustruct_layout.rs:
//!
//! - PropertiesSize: the i32 slot that reads 0x28 on the UClass
//!   for `Object` and 0x30 on the UClass for `Field`.
//! - ChildProperties: the pointer slot on `Actor` whose target
//!   carries a resolvable FName at the FField name offset.
//! - FProperty: every i32 from +0x30 to +0x58 on the first few
//!   properties of `Actor`, so ArrayDim (1), ElementSize and
//!   Offset_Internal can be picked out.
//!
//! ```text
//! k3sc cargo-lock test -p queensdomain-mod --test research_ustruct_layout -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, ping_or_skip};
use modforge::client::{self, Api};
use serde_json::{Value, json};
use std::collections::HashMap;

fn class_objects(api: &Api<Value>) -> HashMap<String, u64> {
    let r = api.op(
        "walk_class",
        json!({"class": "Class", "max": 8000, "include_cdo": false}),
    );
    let mut out = HashMap::new();
    if let Some(arr) = r.result.get("instances").and_then(|v| v.as_array()) {
        for i in arr {
            let (Some(name), Some(addr)) = (
                i.get("name").and_then(|n| n.as_str()),
                i.get("addr").and_then(|a| a.as_str()),
            ) else {
                continue;
            };
            if let Ok(a) = u64::from_str_radix(addr.trim_start_matches("0x"), 16) {
                out.insert(name.to_string(), a);
            }
        }
    }
    println!("UClass objects seen: {}", out.len());
    out
}

fn i32_at(b: &[u8], off: usize) -> i32 {
    i32::from_le_bytes(b[off..off + 4].try_into().unwrap())
}

#[test]
fn properties_size_slot() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let classes = class_objects(&api);
    let mut bytes = HashMap::new();
    for name in ["Object", "Field", "Struct", "Class"] {
        let Some(addr) = classes.get(name) else {
            println!("no UClass named {name}");
            return;
        };
        let b = client::read_bytes(&api, *addr, 0, 0x100);
        println!("{name} UClass @ {addr:#x}, read {} bytes", b.len());
        bytes.insert(name, b);
    }
    // Object and Field sizes are fixed by the engine (0x28 and
    // 0x30). Struct and Class are printed for comparison only.
    println!("offsets where Object reads 0x28 and Field reads 0x30:");
    for off in (0..0x100).step_by(4) {
        if i32_at(&bytes["Object"], off) == 0x28 && i32_at(&bytes["Field"], off) == 0x30 {
            println!(
                "  +{off:#x}: Object=0x28 Field=0x30 Struct={:#x} Class={:#x}",
                i32_at(&bytes["Struct"], off),
                i32_at(&bytes["Class"], off)
            );
        }
    }
    println!(
        "src/lib.rs boots with +0x58; Object reads {:#x} there",
        i32_at(&bytes["Object"], 0x58)
    );
}

#[test]
fn child_properties_slot() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let classes = class_objects(&api);
    let Some(actor) = classes.get("Actor") else {
        println!("no UClass named Actor");
        return;
    };
    let head = client::read_bytes(&api, *actor, 0, 0x70);
    for slot in (0x40..0x70).step_by(8) {
        let p = client::from_le_u64(&head, slot);
        if p == 0 {
            println!("Actor +{slot:#x} = null");
            continue;
        }
        let node = client::read_bytes(&api, p, 0, 0x60);
        if node.len() < 0x60 {
            println!("Actor +{slot:#x} = {p:#x} (unreadable)");
            continue;
        }
        // FField::NamePrivate is +0x28; a UField (UObject) name is
        // +0x18. Print both so the chain kind is visible.
        for name_off in [0x18usize, 0x28] {
            let fname = client::from_le_u64(&node, name_off);
            let r = api.op("fname_to_string", json!({"fname": fname}));
            println!(
                "Actor +{slot:#x} -> {p:#x}, name@+{name_off:#x} = {:?}",
                r.result
                    .get("string")
                    .and_then(|s| s.as_str())
                    .unwrap_or("?")
            );
        }
    }
}

/// Where an FProperty's own data ends: the first slot after it is
/// FStructProperty::Struct, so on Actor's struct properties the right
/// offset names a script struct (RepMovement and the like). ueforge's
/// reflect.rs reads it at +0x70, the UE 5.4 size; on this game the
/// location call came back undecoded, 2026-11-05.
#[test]
fn property_extra_slot() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let classes = class_objects(&api);
    let Some(actor) = classes.get("Actor") else {
        println!("no UClass named Actor");
        return;
    };
    let name = |fname: u64| {
        let r = api.op("fname_to_string", json!({"fname": fname}));
        r.result.get("string").and_then(|s| s.as_str()).unwrap_or("?").to_string()
    };
    let mut p = client::read_u64(&api, *actor, 0x50);
    let mut shown = 0;
    for _ in 0..200 {
        if p == 0 || shown == 8 {
            break;
        }
        let node = client::read_bytes(&api, p, 0, 0x90);
        if node.len() < 0x90 {
            break;
        }
        let kind = name(client::read_u64(&api, client::from_le_u64(&node, 0x8), 0));
        // A struct property's slot names a UObject (the struct); an
        // array property's names an FField (its element record).
        if kind == "StructProperty" || kind == "ArrayProperty" {
            shown += 1;
            println!("{} ({kind}) @ {p:#x}", name(client::from_le_u64(&node, 0x28)));
            for off in (0x68..0x90).step_by(8) {
                let q = client::from_le_u64(&node, off);
                let n = if q > 0x10000 && q < 0x7FFF_FFFF_FFFF {
                    format!("object {} / field {:?}", common::object_name(&api, q), common::ffield_name(&api, q))
                } else {
                    "-".into()
                };
                println!("   +{off:#x} = {q:#x} {n}");
            }
        }
        p = client::from_le_u64(&node, 0x20);
    }
}

/// Walk the first few FProperty nodes off Actor's ChildProperties
/// (+0x50, name at +0x28, next at +0x20) and print every i32 from
/// +0x30 to +0x58. src/lib.rs boots with ElementSize +0x3C;
/// ueforge's Offset_Internal is +0x4C.
#[test]
fn fproperty_slots() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let classes = class_objects(&api);
    let Some(actor) = classes.get("Actor") else {
        println!("no UClass named Actor");
        return;
    };
    let head = client::read_bytes(&api, *actor, 0, 0x60);
    let mut p = client::from_le_u64(&head, 0x50);
    for _ in 0..6 {
        if p == 0 {
            break;
        }
        let node = client::read_bytes(&api, p, 0, 0x60);
        if node.len() < 0x60 {
            println!("node {p:#x} unreadable");
            break;
        }
        let fname = client::from_le_u64(&node, 0x28);
        let name = api.op("fname_to_string", json!({"fname": fname}));
        let ints: Vec<String> = (0x30..0x58)
            .step_by(4)
            .map(|o| format!("+{o:#x}={:#x}", i32_at(&node, o)))
            .collect();
        println!(
            "{:<32} {}",
            name.result
                .get("string")
                .and_then(|s| s.as_str())
                .unwrap_or("?"),
            ints.join(" ")
        );
        p = client::from_le_u64(&node, 0x20);
    }
}
