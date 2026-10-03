# Obenseuer loading screens

Why Obenseuer shows a loading screen at every door between areas, where
the time goes, and what a mod could change. Started 2026-10-02.

Sources: the decompiled game code (Assembly-CSharp.dll, ilspycmd), the
game's own timing lines in Player.log, and the research test
`tests/research_loading.rs` run against the live game. Each fact below
names its source.

## What happens at a door

Code: `SaveController.ChangeLevelDelay` (SaveController.cs:344).

1. The screen fades to the loading screen (`LoadingScreen.Fade`).
2. The game writes a full save into the older of the two autosave slots
   (`SaveGame`).
3. It loads that save back (`LoadGameWithMigration`, SaveController.cs:1205).
   This swaps in the new area's scene with `SceneManager.LoadSceneAsync`
   in single mode, which destroys the old area
   (`LoadingScreen.LoadAsynchronously`).
4. It restores what was saved for the new area: boxes, NPCs, the clock.
   The fade back in waits until this is done: `TimeOfDayAzure` holds
   `updateTimeDisabled` until `SaveController.Loading` is false
   (TimeOfDayAzure.cs:345).

The save in step 2 is how the player's state reaches the next area: the
objects holding it are destroyed with the old area and rebuilt from the
save in the new one (next section).

## Every area brings its own player and managers

Live game, `research_loading.rs`, one trip Open Sewer Tenement to
Interior Player Tenement (2026-10-02). Instance ids before and after the
trip; the same id means the object survived, a new id means it was
destroyed and built again.

```text
SaveController         KEPT         ids [852246] -> [852246]
LoadingScreen          KEPT         ids [852752] -> [852752]
Inventory              REBUILT      ids [6879408] -> [7119596]
BackpackStorage        REBUILT      ids [6879410] -> [7119598]
PlayerStats            REBUILT      ids [6874938] -> [7114958]
TimeOfDayAzure         REBUILT      ids [6839382] -> [7086676]
Crime                  REBUILT      ids [6871766] -> [7111538]
Money                  REBUILT      ids [6877460] -> [7117526]
DifficultyController   REBUILT      ids [6878464] -> [7118562]
WaitingController      REBUILT      ids [6872406] -> [7112096]
TenementController     REBUILT      ids [6839384] -> [7086678]
GameUIController       REBUILT      ids [6867236] -> [7106652]
Notifications          REBUILT      ids [6867052] -> [7106504]
InteractObjects        REBUILT      ids [6874246] -> [7114116]
main camera            REBUILT      ids [6655738] -> [6981904]
```

Code agrees: only a few objects call `DontDestroyOnLoad` (SaveController,
LoadingScreen, InputManager, SteamManager, Achievements, the NPC
pathfinding and NPCDirector, a few others). Inventory, PlayerStats,
TimeOfDayAzure and Crime set `instance = this` in Awake and are not kept
(Inventory.cs:189, PlayerStats.cs:171, TimeOfDayAzure.cs:354, Crime.cs:117).

The game already uses the keep-one-copy pattern for the loading screen:
`LoadingScreen.Awake` (LoadingScreen.cs:83) keeps itself through scene
changes and destroys any second copy.

## Where the time goes

Game's own Player.log lines (seconds from the start of the load):

| Destination | Bar done | Back in game |
|---|---|---|
| Interior Tenement Gatehouse | 2.4 | 3.3 |
| Interior Tenement Deekula A | 2.6 | 4.0 |
| Interior Tenement Deekula C | 14.9 | 17.5 |
| Open Sewer Tenement | 14.6 | 16.3 |
| Open Sewer Tenement (later trip) | 4.6 | 7.7 |
| (destination not in these lines) | 4.9 | 18.1 |

Player.log does not time the save before the bar.

`research_loading.rs`, same trip as above:

```text
fade   2.14s  save and read back   0.00s  bar   4.67s  restore   0.00s  total   6.81s  longest freeze 1.90s
```

The fade, bar and total are measured. The save and restore parts read
0.00s because the game froze for 1.90s once during the trip and the test
cannot ask the game anything while it is frozen; both parts fell inside
freezes. That the 1.90s freeze is the save is likely but not proven.

The save itself, timed by a Harmony prefix and postfix on
`SaveController.SaveGame` (`src/save_timing.rs`), one door trip to Open
Sewer Tenement (2026-10-02), with the game's own lines for that trip:

```text
obenseuer-mod: save took 0.582s
Load scene async done (4.2537571s)...
After small delay (5.2849259s)...
Fade out done (5.8932484s)...
```

| Part | Time |
|---|---|
| Save | 0.58s |
| Bar (the area's scene loading) | 4.25s |
| Restore (boxes, NPCs, clock) | about 1.0s |
| Fade back in | about 0.6s |

The fade to black before the save is not in these lines; the test
measured 2.14s on an earlier trip.

So keeping one copy of the managers would remove the save and part of the
restore, about 1.5s at most on this trip. The bar is the largest part and
keeping the managers does not touch it; loading the next area early does.

Other costs in the code:

- The bar fills at a fixed speed (`Mathf.MoveTowards` at 1 per second,
  LoadingScreen.cs:85) and the new area is only shown once it is full, so
  even an instant load waits about 1 second.
- Fades step the alpha by 0.05 per frame, 20 frames each way.

## The game already loads some areas early

`LoadSceneAsyncTrigger` starts loading the next area alongside the
current one when the player walks into a trigger near some doors. When
the door is used, `LoadingScreen.LoadAsynchronously` reuses that load if
it is in `LoadSceneAsyncTrigger.currentAsyncScenes`.

The early load only helps if the door is used before it finishes: when
the load completes, its `completed` handler removes the area from
`currentAsyncScenes` (LoadSceneAsyncTrigger.cs:33-41), so a door used
after that loads the area again from scratch. The early-loaded area then
seems to stay loaded alongside the current one until the door's load
replaces everything (not confirmed live).

Live game, `research_early_load.rs`, in Open Sewer Tenement (the main
outdoor area, 2026-10-02):

```text
area "Open Sewer Tenement", scenes loaded now 1
57 doors to other areas (Changelevel):
0 early-load triggers (LoadSceneAsyncTrigger):
```

- All 57 doors are active and lead to about 40 different areas (shops,
  tenements, bars, the metro). 6 have no destination (`to ""`), among
  them two elevator doors.
- No door in this area loads early: every door here does the full load.
- Other areas were not checked; the test sees only the area the player
  is in.

## Early load tried at a door (works)

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

## Links that would break if the managers were kept

Text search of the decompiled code: how many files keep their own link
to a manager (a field of that type) against how many ask for the one copy
through `X.instance` each time.

| Manager | Files with their own link | Files using X.instance |
|---|---|---|
| Inventory | 3 | 88 |
| PlayerStats | 1 | 88 |
| TimeOfDayAzure | 2 | 81 |
| Money | 2 | 56 |
| Crime | 0 | 31 |
| BackpackStorage | 0 | 8 |
| GameUIController | 0 | 58 |
| WaitingController | 0 | 19 |

A search for fields declared as `public X name;` or
`[SerializeField] private X name;` on one line; links declared another
way would be missed.

## What a mod could change

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

## Two areas loaded at once

`research_two_areas.rs` (2026-10-02): in Open Sewer Tenement, loaded
Interior Tenement Gatehouse alongside with
`SceneManager.LoadSceneAsync(area, Additive)` and kept both loaded. Full
output in `docs/two-areas.txt`.

```text
memory before: allocated 2916 MB  reserved 3438 MB  managed 381 MB
loaded Interior Tenement Gatehouse alongside in 2.43s
memory after: allocated ?  reserved ?  managed 424 MB
  Inventory              copies 1 -> 1  [3223108] -> [3223108]  instance 3223108 -> 0 SWITCHED
  InteractObjects        copies 1 -> 2  [3217946] -> [3217946, 3339936]  instance 3217946 -> 3339936 SWITCHED
cameras 4 -> 9; main camera Some(2999438) -> Some(2999438)
doors: 57 in "Open Sewer Tenement", 6 new from Interior Tenement Gatehouse
"Open Sewer Tenement" doors span [-9.0, -500.0, -56.9] to [110.2, -84.8, 58.5]
Interior Tenement Gatehouse doors span [12.3, -108.7, -13.0] to [45.2, -97.4, 2.0]
```

- The interior loaded alongside in 2.43s; managed memory rose 381 MB to
  424 MB. The Unity memory readings after the load failed (`?`).
- The interior brought no second Inventory, PlayerStats, TimeOfDayAzure or
  other manager from the list: their copy counts stayed at 1. So on a door
  trip those are not rebuilt from the area scene itself; where they come
  from is not known yet.
- It brought a second `InteractObjects` (the looking-at and using code),
  and the game's `instance` switched to the new copy.
- It brought 5 cameras (4 -> 9); the main camera stayed the same.
- The "instance -> 0 SWITCHED" rows for the other 12 managers are likely
  failed reads, not switches: a live Unity object never has id 0 and
  their copy counts did not change. Not confirmed.
- The interior's doors lie inside the box around the outdoor area's
  doors. That box is coarse (it reaches y -500, likely the "Under Map"
  door), so whether the two areas really share space is not known.

What the player saw after the load:

- The HUD was gone.
- The player seemed to be in a different place than before.

Which of the interior's objects caused this is not known. Candidates: one
of its 5 cameras, its own interface objects, the switched
`InteractObjects`, or its arrival points (`PlayerLevelEntrypoints` sets
itself as the one copy in Awake, PlayerLevelEntrypoints.cs:62; no code
that moves the player on area start was found).

## What a second area brings that takes over

`research_area_takeover.rs` (2026-10-02), with the game's "run in
background" option on (the game answers while unfocused): in Interior
Player Tenement, loaded Interior Tenement Gatehouse alongside and compared
every Assembly-CSharp class with a static `instance` field (187 of 3182
types) plus Unity's cameras, canvases, audio listeners, event systems and
lights. Full output in `docs/area-takeover.txt`.

```text
loaded Interior Tenement Gatehouse alongside in 2.86s
main camera now id 1809714 at {"x":99.4568,"y":-94.52959,"z":12.7817459}
  PlayerCamera: 1 before, 1 new; instance 1925248 -> 2054982
  InteractObjects: 1 before, 1 new; instance 1941926 -> 2065626
  FirstPersonHands: 1 before, 1 new; instance 1934716 -> 2061196
  PauseMenu: 1 before, 1 new; instance -7740 -> -151636
  SoundscapeGlobal: 1 before, 1 new; instance 1948148 -> 2069232
  UnityEngine.Camera: 7 before, 6 new
    Player Camera (id 1991106) active true enabled true depth -1.0 display 0 tag "MainCamera"
  UnityEngine.Canvas: 672 before, 1 new
    Pause Menu(Clone) (id -151630) ... renderMode "ScreenSpaceOverlay" sortingOrder 7
  UnityEngine.AudioListener: 6 before, 5 new
  UnityEngine.Light: 354 before, 151 new
```

The second area brings its own player setup, and each part takes over
the game's one copy (`instance` switched to the new copy):

- Player camera and controls on objects named "Player Camera" and "Player
  Camera Base": PlayerCamera, CameraRotate, CameraShake, SetControls,
  InteractObjects, ThirdPersonCameraCollision,
  ThirdPersonCameraController, FirstPersonSettings, PlayerAudioListener.
- FirstPersonHands, PlayerCameraAnimations.
- A second pause menu (PauseMenu, DeathMessage, PauseMenuGlow) with its
  own overlay canvas.
- SoundscapeGlobal, info_map.
- 6 cameras, one of them a second "Player Camera" tagged MainCamera; 5
  audio listeners; 151 lights.

Not duplicated: Inventory, PlayerStats, TimeOfDayAzure, Crime, Money and
about 100 other managers keep one copy.

Likely causes of what the player saw, not proven: the second area's own
Player Camera drawing (the main camera itself did not move), and its
pause menu overlay or switched player classes hiding the HUD.

Not explained: most unchanged classes read "instance ... -> 0"; a live
object never has id 0, so this is likely a reading problem in the test.
LightsController and four menu panels read "-> null", which may be real.

So for keeping several areas loaded, a mod switches off each newly loaded
area's own player setup so the first one stays in charge.

## Where an area's player setup sits

`research_area_player_setup.rs` (2026-10-02): loaded Interior Tenement
Gatehouse alongside Interior Player Tenement and followed every copy of
the duplicated classes up to its top parent object. Full output in
`docs/area-player-setup.txt`.

```text
second: Player Camera Base (top object id 1974670), 11 parts:
second: Pause Menu(Clone) (top object id -141548), 5 parts:
second: __MAIN (top object id 1955252), 2 parts:
second: ___Screenshot Taking Stuff (top object id 1956678), 8 parts:
```

Each area brings the same four top objects, mirroring the first area's:

| Top object | Holds |
|---|---|
| `Player Camera Base` | the player view and controls: Player Camera, FirstPersonCamera, First person hands, InteractObjects, the camera controllers, PlayerAudioListener, Pause Menu Glow (11 parts) |
| `Pause Menu(Clone)` | PauseMenu, DeathMessage, KeyBindings, LoadMenu and the overlay canvas; "(Clone)" means something creates it at run time |
| `__MAIN` | Soundscapes, info_map; likely more not in the list checked |
| `___Screenshot Taking Stuff` | 4 screenshot cameras with audio listeners |

The first area also had `Furniture Shop UI` with its own camera; the
second did not.

So a mod switches off a short fixed list per area loaded alongside:
`Player Camera Base`, `Pause Menu(Clone)`, `___Screenshot Taking Stuff`.
`__MAIN` may hold what the area itself needs once the player is in it, so
it is not switched off blindly; what it holds is the next question.

## What an area's __MAIN holds

`research_area_main.rs` (2026-10-02), read-only, in Interior Player
Tenement: everything under `__MAIN`, 183 objects. Full list in
`docs/area-main.txt`.

```text
__MAIN
  info_player_spawn  info_player_spawn
  info_navigation  info_navigation
    Navigation  AstarPath, RVOSimulator
  info_game_logic  info_game_logic
  Post Processing  PostProcessVolume
  Soundscapes  SoundscapeGlobal
    ... (day and night music, a sound zone per room: basement, stairs,
        17 apartments and balconies, reverb zone)
  info_map  info_map
```

| Under `__MAIN` | What it is |
|---|---|
| `info_player_spawn` | the area's player start; holds a link to the area's player object (`Player`, info_player_spawn.cs:9), likely the `Player Camera Base` setup; destroys it when destroyed |
| `info_navigation` | the area's NPC pathfinding grid (AstarPath, RVOSimulator) |
| `info_game_logic` | the area's settings: sky override and background radiation, applied in Start (info_game_logic.cs:97) |
| `Post Processing` | the area's image effects volume |
| `Soundscapes` | the area's music and sounds, 160 of the 183 objects |
| `info_map` | the area's map information |

From the code: `info_game_logic` already keeps one copy. A second area's
copy destroys its own object when one exists (info_game_logic.cs:73).
That fits the managers not being duplicated in an area loaded alongside;
whether they hang off it is not confirmed. Its sky and radiation settings
are applied only in Start, so moving into an area kept loaded would have
to apply them again.

So per area kept loaded alongside, a mod would:

- switch off `Player Camera Base`, `Pause Menu(Clone)`,
  `___Screenshot Taking Stuff`
- keep its `Soundscapes`, `Post Processing` and `info_navigation` off
  until the player is in that area, then switch them on (two pathfinding
  grids active at once would likely clash; not tested)
- on moving in, apply that area's sky and radiation settings again

None of this switching has been tried yet.

## Switching off after the load is not enough

`research_area_kept_quiet.rs` (2026-10-02): loaded the Gatehouse
alongside, switched off its `Player Camera Base`, `Pause Menu(Clone)`,
`___Screenshot Taking Stuff` and `Soundscapes`, and set 23 one-copy
fields back to the first area's copies. Output in
`docs/area-kept-quiet.txt`. The player could then not move, look or open
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

## First copy wins

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
lighting looked exactly as with one area.

## Lighting with two areas

Before `Game_Logic` was switched off the scene was too dark.
`research_alongside_lightmaps.rs` compared one area and two:

| | One area | Two areas |
|---|---|---|
| Ambient light | (0.23, 0.20, 0.18) | (0, 0, 0) |
| Reflection probes on | 2 | 32 |
| Bakery lighting stores | 1 | 2 |

`research_azure_sky.rs` found the cause: the second area brings a whole
`Game_Logic / Globals / Azure[Sky] Dynamic Skybox`. Its one-copy
`TimeOfDayAzure` was disabled, but its AzureTimeController,
AzureSkyRenderController, AzureWeatherController, AzureEnvironmentController
and AzureEffectsController kept running and wrote the game-wide sky,
ambient light and shader values every frame (AzureEnvironmentController.cs:41,
AzureSkyRenderController.cs:228 and 339-356). The game normally destroys
that second `Game_Logic` through `info_game_logic`; skipping its Awake left
it alive. Switching off the second `Game_Logic` fixed the lighting.

Switching off the second area's image effects volumes, lights and
reflection probes (`alongside_off`, `research_alongside_lighting.rs`)
did not fix it and with `Game_Logic` off was not needed: the lighting
looked right with them still on. Checked in one area pair only.

## Moving into an area kept loaded (works)

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

Not handled yet: the game still treats the first area as current (save
area name, the area's sky and radiation settings, which area's NPC
pathfinding and sounds are on); doors still do the save and load; the
second area's 1.87 s load happened before the move, not in the
background; memory with several areas kept loaded is not measured.

## Doors between areas kept loaded (src/kept_loaded.rs)

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

## Areas are built in the same place

With both areas on, the player's first trip from inside went "in", and
outside the building looked black with no door back: the building's
interior is built where the building stands in the outdoor area, so the
outdoor door sat on the inside door and answered the use key first.

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

## Loading door destinations automatically

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

## Background loading cost

While an area loads alongside, `Application.backgroundLoadingPriority` is
Low (2 ms of loading work per frame; Unity documents Low 2, BelowNormal
4, Normal 10, High 50); the game's value is put back when nothing loads
alongside and on every reset.

The mod logged each load (2026-10-02):

```text
first_copy_wins on took 0.619s
Open Sewer Tenement ready: load 4.00s, longest frame while loading 0.653s, switching it off 0.077s
Under Map ready: load 1.44s, longest frame while loading 0.014s, switching it off 0.012s
```

The delay was the mod turning first_copy_wins on (patching ~220 methods)
on every save load. Harmony's author on patch speed: "It is as fast as
you can get it" (pardeike/Harmony#609); BepInEx mods patch once at start
(MSchmoecker/FasterLoading, Plugin.Awake). first_copy_wins now patches
once when the mod starts and stays on:

```text
obenseuer-mod: first_copy_wins on: 220 patches in 0.709s
```

Staying on through normal loads: the managers the game keeps through
scene changes (LoadingScreen, SaveController, InputManager, Achievements,
the settings savers, the NPC director and graphs) are brought again by
every area and destroy themselves in their own Awake (LoadingScreen.cs:83);
the guard was stopping that. The shim's `SceneTools.KeptThroughLoads`
tells them apart, and the guard lets their Awake run.
`research_always_on.rs`, a save load with the guard on:

```text
loaded in 4.1s; skipped during the load: 2
skipped during the load: ["SoundscapeGlobal.OnDestroy +1", "info_game_logic.OnDestroy +1"]
one-copy fields not on a live object: []
```

No Awake skipped; the two OnDestroy skips are the old area's, after the
new copies took over (running them would empty the new copies' fields).

Whether the play-time delay is gone is not yet confirmed by the player.

## Getting unstuck

`reload_save`, and the F7 key, reset the mod (no areas kept loaded, door
patch off, loading priority back) and load the save last loaded. Used
live when the player could not move after a door: the game came back to
one clean area.

## Black screen from an area loaded alongside

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

## The game's save and load, as the design must follow them

From SaveController.cs:

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

So with the mod's door move today:

- An area loaded alongside never gets its `<area>.tnmt` or its global
  entries: its scripts start as on a new game (the intro above; box
  contents and events in that area are likely their defaults; not checked).
- After a door move the active scene is the area entered (the mod sets
  it), but the live player and managers stay in the area the save loaded
  into. A save then runs only on the entered area's top objects and
  leaves the live managers out of `Globals.tnmt`. Not checked in a save
  file yet, but it follows from 438-461. Until fixed: press F7 before
  saving after a door move.

## Proper design (proposal, 2026-10-02, not built)

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
- Question 4, what reacts to an area change or a load:

  | Trigger | Scripts |
  |---|---|
  | OnMapChanging (leaving) | NPCDirector (every NPC's state.OnMapChange, NPCDirector.cs:91-104), AnimalController, BuildingSystem, Teleport |
  | OnMapChanged (arrived) | NPCDirector, AnimalController, Collectible, Spawner, RelayTimer, RelayOnDayChange, TenementEventController |
  | LoadingDone | BlackoutController, ItemAchievementList, NaturalLightSourceChecker |
  | PlayerWillChangeLevel | InteractableChair, InteractableLadder (stop sitting, climbing) |
  | PlayerWillLoadGame | Act_Police, Act_Robber |
  | Unity sceneLoaded | LoadOnLevelIni, SalsaConfigGuard (these already run for every area loaded alongside) |

  Steps 2 and 3 run the OnMapChanged and OnMapChanging phases and fire
  PlayerWillChangeLevel, as a door does.

## The game's door, step by step, and what the mod does at each step (2026-10-03)

The game's door, from the decompiled source. Every object of the area left
and of the area entered goes through it exactly once, in this order, and
only one area exists at any time:

| # | The game (SaveController.cs unless named) | Kept areas, the mod (kept_loaded.rs) |
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

What the mod keeps between steps, and whether it lives as long as what it
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

So the mod departs from the game in four ways, and every bug so far is
one of them:

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

## The lifecycle rules kept areas break: full scan (2026-10-02)

The game assumes one area exists at a time. Every bug so far broke one of
these rules the game's code relies on:

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
new errors and every one-copy field live.

## The check's errors: the game's own or the mod's (2026-10-03)

research_kept_scenario.rs from Interior Player Tenement (door to Open
Sewer Tenement and back, save to ModTest, load it), once with kept areas
on and once off (OBENSEUER_KEPT_OFF=1, the game's own loads):

| Error | Kept areas on | Off |
|---|---|---|
| Pathfinding.RVO.Simulator.RemoveAgent "The agent is not added to this simulation" | 2 | 0 |
| LightController.Awake NullReferenceException | 2 | 1 |

RemoveAgent is the mod's. LightController.Awake is also the game's own;
whether the second one is the mod's is not known from one run each.

## Investigating without restarts

`src/investigate.rs`:

- `reload_save`: loads the save last loaded, as the load menu does
  (SaveController.LoadGameWithMigration, LoadMenu.cs:539), after turning
  `first_copy_wins` off. `research_investigate.rs`: one clean area, 0
  errors, the player saw the loading screen.
- `errors`: what the game logged since a mark, grouped by the game code
  that threw it, read from Application.consoleLogPath.

`restart.ps1`'s in-place swap refuses while patched methods would be left
behind, and first_copy_wins is now always on, so every mod change
restarts the game. That check exists for IL2CPP; whether Mono needs it is
not checked.

The game must have its "run in background" option on (OptionsMenu.cs:276),
or it stops answering while unfocused ("main-thread queue timed out").

## Open questions

- What each rebuilt manager's own-link files are, and whether the game
  sets those links in the level editor.
- How many doors already load the next area early.
- Whether each area's lighting and sky clash when two areas are loaded at
  once.

## Running the test

```text
k3sc cargo-lock test -p obenseuer-mod --test research_loading -- --test-threads=1 --nocapture
```

It stops after one door trip (`OBENSEUER_WATCH_TRIPS`, default 1, and
`OBENSEUER_WATCH_SECS`, default 600) and writes `docs/loading-trips.txt`.
The game only answers while its frames run, so keep the game window
focused while it starts.
