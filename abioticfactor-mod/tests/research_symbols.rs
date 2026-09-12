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
