//! D5 visuals trampoline: post-hook on `FUN_14009f680`.
//!
//! Strategy locked in [`horsey-mod/docs/HOOKING-STRATEGY.md`](../../docs/HOOKING-STRATEGY.md)
//! as S2 (post-hook trampoline via `retour::GenericDetour`).
//!
//! Vanilla `FUN_14009f680(buf, ctx)` is the gene-effect engine: it
//! reads a horse's diploid alleles for genes [0..239] and populates
//! 258 unique slots in `buf` (a 353-float stack-allocated array on
//! the caller). The caller then runs `FUN_1400ab3d0(horse, buf)`
//! which transcribes 61 of those slots into the persistent horse
//! struct, which the renderer reads.
//!
//! Our handler runs AFTER the trampoline so `buf` is already
//! populated with vanilla's 258 slot writes. We then walk
//! `EXT_GENE_TABLE` for entries with a `RenderMapping`, evaluate
//! the diploid blend against `EXT_HORSE_GENOMES`, and apply the
//! result to `buf[render.slot]` per `RenderMode` (add / mul / set).
//!
//! Horse identity: `ctx` is `horse + 0x2b8`. We back-compute the
//! horse pointer (`ctx - 0x2b8`) and use it as the session-local
//! `horse_id`. Save / load gets a stable id later (D4.4).
//!
//! Handler discipline: same lock-free, atomics-only pattern as
//! `patches/ext_genes.rs`. See `docs/DEBUGGING.md` §4b.

use crate::genes;
use crate::targets::{self, fn_addr};
use retour::GenericDetour;
use std::ffi::c_void;
use std::sync::atomic::{AtomicPtr, AtomicU64, Ordering};

/// Vanilla offset from `horse` to the ctx pointer the engine takes.
/// `FUN_14009f680(buf, horse + 0x2b8)`.
const HORSE_CTX_OFFSET: usize = 0x2b8;

/// Vanilla buffer length (floats). The caller stack-allocates
/// `local_buf[353]` in every site we surveyed.
const BUF_LEN_FLOATS: usize = 353;

/// `FUN_14009f680` signature. Two pointer args, void return.
type GeneEffectEngineFn = unsafe extern "system" fn(*mut f32, *mut c_void);

/// Lock-free detour storage; same pattern as DI-A.
static DETOUR: AtomicPtr<GenericDetour<GeneEffectEngineFn>> =
    AtomicPtr::new(std::ptr::null_mut());

static CALL_COUNT: AtomicU64 = AtomicU64::new(0);
static GENES_APPLIED_TOTAL: AtomicU64 = AtomicU64::new(0);

pub fn is_armed() -> bool {
    !DETOUR.load(Ordering::Acquire).is_null()
}

pub struct Stats {
    pub call_count: u64,
    pub genes_applied_total: u64,
}

pub fn stats() -> Stats {
    Stats {
        call_count: CALL_COUNT.load(Ordering::Relaxed),
        genes_applied_total: GENES_APPLIED_TOTAL.load(Ordering::Relaxed),
    }
}

fn reset_stats() {
    CALL_COUNT.store(0, Ordering::Relaxed);
    GENES_APPLIED_TOTAL.store(0, Ordering::Relaxed);
}

// ---------------------------------------------------------------------------
// Handler (post-hook). DISCIPLINE: atomics + indirect calls only.
// No format!, no log!, no parking_lot lock at handler entry. The
// `apply_render_to_buf` slow path takes RwLock reads. Those are
// only acquired AFTER the vanilla trampoline returns and only do
// non-blocking reads, which on parking_lot are TLS-light.
// ---------------------------------------------------------------------------

unsafe extern "system" fn engine_handler(buf: *mut f32, ctx: *mut c_void) {
    CALL_COUNT.fetch_add(1, Ordering::Relaxed);

    let p = DETOUR.load(Ordering::Acquire);
    if p.is_null() {
        return;
    }
    // SAFETY: pointer was published by arm() via Box::into_raw +
    // AtomicPtr::store(Release). Trampoline points at vanilla
    // FUN_14009f680.
    unsafe { (*p).call(buf, ctx) };

    if buf.is_null() || ctx.is_null() {
        return;
    }

    // Back-compute the horse pointer; use it as a session-local id.
    let horse_ptr = (ctx as usize).wrapping_sub(HORSE_CTX_OFFSET);
    let horse_id = horse_ptr as u64;

    // SAFETY: vanilla allocated `float[353]` and just wrote into it;
    // we modify the same backing storage with bounds-checked writes.
    let applied =
        unsafe { genes::apply_render_to_buf(buf, BUF_LEN_FLOATS, horse_id) };
    GENES_APPLIED_TOTAL.fetch_add(applied as u64, Ordering::Relaxed);
}

// ---------------------------------------------------------------------------
// Dryrun (read-only diagnostic)
// ---------------------------------------------------------------------------

#[derive(Debug, Clone)]
pub struct TargetReport {
    pub name: &'static str,
    pub rva: usize,
    pub runtime_addr: usize,
    pub prologue_bytes: [u8; 16],
}

pub fn dryrun() -> TargetReport {
    let rva = fn_addr::APPLY_GENE_TO_HORSE;
    let runtime_addr = targets::rebase(rva);
    let mut prologue = [0u8; 16];
    // SAFETY: function entry inside our running image; read-only.
    let view = unsafe { std::slice::from_raw_parts(runtime_addr as *const u8, 16) };
    prologue.copy_from_slice(view);
    TargetReport {
        name: "APPLY_GENE_TO_HORSE",
        rva,
        runtime_addr,
        prologue_bytes: prologue,
    }
}

// ---------------------------------------------------------------------------
// Arm / revert
// ---------------------------------------------------------------------------

pub fn arm() -> anyhow::Result<()> {
    if is_armed() {
        anyhow::bail!("render_trampoline already armed");
    }
    let runtime_addr = targets::rebase(fn_addr::APPLY_GENE_TO_HORSE);
    let handler_addr = engine_handler as *const () as usize;

    // Pre-arm prologue sanity check. See `docs/DEBUGGING.md` §5. The
    // May 2026 build has 0x14009f680 starting with
    // `8d a8 d8 fb ff ff` (`LEA EBP, [RAX-0x428]`), which is NOT a
    // Win64 function entry. Arming there crashed the game inside
    // vanilla at offset +13 with a -1 bad-addr. Refuse to arm until
    // the real entry is re-located in the current binary.
    // SAFETY: target address is in our loaded image; 16 bytes
    // available for read.
    let prologue = unsafe { std::slice::from_raw_parts(runtime_addr as *const u8, 6) };
    if prologue == [0x8d, 0xa8, 0xd8, 0xfb, 0xff, 0xff] {
        anyhow::bail!(
            "render_trampoline: ABORTED. Prologue at 0x{runtime_addr:x} starts \
             with `LEA EBP, [RAX-0x428]` which is mid-function, not a function \
             entry. Re-decompile to find the real APPLY_GENE_TO_HORSE entry \
             before re-enabling this op. See docs/DEBUGGING.md §5."
        );
    }

    modforge::log!(
        "render_trampoline: install APPLY_GENE_TO_HORSE target=0x{runtime_addr:x} \
         handler=0x{handler_addr:x}"
    );
    // SAFETY: address is the entry of FUN_14009f680; signature matches.
    let target: GeneEffectEngineFn = unsafe { std::mem::transmute(runtime_addr) };
    // SAFETY: signatures match.
    let detour = unsafe { GenericDetour::new(target, engine_handler) }
        .map_err(|e| anyhow::anyhow!("render_trampoline: GenericDetour::new failed: {e}"))?;
    // SAFETY: enable installs JMP + trampoline.
    unsafe { detour.enable() }
        .map_err(|e| anyhow::anyhow!("render_trampoline: enable failed: {e}"))?;
    let leaked: *mut GenericDetour<GeneEffectEngineFn> = Box::into_raw(Box::new(detour));
    DETOUR.store(leaked, Ordering::Release);
    reset_stats();
    modforge::log!(
        "render_trampoline: armed APPLY_GENE_TO_HORSE at 0x{runtime_addr:x}"
    );
    Ok(())
}

pub fn revert() {
    let p = DETOUR.swap(std::ptr::null_mut(), Ordering::AcqRel);
    if p.is_null() {
        return;
    }
    // SAFETY: p was published by arm() via Box::into_raw and we
    // just took sole ownership atomically.
    let det = unsafe { Box::from_raw(p) };
    // SAFETY: disable restores the prologue retour stashed at enable.
    let res = unsafe { det.disable() };
    match res {
        Ok(()) => modforge::log!("render_trampoline: reverted APPLY_GENE_TO_HORSE"),
        Err(e) => modforge::log!("render_trampoline: revert FAILED: {e}"),
    }
}
