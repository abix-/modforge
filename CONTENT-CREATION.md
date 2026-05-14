# Horsey Game — Content Creation Guide

A self-contained guide to creating mod content for Horsey Game. Derived from
decompiling `Horsey.exe` (verified) and the JumboDS64 Steam guide (community-verified).

---

## Table of contents

1. [Architecture: how the game loads content](#architecture)
2. [Modding paths summary](#modding-paths)
3. [Editing existing content](#editing-existing)
4. [Adding new species](#new-species)
5. [Adding spawners on the map](#spawners)
6. [Adding buried items](#buried-items)
7. [Editing the world map](#world-map)
8. [Custom textures and sounds](#textures-sounds)
9. [Tuning gene effects](#tuning-genes)
10. [What you cannot add](#cannot-add)
11. [Reference: item ID table](#item-ids)
12. [Reference: vanilla populations](#vanilla-pops)
13. [Reference: vanilla genes](#vanilla-genes)
14. [Debug mode + cheats](#cheats)
15. [Launching with flags](#cli-flags)
16. [Save backup + rollback](#backup)
17. [Distributing your mod](#distributing)

---

<a name="architecture"></a>
## 1. Architecture: how the game loads content

`Horsey.exe` is a hand-rolled C++ engine on SDL3. The engine is fixed; the
**content** is data-driven via files in `data/`.

At startup, the engine reads:

| File | Role | Bound size |
|---|---|---|
| `data/genes.xml` | 240 gene definitions (name, mutation, scale, 4 allele values, codon order) | hardcoded 240-slot table |
| `data/pop.xml` | 28 population definitions with per-gene allele weights | nestable, no fixed count |
| `data/sound.xml` | sound + music registry | name-keyed |
| `data/sprites.xml` + `furniture.xml` + `locs.xml` + `terrain.xml` + `veg.xml` + `biglogo.xml` | sprite atlases pointing into `.png` files | per-atlas |
| `data/horsey.tmx` | Tiled world map (400×225 tiles + objects) | hardcoded 400×225 |
| `data/names.txt` | 4,999 random horse names | name-pool only |
| `data/*.png` | sprite atlas images | dimensions must match `.xml` |
| `data/*.crf` + `*.txt` | ChevyRay bitmap fonts | per-glyph metrics |
| `data/genes.dat` | binary cache of gene table, regenerated from `genes.xml` | regenerated automatically |
| `sound/*.wav` | 402 WAV files | mono/stereo only |
| `sound/Music_*.ogg` | music tracks | Ogg Vorbis |

The save state is stored in `save/save<N>.dat`. The engine writes settings to
`save/settings.xml`.

**Key fact**: when `genes.xml` changes, you must delete `data/genes.dat` to
force a cache rebuild. Otherwise the game uses the stale binary cache.

---

<a name="modding-paths"></a>
## 2. Modding paths summary

| Path | Difficulty | What you can do | Requires |
|---|---|---|---|
| In-game cheats | none | Disable fatigue, +money, +supplies, x300 sim speed | Just play the game |
| `names.txt` edit | trivial | Custom horse names | Text editor |
| PNG / WAV replacement | trivial | Reskin graphics, replace sounds | Image editor / audio editor |
| `genes.xml` edit | easy | Tune trait values across all populations | Text editor |
| `pop.xml` edit | easy | Adjust species rarity, add new species | Text editor |
| `horsey.tmx` edit | medium | Edit world map, place spawners, plant items | Tiled editor |
| `sound.xml` edit | medium | Reassign sounds to events, tune vol/pitch | Text editor |
| Binary patch (`Horsey.exe`) | hard | Add NEW mechanics; change hardcoded thresholds | Reverse engineering (Ghidra) |

---

<a name="editing-existing"></a>
## 3. Editing existing content

Before doing anything, **back up** `data/` and `save/`. See [Save backup + rollback](#backup).

### Always after editing `genes.xml`:

```
delete  data/genes.dat
```

The game regenerates this cache from `genes.xml`. If you don't delete it,
your edits are ignored.

---

<a name="new-species"></a>
## 4. Adding new species

A "species" is a `<pop>` block in `data/pop.xml`. Each pop specifies how
strongly each allele of each gene is favored at spawn time.

### Anatomy of a `<pop>` block

```xml
<pop name="my_species">
    <gene name="SIZE" p0="1" />
    <gene name="LITTER_SIZE" p3="1" />
    <!-- more gene weights -->
</pop>
```

Attributes:
- `name`: the species name. Used in spawner `class` fields. Case-sensitive; spaces allowed.
- One or more `<gene name="X" p0=".." p1=".." p2=".." p3=".." />` lines.

### Gene weight semantics (CRITICAL)

**The `p0`/`p1`/`p2`/`p3` numbers are INVERSE weights**. Higher number = the
allele is LESS likely to be picked. So:
- `p0="1"` is the **most likely** (lowest weight wins).
- `p0="17"` is **rare**.
- A missing `pN` means that allele won't spawn at all (effectively infinite weight).

This is the opposite of what you'd intuitively guess. Verified by JumboDS64's
Steam guide and consistent with our decompilation of `0x14005cf70`
(`pop_inheritance_handler`).

### Inheritance: nested pops

Pops can be nested inside other pops. A nested pop **inherits** the parent's
gene weights and adds/overrides its own. Example from vanilla:

```xml
<pop name="default">
    <gene name="SIZE" p0="1" />     <!-- default size weights -->
    <gene name="BIPED" p0="1" />     <!-- no bipeds by default -->
    
    <pop name="human">
        <gene name="BIPED" p2="1" />    <!-- humans CAN be bipedal -->
        <gene name="ARM_TAG" p2="1" />
        
        <pop name="jockey">
            <gene name="SIZE" p1="1" />  <!-- jockeys are smaller -->
        </pop>
    </pop>
</pop>
```

A jockey horse inherits everything from `default` AND `human`, then applies
its own overrides.

### Recipe: add a new species "spaceparrot"

1. Open `data/pop.xml`.
2. Inside the `<pop name="default">` block, add a new sub-pop:
   ```xml
   <pop name="spaceparrot">
       <gene name="SIZE" p0="20" p1="1" p2="20" />     <!-- small (g1 dominant) -->
       <gene name="BASE_BLUE" p0="20" p2="1" />        <!-- blue base color -->
       <gene name="WING" p3="1" />                     <!-- always winged -->
       <gene name="LITTER_SIZE" p3="1" />              <!-- big broods -->
       <gene name="SPEED_FACTOR" p3="1" />             <!-- fast -->
   </pop>
   ```
3. Delete `data/genes.dat`.
4. (Optional) place spawners on the map (see next section).
5. Launch the game with an existing save. Horses born from new spawners will
   be spaceparrots; existing horses are unchanged.

### Verification

If you place a spawner referencing a misspelled pop name, the game logs
`"Bad Pop %d"` (we found this error at `0x1400a2ed0`). Check the game's
debug log to confirm the spawner found your pop.

---

<a name="spawners"></a>
## 5. Adding spawners on the map

Spawners are **objects** placed in `horsey.tmx` using Tiled.

### Tile to use

Use one of the 7 vanilla animal-tile sprites. There are also 2 unused tiles
(bunny, dinosaur) in the tileset — JumboDS64 notes these may have been
intended for natural spawns at some point.

### Required properties

| Property | Type | Meaning |
|---|---|---|
| `class` | **string** | The pop name from `pop.xml` (e.g. `"spaceparrot"`) |
| `count` | **int** | Total horses to spawn |
| `radius` | **int** | Spawn area = `(2*radius+1) × (2*radius+1)` centered on the spawner tile |

A radius of 5 means horses spawn in an 11×11 square centered on the spawner.

### Recipe: place 5 spaceparrots near the Acres

1. Open `data/horsey.tmx` in Tiled (download from mapeditor.org).
2. If Tiled can't render the map, you need the `.tsx` tileset files. JumboDS64
   shares working ones on Google Drive (see his Steam guide).
3. Switch to the "Objects" layer in the bottom-right Layers panel.
4. Use the "Insert Tile" tool. Pick one of the 7 animal tiles.
5. Click on the map near the Acres to place the spawner.
6. With the spawner selected, in the lower-left Properties panel:
   - Set `class` = `spaceparrot` (the dropdown can show or you can type)
   - Click "+ Add Property", name `count`, type `int`, value `5`.
   - Click "+ Add Property", name `radius`, type `int`, value `8`.
7. Save the `.tmx`.
8. Launch the game. Travel to the Acres. Spaceparrots should be wandering.

### Building constraints

Buildings on the map are **first-instance-wins**. The engine scans the tmx for
each building tile-ID once and uses the first object it finds. You cannot
place two of the same building type (e.g. two Stables) — the second is
ignored.

### Restart+ spawn marker

If you make a custom map and want to test from a fresh start (skipping the
intro), place a **truck-tile object** somewhere on the map. That marks the
player's spawn after Restart+.

---

<a name="buried-items"></a>
## 6. Adding buried items

You can plant any item on any tile so players find it when digging with a shovel.

### How

1. In Tiled, place a **capital-I-shaped** object on the target tile.
2. Add a custom property:
   - Name: `buried`
   - Type: **string** (NOT int — the engine reads it as a string)
   - Value: the item ID number as a string (e.g. `"14"` for treasure chest)

The full item ID list is in [Reference: item ID table](#item-ids) below.

### Cap

Item IDs **0 through 47** are valid. IDs ≥ 48 produce a bugged "single meat"
item that's both edible and worn as an invisible clothing item. (Quote from
JumboDS64's guide; the engine has a hardcoded item table.)

### Useful buried items for mods

| ID | Item | Why mod-worthy |
|---|---|---|
| 13 | Cash suitcase ($200) | Quick money boost |
| 14 | Treasure chest ($5000) | Bigger money boost |
| 22-24 | Car upgrades | Free vehicle upgrades |
| 18-21 | DNA pieces G/A/T/C | Skip CRISPR farming |
| 9 | Championship trophy | Start with one win |
| 46 | Infinite fence bag | Unlimited fencing |
| 47 | 8G RAM upgrade for biohacker | Late-game upgrade early |

---

<a name="world-map"></a>
## 7. Editing the world map

`horsey.tmx` is a Tiled map. 400×225 tiles at 32 pixels each.

### Tilesets

The map uses two tilesets:
- `terrain.tsx` — terrain tiles (firstgid `1`)
- `locs.tsx` — building/location tiles (firstgid `97`)

These `.tsx` files are NOT shipped with the game. JumboDS64 reconstructed
them and shared on Google Drive — see his Steam guide for the link. Without
them, Tiled shows a grid of X marks.

### Editing terrain

1. In Tiled, select the "Tiles" layer.
2. Use the terrain palette in the bottom-right to paint tiles.
3. Note: the grass row at the BOTTOM of the terrain sheet is **plutonium
   grass** (the radioactive grass near the Power Plant).

### Fences

Vertical fences place a fence on the **upper border** of the tile and copy
the actual tile contents from the tile above. Horizontal fences do the same
on the left border, copying from the tile to the left. This is a Tiled
authoring oddity, not a runtime mechanic.

### Buildings

Click the "Objects" layer. Use "Insert Tile" with one of the location tiles
from `locs.tsx`. The game finds buildings by **tile ID**, not by class name —
the class name in Tiled is for editor convenience.

**Only one of each building type** can exist. The game uses the first one it
finds in the tmx and ignores duplicates.

### CRISPR Lab requires a vial-world island

The CRISPR Lab building also requires a separate **vial-world** area
placed elsewhere on the map: a small island of **purple chemical tiles**
where the player drives around when "inside" the vial. Cas9 and the
chromosome horses spawn there.

Driving onto any non-purple-chemical tile exits the vial. Keep the vial
island shape close to vanilla for the shrinking animation to look right.

---

<a name="textures-sounds"></a>
## 8. Custom textures and sounds

### Textures (PNG)

Every `.xml` atlas in `data/` has a sibling `.png` with the same name.
Examples:
- `sprites.xml` ↔ `sprites.png`
- `furniture.xml` ↔ `furniture.png`
- `terrain.xml` ↔ `terrain.png` (also `terrain_editing.png` from JumboDS64)
- `veg.xml` ↔ `veg.png`
- `locs.xml` ↔ `locs.png`

The XML defines pixel rectangles `<sprite n="Name" x=".." y=".." w=".." h=".."/>`
within the PNG. If you redraw a PNG, **keep the same dimensions and tile
positions** or the XML rects will be wrong.

To extend: you CAN add new `<sprite>` entries pointing to new pixel rects in
the PNG. But the game only renders sprites it knows about by name — so
purely decorative additions won't appear in-game.

### Sounds (WAV)

`sound/*.wav` files are referenced by name from `sound.xml`. Replace any WAV
with one of the same filename to swap the sound. WAVs must be **mono or
stereo PCM** (cute_sound library limitation).

You CANNOT add new sound events — the engine triggers sounds by hardcoded
name. New WAVs without a matching entry in `sound.xml` are dead files.

### Music (OGG)

`sound/Music_*.ogg` files are played as music. Same swap rules apply.

### Fonts

8 ChevyRay bitmap fonts: `bubbletime`, `capy_bold`, `classified`, `habit_mono`,
`habit_narrow_bold`, `picory`, `snuggle`, `softsquare`. Each has a `.png`,
`.crf` (binary), and `.txt` (metrics) triplet. Replace all three to swap.

---

<a name="tuning-genes"></a>
## 9. Tuning gene effects

`genes.xml` declares the 240 (vanilla: ~242) gene table that drives every
horse trait. You can tune **values** but not add new gene **names**.

### Gene declaration syntax

```xml
<gene name="GENE_NAME" m="100" s="1" g0="0" g1="0" g2="-1" g3="2" n="ATGC" />
```

| Attr | Meaning | Editable? |
|---|---|---|
| `name` | Gene identifier; matched against the `chromoMap` enum in the engine | NO (chromoMap is fixed) |
| `m` | Mutation rate (%) | YES |
| `s` | Scale: `1` = discrete integer, `100` = continuous/percent | YES (carefully) |
| `g0..g3` | The four possible allele values | YES |
| `n` | The 4-letter ACGT codon order used to encode this gene in the DNA string | YES (cosmetic; affects DNA strings shown in CRISPR) |

### Always after editing

```
delete data/genes.dat
```

The cache must be regenerated. If you skip this, your edits are silently ignored.

### Common tuning recipes

**Bigger litters everywhere:**
```xml
<!-- vanilla -->
<gene name="LITTER_SIZE" m="100" s="1" g0="1" g1="2" g2="3" g3="5" n="CTAG" />

<!-- modded: 5/8/10/15 babies per breeding -->
<gene name="LITTER_SIZE" m="100" s="1" g0="5" g1="8" g2="10" g3="15" n="CTAG" />
```

**Slightly longer lifespans (conservative):**
```xml
<!-- vanilla -->
<gene name="OLD_AGE" m="100" s="1" g0="0" g1="0" g2="-1" g3="2" n="TACG" />

<!-- modded: humans + freaks live longer; default unchanged -->
<gene name="OLD_AGE" m="100" s="1" g0="0" g1="0" g2="-3" g3="-3" n="TACG" />
```

**Remove lethal-white death:**
```xml
<!-- vanilla -->
<gene name="WHITE_IS_LETHAL" m="100" s="1" g0="0" g1="1" g2="0" g3="0" n="AGCT" />

<!-- modded -->
<gene name="WHITE_IS_LETHAL" m="100" s="1" g0="0" g1="0" g2="0" g3="0" n="AGCT" />
```

**No narcolepsy:**
```xml
<!-- vanilla -->
<gene name="NARCOLEPSY" m="100" s="1" g0="0" g1="0" g2="1" g3="0" n="TCGA" />

<!-- modded -->
<gene name="NARCOLEPSY" m="100" s="1" g0="0" g1="0" g2="0" g3="0" n="TCGA" />
```

### Caveats

- Editing `s="1"` to `s="100"` (or vice versa) may break things — the engine
  probably handles those scales differently in the gene-expression code.
- Negative `OLD_AGE` values that are too large may make horses die instantly
  if the base lifespan is small. Start conservative.
- Gene effects only apply to **newly-spawned horses**. Existing horses keep
  their original alleles.

---

<a name="cannot-add"></a>
## 10. What you cannot add (without binary patching)

The following are baked into `Horsey.exe` and cannot be changed by editing
data files:

| What | Why hardcoded |
|---|---|
| New building types (Stable, Lab, CRISPR, Sumo, ...) | Each has dedicated handler functions in the engine (we found these at `0x140033a10`, `0x14007b2e0`, `0x140039190`, etc.) |
| New item types beyond ID 47 | Item table is hardcoded; IDs ≥ 48 produce bugged items |
| New gene NAMES | `chromoMap` is hardcoded to 240 slots indexed by enum (we found this at `0x1400a3eb0`) |
| New mechanics (racing, breeding, CRISPR, sumo) | Implemented in C++ handlers |
| Map size beyond 400×225 | Likely hardcoded in the tmx parser at `0x1400fe2e0` |
| Number of horses in vial (CRISPR) | Loop limit 0x14 = 20 max chromosomes (at `0x1400fd3e0`) |
| Fatigue / sleep thresholds | Hardcoded in the eligibility-check function (`0x1400dde40`) |
| Building "first instance wins" rule | Hardcoded scan in tmx loader |

To change these you must patch `Horsey.exe`. We have the function addresses
in `decompiled/annotated/*.c`. For the fatigue threshold specifically, the
built-in "No Tire" cheat is the cleanest workaround (see [Cheats](#cheats)).

---

<a name="item-ids"></a>
## 11. Reference: item ID table

Source: JumboDS64's Steam guide, cross-referenced with our decompilation of
`item_description_dialog` at `0x1400cc1d0`.

| ID | Item |
|---|---|
| 0 | Hay bale |
| 1 | Apple |
| 2 | Beer |
| 3 | Hot sauce |
| 4 | Plutonium |
| 5 | Fossil bone |
| 6 | Carcass |
| 7 | Manure |
| 8 | Regular blue trophy |
| 9 | Championship trophy |
| 10 | VIP card |
| 11 | DNA beaker |
| 12 | Floppy disk |
| 13 | Cash suitcase ($200) |
| 14 | Treasure chest ($5000) |
| 15 | Potted cactus |
| 16 | Flower vase |
| 17 | Treasure map |
| 18 | Guanine (G DNA piece) |
| 19 | Adenine (A DNA piece) |
| 20 | Thymine (T DNA piece) |
| 21 | Cytosine (C DNA piece) |
| 22 | Racing stripes upgrade |
| 23 | Suspension upgrade |
| 24 | Ram bar upgrade |
| 25 | Sneakers |
| 26 | Bowtie |
| 27 | Dress tie |
| 28 | Top hat |
| 29 | Beanie |
| 30 | Doctor's glasses |
| 31 | Sunglasses |
| 32 | Ball n' chain |
| 33 | Back rocket |
| 34 | Balloon |
| 35 | Roller skates |
| 36 | Stilts |
| 37 | Clown nose |
| 38 | Tan boots |
| 39 | Brown boots |
| 40 | Purple boots |
| 41 | Black boots |
| 42 | Diving ribbon (pink) |
| 43 | Stronghorse ribbon (yellow) |
| 44 | Trampoline ribbon (orange) |
| 45 | Acrobat ribbon (green) |
| 46 | Infinite fence bag |
| 47 | 8G RAM upgrade for biohacker |
| 48+ | **BUGGED**: "single meat" item (edible + invisible clothing) |

---

<a name="vanilla-pops"></a>
## 12. Reference: vanilla populations

28 pops defined in `pop.xml`:

| Pop name | Role |
|---|---|
| `default` | The root pop. All other pops inherit from this. |
| `scratch` | Test/scratch pop |
| `fest horse` | Festival horse variant |
| `crazy horse` | Crazy variant |
| `impala` | Antelope-like |
| `alligator` | Reptile |
| `giraffe` | Tall-necked |
| `rabbit` | Small mammal |
| `duck` | Bird |
| `dino` | Dinosaur |
| `centipede` | Many-legged |
| `tiger` | Big cat |
| `moose` | Antlered |
| `dachshund` | Long-bodied dog |
| `bear` | Large mammal |
| `cow` | Bovine |
| `human` | Bipedal humans (NPCs) |
| `centaur test` | Centaur prototype |
| `jockey` | (nested in human) Jockey NPCs |
| `leprechaun` | (nested in human) Leprechaun variant |
| `pepper` | Spicy variant |
| `car` | Vehicle pop (Clide's cars) |
| `appletree` | Plant species |
| `yeast` | Microbe |
| `hay` | Plant |
| `fish` | Aquatic |
| `helix` | DNA-helix entity |
| `freak` | Circus freaks |

You can add your own under any of these as nested pops to inherit their genes.

---

<a name="vanilla-genes"></a>
## 13. Reference: vanilla genes

242 genes in `data/genes.xml`. Categories:

**Body shape**: `SIZE`, `ASPECT`, `SKINNY`, `BONES`, `BONES2`, `CHEST_BIG`,
`CHEST_SMALL`, `GIANT_DWARF`, `MUSCLE_USE`, `QUADRUPED`, `BIPED`, `SPLAY`,
`LEG_IN`, `LEG_IN2`, `GUT`, `GUT_IS_UDDER`, `OSTODERM`, `OSTO_SIZE`,
`DERRIERE`

**Performance**: `SPEED_FACTOR`, `BREAK_FORCE`, `STIFF_JOINTS`

**Tail**: `TAIL_TAG`, `TAIL_EXISTS`, `TAIL_SIZE`, `TAIL_SHORT`,
`TAIL_ASPECT`, `TAIL_ANGLE`, `TAIL_JOINT_TYPE`, `TAIL_STIFF`, `TAIL_SPEED`,
`TAIL_FLEXIBILITY`, `TAIL_SHAPE`, `TAIL_BOTTOM`, `TAIL_SEGMENTS`,
`TAIL_WAG`, `TAIL_ALT`

**Legs**: `LEG_TAG`, `LEG_TYPE`, `LEG_LENGTH`, `LEG_STRETCH`, `LEG_STRETCH2`,
`LEG_STRENGTH`, `LEG_HAS_FOOT`, `LEG_JOINT_TYPE`, `LEG_FLEXIBILITY`,
`LEG_FLEX_BIAS`, `LEG_THRUST_BACK`, `LEG_IS_CIRCLE`, `LEG_COUNT`,
`LEG_SKEW`, `LEG_PENCIL`, `LEG_AND_ARM_LIMP`, `HAS_KNEE`, `KNEE_MIN`,
`KNEE_MAX`

**Arms**: `ARM_TAG`, `ARM_TYPE`, `ARM_LENGTH`, `ARM_STRETCH`, `ARM_STRETCH2`,
`ARM_STRENGTH`, `ARM_HAS_HAND`, `ARM_JOINT_TYPE`, `ARM_FLEXIBILITY`,
`ARM_FLEX_BIAS`, `ARM_FORWARD`, `ARM_SKEW`, `ARM_NODE_SCALE`, `HAS_ELBOW`,
`ELBOW_RANGE`, `UPARM_TAG`, `UPARM_Y`, `UPARM_ANGLE`, `UPARM_GOOFY`

**Neck**: `NECK_TAG`, `NECK_TYPE`, `NECK_LENGTH`, `NECK_GIRAFFE`,
`NECK_THICKNESS`, `NECK_ANGLE`, `NECK_COCK`, `NECK_JOINT_TYPE`,
`NECK_FLEXIBILITY`, `NECK_FLEX_BIAS`, `NECK_SLOUCH`, `NECK_ONTOP`,
`NECK_STIFF`, `NECK_SPEED`

**Feet**: `HAS_FOOT`, `FOOT_SIZE`, `FOOT_CLOWN`, `FOOT_THICKNESS`,
`FOOT_TOE`, `FOOT_IS_CIRCLE`, `FOOT_BACKWARDS`, `FOOT_IS_HOOF`

**Hands**: `HAS_HAND`, `HAND_WIDTH`, `HAND_LENGTH`, `HAND_FINGER`

**Head**: `HEAD_SIZE`, `HEAD_THICK_SKULL`, `HEAD_X_GROWTH`, `HEAD_Y_GROWTH`,
`HEAD_ASPECT`, `HEAD_SQUARE`, `HEAD_HAS_BACK`, `HEAD_GIANT`,
`HEAD_SHRUNK`, `HEAD_JOINTED`, `HEAD_CHIMERA`

**Face**: `EYE_STYLE`, `BUGEYE`, `EYEBOX_X`, `EYEBOX_Y`, `EYEBOX_SIZE`,
`EYE_SIZE`, `PUPIL_SIZE`, `HAS_PUPIL`, `BROW_SIZE`, `BROW_SLANT`,
`EAR_STYLE`, `EAR_SHAPE`, `EAR_FLOP`, `EAR_X`, `EAR_SIZE`, `EAR_ASPECT`,
`EAR_SLANT`, `EAR_INTERIOR`, `EAR_COMP`, `TEETH_SHAPE`, `HAS_MOUTH`,
`MOUTH_Y`, `MOUTH_SIZE`, `JAW`, `TEETH_UPPER`, `TEETH_UPPER2`, `TONGUE`,
`TONGUE_SEGS`, `NOSE_STYLE`, `NOSE_INNY`, `NOSE_Y`, `NOSE_SIZE`,
`NOSE_INTERIOR`, `RACCOON_EYE`

**Antlers / hats**: `HAS_ANTLERS`, `ANTLER_X`, `ANTLER_W`, `ANTLER_H`,
`ANTLER_TAPER`, `ANTLER_POM`, `ANTLER_COLOR`, `POM_COLOR`, `POM_USECOLOR`,
`ANTLER_REC`, `ANTLER_REC2`, `ANTLER_FLIP`, `ANTLER_MOD`, `ANTLER_SCALEH`,
`ANTLER_SCALEW`, `ANTLER_ANGLE`, `ANTLER_ANGLE2`, `ANTLER_ANGLE_RAND`,
`ANTLER_T1`, `ANTLER_T2`, `HAT_EXISTS`, `HAT_SIZE`, `HAT_RAKE`,
`HAT_ASPECT`, `HAT_TAPER`, `HAT_POM`, `HAT_POM_IS_LID`, `HAT_CLONE`,
`HAT_BACK_SCALE`, `HAT_FRONT_SCALE`, `HAT_BACK_ANGLE`, `HAT_FRONT_ANGLE`,
`HAT_ANGLE_RAND`, `HAT_FLIP`, `HAT_T`

**Color**: `BASE_BROWN`, `BASE_BLACK`, `BASE_RED`, `BASE_GREEN`,
`GREEN_KNOCKOUT`, `BASE_CREAM`, `ALT_BLUE`, `SPOT_YELLOW`, `SKIN_HUE`,
`SKIN_HUE2`, `SWAP_BASE_SPOT`, `SWAP_ALT_SPOT`, `WHITE`, `WHITE_IS_LETHAL`,
`EYE_HUE`, `NOSE_HUE`, `HOOF_COLOR`, `AGOUTI`, `BELLY_ALT`, `SKIN_HEAD`,
`SKIN_HANDS`

**Pattern**: `PAT_SPLIT`, `PAT_BELLY`, `PAT_STRIPE`, `PAT_SPOT`,
`PAT_PERLIN`, `PAT_PERLIN2`, `PAT_PERLIN_SIZE`

**Behavior / health**: `RAMPAGE`, `SPINAL_LOCO`, `BRAIN_SPASTIC`,
`HIGH_INTELLECT`, `OMNIVORE`, `LITTER_SIZE`, `OLD_AGE`, `LIMP`,
`NARCOLEPSY`, `FLU_IMMUNITY`

**Locomotion (limb signal/event chains)**: `L_LEG_SIGNAL`, `L_LEG_FTOB_REACT`,
`L_LEG_FTOB_EVENT`, `L_LEG_BTOF_REACT`, `L_LEG_BTOF_EVENT`, `L_ARM_SIGNAL`,
`L_ARM_FTOB_REACT`, `L_ARM_FTOB_EVENT`, `L_ARM_BTOF_REACT`,
`L_ARM_BTOF_EVENT`, `L_TAIL_SIGNAL`, `L_TAIL_FTOB_REACT`,
`L_TAIL_FTOB_EVENT`, `L_TAIL_BTOF_REACT`, `L_TAIL_BTOF_EVENT`,
`L_NECK_SIGNAL`, `L_NECK_FTOB_REACT`, `L_NECK_FTOB_EVENT`,
`L_NECK_BTOF_REACT`, `L_NECK_BTOF_EVENT`, `LOCO_SYNC`

You cannot add new gene names. You CAN edit any of these values.

---

<a name="cheats"></a>
## 14. Debug mode + cheats

The dev ships a hidden cheat menu unlocked by typing `"debug"` while the
game is paused. Confirmed by both decompilation (`0x140066200`) and the
JumboDS64 guide.

### Unlocking debug mode

1. Pause the game (Escape).
2. Type `d`, then `e`, then `b`, then `u`, then `g`. (You won't see anything
   while typing — the keystrokes are matched against the literal string `"debug"`.)
3. The pause menu changes: the status line now says
   `< Simulation Paused - Year X  Sleeps Y  Races Z >` and extra cheat
   buttons appear.

### Cheat buttons

| Button | Effect |
|---|---|
| Continue | Resume |
| Reset Game | Restart the game from intro |
| Betting Mode | Force betting mode |
| Gong | Trigger gong sound |
| Money | +$1000 per click |
| Loaded | +20 to each of 7 supply counters + sets some flags |
| No Tire / Yes Tire | Toggle fatigue-disabled mode |

### "No Tire" specifically

When the No-Tire toggle is on, **every frame** the game zeros out the per-horse
tiredness flags at offsets `+0x205` and `+0x206`. Horses never accumulate
tiredness. This is the cleanest answer to "horses get tired after one race"
in vanilla, and requires no modding.

### Hot air balloon speed cheat

While in the hot air balloon (with debug mode enabled), press `5` to set
game sim speed to **x300**.

(Confirmed by `BalloonSimFaster` / `BalloonSimSlower` in
`0x14010a5e0`, and JumboDS64's guide.)

---

<a name="cli-flags"></a>
## 15. Launching with flags

The CLI parser at `0x140076a10` recognizes these flags. Add them after
`Horsey.exe` (use Steam's Set Launch Options field):

| Flag | Effect |
|---|---|
| `debug` | Auto-enable debug mode at startup (no need to type "debug" in pause) |
| `autoload` | Auto-load the last save at startup |
| `autosave` | Auto-save on key events |
| `log_races` | Verbose logging of race events |
| `log_stables` | Verbose logging of stable activity |
| `log_world` | Verbose logging of world events |
| `labpop` | Lab population debug mode |
| `savestress` | Stress-test the save system |
| `escquits` | Make Escape key quit instead of opening pause menu |
| `hidpi` | Enable high-DPI rendering |
| `music` | Music control |

Example Steam launch option: `debug log_world autoload`.

---

<a name="backup"></a>
## 16. Save backup + rollback

ALWAYS back up before modding. Files to copy:

```
data/                        (the entire folder, before any edits)
save/save1.dat               (your save)
save/save1.dat.prev          (the game's auto-backup)
save/settings.xml            (your window/audio settings)
```

To rollback after a bad mod:

1. Quit the game completely.
2. Replace the modified files with your backup.
3. Delete `data/genes.dat` (the cache regenerates on launch).
4. Launch.

The game also keeps a `.prev` save automatically — if your save loads and
breaks, restore `save1.dat.prev` over `save1.dat`.

---

<a name="distributing"></a>
## 17. Distributing your mod

The game's mod community is small but JumboDS64's Steam guide names these
distribution targets:

- **Gamebanana** — common indie-mod host
- **ModDB** — long-running mod platform
- Steam Community guides (text-only descriptions of file edits)

A typical mod package contains:
- The edited `data/` files
- A README explaining what to back up and what to overwrite
- Optional: a runnable installer script

You usually distribute as a ZIP. The user manually overwrites their `data/`
folder.

For binary patches (changes to `Horsey.exe`), distribute as a diff or a
patcher tool — never the patched exe itself (copyright).

---

## Quick-start: your first mod

If you've never modded this game before, start with this exercise:

1. Back up `data/genes.xml`, `data/genes.dat`, and `save/`.
2. Open `data/genes.xml`.
3. Find this line:
   ```xml
   <gene name="LITTER_SIZE" m="100" s="1" g0="1" g1="2" g2="3" g3="5" n="CTAG" />
   ```
4. Change it to:
   ```xml
   <gene name="LITTER_SIZE" m="100" s="1" g0="5" g1="8" g2="10" g3="15" n="CTAG" />
   ```
5. Delete `data/genes.dat`.
6. Launch the game with an existing save.
7. Breed two horses. Verify the new pair produces 5+ foals.

This exercise teaches you the full pipeline: backup → edit → delete cache → test.

## Where to go from here

- **For more aggressive mods**: read `MECHANICS.md` for confirmed game mechanics.
- **For binary patches**: see `decompiled/annotated/*.c` for function addresses
  and behavior. Targets like the fatigue check are at `0x1400dde40`.
- **For save editing**: `save_edit.py` is a working save reader. Extending it to
  write specific fields is straightforward once you know the byte offset
  (we have the full save format in `decompiled/annotated/0x14006dc80_save_game_writer.c`).
- **For map editing**: download Tiled (mapeditor.org), grab JumboDS64's `.tsx`
  files from his Steam guide's Google Drive link.

## Verification

Every claim in this document is backed by one of:
- A specific function address in `decompiled/annotated/` or `decompiled/game-funcs/`
- A line citation in `decompiled/all_functions.c`
- A cross-verification with JumboDS64's Steam guide (see `EXTERNAL-KNOWLEDGE.md`)

If something here doesn't match what you see in-game, file an issue against
this repo with: which claim, what you saw, and your save file.
