# Deep classification of game-logic functions

Total game-logic functions: 1234

Three-pass classification:
1. **Role** from referenced strings (most specific)
2. **Category** from code patterns (getter, setter, init, math, etc.)
3. **Domain** propagated through call graph (fatigue, aging, race, etc.)

## Role distribution (string-anchored)

| Role | Count |
|---|---|
| `(no role)` | 951 |
| `lab_location` | 240 |
| `paddock_event` | 4 |
| `zoo_location` | 4 |
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
| `breeding_event` | 1 |
| `genome_clipboard_copy` | 1 |
| `race_start_prompt` | 1 |
| `ribbon_handling` | 1 |
| `balloon_event` | 1 |
| `debug_roster_stats` | 1 |
| `age_too_old_check` | 1 |
| `fatigue_eligibility_check` | 1 |
| `horse_retirement_handler` | 1 |
| `fatigue_all_rested` | 1 |
| `chromosome_extractor` | 1 |
| `debug_population_stats` | 1 |

## Pattern category distribution

| Category | Count |
|---|---|
| `helper` | 592 |
| `repeated_op` | 130 |
| `medium_loop` | 117 |
| `struct_init` | 57 |
| `simple_return` | 53 |
| `struct_handler` | 51 |
| `float_math_complex` | 50 |
| `float_math` | 47 |
| `empty_stub` | 32 |
| `wrapper` | 32 |
| `destructor_like` | 23 |
| `loop_heavy` | 15 |
| `iterates_horse_list_0xb8` | 13 |
| `plays_sound_or_event` | 10 |
| `switch_dispatcher` | 7 |
| `iterates_horse_list_0x26` | 3 |
| `getter` | 2 |

## Domain propagation (after call-graph spreading)

| Domain | Count |
|---|---|
| `world_event` | 1049 |
| `save_io` | 65 |
| `race` | 40 |
| `debug` | 35 |
| `(no domain)` | 24 |
| `aging` | 11 |
| `fatigue` | 5 |
| `genetics` | 3 |
| `settings_io` | 1 |
| `breeding` | 1 |