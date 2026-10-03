# Obenseuer research

> **Authoritative on:** which doc is the authority for each game system.
> Each game system has one doc; a fact lives in that doc only, and other
> docs link to it. Facts are read from the game's files and code
> (decompiled Assembly-CSharp) or measured by the tests in `tests/`
> (research_*.rs), unless marked unverified.

| Game system | Doc |
|---|---|
| The install, assemblies, libraries, JSON data files, modding, how the mod loads | [`game.md`](game.md) |
| Areas: scenes, managers, info_game_logic, arrival points, area changes, game-wide events, lifecycle, coroutines | [`areas.md`](areas.md) |
| The save system, the game's door step by step, player state in the save, DestructibleList | [`save.md`](save.md) |
| Time: the clock, its listeners, catching up while not loaded | [`time.md`](time.md) |
| NPCs: data, classes, ActiveScene, NPCDirector, the scheduler, followers | [`npcs.md`](npcs.md) |
| Pathfinding and the area's navigation | [`pathfinding.md`](pathfinding.md) |
| Relays | [`relays.md`](relays.md) |
| The map | [`map.md`](map.md) |
| The tenement | [`tenement.md`](tenement.md) |
| Building and furniture | [`building.md`](building.md) |
| Crime, prison and police | [`crime.md`](crime.md) |
| Weather | [`weather.md`](weather.md) |
| Dialogue | [`dialogue.md`](dialogue.md) |
| Lighting | [`lighting.md`](lighting.md) |
| The player's stats, difficulty, waiting and sleeping | [`player.md`](player.md) |
| Items, consumables, inventory, item and recipe loading | [`items.md`](items.md) |
| Crafting, trade, storage, banks, locks | [`economy.md`](economy.md) |

The mod's own docs: [`kept-areas.md`](kept-areas.md) (the design for
keeping areas loaded), [`loading-research.md`](loading-research.md)
(history of the loading work), [`todo.md`](todo.md),
[`changelog.md`](changelog.md).
