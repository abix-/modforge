# Mechabellum changelog

## Changelog rules

- Each day has exactly one `## YYYY-MM-DD` heading and exactly one table below
  it.
- Every daily table has exactly three columns: `System`, `Item`, and
  `Done when`.
- Start every Item with `[x]`. No preceding hyphen. Changelog rows are
  completed work only.
- Never combine completed items into one changelog row.
- Put new days above older days.

## 2026-11-07

| System | Item | Done when |
|---|---|---|
| Mod | [x] Set up mechabellum-mod: MelonLoader installed, shim and mod deployed by `scripts/restart.ps1` | Latest.log shows `mechabellum-mod: ready (runtime=Il2Cpp), http on port 17184`; `research_load` passed |
| Research | [x] List the game's own assemblies and their types | `research_types` passed; counts in `docs/research.md` |
