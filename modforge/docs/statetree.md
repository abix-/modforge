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

**Selection only when a transition fires.** Each think the active tasks
run and the transitions are checked; nothing is chosen again unless a
transition fires. A person walking to a well keeps walking to the well.

**Failure goes up.** A task that fails with no transition of its own
for failure hands the failure to its parent's transitions, up to the
root, where the person chooses again.

## What topside's tree holds

The tree is data (topside's content), the running is modforge's:

- The root, in order: hide (the storm), flee, break off, fight, then the
  day's life. Transitions on the root take a person out of the day's
  life when a hostile is seen or the storm comes.
- The day's life, weighted by learned value: eat what they carry, go to
  what answers a need, supply the bunker, look, wander.
- Each of those is going, then doing: going walks the way the pathing
  queue found (docs/pathing.md), doing eats, drinks, checks, takes, or
  stocks. Going succeeds on arriving; a way the queue could not find
  fails it, and the person chooses again.

## Open

- Whether the root's order (the storm, fleeing, fighting) can be
  learned away. topside life.md "Learning to stay alive" lets learning
  overturn instinct by more than a minute's worth; every game above
  keeps these fixed.
</content>
</invoke>
