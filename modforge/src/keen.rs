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
    /// How many bytes the hole covers.
    pub fn bytes(self) -> usize {
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
            out.extend(std::iter::repeat_n("??", kind.bytes()));
            holes.push(Hole {
                name: name.to_string(),
                offset,
                kind,
            });
            offset += kind.bytes();
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
    let b = bytes.get(hole.offset..hole.offset + hole.kind.bytes())?;
    Some(match hole.kind {
        HoleKind::D8 => u64::from(b[0]),
        HoleKind::D32 => u64::from(u32::from_le_bytes(b.try_into().ok()?)),
        HoleKind::Rel32 => {
            let rel = i32::from_le_bytes(b.try_into().ok()?);
            (at + hole.offset as u64 + 4).wrapping_add_signed(i64::from(rel))
        }
    })
}

/// The one match of a Kiln signature in the running exe's code, and
/// each hole's value by name (rel32 holes as absolute addresses).
pub fn find_in_exe(sig: &str) -> Result<(usize, Vec<(String, u64)>), String> {
    find_in(sig, None)
}

/// [`find_in_exe`] counting only matches inside `within` (start, len):
/// Kiln's scoped signatures, which are unique in one function only.
pub fn find_in(
    sig: &str,
    within: Option<(usize, usize)>,
) -> Result<(usize, Vec<(String, u64)>), String> {
    let (pattern, holes) = kiln_sig(sig)?;
    let hits: Vec<usize> = crate::patterns::sleuth::scan_all_matches(&pattern)
        .map_err(|e| format!("{e:#}"))?
        .into_iter()
        .filter(|a| within.is_none_or(|(start, len)| (start..start + len).contains(a)))
        .collect();
    let [at] = hits[..] else {
        return Err(format!("{} matches for {sig:?}", hits.len()));
    };
    let len = pattern.split_whitespace().count();
    // SAFETY: patternsleuth matched `len` bytes of the loaded exe's
    // code at `at`; the image stays mapped for the process lifetime.
    let bytes = unsafe { std::slice::from_raw_parts(at as *const u8, len) };
    let values = holes
        .iter()
        .map(|h| {
            let v = hole_value(h, bytes, at as u64).ok_or("hole past the match")?;
            Ok((h.name.clone(), v))
        })
        .collect::<Result<Vec<_>, String>>()?;
    Ok((at, values))
}

/// Where a world's events wait between two sim steps: an array of
/// buffers at `storage + pending`, `count` of them at
/// `storage + pending_count`, each `stride` bytes, `used` bytes filled
/// at `buffer + used`. Each record is `{u32 hash; u16 program; u8 size;
/// u8 0; data[size rounded up to 8]}`, with the size byte at
/// `record_size`. Kiln, docs/re/gameplay.md section 1.
#[derive(Debug, Clone, Copy)]
pub struct PendingEvents {
    pub pending: usize,
    pub pending_count: usize,
    pub stride: usize,
    pub used: usize,
    pub record_size: usize,
}

impl PendingEvents {
    /// Calls `f(hash, data)` for every event waiting in `storage`.
    ///
    /// # Safety
    /// `storage` must be a live world storage read on the sim thread
    /// between two steps, so nothing writes the buffers meanwhile.
    pub unsafe fn each(&self, storage: usize, mut f: impl FnMut(u32, *const u8, usize)) {
        // SAFETY: the caller hands a live storage; the offsets come
        // from the game's own DeliverEvents.
        unsafe {
            let buffers = *((storage + self.pending) as *const usize);
            let count = *((storage + self.pending_count) as *const u64) as usize;
            for i in 0..count {
                let buf = buffers + i * self.stride;
                let base = *(buf as *const usize);
                let used = *((buf + self.used) as *const u32) as usize;
                let mut off = 0;
                while off + 8 <= used {
                    let rec = base + off;
                    let hash = *(rec as *const u32);
                    let size = usize::from(*((rec + self.record_size) as *const u8));
                    f(hash, (rec + 8) as *const u8, size);
                    off += 8 + size.div_ceil(8) * 8;
                }
            }
        }
    }
}

/// The keys of one of the engine's hash maps at `map`: occupancy bits
/// pointer at +0x8, capacity at +0x10, u32 keys pointer at +0x28
/// (Kiln, docs/re/world.md "keen hash map"; the event map in
/// DeliverEvents has the same shape).
///
/// # Safety
/// `map` must be a live map read where nothing changes it meanwhile.
pub unsafe fn map_keys(map: usize) -> Vec<u32> {
    // SAFETY: the caller hands a live map with the layout above.
    unsafe {
        let bits = *((map + 0x8) as *const *const u64);
        let cap = *((map + 0x10) as *const u64) as usize;
        let keys = *((map + 0x28) as *const *const u32);
        (0..cap)
            .filter(|i| (*bits.add(i / 64) >> (i % 64)) & 1 == 1)
            .map(|i| *keys.add(i))
            .collect()
    }
}

/// A world position in the engine's 32.32 fixed point, in meters.
pub fn fixed_to_m(v: i64) -> f64 {
    v as f64 / 4_294_967_296.0
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
