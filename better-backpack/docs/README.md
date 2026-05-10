# better-backpack docs

> **Authoritative on:** the Grounded 2 RPG / level-up mod
> (BetterBackpack). Per-subject deep dives. Each file states
> what it owns at the top.

## Contents

| File | Subject |
|---|---|
| [building.md](building.md) | Build, install, deploy. Prereqs, cargo commands, deploy script, configuration. |
| [features.md](features.md) | User-facing feature list. What the mod does in-game. |
| [rpg.md](rpg.md) | RPG subsystem internals: catalog, sqrt curve, persistence, code map. |
| [damage.md](damage.md) | Grounded 2 damage internals: combat / fall / environmental, status effect system, instigator resolution. |
| [inventory.md](inventory.md) | Backpack patch internals + viewport rebind. |
| [engine.md](engine.md) | Grounded 2 engine specifics: pak, exes, GObjects, shipping caveats. |
| [performance.md](performance.md) | What this mod costs to run. Per-call costs, hot paths, allocation analysis. |
| [ongoing.md](ongoing.md) | Every piece of code that runs continuously. CPU / RAM / I/O triage reference. |
| [testing.md](testing.md) | Debug HTTP endpoint + integration test harness. |
| [rust-port.md](rust-port.md) | Historical: port from C++ winhttp proxy to Rust cdylib. |
| [ue4ss-port.md](ue4ss-port.md) | Historical: port from custom DLL injection to UE4SS CPPMod. |

## Where to look first

| Symptom | First file to read |
|---|---|
| skill not applying in-game | deployed `better_backpack.log` then [rpg.md](rpg.md) |
| damage / fall / environmental issue | [damage.md](damage.md) |
| inventory / scrolling issue | [inventory.md](inventory.md) |
| save / slot detection | [rpg.md](rpg.md) "Persistence" section |
| build fails | [building.md](building.md) |
| performance / allocation regression | [performance.md](performance.md) + ueforge's `docs/PERFORMANCE.md` |
| writing an integration test | [testing.md](testing.md) |
| understanding why X exists | [rust-port.md](rust-port.md) / [ue4ss-port.md](ue4ss-port.md) |

## Framework references

The framework that bbp is built on lives in the `ueforge/` crate.
For framework-level questions, see:

- [`../../ueforge/README.md`](../../ueforge/README.md) -- entry point
- [`../../ueforge/docs/`](../../ueforge/docs/) -- per-subsystem reference
- [`../../ueforge/docs/PERFORMANCE.md`](../../ueforge/docs/PERFORMANCE.md) -- hot-path doctrine
- [`../../ueforge/docs/RESEARCH.md`](../../ueforge/docs/RESEARCH.md) -- TDD methodology
