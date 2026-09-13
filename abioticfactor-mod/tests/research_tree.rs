//! How the game's own behavior trees are put together, read from the live
//! game: the Exor controller's BT_Main_Exor asset walked node by node
//! (composites, tasks, decorators, services), every node's reflected fields
//! with their values, and the reflected fields of the engine node classes a
//! tree built in memory would use. Read-only; nothing is spawned or run.
//!
//! ```text
//! k3sc cargo-lock test -p abioticfactor-mod --test research_tree -- --nocapture
//! ```

mod common;
#[path = "common/spawn_trace.rs"]
#[allow(dead_code)]
mod spawn_trace;
use common::{api, ping_or_skip};
use modforge::client::Api;
use serde_json::{Value, json};
use spawn_trace::{decode_field, http_read, object_fields, object_name};

/// The class name of a live object.
fn class_name(api: &Api<Value>, object: u64) -> Result<String, String> {
    let class = u64::from_le_bytes(http_read(api, object + 16, 8)?.try_into().unwrap());
    Ok(object_name(api, class)?.unwrap_or_default())
}

fn pointer(api: &Api<Value>, address: u64) -> Result<u64, String> {
    Ok(u64::from_le_bytes(http_read(api, address, 8)?.try_into().unwrap()))
}

/// A TArray header: data pointer and count.
fn array(api: &Api<Value>, address: u64) -> Result<(u64, usize), String> {
    let bytes = http_read(api, address, 12)?;
    Ok((u64::from_le_bytes(bytes[..8].try_into().unwrap()), i32::from_le_bytes(bytes[8..12].try_into().unwrap()).max(0) as usize))
}

/// Print one node and everything under it. Field values are decoded by the
/// property class the live game declares; arrays of nodes are followed.
fn dump(api: &Api<Value>, object: u64, depth: usize, layout: &Layout) -> Result<(), String> {
    if object == 0 || depth > 14 { return Ok(()); }
    let pad = "  ".repeat(depth);
    println!("{pad}{} ({})", object_name(api, object)?.unwrap_or_default(), class_name(api, object)?);
    for (name, kind, offset) in object_fields(api, object)? {
        let address = object + u64::from(offset);
        match kind.as_str() {
            "ObjectProperty" | "ClassProperty" => {
                let target = pointer(api, address)?;
                if target == 0 { continue; }
                println!("{pad}  {name} = {} ({})", object_name(api, target)?.unwrap_or_default(), class_name(api, target)?);
                if name == "RootNode" { dump(api, target, depth + 1, layout)?; }
            }
            "ArrayProperty" => {
                let (data, count) = array(api, address)?;
                match name.as_str() {
                    "Children" => {
                        println!("{pad}  Children x{count}");
                        for index in 0..count {
                            let entry = data + (index * layout.child_stride) as u64;
                            let composite = pointer(api, entry + layout.child_composite as u64)?;
                            let task = pointer(api, entry + layout.child_task as u64)?;
                            let (decorators, decorator_count) = array(api, entry + layout.child_decorators as u64)?;
                            println!("{pad}  child {index}: decorators x{decorator_count}");
                            for d in 0..decorator_count { dump(api, pointer(api, decorators + (d * 8) as u64)?, depth + 2, layout)?; }
                            dump(api, if composite != 0 { composite } else { task }, depth + 2, layout)?;
                        }
                    }
                    "Services" | "RootDecorators" | "Decorators" => {
                        println!("{pad}  {name} x{count}");
                        for index in 0..count { dump(api, pointer(api, data + (index * 8) as u64)?, depth + 2, layout)?; }
                    }
                    _ => println!("{pad}  {name} = array x{count}"),
                }
            }
            "StructProperty" => {
                if name == "BlackboardKey" {
                    let key = decode_field(api, "NameProperty", address + layout.selector_key_name as u64)?;
                    println!("{pad}  BlackboardKey = {key}");
                } else {
                    println!("{pad}  {name} = struct");
                }
            }
            "NameProperty" | "FloatProperty" | "DoubleProperty" | "IntProperty" | "ByteProperty" | "BoolProperty" | "EnumProperty" => {
                match decode_field(api, &kind, address) { Ok(value) => println!("{pad}  {name} = {value}"), Err(error) => println!("{pad}  {name}: {error}") }
            }
            _ => println!("{pad}  {name}: {kind}"),
        }
    }
    Ok(())
}

/// Struct offsets read from the live game, never assumed.
struct Layout { child_stride: usize, child_composite: u32, child_task: u32, child_decorators: u32, selector_key_name: u32 }

fn field(fields: &[(String, String, u32)], name: &str) -> Result<u32, String> {
    fields.iter().find(|(n, _, _)| n == name).map(|(_, _, o)| *o).ok_or_else(|| format!("no field {name} in {fields:?}"))
}

#[test]
fn how_the_exor_tree_is_built() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    // Join Sophia with the Exor controller so its class, and its tree asset, are in memory.
    // A fresh join: a stale session (controller destroyed by the game, memory reused) reads garbage.
    let left = api.op("ai_player.stop", json!({}));
    println!("ai_player.stop: {}", if left.ok { left.result.to_string() } else { format!("{:?}", left.error) });
    let joined = api.op("ai_player.start", json!({"controller_class": "AI_Controller_NPC_Exor_C"}));
    println!("ai_player.start: {}", if joined.ok { joined.result["state"].to_string() } else { format!("{:?}", joined.error) });
    // Her controller, from the join reply (a fresh join describes it; a repeat gives the address).
    let controller = joined.result["controller"]["addr"].as_str().or(joined.result["controller"].as_str()).expect("controller address");
    let controller = u64::from_str_radix(controller.trim_start_matches("0x"), 16).unwrap();
    let tree = spawn_trace::object_field(&api, controller, "BehaviorTree").unwrap();
    assert_ne!(tree, 0, "the Exor controller default has no BehaviorTree");

    // Struct layouts from the live reflection: the child entry and the key selector.
    // The in-process reflection walk (struct.layout); discover_struct_detail
    // returned nonsense for this build (one field "rty" at 437, 2026-09-13).
    let struct_of = |name: &str| -> Vec<(String, String, u32)> {
        let reply = api.op("struct.layout", json!({"name": name}));
        assert!(reply.ok, "struct.layout {name}: {:?}", reply.error);
        reply.result["fields"].as_array().into_iter().flatten()
            .map(|f| (f["name"].as_str().unwrap_or("").to_owned(), f["type"].as_str().unwrap_or("").to_owned(), f["offset"].as_u64().unwrap_or(0) as u32)).collect()
    };
    let child = struct_of("BTCompositeChild");
    let selector = struct_of("BlackboardKeySelector");
    println!("BTCompositeChild: {child:?}");
    println!("BlackboardKeySelector: {selector:?}");
    let end = child.iter().map(|(_, _, o)| *o).max().unwrap();
    let layout = Layout {
        // The last field is a TArray (16 bytes); the entry ends there, pointer aligned.
        child_stride: ((end as usize + 16) + 7) / 8 * 8,
        child_composite: field(&child, "ChildComposite").unwrap(),
        child_task: field(&child, "ChildTask").unwrap(),
        child_decorators: field(&child, "Decorators").unwrap(),
        selector_key_name: field(&selector, "SelectedKeyName").unwrap(),
    };
    println!("child entry stride {}", layout.child_stride);

    println!("==== BT_Main_Exor as the engine holds it");
    dump(&api, tree, 0, &layout).unwrap();

    // Why the mod's in-process walk reports no fields on these classes while
    // this test's walker reads them: the raw first property records, decoded
    // with both FField layouts ueforge tries (next/name/offset at
    // 0x18/0x20/0x44 and 0x20/0x28/0x4C), plus the class's PropertiesSize.
    println!("==== raw property records");
    for class in ["BTTask_RunBehavior", "BTComposite_Selector", "AIController"] {
        let found = api.op("walk_class_chain", json!({"needle": class, "max": 4}));
        let Some(instance) = found.result["instances"].as_array().into_iter().flatten().next() else { println!("{class}: no instance"); continue };
        let object = u64::from_str_radix(instance["addr"].as_str().unwrap().trim_start_matches("0x"), 16).unwrap();
        let uclass = pointer(&api, object + 16).unwrap();
        // UStruct: SuperStruct@0x40, Children@0x48, ChildProperties@0x50, then the size fields.
        let header = http_read(&api, uclass + 0x40, 0x30).unwrap();
        println!("{class}: class 0x{uclass:X} bytes@0x40..0x70 {}", header.iter().map(|b| format!("{b:02X}")).collect::<Vec<_>>().join(" "));
        let mut field = pointer(&api, uclass + 0x50).unwrap();
        for _ in 0..3 {
            if field == 0 { break; }
            let record = http_read(&api, field, 0x60).unwrap();
            let decode = |next: usize, name: usize, offset: usize| -> String {
                let fname = u64::from_le_bytes(record[name..name + 8].try_into().unwrap());
                let text = api.op("fname_to_string", json!({"fname": fname})).result["string"].as_str().unwrap_or("?").to_owned();
                format!("next 0x{:X} name {text} offset {} size@0x34 {} size@0x3C {}", u64::from_le_bytes(record[next..next + 8].try_into().unwrap()), u32::from_le_bytes(record[offset..offset + 4].try_into().unwrap()),
                    u32::from_le_bytes(record[0x34..0x38].try_into().unwrap()), u32::from_le_bytes(record[0x3C..0x40].try_into().unwrap()))
            };
            println!("  field 0x{field:X}: A[{}] B[{}]", decode(0x18, 0x20, 0x44), decode(0x20, 0x28, 0x4C));
            field = u64::from_le_bytes(record[0x18..0x20].try_into().unwrap());
        }
    }
    println!("==== engine node classes a tree built in memory would use");
    for class in ["BehaviorTree", "BTComposite_Selector", "BTTask_RunBehavior", "BTTask_MoveTo", "BTDecorator_Blackboard", "BlackboardData"] {
        let detail = api.op("discover_class_detail", json!({"name": class}));
        let fields: Vec<String> = detail.result["fields"].as_array().into_iter().flatten()
            .map(|f| format!("{}:{}@{}", f["name"].as_str().unwrap_or(""), f["type"].as_str().unwrap_or(""), f["offset"])).collect();
        println!("{class}: {}", if detail.ok { fields.join(" ") } else { format!("{:?}", detail.error) });
    }
}
