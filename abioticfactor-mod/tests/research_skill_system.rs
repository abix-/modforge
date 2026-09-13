//! How does the skill system work at runtime?
//!
//! Reads the live player character's SkillLevelMap, confirms
//! the TMap layout, resolves skill names, and reports current
//! skill levels.
//!
//! Findings (from usmap + runtime):
//! - SkillData has NO MaxLevel field. Level cap (20) is a
//!   Blueprint constant, not data-driven.
//! - SkillLevelMap is TMap<SkillRowHandle, int32> at offset
//!   2016 on AbioticCharacter.
//! - TMap entry stride: 48 bytes. Skill level at entry +32.
//! - 16 map entries for 15+ skills (Sprinting through Throwing,
//!   plus Repair/Resilience/Engineering/Fishing).
//! - SkillPerk.RequiredLevel gates perk unlocks (int32).
//! - ECharacterSkills enum: 18 values (NoSkill + 17 skills).
//!
//! ```text
//! cargo test -p abioticfactor-mod --test research_skill_system -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, ping_or_skip};
use serde_json::json;

const SKILL_LEVEL_MAP_OFFSET: usize = 2016;
const TMAP_ENTRY_STRIDE: usize = 48;
const LEVEL_OFFSET_IN_ENTRY: usize = 32;
const FNAME_OFFSET_IN_ENTRY: usize = 8;

#[test]
fn read_skill_levels() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }

    let player = api.op(
        "resolve_selector",
        json!({"selector": "first_class:Abiotic_PlayerCharacter_C"}),
    );
    println!(
        "player: {} @ {}",
        player.result.get("name").unwrap_or(&json!("?")),
        player.result.get("addr").unwrap_or(&json!("?"))
    );

    // Read TMap header (80 bytes at offset 2016)
    let tmap = api.op(
        "read_bytes",
        json!({
            "instance_selector": "first_class:Abiotic_PlayerCharacter_C",
            "offset": SKILL_LEVEL_MAP_OFFSET,
            "length": 16
        }),
    );
    let hex = tmap.result.get("bytes_hex").and_then(|h| h.as_str()).unwrap_or("");
    let raw: Vec<u8> = (0..hex.len())
        .step_by(2)
        .filter_map(|i| u8::from_str_radix(&hex[i..i + 2], 16).ok())
        .collect();

    let data_ptr = u64::from_le_bytes(raw[0..8].try_into().unwrap());
    let count = i32::from_le_bytes(raw[8..12].try_into().unwrap());
    let capacity = i32::from_le_bytes(raw[12..16].try_into().unwrap());
    println!(
        "SkillLevelMap: data=0x{:X}, count={}, capacity={}",
        data_ptr, count, capacity
    );

    // Read all entries
    let total_bytes = (count as usize) * TMAP_ENTRY_STRIDE;
    let entries = api.op(
        "read_bytes",
        json!({
            "instance_selector": format!("addr:0x{:X}", data_ptr),
            "offset": 0,
            "length": total_bytes
        }),
    );
    let hex = entries.result.get("bytes_hex").and_then(|h| h.as_str()).unwrap_or("");
    let raw: Vec<u8> = (0..hex.len())
        .step_by(2)
        .filter_map(|i| u8::from_str_radix(&hex[i..i + 2], 16).ok())
        .collect();

    println!("\nskill levels:");
    for i in 0..count as usize {
        let base = i * TMAP_ENTRY_STRIDE;
        let fname = u64::from_le_bytes(raw[base + FNAME_OFFSET_IN_ENTRY..base + FNAME_OFFSET_IN_ENTRY + 8].try_into().unwrap());
        let level = i32::from_le_bytes(raw[base + LEVEL_OFFSET_IN_ENTRY..base + LEVEL_OFFSET_IN_ENTRY + 4].try_into().unwrap());

        let name_result = api.op("fname_to_string", json!({"fname": fname}));
        let name = name_result.result.get("string").and_then(|s| s.as_str()).unwrap_or("?");
        println!("  {:20} level {}", name, level);
    }
}

#[test]
fn skill_xp_function_signatures() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }

    let funcs = [
        "UpdateSkillStat",
        "Server_TryAwardSkillXPOnTargetable",
        "Client_EventDispatch_SkillUp",
        "DoesAwardSkillXPWhenHit",
        "Server_Award XP Based On Recipe Category",
    ];

    println!("skill XP function signatures:");
    for func in &funcs {
        let params = api.op(
            "function_parameters",
            json!({"class": "Abiotic_PlayerCharacter_C", "function": func}),
        );
        let num = params.result.get("num_parms").and_then(|n| n.as_i64()).unwrap_or(0);
        let size = params.result.get("parms_size").and_then(|n| n.as_i64()).unwrap_or(0);
        print!("  {} ({} params, {} bytes):", func, num, size);
        if let Some(p) = params.result.get("parameters").and_then(|p| p.as_array()) {
            for param in p {
                let pname = param.get("name").and_then(|n| n.as_str()).unwrap_or("?");
                let psize = param.get("element_size").and_then(|n| n.as_i64()).unwrap_or(0);
                print!(" {}({})", pname, psize);
            }
        }
        println!();
    }
}

#[test]
fn skill_perk_names() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }

    let perks = api.op("dump_data_table", json!({"table_name": "DT_SkillPerks"}));
    if let Some(rows) = perks.result.get("rows").and_then(|r| r.as_array()) {
        println!("DT_SkillPerks: {} rows", rows.len());
        for row in rows {
            let name = row.get("row_name").and_then(|n| n.as_str()).unwrap_or("?");
            println!("  {}", name);
        }
    }
}
