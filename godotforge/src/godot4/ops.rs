//! The Godot 4 ops every mod gets. Game crates add their own.

use godot::builtin::{Rect2, StringName, Variant, VariantType, Vector2};
use godot::classes::{CanvasItem, Control, Engine, Node, Object, Viewport};
use godot::meta::ToGodot;
use godot::obj::{Gd, Singleton};
use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Map, Value as Json, json};

use super::{on_main, target, value};

/// Nodes one tree or screen walk visits at most.
const MAX_NODES: usize = 5000;

/// PROPERTY_USAGE_GROUP | CATEGORY | SUBGROUP: inspector headings,
/// not properties.
const USAGE_HEADING: i64 = 64 | 128 | 256;
/// PROPERTY_USAGE_SCRIPT_VARIABLE.
const USAGE_SCRIPT_VARIABLE: i64 = 4096;

pub fn register_builtins() {
    modforge::counters::register_ops();
    OP_REGISTRY.register_many([
        OpDef::new("ping", "Liveness probe", "{}", |_| Ok(json!({"pong": true}))),
        OpDef::new("list_ops", "Every registered op", "{}", |_| {
            Ok(OP_REGISTRY.list_json())
        }),
        OpDef::new("op_metrics", "Per-op latency", "{}", |_| {
            Ok(modforge::ops::metrics_json())
        }),
        OpDef::new(
            "engine",
            "Godot version, frames drawn, and whether the op ran on the main thread",
            "{}",
            engine,
        ),
        OpDef::new(
            "tree",
            "The scene tree under a node: path, class, script, id, child count",
            "{id|node?: default /root, depth?: 3}",
            tree,
        ),
        OpDef::new(
            "autoloads",
            "The root's children: the game's autoload singletons and the current scene",
            "{}",
            autoloads,
        ),
        OpDef::new(
            "screen",
            "Every visible 2D node on screen: path, class, rect in viewport and window pixels, text, disabled, clickable",
            "{id|node?: default /root, text_only?: bool}",
            screen,
        ),
        OpDef::new(
            "inspect",
            "Every property of an object with its value; script variables marked",
            "{id|node, depth?: 2}",
            inspect,
        ),
        OpDef::new(
            "get_property",
            "One property's value",
            "{id|node, property: str, depth?: 3}",
            get_property,
        ),
        OpDef::new(
            "set_property",
            "Set a property; JSON is converted to the property's current type. Returns the value read back",
            "{id|node, property: str, value: any}",
            set_property,
        ),
        OpDef::new(
            "call_method",
            "Call a method; args are converted to the method's declared types",
            "{id|node, method: str, args?: [any], depth?: 3}",
            call_method,
        ),
        OpDef::new(
            "list_methods",
            "An object's methods with argument names and types; script methods marked",
            "{id|node, script_only?: bool}",
            list_methods,
        ),
        OpDef::new(
            "list_signals",
            "An object's signals with argument names and what is connected",
            "{id|node}",
            list_signals,
        ),
    ]);
    super::input::register_ops();
    super::files::register_ops();
    super::watch::register_ops();
}

fn depth(args: &Json, default: u32) -> u32 {
    args.get("depth")
        .and_then(Json::as_u64)
        .map_or(default, |d| d.min(8) as u32)
}

fn engine(_args: &Json) -> Result<Json, String> {
    on_main("engine", || {
        let engine = Engine::singleton();
        Ok(json!({
            "version": engine.get_version_info().to_variant().stringify().to_string(),
            "frames_drawn": engine.get_frames_drawn(),
            "main_thread": godot::init::is_main_thread(),
        }))
    })
}

fn node_row(node: &Gd<Node>) -> Map<String, Json> {
    let o = node.clone().upcast::<Object>();
    let mut m = Map::new();
    m.insert("path".into(), json!(node.get_path().to_string()));
    m.insert("class".into(), json!(o.get_class().to_string()));
    m.insert("id".into(), json!(o.instance_id().to_i64()));
    if let Some(script) = target::script_path(&o) {
        m.insert("script".into(), json!(script));
    }
    m
}

fn tree(args: &Json) -> Result<Json, String> {
    let args = args.clone();
    on_main("tree", move || {
        let start = target::node_or(&args, "/root")?;
        let max_depth = depth(&args, 3);
        let mut rows = Vec::new();
        let mut stack = vec![(start, 0u32)];
        while let Some((node, d)) = stack.pop() {
            if rows.len() >= MAX_NODES {
                rows.push(json!({"more": "node limit reached"}));
                break;
            }
            let mut row = node_row(&node);
            let children = node.get_children();
            row.insert("depth".into(), json!(d));
            row.insert("children".into(), json!(children.len()));
            rows.push(Json::Object(row));
            if d < max_depth {
                let kids: Vec<_> = children.iter_shared().collect();
                for child in kids.into_iter().rev() {
                    stack.push((child, d + 1));
                }
            }
        }
        Ok(json!({"nodes": rows}))
    })
}

fn autoloads(_args: &Json) -> Result<Json, String> {
    on_main("autoloads", || {
        let tree = target::scene_tree()?;
        let current = tree.get_current_scene().map(|n| n.instance_id());
        let root = tree.get_root().upcast::<Node>();
        let rows: Vec<Json> = root
            .get_children()
            .iter_shared()
            .map(|child| {
                let mut row = node_row(&child);
                row.insert(
                    "current_scene".into(),
                    json!(Some(child.instance_id()) == current),
                );
                Json::Object(row)
            })
            .collect();
        Ok(json!({"nodes": rows}))
    })
}

/// A 2D node's on-screen rect in viewport pixels, if it has a size.
fn screen_rect(item: &Gd<CanvasItem>) -> Option<Rect2> {
    let xform = item.get_global_transform_with_canvas();
    if let Ok(control) = item.clone().try_cast::<Control>() {
        return Some(xform * Rect2::new(Vector2::ZERO, control.get_size()));
    }
    let mut o = item.clone().upcast::<Object>();
    if !o.has_method("get_rect") {
        return None;
    }
    let local = o.try_call("get_rect", &[]).ok()?.try_to::<Rect2>().ok()?;
    Some(xform * local)
}

/// Viewport pixels to the window pixels input events use.
fn to_window(viewport: &Gd<Viewport>, r: Rect2) -> Rect2 {
    viewport.get_screen_transform() * r
}

fn screen(args: &Json) -> Result<Json, String> {
    let args = args.clone();
    on_main("screen", move || {
        let start = target::node_or(&args, "/root")?;
        let text_only = args
            .get("text_only")
            .and_then(Json::as_bool)
            .unwrap_or(false);
        let root_viewport = start.get_viewport().ok_or("node has no viewport")?;
        let visible = root_viewport.get_visible_rect();
        let mut rows = Vec::new();
        let mut visited = 0usize;
        let mut stack = vec![start];
        while let Some(node) = stack.pop() {
            visited += 1;
            if visited > MAX_NODES {
                rows.push(json!({"more": "node limit reached"}));
                break;
            }
            let item = node.clone().try_cast::<CanvasItem>().ok();
            if let Some(item) = &item
                && !item.is_visible_in_tree()
            {
                // Hidden: so is everything under it.
                continue;
            }
            let kids: Vec<_> = node.get_children().iter_shared().collect();
            for child in kids.into_iter().rev() {
                stack.push(child);
            }
            let Some(item) = item else { continue };
            let Some(viewport) = node.get_viewport() else {
                continue;
            };
            let rect = screen_rect(&item);
            if let Some(r) = rect
                && viewport == root_viewport
                && !r.intersects(visible)
            {
                continue;
            }
            let o = node.clone().upcast::<Object>();
            let text = o.get("text").try_to::<godot::builtin::GString>().ok();
            let text = text.map(|t| t.to_string()).filter(|t| !t.is_empty());
            if text_only && text.is_none() {
                continue;
            }
            let mut row = node_row(&node);
            if let Some(r) = rect {
                row.insert("rect".into(), value::rect(r));
                row.insert("window_rect".into(), value::rect(to_window(&viewport, r)));
            }
            if let Some(t) = text {
                row.insert("text".into(), json!(t));
            }
            let disabled = o.get("disabled");
            if disabled.get_type() == VariantType::BOOL {
                row.insert("disabled".into(), value::to_json(&disabled, 0));
            }
            if let Ok(control) = item.try_cast::<Control>() {
                // MOUSE_FILTER_IGNORE is 2.
                let filter = control.get("mouse_filter").try_to::<i64>().unwrap_or(0);
                row.insert("clickable".into(), json!(filter != 2));
            }
            rows.push(Json::Object(row));
        }
        Ok(json!({
            "viewport": value::rect(visible),
            "mouse": value::to_json(&root_viewport.get_mouse_position().to_variant(), 0),
            "nodes": rows,
        }))
    })
}

fn field(d: &godot::builtin::VarDictionary, key: &str) -> Variant {
    d.get(&key.to_variant()).unwrap_or_default()
}

fn inspect(args: &Json) -> Result<Json, String> {
    let args = args.clone();
    on_main("inspect", move || {
        let o = target::object(&args)?;
        let d = depth(&args, 2);
        let mut props = Vec::new();
        for p in o.get_property_list().iter_shared() {
            let usage = field(&p, "usage").try_to::<i64>().unwrap_or(0);
            if usage & USAGE_HEADING != 0 {
                continue;
            }
            let name = field(&p, "name").to_string();
            if name.is_empty() {
                continue;
            }
            let v = o.get(&StringName::from(name.as_str()));
            props.push(json!({
                "name": name,
                "type": value::type_name(v.get_type()),
                "script": usage & USAGE_SCRIPT_VARIABLE != 0,
                "value": value::to_json(&v, d),
            }));
        }
        let mut out = match value::object(&o) {
            Json::Object(m) => m,
            _ => Map::new(),
        };
        if let Some(script) = target::script_path(&o) {
            out.insert("script".into(), json!(script));
        }
        out.insert("properties".into(), Json::Array(props));
        Ok(Json::Object(out))
    })
}

fn string_arg(args: &Json, key: &str) -> Result<String, String> {
    args.get(key)
        .and_then(Json::as_str)
        .map(str::to_string)
        .ok_or_else(|| format!("give {key}"))
}

fn get_property(args: &Json) -> Result<Json, String> {
    let args = args.clone();
    on_main("get_property", move || {
        let o = target::object(&args)?;
        let name = string_arg(&args, "property")?;
        let v = o.get(&StringName::from(name.as_str()));
        Ok(json!({
            "type": value::type_name(v.get_type()),
            "value": value::to_json(&v, depth(&args, 3)),
        }))
    })
}

fn set_property(args: &Json) -> Result<Json, String> {
    let args = args.clone();
    on_main("set_property", move || {
        let mut o = target::object(&args)?;
        let name = StringName::from(string_arg(&args, "property")?.as_str());
        let given = args.get("value").ok_or("give value")?;
        let current = o.get(&name);
        let v = value::from_json(given, Some(current.get_type()))?;
        o.set(&name, &v);
        let after = o.get(&name);
        Ok(json!({
            "before": value::to_json(&current, 1),
            "after": value::to_json(&after, 1),
        }))
    })
}

/// A method's entry from `get_method_list`, if the object has it.
fn method_entry(o: &Gd<Object>, method: &str) -> Option<godot::builtin::VarDictionary> {
    o.get_method_list()
        .iter_shared()
        .find(|m| field(m, "name").to_string() == method)
}

/// A method entry's `args`: a typed array, so read as the any-typed one.
fn entry_args(entry: &godot::builtin::VarDictionary) -> Vec<godot::builtin::VarDictionary> {
    let Ok(args) = field(entry, "args").try_to::<godot::builtin::AnyArray>() else {
        return Vec::new();
    };
    args.iter_shared()
        .filter_map(|a| a.try_to::<godot::builtin::VarDictionary>().ok())
        .collect()
}

fn arg_types(entry: &godot::builtin::VarDictionary) -> Vec<VariantType> {
    entry_args(entry)
        .into_iter()
        .map(|a| VariantType {
            ord: field(&a, "type").try_to::<i32>().unwrap_or(0),
        })
        .collect()
}

fn call_method(args: &Json) -> Result<Json, String> {
    let args = args.clone();
    on_main("call_method", move || {
        let mut o = target::object(&args)?;
        let method = string_arg(&args, "method")?;
        if !o.has_method(method.as_str()) {
            return Err(format!("{} has no method {method}", o.get_class()));
        }
        let types = method_entry(&o, &method)
            .map(|e| arg_types(&e))
            .unwrap_or_default();
        let given = args
            .get("args")
            .and_then(Json::as_array)
            .cloned()
            .unwrap_or_default();
        let mut call_args = Vec::with_capacity(given.len());
        for (i, a) in given.iter().enumerate() {
            call_args.push(value::from_json(a, types.get(i).copied())?);
        }
        let result = o
            .try_call(method.as_str(), &call_args)
            .map_err(|e| format!("{method}: {e}"))?;
        Ok(json!({
            "type": value::type_name(result.get_type()),
            "result": value::to_json(&result, depth(&args, 3)),
        }))
    })
}

fn args_json(entry: &godot::builtin::VarDictionary) -> Vec<Json> {
    entry_args(entry)
        .into_iter()
        .map(|a| {
            json!({
                "name": field(&a, "name").to_string(),
                "type": value::type_name(VariantType {
                    ord: field(&a, "type").try_to::<i32>().unwrap_or(0),
                }),
            })
        })
        .collect()
}

/// A method entry's return type, with the class name for an object.
fn return_type(entry: &godot::builtin::VarDictionary) -> Json {
    let Ok(r) = field(entry, "return").try_to::<godot::builtin::VarDictionary>() else {
        return Json::Null;
    };
    let t = value::type_name(VariantType {
        ord: field(&r, "type").try_to::<i32>().unwrap_or(0),
    });
    let class = field(&r, "class_name").to_string();
    if class.is_empty() {
        json!(t)
    } else {
        json!(format!("{t} {class}"))
    }
}

fn list_methods(args: &Json) -> Result<Json, String> {
    let args = args.clone();
    on_main("list_methods", move || {
        let o = target::object(&args)?;
        let script_only = args
            .get("script_only")
            .and_then(Json::as_bool)
            .unwrap_or(false);
        let script_names: Vec<String> = o
            .get("script")
            .try_to::<Gd<godot::classes::Script>>()
            .ok()
            .map(|s| {
                s.get_script_method_list()
                    .iter_shared()
                    .map(|m| field(&m, "name").to_string())
                    .collect()
            })
            .unwrap_or_default();
        let rows: Vec<Json> = o
            .get_method_list()
            .iter_shared()
            .filter_map(|m| {
                let name = field(&m, "name").to_string();
                let script = script_names.contains(&name);
                (!script_only || script).then(|| {
                    json!({
                        "name": name,
                        "args": args_json(&m),
                        "defaults": field(&m, "default_args")
                            .try_to::<godot::builtin::AnyArray>()
                            .map_or(0, |a| a.len()),
                        "return": return_type(&m),
                        "script": script,
                    })
                })
            })
            .collect();
        Ok(json!({"methods": rows}))
    })
}

fn list_signals(args: &Json) -> Result<Json, String> {
    let args = args.clone();
    on_main("list_signals", move || {
        let o = target::object(&args)?;
        let rows: Vec<Json> = o
            .get_signal_list()
            .iter_shared()
            .map(|s| {
                let name = field(&s, "name").to_string();
                let connections = o.get_signal_connection_list(name.as_str());
                let targets: Vec<Json> = connections
                    .iter_shared()
                    .map(|c| {
                        let callable = field(&c, "callable");
                        json!(callable.stringify().to_string())
                    })
                    .collect();
                json!({"name": name, "args": args_json(&s), "connected": targets})
            })
            .collect();
        Ok(json!({"signals": rows}))
    })
}
