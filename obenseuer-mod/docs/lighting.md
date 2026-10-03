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
With that many areas loaded the game used 13.6 GB, and loads alongside
took over 8 s with single frames of 1.7 to 1.8 s.

## Lights in areas

LightController registers with CullingController and WindowNaturalLight
in Start and is removed only in OnDestroy (WindowNaturalLight only sets
each light's colour from the weather, WindowNaturalLight.cs:178-209; see
[`areas.md`](areas.md)). The game's own error: LightController.Awake
NullReferenceException on a LightController with no Light
(`cullLight.intensity`), logged when such an area loads.
`info_lighting_settings`: one copy, destroys a second copy in Awake and
OnEnable; nothing reads it.
