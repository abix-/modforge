# obenseuer-mod open issues

| Priority | Area | Todo | Done when |
|---:|---|---|---|
| 1 | setup | [x] Install BepInEx 5.4.23.5 into the game directory | `BepInEx/` exists and the game launches with the BepInEx console |
| 1 | setup | [x] Deploy the unityforge C# shim as a BepInEx plugin | The shim loads and prints its init message in the BepInEx log |
| 1 | setup | [x] Build and deploy obenseuer_mod.unityforge.dll | The Rust cdylib loads and `on_init` runs (confirmed by log) |
| 1 | setup | [x] Verify the control plane answers a ping | Control plane answers on port 17175 |
| 1 | setup | [x] Restart script | `obenseuer-mod/scripts/restart.ps1` builds, deploys, restarts |
| 2 | research | [x] Decompile Assembly-CSharp.dll and document key classes | research.md section 9 |
| 2 | research | [x] Map how Items.json is loaded | research.md 9.16: ItemDatabase.Awake, File.ReadAllText, FullSerializer |
| 2 | research | [ ] Map the save/load flow: which SavableScript subclasses hold player state, in what order | Save flow documented |
| 1 | mod | [x] Decide initial mod goals | bigger inventory, increased stack sizes |
| 1 | mod | [x] Inventory: 70 slots (10 columns x 7 rows), UI panel widened left | Inventory opens with 10x7 grid in-game |
| 1 | mod | [x] Stacks: 10x multiplier on all stackable items (632 items) | Items stack to 990 in-game |
| 3 | research | [ ] Dump the full Items.json item count and category list | Category list in research.md |
| 3 | research | [ ] Dump the full Recipes.json recipe count and type list | Recipe types in research.md |
| 3 | research | [ ] Map the NPC scheduler: how Timetable entries drive NPC movement | Scheduler flow documented |
| 1 | deposit.rs | [x] F6 puts inventory and worn backpack items into nearby boxes that already hold the same item, range in settings | Committed; worked in game |
| 1 | kept_loaded.rs | [x] Load the areas behind the doors alongside, keep them switched off, move through a door with no loading screen | research_kept_scenario.rs: trips of 0.416s and 0.291s |
| 1 | first_copy_wins.rs | [x] A second copy of a one-copy class (public static field of its own type) does not take over | research_kept_scenario.rs: identity "Tom", 19 of 20 watched fields live |
| 1 | kept_loaded.rs | [x] Saved data applied on entering, captured on leaving, every visited area written on save | A save made away from home loaded back correctly (operator, 2026-10-02) |
| 1 | FirstCopyGuard.cs | [x] Skip OnDestroy of lava lamps in areas never entered | research_kept_scenario.rs: 0 LavaLamp errors across two normal loads |
| 1 | FirstCopyGuard.cs | [ ] Run OnDestroy of classes with an Awake in areas never entered (written, not built: the shim change needs a game restart) | research_kept_scenario.rs shows no "left ... Err ... InteractableChair.StopSitEnd" line |
| 2 | research_kept_scenario.rs | [ ] Find why WaitingUI gives "type not found" in the watched list | The check reports WaitingUI live, or the reason is in the test |
| 3 | research_kept_scenario.rs | [ ] Commit the automatic check | The file is in git and pushed |
| 4 | research_kept_scenario.rs | [ ] Leave the game's save name as it was after the check saves to ModTest | After the check, a manual save goes to the player's own slot |
| 5 | kept_loaded.rs | [ ] Find which of the check's errors the base game also logs, with the mod's kept areas off | The same door trips with auto off, errors listed side by side in docs/loading-research.md |
| 6 | kept_loaded.rs | [ ] Stop MoneyPanel.OnDisable NullReferenceException (5 per check) | The check shows 0 MoneyPanel errors |
| 7 | kept_loaded.rs | [ ] Stop Pathfinding.RVO.Simulator.RemoveAgent "agent is not added" (2 per check) | The check shows 0 RemoveAgent errors |
| 8 | kept_loaded.rs | [ ] Stop LightController.Awake NullReferenceException (2 per check) | The check shows 0 LightController errors |
| 9 | kept_loaded.rs | [ ] Find the source of the one Transform.get_position NullReferenceException | Its caller is named in docs/loading-research.md |
| 10 | kept_loaded.rs | [ ] Check AlarmClock, ToiletPaperHolder, SlotMachineGameplay, LoadOnLevelIni, which keep data in statics | Each one's result is in docs/loading-research.md |
| 11 | kept_loaded.rs | [ ] Check the classes whose OnEnable/OnDisable run each time an area is switched on and off (98 / 68) | Result in docs/loading-research.md, fixes as their own rows |
| 12 | kept_loaded.rs | [ ] Check the 2 sceneLoaded listeners and the game's searches that skip switched-off objects | Result in docs/loading-research.md |
| 13 | kept_loaded.rs | [ ] Fire the game's LoadingDone event on entering a kept area | Listeners run on entering, shown by a test |
| 14 | kept_loaded.rs | [ ] Run the DestructibleList save and load phases for kept areas | Destroyed objects stay destroyed after leaving and coming back |
| 15 | kept_loaded.rs | [ ] Check NPCManager.ActiveScene after a kept door | Test shows it names the area the player is in |
| 16 | kept_loaded.rs | [ ] Autosave at a kept door, as a normal door does | An Autosave file is written on a kept door trip |
| 17 | kept_loaded.rs | [ ] Use kept areas for doors used right after a save loads (door hook goes on only after the first area loads alongside) | First door after a load has no loading screen |
| 30 | kept_loaded.rs | [ ] Remove the 0.2 to 0.6s hitch when some areas are switched on | Longest frame on entering under 0.05s in the log |
| 31 | kept_loaded.rs | [ ] Cut the mod's part of a save (1.75s) | "save took" in the log under 0.5s |
| 32 | kept_loaded.rs | [ ] Measure and decide on memory (about 7 GB with about 30 areas) | Memory per area in docs/loading-research.md and a decision by the operator |
