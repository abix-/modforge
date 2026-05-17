# World-map location detection

> **Status:** design (proposed 2026-05-17). Not yet shipped. First
> consumer for the [`modforge::screen` axis](../../modforge/docs/screen-axis.md).
> Authoritative on how horsey-mod decides which location is on screen,
> which icon the cursor is hovering, and what the player's current
> world-map context is.

## The problem

For Claude (or any operator) to navigate Horsey at the level of "go to
the circus, then to the racetrack," we need to answer:

1. **Are we on the world map, or inside a location?**
2. **If on the world map, which location icons are visible and where?**
3. **Which location is the cursor pointing at right now?**

Internal state answers (1) for free. The game answers (3) only via a
hover-tooltip rendered to pixels. Not exposed as a queryable field.
That makes (2) and (3) a vision problem.

## Research findings (2026-05-17): Layer 0 is mostly TMX-on-disk

A 1-hour decomp/asset audit answered the Layer 0 questions BETTER than
expected: most of what we want is in a static asset file on disk, not
in memory. Findings, in order of leverage:

### Finding 1: The world map is a Tiled `.tmx` file on disk

`<steam>\steamapps\common\Horsey Game\data\horsey.tmx`. 400 x 225
tiles at 32 px = 12800 x 7200 px world. Two tilesets:

- `terrain.tsx`. Terrain tiles (firstgid 1).
- `locs.tsx`. Building / location sprites (firstgid 97). Actually
  shipped as `data/locs.xml` (TextureAtlas format, not Tiled's `.tsx`).

The map renders by reading this file at game startup via
`TMX_MAP_PARSER` (`FUN_1400fe2e0` at RVA `0x1400fe2e0`, already
registered in `targets_registry.rs`). **We can parse the same file
ourselves with any XML parser.** No memory walking required for the
static location list.

### Finding 2: Every location is an object in the TMX Objects layer

The `<object>` entries carry all the structured data we want, e.g.:

```xml
<object id="6"  type="home"       gid="97"  x="3040" y="3712" width="32" height="32"/>
<object id="7"  type="track"      gid="110" x="3168" y="3712" width="32" height="32"/>
<object id="12" type="crispr"     gid="113" x="3872" y="3872" width="32" height="32"/>
<object id="18" type="sumo"       gid="126" x="3680" y="4128" width="32" height="32"/>
<object id="28" type="powerplant" gid="124" x="5664" y="3872" width="32" height="32"/>
<object id="29" type="paradise"   gid="104" x="8096" y="4896" width="32" height="32"/>
<object id="66" type="circus"     gid="120" x="2464" y="3520" width="32" height="32"/>
<object id="64" type="hermit"     gid="112" x="11392" y="3616" width="32" height="32"/>
```

The vanilla map ships with ~30 named locations (home, track, paddock,
sweetie, crispr, circus, sumo, powerplant, glue, supply, ecologist,
hutch, acres, saloon, car lot, zoo, biohackers, club, hermit,
paradise, plus several event/decor objects like fest-horse, tiger,
moose, alligator, giraffe, impala, vial-world). For each:

- `type`. Canonical semantic name; use as the LocationId/key.
- `gid`. Tile id into `locs.tsx` (sprite to render). Includes
  variant offsets when sprites have `c="N"` multi-frame counts.
- `x`, `y`. World pixel coordinates (top-left of the 32x32 tile).
- `id`. TMX object id; not semantically meaningful beyond uniqueness.

This is the same source-of-truth the game itself uses. Parsing it gives
us a complete labeled list with one `quick-xml` dependency.

### Finding 3: Sprite atlas is also static + labeled

`locs.xml` (TextureAtlas):

```xml
<sprite n="LocStable"  x="0"   y="0"  w="32" h="32" c="8"/>
<sprite n="LocTrack"   x="0"   y="32" w="32" h="32" c="6"/>
<sprite n="LocCrispr"  x="0"   y="64" w="32" h="32"/>
<sprite n="LocCircus"  x="224" y="64" w="32" h="32"/>
<sprite n="LocPowerPlant" x="96" y="96" w="32" h="32"/>
...
```

35 sprites total. `c="N"` is the variant count (LocStable has 8
sub-sprites at consecutive gids 97-104). The combined `(sprite n,
variant_offset, atlas_xy)` plus the corresponding cropped 32x32 from
`data/locs.png` gives us the visual template library for EVERY
location, free of charge, with no auto-collect loop. We just slice
`locs.png` into 32x32 chunks at the atlas coords.

This subsumes the original "auto-collect via scripted clicks" plan;
the templates are already labeled assets shipped with the game.

### Finding 4: GameState and MapState are separate singletons

The TMX parser allocates a 0x268-byte struct and stores its pointer at
`DAT_1403f4e00`. This is **MapState**. A distinct singleton from
**GameState** (`DAT_1403fb0d8`).

- `DAT_1403fb0d8` (GameState). Player progress, money, year, owned
  horses, scene table at +0x438, etc. Already in HORSE-PLACES.md.
- `DAT_1403f4e00` (MapState). The TMX-loaded world. Vtable at +0x00
  (with methods at +0xb0, +0xb8 observed). Field +0x254 is a float
  (likely a camera-related state). Field +0x262 is a bool/flag (gates
  several behavior branches across 5+ call sites; likely "map loaded"
  or "in world map view"). 0x268 bytes total.

`DAT_1403f4e00` is not yet in `targets_registry.rs` and not in
HORSE-PLACES.md. Adding it is the first concrete follow-up.

### Finding 5: Camera / viewport CONFIRMED at MapState +0x254 / +0x258

**Camera state resolved 2026-05-17.** MapState (`*DAT_1403f4e00`) field map:

- `+0x254` = camera_x (float, world pixels). Cited `all_functions.c:80862`, `:120224`
- `+0x258` = camera_y (float, world pixels). Cited `:80862`, `:120223`
- `+0x262` = bool "buildings loaded" / "map active". Gates many code paths

Smoking-gun cite at line 80860-80862 (truck movement / camera-anchor
update path):

```c
FUN_1400cf540(param_1, 0,
  *(float*)(param_1 + 0x118) - *(float*)(DAT_1403f4e00 + 0x254),  // dx
  *(float*)(param_1 + 0x11c) - *(float*)(DAT_1403f4e00 + 0x258),  // dy
  *(float*)(DAT_1403f4e00 + 0x254),                                // camera_x
  *(float*)(DAT_1403f4e00 + 0x258));                               // camera_y
```

Render path at `:120245-120248` writes the textbook 4-float viewport
record `[obj_x - camera_x, obj_y - camera_y, camera_x, camera_y]`.

World->screen projection:

```
screen_x = (world_x - camera_x) * zoom + screen_offset_x
screen_y = (world_y - camera_y) * zoom + screen_offset_y
```

Zoom + screen_offset come from the HK1 5-point calibration in
`tests/input_hk1_calibration.rs`. If zoom is fixed at 1.0 for Horsey
(typical for 2D Tiled games), one calibration point + the live camera
floats fully determine projection.

Also confirmed:

- **Building list lives at MapState +0x130/+0x138 (std::vector<Building*>).**
  Walked at `:112880`, pushed at `:120489`. Size = `(end-begin) >> 3`.
  Iteration sets `building+0x1c8 = 1` (likely a render-dirty flag).
- Building fields known so far: `+0x1c8` (flag), `+0x204` (removed?).
  World-pos / gid / type offsets not yet derived from decomp; the
  TMX-file parse path side-steps the need.
- Second vector at MapState `+0xb8/+0xc0/+0xc8`, purpose TBD.

Full MapState field map: [`HORSE-PLACES.md`](HORSE-PLACES.md#mapstate-dat_1403f4e00-field-map).

### Finding 5b (2026-05-17 round 2): Player position via the Truck object

The player navigates the overworld in a TRUCK. Reading the truck's
position answers "where am I on the map" without any vision.

- `*(GameState + 0x300)` -> Truck object.
- Truck `+0x28 / +0x2c` = position (float; scaled by `DAT_140303fb4`
  to tile coords). Cited `:76288`, `:149189`.
- Truck `+0x30 / +0x34` = per-frame velocity. Interpolated current
  position = `vel * dt + pos`.
- Truck `+0xac` = state bool (likely "at-rest in scene" / "needs init").

Combined with the TMX object parse (Finding 2): read truck tile
position -> match against `obj.x/32, obj.y/32` in the TMX objects ->
that object's `type` is the player's current location.

Also found: **`FUN_1401010d0(GameState*, tile_x, tile_y)`** at RVA
`0x1401010d0`. The canonical tile lookup. Returns a 40-byte
terrain cell at `GS[+0x270] + (gs.map_width * y + x) * 0x28`, or a
sentinel pointer if OOB. Cited `:152898`. Pattern-resolve and expose
as `vanilla.invoke "tile.lookup"` for terrain-cell access from tests.

Full Truck + tile-grid field map: [`HORSE-PLACES.md`](HORSE-PLACES.md#player-position-on-the-world-map-the-truck-object).

### Finding 5c (2026-05-17 round 3): Last-interacted Building + tile-pos accessor

Two more findings collapse the "location-under-cursor" question:

- **Scene handler `+0x148`** holds a pointer to the last-interacted /
  currently-selected Building. Cited `:120484`. Combined with the
  active-scene-handler pointer (TBD), this answers "what location did
  the player just click" with zero pixels.
- **`FUN_1400b4a10(Building*, &out_pair) -> float*`** at RVA
  `0x1400b4a10`. Returns the building's tile coordinates as a packed
  i64 in `out_pair` (low half = tile_x, high half = tile_y) AND returns
  a `float*` pointing inside the building's position field. Cited
  `:25431`, `:25772`, `:26217`, `:31708`, `:31938`, `:120424`. **Use
  this via `vanilla.invoke` instead of guessing building struct offsets.**

Combined with the MapState building vector at `+0x130`, the canonical
cursor-to-location flow becomes:

```rust
// per frame:
let buildings = walk_vector(MAPSTATE + 0x130);  // Vec<*const Building>
let cursor_tile = screen_to_tile(cursor_x, cursor_y, camera, scale);
for building in buildings {
    let (bx, by) = vanilla_invoke!(FUN_1400b4a10, building);
    if (bx, by) == cursor_tile {
        return Some(tmx_object_by_tile_pos(bx, by));  // gives back type, gid, etc.
    }
}
```

Also confirmed in round 3:

- Scene handler **`+0x270`** is a bool that gates two render paths
  (`:61997`); likely "modal/dialog visible". Useful for "should I
  wait or act" agent gating.
- **Generic actor pose pattern** (`+0x28/+0x2c` pos, `+0x30/+0x34`
  vel): shared by Truck, horses, NPCs. Reading any movable entity's
  tile position uses the same code path.
- **Terrain cell layout** (40 B each at `GS+0x270`): first u32 is
  `tile_type`; observed values 3, 4, 6, 13, 14, 20.

### Finding 5d (2026-05-17 round 4): The cursor and scene-transition handlers are NAMED in the decomp

Mining the annotated batches surfaced the exact functions we wanted:

- **`cursor_input_handler` at `0x14009d750`** (1577 B; string anchor `Pointer`). THE cursor dispatcher; all clicks, drags, hovers flow through it. **Hook this** to know what the player just clicked, where the cursor is, what was dragged. Replaces the entire "compute it ourselves from TMX + camera" plan with a single hook.
- **`enter_location_handler` at `0x1401046c0`** (1004 B; `EnterLocation`, `EnterLocationStable`). Fires on scene transition. Triggers auto-save. Hook for "player just entered location X" notifications.
- **`truck_enter_location_handler` at `0x1400cd5a0`** (1326 B; `TruckEnterLocation`). Fires on truck animation start (transition begin, before scene swap).
- **`welcome_dialog` at `0x14008f130`** (459 B; format string `"Welcome to %s"`). The `%s` argument is the location-name resolver. One xref away from a free `LocationId -> name` map.
- **`tmx_object_property_parser` at `0x1400bfa90`** (1970 B; strings `" react"`, `"shape"`, `buried`). Documents the TMX custom-property vocabulary the game accepts.

All have clear string anchors -> trivial to pattern-resolve via `TargetRegistry`. Full handler table in [`HORSE-PLACES.md`](HORSE-PLACES.md#map--scene-event-handlers-from-annotated-decomp).

This shifts the agent-loop design from "poll state + project + match" to "hook events + read state at event boundaries". Cheaper, race-free, semantic.

### Finding 5e (2026-05-17 round 5): active-scene-handler is reachable; enter handler decoded

Two final pieces of the agent-loop puzzle fell into place:

- **`FUN_1401046c0(GameState*, int scene_id, char suppress_sound)`**. The enter-location handler. Signature decoded from `:154943`. Looks up the scene-table slot at `GS[+0x438][scene_id*8]` and validates via vtable+0x18. Triggers auto-save when transitioning from overworld.
- **Active scene-handler pointer recipe**: `*(GS[+0x438] + active_scene_id * 8)`. We don't need a new singleton. The scene-handler IS the slot pointed to by the existing scene table at the active scene_id. From there, `scene_handler+0x148` gives the selected Building, `+0x270` gives the modal-visible bool.
- **scene_id semantic decode**: scenes 1-12 are per-location with specific sounds; 13 vs 14 are a money-gated pair; 28 is a teleport-target. Full table in [`HORSE-PLACES.md`](HORSE-PLACES.md#scene-id-enumeration-the-active_scene_id-semantic-decode).
- **`FUN_1400d1c40(scene, building, format, va_args)`** at RVA `0x1400d1c40`. The **dialog-enqueue function**. ALL in-scene text (`"Welcome to %s"`, `"That's a tired looking horse!"`, `"%s's Rides"`, etc.) flows through here. Hook to capture every dialog string the game shows.
- **`FUN_1400d1dd0(scene, building*) -> i32`** at RVA `0x1400d1dd0`. Canonical "what index is this building in the scene's vector". Cheap lookup.
- Three more scene state machines named: **sumo_match_handler** (`0x14007b2e0`, 5750 B), **biohacker_lab_handler** (`0x140033a10`, 6233 B), **pause_top_level_dispatcher** (`0x1400fd580`, 2159 B, with eco-speed + zoom controls).

The agent loop now has a complete read+react surface:

```rust
// "where am I, what's around, what just happened"
let scene_id = GS[+0x25C] as i32;
if scene_id == -1 {
    // overworld
    let truck = *(GS + 0x300);
    let tile = (truck[+0x28], truck[+0x2c]) * DAT_140303fb4;
    let location = tmx_objects.iter().find(|o| (o.x/32, o.y/32) == tile);
} else {
    // in a scene
    let scene = *(GS[+0x438] + scene_id * 8);
    let selected_building = scene[+0x148];
    let modal_visible = scene[+0x270];
    // dialog text captured via hook on FUN_1400d1c40
}
```

### Finding 5i (2026-05-17 round 12): 60ms click-hold is mandatory for synthetic input

`modforge::input::l1::click()` was emitting `LEFTDOWN` -> `LEFTUP` back-to-back with **zero hold**. Horsey's per-frame input pump polls `GetAsyncKeyState` once per frame (~16 ms at 60 fps) and **never observed the press**. Diagnostic test confirmed: cursor at correct screen coord (982, 393), click op returned ok, game state unchanged for 30 s.

Fix shipped 2026-05-17: `l1::click()` now defaults to a 60 ms hold (~3 frames). New `l1::click_held(btn, x, y, hold_ms)` exposes explicit control. With the fix, click at house door (983, 394) triggered scene transition `-1 -> 0` in 502 ms.

**Apply this to all future synthetic-input work**: 0 ms clicks won't register in any game with per-frame `GetAsyncKeyState` polling. 50-100 ms is the realistic human range.

### Finding 5j (2026-05-17 round 12): vanilla.invoke EXIT_TO_OVERWORLD crashes the game

`vanilla.invoke "EXIT_TO_OVERWORLD"` (the `FUN_1401041f0` registered in `targets_registry.rs`) faulted the game when called from the HTTP-worker thread. Symptom: HTTP connection forcibly closed, game taskkilled.

Root cause (suspected): the exit function touches scene tear-down + render state that the game's main thread is concurrently holding/reading. Same shape as [`DEBUGGING.md`](DEBUGGING.md) Cause A (foreign-thread vanilla calls into render-touching code).

Implication for the scene-navigation plan: skip `vanilla.invoke` for exit; instead **synthesize a click on the in-scene `Map` button** (top-right HUD-anchored, position needs calibration). The Map button click runs the exit function from the game's own UI handler on the right thread. Same code path, no threading risk. This is the "drive like a human" path the user locked in anyway, so the loss of the fast-path-via-invoke is no regression.

### Finding 5h (2026-05-17 round 11): Exit-to-overworld function found + shipped

`FUN_1401041f0(GameState*) -> void` at RVA `0x1401041f0` is the **exit-scene function**. The same code path the in-scene Map button triggers. Cite `all_functions.c:154755`. Already registered in `targets_registry.rs` as `EXIT_TO_OVERWORLD`. Wrapped as the HTTP op `game.exit_to_overworld` and surfaced as an `[Exit to overworld]` button in the Debug tab's "Where Am I" panel.

Effect: sets `GS+0x25C = -1`, zeroes scene state, triggers auto-save when applicable, plays the "World" sound, calls scene tear-down + truck-resume helpers. Idempotent: the wrapper op returns `{skipped: true}` when already on the overworld.

This removes the need for synthetic Map-button click calibration; the agent loop's "exit scene" primitive is now a single op call. Smoke test: `tests/exit_to_overworld_smoke.rs` (drives Home click → exit op → asserts `active_scene_id == -1` → confirms second call is no-op).

### Finding 5g (2026-05-17 round 8, corrected round 9, CONFIRMED round 10): Player home is scene_id 0

**Both questions answered:**

1. **Where on the world map IS the player's home?** TMX object `<object id="6" type="home" gid="97" x="3040" y="3712"/>`. Sprite `LocStable` variant 0.
2. **Which `active_scene_id` does the player ENTER when they click on home?** **`active_scene_id = 0` (CONFIRMED 2026-05-17 via Debug "Where Am I" panel).** scene-handler's self-id at `+0x08` was also 0. Consistent. The scene-handler lives at scene-table slot 0 (= `GS[+0x438] + 0`), the same slot that already held the owned-horse list. Slot 0 is the foundational home / stable subsystem.

scene_id 0 is **not in the factory dispatcher's switch** (factory only handles scene_ids 13+). It's allocated separately during game init / save load because it's foundational state that lives across the entire save (the home doesn't get torn down when you leave it).

The earlier scene_id-21-is-the-stable hypothesis was wrong. Scene 21 may be an NPC-stable scene (Bob's, Mabel's, etc.). Needs separate verification by entering an NPC stable in-game.

The 8 stable TMX objects all use `LocStable` sprite variants:

| TMX type | gid | Owner |
|---|---|---|
| `home` | 97 | **PLAYER** |
| `willaby`, `circled`, `bobs`, `mabels`, `surebreed`, `hacienda`, `paradise` | 98-104 | 7 NPCs |

**Sweetie's House (scene_id 28) is NOT the player's home**. It's an NPC location (separate TMX object `type="sweetie" gid=125`). An earlier round of this doc claimed "home = overworld" which was wrong; corrected after the user confirmed clicking on the home building transitions to a real scene.

Correct decode:

```rust
let scene_id = read_i32(GS + 0x25C);
let here = match scene_id {
    -1 => "Overworld (driving on the world map)",
    13 => "Race Track",
    14 => "Paddock (broke variant)",
    16 => "CRISPR Lab",
    17 => "Sue's Glues",
    21 => "Stable (player's home OR one of the 7 NPC stables; check which TMX home/willaby/... was clicked)",  // suspected
    23 => "The Circus",
    28 => "Sweetie's House (an NPC home)",
    36 => "The Jockey Club",
    37 => "Old Abandoned Track",
    // ... full table in HORSE-PLACES.md
}
```

To confirm scene 21 is the stable: launch the game, click on your house on the world map, open the horsey-mod overlay -> Debug tab -> "Where Am I" panel. The panel shows live `active_scene_id` + the scene-handler's display name and internal name; no guessing needed. UI added 2026-05-17 in `src/overlay.rs::render_where_am_i`, backed by [`src/scene.rs`](../src/scene.rs) which exposes every field documented in [`HORSE-PLACES.md` "Top-level singletons"](HORSE-PLACES.md#top-level-singletons) + [scene-handler factory table](HORSE-PLACES.md#scene-handler-factory--complete-scene_id-table).

### Finding 5f (2026-05-17 round 7): Complete scene_id integer mapping

The world-map vertical now has a **fully decoded `active_scene_id` integer table** mined from the scene-handler factory `FUN_140113d70` (`:150670-:150816`). Each `scene_type_id` value 13-37 (with gaps) dispatches to one of the 16 named scene constructors.

Headline numbers:

| scene_id | Scene |
|---|---|
| 13 | Paddock / Race Track |
| 16 | CRISPR Lab |
| 17 | Sue's Glues |
| 18 | Clide's Rides |
| 20 | Lasso-Mart |
| 22 | Bubber's Hutch |
| 23 | The Circus |
| 24 | The Secret Zoo |
| 25 | O'er Yonder Acres |
| 27 | Power Plant |
| 28 | Sweetie's House |
| 29 | Sumo Ring |
| 30 | Junk Shop (debug) |
| 31 | Normal Suburban House (Biohacker facade) |
| 36 | The Jockey Club |
| 37 | Old Abandoned Track |

Bonus field: **scene_handler `+0x08` = scene_id** (set by the factory at `:150815`). Read it to identify the live scene without any indirect lookups.

Full table + alloc sizes + constructor RVAs: [`HORSE-PLACES.md`](HORSE-PLACES.md#scene-handler-factory--complete-scene_id-table).

The agent-loop now has true semantic scene awareness:

```rust
let scene_id = read_i32(GS + 0x25C);
match scene_id {
    -1 => "World Map",
    13 => "Paddock / Race Track",
    16 => "CRISPR Lab",
    23 => "The Circus",
    28 => "Sweetie's House (home base)",
    36 => "The Jockey Club",
    // ...
}
```

### Finding 6: No "location under cursor" function yet identified

The hover-tooltip path almost certainly exists but didn't surface
from quick string anchors (`s_Hover_*` matches were limited to the
race-bet tooltip "Hover over a horse and press W..."). Two anchors
to pursue when needed: (a) the tooltip render function and its
format-string xrefs, (b) callers of the LOC cursor floats
(`LOC+0x174/+0x178`) that consume them as projection input rather
than as raw mouse position.

Not blocking: with TMX + camera state in hand, we compute "location
under cursor" ourselves via `world_to_screen(loc.world_pos) ->
screen_box; cursor in box?`. No vanilla call needed.

## Implications for the original plan

- The "auto-collect via input axis" library is **superseded** by
  parsing `locs.xml` + slicing `locs.png`. We may still build it as a
  fallback for non-vanilla maps or for visual regression baselines.
- The pHash sliding window is **likely unnecessary** for vanilla.
  World->screen projection from internal state is exact, deterministic,
  and zero false-positive. Reserve pHash for mod-added locations not in
  the parsed TMX.
- The "world-map vs in location" question is still gamestate-only via
  `active_scene_id` (-1 = overworld). Unchanged.

Updated build order below ([see below](#build-order-with-layer-0)).

## Layer 0: decomp-first. Does the game already do this?

**Before reaching for vision, find the game's own answer.** The game
renders the hover tooltip every frame, so SOMEWHERE it has a function
that takes cursor coords and returns the location under the cursor.
That function plus the underlying location table likely answer
questions 2 and 3 with zero pixels.

Targets to find (in priority order):

| Target | Likely shape | Find via |
|---|---|---|
| World-map location table | `std::vector` or static array of records `{id, name_idx, world_x, world_y, sprite_id, ...}` | `gamestate.scan_438_slots` for a "world-map" slot; grep decomp for location names from [`EXTERNAL-KNOWLEDGE.md`](EXTERNAL-KNOWLEDGE.md) (JumboDS64 Steam guide lists them all). |
| Cursor-to-location resolver | Per-frame fn called from tooltip renderer: `(mouse_x, mouse_y) -> LocationId \| -1` | Grep `LOC+0x174`/`+0x178` (the cursor floats HK1 resolved) for consumers; format-string anchor on the tooltip render path (Tier-2 per [`RE-NOTES.md`](RE-NOTES.md)). |
| Tooltip text resolver | Fn that fills the hover string given a LocationId | Format-string xref on hover/tooltip strings. |
| Location-name string table | Indexed by location id | Falls out of the table-walk above. |
| Sprite/texture atlas | Global pointer + UV table | Texture-load function anchors; reading the source-of-truth assets makes the auto-collect loop unnecessary. |
| World-map projection fn | `(world_x, world_y, camera, zoom) -> (screen_x, screen_y)` | Once the location table is in hand, the function that consumes it for rendering is one xref away. |

What success looks like:

- **Location table resolved** -> a `gamestate.world_locations` op
  returns `[{id, name, world_pos, screen_pos}]` without touching pixels.
- **Cursor resolver hooked or invokable** -> `screen.location_at_cursor`
  becomes a single `vanilla.invoke` call, deterministic and instant.
- **Tooltip text readable** -> we get the hover label without hovering.
- **Projection function callable** -> pan/zoom is solved by construction
  (we apply the same projection the renderer does); the "open question"
  about map pan/zoom in the vision plan dissolves.

Find these with the standard toolkit, no new infrastructure:
patternsleuth + `TargetRegistry` to resolve, `vanilla.invoke` to call,
tests-first per the workspace rule. The CRISPR-Lab decomp pass is the
canonical playbook (read the in-game-editor's own apply function, mirror
it). The same posture applies here.

If Layer 0 succeeds, Layer 2 (vision) becomes optional. A fallback
for UI the decomp doesn't cover (animated popups, dialogs without state
hooks, future content the mod hasn't pattern-resolved). It does NOT
become unnecessary. Visual regression testing and long-tail UI still
need it. But it stops being load-bearing for "where am I on the map."

## Layer 1: "world map vs inside a location". Gamestate only

`GS+0x25C` is `active_scene_id` (i32, `[-1, 256)`). `-1` = overworld.
Anything else = inside a scene. Documented in
[`HORSE-PLACES.md`](HORSE-PLACES.md). Already readable via
`gamestate.diag`.

Ship a thin `screen.context` op (or fold into the snapshot) that
returns:

```jsonc
{
  "in_world_map": true,
  "scene_id": -1,
  "scene_name": "overworld"
}
```

**Zero pixels needed.** This solves question 1 entirely.

## Layer 2: "which location icon is at X on the world map". Template/hash matching

The interesting problem. Each location on the world map renders as a
distinct icon. The set is **closed and small** (tens of locations, not
thousands), which is ideal for a deterministic template-matching
recognizer rather than a generalist vision model.

### Template library: auto-collect via the input axis

We do NOT hand-label icons. The mod already drives the game (input
axis) and knows ground truth (gamestate). The auto-collect loop:

1. Start on the world map (`active_scene_id == -1`).
2. `input.mouse.move` cursor to a candidate icon (sweep grid OR cursor
   to a known coord if `pop-extended.xml` or external knowledge gives
   us hints).
3. Capture frame: `screen.capture` -> PNG.
4. `input.mouse.click` to enter.
5. Poll `gamestate.diag` until `active_scene_id` flips from `-1` to N.
   **N is the ground-truth label for the icon we just clicked.**
6. Crop a 64x64 box around the click position on the saved frame.
   Save as `research/world-map-icons/loc_<N>_<name>.png`.
7. `input.key.press ESC` (or whatever exits) back to the world map.
   Poll until `active_scene_id == -1`.
8. Loop until coverage threshold reached.

5-10 minutes of scripted play -> labeled template library for every
location the script visits. No human annotation.

Edge cases:
- Some locations may require travel (boat, balloon) to reach. Skip on
  first pass; add later.
- If the same icon ID appears multiple times on the map (e.g. two
  pasture entries), one template covers both. Detection returns
  multiple hits, which is correct.
- Map view zoom: collect templates at the default zoom. If the game
  supports zoom, collect a template per zoom level OR run the matcher
  multi-scale.

### Recognizer: perceptual hash sliding window, imageproc fallback

Per-frame, on the map view:

1. For each template, precompute its DCT pHash via
   [`image_hasher`](https://crates.io/crates/image_hasher) (DCT pHash
   on 32x32 downscale -> 64-bit fingerprint).
2. At runtime, slide a 64x64 window across the visible map region,
   hash each window, compute Hamming distance to each template hash,
   keep matches with distance <= threshold (start at 6; tune).
3. For ambiguous matches (two templates within 2 bits of each other),
   re-score the candidate regions with
   [`imageproc::template_matching`](https://docs.rs/imageproc/latest/imageproc/template_matching/)
   using `MatchTemplateMethod::CrossCorrelationNormalized` for
   pixel-exact disambiguation.

pHash is so cheap that hashing every window on a 1080p map view is
sub-millisecond on one core. The expensive fallback runs only on the
handful of ambiguous regions per frame.

### What the ops return

```
screen.locations
  -> { in_map: true, locations: [
       { id: 1, name: "home",    bbox: [310, 245, 64, 64], score: 0.99 },
       { id: 7, name: "circus",  bbox: [820, 410, 64, 64], score: 0.96 },
       ...
     ]}

screen.location_at_cursor
  -> { id: 7, name: "circus", score: 0.96 } | null

screen.calibrate_locations { dry_run?: bool }
  -> kicks the auto-collect loop; returns { collected: [{ id, name, path }], skipped: [...] }
```

### Where this lives

```
horsey-mod/src/world_map.rs
  static LOCATION_HASHES: OnceLock<Vec<(LocationId, &str, ImageHash)>>
  pub struct LocationHit { pub id: LocationId, pub name: &'static str, pub bbox: Bbox, pub score: f32 }
  pub fn detect_locations(frame: &Frame) -> Vec<LocationHit>
  pub fn location_under_cursor(frame: &Frame, cursor: (i32, i32)) -> Option<LocationHit>

horsey-mod/research/world-map-icons/
  loc_001_home.png       (64x64 crops, auto-collected, checked in)
  loc_002_track.png
  loc_007_circus.png
  ...
```

The template library is checked into the repo. The auto-collect op is
the way we maintain it across game updates.

## Layer 3: integration with `GameAnnotator`

When the modforge screen axis ships `GameAnnotator`, horsey-mod's
impl calls `world_map::detect_locations(frame)` and emits one Mark per
hit:

```jsonc
{ "id": 4, "kind": "location", "label": "circus", "bbox": [820, 410, 64, 64], "source": "vision" }
```

Combined with the existing groundtruth marks (horses, HUD), Claude
gets a single annotated PNG showing horses + HUD + all visible map
locations, all numbered, in one round-trip.

## Build order with Layer 0

1. **Decomp pass on Layer 0 targets**. One session of grepping +
   pattern-resolving. Likely outcome: location table + cursor resolver
   identified and registered. Ship as `gamestate.world_locations` +
   `screen.location_at_cursor` (the latter backed by `vanilla.invoke`,
   not pixels).
2. **If Layer 0 covers it**, the auto-collect + pHash library work
   below becomes a fallback project, not the main line. Keep the
   template library for visual regression tests only.
3. **If Layer 0 partially covers it** (e.g. table found but no
   cursor resolver), use the table to project locations to screen
   coords; cursor->location becomes "nearest table entry to cursor",
   no vision needed.
4. **Only if Layer 0 fails entirely** (game does the lookup in shader
   or in some way we cannot reach), fall back to the
   auto-collect + pHash plan in Layer 2.

## Tests-first plan

- `tests/world_map_locations_smoke.rs`: with the game on the world
  map (`MODFORGE_EXPECT_LOADED=1` + `MODFORGE_EXPECT_OVERWORLD=1`),
  call `screen.locations`, assert at least one well-known location
  detected with score >= 0.9.
- `tests/world_map_calibration.rs`: scripted auto-collect run; ends
  with N populated templates and an assertion that each template
  re-detects itself in its own source frame with Hamming distance 0.
- `tests/world_map_location_at_cursor.rs`: input-axis-driven; move
  cursor to a known icon (via the calibration map from
  `tests/input_hk1_calibration.rs`), assert
  `screen.location_at_cursor` returns the expected id.
- Unit tests on `world_map::detect_locations` with synthetic frames
  built from the template library + known noise patterns; no game
  needed.

## Why this beats a vision-only approach (e.g. OmniParser alone)

| Concern | Pure-vision (OmniParser) | Templates + gamestate |
|---|---|---|
| "Is this the circus?" | "It's an icon" | "It's location id 7, name circus" |
| Cost per frame | ONNX inference (10s-100s of ms, GPU helpful) | pHash sliding window (<1 ms) |
| Library size | Multi-GB model | Tens of 64x64 PNGs |
| Maintenance | Pinned to model checkpoint; opaque updates | One auto-collect run per game patch |
| Debuggability | Embeddings | Diff two PNGs |

OmniParser earns its keep on the long-tail "I'm in a menu I haven't
taught the mod about" case. For a closed icon universe like the world
map, purpose-built recognition is faster, smaller, deterministic,
and trivially debuggable.

## Future extensions

- **In-location templates.** Same auto-collect trick for "is this the
  CRISPR Lab, the trading post, the stables?". Scene-specific UI
  icons that vary by location.
- **Map-pan/zoom tracking.** If the player pans/zooms the map, the
  icon positions shift; we need either (a) a known anchor (cursor
  position, fixed HUD element) to re-register coords, or (b)
  multi-scale matching. Defer until needed.
- **Path planning.** Once we know all visible locations + the
  player's current implied position (last entered scene), we can
  script "travel from current location to the circus" by sequencing
  the right icon clicks.

## References

- [`modforge::screen` axis design](../../modforge/docs/screen-axis.md) (parent)
- [`HORSE-PLACES.md`](HORSE-PLACES.md) for `active_scene_id` and the
  scene-table slot inventory
- [`tests/input_hk1_calibration.rs`](../tests/input_hk1_calibration.rs)
  (existing 5-point screen<->game-coord calibration)
- [`image_hasher`](https://crates.io/crates/image_hasher)
- [`imageproc::template_matching`](https://docs.rs/imageproc/latest/imageproc/template_matching/)
