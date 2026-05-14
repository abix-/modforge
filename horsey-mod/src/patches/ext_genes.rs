//! D1 detour scaffolding for the extended-gene patches.
//!
//! Status: NOT YET ACTIVE in production. Detours are disabled at
//! attach by default so a fresh inject can never crash the game.
//! Arming is via the `genes.ext.activate_patches` HTTP op, which
//! the user calls manually after confirming the address scan
//! returned plausible targets via `genes.ext.dryrun`.
//!
//! Per the design principle in `horsey-mod/docs/todo.md`:
//! - Vanilla code paths stay valid for genes 0..239.
//! - For genes 240..480 we route through our sidecar buffers.
//! - The detours dispatch on the gene-index argument: vanilla path
//!   for low indices, our path for high.
//!
//! What's IN this module today (D1 phase):
//!   - `dryrun()`: walks each target function's prologue and reports
//!     what it sees. No memory writes. Safe to call anytime.
//!   - `arm()`: stub that, when implemented, installs the detours.
//!     Currently returns an "unimplemented" error so misclicks fail
//!     loudly.
//!
//! What's NOT here yet (D1 follow-up):
//!   - The actual detour-install machinery (5-byte JMP rel32 at
//!     each function entry, stash original prologue bytes in a
//!     trampoline page, install handler that calls our Rust fn
//!     and, if vanilla path needed, jumps past the JMP into the
//!     saved prologue + tail of the original function).
//!   - The handler functions themselves (Rust extern "system" fns
//!     that read RCX/RDX per the Win64 ABI, dispatch to
//!     `crate::genes::evaluate_ext_gene`, return).
//!
//! The reason we ship dryrun + arm-stub now is to lock in the
//! address table and surface any base-image / ASLR drift as soon
//! as the user runs a build. When we add the detour-install code
//! later, the addresses don't move.

use crate::targets::{self, fn_addr};
use parking_lot::Mutex;

/// Whether `arm()` has been called and succeeded. Detour handlers
/// (when they exist) check this flag to know whether to dispatch
/// to the extended path or fall straight through to vanilla.
static ARMED: Mutex<bool> = Mutex::new(false);

pub fn is_armed() -> bool {
    *ARMED.lock()
}

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

/// Per-target metadata. Iterating this is how `dryrun()` and the
/// future `arm()` enumerate the detour install set.
const TARGETS: &[(&str, usize)] = &[
    ("EVAL_DIPLOID_BLEND_A", fn_addr::EVAL_DIPLOID_BLEND_A),
    ("EVAL_DIPLOID_BLEND_B", fn_addr::EVAL_DIPLOID_BLEND_B),
    ("GENE_DEATH_DRIFT", fn_addr::GENE_DEATH_DRIFT),
    ("GENE_ALLELE_SWAP", fn_addr::GENE_ALLELE_SWAP),
];

/// Walk each detour target and capture its first 16 bytes.
/// READ-ONLY; never mutates game memory. Safe to call at any point
/// after the game's image has loaded (which DllMain guarantees).
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

/// Install the D1 detours. Currently a stub: returns an error so a
/// misclick on the HTTP op doesn't half-install anything. Will be
/// implemented in the next D1 sub-phase once we have the trampoline
/// machinery (allocate executable page, copy original prologue,
/// emit JMP back to target+5, atomically write the JMP rel32 at
/// target+0).
pub fn arm() -> anyhow::Result<()> {
    let a = ARMED.lock();
    if *a {
        anyhow::bail!("ext_genes already armed");
    }
    // TODO(D1): install detours. Until the trampoline machinery
    // lands, refuse to flip the flag so callers know nothing
    // happened.
    drop(a);
    anyhow::bail!(
        "ext_genes::arm() not yet implemented. See `horsey-mod/docs/todo.md` D1.1-D1.4. \
         Use `genes.ext.dryrun` to verify target addresses look correct in the meantime."
    )
}

/// Revert the D1 detours. Currently a no-op since `arm` is a stub.
/// When detours land, this restores the original prologue bytes at
/// each target. Called from the existing `patches::revert_all` via
/// the parent module.
pub fn revert() {
    let mut a = ARMED.lock();
    if !*a {
        return;
    }
    // TODO(D1): restore original bytes at each detour site.
    *a = false;
}
