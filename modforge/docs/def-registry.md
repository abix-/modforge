# Def -> Registry -> Instance -> Controller

> The universal four-role pattern every modforge / ueforge /
> unityforge subsystem follows. Borrowed from Kubernetes CRDs
> and adapted for in-process mod frameworks.

The problem this solves: every subsystem (skills, hooks, ops,
selectors, status effects, data assets, shutdown handlers,
tabs, ...) independently invents its own "schema + storage +
instance + behavior" shape. Drift makes "how do I add a new X"
answer differently for every X. This contract defines the
shape once.

## The four roles

| Role | What it is | Example |
|---|---|---|
| **Def** (CRD) | Schema. A `struct` declaring the fields a kind has. Static, immutable, no runtime state. | `SkillDef`, `OpDef`, `SelectorDef`, `HookDef` |
| **Registry** (etcd) | Collection of Defs. A `&'static [<Subject>Def]` const + a lookup. One entry per kind. | `SkillRegistry`, `OP_REGISTRY` |
| **Instance** (CR) | One runtime object derived from a Def. Storage varies (mutex<HashMap>, per-subject state, etc). | `SkillsState.skill_levels[id]` |
| **Controller** | Function/system that reads Def + writes Instance. Reconciles when inputs change. | `Tracker::apply_one`, `OpRegistry::dispatch` |

## Key rule

The Def is the source of truth. Controllers read fresh values
from the Def at every reconcile. Instances never cache Def
fields. If the Def changes (a new module ships with a
different base value, a hot reload swaps catalog rows), the
next reconcile picks it up.

## Naming contract

Pick one shape per role and stick with it across every
subject.

| Role | Naming |
|---|---|
| Schema struct | `<Subject>Def` (`SkillDef`, `OpDef`, `HookDef`, `SelectorDef`, `ShutdownHandlerDef`). **Always Def-suffixed; no exceptions** |
| Discriminator | `<Subject>Kind` enum where the set is closed; `&'static str` id where it is open-ended. Field is always `kind` / `id`, never `name` / `job` / `activity` |
| Registry wrapper struct | `<Subject>Registry` holding `entries: &'static [<Subject>Def]` plus any registry-level config |
| Registry instance | `<SUBJECT>_REGISTRY: <Subject>Registry` (static const) for closed-set framework-owned registries, or per-mod `static CATALOG: <Subject>Registry` |
| Lookup method | `<Subject>Registry::def(&self, key) -> Option<&'static <Subject>Def>` |
| Tracker (stateful subjects) | `<Subject>Tracker`. Holds inner state, persists, reconciles |
| Module-level controller (stateless subjects) | bare functions: `apply_skill`, `place_building`, `dispatch_op` |

## Static registries of Drop-having types

When a Def carries non-Copy state with a non-trivial Drop
(mutexes, atomics, owned heap), const-eval rejects a
temporary array literal:

```rust
// E0493: destructor of [StackDef; N] cannot be evaluated at compile-time
pub static STACKS: StackRegistry =
    StackRegistry::new(&[StackDef::new(...)]);
```

The clean pattern: declare each Def as its own named `static`
and store `&[&'static <Subject>Def]` in the registry.
References are `Copy` + `Drop`-free, so the slice literal
const-evaluates:

```rust
static MATERIALS_DEF: StackDef = StackDef::new("materials", ...);

pub static STACKS: StackRegistry =
    StackRegistry::new(&[&MATERIALS_DEF]);
```

Drop-free Defs (Skills, Tabs) MAY use the simpler
`&[<Subject>Def]` (slice of values). Pick based on whether
the Def has Drop-having state.

## K8s slot comments

Every subsystem's module doc carries a one-line slot
declaration:

```rust
// K8s slot: Def=SkillDef, Registry=CATALOG,
//           Instance=SkillsState.skill_levels,
//           Controller=Tracker
```

Grep for `K8s slot:` across the codebase to confirm no
subject lost its place.

## What does NOT fit

Not every piece wants to be a CRD. Counters (one
`AtomicU64` per call site), PE-queue jobs (each is an
anonymous closure), and the Settings struct (the consumer's
own struct IS the Def) are carve-outs. The shape is
documented when carved out; the carve-out is not a free pass.

## Carve-outs follow the rest of the conventions

Drop ordering, `shutdown_all` registry, naming, all apply
even to subjects that don't have a CRD shape.
