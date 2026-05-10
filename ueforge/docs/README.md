# ueforge docs

> **Authoritative on:** the ueforge framework. One file per
> subsystem, every load-bearing API explained, every design
> rationale captured.

`../README.md` is the entry point + crate-level audit table +
"how to bootstrap a new game" guide. The doctrine docs in this
directory explain *how* to write code on top of ueforge well.
The per-subsystem files explain *what* each subsystem does.

## Doctrine

| File | Authoritative on |
|---|---|
| [PERFORMANCE.md](PERFORMANCE.md) | Hot-path discipline. Zero allocs, bail early, no mutexes on empty path, bounded everything. The 10/10 bar. |
| [RESEARCH.md](RESEARCH.md) | TDD investigation methodology for UE5 games. Standard probes, doctrines on data tables / damage / instigators, snapshot-not-log validation. |

## Subsystem reference

| Subsystem | File | Headline |
|---|---|---|
| Lifecycle | [lifecycle.md](lifecycle.md) | `ue4ss_mod!`, `ModInfo`, C++ shim, on_unreal_init, on_shutdown, build/deploy |
| UE SDK | [ue-sdk.md](ue-sdk.md) | UObject family + `ClassRef` + `TypedField<T>` + GObjects + `PlayerRef` + core_types |
| Hooks | [hooks.md](hooks.md) | `ProcessEventHook`, `function_table!`, `LazyFunctionPtr`, `install_with_backoff`, `install_many` |
| Game-thread queue | [pe-queue.md](pe-queue.md) | `Queue`, `DrainSite`, drain-site selection rules |
| Counters & rings | [counters.md](counters.md) | `counter!`, `peak!`, `time_scope`, `EventRing<T>`, `counter_json!` |
| RPG framework | [rpg.md](rpg.md) | `Skill<E>`, `RpgApplier`, `Tracker<A>`, `tab::render`, `SlotKeyResolver`, `VanillaCache`, level-up system |
| HTTP control plane | [http.md](http.md) | `server::spawn`, builtin ops, selectors, `Api<S>` test client, perf log writer |
| ImGui | [imgui.md](imgui.md) | `ui` module, `Tab` registration, scanner tab |
| Settings | [settings.md](settings.md) | `Settings<T>` atomic JSON store |
| Workers | [worker.md](worker.md) | `worker::spawn` named thread + panic catch |
| Data tables | [data-table.md](data-table.md) | `FieldTweak<T>`, `ClassFieldTweak<T>`, row mutation, timing rules |
| Memory tools | [memory-tools.md](memory-tools.md) | Cheat-Engine-style scanner, freezes, `inspect_address`, `winproc` |

## Reading order

New to ueforge:

1. `../README.md` -- what + why
2. [lifecycle.md](lifecycle.md) -- minimum viable mod skeleton
3. [ue-sdk.md](ue-sdk.md) -- type system you'll use everywhere
4. [hooks.md](hooks.md) -- if you hook anything (you will)
5. [PERFORMANCE.md](PERFORMANCE.md) -- before writing hot-path code
6. [RESEARCH.md](RESEARCH.md) -- before debugging anything

Pick the rest as work demands; cross-references are dense.

## Contributing

When you change ueforge code, update the relevant doc in the
**same commit**. Stale docs lie; rotted docs cost the next
reader days. The audit table in `../README.md` should also
reflect any new public surface.
