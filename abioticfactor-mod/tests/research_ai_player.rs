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

fn read_ptr(api: &Api<Value>, addr: u64, offset: u64) -> u64 {
    let raw = read_bytes(api, addr, offset, 8);
    raw.get(0..8)
        .map(|b| u64::from_le_bytes([b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7]]))
        .unwrap_or(0)
}

fn full_name(api: &Api<Value>, addr: u64) -> String {
    if addr == 0 {
        return "null".into();
    }
    let reply = api.op("resolve_selector", json!({"selector": format!("addr:0x{addr:X}")}));
    reply
        .result
        .get("full_name")
        .and_then(Value::as_str)
        .unwrap_or("?")
        .to_string()
}

/// In a multiplayer game more than one player character and controller
/// can exist. Which character does the local player's controller
/// possess? Prints every player character with its Controller pointer
/// and every player controller with its Player (the local player or a
/// net connection) and its Pawn.
#[test]
fn player_characters_and_controllers() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }

    let Some((controller_offset, _)) = field(&api, "Pawn", "Controller") else {
        println!("Pawn has no reflected Controller field");
        return;
    };
    let Some((pawn_offset, _)) = field(&api, "Controller", "Pawn") else {
        println!("Controller has no reflected Pawn field");
        return;
    };
    let Some((player_offset, _)) = field(&api, "PlayerController", "Player") else {
        println!("PlayerController has no reflected Player field");
        return;
    };
    println!(
        "offsets: Pawn.Controller +{controller_offset}, Controller.Pawn +{pawn_offset}, PlayerController.Player +{player_offset}"
    );

    let (total, characters) = instances(&api, "Abiotic_PlayerCharacter_C", 16);
    println!("player characters: {total}");
    for character in &characters {
        let Some(addr) = addr_of(character) else { continue };
        let controller = read_ptr(&api, addr, controller_offset);
        println!(
            "  0x{addr:X} {}\n      Controller -> {}",
            character.get("name").and_then(Value::as_str).unwrap_or("?"),
            full_name(&api, controller)
        );
    }

    let (total, controllers) = instances(&api, "Abiotic_PlayerController_C", 16);
    println!("player controllers: {total}");
    for controller in &controllers {
        let Some(addr) = addr_of(controller) else { continue };
        let player = read_ptr(&api, addr, player_offset);
        let pawn = read_ptr(&api, addr, pawn_offset);
        println!(
            "  0x{addr:X} {}\n      Player -> {}\n      Pawn   -> {}",
            controller.get("name").and_then(Value::as_str).unwrap_or("?"),
            full_name(&api, player),
            full_name(&api, pawn)
        );
    }
}

/// Read an FString (TArray<TCHAR>: data pointer, count, capacity) at an offset.
fn read_fstring(api: &Api<Value>, addr: u64, offset: u64) -> String {
    let header = read_bytes(api, addr, offset, 16);
    if header.len() < 16 {
        return "<unreadable>".into();
    }
    let data = u64::from_le_bytes(header[0..8].try_into().unwrap());
    let count = i32::from_le_bytes(header[8..12].try_into().unwrap());
    if data == 0 || count <= 0 {
        return String::new();
    }
    let raw = read_bytes(api, data, 0, (count as u64) * 2);
    let units: Vec<u16> = raw
        .chunks_exact(2)
        .map(|c| u16::from_le_bytes([c[0], c[1]]))
        .take_while(|&u| u != 0)
        .collect();
    String::from_utf16_lossy(&units)
}

/// Every reflected field on a class whose name contains `needle`.
fn fields_containing(api: &Api<Value>, class: &str, needle: &str) -> Vec<(String, u64, u64)> {
    let detail = api.op("discover_class_detail", json!({"name": class}));
    detail
        .result
        .get("fields")
        .and_then(Value::as_array)
        .map(|fields| {
            fields
                .iter()
                .filter_map(|f| {
                    let name = f.get("name")?.as_str()?;
                    name.to_lowercase().contains(needle).then(|| {
                        (
                            name.to_string(),
                            f.get("offset").and_then(Value::as_u64).unwrap_or(0),
                            f.get("element_size").and_then(Value::as_u64).unwrap_or(0),
                        )
                    })
                })
                .collect()
        })
        .unwrap_or_default()
}

/// The join was refused with "Login failed: Join_PasswordInvalid". Which
/// object holds the password the game mode compares against, and what
/// does it hold right now? Walks the live game mode, game state, and
/// game instance and prints every field with "password" in its name.
#[test]
fn password_fields() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for needle in ["GameMode", "GameState", "GameInstance", "GameSession"] {
        let (total, objects) = instances(&api, needle, 6);
        println!("{needle}: {total} instance(s)");
        for object in &objects {
            let Some(addr) = addr_of(object) else { continue };
            let full = object.get("full_name").and_then(Value::as_str).unwrap_or("?");
            let class = full.split(' ').next().unwrap_or("?");
            println!("  0x{addr:X} {full}");
            for (name, offset, size) in fields_containing(&api, class, "password") {
                let value = if size == 16 {
                    read_fstring(&api, addr, offset)
                } else {
                    format!("{:?}", read_bytes(&api, addr, offset, size.min(16)))
                };
                println!("      {name} +{offset} size {size} = {value:?}");
            }
        }
    }
}

/// What does the host run to accept LAN players? Prints every net
/// driver with its class, its connection class, and its connections,
/// plus the game session and its session settings, so the join the
/// mod performs can be the one the host already accepts.
#[test]
fn net_driver_and_connections() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let (total, drivers) = instances(&api, "NetDriver", 8);
    println!("NetDriver instances: {total}");
    for driver in &drivers {
        let Some(addr) = addr_of(driver) else { continue };
        let full = driver.get("full_name").and_then(Value::as_str).unwrap_or("?");
        println!("  0x{addr:X} {full}");
        // The fields are declared on the engine's NetDriver base class;
        // the subclass detail lists only its own additions.
        let class = "NetDriver";
        for name in [
            "NetConnectionClass",
            "ServerConnection",
            "ClientConnections",
            "World",
            "NetDriverName",
            "MaxClientRate",
        ] {
            let Some((offset, size)) = field(&api, class, name) else {
                println!("      {name}: not on {class}");
                continue;
            };
            let raw = read_bytes(&api, addr, offset, size.min(16));
            let value = match name {
                "NetConnectionClass" | "ServerConnection" | "World" => {
                    full_name(&api, read_ptr(&api, addr, offset))
                }
                "ClientConnections" => {
                    let data = u64::from_le_bytes(raw[0..8].try_into().unwrap_or([0; 8]));
                    let count = i32::from_le_bytes(raw[8..12].try_into().unwrap_or([0; 4]));
                    let mut names = Vec::new();
                    for i in 0..count.max(0) as u64 {
                        names.push(full_name(&api, read_ptr(&api, data, i * 8)));
                    }
                    format!("{count} connection(s) {names:?}")
                }
                _ => format!("{raw:?}"),
            };
            println!("      {name} +{offset} size {size} = {value}");
        }
    }

    // The EOS driver's own additions (passthrough to plain UDP for a
    // LAN game, or EOS peer-to-peer) are plain C++ members: the PDB
    // says UIpNetDriver is 2424 bytes and UNetDriverEOS 2432, so its
    // state is the last 8 bytes. The world's URL (UWorld +1440, FURL:
    // Host +16, Port +32, Map +40, Op +72) is the address it listens on.
    for driver in &drivers {
        let Some(addr) = addr_of(driver) else { continue };
        println!(
            "  driver bytes 2424..2432 (EOS driver's own state) = {:?}",
            read_bytes(&api, addr, 2424, 8)
        );
        let Some((world_offset, _)) = field(&api, "NetDriver", "World") else { continue };
        let world = read_ptr(&api, addr, world_offset);
        let url = world + 1440;
        println!(
            "  world URL: host {:?} port {} map {:?}",
            read_fstring(&api, url, 16),
            i32::from_le_bytes(read_bytes(&api, url, 32, 4).try_into().unwrap_or([0; 4])),
            read_fstring(&api, url, 40)
        );
        let ops = read_bytes(&api, url, 72, 16);
        let data = u64::from_le_bytes(ops[0..8].try_into().unwrap_or([0; 8]));
        let count = i32::from_le_bytes(ops[8..12].try_into().unwrap_or([0; 4]));
        for i in 0..count.max(0) as u64 {
            println!("      option: {:?}", read_fstring(&api, data, i * 16));
        }
    }

    let (total, sessions) = instances(&api, "GameSession", 4);
    println!("GameSession instances: {total}");
    for session in &sessions {
        let Some(addr) = addr_of(session) else { continue };
        let full = session.get("full_name").and_then(Value::as_str).unwrap_or("?");
        println!("  0x{addr:X} {full}");
        for name in ["MaxPlayers", "MaxSpectators", "SessionName", "bRequiresPushToTalk"] {
            if let Some((offset, size)) = field(&api, "GameSession", name) {
                println!(
                    "      {name} +{offset} size {size} = {:?}",
                    read_bytes(&api, addr, offset, size.min(16))
                );
            }
        }
    }

    let (total, subsystems) = instances(&api, "OnlineSession", 8);
    println!("OnlineSession-named objects: {total}");
    for subsystem in &subsystems {
        println!(
            "  {}",
            subsystem.get("full_name").and_then(Value::as_str).unwrap_or("?")
        );
    }
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
                "MaxAcceleration",
                "BrakingDecelerationWalking",
                "GroundFriction",
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
