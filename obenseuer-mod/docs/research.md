# Obenseuer research

> **Authoritative on:** which doc is the authority for each game system.
> Each game system has one doc; a fact lives in that doc only, and other
> docs link to it. Facts are read from the game's files and code
> (decompiled Assembly-CSharp) or measured by the tests in `tests/`
> (research_*.rs), unless marked unverified.

| Game system | Doc |
|---|---|
| The install, assemblies, libraries, JSON data files, modding, how the mod loads | [`game.md`](game.md) |
| Doors and moving between areas: the door step by step, arrival points, every other area change | [`doors.md`](doors.md) |
| Areas: scenes, managers, info_game_logic, game-wide events, lifecycle, coroutines | [`areas.md`](areas.md) |
| The save system, player state in the save, DestructibleList | [`save.md`](save.md) |
| Time: the clock, its listeners, catching up while not loaded | [`time.md`](time.md) |
| NPCs: data, classes, ActiveScene, NPCDirector, the scheduler, followers | [`npcs.md`](npcs.md) |
| Pathfinding and the area's navigation | [`pathfinding.md`](pathfinding.md) |
| Relays | [`relays.md`](relays.md) |
| The map | [`map.md`](map.md) |
| Sound: soundscapes, an area's global sound, sound zones | [`sound.md`](sound.md) |
| The tenement | [`tenement.md`](tenement.md) |
| Building and furniture | [`building.md`](building.md) |
| Crime, prison and police | [`crime.md`](crime.md) |
| Weather | [`weather.md`](weather.md) |
| Dialogue | [`dialogue.md`](dialogue.md) |
| Lighting | [`lighting.md`](lighting.md) |
| The player's stats, difficulty, waiting and sleeping | [`player.md`](player.md) |
| Items, consumables, inventory, item and recipe loading | [`items.md`](items.md) |
| Crafting, trade, storage, banks, locks | [`economy.md`](economy.md) |

The mod's own docs:

| Subject | Doc |
|---|---|
| The design for keeping areas loaded, and how it was reached | [`kept-areas.md`](kept-areas.md) |
| What the mod costs: loading alongside, mod start, memory | [`performance.md`](performance.md) |
| Running tests against the live game, recovering, investigating | [`testing.md`](testing.md) |
| Open work | [`todo.md`](todo.md) |
| Done work | [`changelog.md`](changelog.md) |
