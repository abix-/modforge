# Batch annotation 09. 80 more functions

Format: `# | addr (size) | name | purpose`. Verified from real extraction.

## 296-375 (80 functions)

| # | Addr | Size | Proposed name | Purpose |
|---|---|---|---|---|
| 296 | `0x1400b6360` | 682 | horse_helper | horse helper, no strings |
| 297 | `0x1400d83f0` | 680 | render_helper_3 | render |
| 298 | `0x1400c9980` | 680 | location_helper | location |
| 299 | `0x140102b40` | 673 | wild_horse_event | wild horse subroutine |
| 300 | `0x1400d7fe0` | 673 | render_helper_4 | render |
| 301 | `0x140101dc0` | 663 | wild_horse_helper | wild horse |
| 302 | `0x140105b00` | 661 | champ_helper | champion-related |
| 303 | `0x140049b70` | 655 | audio_helper | audio |
| 304 | `0x140084060` | 653 | tile_helper | tile |
| 305 | `0x140010ce0` | 653 | physics_helper | physics |
| 306 | `0x140104370` | 650 | supply_ui_refresh | called from Loaded cheat path; updates supply counter UI |
| 307 | `0x1400cd2d0` | 640 | pointer_attach_handler | `PointerAttach` cursor mode |
| 308 | `0x1400c7d80` | 639 | save_write_timestamp | sub-helper of save writer for timestamp field |
| 309 | `0x140032320` | 639 | crazy_horse_handler | references "crazy horse" pop |
| 310 | `0x140043810` | 638 | audio_helper | audio |
| 311 | `0x1401c9f60` | 637 | blit_shader_compiler | SDL_GPU: compiles BlitFrom2D/2DArray/3D/Cube pixel + vertex shaders |
| 312 | `0x1400b8f90` | 636 | horse_state_setter | horse state setter |
| 313 | `0x1400d86a0` | 632 | render_helper_5 | render |
| 314 | `0x140048910` | 630 | vorbis_helper | vorbis |
| 315 | `0x140110bf0` | 625 | helper_unnamed | helper |
| 316 | `0x1400bf3c0` | 623 | helper_unnamed | helper |
| 317 | `0x140042b70` | 608 | audio_helper | audio |
| 318 | `0x1400820a0` | 607 | wild_horse_event_2 | wild horse helper |
| 319 | `0x140047690` | 603 | vorbis_helper | vorbis |
| 320 | `0x1402e6268` | 602 | msvc_runtime_helper | MSVC |
| 321 | `0x1402d6bc0` | 601 | msvc_runtime_helper | MSVC |
| 322 | `0x14000e0e0` | 601 | physics_helper | physics |
| 323 | `0x14004d150` | 600 | vorbis_helper | vorbis |
| 324 | `0x1400d5d90` | 597 | trailer_event | `Trailer` (probably horse-trailer / transport event) |
| 325 | `0x1402d7d00` | 593 | msvc_runtime_helper | MSVC |
| 326 | `0x140073780` | 592 | sprite_helper | sprite |
| 327 | `0x140069ee0` | 590 | saloon_newspaper | `Newspaper` (saloon news reading) |
| 328 | `0x1400fb050` | 589 | horse_render_helper | `Horse` (horse render) |
| 329 | `0x14003f340` | 575 | audio_helper | audio |
| 330 | `0x140094540` | 574 | shred_event | `Shred` (paper-shredding effect, treasure?) |
| 331 | `0x1401107d0` | 571 | helper_unnamed | helper |
| 332 | `0x1400c7910` | 566 | no_record_dialog | `%s%s%s` + `"No Record!"`. Formats horse history with No-Record fallback |
| 333 | `0x1400ffd00` | 565 | plain_tile_handler | `Plain` tile type |
| 334 | `0x140026080` | 562 | xml_assert | `q <= p` assertion in xml parser |
| 335 | `0x1400c31e0` | 555 | helper_unnamed | helper |
| 336 | `0x140005eb0` | 554 | physics_lock_assert | `IsLocked() == false` Box2D assert |
| 337 | `0x140053810` | 553 | audio_helper | audio |
| 338 | `0x140092150` | 552 | debug_pop_transform | `"%s - %d -> %d"`. Logs pop transform |
| 339 | `0x1400ccbd0` | 551 | helper_unnamed | helper |
| 340 | `0x1400b6aa0` | 551 | helper_unnamed | helper |
| 341 | `0x14005bc30` | 548 | crazy_horse_event | references "crazy horse" pop |
| 342 | `0x1400b54a0` | 546 | helper_unnamed | helper |
| 343 | `0x140041900` | 544 | audio_helper | audio |
| 344 | `0x14009bea0` | 543 | helper_unnamed | helper |
| 345 | `0x140100a40` | 535 | wild_horse_helper_3 | wild horse |
| 346 | `0x1400ab1b0` | 535 | cosmetic_helper | cosmetic |
| 347 | `0x14005cf70` | 534 | pop_inheritance_handler | references appletree/crazy horse/freak/hay/pepper/yeast pops. This is the pop tree iterator |
| 348 | `0x1400bedc0` | 528 | helper_unnamed | helper |
| 349 | `0x140030940` | 528 | location_save_helper | save sub-helper for location |
| 350 | `0x1402e6d50` | 518 | msvc_runtime_helper | MSVC |
| 351 | `0x1400b6610` | 518 | horse_state_helper | horse state helper |
| 352 | `0x14007dbf0` | 518 | lassomart_handler | `Lasso-Mart` location (item shop) |
| 353 | `0x1401b52b0` | 517 | vulkan_ext_check | VK_EXT_debug_utils, VK_KHR_get_physical_device_properties2 |
| 354 | `0x1402d307c` | 515 | msvc_runtime_helper | MSVC |
| 355 | `0x1402d2c6c` | 515 | msvc_runtime_helper | MSVC |
| 356 | `0x1402d285c` | 515 | msvc_runtime_helper | MSVC |
| 357 | `0x1400c8010` | 513 | save_read_timestamp | sub-helper of save loader for timestamp |
| 358 | `0x1400d8e00` | 511 | helper_unnamed | helper |
| 359 | `0x1402eda40` | 510 | msvc_runtime_helper | MSVC |
| 360 | `0x140111a50` | 508 | helper_unnamed | helper |
| 361 | `0x140046e50` | 506 | audio_helper | audio |
| 362 | `0x1402cfda0` | 502 | msvc_runtime_helper | MSVC |
| 363 | `0x1400a9360` | 502 | cosmetic_helper | cosmetic |
| 364 | `0x1400a33b0` | 501 | scratch_pop_handler | `scratch` pop reference |
| 365 | `0x14009ebd0` | 499 | font_helper | font |
| 366 | `0x1400c5d10` | 497 | helper_unnamed | helper |
| 367 | `0x140040ca0` | 497 | sound_dispatch | one of the main sound-trigger entry points |
| 368 | `0x140025120` | 497 | xml_helper | xml parser helper |
| 369 | `0x1400fd1e0` | 495 | crispr_exit_vial | called from CRISPR state 0xd; exits vial sub-world |
| 370 | `0x140011000` | 494 | physics_helper | physics |
| 371 | `0x1400111f0` | 493 | physics_helper | physics |
| 372 | `0x1400a9560` | 486 | cosmetic_helper | cosmetic |
| 373 | `0x1400749b0` | 486 | sprite_helper | sprite |
| 374 | `0x1400a2ed0` | 485 | bad_pop_logger | `"Bad Pop %d"`. Error for unknown population |
| 375 | `0x14005de20` | 485 | letter_g_render | `LetterG` (DNA piece "G" render) |

---

**Cumulative coverage: 375 of 1,234 game-logic functions = 30.4%.**

**Specific new mod-relevant finds in this batch:**

- `0x140104370`: supply_ui_refresh. Called by the Loaded cheat to update supply UI after counter bump.
- `0x14005cf70`: pop_inheritance_handler. Confirms pop.xml has nested pops (appletree, crazy horse, freak, hay, pepper, yeast all reachable from one function).
- `0x1400a2ed0`: `Bad Pop %d` debug. Error fires when a spawner references an unknown pop name.
- `0x1401c9f60`: blit shader compiler (vendor, SDL_GPU).
- `0x140092150`: debug pop transform logger. `"%s - %d -> %d"` logs pop changes.
- `0x1400fd1e0`: crispr_exit_vial. Second piece of the CRISPR state machine that we annotated earlier.
- `0x1400c7910`: handles the "No Record!" placeholder when a horse has no races.
