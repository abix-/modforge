# The game

> **Authoritative on:** Obenseuer's install, engine, assemblies, third-party
> libraries, its JSON data files, the modding community, and how the mod
> loads into it (unityforge). Facts are read from disk unless marked
> unverified.
>
> Index of every game system's doc: [`research.md`](research.md).

## The install

| Property | Value |
|---|---|
| Install path | `C:\Games\Steam\steamapps\common\Obenseuer\` |
| Steam app id | 951240 |
| Developer | Loiste Interactive |
| Engine | **Unity 2019.4.41f2** (LTS) |
| Scripting backend | **Mono** (MonoBleedingEdge present, no IL2CPP) |
| Main exe | `Obenseuer.exe` |
| Main assembly | `Obenseuer_Data/Managed/Assembly-CSharp.dll` (~3 MB) |
| First-pass assembly | `Assembly-CSharp-firstpass.dll` |
| Native plugins | `lib_burst_generated.dll` (Burst jobs), `steam_api64.dll` |
| Asset pipeline | Unity Addressables (`StreamingAssets/aa/catalog.json`) |
| Levels | 78 level files (level0 through level77) |
| Game version | 0.4.17 (from globalgamemanagers) |

Assembly-CSharp decompiled with ilspycmd: 1148 classes across the global
namespace, OS.Items (37 classes), and NPC (41 classes).

## Third-party libraries in Managed/

| DLL | Purpose |
|---|---|
| AstarPathfindingProject | A* pathfinding for NPCs ([`pathfinding.md`](pathfinding.md)) |
| BehaviorDesignerRuntime | behavior tree AI |
| DOTween | animation tweening |
| SALSA-LipSync | lip sync for dialogue |
| Cinemachine | camera system |
| BakeryRuntimeAssembly | lightmap baking ([`lighting.md`](lighting.md)) |
| Ookii.Dialogs | native file dialogs |
| Newtonsoft.Json | JSON serialization |

## JSON data files (StreamingAssets/)

All loaded at runtime. Mod surface even without code patches.

| File | Content |
|---|---|
| Items.json | item definitions ([`items.md`](items.md)) |
| Recipes.json | crafting recipes: ID, name, type (Mashing, etc.), inputs with item refs and amounts, conditions, tags, variant items. UTF-16 LE encoded |
| Characters.json | NPC definitions ([`npcs.md`](npcs.md)). UTF-16 LE encoded |
| CharactersRent.json | rent information per character |
| NPCBehavior.json | NPC schedules ([`npcs.md`](npcs.md)) |
| Wearables.json | wearable item definitions |
| StoragePrefabs.json | storage container prefab paths |
| StorageSpawnCategory.json | storage spawn categories |

Loaders and encodings: [`items.md`](items.md), data loading.

## Modding ecosystem

The community uses BepInEx as the mod loader. The Lavender library
(github.com/leonarudo/Lavender) provides helper functions. Nexus Mods
hosts published mods. The Stalburg Wiki documents the modding process.

No BepInEx is installed in this copy yet. Install path would be the
game root, with plugins in `BepInEx/plugins/`.

## Modforge integration

This is a Unity Mono game, which is the exact target of unityforge.
The bootstrap path is:

1. BepInEx loads `Unityforge.Shim.dll` into the Obenseuer process.
2. The shim locates `obenseuer_mod.unityforge.dll`, LoadLibrary's it,
   and calls `unityforge_init(bridge)`.
3. The `unityforge_mod!` macro stores the bridge, calls `on_init`.
4. `on_init` registers generic ops, selectors, and game-specific hooks.
5. The shim's MonoBehaviour.Update calls `unityforge_tick` each frame.

The JSON data files in StreamingAssets are a large modding surface
that does not require Harmony patches. Intercepting the JSON load
or replacing files directly can add/modify items, recipes, NPCs,
and schedules.

For deeper changes (game mechanics, player stats, survival systems,
addiction, economy), Harmony patches against Assembly-CSharp.dll are
needed. The assembly is Mono, so all methods are patchable.
