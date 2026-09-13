//! What the shipped PDB says about player input.
//!
//! Reads `AbioticFactor-Win64-Shipping.pdb` offline: the image-relative
//! addresses of `APlayerController::InputKey` and `UPlayerInput::InputKey`,
//! and the field layout of `FInputKeyParams`. No running game needed.
//! Override the PDB location with `ABIOTICFACTOR_PDB`.
//!
//! ```text
//! cargo test -p abioticfactor-mod --test research_symbols -- --nocapture
//! ```

use std::path::PathBuf;

use ueforge::symbols;

const DEFAULT_PDB: &str = r"C:\Games\Steam\steamapps\common\AbioticFactor\AbioticFactor\Binaries\Win64\AbioticFactor-Win64-Shipping.pdb";

fn pdb_path() -> Option<PathBuf> {
    let path = std::env::var_os("ABIOTICFACTOR_PDB")
        .map(PathBuf::from)
        .unwrap_or_else(|| PathBuf::from(DEFAULT_PDB));
    if path.is_file() {
        Some(path)
    } else {
        eprintln!("SKIP: no PDB at {}", path.display());
        None
    }
}

#[test]
fn input_key_addresses() {
    let Some(path) = pdb_path() else { return };
    for (class, method) in [
        ("APlayerController", "InputKey"),
        ("UPlayerInput", "InputKey"),
        ("UGameViewportClient", "InputKey"),
    ] {
        let found = symbols::functions(&path, class, method).expect("read pdb");
        println!("{class}::{method}: {} match(es)", found.len());
        for symbol in &found {
            println!("  rva 0x{:X}  {}", symbol.rva, symbol.decorated);
        }
        assert!(!found.is_empty(), "{class}::{method} not in the PDB");
    }
}

/// What the host runs when a LAN player joins, by name and address:
/// the connection the net driver creates, the login handshake, and
/// the player spawn at the end of it. The mod must perform the same
/// steps from inside the process, so every one of them has to exist
/// in this build.
#[test]
fn lan_join_symbols() {
    let Some(path) = pdb_path() else { return };
    let wanted: &[(&str, &str)] = &[
        ("UNetDriver", "AddClientConnection"),
        ("UNetDriver", "ServerReplicateActors"),
        ("UNetDriver", "TickDispatch"),
        ("UNetConnection", "InitBase"),
        ("UNetConnection", "InitRemoteConnection"),
        ("UNetConnection", "LowLevelSend"),
        ("UIpConnection", "InitBase"),
        ("UIpConnection", "InitRemoteConnection"),
        ("UIpConnection", "LowLevelSend"),
        ("UNetConnectionEOS", "InitBase"),
        ("UNetDriverEOS", "InitConnect"),
        ("UNetDriverEOS", "InitListen"),
        ("UWorld", "NotifyControlMessage"),
        ("UWorld", "NotifyAcceptingConnection"),
        ("UWorld", "NotifyAcceptedConnection"),
        ("UWorld", "WelcomePlayer"),
        ("UWorld", "SpawnPlayActor"),
        ("AGameModeBase", "Login"),
        ("AGameModeBase", "PreLogin"),
        ("AGameModeBase", "PostLogin"),
        ("AAbioticGameMode", "Login"),
        ("AAbioticGameMode", "PreLogin"),
        ("AAbioticGameMode", "PostLogin"),
        ("AGameSession", "ApproveLogin"),
        ("AAbioticGameSession", "ApproveLogin"),
        ("UEngine", "Browse"),
        ("UEngine", "CreateNewWorldContext"),
        ("UDemoNetConnection", "LowLevelSend"),
        ("UChildConnection", "InitChildConnection"),
    ];
    for (class, method) in wanted {
        match symbols::functions(&path, class, method) {
            Ok(found) if found.is_empty() => println!("{class}::{method}: not in the PDB"),
            Ok(found) => {
                for symbol in found {
                    println!("{class}::{method}: rva 0x{:X} {}", symbol.rva, symbol.decorated);
                }
            }
            Err(error) => println!("{class}::{method}: {error:#}"),
        }
    }
    for symbol in symbols::functions(&path, "", "StaticConstructObject_Internal").unwrap_or_default() {
        println!("StaticConstructObject_Internal: rva 0x{:X} {}", symbol.rva, symbol.decorated);
    }
    for class in ["UNetConnection", "UIpConnection", "FURL"] {
        match symbols::layout(&path, class) {
            Ok(layout) => {
                println!("{class}: size {}", layout.size);
                for field in layout.fields.iter().filter(|f| {
                    matches!(
                        f.name.as_str(),
                        "Driver" | "PlayerController" | "OwningActor" | "URL" | "PlayerId"
                            | "State" | "RemoteAddr" | "Socket" | "SocketPrivate"
                            | "Op" | "Map" | "Host" | "Port"
                    )
                }) {
                    println!("  +{:<5} {:<24} {}", field.offset, field.name, field.type_name);
                }
            }
            Err(error) => println!("{class}: {error:#}"),
        }
    }
}

/// Plain C++ members the live reads need and reflection cannot see:
/// the EOS driver's passthrough flag, the IP driver's socket, and the
/// world's URL (the host's listen address and options).
#[test]
fn net_driver_layout_symbols() {
    let Some(path) = pdb_path() else { return };
    for (class, names) in [
        ("UNetDriverEOS", &["bIsPassthrough", "bIsUsingP2PSockets"][..]),
        ("UIpNetDriver", &["SocketPrivate", "Socket", "LocalAddr", "ServerDesiredSocketReceiveBufferBytes"][..]),
        ("UNetDriver", &["NetConnectionClass", "ServerConnection", "ClientConnections", "World", "LocalAddr"][..]),
        ("UWorld", &["URL", "NetDriver", "AuthorityGameMode", "GameState", "PersistentLevel"][..]),
    ] {
        match symbols::layout(&path, class) {
            Ok(layout) => {
                println!("{class}: size {}", layout.size);
                // The EOS driver is small enough to print whole; the
                // engine classes are filtered to the members we read.
                let all = class == "UNetDriverEOS";
                for field in layout
                    .fields
                    .iter()
                    .filter(|f| all || names.contains(&f.name.as_str()))
                {
                    println!("  +{:<5} {:<40} {}", field.offset, field.name, field.type_name);
                }
            }
            Err(error) => println!("{class}: {error:#}"),
        }
    }
}

/// The client connection code in the game binary: the pending-game
/// object a joining client runs before any world exists. Its
/// functions, its layout, the engine's world-context layout, the
/// object constructor, and the engine global, so the mod can connect
/// to the host on port 7777 the way a LAN client does.
#[test]
fn pending_net_game_symbols() {
    let Some(path) = pdb_path() else { return };
    let wanted: &[(&str, &str)] = &[
        ("UPendingNetGame", "Initialize"),
        ("UPendingNetGame", "InitNetDriver"),
        ("UPendingNetGame", "SendInitialJoin"),
        ("UPendingNetGame", "SendJoin"),
        ("UPendingNetGame", "Tick"),
        ("UPendingNetGame", "NotifyControlMessage"),
        ("UPendingNetGame", "SetFailure"),
        ("UEngine", "GetWorldContextFromWorld"),
        ("UEngine", "GetWorldContextFromPendingNetGame"),
        ("UEngine", "CreateNamedNetDriver"),
        ("UEngine", "FindNamedNetDriver"),
        ("UEngine", "DestroyNamedNetDriver"),
        ("UNetDriver", "InitConnect"),
        ("UNetDriver", "TickFlush"),
        ("UObjectBaseUtility", "AddToRoot"),
        ("UObject", "AddToRoot"),
        ("", "?0FURL"),
        ("", "StaticConstructObject_Internal"),
        ("", "NewObject"),
    ];
    for (class, method) in wanted {
        match symbols::functions(&path, class, method) {
            Ok(found) if found.is_empty() => println!("{class}::{method}: not in the PDB"),
            Ok(found) => {
                for symbol in found {
                    println!("{class}::{method}: rva 0x{:X} {}", symbol.rva, symbol.decorated);
                }
            }
            Err(error) => println!("{class}::{method}: {error:#}"),
        }
    }
    for name in ["GEngine", "GWorld"] {
        match symbols::globals(&path, name) {
            Ok(found) if found.is_empty() => println!("global {name}: not in the PDB"),
            Ok(found) => {
                for symbol in found {
                    println!("global {name}: rva 0x{:X} {}", symbol.rva, symbol.decorated);
                }
            }
            Err(error) => println!("global {name}: {error:#}"),
        }
    }
    for class in [
        "UPendingNetGame",
        "FWorldContext",
        "FStaticConstructObjectParameters",
        "FNamedNetDriver",
    ] {
        match symbols::layout(&path, class) {
            Ok(layout) => {
                println!("{class}: size {}", layout.size);
                for field in &layout.fields {
                    println!("  +{:<5} {:<36} {}", field.offset, field.name, field.type_name);
                }
            }
            Err(error) => println!("{class}: {error:#}"),
        }
    }
}

/// The two constructors the join needs that are not public symbols,
/// the full URL layout the pending game takes, and the root-set flag
/// that keeps the pending-game object alive across garbage collection.
#[test]
fn join_constructor_symbols() {
    let Some(path) = pdb_path() else { return };
    for needle in ["StaticConstructObject_Internal", "FURL::FURL", "UObjectBaseUtility::AddToRoot"] {
        match symbols::procedures(&path, needle) {
            Ok(found) if found.is_empty() => println!("{needle}: not in the module symbols"),
            Ok(found) => {
                for symbol in found {
                    println!("{needle}: rva 0x{:X} {}", symbol.rva, symbol.decorated);
                }
            }
            Err(error) => println!("{needle}: {error:#}"),
        }
    }
    match symbols::layout(&path, "FURL") {
        Ok(layout) => {
            println!("FURL: size {}", layout.size);
            for field in &layout.fields {
                println!("  +{:<5} {:<24} {}", field.offset, field.name, field.type_name);
            }
        }
        Err(error) => println!("FURL: {error:#}"),
    }
    for name in ["EInternalObjectFlags", "ETravelType"] {
        match symbols::enumeration(&path, name) {
            Ok(values) => {
                println!("{name}:");
                for (value_name, value) in values {
                    println!("  {value_name} = {value}");
                }
            }
            Err(error) => println!("{name}: {error:#}"),
        }
    }
}

/// What does the host's login approval read from the login options?
/// `AAbioticGameSession::ApproveLogin` crashed on a null read
/// (AbioticGameSession.cpp:50) when the AI player logged in with only
/// `?Name=AIPlayer`. Walks the function's instructions in the shipped
/// exe and prints every string it references and every function it
/// calls, so the join can send the options a real client sends.
#[test]
fn approve_login_references() {
    let Some(path) = pdb_path() else { return };
    let exe_path = path.with_file_name("AbioticFactor-Win64-Shipping.exe");
    let data = std::fs::read(&exe_path).expect("read exe");
    let image = patternsleuth::image::Image::read(None, &data, Some(&exe_path), false)
        .expect("parse exe");

    let approve = symbols::functions(&path, "AAbioticGameSession", "ApproveLogin")
        .expect("read pdb");
    for symbol in &approve {
        print_references(&image, &path, &symbol.decorated, symbol.rva as u64);
    }
    assert!(!approve.is_empty(), "AAbioticGameSession::ApproveLogin not in the PDB");

    // What a real client appends to its login URL: the game's own
    // override of ULocalPlayer::GetGameLoginOptions.
    let login_options = symbols::procedures(&path, "GetGameLoginOptions").expect("read pdb");
    for symbol in &login_options {
        print_references(&image, &path, &symbol.decorated, symbol.rva as u64);
    }
    assert!(!login_options.is_empty(), "GetGameLoginOptions not in the PDB");
}

/// Walk one function's instructions in the exe and print every string
/// it references and every function it calls, by PDB name.
fn print_references(
    image: &patternsleuth::image::Image<'_>,
    pdb: &std::path::Path,
    name: &str,
    rva: u64,
) {
    use patternsleuth::MemoryTrait as _;
    let base = image.base_address;
    let start = base + rva;
    println!("{name} at rva 0x{rva:X} (image base 0x{base:X})");
    let path = pdb;

    let mut calls = Vec::new();
    let mut references = Vec::new();
    let mut listing = Vec::new();
    patternsleuth::disassemble::disassemble(image, start, |inst| {
        let cur = inst.ip();
        if image.get_root_function(cur)?.map(|f| f.range.start) != Some(start) {
            return Ok(patternsleuth::disassemble::Control::Break);
        }
        listing.push((cur - base, format!("{inst}")));
        if inst.is_call_near() {
            calls.push((cur - base, inst.near_branch_target() - base));
        }
        if inst.is_ip_rel_memory_operand() {
            references.push((cur - base, inst.ip_rel_memory_address()));
        }
        Ok(patternsleuth::disassemble::Control::Continue)
    })
    .expect("disassemble");

    println!("references ({}):", references.len());
    for (at, target) in &references {
        let text = match image.memory.range_from(*target..) {
            Ok(bytes) => {
                let wide: Vec<u16> = bytes
                    .chunks_exact(2)
                    .map(|c| u16::from_le_bytes([c[0], c[1]]))
                    .take(96)
                    .take_while(|&u| u != 0)
                    .collect();
                let printable =
                    |u: &u16| (0x20..0x7F).contains(u);
                if wide.len() >= 2 && wide.iter().all(printable) {
                    format!("L{:?}", String::from_utf16_lossy(&wide))
                } else {
                    let narrow: Vec<u8> = bytes.iter().copied().take(96).take_while(|&b| b != 0).collect();
                    if narrow.len() >= 3 && narrow.iter().all(|b| (0x20..0x7F).contains(b)) {
                        format!("{:?}", String::from_utf8_lossy(&narrow))
                    } else {
                        format!("data {:02X?}", &bytes[..bytes.len().min(8)])
                    }
                }
            }
            Err(_) => "unreadable".to_string(),
        };
        println!("  at +0x{at:X} -> 0x{:X} {text}", target - base);
    }
    listing.sort_by_key(|(at, _)| *at);
    println!("instructions ({}):", listing.len());
    for (at, text) in &listing {
        println!("  +0x{at:X}  {text}");
    }
    let targets: Vec<u32> = calls.iter().map(|(_, t)| *t as u32).collect();
    let names = symbols::names_at(&path, &targets).expect("name call targets");
    println!("calls ({}):", calls.len());
    for (at, target) in &calls {
        println!(
            "  at +0x{at:X} -> rva 0x{target:X} {}",
            names.get(&(*target as u32)).map(String::as_str).unwrap_or("?")
        );
    }
}

/// The AI player's login needs a valid unique net id (ApproveLogin
/// reads it without a null check). The engine builds one from a string
/// and a subsystem name through the online engine interface. Which of
/// those functions exist in this build, and how are the id wrapper and
/// the net connection laid out?
#[test]
fn unique_net_id_symbols() {
    let Some(path) = pdb_path() else { return };
    for needle in [
        "FUniqueNetIdRepl::UniqueIdFromString",
        "FUniqueNetIdRepl::ToString",
        "FUniqueNetIdRepl::SetUniqueNetId",
        "FUniqueNetIdWrapper::ToString",
        "FUniqueNetIdWrapper::GetType",
        "UOnlineEngineInterface::Get",
        "CreateUniquePlayerIdWrapper",
        "GetDefaultOnlineSubsystemName",
        "ULocalPlayer::GetPreferredUniqueNetId",
        "CreateUniquePlayerId",
        "FUniqueNetIdEOSPlus::",
    ] {
        match symbols::procedures(&path, needle) {
            Ok(found) if found.is_empty() => println!("{needle}: not in the module symbols"),
            Ok(found) => {
                for symbol in found.iter().take(12) {
                    println!("{needle}: rva 0x{:X} {}", symbol.rva, symbol.decorated);
                }
            }
            Err(error) => println!("{needle}: {error:#}"),
        }
    }
    for class in ["FUniqueNetIdRepl", "FUniqueNetIdWrapper", "UNetConnection"] {
        match symbols::layout(&path, class) {
            Ok(layout) => {
                println!("{class}: size {}", layout.size);
                for field in layout.fields.iter().filter(|f| {
                    class != "UNetConnection" || matches!(f.name.as_str(), "PlayerId" | "Challenge" | "ClientResponse" | "RequestURL")
                }) {
                    println!("  +{:<5} {:<28} {}", field.offset, field.name, field.type_name);
                }
            }
            Err(error) => println!("{class}: {error:#}"),
        }
    }
}

/// Packet and bunch framing from the shipped engine, for the standalone UDP client.
#[test]
fn udp_packet_framing_symbols() {
    let path = pdb_path().expect("Abiotic PDB is required for protocol research");
    for method in ["ReceivedPacket", "SendRawBunch", "ReceivedRawPacket"] {
        let found = symbols::functions(&path, "UNetConnection", method).expect("read symbols");
        assert!(!found.is_empty(), "UNetConnection::{method} missing");
        for symbol in found { println!("UNetConnection::{method} +0x{:X}", symbol.rva); }
    }
}

#[test]
fn player_spawn_protocol_layouts() {
    let path = pdb_path().expect("Abiotic PDB is required");
    for name in ["FRepLayout", "FRepLayoutCmd", "FRepParentCmd", "FField"] {
        let layout = symbols::layout(&path, name).expect("read protocol layout");
        println!("{name}: size {}", layout.size);
        for field in layout.fields { println!("  +{} {} {}", field.offset, field.name, field.type_name); }
    }
    println!("command types: {:?}", symbols::enumeration(&path, "ERepLayoutCmdType").expect("command enum"));
    for (class, method) in [("UPackageMapClient", "SerializeNewActor")] {
        for symbol in symbols::functions(&path, class, method).expect("read symbols") {
            println!("{class}::{method} +0x{:X}", symbol.rva);
        }
    }
}

#[test]
fn actor_spawn_receive_functions() {
    let path = pdb_path().expect("Abiotic PDB");
    for method in ["ProcessBunch", "ReadContentBlockHeader"] {
        for symbol in symbols::functions(&path, "UActorChannel", method).expect("actor protocol symbols") {
            println!("UActorChannel::{method} +0x{:X}", symbol.rva);
        }
    }
    for symbol in symbols::functions(&path, "FByteProperty", "NetSerializeItem").expect("byte serialization") {
        println!("FByteProperty::NetSerializeItem +0x{:X}", symbol.rva);
    }
    for method in ["OnSerializeNewActor", "OnActorChannelOpen"] {
        for symbol in symbols::functions(&path, "APlayerController", method).expect("controller spawn symbols") {
            println!("APlayerController::{method} +0x{:X}", symbol.rva);
        }
    }
}

#[test]
fn rpc_parameter_serialization_functions() {
    let path = pdb_path().expect("Abiotic PDB");
    for method in ["ReceivePropertiesForRPC", "SendPropertiesForRPC"] {
        for symbol in symbols::functions(&path, "FRepLayout", method).expect("RPC parameter symbols") {
            println!("FRepLayout::{method} +0x{:X}", symbol.rva);
        }
    }
}

#[test]
fn player_possession_initialization_functions() {
    let path = pdb_path().expect("Abiotic PDB");
    for method in ["ServerNotifyLoadedWorld", "TickActor", "ShouldPerformFullTick", "HasClientLoadedCurrentWorld"] {
        for symbol in symbols::functions(&path, "APlayerController", method).expect("possession symbols") {
            println!("APlayerController::{method} +0x{:X}", symbol.rva);
        }
    }
}

#[test]
fn input_event_values() {
    let Some(path) = pdb_path() else { return };
    let values = symbols::enumeration(&path, "EInputEvent").expect("read EInputEvent");
    println!("EInputEvent:");
    for (name, value) in &values {
        println!("  {name} = {value}");
    }
    assert!(
        values.iter().any(|(name, _)| name == "IE_Axis"),
        "EInputEvent has no IE_Axis"
    );
}

#[test]
fn input_key_params_layout() {
    let Some(path) = pdb_path() else { return };
    for name in ["FInputKeyParams", "FKey", "FInputKeyEventArgs"] {
        match symbols::layout(&path, name) {
            Ok(layout) => {
                println!("{name}: size {}", layout.size);
                for (index, field) in layout.fields.iter().enumerate() {
                    let end = layout
                        .fields
                        .get(index + 1)
                        .map(|next| next.offset)
                        .unwrap_or(layout.size);
                    println!(
                        "  +{:<4} size {:<3} {:<28} {}",
                        field.offset,
                        end.saturating_sub(field.offset),
                        field.name,
                        field.type_name
                    );
                }
                if name == "FInputKeyParams" {
                    assert!(!layout.fields.is_empty(), "FInputKeyParams has no members");
                }
            }
            Err(error) => println!("{name}: {error:#}"),
        }
    }
}
