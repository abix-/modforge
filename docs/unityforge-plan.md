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

**Tier 3: shared Rust core (consumed natively by ueforge, via
P/Invoke by unityforge)**

| Asset | Form |
|---|---|
| `modforge/rpg-core/` (Phase 0) | Rust crate with `crate-type = ["cdylib", "rlib"]`. Holds the pure-logic RPG files lifted out of `ueforge/src/rpg/`: XP curve, progress curve, percent formatting, in-memory state types, JSON persistence shape, skill-catalog JSON loader. C ABI via `extern "C"` + `cbindgen`-emitted header |
| future `modforge/<subject>-core/` crates | Same shape, added only when a subject's pure-logic files duplicate identically between ueforge and a written-once unityforge equivalent. Don't speculatively extract; extract on second duplication |

What stays per-framework:

- Traits and interfaces (`trait Effect` in Rust,
  `interface IEffect` in C#). Trait objects don't cross FFI.
- Standard Effect / Trigger implementations that touch the
  engine (engine-specific by definition).
- Trackers and dispatch loops (they call language-specific
  trait/interface methods).
- Hooks, vanilla cache, slot-key resolution (engine-specific).

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

## 6. Sequencing: RPG first

The whole plan rides on one driving goal: **extract ueforge's
RPG module (Skills + Effects + Triggers + Tracker + XP + slot
key + persistence) into modforge so unityforge can build on
it, then prove it works by shipping an RPG mod for Wild West
Miner.**

Everything we build before that is the minimum scaffolding
needed to make RPG run. Everything we build after is whatever
the next concrete consumer demands. No speculative modules.

### What "extract into modforge" means across Rust and C#

The frameworks are different languages. modforge owns three
kinds of asset, with different reuse mechanics:

| Layer | Form | ueforge consumes | unityforge consumes |
|---|---|---|---|
| **Spec** | JSON schemas, ABNF grammars, markdown docs (`spec/`, `docs/`) | reads at design time | reads at design time |
| **Test corpus** | `request -> expected response` JSON files (`test-corpus/`) | loaded by ueforge's tests; HTTP round-trip asserts | loaded by unityforge's tests; same round-trip asserts |
| **Code core (Rust)** | `modforge-rpg-core` Rust crate. XP curve, progress curve, percent formatting, pure state types, JSON persistence file shape | direct `[dependencies]` entry, native Rust call | `[DllImport]` against a built `modforge_rpg_core.dll` + a C ABI surface |

The first two are free. The third is the genuinely-shared
binary that we extract ueforge's pure-logic files into:

```
modforge/
  rpg-core/                       # Rust crate. cdylib + rlib.
    Cargo.toml
    src/
      lib.rs
      xp.rs                       # FROM: ueforge/src/rpg/xp.rs
      progress.rs                 # FROM: ueforge/src/rpg/progress.rs
      format.rs                   # FROM: ueforge/src/rpg/format.rs (pure parts)
      state.rs                    # FROM: ueforge/src/rpg/state.rs
      store.rs                    # FROM: ueforge/src/rpg/store.rs (json serde only)
      disabled.rs                 # FROM: ueforge/src/rpg/disabled.rs
      catalog.rs                  # NEW: SkillDef in catalog-JSON form
      ffi.rs                      # C ABI surface for unityforge
    headers/
      modforge_rpg_core.h         # generated cbindgen header for C# DllImport
```

What's NOT in `modforge/rpg-core/`:

- The `Effect` and `Trigger` traits. Rust trait objects don't
  cross FFI. Each framework defines its own interface
  (`trait Effect` in Rust, `interface IEffect` in C#) and
  implementation list. The catalog spec defines the *kinds*;
  each framework binds those kinds to its own implementation
  types.
- Standard Effect implementations that touch the engine
  (`PlayerFloatEffect`, etc). UE-specific in ueforge,
  Unity-specific in unityforge.
- The Tracker. Stays per-language because it dispatches through
  the language-specific Effect trait/interface. State *types*
  (`SkillsState`, `SlotKey`) are shared via FFI; dispatch isn't.
- Hooks, slot-key resolution, vanilla cache. Engine-specific.

What this gives us:

- One implementation of the XP curve math. A bug fix is one
  patch, not two.
- One persistence file format. ueforge and unityforge mods
  can read each other's save files (academically; in practice
  each game has its own slot, but the *format* is identical).
- One catalog JSON loader. Game mods can define skills as data
  (not code) and the same JSON parses identically in both
  frameworks.
- A real test surface in the shared crate. Phase 0 ships XP
  + progress unit tests; both frameworks inherit them.

What it costs:

- ~200-300 lines of `extern "C"` FFI glue + `cbindgen` setup.
- unityforge's build packages a Rust-built `modforge_rpg_core.dll`
  alongside its own DLL. Modder deploys both.
- P/Invoke marshalling overhead per call. Negligible for the
  surface we expose (XP math + persistence load/save are cold;
  Tracker dispatch is per-language and never crosses FFI).

### Why RPG first

- **It's the densest module in ueforge.** ~4.3k lines across
  19 files in `ueforge/src/rpg/`. Doing it first forces the
  Def/Registry pattern, hook abstraction, persistence shape,
  op envelope, settings, and HTTP control plane to all land
  in coherent form on the Unity side.
- **Wild West Miner is an unusually clean RPG target.** Plain
  Mono, public singletons, currency / dig-action / sell events
  already exposed. We avoid fighting an engine while validating
  a framework.
- **RPG is what ueforge is known to do well.** Porting it
  cleanly is the strongest possible signal that unityforge has
  the right shape.
- **It produces a real, playable mod at the end.** Not a
  framework demo. A thing the player runs.

### Dependency graph

```
modforge specs (RPG schema, persistence, XP, op envelope, naming)
                            |
                            v
unityforge skeleton (csproj + BepInEx entry + IUnityforgeHost)
                            |
              ----------------------------
              |             |            |
              v             v            v
        Logger / Settings   HTTP+Ops   Hooks (HarmonyLib)
                            |             |
                            v             v
                     unityforge.Rpg (Effects + Triggers + Skills + Tracker + XP + slot)
                                          |
                                          v
                                  wwm-rpg (the Wild West Miner mod)
```

Nothing else gets built in this pass. **Snapshots, webhooks,
agent, in-game UI, stacks, difficulty, ScriptableObject browser,
hot reload all wait** until something concrete demands them.

### Phases

#### Phase 0: modforge essentials for RPG (~3-4 days)

Both the spec-only assets and the shared Rust core. RPG-only
slice; nothing else from modforge gets built yet.

**0a. Specs and docs (~1 day)**

- `modforge/` workspace folder + README.
- `spec/op-envelope.json`. JSON schema for `{ op, args }` /
  `{ ok, op, error, result, state }`. Lift from ueforge.
- `spec/skill-catalog.json`. JSON schema for `SkillDef`:
  `{ id, display_name, max_level, effect: { kind, params },
  trigger: { kind, params } }`.
- `spec/rpg-persistence.json`. JSON schema for per-slot
  state file: `{ skill_levels: {id: u32}, xp: u64,
  available_points: u32 }`.
- `spec/xp-curve.md`. The math + reference pseudocode
  (`cumulative_xp_for_level(level)` + `level_for_xp(xp)`).
- `spec/effect-kinds.md`. Catalog of standard Effect kinds
  + their param shapes. The same kinds appear in both
  frameworks; each framework supplies its own implementation
  bound to the kind name.
- `spec/trigger-kinds.md`. Standard Trigger kinds + param
  shapes.
- `docs/composition-model.md`. Effects + Triggers + Skills,
  engine-agnostic, extracted from
  `ueforge/docs/architecture.md`.
- `docs/def-registry.md`. The Def/Registry/Instance/Controller
  pattern.
- `docs/naming.md`. Naming both frameworks follow.

**0b. `modforge/rpg-core/` Rust crate (~2-3 days)**

The pure-logic core ueforge already has, lifted into a
crate both frameworks consume.

- `modforge/rpg-core/Cargo.toml` with
  `crate-type = ["cdylib", "rlib"]` and a `cbindgen` build
  step.
- Port (verbatim, with `pub use` re-exports):
  `xp.rs`, `progress.rs`, `format.rs` (pure parts only),
  `state.rs`, `store.rs` (the JSON ser/de half), `disabled.rs`.
- Add `catalog.rs`: a `SkillDefData` struct that parses from
  the modforge skill-catalog JSON. The Effect / Trigger
  fields are `{kind: String, params: serde_json::Value}`;
  each framework binds the kind to its own implementation
  list at load time.
- Add `ffi.rs`: `extern "C"` surface for unityforge.
  Minimal:
  - `mfrpg_xp_for_level(curve_base, exp, max_level, level) -> u64`
  - `mfrpg_level_for_xp(curve_base, exp, max_level, xp) -> u32`
  - `mfrpg_format_percent(*kind, level, max_level, *out_buf, buf_len) -> u32`
  - `mfrpg_state_load(*path) -> *State` / `mfrpg_state_save(*State, *path)`
  - `mfrpg_state_get_level(*State, *skill_id) -> u32`
  - `mfrpg_state_set_level(*State, *skill_id, level)` etc.
  - `mfrpg_state_free(*State)`
- `cbindgen.toml` + `build.rs` to emit
  `headers/modforge_rpg_core.h` for the C# side's reference.
- ueforge migrates: replace `ueforge/src/rpg/xp.rs` with
  `pub use modforge_rpg_core::xp::*;` etc. Tracker still
  lives in ueforge (it dispatches Rust trait objects).
- Unit tests in `modforge/rpg-core/tests/` cover XP curve,
  state round-trip, catalog JSON parse, FFI smoke. These
  tests are the shared-truth assertion every other place
  inherits.

**0c. Test corpus (~half day)**

- `modforge/test-corpus/rpg/`. Six request/response pairs
  covering level-up, refund, slot-activate,
  snapshot-with-skills, bad-skill-id, max-level-cap.
  Both frameworks load this corpus in their tests; both
  must produce the expected envelopes.

**Exit gate:** `cargo test -p modforge-rpg-core` is green;
ueforge builds against the new crate (Tracker still works
end-to-end against g2rpg's catalog); a Rust integration
test calls every FFI entry point.

#### Phase 1: unityforge skeleton + bare plumbing for RPG (~3 days)

The minimum unityforge needs to make RPG run end-to-end. No
snapshots framework yet. No webhooks. No fancy UI.

- `grounded2mods/unityforge/unityforge.csproj` (netstandard2.1,
  no game-DLL references).
- BepInEx 5 plugin shell. `UnityforgeMod` base class with
  `OnEnable()` / `OnDisable()` hooks for subclasses.
- `IUnityforgeHost` interface (`Now()`, `ModDataDir()`,
  `QueueWrite(Action)`, `Log(level, msg)`).
- `Logger` lift from `TimberbotLog`.
- `Settings` (load + in-memory `JObject` + debounced
  writeback, lifted from `TimberbotService`).
- Tiny HTTP server. Lift `TimberbotHttpServer` and trim to
  GET/POST `/op` only. ~150 lines. No write-job budget yet
  (RPG ops are cheap; single-frame execution is fine).
- `OpDef` + `OpRegistry.Dispatch(op, args, host) -> Envelope`.
  Mirrors ueforge's surface. Two built-in ops: `ping`,
  `snapshot` (returns the host's current snapshot JSON).
- `Hook` + `HookDef` + `HookRegistry` wrapping HarmonyLib.
  `Hook.RegisterPrefix(...)`, `Hook.RegisterPostfix(...)`,
  `HookRegistry.ShutdownAll()`.
- Unit tests: Settings round-trip, OpRegistry dispatch,
  HookRegistry patch+unpatch.

**Exit gate:** an empty BepInEx plugin extending
`UnityforgeMod` loads in any Unity Mono game, opens the HTTP
port, responds to `POST /op {op:"ping"}` with the envelope.

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
