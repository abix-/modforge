# modforge Integration. Yes, It Helps Massively
> **Authoritative on:** how horsey-mod consumes the modforge framework (HTTP server, ops registry, settings, RPG layer).

You already built the runtime control plane I was about to suggest. This
doc maps your existing **modforge** ecosystem onto Horsey.

---

## Table of contents

- [What you have today](#what-you-have-today)
- [What we need to build: `horsey-mod`](#what-we-need-to-build-horsey-mod)
- [Reuse audit: what comes free from modforge](#reuse-audit-what-comes-free-from-modforge)
- [Concrete first-week plan](#concrete-first-week-plan)
- [What it means strategically](#what-it-means-strategically)
- [Risks / open questions](#risks-open-questions)
- [Decision](#decision)

---

## What you have today

```
grounded2mods/
├── modforge/         ← engine-agnostic Rust core (THE foundation)
├── ueforge/          ← UE5 + UE4SS binding (proven on Grounded 2)
├── unityforge/       ← Unity + BepInEx binding (Mono + IL2CPP)
└── (game-side mods)/
    ├── grounded2-rpg/        ← consumes ueforge
    ├── outworld-station-tweaks/  ← consumes ueforge
    └── ...
```

**modforge** is engine-agnostic. It provides:

| Module | What |
|---|---|
| `envelope` | Op request/response envelope |
| `ops` | Op registry + dispatch |
| `selector` | Grammar parser for selecting game objects |
| `server` | HTTP server (tiny_http) + auth + body cap |
| `settings` | JSON config + debounced save + hot reload |
| `counters` | Atomic counters + TimeScope macros |
| `ring` | Bounded ring buffer |
| `scanner` | Process memory scanner |
| `winproc` | Win32 process probes |
| `shutdown` | Ordered shutdown registry |
| `log` | File + stdout sinks |
| `hot_reload` | Protocol types for live-reload |
| `args` | JSON arg helpers |
| **`rpg`** | Effect / Trigger / Skill traits + XP curve + Tracker + persistence + catalog |
| `snapshots` | Generic projection-snapshot types |
| `debug` | Dispatch glue |
| `ui` | Declarative tab API (rendered per-framework) |
| `worker` | Worker handle trait |

All of this is **free** for a Horsey mod. We don't reimplement any of it.

---

## What we need to build: `horsey-mod`

A third sibling crate alongside `ueforge` and `unityforge`. Same role:
provide the engine-specific bindings that satisfy modforge's traits.

### How Horsey differs from UE5 / Unity

| Concern | UE5 / ueforge | Unity / unityforge | Horsey / horsey-mod |
|---|---|---|---|
| Plugin loader | UE4SS C++ shim | BepInEx C# shim | **None**. Must inject via proxy DLL |
| Runtime introspection | UObject reflection | Mono reflection | **None**. Use hardcoded addresses from our decompilation |
| Universal hook point | `UFunction::ProcessEvent` | `MonoMethod` invocation | **None**. Per-function MinHook hooks |
| UI overlay | UE4SS ImGui | BepInEx ImGui | TBD (ImGui via DX12 hook, or web frontend only) |
| Class lookup | `GObjects` walk | Mono class lookup | Hardcoded function pointers from our analysis |
| Field access | UE reflection | Mono reflection | `*(T *)(ptr + 0xOFFSET)` using our struct offsets |

The first three are why Horsey is HARDER to bind than UE5 / Unity. The
last three are why our **prior 100% decompilation work is the
prerequisite**. Without the addresses and offsets we extracted,
horsey-mod has nothing to bind to.

### horsey-mod crate layout (proposed)

```
horsey-mod/
├── Cargo.toml         (depends on modforge; crate-type = ["cdylib", "rlib"])
├── build.rs           (compiles a small C++ shim for SDL hooks)
├── src/
│   ├── lib.rs
│   ├── mod_main.rs    (DllMain + ctor: load real steam_api64 + init modforge)
│   ├── injection.rs   (proxy steam_api64.dll forwarding)
│   ├── hooks/
│   │   ├── mod.rs
│   │   ├── minhook.rs (Rust wrapper around MinHook)
│   │   └── targets.rs (the 18 function addresses we identified)
│   ├── horse.rs       (Horse struct accessors using our +0x1fc, +0x205 etc.)
│   ├── gamestate.rs   (GameState accessors: money +0x308, year +0x314, ...)
│   ├── ops.rs         (Horsey-specific op registrations on modforge's registry)
│   ├── rpg.rs         (RPG Effect impls that touch horse / gamestate fields)
│   ├── input.rs       (SDL3 input hook for hotkeys)
│   ├── ui.rs          (ImGui overlay, OR shim out to modforge::ui)
│   └── version.rs     (binary version detection + offset table per-version)
└── cpp/
    └── shim.cpp       (minimal C++ for SDL3 interop; mirrors ueforge/cpp/)
```

### Key bindings horsey-mod provides

#### A. DLL injection (proxy `steam_api64.dll`)

Horsey loads Steamworks at startup. We rename `steam_api64.dll` →
`steam_api64_real.dll`, drop our `horsey.dll` as `steam_api64.dll`.
DllMain:

```rust
#[no_mangle]
pub extern "system" fn DllMain(hinst: HINSTANCE, reason: u32, _: *mut ()) -> i32 {
    if reason == DLL_PROCESS_ATTACH {
        // Load real steam_api64
        injection::load_real_steam_api();
        // Spawn init thread (don't block DllMain)
        std::thread::spawn(|| {
            modforge::log::init();
            modforge::settings::load(SETTINGS_PATH);
            modforge::server::start_with_auth(SERVER_ADDR, AUTH_TOKEN);
            hooks::install_all();
            ops::register_horsey_ops();
            log::info!("horsey-mod attached");
        });
    }
    1
}
```

#### B. Op registry. Horsey-specific endpoints

Register Horsey ops onto modforge's existing op registry:

```rust
modforge::ops::register("horse.list", |args| -> OpResponse {
    let horses = horse::list_all();   // walks game_state[+0x130..+0x138]
    Ok(json!({ "horses": horses }))
});

modforge::ops::register("horse.read", |args| {
    let id: i32 = args.get_i32("id")?;
    let h = horse::by_id(id)?;
    Ok(json!({
        "name": h.name(),
        "age": h.age(),               // *(int*)(ptr + 0x1fc)
        "max_age": h.max_age(),       // *(int*)(ptr + 0x200)
        "skill": h.skill(),           // *(int*)(ptr + 0x21c)
        "tired_a": h.tired_a(),       // *(u8*)(ptr + 0x205)
        "tired_b": h.tired_b(),       // *(u8*)(ptr + 0x206)
        "litter_stat": h.litter_stat(),  // *(int*)(ptr + 0x254)
        // ...
    }))
});

modforge::ops::register("game.money", |args| {
    let val: i32 = args.get_i32("value")?;
    gamestate::set_money(val);   // *(int*)(state + 0x308) = val
    Ok(json!({ "money": gamestate::money() }))
});

modforge::ops::register("cheats.no_tire", |args| {
    let enabled: bool = args.get_bool("enabled")?;
    unsafe { *(DAT_1403d95c5 as *mut u8) = enabled as u8; }
    Ok(json!({ "no_tire": enabled }))
});
```

Now `curl -H "Auth: <token>" http://localhost:PORT/op` with these payloads
drives the game from outside. All the boilerplate (HTTP, auth, JSON
envelope, error mapping) is in modforge.

#### C. RPG layer on modforge::rpg

Define Horsey skills as `Skill<HorseyEffect>` rows:

```rust
use modforge::rpg::{Skill, StandardEffect};

pub fn catalog() -> Vec<Skill<HorseyEffect>> {
    vec![
        Skill::new("stable_master")
            .display_name("Stable Master")
            .description("Reduces fatigue accumulation rate")
            .effect(HorseyEffect::FatigueScaler { mult: 0.5 })
            .max_level(20),
        Skill::new("veterinarian")
            .display_name("Veterinarian")
            .description("Horses live longer")
            .effect(HorseyEffect::LifespanBonus { years: 2 })
            .max_level(10),
        Skill::new("breeder")
            .display_name("Breeder")
            .description("Bigger litters")
            .effect(HorseyEffect::LitterBonus { add: 2 })
            .max_level(10),
        // ...
    ]
}
```

The `HorseyEffect` enum implements `modforge::rpg::Effect`, which means
modforge's RPG system (XP curve, level-up, persistence, tab UI, etc.) all
work out of the box.

#### D. Hotkeys (the #1 TODO item)

```rust
// In hooks/input.rs:
extern "C" fn sdl_pollevent_hook(event: *mut SDL_Event) -> i32 {
    let ret = unsafe { ORIGINAL_SDL_POLLEVENT(event) };
    if ret != 0 {
        let ev = unsafe { *event };
        if ev.type_ == SDL_EVENT_MOUSE_BUTTON_DOWN {
            let mods = sdl_getmodstate();
            let game_action = match (ev.button.button, mods) {
                (SDL_BUTTON_LEFT, MOD_SHIFT) => HotkeyAction::TransferHorse,
                (SDL_BUTTON_LEFT, MOD_CTRL)  => HotkeyAction::ToggleFavorite,
                (SDL_BUTTON_LEFT, MOD_ALT)   => HotkeyAction::ShowStats,
                _ => HotkeyAction::None,
            };
            if game_action != HotkeyAction::None {
                hotkey::dispatch(game_action, ev.button.x, ev.button.y);
                // Optionally suppress the original event:
                unsafe { (*event).type_ = SDL_EVENT_USER; }
            }
        }
        if ev.type_ == SDL_EVENT_KEY_DOWN {
            match ev.key.keysym.sym {
                SDLK_R => hotkey::dispatch(HotkeyAction::RaceSelected, 0, 0),
                SDLK_F => hotkey::dispatch(HotkeyAction::FeedAll, 0, 0),
                SDLK_S => hotkey::dispatch(HotkeyAction::SleepAll, 0, 0),
                // ...
                _ => {}
            }
        }
    }
    ret
}
```

The mappings live in modforge's `settings` system, so they're user-editable
via JSON and live-reload via Ctrl+R.

---

## Reuse audit: what comes free from modforge

| Need | Source | Status |
|---|---|---|
| HTTP server with auth | `modforge::server` | free |
| Op envelope (JSON in/out) | `modforge::envelope` | free |
| Op registry + dispatch | `modforge::ops` | free |
| Selector grammar (e.g. `horse[age>10]`) | `modforge::selector` | free |
| Settings JSON + hot reload | `modforge::settings` | free |
| Counters / metrics | `modforge::counters` | free |
| Ring buffer (for event logs) | `modforge::ring` | free |
| Process memory scanner | `modforge::scanner` | free, useful for finding offsets in a new game version |
| Win32 process probes | `modforge::winproc` | free |
| Shutdown handling | `modforge::shutdown` | free |
| Logging (file + stdout) | `modforge::log` | free |
| Hot-reload protocol | `modforge::hot_reload` | free |
| RPG: Effect/Trigger/Skill | `modforge::rpg` | free, but we write `HorseyEffect` impls |
| Snapshots (projection diffs) | `modforge::snapshots` | free |
| Debug dispatch | `modforge::debug` | free |
| UI tabs (declarative) | `modforge::ui` | free trait surface; rendering is per-framework |
| Worker handle | `modforge::worker` | free |

What we have to build:
1. `horsey-mod::injection`. Proxy steam_api64.dll
2. `horsey-mod::hooks`. MinHook wrapper + the 18 target function addresses
3. `horsey-mod::horse` / `gamestate`. Typed accessors using our offsets
4. `horsey-mod::ops`. Register Horsey-specific ops
5. `horsey-mod::rpg::HorseyEffect`. Concrete Effect impls
6. `horsey-mod::input`. SDL3 hook for hotkeys
7. `horsey-mod::ui`. Overlay (TBD: ImGui via DX12 hook, or web-only)

Probably **~3000-6000 lines of Rust** for the full binding, given we already
have all the addresses. Each game-side mod (RPG layer, hotkeys, custom
species, etc.) is much smaller (~500 lines each).

---

## Concrete first-week plan

**Day 1: bootstrap**
- Add `horsey-mod/` to `grounded2mods/Cargo.toml` workspace
- Set up `Cargo.toml` with `modforge = { path = "../modforge" }`
- Wire up DllMain that loads real steam_api64
- Verify game launches with our DLL attached (log a "horsey-mod attached" line)

**Day 2: control plane**
- Bring up `modforge::server` with auth
- Add `GET /ping` op
- `curl localhost:PORT/op` from another terminal, see "pong"

**Day 3: first read op**
- Implement `gamestate::money()` reading from `DAT_1403fb0d8 + 0x308`
- Register `game.money` op (GET-style)
- Verify via curl: `{"money": 1234}`

**Day 4: first write op**
- Implement `gamestate::set_money(value)`
- Register `game.money` op (POST with `{"value": 10000}`)
- Verify in-game: cash UI updates

**Day 5: first hook**
- Add MinHook crate
- Hook `apply_gene_to_horse` (`0x14009f680`)
- Log each new horse's name + age via `modforge::log`
- Verify in-game: spawning new horses prints to log

**Day 6: horse list**
- Walk `game_state[+0x130..+0x138]` (the active horse list)
- Register `horse.list` op
- Verify via curl: returns JSON array

**Day 7: hotkey skeleton**
- Hook `SDL_PollEvent`
- Detect `Shift+Click` and log it (no game action yet)
- Verify: console logs `[horsey-mod] shift+click at (x,y)`

After this week we have a working DLL with HTTP, hooks, and the foundation
for everything else.

---

## What it means strategically

Without modforge: building horsey-mod from scratch = 2-3 months.

With modforge: building horsey-mod = **2-3 weeks** because:
- HTTP server, auth, JSON envelope, op registry: **already built**
- RPG system, settings, hot reload: **already built**
- Logging, counters, scanner: **already built**

Each Horsey mod that consumes horsey-mod benefits from modforge upgrades
automatically (the same way grounded2-rpg benefits from ueforge upgrades).

Your existing infrastructure compresses what would have been a major
project into a manageable one. The 100% decompilation work we already did
gave us the addresses; modforge gives us the rest of the runtime.

---

## Risks / open questions

1. **modforge crate API stability**: if ueforge / unityforge are tightly
   coupled to specific modforge versions, we may need to pick a stable
   commit and pin against it.

2. **Per-binary-version offsets**: when Horsey updates, function addresses
   shift. `horsey-mod::version` should detect the binary hash and load
   the right offset table. modforge's `scanner` module is useful here for
   pattern-based fallback.

3. **ImGui or web UI**: ueforge has ImGui via UE4SS's plugin. For Horsey
   we don't have that. Options: hook DX12 to add ImGui, OR build a web
   frontend over modforge's HTTP server, OR both. The web-first approach
   is faster and modforge already powers it.

4. **DLL load order**: Horsey loads steam_api64 early. Our proxy DLL must
   handle the case where the game hasn't initialized SDL yet when our
   DllMain runs. Spawn a worker thread that waits for SDL to be ready,
   then installs hooks.

5. **Save compatibility**: hooks that add fields to horses must serialize
   them in a sidecar save file (`save<N>.ext.bin`) keyed by roster index.
   Don't touch the engine's save format.

---

## Decision

**YES, build horsey-mod as a sibling crate in grounded2mods.** It's the
clean answer. Everything we've planned for Horsey modding (hotkeys, RPG
layer, custom genes, content extensions, control plane) becomes a
horsey-mod consumer.

The first mod to ship: a simple `horsey-hotkeys` crate that adds
Shift+Click + the rest of the keybindings. ~500 lines on top of
horsey-mod. After that we layer on the RPG and the gene-extension
work.

---

## Implementation status (2026-05-15)

### 1. `horsey-mod` crate (per-engine binding for modforge): SHIPPED

Status: working. Lives in [`abix-/Grounded2Mods`](https://github.com/abix-/Grounded2Mods) as a third sibling to `ueforge` and `unityforge`. Pivoted from the originally-planned proxy-`steam_api64.dll` approach to a `CreateRemoteThread(LoadLibraryW)` injector after MSVC link.exe's `.DEF` forwarder syntax failed for 1,089 Steam API exports.

What's done:

- `horsey-inject.exe` finds Horsey.exe and injects `horsey.dll`.
- DllMain spawns a worker thread that initializes modforge logging, settings, HTTP server with auth.
- 18 ops (initial set) registered for read/write of game state + cheats + horse fields. (See GENE-CATALOG.md Part 3 for the 30+ ops shipped with the 480-gene work since.)
- Staged-DLL pattern: each inject copies the cargo output to a fresh timestamped filename so cargo can rebuild while the game is running.
- `_shutdown` op + `--reload` flag implement the hot-reload swap.
- `no_tire = true` set at every DLL attach via `patches::sleep_safe_no_tire`.

What's pending:

- **Hot-reload hardening** (currently causes delayed crash). The `_shutdown` op acknowledges, the listener thread joins, but helper threads inside the old DLL may still have stack frames when `FreeLibrary` is called. Options under consideration:
  - Poll port 33077 in injector after `_shutdown` until truly closed, then wait another ~500ms before `FreeLibrary`.
  - Have `_shutdown` itself call `FreeLibraryAndExitThread` from the last remaining thread (atomic self-unload).
  - Add a `_drain` op that returns only after all helper threads have exited.
- MinHook integration (superseded by `retour` for shipped detours; see [`HOOKING-STRATEGY.md`](HOOKING-STRATEGY.md)).
- `horses.live` walks the wrong list (track-manager's on-track horses, not the full roster). Need to find the right list pointer for the roster UI.

### 2. HTTP control plane: SHIPPED

`modforge::server::spawn` is used directly. The 18 (initial) registered ops are in `horsey-mod/src/ops.rs`. Auth is in `X-Ueforge-Auth` header; token is written to `horsey.auth` next to the DLL on each launch.

Currently registered ops (initial set; the 480-gene work added 30+ more under `genes.ext.*` / `patterns.*` / `game.build_info`):

- Liveness: `ping`, `list_ops`.
- State reads: `game.read`, `game.money.get`, `game.year.get`, `cheats.*`.
- State writes: `game.money.set`, `game.money.add`, `game.year.set`, `cheats.no_tire.set`, `cheats.debug_mode.set`.
- Horses: `horses.count`, `horses.roster_addr`, `horses.live`, `horse.read`, `horse.set_age`, `horse.set_max_age`, `horse.clear_tiredness`.
- Hot reload: `_shutdown`.

To add (still open):

- `horses.list_full` walking the full roster (not just on-track).
- `save.export` / `save.import` for save backup ops.
- `pop.spawn` and `pop.list` for population creation.
- `genes.read` / `genes.write` for runtime gene editing on the VANILLA range (the extended range already has these via `genes.ext.*`).

## Other modforge-consumer plans

These are horsey-mod features that ride on modforge primitives (rpg, settings, scanner). They're not all shipped; this section captures the design.

### Save-edit tool (`save_edit.py`)

Extend `save_edit.py` with set/write operations now that we have the full save format documented in `decompiled/annotated/0x14006dc80_save_game_writer.c`. Reuses the BXSAVEXT codec (see [`SAVE-FORMAT.md`](SAVE-FORMAT.md)) for ext alleles and the vanilla 3-bit-per-allele encoding for the original 240.

### RPG layer for Horsey

Use modforge's RPG module (Effect / Trigger / Skill + XP curve + persistence). First skills:

- "Stable Master". Reduces fatigue accumulation rate.
- "Veterinarian". Increases lifespan.
- "Breeder". Boosts litter sizes.
- "Trainer". Boosts race speed.
- "Geneticist". Unlocks faster CRISPR.

Map each skill to a `StandardEffect` variant that adjusts the appropriate horse-struct field or hooks the appropriate game function.

### Hotkey system

After `horsey-mod` gets an SDL3 input hook (D-tier 4 work; not yet started), add a `hotkeys` module that:

- Hooks SDL's keyboard / mouse input handlers in Horsey.exe.
- Translates modifier+click into game actions.
- Persists key bindings via modforge's settings system.
- Live-reload bindings via `--reload` once hot-reload is hardened.

The user-locked v1 binding is `Shift+Click` smart-transfer of a horse between vehicle / pasture / race-line (see `todo.md` "Hotkeys"). All other bindings are parking-lotted.
