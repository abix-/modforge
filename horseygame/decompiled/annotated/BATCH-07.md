# Batch annotation 07. 40 more functions

## 176. `0x1400dbe10` (896 bytes). `post_race_wrapup`
The caller of `retire_horse_handler`. Handles post-race cleanup: stat updates,
year-gated retirement trigger.

## 177. `0x1400ff790` (886 bytes). `loc_secondary_sprite_picker`
Strings: `"Loc%s2"`. Picks the "second variant" sprite for a location (e.g.
`LocStable2`). Used during render for the busy/full variant.

## 178. `0x1402eb6f0` (882 bytes). `msvc_runtime_helper`
MSVC.

## 179. `0x1402d4650` (878 bytes). `msvc_runtime_helper`
MSVC.

## 180. `0x1400d23d0` (873 bytes). `chomp_event`
Strings: `Chomp`. Plays the Chomp sound. Called when a horse eats.

## 181. `0x1402d42e8` (871 bytes). `msvc_runtime_helper`
MSVC.

## 182. `0x1400d2740` (869 bytes). `poof_heart_event`
Strings: `PoofHeart`. Plays the PoofHeart sound (love-burst effect during
breeding or affection events).

## 183. `0x1400bea50` (869 bytes). `cosmetic_helper`
Cosmetic application sub-helper.

## 184. `0x1400fce70` (860 bytes). `crispr_enter_vial`
Called by CRISPR state machine. Transitions player into vial sub-world.

## 185. `0x140060710` (855 bytes). `champion_record_save`
Strings: `"champ"`. Saves the current champion record (called by save_writer
and the championship event).

## 186. `0x1400164b0` (854 bytes). `geometry_helper`
Math.

## 187. `0x1400b3650` (851 bytes). `gene_apply_helper_2`
Gene application sub-helper.

## 188. `0x14004d3b0` (851 bytes). `vorbis_helper`
Vorbis.

## 189. `0x140067ad0` (850 bytes). `dialog_substring_helper`
Helper for dialog text rendering.

## 190. `0x1400379e0` (850 bytes). `circus_metadata`
Strings: `Circus, "The Circus"`. Sets up circus metadata when loaded.

## 191. `0x1400b6fd0` (849 bytes). `dialog_state_helper`
Dialog sub-helper.

## 192. `0x1400c8220` (831 bytes). `string_helper_2`
Generic string utility.

## 193. `0x1402cf1e0` (830 bytes). `msvc_runtime_helper`
MSVC.

## 194. `0x1401bbf50` (828 bytes). `vulkan_function_loader`
Strings show repeated vulkan function pointer loads
(`param_1[0x127..0x137] = (*DAT_1403fce10)(...)`).
This is a **Vulkan function-pointer loader**. Each entry resolves a Vulkan
API function by name into the engine's dispatch table. Vendor code.

## 195. `0x1400d2090` (821 bytes). `racer_render_helper`
Helper for racer rendering.

## 196. `0x140088990` (817 bytes). `crispr_helper`
CRISPR sub-helper.

## 197. `0x14006ee10` (816 bytes). `save_writer_helper`
Calls FUN_140075650 / 670 / 690 / 6b0 / 6d0 / 710 / 750 / 790 (save writers).
A composite save-write helper.

## 198. `0x1402ee62c` (815 bytes). `msvc_runtime_helper`
MSVC.

## 199. `0x1400a5950` (810 bytes). `xml_attr_helper`
XML attribute helper.

## 200. `0x1401b5d50` (805 bytes). `vulkan_extension_query`
Strings: `"%s %s", SDLGPU, VK_KHR_get_physical_device_properties2`. Vulkan
extension query. Vendor.

## 201. `0x140102530` (805 bytes). `wild_horse_position_helper`
Sub-helper of wild_horse_ai_step.

## 202. `0x14008f6e0` (804 bytes). `paddock_track_metadata`
Strings: `Paddock, "Race Track", Track`. Location metadata setter for Paddock
and Race Track.

## 203. `0x1400479b0` (800 bytes). `vorbis_helper`
Vorbis.

## 204. `0x140101990` (799 bytes). `wild_horse_helper`
Wild horse sub-helper.

## 205. `0x1400293d0` (790 bytes). `xml_encoding_check`
Strings: `"UTF-8", "UTF8"`. Validates the XML encoding declaration. Called by
all XML loaders.

## 206. `0x1400119a0` (780 bytes). `physics_helper`
Math/physics.

## 207. `0x140088000` (775 bytes). `crispr_lab_metadata`
Strings: `"CRISPR Lab", Crispr`. Location metadata setter for CRISPR Lab.

## 208. `0x14006f150` (772 bytes). `save_load_helper`
Calls many save reader helpers. Composite save-read helper.

## 209. `0x140080730` (766 bytes). `wild_horse_helper_2`
Wild horse AI.

## 210. `0x140024220` (766 bytes). `string_helper`
Strings/utility.

## 211. `0x140048b90` (765 bytes). `vorbis_helper`
Vorbis.

## 212. `0x1400b56d0` (761 bytes). `horse_helper`
Generic horse helper.

## 213. `0x1400120b0` (754 bytes). `physics_helper`
Math.

## 214. `0x140055060` (753 bytes). `audio_helper`
Audio.

## 215. `0x14008d460` (752 bytes). `string_format_helper`
String builder.

---

**Cumulative coverage: 215 of 1,234 game-logic functions = 17.4%.**
