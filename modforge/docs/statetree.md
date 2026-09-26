# StateTree: how a person decides

> **Status:** design, no code yet (2026-09-26). The brain's one way to
> decide, built in modforge as plain data and one function, tested
> without a game. It replaces how `brain::choose` decides today; it is
> never a second brain beside it. First user: topside (its life.md
> "The brain").

## Why

Topside's brain offers every rule on every think and lets what the
person learned pick among all of them, fleeing and the storm included.
A person walking to a well re-chooses every second, and "arrived" is one
general rule in front of everything. Endless had the same brain and had
to take it out (endless docs/npc-activity-controller.md: "do not keep a
generic 'Priority 0: arrived => handle activity' branch ahead of all
state logic").

## Who solved it

- Unreal Engine StateTree (Epic): "a general-purpose hierarchical state
  machine that combines the Selectors from behavior trees with States
  and Transitions from state machines". This doc is its model.
- RimWorld: a constant think tree that overrides the current job, and a
  main think tree asked for the next job when the current one ends. A
  job runs as toils, one at a time, in order.
- Halo 2 (Damian Isla, GDC 2005): higher priorities "can always
  interrupt"; score tuning across twenty or more choices "is almost
  impossible".
- F.E.A.R. (Jeff Orkin, GDC 2006): a small state machine (Goto, Animate)
  runs what the planner chose; a blocked door goes into working memory
  and the planner chooses again.
- Kevin Dill, Dual-Utility Reasoning (Game AI Pro 2): rank first (only
  the most important category is considered), then weighted random
  within it.
- Black & White (Richard Evans): what the creature learned picks how to
  meet a desire.

No Rust or Bevy crate is a StateTree. The Bevy AI crates (seldom_state,
bevy_behave, big-brain, bevy_observed_utility, bevy_dogoap, beet) are
each one piece and build the brain from Bevy entities; modforge stays
engine-free.

## How it works

**States.** The states form a tree. A parent state groups its children.
What a person is doing is one path from the root down to one leaf: the
leaf and every parent above it are active.

**Tasks.** A state has tasks: the work it does while active (walk to the
well, drink, sleep). A task starts when its state is entered, runs each
think, and stops when its state is left. Each think a task answers
running, succeeded, or failed.

**Enter conditions.** A state may say when it can be entered (a need
below the line, a hostile in sight, the storm coming). A state whose
conditions fail is never entered.

**Selecting a state.** Selection starts at a state and walks down to a
leaf. How a parent tries its children is set per parent:

- In order: the first child whose enter conditions pass. Used where the
  answer is never a matter of taste (the storm before a fight before the
  day's life).
- Weighted by learned value: every child whose enter conditions pass is
  a choice, and what the person learned (modforge `learn`) weighs them.
  Used where there is a real choice (eat, drink, look, supply the
  bunker, wander).

**Transitions.** A state has transitions: when to leave and where to
go. A transition fires when its state's task succeeds, when it fails,
or when its condition holds (checked every think). Transitions are
checked from the leaf up to the root, and the first that fires wins. A
transition on a parent therefore covers every state under it: the storm
coming, on the root, takes a person out of anything.

**What the tree remembers.** Each person's tree keeps its own record
between thinks, and it is the one record of what they are doing: the
active state and each active state's data (which well, where, for which
need; who they fight and where the fight began). Unreal keeps the same
per running tree (its instance data). Nothing beside the tree remembers
what a person is doing: today's `Activity` and `CombatState` move out of
`brain.rs` into the StateTree as its record, and are deleted from
`brain.rs` (operator, 2026-09-26). The consumer stores the record on
the person and hands it back each think, and reads it to show what they
are doing.

**Selection only when a transition fires.** Each think the active tasks
run and the transitions are checked; nothing is chosen again unless a
transition fires. A person walking to a well keeps walking to the well.

**Failure goes up.** A task that fails with no transition of its own
for failure hands the failure to its parent's transitions, up to the
root, where the person chooses again.

## What topside's tree holds

The tree is data (topside's content), the running is modforge's:

All of the brain is this one tree, fighting included; nothing decides
beside it (topside content/src/brain.rs).

- The root is flat (operator, 2026-09-26): every choice sits directly
  under it, and what the person learned picks among all of them, the
  storm and fighting included (topside life.md "Learning to stay
  alive"). With nothing learned, instinct's order decides: hide (the
  storm), flee, break off, fight, eat what they carry, go to a need,
  supply the bunker, look, wander. Learning overturns instinct only by
  more than its lead for each place in that order.
- Flee, break off, and fight are open when a hostile is in sight or a
  threat is remembered from the last few seconds: flee when hurt below
  their flee line (home, or away with no home), break off when chased
  past the leash (home, or back to where the fight began), fight (face
  it, close in, hit it). Fight succeeds when no hostile is in sight and
  none is remembered; flee and break off succeed on reaching safety.
  Getting hurt or chased past the leash mid-fight chooses again.
- The storm coming or a threat takes a person out of any errand to
  choose again.
- After a fight, or after any errand ends, the person chooses again from
  the root (operator, 2026-09-26). Nothing is held underneath to resume:
  if they are still thirsty and still remember the well, the choice
  sends them back to it; if the fight changed things, it may not.
  RimWorld does the same: an interrupted pawn is asked for its next job.
- Supply the bunker tries in order: haul home, fetch, look in a box,
  head out. Look tries in order: the nearest unchecked thing, head out.
- Each errand is going, then doing: going walks there, doing eats,
  drinks, sleeps, checks, takes, or stocks. Going succeeds on arriving.
  Still to build (topside todo): going walks the way the pathing queue
  found (docs/pathing.md), and a way the queue could not find fails it,
  so the person chooses again.
