# Horse Places

Authoritative catalog of every memory location that holds horse pointers or horse records in Horsey Game. Built from `research/decompiled/all_functions.c` + `gamestate.scan_438_slots` live data + HLT prior art (`research/prior-art/HorseyLiveTweaks/src/core/offsets.h`).

There is NOT one single "owned horses" list. Horses are partitioned across many lists by purpose (owned, race-lane, scene, hovered, selected, pool). To answer "how many horses does the player own" you read the OWNED list. To answer "which horses are visible in this scene" you read the active scene's list. Mistakes here are why the Horses tab read 0/N for weeks.

## Quick map

| Location | Type | Stride | Contains | Source |
|---|---|---|---|---|
| `GS+0x280/+0x288` | std::vector range | 36 bytes | All-horse POOL (player + NPC + ancestors), inline summary records | decomp `:53951` |
| `GS+0x260/+0x268` | std::vector range | unknown | "Sim horses" (HLT `kOffSimHorsesBegin/End`) | HLT |
| `GS+0x25C` | i32 | n/a | active_scene_id, range `[-1, 256)` (-1 = overworld / no scene) | HLT `kRootActiveSceneId` |
| `GS+0x438` | ptr -> array of 256 sub-struct ptrs | 8 bytes per slot | Scene/subsystem table | HLT `kRootSceneTable` + decomp |
| `*(GS+0x438) + slot * 8`, then `+0x130/+0x138` | std::vector<Horse*> | 8 bytes (ptr) | Per-slot horse list, varies by slot | scan_438_slots |
| `horse_ptr+0x0` | qword | n/a | Horse object vtable | live mem dump |
| `horse_ptr+0x1f8` | u32 | n/a | name_id (indexes a global name table; the string is NOT inline) | r4 resolver + live dump |
| `horse_ptr+0x1fc` | i32 | n/a | age | r4 resolver |
| `horse_ptr+0x200` | i32 | n/a | max_age | derived `age+4` |
| `horse_ptr+0x205/+0x206` | u8 each | n/a | tired flags A/B | r4 resolver |
| `horse_ptr+0x21c` | i32 | n/a | skill | r4 resolver |
| `horse_ptr+0x254` | i32 | n/a | litter_size_stat | r4 resolver |
| `horse_ptr+0x498` | n/a | n/a | one allocation = HORSE_ALLOC_SIZE | r4 resolver |

## Scene-table slot inventory

`*(GS+0x438)` is an array indexed by 8-byte slot offset. Each non-empty slot points to a sub-struct with a `vector<Horse*>` at its `+0x130/+0x138`. Live snapshot from a 3-owned-horse save (`active_scene_id = -1`, overworld map):

| Slot offset | Count in observed save | Role | Decomp evidence |
|---|---|---|---|
| **0x00** | **3** | **Player-owned horses (the canonical "all owned" list).** Count is invariant across active_scene_id changes. | `gamestate.scan_438_slots` cross-checked against user's "I own 3 horses" |
| 0x08 | 5 | Race lane 0 | `FUN_140105260:155484` iterates 0x08..0x38 as 7 race lanes |
| 0x10 | 5 | Race lane 1 | same |
| 0x18 | 5 | Race lane 2 | same |
| 0x20 | 5 | Race lane 3 | same |
| 0x28 | 5 | Race lane 4 | same |
| 0x30 | 5 | Race lane 5 | same |
| 0x38 | 5 | Race lane 6 | same |
| 0x68 | 0 (empty) | unknown | reserved |
| 0x70 | 1 | Singleton: per-screen entity | observed |
| 0x78 | 1 | Singleton | observed |
| 0x80 | 1 | Singleton; referenced at `:155082` (`FUN_14009c780` call) | decomp |
| 0x88 | 1 | Singleton | observed |
| 0x90 | 1 | "Currently selected horse" subsystem. `FUN_140107510:156866-156869` reads its last entry when count > 1. `FUN_14010de40:160376` reads `+0x148` of this slot for the selected Horse*. | decomp |
| 0x98 | n/a | Object with vtable methods, init+release path. `:158597-158609` | decomp |
| 0xa0 | 1 | Singleton | observed |
| 0xa8 | 1 | Singleton | observed |
| 0xb0 | 4 | unknown | observed |
| 0xb8 | 1 | Singleton | observed |
| 0xc8 | 1 | Singleton | observed |
| 0xd0 | 3 | Mirror of owned? Same count as slot 0x00 in observed save. Could be "owned visible in current scene", or just a redundant pointer pair. Needs validation. | observed |
| 0xd8 | 1 | Singleton; `:160747` reads it | decomp |
| 0xe0 | 2 | unknown; `:64392` reads `(+0xe0)+0x260` as int | decomp |
| 0xe8 | 0 (empty) | unknown | reserved |
| 0xf8 | 1 | Singleton; `:160355` reads | decomp |
| 0x120 | 5 | "Copy all horses" source per `FUN_140107550:156885`. Likely race-roster or current-event roster, NOT canonical owned. Was a wrong guess earlier in this investigation. | decomp |
| 0x128 | 0 (empty) | unknown | reserved |
| 0x1c8 | 0 (empty) | unknown | reserved |

Slot offsets we have NOT observed yet but the decomp accesses: 0x40, 0x48, 0x50, 0x58, 0x60 (between race lanes 0x38 and 0x68 there are 5 unobserved slots), 0xc0, 0xe8, 0x100, 0x108, 0x110, 0x118.

## Notes on each location

### Roster pool at `GS+0x280/+0x288` (stride 0x24 = 36 bytes)

The ALL-HORSE registry. 28-29 entries in saves we've observed (vs 3 owned). Includes NPCs, ancestors, named horses ever encountered. Entries are NOT Horse object pointers; they are inline 36-byte summary records:

```
+0x00..+0x03: u32 = 0 (padding / pre-id)
+0x04..+0x07: u32 = id (0xdf..0x14b range observed; not unique across entries)
+0x08..+0x0b: u32 = (age-like, range 0x14..0x2f)
+0x0c..+0x0f: u32 = small flag (0, 1, or 2)
+0x10..+0x13: u32 = ~0x1d0..0x1f0 range (birth-year? generation?)
+0x14..+0x23: zero / padding
```

Walking this gives you the global horse universe, not the player's horses. Use this when you need to enumerate every horse the game knows about (e.g. naming, lineage).

### Scene table at `GS+0x438`

Heterogeneous registry of sub-systems. Per HLT it's "scene table" indexed by `active_scene_id`, but our scan shows slots that are clearly NOT scenes (race lanes at 0x08-0x38, owned list at 0x00). It's more like a service locator: each slot is a sub-system that happens to hold one or more horse references at the per-sub-struct offset `+0x130/+0x138`.

When `active_scene_id` is in `[0, 256)`, byte offset `active_scene_id * 8` gives you the active SCENE's horse list. When `active_scene_id = -1` (overworld), there is no active scene, but slot 0x00 (owned) is still populated.

### Slot 0x00 = owned horses

Confirmed by matching count to the user's known "I own 3 horses" assertion in two separate saves. This is the global owned list. Use it for the Horses tab.

Caveat: each horse in this list is a `Horse*` (8-byte pointer to the heap-allocated Horse object). The vector's `begin/end` semantics are standard libstdc++ / MSVC std::vector layout: `end - begin` divided by 8 = count.

### Slot 0x90 = "selected horse" subsystem

`FUN_140107510` returns `*(end - 8)` of slot 0x90's vector, but only when count > 1. So it's NOT a count returning function; it returns "second-most-recent entry of the selected list" or similar. Combined with `FUN_14010de40` reading slot 0x90 then dereferencing `+0x148`, slot 0x90 looks like a "current race / selected horse context" with both a vector and a singleton pointer.

### Race lanes at slots 0x08..0x38

`FUN_140105260:155460-155649` iterates these 7 slots in a fixed sequence, calling `FUN_1400c6580(count-1)` (random selection) for each. Each slot is one race lane / starting position. Each lane has up to ~5 horses queued.

The iterator at the bottom of `FUN_140105260` (line 155637-155641) walks `8..0x39` (slot offsets 8, 0x10, 0x18, 0x20, 0x28, 0x30, 0x38) in a loop calling `FUN_1400df280(*(slot), 1)`. Confirms race-lane semantic.

### Slot 0x120 = race roster source

`FUN_140107550:156885` reads the vector at slot 0x120 and COPIES it into an out-param. Caller at `:31599` is a race-setup function (writes results into a race context struct). Slot 0x120 is the "horses available for THIS race" source, not the player's all-owned set.

Note: this was a wrong guess earlier in this investigation. We tried slot 0x120 first because the function "copies all horses". Wrong: it copies all RACE horses for the current race setup. Real all-owned is slot 0x00.

## Reading horse fields

Once you have a `Horse*`:

```rust
let age: i32     = read_i32(horse + 0x1fc);
let max_age: i32 = read_i32(horse + 0x200);
let tired_a: u8  = read_u8 (horse + 0x205);
let tired_b: u8  = read_u8 (horse + 0x206);
let skill: i32   = read_i32(horse + 0x21c);
let litter: i32  = read_i32(horse + 0x254);
let name_id: u32 = read_u32(horse + 0x1f8);
```

The full Horse object is `HORSE_ALLOC_SIZE = 0x498` bytes. First qword is the vtable (we observed `0x7ff6ff68d750` in one run = a code address). The fields above are scattered through the body.

## Vanilla genome: DIPLOID, two banks of 240 bytes

Confirmed 2026-05-16 via the CRISPR apply function (`FUN_1400b39b0` at 0x1400b39b0) and the `tests/probe_paired_genome.rs` probe.

```
horse + 0x2b8 .. horse + 0x3a7   PRIMARY bank   240 bytes, one allele tier per gene (0..=3)
horse + 0x3a8 .. horse + 0x497   PAIRED  bank   240 bytes, the other diploid copy
```

The render path samples the PAIRED bank (or applies dominance across both). **Writing only the primary leaves the visible phenotype unchanged.** This is the trap we fell into until reading CRISPR's code: the in-game CRISPR Lab `scan_for_chromosomes` (`FUN_1400fd3e0`) calls `FUN_1400b39b0` which writes each gene to BOTH banks:

```c
*(u8*)(horse + gene_offset)         = new_value;   // primary
*(u8*)(horse + gene_offset + 0xF0)  = new_value;   // paired (0xF0 == 240)
```

Production code in `horsey-mod/src/horse.rs::{set_vanilla_allele, set_vanilla_alleles}` writes both banks. Reads via `vanilla_alleles_both()` return `(primary, paired)`. The single-bank `vanilla_alleles()` returns only the primary. Prefer `_both` when investigating dominance / asymmetry.

`FUN_1400a5370(gene_offset) -> u8` is the value-generator CRISPR uses (likely sources from collected chromosome state). When we want to mirror CRISPR exactly (not just force a value) we'd call that.

Gene-offset table: `DAT_14030d110`. Layout: `i32[chromosome_id][0..17]`. Each chromosome carries up to 17 gene offsets, indexed `chromosome_id * 0x44 + slot * 4`. CRISPR walks the 4 chromosome "types" (cases 3, 2, 4, 1 in the apply function); chromosome stride is 0xb8 in its caller. Not yet mirrored in Rust. Our writers take the raw 0..=239 index, not a chromosome+slot pair.

## Slot 0x00 IS the Home Location (CONFIRMED 2026-05-16)

Earlier text speculated about how `slot 0x00` related to the player's owned-horse list. Live-game evidence from `hk1.probe.active_location` settles it:

- `GS+0x438 -> *(arr + 0)` points at a Location object whose first 0x60 bytes contain inline strings `"My House"` (at +0x18) and `"Home"` (at +0x40).
- Its vtable RVA is `0x30f3d0`. **Race-lane slots 0x08..0x38 share this vtable RVA** (they're instances of the same Location class. Vtable primer + how shared vtables let one resolver work across many destinations: [`RE-NOTES.md` -> Vtables](RE-NOTES.md#vtables-c-virtual-dispatch-in-disassembly).
- The Home Location's `+0x130/+0x138` vector IS the owned-horse list. There is no separate "truck Location" or "pasture Location" with its own horse vector (the truck and pasture are rectangles drawn inside the home scene, and horses stay in this one list whether they're "in the truck" or "in the pasture."

This shapes any future feature that needs to identify which container a horse is currently in: read per-horse state, not the vector identity.

## Per-horse container kind: `horse + 0x1d0` (DOWNSTREAM ONLY)

Diff of one horse's bytes before/after a real manual drag pasture <-> truck (`hk1_snapshot_diff_horse` test, 2026-05-16) shows only three offsets change:

- `horse + 0x008` u32: animation ticker (ignore).
- `horse + 0x1d0` u32: container kind. Observed values: `7` = truck, `9` = pasture, `0` or `2` after a fresh save/load. Small enum.
- `horse + 0x1dc` u32: sub-state. Varies: `36`, `20`, `0x12`, `0x27`. Possibly a slot/position index within the container.

Writing `horse + 0x1d0` directly DOES NOT move the horse visually or logically. The game recomputes this field each tick from another authoritative source. So treat it as a downstream cache (read for display, never write for control. The true mover is the click handler's drop-commit flow described in [`HK1-SHIFT-CLICK-TRANSFER-PLAN.md`](HK1-SHIFT-CLICK-TRANSFER-PLAN.md#5b-session-log-live-game-findings-2026-05-16).

## Home Location vtable layout (resolved 2026-05-16)

For the shared Location class at vtable_rva `0x30f3d0`:

| Slot offset | Function RVA (current build) | Decomp ref | Role |
|---|---|---|---|
| `+0x38` | `0xc4b0` | shared with +0x88/+0x90 | default stub (returns 0?) |
| `+0x60` | `0xdc830` | FUN_1400d2ab0:60-call | pickup VFX / audio |
| `+0x68` | `0xd5710` | FUN_1400d2ab0:68-call | unknown |
| `+0x70` | `0xdcf50` | FUN_1400d2ab0:70-call | drag-begin |
| **`+0x78`** | **`0xde2e0`** | **FUN_1400d2ab0:1722** | **drop-commit hit-test. Signature `(*LOC, drag_idx: i32, param3: i32) -> u8`. Returns 1 if drop is valid at LOC's current cursor floats.** |
| `+0x88` | `0xc4b0` | default | default stub |
| `+0x90` | `0xc4b0` | default | default stub |

`vtable[+0x78]` runs only the hit-test; the click handler in vanilla follows up with `FUN_1400b47e0`, `FUN_1400b3dc0`, `FUN_1400b6990`, `FUN_1400ccbd0` to write the actual state. Calling vtable[+0x78] alone returns `1` but leaves the horse unchanged.

## Lesson: when the game has an in-game editor, READ ITS CODE FIRST

Spent a session writing single-bank vanilla allele setters and chasing "why doesn't the horse change visually" before reading the CRISPR Lab decomp. The decomp gave the answer in under five minutes (two banks, write both). Whenever the game has a player-facing feature that does the thing you're trying to mod, that feature's code is ground truth. Grep `research/decompiled/annotated/` first.

## Name table

`name_id` (u32 at +0x1f8) indexes a global table that maps id -> ASCII name. The string is NOT stored inline in the Horse object. We scanned all 0x498 bytes for "tomtato" (a known horse name in the test save) and found no match. The table itself has not yet been located. Once found, document its location here and add `horse::name_string(horse_ptr) -> Option<String>`.

## See also

- [`ADDRESS-RESOLUTION.md`](ADDRESS-RESOLUTION.md): full R1-R5 address-resolution plan + every resolver status.
- [`SAVE-FORMAT.md`](SAVE-FORMAT.md): per-horse save record layout.
- [`PRIOR-ART-HorseyLiveTweaks.md`](PRIOR-ART-HorseyLiveTweaks.md): which HLT offsets we cross-validated and where we diverge.
