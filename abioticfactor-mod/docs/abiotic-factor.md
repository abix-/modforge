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
| [LAN transport, identity, and admission](history/lan-transport.md) | History (UDP client removed 2026-09-13): handshake, identity, admission |
| [LAN possession, character creation, and spawning](history/lan-spawn.md) | History: possession, saved/new characters, traits, the decoded spawn flow ai_player.start reproduces one step of |
| [LAN loading and playable readiness](history/lan-loading.md) | History: level loading, disabled state, readiness gaps |
| [LAN RPC and property reference](history/lan-rpc.md) | History: RPC handles, properties, customization schema |
| [Character saves, disconnect, and persistence](persistence.md) | Save identity, loading/writing saves, disconnect, and persistence gaps |
| [NPC AI: targets and fighting](npc-ai.md) | Soldier rows, perception numbers, decoded target scoring, the character's attack functions, what Sophia reuses |
| [Performance](performance.md) | Game-thread cost rules, what is cached, what was measured |

Keep unfinished work in [todo](todo.md) and shipped history in [changelog](changelog.md). Research findings belong in the topic documents, with their source/test evidence and remaining unknowns. The bot joins and acts through UDP; HTTP supports investigation through permanent Rust tests.
