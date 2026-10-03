# obenseuer-mod open issues

| Priority | Area | Todo | Done when |
|---:|---|---|---|
| 5 | research | [ ] Map the save/load flow: which SavableScript subclasses hold player state, in what order | Save flow documented |
| 6 | research | [ ] Dump the full Items.json item count and category list | Category list in research.md |
| 6 | research | [ ] Dump the full Recipes.json recipe count and type list | Recipe types in research.md |
| 6 | research | [ ] Map the NPC scheduler: how Timetable entries drive NPC movement | Scheduler flow documented |
| 10 | scripts/restart.ps1 | [ ] Hot reload when only the Rust changed: the script finds the shim's hash changed after every build and closes the game | A Rust-only change deploys with "[ready] generation N answering; the game kept running" |
| 11 | kept_loaded.rs | [ ] Find the source of the one Transform.get_position NullReferenceException (seen in 3 of 5 checks with kept areas on) | Its caller is named in docs/loading-research.md |
| 19 | FirstCopyGuard.cs | [ ] One MoneyPanel.OnDisable NullReferenceException got through the never-started finalizer in the `OBENSEUER_DOOR_AT_ONCE=1` check (first door right after the load); find from its stack in Player.log which object and why it was not counted as never entered | Its cause named in docs/loading-research.md, or 3 at-once checks without it |
| 21 | first_copy_wins.rs | [ ] Stop the shim logging an error for each one-copy class without OnDestroy (about 37 "method 'OnDestroy' not found" at mod start) | No "not found" errors at mod start in LogOutput.log |
| 22 | kept_loaded.rs | [ ] Measure what areas left (switched off, not unloaded) do with game-wide events they still get (docs/kept-areas.md, differences) | Result in docs/loading-research.md and a decision by the operator |
| 23 | FirstCopyGuard.cs | [ ] Mod start takes 3.2s since the one-copy check reads Awake and OnEnable (was 0.6s); measure which part | first_copy_wins on under 1s in the log |
| 30 | kept_loaded.rs | [ ] Remove the 0.2 to 0.6s hitch when some areas are switched on | Longest frame on entering under 0.05s in the log |
| 31 | kept_loaded.rs | [ ] Cut the mod's part of a save (1.75s) | "save took" in the log under 0.5s |
| 32 | kept_loaded.rs | [ ] Measure and decide on memory (about 7 GB with about 30 areas) | Memory per area in docs/loading-research.md and a decision by the operator |
