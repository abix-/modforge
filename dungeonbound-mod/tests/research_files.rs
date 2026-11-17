//! Research: the game's own files, read through Godot's file reader
//! (the pack is encrypted; the engine decrypts as it reads).
//!
//! Lists every res:// file, counts them by type, and exports the
//! scripts and data files to a local folder outside the repo for
//! GDRE Tools to decompile. Read-only in the game.

mod common;

use std::collections::BTreeMap;

use serde_json::json;

/// Where exported files go: outside the repo, the game's code is not ours.
const OUT: &str = r"C:\code\dungeonbound-recovered";

#[test]
fn research_res_files() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let listed = common::op(&api, "res_list", json!({"dir": "res://"}));
    let files: Vec<&str> = listed["files"]
        .as_array()
        .expect("files")
        .iter()
        .filter_map(|f| f.as_str())
        .collect();
    let mut by_type: BTreeMap<String, usize> = BTreeMap::new();
    for f in &files {
        let ext = f.rsplit_once('.').map_or("", |(_, e)| e).to_string();
        *by_type.entry(ext).or_default() += 1;
    }
    println!("{} files", files.len());
    for (ext, n) in &by_type {
        println!("  .{ext}: {n}");
    }
    for f in files.iter().filter(|f| f.contains("combat_resolver")) {
        println!("  {f}");
    }
    assert!(!files.is_empty(), "no res:// files listed");
}

#[test]
fn research_export_scripts_and_data() {
    let Some(api) = common::api_or_skip() else {
        return;
    };
    let exported = common::op(
        &api,
        "res_export",
        json!({
            "to": OUT,
            "dir": "res://",
            "suffixes": [".gd", ".gdc", ".remap", ".json", ".cfg", ".godot", ".binary"],
        }),
    );
    println!(
        "written {} files, {} bytes to {}; failed {}",
        exported["written"], exported["bytes"], exported["to"], exported["failed"]
    );
    assert!(exported["written"].as_u64().is_some_and(|n| n > 0));
}
