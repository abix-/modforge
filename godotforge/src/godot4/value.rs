//! Godot values to and from JSON.
//!
//! Out: vectors and colors are arrays (`[x, y]`, `[r, g, b, a]`),
//! rects are `{position, size}`, an object is `{class, id}` plus
//! `path` for a node, so its `id` can be passed back to any op.
//! Collections are cut at [`MAX_ITEMS`] and nesting at the caller's
//! depth; a cut collection ends with `{"more": n}`.
//!
//! In: the type the target expects decides the conversion (a
//! property's current value, a method's declared argument), so
//! `[1, 2]` becomes a Vector2 where a Vector2 is wanted and an array
//! elsewhere. `{"id": n}` and `{"node": "/root/..."}` become objects.

use godot::builtin::{
    AnyArray, AnyDictionary, Color, GString, NodePath, PackedByteArray, PackedFloat32Array,
    PackedFloat64Array, PackedInt32Array, PackedInt64Array, PackedStringArray, PackedVector2Array,
    Rect2, Rect2i, StringName, VarArray, VarDictionary, Variant, VariantType, Vector2, Vector2i,
    Vector3, Vector3i,
};
use godot::classes::{Node, Object};
use godot::meta::ToGodot;
use godot::obj::Gd;
use serde_json::{Map, Value as Json, json};

/// Items kept from one array or dictionary.
pub const MAX_ITEMS: usize = 100;

/// A Godot value as JSON, `depth` levels of nesting deep.
pub fn to_json(v: &Variant, depth: u32) -> Json {
    convert(v, depth).unwrap_or_else(|| json!(v.stringify().to_string()))
}

/// None for a type with no JSON form here; the caller stringifies it.
fn convert(v: &Variant, depth: u32) -> Option<Json> {
    let t = v.get_type();
    Some(match t {
        VariantType::NIL => Json::Null,
        VariantType::BOOL => json!(v.try_to::<bool>().ok()?),
        VariantType::INT => json!(v.try_to::<i64>().ok()?),
        VariantType::FLOAT => float(v.try_to::<f64>().ok()?),
        VariantType::STRING | VariantType::STRING_NAME | VariantType::NODE_PATH => {
            json!(v.stringify().to_string())
        }
        VariantType::VECTOR2 => {
            let p = v.try_to::<Vector2>().ok()?;
            json!([float(p.x as f64), float(p.y as f64)])
        }
        VariantType::VECTOR2I => {
            let p = v.try_to::<Vector2i>().ok()?;
            json!([p.x, p.y])
        }
        VariantType::VECTOR3 => {
            let p = v.try_to::<Vector3>().ok()?;
            json!([float(p.x as f64), float(p.y as f64), float(p.z as f64)])
        }
        VariantType::VECTOR3I => {
            let p = v.try_to::<Vector3i>().ok()?;
            json!([p.x, p.y, p.z])
        }
        VariantType::RECT2 => rect(v.try_to::<Rect2>().ok()?),
        VariantType::RECT2I => {
            let r = v.try_to::<Rect2i>().ok()?;
            json!({
                "position": [r.position.x, r.position.y],
                "size": [r.size.x, r.size.y],
            })
        }
        VariantType::COLOR => {
            let c = v.try_to::<Color>().ok()?;
            json!([c.r, c.g, c.b, c.a])
        }
        VariantType::OBJECT => match v.try_to::<Option<Gd<Object>>>() {
            Ok(Some(o)) => object(&o),
            Ok(None) => Json::Null,
            Err(_) => json!({"freed": true}),
        },
        // Any-typed forms: a typed array or dictionary (Array[Resource])
        // does not convert to the untyped one.
        VariantType::ARRAY => {
            let a = v.try_to::<AnyArray>().ok()?;
            array(a.iter_shared(), a.len(), depth)
        }
        VariantType::DICTIONARY => dictionary(&v.try_to::<AnyDictionary>().ok()?, depth),
        VariantType::PACKED_STRING_ARRAY => {
            let a = v.try_to::<PackedStringArray>().ok()?;
            let items: Vec<Variant> = a.as_slice().iter().map(|s| s.to_variant()).collect();
            let n = items.len();
            array(items.into_iter(), n, depth)
        }
        VariantType::PACKED_INT32_ARRAY => {
            packed(v.try_to::<PackedInt32Array>().ok()?.as_slice(), |x| {
                json!(x)
            })
        }
        VariantType::PACKED_INT64_ARRAY => {
            packed(v.try_to::<PackedInt64Array>().ok()?.as_slice(), |x| {
                json!(x)
            })
        }
        VariantType::PACKED_FLOAT32_ARRAY => {
            packed(v.try_to::<PackedFloat32Array>().ok()?.as_slice(), |x| {
                float(*x as f64)
            })
        }
        VariantType::PACKED_FLOAT64_ARRAY => {
            packed(v.try_to::<PackedFloat64Array>().ok()?.as_slice(), |x| {
                float(*x)
            })
        }
        VariantType::PACKED_VECTOR2_ARRAY => {
            packed(v.try_to::<PackedVector2Array>().ok()?.as_slice(), |p| {
                json!([float(p.x as f64), float(p.y as f64)])
            })
        }
        VariantType::PACKED_BYTE_ARRAY => {
            json!({"bytes": v.try_to::<PackedByteArray>().ok()?.len()})
        }
        _ => return None,
    })
}

/// `{class, id}` and `path` when it is a node in the tree.
pub fn object(o: &Gd<Object>) -> Json {
    let mut m = Map::new();
    m.insert("class".into(), json!(o.get_class().to_string()));
    m.insert("id".into(), json!(o.instance_id().to_i64()));
    if let Ok(node) = o.clone().try_cast::<Node>()
        && node.is_inside_tree()
    {
        m.insert("path".into(), json!(node.get_path().to_string()));
    }
    Json::Object(m)
}

pub fn rect(r: Rect2) -> Json {
    json!({
        "position": [float(r.position.x as f64), float(r.position.y as f64)],
        "size": [float(r.size.x as f64), float(r.size.y as f64)],
    })
}

fn float(f: f64) -> Json {
    serde_json::Number::from_f64(f).map_or(Json::Null, Json::Number)
}

fn array(items: impl Iterator<Item = Variant>, len: usize, depth: u32) -> Json {
    if depth == 0 {
        return json!({"items": len});
    }
    let mut out: Vec<Json> = items
        .take(MAX_ITEMS)
        .map(|v| to_json(&v, depth - 1))
        .collect();
    if len > MAX_ITEMS {
        out.push(json!({"more": len - MAX_ITEMS}));
    }
    Json::Array(out)
}

fn packed<T>(items: &[T], f: impl Fn(&T) -> Json) -> Json {
    let mut out: Vec<Json> = items.iter().take(MAX_ITEMS).map(f).collect();
    if items.len() > MAX_ITEMS {
        out.push(json!({"more": items.len() - MAX_ITEMS}));
    }
    Json::Array(out)
}

fn dictionary(d: &AnyDictionary, depth: u32) -> Json {
    if depth == 0 {
        return json!({"entries": d.len()});
    }
    let mut m = Map::new();
    for (k, v) in d.iter_shared().take(MAX_ITEMS) {
        m.insert(k.stringify().to_string(), to_json(&v, depth - 1));
    }
    if d.len() > MAX_ITEMS {
        m.insert("more".into(), json!(d.len() - MAX_ITEMS));
    }
    Json::Object(m)
}

/// The name of a Godot value type, as Godot's `type_string` gives it.
pub fn type_name(t: VariantType) -> String {
    format!("{t:?}")
}

/// JSON to a Godot value of type `want` (None: whatever the JSON is).
pub fn from_json(v: &Json, want: Option<VariantType>) -> Result<Variant, String> {
    let want = want.filter(|t| *t != VariantType::NIL);
    Ok(match v {
        Json::Null => Variant::nil(),
        Json::Bool(b) => b.to_variant(),
        Json::Number(n) => {
            if want == Some(VariantType::FLOAT) || (want.is_none() && n.is_f64()) {
                n.as_f64().unwrap_or(0.0).to_variant()
            } else if want == Some(VariantType::INT) || want.is_none() {
                n.as_i64()
                    .or_else(|| n.as_f64().map(|f| f as i64))
                    .unwrap_or(0)
                    .to_variant()
            } else if want == Some(VariantType::BOOL) {
                (n.as_f64().unwrap_or(0.0) != 0.0).to_variant()
            } else {
                return Err(format!(
                    "number given, {} wanted",
                    type_name(want.unwrap_or(VariantType::NIL))
                ));
            }
        }
        Json::String(s) => match want {
            Some(VariantType::STRING_NAME) => StringName::from(s.as_str()).to_variant(),
            Some(VariantType::NODE_PATH) => NodePath::from(s.as_str()).to_variant(),
            _ => GString::from(s.as_str()).to_variant(),
        },
        Json::Array(items) => match want {
            Some(t) if is_vector(t) => vector(items, t)?,
            _ => {
                let mut a = VarArray::new();
                for item in items {
                    a.push(&from_json(item, None)?);
                }
                a.to_variant()
            }
        },
        Json::Object(m) => {
            if let Some(id) = m.get("id").and_then(Json::as_i64) {
                return super::target::object_by_id(id).map(|o| o.to_variant());
            }
            if let Some(path) = m.get("node").and_then(Json::as_str) {
                return super::target::node_by_path(path).map(|n| n.to_variant());
            }
            let mut d = VarDictionary::new();
            for (k, item) in m {
                d.set(
                    &GString::from(k.as_str()).to_variant(),
                    &from_json(item, None)?,
                );
            }
            d.to_variant()
        }
    })
}

fn is_vector(t: VariantType) -> bool {
    [
        VariantType::VECTOR2,
        VariantType::VECTOR2I,
        VariantType::VECTOR3,
        VariantType::VECTOR3I,
        VariantType::COLOR,
    ]
    .contains(&t)
}

fn vector(items: &[Json], t: VariantType) -> Result<Variant, String> {
    let n: Vec<f64> = items.iter().filter_map(Json::as_f64).collect();
    if n.len() != items.len() {
        return Err(format!("{} wants numbers", type_name(t)));
    }
    let need = match t {
        VariantType::VECTOR2 | VariantType::VECTOR2I => 2,
        VariantType::COLOR => 3,
        _ => 3,
    };
    if n.len() < need {
        return Err(format!(
            "{} wants {need} numbers, got {}",
            type_name(t),
            n.len()
        ));
    }
    Ok(match t {
        VariantType::VECTOR2 => Vector2::new(n[0] as f32, n[1] as f32).to_variant(),
        VariantType::VECTOR2I => Vector2i::new(n[0] as i32, n[1] as i32).to_variant(),
        VariantType::VECTOR3 => Vector3::new(n[0] as f32, n[1] as f32, n[2] as f32).to_variant(),
        VariantType::VECTOR3I => Vector3i::new(n[0] as i32, n[1] as i32, n[2] as i32).to_variant(),
        _ => Color::from_rgba(
            n[0] as f32,
            n[1] as f32,
            n[2] as f32,
            n.get(3).copied().unwrap_or(1.0) as f32,
        )
        .to_variant(),
    })
}
