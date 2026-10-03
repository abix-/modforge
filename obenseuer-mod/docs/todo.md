# obenseuer-mod open issues

| Priority | Area | Todo | Done when |
|---:|---|---|---|
| 1 | kept_loaded.rs | [ ] Rule 2 (docs/kept-areas.md): entering an area is one function that runs the table's steps 1 to 12 in order, area-owned managers set to the area's copy | The check passes with no new errors; a second visit to an area that is not home moves without a loading screen |
| 2 | kept_loaded.rs | [ ] Rule 3 (docs/kept-areas.md): leaving an area is one function that runs the table's steps 1 to 11 in order | The check passes with no new errors |
| 23 | FirstCopyGuard.cs | [ ] Mod start takes 3.2s since the one-copy check reads Awake and OnEnable (was 0.6s); measure which part | first_copy_wins on under 1s in the log |
| 4 | kept_loaded.rs | [ ] The mod's own state (docs/kept-areas.md): cleared on every normal load, not only the mod's own reload | After a normal load the mod did not start (the menu), the load_alongside op shows only the new area |
| 5 | research | [ ] Map the save/load flow: which SavableScript subclasses hold player state, in what order | Save flow documented |
| 6 | research | [ ] Dump the full Items.json item count and category list | Category list in research.md |
| 6 | research | [ ] Dump the full Recipes.json recipe count and type list | Recipe types in research.md |
| 6 | research | [ ] Map the NPC scheduler: how Timetable entries drive NPC movement | Scheduler flow documented |
| 10 | scripts/restart.ps1 | [ ] Hot reload when only the Rust changed: the script finds the shim's hash changed after every build and closes the game | A Rust-only change deploys with "[ready] generation N answering; the game kept running" |
| 11 | kept_loaded.rs | [ ] Find the source of the one Transform.get_position NullReferenceException (seen in 3 of 5 checks with kept areas on) | Its caller is named in docs/loading-research.md |
| 12 | kept_loaded.rs | [ ] Check AlarmClock, ToiletPaperHolder, SlotMachineGameplay, LoadOnLevelIni, which keep data in statics | Each one's result is in docs/loading-research.md |
| 13 | kept_loaded.rs | [ ] Check the classes whose OnEnable/OnDisable run each time an area is switched on and off (98 / 68) | Result in docs/loading-research.md, fixes as their own rows |
| 14 | kept_loaded.rs | [ ] Check the 2 sceneLoaded listeners and the game's searches that skip switched-off objects | Result in docs/loading-research.md |
| 17 | kept_loaded.rs | [ ] Check NPCManager.ActiveScene after a kept door | Test shows it names the area the player is in |
| 18 | kept_loaded.rs | [ ] Decide: autosave at a kept door, as a normal door does (docs/kept-areas.md, differences) | Operator's decision in docs/kept-areas.md |
| 19 | kept_loaded.rs | [ ] Use kept areas for doors used right after a save loads (door hook goes on only after the first area loads alongside) | First door after a load has no loading screen |
| 20 | kept_loaded.rs | [ ] Find whether kept areas add a LightController.Awake NullReferenceException (the game logs it too: 1 with kept areas off, 2 on, one run each) | 3 runs each way in docs/loading-research.md |
| 21 | first_copy_wins.rs | [ ] Stop the shim logging an error for each one-copy class without OnDestroy (about 37 "method 'OnDestroy' not found" at mod start) | No "not found" errors at mod start in LogOutput.log |
| 22 | kept_loaded.rs | [ ] Measure what areas left (switched off, not unloaded) do with game-wide events they still get (docs/kept-areas.md, differences) | Result in docs/loading-research.md and a decision by the operator |
| 30 | kept_loaded.rs | [ ] Remove the 0.2 to 0.6s hitch when some areas are switched on | Longest frame on entering under 0.05s in the log |
| 31 | kept_loaded.rs | [ ] Cut the mod's part of a save (1.75s) | "save took" in the log under 0.5s |
| 32 | kept_loaded.rs | [ ] Measure and decide on memory (about 7 GB with about 30 areas) | Memory per area in docs/loading-research.md and a decision by the operator |
