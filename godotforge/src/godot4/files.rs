//! The game's own files (`res://`), read through Godot's file reader.
//!
//! An exported game keeps its files in a pack, often encrypted. The
//! engine opens them for the game, decrypting as it reads, so these
//! ops see the files the way the game does: no key needed. Compiled
//! scripts (`.gdc`) come out as Godot's script tokens, which GDRE
//! Tools (GDRETools/gdsdecomp) turns back into GDScript.

use std::path::{Path, PathBuf};

use godot::classes::{DirAccess, FileAccess};
use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};

use super::on_main;

/// Files one `res_list` returns at most.
const MAX_FILES: usize = 50_000;

pub fn register_ops() {
    OP_REGISTRY.register_many([
        OpDef::new(
            "res_list",
            "The game's files under a res:// folder, as the engine sees them (packed files included)",
            "{dir?: default res://, recursive?: true}",
            res_list,
        ),
        OpDef::new(
            "res_export",
            "Copy game files out of the pack to a local folder, keeping their res:// paths. \
             Give paths, or a dir with suffixes",
            "{to: local folder, paths?: [res://...], dir?: res://..., suffixes?: [\".gdc\", ...]}",
            res_export,
        ),
    ]);
}

fn list(dir: &str, recursive: bool, out: &mut Vec<String>) {
    // "res://" already ends in a slash; "res://game" needs one.
    let base = if dir.ends_with('/') {
        dir.to_string()
    } else {
        format!("{dir}/")
    };
    for f in DirAccess::get_files_at(dir).as_slice() {
        if out.len() >= MAX_FILES {
            return;
        }
        out.push(format!("{base}{f}"));
    }
    if recursive {
        for d in DirAccess::get_directories_at(dir).as_slice() {
            list(&format!("{base}{d}"), true, out);
        }
    }
}

fn res_list(args: &Json) -> Result<Json, String> {
    let dir = args
        .get("dir")
        .and_then(Json::as_str)
        .unwrap_or("res://")
        .to_string();
    let recursive = args
        .get("recursive")
        .and_then(Json::as_bool)
        .unwrap_or(true);
    on_main("res_list", move || {
        let mut files = Vec::new();
        list(&dir, recursive, &mut files);
        Ok(json!({"dir": dir, "count": files.len(), "files": files}))
    })
}

/// `res://a/b.gdc` under `to` as `to/a/b.gdc`; None for a path that
/// would leave `to`.
fn local_path(to: &Path, res: &str) -> Option<PathBuf> {
    let rel = res.strip_prefix("res://")?;
    if rel.split('/').any(|p| p == ".." || p.is_empty()) {
        return None;
    }
    Some(to.join(rel))
}

fn res_export(args: &Json) -> Result<Json, String> {
    let to = PathBuf::from(
        args.get("to")
            .and_then(Json::as_str)
            .ok_or("give to: a local folder")?,
    );
    let paths: Vec<String> = args
        .get("paths")
        .and_then(Json::as_array)
        .map(|a| {
            a.iter()
                .filter_map(Json::as_str)
                .map(str::to_string)
                .collect()
        })
        .unwrap_or_default();
    let dir = args.get("dir").and_then(Json::as_str).map(str::to_string);
    let suffixes: Vec<String> = args
        .get("suffixes")
        .and_then(Json::as_array)
        .map(|a| {
            a.iter()
                .filter_map(Json::as_str)
                .map(str::to_string)
                .collect()
        })
        .unwrap_or_default();
    if paths.is_empty() && dir.is_none() {
        return Err("give paths or dir".into());
    }
    on_main("res_export", move || {
        let mut wanted = paths;
        if let Some(dir) = &dir {
            let mut all = Vec::new();
            list(dir, true, &mut all);
            wanted.extend(
                all.into_iter()
                    .filter(|f| suffixes.is_empty() || suffixes.iter().any(|s| f.ends_with(s))),
            );
        }
        let mut written = 0usize;
        let mut bytes = 0usize;
        let mut failed = Vec::new();
        for res in &wanted {
            let Some(local) = local_path(&to, res) else {
                failed.push(json!({"path": res, "error": "not a res:// path inside the folder"}));
                continue;
            };
            let data = FileAccess::get_file_as_bytes(res.as_str());
            if data.is_empty() && !FileAccess::file_exists(res.as_str()) {
                failed.push(json!({"path": res, "error": "not found"}));
                continue;
            }
            let result = local
                .parent()
                .map_or(Ok(()), std::fs::create_dir_all)
                .and_then(|()| std::fs::write(&local, data.as_slice()));
            match result {
                Ok(()) => {
                    written += 1;
                    bytes += data.len();
                }
                Err(e) => failed.push(json!({"path": res, "error": e.to_string()})),
            }
        }
        Ok(json!({
            "to": to.display().to_string(),
            "written": written,
            "bytes": bytes,
            "failed": failed,
        }))
    })
}
