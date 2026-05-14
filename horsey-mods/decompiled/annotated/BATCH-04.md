# Batch annotation 04 — 30 more game functions

## 71. `0x1400cc1d0` (2,029 bytes) — `item_description_dialog`

Strings: `"A rare specimen"`, `"It's a ram bar for your truck"`, `"It's an
assortment of delicious h..."`, `"It's an infinite bag of fences"`, `"Oh no!
The freak has escaped"`, `"This gun never runs out of ammo"`, `"This looks
dangerous"`, `"This money came from the governm..."`, `"Why that looks like
16MB of EDO R..."`, `Wonderful`.

The **item-pickup description dialog**. Each item ID has an associated flavor
text shown when picked up: ram bar (item 24), infinite fence bag (46), 16MB
EDO RAM (the 47), etc. "freak has escaped" is the circus freak-tent event.

## 72. `0x1402d0790` (2,022 bytes) — `msvc_runtime_helper`

Vendor MSVC runtime function.

## 73. `0x140080e40` (1,972 bytes) — `wild_horse_ai_step`

Per-frame wild-horse AI tick. Called from `wild_horse_eating_handler`. Heavy
on RNG (calls `FUN_1400c6580` for random checks). Manages wandering, eating,
mating triggers for wild horses.

## 74. `0x1400bfa90` (1,970 bytes) — `tmx_object_property_parser`

Strings: `" react", "shape"`. Parses individual properties on tmx Objects
(like the `buried` property we documented). Called by the map loader.

## 75. `0x140093d90` (1,956 bytes) — `race_odds_debug_print`

Strings: `"%d - %d"`. Called by `process_race_results` and the race state
machine. Probably prints "%d - %d" odds (winner-loser stats).

## 76. `0x1400bcb00` (1,924 bytes) — `horse_status_render_helper`

Renders status indicators above horses. Helper for `render_horse_thought_bubble`.

## 77. `0x1400cba60` (1,894 bytes) — `prize_open_animation`

Strings: `BriefcaseOpen, InvTrumpet, OpenPrize, Shred, "duck"`.

Opens a prize/briefcase. BriefcaseOpen sound, InvTrumpet (inventory-add
trumpet flourish), Shred (paper-shredding for treasure?). "duck" is a
spawned pop reference.

## 78. `0x140017910` (1,887 bytes) — `geometry_helper_recursive`

Pure math helper. Recursive geometry routine.

## 79. `0x14009c8c0` (1,881 bytes) — `font_loader`

Strings: `bubbletime, bubbletime.txt, capy bold, capy bold crf, classified,
classified.txt, habit mono, habit mono crf, habit narrow bold, habit narrow
bold crf, picory, picory.txt, snuggle, snuggle crf, softsquare`.

The **font loader**. Loads all the ChevyRay bitmap fonts: bubbletime, capy
bold, classified, habit mono, habit narrow bold, picory, snuggle, softsquare.
Each font has a .txt (metrics) + .crf (binary) + .png (atlas) triplet.

## 80. `0x1400cddd0` (1,833 bytes) — `track_horse_position_render`

Renders horse positions during a race / on-track display. Called from many
location handlers.

## 81. `0x14001eae0` (1,832 bytes) — `geometry_helper_2`

Pure math recursion helper. Same family as 0x140017910.

## 82. `0x14000eef0` (1,814 bytes) — `format_horse_label_helper`

Called only by `format_horse_type_label`. Helper for label construction.

## 83. `0x1400b78d0` (1,787 bytes) — `apply_gene_for_body_part`

Strings: `color, ears, eyebrows, eyes, feet, head, legs, mouth, tail, torso`.

Picks which body part a gene applies to. Each gene's expression dispatches
into per-body-part appearance code. Called by the central `check_horse_eligibility`
handler and `apply_gene_to_horse`.

## 84. `0x140012ba0` (1,765 bytes) — `geometry_helper_3`

Pure math recursion helper.

## 85. `0x14005d710` (1,728 bytes) — `render_letter_g_or_treasuremap`

Strings: `LetterG, treasuremap`. Probably draws a literal "G" letter (for the
"G" DNA piece item) and the treasure map item.

## 86. `0x140015c30` (1,718 bytes) — `geometry_helper_4`

Strings: `"iA != (-1)"` (an assertion). Pure math helper.

## 87. `0x140047cd0` (1,675 bytes) — `vorbis_window_helper`

Vorbis decoder support helper.

## 88. `0x1400afc20` (1,664 bytes) — `cosmetic_apply_helper_2`

Sub-branch of `apply_horse_decoration`. Tiny per-cosmetic specialization.

## 89. `0x1400ae6b0` (1,656 bytes) — `apply_boots_decoration`

Strings: `DecoRollerblades, DecoSneakers, ItemCowboyBoots1`.

Applies boots/sneakers/rollerblades to a horse (item IDs 25, 35, 38-41).

## 90. `0x14002fe00` (1,630 bytes) — `daily_horse_event_emitter`

Strings: `"%s ate some hay today", "%s likes it!", "%s was a good horse today"`.

Per-day per-horse event log. Each game day, emits one of these messages for
each horse based on what they did. The "daily journal" feature.

## 91. `0x1401112f0` (1,624 bytes) — `runtime_helper_unnamed`

Pure runtime helper.

## 92. `0x140102df0` (1,621 bytes) — `wild_horse_spawn_helper`

Called by `wild_horse_ai_step`. Handles spawning new wild horses (probably
from spawners we documented in CONTENT-MODDING.md).

## 93. `0x1400e0420` (1,610 bytes) — `champion_record_format`

Strings: `"%s champ: %s"`. Formats champion-record entries. Called by
`retire_horse_handler` and a sibling.

## 94. `0x1400816b0` (1,610 bytes) — `wild_mating_handler`

Strings: `WildMating`. Wild-horse mating trigger. Plays the WildMating sound,
spawns offspring genome via `pop_genome_builder` and friends.

## 95. `0x14009d750` (1,577 bytes) — `cursor_input_handler`

Strings: `Pointer`. Handles cursor (pointer) input — clicks, drags, hovers.
Calls `save_game_writer` (auto-save trigger?) and other handlers.

## 96. `0x140013290` (1,575 bytes) — `geometry_helper_5`

Math helper.

## 97. `0x1400fa910` (1,539 bytes) — `unzoom_truck_action`

Strings: `UnzoomTruck`. The truck-zoom-out animation handler.

## 98. `0x1400d03f0` (1,539 bytes) — `horse_select_validator`

Strings: `"Horse"`. Validates a horse selection (clicking on a horse). Used
by multiple location handlers.

## 99. `0x14006a420` (1,505 bytes) — `npc_dialog_helper`

Pure helper for NPC dialog dispatch.

## 100. `0x1400449e0` (1,493 bytes) — `audio_stream_helper`

Audio decoder helper. Vorbis-stream sub-routine.

---

**Cumulative coverage: 100 of 1,234 game-logic functions = 8.1%.**
