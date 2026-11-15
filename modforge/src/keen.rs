//! Keen Games' engine (Enshrouded): its type tables by name. The exe
//! keeps a record for every `keen::` type with its size and fields;
//! kfc-base (github.com/Brabb3l/kfc-parser) reads them, and this module
//! serves them as the `types.find` op so a mod can read a struct's
//! fields by name instead of by guessed offsets.

use crate::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use std::sync::OnceLock;

pub use kfc_base::reflection::{LookupKey, PrimitiveType, TypeMetadata, TypeRegistry};

/// The running exe's type tables, read once.
pub fn registry() -> Result<&'static TypeRegistry, String> {
    static REGISTRY: OnceLock<Result<TypeRegistry, String>> = OnceLock::new();
    REGISTRY
        .get_or_init(|| {
            let exe = std::env::current_exe().map_err(|e| format!("current exe: {e}"))?;
            TypeRegistry::load_from_executable(&exe)
                .map_err(|e| format!("read types from {}: {e}", exe.display()))
        })
        .as_ref()
        .map_err(Clone::clone)
}

/// A type by its full name (`keen::ecs::LootInteractionEvent`): size,
/// hash, and each field's offset and type, or each enum value.
pub fn describe(reg: &TypeRegistry, name: &str) -> Option<Json> {
    let ty = reg.get_by_name(LookupKey::Qualified(name))?;
    let fields: Vec<Json> = ty
        .struct_fields
        .values()
        .map(|f| {
            json!({
                "name": f.name,
                "offset": format!("{:#x}", f.data_offset),
                "type": reg.get(f.r#type).map(|t| t.qualified_name.as_str()),
            })
        })
        .collect();
    let values: Vec<Json> = ty
        .enum_fields
        .values()
        .map(|v| json!({"name": v.name, "value": v.value}))
        .collect();
    Some(json!({
        "name": ty.qualified_name,
        "size": ty.size,
        "kind": format!("{:?}", ty.primitive_type),
        "qualified_hash": format!("{:#x}", ty.qualified_hash),
        "parent": ty.inner_type.and_then(|i| reg.get(i)).map(|t| t.qualified_name.as_str()),
        "fields": fields,
        "values": values,
    }))
}

/// One named hole in a Kiln signature (`{name:d32}`, `{name:d8}`,
/// `{name:rel32}`): where it sits in the match and how to read it.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Hole {
    pub name: String,
    pub offset: usize,
    pub kind: HoleKind,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum HoleKind {
    /// A 4-byte value (a field offset).
    D32,
    /// A 1-byte value (a small field offset).
    D8,
    /// A call or jump's 4-byte relative target.
    Rel32,
}

impl HoleKind {
    pub fn len(self) -> usize {
        match self {
            HoleKind::D8 => 1,
            HoleKind::D32 | HoleKind::Rel32 => 4,
        }
    }
}

/// A signature in Kiln's sigdb form (github.com/frostdev-ops/kiln,
/// `sigdb/symbols`) as a patternsleuth signature with every named hole
/// open, and the holes.
pub fn kiln_sig(sig: &str) -> Result<(String, Vec<Hole>), String> {
    let mut out = Vec::new();
    let mut holes = Vec::new();
    let mut offset = 0;
    for token in sig.split_whitespace() {
        if let Some(inner) = token.strip_prefix('{').and_then(|t| t.strip_suffix('}')) {
            let (name, kind) = inner
                .rsplit_once(':')
                .ok_or_else(|| format!("hole {token} has no kind"))?;
            let kind = match kind {
                "d32" => HoleKind::D32,
                "d8" => HoleKind::D8,
                "rel32" => HoleKind::Rel32,
                _ => return Err(format!("hole {token}: unknown kind {kind}")),
            };
            out.extend(std::iter::repeat_n("??", kind.len()));
            holes.push(Hole {
                name: name.to_string(),
                offset,
                kind,
            });
            offset += kind.len();
        } else {
            out.push(token);
            offset += 1;
        }
    }
    Ok((out.join(" "), holes))
}

/// A hole's value in the bytes of a match at `at`: the number, or for
/// rel32 the address it points at.
pub fn hole_value(hole: &Hole, bytes: &[u8], at: u64) -> Option<u64> {
    let b = bytes.get(hole.offset..hole.offset + hole.kind.len())?;
    Some(match hole.kind {
        HoleKind::D8 => u64::from(b[0]),
        HoleKind::D32 => u64::from(u32::from_le_bytes(b.try_into().ok()?)),
        HoleKind::Rel32 => {
            let rel = i32::from_le_bytes(b.try_into().ok()?);
            (at + hole.offset as u64 + 4).wrapping_add_signed(i64::from(rel))
        }
    })
}

/// `types.find {name}`: one type; `types.search {text, max?}`: the full
/// names holding `text`.
pub fn register_ops() {
    OP_REGISTRY.register_many([
        OpDef::new(
            "types.find",
            "read-only: a Keen engine type by full name, with its size, hash and fields",
            "name",
            |args| {
                let name = args["name"].as_str().ok_or("name missing")?;
                describe(registry()?, name).ok_or_else(|| format!("no type {name:?}"))
            },
        ),
        OpDef::new(
            "types.search",
            "read-only: full names of Keen engine types holding text",
            "text, max?",
            |args| {
                let text = args["text"].as_str().ok_or("text missing")?;
                let max = args["max"].as_u64().unwrap_or(200) as usize;
                let names: Vec<&str> = registry()?
                    .iter()
                    .map(|t| t.qualified_name.as_str())
                    .filter(|n| n.contains(text))
                    .take(max)
                    .collect();
                Ok(json!({"names": names}))
            },
        ),
    ]);
}
