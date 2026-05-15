# save1.dat - format notes
> **Authoritative on:** format notes for save1.dat (partial; static-analysis pass).

Live save dumped 2026-05-13. Total size 245,151 bytes.

All findings are from static analysis. Field meanings are HYPOTHESES until confirmed by a byte-diff experiment between two known-different saves.

## Table of contents

- [File map (high level)](#file-map-high-level)
- [Header (first 20 bytes)](#header-first-20-bytes)
- [Horse roster record (verified by walking)](#horse-roster-record-verified-by-walking)
- [Open work](#open-work)
- [Tools](#tools)
- [Findings from prior-art `alexjthomson/horsey-save-editor`](#findings-from-prior-art-alexjthomsonhorsey-save-editor)

---

## File map (high level)

| Range | Size | Confidence | Content |
|---|---|---|---|
| 0x0000..0x0014 | 20 B | medium | Header (5 uint32s) |
| 0x0014..0x0c6f | 3,163 B | high | Horse roster: 85 records |
| 0x0c6f..0x0d4f | ~224 B | low | Looks like more named records (ribbons/champions?) - records named "Meteor", "Participation Award", "Vapid Transit", "Willgo", "Buffalo" with horse-roster-shaped fields |
| 0x0d4f..0x0e3e4 | 54,933 B | low | Large binary block. Contains float values and 0x3f800000 (=1.0f) patterns. Possibly world state / positions / per-horse genome. Roughly 76*720 = 54720 bytes if it's "one genome per horse" - but the math is fuzzy. |
| 0x0e3e4..end | 187,963 B | none | Sparse strings ("unknown", short fragments). Mostly binary with float values that look like positions. Probably tile state, gene drives, item placements, money, calendar. |

Roster + champion block = 1.2% of file. The remaining 98.8% is whatever the in-game world state is.

## Header (first 20 bytes)

| Offset | Bytes | Value | Hypothesis |
|---|---|---|---|
| 0x00 | 0c 00 00 00 | 12 | Save format version |
| 0x04 | fd b9 1b 62 | 1645984253 | Unix timestamp (Feb 27 2022) - either save creation time or world seed |
| 0x08 | 00 00 00 00 | 0 | Unknown (zero) |
| 0x0c | 32 00 00 00 | 50 | Unknown - could be max horse capacity, current year, or current channel |
| 0x10 | 5d 00 00 00 | 93 | Unknown - could be next-horse-id counter or total-horses-ever |

Note: 93 != 85 (record count). So this field is NOT just "active horse count". Could be "next ID to assign" or "total horses ever created including dead/sold".

## Horse roster record (verified by walking)

Variable size, minimum 26 bytes. Layout per record:

```
struct HorseRecord {
    uint32  name_length;
    char    name[name_length];           // UTF-8, no trailing null included in length
    uint8   flag_a;                      // 0 in samples (sex? sex-male?)
    uint8   flag_b;                      // varies (color/pattern/breed sub-id?)
    uint8   flag_c;                      // varies
    uint8   flag_d;                      // varies
    uint8   flag_e;                      // 0 in samples
    uint8   pop_id;                      // 1..255: which population the horse belongs to
    int32   parent_a;                    // -1 if no parent (wild-spawn)
    int32   parent_b;                    // -1 if no parent
    uint32  unknown1;                    // 0 in all samples
    uint32  child_count;                 // 0..N
    int32   child_ids[child_count];      // IDs of offspring
}
```

### What's CONFIRMED about this struct

- Name is length-prefixed UTF-8. We've successfully parsed names with non-ASCII chars (e.g. "Señor Borde...").
- The 22-byte trailer is consistent across 85 records.
- `child_count` matches the variable-length tail of child IDs.
- Records with parents (e.g. "Whirlwind Romance" has p1=2, p2=3) cross-reference earlier record indices.

### What's STILL UNKNOWN

- **What flag_a..flag_e actually encode.** Could be sex, gender-marker, pregnant state, current location, breed sub-type, color. We do NOT know.
- **Whether the genome lives in this record.** It doesn't - the record is too small. 22 fixed bytes leaves no room for 200+ allele values.
- **Whether age/fatigue/hunger are here.** They're not visible in the 22-byte trailer. Likely stored in one of the big binary blocks.

### The pop_id field looks real

Observed values: 1, 2, 3, 4, 5, 7, 12, 255. From `pop.xml`, the populations in order are: default, scratch, fest horse, crazy horse, impala, alligator, giraffe, rabbit, duck, dino, centipede, tiger, moose, dachshund, bear, cow, human, centaur test, jockey, leprechaun, pepper, car, appletree, yeast, hay, fish, helix, freak.

If we number them 0..N (or 1..N), 1=default fits "Dale" being an ordinary horse, and 12=moose or similar fits a weird horse. 255 looks like a sentinel for "freak" or "custom". Worth testing.

## Open work

Action items (find fatigue/age fields, identify genome location, confirm pop_id mapping, run save-diff experiments) are tracked in [`todo.md`](todo.md#save-format-research).

## Tools

- `parse_save.py` (in this folder): walks the roster and dumps blocks. Read-only.

## Findings from prior-art `alexjthomson/horsey-save-editor`

Independent save-file reverse-engineering. Cross-validates and extends the static-analysis pass above. Source: [alexjthomson/horsey-save-editor](https://github.com/alexjthomson/horsey-save-editor), pure HTML/JS browser-side editor.

### Header (confirmed)

20-byte (0x14) header. Layout: `u32 / u64 / u32 / u32`; the **horse count** lives at offset `+0x10` (32-bit unsigned). Roster table starts at offset `+0x14`.

### Diploid genome encoding (NEW)

Per-gene the save stores **one byte per diploid pair**. The byte is computed as `byte = 0x09 + rank(second_strand_base) * 8 + rank(first_strand_base)` where the base ranks differ per gene (a per-gene table picks the rank assignment so the codon-order `n` attribute lines up with which integer index 0..3 is which base).

Example pair-to-byte table for a gene whose rank is `{A: 0, C: 3, G: 2, T: 1}`:

| Pair | Byte | Pair | Byte | Pair | Byte | Pair | Byte |
|---|---|---|---|---|---|---|---|
| AA | 09 | CA | 0c | GA | 0b | TA | 0a |
| AC | 21 | CC | 24 | GC | 23 | TC | 22 |
| AG | 19 | CG | 1c | GG | 1b | TG | 1a |
| AT | 11 | CT | 14 | GT | 13 | TT | 12 |

The save-editor JSON `raw_indices` (line 4028 of `index.html`) carries per-gene rank assignments derived from the genes.xml `n` codon-order attribute. The 16 homozygous + 16 heterozygous combinations land at deterministic byte values.

### Horse flag-bits enum (NEW)

The save-editor decodes a flag byte per horse with these bits:

| Bit | Meaning |
|---|---|
| 0x01 | Unknown |
| 0x02 | Championship Horse |
| 0x04 | GMO Horse (CRISPR-edited) |
| 0x08 | Won Diving Medal |
| 0x10 | Won Strong Horse Medal |
| 0x20 | Won Trampoline Medal |
| 0x40 | Won Acrobat Medal |
| 0x80 | Unknown |

Two flag bits are still unknown. Worth diff-testing.

### Money location (cross-check)

The save-editor reads money at `tableEnd + 0x14` where `tableEnd` is after the roster table. Our decomp pass found the runtime money at `gamestate+0x308`. These are different views: their offset is into `save1.dat`, ours is into the `DAT_1403fb0d8` live struct. Both correct in context.

### Implications

- The genome storage we couldn't fit in the 22-byte horse-roster trailer is one byte per gene, encoded via the rank-formula, stored elsewhere in the file (likely the 55KB block our static pass identified).
- The CRISPR Lab UI (helix display) maps directly to these bytes: each helix position is one diploid byte; the player sees the pair of bases and edits one strand at a time.
- The flag-bits enum decodes part of `flag_a..flag_e` in our 22-byte trailer. Bit 0x02 (Championship) and 0x04 (GMO Horse) line up with achievements we can validate in-game.

## Save pipeline functions (resolved 2026-05-15)

The save / load code path is decomposed across four functions, all reachable from the top-level save / load drivers. Patches must hook at the per-horse level so a `.ext` sidecar can be emitted / consumed in the same iteration order as vanilla.

| Function | RVA (Ghidra) | Role |
|---|---|---|
| `FUN_14006d610` | `0x14006d610` | Roster save driver. Iterates `gamestate[+0x130]` `std::vector<Horse*>` and calls the per-horse writer for each entry. |
| `FUN_14006ee10` | `0x14006ee10` | Per-horse save writer. Calls `FUN_14006d470(horse + 0x2b8)` to pack the 480-byte genome to 240 bytes (3-bit-per-allele encoding). Writes ~12 other small fields (`name_id`, `age`, flag bits, etc.) inline. |
| `FUN_14006d470` | `0x14006d470` | Per-genome packer. Reads from `horse + 0x2b8`, emits 240 packed bytes. |
| `FUN_14006f150` | `0x14006f150` | Per-horse save loader. Calls `FUN_14006d580(horse + 0x2b8)` to unpack the 240 bytes back into the inline genome, then `FUN_1400b3070(horse)` to regenerate derived render fields by re-running engine + consumer. |
| `FUN_14006d580` | `0x14006d580` | Per-genome unpacker (mirror of `FUN_14006d470`). |
| `FUN_1400b3070` | `0x1400b3070` | "Rebuild equipment and physics". Derived-state regen called at end of per-horse load + at every CRISPR / regen event. Our D1 + D5 detours fire during this regen, so if `EXT_HORSE_GENOMES` is populated BEFORE `FUN_14006f150` calls it, ext alleles are auto-applied to the render buf. |

Roster save / load order is **`gamestate[+0x130]` vector position**. The sidecar serializes per-horse records in the same order; positional index is the de facto stable horse id.

## Horse-id field (D4.4 finding): there isn't one

Investigated 2026-05-15. No dedicated `horse_id` int32 exists on the horse struct. The fields surveyed:

- `horse[+0xc]` = `pop_id` (verified: `FUN_14005cf70` indexes pop names "pepper" / "yeast" etc. by this field; `FUN_14005cf50` indexes a 0x58-stride table by it).
- `horse[+0x18]` = increment counter (e.g. `FUN_14005d480` does `*(int*)(h + 0x18) += 1`). Used for state ticks, not a stable id.
- `horse[+0x40]` = genome hash (`FUN_14005d360` computes a deterministic hash of the genome bytes for freak pops; not an assigned id).
- `horse[+0x78]` = pop-seed genome blob (480 bytes; allocated by `FUN_14005cf70`, populated from pop initial-allele weights).

Roster lives at `gamestate[+0x130]/+0x138` as a `std::vector<Horse*>` (stride 8). Per `FUN_1400c0660:112458-112470`.

Save header `+0x10` holds a "next id" counter (value 93 vs 85 active records), suggesting monotonic id issuance. But no horse-struct field surveyed so far stores it.

Save record `parent_a`/`parent_b`/`child_ids[]` are int32s; the SAVE-FORMAT.md notes ("Whirlwind Romance has p1=2, p2=3") describe them as cross-referencing **earlier record indices** in the roster, i.e. positional.

**Working hypothesis (locked):** Horsey uses roster-slot position as the stable id. The save's "next id" counter `93 > 85` is consistent with slots being retained-with-dead-flag (93 ever issued, 85 live, 8 retained / dead). Sidecar files reference horses by positional index in the same save-time iteration order; vanilla parent / child refs use the same indexing.

Open: confirm by save-diff experiment (kill a horse mid-save, observe whether the slot keeps existing or is removed). Until confirmed, treat the index as session-stable but sequence-fragile.

## Sidecar format `save<N>.dat.ext` (shipped 2026-05-15)

Per the "layer on top of vanilla" design principle (see [`VIABILITY.md`](VIABILITY.md) Q-save-3), vanilla save bytes are never modified. Extended state lives in a sibling sidecar.

Path: `save<N>.dat.ext` co-located with the vanilla save (game `save/` directory).

Binary layout (locked 2026-05-15):

```
magic[8]      = "BXSAVEXT"
version: u32  = 1
ext_count: u32  = EXT_GENE_COUNT (currently 240)
horse_count: u32  (back-patched at close)
per_horse_record[horse_count]:
    ext_alleles: u8[2 * EXT_GENE_COUNT]  (strand A then strand B; values 0..3)
payload_crc: u32  (CRC32 IEEE)
```

Dense records (every horse gets a full 2*EXT_GENE_COUNT byte block) per user direction; simple beats sparse-with-tag at this scale.

Implementation: `horsey-mod/src/patches/save_sidecar.rs` ships 4 detours, all registered as post-hooks via `retour::GenericDetour`:

| Detour | Target RVA | Role |
|---|---|---|
| `SAVE_WRITER` | `0x14006dc80` | Top-level save driver. **Address stale 2026-05-15** (the prologue at this RVA is mid-function code, not a function entry; needs re-derivation via pattern-scan). |
| `LOAD_GAME` | `0x14006e480` | Top-level load driver. **Same stale-address issue.** |
| `HORSE_SAVE_WRITER` | `0x14006ee10` | Per-horse serializer. **Stale.** |
| `HORSE_SAVE_LOADER` | `0x14006f150` | Per-horse deserializer. **Stale.** |

Sidecar I/O code is correct (the BXSAVEXT codec has 7 unit tests in `patches::save_sidecar::tests`, all green); only the address binding is broken. `genes.ext.save.arm` is UNSAFE TO ARM until the four addresses are re-derived via pattern-scan (see [`ADDRESS-RESOLUTION.md`](ADDRESS-RESOLUTION.md) R2). The failing harness test `dryrun_d3_d4::save_dryrun_prologues_ok` enforces this.

HTTP ops shipped (`horsey-mod/src/ops.rs`): `genes.ext.save.{dryrun,arm,disarm,stats}`.

Loader-side ordering: when the per-horse loader runs, we populate `EXT_HORSE_GENOMES[horse_ptr]` BEFORE the vanilla trampoline returns, so that vanilla's tail call to `FUN_1400b3070` (regen) reads the freshly-loaded ext alleles via the existing D1 + D5 detours. This means ext effects auto-apply on save / load without a second pass.

Save-uninstall policy (locked 2026-05-15): orphan `.ext` files left in place when horsey-mod is removed. They're inert without the DLL and reactivate cleanly on re-install.
