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

use crate::genes;
use crate::targets::{self, fn_addr};
use parking_lot::Mutex;
use retour::GenericDetour;
use std::ffi::c_void;
use std::sync::atomic::{AtomicU64, Ordering};
use std::sync::OnceLock;

/// Vanilla offset from `horse` to the ctx pointer the engine takes.
/// `FUN_14009f680(buf, horse + 0x2b8)`.
const HORSE_CTX_OFFSET: usize = 0x2b8;

/// Vanilla buffer length (floats). The caller stack-allocates
/// `local_buf[353]` in every site we surveyed.
const BUF_LEN_FLOATS: usize = 353;

/// `FUN_14009f680` signature. Two pointer args, void return.
///
/// Decomp signature: `void FUN_14009f680(float *param_1, undefined8 *param_2)`
type GeneEffectEngineFn = unsafe extern "system" fn(*mut f32, *mut c_void);

fn detour_slot() -> &'static Mutex<Option<GenericDetour<GeneEffectEngineFn>>> {
    static T: OnceLock<Mutex<Option<GenericDetour<GeneEffectEngineFn>>>> = OnceLock::new();
    T.get_or_init(|| Mutex::new(None))
}

static CALL_COUNT: AtomicU64 = AtomicU64::new(0);
static GENES_APPLIED_TOTAL: AtomicU64 = AtomicU64::new(0);

pub fn is_armed() -> bool {
    detour_slot().lock().is_some()
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
// Handler (post-hook)
// ---------------------------------------------------------------------------

/// Post-hook handler. Runs vanilla first via the trampoline; then
/// walks our extended genes and applies their render mappings to
/// `buf`. The caller's downstream `FUN_1400ab3d0(horse, buf)` then
/// transcribes the modified buf into the horse struct.
///
/// SAFETY: signature must match the vanilla function. extern
/// "system" on x64 Windows is the win64 ABI. Vanilla writes 258
/// slots into `buf` (a `float[353]` allocation), so reading and
/// modifying any slot in [0..353) is safe.
unsafe extern "system" fn engine_handler(buf: *mut f32, ctx: *mut c_void) {
    CALL_COUNT.fetch_add(1, Ordering::Relaxed);

    // Run vanilla.
    {
        let g = detour_slot().lock();
        match g.as_ref() {
            // SAFETY: trampoline is the saved original FUN_14009f680.
            Some(d) => unsafe { d.call(buf, ctx) },
            // Shouldn't happen: enable() runs before we get here.
            None => return,
        }
    }

    if buf.is_null() || ctx.is_null() {
        return;
    }

    // Back-compute the horse pointer. ctx is `horse + 0x2b8`.
    let horse_ptr = (ctx as usize).wrapping_sub(HORSE_CTX_OFFSET);
    let horse_id = horse_ptr as u64;

    // SAFETY: vanilla allocated `float[353]` and just wrote into it;
    // we modify the same backing storage with bounds-checked writes.
    let applied = unsafe { genes::apply_render_to_buf(buf, BUF_LEN_FLOATS, horse_id) };
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
    {
        let g = detour_slot().lock();
        if g.is_some() {
            anyhow::bail!("render_trampoline already armed");
        }
    }

    let runtime_addr = targets::rebase(fn_addr::APPLY_GENE_TO_HORSE);
    // SAFETY: address is the entry of FUN_14009f680 in our image;
    // signature matches the vanilla prototype.
    let target: GeneEffectEngineFn = unsafe { std::mem::transmute(runtime_addr) };
    // SAFETY: signatures match.
    let detour = unsafe { GenericDetour::new(target, engine_handler) }
        .map_err(|e| anyhow::anyhow!("render_trampoline: GenericDetour::new failed: {e}"))?;
    // SAFETY: enable installs JMP + trampoline.
    unsafe { detour.enable() }
        .map_err(|e| anyhow::anyhow!("render_trampoline: enable failed: {e}"))?;
    *detour_slot().lock() = Some(detour);
    reset_stats();
    modforge::log!(
        "render_trampoline: armed APPLY_GENE_TO_HORSE at 0x{runtime_addr:x}"
    );
    Ok(())
}

pub fn revert() {
    let detour = detour_slot().lock().take();
    if let Some(d) = detour {
        // SAFETY: disable restores the prologue retour stashed at enable.
        let res = unsafe { d.disable() };
        match res {
            Ok(()) => modforge::log!("render_trampoline: reverted APPLY_GENE_TO_HORSE"),
            Err(e) => modforge::log!("render_trampoline: revert FAILED: {e}"),
        }
    }
}
