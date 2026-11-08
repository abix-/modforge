//! Where did the game's fields move to on this build?
//!
//! Read-only. GameHelper2's static patterns still match, but fields
//! inside the game's objects moved. These tests search live memory
//! through the running poe2-mod (roots, patterns.read_bytes,
//! mem.wstring, read with modforge's memory_research client) for
//! things of a known shape and print the offsets they sit at.
//!
//! ```text
//! cargo run -p poe2-mod            # in one terminal, game running, in a zone
//! k3sc cargo-lock test -p poe2-mod --test research_offsets -- --nocapture --test-threads=1
//! ```
//!
//! SKIPs (prints why and passes) when poe2-mod or the game is not running.

use modforge::memory_research::{Remote, heap_pointer};
use serde_json::{Value, json};
use std::ops::Range;

/// How far into an object the searches look.
const SPAN: usize = 0x1000;

fn hex(v: &Value) -> u64 {
    u64::from_str_radix(v.as_str().unwrap_or("0").trim_start_matches("0x"), 16).unwrap_or(0)
}

struct Roots {
    remote: Remote,
    area: u64,
    world: u64,
    exe: Range<u64>,
}

fn roots() -> Option<Roots> {
    let remote = Remote::at(17185);
    let r = match remote.op("roots", json!({})) {
        Ok(r) => r,
        Err(e) => {
            println!("SKIP: {e}");
            return None;
        }
    };
    println!("{}", serde_json::to_string_pretty(&r).unwrap());
    Some(Roots {
        area: hex(&r["area_instance"]),
        world: hex(&r["world_data"]),
        exe: hex(&r["exe"][0])..hex(&r["exe"][1]),
        remote,
    })
}

/// The path of the entity at `p` (entity + 0x08 details, details +
/// 0x08 path), when it reads as a Metadata path.
fn entity_path(r: &Remote, p: u64) -> Option<String> {
    let details = r.word(p.wrapping_add(0x08))?;
    let path = r.wstring(details.wrapping_add(0x08))?;
    path.starts_with("Metadata/").then_some(path)
}

#[test]
fn local_player_in_the_area_instance() {
    let Some(g) = roots() else { return };
    let mut found = Vec::new();
    for (i, p) in g.remote.words(g.area, SPAN).into_iter().enumerate() {
        if !heap_pointer(p, &g.exe) {
            continue;
        }
        if let Some(path) = entity_path(&g.remote, p) {
            println!("area + {:#x} -> entity {p:#x} {path}", i * 8);
            found.push(path);
        }
    }
    assert!(
        found.iter().any(|p| p.starts_with("Metadata/Characters/")),
        "no player entity in the first {SPAN:#x} bytes of the area instance"
    );
}

/// std::map {head, size}: the head node's is_nil byte (0x19) is 1 and
/// its parent (the root) is a heap pointer.
#[test]
fn entity_maps_in_the_area_instance() {
    let Some(g) = roots() else { return };
    let w = g.remote.words(g.area, SPAN);
    let mut maps = 0;
    for i in 0..w.len().saturating_sub(1) {
        let (head, size) = (w[i], w[i + 1]);
        if !heap_pointer(head, &g.exe) || !(1..500_000).contains(&size) {
            continue;
        }
        let node = g.remote.bytes(head, 0x20);
        if node.len() < 0x20 || node[0x19] != 1 {
            continue;
        }
        let root = u64::from_le_bytes(node[8..16].try_into().unwrap());
        if !heap_pointer(root, &g.exe) {
            continue;
        }
        // The root's value: key at node + 0x20, value (entity) at 0x28.
        let entity = g.remote.word(root + 0x28).unwrap_or(0);
        let path = entity_path(&g.remote, entity);
        println!(
            "area + {:#x}: std::map of {size}, root {root:#x}, first value {entity:#x} {path:?}",
            i * 8
        );
        maps += usize::from(path.is_some());
    }
    assert!(maps > 0, "no std::map of entities in the area instance");
}

/// TerrainStruct: total tiles (two small i64) then the tile vector of
/// x * y tiles of 0x38 bytes.
#[test]
fn terrain_in_the_area_instance() {
    let Some(g) = roots() else { return };
    let w = g.remote.words(g.area, SPAN);
    let mut found = Vec::new();
    for i in 0..w.len().saturating_sub(4) {
        let (x, y, first, last) = (w[i], w[i + 1], w[i + 2], w[i + 3]);
        if !(1..2000).contains(&x) || !(1..2000).contains(&y) || !heap_pointer(first, &g.exe) {
            continue;
        }
        if last.wrapping_sub(first) == x * y * 0x38 {
            let base = i * 8 - 0x18;
            println!("terrain at area + {base:#x}: {x} x {y} tiles");
            for (name, off) in [("walkable", 0xD0), ("bytes per row", 0x130)] {
                let v = g.remote.word(g.area + base as u64 + off).unwrap_or(0);
                println!("  + {off:#x} ({name}): {v:#x}");
            }
            found.push(base);
        }
    }
    assert!(!found.is_empty(), "no tile vector in the area instance");
}

/// The WorldArea.dat row at GameHelper2's chain (world + 0x98, then
/// + 0x98): which of its fields point to text, and what text.
#[test]
fn zone_row_fields() {
    let Some(g) = roots() else { return };
    let Some(row) = g.remote.chain(g.world, &[0x98, 0x98]) else {
        panic!("no row at world + 0x98 + 0x98");
    };
    println!("row at {row:#x}");
    let mut texts = 0;
    for (i, p) in g.remote.words(row, 0x100).into_iter().enumerate() {
        let text = (p > 0x1_0000)
            .then(|| g.remote.wide_cstr(p, 128))
            .flatten()
            .filter(|s| s.len() >= 2 && s.chars().all(|c| (' '..='~').contains(&c)));
        println!("  + {:#04x}: {p:#018x} {}", i * 8, text.as_deref().unwrap_or(""));
        texts += usize::from(text.is_some());
    }
    assert!(texts > 0, "no text fields in the row");
}

/// From the world area details (world + 0x98), every pointer one step
/// on whose first 0x80 bytes point to readable text: where the
/// WorldArea.dat row moved to, and which of its fields hold the id and
/// the name.
#[test]
fn zone_details_texts() {
    let Some(g) = roots() else { return };
    let details = g.remote.word(g.world + 0x98).unwrap_or(0);
    println!(
        "details at {details:#x} (in exe: {})",
        g.exe.contains(&details)
    );
    let printable =
        |s: &String| s.len() >= 3 && s.chars().all(|c| (' '..='~').contains(&c));
    let mut found = 0;
    for (i, r) in g.remote.words(details, 0x400).into_iter().enumerate() {
        if r < 0x1_0000 || r > 0x7FFF_FFFF_FFFF {
            continue;
        }
        for (j, t) in g.remote.words(r, 0x80).into_iter().enumerate() {
            if t < 0x1_0000 || t > 0x7FFF_FFFF_FFFF {
                continue;
            }
            if let Some(s) = g.remote.wide_cstr(t, 128).filter(printable) {
                println!("details + {:#x} -> {r:#x} + {:#x} -> {s}", i * 8, j * 8);
                found += 1;
            }
        }
    }
    assert!(found > 0, "no text one pointer on from the details");
}

/// The area level byte and the instance hash at GameHelper2's offsets
/// (0xBC, 0x114) and 8 on (as the row pointer moved 0x98 to 0xA0).
/// The level should match the zone's; the hash changes each instance.
#[test]
fn area_level_and_hash() {
    let Some(g) = roots() else { return };
    let b = g.remote.bytes(g.area, 0x140);
    let dword = |o: usize| u32::from_le_bytes(b[o..o + 4].try_into().unwrap());
    for o in [0xBC, 0xC4] {
        println!("level byte at {o:#x}: {}", b[o]);
    }
    for o in [0x114, 0x11C] {
        println!("hash at {o:#x}: {:#010x}", dword(o));
    }
    for o in (0xB0..0x130).step_by(4) {
        println!("  {o:#x}: {:#010x} {}", dword(o), dword(o) as i32);
    }
}

/// The area change counter: some `inc dword [rip+x]` (FF 05) in the
/// code bumps it, and its value is the newest area change count on the
/// loaded files. Prints every such global in the exe holding that value.
#[test]
fn area_change_counter() {
    let Some(g) = roots() else { return };
    let counts = g.remote.op("file_counts", json!({})).expect("file_counts");
    println!("file counts: {counts}");
    let newest = counts["newest"][0][0].as_i64().expect("no loaded files") as u32;
    let sites = g
        .remote
        .op("patterns.rip_sites", json!({"sig": "FF 05 | ?? ?? ?? ??"}))
        .expect("rip_sites");
    println!("{} inc dword [rip] sites", sites["count"]);
    let mut hits = Vec::new();
    for s in sites["sites"].as_array().unwrap() {
        if s["in_image"] != json!(true) {
            continue;
        }
        let target = hex(&s["target"]);
        let b = g.remote.bytes(target, 4);
        if b.len() == 4 && u32::from_le_bytes(b[..4].try_into().unwrap()) == newest {
            let operand = hex(&s["operand"]);
            let code = g.remote.bytes(operand - 2, 16);
            let code: Vec<String> = code.iter().map(|b| format!("{b:02X}")).collect();
            println!(
                "target {target:#x} (rva {:#x}) = {newest}, from {operand:#x}: {}",
                target - g.exe.start,
                code.join(" ")
            );
            hits.push(target);
        }
    }
    assert!(!hits.is_empty(), "no incremented global holds {newest}");
}

/// The loaded files (GameHelper2 LoadedFilesRootObject): the "File
/// Root" global points at 0x10 buckets of 0x40 bytes, each a vector of
/// {_, file, _} pointers; a file has its name (wstring) at 0x08 and its
/// area change count at 0x40. Prints the first bucket's entries and
/// each file's first 0x60 bytes, so a moved field shows.
#[test]
fn loaded_file_records() {
    let Some(g) = roots() else { return };
    let statics = g.remote.op("statics", json!({})).expect("statics");
    let global = statics["patterns"]
        .as_array()
        .unwrap()
        .iter()
        .find(|p| p["name"] == "File Root" && p["address"].is_string())
        .map(|p| hex(&p["address"]))
        .expect("no File Root");
    let root = g.remote.word(global).expect("file root pointer");
    println!("File Root {global:#x} -> {root:#x}");
    for b in 0..2u64 {
        let bucket = g.remote.words(root + b * 0x40, 0x40);
        println!("bucket {b}: {:x?}", bucket);
        let (first, last) = (bucket[0], bucket[1]);
        let n = last.wrapping_sub(first);
        println!("  vector {first:#x}..{last:#x}: {n:#x} bytes ({} of 0x18)", n / 0x18);
        let entries = g.remote.words(first, 0x18 * 4);
        for (i, e) in entries.chunks(3).enumerate() {
            println!("  entry {i}: {e:x?}");
            for &p in e {
                if !heap_pointer(p, &g.exe) {
                    continue;
                }
                let w = g.remote.words(p, 0x60);
                let name = g.remote.wstring(p + 8);
                println!("    {p:#x}: {w:x?} name {name:?}");
            }
        }
    }
}

/// A WorldArea.dat row: its first field points to the zone id text and
/// the next to the zone name. Searched two pointers deep from the world
/// data.
#[test]
fn zone_row_from_the_world_data() {
    let Some(g) = roots() else { return };
    let plain = |s: &str| {
        (3..64).contains(&s.len())
            && s.chars().all(|c| c.is_ascii_alphanumeric() || c == '_')
    };
    let mut found = 0;
    for (i, p) in g.remote.words(g.world, 0x200).into_iter().enumerate() {
        if !heap_pointer(p, &g.exe) {
            continue;
        }
        for (j, row) in g.remote.words(p, 0x200).into_iter().enumerate() {
            if !heap_pointer(row, &g.exe) {
                continue;
            }
            let Some(id_at) = g.remote.word(row) else {
                continue;
            };
            if !heap_pointer(id_at, &g.exe) {
                continue;
            }
            let Some(id) = g.remote.wide_cstr(id_at, 64).filter(|s| plain(s)) else {
                continue;
            };
            let name = g
                .remote
                .word(row + 8)
                .and_then(|n| g.remote.wide_cstr(n, 128));
            println!(
                "world + {:#x} -> + {:#x} -> row {row:#x}: id {id}, name {name:?}",
                i * 8,
                j * 8
            );
            found += 1;
        }
    }
    assert!(found > 0, "no zone row two pointers from the world data");
}
