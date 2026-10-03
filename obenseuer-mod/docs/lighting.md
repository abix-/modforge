# Lighting

> **Authoritative on:** light probes, baked lightmaps (Bakery), and the
> lightmap mode with areas loaded together.
>
> Index of every game system's doc: [`research.md`](research.md).

## Light probes and lightmaps (research_light_probes.rs, every area loaded alongside, 106 scenes, 2026-10-03)

The game uses no light probes (0) and never touches LightProbes or
LightmapSettings. Baked lightmaps come from Bakery
(BakeryRuntimeAssembly.dll): one `ftLightmapsStorage` per area adds its
lightmaps in Awake (`ftLightmaps.RefreshScene`, reference counted) and
removes them in OnDestroy (`UnloadScene`); the game-wide lightmap mode is
the last store's (`directionalMode`), applied on every active scene
change. 50 stores: 47 without lightmaps, 3 with (Interior Tenement
Deekula Mine Entrance 32, Interior Tenement Caravan 22, Interior Bazaar
Bar 22), none directional: the mode is NonDirectional for every area.
Memory and load times in that run: [`performance.md`](performance.md).

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
looked right with them still on. Checked in one area pair only. This
answers the open question whether each area's lighting and sky clash
when two areas are loaded at once: they do only through the second
`Game_Logic`'s sky.

## Lights in areas

LightController registers with CullingController and WindowNaturalLight
in Start and is removed only in OnDestroy (WindowNaturalLight only sets
each light's colour from the weather, WindowNaturalLight.cs:178-209; see
[`areas.md`](areas.md)). The game's own error: LightController.Awake
NullReferenceException on a LightController with no Light
(`cullLight.intensity`), logged when such an area loads.
`info_lighting_settings`: one copy, destroys a second copy in Awake and
OnEnable; nothing reads it.
