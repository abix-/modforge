# obenseuer-mod open issues

| Priority | Area | Todo | Done when |
|---:|---|---|---|
| 2 | research | [ ] Map the save/load flow: which SavableScript subclasses hold player state, in what order | Save flow documented |
| 3 | research | [ ] Dump the full Items.json item count and category list | Category list in research.md |
| 3 | research | [ ] Dump the full Recipes.json recipe count and type list | Recipe types in research.md |
| 3 | research | [ ] Map the NPC scheduler: how Timetable entries drive NPC movement | Scheduler flow documented |
| 5 | kept_loaded.rs | [ ] Stop Pathfinding.RVO.Simulator.RemoveAgent "agent is not added" (2 per check with kept areas on, 0 with them off: the mod's) | The check shows 0 RemoveAgent errors |
| 6 | kept_loaded.rs | [ ] Find where the dead Spawner in TimeOfDayAzure's list comes from: NullReferenceException at Spawner.DeltaSeconds every frame (166631 in Player.log) after loading Tom_Tomato/Autosave, after failed kept-areas-off runs | The line that keeps the dead Spawner is named in docs/loading-research.md |
| 7 | scripts/restart.ps1 | [ ] Hot reload when only the Rust changed: the script finds the shim's hash changed after every build and closes the game | A Rust-only change deploys with "[ready] generation N answering; the game kept running" |
| 9 | kept_loaded.rs | [ ] Find the source of the one Transform.get_position NullReferenceException (not seen in the last check) | Its caller is named in docs/loading-research.md, or 3 checks in a row without it |
| 10 | kept_loaded.rs | [ ] Check AlarmClock, ToiletPaperHolder, SlotMachineGameplay, LoadOnLevelIni, which keep data in statics | Each one's result is in docs/loading-research.md |
| 11 | kept_loaded.rs | [ ] Check the classes whose OnEnable/OnDisable run each time an area is switched on and off (98 / 68) | Result in docs/loading-research.md, fixes as their own rows |
| 12 | kept_loaded.rs | [ ] Check the 2 sceneLoaded listeners and the game's searches that skip switched-off objects | Result in docs/loading-research.md |
| 13 | kept_loaded.rs | [ ] Fire the game's LoadingDone event on entering a kept area | Listeners run on entering, shown by a test |
| 14 | kept_loaded.rs | [ ] Run the DestructibleList save and load phases for kept areas | Destroyed objects stay destroyed after leaving and coming back |
| 15 | kept_loaded.rs | [ ] Check NPCManager.ActiveScene after a kept door | Test shows it names the area the player is in |
| 16 | kept_loaded.rs | [ ] Autosave at a kept door, as a normal door does | An Autosave file is written on a kept door trip |
| 17 | kept_loaded.rs | [ ] Use kept areas for doors used right after a save loads (door hook goes on only after the first area loads alongside) | First door after a load has no loading screen |
| 18 | kept_loaded.rs | [ ] Find whether kept areas add a LightController.Awake NullReferenceException (the game logs it too: 1 with kept areas off, 2 on, one run each) | 3 runs each way in docs/loading-research.md |
| 19 | first_copy_wins.rs | [ ] Stop the shim logging an error for each one-copy class without OnDestroy (about 37 "method 'OnDestroy' not found" at mod start) | No "not found" errors at mod start in LogOutput.log |
| 30 | kept_loaded.rs | [ ] Remove the 0.2 to 0.6s hitch when some areas are switched on | Longest frame on entering under 0.05s in the log |
| 31 | kept_loaded.rs | [ ] Cut the mod's part of a save (1.75s) | "save took" in the log under 0.5s |
| 32 | kept_loaded.rs | [ ] Measure and decide on memory (about 7 GB with about 30 areas) | Memory per area in docs/loading-research.md and a decision by the operator |
