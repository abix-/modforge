# unityforge + modforge: plan

> **Status:** plan, 2026-05-12. Sibling to
> [`wild-west-miner-research.md`](wild-west-miner-research.md).
>
> **Stack decision (2026-05-12, final):** all Rust. unityforge
> is a Rust crate peer of ueforge. modforge is a Rust crate
> consumed natively by both. Game mods are Rust crates. The
> only C# is a small per-host shim (analogous to ueforge's
> 502-line C++ shim against UE4SS) that bootstraps the Rust
> cdylib inside BepInEx and bridges Mono reflection +
> HarmonyLib to Rust function pointers. **No FFI between
> Rust crates**. The only FFI is the shim seam.
>
> Supersedes the earlier draft of this doc that proposed a
> C# unityforge consuming a Rust modforge-core via P/Invoke.
> All-Rust is dramatically simpler and gives us native code
> reuse without marshalling, two-language stack traces, or
> lowest-common-denominator APIs.
>
> **North star.** The goal isn't a Wild West Miner mod. The
> goal is to make modding *any random UE5 or Unity Mono game*
> cheap going forward. UE5 + Unity Mono cover the
> overwhelming majority of mid-budget PC games shipping
> today. Wild West Miner is the proof-point for the
> unityforge half; Grounded 2 / Outworld Station are the
> proof-points for the ueforge half. After both halves
> exist, picking up a new target collapses from "months of
> research + plumbing" to "a Rust crate against a known
> framework." That payoff repeats for every future game.
> Front-loaded framework investment is the right call when
> it amortizes across N future projects.

## 1. The shape, restated

Four Rust crates plus one C# shim:

1. **modforge** (new Rust crate). Engine-agnostic core
   consumed natively by both frameworks. Holds everything
   that doesn't touch UObject or Mono: op envelope, op
   registry, selector grammar, settings, counters, ring,
   scanner, winproc, server, shutdown, log, the pure RPG
   half (xp / progress / format / state / store / disabled /
   catalog), and the Effect + Trigger + Skill *traits*
   themselves. Game-agnostic standard Effect / Trigger
   implementations CAN live here too, since both frameworks
   speak Rust.
2. **ueforge** (Rust crate, exists). The UE5 / UE4SS
   bindings. Adds UObject SDK, vtable + PE hooks, PE queue,
   data tables, UE-specific Effect implementations, the C++
   shim against UE4SS. Depends on `modforge`.
3. **unityforge** (new Rust crate). The Unity Mono bindings.
   Adds Mono reflection wrappers, HarmonyLib bridge,
   `Singleton<T>` / `StaticInstance<T>` access,
   ScriptableObject browser, Unity-specific Effect
   implementations. Depends on `modforge`. Ships a small
   C# shim DLL beside its cdylib (see below).
4. **`unityforge-shim`** (small C# project). One
   `[BepInPlugin]` that loads `unityforge.dll` via
   `[DllImport]`, passes a function-pointer bridge table for
   Mono reflection + HarmonyLib, and forwards
   `Awake` / `Update` / `OnDestroy` into Rust. Analogous to
   ueforge's `cpp/ueforge_shim.cpp` (502 lines). Likely
   under 1000 lines of C#.
5. **Game mods** (Rust cdylib crates). `grounded2-rpg` and
   `outworld-station-tweaks` exist. `wwm-rpg` is new. All
   pure Rust. Depend on `ueforge` or `unityforge` plus
   `modforge`.

Game mods are downstream consumers, not inputs to this plan.

### Why all-Rust ends the polyglot-tax debate

- **Native code reuse.** modforge's Effect / Trigger / Skill
  traits are normal Rust traits. ueforge implements them for
  UE; unityforge implements them for Unity. No FFI between
  modforge consumers.
- **One language, one debugger, one test stack.** Stack
  traces inside the framework cross zero language
  boundaries.
- **The hard FFI is contained.** The Mono + Harmony bridge
  is a single seam (the C# shim) with a fixed surface area
  (~30-50 entry points). Once it works, it doesn't change as
  we add framework features.

## 2. What goes in modforge

**No duplication.** modforge is a Rust crate. ueforge and
unityforge are both Rust crates that depend on it via
`[dependencies]` in their Cargo.toml. Engine-agnostic code
lives in modforge once and both frameworks call it natively.
No FFI between Rust crates. The audit below tells you where
each existing ueforge file goes.

### modforge as a Rust crate

```
modforge/
  Cargo.toml                     # [lib] crate-type = ["rlib"]
  src/
    lib.rs
    envelope/                    # OpResponse + parse_request
    ops/                         # OpDef + OpRegistry + dispatch + list_ops
    selector/                    # grammar parser + SelectorRegistry
    settings/                    # JSON file + debounced save
    counters/                    # AtomicU64 + TimeScope + macros
    ring/                        # bounded ring buffer
    scanner/                     # process memory scanner
    winproc/                     # Win32 process probes
    server/                      # tiny_http listener + auth token + body cap
    shutdown/                    # ShutdownRegistry + handler ordering
    log/                         # file + stdout sink + level + format
    hot_reload/                  # protocol types
    args/                        # JSON arg helpers
    rpg/
      effect.rs                  # Effect trait (engine-agnostic)
      trigger.rs                 # Trigger trait + TriggerCtx
      skill.rs                   # SkillDef + SkillRegistry
      tracker.rs                 # Tracker (dispatches Effect impls)
      xp.rs                      # pure math
      progress.rs                # pure math
      format.rs                  # percent format
      state.rs                   # SkillsState
      store.rs                   # JSON persistence
      disabled.rs                # per-skill toggle
      catalog.rs                 # JSON catalog parse
      std_effect_pure.rs         # game-agnostic standard effects (formatting-only, no engine access)
  spec/                          # design-time schemas + docs
    op-envelope.json
    selector-grammar.md
    op-registry.md
    generic-primitives.md
    skill-catalog.json
    rpg-persistence.json
    xp-curve.md
    effect-kinds.md
    trigger-kinds.md
  test-corpus/                   # request/response pairs both frameworks pass
    ops/...
    rpg/...
    selector/...
  docs/
    methodology.md               # RESEARCH.md elevated
    composition-model.md         # Effects + Triggers + Skills
    def-registry.md              # the CRD pattern
    naming.md
  client/                        # shared HTTP test client (Rust)
  deploy/                        # modforge-deploy (Rust binary)
```

All-Rust. ueforge: `modforge = { path = "../modforge" }`.
unityforge: same. No FFI. No `cdylib` on modforge. The only
cdylibs in the workspace are the actual game-mod crates and
the framework crates that themselves load into a host.

### Module audit (where each ueforge subsystem goes)

All-Rust simplifies the destinations. "Goes to modforge"
means a file moves and ueforge replaces it with `pub use
modforge::<mod>::*;`. No FFI seams.

| ueforge today | Lines | Destination | Notes |
|---|---|---|---|
| `args.rs` | small | `modforge::args` | JSON helpers |
| `client/` | 1751 | `modforge::client` | HTTP test client, engine-agnostic |
| `counters.rs` | small | `modforge::counters` | AtomicU64 + TimeScope |
| `damage/` | 360 | **ueforge** | UE damage hook |
| `data_table.rs` | 1410 | **ueforge** | UDataTable |
| `debug/` | 264 | `modforge::debug` | dispatch glue is generic |
| `discovery.rs` | 421 | **ueforge** | UE GObjects walker |
| `dynamic_tweaks.rs` | 247 | **ueforge** | UE CDO writes |
| `envelope.rs` | small | `modforge::envelope` | OpResponse + parse_request |
| `fall.rs` | 215 | **ueforge** | UE fall hook |
| `hook/` | 1102 | **ueforge** | UE vtable + PE (unityforge has its own `mono_hook` module wrapping the Harmony bridge) |
| `hot_reload.rs` | small | partial | protocol types -> `modforge::hot_reload`; cdylib swap mechanics stay per-framework |
| `inventory/` | 560 | **ueforge** | UE inventory hooks |
| `log.rs` | 214 | `modforge::log` | sink + level + format |
| `mod_main.rs` | 329 | **ueforge** | CppUserModBase + UE4SS entry (unityforge has its own `mod_main` against the C# shim) |
| `ops.rs` | 866 | split | `OpDef` + `OpRegistry` + dispatch -> `modforge::ops`. UE-specific primitives (`read_bytes`, `walk_class`, `inspect_address`, `exec_call`) stay in ueforge. unityforge ships Unity equivalents with same op-name surface |
| `parms.rs` | small | **ueforge** | UE UFunction parm marshalling |
| `pe_queue.rs` | 473 | **ueforge** | UE ProcessEvent queue (unityforge has `main_thread_queue` against Unity's tick) |
| `ring.rs` | 138 | `modforge::ring` | bounded ring buffer |
| `rpg/effect.rs` | 475 | `modforge::rpg::effect` | Effect trait, engine-agnostic |
| `rpg/trigger.rs` | 223 | `modforge::rpg::trigger` | Trigger trait + TriggerCtx |
| `rpg/skill.rs` | 112 | `modforge::rpg::skill` | SkillDef + SkillRegistry |
| `rpg/tracker.rs` | 601 | `modforge::rpg::tracker` | Generic over Effect impls; dispatches whatever the framework registers |
| `rpg/xp.rs` | 149 | `modforge::rpg::xp` | pure math |
| `rpg/progress.rs` | 30 | `modforge::rpg::progress` | pure math |
| `rpg/format.rs` | 171 | `modforge::rpg::format` | percent format |
| `rpg/state.rs` | 77 | `modforge::rpg::state` | SkillsState |
| `rpg/store.rs` | 637 | `modforge::rpg::store` | JSON persistence |
| `rpg/disabled.rs` | 117 | `modforge::rpg::disabled` | per-skill toggle |
| `rpg/poller.rs` | 254 | `modforge::rpg::poller` | slot-key polling loop |
| `rpg/slot_key.rs` | 78 | partial | trait -> `modforge::rpg::slot_key`. UE-specific resolver impl stays in ueforge; unityforge implements the trait for Mono |
| `rpg/std_effect.rs` | 543 | partial | engine-agnostic effects (e.g. progress-curve formatters) -> `modforge::rpg::std_effect`. Engine-touching ones (`PlayerFloatEffect` reading UObject CDO) stay in ueforge; unityforge ships its own |
| `rpg/vanilla.rs` | 166 | partial | generic cache mechanics -> `modforge::rpg::vanilla`. Engine-specific field-handle type stays per-framework |
| `rpg/ops.rs` | 133 | `modforge::rpg::ops` | `skill_list`, `skill_levelup`, `skill_refund`, `skill_state` ops |
| `rpg/tab.rs` | 164 | partial | declarative tab shape -> modforge; ImGui rendering per-framework |
| `rpg/health.rs` | 208 | **ueforge** | UE health Effect impl |
| `rpg/status.rs` | 121 | **ueforge** | UE status-effect impl |
| `rpg/mod.rs` | 66 | `modforge::rpg` (pub use) | re-exports |
| `scanner.rs` | 919 | `modforge::scanner` | process memory scanner |
| `selector.rs` | 217 | split | grammar parser + `SelectorRegistry` -> `modforge::selector`. UE-specific resolvers (`class:`, `first_class:`, `singleton:`) stay in ueforge; unityforge registers its own |
| `server.rs` | 213 | `modforge::server` | tiny_http wrapper |
| `settings.rs` | 290 | `modforge::settings` | JSON + debounce |
| `shutdown.rs` | 162 | `modforge::shutdown` | registry pattern + ordering |
| `snapshots/` | 0 | `modforge::snapshots` | ProjectionSnapshot generics live here once written |
| `tweak.rs` | 696 | **ueforge** | UE CDO tweak primitives |
| `uasset.rs` | 332 | **ueforge** | UE pak / utoc parser |
| `ue/` | 4034 | **ueforge** | UObject SDK |
| `ui.rs` + `ui_*.rs` | ~1500 | partial | declarative tab API -> `modforge::ui`. UE ImGui rendering stays in ueforge; unityforge renders into Unity IMGUI or its own bundled imgui |
| `winproc.rs` | 880 | `modforge::winproc` | Win32 process probes |
| `bin/ueforge-deploy.rs` | ~250 | `modforge/deploy` | one deploy tool, Rust binary |
| `bin/dump-strings.rs` + `read-property.rs` | ~400 | **ueforge** | uasset-specific |
| `build.rs` | 183 | **ueforge** | C++ shim build glue |
| `worker.rs` | small | partial | shape -> modforge; UE worker stays in ueforge, unityforge has its own |

Totals: ~12k Rust lines move into `modforge`. ueforge keeps
~10-12k UE-specific lines plus its C++ shim. unityforge
writes ~5-7k Rust lines for Unity bindings plus a ~1k-line
C# shim.

What stays per-framework (engine-specific, never duplicated
across modforge):

- Engine SDK (UObject vs Mono reflection).
- Hooks (vtable + PE vs HarmonyLib).
- Main-thread dispatch (PE queue vs Unity Update tick).
- Engine-touching Effect implementations.
- Asset format parsers (uasset vs Unity asset bundles).
- Mod entry shim (UE4SS C++ vs BepInEx C#).

What this gives us:

- **Conformance is testable.** Both frameworks pass the same
  test corpus over HTTP. Behavior parity is enforced, not
  hoped for.
- **One external client.** Any tool, dashboard, or agent that
  speaks the op envelope talks to either engine.
- **One deploy tool.** One CLI to ship either kind of mod.
- **Shared methodology.** The "snapshot + ops + selectors +
  Def/Registry" doctrine is one document, not two divergent
  copies.

## 3. What unityforge owns (the Unity-side framework)

unityforge is a Rust cdylib + a small C# shim. The cdylib
holds everything; the shim bootstraps it inside BepInEx and
bridges Mono reflection + HarmonyLib via function pointers.

### 3.1 The C# shim (`unityforge-shim`)

A single small C# project. `netstandard2.1`. Built once,
shipped beside every unityforge-based mod.

**Responsibilities (all of them small):**

- `[BepInPlugin]` entry. Locates `unityforge.dll` (the Rust
  cdylib) and `LoadLibrary`s it. Calls
  `unityforge_init(bridge)` with a function-pointer bridge
  table.
- The bridge table: ~30-50 `IntPtr` slots pointing at static
  C# methods that Rust can call back through. Covers:
  - Mono reflection: `find_type(name)`, `get_singleton(name)`,
    `get_field`, `set_field`, `invoke_method`, `walk_class`,
    `inspect_object` (dump fields by reflection),
    `box`/`unbox` for value types.
  - Harmony patching: `patch_prefix(class, method, fn_ptr)`,
    `patch_postfix(...)`, `unpatch(handle)`. The C# side
    wraps unmanaged function pointers in managed delegates
    via `Marshal.GetDelegateForFunctionPointer` so Harmony
    can target them.
  - Unity tick: `register_update(fn_ptr)`. Called once at
    init; the shim's MonoBehaviour's `Update` invokes the
    function pointer every frame.
  - Logger sink: forwards `MelonLogger`-style level + message
    pairs to BepInEx's `ManualLogSource`.
- `Update()` in the shim calls `unityforge_tick(now)`.
- `OnDestroy()` calls `unityforge_shutdown()`.

That's it. **The shim does not know what unityforge does.**
It exposes a fixed set of Mono+Harmony primitives. Adding
features to unityforge does not modify the shim.

Sizing: estimate 500-1000 lines of C#. Once correct, frozen.

### 3.2 The Rust unityforge crate

Mirrors ueforge module-for-module. Both are Rust; the trait
implementations are different but the trait *definitions*
come from modforge so they're identical.

| Module (modforge trait) | ueforge impl | unityforge impl |
|---|---|---|
| `modforge::server` | direct use | direct use |
| `modforge::ops::OpRegistry` | direct use | direct use |
| `modforge::selector::SelectorRegistry` | direct use; registers `class:`/`first_class:`/`singleton:` resolvers against UObject | direct use; registers `class:`/`first_class:`/`singleton:`/`static_instance:`/`monobehaviour:` resolvers against Mono via the shim bridge |
| `modforge::rpg::SkillRegistry` | direct use | direct use |
| `modforge::rpg::tracker::Tracker` | direct use; instantiated with ueforge's Effect impls | direct use; instantiated with unityforge's Effect impls |
| Mod entry | `ueforge::ModDef` + `ue4ss_mod!` macro + C++ shim | `unityforge::ModDef` + `unityforge_mod!` macro + C# shim |
| Engine SDK | `ueforge::ue::*` (UObject, UClass, FName, TArray, FString) | `unityforge::mono::*` (MonoType, MonoObject, MonoField, MonoMethod). Wraps the shim bridge in idiomatic Rust |
| Hooks | `ueforge::hook::ProcessEventHook` (vtable + PE trampoline) | `unityforge::hook::HarmonyHook` (calls `patch_prefix` / `patch_postfix` via the shim) |
| Main-thread queue | `ueforge::PE_QUEUE` | `unityforge::MAIN_QUEUE` (drained by the shim's `Update` tick) |
| Generic primitives | `read_bytes`, `walk_class`, `inspect_address`, `exec_call`, `fname_to_string` | `walk_class`, `inspect_object`, `read_field`, `write_field`, `invoke_method`, `list_singletons` (Unity names; same op-envelope contract) |
| Standard Effects (engine-touching) | `PlayerFloatEffect` (reads UObject CDO) | `MonoFloatEffect` (reads via shim bridge) |
| Stacks / data-asset tweaks | `StackDef` against UDataTable | `StackDef` against ScriptableObject |
| In-game UI | bundled imgui via C++ shim | bundled imgui via the same Rust ImGui bindings + a Unity IMGUI fallback (revisit) |
| Webhooks | new in modforge; added to both | new in modforge; added to both |
| Agent launcher | new in modforge; added to both | new in modforge; added to both |
| Hot reload | `ueforge::hot_reload::finalize_swap` (cdylib swap on the UE4SS side) | `unityforge::hot_reload::finalize_swap` (cdylib swap; the shim trampolines the new entry points) |

The crate is `unityforge`, exposes `ModDef` + a
`unityforge_mod!` macro that emits the `extern "C"` entry
points the shim invokes (`unityforge_init`, `unityforge_tick`,
`unityforge_shutdown`). Game mods write:

```rust
static MOD_INFO: unityforge::ModDef = unityforge::ModDef {
    name: "WildWestRpg",
    ...
};

unityforge::unityforge_mod!(MOD_INFO);
```

and that's their entire entry-point surface. Same shape as
ueforge.

## 4. The naming + architectural mandates (shared)

These come from `ueforge/docs/architecture.md` and apply to
both frameworks verbatim:

- **Def -> Registry -> Instance -> Controller** for every
  subject. Skills, effects, triggers, hooks, ops, selectors,
  shutdown handlers, data tables, status effects, tabs,
  stacks, difficulty, buildings.
- **Effects + Triggers + Skills** composition. Same vocabulary
  on both sides.
- "Always change the framework first." If you wrote it twice,
  it belongs in the framework. If you wrote it three times,
  it belongs in modforge.
- **The op-envelope rule:** every response carries the full
  state snapshot. Tests assert against the snapshot, not the
  per-op result.
- **toon vs json:** every list/value endpoint supports both
  formats.
- Naming: `<Subject>Def`, `<Subject>Registry`, `<Subject>Tracker`,
  controllers are bare functions.

## 5. Workspace layout

```
grounded2mods/
  Cargo.toml                      # workspace root
  modforge/                       # Rust crate (new)
    Cargo.toml                    # [lib] crate-type = ["rlib"]
    src/
      lib.rs
      envelope/
      ops/
      selector/
      settings/
      counters/
      ring/
      scanner/
      winproc/
      server/
      shutdown/
      log/
      hot_reload/
      args/
      debug/
      snapshots/
      ui/                         # declarative tab API (rendering per-framework)
      rpg/
        effect.rs
        trigger.rs
        skill.rs
        tracker.rs
        xp.rs
        progress.rs
        format.rs
        state.rs
        store.rs
        disabled.rs
        catalog.rs
        std_effect_pure.rs
        slot_key.rs                # trait + generic poller
        vanilla.rs                 # generic cache
        ops.rs
        tab.rs
    spec/                         # schemas + ABNF + reference docs
    test-corpus/                  # shared HTTP request/response pairs
    client/                       # Rust HTTP client (the Api<S> test client)
    deploy/                       # modforge-deploy CLI
    docs/
  ueforge/                        # exists today
    Cargo.toml                    # adds modforge = { path = "../modforge" }
    src/
      ue/                         # UObject SDK
      hook/                       # vtable + PE
      pe_queue.rs
      parms.rs
      tweak.rs
      data_table.rs
      damage/
      fall.rs
      inventory/
      discovery.rs
      dynamic_tweaks.rs
      uasset.rs
      mod_main.rs
      worker.rs
      ui.rs                       # ImGui bindings (UE-side)
      ui_*.rs                     # browser tabs (UE-specific)
      rpg/
        health.rs                 # UE health Effect impl
        status.rs                 # UE status Effect impl
        std_effect.rs             # engine-touching standard effects
      bin/
        dump-strings.rs
        read-property.rs
    cpp/                          # CppUserModBase shim
    docs/
  unityforge/                     # new Rust crate + tiny C# shim
    Cargo.toml                    # [lib] crate-type = ["cdylib", "rlib"]
    src/
      lib.rs
      mod_main.rs                 # unityforge_mod! macro + extern "C" entry points
      mono/                       # Mono reflection (calls into shim bridge table)
        mod.rs
        types.rs                  # MonoType + MonoObject + MonoField wrappers
        singleton.rs              # Singleton<T> / StaticInstance<T> access
      hook/                       # HarmonyLib bridge wrapper + HookRegistry
      main_thread_queue.rs        # parallel to ueforge::pe_queue
      ops/                        # Unity-specific generic primitives
      selector/                   # Unity-side resolvers
      rpg/
        std_effect.rs             # engine-touching standard effects for Mono
        slot_key_mono.rs          # Mono ISlotKeyResolver impl
        vanilla_mono.rs           # cache for MonoField handles
      stacks/                     # ScriptableObject field tweak
      ui.rs                       # ImGui-via-shim or Unity IMGUI
      bridge.rs                   # the shim function-pointer table (Rust side)
    cs-shim/
      Unityforge.Shim.csproj      # netstandard2.1
      Unityforge.Shim.cs          # [BepInPlugin] entry
      MonoBridge.cs               # reflection helpers exposed to Rust
      HarmonyBridge.cs            # patch handle registry
    docs/
      README.md
      architecture.md
      shim.md                     # the C# seam + bridge table
      mono.md                     # Mono reflection model
      hooks.md
      rpg.md
      lifecycle.md
    tests/
  grounded2-rpg/                  # exists; depends on ueforge + modforge
  outworld-station-tweaks/        # exists; depends on ueforge + modforge
  wwm-rpg/                        # NEW Rust mod; depends on unityforge + modforge
```

## 6. Sequencing: HTTP debug server + RPG, in parallel

**Two top-priority subsystems, not one.**

1. **HTTP debug control plane.** The single most important
   research / testing / inspection surface either framework
   exposes. Tests drive the live game from outside. Research
   questions become test files. Without it, modders are blind.
   ueforge's `docs/http.md` calls it the most important thing
   the framework ships, and that goes double during unityforge
   bring-up: we'll be reverse-engineering Wild West Miner from
   the HTTP endpoint.
2. **RPG.** The densest module in ueforge and the
   highest-leverage proof of the framework. Forces every
   architectural mandate (Def/Registry, Effects + Triggers +
   Skills, hooks, persistence, op envelope) into coherent
   shape on the Unity side.

Both go in Phase 0 + Phase 1. RPG-the-mod is Phase 3 and
depends on both. Nothing else gets built in this pass.

### Dependency graph

```
              modforge Rust crate extraction
       (envelope + ops + selector + settings +
        counters + ring + scanner + winproc +
        server + shutdown + log + rpg traits +
        rpg pure-logic + rpg std_effect_pure)
                          |
              ueforge migrates to depend on modforge
                          |
            -------------------------------
            |                             |
            v                             v
        ueforge stable             unityforge: C# shim +
       (working as before)         Rust crate skeleton +
                                   Mono bridge + HarmonyLib bridge
                                          |
                          --------------------------------
                          |                              |
                          v                              v
              unityforge HTTP control plane    unityforge.Hooks
              (full ueforge parity:            (Harmony via shim,
               OpRegistry, selectors,           HookRegistry mirrors
               generic primitives,              ueforge surface)
               reflection inspector)
                          |                              |
                          ---------------------------------
                                          |
                                          v
                                 unityforge::rpg
                            (instantiates modforge::rpg
                             with Mono-side Effect impls)
                                          |
                                          v
                                 wwm-rpg Rust cdylib (proof)
```

Other framework concerns wait until something concrete demands
them: snapshots framework, webhooks, agent, in-game UI,
stacks, difficulty, ScriptableObject browser, hot reload.

### Phases

#### Phase 0: modforge extraction (~4-5 days)

Lift ~12k Rust lines out of ueforge into a new `modforge`
crate. ueforge replaces each moved file with `pub use
modforge::<mod>::*;` so existing call sites compile and tests
stay green at every commit. No FFI work, no C ABI, no
cbindgen. Just a Cargo workspace rearrange.

**0a. Specs and docs (~1 day)**

- `modforge/` Cargo crate with `[lib] crate-type = ["rlib"]`.
- `modforge` Cargo workspace member entry in
  `grounded2mods/Cargo.toml`.
- `spec/op-envelope.json`. JSON schema for the envelope.
- `spec/selector-grammar.md`. ABNF.
- `spec/op-registry.md` + `spec/generic-primitives.md`.
  Stable op-name surface both frameworks ship.
- `spec/skill-catalog.json` + `spec/rpg-persistence.json` +
  `spec/xp-curve.md` + `spec/effect-kinds.md` +
  `spec/trigger-kinds.md`.
- `docs/methodology.md` (elevated RESEARCH.md),
  `docs/composition-model.md`, `docs/def-registry.md`,
  `docs/naming.md`.

**0b. Migration (~2-3 days)**

Move files in this order. After each step run `cargo test
--workspace`; commit when green; move on. ueforge re-exports
via `pub use modforge::<mod>::*;` so consumers don't see the
change.

| # | What moves | From | To |
|---|---|---|---|
| 1 | `ring` | `ueforge/src/ring.rs` | `modforge/src/ring/` |
| 2 | `counters` | `ueforge/src/counters.rs` | `modforge/src/counters/` |
| 3 | `log` | `ueforge/src/log.rs` | `modforge/src/log/` |
| 4 | `args` | `ueforge/src/args.rs` | `modforge/src/args/` |
| 5 | `envelope` | `ueforge/src/envelope.rs` | `modforge/src/envelope/` |
| 6 | `settings` | `ueforge/src/settings.rs` | `modforge/src/settings/` |
| 7 | `shutdown` | `ueforge/src/shutdown.rs` | `modforge/src/shutdown/` |
| 8 | `selector` (grammar) | `ueforge/src/selector.rs` (grammar half) | `modforge/src/selector/` |
| 9 | `ops` (registry) | `ueforge/src/ops.rs` (registry half) | `modforge/src/ops/` |
| 10 | `server` | `ueforge/src/server.rs` | `modforge/src/server/` |
| 11 | `scanner` | `ueforge/src/scanner.rs` | `modforge/src/scanner/` |
| 12 | `winproc` | `ueforge/src/winproc.rs` | `modforge/src/winproc/` |
| 13 | `hot_reload` (protocol) | `ueforge/src/hot_reload.rs` | `modforge/src/hot_reload/` |
| 14 | `rpg` (effect/trigger/skill traits) | `ueforge/src/rpg/{effect,trigger,skill}.rs` | `modforge/src/rpg/` |
| 15 | `rpg` (tracker + pure math) | `ueforge/src/rpg/{tracker,xp,progress,format,state,store,disabled,poller,catalog}.rs` | `modforge/src/rpg/` |
| 16 | `rpg` (generic std_effect) | `ueforge/src/rpg/std_effect.rs` (the formatting-only effects) | `modforge/src/rpg/std_effect_pure.rs` |
| 17 | `client` | `ueforge/src/client/` | `modforge/client/` |
| 18 | `bin/ueforge-deploy` | `ueforge/src/bin/ueforge_deploy.rs` | `modforge/deploy/` |
| 19 | `debug` glue | `ueforge/src/debug/` | `modforge/src/debug/` |
| 20 | `snapshots` generics | `ueforge/src/snapshots/` | `modforge/src/snapshots/` |
| 21 | `ui` declarative shape | `ueforge/src/ui.rs` (the API; rendering stays) | `modforge/src/ui/` |
| 22 | `worker` shape | `ueforge/src/worker.rs` (the trait; UE impl stays) | `modforge/src/worker/` |

The split-rows (selector grammar vs UE resolvers, ops
registry vs UE primitives, rpg pure vs UE Effect impls,
worker trait vs UE worker) each take a careful split commit.
Mechanical otherwise.

**0c. Test corpus (~1 day)**

- `modforge/test-corpus/ops/`. One JSON per primitive op.
- `modforge/test-corpus/rpg/`. Level-up, refund, etc.
- `modforge/test-corpus/selector/`. Each selector form.
- ueforge's existing tests load the corpus; both frameworks
  will eventually run identical assertions.

**Exit gate:**

- `cargo build --workspace` green.
- `cargo test --workspace` green.
- ueforge in-game: g2rpg ImGui tab still renders, HTTP debug
  still answers. Zero behavior change.

#### Phase 1: unityforge skeleton + C# shim + HTTP control plane (~6-8 days)

The biggest phase. Stand up the C# shim seam, prove a Rust
cdylib loads in BepInEx and can call into Mono + Harmony,
expose the full HTTP debug surface. Once Phase 1 exits we
can research any Unity Mono game by curl.

**1a. Cargo crate + workspace wiring (~half day)**

- `unityforge/Cargo.toml` with
  `[lib] crate-type = ["cdylib", "rlib"]`.
- `unityforge = { path = "../unityforge" }` available to
  game-mod crates.
- `unityforge::ModDef` + `unityforge_mod!` macro. Emits
  the `extern "C"` entry points (`unityforge_init`,
  `unityforge_tick`, `unityforge_shutdown`).

**1b. C# shim project (~2 days)**

- `unityforge/cs-shim/Unityforge.Shim.csproj`
  (netstandard2.1). References:
  `BepInEx`, `HarmonyLib` (0Harmony.dll), Unity
  `UnityEngine.CoreModule.dll`. No game-DLL refs.
- `Unityforge.Shim.cs`: `[BepInPlugin]` entry. Locates
  `unityforge.dll` next to itself, `LoadLibrary`s it,
  `GetProcAddress` for the three Rust entry points,
  calls `unityforge_init(bridge_table_ptr)`.
- `Bridge.cs`: a `[StructLayout(LayoutKind.Sequential)]`
  struct of function pointers. Static methods on
  `MonoBridge` and `HarmonyBridge` are exposed via
  `Marshal.GetFunctionPointerForDelegate` into the bridge
  struct.
- `MonoBridge.cs`: static methods for `find_type(utf8_name)`,
  `find_singleton_instance(name)`, `get_field(handle,
  field_name)`, `set_field(handle, field_name, value)`,
  `invoke_method(handle, method_name, args_json) ->
  result_json`, `walk_class(type_handle)`, `dump_object
  (object_handle) -> json`. Each method translates Rust
  callsites to managed reflection.
- `HarmonyBridge.cs`: static methods `patch_prefix(class,
  method, native_fn_ptr) -> handle`, `patch_postfix(...)`,
  `unpatch(handle)`. Wraps unmanaged function pointers in
  managed delegates via
  `Marshal.GetDelegateForFunctionPointer` so HarmonyLib can
  target them. Tracks handles in a `Dictionary<int,
  HarmonyMethod>`.
- `Update()` on the shim's MonoBehaviour calls
  `unityforge_tick(Time.realtimeSinceStartup)`.
- `OnDestroy()` calls `unityforge_shutdown()`.

Estimate: ~600-900 lines of C#. Once correct, frozen.

**1c. Rust Mono bridge wrapper (~1 day)**

- `unityforge::bridge`. A `BridgeTable` struct mirroring the
  C# struct, populated at `unityforge_init`. Stored in a
  `OnceLock<BridgeTable>`.
- `unityforge::mono::{MonoType, MonoObject, MonoField,
  MonoMethod}`. Idiomatic Rust types wrapping opaque
  handles. Method calls go through the bridge table.
  Drop impls release handles back to the shim.
- Safety: handles are 32-bit cookies (not pointers) so a
  stale handle dispatched after game-state change returns an
  error instead of UB. The shim owns the
  `Dictionary<int, object>` and `GCHandle`s where needed.

**1d. HTTP control plane (~1.5 days)**

Pure reuse of `modforge::server` + `modforge::ops` +
`modforge::selector`. The unityforge work is just
registering the Unity-side ops and selector resolvers:

- `unityforge::ops`. Register Unity primitives against the
  shared `OpRegistry`:
  - `walk_class` (calls `MonoBridge.walk_class`).
  - `inspect_object` (calls `MonoBridge.dump_object`).
  - `read_field`, `write_field`.
  - `invoke_method`.
  - `list_singletons` (Unity-pattern probe).
- `unityforge::selector`. Register resolvers for `class:`,
  `first_class:`, `singleton:`, `static_instance:`,
  `monobehaviour:`. Each one looks up the live object via
  the Mono bridge.
- `unityforge::main_thread_queue`. Parallel to
  `ueforge::pe_queue`. Lock-free fast path, re-entrance
  guard, budgeted drain on every tick.

**1e. Hook bridge (~1 day)**

- `unityforge::hook::HarmonyHook`. Wraps the shim's
  `patch_prefix` / `patch_postfix` entries. Rust callbacks
  are `extern "C" fn(...)` pointers passed to the shim.
- `unityforge::hook::HookRegistry`. Same surface as
  `ueforge::hook::HookRegistry`: `register`,
  `shutdown_all`, per-hook panic counter.
- The trampoline catches panics in user prefix/postfix
  bodies so one bad hook doesn't crash the shim.

**1f. Tests + WWM smoke (~1-1.5 days)**

- Rust unit tests for the bridge wrappers (mock bridge
  table).
- Integration: load the modforge `test-corpus/ops/` corpus,
  run against a stub bridge, assert envelope parity.
- End-to-end: build `unityforge.dll` + shim, drop into
  WWM's BepInEx plugins dir, launch the game, `curl POST
  localhost:<port>/op {"op":"ping"}` -> envelope.
- `walk_class PlayerManager` -> live instance handle.
- `inspect_object <handle>` -> PlayerData fields.
- `invoke_method PlayerManager AddPlayerCurrency [1e6]`
  -> player balance jumps in-game.

**Exit gate:**

- Hello-plugin Rust cdylib loads inside WWM via the shim.
- Full generic-primitive op surface answers curl.
- Conformance corpus passes against unityforge.

#### Phase 2: unityforge::rpg (~3-4 days)

Most of RPG already moved into modforge in Phase 0. The
`Effect` and `Trigger` traits, the `SkillDef`, the
`Tracker`, XP curve, persistence, catalog parser, slot
poller, OpRegistry handlers, all live in
`modforge::rpg::*`. Both frameworks use them natively.

Phase 2 is the engine-binding half:

| What | Where | Notes |
|---|---|---|
| `unityforge::rpg::slot_key_mono` | unityforge | Implements `modforge::rpg::SlotKeyResolver` for Mono. Reads a configurable singleton + field via the bridge. Game crates configure with `(singleton_name, field_name)` |
| `unityforge::rpg::vanilla_mono` | unityforge | Per-class vanilla-value cache; key type is `MonoField` handle |
| `unityforge::rpg::std_effect` | unityforge | Mono-specific Effect implementations: `MonoFloatFieldEffect`, `MonoFieldMultiplyEffect`, `MonoFieldAdditiveEffect`, `MonoMethodInvokeEffect`. Each implements `modforge::rpg::Effect`. Uses the bridge to read/write fields and invoke methods |
| `unityforge::rpg::trigger_harmony` | unityforge | `OnHarmonyPatch` trigger: the framework patches a target method via the Harmony bridge and fires the trigger on pre/post. Also a thin `OnMonoEvent` trigger for games like WWM that already expose `static event Action` |
| `unityforge::rpg::ops_register` | unityforge | Wires `modforge::rpg::ops` handlers into the unityforge `OpRegistry` |

That's it. The Tracker is shared. The catalog parser is
shared. The XP math is shared. unityforge contributes only
the parts that *touch Mono*.

Phase 2 deliverable: a `unityforge.dll` whose RPG surface
matches ueforge's, byte-for-byte on the conformance corpus
where the game-specific config is held constant.

Tests (mostly inherited from modforge):
- Catalog parse / state round-trip / XP curve. Already passing
  in modforge.
- Mono-specific Effect impls tested against a stub bridge.
- Conformance: load `modforge/test-corpus/rpg/` against a
  unityforge process running a stub catalog; envelope parity
  with ueforge.

**Exit gate:** unityforge's `list_ops` includes the RPG ops;
the conformance corpus passes; a stub catalog can be
loaded + leveled + saved + reloaded via curl.

#### Phase 3: wwm-rpg (the Wild West Miner RPG mod, ~5-7 days)

The proof. A Rust cdylib crate built on unityforge that
ships skills to the player. The C# shim is the same one
unityforge already provides; the only WWM-specific C# is a
trivial `[BepInPlugin]` that loads `wwm-rpg.dll` instead of
the framework's hello plugin.

- New Rust crate: `grounded2mods/wwm-rpg/Cargo.toml` with
  `crate-type = ["cdylib"]`. Depends on
  `unityforge = { path = "../unityforge" }`.
- `static MOD_INFO: unityforge::ModDef = ...;`
  `unityforge::unityforge_mod!(MOD_INFO);` and that's the
  whole entry surface.
- Configures the Mono slot-key resolver:
  `MonoSlotKey::new("GameSerializationSystem",
  "_currentLoadedSaveNumber")`.
- Hook wiring (Rust, calls the Harmony bridge through
  unityforge):
  - Patch `DigManager.OnDig` (static event subscription).
    XP source per swing.
  - Patch `PlayerManager.e_OnPlayerCurrencyChanged` (static
    event subscription). XP source per sale.
  - Patch `Worker.HireMethod` (Harmony prefix). For
    "Charisma" skill discount.
  - Patch `Mine.MineData` accessor or the ore-drop call
    site. For "Lucky" skill.
- Catalog: 5-8 skills declared as `static
  SkillDef`s referencing `unityforge::rpg::std_effect`
  implementations (`MonoFieldMultiplyEffect`,
  `MonoFieldAdditiveEffect`):
  - **Greedy Miner**: MonoFieldMultiply on a
    `MineDataSO.OreValue`.
  - **Strong Back**: MonoFieldAdditive on
    `PlayerCarryingController.MaxCapacity`.
  - **Quick Pickaxe**: MonoFieldMultiply on
    `DigManager._digRange`.
  - **Lucky**: probability-scaler Effect.
  - **Charisma**: MonoFieldMultiply on hire cost.
  - **Resilient**: MonoFieldMultiply on stamina drain.
- XP curve: ueforge defaults (`base=100`, `exponent=1.8`,
  `max_level=50`).
- UI: ImGui tab declared via
  `unityforge::ui::Tab { name: "RPG", render: ... }` (the
  imgui-via-shim path; if blocked, fall back to a tiny
  OnGUI overlay declared declaratively through the same
  Tab API).
- Save/load: a sibling JSON under
  `<ModDataDir>/<slot>.json`, written by
  `modforge::rpg::store`. Cleaner than piggybacking on
  `GameSerializationData`.

**Exit gate:** load the game, dig some ore, see XP accrue,
level up Strong Back, observe inventory cap visibly
increase, save + reload, observe state persisted. Quit and
relaunch, state still there.
`curl POST /op {"op":"skill_state"}` returns the same
numbers. Same op set as ueforge's grounded2-rpg.

#### What's deferred (and why)

| Module | Why later |
|---|---|
| Snapshots framework (ProjectionSnapshot generics) | The shape lives in `modforge::snapshots` after Phase 0, but per-frame projection types are added when a consumer needs them |
| Webhooks | Add when a consumer asks for push events |
| Agent launcher | Port from Timberbot's `TimberbotAgent` into `modforge::agent` when LLM-driven play matters |
| Stacks / Difficulty / SO browser | No consumer demanding them yet; unityforge writes its own when one appears |
| Hot reload of the Rust cdylib through the shim | Defer until Phase 1 / 2 are stable. Both ueforge and Timberbot shipped value before hot reload mattered |
| Conformance test for non-RPG ops | The corpus covers it; ueforge/unityforge will close any drift as we hit it |
| IL2CPP support | Mono-only through wwm-rpg. Il2CppInterop bridge is v2 |
| Bundled imgui inside Unity process | Spike during Phase 1; if hard, fall back to Unity IMGUI for v1 |

**Total Phase 0-3: ~18-24 days.** Roughly 3-4 weeks. End
state: modforge owns ~12k engine-agnostic Rust lines that
both frameworks depend on. ueforge stays working through the
migration. unityforge ships as a Rust cdylib + a ~1k-line C#
shim. Wild West Miner has a Rust-native RPG mod that proves
the framework. Future Unity-Mono game = new Rust cdylib +
the same shim, days not months.

## 7. Open design questions

1. **IL2CPP scope in v1?** Both Timberborn and Wild West Miner
   are Mono. Schedule 1 is IL2CPP. unityforge v1 is Mono-only;
   IL2CPP via Il2CppInterop is a v2 expansion. The C# shim
   pattern still applies, just with an Il2Cpp-flavored bridge.
2. **In-game UI: imgui via shim, or native Unity IMGUI?**
   ueforge bundles imgui v1.92.1 in its C++ shim. unityforge
   could ship imgui in a native renderer DLL plus a render
   loop hook (cleanest parity) or use Unity IMGUI `OnGUI`
   (simpler, uglier). Spike during Phase 1.
3. **Hot reload of the Rust cdylib through the shim.** The
   shim keeps `LoadLibrary`d handles; the swap protocol
   needs the shim to `FreeLibrary` and re-`LoadLibrary` on a
   trigger, plus an unpatch-all step on Harmony first. Spike
   during Phase 1 or defer.
4. **Timberbot's future.** Timberbot is mature C# code that
   does not need unityforge. Once unityforge exists,
   Timberbot could optionally adopt it (rewrite in Rust) or
   stay as-is. Defer the call. No schedule pressure.
5. **Shim language portability.** The C# shim is BepInEx-
   shaped. If we later want to load unityforge into a
   different host (MelonLoader, a Unity Editor extension),
   we write a sibling shim against that host. The Rust side
   doesn't change.

## 8. Risks

| Risk | Mitigation |
|---|---|
| 3-4 weeks is long; momentum risk for solo work | Per-phase exit criteria. Each phase ships a buildable, tested, observable artifact. Hello-plugin running in WWM is an explicit Phase 1 exit gate; that's playable signal long before Phase 3 |
| Mono reflection through a function-pointer bridge is unfamiliar | Phase 1b spike up front. There's prior art (BepInEx native plugins, MonoMod). If the bridge surface needs expansion, the shim is small and easy to extend |
| Harmony patches calling unmanaged function pointers | `Marshal.GetDelegateForFunctionPointer` + a managed stub delegate handles this. Standard pattern; not bleeding edge |
| ueforge migration regression (the existing UE mods break) | The migration is a series of file moves + `pub use` re-exports. Workspace tests run between each step. If a step breaks tests, it's reverted before moving on |
| Bridge ABI versioning across shim/Rust drift | The bridge table is a versioned struct with a magic number + version field at the head. Mismatches refuse to init with a clear error |
| Hot reload through shim is harder than ueforge's pure-Rust swap | Defer to a later phase. Both Timberbot and ueforge shipped value long before hot reload mattered |
| imgui inside a Unity process via a native renderer is fiddly | Fallback to Unity IMGUI is always available. UI is v0 nice-to-have, not a blocker for skills + curl |
| Symmetric module-for-module mirror produces awkward APIs on one side | The mandates apply to *naming and shape*; the implementation can differ. Mono is more reflection-friendly than UObject; unityforge's Effect impls will be simpler than ueforge's offset-driven ones, and that's fine |

## 9. Acceptance gates

The plan is "done" when:

- `cargo build --workspace` builds all four crates (modforge,
  ueforge, unityforge, modforge-deploy).
- `cargo test --workspace` passes.
- ueforge's existing game mods (`grounded2-rpg`,
  `outworld-station-tweaks`) still work in-game,
  byte-for-byte identical to pre-extraction.
- `unityforge.dll` + `Unityforge.Shim.dll` load into Wild
  West Miner via BepInEx. `curl` to the debug port returns
  the full generic-primitive op surface.
- `wwm-rpg` Rust cdylib loads via the same shim, ships a
  catalog of 5-8 skills, and gameplay shows skill effects
  applied + persisted across save/load.
- `modforge/test-corpus/` passes against both ueforge and
  unityforge.
- The methodology doc + composition-model doc + def-registry
  doc are the single source of truth for both frameworks.
- A new Unity-Mono game can be picked up as a Rust cdylib
  consuming unityforge in days, not weeks. (Verified by the
  next consumer when one appears.)
