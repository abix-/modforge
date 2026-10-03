//! Ops for investigating in the running game without restarting it
//! (operator 2026-10-02: stop relaunching the game after every try).
//!
//! - `reload_save`, also the F7 key: getting unstuck. Puts the mod back to
//!   its starting state, then loads the save last loaded the way the
//!   game's load menu does (SaveController.LoadGameWithMigration,
//!   LoadMenu.cs:539). One clean area after a try left the game broken.
//! - `errors`: the errors the game logged since a mark, grouped by the
//!   game code that threw them, read from the game's own log
//!   (Application.consoleLogPath).

use std::sync::Mutex;
use std::time::Duration;

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use unityforge::input::{KeyCode, register_key_press};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{LogLevel, MonoObject, invoke_static, json_handle, log, owned_object};


/// Where `errors` starts reading: (log path, byte offset).
static MARK: Mutex<Option<(String, u64)>> = Mutex::new(None);

/// The in-game key for getting unstuck (the game's code uses F1, F11, F12;
/// deposit uses F6).
const UNSTUCK_KEY: KeyCode = KeyCode::F7;

pub fn install() {
    if register_key_press(UNSTUCK_KEY, on_unstuck_key).is_none() {
        log(LogLevel::Error, "obenseuer-mod: unstuck key binding failed");
    }
    OP_REGISTRY.register(OpDef::new(
        "reload_save",
        "Get unstuck (also the F7 key): mod back to its starting state, then load the save last loaded",
        "{}",
        |_| MAIN_QUEUE.run_result("reload_save", Duration::from_secs(10), reload_save),
    ));
    OP_REGISTRY.register(OpDef::new(
        "near_player",
        "Doors and drawn objects near the camera, in one frame: doors' state, and objects whose baked lighting index points past the baked lighting list",
        r#"{"metres": 20}"#,
        |args| {
            let metres = args.get("metres").and_then(Json::as_f64).unwrap_or(20.0);
            MAIN_QUEUE.run_result("near_player", Duration::from_secs(30), move || near_player(metres))
        },
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

/// Getting unstuck: one path for the op and the in-game key. Puts the mod
/// back to its starting state (no areas kept loaded, no door patch), then
/// loads the save last loaded, which unloads every other area.
fn reload_save() -> Result<Json, String> {
    crate::kept_loaded::reset();
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

extern "C" fn on_unstuck_key() {
    match reload_save() {
        Ok(r) => log(LogLevel::Info, &format!("obenseuer-mod: unstuck: {r}")),
        Err(e) => log(LogLevel::Warn, &format!("obenseuer-mod: unstuck failed: {e}")),
    }
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

fn near_player(metres: f64) -> Result<Json, String> {
    let camera = obj(invoke_static("UnityEngine.Camera", "get_main", &json!([]))?).ok_or("no main camera")?;
    let me = position(&camera)?;
    let maps = obj(invoke_static("UnityEngine.LightmapSettings", "get_lightmaps", &json!([]))?)
        .and_then(|m| m.read_field("Length").ok())
        .and_then(|v| v.as_i64())
        .unwrap_or(-1);

    let mut doors = Vec::new();
    for d in crate::deposit::instances_with("Changelevel", true)? {
        let Ok(p) = position(&d) else { continue };
        let dist = distance(me, p);
        if dist > metres {
            continue;
        }
        let collider = obj(d.invoke("GetComponent", &json!(["Collider"]))?)
            .map(|c| c.invoke("get_enabled", &json!([])).unwrap_or(Json::Null))
            .unwrap_or(json!("none"));
        doors.push(json!({
            "metres": (dist * 10.0).round() / 10.0,
            "to": d.read_field("OtherLevel")?,
            "on": d.invoke("get_isActiveAndEnabled", &json!([]))?,
            "open": d.read_field("isOpen").unwrap_or(Json::Null),
            "collider on": collider,
            "where": path(&d),
        }));
    }

    let near = obj(invoke_static("UnityEngine.Physics", "OverlapSphere", &json!([{"x": me[0], "y": me[1], "z": me[2]}, metres]))?)
        .ok_or("OverlapSphere gave nothing")?;
    let n = near.read_field("Length")?.as_i64().unwrap_or(0);
    let mut by_index: std::collections::BTreeMap<i64, u64> = Default::default();
    let mut past_the_list = Vec::new();
    for i in 0..n {
        let Some(c) = obj(near.invoke("GetValue", &json!([i]))?) else { continue };
        let Some(r) = obj(c.invoke("GetComponent", &json!(["Renderer"]))?) else { continue };
        if r.invoke("get_enabled", &json!([]))?.as_bool() != Some(true) {
            continue;
        }
        let index = r.invoke("get_lightmapIndex", &json!([]))?.as_i64().unwrap_or(-1);
        *by_index.entry(index).or_default() += 1;
        // 65534/65535: Unity's "no baked lighting" markers.
        if index >= maps && index < 65534 && past_the_list.len() < 40 {
            past_the_list.push(format!("{index}  {}", path(&c)));
        }
    }
    Ok(json!({
        "camera": me,
        "baked lighting list length": maps,
        "doors": doors,
        "colliders": n,
        "drawn objects by baked lighting index": by_index,
        "drawn objects with an index past the list (first 40)": past_the_list,
    }))
}

fn position(o: &MonoObject) -> Result<[f64; 3], String> {
    let t = obj(o.invoke("get_transform", &json!([]))?).ok_or("no transform")?;
    let p = t.invoke("get_position", &json!([]))?;
    let c = |k: &str| p.get(k).and_then(Json::as_f64).ok_or_else(|| format!("position has no {k}"));
    Ok([c("x")?, c("y")?, c("z")?])
}

fn distance(a: [f64; 3], b: [f64; 3]) -> f64 {
    (0..3).map(|i| (a[i] - b[i]).powi(2)).sum::<f64>().sqrt()
}

/// "Top / Object": the object's top parent and its own name.
fn path(o: &MonoObject) -> String {
    let name = |x: &MonoObject| x.invoke("get_name", &json!([])).ok().and_then(|v| v.as_str().map(String::from)).unwrap_or("?".into());
    let t = o.invoke("get_transform", &json!([])).ok().and_then(obj);
    let top = t.as_ref().and_then(|t| t.invoke("get_root", &json!([])).ok()).and_then(obj);
    match (top, t) {
        (Some(top), Some(t)) => format!("{} / {}", name(&top), name(&t)),
        _ => name(o),
    }
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
