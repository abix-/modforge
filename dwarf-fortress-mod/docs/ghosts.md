# Ghost suppression

## Operator requirement

When a fortress citizen dies, they stay dead. The player must not need a
coffin, tomb, burial, engraved slab, memorial, or new tunnel to prevent
haunting. A mass-casualty event must not create twenty cleanup chores.

This feature removes ghosts, not death. Corpses, death records, relationships,
combat consequences, and ordinary reactions to death remain vanilla unless
later evidence shows that one must change to suppress haunting.

## Current evidence

Dwarf Fortress represents an active ghost on the unit:

- `unit.flags3.ghostly` identifies ghost status.
- `unit.flags2.killed` remains the ordinary killed-state flag.
- `unit.ghost_info` and `unit.ghost_type` hold ghost-specific state.
- `unit.counters.death_id` links to the death incident.
- `unit.hist_figure_id` links to the historical figure.
- `dfhack.units.isGhost(unit)` is the supported Lua predicate.
- Legacy DFHack's `tweak clear-ghostly` implementation cleared
  `flags3.ghostly` and set `flags1.inactive`. That command is absent from the
  DFHack 53.16 `tweak` plugin.

No supported DFHack field or operation means "spiritually settled without a
burial or memorial". `autoslab`, `burial`, and `entomb` automate the vanilla
physical chores and do not meet this requirement.

DFHack exposes the event-driven `UNIT_NEW_ACTIVE` event as
`eventful.onUnitNewActive(unit_id)`. The 53.16 event manager builds the list
of newly active unit IDs, then invokes the callbacks. This is a candidate
interception point because a new ghost has entered the active-unit list but
can be retired in the same DFHack update.

`UNIT_DEATH` is also polling-derived. It fires only after a formerly active
unit is inactive and `dfhack.units.isDead(unit)` is already true. Ghosts can
appear months after death, so this event can remember which unit IDs were
citizens but cannot prevent the later ghost transition.

The legacy command documented its own behavior as a dirty recovery tool that
might not have all effects of a proper burial. Copying those two writes is
therefore a research candidate, not a maintained or accepted production
implementation.

## Candidate approaches

### 1. Prevent ghost creation

Find and intercept the native decision that turns an eligible dead historical
figure into a ghost. This most directly matches the requirement and avoids
constructing a ghost even briefly.

DFHack exposes no identified `createGhost` virtual method or normal-haunting
function. True prevention therefore requires live reverse engineering of the
code that sets `flags3.ghostly`, creates `ghost_info`, and activates the unit.
A version-specific C++/modforge detour is justified only after that path is
captured. Do not guess a signature or assume that the supernatural
`interaction_effect_raise_ghostst` owns normal fortress haunting.

### 2. Retire a newly activated ghost

Register `eventful.onUnitNewActive`, resolve the unit ID with `df.unit.find`,
check `dfhack.units.isGhost(unit)`, and immediately perform the proven
retirement transition. `isCitizen()` cannot be used here because dead and
ghostly units are intentionally not classified as current citizens.

The prototype should remember the IDs of current citizens and update that set
from `UNIT_DEATH`. `dfhack.units.isOwnGroup(unit)` is useful corroboration,
but retaining the citizen ID prevents a visitor or invader ghost from being
changed accidentally. This is likely sufficient as a Lua prototype and avoids
polling the whole unit list.

This is prompt post-creation suppression, not literal prevention. Public source
does not prove that every native ghost transition emits `UNIT_NEW_ACTIVE`, so
the live research test must establish that before this becomes the production
path.

The implementation must not affect:

- living citizens;
- visitors or invaders;
- animated corpses, intelligent undead, or necromancer creations;
- non-citizen ghosts unless the operator expands the requirement.

An enable/load pass may inspect existing active units once to retire ghosts
already present in a save. Repeating whole-world scans are forbidden.

Do not clear `flags2.killed`, remove the historical figure, alter civ or entity
links, fake `incident.flags.discovered`, or delete `ghost_info`. None of those
is an established memorial transition, and each risks corrupting history,
corpse ownership, or save state.

### 3. Add `CANNOT_UNDEAD` to the dwarf caste

A normal raw mod can patch `DWARF` with:

```text
[SELECT_CREATURE:DWARF]
    [SELECT_CASTE:ALL]
        [CANNOT_UNDEAD]
```

Older documentation says this prevents ghosts. Current documentation describes
the token as behaving like `NOT_LIVING` except for hostility from
`OPPOSED_TO_LIFE` creatures. That wording implies possible unrelated effects.
It also may require a newly generated world or a runtime raw edit to affect an
existing fortress.

Do not ship this shortcut until a controlled test proves normal citizen needs,
emotions, illness, aging, relationships, hostile-undead behavior, and
necromancy remain acceptable.

## Required research

1. Record a dead citizen's incident, historical figure, and unit state before
   ghost creation.
2. Use DFHack's event test tooling to prove every tested vanilla ghost
   transition emits `UNIT_NEW_ACTIVE` before the ghost affects gameplay.
3. Capture every changed field when vanilla creates the ghost.
4. Retire one disposable-save ghost using the minimal state transition and
   save/reload twice.
5. Verify no ghost appears in the unit list, announcements, relationships, or
   active-unit collection.
6. Repeat with twenty dead citizens and prove zero burial or memorial jobs are
   required.

## Acceptance

- Zero active citizen ghosts after deaths or save load.
- Zero coffins, tombs, slabs, memorials, or burial jobs required.
- Deaths and corpses remain recorded normally.
- No periodic whole-world scan.
- No save corruption across repeated save/load.
- A setting can disable the behavior and leave vanilla rules intact.

## Sources

- [DFHack eventful client](https://docs.dfhack.org/en/53.16-r1/docs/tools/devel/eventful-client.html)
- [DFHack Lua unit API](https://docs.dfhack.org/en/53.16-r1/docs/dev/Lua%20API.html)
- [DFHack 53.16 eventful bridge](https://github.com/DFHack/dfhack/blob/53.16-r1/plugins/eventful.cpp)
- [DFHack 53.16 event manager](https://github.com/DFHack/dfhack/blob/53.16-r1/library/modules/EventManager.cpp)
- [Legacy DFHack `tweak clear-ghostly` source](https://github.com/DFHack/dfhack/blob/7ea44010e084c2b4b03d08f4d97324137bbaefd1/plugins/tweak/tweak.cpp)
- [DFHack `autoslab`](https://docs.dfhack.org/en/53.16-r1/docs/tools/autoslab.html)
- [DFHack `burial`](https://docs.dfhack.org/en/53.16-r1/docs/tools/burial.html)
- [DFHack `entomb`](https://docs.dfhack.org/en/53.16-r1/docs/tools/entomb.html)
- [Current creature tokens](https://dwarffortresswiki.org/index.php/Creature_token)
- [Current ghost behavior](https://dwarffortresswiki.org/index.php/Ghost)
