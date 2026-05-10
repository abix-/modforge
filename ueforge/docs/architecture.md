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
| Schema struct | `<Subject>Def` (`SkillDef`, `OpDef`, `BuildingDef`, `SelectorDef`, `ShutdownHandlerDef`, `TabDef`). Exception kept for back-compat: `Skill<E>` is the existing name; treat it as the SkillDef. |
| Discriminator | `<Subject>Kind` enum where the set is closed; `&'static str` id where it's open-ended. The field that holds it is always called `kind` (NOT `name`, `job`, `activity`). |
| Registry const | `<SUBJECT>_REGISTRY: &'static [<Subject>Def]`. Module-private if scoped to one module; `pub` at the framework level if external mods register into it. |
| Lookup fn | `<subject>_def(kind: <Subject>Kind) -> &'static <Subject>Def` for closed sets. `<subject>_def_by_id(id: &str) -> Option<&'static <Subject>Def>` for open sets. |
| Tracker (stateful subjects) | `<Subject>Tracker` -- holds the inner state, persists, reconciles. |
| Module-level controller (stateless subjects) | bare functions: `apply_skill`, `place_building`, `dispatch_op`. |

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
| **Hooks** (`ProcessEventHook`) | The "kind" would be the class name + handler closure, but every install is unique by definition. There's no shared schema across installs that a Def could capture -- handlers are user-supplied closures with no declarable shape. The existing `HookRegistry` is an *instance* registry, not a kind registry. |
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
| **Skills** | `Skill<E>` (`ueforge/src/rpg/skill.rs`) | per-mod `CATALOG: &[Skill<E>]` (`grounded2-rpg::CATALOG`, `outworld::CATALOG`) | `SkillsState.skill_levels[id]` | `Tracker<A>::apply_skill` via `RpgApplier` | **95%** | Naming: `CATALOG` should be `SKILL_REGISTRY`; add `skill_def(id)` lookup at the framework level; rename `Skill` -> `SkillDef` (or alias) |
| **StandardEffect variants** | `StandardEffect` enum (`ueforge/src/rpg/std_effect.rs`) | Variants ARE the registry (closed enum) | Inlined in each `Skill { effect: StandardEffect::... }` | `StandardEffect::apply` / `format` | **80%** | Registry is implicit (enum variants act as keys); each variant carries its parameters inline. Works, but no separate Def-to-instance split. Acceptable since variants are parameterized by `'static` data only. |
| **Bestiary** | `(&'static str, u32)` tuple (`ueforge/src/rpg/xp.rs`) | `Bestiary.table` field | per-kill XP value | `Bestiary::lookup` | **80%** | Tuple should be a named `BestiaryRow { class_name, base_xp }` struct so future fields (xp scaling per zone, cap level, ...) don't break the shape. |
| **Tabs** | `Tab { name, render }` (`ueforge/src/mod_main.rs`) | `MOD_INFO.tabs: &'static [Tab]` | imgui draw call per render | `ueforge_mod_render_tab` | **100%** | Reference implementation. Tiny but the pattern is exact. |
| **Buildings** (planned, not built) | `Building<S, C>` design in [todo.md](../../docs/todo.md) | `BuildingsCatalog` | `Instance<S>` per placed | `BuildingsTracker::tick` + `BuildingSpawner` trait | **designed-100%** | Lock the naming to the contract above before implementation. |
| **Status effects** (in-flight) | per-row in game-side `UDataTable` | game-side data table (read live, not a Rust const) | `UStatusEffectComponent` instances on UE actors | `StandardEffect::StatusEffect` apply path | **partial** | Def + Registry live in the GAME's data tables, not in our Rust code. The Rust side is a thin wrapper; the registry is the game's. Acceptable -- the alternative is duplicating the table -- but document the boundary explicitly. |
| **Debug ops** | nothing (op handlers are bare `fn`s) | hardcoded match arms in `ops::handle_builtin`, `debug::dispatch_standard_op`, `debug::dispatch_pe_ops` (3 places) | per-call args + return JSON | the dispatch fn | **30%** | Three match statements covering overlapping op-name spaces. `STANDARD_OPS: &[&str]` is a NAME list with no schema, no docs, no args description. New op = edit at least 2 files. **Highest-leverage refactor target.** |
| **Selectors** | nothing | hardcoded match in `selector::resolve_generic` (`addr:`, `class:`, `first_class:`, `singleton:`); per-game extensions are separate match in each game crate | resolved `&'static UObject` | the resolver fn | **30%** | New selector kind = edit `resolve_generic`. Cross-game extensions duplicate the dispatch shape. |
| **Shutdown handlers** | nothing | hardcoded sequence in the `ueforge_mod_shutdown` macro: `on_shutdown` -> `hook::shutdown_all` -> `server::shutdown_all` -> `settings::shutdown_all` -> `scanner::shutdown_sweeper_if_running` -> `finalize_hot_reload_swap` | per-call drop | the macro itself | **0%** | New module that spawns threads must edit the macro to register its cleanup. Easy to forget; the cost shows up as a hot-reload thread leak. |
| **Modules** (rpg / stacks / difficulty / inventory / damage / planned buildings) | nothing | implicit; each module has its own catalog + tracker + ops + tab without a shared shape | -- | -- | **n/a** | Possible meta-pattern: a `ModuleDef` that names which subsystems each module participates in. Defer until we feel the pain. |
| **Hooks** | n/a (carve-out) | `HookRegistry` (instance registry) | per-install `ProcessEventHook` | the trampoline | -- | Doesn't fit the pattern; see "What does NOT fit" above. |
| **Counters** | n/a (carve-out) | per-call-site statics | `AtomicU64` value | `bump` / `time_scope` | -- | Doesn't fit. |
| **PE queue jobs** | n/a (carve-out) | per-call closures | `Pending` | `Queue::drain` | -- | The Queue itself fits; jobs don't. |

## Highest-leverage refactor targets

In rough priority order. Each one collapses 2-3 hardcoded
match statements into a single registry append.

1. **Debug ops registry.** Lift `STANDARD_OPS` into
   `OpDef { kind, handler, args_doc, summary }` +
   `OP_REGISTRY: &'static [OpDef]`. Replace the three dispatch
   match statements with a single `dispatch(op_name, args)`
   that looks up the registry. Auto-generate a `list_ops`
   handler that returns the registry as JSON for client
   discovery. New op = 1 registry entry, no dispatch edits.
2. **Selectors registry.**
   `SelectorDef { prefix: &'static str, resolver: fn(&str, usize) -> Result<usize, String> }`
   + `SELECTOR_REGISTRY`. `resolve_generic` becomes a registry
   walk. Game crates can extend by registering their own
   prefixes (e.g. `live_player:`).
3. **Shutdown handlers registry.**
   `ShutdownHandlerDef { name, order: u32, run: fn() }` +
   `SHUTDOWN_REGISTRY`. The macro becomes "iterate registry
   sorted by `order`". Each module's first init call registers
   its cleanup; new modules can't forget the wiring.
4. **Buildings + status effects.** Both still in design /
   in-flight. Land them compliant from day one (no rework
   later).
5. **Skills cleanup.** Rename `CATALOG` -> `SKILL_REGISTRY`;
   add framework-level `skill_def(catalog, id)` (already
   `find_skill` -- alias and update naming). Cosmetic; cheap.
6. **`BestiaryRow` struct.** Replace the `(&str, u32)` tuple
   with a named struct so future fields don't reshape every
   consumer.

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
