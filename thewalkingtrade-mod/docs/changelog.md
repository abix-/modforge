# The Walking Trade changelog

## Changelog rules

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

## 2026-09-30

| System | Item | Done when |
|---|---|---|
| Performance | [x] Remove the five-second job; bench, barbed wire, cleaner window and hire lookup run on game events instead | `perf_window` over 60 s of play before: `twt: 5s tick (all)` 12 calls, 138.9 ms average, 12 frames over 100 ms. After: no tick rows, no frames over 100 ms, damage hook worst single call 45.65 ms down to 0.83 ms. |
| Performance | [x] Time every mod entry point under a name and add a test that reports it | `tests/perf.rs` `perf_window` switches modforge timing on, waits `TWT_PERF_SECS`, prints calls, total, average and worst per `twt: ...` name plus frame counts. Ran twice against the live game, output above. |
| Barbed wire | [x] Barbed wire wears out 10 times slower: `_ownDamagePerTick` 2.0 to 0.2, set in a prefix on `BarbedWireDamageTrigger.Awake` | `barbed_wire` test after a restart: 9 active wires read `_ownDamagePerTick=0.2`. Slow (0.25) and damage dealt (10 per 0.25 s tick) unchanged. |
| Skill tree | [x] An owned multiplier upgrade or +1 hire upgrade can be bought again with the tree's unlock button, each purchase adding one more copy of the upgrade | User bought +1 hire again twice; `thewalkingtrade.json` holds `MaximumStaffCountSkillNode2: 1` and `MaximumStaffCountSkillNode4: 1`. Stacking measured on crafting speed with `crafting_speed_repeat_write`: 0.75 to 0.5625. |
| Skill tree | [x] Repeat counts are restored after a save loads | Log after load: `skill repeats restored: 2 copies`. |
| Shop | [x] The shop opens by itself when a new day starts (postfix on `GameController.OnPlayerSleepCompleted` calls `StoreManager.TryToggleStoreOpen`) | User confirmed in play: "works great". |
| Crafting bench | [x] Crafting bench item areas no longer block building (bench item boxes tagged `AllowBuilding`) | Player.log named the blocker 25801 times: `Placement blocked by ItemObjectsContainer`, the 50x bench boxes. After the tag the user placed the flimsy wooden shelf: "ok works". |
| Crafting bench | [x] Crafting bench item areas set to `craft_bench_multiplier` (default 50) times their original size, applied after each load and after `thewalkingtrade.json` changes | Log after load: `craft bench: 5 box(es) set to 50x`. `craft_station_item_boxes` read Level4 box 0 at `(696.50, 303.00, 996.50)`. |
| Cleaner | [x] Body disposal can be switched on at cleaner level 2: both level checks patched 3 to 2 in GameAssembly.dll, and the settings window's level 3 box lowered to 2 | Log at every start: `cleaner_dispose_policy_level: 3 -> 2` and `cleaner_dispose_valid_work_level: 3 -> 2`, each pattern matching once, on game 1.2.4 and 1.2.5. User could select the option at level 2. |
| Research | [x] Decompile the game (Cpp2IL) and record repeatable skill upgrade research | `docs/research.md` section "Repeatable skill upgrades", with the live reads pasted. |
