//! Finding the object an op is about.
//!
//! Every op that takes a target accepts `{"id": n}` (an object's
//! instance id, as any op returns it) or `{"node": "/root/..."}` (a
//! node path). Ids are checked against Godot's own object table, so a
//! stale id is an error, not a crash.

use godot::builtin::NodePath;
use godot::classes::{Engine, Node, Object, SceneTree};
use godot::obj::{Gd, InstanceId, Singleton};
use serde_json::Value as Json;

pub fn scene_tree() -> Result<Gd<SceneTree>, String> {
    Engine::singleton()
        .get_main_loop()
        .ok_or("no main loop")?
        .try_cast::<SceneTree>()
        .map_err(|_| "main loop is not a SceneTree".to_string())
}

pub fn root() -> Result<Gd<Node>, String> {
    Ok(scene_tree()?.get_root().upcast::<Node>())
}

pub fn object_by_id(id: i64) -> Result<Gd<Object>, String> {
    let iid = InstanceId::try_from_i64(id).ok_or_else(|| format!("bad id {id}"))?;
    Gd::<Object>::try_from_instance_id(iid).map_err(|_| format!("no live object with id {id}"))
}

pub fn node_by_path(path: &str) -> Result<Gd<Node>, String> {
    root()?
        .get_node_or_null(&NodePath::from(path))
        .ok_or_else(|| format!("no node at {path}"))
}

/// The op's target object, from `id` or `node`.
pub fn object(args: &Json) -> Result<Gd<Object>, String> {
    if let Some(id) = args.get("id").and_then(Json::as_i64) {
        return object_by_id(id);
    }
    if let Some(path) = args.get("node").and_then(Json::as_str) {
        return Ok(node_by_path(path)?.upcast::<Object>());
    }
    Err("give id or node".into())
}

/// The op's target node; `default` when neither `id` nor `node` given.
pub fn node_or(args: &Json, default: &str) -> Result<Gd<Node>, String> {
    if args.get("id").is_none() && args.get("node").is_none() {
        return node_by_path(default);
    }
    object(args)?
        .try_cast::<Node>()
        .map_err(|_| "target is not a node".to_string())
}

/// The script attached to an object, by its resource path.
pub fn script_path(o: &Gd<Object>) -> Option<String> {
    let script = o.get("script");
    let script = script.try_to::<Gd<godot::classes::Resource>>().ok()?;
    let path = script.get_path().to_string();
    (!path.is_empty()).then_some(path)
}
