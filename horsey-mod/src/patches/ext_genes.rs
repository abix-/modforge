//! DI-A detours for the extended-gene integration.
//!
//! Strategy: per-function trampolines via `retour::GenericDetour`.
//! Each detour wraps a vanilla function that touches the gene table
//! at a literal index. Our handler dispatches on the index: vanilla
//! path for `idx < 240`, sidecar path for `idx >= 240`. See
//! `horsey-mod/docs/HOOKING-STRATEGY.md` §6.2 for the rationale.
//!
//! v1 covers 3 of the 5 DI-A targets:
//!   - `EVAL_DIPLOID_BLEND_A` (FUN_1400a5d20)
//!   - `EVAL_DIPLOID_BLEND_B` (FUN_1400a5e00)
//!   - `GENE_ALLELE_SWAP`    (FUN_1400c03a0)
//!
//! Deferred (need separate analysis):
//!   - `GENE_DEATH_DRIFT` (FUN_1400c0660): the gene index isn't a
//!     function parameter; it's computed mid-function. Needs a
//!     mid-function patch, not an entry-point detour.
//!   - `CRISPR_LAB` UI dispatch (FUN_1400c1cf0): state-machine
//!     function with internal gene-idx dispatch. Needs structural
//!     analysis before we know where to detour.
//!
//! Safety posture: detours stay disarmed at attach by default. The
//! operator runs `genes.ext.dryrun` to confirm addresses look sane,
//! then `genes.ext.arm` to install. `revert()` runs from
//! `patches::revert_all` on DLL detach so hot reload is safe.

use crate::genes;
use crate::targets::{self, fn_addr};
use parking_lot::Mutex;
use retour::GenericDetour;
use std::sync::atomic::{AtomicU64, Ordering};
use std::sync::OnceLock;

// ---------------------------------------------------------------------------
// Function signatures (must match the vanilla decomp prototypes exactly)
// ---------------------------------------------------------------------------

/// `FUN_1400a5d20`: allele diploid blend evaluator (formula A).
///
/// Decomp signature: `float FUN_1400a5d20(longlong param_1, int param_2)`
type EvalDiploidBlendFn = unsafe extern "system" fn(*const u8, i32) -> f32;

/// `FUN_1400a5e00`: allele diploid blend evaluator (formula B).
///
/// Decomp signature: `int FUN_1400a5e00(longlong param_1, int param_2)`.
/// Returns an `int` per the decomp but the bit pattern IS an f32
/// (vanilla's caller bit-casts). We model as f32 to keep the math
/// path consistent; the win64 ABI returns both via XMM0 / RAX in
/// the same low 32 bits for our purposes.
type EvalDiploidBlendBFn = unsafe extern "system" fn(*const u8, i32) -> u32;

/// `FUN_1400c03a0`: gene allele renumber sync.
///
/// Decomp signature: `void FUN_1400c03a0(undefined8 param_1, int param_2, int param_3, int param_4)`
/// - `param_1`: opaque pointer (game state ctx). Passed through.
/// - `param_2`: gene index. Same dispatch criterion as the others.
/// - `param_3`, `param_4`: allele positions being swapped.
type GeneAlleleSwapFn = unsafe extern "system" fn(usize, i32, i32, i32);

// ---------------------------------------------------------------------------
// Per-detour state
// ---------------------------------------------------------------------------

struct DetourSet {
    eval_a: Option<GenericDetour<EvalDiploidBlendFn>>,
    eval_b: Option<GenericDetour<EvalDiploidBlendBFn>>,
    allele_swap: Option<GenericDetour<GeneAlleleSwapFn>>,
}

fn detours() -> &'static Mutex<DetourSet> {
    static T: OnceLock<Mutex<DetourSet>> = OnceLock::new();
    T.get_or_init(|| {
        Mutex::new(DetourSet {
            eval_a: None,
            eval_b: None,
            allele_swap: None,
        })
    })
}

/// Total handler invocations across all detours since `arm()`.
static CALL_COUNT: AtomicU64 = AtomicU64::new(0);

/// Handler invocations that took the extended path (`idx >= 240`).
static EXT_CALL_COUNT: AtomicU64 = AtomicU64::new(0);

/// Max gene index any handler has seen. Sanity: stays < 240 until
/// something passes an extended index (e.g. the D5 trampoline
/// evaluating extended slots).
static MAX_IDX_SEEN: AtomicU64 = AtomicU64::new(0);

/// Per-handler invocation counts. (a, b, swap).
static CALL_COUNT_A: AtomicU64 = AtomicU64::new(0);
static CALL_COUNT_B: AtomicU64 = AtomicU64::new(0);
static CALL_COUNT_SWAP: AtomicU64 = AtomicU64::new(0);

pub fn is_armed() -> bool {
    let d = detours().lock();
    d.eval_a.is_some() || d.eval_b.is_some() || d.allele_swap.is_some()
}

pub fn stats() -> Stats {
    Stats {
        call_count: CALL_COUNT.load(Ordering::Relaxed),
        ext_call_count: EXT_CALL_COUNT.load(Ordering::Relaxed),
        max_idx_seen: MAX_IDX_SEEN.load(Ordering::Relaxed),
        call_count_a: CALL_COUNT_A.load(Ordering::Relaxed),
        call_count_b: CALL_COUNT_B.load(Ordering::Relaxed),
        call_count_swap: CALL_COUNT_SWAP.load(Ordering::Relaxed),
    }
}

pub struct Stats {
    pub call_count: u64,
    pub ext_call_count: u64,
    pub max_idx_seen: u64,
    pub call_count_a: u64,
    pub call_count_b: u64,
    pub call_count_swap: u64,
}

fn reset_stats() {
    CALL_COUNT.store(0, Ordering::Relaxed);
    EXT_CALL_COUNT.store(0, Ordering::Relaxed);
    MAX_IDX_SEEN.store(0, Ordering::Relaxed);
    CALL_COUNT_A.store(0, Ordering::Relaxed);
    CALL_COUNT_B.store(0, Ordering::Relaxed);
    CALL_COUNT_SWAP.store(0, Ordering::Relaxed);
}

fn bump_common(idx: i32) {
    CALL_COUNT.fetch_add(1, Ordering::Relaxed);
    let idx_u64 = idx.max(0) as u64;
    MAX_IDX_SEEN.fetch_max(idx_u64, Ordering::Relaxed);
}

// ---------------------------------------------------------------------------
// Handlers
// ---------------------------------------------------------------------------

/// EVAL_A handler. `idx<240` falls through to vanilla; `idx>=240`
/// computes the diploid blend against `EXT_GENE_TABLE` +
/// `EXT_HORSE_GENOMES`. See `genes::evaluate_ext_gene`.
///
/// SAFETY: signature matches the vanilla function. extern "system"
/// on x64 Windows is the win64 ABI; matches `(longlong, int) -> float`.
unsafe extern "system" fn eval_a_handler(genome: *const u8, idx: i32) -> f32 {
    bump_common(idx);
    CALL_COUNT_A.fetch_add(1, Ordering::Relaxed);
    if idx >= 240 {
        EXT_CALL_COUNT.fetch_add(1, Ordering::Relaxed);
        let horse_id = genome as u64;
        let ext_idx = (idx - 240) as usize;
        return genes::evaluate_ext_gene(horse_id, ext_idx);
    }
    let g = detours().lock();
    match g.eval_a.as_ref() {
        // SAFETY: trampoline is the saved original FUN_1400a5d20.
        Some(d) => unsafe { d.call(genome, idx) },
        None => 0.0,
    }
}

/// EVAL_B handler. Same dispatch as EVAL_A but the vanilla return
/// type is `int` (bit-cast f32). For the extended path we evaluate
/// the same blend and bit-cast to u32 so the caller's bit-pattern
/// expectation is preserved.
///
/// SAFETY: extern "system" matches `(longlong, int) -> int`.
unsafe extern "system" fn eval_b_handler(genome: *const u8, idx: i32) -> u32 {
    bump_common(idx);
    CALL_COUNT_B.fetch_add(1, Ordering::Relaxed);
    if idx >= 240 {
        EXT_CALL_COUNT.fetch_add(1, Ordering::Relaxed);
        let horse_id = genome as u64;
        let ext_idx = (idx - 240) as usize;
        return genes::evaluate_ext_gene(horse_id, ext_idx).to_bits();
    }
    let g = detours().lock();
    match g.eval_b.as_ref() {
        // SAFETY: trampoline is the saved original FUN_1400a5e00.
        Some(d) => unsafe { d.call(genome, idx) },
        None => 0,
    }
}

/// GENE_ALLELE_SWAP handler. For `idx<240` vanilla syncs the swap
/// across every pop record. For `idx>=240` we mirror the swap in
/// our `EXT_GENE_TABLE` and `EXT_POP_WEIGHTS` and SKIP vanilla
/// (vanilla would walk DAT_1403ee4b0 with an out-of-range index
/// and crash).
///
/// SAFETY: extern "system" matches `(undefined8, int, int, int) -> void`.
unsafe extern "system" fn allele_swap_handler(
    ctx: usize,
    gene_idx: i32,
    a: i32,
    b: i32,
) {
    bump_common(gene_idx);
    CALL_COUNT_SWAP.fetch_add(1, Ordering::Relaxed);
    if gene_idx >= 240 {
        EXT_CALL_COUNT.fetch_add(1, Ordering::Relaxed);
        let ext_idx = (gene_idx - 240) as usize;
        genes::swap_ext_alleles(ext_idx, a as usize, b as usize);
        return;
    }
    let g = detours().lock();
    if let Some(d) = g.allele_swap.as_ref() {
        // SAFETY: trampoline is the saved original FUN_1400c03a0.
        unsafe { d.call(ctx, gene_idx, a, b) };
    }
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
    /// True if `arm()` wires up a real detour for this target.
    pub wired: bool,
}

/// Per-target metadata. The full DI-A target set is enumerated for
/// dryrun visibility even when some are not yet wired.
const TARGETS: &[(&str, usize, bool)] = &[
    ("EVAL_DIPLOID_BLEND_A", fn_addr::EVAL_DIPLOID_BLEND_A, true),
    ("EVAL_DIPLOID_BLEND_B", fn_addr::EVAL_DIPLOID_BLEND_B, true),
    ("GENE_ALLELE_SWAP", fn_addr::GENE_ALLELE_SWAP, true),
    ("GENE_DEATH_DRIFT", fn_addr::GENE_DEATH_DRIFT, false),
];

pub fn dryrun() -> Vec<TargetReport> {
    let mut out = Vec::with_capacity(TARGETS.len());
    for (name, rva, wired) in TARGETS {
        let runtime_addr = targets::rebase(*rva);
        let mut prologue = [0u8; 16];
        // SAFETY: `runtime_addr` is the entry of a known function
        // in the running Horsey.exe image. Read-only.
        let view = unsafe { std::slice::from_raw_parts(runtime_addr as *const u8, 16) };
        prologue.copy_from_slice(view);
        out.push(TargetReport {
            name,
            rva: *rva,
            runtime_addr,
            prologue_bytes: prologue,
            wired: *wired,
        });
    }
    out
}

// ---------------------------------------------------------------------------
// Arm / revert
// ---------------------------------------------------------------------------

fn install_eval_a(set: &mut DetourSet) -> anyhow::Result<()> {
    let runtime_addr = targets::rebase(fn_addr::EVAL_DIPLOID_BLEND_A);
    // SAFETY: address is the entry of FUN_1400a5d20 in our image;
    // signature matches the vanilla prototype.
    let target: EvalDiploidBlendFn = unsafe { std::mem::transmute(runtime_addr) };
    // SAFETY: target/replacement have identical signatures.
    let detour = unsafe { GenericDetour::new(target, eval_a_handler) }
        .map_err(|e| anyhow::anyhow!("eval_a: GenericDetour::new failed: {e}"))?;
    // SAFETY: enable writes the JMP + installs the trampoline.
    unsafe { detour.enable() }
        .map_err(|e| anyhow::anyhow!("eval_a: enable failed: {e}"))?;
    set.eval_a = Some(detour);
    modforge::log!("ext_genes: armed EVAL_DIPLOID_BLEND_A at 0x{runtime_addr:x}");
    Ok(())
}

fn install_eval_b(set: &mut DetourSet) -> anyhow::Result<()> {
    let runtime_addr = targets::rebase(fn_addr::EVAL_DIPLOID_BLEND_B);
    // SAFETY: address is the entry of FUN_1400a5e00 in our image.
    let target: EvalDiploidBlendBFn = unsafe { std::mem::transmute(runtime_addr) };
    // SAFETY: signatures match.
    let detour = unsafe { GenericDetour::new(target, eval_b_handler) }
        .map_err(|e| anyhow::anyhow!("eval_b: GenericDetour::new failed: {e}"))?;
    // SAFETY: enable installs the detour.
    unsafe { detour.enable() }
        .map_err(|e| anyhow::anyhow!("eval_b: enable failed: {e}"))?;
    set.eval_b = Some(detour);
    modforge::log!("ext_genes: armed EVAL_DIPLOID_BLEND_B at 0x{runtime_addr:x}");
    Ok(())
}

fn install_allele_swap(set: &mut DetourSet) -> anyhow::Result<()> {
    let runtime_addr = targets::rebase(fn_addr::GENE_ALLELE_SWAP);
    // SAFETY: address is the entry of FUN_1400c03a0 in our image.
    let target: GeneAlleleSwapFn = unsafe { std::mem::transmute(runtime_addr) };
    // SAFETY: signatures match.
    let detour = unsafe { GenericDetour::new(target, allele_swap_handler) }
        .map_err(|e| anyhow::anyhow!("allele_swap: GenericDetour::new failed: {e}"))?;
    // SAFETY: enable installs the detour.
    unsafe { detour.enable() }
        .map_err(|e| anyhow::anyhow!("allele_swap: enable failed: {e}"))?;
    set.allele_swap = Some(detour);
    modforge::log!("ext_genes: armed GENE_ALLELE_SWAP at 0x{runtime_addr:x}");
    Ok(())
}

/// Install the DI-A v1 detour set (EVAL_A, EVAL_B, ALLELE_SWAP).
/// Errors out if any one fails; previously installed detours from
/// the same `arm()` call are rolled back so we never half-arm.
pub fn arm() -> anyhow::Result<()> {
    let mut g = detours().lock();
    if g.eval_a.is_some() || g.eval_b.is_some() || g.allele_swap.is_some() {
        anyhow::bail!("ext_genes already armed");
    }

    if let Err(e) = install_eval_a(&mut g) {
        return Err(e);
    }
    if let Err(e) = install_eval_b(&mut g) {
        // Roll back eval_a so we never report partial arming.
        if let Some(d) = g.eval_a.take() {
            // SAFETY: disable restores the prologue.
            let _ = unsafe { d.disable() };
        }
        return Err(e);
    }
    if let Err(e) = install_allele_swap(&mut g) {
        if let Some(d) = g.eval_b.take() {
            // SAFETY: disable restores the prologue.
            let _ = unsafe { d.disable() };
        }
        if let Some(d) = g.eval_a.take() {
            // SAFETY: disable restores the prologue.
            let _ = unsafe { d.disable() };
        }
        return Err(e);
    }

    reset_stats();
    Ok(())
}

pub fn revert() {
    let mut g = detours().lock();
    let take_a = g.eval_a.take();
    let take_b = g.eval_b.take();
    let take_swap = g.allele_swap.take();
    drop(g);

    for (name, detour) in [
        ("EVAL_DIPLOID_BLEND_A", take_a.map(|d| Box::new(d) as Box<dyn DisableAny>)),
        ("EVAL_DIPLOID_BLEND_B", take_b.map(|d| Box::new(d) as Box<dyn DisableAny>)),
        ("GENE_ALLELE_SWAP", take_swap.map(|d| Box::new(d) as Box<dyn DisableAny>)),
    ] {
        if let Some(d) = detour {
            match d.disable_any() {
                Ok(()) => modforge::log!("ext_genes: reverted {name}"),
                Err(e) => modforge::log!("ext_genes: revert {name} FAILED: {e}"),
            }
        }
    }
}

/// Type-erased disable wrapper so the revert loop can treat the
/// three differently-typed detours uniformly.
trait DisableAny {
    fn disable_any(&self) -> Result<(), retour::Error>;
}

impl<T: retour::Function> DisableAny for GenericDetour<T> {
    fn disable_any(&self) -> Result<(), retour::Error> {
        // SAFETY: disable restores the prologue retour stashed at enable.
        unsafe { self.disable() }
    }
}
