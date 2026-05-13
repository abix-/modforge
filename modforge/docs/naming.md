# Naming conventions

> Both frameworks follow these. Reviewers grep these patterns
> to confirm a new subsystem fits.

## Modules

- `snake_case` per Rust default.
- Plural for collections (`hooks`, `ops`, `selectors`).
- Singular for traits + types in their own module
  (`effect`, `trigger`, `skill`).

## Types

- `<Subject>Def` for schema structs. Always Def-suffixed.
- `<Subject>Registry` for collections.
- `<Subject>Tracker` for stateful controllers.
- `<Subject>Instance` (rare; usually replaced by per-subject
  state struct).
- Traits: capitalized noun (`Effect`, `Trigger`, `Hook`).
- Trait objects: `&'static dyn Effect`, `Box<dyn Effect>`.

## Constants

- `SCREAMING_SNAKE_CASE` for `static` registries:
  `OP_REGISTRY`, `HOOK_REGISTRY`, `CATALOG`.
- Per-mod catalog: `static CATALOG: SkillRegistry = ...`.

## Functions

- Lookup: `registry.def(key)`.
- Register: `registry.register(def)`.
- Dispatch: `registry.dispatch(name, args)`.
- Apply: `controller.apply(...)` or bare `apply_x(...)`.
- Init: `register_builtins()` for framework-supplied entries.

## File names

- One major struct per file: `effect.rs`, `trigger.rs`,
  `skill.rs`. Re-exports through `mod.rs`.
- `mod.rs` declares the submodules and the public surface
  via `pub use`.

## Op names

- `snake_case`. `walk_class`, `inspect_address`,
  `read_field`, `skill_levelup`.
- Verb + noun.
- Same name across both frameworks when the semantics match.
- New names where the semantics differ
  (`read_bytes` for UE raw memory vs `read_field` for managed).

## Selector prefixes

- `snake_case:` form. `class:`, `first_class:`,
  `singleton:`, `static_instance:`, `monobehaviour:`.
- Universal forms are reserved (`addr:`, `class:`,
  `first_class:`, `singleton:`); per-framework and per-game
  selectors extend.

## Logging

- One line per event. `mod_name: action: outcome` shape.
- Framework prefix: `modforge:`, `ueforge:`, `unityforge:`.
- Game-mod prefix: the mod's name.
- No multi-line log entries unless dumping structured data.
