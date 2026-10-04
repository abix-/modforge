# obenseuer-mod changelog

## Changelog rules

These rules govern `docs/changelog.md`. Follow them exactly.

- Each day has exactly one `## YYYY-MM-DD` heading and exactly one table below
  it.
- Every daily table has exactly three columns: `System`, `Item`, and
  `Done when`.
- Start every Item with `[x]`. No preceding hyphen. Changelog rows are
  completed work only.
- Never combine completed items into one changelog row. Never replace them with
  a summary paragraph, grouped bullet, status paragraph, or count.
- When recording a completed todo row, copy its System into `System`, its
  completed instruction into `Item`, and its completion proof into `Done when`.
- Verify the exact result before adding the changelog row.
- Leave unfinished work in the todo. Do not add partial work to the changelog.
- Put new days above older days. Add rows to the existing table when that date
  already exists. Never create a second heading or second table for the same
  day.
- Use plain terms. Do not use vague descriptions, invented language, or design
  essays.

## 2026-10-04

| System | Item | Done when |
|---|---|---|
| research | [x] Objects switched off and on keep or lose state the game rebuilds: animators | `research_kept_scenario.rs` (SceneTools.AnimatorStates): Open Sewer Tenement's animators after the later kept door against the game's load, 142 = 142 (the player setup's own left out) |
| kept_loaded.rs, unityforge SceneTools.cs | [x] An area's background sound plays again after a later kept door (its soundscapes' coroutine lists emptied as fresh ones), and sounds scripts started play again (remembered on switch-off, started on switch-on before the load steps) (sound.md) | `research_kept_scenario.rs` (SceneTools.PlayingSounds), Open Sewer Tenement: 45 and 41 sounds, the 4 different soundscape loops only (they play by chance); before 43 and 32 |
| kept_loaded.rs | [x] On a later visit to a kept area the player's build space (`activeManager`) is set back as the game's load does: the area's FurnitureManager saved as `isActive` (`build_space_again`; building.md) | `research_kept_scenario.rs` after every door: Interior Player Tenement 23 build spaces, the active one set on the first and the later visit; Open Sewer Tenement and Under Map none; passed |
| kept_loaded.rs | [x] The sound starts from nothing on every kept door, as the game's rebuilt SoundscapeController does (`fresh_sound`; new sound.md) | `research_kept_scenario.rs`: global sound the area's after every door (none in Under Map, which has no day or night sound, research_soundscape.rs), the sound playing the area's; passed with Open Sewer Tenement and Under Map |
| unityforge FirstCopyGuard.cs, SceneTools.cs | [x] An area without a copy of an area-owned manager leaves its `instance` empty, and a copy in an area loading alongside or never entered never takes it (kept-areas.md, rule 1) | research_map.rs in Under Map before: info_map.instance in Interior Tenement B; `research_kept_scenario.rs` after: "map: none in Under Map", one-copy fields all live (an empty one only where the area has no object of the class) |

| System | Item | Done when |
|---|---|---|
| research | [x] Research how weather and indoor or outdoor areas work (WeatherManager, weather zones) | weather.md: one global WeatherManager; indoor areas switch TimeOfDayAzure's override sky zone from info_game_logic's Start, which the mod re-runs on every kept visit; no kept-area gap found |
| docs | [x] The game system docs rewritten as API references from the decompiled source: dialogue, lighting, player, items, economy, and info_game_logic in areas | Same form as below; new gaps added to the todo (dialogue managers, shop state, storage restock away) |
| docs | [x] The game system docs rewritten as API references from the decompiled source: map, relays, doors, save, time, npcs, pathfinding, tenement, building, crime, weather | Each lists fields (type, saved or not), methods (signature, lines), events, flows, and a kept-areas section; new gaps added to the todo |
| docs | [x] loading-research.md moved into the authoritative docs, every section kept: door timing and early loads to doors.md; what an area brings, links to managers, one copy per area to areas.md; lighting with two areas to lighting.md; background loading cost to a new performance.md; running tests, getting unstuck, investigating to a new testing.md; everything tried for the mod to kept-areas.md, history; its open questions to the todo (the lighting one answered in lighting.md); then removed | research.md lists performance.md and testing.md; no doc or code comment names loading-research.md |
| docs | [x] Doors and moving between areas get one doc: the door step by step (from save.md), arrival points and area changes other than doors (from areas.md) | doors.md, listed in research.md; save.md and areas.md link to it |
| docs | [x] One doc per game system, each with an "Authoritative on" line; research.md is the index | research.md lists game.md, areas.md, save.md, time.md, npcs.md, pathfinding.md, relays.md, map.md, tenement.md, building.md, crime.md, weather.md, dialogue.md, lighting.md, player.md, items.md, economy.md |
| research | [x] Map the save/load flow: which SavableScript subclasses hold player state, in what order | save.md, player state in the save |
| research | [x] Map the NPC scheduler: how Timetable entries drive NPC movement | npcs.md, the scheduler, timetable to movement |
| research | [x] Find what the mod does with kept areas on a normal load (prison, sleep events, blackouts, ChangeScene) | doors.md, with kept_loaded.rs lines |
| research | [x] Research how relays start (Relay.cs) | relays.md, with lines; two gaps in the todo |
| research | [x] Research how the tenement uses areas | tenement.md, with lines; two gaps in the todo |
| research | [x] Research how building and placed furniture use areas | building.md, with lines; two rows in the todo |
| research | [x] Research crime and the area changes that are not doors | crime.md and doors.md, with lines |
| kept_loaded.rs, unityforge EventTools.cs | [x] In areas left only the objects the game catches up on load (`savedTimeAndDay`) keep the game's clock; every other clock listener is taken out (Prison kept lowering crimes, RelayPlayerDistance fired each day) | The check passes with only LightController.Awake; handlers out leaving Open Sewer Tenement 1288 (631 with the whole clock kept, 1584 with none) |
| kept_loaded.rs, unityforge EventTools.cs, FileTools.cs | [x] Areas left keep hearing the game's clock (SecondsPassed, MinutePassed, DayChanged, CurrentTimeAndDay; not their area-owned managers), so time passes there as the game's load would catch it up; the area's navigation loads before it switches on | The check passes with only LightController.Awake (the game's own); the NavmeshTile.GetVertex and CollectibleTaskItem.Start errors of the load-step catch-up and the late navigation load are gone; handlers out leaving Open Sewer Tenement 631, the tenement 71 |
| kept_loaded.rs, first_copy_wins.rs, unityforge FirstCopyGuard.cs, SceneTools.cs | [x] A manager's static may be private (info_navigation, SkyCamera); info_navigation and SkyCamera area-owned; the area's navigation loads on every entering; only Game_Logic's area-owned objects are moved; the 4 loops started in Start start again on later visits; followers follow into the area the player is in | The check passes (two round trips, NPCs, sound, radiation, managers, identity); Player.log "Nav file loaded!" 7 times in the run (4 kept doors, 3 normal loads); follower and door patches on, no "patch failed". Followers and the loops not checked in play |
| kept_loaded.rs, unityforge EventTools.cs, FirstCopyGuard.cs | [x] The door mirrors the game's: rule 3's steps while the area is on, the player moves out, a physics step passes (its zones see the player leave), then the area switches off and rule 2 runs; handlers on the managers' instance events taken out and put back too | The check passes with two round trips (NPCs, sound, radiation, managers, identity); handlers out leaving the tenement 388 (359 with static events only), Open Sewer Tenement 1584 (1535). StrictArea in a zone at a door not checked |
| kept_loaded.rs | [x] NPCs of an area left are recorded by the game's NPCData.OnSavingGame and unbound as their destruction would (scheduler.OnDestroy, no controller); NPCManager.Start runs again on later visits to reconcile the area's NPCs | Before: the check's save recorded Open Sewer Tenement's Market Square Police and Backyard Police as in the Gatehouse. After: "NPCs of Open Sewer Tenement after the save: 2, recorded as in Interior Player Tenement: []", the check passes |
| kept_loaded.rs | [x] Use kept areas for doors used right after a save loads: the door patch is put on once at mod start (it was put on after the first area loaded alongside) and does nothing with kept areas off | `OBENSEUER_DOOR_AT_ONCE=1` check passes: the first door right after the load is a trip through the mod (0.664s), kept areas kept, three more doors |
| research_kept_scenario.rs | [x] The check asserts the sound playing after a door is the entered area's (not only the global one) | The two-round check passes with "sound: the area's own" after every door |
| unityforge EventTools.cs, kept_loaded.rs, first_copy_wins.rs | [x] Areas left stop reacting to the game's static events: their handlers are taken out on leaving and put back on entering (once); SoundscapeGlobal area-owned; info_game_logic.Start and SoundscapeGlobal.Start run again on later visits | The check passes with two round trips: after every kept door the global sound belongs to the area entered and stays so; the log shows "event handlers out 359" leaving the tenement and 358 back entering it |
| tests/common/mod.rs | [x] Tests wait as long as the mod's ops (30 s) and read a manager's instance with retries (`instance_of`) | Reads that failed right after doors no longer fail the check (research_managers_live.rs showed every manager live) |
| first_copy_wins.rs, kept_loaded.rs | [x] info_game_logic area-owned (the area's settings: prison, safety, radiation, sky), its Start run on every entering as every visit is a fresh load in the game | `OBENSEUER_AWAY="Under Map"` check: after the door the live RadiationController.backgroundRadiation is Under Map's own 89.0 (the tenement's is 0.0004); identity "Tom" kept; research_area_settings.rs values in areas.md, info_game_logic |
| first_copy_wins.rs, kept_loaded.rs | [x] NPCManager, info_map, info_water_source area-owned (the rule and the scan of 199 managers in docs); area-owned managers set before the area switches on | The check passes with two round trips and asserts NPCManager.ActiveScene names the area entered after every kept door; only the check's own loads |
| kept_loaded.rs | [x] Decide: autosave at a kept door | Operator: no autosave at doors, the player saves (docs/kept-areas.md, differences) |
| kept_loaded.rs | [x] Rule 3 (docs/kept-areas.md): leaving an area is one function (`leave_area`) that runs the table's steps 1 to 11 in order, the area's DestructibleList saved (step 5), the area always switched off (step 11) | The check passes with two round trips and 1 game error (LightController.Awake, the game's own); every leaving logs Ok |
| kept_loaded.rs | [x] Rule 2 (docs/kept-areas.md): entering an area is one function (`enter_area`) that runs the table's steps 1 to 12 in order, area-owned managers set to the area's copy, the arrival point read from the area's own list | The check passes with two round trips, no new errors; every entry logs LoadingStarted, saved data (with the DestructibleList steps on a first visit), OnMapChanged, LoadingDone all Ok |
| unityforge FirstCopyGuard.cs, SceneTools.cs | [x] Rule 1, which copy (docs/kept-areas.md): a manager is a class whose Awake or OnEnable sets its self-typed static field or property to itself; area-owned managers (PlayerLevelEntrypoints, DestructibleList, SleepEventController) moved out of an area's Game_Logic as its content and made the game's on entering | research_one_copy_kinds.rs: no Storage, LiquidStorage, VendingMachine, ItemData, InteractableTalk, CraftingBase, Toilet (201 classes); the check passes with two round trips |
| kept_loaded.rs | [x] Run OnMapChanged on entering on the area and home only, not on the kept-through-loads objects (SaveController.cs:653) | The check passes with 2 errors (LightController.Awake), no new ones |
| unityforge SceneTools.cs | [x] Keep "loaded quietly", "never entered" and "switched off" per load of an area (Scene.handle), not per area name, and only for the mod's own loads alongside | Kept areas off after an area loaded alongside: 12684 errors with the old shim (12540 Spawner.DeltaSeconds), 1 with the new (LightController.Awake, the game's own); kept areas on: the check passes with 2 (LightController.Awake) |
| unityforge FirstCopyGuard.cs | [x] Stop Pathfinding.RVO.Simulator.RemoveAgent "agent is not added" (2 per check with kept areas on, 0 with them off): a one copy is also a public static property of the class's own type (RVOSimulator.active) | The check shows 0 RemoveAgent errors; first_copy_wins on: 359 patches (was 336) |
| kept_loaded.rs | [x] Find which of the check's errors the base game also logs, with the mod's kept areas off | docs/kept-areas.md "The check's errors: the game's own or the mod's": RemoveAgent 2 on / 0 off, LightController.Awake 2 on / 1 off (OBENSEUER_KEPT_OFF=1 run passed, back on Tom_Tomato/Slot7) |
| research_kept_scenario.rs | [x] Leave the game's save name as it was after the check saves to ModTest | The check ends with `back on the player's save: "Tom_Tomato/Slot1"` (the reload_save op takes an optional `save`) |
| FirstCopyGuard.cs | [x] Run OnDestroy of classes with an Awake in areas never entered | research_kept_scenario.rs passed (c2ba7b23): no "left ... Err ... InteractableChair.StopSitEnd" line |
| FirstCopyGuard.cs | [x] Stop MoneyPanel.OnDisable NullReferenceException (5 per check) | The check shows 0 MoneyPanel errors (c2ba7b23) |
| research_kept_scenario.rs | [x] Find why WaitingUI gives "type not found" in the watched list | The check reports WaitingUI live (cause of the earlier miss unknown; the test now prints the bridge error if it happens again) |
| research_kept_scenario.rs | [x] Commit the automatic check | Pushed in c2ba7b23 |
| FirstCopyGuard.cs | [x] Skip OnDestroy of lava lamps in areas never entered | research_kept_scenario.rs: 0 LavaLamp errors across two normal loads |
| first_copy_wins.rs | [x] A second copy of a one-copy class (public static field of its own type) does not take over | research_kept_scenario.rs: identity "Tom", 20 of 20 watched fields live (c2ba7b23) |
| kept_loaded.rs | [x] Saved data applied on entering, captured on leaving, every visited area written on save | A save made away from home loaded back correctly (operator, 2026-10-02) |
| kept_loaded.rs | [x] Load the areas behind the doors alongside, keep them switched off, move through a door with no loading screen | research_kept_scenario.rs: trips of 0.416s and 0.291s |
| deposit.rs | [x] F6 puts inventory and worn backpack items into nearby boxes that already hold the same item, range in settings | Committed; worked in game |
| mod | [x] Stacks: 10x multiplier on all stackable items (632 items) | Items stack to 990 in-game (done before this date, moved from the todo) |
| mod | [x] Inventory: 70 slots (10 columns x 7 rows), UI panel widened left | Inventory opens with 10x7 grid in-game (done before this date, moved from the todo) |
| mod | [x] Decide initial mod goals | bigger inventory, increased stack sizes (done before this date, moved from the todo) |
| research | [x] Map how Items.json is loaded | items.md, data loading: ItemDatabase.Awake, File.ReadAllText, FullSerializer (done before this date, moved from the todo) |
| research | [x] Decompile Assembly-CSharp.dll and document key classes | the game system docs listed in research.md (done before this date, moved from the todo) |
| setup | [x] Restart script | `obenseuer-mod/scripts/restart.ps1` builds, deploys, restarts (done before this date, moved from the todo) |
| setup | [x] Verify the control plane answers a ping | Control plane answers on port 17175 (done before this date, moved from the todo) |
| setup | [x] Build and deploy obenseuer_mod.unityforge.dll | The Rust cdylib loads and `on_init` runs (confirmed by log) (done before this date, moved from the todo) |
| setup | [x] Deploy the unityforge C# shim as a BepInEx plugin | The shim loads and prints its init message in the BepInEx log (done before this date, moved from the todo) |
| setup | [x] Install BepInEx 5.4.23.5 into the game directory | `BepInEx/` exists and the game launches with the BepInEx console (done before this date, moved from the todo) |
