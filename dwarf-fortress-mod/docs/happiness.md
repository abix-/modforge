# Native happiness explanation

## Operator requirement

Make fortress happiness understandable before changing it. For every living
citizen, explain what the game currently records, why the citizen is stressed
or unfocused, and what normal player action could help.

The first version is read-only. It must not erase stress, fill needs, rewrite
personality, or manufacture positive thoughts.

## Native model

Dwarf Fortress does not have one independent "happiness" value. DFHack derives
a stress category with `dfhack.units.getStressCategory(unit)`. Relevant native
state includes:

- `unit.status.current_soul.personality.stress`;
- `unit.status.current_soul.personality.longterm_stress`;
- `current_focus` and `undistracted_focus`;
- current needs, their strength, and focus values;
- recent emotions and their source thoughts;
- personality facets, values, preferences, and relationships;
- trauma and combat hardening;
- physical or environmental conditions that generated thoughts.

DFHack 53.16 uses stress cutoffs `50000`, `25000`, `10000`, `-10000`,
`-25000`, `-50000`, and `-100000` for its native categories. These categories
are labels over stress, not a second happiness system.

Needs and stress are related but not interchangeable. An unmet need reduces
focus; emotions and experiences contribute to long-term stress. A useful report
must preserve that distinction.

## First report

For each living fortress citizen:

1. Name, unit ID, profession, squad, and current activity.
2. Raw long-term stress and DFHack's native stress category.
3. Unmet needs ordered by current focus loss and need strength.
4. Recent negative and positive emotions with native thought type, severity,
   age, and referenced person, item, place, or event when available.
5. Personality facets or values that amplify those experiences.
6. Actionable observations, each linked to the native evidence that produced
   it.

Fortress-wide output should group shared causes. For example, it should say
that twelve citizens have a strongly unmet prayer need rather than presenting
twelve disconnected rows.

For needs, `need_level` describes strength and `focus_level` describes current
satisfaction. A negative focus is clearly unmet; a focus below the freshly
satisfied value of `400` must not automatically be labeled unmet.

Visible emotion entries contain `type`, `thought`, `subthought`, `severity`,
`strength`, `relative_strength`, `year`, and `year_tick`. Their severity and
the emotion type's divider can estimate a stress contribution, but summing
visible emotions does not reconstruct current stress exactly. Decay,
long-term stress, and overcome memories make that inference lossy and it must
be labeled as an estimate.

## Existing tools and why another view helps

- `allneeds` summarizes needs by focus, strength, frequency, or ID.
- `gui/unit-info-viewer` exposes detailed unit information.
- `fillneeds --all` and `remove-stress --all` can overwrite symptoms.
- `modtools/set-need` can edit need focus and strength.

The goal is not another cheat command. It is one evidence-backed explanation
that joins stress, needs, emotions, thoughts, and personality while leaving
the simulation untouched.

## Research questions

- Which current emotion fields encode strength, divider, flags, and age?
- Which thought types retain resolvable references to their cause?
- How does the game decay or amplify long-term stress in version 53.16?
- Which personality facets alter stress response or need strength?
- Which apparent recommendations can be derived reliably, and which must be
  labeled as hypotheses?
- Can a snapshot be captured quickly enough without stalling a large fortress?

## Acceptance

- Inspection performs no writes to DF state.
- Every conclusion includes its source field or native event.
- Unknown thought references are shown as unknown, not guessed.
- Per-citizen and fortress-wide reports complete within a measured budget.
- Reports remain useful with hundreds of citizens.
- Any future automatic happiness changes are separate, explicit settings.

## Sources

- [DFHack `allneeds`](https://docs.dfhack.org/en/53.16-r1/docs/tools/allneeds.html)
- [DFHack Lua API](https://docs.dfhack.org/en/53.16-r1/docs/dev/Lua%20API.html)
- [DFHack `fillneeds`](https://docs.dfhack.org/en/53.16-r1/docs/tools/fillneeds.html)
- [DFHack `remove-stress`](https://docs.dfhack.org/en/53.16-r1/docs/tools/remove-stress.html)
- [DFHack `modtools/set-need`](https://docs.dfhack.org/en/53.14-r2/docs/tools/modtools/set-need.html)
