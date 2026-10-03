# obenseuer-mod open issues

| Priority | Area | Todo | Done when |
|---:|---|---|---|
| 2 | research | [ ] Map the save/load flow: which SavableScript subclasses hold player state, in what order | Save flow documented |
| 3 | research | [ ] Dump the full Items.json item count and category list | Category list in research.md |
| 3 | research | [ ] Dump the full Recipes.json recipe count and type list | Recipe types in research.md |
| 3 | research | [ ] Map the NPC scheduler: how Timetable entries drive NPC movement | Scheduler flow documented |
| 5 | kept_loaded.rs | [ ] A second visit to an area that is not home finds no arrival point and falls back to a normal load (tenement, Open Sewer Tenement, tenement, Open Sewer Tenement: "no arrival point PlayerTenement_Out") | That trip moves without a loading screen, shown by the check |
| 6 | kept_loaded.rs | [ ] Fire SavingStarted and SavingDone around the capture on leaving, as SaveGame does (SaveController.cs:452) | The check passes; listeners run, shown by a test |
| 7 | kept_loaded.rs | [ ] Fire LoadingStarted before the load phases on entering (SaveController.cs:640) | Listeners run on entering, shown by a test |
| 8 | kept_loaded.rs | [ ] Run OnLoadingGame and LatePrimary one frame after Primary to Tertiary, as the game does (SaveController.cs:647) | The check passes with no new errors |
| 9 | kept_loaded.rs | [ ] Apply the dialogue data on entering, as the game does (SaveController.cs:656-659) | Dialogue state matches after a kept door, shown by a test |
| 10 | scripts/restart.ps1 | [ ] Hot reload when only the Rust changed: the script finds the shim's hash changed after every build and closes the game | A Rust-only change deploys with "[ready] generation N answering; the game kept running" |
| 11 | kept_loaded.rs | [ ] Find the source of the one Transform.get_position NullReferenceException (seen in 3 of 5 checks with kept areas on) | Its caller is named in docs/loading-research.md |
| 12 | kept_loaded.rs | [ ] Check AlarmClock, ToiletPaperHolder, SlotMachineGameplay, LoadOnLevelIni, which keep data in statics | Each one's result is in docs/loading-research.md |
| 13 | kept_loaded.rs | [ ] Check the classes whose OnEnable/OnDisable run each time an area is switched on and off (98 / 68) | Result in docs/loading-research.md, fixes as their own rows |
| 14 | kept_loaded.rs | [ ] Check the 2 sceneLoaded listeners and the game's searches that skip switched-off objects | Result in docs/loading-research.md |
| 15 | kept_loaded.rs | [ ] Fire the game's LoadingDone event on entering a kept area | Listeners run on entering, shown by a test |
| 16 | kept_loaded.rs | [ ] Run the DestructibleList load steps for kept areas (SaveController.cs:645-646, 650) | Destroyed objects stay destroyed after leaving and coming back |
| 17 | kept_loaded.rs | [ ] Check NPCManager.ActiveScene after a kept door | Test shows it names the area the player is in |
| 18 | kept_loaded.rs | [ ] Autosave at a kept door, as a normal door does | An Autosave file is written on a kept door trip |
| 19 | kept_loaded.rs | [ ] Use kept areas for doors used right after a save loads (door hook goes on only after the first area loads alongside) | First door after a load has no loading screen |
| 20 | kept_loaded.rs | [ ] Find whether kept areas add a LightController.Awake NullReferenceException (the game logs it too: 1 with kept areas off, 2 on, one run each) | 3 runs each way in docs/loading-research.md |
| 21 | first_copy_wins.rs | [ ] Stop the shim logging an error for each one-copy class without OnDestroy (about 37 "method 'OnDestroy' not found" at mod start) | No "not found" errors at mod start in LogOutput.log |
| 22 | kept_loaded.rs | [ ] Measure what areas left (switched off, not unloaded) do with game-wide events they still get (switched-off Spawners get SecondsPassed) | Result in docs/loading-research.md and a decision by the operator |
| 30 | kept_loaded.rs | [ ] Remove the 0.2 to 0.6s hitch when some areas are switched on | Longest frame on entering under 0.05s in the log |
| 31 | kept_loaded.rs | [ ] Cut the mod's part of a save (1.75s) | "save took" in the log under 0.5s |
| 32 | kept_loaded.rs | [ ] Measure and decide on memory (about 7 GB with about 30 areas) | Memory per area in docs/loading-research.md and a decision by the operator |
