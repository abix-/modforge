# HK1: Shift+Click Smart-Transfer Plan

> **Scope:** the first and only hotkey in v1 (user-locked 2026-05-15 in `todo.md` -> "High-priority features" -> "Hotkeys"). Shift+Click on a horse infers the right destination (truck <-> pasture <-> race line) from the player's current location and the horse's current container, then performs the transfer.
>
> **Status when this doc was written:** no code yet. Research + sequencing only. This document tells the next session what to build, in what order, with which tests, and where the decomp evidence lives.

---

## 1. Goal in one paragraph

The vanilla flow forces the player to click-and-drag every single horse, one at a time, between the truck (mobile carrier), the pasture (home), and the race line (track starting position). Race-day routines look like: pasture -> truck (drag every horse), drive to track, truck -> race line (drag every horse), run race, race line -> truck (drag every horse), drive home, truck -> pasture (drag every horse). HK1 collapses each individual transfer into a single Shift+Click on the horse. The mod reads the player's current location and the horse's current container, picks the obvious destination, and commits the move with the same side effects the vanilla drag-drop produces (fatigue clearing on race-line drop, audio cue, animation, etc.).

Not in v1: bulk transfer, "transfer all eligible", group selection, custom keybinds, per-location toggles. Ship the single-horse single-click case first; bulk variants come later.

---

## 2. What the game already does (decomp evidence)

The game's existing drag-drop machinery is the foundation. We do not re-implement it; we drive it.

### 2.1. The Location object (`Location*` = `LOC` for short)

Most "places that hold horses" are instances of a single C++ class (subclassed per location). The clearest specimen is `FUN_1400d2ab0` (`interact_with_npc_or_item`), which is one Location's click-tick handler. Inferred field map from reading `all_functions_annotated.c:251400-251680`:

| Field on `LOC` | Type | Role |
|---|---|---|
| `LOC[0x0]` (vtable) | `void**` | vtable; methods at `+0x38, +0x60, +0x68, +0x70, +0x88, +0x90` are called by the click handler |
| `LOC+0x174 / LOC+0x2f*4` (`fVar32`/`fVar34`) | `float, float` | last cursor world-position |
| `LOC[0x17] .. LOC[0x18]` | `std::vector<Interactable*>` | "things you can click here" (items, NPCs, drop targets) |
| `LOC[0x1a]` | `i32` | index into items vector, currently-hovered |
| `LOC[0x26]` | `Horse**` | begin of `std::vector<Horse*>` for this location |
| `LOC[0x27]` | `Horse**` | end of same vector |
| `LOC[0x2c]` | `bool` | "click is valid" / "armed" |
| `LOC[0x2d]` | `i32` | index of the horse the player is currently DRAGGING (-1 = none) |
| `LOC[0x2e]` | `i32` | index of the horse the player is currently HOVERING / candidate to grab (-1 = none) |
| `LOC[0x37]` | `i32` | mouse-button / click state for this tick |
| `LOC+0x16c` | `i32` | "last horse picked up" index |
| `LOC+0xd4` | `i32` | currently-dragged item index (the items vector at `LOC[0x17]`, not horses) |
| `LOC+0x234` | `bool` | "ready to leave location" flag |
| `LOC+0x300` | sub-struct ptr | per-frame screen-space state (truck/UI overlays) |

The horse drag-drop flow inside `FUN_1400d2ab0`:

1. While the mouse is hovering a horse, `LOC[0x2e]` is set to that horse's index in `LOC[0x26]`.
2. On click, if `LOC[0x2c]` (armed) is true and `LOC[0x2e] != -1`, the code commits the grab: it calls `vtable[+0x60](LOC, idx)` (pickup VFX/sound), `vtable[+0x70](LOC, idx, click_state)` (state transition: horse is now mid-drag), writes `LOC[0x2d] = LOC[0x2e]`, and calls `FUN_1400b6890(horse_ptr)` (animation start).
3. On release at a valid drop target, the same handler at the destination Location commits the move (a different vtable slot, likely `+0x88` from the symmetric branch).
4. On release at an INVALID target, `FUN_1400cdae0` (`drop_horse_fail_event`) fires the `DropHorseFail` audio cue.

Critically: **the horse's per-location ownership is the `Horse*` membership in `LOC[0x26]`'s vector.** Moving a horse between truck / pasture / race-line is *moving a `Horse*` between two Location objects' horse vectors*. The vtable methods on `LOC` handle the per-side-effects (animation, audio, fatigue reset, scene flags).

### 2.2. Where the truck / pasture / race-line Location objects live

Per `HORSE-PLACES.md`, the scene-table dump, AND the S0 probe results (2026-05-16):

| What | Where | Notes |
|---|---|---|
| `GS+0x438` | ptr to `void*[256]` | Scene/subsystem table; HLT calls it `kRootSceneTable` |
| `GS+0x25C` | `i32` | `active_scene_id`, -1 = overworld / at Home |
| **Slot 0x00** | sub-struct with strings `"My House"` + `"Home"` at +0x18 / +0x40 | **PASTURE = HOME LOCATION.** Its `+0x130/+0x138` vector is the owned-horse list. vtable_rva `0x30f3d0`. Confirmed via `hk1.probe.active_location` (S0). |
| **Slots 0x08..0x38** | `vector<Horse*>` each | **7 race lanes.** All share vtable_rva `0x30f3d0` with slot 0x00 (same Location class). Confirmed via `hk1.probe.scene_slot_vtables` (S0). |
| Slot 0x90 | sub-struct, vtable_rva `0x30b8a8` | "currently selected horse" context: vector + singleton `Horse*` at `+0x148` |
| Slot 0xb0 | sub-struct, vtable_rva `0x307c10`, count 4 | unknown role (4-element list in observed save) |
| Slot 0xb8 | sub-struct, vtable_rva `0x304578`, count 1 | unknown singleton |
| Slot 0xd0 | sub-struct, vtable_rva `0x30a0c0`, count 3 | candidate mirror of owned (3 in some saves) |
| Slot 0xf8 | sub-struct, vtable_rva `0x3037d0` | matches HLT's `kNeighborSceneVtableRva = 0x3037D0` -> NEIGHBOR scene |
| Slot 0x120 | sub-struct, vtable_rva `0x304e08`, count 5 | "horses available for THIS race" source (race-roster, NOT owned) |

Key consequence of the shared vtable: **the pickup vtable slot we resolve from `FUN_1400d2ab0` applies to BOTH the home Location AND each race-lane Location**. One resolver, two destination kinds.

The **truck** still isn't classified. Possibilities:
- A per-Location side-struct on the Home object (e.g. at `LOC+0x300`, the "screen-space state" pointer the decomp dereferences).
- A separate slot we haven't classified yet (likely one of 0xb0 / 0xb8 / 0xd0; these have unknown roles and the right "small singleton" shape).
- A field directly on `GameState` outside the `+0x438` table.

Slots 0xb0 (count 4) and 0xd0 (count 3) are the strongest candidates for the truck because: (a) the truck carries multiple horses at once, (b) their counts match the observed in-game truck content in some sessions. Confirming requires (1) loading horses into the truck in-game, (2) re-running `hk1.probe.scene_slot_vtables`, (3) seeing which slot's count changed.

When the player is at the Paddock / Race Track, `active_scene_id` should switch to a positive int. Re-running `hk1.probe.active_location` from inside the paddock will reveal the paddock's slot offset and confirm it uses the same `0x30f3d0` Location class. THIS IS STAGE S0.5 BELOW.

### 2.3. The mouse / hover globals

HLT confirmed two RVAs we can read directly:
- `kRvaMouseScreenX = 0x3ED970`
- `kRvaMouseScreenY = 0x3ED978`

For hit-testing we do not need to recompute "which horse is under the cursor". The active Location already maintains `LOC[0x2e]` for us (the hovered horse index). That value is alive each frame the cursor is over a horse.

If the active Location is harder to reach than expected, a fallback is scene-table slot 0x90's `+0x148` Horse* singleton, which `FUN_14010de40:160376` reads as "currently selected horse" in some contexts.

### 2.4. Two known-good entry points for synthesised transfers

When we choose to call the game's own functions rather than mutate vectors ourselves:

- **`vtable[+0x70](LOC, idx, state)`** -> begin drag (sets `LOC[0x2d]`, plays pickup audio, starts animation).
- **`vtable[+0x88](LOC, item_ptr)`** -> commit drop on a destination (the items branch; horses likely use a sibling slot identifiable by reading the destination's vtable).
- **`FUN_1400b6890(horse_ptr)`** -> horse-animation start used during pickup.
- **`FUN_1400cdae0(LOC)`** -> drop-fail event (used to confirm what the failure path looks like; we want to AVOID triggering it).

These are not yet pattern-resolved. Resolution work is part of the plan.

---

## 3. Three possible implementation strategies (and the recommended one)

### Strategy A. Pure vector surgery

Find the source vector and the destination vector, swap-remove the `Horse*` from the source, push it to the destination.

- **Pro:** trivially understood, no calls into game code.
- **Con:** skips every side effect (fatigue clearing on race-line drop is a known one per `todo.md`, plus animation, audio, scene flags). HLT explicitly notes that "the scene keeps multiple live indices into [its vectors]; do not compact from the DLL" (`world_map_tools.cpp:179`). The same warning applies here. Game state will be subtly wrong and probably crash within seconds.
- **Verdict:** rejected.

### Strategy B. Synthesize click + drop via Location state

Write `LOC[0x2e] = candidate_idx` on the SOURCE Location and `LOC[0x37] = click-down-state`, let the Location tick handler do the pickup, then on the next tick set the DEST Location's "drop here" state and let it commit.

- **Pro:** the game's own machinery runs every side effect.
- **Con:** requires precise multi-frame state coordination, requires the player to actually be at the destination (we can't tick the dest Location if it isn't the active one), and we are racing the game's own input handling. Hard to make deterministic.
- **Verdict:** rejected for v1. May revisit if Strategy D turns out brittle.

### Strategy C. Direct vtable call on source + dest

Resolve the pickup vtable slot (+0x70 on `LOC`) and the drop vtable slot (probably +0x88 or +0x68, TBD by deeper reading), call them in sequence: `src_LOC.vtable[+0x70](src_LOC, src_idx, 1)` then `dst_LOC.vtable[drop_slot](dst_LOC, horse_ptr)`.

- **Pro:** explicit, deterministic, runs all the game's side effects.
- **Con:** dependent on vtable slot stability across builds (HLT had to re-derive vtables when builds shifted). Means we need pattern-anchored resolvers for the vtable slots, not RVAs.
- **Verdict:** **RECOMMENDED for v1.** The vtable slots are stable WITHIN a build, and we have machinery (`modforge::patterns::sleuth`) to re-derive them.

### Strategy D. High-level "transfer horse" function

Find a single game function that takes `(horse_ptr, dest_scene_id_or_kind)` and does the whole transfer. This would be ideal but no such function is identified yet. Likely doesn't exist as a single named entry; the game's transfer flow is event-driven through the click handler. Defer; if we discover one during research, switch to it.

---

## 4. Architecture for HK1

```
+----------------------------------------------------------+
|  hudhook overlay (already shipping)                       |
|  - hooks IDXGISwapChain::Present                          |
|  - subclasses the game's HWND -> sees WM_KEYDOWN/         |
|    WM_LBUTTONDOWN before the game does                    |
+--------------------------+-------------------------------+
                           |
                           v
+----------------------------------------------------------+
|  modforge::input (new module)                            |
|  - publishes a per-frame snapshot:                       |
|      Modifiers { shift, ctrl, alt }                      |
|      Mouse { x_screen, y_screen, lbutton_down,           |
|              lbutton_pressed_this_frame }                |
|  - shared lock-free; horsey-mod reads it from the        |
|    overlay render callback OR a separate detour          |
+--------------------------+-------------------------------+
                           |
                           v
+----------------------------------------------------------+
|  horsey-mod::hk1::shift_click (new module)               |
|  Per-frame:                                              |
|    if !shift || !lbutton_pressed_this_frame: return      |
|    horse = resolve_hovered_horse()       <- step 4.2     |
|    if horse.is_none(): return                            |
|    src = horse.container()               <- step 4.3     |
|    ctx = player.current_location()       <- step 4.4     |
|    dst = pick_destination(src, ctx)      <- step 4.5     |
|    if dst.is_none(): return                              |
|    swallow_click()                       <- step 4.6     |
|    transfer(horse, src, dst)             <- step 4.7     |
+----------------------------------------------------------+
```

### 4.1. Input plumbing

We already use hudhook for the overlay. Hudhook subclasses the game window. The render-loop callback receives the imgui `Ui`, which exposes `io.keys_down`, `io.key_shift`, `io.mouse_clicked[0]`. That is enough; no new hook needed.

Caveat: the overlay only ticks while ImGui is rendering. We want HK1 active even when the overlay window is hidden. Options:
- Keep the overlay's render loop active (one no-op imgui frame per game frame) and read input from it -> simplest.
- Add a second WndProc subclass via hudhook -> only do this if option 1 has measurable overhead.

For v1: option 1. Read input from the overlay's existing per-frame `Ui`.

### 4.2. `resolve_hovered_horse() -> Option<HorsePtr>`

Three signals, in priority order:

1. **Active Location's `LOC[0x2e]` and `LOC[0x26]`.** This is the game's own "horse the cursor is over right now" index. If the active scene exposes a single Location object (which it does for paddock, track, home), we read its `+0x2e * 4` int, then index into `+0x26`'s vector. Need: a resolver for "active Location pointer" given `GS`. The most likely path is `GS+0x438[active_scene_id*8]` -> a sub-struct that either IS the Location or contains a `Location*` at a fixed offset.
2. **Scene slot 0x90's `+0x148`.** "Currently selected horse" singleton. Fallback if (1) is messy at some locations.
3. **Brute hit-test using `kRvaMouseScreenX/Y`.** Iterate the active scene's horse vector, read each horse's screen-space position, test cursor against an AABB. Last resort; expensive and inaccurate.

For v1: implement (1) and (2) only. Skip (3).

### 4.3. `horse.container() -> Container { Truck | Pasture | RaceLine(lane) | Other }`

Read the horse's *current owner*. The horse object has fields for its location/container state, but the offsets are not yet documented in `HORSE-PLACES.md`. Two ways to find this:

- **Forward search:** for each known horse `Horse*` in the owned-list, scan its bytes and look for the `Location*` of its current container. The truck/pasture Location pointers are stable within a save; one of the qwords on the Horse struct is the back-pointer.
- **Backward search:** enumerate the candidate Location objects (pasture LOC, truck LOC, each race-lane slot's container) and check each one's `LOC[0x26]` vector for the horse pointer. Cheap because there are <10 candidates and each vector has <10 horses.

For v1: backward search. It is O(small * small) and avoids guessing field offsets on the Horse object. Implement as `find_container_of(horse_ptr) -> Container` that walks the known list of horse-vectors and reports the first hit.

### 4.4. `player.current_location() -> LocationKind`

Read `active_scene_id` (`GS+0x25C`) and translate via a small lookup table. Scene IDs are stable within a build; we resolve them once at first call.

| Scene id | Location | Heuristic for resolution |
|---|---|---|
| -1 | overworld (no Location) | direct check |
| `paddock_id` | Race Track / Paddock | string `EnterLocationPaddock` -> caller -> scene id constant |
| `home_id` | Pasture | string `Pasture` if present, else by Location vtable comparison |
| other | (other locations, not in v1 routing table) | passthrough |

The scene IDs are themselves binary-derived constants. Resolve them via the string-xref method already used elsewhere (`format-string xref` recipe in `ADDRESS-RESOLUTION.md`).

### 4.5. `pick_destination(src, ctx) -> Option<Container>`

The user-locked rules from `todo.md`:

```
ctx = RaceTrack:
  src = Truck      -> RaceLine(player's_preferred_lane)
  src = RaceLine(_)-> Truck
  else             -> None

ctx = Pasture:
  src = Truck      -> Pasture
  src = Pasture    -> Truck
  else             -> None

ctx = anywhere else:
  src = Truck      -> Pasture
  src = Pasture    -> Truck
  else             -> None  (or future: nearest carrier)
```

"Player's preferred lane" at the track: pick the first non-full race lane (lanes 0x08..0x38, each capped at ~5 per HORSE-PLACES). If all full, return None and (optionally) play the same DropHorseFail audio.

### 4.6. `swallow_click()`

We want the game NOT to also process this click as a drag-start. Hudhook's WndProc subclass can return early on the consumed message, but only while the overlay is the focus capture. Two approaches:

- **A:** mark the message handled in hudhook's WndProc on the frame we act -> game never sees it. Cleanest if the overlay can capture mouse selectively.
- **B:** let the game see the click but also call our transfer. We then have to undo the game's own drag-start state (`LOC[0x2d] = -1`, clear `LOC[0x16c]`). Worse: more state to babysit.

For v1: A. If hudhook's WndProc cannot conditionally swallow, fall back to B.

### 4.7. `transfer(horse, src, dst)`

Strategy C from section 3. Concretely:

1. Resolve pickup vtable slot on `src` (target it as "the slot called from `FUN_1400d2ab0` when `LOC[0x2c]` is true and `LOC[0x2e] != -1`"). This is `vtable[+0x70]`.
2. Resolve drop vtable slot on `dst`. Reread the click-release branch of `FUN_1400d2ab0` (the part that runs when `*(char *)((longlong)param_1 + 0x234) != '\0'` or the symmetric drop branch we haven't yet located precisely). Identify the slot.
3. Call sequence:
   ```rust
   unsafe {
       // Begin drag on src
       let pickup: extern "fastcall" fn(*mut Location, i32, i32) =
           transmute(src.vtable[PICKUP_SLOT]);
       pickup(src.ptr, src_idx, 1);

       // Commit drop on dst
       let drop_: extern "fastcall" fn(*mut Location, *mut Horse) =
           transmute(dst.vtable[DROP_SLOT]);
       drop_(dst.ptr, horse);
   }
   ```
   wrapped in a SEH guard (per HLT pattern) so a vtable shift between builds can't take the game down without us hearing about it.

### 4.8. Settings toggle

Single bool: `hotkeys.shift_click_transfer.enabled`, default `true`. Persisted via existing settings store (`modforge::settings`). UI: one checkbox on the overlay's existing Hotkeys tab (new section).

---

## 5. Address-resolution work (all pattern-anchored per CLAUDE.md)

Every constant below must land in `targets::resolve::*` and be re-derived via `modforge::patterns::sleuth` at injection time. No bare `0x...` literals in source.

| Symbol | Resolver | Anchor strategy |
|---|---|---|
| `MOUSE_SCREEN_X` data global | `data_global::mouse_screen_x` | port HLT's `kRvaMouseScreenX = 0x3ED970`; rederive in our build via xref from `FUN_14009d750` (cursor input) |
| `MOUSE_SCREEN_Y` | `data_global::mouse_screen_y` | same; adjacent qword |
| `ACTIVE_LOCATION_PTR` | `data_global::active_location_ptr` | derive: `GS+0x438[active_scene_id*8]` chain; expose as helper, not a single resolved global |
| `PICKUP_VTABLE_SLOT` (offset 0x70) | `vtable_slot::location_pickup` | read `FUN_1400d2ab0`, find the `call qword ptr [rcx+0x70]` after the `LOC[0x2c] != 0` branch; assert slot value is 0x70 |
| `DROP_VTABLE_SLOT` (offset TBD) | `vtable_slot::location_drop` | read the symmetric branch on release-at-target; identify slot; assert |
| `PADDOCK_SCENE_ID` | `data_global::paddock_scene_id` | string xref `EnterLocationPaddock` -> caller -> constant operand in compare |
| `HOME_SCENE_ID` | similar | string xref `EnterLocationHome` or equivalent |
| `RACE_LANE_SLOTS` | const range 0x08..0x38 | declared as constant in source after confirmation via `FUN_140105260:155484` decomp; double-check via runtime scan |
| `LOC_HORSE_VEC_BEGIN` (0x26 * 8) | `location_offset::horse_vec_begin` | confirm by reading `FUN_1400d2ab0` references |
| `LOC_CANDIDATE_IDX` (0x2e * 8) | `location_offset::candidate_idx` | same |
| `LOC_DRAG_IDX` (0x2d * 8) | `location_offset::drag_idx` | same |

The HK1 module reads everything via these resolvers. If any fails to resolve, HK1 disables itself with a status note in the overlay (same pattern as `enter_scene_id` failure mode in HLT).

---

## 6. Sequenced delivery, one ship + checkpoint between each

Per CLAUDE.md, each stage ships its own commit with: tests that prove the primitive works, real game verification (Claude drives `horsey-play` + tests), zero unstaged scope creep.

### Stage HK1-S0. Research probes (no production code) [DONE 2026-05-16]

- `tests/hk1_probe_loc_field_layout.rs`: passes. With `active_scene_id = -1` (overworld/home), probe walks slot 0x00 and reports `loc_ptr`, `vtable_rva=0x30f3d0`, `loc_horse_count=2` (matches user save), `loc_drag_idx=-1`, `loc_cand_idx=-1`, `loc_armed=0`. Raw bytes reveal strings `"My House"` + `"Home"` confirming slot 0x00 IS the Home Location.
- `tests/hk1_probe_scene_slot_vtables.rs`: passes. Classifies 30 slots; slot 0x00 + slots 0x08..0x38 all share vtable_rva 0x30f3d0 = the shared Location class. Slot 0xf8 matches HLT's `kNeighborSceneVtableRva = 0x3037D0`.
- `tests/hk1_probe_mouse_globals.rs`: passes (no error) but values read as `0xffffffff` raw bits -> NaN floats. HLT's mouse RVAs are STALE in our build (binary updated 0a2689fe). S1 must re-anchor via xref from `cursor_input_handler` (FUN_14009d750).

Backing ops in `src/ops.rs`: `hk1.probe.active_location`, `hk1.probe.scene_slot_vtables`, `hk1.probe.mouse_globals`.

### Stage HK1-S0.5. Paddock active_location probe [TODO, requires player at paddock]

Same `hk1.probe.active_location` op, but with player physically at the Race Track location in-game (so `active_scene_id` switches to a positive integer). Expected: probe reports the paddock slot offset, confirms vtable_rva is the same `0x30f3d0` Location class, dumps `LOC[0x26]` horse-vec which holds the horses currently at the track. This pins the paddock scene id constant for the `LocationKind` lookup table in section 4.4.

**Ship gate:** S0 + S0.5 both reproduce the decomp evidence in live memory.

### Stage HK1-S1. Input snapshot

- `modforge::input` module exposing `read_snapshot() -> InputSnapshot { shift, lbutton_pressed, mouse: (x, y) }`.
- Read from hudhook's `Ui` inside the overlay render loop, publish to a `parking_lot::RwLock<InputSnapshot>` or atomic struct.
- HTTP op `input.snapshot` for tests: returns the most recent snapshot as JSON.
- Test: `tests/input_snapshot_updates.rs` polls the HTTP op while a fixture nudges the mouse (driven via `SendInput`); assert `x` changes.

**Ship gate:** test passes; `input.snapshot` shows live cursor data.

### Stage HK1-S2. Hovered-horse resolver

- `horse::hovered_horse() -> Option<HorsePtr>` reading the active Location's `+0x26 / +0x2e`.
- Active-Location resolver: `gamestate::active_location() -> Option<LocationPtr>` doing the `GS+0x438[active_scene_id*8]` walk.
- HTTP op `horse.hovered`. Returns `{horse_ptr, name, name_id, container_hint}`.
- Test: `tests/horse_hovered.rs` env-driven; tester runs game, hovers a known horse, calls op, asserts horse name matches.

**Ship gate:** hovering known horse returns its pointer + name in the HTTP op.

### Stage HK1-S3. Container resolver (backward search)

- `horse::container_of(horse_ptr) -> Container` walking the known list of horse-vectors (owned slot 0x00, race lanes 0x08..0x38, paddock LOC, home LOC, truck LOC). First hit wins.
- HTTP op `horse.container`. Input: `horse_ptr`. Output: `{kind, location_ptr, index}`.
- Test: `tests/horse_container.rs` cycles a horse through 2-3 locations in-game (manually) and asserts the op reports the right container each time.

**Ship gate:** moving a horse manually changes the reported container.

### Stage HK1-S4. Destination picker (pure logic)

- `hotkeys::pick_destination(src: Container, ctx: LocationKind) -> Option<Container>`.
- No game-state reads inside (it is a pure mapping from inputs to a kind). Easy to unit-test.
- Unit tests covering every rule in section 4.5.

**Ship gate:** all rule rows in section 4.5 have a passing assert.

### Stage HK1-S5. Transfer primitive (Strategy C wired up)

- `hotkeys::transfer(horse: HorsePtr, src: Container, dst: Container) -> Result<()>`.
- Calls pickup vtable on src, drop vtable on dst, wrapped in SEH.
- HTTP op `horse.transfer` taking `{horse_ptr, dst: "truck"|"pasture"|"race_line"}`. Reads `src` itself via the container resolver from S3.
- Test: `tests/horse_transfer_truck_pasture.rs`. Game has player at pasture, one horse in pasture. Test calls op with `dst=truck`. Asserts container changes, then calls with `dst=pasture`, asserts it changes back.

**Ship gate:** round-trip transfer via HTTP works without crashing; visible in game (horse animates the same way as a manual drag-drop).

### Stage HK1-S6. Hotkey wire-up

- `hotkeys::shift_click::tick()` called from the overlay render loop.
- Reads input snapshot. On Shift+Click rising-edge, runs the full pipeline (resolve hovered -> resolve container -> resolve ctx -> pick destination -> call transfer).
- Swallow the click (Strategy A from 4.6); if that proves impossible in hudhook, fall back to B.
- Settings entry `hotkeys.shift_click_transfer.enabled` (default true) gates the whole thing.
- Test: `tests/hk1_e2e.rs`. Drives `horsey-play` + synthesised input. Assert one Shift+Click moves a horse pasture->truck.

**Ship gate:** real Shift+Click in the running game moves horses correctly.

### Stage HK1-S7. Failure paths + audio

- When `pick_destination` returns `None` (e.g. all race lanes full), play the `DropHorseFail` cue: `FUN_1400cdae0` is the existing emitter, but calling it requires an active Location. Simpler: directly invoke the audio play function for `DropHorseFail` if pattern-resolved; else silently ignore for v1.
- Status note in the overlay's footer: "HK1: transferred Foo to truck" or "HK1: race lanes full".

**Ship gate:** edge cases produce visible feedback; no silent failures.

---

## 7. Tests-first checklist (CLAUDE.md hard rule)

Every primitive in section 6 ships with its `tests/*.rs` BEFORE the production code that backs it. No probing via curl/python/PowerShell one-liners. The S0 research probes themselves are tests (they assert structural invariants on the live game).

The full test list:

- `tests/probe_loc_field_layout.rs` (S0)
- `tests/probe_scene_slot_inventory.rs` (S0)
- `tests/probe_mouse_globals.rs` (S0)
- `tests/input_snapshot_updates.rs` (S1)
- `tests/horse_hovered.rs` (S2)
- `tests/horse_container.rs` (S3)
- `tests/pick_destination_rules.rs` (S4, unit)
- `tests/horse_transfer_truck_pasture.rs` (S5)
- `tests/horse_transfer_track_lane.rs` (S5 extension)
- `tests/hk1_e2e.rs` (S6)
- `tests/hk1_no_destination.rs` (S7, asserts no crash + status note)

---

## 8. Risks and unknowns

1. **Vtable slot stability across builds.** Mitigation: resolvers anchor on the calling site in `FUN_1400d2ab0`, not on a hardcoded slot number. The slot is decoded from the operand of the `call qword ptr [rcx+disp8]` instruction.
2. **Hudhook click swallowing.** If hudhook's WndProc cannot conditionally swallow WM_LBUTTONDOWN, we either subclass the game's HWND ourselves (a second hook) or fall back to "let the click through and undo the game's drag-start state". Detect early in S1.
3. **Truck Location object location.** Section 2.2 has it as "probably attached to GameState or to a per-Location side-struct". If the truck has no stable Location pointer (e.g. it is reconstructed every scene transition), Strategy C breaks for the truck side and we have to fall back to Strategy B for that one container. Detect during S0 / S2.
4. **Multi-frame drag state.** If the game's tick reads `LOC[0x2d]` BEFORE we get a chance to set it, the drag-start animation could glitch. SEH wrap; if we see glitches, add a one-frame delay (set `LOC[0x2d]` from a deferred callback on the next tick).
5. **Save/load.** The transfer mutates game state that the vanilla save format already persists. No mod-side sidecar needed for HK1. Verify in S5: transfer, save, reload, confirm horse is still where we put it.

---

## 9. Out of scope for v1 (carried forward into a future doc)

- Bulk transfer (Shift+Click on a group; "transfer all eligible" hotkey).
- Custom keybinds (the modifier and button are hardcoded to Shift+LMB).
- Per-location toggles in settings (only the global enable/disable exists).
- HK2+ for any other hotkey.
- Transferring horses we do not own (NPC horses, wild horses).
- Cross-scene transfers when the player is not at either endpoint (i.e. teleporting horses). Vanilla doesn't support this; HK1 doesn't either.

---

## 10. References to other docs

- `docs/todo.md` -> "Hotkeys" -> HK1 spec, groundwork list.
- `docs/HORSE-PLACES.md` -> scene-table layout, horse vector locations, slot inventory.
- `docs/ADDRESS-RESOLUTION.md` -> migration tracker; new resolvers from section 5 add to its tables.
- `docs/PRIOR-ART-HorseyLiveTweaks.md` -> what HLT does and does not do (HLT does NOT have horse transfer; HK1 is novel territory).
- `research/decompiled/all_functions_annotated.c:251400-251680` -> the Location click-drag handler this plan is built around.
- `research/decompiled/annotated/BATCH-08.md:19` -> `drop_horse_fail_event`.
- `research/prior-art/HorseyLiveTweaks/src/core/offsets.h` -> mouse-coord RVAs, scene-table offsets.
