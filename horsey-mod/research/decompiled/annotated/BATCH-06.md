# Batch annotation 06. 40 more functions

## 136. `0x1402d5aec` (1,133 bytes). `msvc_runtime_helper`
MSVC runtime support.

## 137. `0x14005f1f0` (1,125 bytes). `clarence_tournament_dialog`
Strings: `"If you can believe it"`, `SimHorseFinished`, `SimStartRace`,
`"That was the tournament Clarence w..."`. NPC Clarence narrates tournament
results in the biohacker sim. SimStartRace/SimHorseFinished are sim sounds.

## 138. `0x1400db270` (1,124 bytes). `lost_button_handler`
Strings: `LostButton`. Handles a lost-button event (cosmetic). Called from
tmx loader, world action dispatcher.

## 139. `0x1400b02b0` (1,116 bytes). `cosmetic_apply_helper_5`
Decoration sub-helper (boots/skates family).

## 140. `0x1401c97e0` (1,105 bytes). `d3d12_resource_helper`
SDL_GPU/D3D12 vendor support.

## 141. `0x1400a9c80` (1,093 bytes). `cosmetic_init_helper`
Decoration init sub-helper.

## 142. `0x1400b7fe0` (1,073 bytes). `horse_state_update_step`
Called by track / paddock / race handlers. Per-frame state update.

## 143. `0x140054630` (1,065 bytes). `audio_init_helper`
Audio system init helper.

## 144. `0x1400ae280` (1,059 bytes). `cosmetic_apply_dispatcher`
Top-level dispatcher in the decoration tree.

## 145. `0x14000da90` (1,057 bytes). `geometry_helper_recursive_3`
Math.

## 146. `0x14010f7e0` (1,050 bytes). `prize_helper`
Called by `prize_appearance_handler` and friends. Prize placement helper.

## 147. `0x1400c8e70` (1,049 bytes). `circus_or_race_render_helper`
Called by circus, race, results, status renderers.

## 148. `0x1400b5b50` (1,048 bytes). `string_helper`
Called by physics, render, and audio. Generic string helper.

## 149. `0x1400cfda0` (1,047 bytes). `random_horse_picker`
Picks a random horse (using FUN_1400c6580 = RNG). Called by retirement,
champion, etc.

## 150. `0x1400b39b0` (1,034 bytes). `gene_lookup_helper`
Called by `apply_gene_to_horse_helper` and the chromosome scanner. Looks up a
gene by index in the chromoMap.

## 151. `0x14009e2f0` (1,027 bytes). `font_atlas_lookup`
Looks up a glyph in the font atlas. Used by the dialog renderer.

## 152. `0x1402cd4e0` (1,018 bytes). `msvc_runtime_helper`
MSVC.

## 153. `0x1400fdee0` (1,018 bytes). `tmx_post_load_init`
Called by `load_game`. After loading the map, runs per-location setup.

## 154. `0x1400d9010` (1,018 bytes). `audio_decoder_helper`
Vorbis decoder support.

## 155. `0x14004c420` (1,017 bytes). `vorbis_helper_4`
Vorbis decoder.

## 156. `0x14001b740` (1,014 bytes). `geometry_helper_recursive_4`
Math.

## 157. `0x140011cb0` (1,012 bytes). `physics_helper`
Box2D-like physics helper.

## 158. `0x1401046c0` (1,004 bytes). `enter_location_handler`
Strings: `EnterLocation, EnterLocationStable`. Plays the location-enter sound
when the player enters a building. Triggers an auto-save on entry.

## 159. `0x1400113e0` (1,002 bytes). `physics_helper_2`
Math/physics.

## 160. `0x140071420` (993 bytes). `sprite_render_helper`
Sprite rendering.

## 161. `0x140073c30` (989 bytes). `sprite_helper`
Sprite rendering sub-helper.

## 162. `0x1400c4a10` (965 bytes). `string_concat_helper`
Builds strings.

## 163. `0x1400c9420` (961 bytes). `unknown_string_lookup`
Strings: `"unknown"`. Returns "unknown" when a lookup fails.

## 164. `0x140057c20` (961 bytes). `tile_load_helper`
Tile loader helper.

## 165. `0x140020340` (948 bytes). `geometry_helper`
Math.

## 166. `0x14004d8d0` (946 bytes). `vorbis_helper_5`
Vorbis.

## 167. `0x1400c43d0` (935 bytes). `xml_open_file`
Called by `load_genes_xml` and friends. Opens an XML file by filename.

## 168. `0x1400a65d0` (920 bytes). `xml_parse_helper`
XML parsing sub-helper.

## 169. `0x140086570` (919 bytes). `text_draw_centered`
Draws centered text. Called by render handlers.

## 170. `0x14010d260` (918 bytes). `tile_picker_helper`
Pick a tile variant.

## 171. `0x1402cf520` (916 bytes). `msvc_runtime_helper`
MSVC.

## 172. `0x1402eef9c` (915 bytes). `msvc_runtime_helper`
MSVC.

## 173. `0x140105da0` (904 bytes). `population_lookup_helper`
Called by `pop_genome_builder`. Pop lookup sub-routine.

## 174. `0x1400168e0` (904 bytes). `geometry_helper`
Math.

## 175. `0x1400aac60` (902 bytes). `rng_helper`
Wraps FUN_1400c6580 (RNG). Called by many event handlers.

---

**Cumulative coverage: 175 of 1,234 game-logic functions = 14.2%.**
