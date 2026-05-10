# Architecture (Def -> Registry -> Instance -> Controller)

> **Authoritative on:** the universal layering pattern every
> ueforge subsystem follows (or should). Borrowed from
> Kubernetes Custom Resource Definitions and adapted for an
> in-process UE5 mod framework.
>
> Read this before adding a new module. New work should land
> compliant; existing drift is tracked in the compliance table.

The motivating problem: ueforge has many subjects -- skills,
buildings, status effects, debug ops, selectors, shutdown
handlers, hooks, tabs -- and each one independently invented
its own "schema + storage + instance + behavior" shape. Some
landed on a clean Def + Registry pattern (skills, tabs);
others ended up as hardcoded match arms across multiple files
(debug ops, selectors). The drift makes "how do I add a new
X" answer differently for every X.

This document defines the contract once. New subjects pick
the same shape. Existing subjects get scored against it; the
gap is the cleanup punch list.

## The four roles

| Role | What it is | Example |
|---|---|---|
| **Def** (CRD) | The schema. A `struct` declaring the fields a kind has. Static, immutable, no runtime state. | `Skill<E>`, `BuildingDef<S, C>`, `OpDef`, `SelectorDef` |
| **Registry** (etcd) | The collection of Defs. A `&'static [<Subject>Def]` const + a `<subject>_def(kind)` lookup. One entry per kind. | `CATALOG: &[Skill<E>]`, planned `OP_REGISTRY` |
| **Instance** (CR) | One runtime object created from a Def. Lives in whatever storage fits (an ECS would use components; we use `Mutex<HashMap<Handle, ...>>` or per-subject state structs). | `SkillsState.skill_levels[id]`, `BuildingsTracker::instances[handle]` |
| **Controller** | The function or system that reads the Def + inputs and writes/updates the Instance. Reconcile = re-derive when inputs change. | `RpgApplier::apply_skill`, `BuildingsTracker::tick`, `place_building` |

**Key rule:** the Def is the source of truth. Controllers read
fresh values from the Def at every reconcile. Instances never
cache Def fields -- if the Def changes (a new module ships
with a different base value, a hot-reload swaps catalog rows),
the next reconcile picks it up.

## The naming contract

Pick one shape for each role and stick with it across every
subject. Endless's `k8s.md` flags drift between `job` /
`activity` / `kind`; we avoid that here.

| Role | Naming |
|---|---|
| Schema struct | `<Subject>Def` (`SkillDef`, `CreatureDef`, `HookDef`, `OpDef`, `BuildingDef`, `SelectorDef`, `ShutdownHandlerDef`, `TabDef`). Always Def-suffixed -- no exceptions. |
| Discriminator | `<Subject>Kind` enum where the set is closed; `&'static str` id where it's open-ended. The field that holds it is always called `kind` / `id` (NOT `name`, `job`, `activity`). |
| Registry wrapper struct | `<Subject>Registry` holding `entries: &'static [<Subject>Def]` plus any extra registry-level config (e.g. `BestiaryRegistry` carries `default_xp: u32` alongside its entries). The wrapper exists so future fields don't reshape every consumer; bare slices are reserved for the carve-out exceptions below. |
| Registry instance | `<SUBJECT>_REGISTRY: <Subject>Registry` (static const) for closed-set framework-owned registries, or per-mod `static CATALOG: <Subject>Registry<E>` when the registry is parameterized over a consumer-defined effect enum. |
| Lookup method | `<Subject>Registry::def(&self, key) -> Option<&'static <Subject>Def>` is the canonical lookup. Free `<subject>_def(...)` functions are kept as thin wrappers for back-compat where prior call sites used them. |
| Tracker (stateful subjects) | `<Subject>Tracker` -- holds the inner state, persists, reconciles. |
| Module-level controller (stateless subjects) | bare functions: `apply_skill`, `place_building`, `dispatch_op`. |

**Bare-slice exception.** Subjects with no extra registry-level
config AND no foreseeable use for one MAY skip the
`<Subject>Registry` wrapper and use a bare
`&'static [<Subject>Def]` directly. Tabs (`MOD_INFO.tabs`) is
the canonical example -- the only registry-level fact is
"these are the tabs", a wrapper would be ceremony tax. Mark
the carve-out explicitly in the module's K8s slot header.

Header line on every subject's module doc: a single line
declaring its slot --

```
// K8s slot: Def=SkillDef, Registry=CATALOG, Instance=SkillsState.skill_levels, Controller=RpgApplier::apply_skill
```

A reviewer can grep that line across the codebase to confirm
no subject lost its place.

## What does NOT fit (and why)

Not every piece of ueforge wants to be a CRD. Forcing the
pattern where it doesn't fit adds ceremony with no payoff.

| Subject | Why it doesn't fit |
|---|---|
| **Hooks** (`ProcessEventHook`) | Partial fit. `HookDef` exists as the per-install runtime record (class_name, slot, vtable, handler, active_calls, panic_count) and `HookRegistry` wraps the global handle list with the same `register` / `shutdown_all` / `defs` / `panic_count_total` surface as other registries. The carve-out is only that handlers are closures populated imperatively -- there's no compile-time `static HOOK_REGISTRY: HookRegistry = ...` const declaration the way `SkillRegistry` works. The shape is consistent; the mechanic is different. |
| **Counters** (`counter!` macro) | One static `AtomicU64` per call site. The "schema" is just `AtomicU64`; the variation is the call site itself. A registry would be a copy of the source. |
| **PE queue jobs** | Anonymous `Box<dyn FnOnce>`. Every job is unique; no shared schema. The Queue itself is the shared piece, and it already has a Def shape (the `Queue` struct + bounded depth + cancel flag). |
| **`Settings<T>`** | Generic over the consumer's struct; the consumer's struct IS the Def. `Settings` is a controller / persistence wrapper. Already correctly placed. |
| **Logger** | Process-singleton sink. No kinds. |

The carve-out is not a free pass: subjects in this list still
follow the rest of the framework's conventions (Drop ordering,
`shutdown_all` registry, etc.). They just don't have a CRD.

## Compliance scorecard

Score = how cleanly the subject splits into Def + Registry +
Instance + Controller, and whether adding a new variant is a
1-line registry append.

| Subject | Def | Registry | Instance | Controller | Score | Gap |
|---|---|---|---|---|---|---|
| **Skills** | `SkillDef<E>` (`ueforge/src/rpg/skill.rs`) | `SkillRegistry<E>` wrapper (`SkillRegistry::new(&[SkillDef { ... }])`); per-mod `static CATALOG: SkillRegistry<MyEffect>` | `SkillsState.skill_levels[id]` | `Tracker<A>::apply_skill` via `RpgApplier` | **100%** | Reference implementation for parameterized registries. Lookup via `CATALOG.def(id)`; iteration via `CATALOG.iter()` or `for s in CATALOG`. |
| **StandardEffect variants** | `StandardEffect` enum (`ueforge/src/rpg/std_effect.rs`) | Variants ARE the registry (closed enum) | Inlined in each `SkillDef { effect: StandardEffect::... }` | `StandardEffect::apply` / `format` | **80%** | Registry is implicit (enum variants act as keys); each variant carries its parameters inline. Works, but no separate Def-to-instance split. Acceptable since variants are parameterized by `'static` data only. |
| **Creatures** | `CreatureDef { class_name, base_xp }` (`ueforge/src/rpg/xp.rs`) | `CreatureRegistry { entries: &[CreatureDef], default_xp: u32 }`; per-mod `static CREATURES: CreatureRegistry` | per-kill XP value | `CreatureRegistry::lookup` | **100%** | Lookup via `CREATURES.def(class_name)` (full row) or `CREATURES.lookup(class_name)` (XP value with default fallback). Future fields (drop tables, level, faction) extend the row. |
| **Tabs** | `Tab { name, render }` (`ueforge/src/mod_main.rs`) | `MOD_INFO.tabs: &'static [Tab]` (bare slice -- documented carve-out per the contract) | imgui draw call per render | `ueforge_mod_render_tab` | **100%** | Reference implementation for the bare-slice exception. Tiny but the pattern is exact. |
| **Buildings** (planned, not built) | `Building<S, C>` design in [todo.md](../../docs/todo.md) | `BuildingsCatalog` | `Instance<S>` per placed | `BuildingsTracker::tick` + `BuildingSpawner` trait | **designed-100%** | Lock the naming to the contract above before implementation. |
| **Status effects** (in-flight) | per-row in game-side `UDataTable` | game-side data table (read live, not a Rust const) | `UStatusEffectComponent` instances on UE actors | `StandardEffect::StatusEffect` apply path | **partial** | Def + Registry live in the GAME's data tables, not in our Rust code. The Rust side is a thin wrapper; the registry is the game's. Acceptable -- the alternative is duplicating the table -- but document the boundary explicitly. |
| **Debug ops** | `OpDef { name, summary, args, handler }` (`ueforge/src/ops.rs`) | `OpRegistry` static singleton (`OP_REGISTRY`); populated at worker init via `register_builtins()` + `register_with_resolver(...)` + `rpg::ops::register(...)` + `debug::register_pe_call(...)` + per-game closures | per-call args + return JSON | `OpRegistry::dispatch(name, args)` -- one call replaces three match statements | **100%** | Auto-generated `list_ops` op for client discovery. New op = one `OP_REGISTRY.register(OpDef::new(...))` line; no dispatch edits. Same closure-populated-at-runtime pattern as hooks. |
| **Selectors** | `SelectorDef { prefix, summary, resolver: fn }` (`ueforge/src/selector.rs`) | `SelectorRegistry` static singleton (`SELECTOR_REGISTRY`); populated via `selector::register_builtins()` (framework's `addr:` / `class:` / `first_class:` / `singleton:`) + per-game `register(SelectorDef { ... })` | resolved `&'static UObject` | `selector::resolve(s)` walks the registry | **100%** | Auto-generated `list_selectors` op for client discovery. New selector kind = one `SELECTOR_REGISTRY.register(...)` line; game crates extend without touching framework code. |
| **Shutdown handlers** | `ShutdownHandlerDef { name, order, run: fn() }` (`ueforge/src/shutdown.rs`) | `ShutdownRegistry` static singleton (`SHUTDOWN_REGISTRY`); framework `register_builtins()` registers hooks=100 / http=200 / settings=300 / scanner=400; game crates interleave at `50` (pre-framework) or `500+` (post-framework) | per-call invocation | `SHUTDOWN_REGISTRY::run_all` (sorts by order, runs each, logs) | **100%** | The `ueforge_mod_shutdown` macro is now: `on_shutdown` -> `register_builtins()` -> `run_all()` -> `finalize_hot_reload_swap`. New ueforge subsystem that spawns threads adds its `register_builtins()` line; game-specific cleanup goes via `SHUTDOWN_REGISTRY.register(...)` from `worker()`. |
| **Modules** (rpg / stacks / difficulty / inventory / damage / planned buildings) | nothing | implicit; each module has its own catalog + tracker + ops + tab without a shared shape | -- | -- | **n/a** | Possible meta-pattern: a `ModuleDef` that names which subsystems each module participates in. Defer until we feel the pain. |
| **Hooks** | `HookDef` (per-install runtime record; `class_name`, `slot`, `vtable`, `handler`, `active_calls`, `panic_count`) | `HookRegistry` static singleton (`HOOK_REGISTRY`) holding the owned `ProcessEventHook` handles + snapshot accessors | `ProcessEventHook` RAII guard | trampoline (per-fire) + Drop (uninstall + drain) + `HookRegistry::shutdown_all` (hot-reload teardown) | **90%** | Defs are populated imperatively (closures, no compile-time const) -- documented exception. Naming + surface matches the other registries. |
| **Counters** | n/a (carve-out) | per-call-site statics | `AtomicU64` value | `bump` / `time_scope` | -- | Doesn't fit. |
| **PE queue jobs** | n/a (carve-out) | per-call closures | `Pending` | `Queue::drain` | -- | The Queue itself fits; jobs don't. |

## Highest-leverage refactor targets

In rough priority order. Each one collapses 2-3 hardcoded
match statements into a single registry append.

1. ~~**Debug ops registry.**~~ -- DONE 2026-05-10. `OpDef` +
   `OpRegistry` shipped; `OP_REGISTRY` singleton; auto-generated
   `list_ops` handler. The three old dispatchers
   (`handle_builtin`, `dispatch_standard_op`, `dispatch_pe_ops`)
   are gone. Game crates collapse to one
   `OP_REGISTRY.dispatch(op, args)` call.
2. ~~**Selectors registry.**~~ -- DONE 2026-05-10. `SelectorDef`
   + `SelectorRegistry` shipped; `SELECTOR_REGISTRY` singleton;
   `selector::resolve(s)` is the one entry point. Auto-generated
   `list_selectors` op. `resolve_generic` is gone.
3. ~~**Shutdown handlers registry.**~~ -- DONE 2026-05-10.
   `ShutdownHandlerDef` + `ShutdownRegistry` shipped;
   `SHUTDOWN_REGISTRY` singleton; the macro now runs
   `register_builtins()` then `run_all()`. New ueforge
   subsystem registers itself in `register_builtins`; game
   crates interleave via `SHUTDOWN_REGISTRY.register(...)`.
4. **Buildings + status effects.** Both still in design /
   in-flight. Land them compliant from day one (no rework
   later).
5. **Skills cleanup.** Rename `CATALOG` -> `SKILL_REGISTRY`;
   add framework-level `skill_def(catalog, id)` (already
   `find_skill` -- alias and update naming). Cosmetic; cheap.
6. **`BestiaryRow` struct.** Replace the `(&str, u32)` tuple
   with a named struct so future fields don't reshape every
   consumer.

## Lift candidates: game-specific ops with universal shape

When a game crate registers a debug op into `OP_REGISTRY` with
captured-game-state, look at the **shape**:

- If the op's algorithm is **universal** to UE5 RPG / survival
  games but the **constants** (class names, field offsets,
  UFunction names) are game-specific, it belongs in the
  framework as a binding-driven module.
- Pattern: ueforge ships the op handlers; game declares a
  `<Module>Binding` struct of constants; game's `worker()` calls
  `<module>::register(&BINDING, &PE_QUEUE)`.
- Examples already in this shape: `damage::DamageBinder`,
  `inventory::ViewportBinder`.

Today's known lift candidates (see [todo.md](../../docs/todo.md)
"Lift game-specific ops to ueforge"):

| Op family | Game-side | Universal shape |
|---|---|---|
| `simulate_add_health` / `simulate_set_current_health` / `simulate_apply_damage` | g2rpg `op_simulate_*` (HC selector + 0x32C offset + AddHealth UFunction name) | `ueforge::rpg::health::HealthBinding { hc_class, hc_selector, current_damage_offset, add_health_function }` -> registers all three ops |

When the second consumer asks for the same shape, lift before
duplicating.

## How to add a new compliant subject

Checklist for the next module:

1. Define `<Subject>Def { ... }` in a single source file. All
   fields `'static`-friendly (`&'static str`, primitives,
   `fn` pointers -- no `String`, no `Vec`, no closures).
2. Define `<Subject>Kind` (closed enum) OR document the id
   convention (open `&'static str` or `String`).
3. Author `<SUBJECT>_REGISTRY: &'static [<Subject>Def]`. One
   entry per kind. Compile-time const where possible.
4. Provide `<subject>_def(kind) -> &'static <Subject>Def`.
5. Decide: stateful (`<Subject>Tracker`) or stateless (free
   functions). Persist via `SlotStore<S>` if the instance
   state survives across saves.
6. Write the K8s-slot one-liner at the top of the module doc.
7. Add a row to the compliance table above.
8. If the subject spawns threads or owns external resources,
   register with the appropriate `shutdown_all` registry so
   hot-reload teardown works.

## Cross-references

- [README.md](README.md) -- module index
- [hooks.md](hooks.md) -- the hook subsystem (carve-out
  example)
- [pe-queue.md](pe-queue.md) -- the PE queue (carve-out
  example for jobs; the Queue itself is shape-compliant)
- [rpg.md](rpg.md) -- skills (95% compliant; the closest to
  the reference shape)
- [lifecycle.md](lifecycle.md) -- shutdown sequence (0%
  compliant today; refactor target)
- [settings.md](settings.md) -- generic-over-consumer pattern
  (shape-compliant via composition)
- [`endless/docs/k8s.md`](https://github.com/abix-/endless/blob/dev/docs/k8s.md)
  -- the source pattern
