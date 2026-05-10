//! Walk DT_Materials rows. Layout from
//! `OutworldStation\Binaries\Win64\ue4ss\CXXHeaderDump\SpaceSalvageStation.hpp`:
//!
//! ```text
//! struct FSMaterialData : public FTableRowBase {  // size 0x170
//!     EItemMaterial Material;     // 0x0008  (u8)
//!     FText Name;                 // 0x0010
//!     FText Description;          // 0x0020
//!     UTexture2D* Icon;           // 0x0030
//!     FLinearColor Colour;        // 0x0038
//!     int32 MaxCanStack;          // 0x0048  <-- TARGET FOR STACK MOD
//!     UStaticMesh* ConveyItemMesh;// 0x0050
//!     FTransform ConveyItemTransform; // 0x0060
//!     int32 Value;                // 0x00C0
//!     ...
//! };
//! ```
//!
//! UDataTable.RowMap is `TMap<FName, uint8*>` at +0x30 (UE 5.x stable).
//!
//! Test pattern: each fn starts as `eprintln!` of observations.
//! Promote individual lines to `assert!` once we know what to expect.

mod common;

use serde_json::json;

const ROW_MAP_OFFSET: u64 = 0x30; // UDataTable::RowMap
const STACK_OFFSET: u64 = 0x48;   // FSMaterialData::MaxCanStack

/// Find the live DT_Materials and return its UObject address as
/// an `addr:0x...` selector string. Helper for the rest of the
/// tests.
fn find_dt_materials(api: &common::Api) -> Option<String> {
    let r = api.op(
        "walk_class",
        json!({"class": "DataTable", "max": 10000, "include_cdo": false}),
    );
    if !r.ok { return None; }
    r.result["instances"]
        .as_array()?
        .iter()
        .find(|i| i["name"].as_str() == Some("DT_Materials"))
        .and_then(|i| i["addr_selector"].as_str().map(|s| s.to_string()))
}

#[test]
fn dump_row_map_header() {
    let Some(api) = common::try_api() else { return };
    let Some(dt) = find_dt_materials(&api) else {
        eprintln!("DT_Materials not found");
        return;
    };
    eprintln!("DT_Materials at {dt}");

    // Read the TMap header at +0x30. uespy::ue::offsets::tmap
    // says ELEMENT_SIZE=24, DATA_NUM=8, but the wire-side has to
    // parse bytes itself.
    let r = api.op(
        "read_bytes",
        json!({"instance_selector": dt, "offset": ROW_MAP_OFFSET, "length": 16}),
    );
    let bytes = hex_decode(r.result["bytes_hex"].as_str().unwrap());
    let data_ptr = u64::from_le_bytes(bytes[0..8].try_into().unwrap());
    let data_num = i32::from_le_bytes(bytes[8..12].try_into().unwrap());
    eprintln!("RowMap data_ptr=0x{data_ptr:X}, data_num={data_num}");
}

#[test]
fn list_material_names_and_stacks() {
    let Some(api) = common::try_api() else { return };
    let Some(dt) = find_dt_materials(&api) else { return };

    // Read TMap header
    let r = api.op(
        "read_bytes",
        json!({"instance_selector": dt, "offset": ROW_MAP_OFFSET, "length": 16}),
    );
    let bytes = hex_decode(r.result["bytes_hex"].as_str().unwrap());
    let data_ptr = u64::from_le_bytes(bytes[0..8].try_into().unwrap());
    let data_num = i32::from_le_bytes(bytes[8..12].try_into().unwrap()) as usize;

    eprintln!("=== {data_num} TMap slots in DT_Materials.RowMap ===");

    // Read all slots in one shot. Slot stride = 24 (TSetElement<TPair>).
    let total_bytes = data_num * 24;
    let r = api.op(
        "read_bytes",
        json!({
            "instance_selector": format!("addr:0x{data_ptr:X}"),
            "offset": 0,
            "length": total_bytes,
        }),
    );
    if !r.ok {
        eprintln!("read_bytes on RowMap data failed: {:?}", r.error);
        return;
    }
    let slot_bytes = hex_decode(r.result["bytes_hex"].as_str().unwrap());

    let mut found = 0;
    for i in 0..data_num {
        let off = i * 24;
        let key = u64::from_le_bytes(slot_bytes[off..off+8].try_into().unwrap());
        let value = u64::from_le_bytes(slot_bytes[off+8..off+16].try_into().unwrap());
        if value == 0 { continue; } // free / unallocated slot

        // Resolve FName -> material name
        let r_name = api.op("fname_to_string", json!({"fname": key}));
        let name = if r_name.ok {
            r_name.result["string"].as_str().unwrap_or("?").to_string()
        } else {
            format!("fname=0x{key:016X}")
        };

        // Read the row's MaxCanStack (int32) at +0x48
        let r2 = api.op(
            "read_bytes",
            json!({
                "instance_selector": format!("addr:0x{value:X}"),
                "offset": STACK_OFFSET,
                "length": 4,
            }),
        );
        if !r2.ok { continue; }
        let stack_bytes = hex_decode(r2.result["bytes_hex"].as_str().unwrap());
        let stack = i32::from_le_bytes(stack_bytes[0..4].try_into().unwrap());

        eprintln!("  {name:<40} MaxCanStack={stack}");
        found += 1;
    }
    eprintln!("=== {found} live rows ===");
}

fn hex_decode(s: &str) -> Vec<u8> {
    (0..s.len())
        .step_by(2)
        .map(|i| u8::from_str_radix(&s[i..i+2], 16).unwrap())
        .collect()
}
