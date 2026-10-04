# Kept areas: design

> **Authoritative on:** what obenseuer-mod does to make doors seamless
> (areas kept loaded): the design, why each choice was made, and how it
> was reached (the history section at the end). Nothing is built that is
> not here. What the game itself does: the game system docs listed in
> [`research.md`](research.md), doors in [`doors.md`](doors.md).

## Goal

Doors between areas move the player with no loading screen. The game must
behave as it does without the mod: same data, same events, same results.
Areas once loaded stay loaded (no limit by default); loading them happens
in the background and must never make the game stutter.

## The idea

The game has one area at a time. At a door it saves, unloads the area,
loads the next one, and loads the save into it (SaveController.cs:344-359).

The mod keeps areas loaded and does the same steps itself, on the area
left and the area entered, without unloading and without files. The
player's data never leaves memory: the player and managers the save loaded
stay the live ones in every area.

Every rule below copies a piece of the game. Anything the game does at a
door that the mod does not do, or does differently, is listed under
"Differences from the game".

## Rule 1: loading an area alongside

1. The area loads in the background (`LoadSceneAsync`, additive, low
   priority).
2. Unity's `sceneLoaded` runs after its objects' Awake and OnEnable and
   before any Start; there the shim switches its top objects off
   (`SceneTools.LoadQuietly`). Nothing in it starts until the player walks
   in.
3. Its copies of the game's managers do not take over, except the
   area-owned ones (below).

### Which copy the game uses

Every area brings its own copy of each manager. A manager is a class whose
Awake (or OnEnable) sets a static field or property of its own type, public
or not, to itself (`instance = this`; `info_navigation`, `SkyCamera`,
`OutlineEffect`, `SteamManager` keep theirs private). A static field of its own type that Awake
does not set is not a manager: `Storage.active` is the box open now.

- Game-wide managers (the player's: Inventory, PlayerStats, Money, the
  clock, the camera, the UI): the copies the save loaded stay the game's
  in every area. A copy from an area loaded alongside does not take over
  (its Awake and OnDestroy are skipped, first_copy_wins.rs).
- Area-owned managers: hold the area's own data, so they belong to the
  area's content, not to the player setup. This is Unity's standard
  pattern for levels loaded alongside a persistent scene: one persistent
  set of player and managers, and a level's own managers live and work in
  the level (areas.md, "One copy for the game, or one copy per area"). Obenseuer's scenes bundle them inside each area's copy of the
  player setup (`Game_Logic`), which the mod keeps switched off, so the
  mod separates them:
  - When the area has loaded alongside (in `sceneLoaded`, rule 1 step 2),
    each one inside `Game_Logic` has its object taken out of it and made a
    top object of the same area (the others are already the area's
    content and stay where they are: `SkyCamera` is placed relative to its
    parent). It is then the area's content: switched on and off
    with the area, saved and loaded with it by the game's own steps (rules
    2 and 3), and able to run its coroutines. Each sits alone on its own
    object with no children (research_area_owned.rs), so nothing else
    moves with it.
  - Its Awake is still held back at load (it would take over while the
    player is elsewhere). Entering the area sets its `instance` to the
    area's copy and switches the script on (rule 2, step 2), as its Awake
    would have on a normal load. `DestructibleList.Awake` also empties
    `Collectible.allCollectibles` (DestructibleList.cs:91): whether entering
    must do that too is not checked yet.
  - Known: `PlayerLevelEntrypoints` (`Game_Logic/Other/PlayerLevelEntrypoints`,
    arrival points), `DestructibleList` (`Game_Logic/Other/LoadSavegame`,
    dropped and destroyed items, saved in the area's file),
    `SleepEventController`
    (`Game_Logic/Controllers/WaitingController/SleepEventController`, saved
    in the area's file), `NPCManager` (`Game_Logic/Controllers/NPC/NPCManager`,
    caches the area's name in Start, NPCManager.cs:60, read by 20 NPC code
    paths), `info_map` (`__MAIN/info_map`), `info_water_source`
    (the area's water source, where it has one). Each sits alone on its
    own object with no children (research_area_owned.rs).
  - How they are found: a manager is area-owned when it saves into the
    area's file, caches the area's name instead of reading it when needed,
    or holds settings or objects built for its area (the `info_*`
    classes, arrival points). Reading the area's name when needed is not
    area-owned: the area entered is the active scene (rule 2, step 1). The
    scan of the game's 199 managers and its reading are in
    areas.md (one copy for the game, or one copy per area); a class shown to be area-owned later is added
    here first.
  - `info_game_logic` (`__MAIN/info_game_logic`) is area-owned too: its
    fields are the area's settings, read through `instance` (prison area,
    `baseSafetyFactor`, item expiry, map and skybox settings,
    info_game_logic.cs:8-65), and its Start pushes the area's sky and
    background radiation into the live `TimeOfDayAzure` and
    `RadiationController` (97-127). Its Awake and OnEnable destroy their
    own object when `instance` is another copy, and its OnDestroy
    destroys `Main` (73-95, 177-183): made area-owned while the area
    switched on before `instance` was set, walking back home destroyed
    the live player and managers (identity fell back to
    "Esko_Virtanen"). With the order below it finds itself.
  - Order on entering (rule 2): the area-owned managers become the game's
    before the area switches on, as Awake runs before OnEnable in a load.
  - An area without a copy of one leaves its `instance` empty, as in the
    game the previous area's copy is destroyed with its area (Under Map
    has no info_map; FirstCopyGuard.EnterArea). A copy in an area loading
    alongside or never entered never takes an area-owned `instance`, also
    an empty one (FirstCopyGuard.Newcomer, SceneTools.InQuietArea): before
    2026-10-04 Interior Tenement B, loading alongside after a door into
    Under Map, took the empty info_map (research_map.rs).
  - `SoundscapeGlobal` (`__MAIN/Soundscapes`, with its 4 children, all the
    area's content) is area-owned too: it holds the area's day and night
    sound, plays it in Start and sets it every minute
    (areas.md, what area objects do in Start).
  - `info_navigation` (loads its area's navigation file into the one
    pathfinder, pathfinding.md) and `SkyCamera` (the area's 3D sky
    camera) are area-owned too. In the game a new area's pathfinder holds
    that area's map from the start. On entering, before the area switches
    on, the mod loads the area's navigation file into the pathfinder with
    the game's own steps (`AstarPath.active.data.DeserializeGraphs`, then
    `WaypointGraph.MapWaypoints`, as info_navigation.LoadCO) and marks its
    `info_navigation` loaded. Loaded a frame after switching on (from its
    OnEnable), animals got paths on the previous area's map
    (NavmeshTile.GetVertex IndexOutOfRangeException).
  - Coroutines that run for good, started in Start (areas.md, coroutines):
    Unity stops them when the area switches off and does not restart
    them. On a later visit the mod starts them again on the area's
    objects: BottleRecyclingLights.Blinking,
    BottleRecyclingLightsUI.Blinking, PulseLight.LightEffect,
    RagdollAnimation.StepTimer (their Start must not run again: PulseLight
    would record a dimmed light as its maximum).
  - Followers: the game takes the player's area from the player object's
    scene (NPCSceneUtilities.OnFollowingTarget), and the live player
    object stays in the area the save loaded into. A prefix gives that
    method the area the player is in (the active scene) when the follow
    target is switched on in another scene, and otherwise lets it run.
  - Unity runs Start once per object; in the game every visit is a fresh
    load, so these Starts run on every visit. The mod runs the area's
    `info_game_logic.Start` and `SoundscapeGlobal.Start` again on every
    later visit (rule 2, step 3's frame); on the first visit Unity runs
    them itself.

### NPCs

In the game (npcs.md): the door save records every NPC that has
an object (`NPCDirector.OnSavingGameSpecial` -> `NPCData.OnSavingGame`:
its area and position); the unload destroys those objects, whose
OnDestroy unsubscribes their schedule (`scheduler.OnDestroy()`), and the
NPC lives on as data, moved by `NPCDirector.DeltaSeconds`; entering, the
area's `NPCManager.StartDelay` moves or spawns the NPCs whose data says
they are there and switches off the objects of NPCs that are elsewhere.

- Leaving an area (rule 3, step 6): for each NPC object of that area (its
  NPCManager's list), the game's `NPCData.OnSavingGame()` records it, then
  what destroying its object does: `scheduler.OnDestroy()`, and its data
  no longer points at the object (`scheduler.NPC` and the cached
  `controller` emptied). Only the current area's NPCs then have an
  object, as in the game, so a save records them right.
- Entering an area: `NPCManager.Start` runs again on later visits (with
  info_game_logic and SoundscapeGlobal), so its `StartDelay` reconciles
  the area's NPCs on every visit.
- Not known: NPCs following the player through a door (their arrival
  point is recorded in OnMapChanging, NPCDataState.OnMapChange).

### Game-wide events

The game's 28 static events (areas.md, game-wide events) keep their handlers until
OnDestroy, and an area left is switched off, not destroyed. In the game
it is destroyed, so its objects stop reacting: home's `SoundscapeGlobal`
otherwise sets home's sound every minute wherever the player is, and a
left area's Spawners keep their timers. So:

- Leaving an area (rule 3, after step 11): from every static event, and
  from every event on the live managers' copies (Inventory.ItemConsumed,
  FadeGameObjectController.UpdateFade, ...), the handlers whose object is
  in that area and now switched off are taken out and kept for that load
  of the area (`Scene.handle`). The live player and managers stay on, so
  theirs stay. On the game's clock events, the handlers of objects the
  game catches up on load stay (time while away, rule 2).
- Entering an area (rule 2, after the Starts run again): its kept
  handlers go back, each only if the event does not already hold it (a
  Start run again subscribes again).
- Kept handlers of a load are dropped when it unloads.

### Game-wide lists

In the game an area's objects leave the game-wide lists when the area is
destroyed (their OnDestroy, or the list's owner rebuilt by the load):
tenement resource storages, build spaces, lights and light zones,
talkable NPCs, tenement residents and scene events, the game's timers.
An area left keeps its objects, so (the shim's `EventTools.LeaveAreaLists`
and `EnterAreaLists`, same scope as the events):

- Leaving (after its handlers are taken out): its switched-off objects,
  and plain objects whose callbacks point at them (`TimeOfDayAzure.Timer`),
  are taken out of every static list, dictionary and set of the game's
  assembly and of those on the managers' live copies; kept for that load
  of the area. Not from the area's own managers (area-owned, in the area
  left): their lists are its own data (its arrival points, its NPCs).
- Entering, after its load steps (a timer's `OnLoading` puts itself back
  with the time passed): each goes back unless its list holds it already.

## The door

The game's door (doors.md) moves the player out of the area, then unloads it. The
mod mirrors that, with the area switched off instead of unloaded:

1. Rule 3, steps 1 to 10, on the area left, still on.
2. The player moves to the door's arrival point.
3. At least one physics step passes with the area left still on: its
   zones (triggers) see the player leave, as when walking out of them
   (StrictArea stops watching the player and clears its flag).
4. Rule 3, step 11: the area left switches off; its handlers on
   game-wide events are taken out (game-wide events, below).
5. Rule 2 on the area entered: it switches on, its zones see the player
   arrive.

The mod's prefix on `Changelevel.ChangeLevel` (kept_loaded.rs `on_door`)
is put on once at mod start, as every Harmony patch of the mod, and does
nothing with kept areas off. A door into an area kept loaded runs the
steps above; into an area not loaded yet (right after a save load, or
one never reached), the game's loading screen fades in, the area loads
alongside at full speed, then rules 3 and 2 run and it fades out. The
game's own door (its normal load) runs only when the area has no arrival
point for the door.

## Rule 2: entering an area

The game's own steps after a load (`LoadSaveGameDifferentScene`,
SaveController.cs:640-664), on the area entered, in this order:

| # | Game step | Line | Mod |
|---|---|---|---|
| 1 | Area loaded: Awake, OnEnable, then Start | 624-639 | Area switched on (Start runs now), made the active scene |
| 2 | Area-owned managers are the area's | (their Awake) | Their `instance` set to the area's copy (rule 1, which copy) |
| 3 | `LoadingStarted` | 640 | Fired |
| 4 | Load phases Primary, Secondary, Tertiary | 641-643 | First visit: from the area's saved file |
| 5 | Kept-through-loads OnLoadingGameSpecial | 644 | Not run: game-wide data, already live |
| 6 | `DestructibleList.OnLoadingGameDestructibleList`, the destroyed-objects check | 645-646 | First visit |
| 7 | Next frame | 647 | Next frame |
| 8 | OnLoadingGame, OnLoadingGameLatePrimary, the check again | 648-650 | First visit |
| 9 | OnMapChanged on the area | 651-654 | Every visit, on the area (and on the live player and managers' area) |
| 10 | Player to the arrival point | 655 | The door's arrival point in the area |
| 11 | Dialogue data applied | 656-659 | Not run: game-wide data, already live |
| 12 | Temp lists cleared, `Loading` false, `LoadingDone` | 660-663 | Lists cleared, `LoadingDone` fired |

"First visit" means the first time since the save was loaded. Later visits
keep what is live in the area: its data never left memory.

Later visits (2026-10-03): in the game every visit is a fresh load, so the
load steps run on every visit, not only the first:

- Steps 4 and 8 run on the area with the entries captured when it was left
  (rule 3). Those entries hold the area's live objects, so the steps
  restore nothing stale and do their work: delayed relay outputs restart,
  door locks sync, relays and trigger zones fire on load, timers catch up
  (docs/relays.md, docs/doors.md).
- Not run on a later visit (kept_loaded.rs `CREATES_OBJECTS`, the shim's
  `EventTools.RunStep`): step 6 (the DestructibleList steps) and the
  classes whose load step creates objects that are still there
  (CollectibleItemSpawner, FurnitureBlueprintSpawner, FurnitureManager,
  ParcelLocker, RatFightArena; docs/save.md); and the top objects holding
  the managers' live copies (the live player and game-wide managers, in
  the area the save loaded): they are not the area's content, and
  re-running their load re-did game-wide work (TenementController's load
  rebuilt the building's doors in Open Sewer Tenement, leaving that area's
  arrival point list with destroyed doors; research_kept_arrivals.rs).
- What area objects do in Start runs again, after the area switches on
  (`RUN_AGAIN`, the shim's `SceneTools.RunAgain`): the area-owned
  managers' Start (info_game_logic, SoundscapeGlobal, NPCManager), the
  coroutines that run for good, the relay start delay (`triggerAtStart`),
  and the Start of RelayAuto, RelayDialogueVariable, RelayRandom,
  RelayRandomValue, RelayTaskStatus, RelayWeekdays, and the shops' start
  coroutine (Trade.StartDelay: the open or closed relay for the hours).
  The clock handler such work subscribes again (SoundscapeGlobal,
  RelayWeekdays and Trade `DeltaSeconds`) is not put back on entering, as
  a fresh object subscribes once (EventTools.EnterArea).
- The NPC waypoint graph is mapped after the area switches on
  (`map_waypoints`): `MapWaypoints` sees switched-on waypoints only.

The map and the build space the player is in are set back on entering
(`map_again`, `build_space_again`; docs/map.md, docs/building.md).

Time while away (time.md): in the game an area not loaded does not run,
and its load catches it up from the time recorded when it was saved
(`savedTimeAndDay`: growing, storage restock, spawners, shops, animals,
NPC needs, fuel...). The mod does the same: leaving takes every handler
of the area out, the clock's too (`TimeOfDayAzure.SecondsPassed`,
`MinutePassed`, `DayChanged`, `CurrentTimeAndDay`), and leaving's save
steps record `savedTimeAndDay`; a later visit's load steps catch up from
it. Until 2026-10-04 the objects with `savedTimeAndDay` kept the clock
while away and their load steps were skipped on later visits; the relays
their load fires (Storage `onUpdate`, WorkableResourceSource `onStock`)
then never fired: 24 relays on a later door into Open Sewer Tenement
against the game's 94; with the game's catch-up, 93 against 93
(docs/relays.md, measured; operator: "we do what the game does").
`Collectible.OnLoadingGame` calls Start on a live object: harmless, its
Start returns once it has run (`startDone`, Collectible.cs:203;
CollectibleItem and CollectibleRecipeBook check it too; the others set
their title again).

## Rule 3: leaving an area

The game's own steps at a door (`ChangeLevel` 270, `SaveGame` 416-478), on
the area left, in this order:

| # | Game step | Line | Mod |
|---|---|---|---|
| 1 | `PlayerWillChangeLevel` | 270 | Fired |
| 2 | OnMapChanging on the area and the kept-through-loads objects | 446-447 | The same |
| 3 | `SavingStarted` | 452 | Fired |
| 4 | Save phases Primary, Secondary, Tertiary | 453-455 | On the area, into memory |
| 5 | `DestructibleList.OnSavingGameDestructibleList` | 456 | The area's DestructibleList, into memory |
| 6 | Kept-through-loads OnSavingGameSpecial | 457 | Not run: game-wide data, stays live |
| 7 | OnSavingGame, OnSavingGameLatePrimary | 458-459 | On the area, into memory |
| 8 | Files written | 460-476 | Not now: kept for the next save (rule 4) |
| 9 | OnSavingFile | 477 | Not run: no file written |
| 10 | `SavingDone` | 478 | Fired |
| 11 | Area unloaded: OnDisable, OnDestroy | (scene swap) | Area switched off: OnDisable only |

## Rule 4: saving

When the game saves (`SaveGame`), the mod adds every visited area's data
captured in rule 3 to the save folder: each area's file from its own
captured entries, merged with what the file already held. The area the
player is in is saved by the game itself.

The game's save runs the save steps on the active scene only
(SaveController.cs:452-459). Away from home the live player and managers
(the clock, the player's stats, inventory, money, tasks) are in home's
scene, so the game does not save them. The mod runs the same save steps on
home's switched-on objects (its own content is off away from home, so
these are the live player and managers; `live_set_entries`) and writes
their entries first: in Globals.tnmt before what the game wrote and before
the global entries captured from areas, in home's file before home's
captured entries (`write_merged`: an entry of a GUID comes from the first
source that has it). Before 2026-10-04 they came from the entries captured
when the player last left home: save steps set fields (the clock's
`savedTimeAndDay`, TimeOfDayAzure.cs:323; the inventory's saved slots,
Inventory.cs:124), so the save held them as at that moment, and a save
made away from home and loaded put the clock back (600 game seconds in the
check; `research_kept_scenario.rs` asserts the clock after the load is not
before the clock at the save).

## The mod's own state

State about a loaded area belongs to that load (Unity's `Scene.handle`,
new on every load), never to the area's name, and is dropped when that
load unloads. Everything the mod keeps is cleared when the game does a
normal load.

## Differences from the game

| Difference | Why | Status |
|---|---|---|
| Areas left are switched off, not unloaded | Unloading is what makes doors slow | Their handlers on the game's static events are taken out while away (rule 1, game-wide events); instance events on managers and lists that collect every area's objects stay (areas.md, what area objects do in Start: none breaks play) |
| No autosave at a door | Writing files at a door stutters | Decided by the operator (2026-10-03): no autosave at doors; the player saves |
| Objects in an area never entered woke but never started; OnDestroy of a class with Start and no Awake is skipped for them, and an exception their OnDisable throws is swallowed | Nothing may start before the player walks in (an area's intro ran and left the screen black) | Built |

## Proof

`tests/research_kept_scenario.rs`, after every change: through a door and
back twice (the second visit to an area that is not home must also move
without a loading screen), save, load, then back to the player's own save.
With kept areas on and off (`OBENSEUER_KEPT_OFF=1`), it must end with no
error the game does not also log, every manager live, the player's
identity intact, and after every kept door `NPCManager.ActiveScene` naming
the area entered.

## Status (2026-10-03)

| Rule | Built | Missing |
|---|---|---|
| 1 | Yes | |
| 2 | Yes: `enter_area`, the arrival point read from the area's own list first (`arrival_point`) | |
| 3 | Yes: `leave_area` | |
| 4 | Yes | |
| The mod's own state | Yes: shim state per load; Rust state cleared on every normal load (`tick`: a new GameController calls `reset()`, kept_loaded.rs:121-123) | |

## How the design was reached (history, 2026-10-02 to 2026-10-03)

What was tried and measured on the way to the design above, in order.
The game's own systems found on the way are in their own docs (doors.md,
areas.md, save.md, lighting.md); the mod's costs in performance.md.

### What a mod could change (first list, 2026-10-02)

- Keep one copy of the player and the managers for the whole game, the way
  LoadingScreen already does: keep them through scene changes on the first
  load, and destroy each new area's own copies in their Awake (Harmony
  prefix). Keep the per-area save and restore for boxes and NPCs; skip the
  global part. The door save is also the autosave; skipping it means no
  autosave at doors unless the mod keeps one.
- Start the early load at every door, not only the ones with a
  `LoadSceneAsyncTrigger`. Targets the bar, the largest part on the
  outdoor area. Risks: stutter while loading in the background, memory.
- Remove the bar's forced minimum of about 1 second.
- Keep the door save in memory instead of writing it to disk and reading
  it back. Removes only the disk time, which is not measured.

No published mod for this game, or for another Unity game, that turns
separate area loads into one continuous world is known to us.

### Early load tried at a door (works)

`research_early_load_try.rs` (2026-10-02): from Open Sewer Tenement it
picked the nearest door (Door_002_usable_changelevel to Interior Player
Tenement, 1.9 m away), started
`SceneManager.LoadSceneAsync(area, Single)` with
`allowSceneActivation = false`, and put the load and the area name into
`LoadSceneAsyncTrigger.currentAsyncOperations` and `currentAsyncScenes`.
The player then used that door. After the trip the test removed both
entries again (LoadingScreen never removes them, and a finished load left
in the lists would be reused on the next visit).

Test output:

```text
nearest door Door_002_usable_changelevel to Interior Player Tenement, 1.9 m away
Interior Player Tenement loaded early and held in 1.52s
```

The game's own lines for that trip (Player.log):

```text
Changing level to Interior Player Tenement!
Allow Scene Activation...
Load scene async done (1.6754769s)...
After small delay (2.9756345s)...
Fade out done (3.2333955s)...
```

`Allow Scene Activation...` is logged only when the door finds an early
load in the list (LoadingScreen.cs:212); a normal load logs
`Load Scene Async...` instead. So the door used the early load.

| Trip into Interior Player Tenement | Bar | Back in game |
|---|---|---|
| Normal load (research_loading.rs, earlier trip) | 4.67s | not measured |
| Loaded early | 1.68s | 3.23s |

The save on this trip took 0.565s (save_timing.rs). Most of the remaining
1.68s bar is likely the forced minimum fill of about 1 second
(LoadingScreen.cs:85); not proven.

Not known yet:

- One trip each way; the area may have been in memory from earlier visits.
- Whether the next door after this works normally.
- What happens if the player uses a different door while a load is held:
  Unity cannot cancel a scene load and holds later ones behind it, so the
  game would likely hang at that door.

### Two areas loaded at once

What a second area brings, takes over, and where its player setup and
`__MAIN` sit: [`areas.md`](areas.md) (two areas loaded at once, what a
second area brings that takes over, where an area's player setup sits,
what an area's __MAIN holds).

### Switching off after the load is not enough

`research_area_kept_quiet.rs` (2026-10-02): loaded the Gatehouse
alongside, switched off its `Player Camera Base`, `Pause Menu(Clone)`,
`___Screenshot Taking Stuff` and `Soundscapes`, and set 23 one-copy
fields back to the first area's copies. Output in
`output/area-kept-quiet.txt`. The player could then not move, look or open
the pause menu. `research_player_frozen.rs` showed the game's own
movement blocks were all off (time scale 1, no menu, nothing in
`disabledList`); Player.log showed errors every frame:

```text
   3330   at ThirdPersonCameraController.LateUpdate ()
   3201   at GameUIController.InventoryIsVisible ()
   2754   at WaitingUI.PlayPassOutEffect ()
   1310   at RadiationController.MeasureRadiation (UnityEngine.Transform position)
```

Cause, from the code: the second area's managers set themselves as the
one copy in Awake, then its `info_game_logic` destroys its own game logic
when one exists (info_game_logic.cs:73), taking those managers with it.
About 100 one-copy fields are left on destroyed objects. The earlier
"instance -> 0" readings were these, not a reading problem. Putting
fields back afterwards only covered the 23 known ones.

### First copy wins

The usual Unity answer is a guard in Awake: a new copy that finds a live
copy already in the field does not take over. About 85,000 C# files on
GitHub carry it (`"instance != null && instance != this" Destroy
language:C#`); the game uses it only in `LoadingScreen.Awake` and
`info_game_logic.Awake`. No Obenseuer mod (leonarudo/Lavender,
shiggityshaggs/*) or the developers' issue tracker
(loiste-interactive/Obenseuer-Issues) covers loading areas together.

`src/first_copy_wins.rs` (op `first_copy_wins`) puts that guard on every
class with a one-copy field: a Harmony prefix on Awake and OnDestroy of
the ~187 Assembly-CSharp classes with a static `instance`, plus
`AstarPath.active`. When the field already holds a live, different copy,
the original is skipped and the new copy disabled. For the new copies of
`ThirdPersonCameraController`, `PauseMenu` and `TimeOfDayAzure` it also
switches off their top object one frame later (Unity can refuse it during
start-up).

The shim had 16 slots per patch kind (HarmonyBridge.cs:75), so the first
try patched 13 methods and failed. Routing by `__originalMethod` fails on
this Harmony (HarmonyBridge.cs:16-22), so the shim now shares one slot
among every patch of the same Rust callback; the callback tells the
methods apart by its object. `PatchPrefixCtx` passes the callback as the
key; the slot is freed with its last patch.

`research_first_copy_wins.rs`, final run (2026-10-02):

```text
first_copy_wins on: {"not patched (no such method)":156,"on":true,"patches":220,...}
loaded Interior Tenement Gatehouse alongside in 1.91s
20 of 20 unchanged
switched off: ["Game_Logic","Pause Menu(Clone)","Player And Camera"]
errors since the load: 0
```

The player could move, look, see the HUD, open the pause menu, and the
lighting looked exactly as with one area (lighting with two areas:
[`lighting.md`](lighting.md)).

### Moving into an area kept loaded (works)

`research_move.rs` (2026-10-02): reloaded the save (Interior Player
Tenement), loaded Interior Tenement Gatehouse alongside, and set the
player's character (OpenSewerCharacterController, its transform and
Rigidbody) to the Gatehouse's `info_player_spawn` position. The areas
share one world space, so the move is a position change.

```text
loaded Interior Tenement Gatehouse alongside in 1.87s
player at {"x":99.602356,"y":-96.01,"z":16.56256}, the second area's start at {"x":45.642,"y":-99.9853,"z":-9.385}
moved in 0.098s; player now at {"x":45.642025,"y":-99.9853,"z":-9.384989}
player 3 s later at {"x":45.64433,"y":-99.9853,"z":-9.382685}
errors since the move: 1
  1  "ArgumentException: The agent is not added to this simulation"  at "Pathfinding.RVO.Simulator.RemoveAgent (Pathfinding.RVO.IAgent agent)"
```

The player was in the Gatehouse, it looked right and they could walk
around. 0.1 s against 3 to 18 s for a door. The one error (NPC crowd
movement removing an agent it never added) happened once; its source is
not checked.

Not handled yet at the time: the game still treats the first area as
current (save area name, the area's sky and radiation settings, which
area's NPC pathfinding and sounds are on); doors still do the save and
load; the second area's 1.87 s load happened before the move, not in the
background; memory with several areas kept loaded is not measured.

### Doors between areas kept loaded (src/kept_loaded.rs)

Every door calls the inherited `Changelevel.ChangeLevel()`
(DoorChangelevel.cs:219, TriggerChangelevel.cs:59). A Harmony prefix on
it: when the door's `OtherLevel` is an area kept loaded, the player is
moved to that area's arrival point named by the door's `OtherEntrypoint`,
with the game's own `PlayerLevelEntrypoints.Entrypoint.TeleportPlayer()`,
and the save and load are skipped. Every door's Awake adds its arrival
point to the one `PlayerLevelEntrypoints.instance.Entrypoints` list, so an
area loaded alongside adds its arrival points there too; the mod records
which belong to which area when it loads one.

`DoorChangelevel.OpenDoor` disables the controls for the door before
calling ChangeLevel (`GameController.ControlsDisabled(door)`,
DoorChangelevel.cs:206); a scene load throws that away, the move does
not, so the mod calls `GameController.ControlsEnabled(door)`
(GameController.cs:324) after the move. Without it the player could not
move.

`research_doors.rs` (2026-10-02), Interior Player Tenement with Open Sewer
Tenement loaded alongside:

```text
trip: "Door_002_usable_changelevel to Interior Player Tenement/PlayerTenement_In (0.005s)"
trip: "Door_002_usable_changelevel to Open Sewer Tenement/PlayerTenement_Out (0.003s)"
```

### Only the area the player is in is switched on

With both areas on, the outdoor door sat on the inside door and answered
the use key first (areas share one world space, [`areas.md`](areas.md)).

Only the area the player is in is switched on. The shim's
`SceneTools.RootsOf(area)` (cs-shim-mono/SceneTools.cs; a Scene is a
struct, so its GetRootGameObjects is out of the bridge's reach) lists an
area's top objects. An area switches off when it finishes loading
alongside; at a door the destination switches on, the player moves, and
the area left switches off. Never switched on: the area's own setup
first_copy_wins switched off, and `___Screenshot Taking Stuff`
(research_cameras.rs: in the outdoor area one screenshot camera is on and
drew over the player's camera, depth 0 against -1). Never switched off:
the top objects of the live player and managers (ThirdPersonCameraController,
PauseMenu, TimeOfDayAzure, OpenSewerCharacterController; in the player's
building the character is a top object of its own, and switching it off
left the player unable to move).

With the area swap a door trip took 0.288 to 0.292 s (switching an area
on), the camera was right and the door back was there.

### Loading door destinations automatically

kept_loaded's tick (src/lib.rs on_tick): when the player arrives in an
area by a normal load, the current area's door destinations are queued,
nearest door first, and loaded alongside one at a time, up to
`kept_loaded.max_areas` (settings.json, default 10, operator's choice)
besides the current area. A door move plans again from the new area.
Arriving is detected by the game's one GameController becoming a new
object: only a normal load does that (save, menu, F7, a door into an area
not kept loaded), since loads alongside keep the first copy. Polling
`SaveController.Loading` from a test missed save loads the game's log
shows; the mod's earlier "no current area and in a game area" rule
started loads alongside during a save load (140 skips in
research_always_on.rs). Nothing starts while no live GameController
exists.

In-game messages say "Nearby area ready" and "No loading screen (0.29s)";
area names go to the mod log only, so places not found yet are not given
away. From the player's building the destinations were Open Sewer
Tenement and "Under Map" (the game's area for falling through the world).

The cost of loading alongside: [`performance.md`](performance.md).

### Black screen from an area loaded alongside

The game went black twice with areas kept loaded (BlackCanvas alpha 1.0,
research_screen.rs), and a Harmony patch logging every
`BlackCanvas.ShowBlackCanvas` and `FadeIn` logged nothing. The cause:
"Interior Start", the new-game area, loaded alongside both times. Its
`StartOpenSewer.Start` (StartOpenSewer.cs:50-60) runs the new-game intro
unless the save says it ran (`skipStart`, `tutorialStarted`, read in its
OnLoadingGame, line 40): it disables the controls and the game menu, sets
`BlackCanvas.instance.canvasGroup.alpha = 1` directly (line 72), and only
after 3 s gives them back and fades out (73-87). An area loaded alongside
never gets its saved data, so the intro ran; switching the area off
stopped it halfway, black.

### The game's save and load, as the design must follow them

From SaveController.cs (the full steps: [`doors.md`](doors.md) and
[`save.md`](save.md)):

- `SaveGame` (416-484): `LevelName` is the active scene's name (438).
  Every save phase runs on the active scene's top objects only (453-459):
  `ExecuteSaveLoadFunctions` takes top objects and calls every
  SavableScript under them whose object is on (1113-1131). Global scripts
  (`SerializeData(this, global: true)`) go to `Globals.tnmt`, the rest to
  `<LevelName>.tnmt` (461-475). The save folder is copied from the last
  one first (469-472), so other areas' files are kept. A door
  (`ChangeLevelDelay`, 344) is a SaveGame into the older autosave.
- `LoadGameWithMigration` (1205-): reads `Globals.tnmt` and
  `<level>.tnmt` into `tempSavedata_Global` and `tempSavedata_Level`
  (1232, 1277-1311), then `LoadSaveGameDifferentScene` (618-666) loads the
  scene and runs the load phases on the active scene's top objects
  (641-650), OnMapChanged when the area changed (651-654), moves the
  player to the arrival point (655), applies the dialogue data (656-659),
  and fires `LoadingDone` (663).
- Each SavableScript finds its entry by its `GUID` and takes it out of
  the list (`DeSerializeData`, 707-).

So with the mod's door move at the time:

- An area loaded alongside never gets its `<area>.tnmt` or its global
  entries: its scripts start as on a new game (the intro above; box
  contents and events in that area are likely their defaults; not checked).
- After a door move the active scene is the area entered (the mod sets
  it), but the live player and managers stay in the area the save loaded
  into. A save then runs only on the entered area's top objects and
  leaves the live managers out of `Globals.tnmt`. Not checked in a save
  file yet, but it follows from 438-461. Until fixed: press F7 before
  saving after a door move.

### Proper design (proposal, 2026-10-02, not built)

Superseded by the design above (2026-10-03); kept as the history of how
it was reached.

Reproduce the game's own enter and leave steps for areas kept loaded,
with the game's own code, instead of patching what each skipped step
broke.

1. Loading alongside starts nothing. The shim catches Unity's
   `SceneManager.sceneLoaded` for areas the mod loads and switches their
   top objects off there, before any Start runs (today the mod switches
   them off a frame or more later, after Start: the intro, events and
   spawns got through). Awake and OnEnable still run at load; Start runs
   when the player walks in, as in a normal visit.
2. Walking in, as a normal load does it (order measured, question 1
   below): the area becomes the active scene and switches on (its
   objects start), and on the next frame its saved data is applied: read
   `<area>.tnmt` (and its global entries from `Globals.tnmt`) from the
   current save folder into the game's temp lists and run the load phases
   on the area's top objects, then OnMapChanged; then the arrival point.
   The load pass skips objects that are off (1131), so the data cannot go
   in before switching on. Only on the first visit after a save load;
   later visits keep the live state.
3. Walking out captures the area left, while it is still on: OnMapChanging
   (the NPC director and others, question 4), then the save phases on its
   own top objects, kept as that area's entries; then it switches off.
4. Every save writes each visited area's file from its own captured
   entries (the active area's taken fresh), merged with what the file
   held; global data from the live managers wherever they are. Each area's
   copies save under their own GUIDs, so entries never move between
   areas' files.

Answered (2026-10-02):

- Question 2, `research_live_roots_saving.rs`: the live top objects hold
  area-file scripts as well as global ones. Game_Logic: 38 global classes
  (Inventory, PlayerStats, Money, Crime, TimeOfDayAzure...) and 85 Relay,
  13 EditTask, DestructibleList, the slot controllers,
  SleepEventController, TriggerChangelevel, InteractableTalk in the area
  file. Player: PlayerStats, PlayerHandItems global; PersistLocation (the
  player's position) and relays in the area file. Pause Menu(Clone): 429
  Relay, area file.
- `research_save_ids.rs`: each area's copies save under their own GUIDs
  (SleepEventController: a different GUID per area; PersistLocation on the
  live player 79edc4c2..., on most areas' copies c0f9412e...). So step 4
  as written is wrong: saving the live top objects with another area
  writes the first area's entries into the other area's file, where that
  area's copies never read them, and the first area's file stops being
  written. And in a kept area its own Game_Logic copy is off, so the save
  pass (SaveController.cs:1131) drops its entries from that area's file
  (the level file is rewritten from what is on, 462/475).
  Step 4 becomes: each area's file is written from its own objects,
  captured while that area is on (when the player leaves it), merged with
  the entries its file already held; global data from the live managers.
- Inventory and PlayerStats read no GUID field; how the game matches
  global managers to their saved entries is not checked.
- 35 Game_Logic copies were live: 34 areas kept loaded at once.

- Question 1, order in a normal load (frame numbers logged by temporary
  prefixes on LoadGameWithMigration, ExecuteSaveLoadFunctions and
  Relay.Start, one save load):

  ```text
  save load begins at frame 17868
  load phase pass at frame 18794; Relay.Start so far 105 (first at frame 18793)
  load phase pass at frame 18795; Relay.Start so far 189 (first at frame 18793)
  ```

  The area's objects start first, its saved data goes in on the next
  frame; scripts that need the data wait (Relay fires its start events 3
  frames after Start, Relay.cs:88-93). Step 2 follows that order.
- Question 3, a save at every door: not needed. Step 3 captures the area
  left into memory (the save phases' output for its objects); the files
  are written at the game's next save (step 4).
- Question 4, what reacts to an area change or a load: the table in
  [`areas.md`](areas.md), game-wide events and their listeners. Steps 2
  and 3 run the OnMapChanged and OnMapChanging phases and fire
  PlayerWillChangeLevel, as a door does.

### The game's door and what the mod did at each step (2026-10-03)

The game's door, from the decompiled source. Every object of the area left
and of the area entered goes through it exactly once, in this order, and
only one area exists at any time:

| # | The game (SaveController.cs unless named) | Kept areas, the mod (kept_loaded.rs) at the time |
|---|---|---|
| 1 | Door: `Changelevel.ChangeLevel` (Changelevel.cs:72-87), fade in (`ChangeLevelDelay`, 344-355) | Door prefix moves the player without the fade |
| 2 | `PlayerWillChangeLevel` (InteractableChair, InteractableLadder) | Fired (`capture_leaving`, 659) |
| 3 | `SaveGame` into the older autosave (356-357): OnMapChanging on the active area and the kept-through-loads objects (446-447) | OnMapChanging on the area left, the home area, the kept-through-loads objects (`area_change_phase`). No autosave |
| 4 | `SavingStarted`, save phases on the active area, files written (452-484) | Save phases on the area left, kept in memory, written at the next save. `SavingStarted` and `SavingDone` not fired |
| 5 | Scene swap, single mode (634 or LoadingScreen): every object of the old area gets OnDisable, then OnDestroy, and is gone | The area left is switched off: OnDisable only. Its objects stay, and stay subscribed to game-wide events they subscribed to in Awake, OnEnable or Start (Spawner to `TimeOfDayAzure.SecondsPassed`, Spawner.cs:175, released only in OnDestroy, 388) |
| 6 | New area: Awake, OnEnable; Start on the next frame | First visit: Awake and OnEnable ran when it loaded alongside (switched off in sceneLoaded, `SceneTools.LoadQuietly`); Start when switched on. Later visits: OnEnable only, no Start |
| 7 | `LoadingStarted`; load phases Primary, Secondary, Tertiary on the active area (640-643) | First visit only: the same phases (`apply_saved_data`). `LoadingStarted` not fired |
| 8 | Kept-through-loads `OnLoadingGameSpecial`, `DestructibleList.OnLoadingGameDestructibleList`, the DestructibleList check including switched-off objects (644-646) | Not run |
| 9 | Next frame: OnLoadingGame, OnLoadingGameLatePrimary, the DestructibleList check again (647-650) | OnLoadingGame and LatePrimary, same frame. The check not run |
| 10 | OnMapChanged on the active area only (651-654) | On the area and the home area (where the live player and managers are). Until 2026-10-03 also on the kept-through-loads objects; removed, the check passes with no new errors |
| 11 | Player to the arrival point, dialogue data (655-659) | Player moved (TeleportPlayer); dialogue data not applied |
| 12 | Temp lists cleared, `Loading` false, `LoadingDone` (BlackoutController, ItemAchievementList, NaturalLightSourceChecker), fade out (660-664) | Lists cleared; `LoadingDone` not fired |
| 13 | A save load from anywhere: the same, from step 5, with every area unloaded | `reset()` clears the mod's Rust state, the game loads; the shim's own state is not cleared (below) |

What the mod kept between steps, and whether it lived as long as what it
describes:

| State | Where | Kept by | Cleared | Right? |
|---|---|---|---|---|
| Areas loaded quietly, still loading | `SceneTools.Quiet` | scene name | when its sceneLoaded comes | No: a load cut off by `reset()` leaves the name, and the game's own next load of that area is then switched off whole |
| Areas never entered | `SceneTools.NeverEntered` | scene name | on entering only | No: never cleared on a normal load, so a later normal load of the same area counts as never entered. Its objects started, but OnDestroy is skipped for them; a Spawner stays subscribed after it is destroyed. This fits the flood (NullReferenceException at Spawner.DeltaSeconds every frame after loading an autosave, after runs that loaded Open Sewer Tenement both ways); not proven |
| Top objects LoadQuietly switched off | `SceneTools.SwitchedOff` | scene name | taken once | Same name risk as `Quiet` |
| Areas loaded, swapped-off tops, captured entries, data applied, home | `kept_loaded.rs` statics | area name | `reset()` | Yes, while every normal load goes through `reset()`. A normal load the mod did not start (a door before the door prefix is on, the menu, a game over) does not: not checked |
| An area's own setup tops switched off | `first_copy_wins::SWITCHED_OFF_IDS` | instance id | never | Harmless: ids are not reused in one run |

Proven and fixed (2026-10-03): research_kept_scenario.rs with kept areas
off, after Open Sewer Tenement had loaded alongside, with state kept by
name: 12684 game errors in one run (12540 at Spawner.DeltaSeconds, 88
RelayWeekdays.Check, 32 VendingMachine.MinutePassed, 16 Clock.CurrentTime,
7 Trade.DeltaSeconds: all subscribe to a game-wide event when they start
and unsubscribe in OnDestroy). SceneTools now keeps loaded quietly, never
entered and switched off per load (`Scene.handle`), takes only the mod's
own loads alongside (additive mode), and drops a load's state when it
unloads. The same run: 1 error (LightController.Awake, also the game's
own); with kept areas on: 2 (LightController.Awake).

So the mod departed from the game in four ways, and every bug up to then
was one of them:

1. It keeps state by area name. The game never has two loads of one area
   alive, so a name is not a load. The mod's state has to belong to one
   load of an area (Unity's `Scene.handle`, new on every load), or be
   cleared whenever the game loads.
2. It leaves out steps of the game's sequence: the autosave, `SavingStarted`
   and `SavingDone`, `LoadingStarted`, the DestructibleList steps, the
   frame between steps 7 and 9, dialogue data, `LoadingDone`.
3. It added a step the game does not take: OnMapChanged on the
   kept-through-loads objects. Fixed 2026-10-03.
4. An area left is switched off, not unloaded: its objects keep what they
   subscribed to and keep running for game-wide events (a switched-off
   Spawner still gets `SecondsPassed`). Not yet measured what that does in
   play.

### The lifecycle rules kept areas break: full scan (2026-10-02)

The game assumes one area exists at a time. Every bug up to then broke
one of these rules the game's code relies on:

| Rule | How kept areas break it | Bugs so far |
|---|---|---|
| 1. one copy of each manager, static data set once | areas bring copies; their Awake writes statics | managers, identity, sky, camera |
| 2. an object that wakes also starts | kept areas Awake but Start only when entered (LoadQuietly) | the intro; lava lamps; MoneyPanel.OnDisable errors; chairs left subscribed |
| 3. objects switch off only when their area unloads | the area swap switches them off and on | none seen yet |
| 4. only the current area exists | whole-game searches and scene events see every area | (scene-event listeners run per area) |
| 5. the current area's data is loaded and saved | kept areas need it done by hand | design steps 2 to 4 |

A read-only scan of the decompiled code (scratchpad `scan_rules.py`, 950
MonoBehaviour-like classes) found, per rule:

- Rule 2, Start sets something that OnDestroy or OnDisable uses: 7
  classes. LavaLamp (OnDestroy destroys `material`, the shared asset when
  Start never ran: then every lamp started later fails, `new Material(null)`,
  ArgumentNullException at LavaLamp.Start and a NullReferenceException at
  LavaLamp.Update every frame, 3533 seen), NPCController (destroys `Data`),
  cakeslice.OutlineEffect (render textures), Cull_light, LightController,
  InteractableCashRegister, OnNPCStateChange.
- Rule 3: 68 classes with OnDisable, 98 with OnEnable; 12 OnDisable use a
  one-copy manager. The game switches objects on and off itself, so most
  should cope; MoneyPanel errors and the scan did not flag it, so this rule
  is read from the errors seen, not the scan.
- Rule 4: FindObjectOfType/FindObjectsOfType in 18 classes,
  GameObject.Find in 6, Camera.main in 13: all skip switched-off objects,
  so the area swap hides kept areas from them. sceneLoaded listeners: 2
  (LoadOnLevelIni, SalsaConfigGuard). GetActiveScene users: 12 (NPCManager
  among them); the mod makes the entered area the active scene.
- Rule 1, static data written in Awake or OnEnable: 14 classes. Covered:
  LightsController, ItemDatabase (one-copy, guarded), SaveController,
  SteamManager and the NPC graphs and director (kept through loads, guard
  themselves), MenuLocalization, NotesPanel (a folder path). To check:
  AlarmClock (alarmClocks) and ToiletPaperHolder (allHolders) add every
  copy to a game-wide list; SlotMachineGameplay resets `_runResults`;
  LoadOnLevelIni.

Fixes, one per rule:

1. Done: first_copy_wins. To check: the four classes above.
2. Objects in an area never entered woke (Awake, OnEnable) but never
   started. OnDestroy is skipped for them only in classes with a Start and
   no Awake (FirstCopyGuard.StartWithoutAwakeClasses): with an Awake, its
   OnDestroy must undo Awake (InteractableChair unsubscribes from
   SaveController.PlayerWillChangeLevel; skipped, destroyed chairs stayed
   subscribed and leaving an area threw). OnDisable is never skipped
   (SMVHierarchy and InteractableListItem unsubscribe there what OnEnable
   subscribed); it runs, and only an exception it throws on an object
   never started is swallowed, by a Harmony finalizer on every OnDisable
   of a class with a Start (FirstCopyGuard.FinishOnDisableOfNeverStarted;
   MoneyPanel.OnDisable reads lists only Start fills).
3. Fix the classes the error count shows (MoneyPanel first).
4. Nothing for the searches; check the 2 sceneLoaded listeners.
5. Design steps 2 to 4 (built).

And an automatic check after every build: the mod walks through doors
itself with the game's own door call, saves and loads, and must end with 0
new errors and every one-copy field live (the proof section above).

### The check's errors: the game's own or the mod's (2026-10-03)

research_kept_scenario.rs from Interior Player Tenement (door to Open
Sewer Tenement and back, save to ModTest, load it), once with kept areas
on and once off (OBENSEUER_KEPT_OFF=1, the game's own loads):

| Error | Kept areas on | Off |
|---|---|---|
| Pathfinding.RVO.Simulator.RemoveAgent "The agent is not added to this simulation" | 2 | 0 |
| LightController.Awake NullReferenceException | 2 | 1 |

RemoveAgent is the mod's. LightController.Awake is also the game's own;
whether the second one is the mod's is not known from one run each.

### Between doors, read from the code (2026-10-03)

- AlarmClock, ToiletPaperHolder: add themselves to a game-wide list in
  OnEnable and remove themselves in OnDisable (AlarmClock.cs:15-41): a
  switched-off kept area takes its copies out. Same as the game.
- LoadOnLevelIni: Awake destroys any second copy (`spawned`, 18-37); its
  sceneLoaded listener exists only after a load from the menu and leaves
  on the first area. Same as the game.
- SlotMachineGameplay: every machine's Awake replaces one shared array
  (`_runResults`, 148); the game does that with several machines in one
  area already. A machine loading alongside while one is played matters
  only with a different reel count.
- Whole-game searches (FindObjectOfType, FindObjectsOfType,
  GameObject.Find, Camera.main): all skip switched-off objects, so they
  find the current area and the live player and managers, as in the game.
- SalsaConfigGuard: on every scene load, the mod's loads alongside too,
  and again a second later, it checks every Salsa, Emoter and Eyes in
  every loaded area, switched-off ones included. Only settings; its cost
  grows with areas kept loaded.
- OnEnable and OnDisable at every door: all 17 subscriptions made in an
  OnEnable are undone in the class's OnDisable, so nothing subscribes
  twice.
- NPCManager.ActiveScene: a name cached in Start (NPCManager.cs:60), read
  by 20 NPC code paths (spawning, schedules, the NPC director,
  pathfinding between areas). The live NPCManager is home's, so after a
  kept door it still names home. NPCManager is area-owned (which managers
  are area-owned: [`areas.md`](areas.md)).
- LightController.Awake NullReferenceException: a LightController on an
  object with no Light (`cullLight.intensity`, offset 0x0c). The game's
  own scene mistake; it is logged when such an area loads, alongside or
  not.

### First door right after a load (2026-10-03)

The door patch is on from mod start, so a door used right after a save
load goes through the mod: the area behind it loads alongside behind the
loading screen, then the player moves in (OBENSEUER_DOOR_AT_ONCE=1 check
passed). One MoneyPanel.OnDisable NullReferenceException in that run,
stack: the mod's `SetActive` (MonoBridge.InvokeMethod). The player moved
in the same frame the area finished loading; the jobs its Awakes queued
to switch its player setup off (first_copy_wins
switch_off_top_next_frame) had not run, so entering switched the area's
Game_Logic on for a frame, and the queued job then switched an entered
MoneyPanel off. Fix: the waiting door moves the player in one frame later.
