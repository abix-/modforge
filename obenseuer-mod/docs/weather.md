# Weather

> **Authoritative on:** weather (`WeatherManager`, Azure Sky's
> `AzureWeatherController` global and local profiles, thunder,
> `Weather`, `WeatherChange`), how indoor areas override the sky, and the
> weather events.
>
> Index of every game system's doc: [`research.md`](research.md).

## WeatherManager

`public class WeatherManager : SavableScript` (WeatherManager.cs).
Game-wide, in `Game_Logic/Globals`. GUID const "WeatherManager"; saves
into Globals.

| Field | Saved | Meaning |
|---|---|---|
| `static WeatherManager instance` | no | Awake (94-97) |
| `int savedWeather` | yes | Global weather profile index at save |
| `[fsProperty] int currentWheatherLenght` | yes | Game seconds until the next random change |
| `[fsProperty] bool thunder`, `[fsProperty] float currentLightningTime` | yes | Thunder on; seconds to next strike |
| `weatherController` (`AzureWeatherController`), `effectsController` (`AzureEffectsController`) | no | Azure parts |
| `minLightningTime` (10), `maxLightningTime` (30), `thunderChance` (30%) | no | |
| `const int weatherMinLenghtInHours = 6`, `weatherMaxLenghtInHours = 24`; `const float temperatureRange = 40` | | |
| `float Wind` (get) | | `effectsController.windSpeed` |

Events (static): `WeatherUpdated` (fired by `ChangeWeather`; listeners:
`logic_weather_listener`, `MaterialWindEffect`), `WeatherTransitioning`
(every frame of a transition; `logic_weather_listener`).

| Method | Does |
|---|---|
| `Start()` (99-103) | Random length 6 to 24 h; 0.3 s later `TimeOfDayAzure.MinutePassed += DeltaSeconds` |
| `DeltaSeconds(int sec)` (138-145) | Each game minute: length used up -> `ChangeRandomWheather(Random 50-100 s transition)`; `length -= 60` |
| `Update()` (105-119) | Thunder strikes (`effectsController.InstantiateThunderEffect`) while `thunder`, not `info_game_logic.instance.overrideSky`, and no transition |
| `OnSavingGame()` (78-82) | `savedWeather = ActiveWeatherIndex()` |
| `OnLoadingGame()` (84-92) | `SetWeather(savedWeather or 0, changeSpeed: true)` |
| `SetWeather(int index, bool changeSpeed, float transitionTime)` (211-223) | `weatherController.SetNewWeatherProfile(...)`; "Heavy Rain Intensity" >= 0.5 and the thunder roll -> `StartThunder()`, else `StopThunder()`; `ChangeWeather(transitionTime)` |
| `SetWeather(AzureWeatherProfile, float transitionLength = 10)` (225-231) | By profile name |
| `SetRandomWeather(float)` (233-237) | Random global profile; `SoundscapeController.instance.UpdateCurrentSoundscape()` |
| `ChangeWeather(float time)` (201-209) | `WeatherUpdated`; `WeatherTransitioning` each frame for `time` s |
| `ActiveWeather()`, `ActiveWeatherIndex()`, `WeatherCount()`, `WeatherName(int)` | Azure global profiles |
| `RainIntensity()`, `Light/Medium/HeavyRainIntensity()`, `WindIntensity()`, `Light/Medium/HeavyWindIntensity()` | Profile property sliders |
| `Temperature()` (337-344) | "Temperature" curve at the timeline x 40 - 20 (degrees) |
| `CurrentOutsideAmbience()` | "Environment Ambient Color" now |
| `StartThunder()`, `StopThunder()`, `ToggleThunder()`, `IsThunderActive()` | |
| `AddWeartherZone(AzureWeatherZone)` (346-352) | Adds to `weatherController.m_localWeatherZonesList` (no caller in code) |

## Azure local weather zones

`AzureWeatherController` (UnityEngine.AzureSky/AzureWeatherController.cs)
blends global profiles with `m_localWeatherZonesList`: each frame, for
each zone whose collider is enabled and `activeInHierarchy`, by the
distance of `m_localWeatherZoneTrigger` to the collider and the zone's
`blendDistance` (255-290). Switched-off zones are skipped.

## Indoor areas: the sky override

`TimeOfDayAzure` holds an `overrideSky` object with an
`AzureWeatherZone` (`overrideSkyZone`) and a default `overrideSkyProfile`
([`time.md`](time.md)):

- `DisableSky(AzureWeatherProfile profile)`: zone profile = `profile`
  or the default; `overrideSky` switched on: the area shows that profile,
  not the weather.
- `EnableSky()`: `overrideSky` switched off: the global weather shows.
- `SkyEnabled()`: `!overrideSky.activeInHierarchy`.

Callers: `info_game_logic.DelaySet()` (info_game_logic.cs:116-127), 0.1 s
realtime after its Start unless `disableOverrideSkyOnPlay`: `overrideSky`
-> `DisableSky(overrideProfile)`, else `EnableSky()`. `ShopController`
(ShopController.cs:160-198) disables the sky while a shop menu is open
and restores it on close. Per-area values: [`areas.md`](areas.md),
info_game_logic. Thunder does not strike while
`info_game_logic.instance.overrideSky`.

## Weather and WeatherChange

`[CreateAssetMenu] public class Weather : ScriptableObject` (Weather.cs):
`weatherName`, `propability`, `TimeAndDay durationMin`, `durationMax`,
`temperature`, `PrecipitationType precipitation` (None, Snow, Rain),
`List<ParticleInfo> particleSystems` (`particleSystem`, `offset`,
`controlEmissionRate`, `emissionRate`), `SoundInfo ambience`, `Vector2
wind`, `randomWind` (a value in `wind`). No code reads these assets in
this version (the Azure profiles drive the weather).

`WeatherChange : MonoBehaviour` (WeatherChange.cs): `ChangeWeather()` ->
`WeatherManager.instance.SetWeather(weatherProfile, transitionLength)`
(for relays).

## With areas kept loaded

`WeatherManager` and `TimeOfDayAzure` are the live copies from the area
the save loaded (one copy). `info_game_logic` is area-owned and its Start
runs again on every later visit (kept-areas.md), so `DelaySet` applies
the entered area's sky override, as on every game load.
