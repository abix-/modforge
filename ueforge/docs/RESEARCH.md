# ueforge Research Methodology

> **Authoritative on:** how to investigate "why does X happen" in
> a running UE5 game when you have only an SDK dump and ueforge.

Audience: anyone debugging a UE-mod feature, hunting a regression,
or reverse-engineering a game system. Read before you start
guessing.

## The principle: research is code, not curl

Every experiment becomes a test file under `<mod>/tests/explore_*.rs`
that drives the live game through the `/debug` HTTP endpoint and
asserts on the response. Curl-and-eyeball doesn't survive a
restart, doesn't catch regressions, doesn't compose.

Your investigation is one binary per question. The answer is
"the test passes." The test stays in the tree as a fence: anyone
who breaks the underlying behavior trips the same assertion
the next time CI runs.

This is the same shape as the `runtime-control-http` skill's
cross-project rule -- this file is the UE-mod-specific concrete
walk.

## The TDD loop

For every feature, every bug, every research question:

1. **Concrete user-observable expectation.** Phrase it as: "if I
   do X then Y must happen." If you can't phrase it, you don't
   know what you're researching.
2. **Snapshot field for the observable.** Add a field to the
   game's `Snapshot` struct that exposes the observable -- a
   live HC field, an inventory size, a status-effect list, a
   counter delta. If the snapshot can't show the observable,
   add it before going further.
3. **Failing test.** Write `tests/explore_<scenario>.rs` that
   drives the endpoint, snapshots state, asserts the
   expectation. It must fail today.
4. **Probe through the endpoint.** Use the built-in ops
   (`read_bytes`, `walk_class`, `inspect_address`, `call`,
   `freeze`, `scan_memory`) to find out what the game is
   actually doing. Each probe is a few lines of test-side code
   plus assertions.
5. **Form a hypothesis.** "X happens because field Y at offset Z
   on class W has value V." Write it as code that the test
   verifies.
6. **Implement the fix.** Once the hypothesis explains the
   behavior, write the fix in the mod. The implementation is
   usually small -- the research was the work.
7. **Test goes green.** Land the test, the snapshot field, the
   op (if any), and the fix in one commit.

The fence stays. Anyone breaking the behavior trips it.

## Standard probes

Every UE-mod investigation reaches for these. ueforge ships them
under [`ueforge::ops`] and via the built-in dispatcher in any
mod's `/debug` endpoint.

### `walk_class { class, max?, include_cdo? }`

Lists every instance of a class in GObjects with its address and
full name. First step in any "where is this thing" question.

### `read_bytes { instance_selector, offset, length }`

Raw byte read at an address. Combined with the SDK headers (offset
of `Foo.Bar`), this answers "what's the live value of `Bar` on
this instance right now."

### `inspect_address { addr }`

Walks the UClass property chain and returns named field values at
their offsets. Great for "I have a UObject pointer and want to
see what's in it" without writing parm structs by hand.

### `call { class, function, instance_selector, parms_hex }`

Invokes any UFunction on any object with arbitrary parm bytes.
Replaces every `simulate_*` op a mod might be tempted to ship --
tests build their own parm struct, hex-encode, send. Engine-mutated
OUT params come back in the response.

### `scan_memory { type, value }` + `scan_rescan` + `freeze`

Cheat-Engine-style scan. Use when no SDK header tells you where a
field lives. Walks committed regions for an integer / float
value, narrows on rescan, freezes a chosen address. Validated
against `VirtualQuery` per write so a UE-recycled allocation can't
fault the game.

### `freeze { selector, offset, type, value }`

Selector-relative freeze. Resolves the selector each tick so a
multi-minute freeze on a recycled allocation re-acquires instead
of writing to stale memory.

## The five probe types in order of leverage

When researching an unknown system, work through these in order
before guessing:

1. **SDK header search.** `grep` for the field name in the dumped
   class headers (`<game>\Binaries\Win64\ue4ss\UEHeaderDump\`).
   90% of UE field-research questions answer here.
2. **Run-time UClass property walk.** `inspect_address` on a
   live instance shows the actual values at the known offsets.
   Answers "is this field non-zero / what's its current value."
3. **PE event capture.** Hook the suspected UFunction with
   `ProcessEventHook`, log every fire with parm bytes + `this`
   classname + caller. Answers "when does this fire and with
   what."
4. **Memory scan.** Find the address by value when no header
   tells you where. Cheap on UE5 because committed regions are
   small relative to the full address space.
5. **Native disassembly.** Last resort. Cheat Engine's "what
   accesses this address" / "what writes to this address" or a
   debugger conditional breakpoint.

Stop at the lowest-leverage probe that answers the question.

## Doctrine: status effects and data tables

Every investigation that touched UE5 game stats hit this pattern.
Copying the lessons here so the next mod doesn't waste a
two-day spike:

- **DataTable reads return copies.** Game code calls
  `GetDataTableRow` and gets back a struct *by value*. Mutate the
  source DT and pre-existing actors that already read the row
  see the old value. Mutate from `on_unreal_init` BEFORE any
  consumer reads the row, or hook the UFunction that reads to
  intercept at call-site.
- **Status effects are usually row-driven.** A `UStatusEffect`
  often holds a `FDataTableRowHandle` and reads `Type` / `Value`
  from the row. So mutating the row mutates every effect built
  from it; allocating a fresh effect with a different value
  requires either injecting a new row or finding an unused one.
- **Damage flows through type filters.** Native damage code
  consults a "required damage type flags" mask before applying
  damage. If you set the mask, you also block healing effects
  that route through the same gate (the bandage regression).
  Always test that consumable heals still work after touching a
  damage gate.
- **Most game stats route through one canonical component.**
  Status effects, perk effects, gear bonuses all go through
  `UStatusEffectComponent` (or the game's analogue) at a stable
  offset on the player. Find that component -- everything else
  flows from it.

## Doctrine: damage paths

There are typically three damage paths in a UE survival game,
and they don't all use the same UFunction:

1. **Combat damage** -- creature hits, weapon hits. Routes
   through `ApplyDamage` (or the game's wrapper) with non-zero
   type flags. Hooks here see player kills.
2. **Fall damage** -- separate native code reading
   `CharMovementComponent.Velocity.Z` in `OnLanded` or its
   equivalent. Mitigate via velocity-stomp before native code
   reads.
3. **Environmental / hazard damage** -- often goes through the
   same `ApplyDamage` as combat but with `type_flags = 0`.
   Mitigate by intercepting before the damage gate -- not by
   blocking the gate, which also blocks heals.

Read the SDK headers for the damage code in your specific game
before assuming any one path mitigation covers all three.

## Doctrine: instigator resolution

Player-dealt damage attributes via
`LastDamageInfo.InstigatorController.Pawn`. This is a
`FWeakObjectPtr`, two i32s. When the game replicates damage from
a remote actor, the weak pointer can be null/zero -- which
resolves to `/Script/CoreUObject (Package)` (a CDO with index 0).
So a kill that's clearly from the player can attribute to "the
package." The g2rpg pkg(0) bug is exactly this.

Workarounds:

- Hook `ApplyDamageFromInfo` ahead of the multicast and cache
  the `(HealthComponent, FDamageInfo)` pair locally. When the
  multicast fires with KillingBlow, prefer the cached value if
  the multicast's `LastDamageInfo` is null.
- Heuristic fallback: if the dying actor is in attack range +
  the player swung a weapon recently, attribute to the player.

## Doctrine: when to mutate at install vs. when to hook

- **Mutate at install** when the value is read once-per-
  whatever-it-is and consumers cache it. Survival drain rates,
  item stack sizes, gear damage multipliers. The mutation is
  cheap and lasts for the session.
- **Hook the UFunction** when the value is read on every fire
  from a fresh DT row, OR when other actors have already cached
  the old value before you got there. Damage gating, status
  effect application.

If install-time mutation looks right but the in-game effect
doesn't propagate, you're seeing the cache problem. Switch to
hooking.

## Doctrine: validate via the snapshot, not the log

Logs are write-only history; you have to read them, eyeball
patterns, hope you catch the right line. The snapshot endpoint
gives a queryable, structured view of *current* state.

For every mutation the mod can perform, the snapshot must
expose the observable that proves it landed. If you can't see
the change in the snapshot, you can't write a regression test
for it -- and the test you can't write is the regression you
will ship.

This is non-negotiable: every read worth introspecting is a
snapshot field. Logs are diagnostic, not authoritative.

## Doctrine: failure-injection tests

Every error path that can fail at runtime needs a test that
forces the failure. Disk-full saves, missing classes, stale UE
runtime, malformed args, port collisions. ueforge's
`SlotStore::save` returning `Result` (kovarex P0) exists
specifically so the test side can force a failure and assert on
the surfaced error.

Don't ship code without the failure test. The bug you didn't
test is the bug the user finds.

## The research notebook

Each mod keeps a per-feature investigation log alongside the
code. Use it as the cross-link between the SDK headers, the
hypotheses, the failed approaches, and the eventual fix.
`docs/damage.md` in grounded2-rpg is the canonical shape:

- One header per feature / regression.
- "What we know" -- citations into SDK headers, file:line.
- "What didn't work" -- approaches tried + why they failed.
- "What works" -- the validated mechanism + a snapshot of the
  endpoint output proving it.
- "Migration / follow-ups" -- where the fix could move next.

Documentation that lives next to the code stays correct because
the next person reading the code reads the doc. Documentation in
a wiki rots.

## Skill cross-references

- [`runtime-control-http`](~/.claude/skills/runtime-control-http/SKILL.md)
  -- the cross-project pattern for command-shaped endpoints,
  TDD-first workflow, and the test coverage principle. Read first
  if you're new to this style.
- [`ueforge/PERFORMANCE.md`](PERFORMANCE.md) -- hot-path discipline.
  Companion to this file -- research informs implementation, but
  implementation has to meet the perf bar before it ships.

## Closing rule

Every bug is a missing test. When a regression is found, the
test goes in BEFORE the fix. The test stays as a fence forever.
That's how 10 years pass without a code update.
