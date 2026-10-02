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

Other costs in the code:

- The bar fills at a fixed speed (`Mathf.MoveTowards` at 1 per second,
  LoadingScreen.cs:85) and the new area is only shown once it is full, so
  even an instant load waits about 1 second.
- Fades step the alpha by 0.05 per frame, 20 frames each way.

## The game already loads some areas early

`LoadSceneAsyncTrigger` starts loading the next area alongside the
current one when the player walks into a trigger near some doors. When
the door is used, `LoadingScreen.LoadAsynchronously` reuses that load if
it is in `LoadSceneAsyncTrigger.currentAsyncScenes`. Not known: how many
doors have such a trigger.

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

## Open questions

- How long the save takes, measured outside a freeze (for example a
  Harmony prefix and postfix on `SaveController.SaveGame` that log the
  time).
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
