# Horsey as a Base Class. Engine Extension Modding
> **Authoritative on:** the tier model for going beyond data-only mods into engine extension (binary patches, hooking, sidecar state).

**Premise**: the data files are the game's narrow public API. The binary is
the implementation. To build anything you want, treat the binary as malleable
and the data files as one specific configuration on top of it.

Nothing is out of the question. The cost scales with how far you push.

---

## Cost ladder

| Tier | What it lets you do | Tooling | Time investment |
|---|---|---|---|
| **T1: Data mods** | Tweak existing systems | Text editor + Tiled | hours |
| **T2: Binary patches** | Change hardcoded constants (fatigue threshold, gene count, etc.) | Ghidra + a hex editor | days per patch |
| **T3: DLL injection + hooks** | Override functions; inject new behavior into existing code paths | Visual Studio + MinHook | weeks |
| **T4: Runtime control plane** | Live introspect + mutate game state from outside (HTTP, CLI) | T3 + an embedded HTTP server | weeks; one-time |
| **T5: Custom engine systems** | New mechanics that don't exist in vanilla (new attribute axes, new locations, new mini-games) | T3/T4 + your own C++ subsystems | months |
| **T6: Game-state replacement** | Replace large slices of the game (new economy, new genetics, new world simulation) | T5 + significant design work | months |

---

## What's NOT in any data file (hardcoded mechanics)

Confirmed by exhaustive grep of `data/*.xml` and `data/*.txt`:

- **No `STAMINA`, `FATIGUE`, `TIRED`, `RACES_PER_REST`, `ENERGY`, `RECOVERY`, or `COOLDOWN` gene or attribute anywhere.** The "horse can only run one race before tired" mechanic is hardcoded.
- **No base lifespan value.** `OLD_AGE` is a modifier, not a base. The base age-tick rate / death threshold is hardcoded.
- **No hunger/thirst tunable.** `StatusHungry` and `ThoughtHungry` sprites exist (sprites.xml:147, 154) so the mechanic exists, but its rate is hardcoded.
- **No `EnterSleep` / `WakeUp` cooldowns** in `sound.xml`. The sound registry just plays clips; it doesn't tune the mechanic.

Useful RE search anchors for these hardcoded mechanics (use as Ghidra string searches):

- **Sound names** (from `sound.xml`): `HorsesAge`, `WildMating`, `StartNextRace`, `RaceGo`, `WonRace`, `LoseRace`, `TitleCard`, `EnterLocationAbandoned`, `FillHole`, `DestroyTree`, `DestroyMountain`, `ReclaimLand`, `Fish`, `WhipCrack`, `BalloonFly`.
- **UI sprites** (from `sprites.xml`): `StatusOld`, `StatusTired`, `StatusHungry`, `StatusHungry2`, `ThoughtTired`, `ThoughtHungry`, `ThoughtHungry2`, `AnimSleep`, `AnimSleep2`, `SleepMoon`, `AgeWord`.

These are the levers that any "longer lifespan" / "less fatigue" / "no hunger" mod has to reach through engine extension (DLL hook), not XML editing.

## The hard ceilings in the engine (and how to break them)

### 1. The 240-gene limit

**The wall**: `chromoMap` is allocated with 240 entries at startup
(`FUN_1400a3eb0`, our chromomap loader). Each entry is 32 bytes. Gene index
240+ throws "Gene %d not in chromoMap". The gene-application loops in
`apply_gene_to_horse` (`0x14009f680`) iterate up to the table size.

**Approach A. Replace, don't extend**: 242 vanilla genes is already close
to 240, so most of the table is in use. You can REPLACE the semantically
useless ones (e.g. `L_TAIL_FTOB_EVENT` patterns) with your own gene names
and behaviors. Cost: you redefine what those genes DO in the
gene-expression code (a binary patch or DLL hook). Each replaced gene gets
a fresh trait you control.

**Approach B. Expand the table**: patch the binary's `0xf0` (240) constant
to a larger value (e.g. `0x200` = 512). Also patch any iteration bounds
that check against this. The table allocation size (`240 * 32 = 0x1e00`
bytes) needs to grow correspondingly. Difficulty: medium-hard, because the
constant appears in multiple places (loader, lookup, expression). Tooling:
sigscan + bulk patch script.

**Approach C. Bolt on a sidecar gene table**: leave the original 240 alone
but maintain your own parallel "extension genes" table in a DLL. Add hook
calls into `apply_gene_to_horse` so the extension genes' effects run after
the vanilla ones. The horse's "real" data structure stays the same; your
DLL stores extension state in a hashmap keyed by horse pointer.

Realistic ceiling with all three: **thousands of effective gene axes**.

### 2. The 7-supply limit

`game_state[+0x31c..+0x349]` is a 7-entry array of `(uint32 count, uint8 flag_a, uint8 flag_b)` records. Most loops on supplies are sized 6 or 7.

**Break it** by either:
- Patching the loop bounds to a larger number AND extending the struct (move other fields, save format changes).
- Building a side-channel supply system in your DLL with arbitrary categories. Don't touch the original 7; just present a fuller UI from a hook.

### 3. The 400×225 map

`horsey.tmx` is fixed-size. The tmx parser at `0x1400fe2e0` reads the
`width`/`height` attributes but probably has hardcoded buffer sizes
downstream.

**Break it** by:
- Replacing the world with a multi-region system (your DLL teleports player
  between separate "maps" represented as multiple sub-tmx files; the engine
  thinks it's still in one 400×225 map but you swap tiles dynamically based on
  the player's "true" world position).
- Or: patch the bounds for one-time bigger-map experiments.

### 4. Hardcoded building types

Each building (Stable, Track, CRISPR, Sumo, Saloon, etc.) has its own
handler function. New building types need new handlers.

**Break it** by:
- Repurpose unused-feeling buildings (e.g. the Pawn shop) with completely
  different behavior via DLL hook.
- Add a "custom building" handler in your DLL that hooks the world tile
  enter-event. When the player steps on a magic tile, your handler runs
  custom logic.

### 5. Item ID cap at 47

The item table is hardcoded with 48 entries. Item 48+ degrades to a buggy
"single meat" item.

**Break it** by:
- Repurpose unused items (the "single meat" bug suggests at least one slot
  is essentially free if you don't mind redefining it).
- Patch the table size and add new item dispatch entries (binary patch).
- Sidecar item system in your DLL that intercepts pickup/use and adds new
  item categories that the engine doesn't know about.

---

## The "horse as a Rust trait" mental model

You want to think of `Horse` as:

```rust
trait Horse {
    // implemented by the engine
    fn age() -> i32;
    fn skill() -> i32;
    fn run_race(...);
    fn breed_with(other: &Horse);

    // YOUR EXTENSIONS
    fn personality_axis(&self) -> [f32; 16];
    fn lineage_drift(&self) -> Lineage;
    fn psionic_potential(&self) -> u32;
    // ...
}
```

The engine provides the base implementation. Your DLL implements the
extensions by:

1. Hooking the horse-construction function. `apply_gene_to_horse`
   (`0x14009f680`) is the entry point. After the engine builds the horse,
   your code attaches extension state via a `std::unordered_map<HorsePtr,
   ExtensionState>` keyed by the horse's memory address.

2. Hooking horse-update functions. Most per-frame updates pass the horse
   pointer; you can run extension logic post-engine each frame.

3. Hooking horse-destruction. `*(code**)*horse_ptr` is the vtable
   destructor; intercept it to clean up your extension state.

4. Hooking save/load. `save_game_writer` (`0x14006dc80`) and `load_game`
   (`0x14006e480`) are the I/O points. Save your extension state in a
   sidecar file (`save<N>.ext.dat`) keyed by horse roster ID.

This pattern gives you arbitrary horse complexity without touching the
engine's internal layout.

---

## Mod architecture recommendations

### Use a single mod-loader DLL

Pattern: rename `steam_api64.dll` to `steam_api64_real.dll`. Place your mod
DLL named `steam_api64.dll` in the game folder. Your DLL's `DllMain`
forwards every Steamworks API call to the real one (use Detours-style
forwarding exports), and at attach time it:
1. Loads the real Steam DLL.
2. Initializes MinHook.
3. Installs your hooks on the game functions you care about.
4. Optionally starts an HTTP control plane (see below).

This pattern (proxy DLL) is the standard for SDL-based games because they
load Steamworks early and reliably.

### Runtime control plane

For ambitious projects, the FIRST thing to build is a control plane: an
HTTP server inside your DLL that exposes ALL runtime game state plus the
ability to drive ANY in-process operation. Endpoints like:

- `GET /horses` → list all horses with full state
- `GET /horses/<id>` → one horse
- `POST /horses/<id>/age` → set age
- `POST /horses/<id>/breed_with/<other>` → trigger breeding
- `POST /game/year` → set year
- `POST /game/money` → set money
- `POST /cheats/no-tire` → toggle the fatigue cheat
- `GET /memory/<addr>?type=u32` → read arbitrary memory
- `POST /memory/<addr>?type=u32&value=N` → write arbitrary memory

This lets you:
- **Investigate the game** without recompiling (curl + jq is faster than Ghidra).
- **TDD your mod** (assert game state via HTTP between operations).
- **Build external tools** (a web UI for breeding chains, a CLI for save
  editing, a discord bot for race wagering).

In our repo, see `runtime-control-http` skill for the full pattern. It's
the highest-leverage thing to build first because EVERYTHING ELSE
benefits from being able to poke the game from outside.

### State storage for extensions

For your custom horse state (the "psionic potential" axis or whatever):

- In-memory: `std::unordered_map<Horse*, ExtState>` in your DLL. Lookups are
  O(1) by pointer.
- Persistent: write a sidecar file `save<N>.ext.bin` alongside the engine's
  save. Save your hashmap keyed by horse roster index (so it survives even
  if pointer addresses change between sessions). The engine's
  `save_game_writer` is your hook point for this.
- Versioned: include a format version in your sidecar so future extensions
  can grow.

---

## Concrete first-month roadmap

**Week 1. Foundation**
- Set up Visual Studio with a DLL project.
- Build the proxy DLL that loads alongside Steam.
- Verify the game launches with your DLL attached.
- Add a hello-world log to confirm DllMain ran.

**Week 2. Control plane**
- Embed an HTTP server (`crow.h`, single-file C++ HTTP).
- Expose 5 endpoints: `GET /ping`, `GET /horses`, `POST /horses/<id>/name`,
  `GET /game/year`, `POST /game/money`.
- Use the addresses we've already extracted:
  - Money: `game_state[+0x308]` from our `MECHANICS.md`.
  - Year: `game_state[+0x314]`.
  - Horse list: `game_state[+0x130..+0x138]` (or use `+0xb8/+0xc0` for the
    main horse-list iter. Depends on which list you want).

**Week 3. First hook**
- Install a MinHook on `apply_gene_to_horse` (`0x14009f680`).
- Post-call, read the horse's vanilla traits.
- Store an extension state in your hashmap.
- Expose it via `GET /horses/<id>/extension`.

**Week 4. First custom mechanic**
- Pick a small "extension axis", e.g. "musical talent" (0-100).
- Wire it up:
  - Random init in your hook.
  - Save/load via sidecar file.
  - Read/write via HTTP.
  - Visual indicator: hook the horse status-render function and overlay a
    small icon when musical_talent > 50.

**Month 2. Real complexity**
- New mechanic: dynasties. Track ancestry through breeding (the engine
  already has parent IDs in the horse roster; you build a lineage graph on
  top).
- Multiple horse lifecycle stages your DLL adds (foal/yearling/adult/elder)
  with different stats, even though the engine only models one.
- Custom events: random "an inspector arrives and judges your horses"
  events that don't exist in vanilla. Your DLL fires them by injecting into
  the daily-event scheduler.

---

## Where in the engine to insert hooks

We've documented these entry points; they're well-suited as hook targets:

| Function | Address | Hook for |
|---|---|---|
| `apply_gene_to_horse` | `0x14009f680` | Horse construction; attach extension state |
| `check_horse_eligibility` | `0x1400dde40` | Action gating (override "too tired" etc.) |
| `retire_horse_handler` | `0x1400df280` | Custom retirement logic |
| `compute_horse_price` | `0x1400dcab0` | Custom pricing |
| `crispr_lab_state_machine` | `0x140089510` | Custom CRISPR mechanics |
| `breeding_state_machine` | `0x1400e0aa0` | Custom breeding rules (extension genes inherit) |
| `save_game_writer` | `0x14006dc80` | Save sidecar |
| `load_game` | `0x14006e480` | Load sidecar |
| `draw_pause_status` | `0x140066200` | Add your own pause-menu buttons |
| `tmx_map_parser` | `0x1400fe2e0` | Custom tmx properties / object types |
| `pop_genome_builder` | `0x140092820` | Inject custom spawn logic per population |
| `daily_horse_event_emitter` | `0x14002fe00` | Custom daily events |
| `track_state_machine` | `0x14002d7c0` | Custom race rules |
| `circus_event_handler` | `0x140039190` | Custom circus events |
| `sumo_match_handler` | `0x14007b2e0` | Custom sumo rules |
| `power_plant_handler` | `0x1400693b0` | Custom power-plant interactions |
| `world_action_dispatcher` | `0x140107660` | Custom world-tile actions |
| `hot_air_balloon_controller` | `0x14010a5e0` | Custom balloon actions |

All of these are documented in `decompiled/annotated/`. Read the deep
annotations (`*.c` files) for the struct layouts each handler uses.

---

## Reference implementations (similar projects)

To save time, look at how other indie-game modding scenes handle this:

| Game | Modding pattern | What to study |
|---|---|---|
| Stardew Valley (XNA/MonoGame) | SMAPI proxies the game with managed runtime hooks | how an open API surface gets retrofitted onto a non-modded game |
| Schedule 1 (IL2CPP Unity) | MelonLoader patches IL2CPP-compiled methods via Harmony | how to do per-method runtime patching at scale |
| Skyrim (native PE) | SKSE proxies via DLL injection, then SkyUI etc. ride on top | proxy DLL + scripted-overlay pattern |
| Factorio (Lua-scripted) | Lua API is the official extension point | the kind of API surface we'd RECREATE for Horsey |

The closest analogy here is **Skyrim/SKSE**: native binary, DLL injection,
proxy-loader pattern. SKSE then exposes a Lua/Papyrus-ish runtime that
gameplay mods sit on top of.

For Horsey: build "HSE" (Horsey Script Extender). The DLL is the binding
layer; gameplay mods are JSON/Lua/Python configs that drive your HSE
through its HTTP control plane.

---

## What this unlocks long-term

With the engine treated as a base trait, the kinds of mods you can build:

- **Genetic complexity**: 16-axis personality matrix, polygenic traits with
  dominance/recessive interactions, environmental epigenetics, lineage drift.
- **Economic complexity**: market depths, real-time price-setting, multiple
  currencies, factions with separate economies.
- **World complexity**: weather, seasons, day/night, migration patterns,
  pollution from the power plant affecting downwind tiles, fence integrity
  decay.
- **Social complexity**: horse personalities affect breeding compatibility,
  social hierarchies, herd dynamics, jealousy mechanics.
- **Narrative complexity**: a procedural story system that emits events based
  on player+horse history.
- **Race complexity**: betting pools that other NPCs participate in, betting
  fraud, race-fixing mini-games, multi-day stage races.
- **Multiplayer**: a Steam-P2P based system where two players coexist in the
  same simulated island with separate horse rosters.

None of these are out of reach. They each take real engineering work, but
the foundation (DLL + hooks + control plane + sidecar state) is what makes
all of them possible.

---

## Practical tooling stack

| Component | Choice | Why |
|---|---|---|
| Language for DLL | C++ (MSVC) | Matches the game's ABI; cleanest hook target |
| Hook library | **MinHook** | Lightweight, x64-friendly, single-header |
| HTTP server | **crow** or **httplib** | Single-file, async, easy embed |
| JSON | **nlohmann/json** | De facto standard |
| Build | CMake or Visual Studio direct | Either works for x64 DLLs |
| RE workflow | Ghidra (we have it) + our annotated files | Reuses our existing analysis |
| Live debugging | x64dbg | Free Windows debugger; attach to running game |
| Memory inspection | Cheat Engine | Initial recon for fields we haven't found |

---

## The "first thing to build" decision

If you're going to invest weeks/months in this, the FIRST thing is the
**HTTP control plane**. Everything else benefits from being able to:
1. Read game state without recompiling
2. Trigger operations from a script/CLI
3. Test invariants
4. Build external UIs (web dashboards, CLIs, mobile apps)

Without this, every change is "edit code → recompile → relaunch game →
manually navigate to the test scenario → observe". With it, every change is
"hot-reload DLL → curl the new endpoint → see result".

The decompilation work we've done gives you the addresses and struct
offsets needed. Combined with MinHook + httplib, the control plane is
roughly **500-1000 lines of C++**.

---

## TL;DR

- **Nothing is out of the question.** The engine is fixed but extensible.
- **The 240-gene limit, 400×225 map, 7 supplies, etc. are SOFT caps**. All
  are removable with binary patches or DLL hooks.
- **Horse is your base class**. Extend it with your own state in a hashmap.
- **Build the HTTP control plane first**. It accelerates everything else by
  10x.
- **Proxy `steam_api64.dll`** for clean DLL injection.
- **Use MinHook** for x64 function hooking.
- **Sidecar save files** for persistent extension state.
- **Reference**: Skyrim's SKSE for the architectural pattern.

The realistic complexity ceiling isn't the engine; it's the time you put
into building extensions.
