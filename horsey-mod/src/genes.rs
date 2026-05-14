//! Extended-gene state for the bestiary expansion mod.
//!
//! Per the D0..D9 plan in `horsey-mod/docs/todo.md`, extending the
//! engine's gene capacity from 240 to 480 means storing the extended
//! state in our own buffers (the design principle: layer on top of
//! vanilla, never modify vanilla data). This module owns all three
//! sidecar buffers:
//!
//! - `EXT_GENE_TABLE`: definitions for genes 240..(240 + EXT_GENE_COUNT)
//! - `EXT_POP_WEIGHTS`: per-pop allele weights for those extended genes
//! - `EXT_HORSE_GENOMES`: per-horse diploid alleles for those extended genes
//!
//! The vanilla side remains at `DAT_1403ee4a4` (gene table), per-pop
//! `DAT_1403f2fc0 + pop_id * 0x1018` (pop records), and `horse[0x78]`
//! (per-horse 480-byte genome). We never write into those addresses
//! through this module.
//!
//! See `horsey-mod/docs/ALLELE-MODEL.md` for the engine model these
//! buffers mirror.

use parking_lot::RwLock;
use serde::{Deserialize, Serialize};
use std::collections::HashMap;
use std::sync::OnceLock;

/// Extended gene count. Vanilla has 240 slots (`DAT_1403ee4a4` at
/// offsets [0..240) with 32-byte stride). We add this many MORE
/// slots in our own table, indexed [240..240+EXT_GENE_COUNT).
///
/// Default 240 = exactly double. The patch surface does not change
/// if we pick a higher number (e.g. 512, 1024); the cost is just
/// more heap. We keep 240 for v1 to make the math obvious.
pub const EXT_GENE_COUNT: usize = 240;

/// Total gene count (vanilla + extended).
pub const TOTAL_GENE_COUNT: usize = 240 + EXT_GENE_COUNT;

/// Default mutation rate for an unauthored gene. Matches the vanilla
/// loader's default at `FUN_1400a3eb0:44`.
pub const DEFAULT_MUTATION_RATE: u32 = 100;

/// Default scale. Matches `FUN_1400a3eb0:45`.
pub const DEFAULT_SCALE: u64 = 1;

/// Mirrors the vanilla 32-byte gene table record. We keep the layout
/// identical to the vanilla one so any future shared serializer code
/// can treat both sides interchangeably.
///
/// Vanilla layout (per `ALLELE-MODEL.md` and `FUN_1400a5d20:24`'s
/// self-check):
/// - +0x00 uint32 index    (must equal slot index)
/// - +0x04 uint32 m        (mutation rate, default 100)
/// - +0x08 uint64 s        (scale, default 1)
/// - +0x10 4 x uint32      (alleles g0..g3)
/// - +0x20 (next record)
#[derive(Clone, Debug, Serialize, Deserialize)]
pub struct ExtGene {
    /// User-facing name as it would appear in `genes-extended.xml`,
    /// e.g. `BX_WING_SIZE`. Vanilla genes are indexed by name in the
    /// chromomap; we mirror that for the extended set.
    pub name: String,

    /// Mutation rate (vanilla `m` field). Range typically 0..255.
    pub mutation_rate: u32,

    /// Scale (vanilla `s` field). Vanilla default is 1; non-default
    /// values change how the diploid blend formula scales.
    pub scale: u64,

    /// The four allele payload values. Per `FUN_1400a5d20`'s blend
    /// formula, allele index 0..3 selects which of these is used as
    /// the dominant or recessive contribution.
    pub alleles: [u32; 4],

    /// Render-output mapping. Tells the D5 trampoline which
    /// `param_1[N]` slot to write to and how. Optional: unset means
    /// the gene's value is computed and stored but produces no
    /// visible effect (useful for breeding-only traits).
    #[serde(default)]
    pub render: Option<RenderMapping>,
}

/// How an extended gene's evaluated value should be applied to the
/// per-horse render parameter array. Authored alongside the gene in
/// `genes-extended.xml`.
#[derive(Clone, Debug, Serialize, Deserialize)]
pub struct RenderMapping {
    /// `param_1[N]` slot index (0..352 from Q-render-2).
    pub slot: u32,

    /// How to apply the value to the slot.
    pub mode: RenderMode,
}

#[derive(Copy, Clone, Debug, Serialize, Deserialize, PartialEq)]
#[serde(rename_all = "snake_case")]
pub enum RenderMode {
    /// Add the gene's evaluated value to whatever vanilla wrote.
    Add,
    /// Multiply the slot by the gene's value.
    Mul,
    /// Override the slot regardless of vanilla.
    Set,
}

impl ExtGene {
    /// Default-initialize an extended gene. Used when a slot is
    /// touched without an explicit `genes-extended.xml` definition,
    /// or when a save loads with more authored genes than the
    /// running mod knows about.
    pub fn default_named(name: impl Into<String>) -> Self {
        Self {
            name: name.into(),
            mutation_rate: DEFAULT_MUTATION_RATE,
            scale: DEFAULT_SCALE,
            alleles: [0, 0, 0, 0],
            render: None,
        }
    }
}

/// Per-pop extended weights. One entry per gene in the extended
/// range, with 4 weights (one per allele).
///
/// Mirrors the vanilla per-pop weight layout at offset `+0x28`
/// of the pop record, just for the extended range.
#[derive(Clone, Debug, Serialize, Deserialize)]
pub struct ExtPopWeights {
    /// `[gene_idx_within_ext][allele_idx]` = inverse weight.
    /// Inverse means lower number = more likely (matches vanilla).
    pub weights: Vec<[u32; 4]>,
}

impl ExtPopWeights {
    pub fn default_for_count(n: usize) -> Self {
        Self {
            weights: vec![[1, 1, 1, 1]; n],
        }
    }
}

/// Per-horse extended diploid genome. Two allele indices per gene,
/// stored in the same i / i+EXT_GENE_COUNT layout that vanilla uses
/// for its 480-byte block at `horse[0x78]`. Each allele index is
/// 0..3 (which of the 4 allele payloads on this gene to use).
///
/// Stored as a flat `Vec<u8>` of length `2 * EXT_GENE_COUNT`.
#[derive(Clone, Debug, Serialize, Deserialize)]
pub struct ExtHorseGenome {
    pub alleles: Vec<u8>,
}

impl ExtHorseGenome {
    pub fn empty() -> Self {
        Self {
            alleles: vec![0; 2 * EXT_GENE_COUNT],
        }
    }
}

// =============================================================================
// State (the three sidecar buffers)
// =============================================================================

/// Extended gene table. `Vec` indexed [0..EXT_GENE_COUNT). To get
/// the vanilla-equivalent gene index, add 240.
fn gene_table() -> &'static RwLock<Vec<ExtGene>> {
    static T: OnceLock<RwLock<Vec<ExtGene>>> = OnceLock::new();
    T.get_or_init(|| {
        let mut v = Vec::with_capacity(EXT_GENE_COUNT);
        for i in 0..EXT_GENE_COUNT {
            v.push(ExtGene::default_named(format!("BX_RESERVED_{i:03}")));
        }
        RwLock::new(v)
    })
}

/// Per-pop extended weights. Keyed by vanilla pop_id (the same
/// `pop_id` field stored at offset 0 in vanilla pop records).
fn pop_weights() -> &'static RwLock<HashMap<u32, ExtPopWeights>> {
    static T: OnceLock<RwLock<HashMap<u32, ExtPopWeights>>> = OnceLock::new();
    T.get_or_init(|| RwLock::new(HashMap::new()))
}

/// Per-horse extended genomes. Keyed by horse_id. The stable horse
/// identifier is open (D4.4 in todo); for now we accept whatever the
/// caller provides as a u64 key.
fn horse_genomes() -> &'static RwLock<HashMap<u64, ExtHorseGenome>> {
    static T: OnceLock<RwLock<HashMap<u64, ExtHorseGenome>>> = OnceLock::new();
    T.get_or_init(|| RwLock::new(HashMap::new()))
}

// =============================================================================
// Gene table accessors
// =============================================================================

/// Read an extended gene by extended-range index (0..EXT_GENE_COUNT).
pub fn get_ext_gene(ext_idx: usize) -> Option<ExtGene> {
    gene_table().read().get(ext_idx).cloned()
}

/// Read an extended gene by full-range index (240..TOTAL_GENE_COUNT).
/// Returns None for vanilla indices and out-of-range.
pub fn get_gene_by_total_idx(total_idx: usize) -> Option<ExtGene> {
    if total_idx < 240 || total_idx >= TOTAL_GENE_COUNT {
        return None;
    }
    get_ext_gene(total_idx - 240)
}

/// Set an extended gene's full definition. Returns the previous
/// value if the slot was already populated.
pub fn set_ext_gene(ext_idx: usize, gene: ExtGene) -> Option<ExtGene> {
    let mut t = gene_table().write();
    if ext_idx >= t.len() {
        return None;
    }
    let old = t[ext_idx].clone();
    t[ext_idx] = gene;
    Some(old)
}

/// List all extended genes (snapshot copy).
pub fn list_ext_genes() -> Vec<ExtGene> {
    gene_table().read().clone()
}

/// Look up an extended gene by name. Returns the extended-range
/// index AND the gene record. None if no extended gene has this
/// name.
pub fn find_ext_gene_by_name(name: &str) -> Option<(usize, ExtGene)> {
    gene_table()
        .read()
        .iter()
        .enumerate()
        .find(|(_, g)| g.name == name)
        .map(|(i, g)| (i, g.clone()))
}

// =============================================================================
// Per-pop weight accessors
// =============================================================================

/// Get a pop's extended weights. Auto-initializes to defaults if
/// not yet seen.
pub fn get_or_init_pop_weights(pop_id: u32) -> ExtPopWeights {
    let mut w = pop_weights().write();
    w.entry(pop_id)
        .or_insert_with(|| ExtPopWeights::default_for_count(EXT_GENE_COUNT))
        .clone()
}

/// Set a single allele weight for a pop's extended gene.
/// `ext_gene_idx` is in [0..EXT_GENE_COUNT). `allele_idx` is in [0..4).
pub fn set_pop_ext_weight(
    pop_id: u32,
    ext_gene_idx: usize,
    allele_idx: usize,
    weight: u32,
) -> Result<(), String> {
    if ext_gene_idx >= EXT_GENE_COUNT {
        return Err(format!(
            "ext_gene_idx {ext_gene_idx} out of range (max {})",
            EXT_GENE_COUNT - 1
        ));
    }
    if allele_idx >= 4 {
        return Err(format!("allele_idx {allele_idx} out of range (max 3)"));
    }
    let mut w = pop_weights().write();
    let entry = w
        .entry(pop_id)
        .or_insert_with(|| ExtPopWeights::default_for_count(EXT_GENE_COUNT));
    entry.weights[ext_gene_idx][allele_idx] = weight;
    Ok(())
}

/// List every pop_id with extended weights and their full weight
/// matrices. Sorted by pop_id ascending.
pub fn list_pop_ext_weights() -> Vec<(u32, ExtPopWeights)> {
    let mut v: Vec<_> = pop_weights()
        .read()
        .iter()
        .map(|(k, v)| (*k, v.clone()))
        .collect();
    v.sort_by_key(|(k, _)| *k);
    v
}

// =============================================================================
// Per-horse genome accessors
// =============================================================================

/// Read a horse's full extended genome. None if no entry exists.
pub fn get_horse_ext_genome(horse_id: u64) -> Option<ExtHorseGenome> {
    horse_genomes().read().get(&horse_id).cloned()
}

/// Set a horse's full extended genome.
pub fn set_horse_ext_genome(horse_id: u64, genome: ExtHorseGenome) {
    horse_genomes().write().insert(horse_id, genome);
}

/// Drop a horse's extended genome (call from D3.2 detour when the
/// vanilla 480-byte block is freed).
pub fn drop_horse_ext_genome(horse_id: u64) -> bool {
    horse_genomes().write().remove(&horse_id).is_some()
}

/// Read both diploid alleles for a specific extended gene of a
/// specific horse. Returns (maternal, paternal) allele indices each
/// in [0..3], or None if the horse has no extended genome.
pub fn get_horse_ext_alleles(horse_id: u64, ext_gene_idx: usize) -> Option<(u8, u8)> {
    if ext_gene_idx >= EXT_GENE_COUNT {
        return None;
    }
    let g = horse_genomes().read();
    let genome = g.get(&horse_id)?;
    let m = genome.alleles[ext_gene_idx] & 0x3;
    let p = genome.alleles[ext_gene_idx + EXT_GENE_COUNT] & 0x3;
    Some((m, p))
}

/// Set the diploid allele pair for one extended gene of one horse.
/// Auto-initializes the horse's extended genome if not present.
pub fn set_horse_ext_alleles(
    horse_id: u64,
    ext_gene_idx: usize,
    maternal: u8,
    paternal: u8,
) -> Result<(), String> {
    if ext_gene_idx >= EXT_GENE_COUNT {
        return Err(format!(
            "ext_gene_idx {ext_gene_idx} out of range (max {})",
            EXT_GENE_COUNT - 1
        ));
    }
    if maternal > 3 || paternal > 3 {
        return Err("alleles must be 0..3".into());
    }
    let mut g = horse_genomes().write();
    let genome = g.entry(horse_id).or_insert_with(ExtHorseGenome::empty);
    genome.alleles[ext_gene_idx] = maternal & 0x3;
    genome.alleles[ext_gene_idx + EXT_GENE_COUNT] = paternal & 0x3;
    Ok(())
}

/// List every horse_id with an extended genome.
pub fn list_horse_genome_ids() -> Vec<u64> {
    let mut v: Vec<_> = horse_genomes().read().keys().copied().collect();
    v.sort();
    v
}

// =============================================================================
// Diploid evaluator (mirrors FUN_1400a5d20 for the extended range)
// =============================================================================

/// Evaluate an extended gene's effect for a specific horse. Mirrors
/// the math of `FUN_1400a5d20` but reads from our sidecar buffers.
///
/// Returns 0.0 if the horse has no extended genome OR the gene is
/// out of range. The D5 trampoline calls this for every extended
/// gene per horse per call to FUN_14009f680.
pub fn evaluate_ext_gene(horse_id: u64, ext_gene_idx: usize) -> f32 {
    let Some(gene) = get_ext_gene(ext_gene_idx) else {
        return 0.0;
    };
    let Some((m_allele, p_allele)) = get_horse_ext_alleles(horse_id, ext_gene_idx) else {
        return 0.0;
    };
    let dom_idx = m_allele.max(p_allele) as usize;
    let rec_idx = m_allele.min(p_allele) as usize;
    let dom_value = gene.alleles[dom_idx] as f32;
    let rec_value = gene.alleles[rec_idx] as f32;
    let m = gene.mutation_rate as f32;
    let s = gene.scale as f32;
    // Vanilla blend constants DAT_14039ca44 and DAT_14039ca5c are
    // not yet documented (open question). For now we use the
    // simplest interpretation: m/s in [0,1] is the recessive
    // contribution weight, (1 - m/s) is the dominant. With vanilla
    // m=100, s=1, this gives 100/1 = 100 -> clamped to 1.0.
    let recessive_weight = (m / s.max(1e-6)).clamp(0.0, 1.0);
    let dominant_weight = 1.0 - recessive_weight;
    dominant_weight * dom_value + recessive_weight * rec_value
}

// =============================================================================
// JSON snapshot (for HTTP dump op)
// =============================================================================

/// Full snapshot of every extended-gene buffer. Used by the
/// `genes.ext.dump` HTTP op.
#[derive(Serialize)]
pub struct ExtSnapshot {
    pub ext_gene_count: usize,
    pub total_gene_count: usize,
    pub genes: Vec<ExtGene>,
    pub pop_weights: HashMap<String, ExtPopWeights>,
    pub horse_genome_count: usize,
    pub horse_ids: Vec<u64>,
}

pub fn snapshot() -> ExtSnapshot {
    let pops: HashMap<String, ExtPopWeights> = pop_weights()
        .read()
        .iter()
        .map(|(k, v)| (k.to_string(), v.clone()))
        .collect();
    let horse_ids: Vec<u64> = list_horse_genome_ids();
    ExtSnapshot {
        ext_gene_count: EXT_GENE_COUNT,
        total_gene_count: TOTAL_GENE_COUNT,
        genes: list_ext_genes(),
        pop_weights: pops,
        horse_genome_count: horse_ids.len(),
        horse_ids,
    }
}

/// Test-only: reset every sidecar buffer so tests that mutate
/// global state can run independently. Production code never calls
/// this. Keeps the table at vanilla defaults.
#[cfg(test)]
pub fn reset_all_for_tests() {
    let mut t = gene_table().write();
    t.clear();
    for i in 0..EXT_GENE_COUNT {
        t.push(ExtGene::default_named(format!("BX_RESERVED_{i:03}")));
    }
    drop(t);
    pop_weights().write().clear();
    horse_genomes().write().clear();
}

/// Test-only mutex serializing every test that touches global gene
/// state. Hold for the entire test body. Without it, parallel tests
/// pollute each other and assertions about `set_ext_gene` /
/// `set_horse_ext_alleles` outcomes are unreliable.
#[cfg(test)]
pub static TEST_LOCK: parking_lot::Mutex<()> = parking_lot::Mutex::new(());

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn default_table_has_ext_gene_count_entries() {
        let _g = TEST_LOCK.lock();
        reset_all_for_tests();
        assert_eq!(list_ext_genes().len(), EXT_GENE_COUNT);
    }

    #[test]
    fn set_then_get_ext_gene() {
        let _g = TEST_LOCK.lock();
        reset_all_for_tests();
        let g = ExtGene {
            name: "TEST_GENE".into(),
            mutation_rate: 50,
            scale: 1,
            alleles: [10, 20, 30, 40],
            render: Some(RenderMapping {
                slot: 99,
                mode: RenderMode::Add,
            }),
        };
        set_ext_gene(0, g.clone());
        let back = get_ext_gene(0).unwrap();
        assert_eq!(back.name, "TEST_GENE");
        assert_eq!(back.alleles, [10, 20, 30, 40]);
    }

    #[test]
    fn pop_weights_default_to_ones() {
        let _g = TEST_LOCK.lock();
        reset_all_for_tests();
        let w = get_or_init_pop_weights(42);
        assert_eq!(w.weights.len(), EXT_GENE_COUNT);
        assert_eq!(w.weights[0], [1, 1, 1, 1]);
    }

    #[test]
    fn horse_genome_diploid_layout() {
        let _g = TEST_LOCK.lock();
        reset_all_for_tests();
        set_horse_ext_alleles(7, 5, 2, 3).unwrap();
        let (m, p) = get_horse_ext_alleles(7, 5).unwrap();
        assert_eq!((m, p), (2, 3));
    }

    #[test]
    fn evaluate_homozygous() {
        let _g = TEST_LOCK.lock();
        reset_all_for_tests();
        let g = ExtGene {
            name: "T".into(),
            mutation_rate: 100,
            scale: 1,
            alleles: [10, 20, 30, 80],
            render: None,
        };
        set_ext_gene(0, g);
        set_horse_ext_alleles(1, 0, 3, 3).unwrap();
        // Homozygous 3,3: dom = rec = 80. Blend math doesn't matter.
        assert_eq!(evaluate_ext_gene(1, 0), 80.0);
    }

    #[test]
    fn evaluate_no_horse_genome_returns_zero() {
        let _g = TEST_LOCK.lock();
        reset_all_for_tests();
        assert_eq!(evaluate_ext_gene(99999, 0), 0.0);
    }
}
