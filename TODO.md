# Horsey mods TODO

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

Probably easiest as a `horseyforge` mod once that foundation exists (see
[`MODFORGE-INTEGRATION.md`](MODFORGE-INTEGRATION.md)).

---

## Mod foundations to build

### 1. `horseyforge` crate (per-engine binding for modforge)

Third sibling alongside `ueforge` (UE5) and `unityforge` (Unity). Provides:
- DLL injection via proxy `steam_api64.dll`
- MinHook (native function hooking)
- Game-specific struct accessors (using offsets from our decompilation)
- Game-specific Effect/Trigger/Skill impls on top of modforge's traits

Once `horseyforge` exists, every Horsey mod (hotkeys, RPG layer, custom
species attributes, etc.) inherits modforge's HTTP control plane, RPG
system, settings, hot reload, scanner, counters, etc.

### 2. HTTP control plane (free from modforge)

Wire up modforge's `tiny_http` server with Horsey-specific endpoints. The
op registry + selector grammar are already in modforge; we just register
Horsey ops:
- `horse.list` / `horse.read.<id>` / `horse.write.<id>.<field>`
- `game.year` / `game.money` / `game.sleeps`
- `genes.read` / `genes.write`
- `pop.spawn.<name>` / `pop.list`
- `cheats.no-tire` / `cheats.money` / `cheats.loaded`

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

### 5. Hotkey system (this todo's #1)

After horseyforge exists, add a `hotkeys` module that:
- Hooks SDL's keyboard/mouse input handlers in Horsey.exe
- Translates modifier+click into game actions
- Persists key bindings via modforge's settings system
- Live-reload bindings via Ctrl+R (modforge's hot-reload pattern)

---

## Content-design ideas (for after foundations are in place)

### Genetic complexity beyond 240 genes

- **Extension gene table** in horseyforge (sidecar to vanilla's chromoMap).
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
- Eventually: a fully scripted location built entirely in horseyforge.

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
- Stored in horseyforge sidecar state.

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
- [ ] How does the game integrate with Steam — does it call SteamAPI_Init,
      SteamUtils, etc.? (Yes; we have `SteamUtils010` reference at
      `0x1400c35b0`.)
- [ ] Are there per-frame update hooks we can hijack cleanly? (`0x1400dbe10`
      post_race_wrapup is one; there's a global per-frame tick somewhere.)
- [ ] What does the engine do when DLL load order is wrong? (Test by injecting
      a no-op DLL first.)

---

## Long-term: open the platform

Goal: Horsey modding becomes a real ecosystem. Required steps:

1. Publish `horseyforge` to crates.io (or git URL).
2. Write a tutorial: "Build your first Horsey mod in 30 minutes".
3. Reference mod (e.g. a clean RPG layer) for new modders to copy.
4. Steam Workshop integration? (Unclear if SDK supports custom uploads.)
5. Auto-updater for horseyforge itself (so mod authors don't pin to ancient
   game versions).
