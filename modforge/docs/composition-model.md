# Composition model: Effects + Triggers + Skills

> Engine-agnostic. Same vocabulary on both sides.

The rule that makes the whole stack worth its weight:

> Each thing we research and figure out how to do in the game is
> an **Effect**. A **Skill** is one Effect applied with parameters.
> **Triggers** tell us WHEN to fire an Effect.
>
> If we do this generically we only have to do each one of the
> things ONCE.

Three concerns. Three vocabularies.

## Effects (the verbs)

An Effect is one reusable operation we figured out how to
perform in the game: write an `f32` at an offset on a class
default object, scale a set of movement fields, mutate a data
table row + invoke a status-effect spawn, heal a health
component via a method call, etc. Each Effect is:

- A **type** that implements the `Effect` trait
  (the operation's shape: "scale these fields by
  `1 + max_bonus * progress`").
- **Parameterized** per use (instances carry the offsets, the
  base, the max_bonus, the class refs).
- **Researched once, used everywhere.** A new game adopts the
  framework's Effect library; it only needs new Effect types
  when the game has an operation no other game shares.

## Skills (the products)

A Skill is a player-facing upgrade slot: id, display name,
max level, and an Effect. Same `Skill` type across every game.
Adding a Skill is one catalog row that picks an Effect and
supplies its parameters. The Skill never touches the game
world directly; it owns leveling + persistence + UI; it
delegates the actual writes to its Effect.

```rust
SkillDef {
    id: "attack_damage",
    display_name: "Attack Damage",
    max_level: 100,
    effect: EffectDef::new("PlayerFloat", &ATTACK_DAMAGE_FLOAT),
    trigger: &ON_SLOT_CHANGE,
}
```

`ATTACK_DAMAGE_FLOAT` is a `static PlayerFloatEffect` with
`(offset: 0x12B8, base: 1.0, max_bonus: 3.0, format: ...)`.
The Effect type is shared with every other PlayerFloat skill
(Armor, etc.); only the parameters differ.

## Triggers (the WHEN)

A skill needs to know WHEN to fire its Effect. That's the
Trigger. Some triggers are passive (`OnSlotChange`: fires when
the player levels up / spends / refunds / toggles); others are
event-driven (`OnDamageDealt`, `OnKill`, `Periodic`).

`TriggerDef { kind, imp: &'static dyn Trigger }` is the Def,
symmetric with `EffectDef`. Each trigger TYPE is a struct that
owns its own wiring: filter, decode, subscriber list.

## Hooks vs Triggers

Different layers, different responsibilities:

- **Hook**: the mechanism. A vtable patch on a UE class; a
  HarmonyLib patch on a Mono method. Low-level. Plumbing.
- **Trigger**: the semantic event source. Built on top of
  zero or more Hooks plus filter + decode + typed event
  dispatch.

N:M between hooks and triggers. One trigger may install
hooks on multiple classes. One hook may serve multiple
triggers. Some triggers (`Periodic`, `OnSlotChange`) install
no hooks at all.

## The "do it once" rule

When we figure out how to mutate, say, a status effect by
walking a data table + calling a spawn function, that work
lives in **one** `StatusEffectApply` Effect type. Every
game's status-effect skills then differ only in
`(table_path, row_id, value_at_max)`: catalog row data. We
do not research the operation again; we do not write the
apply path twice.

Same for Hooks: the damage-event decode + Player/Other
classification + before/after dispatch lives once in
`damage::DamageHook` per framework. Every game's damage-
driven skills plug into it.

If you find yourself re-writing the same operation in two
places, the operation should have been an Effect. If two
games' skills differ only in parameters, the Effect type
already covers both. Only the catalog rows change.
