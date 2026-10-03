# obenseuer-mod open issues

| Priority | Area | Todo | Done when |
|---:|---|---|---|
| 1 | kept_loaded.rs | [ ] The map does not follow a kept door: MapController's current map (`currentSceneMapInfo`, landmarks) and the map panel's image are set only in their Start and MapController's OnLoadingGame (research.md 9.37, the map); landmarks found in another area go into the save's area's map record | After a kept door the map panel shows the entered area's map image and landmarks, shown by a test |
| 1 | kept_loaded.rs | [ ] Relays with `triggerAtStart` fire only on the first visit to a kept area; in the game they fire on every area load (research.md 9.37, relays) | A test shows a start relay's outputs fire again on a second kept door into its area |
| 1 | kept_loaded.rs | [ ] A relay's delayed output stops when its kept area is switched off and is never restarted; in the game OnLoadingGame restarts it from the saved `delayLeft` (research.md 9.37, relays) | A test shows a delayed output started before a kept door fires after coming back |
| 1 | research | [ ] Research the other area logic that starts like relays (RelayAuto, TriggerMultiple, ...) and count relays per area with one in-game call that returns only the counts | research.md says, with lines, which start outputs fire on which load or Start; any kept-area gap is its own row |
| 2 | research | [ ] Research how tasks and quests use areas (TaskController, TaskItemsManager, task triggers) | research.md says, with lines, which tasks check or react to the area; any kept-area gap is its own row |
| 2 | research | [ ] Research how dialogue triggers start (Pixel Crushers Dialogue System triggers on start or on area load) | research.md says, with lines, which triggers fire per load or Start; any kept-area gap is its own row |
| 3 | kept_loaded.rs | [ ] A tenement event for a resident whose area was left can run that area's spawner while it is switched off; in the game that area's objects are gone (research.md 9.37, the tenement) | A test shows a tenement event for a left area spawns nothing there |
| 3 | kept_loaded.rs | [ ] `currentSceneResidents` keeps the residents of areas left (their NPC objects are switched off, not destroyed); in the game it holds the current area's only (research.md 9.37, the tenement) | Operator decides whether renting may hide a resident in another kept area |
| 3 | research | [ ] Research how police and crime follow the player through doors (Act_Police, pursuit) | research.md says, with lines, what a chasing NPC does at a door; any kept-area gap is its own row |
| 3 | research | [ ] Research how weather and indoor or outdoor areas work (WeatherManager, weather zones) | research.md says, with lines, how weather follows the area; any kept-area gap is its own row |
| 4 | research | [ ] List every FurnitureManager GUID per area with one in-game call; a GUID shared by two areas puts furniture under the wrong area's manager with kept areas (research.md 9.37, building) | research.md has the list and says whether any GUID is shared |
| 4 | kept_loaded.rs | [ ] On a later visit to a kept area the player's build space (`activeManager`) is not set back from the save, only by walking into it; in the game the load sets it (research.md 9.37, building) | A test shows a door out of and back into a build space leaves the build menu as the game does |
| 1 | research | [ ] Prison, sleep events, blackouts and ChangeScene take the game's normal load, not the kept door (research.md 9.37, area changes other than doors); find what the mod does with kept areas on a normal load | research.md says, with kept_loaded.rs lines, what happens to the kept areas on a normal load; any gap is its own row |
| 4 | research | [ ] Read what the fast travel menu's buttons call (set in the scene, not in code) | research.md names the method and whether it is a normal load |
| 5 | research | [ ] Map the save/load flow: which SavableScript subclasses hold player state, in what order | Save flow documented |
| 6 | research | [ ] Dump the full Items.json item count and category list | Category list in research.md |
| 6 | research | [ ] Dump the full Recipes.json recipe count and type list | Recipe types in research.md |
| 6 | research | [ ] Map the NPC scheduler: how Timetable entries drive NPC movement | Scheduler flow documented |
| 10 | scripts/restart.ps1 | [ ] Hot reload when only the Rust changed: the script finds the shim's hash changed after every build and closes the game | A Rust-only change deploys with "[ready] generation N answering; the game kept running" |
| 11 | kept_loaded.rs | [ ] Find the source of the one Transform.get_position NullReferenceException (seen in 3 of 5 checks with kept areas on) | Its caller is named in docs/loading-research.md |
| 19 | kept_loaded.rs | [ ] A door into an area still loading moved the player in the frame it finished loading, before its player setup was switched off (cause in docs/loading-research.md, "First door right after a load"); the waiting door now moves one frame later (built, not deployed) | 3 `OBENSEUER_DOOR_AT_ONCE=1` checks without a MoneyPanel.OnDisable error |
| 21 | first_copy_wins.rs | [ ] Stop the shim logging an error for each one-copy class without OnDestroy (about 37 "method 'OnDestroy' not found" at mod start) | No "not found" errors at mod start in LogOutput.log |
| 22 | kept_loaded.rs | [ ] Measure what areas left (switched off, not unloaded) do with game-wide events they still get (docs/kept-areas.md, differences) | Result in docs/loading-research.md and a decision by the operator |
| 23 | FirstCopyGuard.cs | [ ] Mod start takes 3.2s since the one-copy check reads Awake and OnEnable (was 0.6s); measure which part | first_copy_wins on under 1s in the log |
| 30 | kept_loaded.rs | [ ] Remove the 0.2 to 0.6s hitch when some areas are switched on | Longest frame on entering under 0.05s in the log |
| 31 | kept_loaded.rs | [ ] Cut the mod's part of a save (1.75s) | "save took" in the log under 0.5s |
| 32 | kept_loaded.rs | [ ] Measure and decide on memory (about 7 GB with about 30 areas) | Memory per area in docs/loading-research.md and a decision by the operator |
