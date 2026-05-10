//! Cheat-Engine-style memory scanner. In-process, so no
//! `ReadProcessMemory` dance — we walk our own committed
//! VirtualAlloc regions and match value patterns directly.
//!
//! Surface (all exposed as ops on the embedding mod's `/debug`):
//!
//! - `scan_memory { type, value, regions? }` → first scan; opens
//!   a session and returns the survivor address list.
//! - `scan_rescan { session_id, mode, value? }` → narrows the
//!   session by re-reading current values and applying one of
//!   `exact`, `changed`, `unchanged`, `decreased`, `increased`,
//!   `decreased_by` (with `delta`), `increased_by` (with `delta`).
//! - `scan_session { session_id, max?, offset? }` → paginate
//!   over the current survivor set.
//! - `scan_close { session_id }` → drop the session state.
//! - `freeze { addr, type, value, hz? }` → spawn a writer thread
//!   that rewrites `value` at `addr` every `1/hz` seconds.
//! - `unfreeze { addr }` / `freeze_list`.
//!
//! Value types: `u8 i8 u16 i16 u32 i32 u64 i64 f32 f64`. Step
//! size = type's natural alignment. For exotic types (FName,
//! UTF-16 strings, byte sequences) you'd extend `Value` later;
//! the primitive set handles ~95% of game-state finds.

use std::collections::HashMap;
use std::sync::atomic::{AtomicBool, AtomicU64, Ordering};
use std::sync::{Arc, OnceLock};
use std::thread;
use std::time::Duration;

use parking_lot::Mutex;

use serde_json::{Value as Json, json};

use crate::args::{arg_str, arg_u64};

// ---- Value type + parsing -------------------------------------------------

#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash)]
pub enum Ty {
    U8,
    I8,
    U16,
    I16,
    U32,
    I32,
    U64,
    I64,
    F32,
    F64,
}

impl Ty {
    fn from_str(s: &str) -> Result<Self, String> {
        Ok(match s {
            "u8" => Ty::U8,
            "i8" => Ty::I8,
            "u16" => Ty::U16,
            "i16" => Ty::I16,
            "u32" => Ty::U32,
            "i32" => Ty::I32,
            "u64" => Ty::U64,
            "i64" => Ty::I64,
            "f32" => Ty::F32,
            "f64" => Ty::F64,
            other => return Err(format!("unknown value type '{other}'")),
        })
    }
    fn size(self) -> usize {
        match self {
            Ty::U8 | Ty::I8 => 1,
            Ty::U16 | Ty::I16 => 2,
            Ty::U32 | Ty::I32 | Ty::F32 => 4,
            Ty::U64 | Ty::I64 | Ty::F64 => 8,
        }
    }
}

/// In-memory value. f32/f64 stored as bits so equality works
/// the way scan callers expect (NaN matches NaN; -0 != +0).
#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash)]
enum Val {
    U64Bits(u64, Ty),
}

impl Val {
    fn from_json(v: &Json, ty: Ty) -> Result<Self, String> {
        let bits = match ty {
            Ty::U8 => v.as_u64().ok_or("expected u8")?.try_into().map(|x: u8| x as u64).map_err(|_| "u8 out of range")?,
            Ty::I8 => v.as_i64().ok_or("expected i8")?.try_into().map(|x: i8| (x as u8) as u64).map_err(|_| "i8 out of range")?,
            Ty::U16 => v.as_u64().ok_or("expected u16")?.try_into().map(|x: u16| x as u64).map_err(|_| "u16 out of range")?,
            Ty::I16 => v.as_i64().ok_or("expected i16")?.try_into().map(|x: i16| (x as u16) as u64).map_err(|_| "i16 out of range")?,
            Ty::U32 => v.as_u64().ok_or("expected u32")?.try_into().map(|x: u32| x as u64).map_err(|_| "u32 out of range")?,
            Ty::I32 => v.as_i64().ok_or("expected i32")?.try_into().map(|x: i32| (x as u32) as u64).map_err(|_| "i32 out of range")?,
            Ty::U64 => v.as_u64().ok_or("expected u64")?,
            Ty::I64 => v.as_i64().ok_or("expected i64")? as u64,
            Ty::F32 => (v.as_f64().ok_or("expected f32")? as f32).to_bits() as u64,
            Ty::F64 => v.as_f64().ok_or("expected f64")?.to_bits(),
        };
        Ok(Val::U64Bits(bits, ty))
    }
    fn bytes(self) -> Vec<u8> {
        let Val::U64Bits(bits, ty) = self;
        match ty {
            Ty::U8 | Ty::I8 => vec![bits as u8],
            Ty::U16 | Ty::I16 => (bits as u16).to_le_bytes().to_vec(),
            Ty::U32 | Ty::I32 | Ty::F32 => (bits as u32).to_le_bytes().to_vec(),
            Ty::U64 | Ty::I64 | Ty::F64 => bits.to_le_bytes().to_vec(),
        }
    }
}

/// Read a `Ty`-sized value at `ptr` as a u64 of bits.
unsafe fn read_bits(ptr: *const u8, ty: Ty) -> u64 {
    unsafe {
        match ty {
            Ty::U8 | Ty::I8 => (ptr.read_unaligned()) as u64,
            Ty::U16 | Ty::I16 => (ptr as *const u16).read_unaligned() as u64,
            Ty::U32 | Ty::I32 | Ty::F32 => (ptr as *const u32).read_unaligned() as u64,
            Ty::U64 | Ty::I64 | Ty::F64 => (ptr as *const u64).read_unaligned(),
        }
    }
}

/// Sign-extending or float-aware comparator helpers used by the
/// `decreased / increased` rescan modes.
fn cmp(ty: Ty, a: u64, b: u64) -> std::cmp::Ordering {
    use std::cmp::Ordering::*;
    match ty {
        Ty::U8 => (a as u8).cmp(&(b as u8)),
        Ty::I8 => (a as i8).cmp(&(b as i8)),
        Ty::U16 => (a as u16).cmp(&(b as u16)),
        Ty::I16 => (a as i16).cmp(&(b as i16)),
        Ty::U32 => (a as u32).cmp(&(b as u32)),
        Ty::I32 => (a as i32).cmp(&(b as i32)),
        Ty::U64 => a.cmp(&b),
        Ty::I64 => (a as i64).cmp(&(b as i64)),
        Ty::F32 => f32::from_bits(a as u32)
            .partial_cmp(&f32::from_bits(b as u32))
            .unwrap_or(Equal),
        Ty::F64 => f64::from_bits(a)
            .partial_cmp(&f64::from_bits(b))
            .unwrap_or(Equal),
    }
}

fn signed_diff(ty: Ty, a: u64, b: u64) -> i64 {
    // Returns a - b for the type, sign-aware.
    match ty {
        Ty::U8 => (a as u8 as i64) - (b as u8 as i64),
        Ty::I8 => (a as i8 as i64) - (b as i8 as i64),
        Ty::U16 => (a as u16 as i64) - (b as u16 as i64),
        Ty::I16 => (a as i16 as i64) - (b as i16 as i64),
        Ty::U32 => (a as u32 as i64) - (b as u32 as i64),
        Ty::I32 => (a as i32 as i64) - (b as i32 as i64),
        Ty::U64 => (a as i64).wrapping_sub(b as i64),
        Ty::I64 => (a as i64).wrapping_sub(b as i64),
        Ty::F32 => (f32::from_bits(a as u32) - f32::from_bits(b as u32)) as i64,
        Ty::F64 => (f64::from_bits(a) - f64::from_bits(b)) as i64,
    }
}

// ---- Region walker (private RW pages) ------------------------------------

#[derive(Clone, Copy)]
struct Region {
    base: usize,
    size: usize,
}

/// Walk every committed private RW region in this process. Skip
/// image / mapped / read-only / executable. We're explicitly
/// chasing dynamic state (UObjects on the heap, allocator
/// buffers, etc.).
fn iter_private_rw_regions() -> Vec<Region> {
    use windows_sys::Win32::System::Memory::{
        MEM_COMMIT, MEM_PRIVATE, MEMORY_BASIC_INFORMATION, PAGE_READWRITE, PAGE_WRITECOPY,
        VirtualQuery,
    };
    let mut out = Vec::new();
    let mut addr: usize = 0;
    let mut info: MEMORY_BASIC_INFORMATION = unsafe { std::mem::zeroed() };
    let info_size = std::mem::size_of::<MEMORY_BASIC_INFORMATION>();
    loop {
        let written = unsafe { VirtualQuery(addr as *const _, &mut info, info_size) };
        if written == 0 {
            break;
        }
        let next = info.BaseAddress as usize + info.RegionSize;
        if next <= addr {
            break;
        }
        if info.State == MEM_COMMIT
            && info.Type == MEM_PRIVATE
            && (info.Protect & 0xFF == PAGE_READWRITE
                || info.Protect & 0xFF == PAGE_WRITECOPY)
        {
            out.push(Region {
                base: info.BaseAddress as usize,
                size: info.RegionSize,
            });
        }
        addr = next;
    }
    out
}

// ---- Session state --------------------------------------------------------

struct Session {
    ty: Ty,
    addresses: Vec<usize>,
}

static SESSIONS: OnceLock<Mutex<HashMap<u64, Session>>> = OnceLock::new();
static NEXT_SESSION_ID: AtomicU64 = AtomicU64::new(1);

fn sessions() -> &'static Mutex<HashMap<u64, Session>> {
    SESSIONS.get_or_init(|| Mutex::new(HashMap::new()))
}

// ---- Freezes --------------------------------------------------------------

/// Where a freeze's target address came from. Selector-backed
/// freezes can re-resolve when the cached address goes stale (UE
/// recycles allocations, the source object moves, etc.). Raw-addr
/// freezes have no recovery path -- once the page is gone, the
/// freeze just stops.
#[derive(Clone)]
enum FreezeSource {
    /// `addr:0x...` / `class:Foo` / `singleton:Bar` + byte offset.
    /// Re-resolved on validation miss.
    Selector { selector: String, offset: usize },
    /// User passed a raw `addr:0x...` directly. Stops on staleness.
    RawAddr,
}

struct FreezeJob {
    stop: Arc<AtomicBool>,
    ty: Ty,
    bytes: Vec<u8>,
    hz: u32,
    source: FreezeSource,
}

static FREEZES: OnceLock<Mutex<HashMap<usize, FreezeJob>>> = OnceLock::new();

fn freezes() -> &'static Mutex<HashMap<usize, FreezeJob>> {
    FREEZES.get_or_init(|| Mutex::new(HashMap::new()))
}

/// True if the address range [addr, addr+len) lies entirely within
/// a single committed, writable, private region. Cheap (one
/// `VirtualQuery`); call before every freeze write to avoid
/// faulting on a guard page when the source allocation is freed.
fn is_writable(addr: usize, len: usize) -> bool {
    use windows_sys::Win32::System::Memory::{
        MEM_COMMIT, MEMORY_BASIC_INFORMATION, PAGE_READWRITE, PAGE_WRITECOPY, VirtualQuery,
    };
    if addr == 0 {
        return false;
    }
    let mut info: MEMORY_BASIC_INFORMATION = unsafe { std::mem::zeroed() };
    let n = unsafe {
        VirtualQuery(
            addr as *const _,
            &mut info,
            std::mem::size_of::<MEMORY_BASIC_INFORMATION>(),
        )
    };
    if n == 0 {
        return false;
    }
    if info.State != MEM_COMMIT {
        return false;
    }
    let p = info.Protect & 0xFF;
    if p != PAGE_READWRITE && p != PAGE_WRITECOPY {
        return false;
    }
    // Reject writes that span the end of the queried region.
    let region_end = info.BaseAddress as usize + info.RegionSize;
    addr.saturating_add(len) <= region_end
}

// ---- Ops ------------------------------------------------------------------

pub fn scan_memory(args: &Json) -> Result<Json, String> {
    let ty = Ty::from_str(arg_str(args, "type")?)?;
    let v = args.get("value").ok_or("missing arg 'value'")?;
    let target = Val::from_json(v, ty)?;
    let Val::U64Bits(target_bits, _) = target;

    let regions = iter_private_rw_regions();
    let step = ty.size();
    let mut survivors = Vec::new();
    for r in &regions {
        if r.size < step {
            continue;
        }
        unsafe {
            let base = r.base as *const u8;
            // Step at type alignment to bound work; misaligned
            // values are rare for game state. Add a "step": 1
            // arg later if needed.
            let mut off = 0usize;
            while off + step <= r.size {
                let bits = read_bits(base.add(off), ty);
                if bits == target_bits {
                    survivors.push(r.base + off);
                }
                off += step;
            }
        }
    }

    let id = NEXT_SESSION_ID.fetch_add(1, Ordering::Relaxed);
    sessions().lock().insert(
        id,
        Session {
            ty,
            addresses: survivors.clone(),
        },
    );
    Ok(json!({
        "session_id": id,
        "type": format!("{ty:?}").to_lowercase(),
        "matches": survivors.len(),
        "regions_scanned": regions.len(),
        "sample": survivors
            .iter()
            .take(20)
            .map(|a| format!("0x{a:X}"))
            .collect::<Vec<_>>(),
    }))
}

pub fn scan_rescan(args: &Json) -> Result<Json, String> {
    let id = arg_u64(args, "session_id", None)?;
    let mode = arg_str(args, "mode")?;
    let mut s = sessions().lock();
    let sess = s.get_mut(&id).ok_or_else(|| format!("session {id} not found"))?;
    let ty = sess.ty;

    // Read current value at every survivor.
    let cur: Vec<u64> = sess
        .addresses
        .iter()
        .map(|&a| unsafe { read_bits(a as *const u8, ty) })
        .collect();

    let new: Vec<usize> = match mode {
        "exact" => {
            let v = args.get("value").ok_or("'exact' needs 'value'")?;
            let Val::U64Bits(want, _) = Val::from_json(v, ty)?;
            sess.addresses
                .iter()
                .zip(&cur)
                .filter(|&(_, c)| *c == want)
                .map(|(a, _)| *a)
                .collect()
        }
        "unchanged" | "changed" | "decreased" | "increased" => {
            // Need previous value for these. We don't store
            // per-survivor previous; instead, accept this rescan
            // contract: caller passes "value" = the previous
            // reference (e.g. the value that was true before the
            // in-game action). Cheat-Engine has true diff-mode
            // that stashes per-addr prev internally; future work.
            let v = args.get("value").ok_or(
                format!("'{mode}' needs 'value' = the previous reference value"),
            )?;
            let Val::U64Bits(prev, _) = Val::from_json(v, ty)?;
            use std::cmp::Ordering as O;
            sess.addresses
                .iter()
                .zip(&cur)
                .filter(|&(_, c)| match mode {
                    "unchanged" => *c == prev,
                    "changed" => *c != prev,
                    "decreased" => cmp(ty, *c, prev) == O::Less,
                    "increased" => cmp(ty, *c, prev) == O::Greater,
                    _ => unreachable!(),
                })
                .map(|(a, _)| *a)
                .collect()
        }
        "decreased_by" | "increased_by" => {
            let v = args.get("value").ok_or(
                format!("'{mode}' needs 'value' = the previous reference value"),
            )?;
            let Val::U64Bits(prev, _) = Val::from_json(v, ty)?;
            let delta_v = args.get("delta").ok_or(format!("'{mode}' needs 'delta'"))?;
            let Val::U64Bits(delta_bits, _) = Val::from_json(delta_v, ty)?;
            let want_diff = match mode {
                "decreased_by" => -(signed_diff(ty, delta_bits, 0).abs()),
                "increased_by" => signed_diff(ty, delta_bits, 0).abs(),
                _ => unreachable!(),
            };
            sess.addresses
                .iter()
                .zip(&cur)
                .filter(|&(_, c)| signed_diff(ty, *c, prev) == want_diff)
                .map(|(a, _)| *a)
                .collect()
        }
        other => return Err(format!("unknown rescan mode '{other}'")),
    };

    sess.addresses = new;
    Ok(json!({
        "session_id": id,
        "matches": sess.addresses.len(),
        "sample": sess.addresses.iter().take(20).map(|a| format!("0x{a:X}")).collect::<Vec<_>>(),
    }))
}

pub fn scan_session(args: &Json) -> Result<Json, String> {
    let id = arg_u64(args, "session_id", None)?;
    let max = arg_u64(args, "max", Some(200))? as usize;
    let offset = arg_u64(args, "offset", Some(0))? as usize;
    let s = sessions().lock();
    let sess = s.get(&id).ok_or_else(|| format!("session {id} not found"))?;
    let total = sess.addresses.len();
    let end = (offset + max).min(total);
    let slice: Vec<String> = sess.addresses[offset.min(total)..end]
        .iter()
        .map(|a| format!("0x{a:X}"))
        .collect();
    Ok(json!({
        "session_id": id,
        "type": format!("{:?}", sess.ty).to_lowercase(),
        "total": total,
        "offset": offset,
        "returned": slice.len(),
        "addresses": slice,
    }))
}

pub fn scan_close(args: &Json) -> Result<Json, String> {
    let id = arg_u64(args, "session_id", None)?;
    let removed = sessions().lock().remove(&id).is_some();
    Ok(json!({"session_id": id, "removed": removed}))
}

// ---- Freeze ---------------------------------------------------------------

pub fn freeze(args: &Json) -> Result<Json, String> {
    let ty = Ty::from_str(arg_str(args, "type")?)?;
    let v = args.get("value").ok_or("missing arg 'value'")?;
    let bytes = Val::from_json(v, ty)?.bytes();
    let hz = arg_u64(args, "hz", Some(30))? as u32;
    let hz = hz.clamp(1, 1000);

    // Two arg shapes:
    //   { selector, offset?, type, value }  -- preferred. The
    //     writer re-resolves on staleness (address-recycling safe).
    //   { addr, type, value }               -- legacy. Address is
    //     opaque; the writer stops when the page is unmapped or
    //     loses RW protection.
    let (addr, source) = match args.get("selector").and_then(Json::as_str) {
        Some(sel) => {
            let offset = arg_u64(args, "offset", Some(0))? as usize;
            let addr = resolve_selector_addr(sel, offset)?;
            (
                addr,
                FreezeSource::Selector {
                    selector: sel.to_string(),
                    offset,
                },
            )
        }
        None => {
            let addr_str = arg_str(args, "addr")?;
            (parse_addr(addr_str)?, FreezeSource::RawAddr)
        }
    };

    if !is_writable(addr, bytes.len()) {
        return Err(format!(
            "freeze: address 0x{addr:X} is not committed RW for {} bytes",
            bytes.len()
        ));
    }

    // Replace existing freeze on this addr if any.
    if let Some(old) = freezes().lock().remove(&addr) {
        old.stop.store(true, Ordering::Release);
    }

    let stop = Arc::new(AtomicBool::new(false));
    let source_t = source.clone();
    spawn_freeze_writer(addr, bytes.clone(), hz, stop.clone(), source_t)?;

    freezes().lock().insert(
        addr,
        FreezeJob {
            stop,
            ty,
            bytes,
            hz,
            source,
        },
    );
    Ok(json!({"addr": format!("0x{addr:X}"), "hz": hz, "frozen": true}))
}

fn resolve_selector_addr(selector: &str, offset: usize) -> Result<usize, String> {
    use crate::ue::UObject;
    let resolved = crate::selector::resolve_generic(selector)
        .ok_or_else(|| format!("freeze: selector '{selector}' not recognized"))?;
    let obj = resolved.map_err(|e| format!("freeze: resolve '{selector}': {e}"))?;
    Ok((obj as *const UObject as usize).wrapping_add(offset))
}

/// Spawn the writer thread. Validates page protection on each
/// tick; on miss, attempts to re-resolve the selector (if any) to
/// recover from UE recycling the underlying allocation. Bails out
/// after `MAX_CONSECUTIVE_FAILURES` failed validations so a
/// permanently-stale freeze can't busy-loop forever.
fn spawn_freeze_writer(
    initial_addr: usize,
    bytes: Vec<u8>,
    hz: u32,
    stop: Arc<AtomicBool>,
    source: FreezeSource,
) -> Result<(), String> {
    const MAX_CONSECUTIVE_FAILURES: u32 = 30;
    let interval = Duration::from_millis((1000 / hz.max(1)) as u64);
    thread::Builder::new()
        .name(format!("ueforge-freeze-{initial_addr:X}"))
        .spawn(move || {
            let mut addr = initial_addr;
            let mut failures: u32 = 0;
            while !stop.load(Ordering::Acquire) {
                if !is_writable(addr, bytes.len()) {
                    // Try to re-resolve from a selector. Raw-addr
                    // freezes have no recovery path.
                    let recovered = match &source {
                        FreezeSource::Selector { selector, offset } => {
                            resolve_selector_addr(selector, *offset)
                                .ok()
                                .filter(|a| is_writable(*a, bytes.len()))
                        }
                        FreezeSource::RawAddr => None,
                    };
                    match recovered {
                        Some(new_addr) => {
                            crate::log::log(format_args!(
                                "ueforge freeze: re-resolved 0x{addr:X} -> 0x{new_addr:X}"
                            ));
                            addr = new_addr;
                            failures = 0;
                        }
                        None => {
                            failures = failures.saturating_add(1);
                            if failures >= MAX_CONSECUTIVE_FAILURES {
                                crate::log::log(format_args!(
                                    "ueforge freeze: 0x{initial_addr:X} stale for \
                                     {failures} ticks; stopping"
                                ));
                                return;
                            }
                            thread::sleep(interval);
                            continue;
                        }
                    }
                }
                unsafe {
                    let dst = addr as *mut u8;
                    std::ptr::copy_nonoverlapping(bytes.as_ptr(), dst, bytes.len());
                }
                failures = 0;
                thread::sleep(interval);
            }
        })
        .map_err(|e| format!("spawn failed: {e}"))?;
    Ok(())
}

pub fn unfreeze(args: &Json) -> Result<Json, String> {
    let addr_str = arg_str(args, "addr")?;
    let addr = parse_addr(addr_str)?;
    let removed = match freezes().lock().remove(&addr) {
        Some(j) => {
            j.stop.store(true, Ordering::Release);
            true
        }
        None => false,
    };
    Ok(json!({"addr": format!("0x{addr:X}"), "removed": removed}))
}

pub fn freeze_list(_args: &Json) -> Result<Json, String> {
    let f = freezes().lock();
    let entries: Vec<Json> = f
        .iter()
        .map(|(addr, job)| {
            let mut row = json!({
                "addr": format!("0x{addr:X}"),
                "type": format!("{:?}", job.ty).to_lowercase(),
                "bytes_hex": crate::hex::encode(&job.bytes),
                "hz": job.hz,
            });
            match &job.source {
                FreezeSource::Selector { selector, offset } => {
                    row["selector"] = json!(selector);
                    row["offset"] = json!(format!("0x{offset:X}"));
                }
                FreezeSource::RawAddr => {
                    row["selector"] = json!(null);
                }
            }
            row
        })
        .collect();
    Ok(json!({"count": entries.len(), "freezes": entries}))
}

fn parse_addr(s: &str) -> Result<usize, String> {
    let hex = s
        .strip_prefix("0x")
        .or_else(|| s.strip_prefix("0X"))
        .unwrap_or(s);
    usize::from_str_radix(hex, 16).map_err(|e| format!("bad address '{s}': {e}"))
}
