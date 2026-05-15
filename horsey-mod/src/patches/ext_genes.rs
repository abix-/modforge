//! D1 / DI-A detours for the extended-gene integration.
//!
//! Strategy: per-function trampolines via `retour::GenericDetour`.
//! Each detour wraps a vanilla function that touches the gene table
//! at a literal index. Our handler dispatches on the index: vanilla
//! path for `idx < 240`, sidecar path for `idx >= 240`. See
//! `horsey-mod/docs/HOOKING-STRATEGY.md` §6.2 for the rationale.
//!
//! v1 first slice: ONE detour on `FUN_1400a5d20`
//! (allele evaluator A). Once in-game verification confirms the
//! pattern works, we fan out to the 4 other DI-A targets
//! (a5e00, c0660, c03a0, c1cf0).
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
/// - `param_1`: pointer to a horse's 480-byte genome buffer at
///   `horse + 0x78`. Vanilla reads `*(char*)(param_1 + idx)` for
///   the maternal allele and `*(char*)(param_1 + 0xf0 + idx)` for
///   the paternal allele.
/// - `param_2`: gene index in [0..240).
/// - Returns: f32 blend value the caller writes into `param_1[N]`
///   of the render buffer.
type EvalDiploidBlendFn = unsafe extern "system" fn(*const u8, i32) -> f32;

// ---------------------------------------------------------------------------
// State
// ---------------------------------------------------------------------------

/// The single installed detour on `EVAL_DIPLOID_BLEND_A`. `None` when
/// not armed; `Some` after `arm()` succeeds; back to `None` after
/// `revert()`.
static EVAL_A_DETOUR: OnceLock<Mutex<Option<GenericDetour<EvalDiploidBlendFn>>>> =
    OnceLock::new();

fn detour_slot() -> &'static Mutex<Option<GenericDetour<EvalDiploidBlendFn>>> {
    EVAL_A_DETOUR.get_or_init(|| Mutex::new(None))
}

/// Total handler invocations since `arm()`. Bumped on every call,
/// regardless of vanilla vs extended dispatch. Surfaced via
/// `genes.ext.stats` for "is the detour even firing" verification.
static CALL_COUNT: AtomicU64 = AtomicU64::new(0);

/// Handler invocations that hit the extended path (`idx >= 240`).
static EXT_CALL_COUNT: AtomicU64 = AtomicU64::new(0);

/// Max gene index observed in any handler call. Useful for sanity:
/// in v1 with no extended-aware caller, we expect this to stay
/// strictly below 240 because vanilla `FUN_14009f680` only ever
/// passes literal indices in [0..240). When the D5 trampoline
/// starts driving extended-gene evaluations, this will climb above
/// 240 and prove the detour pipeline is working end-to-end.
static MAX_IDX_SEEN: AtomicU64 = AtomicU64::new(0);

pub fn is_armed() -> bool {
    detour_slot().lock().is_some()
}

pub fn stats() -> (u64, u64, u64) {
    (
        CALL_COUNT.load(Ordering::Relaxed),
        EXT_CALL_COUNT.load(Ordering::Relaxed),
        MAX_IDX_SEEN.load(Ordering::Relaxed),
    )
}

pub fn reset_stats() {
    CALL_COUNT.store(0, Ordering::Relaxed);
    EXT_CALL_COUNT.store(0, Ordering::Relaxed);
    MAX_IDX_SEEN.store(0, Ordering::Relaxed);
}

// ---------------------------------------------------------------------------
// Handler
// ---------------------------------------------------------------------------

/// Our replacement for `FUN_1400a5d20`. Dispatches on the gene index:
///
/// - `idx >= 240`: extended slot. Compute the diploid blend against
///   our sidecar tables (`EXT_GENE_TABLE` + `EXT_HORSE_GENOMES`)
///   using the horse genome pointer as a session-local key.
/// - `idx < 240`: vanilla. Call the saved trampoline so the game's
///   original math runs unchanged.
///
/// SAFETY: signature must match the vanilla function exactly. `extern
/// "system"` on x64 Windows is the win64 ABI, which matches the
/// decompiler's `(longlong, int) -> float` C signature.
unsafe extern "system" fn eval_a_handler(genome: *const u8, idx: i32) -> f32 {
    CALL_COUNT.fetch_add(1, Ordering::Relaxed);
    let idx_u64 = idx.max(0) as u64;
    MAX_IDX_SEEN.fetch_max(idx_u64, Ordering::Relaxed);

    if idx >= 240 {
        EXT_CALL_COUNT.fetch_add(1, Ordering::Relaxed);
        let horse_id = genome as u64;
        let ext_idx = (idx - 240) as usize;
        return genes::evaluate_ext_gene(horse_id, ext_idx);
    }

    // Vanilla path.
    match detour_slot().lock().as_ref() {
        // SAFETY: the trampoline is a valid function pointer for the
        // original `FUN_1400a5d20`, produced by retour. Same ABI,
        // same arguments. Calling it is no less safe than calling
        // the original function directly.
        Some(d) => unsafe { d.call(genome, idx) },
        // Shouldn't happen: arm() installs before enabling. Defensive
        // fallback returns 0.0 instead of crashing the game.
        None => 0.0,
    }
}

// ---------------------------------------------------------------------------
// Dryrun (read-only diagnostic)
// ---------------------------------------------------------------------------

/// What `dryrun` learned about one target function.
#[derive(Debug, Clone)]
pub struct TargetReport {
    pub name: &'static str,
    /// PE-relative address from `targets::fn_addr` constants.
    pub rva: usize,
    /// Resolved runtime address.
    pub runtime_addr: usize,
    /// First 16 bytes of the function (for visual sanity check that
    /// we're pointing at code, not data).
    pub prologue_bytes: [u8; 16],
}

/// Per-target metadata. The full DI-A target set is enumerated for
/// dryrun even though only the first is wired to `arm()` in v1.
const TARGETS: &[(&str, usize)] = &[
    ("EVAL_DIPLOID_BLEND_A", fn_addr::EVAL_DIPLOID_BLEND_A),
    ("EVAL_DIPLOID_BLEND_B", fn_addr::EVAL_DIPLOID_BLEND_B),
    ("GENE_DEATH_DRIFT", fn_addr::GENE_DEATH_DRIFT),
    ("GENE_ALLELE_SWAP", fn_addr::GENE_ALLELE_SWAP),
];

pub fn dryrun() -> Vec<TargetReport> {
    let mut out = Vec::with_capacity(TARGETS.len());
    for (name, rva) in TARGETS {
        let runtime_addr = targets::rebase(*rva);
        let mut prologue = [0u8; 16];
        // SAFETY: `runtime_addr` is the entry of a known function
        // inside the running Horsey.exe image. Reading 16 bytes is
        // safe; we never write.
        let view = unsafe { std::slice::from_raw_parts(runtime_addr as *const u8, 16) };
        prologue.copy_from_slice(view);
        out.push(TargetReport {
            name,
            rva: *rva,
            runtime_addr,
            prologue_bytes: prologue,
        });
    }
    out
}

// ---------------------------------------------------------------------------
// Arm / revert
// ---------------------------------------------------------------------------

/// Install the DI-A v1 detour set (currently: just
/// `EVAL_DIPLOID_BLEND_A`). Returns Ok once enabled. The detour
/// then dispatches every call through `eval_a_handler`.
///
/// Idempotent against repeat calls: if already armed, returns an
/// error so the operator notices instead of silently re-installing.
pub fn arm() -> anyhow::Result<()> {
    {
        let g = detour_slot().lock();
        if g.is_some() {
            anyhow::bail!("ext_genes already armed");
        }
    }

    let runtime_addr = targets::rebase(fn_addr::EVAL_DIPLOID_BLEND_A);

    // Transmute the raw address into our typed function pointer.
    // SAFETY: `runtime_addr` is the entry of `FUN_1400a5d20`,
    // resolved from a hardcoded PE-relative address into the running
    // Horsey.exe image. The signature `EvalDiploidBlendFn` matches
    // the vanilla decomp prototype. Transmuting a usize that is a
    // valid function entry into a function pointer of the right
    // ABI is well-defined.
    let target: EvalDiploidBlendFn = unsafe { std::mem::transmute(runtime_addr) };

    // Build and enable the detour. SAFETY: retour requires the
    // target be a valid function entry with our claimed signature;
    // we just constructed it from the address resolved above. The
    // replacement (`eval_a_handler`) has the same signature.
    let detour = unsafe { GenericDetour::new(target, eval_a_handler) }
        .map_err(|e| anyhow::anyhow!("GenericDetour::new failed: {e}"))?;

    // SAFETY: enable() writes the JMP rel32 at the target entry and
    // installs the trampoline page. retour handles RIP-relative
    // rewrites and >2GB relays internally.
    unsafe { detour.enable() }
        .map_err(|e| anyhow::anyhow!("GenericDetour::enable failed: {e}"))?;

    *detour_slot().lock() = Some(detour);
    reset_stats();
    modforge::log!(
        "ext_genes: armed EVAL_DIPLOID_BLEND_A detour at 0x{runtime_addr:x}"
    );
    Ok(())
}

/// Revert the installed detour. Called from
/// `patches::revert_all` on DLL detach so hot reload is safe.
/// Idempotent: no-op if not armed.
pub fn revert() {
    let detour = detour_slot().lock().take();
    if let Some(d) = detour {
        // SAFETY: disable() restores the original prologue bytes
        // retour stashed during enable(). The detour value is then
        // dropped (releasing the trampoline page).
        let res = unsafe { d.disable() };
        match res {
            Ok(()) => modforge::log!("ext_genes: reverted EVAL_DIPLOID_BLEND_A detour"),
            Err(e) => modforge::log!("ext_genes: revert FAILED: {e}"),
        }
    }
}
