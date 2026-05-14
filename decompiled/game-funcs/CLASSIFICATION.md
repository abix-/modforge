# Deep classification of game-logic functions

Total game-logic functions: 971

Three-pass classification:
1. **Role** from referenced strings (most specific)
2. **Category** from code patterns (getter, setter, init, math, etc.)
3. **Domain** propagated through call graph (fatigue, aging, race, etc.)

## Role distribution (string-anchored)

| Role | Count |
|---|---|
| `(no role)` | 755 |
| `lab_location` | 178 |
| `zoo_location` | 4 |
| `paddock_event` | 3 |
| `circus_location` | 2 |
| `save_file_path` | 2 |
| `sumo_location` | 2 |
| `champion_handling` | 2 |
| `stable_event` | 2 |
| `glue_factory` | 2 |
| `race_won_event` | 1 |
| `dna_sample` | 1 |
| `sound_xml_loader` | 1 |
| `treasure_event` | 1 |
| `fatigue_rest_prompt` | 1 |
| `hutch_location` | 1 |
| `debug_pause_status` | 1 |
| `power_plant_location` | 1 |
| `saloon_location` | 1 |
| `settings_xml_io` | 1 |
| `lasso_action` | 1 |
| `genome_clipboard_copy` | 1 |
| `race_start_prompt` | 1 |
| `ribbon_handling` | 1 |
| `balloon_event` | 1 |
| `debug_roster_stats` | 1 |
| `horse_retirement_handler` | 1 |
| `fatigue_all_rested` | 1 |
| `debug_population_stats` | 1 |

## Pattern category distribution

| Category | Count |
|---|---|
| `helper` | 431 |
| `repeated_op` | 105 |
| `medium_loop` | 102 |
| `float_math_complex` | 48 |
| `struct_handler` | 47 |
| `struct_init` | 46 |
| `simple_return` | 44 |
| `float_math` | 41 |
| `empty_stub` | 27 |
| `destructor_like` | 22 |
| `wrapper` | 19 |
| `loop_heavy` | 13 |
| `plays_sound_or_event` | 9 |
| `iterates_horse_list_0xb8` | 7 |
| `switch_dispatcher` | 5 |
| `iterates_horse_list_0x26` | 3 |
| `getter` | 2 |

## Domain propagation (after call-graph spreading)

| Domain | Count |
|---|---|
| `world_event` | 812 |
| `save_io` | 75 |
| `race` | 40 |
| `(no domain)` | 19 |
| `aging` | 11 |
| `debug` | 8 |
| `fatigue` | 3 |
| `genetics` | 2 |
| `settings_io` | 1 |