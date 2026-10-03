# Lighting

> **Authoritative on:** lighting: baked lightmaps (Bakery
> `ftLightmapsStorage`), light probes, the lightmap mode, the game's light
> management (`LightController`, `LightsController` and light zones,
> `CullingController`, `WindowNaturalLight`), and lighting with two or
> more areas loaded.
>
> Index of every game system's doc: [`research.md`](research.md).

## Baked lighting (research_light_probes.rs, every area loaded alongside, 106 scenes, 2026-10-03)

The game uses no light probes (0) and never touches `LightProbes` or
`LightmapSettings`. Baked lightmaps come from Bakery
(BakeryRuntimeAssembly.dll): one `ftLightmapsStorage` per area adds its
lightmaps in Awake (`ftLightmaps.RefreshScene`, reference counted) and
removes them in OnDestroy (`UnloadScene`); the game-wide lightmap mode is
the last store's (`directionalMode`), applied on every active scene
change. 50 stores: 47 without lightmaps, 3 with (Interior Tenement
Deekula Mine Entrance 32, Interior Tenement Caravan 22, Interior Bazaar
Bar 22), none directional: the mode is NonDirectional for every area.
Memory and load times in that run: [`performance.md`](performance.md).

## LightController

`public class LightController : MonoBehaviour` (LightController.cs). On a
`Light`; turns it off or drops shadows by distance and zone.

| Member | Meaning |
|---|---|
| `Light cullLight`, `HxVolumetricLight volumetricLight`, `HxDummyLight dummyLight` | Parts (Awake) |
| `float TurnOffDistance`, `ShadowOffDistance`, `ShadowDistance` | Distances; default `range * 3.15`, at least 5 |
| `bool NoShadows`, `SmoothTransition`, `overrideTurnOff`, `disabled`, `moving`, `movingInSingleZone`, `culling` | Options |
| `float originalIntensity`, `intensityMultiplier` | |
| `Awake()` (63-104) | Reads the light (`cullLight.intensity`; **NullReferenceException when there is no Light**, the game's own scene mistake, logged when such an area loads) |
| `Start()` (106-145) | Not moving: added to `LightsController.controllerstatus`, `controllersAll`, `orphanControllers`; into the first `LightCullZone` in `LightsController.allZones` whose box contains it; tag "NaturalLightSource" -> `WindowNaturalLight.instance.AddLightSource(this)`; `culling` -> `CullingController.instance.AddToCullingGroup(Light, Cull, sphere)` |
| `Override(bool state)` (152-) | Zone visibility |
| `Update()` (207-) | Distance to `PlayerLocator` decides on, shadows, off |
| `Cull(bool visible)` (360-) | Camera culling callback |
| OnDestroy (396-412) | Removed from the static lists |

## LightsController

`public class LightsController : MonoBehaviour` (LightsController.cs). In
Game_Logic/Controllers. One copy (`instance`).

| Member | Meaning |
|---|---|
| `static List<LightController> controllersAll`, `orphanControllers` | All lights; lights in no zone |
| `static List<LightCullZone> allZones` | Light zones |
| `static Dictionary<LightController, bool> controllerstatus` | Visible per light |
| `static LightCullZone CurrentZone` (38-63) | The zone the player is in; setting it tests the zone and its links, schedules an update; null -> orphan lights visible; ignored while `TimeOfDayAzure.updateTimeDisabled` |
| `Awake()` (65-74) | `instance`; **resets every static list** |
| `LateUpdate()` (93-101) | `ApplyLightOverrideStatus()`: `Override(status)` on every light in `controllerstatus` |
| `SetLightStatusAllHidden`, `SetLightStatusAllVisible`, `SetLightStatusAllHiddenOnce`, `UpdateLightOverrideStatus()`, `disableAllLightControllers` | |
| Ambient colour change (`changeAmbientColor`) | |

`CameraShake` (CameraShake.cs:114) iterates `controllersAll`.

## CullingController

`public class CullingController : MonoBehaviour` (CullingController.cs).
Unity `CullingGroup`s per type (Default, NPC, Light).
`AddToCullingGroup(CullingType, Action<bool> cb, BoundingSphere)` (51-65)
returns a `CullingItem`; `RemoveFromCullingGroup(item)`;
`UpdatePosition(item)`; callbacks on visibility changes (110-138).

## WindowNaturalLight

`public class WindowNaturalLight : MonoBehaviour` (WindowNaturalLight.cs).
One copy. Colours natural light sources and windows from the weather.

| Member | Does |
|---|---|
| `static event Action SourcesChanged` | |
| `Start()` (44-) | `TimeOfDayAzure.SecondsPassed += DeltaSeconds` |
| `AddLightSource(LightController)`, `RemoveLightSource(LightController)` (56-71) | |
| `BuildWindowsList()`, `AppendWindowsList(GameObject)` | Window materials |
| `InNaturallightRadius(Transform, float, bool)`, `static HasObstruction(...)` | Sunlight queries (used by growing, `NaturalLightSourceChecker`) |
| `UpdateLights(bool Force)` (178-209) | Sets each light's colour from `WeatherManager.instance.CurrentOutsideAmbience()` |

`info_lighting_settings`: one copy, destroys a second copy in Awake and
OnEnable; nothing reads it.

## Lighting with two areas (2026-10-02)

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

## With areas kept loaded

- Lightmaps: each kept area's Bakery store stays registered while it is
  loaded; the mode is NonDirectional everywhere, so the last store's mode
  does not change anything.
- `LightsController` is one copy (first_copy_wins), so its static lists
  are not reset by later areas: `controllersAll`, `controllerstatus` and
  `allZones` collect the lights and zones of every kept area entered
  (their Start runs on the first visit). `ApplyLightOverrideStatus` calls
  `Override` on lights in switched-off areas too (effect not checked).
- `WindowNaturalLight`, `CullingController`: the live copies collect the
  lights of every kept area entered.
