//! horsey-mod's declarative target registry (B2 starter).
//!
//! Each entry is a `modforge::patterns::sleuth::TargetDef`. The
//! Resolver controller in modforge walks this registry at attach
//! time and resolves every address, running the validators on each.
//!
//! Migration status: this file declares a STARTER SUBSET of
//! horsey-mod's targets to prove the cross-module wiring works.
//! The full set (~80 RVAs + ~30 resolvers from `targets.rs`)
//! migrates in batches under workspace todo P0 task B4.
//!
//! New targets land here as `static FOO: TargetDef = ...;` plus an
//! entry in `HORSEY_TARGETS.entries`.

use modforge::patterns::sleuth::{
    Candidate, InImage, Recipe, Resolver, TargetDef, TargetKind, TargetRegistry,
    Validator,
};
use modforge::vanilla::sig::{ArgKind, RetKind, Signature};

/// Pointer to the global game-state struct (`.data` slot at the
/// hardcoded RVA 0x1403fb0d8). Two candidates:
///
/// 1. Cheat-money anchor: `81 81 ... e8 03 00 00` is the `add [rcx+disp32], 1000`
///    inside DRAW_PAUSE_STATUS. The disp32 resolves to GAMESTATE_PTR + 0x308;
///    the +0x308 is baked into the hint, not the sig.
/// 2. HLT's constructor-store anchor: `48 89 1D ?? ?? ?? ?? 48 89 BB 70 02 00 00`
///    is the slot-store in FUN_1400fd580 followed by a follow-up
///    mov inside the same constructor.
static GAMESTATE_PTR_VALIDATORS: &[&dyn Validator] = &[&InImage];

static GAMESTATE_PTR: TargetDef = TargetDef {
    name: "GAMESTATE_PTR",
    kind: TargetKind::DataGlobal,
    candidates: &[
        Candidate {
            sig: "48 89 1D ?? ?? ?? ?? 48 89 BB 70 02 00 00",
            recipe: Recipe::DecodeRipDisp { disp_off: 3, instr_len: 7 },
        },
    ],
    hint_rva: Some(0x1403fb0d8),
    hint_tolerance: 0x1000,
    validators: GAMESTATE_PTR_VALIDATORS,
};

/// Signature for `APPLY_GENE_TO_HORSE`. The vanilla function takes
/// `(buf_ptr, horse_struct + 0x2b8)` and returns void. Decomp
/// evidence at FUN_14009f680 in research/decompiled.
pub static APPLY_GENE_SIG: Signature = Signature::new(
    &[ArgKind::Ptr, ArgKind::Ptr],
    RetKind::Void,
);

/// `APPLY_GENE_TO_HORSE` function entry. This is the D5 render
/// trampoline's hook target. Hint RVA from old decomp; the live
/// build's location may drift, but the prologue is stable.
/// Carries a Signature so it's invocable via `modforge::vanilla`.
static APPLY_GENE_VALIDATORS: &[&dyn Validator] = &[&InImage];

static APPLY_GENE_TO_HORSE: TargetDef = TargetDef {
    name: "APPLY_GENE_TO_HORSE",
    kind: TargetKind::FunctionEntry { signature: Some(&APPLY_GENE_SIG) },
    candidates: &[
        // Function entry prologue. Specific enough to identify
        // APPLY_GENE_TO_HORSE in the live image; the migration
        // will tune the byte width as needed during B4.
        Candidate {
            sig: "48 89 5C 24 ?? 48 89 6C 24 ?? 48 89 74 24",
            recipe: Recipe::MatchIsAddress,
        },
    ],
    hint_rva: Some(0x14009f670),
    hint_tolerance: 0x4000,
    validators: APPLY_GENE_VALIDATORS,
};

/// The starter registry. Every additional target lands here.
pub static HORSEY_TARGETS: TargetRegistry = TargetRegistry::new(
    "horsey-mod",
    &[
        &GAMESTATE_PTR,
        &APPLY_GENE_TO_HORSE,
    ],
);

/// Per-process Resolver singleton bound to `HORSEY_TARGETS`. Call
/// `resolver().resolve("NAME")` to get the cached addr.
pub static HORSEY_RESOLVER: Resolver = Resolver::new(&HORSEY_TARGETS);

/// Wire `vanilla.invoke` and `vanilla.list` HTTP cmdlets against
/// the horsey resolver. Call from worker init AFTER the OP_REGISTRY
/// has been built.
pub fn register_vanilla_ops() {
    modforge::vanilla::ops::register(&modforge::ops::OP_REGISTRY, &HORSEY_RESOLVER);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn registry_lookup_finds_every_declared_target() {
        assert!(HORSEY_TARGETS.def("GAMESTATE_PTR").is_some());
        assert!(HORSEY_TARGETS.def("APPLY_GENE_TO_HORSE").is_some());
        assert!(HORSEY_TARGETS.def("DEFINITELY_MISSING").is_none());
    }

    #[test]
    fn registry_iter_yields_all_entries() {
        let names: Vec<&str> = HORSEY_TARGETS.iter().map(|d| d.name).collect();
        assert!(names.contains(&"GAMESTATE_PTR"));
        assert!(names.contains(&"APPLY_GENE_TO_HORSE"));
        assert_eq!(names.len(), HORSEY_TARGETS.entries.len());
    }
}
