//! What does the live game give an AI player to work with?
//!
//! Pure discovery against a loaded save. Each test closes one row in
//! `docs/todo.md`: navigation data, the character's movement values
//! that decide jump and crouch links, the Enhanced Input setup, and
//! the split-screen setting. Nothing here changes game state.
//!
//! ```text
//! cargo test -p abioticfactor-mod --test research_ai_player -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, ping_or_skip};
use modforge::client::Api;
use serde_json::{Value, json};

const PLAYER: &str = "first_class:Abiotic_PlayerCharacter_C";

fn hex_bytes(result: &Value) -> Vec<u8> {
    let hex = result.get("bytes_hex").and_then(Value::as_str).unwrap_or("");
    (0..hex.len())
        .step_by(2)
        .filter_map(|i| u8::from_str_radix(&hex[i..i + 2], 16).ok())
        .collect()
}

fn addr_of(instance: &Value) -> Option<u64> {
    let text = instance.get("addr").and_then(Value::as_str)?;
    u64::from_str_radix(text.trim_start_matches("0x"), 16).ok()
}

/// Every non-default object whose class chain contains `needle`.
fn instances(api: &Api<Value>, needle: &str, max: u64) -> (u64, Vec<Value>) {
    let reply = api.op("walk_class_chain", json!({"needle": needle, "max": max}));
    let total = reply.result.get("total").and_then(Value::as_u64).unwrap_or(0);
    let list = reply
        .result
        .get("instances")
        .and_then(Value::as_array)
        .cloned()
        .unwrap_or_default();
    (total, list)
}

/// (offset, element_size) of one reflected field on a class.
fn field(api: &Api<Value>, class: &str, name: &str) -> Option<(u64, u64)> {
    let detail = api.op("discover_class_detail", json!({"name": class}));
    detail
        .result
        .get("fields")?
        .as_array()?
        .iter()
        .find(|f| f.get("name").and_then(Value::as_str) == Some(name))
        .map(|f| {
            (
                f.get("offset").and_then(Value::as_u64).unwrap_or(0),
                f.get("element_size").and_then(Value::as_u64).unwrap_or(0),
            )
        })
}

fn read_bytes(api: &Api<Value>, addr: u64, offset: u64, length: u64) -> Vec<u8> {
    let reply = api.op(
        "read_bytes",
        json!({
            "instance_selector": format!("addr:0x{addr:X}"),
            "offset": offset,
            "length": length,
        }),
    );
    hex_bytes(&reply.result)
}

/// Print one float field (f32 or f64 by element size) with its offset.
fn print_float(api: &Api<Value>, class: &str, addr: u64, name: &str) {
    match field(api, class, name) {
        Some((offset, 4)) => {
            let raw = read_bytes(api, addr, offset, 4);
            let value = raw
                .get(0..4)
                .map(|b| f32::from_le_bytes([b[0], b[1], b[2], b[3]]));
            println!("  {name:24} +{offset:<5} f32 {value:?}");
        }
        Some((offset, 8)) => {
            let raw = read_bytes(api, addr, offset, 8);
            let value = raw.get(0..8).map(|b| {
                f64::from_le_bytes([b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7]])
            });
            println!("  {name:24} +{offset:<5} f64 {value:?}");
        }
        Some((offset, size)) => println!("  {name:24} +{offset:<5} size {size} (not a float)"),
        None => println!("  {name:24} NOT FOUND on {class}"),
    }
}

fn component(api: &Api<Value>, actor: u64, class: &str) -> Option<u64> {
    let reply = api.op("component_of_class", json!({"actor": actor, "class": class}));
    let text = reply.result.get("component")?.as_str()?;
    u64::from_str_radix(text.trim_start_matches("0x"), 16).ok()
}

#[test]
fn navigation_mesh_and_links() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }

    let (total, meshes) = instances(&api, "RecastNavMesh", 8);
    println!("RecastNavMesh instances: {total}");
    for mesh in &meshes {
        println!(
            "  {}",
            mesh.get("full_name").and_then(Value::as_str).unwrap_or("?")
        );
    }
    if let Some(addr) = meshes.first().and_then(addr_of) {
        println!("navigation mesh settings (first instance):");
        for name in [
            "TileSizeUU",
            "CellSize",
            "CellHeight",
            "AgentRadius",
            "AgentHeight",
            "AgentMaxSlope",
            "AgentMaxStepHeight",
        ] {
            print_float(&api, "RecastNavMesh", addr, name);
        }
    }

    let (total, volumes) = instances(&api, "NavMeshBoundsVolume", 32);
    println!("NavMeshBoundsVolume instances: {total}");
    for volume in &volumes {
        println!(
            "  {}",
            volume.get("full_name").and_then(Value::as_str).unwrap_or("?")
        );
    }

    let (total, links) = instances(&api, "NavLinkProxy", 32);
    println!("NavLinkProxy instances: {total}");
    for link in &links {
        println!(
            "  {}",
            link.get("full_name").and_then(Value::as_str).unwrap_or("?")
        );
    }
    let (total, _) = instances(&api, "NavLinkCustomComponent", 1);
    println!("NavLinkCustomComponent instances: {total}");
    let (total, _) = instances(&api, "NavigationSystemV1", 1);
    println!("NavigationSystemV1 instances: {total}");
}

#[test]
fn character_movement_values() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }

    let player = api.op("resolve_selector", json!({"selector": PLAYER}));
    let Some(player_addr) = addr_of(&player.result) else {
        println!("no player character: {:?}", player.result);
        return;
    };
    println!("player character 0x{player_addr:X}");

    match component(&api, player_addr, "CharacterMovementComponent") {
        Some(movement) => {
            println!("CharacterMovementComponent 0x{movement:X}");
            for name in [
                "JumpZVelocity",
                "GravityScale",
                "MaxStepHeight",
                "WalkableFloorAngle",
                "CrouchedHalfHeight",
                "MaxWalkSpeed",
                "MaxWalkSpeedCrouched",
                "AirControl",
                "JumpOffJumpZFactor",
                "Mass",
            ] {
                print_float(&api, "CharacterMovementComponent", movement, name);
            }
        }
        None => println!("no CharacterMovementComponent on the player"),
    }

    match component(&api, player_addr, "CapsuleComponent") {
        Some(capsule) => {
            println!("CapsuleComponent 0x{capsule:X}");
            for name in ["CapsuleRadius", "CapsuleHalfHeight"] {
                print_float(&api, "CapsuleComponent", capsule, name);
            }
        }
        None => println!("no CapsuleComponent on the player"),
    }
}

#[test]
fn enhanced_input_setup() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }

    let (total, subsystems) = instances(&api, "EnhancedInputLocalPlayerSubsystem", 8);
    println!("EnhancedInputLocalPlayerSubsystem instances: {total}");
    for subsystem in &subsystems {
        println!(
            "  {}",
            subsystem
                .get("full_name")
                .and_then(Value::as_str)
                .unwrap_or("?")
        );
    }

    let (total, contexts) = instances(&api, "InputMappingContext", 64);
    println!("InputMappingContext instances: {total}");
    for context in &contexts {
        println!(
            "  {}",
            context.get("full_name").and_then(Value::as_str).unwrap_or("?")
        );
    }

    let (total, actions) = instances(&api, "InputAction", 1024);
    let mut names: Vec<&str> = actions
        .iter()
        .filter_map(|a| a.get("name").and_then(Value::as_str))
        .collect();
    names.sort_unstable();
    println!("InputAction instances: {total}");
    for name in names {
        println!("  {name}");
    }
}

#[test]
fn split_screen_setting() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }

    let reply = api.op(
        "walk_class",
        json!({"class": "GameMapsSettings", "include_cdo": true, "max": 4}),
    );
    let settings = reply
        .result
        .get("instances")
        .and_then(Value::as_array)
        .cloned()
        .unwrap_or_default();
    println!("GameMapsSettings objects: {}", settings.len());
    for object in &settings {
        println!(
            "  {} cdo={}",
            object.get("full_name").and_then(Value::as_str).unwrap_or("?"),
            object.get("is_cdo").and_then(Value::as_bool).unwrap_or(false)
        );
    }

    let Some((offset, size)) = field(&api, "GameMapsSettings", "bUseSplitscreen") else {
        println!("bUseSplitscreen NOT FOUND on GameMapsSettings");
        return;
    };
    for object in &settings {
        let Some(addr) = addr_of(object) else { continue };
        let raw = read_bytes(&api, addr, offset, size.max(1));
        println!(
            "  0x{addr:X} bUseSplitscreen +{offset} size {size} raw byte {:?} (bitfield: bit position not reported by the class walk)",
            raw.first()
        );
    }
}
