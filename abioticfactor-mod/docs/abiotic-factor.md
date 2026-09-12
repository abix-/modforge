# Abiotic Factor research

Research for the standalone Rust UDP player and the Abiotic Factor mod lives in this folder. Add findings to the owning topic below, keeping observed facts, decoded behavior, and open questions distinct.

Confirmed 2026-09-12: Sophia joins, spawns and walks with animations through the
standalone Rust UDP client. The first movement command is a bounded world +X
input. See the RPC reference for the implementation, commands and remaining limits.

| Topic | Contents |
|---|---|
| [Engine and modding](engine.md) | Game build, binaries, mod infrastructure, classes, and data tables |
| [Skills, recipes, and difficulty](progression.md) | Skills, XP curve, recipes, and difficulty |
| [Character health, stats, and input](character.md) | Body-part health, character stats, and native player input |
| [LAN research method and evidence](research-method.md) | Evidence labels, permanent Rust diagnostics, and reproducible decoding |
| [LAN transport, identity, and admission](lan-transport.md) | UDP handshake, identity, admission, and early multiplayer notes |
| [LAN possession, character creation, and spawning](lan-spawn.md) | Possession, saved/new characters, traits, spawn ordering, and confirmed freeze |
| [LAN loading and playable readiness](lan-loading.md) | Level loading, disabled state, and readiness gaps |
| [LAN RPC and property reference](lan-rpc.md) | Inspected RPC handles, properties, and customization schema |
| [Character saves, disconnect, and persistence](persistence.md) | Save identity, loading/writing saves, disconnect, and persistence gaps |

Keep unfinished work in [todo](todo.md) and shipped history in [changelog](changelog.md). Research findings belong in the topic documents, with their source/test evidence and remaining unknowns. The bot joins and acts through UDP; HTTP supports investigation through permanent Rust tests.
