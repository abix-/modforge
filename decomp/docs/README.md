# decomp docs

> **Authoritative on:** the `decomp` crate. Successor to
> `falcon-printer/` after the 2026-05-14 r2sleigh migration.
> The crate-level [`../README.md`](../README.md) is the
> one-page intro and quick-start; these files are the
> deeper rationale, the pipeline walkthrough, and the open
> ladder.

## Contents

| File | Subject |
|---|---|
| [polish-ladder.md](polish-ladder.md) | Open work for `decomp`. Different ladder from falcon-printer because the substrate is different. |

## Cross-references

The historical context, migration plan, and per-phase
status live in falcon-printer's doc tree:

- [`../../falcon-printer/docs/strategy.md`](../../falcon-printer/docs/strategy.md) -
  why we migrated from Falcon to r2sleigh; phased
  plan with decision gates.
- [`../../falcon-printer/docs/survey.md`](../../falcon-printer/docs/survey.md) -
  ecosystem survey, why we picked r2sleigh.
- [`../../falcon-printer/docs/architecture.md`](../../falcon-printer/docs/architecture.md) -
  Falcon-based architecture (now historical).
- [`../../falcon-printer/docs/passes.md`](../../falcon-printer/docs/passes.md) -
  the Falcon middle-end passes we built. Most are now
  upstream's responsibility in r2sleigh, but the
  documentation captures the patterns.

These docs stay in falcon-printer/ for git history and
migration provenance. Once the cutover lands (phase 4),
we relocate the relevant parts into decomp/docs/.
