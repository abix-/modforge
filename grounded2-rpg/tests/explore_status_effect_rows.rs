// Discovery test: find rows in Table_StatusEffects matching the
// EStatusEffectType values we want to migrate skills to.
//
// Optimized vs. v1: reads the entire row-map element array in
// ONE batch read_bytes call, parses client-side, then reads each
// row body's Type+Value. Stops as soon as all target types are
// captured.
//
// Captures:
//   - row address
//   - FName u64 (the key in the TMap; what `FDataTableRowHandle`
//     needs in addition to the table pointer)
//   - row's Type and Value
//
// Run:
//   set BBP_DEBUG_PORT=17171
//   cargo test --release --target x86_64-pc-windows-msvc \
//     --test explore_status_effect_rows -- --nocapture --test-threads=1

mod common;

use serde_json::json;
use std::collections::BTreeMap;

const TARGET_TYPES: &[(u8, &str)] = &[
    (5, "MaxHealth"),
    (14, "FallDamage"),
    (23, "AttackDamage"),
    (24, "Health"),
    (29, "DamageReduction"),
    (30, "DamageReductionMultiplier"),
    (38, "LifeSteal"),
];

#[derive(Debug, Clone)]
struct RowFind {
    type_id: u8,
    fname_u64: u64,
    addr: u64,
    value: f32,
}

#[test]
fn discover_rows_by_type() {
    let api = common::Api::require();

    // 1. Find Table_StatusEffects.
    let r = api.op("walk_class", json!({"class": "DataTable", "max": 4096}));
    let instances = r
        .result
        .get("instances")
        .and_then(|v| v.as_array())
        .expect("walk_class returned no instances");

    let target = instances
        .iter()
        .find(|inst| {
            inst.get("full_name")
                .and_then(|v| v.as_str())
                .map(|s| s.contains("Table_StatusEffects.Table_StatusEffects"))
                .unwrap_or(false)
        })
        .expect("Table_StatusEffects not found");
    let table_addr_sel = target
        .get("addr_selector")
        .and_then(|v| v.as_str())
        .unwrap()
        .to_string();
    let table_addr = u64::from_str_radix(
        target.get("addr").unwrap().as_str().unwrap().trim_start_matches("0x"),
        16,
    )
    .unwrap();
    eprintln!("Table_StatusEffects @ 0x{table_addr:016x} (selector={table_addr_sel})");

    // 2. Read the row-map header (data_ptr + num + max). 16 bytes.
    let header_resp = api.op_ok(
        "read_bytes",
        json!({
            "instance_selector": &table_addr_sel,
            "offset": 0x30,
            "length": 16,
        }),
    );
    let header_bytes = common::hex_decode(
        header_resp
            .live_player
            .as_ref()
            .map(|_| ()) // unused; just appeasing the borrow
            .map(|_| "")
            .unwrap_or_default(),
    )
    .ok()
    .unwrap_or_default();
    let _ = header_bytes; // (unused; we use the result map below)
    let header_resp = api.op(
        "read_bytes",
        json!({
            "instance_selector": &table_addr_sel,
            "offset": 0x30,
            "length": 16,
        }),
    );
    let bytes = common::hex_decode(
        header_resp
            .result
            .get("bytes_hex")
            .and_then(|v| v.as_str())
            .unwrap(),
    )
    .unwrap();
    let data_ptr = u64::from_le_bytes(bytes[0..8].try_into().unwrap());
    let num = i32::from_le_bytes(bytes[8..12].try_into().unwrap());
    eprintln!("  row_map data=0x{data_ptr:016x}  num={num}");
    if data_ptr == 0 || num <= 0 {
        panic!("empty row map");
    }
    let num_rows = num as usize;

    // 3. Read the entire element array in ONE batch.
    // Each element is 24 bytes: { u64 fname; *u8 row_ptr; ... }
    let array_len = num_rows * 24;
    let elem_resp = api.op(
        "read_bytes",
        json!({
            "instance_selector": format!("addr:0x{data_ptr:x}"),
            "offset": 0,
            "length": array_len,
        }),
    );
    assert!(elem_resp.ok, "batch element read failed: {:?}", elem_resp.error);
    let elem_bytes = common::hex_decode(
        elem_resp
            .result
            .get("bytes_hex")
            .and_then(|v| v.as_str())
            .unwrap(),
    )
    .unwrap();
    eprintln!("  fetched {} bytes of element array", elem_bytes.len());

    // 4. For each non-null row, read 8 bytes at row+0x30 to get
    // Type+Value. Stop once all target types have a hit.
    let target_set: std::collections::HashSet<u8> =
        TARGET_TYPES.iter().map(|(t, _)| *t).collect();
    let mut found: BTreeMap<u8, RowFind> = BTreeMap::new();
    let mut rows_scanned = 0usize;

    for i in 0..num_rows {
        let off = i * 24;
        if off + 16 > elem_bytes.len() {
            break;
        }
        let fname = u64::from_le_bytes(elem_bytes[off..off + 8].try_into().unwrap());
        let row_ptr = u64::from_le_bytes(elem_bytes[off + 8..off + 16].try_into().unwrap());
        if row_ptr == 0 {
            continue;
        }
        rows_scanned += 1;

        let r2 = api.op(
            "read_bytes",
            json!({
                "instance_selector": format!("addr:0x{row_ptr:x}"),
                "offset": 0x30,
                "length": 8,
            }),
        );
        if !r2.ok {
            continue;
        }
        let row_bytes = common::hex_decode(
            r2.result
                .get("bytes_hex")
                .and_then(|v| v.as_str())
                .unwrap(),
        )
        .unwrap();
        let stat_type = row_bytes[0];
        let value = f32::from_le_bytes(row_bytes[4..8].try_into().unwrap());

        if target_set.contains(&stat_type) && !found.contains_key(&stat_type) {
            found.insert(
                stat_type,
                RowFind {
                    type_id: stat_type,
                    fname_u64: fname,
                    addr: row_ptr,
                    value,
                },
            );
            eprintln!(
                "  [{:5}] HIT type={stat_type:>3} value={value:>8.3} fname=0x{fname:016x} row=0x{row_ptr:016x}",
                rows_scanned
            );
            if found.len() == target_set.len() {
                eprintln!("  all target types found after {rows_scanned} row reads; stopping");
                break;
            }
        }
    }

    eprintln!("\n=== Migration target rows ===");
    for &(ty, name) in TARGET_TYPES {
        match found.get(&ty) {
            Some(f) => eprintln!(
                "  Type {ty:>3} ({name:<28}) value={:>8.3} fname=0x{:016x} addr=0x{:016x}",
                f.value, f.fname_u64, f.addr
            ),
            None => eprintln!("  Type {ty:>3} ({name:<28}) NOT FOUND in {rows_scanned} scanned rows"),
        }
    }

    eprintln!(
        "\nTable selector for the migration: {}",
        table_addr_sel
    );
}
