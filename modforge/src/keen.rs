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

// ---- game parts of a mod's own ("programs") ----
//
// The engine runs a world as a table of programs, each with a
// descriptor naming what it reads, writes and sends. A mod adds its own
// the way Kiln does (github.com/frostdev-ops/kiln,
// native/services/world/programs.cpp, MIT; EMF
// docs/engine_parts/re_custom_programs.md): hook RegisterAllPrograms,
// the last registration call of a world's setup, call the original, then
// hand the game's own RegisterProgram one more descriptor. The engine
// then runs the program every step and gives it its own event outboxes.

/// Kiln's signatures (sigdb/symbols/server.d/world.json and
/// gameplay.json).
const REGISTER_ALL_PROGRAMS: &str =
    "40 53 48 83 EC 50 48 8B D9 48 8D 15 ?? ?? ?? ?? 48 8D 4C 24 40 41 B8 24";
const REGISTER_PROGRAM: &str = "48 89 5C 24 08 48 89 74 24 18 55 57 41 54 41 56 41 57 48 8D 6C 24 C9 48 81 EC A0 00 00 00 F6 82 {world/desc.flags:d32} 02";
const REGISTER_PROGRAM_COUNT: &str =
    "0F B7 86 {world/programs.count:d32} 41 BE {world/programs.max:d32} 66 41 3B C6";
const ITER_BEGIN: &str = "48 89 5C 24 10 55 56 57 41 54 41 55 41 56 41 57 48 83 EC 60 4C 8B 09 48 8B D9 48 8B FA 41 0F B6 81 {world/job.tpl_count:d32}";
const ITER_BEGIN_EVENTS_OUT: &str =
    "41 8B 81 {world/job.events_out_count:d32} 48 89 4C 24 48 48 89 1F 48 8D 04 C1";
const JOB_SENDER: &str = "48 8B CE E8 {gameplay/JobProgramId:rel32} 48 8B CE 0F B7 D8 E8 {gameplay/JobEventBuffer:rel32} 44 0F B7 CB BA B7 6F 76 A4 41 B8 38 00 00 00 48 8B C8 E8 {gameplay/EmitEvent:rel32}";

/// No entity query: one update per step (Kiln's KILN_PROGRAM_SYSTEM).
pub const PROGRAM_SYSTEM: u32 = 0x4;
/// Not in a client's prediction world (KILN_PROGRAM_HOST_ONLY).
pub const PROGRAM_HOST_ONLY: u32 = 0x10;

#[repr(C)]
#[derive(Clone, Copy)]
struct NameRef {
    s: *const u8,
    n: u64,
}

#[repr(C)]
#[derive(Clone, Copy)]
struct NameList {
    p: *const NameRef,
    n: u64,
}

const NO_NAMES: NameList = NameList {
    p: std::ptr::null(),
    n: 0,
};

/// The engine's program descriptor, 0x188 bytes (Kiln's EngineDesc,
/// native/services/world/world_internal.h).
#[repr(C)]
struct EngineDesc {
    name: NameRef,
    update: unsafe extern "system" fn(*mut ProgramCtx),
    /// tpl, tpl_opt, read, read_opt, write, write_opt, add, rem.
    lists: [NameList; 8],
    sys_read: NameList,
    sys_read_opt: u64,
    sys_write: NameList,
    sys_write_opt: u64,
    sys_write_parallel: u64,
    /// other_tpl, other_read, other_write, other_write_unser.
    other: [NameList; 4],
    /// with, without, any_of, all_write, all_read.
    filters: [NameList; 5],
    events_in: NameList,
    events_out: NameList,
    flags: u32,
    interval: u32,
}
const _: () = assert!(std::mem::size_of::<EngineDesc>() == 0x188);

/// What the engine hands a program's update: its job, and how many
/// entities it has iterated (a SYSTEM program leaves it 0).
#[repr(C)]
pub struct ProgramCtx {
    pub job: *mut u8,
    pub index: u32,
    pad: u32,
}

/// A mod's own program: a SYSTEM program that sends `events_out`
/// (short names, `LootInteractionEvent`).
pub struct ProgramDef {
    pub name: &'static str,
    pub events_out: &'static [&'static str],
    pub flags: u32,
    pub update: unsafe extern "system" fn(*mut ProgramCtx),
}

type RegisterAllFn = unsafe extern "system" fn(usize);
type RegisterProgramFn = unsafe extern "system" fn(usize, *const EngineDesc, bool) -> bool;
type IterBeginFn = unsafe extern "system" fn(*mut ProgramCtx, *mut u64, u32);
type JobProgramIdFn = unsafe extern "system" fn(usize) -> u16;
type JobEventBufferFn = unsafe extern "system" fn(usize) -> usize;
type EmitFn = unsafe extern "system" fn(usize, u32, u32, u16) -> *mut u8;

struct Programs {
    hook: crate::hook::Hook<RegisterAllFn>,
    register: RegisterProgramFn,
    count: usize,
    events_out_count: usize,
    iter_begin: IterBeginFn,
    job_program: JobProgramIdFn,
    job_buffer: JobEventBufferFn,
    emit: EmitFn,
    /// Leaked descriptors (the engine keeps pointers into them), as
    /// addresses, with each one's events_out count.
    descs: Vec<(usize, &'static str, usize)>,
    wants: fn(usize) -> bool,
}

static PROGRAMS: OnceLock<Programs> = OnceLock::new();

fn leak_name(s: &str) -> NameRef {
    let b: &'static [u8] = Box::leak(s.as_bytes().to_vec().into_boxed_slice());
    NameRef {
        s: b.as_ptr(),
        n: b.len() as u64,
    }
}

unsafe extern "system" fn on_register_all(world: usize) {
    let Some(p) = PROGRAMS.get() else { return };
    let _ = crate::call_original!(p.hook, world);
    if !(p.wants)(world) {
        return;
    }
    for (desc, name, _) in &p.descs {
        let r = crate::seh::guard(|| {
            // SAFETY: the game's RegisterProgram(world, desc, false)
            // inside the world's setup, as RegisterAllPrograms calls it;
            // the descriptor lives for the process.
            unsafe {
                let count = (world + p.count) as *const u16;
                let before = *count;
                let ok = (p.register)(world, *desc as *const EngineDesc, false);
                (ok, before, *count)
            }
        });
        match r {
            Ok((true, before, after)) if after == before + 1 => {
                crate::log!("keen: program {name} registered as #{after} in world {world:#x}")
            }
            Ok((ok, before, after)) => crate::log!(
                "keen: program {name} refused by the game (ok {ok}, count {before} -> {after})"
            ),
            Err(e) => crate::log!("keen: RegisterProgram for {name} faulted: {e:?}"),
        }
    }
}

/// Adds `defs` to every world whose setup `wants` (given the world)
/// accepts, from the next world setup on: a mod loaded after a world
/// was set up gets its programs in the next one (load the world again).
pub fn add_programs(defs: Vec<ProgramDef>, wants: fn(usize) -> bool) -> Result<(), String> {
    let (register_all, _) = find_in_exe(REGISTER_ALL_PROGRAMS)?;
    let (register, _) = find_in_exe(REGISTER_PROGRAM)?;
    let (_, v) = find_in(REGISTER_PROGRAM_COUNT, Some((register, 1024)))?;
    let count = hole(&v, "world/programs.count")?;
    let (iter_begin, _) = find_in_exe(ITER_BEGIN)?;
    let (_, v) = find_in(ITER_BEGIN_EVENTS_OUT, Some((iter_begin, 256)))?;
    let events_out_count = hole(&v, "world/job.events_out_count")?;
    let (_, v) = find_in_exe(JOB_SENDER)?;
    let job_program = hole(&v, "gameplay/JobProgramId")?;
    let job_buffer = hole(&v, "gameplay/JobEventBuffer")?;
    let emit = hole(&v, "gameplay/EmitEvent")?;
    let descs = defs
        .iter()
        .map(|d| {
            let names: Vec<NameRef> = d.events_out.iter().map(|n| leak_name(n)).collect();
            let names: &'static [NameRef] = Box::leak(names.into_boxed_slice());
            let desc = Box::leak(Box::new(EngineDesc {
                name: leak_name(d.name),
                update: d.update,
                lists: [NO_NAMES; 8],
                sys_read: NO_NAMES,
                sys_read_opt: 0,
                sys_write: NO_NAMES,
                sys_write_opt: 0,
                sys_write_parallel: 0,
                other: [NO_NAMES; 4],
                filters: [NO_NAMES; 5],
                events_in: NO_NAMES,
                events_out: NameList {
                    p: names.as_ptr(),
                    n: names.len() as u64,
                },
                flags: d.flags,
                interval: 1, // 0 divides by zero in the stage scheduler (Kiln)
            }));
            (
                desc as *const EngineDesc as usize,
                d.name,
                d.events_out.len(),
            )
        })
        .collect();
    // SAFETY: REGISTER_ALL_PROGRAMS matches the entry of the game's
    // RegisterAllPrograms(world), a normal x64 function; the others are
    // the entries their signatures name, with the ABI Kiln documents.
    let programs = unsafe {
        Programs {
            hook: crate::hook::Hook::<RegisterAllFn>::install(
                "RegisterAllPrograms",
                register_all,
                on_register_all,
            )
            .map_err(|e| format!("{e:#}"))?,
            register: std::mem::transmute::<usize, RegisterProgramFn>(register),
            count,
            events_out_count,
            iter_begin: std::mem::transmute::<usize, IterBeginFn>(iter_begin),
            job_program: std::mem::transmute::<usize, JobProgramIdFn>(job_program),
            job_buffer: std::mem::transmute::<usize, JobEventBufferFn>(job_buffer),
            emit: std::mem::transmute::<usize, EmitFn>(emit),
            descs,
            wants,
        }
    };
    crate::log!(
        "keen: RegisterAllPrograms hooked at {register_all:#x}; programs {:?} wait for the next world setup",
        defs.iter().map(|d| d.name).collect::<Vec<_>>()
    );
    PROGRAMS
        .set(programs)
        .map_err(|_| "programs already added".to_string())?;
    crate::shutdown::SHUTDOWN_REGISTRY
        .record("keen", "unhook RegisterAllPrograms".into(), 0, || {
            if let Some(p) = PROGRAMS.get() {
                // SAFETY: disabling the detour this module enabled.
                let _ = unsafe { p.hook.detour().disable() };
            }
        })
        .keep();
    Ok(())
}

fn hole(values: &[(String, u64)], name: &str) -> Result<usize, String> {
    values
        .iter()
        .find(|(n, _)| n == name)
        .map(|(_, v)| *v as usize)
        .ok_or_else(|| format!("no {name}"))
}

/// A program's outboxes for this step, one per name in its
/// `events_out`, in that order (Kiln lays event-out slots out in list
/// order). None when the engine's job does not have `expected` of them.
///
/// # Safety
/// Inside the program's update, with the ctx the engine passed.
pub unsafe fn outboxes(ctx: *mut ProgramCtx, expected: usize) -> Option<Outboxes> {
    let p = PROGRAMS.get()?;
    // SAFETY: the engine's ctx for this update; its job is live.
    unsafe {
        let job = (*ctx).job as usize;
        if *((job + p.events_out_count) as *const u32) as usize != expected {
            return None;
        }
        let mut iter = vec![0u64; 1 + expected];
        (p.iter_begin)(ctx, iter.as_mut_ptr(), (iter.len() * 8) as u32);
        let storage = *(job as *const usize);
        Some(Outboxes {
            senders: iter[1..].iter().map(|s| *s as usize).collect(),
            storage,
        })
    }
}

/// This step's outboxes of a program, from [`outboxes`].
pub struct Outboxes {
    senders: Vec<usize>,
    /// The world storage the program runs in.
    pub storage: usize,
}

impl Outboxes {
    /// A zeroed event of `hash` and `size` in outbox `i`, to fill in;
    /// null when the outbox is full.
    ///
    /// # Safety
    /// Inside the update that produced these outboxes.
    pub unsafe fn emit(&self, i: usize, hash: u32, size: u32) -> *mut u8 {
        let Some(p) = PROGRAMS.get() else {
            return std::ptr::null_mut();
        };
        let job = self.senders[i];
        // SAFETY: the game's own sequence for sending an event from a
        // job (JOB_SENDER): its program id, its buffer, EmitEvent.
        unsafe {
            let program = (p.job_program)(job);
            let buf = (p.job_buffer)(job);
            (p.emit)(buf, hash, size, program)
        }
    }
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
