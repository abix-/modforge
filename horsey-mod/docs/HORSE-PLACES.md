# Horse Places

Authoritative catalog of every memory location that holds horse pointers or horse records in Horsey Game. Built from `research/decompiled/all_functions.c` + `gamestate.scan_438_slots` live data + HLT prior art (`research/prior-art/HorseyLiveTweaks/src/core/offsets.h`).

There is NOT one single "owned horses" list. Horses are partitioned across many lists by purpose (owned, race-lane, scene, hovered, selected, pool). To answer "how many horses does the player own" you read the OWNED list. To answer "which horses are visible in this scene" you read the active scene's list. Mistakes here are why the Horses tab read 0/N for weeks.

## Top-level singletons

The game has TWO top-level state singletons (both `.data` slots; both hold POINTERS that must be dereffed):

| Slot RVA | Pointer to | Size | Purpose | Discovery |
|---|---|---|---|---|
| `DAT_1403fb0d8` | GameState | 0x448 B (alloc size) | Player progress, money, year, owned horses, scene table at +0x438, fatigue/no_tire flags, etc. **Most fields documented in this doc.** | Existing (R-tier resolved as `GAMESTATE_PTR`). |
| `DAT_1403f4e00` | MapState  | 0x268 B            | TMX-loaded world map. Populated by `TMX_MAP_PARSER` (`FUN_1400fe2e0`) reading `data/horsey.tmx`. See MapState field map below. | 2026-05-17 decomp pass for [`world-map-detection.md`](world-map-detection.md). Not yet in `targets_registry.rs`. |

### MapState (`*DAT_1403f4e00`) field map

Decomp citations are `all_functions.c:<line>`. Confirmed offsets (2026-05-17 pass):

| Offset | Type | Field | Decomp cite | Notes |
|---|---|---|---|---|
| `+0x000` | `void**` | vtable | `:64613` `(**(code **)(*DAT_1403f4e00 + 0xb0))()` | Methods observed at vtable+0xb0, +0xb8. |
| `+0x0b8 / +0x0c0 / +0x0c8` | `std::vector<T*>` | unknown vector (begin / end / cap_end) | `:120160`, `:150208` | Walked alongside the building vector during scene-transition cleanup. Purpose TBD. |
| `+0x130 / +0x138 / +0x140` | `std::vector<Building*>` | building/location list (begin / end / cap_end) | `:120489` push, `:112880` walk, `:120156` clear | **THE building list parsed from `horsey.tmx` Objects layer.** Iteration sets `building+0x1c8 = 1` on each entry; size = `(end - begin) >> 3`. Pushed to via `FUN_140030680` on grow; fast-path stores 8 bytes (pointer-sized) at end and increments end by 8. |
| `+0x254` | `float` | **camera_x** (world pixels) | `:80862`, `:120224` | Subtracted from object world coords to produce screen-relative offset. |
| `+0x258` | `float` | **camera_y** (world pixels) | `:80862`, `:120223` | Sibling of camera_x. Pair pattern `(obj_x - camera_x, obj_y - camera_y, camera_x, camera_y)` written to a 4-float buffer at `:120245-120248`. |
| `+0x262` | `bool` | "buildings loaded" / "map active" | `:120506` set when building vector non-empty; `:57328`, `:58161`, `:58718`, `:75559` consumers | Gates many code paths. Likely "we are currently rendering the world map view". |
| `+0x268` | end |. |. | Total allocation per `:150510` `FUN_1402c704c(0x268)`. |

### Player position on the world map: the Truck object

The player navigates the overworld in a TRUCK. The truck's live world
position IS the player's location. From decomp (2026-05-17):

- `*(GameState + 0x300)` -> **Truck object** (also more generally an
  "active actor"; same struct layout as horses and other movable
  scene entities. The +0x28/+0x2c/+0x30/+0x34 position+velocity
  pattern recurs).

Confirmed Truck fields:

| Offset | Type | Field | Cite | Notes |
|---|---|---|---|---|
| `+0x08` | `u32` | id/index | `:149193` | Passed to `FUN_140071ed0`. Likely actor id or scene-class id. |
| `+0x28` | `float` | pos_x | `:76288`, `:149189`, `:153692` | Position in scaled units (multiply by `DAT_140303fb4` -> tile coords). |
| `+0x2c` | `float` | pos_y | `:76289`, `:149191`, `:153694` | Sibling of pos_x. |
| `+0x30` | `float` | vel_x | `:149189` | Per-frame velocity; `(vel * dt + pos)` is the interpolated position. |
| `+0x34` | `float` | vel_y | `:149191` | Sibling of vel_x. |
| `+0xac` | `bool` | state flag (likely "at-rest" / "in-scene") | `:80852`, `:80921`, `:148762` | When `'\0'`, code takes the "needs init / stopped" branch and calls `FUN_1400cd5a0`. When non-zero, the camera-update path fires (`:80856-80862`). |

**Reading the player's tile position**:

```rust
let truck = *(GS + 0x300) as *const u8;
let pos_x_raw = *(truck.add(0x28) as *const f32);
let pos_y_raw = *(truck.add(0x2c) as *const f32);
let scale = DAT_140303fb4;  // float, ~0.03125 (1/32) or 1.0 depending on units
let tile_x = (pos_x_raw * scale) as i32;
let tile_y = (pos_y_raw * scale) as i32;
```

To answer "what location is the player currently on":

1. Compute `(tile_x, tile_y)` from the truck (above).
2. Walk the TMX Objects list (parsed from `data/horsey.tmx`) for the
   object whose `(x / 32, y / 32) == (tile_x, tile_y)`.
3. That object's `type` attribute is the player's current location
   (e.g. `"home"`, `"circus"`).

Or via the live in-memory building vector at MapState `+0x130`: walk it,
find the entry whose position fields match. Building world-pos offsets
TBD; the TMX path side-steps the need.

### Terrain tile grid + tile lookup

**`FUN_1401010d0(GameState*, int tile_x, int tile_y) -> u8*`** (RVA `0x1401010d0`). Returns a pointer to a 40-byte terrain cell at `(tile_x, tile_y)`, or sentinel `&DAT_1403dc390` if OOB. From decomp (`:152898`):

```c
undefined4 * FUN_1401010d0(GameState *gs, int tile_x, int tile_y) {
    if (tile_x >= 0 && tile_x < gs[+0x278] &&
        tile_y >= 0 && tile_y < gs[+0x27c]) {
        return (u8*)(gs[+0x270] + (gs[+0x278] * tile_y + tile_x) * 0x28);
    }
    return &DAT_1403dc390;  // OOB sentinel
}
```

| GameState offset | Meaning |
|---|---|
| `+0x270` | ptr to terrain grid (flat `width * height` array of 40-byte cells) |
| `+0x278` | `map_width` (in tiles). Already in this doc as `map_width` |
| `+0x27c` | `map_height` (in tiles). Already in this doc as `map_height` |

Each terrain cell is 0x28 = 40 bytes. Per-tile state: tile type, growth, owner, mod state, etc. (specific field offsets not yet derived).

Pattern-resolve `FUN_1401010d0` and expose as `vanilla.invoke "tile.lookup" {x, y}` for free terrain-cell access from tests.

### Object-placement vector on GameState

Distinct from MapState's building vector. Lives on GameState:

| Offset | Field | Cite |
|---|---|---|
| `+0x420` | `std::vector<u64>` begin (object placements; 8-byte stride pairs of `(tile_idx, something)`) | `:152927`, `:152944` |
| `+0x428` | end | `:152929`, `:152951` |
| `+0x430` | cap_end | `:152945` |

Set via `FUN_140101120(gs, tile_x, tile_y, param4)`. Pairs store `(width * y + x, param4)` at 8 bytes each. Likely a sparse-set of placed items on tiles (shovel-discoverable items, growth markers, mod-placed objects).

### Building object (entries in MapState +0x130 vector)

Each pointer in the building vector points to a Building object. Confirmed fields:

| Offset | Type | Field | Cite | Notes |
|---|---|---|---|---|
| `+0x1c8` | `u8` | flag | `:112884` | Set to 1 in iteration loop. Likely a "render dirty" or "needs spawn-check" flag. |
| `+0x1d4` | sub-struct | id / state | `:120430` | Address passed (with `+0x1d4` offset) to `FUN_1400b6610` cleanup. |
| `+0x204` | `u8` | "removed / disabled" flag | `:120483`, `:120429` | Set to 1 alongside removal from vector A at MapState+0xb8/+0xc0. When set, skip render. |

**Building tile-position accessor: `FUN_1400b4a10(Building*, out i64 *coord_pair) -> float*`** at RVA `0x1400b4a10`. Cited at `:25431`, `:25772`, `:26217`, `:31708`, `:31938`, `:120424`. The function fills `*coord_pair` with a packed `(tile_x, tile_y)` (`coord_pair._0_4_` and `._4_4_`) AND returns a `float*` pointing inside the building (probably the building's float-position field). Use via `vanilla.invoke` instead of guessing offsets:

```rust
let (tx, ty) = vanilla_invoke!(FUN_1400b4a10, building_ptr, &mut packed);
```

The Building **world position**, **gid (sprite id)**, and **type** fields are not yet mapped explicitly from decomp, but `FUN_1400b4a10` returns enough to find which TMX object corresponds to the live Building (match its tile pos against `tmx_objects.iter().map(|o| (o.x/32, o.y/32))`). The in-memory Building struct is only needed if we want to mutate live state (move a location, hide it, etc.).

### Horse / building name resolver: `FUN_1400cf970`

**`FUN_1400cf970(scene*, entity*) -> char*`** at RVA `0x1400cf970`. Returns the entity's display name. Body (`:121389-121427`):

```c
char* horse_name_resolver(scene*, entity*) {
    if (entity == null) return "Horse";
    int name_id = *(i32*)(entity + 0x1f8);
    if (name_id == -1) return "Horse";
    char *entry = (char*)((longlong)name_id * 0x88 + DAT_1403f34e0);
    // ... possibly call FUN_1400c7910 (no-record dialog?) if entry[+0x40] flag set
    if (*(ulonglong*)(entry + 0x18) > 0xf) entry = *(char**)entry;  // heap string when cap>15
    return entry;
}
```

- **`DAT_1403f34e0`** is the NAME_TABLE base (RVA). Already heap-resolved in production via custom resolver; this is the dev's eyeball reference RVA.
- Confirms `entity + 0x1f8` = name_id (matches HORSE name_id at +0x1f8 already documented).
- Returns "Horse" sentinel when entity is null or name_id is -1.

**`FUN_1400cf9a0`** at RVA `0x1400cf9a0` (28 B) is a sibling resolver. Needs separate look.

### Scene handler `+0x148` = currently selected / last-interacted entity (horse or NPC, NOT a Building)

**Correction (2026-05-17 round 5):** earlier rounds called scene-handler `+0x148` a "Building pointer". The horse-name-resolver evidence (`FUN_1400cf970` reads `entity+0x1f8 = name_id`, the HORSE name field) shows `+0x148` is more accurately an **entity pointer** (typically a horse, NPC, or proprietor). The "currently relevant entity" for the scene. In the Stable scene, it's the proprietor's horse. In the Glue scene, it's "Sweetie" (the proprietor whose name renders in `"Welcome to %s's Glues"`). The scene-table slot 0x90 documented as "Currently selected horse subsystem" is the same offset semantics generalized.

This also corrects an earlier claim: the function `FUN_1400d1dd0(scene, entity*) -> i32` walks `scene[+0x130]` doing pointer-equality search; it returns the entity's index. The vector contents type is scene-dependent (Buildings in the map scene, Horses in roster scenes, etc.), so call it `scene_entity_index` rather than the building-specific name.

### Scene handler `+0x148` legacy section (KEEP as the offset map, but the type is "entity" not "Building")

The "active scene" handler object has a `+0x148` slot that holds a Building pointer. The building the player most recently interacted with or has selected. Cited at `:120484` (`if (lVar6 == *(longlong *)(param_1 + 0x148))`) and several siblings. Combined with `FUN_1400b4a10` this answers "which location did the player just enter / click" without any pixel reads.

Other observed fields on the scene handler:
- **`+0x00`** = vtable (one per scene type; e.g. `&PTR_FUN_140304578` for Circus).
- **`+0x08`** = **scene_id** (i32). Set by the scene-handler factory `FUN_140113d70` (`:150815`: `*(int *)(scene + 8) = param_2`). Read this to identify any scene-handler without indirect lookups.
- **`+0x18`** = **display_name** (`std::string`, e.g. `"The Circus"`, `"CRISPR Lab"`). **This is the `%s` for `"Welcome to %s"`**. Read it directly without function calls. Set in the per-scene constructor via `FUN_1400278e0(scene+3, "The Circus")`. Cite `:31444`.
- **`+0x38`** = **internal_name** / type identifier (`std::string`, e.g. `"Circus"`, `"Crispr"`). The string the metadata setter uses to register the scene. Set via `FUN_1400278e0(scene+7, "Circus")`. Cite `:31445`.
- `+0x78` = pointer to a lookup structure used by `FUN_1400c56f0(tile_x, tile_y, lookup, 0)`. Likely a hashmap or sparse-set of "which tiles are interactable in this scene".
- `+0x118 / +0x11c` = world-pixel position pair (subtracted from camera to produce screen offset at `:80860`); likely the scene's anchor / camera-target world position.
- `+0x130 / +0x138 / +0x140` = `std::vector<Entity*>` (entities the scene tracks: Buildings in the map scene, Horses in roster scenes).
- `+0x148` = **selected / "currently relevant" entity pointer** (horse / NPC; see correction above).
- `+0x234` = bool "scene initialized" / "in-scene branch active".
- `+0x250` = u32 main state code (set to 2 after init).
- `+0x25c` = u32 sub-state (typically a tick counter / phase index).
- `+0x270` = bool "modal/dialog visible" (consumed at `:61997` with branches on different render path).

**Per-scene constructors** (e.g. `circus_metadata` at `0x1400379e0`) are the entry points: each registers a vtable and writes display_name / internal_name. Pattern-grep `FUN_1400278e0\(param_1 \+ 3,\s*"..."\)` to enumerate every scene constructor and its display name. The string literal IS the location's user-visible name.

### Complete location-handler enumeration (16 scenes)

All 16 scene constructors that set `display_name` at `+0x18` via `FUN_1400278e0(param_1 + 3, "...")`. Internal name (the scene-type key) is set via `FUN_1400278e0(param_1 + 7, "...")` and the vtable pointer is the first thing the constructor writes (`*param_1 = &PTR_FUN_<vtable>`).

| Display Name | Constructor RVA | Vtable RVA | Internal Name | TMX `type` |
|---|---|---|---|---|
| Old Abandoned Track | `0x14002cd80` | `0x140303168` | `Abandoned` | `abandoned` |
| O'er Yonder Acres | `0x14002f0f0` | `0x140303430` | `Acres` | `acres` |
| Normal Suburban House | `0x140030940` | (TBD) | `Biohacker` |. (early-game / facade variant?) |
| Bio-Hacker | `0x140033a10` | (TBD) | `Biohacker` | `biohackers` |
| The Circus | `0x1400379e0` | `0x140304578` | `Circus` | `circus` |
| The Jockey Club | `0x14003e720` | `0x140304e08` | `DAT_140304ed8` | `club` |
| Bubber's Hutch | `0x140064590` | (TBD) | `Hutch` | `hutch` |
| Junk Shop (debug) | `0x140067850` | `0x140308050` | `DAT_140308124` | `junk` |
| Power Plant | `0x140067e60` | `0x140309998` | `PowerPlant` | `powerplant` |
| Sumo Ring | `0x14007ad10` | `0x14030a658` | `DAT_14030a744` | `sumo` |
| Lasso-Mart | `0x14007dbf0` | `0x14030a810` | `DAT_14030a8dc` | `supply` |
| CRISPR Lab | `0x140088000` | (TBD) | `Crispr` | `crispr` |
| Clide's Rides | `0x14008de50` | `0x14030b6e8` | `CarLot` | `car lot` |
| Sue's Glues | `0x1400a6cb0` | `0x14030cde0` | `DAT_14030ceac` | `glue` |
| Sweetie's House | `0x1400f4ea0` | (TBD) | `Sweetie` | `sweetie` |
| The Secret Zoo | `0x1401123f0` | `0x140313bd0` | `DAT_140313ca0` | `zoo` |

Vtables marked `(TBD)` were not in the snippet excerpts; trivially recoverable by reading the constructor's first store-instruction.

**The two `"Biohacker"` internal-name entries** ("Normal Suburban House" and "Bio-Hacker") suggest a game-phase variant: the location renders as "Normal Suburban House" early on, then transitions to "Bio-Hacker" after some progression. Worth confirming live but documented for now.

**TMX `type` -> scene resolution recipe**: parse the TMX object, take `type` attribute, lowercase, compare against the internal_name (case-insensitive). e.g. TMX `type="circus"` -> internal_name `"Circus"` -> constructor `0x1400379e0` -> vtable `0x140304578` -> all scene state and methods.

TMX object `type` attributes without a constructor here (paddock, track, race-track, paradise, ecologist, hacienda, bobs, willaby, mabels, surebreed, circled, vial-world, hermit, saloon) are either:
- Not separate scenes (decoration only); player interaction stays on the world map.
- Sub-objects of the scenes above (e.g. `paddock` is part of the race-track scene; `mabels/bobs/willaby/surebreed/hacienda` are likely NPC homes inside the Stable / Saloon scene).
- `hermit` and `paradise` may be unique-event scenes with different construction patterns.

To pattern-resolve these scene constructors, the `FUN_1400278e0(param_1 + 3, "<name>")` site IS the anchor: any literal-string-write recipe finds them.

TMX object `type` attributes without a constructor here (paddock, track, race-track, paradise, ecologist, car lot, hacienda, bobs, willaby, mabels, surebreed, circled, vial-world, hermit, saloon) are either:
- Not separate scenes (decoration only); player interaction stays on the world map.
- Sub-objects of the scenes above (e.g. `paddock` is part of the race-track scene; `mabels/bobs/willaby/surebreed/hacienda` are likely NPC homes inside the Stable / Saloon scene).
- `hermit` and `paradise` may be unique-event scenes with different construction patterns.

To pattern-resolve these scene constructors, the `FUN_1400278e0(param_1 + 3, "<name>")` site IS the anchor: any literal-string-write recipe finds them.

### Terrain cell layout (40 bytes each at `GS+0x270`)

Returned by `FUN_1401010d0(GS, tile_x, tile_y) -> u8*`. First field is the tile type:

| Offset | Type | Field | Cite | Observed values |
|---|---|---|---|---|
| `+0x00` | `u32` | tile_type | `:76993`, `:77002`, `:77009`, `:83018` | 3, 4, 6, 13 (0xd), 14 (0xe), 20 (0x14). See type names below. |

Remaining 36 bytes hold per-tile state (growth, owner, mod flag, etc.); offsets not yet derived.

**Terrain-type name table** lives at RVA `0x1403dc340` (`PTR_s_Plain_1403dc340`). It is a 10-entry `char*` array (80 bytes) iterated at `:152149-152174` (`do { ... } while (u < 10)`). So **there are exactly 10 terrain types** indexed 0-9. The first is `"Plain"`. Read the rest at runtime via `patterns.read_bytes` on the 80-byte table to enumerate them all.

Named terrain handlers known so far:

| Type name | Handler RVA | Notes |
|---|---|---|
| `Plain` | `0x1400ffd00` | `plain_tile_handler` (565 B). Default walkable. |
| `Grass` | `0x1401003e0` | `grass_tile_handler` (454 B). |
| `GifLand` | `0x14005bad0` | Possibly an animated terrain tile. |
| `Water` |. | String `s_Water_14030a274` referenced at several sites; handler RVA TBD. |

Cross-mapping tile_type integer codes to type names requires reading the 10-pointer table at runtime; recommended R3-style task. Walkable test at `:77009` (`if (*piVar3 != 4) return 0;`) suggests `4 == Plain` or similar; verify by inspection.

### Where is the player's home / barn / pasture? (CONFIRMED 2026-05-17)

**Both questions answered (2026-05-17, live test):**

**Q1: WHERE on the world map is the player's home?** ANSWERED.

The player's home position is the TMX object `<object id="6" type="home" gid="97" x="3040" y="3712"/>`. Sprite `LocStable` variant 0 (the first of 8 stable-sprite variants). On the world map the player walks/drives up to this tile.

**Q2: When the player CLICKS that home, which `active_scene_id` do they enter?** **CONFIRMED: `active_scene_id = 0`.**

User entered their home in-game 2026-05-17; the new in-game "Where Am I" panel reported `active_scene_id: 0` AND `scene+0x08 (self-id): 0`. The scene was resolved via `GS[+0x438] + 0*8` = scene-table slot 0, which is already documented in this doc as the **owned-horse / home subsystem**. Consistent.

This means:

- **Scene-table slot 0 holds the player's home/stable scene-handler**, not just the owned-horse list. The "owned horses" we already document at slot 0 are the horses that live AT the home; the scene-handler at slot 0 is the home scene itself when entered.
- **scene_id 0 is special-case in the dispatcher**: the factory at `FUN_140113d70` (`:150670-:150816`) only handles scene_ids 13+, so scene_id 0 (home) is NOT constructed there. It must be allocated during game init / save load via a different path. Since it is foundational state, it lives across the entire save and is not torn down between location visits.
- **The scene_id 21 ("Stable") hypothesis was wrong.** Scene 21 may be an NPC-stable scene (Bob's, Mabel's, etc.) or something else; needs separate verification by entering an NPC stable in-game.

(Outstanding for full identification: the panel also shows `scene+0x18` display name and `scene+0x38` internal name. Not yet captured. User to report next.)

### Original investigation notes (kept for context; SUPERSEDED by confirmation above)

Best initial candidate had been **scene_id 21** (`FUN_140057c20`, alloc 0x2e0 = 736 bytes). Reasons:

- Display + internal name set from `&DAT_140305758` (not a literal. Consistent with a *dynamic* proprietor-name slot rather than a fixed location label like "CRISPR Lab").
- Body has **20+ `FUN_1400c9c30` slot registrations** (interactable hotspots), more than any other named scene. Consistent with a stable having grazing slots + breeding slots + storage slots etc.
- The stable sprite has 8 variants and there are exactly 8 TMX objects using stable-sprite variants:

| TMX type | gid | Variant | Owner |
|---|---|---|---|
| `home` | 97 | LocStable_0 | **PLAYER** |
| `willaby` | 98 | LocStable_1 | NPC Willaby |
| `circled` | 99 | LocStable_2 | NPC |
| `bobs` | 100 | LocStable_3 | NPC Bob |
| `mabels` | 101 | LocStable_4 | NPC Mabel |
| `surebreed` | 102 | LocStable_5 | NPC Surebreed |
| `hacienda` | 103 | LocStable_6 | NPC |
| `paradise` | 104 | LocStable_7 | NPC |

A single stable scene parameterized by proprietor would explain why we don't see 8 separate constructors with "Stable" in the display string. The scene takes its display name from whichever building's proprietor was clicked.

**To confirm scene_id 21 is the stable scene**, do one of:

1. **Use the in-game Debug tab "Where Am I" panel** (added 2026-05-17). Enter the player's home in-game; the overlay shows live `active_scene_id` + the scene-handler's display/internal/self-id strings. Reports without guessing. Backing module: [`src/scene.rs`](../src/scene.rs); UI: `render_where_am_i` in [`src/overlay.rs`](../src/overlay.rs).
2. **Read the .rdata string** at RVA `0x140305758` via `patterns.read_bytes`. If it's empty / placeholder, confirms dynamic proprietor naming. If it says something like "Stable" / "Home" / "Barn", confirms identity.
3. **Walk `FUN_140057c20` body** for proprietor-name patterns (look for hashes / lookups against the 8 NPC names).

Other candidates for the stable scene (less likely):

- scene_id 15 (`FUN_14005bf10`, 600 B). Display `&DAT_140306538`; cross-references suggest this is a 4-char terrain name (used for tile_type 14 labeling at `:157722`), not a stable.
- scene_id 19 (`FUN_1400bfa90`, 1160 B). Display `&DAT_14030daf0` is a 3-char string; annotation calls this function `tmx_object_property_parser` (1970 B) but the body looks like a constructor. Possibly does double duty.
- scene_id 38 (`FUN_14005e310`, 624 B). Empty display; body constructs a horse with a specific DNA literal. Looks like a CRISPR sub-scene, not a stable.
- scene_id 47 (`FUN_14005bad0` `gif_land_handler`). Terrain handler per BATCH-12.

**Sweetie's House (scene_id 28) is NOT the player's home.** That row in the scene table represents Sweetie's NPC home (a separate TMX object at `type="sweetie" gid=125 x=3264 y=3680`). The player can visit it but it is not where their pasture and breeding live.

**Note**: an earlier round of these docs claimed "player's home IS the overworld (active_scene_id == -1)". That was wrong. The user clarified that clicking on the home building on the world map transitions to a real scene with its own scene_id. Section has been rewritten accordingly.

### Breeding state machine (`FUN_1400e0aa0`) runs INSIDE the stable scene

`FUN_1400e0aa0 breeding_state_machine` (6908 B, annotated at `research/decompiled/annotated/0x1400e0aa0_breeding_state_machine.c`). Invoked from the stable scene (most likely scene_id 21) when the player initiates a mating. Drives the BarnDoorClose / BarnMating animation sequence and applies the litter at the final frame. State fields per the annotation:

- `param_1[0x88]` (offset 0x440) = parent A horse pointer
- `param_1[0x89]` (offset 0x448) = parent B horse pointer
- `param_1[0xf]` = the barn building object (TMX `home`)
- `param_1 + 0x254` = frame counter
- `param_1 + 0x461` = "doors closing" flag (set at frame 0x1e = 30)
- `param_1 + 0x462` = "active mating" flag (1 = will produce offspring; 0 = canceled, e.g. same-species check failed)

Per-horse fields during breeding:
- `horse + 0x1c` = type/species (compared to 2, 4, 6)
- `horse + 0x207` = "in breeding" byte flag (set to 1 on both parents at frame 30)
- `horse + 0x254` = litter_size_stat (already documented)

Litter size calculation: `children = min(parentA.litter_size_stat, parentB.litter_size_stat) + (rand_20 == 0 && sleeps > 1 ? 1 : 0)`. Per the annotation, vanilla allele values are g0=1, g1=2, g2=3, g3=5. Hooking this state machine lets the mod observe every breeding event in detail.

### Scene-handler factory + complete scene_id table

**`FUN_140113d70`** (the function containing the dispatch at `:150670-150816`) is the **scene-handler factory**: `(?, int scene_type_id) -> Scene*`. It dispatches on `scene_type_id`, allocates the right-sized struct via `FUN_1402c704c(size)`, calls the type-specific constructor, then stores `*(int *)(scene + 8) = scene_type_id` (so each scene self-identifies).

**This gives us TWO fundamental new facts:**

1. **`scene_handler + 0x08` = scene_id** (i32). Read this field to identify any scene-handler.
2. The **complete scene_id <-> constructor mapping** is hard-coded in this dispatcher. Below is the full table mined from `:150670-:150811`:

| scene_id | hex | Alloc size | Constructor RVA | Scene |
|---|---|---|---|---|
| 13 | `0xd` | 1000 | `FUN_14008f6e0` | (`paddock_track_metadata`. Paddock + Race Track) |
| 14 | `0xe` | 0x2d0 (720) | `FUN_14005fad0` | (unknown. The "broke" variant of scene 13?) |
| 15 | `0xf` | 600 | `FUN_14005bf10` | (unknown / sub-handler) |
| 16 | `0x10` | 0x4d8 (1240) | `FUN_140088000` | **CRISPR Lab** |
| 17 | `0x11` | 0x288 (648) | `FUN_1400a6cb0` | **Sue's Glues** |
| 18 | `0x12` | 0x270 (624) | `FUN_14008de50` | **Clide's Rides** |
| 19 | `0x13` | 0x488 (1160) | `FUN_1400bfa90` | (overlaps with `tmx_object_property_parser` annotation. Worth re-investigating) |
| 20 | `0x14` | 0x310 (784) | `FUN_14007dbf0` | **Lasso-Mart** (confirmed 2026-05-17 live) |
| 21 | `0x15` | 0x2e0 (736) | `FUN_140057c20` | (unknown / sub-handler) |
| 22 | `0x16` | 0x328 (808) | `FUN_140064590` | **Bubber's Hutch** |
| 23 | `0x17` | 0x2268 (8808) | `FUN_1400379e0` | **The Circus** (largest scene struct) |
| 24 | `0x18` | 0x250 (592) | `FUN_1401123f0` | **The Secret Zoo** |
| 25 | `0x19` | 0x278 (632) | `FUN_14002f0f0` | **O'er Yonder Acres** |
| 26 | `0x1a` | 0x2f0 (752) | `FUN_140069ee0` | (unknown / sub-handler) |
| 27 | `0x1b` | 0x288 (648) | `FUN_140067e60` | **Power Plant** |
| 28 | `0x1c` | 0x288 (648) | `FUN_1400f4ea0` | **Sweetie's House** (also the special teleport-target case at enter_location handler `:154987`) |
| 29 | `0x1d` | 0x2b0 (688) | `FUN_14007ad10` | **Sumo Ring** |
| 30 | `0x1e` | 0x250 (592) | `FUN_140067850` | **Junk Shop (debug)** |
| 31 | `0x1f` | 0x6b8 (1720) | `FUN_140030940` | **Normal Suburban House** (early-game Biohacker facade) |
| 36 | `0x24` | 0x250 (592) | `FUN_14003e720` | **The Jockey Club** |
| 37 | `0x25` | 0x288 (648) | `FUN_14002cd80` | **Old Abandoned Track** |
| 38 | `0x26` | 0x270 (624) | `FUN_14005e310` | (unknown) |
| 47 | `0x2f` | 600 | `FUN_14005bad0` | (`gif_land_handler` per BATCH-12; likely an animated terrain type or sub-handler) |

(scene_ids in gaps 32-35, 39-46 don't appear in the dispatcher. Those scene_ids are unused or handled by a different path.)

Cross-references the earlier-found `Bio-Hacker` constructor (`0x140033a10`, `biohacker_lab_handler`): NOT in this dispatcher. It is likely allocated through a different path (perhaps a transformation of the Normal Suburban House scene_id 31 when the player progresses). This matches the "Biohacker" internal_name being shared between `0x140030940` and `0x140033a10`.

### Scene-id enumeration (the `active_scene_id` semantic decode)

`GS+0x25C` is `active_scene_id` (i32, `[-1, 256)`). The enter-location handler `FUN_1401046c0(GameState*, int scene_id, char suppress_sound)` indexes into the scene table by `scene_id`:

```c
*(longlong *)(*(longlong *)(GS + 0x438) + scene_id * 8)
```

So **scene_id maps directly to scene-table slot offset / 8**. Cross-reference with the scene-table inventory below.

Decoded from the enter-location handler body (`:154987-154992`) + cross-referenced with the scene-handler factory table above + live test (2026-05-17):

| scene_id | hex | Behavior |
|---|---|---|
| **0** | **0x0** | **PLAYER HOME (stable / pasture / breeding).** Confirmed live 2026-05-17 via Debug "Where Am I" panel. Scene-handler lives at scene-table slot 0 (same slot as the owned-horse list). Special-cased outside the factory dispatcher; allocated at game init / save load. |
| 1-12 | 1..0xc | Specific named locations; play a per-location sound (`EnterLocationStable`, etc.) instead of the generic `EnterLocation`. **NOT in the factory dispatcher** (factory starts at scene_id 13). These must be allocated elsewhere or are reserved for race-lane sub-scenes (slot offsets 0x08-0x60 = race lanes 0-11). |
| 13 | 0xd | **Paddock + Race Track** (`FUN_14008f6e0`). Money-gated swap: if `GS+0x308 (money) < 1`, swap to scene 14. The track-entry has an entry fee. |
| 14 | 0xe | The "broke" variant of scene 13 (`FUN_14005fad0`). |
| 16 | 0x10 | CRISPR Lab. |
| 17 | 0x11 | Sue's Glues. |
| 18 | 0x12 | Clide's Rides. |
| 20 | 0x14 | Lasso-Mart. (confirmed 2026-05-17 live) |
| 22 | 0x16 | Bubber's Hutch. |
| 23 | 0x17 | The Circus. |
| 24 | 0x18 | The Secret Zoo. |
| 25 | 0x19 | O'er Yonder Acres. |
| 27 | 0x1b | Power Plant. |
| 28 | 0x1c | **Sweetie's House**. Special handling at enter handler (`:154976-154981`): sets truck `+0x38 = -1` and offsets truck pos by constants. Likely the player's home base / teleport-target. |
| 29 | 0x1d | Sumo Ring. |
| 30 | 0x1e | Junk Shop (debug). |
| 31 | 0x1f | Normal Suburban House (Biohacker facade). |
| 36 | 0x24 | The Jockey Club. |
| 37 | 0x25 | Old Abandoned Track. |

Per-scene strings observed in the EnterLocation switch: only scenes 1-12 use specific sounds; 0 and 13+ fall through to generic `EnterLocation`.

The scene_id -> location-name mapping is reachable via the `"Welcome to %s"` resolver (`FUN_1400d1c40` line 84711) which takes the active building pointer and resolves its name. One indirection from a free `scene_id -> name` table.

### Enter-location handler internals

`FUN_1401046c0(GameState*, int scene_id, char suppress_sound)`. RVA `0x1401046c0`. Key field touches (cite `:154943-155015`):

| Action | Field | Notes |
|---|---|---|
| Lookup scene-table slot | `GS[+0x438] + scene_id*8` | Abort if null. |
| Read scene_id-specific anchor float | `slot[+0xc]` | Scene anchor y-coord (or similar). |
| Read scene_id-specific anchor pair | `slot[+0x10]` | Scene anchor x-coord. |
| Call `FUN_1400fb8c0(truck, packed_xy)` | Truck `+0x300` | Move/anchor truck to scene position. |
| Special-case `scene_id == 0x1c` | Truck `+0x38, +0x28, +0x2c` | Set state flag = -1; offset position by `DAT_1403033a8` and `DAT_14039ca44`. |
| Money-gate `scene_id == 0xd` | `GS+0x308` | Swap to 0xe if money < 1. |
| Auto-save trigger | `if (active_scene_id == -1 && DAT_1403d9524 && !suppress_sound)` | Calls `FUN_14006dc80(GS, 1)` (the save handler we already know). |
| Active-handler validation | `slot.vtable[+0x18](slot)` | "Can enter" check; if returns 0, abort. |
| Sound dispatch | `s_EnterLocation_1403137e0` (base) + variant per scene_id | Plays via downstream audio func. |

**This tells us the active scene-handler IS the scene-table slot** at `GS[+0x438][scene_id*8]`, where scene_id == active_scene_id. We can read `scene_handler+0x148` (selected building) by walking from `GS+0x438 + active_scene_id*8 -> deref`.

### Map / scene event handlers (from annotated decomp)

High-leverage functions for agent state. Each has a clear string anchor making them easy to pattern-resolve, and each is small enough to hook safely. Source: `research/decompiled/annotated/BATCH-*.md`.

| RVA | Name | Strings / anchor | Use case |
|---|---|---|---|
| `0x14009d750` | **`cursor_input_handler`** (1577 B) | `Pointer` | THE cursor dispatcher. Clicks, drags, hovers all flow through here. Hook to know "where is the cursor + what did the player just click/drag". |
| `0x1400d1c40` | **`dialog_enqueue`** (~210 B) |. | `(scene, entity, format_str, va_args...)`. Enqueues a dialog line bound to an entity (horse / NPC). ALL in-scene text flows through here (`"Welcome to %s"`, `"%s's Rides"`, `"That's a tired looking horse!"`, etc.). Hook to capture every dialog the game shows. Internally substitutes `%s` via `FUN_1400cf970` (the name resolver). |
| `0x1401041f0` | **`exit_to_overworld`** | `s_World_14030a640` | `(GameState*) -> void`. The exit-scene function. Same as clicking the in-scene `Map` button at top-right. Sets `GS+0x25C = -1`, zeroes scene state (`+600`, `+0x36c`, `+0x3c4`, `+0x1f8`, `+0x3a8`, `+900`, `+0xd0`), triggers auto-save when `GS+0x254 != 0` and `DAT_1403d9524 != 0`, plays `"World"` sound, calls `FUN_140104370` (scene tear-down) + `FUN_1400a89f0(truck)` (resume truck driving). Cite `:154755`. **Registered in `targets_registry.rs` as `EXIT_TO_OVERWORLD`** with signature `(*GameState) -> void`; callable via `vanilla.invoke "EXIT_TO_OVERWORLD"` or the wrapper op `game.exit_to_overworld`. |
| `0x1400d1dd0` | **`scene_entity_index`** (57 B) |. | `(scene, entity*) -> i32`. Linear-search index of an entity in `scene[+0x130]`, or -1. Generic (vector content type is scene-dependent). |
| `0x1400cf970` | **`horse_name_resolver`** (~120 B) |. | `(scene, entity*) -> char*`. Resolves entity name via `entity[+0x1f8]` (name_id) -> NAME_TABLE lookup. Returns `"Horse"` sentinel for null / -1. |
| `0x1400cf9a0` | sibling resolver (28 B) |. | Tiny sibling of above; signature/purpose TBD. |
| `0x1400379e0` | `circus_metadata` (850 B) | `Circus`, `"The Circus"` | Per-location metadata setter (Circus). |
| `0x14008f6e0` | `paddock_track_metadata` (804 B) | `Paddock`, `"Race Track"`, `Track` | Per-location metadata setter (Paddock + Race Track). |
| `0x14002cfc0` | `location_metadata` (670 B) |. | Another metadata setter (unidentified location). |
| `0x14007b2e0` | **`sumo_match_handler`** (5750 B) | `GongWoodLight`, `LerpHorse`, `SumoBattle`, `World`, `"rabbit"` | Full Sumo scene state machine. |
| `0x140033a10` | **`biohacker_lab_handler`** (6233 B) | `Bio-Hacker`, `Biohacker`, `BiohackerDoorOpen`, `Drain`, `GarageDoorOpen` | Full Bio-Hacker Lab scene state machine. |
| `0x1400fd580` | **`pause_top_level_dispatcher`** (2159 B) | `EcoFaster`, `EcoSlower`, `EcoZoomIn`, `EcoZoomOut`, `Pause` | Pause-menu top-level state machine. Eco/speed/zoom controls. |
| `0x1400cd2d0` | `pointer_attach_handler` (640 B) | `PointerAttach` | Cursor mode change (attached to a horse/object). |
| `0x1400cd5a0` | **`truck_enter_location_handler`** (1326 B) | `TruckEnterLocation` | Fires when the truck animates into a location (transition START). |
| `0x1401046c0` | **`enter_location_handler`** (1004 B) | `EnterLocation`, `EnterLocationStable` | Fires when the player ACTUALLY enters (scene transition). **Triggers auto-save on entry.** Hook for "scene change" notifications. |
| `0x1400cdae0` | `drop_horse_fail_event` (733 B) | `DropHorseFail`, `TruckLeaveLocation` | Truck leaves a location / failed-drop event. |
| `0x1400fa910` | `unzoom_truck_action` (1539 B) | `UnzoomTruck` | Truck zoom-out animation handler. |
| `0x140104df0` | `truck_handler` (260 B) | `truck` | Small truck state handler. |
| `0x14008f130` | **`welcome_dialog`** (459 B) | `"Welcome to %s"` | Location-entry welcome dialog. Format-string xref reveals the location-name lookup function (free name resolver). |
| `0x14008f130` -> location name | derived |. | The `"Welcome to %s"` `%s` argument is the location-name resolver. One xref away from a free LocationId -> name string mapping. |
| `0x14002d7c0` | **`track_state_machine`** (4033 B) | `CrossFinishLine`, `EnterLocationPaddock`, `RaceGetSet`, `Racing`, `TruckEnterLocation`, `TruckLeaveLocation`, `WonRace` | THE race lifecycle state machine (per BATCH-02 ## 29). Hook for race-phase notifications. State: `+0x250` (main, =2 = race-active), `+0x254` (tick counter; milestones at 0x87, 0xa5). |
| `0x14010a5e0` | **`hot_air_balloon_controller`** (5188 B) | `BalloonDisabled`, `BalloonDown`, `BalloonSimFaster`, `BalloonSimSlower`, `BalloonUp`, `LassoMiss`, `LiftOff`, `LiftOn`, `SelectInv`, `SmashFence` | Full hot-air-balloon scene controller. `BalloonSimFaster` = the 300x sim-speed cheat (press `5` in balloon, per JumboDS64). |
| `0x14007e030` | **`hint_dispatcher`** (3320 B) | `BuyItem`, plus ~12 NPC hint strings ("I saw wild horses south west", "Try betting on horses", "Why not go home and rest", "You can't afford that", etc.) | The NPC-and-world hint-dialog dispatcher. **Hook this** to capture every NPC hint the game emits. |
| `0x1400d0c80` | `npc_dialog_with_speech_variants` (4008 B) | `" *hic*"`, `Dialog`, `"orses"`, `"orshes"` | NPC speech variants (drunk slurring in the saloon). Distinct from `dialog_enqueue`. This handles delivery, that handles enqueueing. |
| `0x1400fd580` | **`top_level_map_loader`** (already R-tier resolved as `GAMESTATE_PTR` anchor) |. | THE top-level map loader (calls `tmx_parse_layer` per layer). Allocates GameState 0x448-byte struct; this is why GAMESTATE_PTR is anchored on it. NOT the same as `tmx_parse_layer` (next row). |
| `0x1400fe2e0` | **`tmx_parse_layer`** (5277 B). Previously labeled `TMX_MAP_PARSER` in `targets.rs` | `height`, `objectgroup`, `offsetx`, `offsety`, `terrain`, `value`, `width` | Parses ONE Tiled `.tmx` layer. Called by `top_level_map_loader` per layer. **Naming correction**: our `TMX_MAP_PARSER` target is actually the per-layer parser, not the top-level loader. The top-level loader is `FUN_1400fd580`. Consider renaming or adding `TMX_TOP_LEVEL_LOADER` as a separate target. |
| `0x140088000` | `crispr_lab_metadata` (775 B) | `"CRISPR Lab"`, `Crispr` | Per-location metadata setter. There is one of these per location. Pattern-grep `BATCH-07.md` for "Location metadata setter" to enumerate. |
| `0x1400693b0` | `power_plant_handler` (1207 B) |. | Power plant location handler. |
| `0x1400bfa90` | **`tmx_object_property_parser`** (1970 B) | `" react"`, `"shape"`, `buried` (documented elsewhere) | Parses TMX `<properties>` children. Tells us what custom property names are valid on TMX objects. |
| `0x140076a10` | **`parse_command_line_flags`** (3488 B; already resolved as `SETTINGS_XML_HANDLER`) | `autoload`, `autosave`, `debug`, `escquits`, `hidpi`, `labpop`, `log_races`, `log_stables`, `log_world`, `music`, `savestress` | Full CLI flag parser. See [`CONTENT-CREATION.md`](CONTENT-CREATION.md) for usage; expose `log_world`/`log_stables`/`log_races` to harvest extra debug state. |
| `0x1401003e0` | `grass_tile_handler` (454 B) | `Grass` | Grass terrain type. |
| `0x1400ffd00` | `plain_tile_handler` (565 B) | `Plain` | Plain terrain type. |
| `0x14005bad0` | `gif_land_handler` | `GifLand` | Possibly an animated terrain tile. |
| `0x14010d260`, `0x14010d600`, `0x140084060`, `0x140083480`, `0x140083b50` | various `tile_helper` |. | Per-tile-type sub-handlers. |
| `0x140037710` | `dialog_helper` (608 B) |. | Generic dialog/text helper. |
| `0x1400cce00` | `text_drawing_helper` (728 B) |. | Text/dialog drawing. |
| `0x140067330`, `0x140067560`, `0x140067490` | pause-menu button widgets |. | UI button widgets in the pause menu. Useful for synthetic-input-driven menu testing. |
| `0x140080e40` | `wild_horse_ai_step` (1972 B) |. | Wild-horse AI per-tick step. |
| `0x140102df0` | `wild_horse_spawn_helper` (1621 B) |. | Wild-horse spawn. |
| `0x140102060` | `wild_horse_target_picker` (1225 B) |. | Wild-horse pathfinding target. |
| `0x140033a10` | `price_or_score_formula` (already key-funcs annotated) |. | Horse price / race-score formula. |
| `0x14010d7e0` | `tile_random_picker` (1413 B) |. | Random tile picker. Useful for spawn-location logic. |

For the full taxonomy of annotated functions, grep `research/decompiled/annotated/BATCH-*.md` directly.

### Generic actor pose pattern (Truck, Horses, NPCs)

The Truck struct layout (`+0x28/+0x2c` pos, `+0x30/+0x34` vel) is the **generic actor pose** shared by all movable scene entities. Cited at `:25431` (passing horses through the same pos accessor pipeline as buildings), `:99840` (`FUN_1401010d0(GS, (int)(*(float*)(actor + 0x28) * DAT_140303fb4), ...)`), `:153692` (horse-vs-horse position compare uses `+0x28/+0x2c`). Useful corollary: reading any movable scene actor's pos uses the same code path. Horse positions, NPCs, the truck, all share offset layout for `(pos_x, pos_y, vel_x, vel_y)`.

The `DAT_140303fb4` scale constant converts these `+0x28/+0x2c` floats to tile indices. Not initialized inline in decomp (lives in `.rdata`); read at runtime once and cache. Pervasive (~62 references in decomp).

### World->screen projection (closed)

With camera_x / camera_y at MapState `+0x254` / `+0x258`, projection is:

```
screen_x = (world_x - camera_x) * zoom + screen_offset_x
screen_y = (world_y - camera_y) * zoom + screen_offset_y
```

Zoom + screen_offset are TBD but derivable from the existing HK1 5-point calibration (`tests/input_hk1_calibration.rs`): each calibration point gives `(world_x, world_y) -> (screen_x, screen_y)` at a known camera, so two points fully constrain (zoom, screen_offset). If zoom is fixed at 1.0 (likely for Horsey), one point suffices.

The world map (locations, sprites, tile grid) does NOT live in memory in any structured form we need to walk; it lives in `<steam>\steamapps\common\Horsey Game\data\horsey.tmx` and `data/locs.xml` / `data/locs.png`. See [`world-map-detection.md`](world-map-detection.md) findings 1-3.

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
| `horse_ptr+0x258` | u32 | n/a | race flags (bits `0x100` "in starting gate?" and `0x400000` "race-eligible/active?" observed in `track_state_machine`) | `all_functions.c:25895`, `:25898` |
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
