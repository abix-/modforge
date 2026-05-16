//! horsey-mod's declarative target registry.
//!
//! Every horsey address (data globals, function entries, field
//! offsets) is declared here as a `modforge::patterns::sleuth::TargetDef`.
//! The Resolver controller in modforge walks this registry at attach
//! time and resolves every address, running validators on each.
//!
//! Migration status (B4): the bulk of entries use `candidates: &[]`
//! and rely on `hint_rva` fallback for now; they resolve to the
//! same hardcoded RVAs the legacy `targets::resolve::*` functions
//! return. Per-target sig tuning happens as targets get exercised
//! against the live game; each tuned target adds a real
//! `Candidate { sig, recipe }` to its entry.
//!
//! The legacy `targets::resolve::*` family in `targets.rs` stays
//! callable during the migration; the parity test in
//! `tests/registry_parity.rs` guards against drift.

use modforge::patterns::sleuth::{
    Candidate, InImage, Recipe, Resolver, TargetDef, TargetKind, TargetRegistry,
    Validator,
};
use modforge::vanilla::sig::{ArgKind, RetKind, Signature};

// ============================================================================
// Validator chains (shared by groups of similar targets)
// ============================================================================

static V_IN_IMAGE: &[&dyn Validator] = &[&InImage];
static V_NONE: &[&dyn Validator] = &[];

// ============================================================================
// Data globals (.data slots)
// ============================================================================

static GAMESTATE_PTR: TargetDef = TargetDef {
    name: "GAMESTATE_PTR",
    kind: TargetKind::DataGlobal,
    candidates: &[Candidate {
        sig: "48 89 1D ?? ?? ?? ?? 48 89 BB 70 02 00 00",
        recipe: Recipe::DecodeRipDisp { disp_off: 3, instr_len: 7 },
    }],
    hint_rva: Some(0x1403fb0d8),
    hint_tolerance: 0x1000,
    validators: V_IN_IMAGE,
};

static SAVE_VERSION_GLOBAL: TargetDef = TargetDef {
    name: "SAVE_VERSION_GLOBAL",
    kind: TargetKind::DataGlobal,
    candidates: &[],
    hint_rva: Some(0x1403fb0e0),
    hint_tolerance: 0x1000,
    validators: V_IN_IMAGE,
};

static RACES_COUNTER: TargetDef = TargetDef {
    name: "RACES_COUNTER",
    kind: TargetKind::DataGlobal,
    candidates: &[],
    hint_rva: Some(0x1403eded8),
    hint_tolerance: 0x1000,
    validators: V_IN_IMAGE,
};

static NO_TIRE_TOGGLE: TargetDef = TargetDef {
    name: "NO_TIRE_TOGGLE",
    kind: TargetKind::DataGlobal,
    candidates: &[],
    hint_rva: Some(0x1403d95a5),
    hint_tolerance: 0x1000,
    validators: V_IN_IMAGE,
};

/// `DEBUG_MODE_ACTIVE`. Anchor: the unlock-block
/// `c6 05 ?? ?? ?? ?? 01 c6 05 ?? ?? ?? ?? 00` (set 1 + set 0).
/// Two RIP-rel `mov byte ptr [global], imm` instructions, 7 bytes
/// each. The two targets are at known relative offset -0x79 in
/// the live build's .data layout.
static DEBUG_MODE_ACTIVE: TargetDef = TargetDef {
    name: "DEBUG_MODE_ACTIVE",
    kind: TargetKind::DataGlobal,
    candidates: &[Candidate {
        sig: "c6 05 ?? ?? ?? ?? 01 c6 05 ?? ?? ?? ?? 00",
        recipe: Recipe::PairedRipDispWithDelta {
            disp1_off: 2, disp1_next_ip: 7,
            disp2_off: 9, disp2_next_ip: 14,
            delta: -0x79,
        },
    }],
    hint_rva: Some(0x1403d957b),
    hint_tolerance: 0x1000,
    validators: V_IN_IMAGE,
};

/// `DEBUG_LOG_GATE`. Anchor: the global-init triplet
/// `c7 05 ?? ?? ?? ?? 00 01 00 00 c7 05 ?? ?? ?? ?? ff ff ff ff`
/// (3rd write = 0x100 to DAT_1403d9598, then 4th write = 0xffffffff).
/// The decomp's known offset from the 3rd-write target to
/// DEBUG_LOG_GATE is -0x72 (cheat globals drift uniformly when
/// .data is re-laid-out, so this rel-offset is stable across builds).
static DEBUG_LOG_GATE: TargetDef = TargetDef {
    name: "DEBUG_LOG_GATE",
    kind: TargetKind::DataGlobal,
    candidates: &[Candidate {
        sig: "c7 05 ?? ?? ?? ?? 00 01 00 00 c7 05 ?? ?? ?? ?? ff ff ff ff",
        recipe: Recipe::RipDispWithRelOffset {
            disp_off: 2, instr_len: 10, rel_offset: -0x72,
        },
    }],
    hint_rva: Some(0x1403d9506),
    hint_tolerance: 0x1000,
    validators: V_IN_IMAGE,
};

static NAME_TABLE: TargetDef = TargetDef {
    name: "NAME_TABLE",
    kind: TargetKind::DataGlobal,
    candidates: &[],
    hint_rva: Some(0x1403f34e0),
    hint_tolerance: 0x1000,
    validators: V_IN_IMAGE,
};

// ============================================================================
// Function entries
// ============================================================================
//
// Most entries below are hint-only during the B4 migration. As each
// is exercised in production, a real Candidate gets added with the
// derived sig + recipe. The legacy `targets::function_entry::*`
// consts stay valid until B5 deletes them.

/// Standard MSVC Win64 prologue sig that fits most horsey-mod
/// targets: `mov [rsp+disp8], rbx; mov [rsp+disp8], rbp; mov [rsp+disp8], rsi`.
/// Specific-enough for hint-tolerance guarding to disambiguate.
const PROLOGUE_SHADOW_SAVE_3: &str =
    "48 89 5C 24 ?? 48 89 6C 24 ?? 48 89 74 24";

// Signatures for invocable functions. These let the function be
// called via `modforge::vanilla::Invoker`.
pub static APPLY_GENE_SIG: Signature = Signature::new(
    &[ArgKind::Ptr, ArgKind::Ptr],
    RetKind::Void,
);

/// `HORSE_REBUILD` / `FUN_1400b3070` per HLT
/// `kRvaHorseRebuildEquipmentAndPhysics`. Takes the horse ptr and
/// rebuilds derived state from the working genome.
pub static HORSE_REBUILD_SIG: Signature = Signature::new(
    &[ArgKind::Ptr],
    RetKind::Void,
);

/// `FUN_1400c6580` per HLT `kRvaRngNextModulo`. Generic
/// `rng_next() % modulus`.
pub static RNG_NEXT_MODULO_SIG: Signature = Signature::new(
    &[ArgKind::U32],
    RetKind::U32,
);

/// `FUN_1400b35f0` per HLT `kRvaHorseCopyGeneLanePairs`. Sets a
/// horse's genome from a 480-byte buffer.
pub static HORSE_COPY_GENE_LANE_PAIRS_SIG: Signature = Signature::new(
    &[ArgKind::Ptr, ArgKind::Ptr],
    RetKind::Void,
);

static APPLY_GENE_TO_HORSE: TargetDef = TargetDef {
    name: "APPLY_GENE_TO_HORSE",
    kind: TargetKind::FunctionEntry { signature: Some(&APPLY_GENE_SIG) },
    candidates: &[Candidate {
        sig: PROLOGUE_SHADOW_SAVE_3,
        recipe: Recipe::MatchIsAddress,
    }],
    hint_rva: Some(0x14009f670),
    hint_tolerance: 0x4000,
    validators: V_IN_IMAGE,
};

/// New entries from HLT cross-reference: invocable vanilla functions.
static HORSE_REBUILD: TargetDef = TargetDef {
    name: "HORSE_REBUILD",
    kind: TargetKind::FunctionEntry { signature: Some(&HORSE_REBUILD_SIG) },
    candidates: &[],
    hint_rva: Some(0x1400b3070),
    hint_tolerance: 0x4000,
    validators: V_IN_IMAGE,
};

static RNG_NEXT_MODULO: TargetDef = TargetDef {
    name: "RNG_NEXT_MODULO",
    kind: TargetKind::FunctionEntry { signature: Some(&RNG_NEXT_MODULO_SIG) },
    candidates: &[],
    hint_rva: Some(0x1400c6580),
    hint_tolerance: 0x4000,
    validators: V_IN_IMAGE,
};

static HORSE_COPY_GENE_LANE_PAIRS: TargetDef = TargetDef {
    name: "HORSE_COPY_GENE_LANE_PAIRS",
    kind: TargetKind::FunctionEntry {
        signature: Some(&HORSE_COPY_GENE_LANE_PAIRS_SIG),
    },
    candidates: &[],
    hint_rva: Some(0x1400b35f0),
    hint_tolerance: 0x4000,
    validators: V_IN_IMAGE,
};

// Function entries inherited from existing targets.rs. Hint-only
// during B4; real sigs land per target as they get tuned.

macro_rules! hint_only_fn {
    ($name:ident, $rva:expr) => {
        static $name: TargetDef = TargetDef {
            name: stringify!($name),
            kind: TargetKind::FunctionEntry { signature: None },
            candidates: &[],
            hint_rva: Some($rva),
            hint_tolerance: 0x4000,
            validators: V_IN_IMAGE,
        };
    };
}

hint_only_fn!(EVAL_DIPLOID_BLEND_A,   0x1400a5d10);
hint_only_fn!(EVAL_DIPLOID_BLEND_B,   0x1400a5df0);
hint_only_fn!(GENE_DEATH_DRIFT,       0x1400c0650);
hint_only_fn!(GENE_ALLELE_SWAP,       0x1400c0390);
hint_only_fn!(GENE_TABLE_XML_WRITER,  0x1400a4880);
hint_only_fn!(GENE_TABLE_LOADER,      0x1400a3eb0);
hint_only_fn!(POP_XML_LOADER,         0x1400a4fe0);
hint_only_fn!(GENE_ENGINE_CONSUMER,   0x1400ab3c0);
hint_only_fn!(CHECK_HORSE_ELIGIBILITY,0x1400de230);
hint_only_fn!(RETIRE_HORSE_HANDLER,   0x1400df675);
hint_only_fn!(COMPUTE_HORSE_PRICE,    0x1400dc785);
hint_only_fn!(CRISPR_LAB,             0x1400894bc);
hint_only_fn!(BREEDING,               0x1400e0817);
hint_only_fn!(SAVE_WRITER,            0x14006d674);
hint_only_fn!(LOAD_GAME,              0x14006e350);
hint_only_fn!(DRAW_PAUSE_STATUS,      0x1400660cc);
hint_only_fn!(TMX_MAP_PARSER,         0x1400fe2e0);
hint_only_fn!(POP_GENOME_BUILDER,     0x1400927e7);
hint_only_fn!(DAILY_HORSE_EVENT,      0x14002fe00);
hint_only_fn!(TRACK_STATE_MACHINE,    0x14002d7c0);
hint_only_fn!(CIRCUS_HANDLER,         0x140039190);
hint_only_fn!(SUMO_HANDLER,           0x14007b28c);
hint_only_fn!(POWER_PLANT,            0x140069270);
hint_only_fn!(WORLD_ACTION,           0x1401075a2);
hint_only_fn!(BALLOON_CONTROLLER,     0x14010a9e0);
hint_only_fn!(HORSE_CONSTRUCTOR,      0x1400aac50);
hint_only_fn!(HORSE_DESTRUCTOR,       0x1400bf1e0);
hint_only_fn!(GENE_COMBINATOR,        0x1400a2d70);
hint_only_fn!(HORSE_SAVE_WRITER,      0x14006ecfb);
hint_only_fn!(HORSE_SAVE_LOADER,      0x14006f031);

// Silence unused warning for V_NONE (kept for future field-offset
// entries that don't need validators).
#[allow(dead_code)]
static _V_NONE_KEEPALIVE: &[&dyn Validator] = V_NONE;

// ============================================================================
// The registry
// ============================================================================

pub static HORSEY_TARGETS: TargetRegistry = TargetRegistry::new(
    "horsey-mod",
    &[
        // Data globals
        &GAMESTATE_PTR,
        &SAVE_VERSION_GLOBAL,
        &RACES_COUNTER,
        &NO_TIRE_TOGGLE,
        &DEBUG_MODE_ACTIVE,
        &DEBUG_LOG_GATE,
        &NAME_TABLE,

        // Invocable functions (with Signature)
        &APPLY_GENE_TO_HORSE,
        &HORSE_REBUILD,
        &RNG_NEXT_MODULO,
        &HORSE_COPY_GENE_LANE_PAIRS,

        // Function entries (hint-only; sigs land per-target during B4)
        &EVAL_DIPLOID_BLEND_A,
        &EVAL_DIPLOID_BLEND_B,
        &GENE_DEATH_DRIFT,
        &GENE_ALLELE_SWAP,
        &GENE_TABLE_XML_WRITER,
        &GENE_TABLE_LOADER,
        &POP_XML_LOADER,
        &GENE_ENGINE_CONSUMER,
        &CHECK_HORSE_ELIGIBILITY,
        &RETIRE_HORSE_HANDLER,
        &COMPUTE_HORSE_PRICE,
        &CRISPR_LAB,
        &BREEDING,
        &SAVE_WRITER,
        &LOAD_GAME,
        &DRAW_PAUSE_STATUS,
        &TMX_MAP_PARSER,
        &POP_GENOME_BUILDER,
        &DAILY_HORSE_EVENT,
        &TRACK_STATE_MACHINE,
        &CIRCUS_HANDLER,
        &SUMO_HANDLER,
        &POWER_PLANT,
        &WORLD_ACTION,
        &BALLOON_CONTROLLER,
        &HORSE_CONSTRUCTOR,
        &HORSE_DESTRUCTOR,
        &GENE_COMBINATOR,
        &HORSE_SAVE_WRITER,
        &HORSE_SAVE_LOADER,
    ],
);

/// Per-process Resolver singleton bound to `HORSEY_TARGETS`.
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
        // Smoke-test a representative subset across kinds.
        assert!(HORSEY_TARGETS.def("GAMESTATE_PTR").is_some());
        assert!(HORSEY_TARGETS.def("NAME_TABLE").is_some());
        assert!(HORSEY_TARGETS.def("APPLY_GENE_TO_HORSE").is_some());
        assert!(HORSEY_TARGETS.def("HORSE_REBUILD").is_some());
        assert!(HORSEY_TARGETS.def("RNG_NEXT_MODULO").is_some());
        assert!(HORSEY_TARGETS.def("GENE_COMBINATOR").is_some());
        assert!(HORSEY_TARGETS.def("HORSE_SAVE_LOADER").is_some());
        assert!(HORSEY_TARGETS.def("DEFINITELY_MISSING").is_none());
    }

    #[test]
    fn registry_includes_invocable_signatures() {
        // Targets with `signature: Some(_)` are vanilla-invocable.
        let invocable: Vec<&'static str> = HORSEY_TARGETS.iter()
            .filter_map(|d| match d.kind {
                TargetKind::FunctionEntry { signature: Some(_) } => Some(d.name),
                _ => None,
            })
            .collect();
        assert!(invocable.contains(&"APPLY_GENE_TO_HORSE"));
        assert!(invocable.contains(&"HORSE_REBUILD"));
        assert!(invocable.contains(&"RNG_NEXT_MODULO"));
        assert!(invocable.contains(&"HORSE_COPY_GENE_LANE_PAIRS"));
        assert_eq!(invocable.len(), 4);
    }

    #[test]
    fn registry_target_count() {
        // Sanity that we declared what we think we did.
        // 7 data globals + 4 invocable functions + 30 hint-only
        // function entries = 41 total.
        assert_eq!(HORSEY_TARGETS.entries.len(), 41);
    }
}
