# Batch annotation 03. Next 30 substantial game functions

## 41. `0x140033a10` (6,233 bytes). `biohacker_lab_handler`

Strings: `Bio-Hacker, Biohacker, BiohackerDoorOpen, Drain, GarageDoorOpen,
"Good afternoon neighbor", "If it had more RAM the sim would...", "It's already
empty", SampleDNA, SimSavingToDisk, SimSpawnDisk, "That's just sludge on the
bottom", "The genes of the most optimal horse...", Uberhorse, "but there's no
more slots so..."`.

The **Biohacker / Lab** location handler. Manages: DNA sampling, "sim" disk
saving (the disks the player finds), the Uberhorse genome (optimal genes on a
disk you find), RAM upgrade ("If it had more RAM the sim would..." - this is
the 8G RAM upgrade item ID 47). "Drain" is the sludge-pond drain interaction.

## 42. `0x1400c0660` (5,765 bytes). `debug_print_horse_roster`

Strings: `"horses: %d   bails: %d   errors: %d"`.

Debug printer. Counts and prints the population stats. Called once. The
"bails" count tracks horses that retired due to (bails) reason. "errors" is
horse-simulation errors. Useful for the cheat-menu's debug stats line.

## 43. `0x1402f6c9c` (4,734 bytes). `runtime_helper_unnamed`

No strings, called by addresses in the 0x1402exxxxx range. This is in the
MSVC C++ runtime range (high-address functions are typically library code).
Likely STL/iostream helper.

## 44. `0x1401c10d0` (4,690 bytes). `d3d12_device_init_logger`

Strings: `"D3D12 Adapter: %s", "D3D12 Driver: %s", SDL.gpu.device.create.d3d12.agility_sdk_path`.

D3D12 device initialization and logging. Vendor code (SDL_GPU), not really
game logic but lives in the call graph.

## 45. `0x14010ba40` (4,610 bytes). `terrain_render_dispatcher`

Strings: `"Apple", "Grass", "NGrass"`.

Picks which terrain/vegetation tile to render. Apple = apple tree, Grass /
NGrass = normal vs plutonium grass.

## 46. `0x14007c970` (3,987 bytes). `prize_gallery_display`

Strings: `"%d-%d", ":%02d", DragHorseHere, Gallery, "Prize $%d"`.

Renders the prize gallery (collected trophies / prizes). Time-formatted strings
(":%02d") for race time displays. "DragHorseHere" is the UI prompt.

## 47. `0x140060a80` (3,713 bytes). `corral_entry_validator`

Strings: `"Before it can enter the Champion..."`, `"Go home and rest your horse
first"`, `Good luck, Horse, "Maybe watch some more races", "More monneeey",
"Not enough money", "Now go to the track to watch %s race", "Only one Champion
entry at a time please", "That horse is too old to race", "The corral is inside
the fence...", "There aren't enough winning hors...", "Try again later", "Your
horse is hungry  Feed it first", "Your horse needs to win 2 races"`.

The **corral entry validator** for race / championship. Emits all the
why-can't-you-race messages: too old, hungry, broke, not enough wins, only one
Champion entry, etc. This is a SECOND fatigue/age/hunger eligibility gate
(complements `check_horse_eligibility`).

## 48. `0x140076a10` (3,488 bytes). `parse_command_line_flags`

Strings: `Sweetie, Track, autoload, autosave, debug, escquits, hidpi,
"horsey.tmx", labpop, log_races, log_stables, log_world, music, savestress`.

**Command-line flag parser**. The game accepts CLI flags including:
- `autoload`, `autosave`: auto-load and auto-save
- `debug`: probably auto-enables debug mode
- `escquits`: escape key quits (vs cancels)
- `hidpi`: high-DPI rendering
- `labpop`: probably for Lab debug
- `log_races`, `log_stables`, `log_world`: enable debug logging by category
- `music`: music control flag
- `savestress`: probably stress-test the save system

**HORSEY MOD**: launch the game with `debug` flag to auto-enable debug mode
without typing it in the pause menu!

## 49. `0x1402d8d60` (3,443 bytes). `runtime_helper_unnamed_2`

Pure MSVC runtime / iostream helper.

## 50. `0x1401acec0` (3,099 bytes). `vulkan_device_init`

Strings: `"Failed to create logical device!", SDL.gpu.device.create.verbose`.

Vulkan device init. Vendor code in SDL_GPU.

## 51. `0x140082640` (2,966 bytes). `wild_horse_eating_handler`

Strings: `Splash, WildChompMeat, WildChompVeg`.

Handles wild horses eating in the world. WildChompMeat (carnivores) and
WildChompVeg (herbivores) play different sounds. Splash is for water entry.

## 52. `0x1400a74e0` (2,941 bytes). `glue_factory_handler`

Strings: `"%s gets you $%d", ConveyorLoop, ConveyorStart, ConveyorStop,
PlaceOnScale, ProcessHorse, RemoveFromScale`.

The **Glue Factory** location. Player places a horse on a scale, conveyor
runs (ConveyorLoop), processes the horse (ProcessHorse), and pays out cash
("%s gets you $%d").

## 53. `0x1401035b0` (2,834 bytes). `terrain_tile_dispatcher`

Strings: `"Plain"`. Helper for the world action dispatcher. Routes plain
terrain interactions.

## 54. `0x14004b960` (2,740 bytes). `vorbis_helper`

Helper for `vorbis_audio_decoder` (`0x140053a40`). Decodes inner pages of an
Ogg stream.

## 55. `0x1400ca260` (2,646 bytes). `show_horse_stats_screen`

Strings: `"Horse", "ShowStatsScreen"`.

Shows the horse stats popup. Called from track, race, biohacker, and the
circus.

## 56. `0x1400aed30` (2,595 bytes). `cosmetic_apply_helper`

Sub-helper of `apply_horse_decoration`. Called by sibling helpers. Applies a
specific decoration type.

## 57. `0x1400b3dc0` (2,575 bytes). `horse_anim_step`

Called by `track_state_machine`, sumo handler, balloon handler. Per-frame
horse animation step.

## 58. `0x1400463e0` (2,552 bytes). `sound_dispatcher_helper`

Sub-helper of `sound_xml_parser`. Sound dispatch by name lookup.

## 59. `0x1400d98f0` (2,517 bytes). `runtime_string_helper`

MSVC STL helper.

## 60. `0x1400ceb60` (2,502 bytes). `whip_horse_movement`

Strings: `"High Achiever", Horse, WhipCrack, "crazy horse"`.

Whip-crack to make a horse move faster (during racing or movement). "High
Achiever" is a status / accolade. Called by the track, sumo, biohacker, and
circus locations.

## 61. `0x1400cacd0` (2,454 bytes). `prize_appearance_handler`

Strings: `Plinth, PrizePresent, SleepMoon`.

Animates a prize appearing on a plinth. Used when the player wins something.

## 62. `0x140106140` (2,405 bytes). `pop_xml_recursive_pop_lookup`

Called by `pop_genome_builder`. Recursive walk of the pop.xml tree to resolve
a population by name (handles the parent-pop inheritance from JumboDS64's
guide).

## 63. `0x140196db0` (2,291 bytes). `runtime_string_op_unnamed`

MSVC STL helper.

## 64. `0x1400bd820` (2,270 bytes). `render_horse_thought_bubble`

Strings: `AnimSleep, ThoughtTired`.

Renders the sleep / tired-thought animations above a horse. The visual feedback
for tiredness state.

## 65. `0x1400d52c0` (2,253 bytes). `render_racer_info_card`

Strings: `Horse, RacerInfo, StatusFoal`.

Renders the per-racer info card (small info widget above each horse on track).
"StatusFoal" indicates a foal status icon (young horse).

## 66. `0x1400fd580` (2,159 bytes). `pause_top_level_dispatcher`

Strings: `EcoFaster, EcoSlower, EcoZoomIn, EcoZoomOut, Pause`.

Top-level pause handler. EcoFaster/Slower are the sim-speed controls (matches
JumboDS64's note about pressing 5 for x300). EcoZoomIn/Out are camera-zoom
sounds. Called by the main pause input handler. Calls `load_game` (FUN_14006e480)
when loading.

## 67. `0x1400b2490` (2,096 bytes). `deco_helper_unnamed`

Sub-helper of `apply_horse_decoration`. Tiny specialization.

## 68. `0x1400b4b10` (2,053 bytes). `dialog_state_step`

Called from npc-dialog handlers. Per-frame dialog state advancer.

## 69. `0x140097dd0` (2,046 bytes). `race_step_handler`

Called from race state machine. Per-frame race simulation step (each horse
moves forward based on speed, applies fatigue, checks finish line). Touches
horse physics simulator.

## 70. `0x140013d80` (2,038 bytes). `vector_math_helper_recursive`

Self-recursive geometry helper. Pure math.
