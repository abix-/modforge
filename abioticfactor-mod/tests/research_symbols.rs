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
