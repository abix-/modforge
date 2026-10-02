//! Ops for investigating in the running game without restarting it
//! (operator 2026-10-02: stop relaunching the game after every try).
//!
//! - `reload_save`: load the save last loaded, the way the game's load
//!   menu does (SaveController.LoadGameWithMigration, LoadMenu.cs:539).
//!   Gets back one clean area after a try left the game broken.
//! - `errors`: the errors the game logged since a mark, grouped by the
//!   game code that threw them, read from the game's own log
//!   (Application.consoleLogPath).

use std::sync::Mutex;
use std::time::Duration;

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{MonoObject, invoke_static, json_handle, owned_object};

use crate::first_copy_wins;

/// Where `errors` starts reading: (log path, byte offset).
static MARK: Mutex<Option<(String, u64)>> = Mutex::new(None);

pub fn install() {
    OP_REGISTRY.register(OpDef::new(
        "reload_save",
        "Load the save last loaded, as the game's load menu does; turns first_copy_wins off first",
        "{}",
        |_| MAIN_QUEUE.run_result("reload_save", Duration::from_secs(10), reload_save),
    ));
    OP_REGISTRY.register(OpDef::new(
        "errors",
        "Errors the game logged since the mark, grouped by the game code that threw them",
        r#"{"mark": true}  (mark: start counting from now)"#,
        |args| {
            let mark = args.get("mark").and_then(Json::as_bool) == Some(true);
            MAIN_QUEUE.run_result("errors", Duration::from_secs(10), move || errors(mark))
        },
    ));
}

fn reload_save() -> Result<Json, String> {
    first_copy_wins::set(Some(false))?;
    let character = save_controller_static("CharacterName")?;
    let save = save_controller_static("SaveName")?;
    let routine = obj(invoke_static("SaveController", "LoadGameWithMigration", &json!([character, save, true]))?)
        .ok_or("LoadGameWithMigration gave no coroutine")?;
    let controller = crate::deposit::first_instance("SaveController")?;
    controller.invoke("StartCoroutine", &json!([{"handle": routine.handle().0}]))?;
    if let Ok(game) = crate::deposit::first_instance("GameController") {
        let _ = game.write_field("GameIsPaused", &json!(false));
    }
    Ok(json!({"loading": format!("{character}/{save}")}))
}

/// A private static string on SaveController.
fn save_controller_static(field: &str) -> Result<String, String> {
    let ty = obj(invoke_static("System.Type", "GetType", &json!(["SaveController, Assembly-CSharp"]))?)
        .ok_or("SaveController type not found")?;
    let f = obj(ty.invoke("GetField", &json!([field, "NonPublic, Static"]))?)
        .ok_or_else(|| format!("SaveController.{field} not found"))?;
    f.invoke("GetValue", &json!([null]))?
        .as_str()
        .map(String::from)
        .ok_or_else(|| format!("SaveController.{field} is not set (no save loaded yet)"))
}

fn errors(mark: bool) -> Result<Json, String> {
    let path = invoke_static("UnityEngine.Application", "get_consoleLogPath", &json!([]))?
        .as_str()
        .map(String::from)
        .ok_or("no consoleLogPath")?;
    let text = std::fs::read(&path).map_err(|e| format!("read {path}: {e}"))?;
    if mark {
        *MARK.lock().unwrap() = Some((path, text.len() as u64));
        return Ok(json!({"marked": true}));
    }
    let from = match &*MARK.lock().unwrap() {
        Some((p, at)) if *p == path && (*at as usize) <= text.len() => *at as usize,
        _ => 0,
    };
    let text = String::from_utf8_lossy(&text[from..]);
    Ok(group(&text))
}

/// Counts each error by its message and the first game frame under it.
fn group(text: &str) -> Json {
    let mut counts: std::collections::BTreeMap<(String, String), u64> = Default::default();
    let mut lines = text.lines().peekable();
    let mut total = 0;
    while let Some(line) = lines.next() {
        if !line.contains("Exception:") {
            continue;
        }
        total += 1;
        let mut at = String::new();
        while let Some(next) = lines.peek() {
            let Some(frame) = next.strip_prefix("  at ") else { break };
            let frame = frame.split(" [0x").next().unwrap_or(frame);
            if at.is_empty() && !is_engine_frame(frame) {
                at = frame.to_string();
            }
            lines.next();
        }
        *counts.entry((line.trim().to_string(), at)).or_default() += 1;
    }
    let mut rows: Vec<_> = counts.into_iter().collect();
    rows.sort_by(|a, b| b.1.cmp(&a.1));
    json!({
        "total": total,
        "groups": rows.iter().take(20).map(|((error, at), n)| json!({"count": n, "error": error, "at": at})).collect::<Vec<_>>(),
    })
}

fn is_engine_frame(frame: &str) -> bool {
    ["UnityEngine.Bindings", "UnityEngine.Component", "UnityEngine.Object", "UnityEngine.GameObject", "System."]
        .iter()
        .any(|p| frame.starts_with(p))
}

fn obj(v: Json) -> Option<MonoObject> {
    json_handle(&v).map(owned_object)
}
