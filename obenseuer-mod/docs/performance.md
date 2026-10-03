# Performance

> **Authoritative on:** what the mod costs while running: loading areas
> alongside (frame times, loading priority), mod start (patching), and
> memory with areas kept loaded. What a door costs in the game:
> [`doors.md`](doors.md).
>
> Index of every game system's doc: [`research.md`](research.md).

## Background loading cost (2026-10-02)

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

The first-copy check itself: done from Rust it took about eight
reflection calls across the bridge per Awake or OnDestroy, each
marshalled as JSON, and made up 40 to 70% of the longest frame while an
area loaded alongside. The shim's FirstCopyGuard.cs now does it in one
call and finds each class's static field once (FirstCopyGuard.cs:1-6).

Whether the play-time delay is gone is not yet confirmed by the player.

## Memory and loads with every area loaded (2026-10-03)

With every area loaded alongside (106 scenes, research_light_probes.rs
with OBENSEUER_ALL_AREAS=1) the game used 13.6 GB, and loads alongside
took over 8 s with single frames of 1.7 to 1.8 s.
