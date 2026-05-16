//! Locate vanilla `genes.xml` next to the running Horsey.exe.
//! Probes a few candidate paths relative to the exe and prints
//! which one (if any) exists.

mod common;

use serde_json::{json, Value};
use std::path::PathBuf;

#[test]
fn find_genes_xml() {
    let Some(game) = common::launch("find_genes_xml") else { return };

    // Read the live Horsey.exe path via a debug op. game.build_info
    // exposes it via image_file_info (PathBuf, size, mtime).
    let bi = game.op_json("game.build_info", &json!({})).unwrap();
    let path_s = bi.get("result").and_then(|r| r.get("exe_path"))
        .and_then(Value::as_str).unwrap_or("");
    eprintln!("exe_path: {path_s}");
    assert!(!path_s.is_empty(), "build_info missing exe_path");

    let exe = PathBuf::from(path_s);
    let parent = exe.parent();
    let candidates: Vec<PathBuf> = match parent {
        Some(p) => vec![
            p.join("data").join("genes.xml"),
            p.join("genes.xml"),
            p.join("..").join("data").join("genes.xml"),
            p.join("..").join("..").join("data").join("genes.xml"),
            p.join("Content").join("data").join("genes.xml"),
        ],
        None => vec![],
    };

    let mut found: Option<PathBuf> = None;
    for c in &candidates {
        let exists = c.exists();
        eprintln!("  {} -> exists={exists}", c.display());
        if exists && found.is_none() {
            found = Some(c.clone());
        }
    }
    if let Some(p) = &found {
        let bytes = std::fs::metadata(p).map(|m| m.len()).unwrap_or(0);
        eprintln!("[FOUND] {} ({} bytes)", p.display(), bytes);
    } else {
        panic!("genes.xml not found in any candidate location");
    }
}
