# obenseuer-mod open issues

| Priority | Area | Todo | Done when |
|---:|---|---|---|
| 1 | research | [ ] Research how the map uses the current area (MapController, Map, PlayerMarker; MapController.Start and OnLoadingGame call GetCurrentSceneMap) | research.md says, with lines, what picks the area's map and when; any kept-area gap is its own row |
| 1 | research | [ ] Research how relays and area logic start (Relay, RelayAuto, TriggerMultiple, ...; Relay.OnLoadingGame re-fires its start outputs on every load) | research.md says, with lines, which start outputs fire on which load or Start; any kept-area gap is its own row |
| 2 | research | [ ] Research how tasks and quests use areas (TaskController, TaskItemsManager, task triggers) | research.md says, with lines, which tasks check or react to the area; any kept-area gap is its own row |
| 2 | research | [ ] Research how dialogue triggers start (Pixel Crushers Dialogue System triggers on start or on area load) | research.md says, with lines, which triggers fire per load or Start; any kept-area gap is its own row |
| 3 | research | [ ] Research how the tenement uses areas (TenementController, TenementEventController.currentSceneResidents) | research.md says, with lines, what is per area; any kept-area gap is its own row |
| 3 | research | [ ] Research how police and crime follow the player through doors (Act_Police, pursuit) | research.md says, with lines, what a chasing NPC does at a door; any kept-area gap is its own row |
| 3 | research | [ ] Research how weather and indoor or outdoor areas work (WeatherManager, weather zones) | research.md says, with lines, how weather follows the area; any kept-area gap is its own row |
| 4 | research | [ ] Research how building and placed furniture use areas (BuildingSystem, FurniturePlaceable) | research.md says, with lines, what is per area; any kept-area gap is its own row |
| 4 | research | [ ] Research how fast travel moves the player (FastTravelController) | research.md says, with lines, whether it uses doors or normal loads; any kept-area gap is its own row |
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
