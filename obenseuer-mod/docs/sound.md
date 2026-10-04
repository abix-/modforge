# Sound

> **Authoritative on:** the soundscapes: SoundscapeController (what plays),
> SoundscapeGlobal (an area's day and night sound), SoundscapeArea (a
> sound), SoundscapeTrigger (a zone that changes the sound), and how they
> behave with areas kept loaded.
>
> Index of every game system's doc: [`research.md`](research.md).

Read from the decompiled source (SoundscapeController.cs, SoundscapeGlobal.cs,
SoundscapeArea.cs, SoundscapeTrigger.cs) and measured by
`tests/research_soundscape.rs`.

## SoundscapeController

`public class SoundscapeController : SoundscapeAudioPlayer`. Game-wide
manager, rebuilt with every area in the game. Nothing saved (`fsIgnore` or
private).

| Field | Type | Meaning |
|---|---|---|
| `instance` | `static SoundscapeController` | Set in Awake (48-51) |
| `currentGlobalSoundscape` | `SoundscapeArea`, private | The area's global sound, set by `SetGlobalSoundscape` |
| `previousSoundscape` | `SoundscapeArea`, private | The one before `currentSoundscape` |
| `currentSoundscape` | `SoundscapeArea` | The sound playing in front |
| `currentBackgroundSoundscape` | `SoundscapeArea` | The sound playing behind (another room heard through a door) |
| `currentBackgroundLocation` | `Transform`, private | Where the background sound comes from |
| `currentTrigger` | `SoundscapeTrigger` | The zone the player is in |
| `currentHour` | `float`, private | Last hour seen; a new hour replays `currentSoundscape` (Update, 78-86) |
| `soundscapeAreas` | `List<SoundscapeArea>` | Soundscapes with an `id`, added in `SoundscapeArea.Start`; read by `FindSoundscapeAreaById` |

| Method | Does |
|---|---|
| `SetGlobalSoundscape(SoundscapeArea)` (93-109) | Sets `currentGlobalSoundscape`; replays the background or front sound when it was the old global one |
| `PlaySoundscape(SoundscapeArea, bool playImmediately, bool stopPreviousImmediately)` (186-208) | Null means the global one. Stops the previous front sound unless it is the background, sets `currentSoundscape`, plays it |
| `SetBackgroundSoundscape(...)` (135-184) | Sets the background sound and `currentTrigger`; with `isGlobal` the background is the global sound (asks SoundscapeGlobal first when none is set) |
| `UpdateBackgroundDistance()` (236-262) | Every frame: background volume from the distance to its location and the trigger's door state |
| `FindSoundscapeAreaById(string)` (284-298) | First `soundscapeAreas` entry with that id |

## SoundscapeGlobal

`public class SoundscapeGlobal : MonoBehaviour`. One per area, area-owned
([`kept-areas.md`](kept-areas.md), rule 1). Not saved.

| Member | Does |
|---|---|
| `playAtStart` | Start plays the global sound right away; else it is set at the next game minute |
| `soundscapeDay`, `soundscapeNight` | The area's global sound by day (8:00 to 21:00) and night; no night sound means day all the time |
| `Start()` | Subscribes to `TimeOfDayAzure.MinutePassed`; with `playAtStart`, sets and plays the global sound |
| `SetGlobalSoundscape()` | Picks day or night and calls `SoundscapeController.SetGlobalSoundscape`; with neither set, the global sound becomes none |
| `OnDestroy()` | Unsubscribes |

Measured (research_soundscape.rs, Tom_Tomato/Slot7):

| Area | playAtStart | Day | Night |
|---|---|---|---|
| Interior Player Tenement | false | Global Day | Global Night |
| Open Sewer Tenement | true | Global Day | Global Night |
| Under Map | false | none | none |

Under Map has no global sound.

## SoundscapeArea

`public class SoundscapeArea : MonoBehaviour`. One sound (loops and random
sounds). `Start()` (35-46): adds itself to `soundscapeAreas` when it has an
`id`, creates its audio sources, and with `playAtStart` plays itself.

## SoundscapeTrigger

`public class SoundscapeTrigger : SavableScript`. A zone; saves into the
area's file. Saved field: `currentSoundscape` (the player was in it).

| Member | Does |
|---|---|
| `OnTriggerEnter(Collider)` (60-66) | The player's head: `PlaySoundscape` |
| `PlaySoundscape(bool)` (68-72) | Sets the background (its area, or the global one) and plays its front sound |
| `OnLoadingGame()` (47-58) | When saved with the player in it, plays its sound right away |

## Flows

Loading an area: the new SoundscapeController starts with nothing set ->
the area's soundscapes with `playAtStart` play -> SoundscapeGlobal.Start
sets the global sound (with `playAtStart`) -> load steps: the trigger the
player was in plays its sound.

## With areas kept loaded

- SoundscapeController is kept, so after a kept door it would still hold
  the previous area's sounds and trigger. The mod sets
  `currentGlobalSoundscape`, `previousSoundscape`, `currentSoundscape`,
  `currentBackgroundSoundscape`, `currentBackgroundLocation` and
  `currentTrigger` to nothing before the area switches on (`fresh_sound`,
  kept_loaded.rs), as a rebuilt one starts. The trigger left keeps its
  saved `currentSoundscape`, as in the game.
- SoundscapeGlobal.Start runs again on later visits (`RUN_AGAIN`).
- Checked by `research_kept_scenario.rs` after every door: the global sound
  is the area's (none in Under Map), and the sound playing is the area's
  or none. Passed 2026-10-04 with Open Sewer Tenement (two round trips) and
  Under Map (one way: it has no door back to the player's tenement).
- `soundscapeAreas` holds the soundscapes of every kept area entered; ids
  shared by two areas would make `FindSoundscapeAreaById` find the wrong
  one. Not checked.
