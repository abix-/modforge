# Batch annotation 05 — 35 more functions

## 101. `0x140106bc0` (1,463 bytes) — `retire_horse_helper`

Called by `retire_horse_handler`, `process_race_results`, and others. Helper
that completes one horse's retirement: updates stats, broadcasts message.

## 102. `0x14001f210` (1,430 bytes) — `geometry_helper_recursive_2`

Pure recursive math helper.

## 103. `0x140010540` (1,427 bytes) — `physics_constraint_helper`

Strings: `"def->ratio != 0.0f", "false"`. Box2D-style constraint helper
(verifies a ratio is non-zero). Part of horse limb physics.

## 104. `0x14010d7e0` (1,413 bytes) — `tile_random_picker`

Picks a random tile variant during render. Used by world action dispatcher.

## 105. `0x1400a4880` (1,397 bytes) — `genes_xml_validation_logger`

Strings: `"genes xml"`. Validates the parsed genes.xml; logs errors with
prefix "genes xml". Sub-helper of `load_genes_xml`.

## 106. `0x1402e4980` (1,386 bytes) — `runtime_helper_unnamed`

MSVC runtime.

## 107. `0x1400b3070` (1,367 bytes) — `apply_gene_to_horse_helper`

Called by `wild_horse_handler`, `biohacker_lab`, and several spawners. A
gene-application sub-helper that calls `apply_gene_to_horse` and
`format_horse_type_label`. Probably the "apply genome to a new horse"
entry point used after breeding/spawning.

## 108. `0x1400063f0` (1,364 bytes) — `physics_assert_helper`

Strings: `"b->IsActive() == true"`. Box2D-style assertion.

## 109. `0x1402f8e20` (1,353 bytes) — `runtime_string_helper`

MSVC STL helper. Called by many places (utility).

## 110. `0x1400d72f0` (1,342 bytes) — `helper_for_render`

Pure helper for rendering pipeline.

## 111. `0x140049630` (1,339 bytes) — `vorbis_helper_2`

Vorbis decoder sub-helper.

## 112. `0x1400cd5a0` (1,326 bytes) — `truck_enter_location_handler`

Strings: `TruckEnterLocation`. Plays the TruckEnterLocation sound and runs
the truck-entering animation when the player arrives at a location.

## 113. `0x1400e3670` (1,319 bytes) — `retirement_helper`

Sub-helper of `retire_horse_handler`.

## 114. `0x140020bb0` (1,306 bytes) — `geometry_helper_6`

Math.

## 115. `0x1402d0f80` (1,277 bytes) — `runtime_helper_unnamed_2`

MSVC.

## 116. `0x140048e90` (1,264 bytes) — `vorbis_helper_3`

Vorbis decoder sub-helper.

## 117. `0x1400155f0` (1,250 bytes) — `physics_assert_with_parents`

Strings: `"child1 != (-1)", "child2 != (-1)"`. Physics-tree assertion that
two child nodes are valid. Probably the breeding-tree validator.

## 118. `0x1400d5ff0` (1,241 bytes) — `horse_status_render_dispatcher`

Called from 5 location handlers (track, paddock, stable, etc.). Picks which
status icon to render above each horse based on horse state.

## 119. `0x14001e5e0` (1,229 bytes) — `geometry_helper_7`

Math.

## 120. `0x140102060` (1,225 bytes) — `wild_horse_target_picker`

Called by `wild_horse_ai_step`. Picks a target tile / direction for a wild
horse to move toward.

## 121. `0x140105260` (1,223 bytes) — `debug_print_race_separator`

Strings: `"--- %d ---"`. Debug log separator that prints `--- N ---` before
each race log. Calls `retire_horse_handler`.

## 122. `0x14000bfe0` (1,221 bytes) — `geometry_helper_8`

Math.

## 123. `0x1400693b0` (1,207 bytes) — `power_plant_handler`

Strings: `"Power has been restored", "Power is off again", PowerOn`.

The **Power Plant location**. Handles the power-on / power-off state of the
island. Plays PowerOn sound when power is restored. Probably tied to the
HorseTouchingTurbine event we saw.

## 124. `0x1400138c0` (1,203 bytes) — `geometry_helper_9`

Math.

## 125. `0x140020700` (1,199 bytes) — `geometry_helper_10`

Math.

## 126. `0x1400aa2b0` (1,183 bytes) — `cosmetic_apply_helper_3`

Decoration application sub-helper.

## 127. `0x1400d7830` (1,181 bytes) — `helper_for_render_2`

Render-pipeline helper.

## 128. `0x1400a5400` (1,178 bytes) — `time_formatter`

Strings: `"%02d:"`. Formats race times as MM:SS. Called by crispr lab
(probably the disk-saving countdown) and self-recursive.

## 129. `0x1402edc48` (1,171 bytes) — `msvc_runtime_helper`

MSVC.

## 130. `0x1400c86f0` (1,167 bytes) — `cosmetic_apply_helper_4`

Decoration helper.

## 131. `0x1402de160` (1,164 bytes) — `msvc_runtime_helper_2`

MSVC.

## 132. `0x1400af790` (1,158 bytes) — `apply_bowtie_decoration`

Strings: `ItemBowTie`. Bow-tie cosmetic applier (item ID 26 - bowtie).

## 133. `0x1401005b0` (1,157 bytes) — `pause_dispatcher_helper`

Sub-helper of `pause_top_level_dispatcher`.

## 134. `0x140018070` (1,141 bytes) — `geometry_helper_11`

Math.

## 135. `0x1400b87e0` (1,137 bytes) — `drunk_horse_status`

Strings: `Drunk, Sauced`. Sets a horse's drunk status (after eating/drinking
beer-related items in the saloon).

---

**Cumulative coverage: 135 of 1,234 game-logic functions = 10.9%.**
