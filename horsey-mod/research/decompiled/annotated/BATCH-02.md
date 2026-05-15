# Batch annotation 02. Next 24 substantial game functions

## 17. `0x140058480` (7,589 bytes). `ecologist_research_dialog`

Strings: `BuyItem`, `Catastrophe... All the wild horses`, `De Horsey Island was
named for A...`, `He distinguished himself in Cana...`, `Horse population is
critically low`, `I did it! My research is complete`, `I dug a hole and found
this plinth`, `I'm doing more research`, `I made this chart`, `I need lots of
horse variety`, `My goals are complete`, `My research is complete`, `Oh no my
PhD is ruined`.

The **Ecologist NPC** logic. Tracks the player's two goals (population +
diversity) and emits the research-progress dialogs. The ecologist is also the
source of the De Horsey Island lore.

## 18. `0x1400b9540` (5,110 bytes). `horse_physics_simulator`

Strings: `BalloonBoop, ChainRattle, PoofBubble, "critical physics error horse
seed: %llu limb %d"`.

Per-horse physics step. The "critical physics error" debug log fires when the
limb skeleton produces NaN/infinite values. Called from balloon controllers,
race state machine, etc.. Anywhere horses animate. The "horse seed" in the
error log confirms each horse has a deterministic seed for its limb sim.

## 19. `0x1400fe2e0` (5,277 bytes). `tmx_parse_layer`

Strings: `height, objectgroup, offsetx, offsety, terrain, value, width`.

Parses one Tiled `.tmx` layer (terrain, objects, or another). Called by the
top-level map loader at `FUN_1400fd580`. These are the standard Tiled XML
attribute names.

## 20. `0x14010a5e0` (5,188 bytes). `hot_air_balloon_controller`

Strings: `BalloonDisabled, BalloonDown, BalloonSimFaster, BalloonSimSlower,
BalloonUp, LassoMiss, LiftOff, LiftOn, SelectInv, SmashFence`.

The full hot-air-balloon location handler. **BalloonSimFaster/Slower** is the
x300 sim-speed cheat that JumboDS64 mentioned (press `5` in balloon).
LassoMiss = throwing the lasso from up high and missing. SmashFence = breaking
a fence on landing.

## 21. `0x14007e030` (3,320 bytes). `hint_dispatcher`

Strings: `BuyItem, "I saw wild horses south west of here"`, `"Let me get that
for you"`, `"The ancients buried a lot of stuff..."`, `"This island sure has
some mysteries"`, `"Try betting on horses to earn money"`, `"Why not buy some
hay to feed your horses"`, `"Why not go home and rest your horse"`, `"Why not
go to the Paddock and race"`, `"Why not grab that lasso up there"`, `"You can
dig with a shovel"`, `"You can't afford that"`, `"for ritual purposes I'm sure"`.

The **hint-dialog dispatcher**. NPCs and the world emit these context hints
("did you know..."). This function is the source of the gameplay-tutorial
suggestions.

## 22. `0x140092820` (5,156 bytes). `pop_genome_builder`

Strings: `crazy horse, giraffe`. Called by `0x14008ffc0` (process_race_results)
and itself (recursion).

Looks up a population by name (e.g. "crazy horse", "giraffe") and constructs a
horse genome by sampling weighted alleles. This is the **pop.xml runtime
spawner**. The function that JumboDS64's "p0..p3 are inverse weights" claim
points to. Needs detailed read to confirm the weight direction.

## 23. `0x140053a40` (3,042 bytes). `vorbis_audio_decoder`

Strings: `vorbis`. Called by many audio handlers.

Decodes an Ogg Vorbis audio stream (cute_sound supports only WAV, so this
must be a separate path for the OGG music files in `sound/`).

## 24. `0x14001f7b0` (2,954 bytes). `geometry_validator`

Strings: `"a.x >= 0.0f && a.y >= 0.0f"`.

An assertion debug message string. This function validates 2D-vector geometry
inputs are non-negative. Likely a math helper for sprite/world coordinates.

## 25. `0x1400ad5c0` (3,254 bytes). `apply_horse_jet_engine_deco`

Strings: `DecoJetEngine, DecoJetEngineV, ItemRibbon1`.

Sub-branch of the apply_horse_decoration tree. Attaches a jet-engine prop
(probably the rocket-booster item ID 33) to the horse and uses ItemRibbon1
as a related decoration.

## 26. `0x140086910` (3,007 bytes). `dialog_text_layout`

No exposed strings; called by `interact_with_npc_or_item` (`0x1400d2ab0`),
the genome clipboard (`0x14008ffc0`), and other dialog handlers. Used to
layout/render dialog text into the dialog bubble. Helper function.

## 27. `0x14006b040` (2,987 bytes). `saloon_news_dialog`

Strings: `CloseNews, "Read the latest 'Sporting News'", "Sorry sodbuster, no
cash, no beer", "What'll it be"`.

The **Saloon location** NPC. Sells beer (won't serve if no cash), shows the
latest "Sporting News" newspaper.

## 28. `0x14004dc90` (4,047 bytes). `ogg_packet_decoder`

Helper for `0x140053a40` (vorbis decoder). Decodes a single Ogg packet.

## 29. `0x14002d7c0` (4,033 bytes). `track_state_machine`

Strings: `CrossFinishLine, EnterLocationPaddock, RaceGetSet, Racing,
TruckEnterLocation, TruckLeaveLocation, WonRace`.

The **Race Track location** controller. Handles the full race lifecycle:
truck arrives, paddock entry, get-set, race start, cross finish line, won
race trigger.

## 30. `0x1400da2f0` (3,290 bytes). `unknown_helper_called_by_handlers`

No strings; called by 3 other game functions; recursive. Pure helper. Needs
manual reading.

## 31. `0x1400d0c80` (4,008 bytes). `npc_dialog_with_speech_variants`

Strings: `" *hic*", Dialog, "orses", "orshes"`.

NPCs spawn speech variants. The "*hic*" suggests drunk NPC dialog (saloon).
"orses" and "orshes" are misspellings of "horses". Drunk slurring (the
saloon-drunk dialogue source).

## 32. `0x1400c35b0` (3,356 bytes). `sdl_gpu_init`

Strings: `Horsey Game, SDL_RENDER_GPU_LOW_POWER, SteamUtils010, "files txt"`.

Initializes the SDL renderer + Steam integration. Calls into save/settings
handlers and SteamUtils010 (Steam API).

## 33. `0x14003f810` (3,359 bytes). `sound_xml_parser`

Strings: `"bad %s", music, pitch, pitchhigh, pitchlow`.

Parses sound.xml entries. "music" / "pitch" / "pitchhigh" / "pitchlow" are
the attribute names from sound.xml. `"bad %s"` is the error message for an
invalid entry.

## 34. `0x140016c70` (3,150 bytes). `bool_to_string_helper`

Strings: `"false"`. Math/utility helper. Probably converts internal state
to a "false" / "true" stringization for logging.

## 35. `0x140006950` (3,264 bytes). `vector_math_validator`

Strings: `"alpha0 < 1.0f"`. Geometry assertion helper. Same family as
`geometry_validator`.

## 36. `0x14001f7b0` (2,954 bytes). `vector_op_helper`

Strings: `"a.x >= 0.0f && a.y >= 0.0f"`. (already listed above as #24)

## 37. `0x1400b85b0` (167 bytes). `interact_helper_tiny`

Called by `interact_with_npc_or_item` and the larger handler. Small. Pure
wrapper.

## 38. `0x140042b30` (44 bytes). `audio_helper_tiny`

Called only by itself or via thunks. Tiny audio helper.

## 39. `0x140126260` (7 bytes). `trampoline_stub`

7-byte stub. A thunk/PLT-like function jumping elsewhere.

## 40. `0x14008ffc0` (8,565 bytes). `race_oddsmaking`

Strings: `TitleCard, "Oddsmaking error on %s!", "Wild Horse %d"`.

Computes betting odds for each horse before a race based on their stats. The
debug error log fires if the math produces a degenerate result (probably
divide-by-zero on identical horses or empty pool).
