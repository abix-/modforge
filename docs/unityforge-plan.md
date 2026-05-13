# unityforge + modforge: plan

> **Status:** plan, 2026-05-12. Sibling to
> [`wild-west-miner-research.md`](wild-west-miner-research.md).
>
> Supersedes the earlier draft of this doc that scoped
> unityforge as a Timberbot extraction with Goldbot as the
> first consumer. That framing was wrong. unityforge is the
> **Unity Mono equivalent of ueforge**. A full framework, not
> a thin scaffolding layer. And the shared concepts between
> the two go into a **common `modforge` workspace** that both
> frameworks build on. No game mod is on the critical path.

## 1. The shape, restated

Three things to build, in this order:

1. **modforge.** A common workspace owning everything that is
   engine-independent: the op envelope, selector grammar,
   toon format, skill / effect / trigger schema, settings file
   format, webhook payload schema, hot-reload protocol, the
   external HTTP client, the deploy tool, the test corpus,
   the methodology doc.
2. **ueforge** (already exists). The UE5 / UE4SS / Rust
   framework. Adopts modforge's specs and shared tooling.
3. **unityforge** (new). The Unity Mono / BepInEx / C#
   framework. Implements the same modules ueforge does:
   hooks, registry-pattern subjects, skills, effects, triggers,
   snapshots, ops, agent, in-game UI, hot reload. Adopts
   modforge.

Game mods (`grounded2-rpg`, `outworld-station-tweaks`, a
future Wild West Miner mod) are downstream consumers, not
inputs to this plan.

## 2. What goes in modforge

**No duplication.** If a subsystem is engine-agnostic, it lives
in modforge once and both frameworks consume it. ueforge moves
those files out of its own tree (or re-exports from modforge);
unityforge consumes via FFI. Audit below.

modforge owns three tiers of shared asset. Tiers 1-2 are free
to share. Tier 3 is real binary code, lifted from ueforge into
a Rust crate that ueforge depends on natively and unityforge
consumes via FFI:

**Tier 1: specs and docs (read at design time)**

| Asset | Form |
|---|---|
| Op envelope spec | JSON schema + markdown |
| Toon format spec | Markdown + reference encoder pseudocode |
| Selector grammar | Markdown + ABNF/regex |
| Skill catalog schema | JSON schema |
| Settings file schema | JSON schema |
| Webhook payload schema | JSON schema |
| Hot-reload protocol | Markdown spec |
| Methodology doc | `methodology.md`. The RESEARCH.md content elevated |
| Skill-file (LLM agent) template | Markdown template |
| LLM prompt templates | `*.md` per agent role |

**Tier 2: shared external tooling**

| Asset | Form |
|---|---|
| Test corpus | JSON files: `request, expected response`. Both frameworks load it in tests and assert byte-for-byte parity |
| External HTTP client | One implementation (Python today, lifted from `timberbot/script/timberbot.py` + ueforge's client; merged) |
| Deploy tool | `modforge-deploy` (Rust binary lifted from `ueforge/src/bin/ueforge_deploy.rs`) reading per-crate `[package.metadata.modforge]` for Rust or an MSBuild target for C# |

**Tier 3: `modforge/core/` Rust crate (consumed natively by
ueforge, via P/Invoke by unityforge)**

One crate, multiple submodules. `crate-type = ["cdylib", "rlib"]`.
C ABI via `extern "C"` + `cbindgen`-emitted header for the
C# side.

```
modforge/core/src/
  lib.rs
  envelope/    # OpResponse + parse_request + envelope shape
  ops/         # OpDef + OpRegistry + dispatch
  selector/    # grammar parser (the grammar; engine resolvers stay per-framework)
  settings/    # JSON file + debounced save
  counters/    # AtomicU64 counter + TimeScope
  ring/        # bounded ring buffer
  scanner/     # process memory scanner mechanics
  winproc/     # Win32 process probes (threads, modules, regions, memory)
  server/      # tiny_http listener wrapper
  shutdown/    # registry pattern for shutdown handlers
  log/         # file + stdout sink, level enum, format
  hot_reload/  # protocol types
  rpg/         # xp, progress, format, state, store, disabled, catalog (the pure RPG)
  ffi.rs       # C ABI surface for unityforge
headers/
  modforge_core.h
```

### Module audit (where each ueforge subsystem goes)

| ueforge today | Lines | Destination | Notes |
|---|---|---|---|
| `args.rs` | small | `modforge/core/args` | JSON arg helpers, pure |
| `client/` | 1751 | `modforge/client` | HTTP test client. Engine-agnostic. Lifted whole |
| `counters.rs` | small | `modforge/core/counters` | AtomicU64 + TimeScope |
| `damage/` | 360 | **ueforge** | UE damage hook (unityforge has its own equivalent module later) |
| `data_table.rs` | 1410 | **ueforge** | UDataTable (unityforge: ScriptableObject browser, separate module) |
| `debug/` | 264 | partial | shape -> modforge spec; UE handlers stay |
| `discovery.rs` | 421 | **ueforge** | UE GObjects walker |
| `dynamic_tweaks.rs` | 247 | **ueforge** | UE CDO writes |
| `envelope.rs` | small | `modforge/core/envelope` | OpResponse + parse_request |
| `fall.rs` | 215 | **ueforge** | UE fall hook |
| `hook/` | 1102 | **ueforge** | UE vtable + PE (unityforge: Harmony wrapper, separate) |
| `hot_reload.rs` | small | partial | protocol types -> `modforge/core/hot_reload`; the cdylib swap impl stays in ueforge |
| `inventory/` | 560 | **ueforge** | UE inventory hooks |
| `log.rs` | 214 | `modforge/core/log` | sink + level enum + format |
| `mod_main.rs` | 329 | **ueforge** | CppUserModBase + UE4SS entry |
| `ops.rs` | 866 | partial split | `OpDef` + `OpRegistry` + dispatch shape -> `modforge/core/ops`. The specific UE primitives (`read_bytes`, `walk_class`, `inspect_address`, `fname_to_string`, `exec_call`) stay in ueforge. unityforge ships C# equivalents with the same op-name surface (different impl: C# reflection vs FProperty walk) |
| `parms.rs` | small | **ueforge** | UE UFunction parm marshalling |
| `pe_queue.rs` | 473 | **ueforge** | UE ProcessEvent queue (unityforge: MainThreadQueue, separate module) |
| `ring.rs` | 138 | `modforge/core/ring` | bounded ring buffer |
| `rpg/` | 4325 | partial | pure: xp, progress, format, state, store, disabled, catalog -> `modforge/core/rpg`. per-engine: effect, trigger, tracker, vanilla, slot_key, std_effect, ops, tab, health, status |
| `scanner.rs` | 919 | `modforge/core/scanner` | process memory scanning. Engine-agnostic |
| `selector.rs` | 217 | partial | grammar parser -> `modforge/core/selector`. UE-specific resolvers (`class:`, `first_class:`, `singleton:`) stay in ueforge; unityforge registers its own resolvers against the shared parser |
| `server.rs` | 213 | `modforge/core/server` | tiny_http wrapper; small enough to share without controversy |
| `settings.rs` | 290 | `modforge/core/settings` | JSON + debounce |
| `shutdown.rs` | 162 | `modforge/core/shutdown` | registry pattern; handler types stay per-engine |
| `snapshots/` | 0 | partial | snapshot envelope shape -> `modforge/core/snapshot`. Per-frame projection types are generics; per-engine |
| `tweak.rs` | 696 | **ueforge** | UE CDO tweak primitives |
| `uasset.rs` | 332 | **ueforge** | UE pak/utoc parser |
| `ue/` | 4034 | **ueforge** | UObject SDK (unityforge's equivalent module wraps Unity reflection + Singleton<T> access) |
| `ui.rs` + `ui_*.rs` | ~1500 | **ueforge** | UE-specific ImGui bindings + browser tabs. unityforge does its own UI module; the *declarative tab API* may end up in `modforge/core/ui` as a thin shape if the two converge |
| `winproc.rs` | 880 | `modforge/core/winproc` | Win32 process probes; engine-agnostic |
| `bin/ueforge-deploy.rs` | ~250 | `modforge/deploy` | one deploy tool for both kinds of mod |
| `bin/dump-strings.rs` + `read-property.rs` | ~400 | **ueforge** | uasset-specific |
| `build.rs` | 183 | **ueforge** | C++ shim build glue (UE-specific) |
| `worker.rs` | small | **ueforge** | UE-thread worker (unityforge: BepInEx MonoBehaviour Update, separate) |

Totals: ~10k lines move into `modforge/core` over time;
ueforge keeps its UE-specific ~15-18k lines; unityforge writes
~4-6k lines of Unity-specific code that mirrors ueforge's
engine-specific surfaces.

What stays per-framework (categorical, not duplicated):

- Traits and interfaces (`trait Effect` in Rust,
  `interface IEffect` in C#). Trait objects don't cross FFI.
- Standard Effect / Trigger implementations that touch the
  engine.
- Trackers and dispatch loops (call language-specific
  trait/interface methods).
- Hooks, vanilla cache, slot-key resolution, engine SDK
  (UObject vs Unity reflection).

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

unityforge mirrors ueforge module-for-module. The Unity-side
implementations differ; the surface area matches. Adding a
module in one without the other is a bug.

| Module | ueforge (Rust) implementation | unityforge (C#) implementation |
|---|---|---|
| **Mod entry / lifecycle** | `ueforge::ModDef` + `ue4ss_mod!` macro + C++ shim | `UnityforgeMod` base class + BepInEx `[BepInPlugin]` |
| **HTTP control plane** | `server::spawn` + `OpResponse<S>` envelope | `Unityforge.HttpServer` + same envelope |
| **Op envelope** | `parse_request` / `OpResponse` | C# equivalent against the same JSON schema |
| **Op registry** | `OpDef` + `OpRegistry::dispatch` | `OpDef` + `OpRegistry.Dispatch` in C# |
| **Selector grammar** | `selector::resolve` + `SelectorDef` | C# parser against the modforge ABNF |
| **Snapshot pipeline** | `ops::snapshot` (double-buffered) | `ProjectionSnapshot<TDef, TState, TDetail>` + `ValueStore<...>` (already exists in Timberbot, lift) |
| **Hooks** | `ProcessEventHook` (UE5 vtable patch + PE trampoline) | `Hook` wrapping HarmonyLib (`Harmony.Patch`) + a registry that mirrors `HookRegistry`'s surface |
| **PE-queue / main-thread queue** | `PE_QUEUE` (lock-free fast path + re-entrance guard) | `MainThreadQueue` (`ConcurrentQueue<Action>` + budgeted drain on `Update`) |
| **Skills / Effects / Triggers** | `SkillDef`, `EffectDef`, `TriggerDef`, `Tracker` | Direct port. Same Def/Registry/Tracker shape. Effects in C# implement `IEffect`; triggers wrap `Hook` or fire from polled events |
| **Registry pattern (Def -> Registry -> Instance -> Controller)** | Universal. Every subject | Universal. Every subject |
| **Stacks / inventory tweaks** | `stacks::StackDef` + DataTable scan | C# equivalent against ScriptableObjects (Unity's data-asset analog of UE DataTables) |
| **Difficulty / CDO field tweaks** | `difficulty::DifficultyDef` | C# equivalent against `Singleton<T>` singletons |
| **DataTable browser** | `data_table` + `ui_data_table_browser` | ScriptableObject browser (Unity equivalent: walk `Resources.LoadAll<ScriptableObject>` or Addressables catalog) |
| **Reflection inspector** | `winproc` + `discovery` + class browser | C# `System.Reflection` inspector (already exists in Timberbot as `TimberbotDebug`, lift) |
| **Settings** | `Settings<T>` + JSON persistence | `Settings<T>` (C#) + JSON persistence |
| **Hot reload** | `hot_reload::finalize_swap` | BepInEx ScriptEngine-driven swap (TBD; may use Harmony's own unpatch + re-patch + reload-domain) |
| **Logger** | `log::init` + file + console | `Logger` (lift from `TimberbotLog`) |
| **Counters / timing** | `counters` + `counter!` / `peak!` macros | C# `Counters` static with `Counter`, `TimeScope`. Same surface. |
| **Bounded ring buffer** | `ring::Ring<T>` | C# generic `Ring<T>` |
| **Webhooks** | (not in ueforge today; lift to modforge spec + add to ueforge) | `Webhook` (lift from `TimberbotWebhook`) |
| **Agent launcher** | (not in ueforge today; add) | `Agent` (lift from `TimberbotAgent`) |
| **In-game UI** | Bundled imgui v1.92.1 + `ui::*` bindings | Unity IMGUI (`OnGUI`) wrapper with a matching declarative API, or bundled imgui (revisit). Tabs declared the same way. |
| **Entity registry (game-side, generic)** | game-side; selectors handle this | `EntityRegistry<TId>` (lift from Timberbot) |
| **Write-job interface + budget runner** | game-side queues onto PE_QUEUE | `IWriteJob` + budgeted drain (lift from Timberbot) |

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
  modforge/                       # shared spec + tooling (new)
    spec/
      op-envelope.json            # JSON schema
      selector-grammar.md         # ABNF + examples
      toon-format.md              # encoder spec
      skill-catalog.json          # JSON schema for skill data
      settings.json               # JSON schema
      webhook-payload.json        # JSON schema
      hot-reload.md               # protocol spec
    test-corpus/                  # request -> expected response
      ops/
        snapshot.json
        read_bytes.json
        ...
      framework-conformance/
        ...
    client/
      modforge_client/            # Python client (merged from
      ...                         #   timberbot.py + ueforge::client)
    deploy/
      Cargo.toml                  # modforge-deploy (Rust)
      src/main.rs                 # absorbed from ueforge-deploy
    docs/
      methodology.md              # RESEARCH.md elevated
      composition-model.md        # Effects + Triggers + Skills
      def-registry.md             # the CRD pattern, engine-agnostic
      naming.md
    README.md
  ueforge/                        # exists today; adopts modforge
    Cargo.toml
    src/
    cpp/
    docs/
  unityforge/                     # new
    unityforge.csproj             # netstandard2.1
    src/
      Mod/                        # entry + lifecycle
      Ops/
      Selectors/
      Hooks/                      # HarmonyLib wrapper + registry
      Snapshots/
      Rpg/                        # Skills + Effects + Triggers
      Stacks/
      Difficulty/
      DataAssets/                 # ScriptableObject browser
      Settings/
      Webhook/
      Agent/
      Ui/
      Counters/
      Logger/
      Service/                    # per-frame dispatch + host iface
    docs/
      README.md
      architecture.md             # mirrors ueforge/docs/architecture.md
      hooks.md
      rpg.md
      lifecycle.md
    tests/
  grounded2-rpg/                  # exists
  outworld-station-tweaks/        # exists
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
                modforge/core extraction
        (envelope + ops + selector + settings +
         ring + counters + scanner + winproc +
         server + shutdown + log + rpg-core)
                          |
            -------------------------------
            |                             |
            v                             v
        ueforge migration         unityforge skeleton
        (consume modforge)        (BepInEx + IUnityforgeHost)
                                          |
                          --------------------------------
                          |                              |
                          v                              v
              unityforge HTTP control plane     unityforge.Hooks
              (FULL: ops registry, selectors,   (HarmonyLib wrapper)
               snapshot, reflection inspector,
               generic primitives)
                          |                              |
                          ---------------------------------
                                          |
                                          v
                                 unityforge.Rpg
                                          |
                                          v
                                 wwm-rpg (the proof)
```

Other framework concerns wait until something concrete demands
them: snapshots framework, webhooks, agent, in-game UI,
stacks, difficulty, ScriptableObject browser, hot reload.

### Phases

#### Phase 0: modforge extraction (~5-7 days)

Spec assets + the `modforge/core/` Rust crate covering both
the HTTP debug surface AND the RPG pure-logic. ueforge
migrates module-by-module; each migrated submodule ships
green tests before the next moves. unityforge consumes the
whole crate via P/Invoke in Phase 1.

**0a. Specs and docs (~1.5 days)**

- `modforge/` workspace folder + README.
- `spec/op-envelope.json`. JSON schema for `{ op, args }` /
  `{ ok, op, error, result, state }`. Lifted from ueforge.
- `spec/selector-grammar.md`. ABNF for `addr:0x...`,
  `class:Foo`, `first_class:Foo`, `singleton:Bar`. Parser is
  engine-agnostic; resolvers register per-framework.
- `spec/op-registry.md`. The `OpDef` shape, dispatch rules,
  `list_ops` / `list_selectors` auto-generation.
- `spec/generic-primitives.md`. The op-name surface every
  framework ships: `ping`, `snapshot`, `read_bytes`,
  `write_bytes`, `walk_class`, `inspect_address`,
  `exec_call`, `list_ops`, `list_selectors`, `scan_memory`,
  `freeze`, etc. Each op declares stable args+result
  schemas. **Implementations** are per-engine (UE walks
  UObject; Unity walks managed reflection); **op names +
  envelope shapes** are shared.
- `spec/skill-catalog.json`. Schema for `SkillDef`:
  `{ id, display_name, max_level, effect: { kind, params },
  trigger: { kind, params } }`.
- `spec/rpg-persistence.json`. Per-slot state file schema.
- `spec/xp-curve.md`. Math + reference pseudocode.
- `spec/effect-kinds.md` + `spec/trigger-kinds.md`. Standard
  Effect / Trigger kinds and their param shapes.
- `docs/methodology.md`. RESEARCH.md content elevated.
- `docs/composition-model.md`. Effects + Triggers + Skills,
  engine-agnostic.
- `docs/def-registry.md`. The CRD pattern.
- `docs/naming.md`. Naming both frameworks follow.

**0b. `modforge/core/` Rust crate (~3-4 days)**

One crate, multiple submodules. `crate-type = ["cdylib",
"rlib"]`. C ABI via `extern "C"` + `cbindgen`-emitted
header for the C# side.

Submodules in migration order. Each row corresponds to one
ueforge file moving under `modforge/core/src/<submodule>/`,
with ueforge replacing the original with a `pub use
modforge_core::<submodule>::*;` re-export so existing call
sites compile unchanged:

| # | Submodule | From | Tests |
|---|---|---|---|
| 1 | `ring` | `ueforge/src/ring.rs` | bounded ring round-trip |
| 2 | `counters` | `ueforge/src/counters.rs` | atomic increment + TimeScope |
| 3 | `log` | `ueforge/src/log.rs` | sink + level + format |
| 4 | `args` | `ueforge/src/args.rs` | JSON arg helper round-trip |
| 5 | `envelope` | `ueforge/src/envelope.rs` | parse_request + OpResponse |
| 6 | `settings` | `ueforge/src/settings.rs` | JSON debounce save |
| 7 | `shutdown` | `ueforge/src/shutdown.rs` | registry order + run_all |
| 8 | `selector` | `ueforge/src/selector.rs` (grammar half) | grammar parser |
| 9 | `ops` | `ueforge/src/ops.rs` (registry half) | OpDef + dispatch + list_ops |
| 10 | `server` | `ueforge/src/server.rs` | tiny_http listener + auth token |
| 11 | `scanner` | `ueforge/src/scanner.rs` | memory scan + cancel |
| 12 | `winproc` | `ueforge/src/winproc.rs` | threads/modules/regions/cpu |
| 13 | `hot_reload` | `ueforge/src/hot_reload.rs` (protocol) | handshake types |
| 14 | `rpg` | `ueforge/src/rpg/{xp,progress,format,state,store,disabled}.rs` + new `catalog.rs` | XP curve + state round-trip + catalog parse |

Per submodule the migration is mechanical: move file,
re-export, run `cargo test`, commit. The bigger ones
(`ops`, `selector`, `rpg`) need a careful split of the
generic shape (moves) from the engine-specific handlers
(stays in ueforge).

`ffi.rs` is added last. It exposes the surface unityforge
needs at runtime (XP math, state ops, settings load/save,
catalog parse, envelope encode/decode, selector parse,
scanner control, log emit). `cbindgen` emits
`headers/modforge_core.h`.

**0c. Test corpus (~1 day)**

- `modforge/test-corpus/ops/`. One file per generic
  primitive: input args + expected envelope shape:
  `ping.json`, `snapshot.json`, `list_ops.json`,
  `list_selectors.json`, `read_bytes.json`,
  `write_bytes.json`, `walk_class.json`,
  `inspect_address.json`, `exec_call.json`,
  `scan_memory.json`, `freeze.json`.
- `modforge/test-corpus/rpg/`. Level-up, refund,
  slot-activate, snapshot-with-skills, bad-skill-id,
  max-level-cap.
- `modforge/test-corpus/selector/`. Each selector form +
  expected resolved-handle envelope.

Both frameworks load this corpus in their integration
tests; both must produce identical envelopes.

**Exit gate:**
- `cargo test -p modforge-core` is green.
- ueforge builds and runs against the new crate. g2rpg
  in-game tab renders. HTTP debug endpoint responds. No
  behavior change vs. pre-extraction.
- A Rust integration test exercises every `extern "C"`
  entry the FFI surface ships; this smoke-tests the
  unityforge consumption shape before Phase 1 starts.

#### Phase 1: unityforge skeleton + full HTTP control plane (~5-6 days)

The minimum unityforge needs for both **research** (the HTTP
debug surface that lets us reverse-engineer Wild West Miner)
and RPG plumbing (settings, logger, hooks).

**The HTTP control plane is the priority deliverable.** Once
this phase exits, an empty BepInEx plugin on any Unity-Mono
game opens a debug port and accepts the full generic-primitive
op surface. Phase 2's RPG work and Phase 3's wwm-rpg both
ride on that.

**1a. Project + host contract (~half day)**

- `grounded2mods/unityforge/unityforge.csproj` (netstandard2.1).
  References Newtonsoft.Json. **Build-output also copies
  `modforge_core.dll` + `0Harmony.dll` next to the plugin DLL.**
- BepInEx 5 plugin shell. `UnityforgeMod` base class with
  `OnEnable()` / `OnDisable()` for subclasses + a
  MonoBehaviour driver that calls `TickFrame()` each Update.
- `IUnityforgeHost` interface (`Now()`, `ModDataDir()`,
  `QueueWrite(Action)`, `Log(level, msg)`, `Snapshot() -> JObject`).

**1b. modforge-core P/Invoke layer (~1 day)**

- `Native/ModforgeCore.cs`. `[DllImport("modforge_core")]`
  declarations matching the cbindgen header.
- Marshalling helpers for strings, `JObject` <-> JSON bytes,
  opaque handles (settings, scanner sessions).
- Wrappers: `Settings`, `Logger`, `Counters`, `Envelope`,
  `OpRegistry`, `SelectorRegistry`, `Scanner`, `Winproc`,
  `ShutdownRegistry`. Each one is a thin C# class over the
  native entry points; ueforge's behaviors come along for
  free.

**1c. HTTP control plane (~2 days)**

The big one. Full ueforge parity for the debug surface:

- `Unityforge.HttpServer`. Listener thread + accept loop +
  POST routing. Mirrors `ueforge::server::spawn`. Per-launch
  auth token + 1 MiB body cap. Panics in op handlers caught
  so a buggy op doesn't drop the listener.
- `Unityforge.MainThreadQueue`. `ConcurrentQueue<Action>` +
  re-entrance guard + budgeted drain on `TickFrame()`. The
  C# parallel to `PE_QUEUE`. POST handlers that touch Unity
  state enqueue here; GET handlers run on the listener
  thread against snapshots.
- `Unityforge.OpRegistry` (C# wrapper over the native one).
  Built-in ops registered by Phase-1 framework code:
  - `ping`, `snapshot`, `list_ops`, `list_selectors` (free
    from modforge-core).
- **C# implementations of the generic-primitive op family
  for Unity Mono**, with the same op-name + args + result
  schemas as ueforge's UE versions:
  - `walk_class` -> enumerates live MonoBehaviour /
    ScriptableObject / `Singleton<T>` instances of a named
    type via reflection. Returns `{ instances: [{ address,
    name, full_name }] }`.
  - `inspect_address` -> dump fields of a managed object
    handle. Returns `{ class_name, properties: [{ name,
    offset?, value }] }`.
  - `read_field` -> typed managed read. Replaces UE's
    raw `read_bytes` (different memory model, same op
    name semantics: read a value by selector + path).
  - `write_field` -> typed managed write, queued to main
    thread.
  - `invoke_method` -> reflection invoke with JSON args /
    result. Unity's parallel to UE's `exec_call`.
  - `list_singletons` -> enumerate all live `Singleton<T>` /
    `StaticInstance<T>` instances (game-pattern probe).
- `Unityforge.SelectorRegistry` registers the Unity-side
  resolvers against the shared parser: `addr:`, `class:`,
  `first_class:`, `singleton:`, `static_instance:`,
  `monobehaviour:`. Names match ueforge where the concept
  matches; new names where Unity differs.
- `Unityforge.Hook` + `HookDef` + `HookRegistry` wrapping
  HarmonyLib. `RegisterPrefix`, `RegisterPostfix`,
  `RegisterFinalizer`, `ShutdownAll()`. Panic counters per
  hook (parity with ueforge).

**1d. Reflection inspector (~1 day)**

- `Unityforge.ReflectionInspector`. C#'s answer to ueforge's
  `discovery` + `inspect_address`. Walks managed types and
  field metadata. Used by `inspect_address`, `walk_class`,
  `list_singletons`. Caches `FieldInfo` / `PropertyInfo`
  per-type to avoid hot-path reflection.

**1e. Logger + Settings + Service wiring (~half day)**

- `Logger`. Thin facade over the native sink + Unity
  `Debug.Log` mirror.
- `Settings`. Wraps `modforge_core::settings` with a
  typed-accessor helper.
- `UnityforgeService`. `TickFrame(now)` calls drain queue +
  process snapshot requests + flush settings.

**1f. Unit + integration tests (~1 day)**

- C# unit tests for marshalling each FFI entry.
- Integration: load the modforge `test-corpus/ops/`
  corpus, run each request against a stub host, assert
  envelope shape parity with what ueforge produces for the
  same corpus.

**Exit gate:**

- An empty BepInEx plugin extending `UnityforgeMod` loads in
  Wild West Miner (verified end-to-end).
- `curl POST localhost:<port>/op -d '{"op":"ping"}'` returns
  the expected envelope.
- `curl ... {"op":"list_ops"}` returns the generic-primitive
  set + the built-in ueforge-parity set.
- `curl ... {"op":"walk_class","args":{"class":"PlayerManager"}}`
  returns the live `PlayerManager` instance address.
- `curl ... {"op":"inspect_address","args":{"addr":"<above>"}}`
  dumps PlayerData via reflection.
- Conformance corpus passes.

#### Phase 2: unityforge.Rpg (~4-5 days)

The Unity-side implementation. Pure-logic types come from
`modforge-rpg-core` via P/Invoke; per-language types (`IEffect`,
`ITrigger`, `Tracker` dispatch) are native C#.

| Source | unityforge file | Notes |
|---|---|---|
| `modforge-rpg-core::xp` (FFI) | `Rpg/XpCurve.cs` (~30) | Thin C# wrapper around `mfrpg_xp_for_level` / `mfrpg_level_for_xp` |
| `modforge-rpg-core::progress` (FFI) | `Rpg/Progress.cs` (~20) | Thin wrapper |
| `modforge-rpg-core::format` (FFI) | `Rpg/PercentFormat.cs` (~40) | Thin wrapper |
| `modforge-rpg-core::state` (FFI) | `Rpg/SkillsState.cs` (~50) | C# class holding `IntPtr` to native state; methods marshal through FFI |
| `modforge-rpg-core::store` (FFI) | `Rpg/SkillStore.cs` (~60) | Calls `mfrpg_state_load` / `mfrpg_state_save` |
| `modforge-rpg-core::disabled` (FFI) | `Rpg/DisabledSkill.cs` (~30) | Thin wrapper |
| `modforge-rpg-core::catalog` (FFI) | `Rpg/SkillCatalog.cs` (~120) | Loads catalog JSON via native parser; binds each Effect/Trigger kind to a C# implementation type via a lookup table |
| `ueforge/src/rpg/effect.rs` (475) | `Rpg/IEffect.cs` + `Rpg/EffectDef.cs` (~150) | C# interface. `Apply(level, maxLevel, ctx)` + `Format(level, maxLevel)`. **Native C#**, does not go through FFI. Effects touch the game engine |
| `ueforge/src/rpg/trigger.rs` (223) | `Rpg/ITrigger.cs` + `Rpg/TriggerDef.cs` (~120) | Same shape. `TriggerCtx` is a tagged class hierarchy. **Native C#** |
| `ueforge/src/rpg/skill.rs` (112) | `Rpg/SkillDef.cs` + `Rpg/SkillRegistry.cs` (~80) | Catalog row composing one Effect + one Trigger. **Native C#** |
| `ueforge/src/rpg/tracker.rs` (601) | `Rpg/Tracker.cs` (~500) | Per-slot leveling + XP accumulation + fire-on-slot-change. Holds an FFI handle to the shared `SkillsState`; dispatches Effects in native C#. The big port |
| `ueforge/src/rpg/slot_key.rs` (78) | `Rpg/ISlotKeyResolver.cs` + `Rpg/StaticSlotKey.cs` (~60) | Engine-side resolver; consumer supplies it. **Native C#** |
| `ueforge/src/rpg/poller.rs` (254) | `Rpg/SlotPoller.cs` (~150) | Polls slot resolver, fires activate/deactivate. Uses Update tick, no thread needed |
| `ueforge/src/rpg/vanilla.rs` (166) | `Rpg/VanillaCache.cs` (~120) | Per-class vanilla-value cache. **Native C#**. Caches Unity field handles |
| `ueforge/src/rpg/std_effect.rs` (543) | `Rpg/StdEffect/*.cs` (~400) | `PlayerFloatEffect`, `FieldMultiplyEffect`, `FieldAdditiveEffect`, `MethodInvokeEffect`. Use C# reflection cache + Harmony |
| `ueforge/src/rpg/ops.rs` (133) | `Rpg/RpgOps.cs` (~110) | `skill_list`, `skill_levelup`, `skill_refund`, `skill_state` ops |
| `ueforge/src/rpg/tab.rs` (164) | (deferred) | UI deferred |
| `ueforge/src/rpg/health.rs` (208) | (deferred) | Game-specific lift |
| `ueforge/src/rpg/status.rs` (121) | (deferred) | Status-effect Effect |
| `ueforge/src/rpg/mod.rs` (66) | `Rpg/Rpg.cs` (~40) | Public re-exports |

Phase 2 deliverable: `unityforge.dll` containing a complete RPG
subsystem that compiles against netstandard2.1 with zero
game-DLL references. The `IEffect` implementations that touch
Unity types stay generic (operate on a delegate the consumer
supplies). The consumer wires `FieldMultiplyEffect.For<T>` to
its game classes; the framework never names a game type.

Unit tests:
- XP curve: `cumulative_xp_for_level` + `level_for_xp` round-trip
- Tracker: level up consumes XP; refund restores; fire on slot
  change fires every catalog row
- Store: round-trip a `SkillsState` through JSON
- OpRegistry: every RPG op returns a valid envelope against a
  stub tracker
- Conformance: load the modforge `test-corpus/rpg/` and run
  each scenario

**Exit gate:** all unit tests pass; conformance corpus passes;
the unityforge tab in `OpRegistry.ListOps()` shows the same
RPG ops ueforge ships.

#### Phase 3: wwm-rpg (the Wild West Miner RPG mod, ~5-7 days)

The proof. A real BepInEx plugin built on unityforge that
ships skills to the player.

- New crate: `grounded2mods/wwm-rpg/wwm-rpg.csproj`.
- References: `unityforge.dll`, Wild West Miner's
  `Assembly-CSharp.dll` (publicized), `0Harmony.dll`,
  `Newtonsoft.Json.dll`, `UnityEngine.CoreModule.dll`.
- Implements `IUnityforgeHost` via a small MonoBehaviour
  (`Update()` -> `host.Tick(Time.realtimeSinceStartup)`).
- Implements `ISlotKeyResolver` reading
  `GameSerializationSystem.Instance._currentLoadedSaveNumber`
  (publicizer makes the private field readable).
- Reverse-engineer the right hook points (more decompile work).
  Likely candidates:
  - `DigManager.OnDig` (static event). XP source per swing.
  - `PlayerManager.e_OnPlayerCurrencyChanged` (static event).
    XP source per sale.
  - `Worker.HireMethod`. Patch with Harmony for "Charisma"
    skill discount.
  - `MineDataSO` field on a `Mine`. Mutate for "Lucky"
    skill ore drops.
- Catalog: 5-8 skills.
  - **Greedy Miner** (FieldMultiply on a `MineDataSO.OreValue`,
    PlusPercentMult format).
  - **Strong Back** (FieldAdditive on
    `PlayerCarryingController.MaxCapacity`).
  - **Quick Pickaxe** (FieldMultiply on `DigManager._digRange`
    or `_digCheckTimeout`).
  - **Lucky** (probability scaler on ore drop tables).
  - **Charisma** (FieldMultiply on
    `WorkersManager.HireCostMultiplier` or similar).
  - **Resilient** (FieldMultiply on player stamina drain).
- XP curve: ueforge's defaults (base=100, exponent=1.8,
  max_level=50).
- UI: F-key opens a minimal Unity IMGUI overlay listing
  skills + Plus button per skill. Good enough for v0;
  full UI is later.
- Save/load: piggyback on
  `GameSerializationSystem.RegisterObjectToSerialize` and
  add a key `WWM_RPG` to `GameSerializationData`. OR write a
  sibling file under `ModDataDir/<slot>.json`. Pick the
  sibling file; cleaner separation.

**Exit gate:** load the game, dig some ore, see XP accrue,
level up Strong Back, observe inventory cap visibly increase,
save+reload, observe state persisted. Quit and relaunch,
state still there. Run `curl POST /op {op:"skill_state"}` and
get the same numbers.

#### What's deferred (and why)

| Module | Why later |
|---|---|
| Snapshots framework (ProjectionSnapshot) | wwm-rpg's snapshots are small enough to build by hand. Wait until a second consumer needs the generic pipeline. |
| Webhooks | Nice but not required. Add when a consumer asks for push events. |
| Agent launcher | Lift from Timberbot when we want LLM-driven play, not before. |
| In-game UI framework (imgui/IMGUI wrapper) | wwm-rpg ships its own OnGUI overlay. Generalize after two consumers. |
| Stacks / Difficulty / SO browser | No consumer demanding them yet. |
| Hot reload | Mono+Harmony hot reload is gnarly. Live without it through Phase 3. |
| Conformance test for non-RPG ops | RPG conformance is the only thing we need to prove unityforge matches ueforge in spirit. |
| Timberbot port to unityforge | Independent work, no schedule pressure, only worth doing once unityforge has snapshots + webhooks + agent landed. |
| IL2CPP support | Mono-only through wwm-rpg. Schedule 1 path waits. |

**Total Phase 0-3: ~14-17 days.** About 3 weeks. End state:
modforge holds the engine-agnostic spec for RPG; unityforge
holds a complete RPG implementation; Wild West Miner has a
working skill mod that proves the abstractions match
ueforge's. Everything else gets built when a real consumer
asks for it.

## 7. Open design questions

1. **IL2CPP scope in v1?** Both Timberborn and Wild West Miner
   are Mono. Schedule 1 is IL2CPP. unityforge v1 is Mono-only;
   IL2CPP is a v2 expansion via Il2CppInterop. Confirm we're
   OK with that.
2. **Bundled imgui in C#?** ueforge bundles imgui v1.92.1 via
   the C++ shim. C# has options: P/Invoke into a native imgui
   DLL (CImGui.NET / ImGui.NET), use Unity IMGUI (`OnGUI`),
   or build a UIElements layer. Recommendation: ImGui.NET for
   parity. Decide in M8.
3. **The shared-binary tease.** If modforge's selector parser
   and toon encoder both end up identical, do we extract them
   into a Rust `modforge-core` crate that ueforge consumes
   natively and unityforge consumes via P/Invoke? Defer until
   we've written both copies and the duplication is concrete.
4. **Timberbot's future.** Timberbot currently ships ~12k lines
   of mostly-generic code. Once unityforge exists, Timberbot
   has two choices: port onto unityforge (mechanical refactor,
   ~3-5 days, loses ~7k lines), or stay independent. Defer the
   call until unityforge is real; Timberbot keeps shipping in
   the meantime.

## 8. Risks

| Risk | Mitigation |
|---|---|
| 4-5 weeks is long; we get distracted | Strict per-milestone exit criteria. Each milestone ships a buildable, tested artifact. No "almost done" merges. |
| Symmetry pressure forces bad Unity APIs to match Rust | The architectural mandates apply; the *implementation* doesn't. If HarmonyLib forces a different hook ergonomic than UE4SS, that's fine. The Def/Registry shape stays the same; how `register` is called can differ. |
| Hot reload in C# is materially harder than in Rust | Spike early in M9. If it's gnarly, push to v2 and ship without it. Both Timberbot and ueforge ran a long time before hot reload mattered. |
| modforge specs drift from ueforge reality | M10 closes this. Specs are authoritative; ueforge passes them or we fix ueforge. |
| ImGui.NET binary size or Unity-version incompat | Spike before M8. Fallback is Unity IMGUI. UI is a v0 nice-to-have, not a blocker. |

## 9. Acceptance gates

The plan is "done" when:

- `modforge/spec/` validates against both frameworks' actual
  HTTP behavior via the shared test corpus.
- `unityforge.dll` builds against netstandard2.1, has zero
  game-DLL references, and passes the corpus loaded with a
  stub host.
- ueforge and unityforge each expose the same modules
  (per section 3's table) and share the same Def/Registry
  naming.
- `modforge-deploy` ships either a Rust cdylib (UE4SS) or a
  C# DLL (BepInEx) given the same CLI shape.
- The methodology doc + composition-model doc are the single
  source of truth for both frameworks.
