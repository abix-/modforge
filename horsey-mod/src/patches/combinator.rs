//! D3.4 breeding-combinator post-hook.
//!
//! Vanilla `FUN_1400a2d80(p_a_ctx, p_b_ctx, child_ctx)` performs
//! Mendelian recombination of two parents' 0x1e0-byte inline genomes
//! at `horse + 0x2b8` into the child's inline genome. See
//! [`horsey-mod/docs/GENE-CATALOG.md`](../../docs/GENE-CATALOG.md)
//! Part 1 Step 1 and `todo.md` D3.4 for the algorithm.
//!
//! Our handler runs AFTER the trampoline. We recover horse base
//! pointers from `ctx - 0x2b8` (the gene-state offset) and run our
//! own Mendelian combinator on the extended range via
//! `genes::combine_for_breeding`.
//!
//! Handler discipline: same lock-free, atomics-only pattern as
//! `ext_genes.rs` + `render_trampoline.rs`. See `docs/DEBUGGING.md`
//! §4b.

use crate::genes;
use crate::targets::{self, fn_addr};
use retour::GenericDetour;
use std::ffi::c_void;
use std::sync::atomic::{AtomicPtr, AtomicU64, Ordering};

/// Vanilla offset from `horse` to the inline genome ctx the
/// combinator takes. Mirror of `render_trampoline::HORSE_CTX_OFFSET`.
const HORSE_CTX_OFFSET: usize = 0x2b8;

/// `FUN_1400a2d80` signature: three `longlong` pointers, void return.
/// Decomp: `void FUN_1400a2d80(longlong param_1, longlong param_2,
///                              longlong param_3)`.
type CombinatorFn =
    unsafe extern "system" fn(*mut c_void, *mut c_void, *mut c_void);

static DETOUR: AtomicPtr<GenericDetour<CombinatorFn>> =
    AtomicPtr::new(std::ptr::null_mut());

static CALL_COUNT: AtomicU64 = AtomicU64::new(0);
static COMBINES_DONE: AtomicU64 = AtomicU64::new(0);

pub fn is_armed() -> bool {
    !DETOUR.load(Ordering::Acquire).is_null()
}

pub struct Stats {
    pub call_count: u64,
    pub combines_done: u64,
}

pub fn stats() -> Stats {
    Stats {
        call_count: CALL_COUNT.load(Ordering::Relaxed),
        combines_done: COMBINES_DONE.load(Ordering::Relaxed),
    }
}

fn reset_stats() {
    CALL_COUNT.store(0, Ordering::Relaxed);
    COMBINES_DONE.store(0, Ordering::Relaxed);
}

// ---------------------------------------------------------------------------
// Handler (post-hook). Atomics + indirect call + delegate to slow path.
// ---------------------------------------------------------------------------

unsafe extern "system" fn combinator_handler(
    p_a_ctx: *mut c_void,
    p_b_ctx: *mut c_void,
    child_ctx: *mut c_void,
) {
    CALL_COUNT.fetch_add(1, Ordering::Relaxed);

    let p = DETOUR.load(Ordering::Acquire);
    if p.is_null() {
        return;
    }
    // SAFETY: pointer published by arm() via Box::into_raw +
    // AtomicPtr::store(Release). Trampoline points at vanilla
    // FUN_1400a2d80.
    unsafe { (*p).call(p_a_ctx, p_b_ctx, child_ctx) };

    if p_a_ctx.is_null() || p_b_ctx.is_null() || child_ctx.is_null() {
        return;
    }

    // Recover horse base pointers. Vanilla call site:
    // FUN_1400a2d80(parent_a + 0x2b8, parent_b + 0x2b8, child + 0x2b8)
    let pa_id = (p_a_ctx as usize).wrapping_sub(HORSE_CTX_OFFSET) as u64;
    let pb_id = (p_b_ctx as usize).wrapping_sub(HORSE_CTX_OFFSET) as u64;
    let child_id = (child_ctx as usize).wrapping_sub(HORSE_CTX_OFFSET) as u64;

    combinator_slowpath(pa_id, pb_id, child_id);
    COMBINES_DONE.fetch_add(1, Ordering::Relaxed);
}

/// Off-stack slow path. Keeps handler frame tiny per handler
/// discipline (no format!, no log!, no big stack).
#[inline(never)]
fn combinator_slowpath(parent_a_id: u64, parent_b_id: u64, child_id: u64) {
    genes::combine_for_breeding(parent_a_id, parent_b_id, child_id);
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
    let rva = fn_addr::GENE_COMBINATOR;
    let runtime_addr = targets::rebase(rva);
    let mut prologue = [0u8; 16];
    // SAFETY: function entry inside our running image; read-only.
    let view =
        unsafe { std::slice::from_raw_parts(runtime_addr as *const u8, 16) };
    prologue.copy_from_slice(view);
    TargetReport {
        name: "GENE_COMBINATOR",
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
        anyhow::bail!("combinator already armed");
    }
    let runtime_addr = targets::rebase(fn_addr::GENE_COMBINATOR);
    let handler_addr = combinator_handler as *const () as usize;

    // SAFETY: target inside our loaded image; 8 bytes readable.
    let prologue =
        unsafe { std::slice::from_raw_parts(runtime_addr as *const u8, 8) };
    let prologue_hex: String = prologue
        .iter()
        .map(|b| format!("{b:02x}"))
        .collect::<Vec<_>>()
        .join(" ");
    modforge::log!(
        "combinator: GENE_COMBINATOR prologue=[{prologue_hex}] \
         (expecting 48 89 5c 24 .. or 48 8b c4 .. = MSVC prologue)"
    );

    modforge::log!(
        "combinator: install GENE_COMBINATOR target=0x{runtime_addr:x} \
         handler=0x{handler_addr:x}"
    );
    // SAFETY: address is the true entry of FUN_1400a2d80; signature
    // matches decomp prototype.
    let target: CombinatorFn = unsafe { std::mem::transmute(runtime_addr) };
    // SAFETY: signatures match.
    let detour = unsafe { GenericDetour::new(target, combinator_handler) }
        .map_err(|e| anyhow::anyhow!("combinator: GenericDetour::new failed: {e}"))?;
    // SAFETY: enable installs JMP + trampoline.
    unsafe { detour.enable() }
        .map_err(|e| anyhow::anyhow!("combinator: enable failed: {e}"))?;
    let leaked: *mut GenericDetour<CombinatorFn> = Box::into_raw(Box::new(detour));
    DETOUR.store(leaked, Ordering::Release);
    reset_stats();
    modforge::log!(
        "combinator: armed GENE_COMBINATOR at 0x{runtime_addr:x}"
    );
    Ok(())
}

pub fn revert() {
    let p = DETOUR.swap(std::ptr::null_mut(), Ordering::AcqRel);
    if p.is_null() {
        return;
    }
    // SAFETY: p was published by arm() and we just took ownership atomically.
    let det = unsafe { Box::from_raw(p) };
    // SAFETY: disable restores the prologue.
    let res = unsafe { det.disable() };
    match res {
        Ok(()) => modforge::log!("combinator: reverted GENE_COMBINATOR"),
        Err(e) => modforge::log!("combinator: revert FAILED: {e}"),
    }
}
