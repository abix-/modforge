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

## Investigating without restarts

`src/investigate.rs`:

- `reload_save`: loads the save last loaded, as the load menu does
  (SaveController.LoadGameWithMigration, LoadMenu.cs:539), after turning
  `first_copy_wins` off. `research_investigate.rs`: one clean area, 0
  errors, the player saw the loading screen.
- `errors`: what the game logged since a mark, grouped by the game code
  that threw it, read from Application.consoleLogPath.

A mod change goes in without a restart through `restart.ps1`'s in-place
swap, except after `first_copy_wins` was on: the swap refuses while
patched methods would be left behind. That check exists for IL2CPP;
whether Mono needs it is not checked.

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
