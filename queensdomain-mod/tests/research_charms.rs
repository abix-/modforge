//! What does the strength charm do?
//!
//! Prints every loaded Blueprint class and every data asset whose
//! name mentions strength or charm, with parents, and dumps the
//! fields of each strength one so its stats and description show.
//!
//! ```text
//! k3sc cargo-lock test -p queensdomain-mod --test research_charms -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, dump, instances, ping_or_skip};

/// Find where UE 4.27 keeps an FText's display string and where a
/// soft class ref keeps its path, by scanning instead of assuming.
/// Uses AttackPowerCharm: Name FText at +0x110, LogicComponent at
/// +0x40 (40 bytes).
#[test]
fn text_layout_probe() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let Some((item, _)) = instances(&api, "DataAsset", 20000)
        .into_iter()
        .find(|(_, n)| n == "AttackPowerCharm")
    else {
        println!("AttackPowerCharm not loaded");
        return;
    };
    for (label, off) in [("Name", 0x110u64), ("Description", 0x128)] {
        let ft = modforge::client::read_bytes(&api, item, off, 24);
        println!("{label} FText bytes: {}", hex::encode(&ft));
        let p = modforge::client::from_le_u64(&ft, 0);
        if p == 0 {
            continue;
        }
        let td = modforge::client::read_bytes(&api, p, 0, 0x60);
        println!("  text data {p:#x}: {}", hex::encode(&td));
        for slot in (0..0x60).step_by(8) {
            let q = modforge::client::from_le_u64(&td, slot);
            if !(q > 0x10000 && q < 0x7FFF_FFFF_FFFF) {
                continue;
            }
            let qb = modforge::client::read_bytes(&api, q, 0, 0x40);
            if qb.len() < 0x40 {
                continue;
            }
            println!("    +{slot:#x} -> {q:#x}: {}", hex::encode(&qb));
            for s2 in (0..0x40).step_by(8) {
                if let Some(s) = common::fstring_at(&api, q + s2 as u64) {
                    if !s.is_empty() {
                        println!("      +{s2:#x} FString \"{s}\"");
                    }
                }
                let r = modforge::client::from_le_u64(&qb, s2);
                if r > 0x10000 && r < 0x7FF0_0000_0000 && r != q {
                    for s3 in (0..0x60).step_by(8) {
                        if let Some(s) = common::fstring_at(&api, r + s3 as u64) {
                            if s.chars().count() > 3 && !s.contains('\u{FFFD}') {
                                println!("      +{s2:#x} -> {r:#x} +{s3:#x} FString \"{s}\"");
                            }
                        }
                    }
                }
            }
        }
        for slot in (0..0x60).step_by(8) {
            let f = modforge::client::from_le_u64(&td, slot);
            let r = api.op("fname_to_string", serde_json::json!({"fname": f}));
            let s = r.result.get("string").and_then(|s| s.as_str()).unwrap_or("?");
            if s != "None" && !s.starts_with('<') {
                println!("    +{slot:#x} as FName: {s}");
            }
        }
    }
    let lc = modforge::client::read_bytes(&api, item, 0x40, 40);
    println!("LogicComponent bytes: {}", hex::encode(&lc));
    for slot in (0..40).step_by(8) {
        let f = modforge::client::from_le_u64(&lc, slot);
        let r = api.op("fname_to_string", serde_json::json!({"fname": f}));
        println!(
            "  +{slot:#x} as FName: {}",
            r.result.get("string").and_then(|s| s.as_str()).unwrap_or("?")
        );
        if let Some(s) = common::fstring_at(&api, item + 0x40 + slot as u64) {
            println!("  +{slot:#x} as FString: {s}");
        }
    }
}

#[test]
fn strength_charm() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let bps = instances(&api, "BlueprintGeneratedClass", 20000);
    println!("== classes");
    for (addr, name) in &bps {
        let l = name.to_ascii_lowercase();
        if l.contains("strength") || l.contains("charm") {
            println!(
                "   {name} <- {}",
                common::super_chain(&api, *addr).join(" <- ")
            );
        }
    }
    println!("== data assets");
    for (addr, name) in instances(&api, "DataAsset", 20000) {
        let l = name.to_ascii_lowercase();
        if !(l.contains("strength") || l.contains("charm")) {
            continue;
        }
        let class = common::class_of(&api, addr);
        // FS_ItemData_C: Name +0x110, Item Description +0x128 (FText);
        // FS_Item: LogicComponent +0x40, a soft class ref whose
        // asset path FName sits at +0x10 inside it.
        let shown = common::ftext(&api, addr, 0x110).unwrap_or_default();
        let desc = common::ftext(&api, addr, 0x128).unwrap_or_default();
        let lb = modforge::client::read_bytes(&api, addr, 0x50, 8);
        let logic = if lb.len() == 8 {
            let f = modforge::client::from_le_u64(&lb, 0);
            let r = api.op("fname_to_string", serde_json::json!({"fname": f}));
            r.result.get("string").and_then(|s| s.as_str()).unwrap_or("").to_string()
        } else {
            String::new()
        };
        println!("   {name} ({class}) \"{shown}\"\n      desc: {desc}\n      logic: {logic}");
        // ItemTags +0x68 (tag container: TArray of FName) and
        // DataTags +0x88 (80 bytes, the size of a TMap). Print the
        // array elements as FName, and the map elements as FName key
        // plus f32 value at stride 24 (12 byte pair + 8 hash ints,
        // aligned to 8).
        for (label, off, stride) in [("ItemTags", 0x68u64, 8u64), ("DataTags", 0x88, 24)] {
            let h = modforge::client::read_bytes(&api, addr, off, 16);
            if h.len() < 16 {
                continue;
            }
            let data = modforge::client::from_le_u64(&h, 0);
            let num = i32::from_le_bytes(h[8..12].try_into().unwrap());
            if data == 0 || !(1..64).contains(&num) {
                println!("      {label}: {num}");
                continue;
            }
            let b = modforge::client::read_bytes(&api, data, 0, num as u64 * stride);
            let mut out = Vec::new();
            for i in 0..num as usize {
                let o = i * stride as usize;
                if b.len() < o + 12 {
                    break;
                }
                let f = modforge::client::from_le_u64(&b, o);
                let r = api.op("fname_to_string", serde_json::json!({"fname": f}));
                let tag = r.result.get("string").and_then(|s| s.as_str()).unwrap_or("?").to_string();
                if stride == 8 {
                    out.push(tag);
                } else {
                    let v = f32::from_le_bytes(b[o + 8..o + 12].try_into().unwrap());
                    out.push(format!("{tag}={v}"));
                }
            }
            println!("      {label}: {}", out.join(", "));
        }
        // No item is named "strength"; AttackPowerCharm is the
        // likely in-game "Strength Charm". Dump it and DefenseCharm.
        if l.contains("strength") || name == "AttackPowerCharm" || name == "DefenseCharm" {
            let cls = modforge::client::from_le_u64(&modforge::client::read_bytes(&api, addr, 0x10, 8), 0);
            let mut chain = vec![class.clone()];
            chain.extend(common::super_chain(&api, cls));
            for c in chain.iter().take_while(|c| {
                !matches!(c.as_str(), "DataAsset" | "PrimaryDataAsset" | "Object")
            }) {
                dump(&api, addr, c, None);
            }
        }
    }
}
