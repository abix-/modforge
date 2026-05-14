# Horsey mods TODO

## Current status

| Layer | Status |
|---|---|
| Decompilation | **DONE** (100% functions, 25 deep annotations, 1234 batch entries) |
| `horsey-mod` crate | **SHIPPED** in grounded2mods workspace |
| DLL injection + HTTP control plane | **WORKING** (verified live) |
| 18 ops for read/write of game state | **WORKING** |
| `no_tire = true` by default at attach | **WORKING** |
| Cargo rebuild while game running | **WORKING** (staged-DLL pattern) |
| `--reload` swap | **PARTIAL** (swap works but crashes after; hardening below) |
| MinHook trampolines | not started |
| SDL3 input hooks | not started |
| Roster UI | not started |
| Hotkeys | not started |
| Save sidecar | not started |
| RPG layer | not started |

Latest milestone: [`MILESTONE-FIRST-INJECTION.md`](MILESTONE-FIRST-INJECTION.md).

---

## Active blocker

### Hot-reload crash

`horsey-inject.exe --reload` performs the swap and reports success, but
the game crashes a few seconds later. The post-reload state is briefly
visible (verified: `no_tire: true` was readable after the swap before crash).

Most likely cause: helper threads inside the old DLL haven't fully unwound
their stack when `FreeLibrary` is called. The `_shutdown` op spawns a
`horsey-shutdown` thread that lives inside the old DLL; if that thread
hasn't exited, the FreeLibrary returns "successfully" but the next time
that thread tries to return into freed code: crash.

Fix candidates:
1. Make `_shutdown` synchronous: stop the server in the request handler,
   wait until `shutdown_all()` has truly returned (all listeners joined),
   then return the HTTP response.
2. Injector polls port 33077 after `_shutdown` until it's closed, then
   waits another 500ms for in-flight helper threads, then `FreeLibrary`.
3. From the last remaining thread, call `FreeLibraryAndExitThread`.

Recommended: try (1) first (simplest, no injector change). If that's
insufficient, add (2). Use (3) only if both fail.

Workaround until fixed: relaunch Horsey + re-inject fresh on each rebuild.

---

## High-priority features

### Hotkey-driven actions (CRITICAL for ease-of-use)

Repetitive clicking is the second-biggest tedium source after fatigue/aging.
Implement modifier-click + keyboard hotkeys for common actions.

| Hotkey | Action |
|---|---|
| `Shift+Click` (on horse) | Transfer the horse to truck / corral / current location |
| `Ctrl+Click` (on horse) | Toggle "favorite" (excludes from retire/sell candidates) |
| `Alt+Click` (on horse) | Show full stats panel |
| `Shift+Click` (on item) | Auto-buy 10 (or the bulk-buy default) |
| `Shift+Click` (on horse in roster) | Quick-feed (uses inventory hay) |
| `R` | Race the currently-selected horse |
| `F` | Feed all hungry horses (drains hay from inventory) |
| `S` | Sleep all tired horses |
| `B` | Open breeding menu with currently-selected horse pre-filled |
| `T` | Open transfer menu |
| `Esc+1..9` | Quick-switch player slots / save slots |
| `Numpad +` / `Numpad -` | Increase / decrease sim speed |

**Why this matters**: vanilla forces you to click-by-click on every horse
for every action. Bulk hotkeys turn tedious chores into one keypress.

**Implementation path**: requires DLL injection (Tier 3+ from
`ENGINE-EXTENSION.md`) because the input handler is in `Horsey.exe`. The
DLL hooks SDL input events and short-circuits them to game actions before
the engine sees the raw click.

Probably easiest as a `horsey-mod` mod once that foundation exists (see
[`MODFORGE-INTEGRATION.md`](MODFORGE-INTEGRATION.md)).

---

### Horse-crowd management (CRITICAL for 50+ horse households)

When many horses are at the same location (e.g. all your horses parked at
home), they stack on top of each other. Vanilla problems:

- Horses overlap pixel-for-pixel; you can't see how many are there.
- Clicking one horse is a lottery (you get whichever is rendered last).
- No way to tell at a glance which horses are hungry / tired / sick.
- Breeding setup is painful: you can't easily pick two specific parents.
- Counting "how many horses do I own?" requires moving the camera to find
  every stack.

#### Sub-features

**1. Auto-spread overlapping horses**

When N >= 2 horses share a tile, render them in a small fan/circle around
the actual position so each is individually clickable. Hover one horse to
"lift" it forward for emphasis.

Implementation: hook the per-horse render call. Detect overlap by
quantizing positions to half-tile buckets. For each bucket with >1
horse, offset each horse's render position by a deterministic angle
(`horse_id % N * 360/N`) and a small radius. The actual game-state
position stays unchanged; only the render position is offset.

**2. Roster panel overlay**

A side-panel UI showing ALL horses with one row each, columns sortable:

| Name | Loc | Age | Hunger | Tired | Breed-Ready | Skill | Status |

Click a row to focus camera + select that horse. Filter chips at top:
"Hungry only", "Tired only", "Old", "At home", "On track", etc.

Backend: the data already lives in our `horses.count`/`horse.read` ops.
Front-end is either:
- ImGui overlay (DX12-hook integration; significant work)
- **Web UI** served from `modforge::server` (much faster path; user
  has it open in a side browser window)

The web UI is the right first cut. ~200 lines of HTML/JS pulling from
our existing HTTP control plane.

**3. Status badges on stacked horses**

Above each horse, render small icons matching what the engine already
draws (`StatusHungry`, `StatusTired`, `StatusOld`) but ENLARGED and
ALWAYS-VISIBLE (not just on hover). Color-coded:

- Red dot = needs food urgently
- Yellow dot = tired
- Blue dot = ready to breed
- Skull = imminent death from old age

Hook the existing `render_horse_thought_bubble` family (we annotated
those at `0x1400bd820` etc.) and always-draw the badges instead of
gating on hover state.

**4. Hotkey horse cycling**

When multiple horses are stacked, pressing `Tab` cycles selection
through them. Useful when auto-spread is off or when zoomed out.

**5. Count display**

Floating "N" badge above a stack of overlapping horses, showing the
count. Disappears when you mouse-over (so it doesn't block the spread
view).

**6. Breeding picker**

A dedicated overlay: pick parent A from the roster, pick parent B,
preview the predicted offspring stats (using our knowledge of the
breeding formula: `litter = min(parentA.litter, parentB.litter) +
rng_bonus`). Click "Breed" to drag both horses to the barn
automatically.

**7. Smart auto-feeding**

A toggle: "auto-feed hungry horses from inventory hay". When on, any
horse whose hunger crosses the threshold gets fed automatically as
long as hay is in stock. Removes the manual feeding chore entirely.

**8. Group operations**

Select multiple horses (Ctrl+click or via the roster panel), then:
- Move them all to a location
- Feed them all
- Put them all to sleep
- Retire them all
- Bulk-sell at the glue factory

#### Why this matters

The user explicitly identified this as the second-biggest tedium source
after fatigue/aging. Without these features the late-game experience
(50+ horses) is dominated by UI friction, not gameplay.

#### Implementation path

This entire feature stack rides on `horsey-mod`:

| Sub-feature | Backend | Frontend |
|---|---|---|
| Auto-spread | Hook per-horse render | none (positions just shift) |
| Roster panel | Existing `horses.*` ops | Web UI page (HTML + JS) |
| Status badges | Hook status-bubble render | none (badge always-on) |
| Hotkey cycling | SDL input hook | none |
| Count display | Hook overlap detection | rendered via render hook |
| Breeding picker | New `breed.preview` op | Web UI page |
| Auto-feed | New `auto_feed` toggle setting | none (runs automatically) |
| Group ops | New `horses.bulk_*` ops | Web UI page |

The web-UI approach is the unblocker: don't try to inject UI into the
SDL3 renderer right away. Use `modforge::server`'s HTTP plane plus a
single-page HTML app served from our DLL. The user keeps a Chrome tab
open on `http://localhost:33077/ui` with all the management features.
The IN-GAME view (auto-spread, status badges, count display) is the
in-game-rendered subset; the heavy UI lives in the browser.

This split is also how serious modders ship overlays in 2026: the
external-tool-via-localhost pattern is friction-free vs. embedding a
full UI library into the game's render path.

---

## Mod foundations

### 1. `horsey-mod` crate (per-engine binding for modforge) **SHIPPED**

Status: **working**. Lives in [`abix-/Grounded2Mods`](https://github.com/abix-/Grounded2Mods)
as a third sibling to `ueforge` and `unityforge`. Pivoted from the originally-planned
proxy-`steam_api64.dll` approach to a `CreateRemoteThread(LoadLibraryW)` injector
after MSVC link.exe's `.DEF` forwarder syntax failed for 1,089 Steam API exports.

What's done:
- `horsey-inject.exe` finds Horsey.exe and injects `horsey.dll`
- DllMain spawns a worker thread that initializes modforge logging, settings,
  HTTP server with auth
- 18 ops registered for read/write of game state + cheats + horse fields
- Staged-DLL pattern: each inject copies the cargo output to a fresh
  timestamped filename so cargo can rebuild while the game is running
- `_shutdown` op + `--reload` flag implement the hot-reload swap
- `no_tire = true` set at every DLL attach

What's pending:
- **Hot-reload hardening** (currently causes delayed crash). The `_shutdown`
  op acknowledges, the listener thread joins, but helper threads inside
  the old DLL may still have stack frames when `FreeLibrary` is called.
  Options under consideration:
  - Poll port 33077 in injector after `_shutdown` until truly closed, then
    wait another ~500ms before `FreeLibrary`
  - Have `_shutdown` itself call `FreeLibraryAndExitThread` from the last
    remaining thread (atomic self-unload)
  - Add a `_drain` op that returns only after all helper threads have exited
- MinHook integration (zero progress; foundational for everything else)
- `horses.live` walks the wrong list (track-manager's on-track horses, not the
  full roster). Need to find the right list pointer for the roster UI.

### 2. HTTP control plane **SHIPPED**

`modforge::server::spawn` is used directly. The 18 registered ops are in
`horsey-mod/src/ops.rs`. Auth is in `X-Ueforge-Auth` header; token is
written to `horsey.auth` next to the DLL on each launch.

Currently registered ops:
- Liveness: `ping`, `list_ops`
- State reads: `game.read`, `game.money.get`, `game.year.get`, `cheats.*`
- State writes: `game.money.set`, `game.money.add`, `game.year.set`,
  `cheats.no_tire.set`, `cheats.debug_mode.set`
- Horses: `horses.count`, `horses.roster_addr`, `horses.live`, `horse.read`,
  `horse.set_age`, `horse.set_max_age`, `horse.clear_tiredness`
- Hot reload: `_shutdown`

To add:
- `horses.list_full` walking the full roster (not just on-track)
- `save.export` / `save.import` for save backup ops
- `pop.spawn` and `pop.list` for population creation
- `genes.read` / `genes.write` for runtime gene editing (when MinHook lands)

### 3. Save-edit tool (in-progress, see `save_edit.py`)

Extend `save_edit.py` with set/write operations now that we have the full
save format documented in
`decompiled/annotated/0x14006dc80_save_game_writer.c`.

### 4. RPG layer for Horsey

Use modforge's RPG module (Effect/Trigger/Skill + XP curve + persistence).
First skills:
- "Stable Master" - reduces fatigue accumulation rate
- "Veterinarian" - increases lifespan
- "Breeder" - boosts litter sizes
- "Trainer" - boosts race speed
- "Geneticist" - unlocks faster CRISPR

Map each skill to a `StandardEffect` variant that adjusts the appropriate
horse-struct field or hooks the appropriate game function.

### 5. Hotkey system

After `horsey-mod` gets MinHook + SDL3 input hook, add a `hotkeys` module
that:
- Hooks SDL's keyboard/mouse input handlers in Horsey.exe
- Translates modifier+click into game actions
- Persists key bindings via modforge's settings system
- Live-reload bindings via `--reload` once hot-reload is hardened

---

## Content-design ideas (for after foundations are in place)

### Genetic complexity beyond 240 genes

- **Extension gene table** in horsey-mod (sidecar to vanilla's chromoMap).
- New axes: personality matrix (16-dim), lineage drift, environmental
  adaptation, social temperament.
- Display via custom UI panel (web frontend or imgui overlay).

### Dynasty tracking

- Build an ancestry graph from horse-parent pointers.
- Track which "dynasty" wins races, breeds successfully, etc.
- Display dynasty trees in a web UI.

### Custom locations

- Hook the world-action dispatcher.
- Add a "Repurposed Building" overlay on an unused-feeling vanilla building
  (e.g. Pawn shop) that triggers custom logic.
- Eventually: a fully scripted location built entirely in horsey-mod.

### Social / herd mechanics

- Per-horse personality affects breeding compatibility.
- "Friends" / "rivals" relationships.
- Herd hierarchies (alpha / beta / etc.) affecting race outcomes.

### Procedural events

- Weekly random events: "An inspector arrives", "A storm damages fences",
  "A rival breeder challenges you".
- Injected into the daily-event scheduler (we annotated this at
  `0x14002fe00`).

### Multi-currency economy

- Add "research points", "fame", "favor" as separate currencies.
- Each tied to specific activities.
- Stored in horsey-mod sidecar state.

### Weather + seasons

- Per-day weather state.
- Affects horse hunger drain, breeding success, race times.
- Visible via a UI overlay.

---

## Open research questions

These could change the modding architecture; worth investigating early:

- [ ] Does Horsey have an existing ImGui integration we can reuse? (Probably no.)
- [ ] Is the SDL3 input layer hookable cleanly via DLL? (Probably yes via SDL3
      public API forwarding.)
- [ ] How does the game integrate with Steam. Does it call SteamAPI_Init,
      SteamUtils, etc.? (Yes; we have `SteamUtils010` reference at
      `0x1400c35b0`.)
- [ ] Are there per-frame update hooks we can hijack cleanly? (`0x1400dbe10`
      post_race_wrapup is one; there's a global per-frame tick somewhere.)
- [ ] What does the engine do when DLL load order is wrong? (Test by injecting
      a no-op DLL first.)

---

## Long-term: open the platform

Goal: Horsey modding becomes a real ecosystem. Required steps:

1. Publish `horsey-mod` to crates.io (or git URL).
2. Write a tutorial: "Build your first Horsey mod in 30 minutes".
3. Reference mod (e.g. a clean RPG layer) for new modders to copy.
4. Steam Workshop integration? (Unclear if SDK supports custom uploads.)
5. Auto-updater for horsey-mod itself (so mod authors don't pin to ancient
   game versions).
