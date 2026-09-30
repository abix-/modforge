# dwarf-fortress-mod open issues

| Priority | System | Todo | Done when |
|---:|---|---|---|
| 1 | `ghosts` | [ ] Prove the exact Dwarf Fortress 53.16 transition that creates an active ghost | A repeatable live research test kills or observes one citizen, identifies the triggering state change, and records the before/after unit and incident fields |
| 1 | `ghosts` | [ ] Retire newly activated citizen ghosts without burial or memorial work | An event-driven implementation leaves the dwarf dead, creates no active haunting unit, requires no coffin, tomb, slab, or job, and passes a 20-citizen casualty test |
| 2 | `ghosts` | [ ] Handle ghosts already active when the mod is enabled or a save loads | Existing citizen ghosts are retired once with an exact count, while living, undead, visiting, and non-citizen units are unchanged |
| 2 | `ghosts` | [ ] Compare runtime suppression with the `CANNOT_UNDEAD` dwarf-caste patch | A controlled save proves whether the token prevents ghosts and records every observed side effect on life status, necromancy, hostile undead, needs, and normal citizen behavior |
| 3 | `happiness` | [ ] Capture native stress, needs, emotions, thoughts, and personality data for every living citizen | A read-only research command returns named citizens with raw values and native enum names without changing game state |
| 3 | `happiness` | [ ] Explain why each citizen is unhappy in actionable terms | The report ranks current stress contributors and unmet needs, links them to recent thoughts or emotions, and distinguishes evidence from inferred advice |
| 4 | `happiness` | [ ] Add fortress-wide happiness priorities | One report groups shared causes, identifies how many citizens each cause affects, and ranks interventions without editing stress or needs |
| 5 | `tests` | [ ] Add save-safe live tests for ghost suppression and happiness inspection | Tests use a disposable save, skip clearly when Dwarf Fortress or DFHack is unavailable, and never mutate the operator's normal fortress |
