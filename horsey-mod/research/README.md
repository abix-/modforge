# horsey-mods

Reverse-engineering and modding research for **Horsey Game** (Steam, build 2026-05-08).

## Goal

100% decompilation of `Horsey.exe` with full behavior documentation. Mods fall out as side effects.

Start with `FINDINGS.md` for the current state and plan.

## Files

| File | What |
|---|---|
| `FINDINGS.md` | Authoritative summary: engine, file layout, gene system, save format, plan, progress. |
| `RESEARCH.md` | Working log of the initial data-file survey. |
| `RE-NOTES.md` | Strings extracted from `Horsey.exe` to anchor Ghidra analysis. |
| `SAVE-FORMAT.md` | Static-analysis notes on `save1.dat`. Partial. |
| `parse_save.py` | Walks the horse roster in `save1.dat`. |
| `diff_save.py` | Byte-diff two save snapshots. |
| `save-snapshots/` | Captured save files for diff experiments. |

## Working principle

Every claim about game behavior must be backed by decompiled code from `Horsey.exe` (address cited) or an in-game observation. Inference from binary patterns is labelled `(INFERRED, NOT VERIFIED)` or removed.
