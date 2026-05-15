// =============================================================================
// FUN_14006e480 @ 0x14006e480 -- proposed name: load_game
//
// PURPOSE:
//   Load save<N>.dat into the game-state struct at param_1. Mirrors the writer
//   at FUN_14006dc80 byte-for-byte. The order of FUN_140075xxx calls in this
//   function IS the save file format.
//
// CALLED BY: load-game UI action.
// SIZE: 2,439 bytes.
//
// READER FUNCTION SIGNATURES (inferred by their use):
//   FUN_140075da0()             -- read uint32 (returns the value)
//   FUN_1400c8010()             -- read timestamp
//   FUN_140075b80(ptr)          -- read uint32, store at *ptr
//   FUN_140075e80(ptr)          -- read uint8,  store at *ptr
//   FUN_140075f20(local, ptr)   -- read uint64, store at *ptr (with helper)
//   FUN_140075ed0(ptr)          -- read uint8,  store at *ptr (variant)
//   FUN_140075cb0(ptr)          -- read length-prefixed string into ptr->std::string
//
// SAVE VERSION:
//   First field read is the version. Stored globally at DAT_1403fb0e0.
//   Current version (writer) is 12 (0x0c). Loader does conditional reads based
//   on this: e.g. line 64750 `if (0xb < DAT_1403fb0e0)` means "if version > 11,
//   read an additional horse field at +0xc". So save format is forward-compatible
//   forks back through v0.
//
// HORSE ROSTER (in-memory layout reconstructed):
//   Each horse occupies 0x24 = 36 bytes in the in-memory `param_1 + 0x280..0x288`
//   vector. The loader reads:
//     horse[+0x4]  uint32  (read for ALL versions)
//     horse[+0x8]  uint32  (all versions)
//     horse[+0xc]  uint32  (ONLY IF save version > 11) - new in v12
//     horse[+0x10] uint32  (all versions)
//   But there are MORE fields per horse than 4 uint32s. The full reconstruction
//   would require reading FUN_140075cb0 — which is probably a length-prefixed
//   string reader (the horse name). So each horse record on disk is:
//     - name      length-prefixed UTF-8 string  (we already documented this)
//     - 4 or 5 trailer fields                    (this confirms the trailer
//                                                  size we computed: 22 bytes
//                                                  for v<=11, plus 4 bytes
//                                                  for v>=12)
//
// VERSION HISTORY (inferred):
//   v0..v11: 4 trailer uint32s per horse
//   v12: adds a 5th field. This explains the extra 4 bytes we noticed in
//        record sizes between Dale (30B) and others.
//
// FULL HEADER + FIELDS READ:
//   1. version              uint32  -> DAT_1403fb0e0
//   2. timestamp                    -> internal time state
//   3. frame_tick           uint32  -> game_state[+0x254]
//   4. year                 uint32  -> game_state[+0x314]
//   5. ?                    uint32  -> game_state[+0x268]
//   6. ?                    uint8   -> game_state[+0x114]   (note: uint8, not 32)
//   7. sleeps               uint32  -> game_state[+0x318]
//   8. money                uint32  -> game_state[+0x308]
//   9. ?                    uint32  -> game_state[+0x440]
//  10. flag                 uint8   -> game_state[+0x414]
//  11. flag                 uint8   -> game_state[+0x415]
//  12. ?                    uint32  -> game_state[+0x37c]
//  13. (discarded)          uint8
//  14. ?                    uint32  -> game_state[+0x418]
//  15. flag                 uint8   -> game_state[+0x41c]
//  16. ?                    uint64  -> game_state[+0x39c]
//  17. ?                    uint32  -> game_state[+0x410]
//
//   SUPPLIES (6 iterations, 6 bytes each):
//   18a. flag_after          uint8   -> game_state[+0x31c + i*8 + 5]
//   18b. count               uint32  -> game_state[+0x31c + i*8 + 0]
//   18c. flag_before         uint8   -> game_state[+0x31c + i*8 + 4]
//
//   MISC 13 PAIRS (8 bytes each):
//   19a. uint32 -> game_state[+(0x2cc - 0x34) + i*4] = game_state[+0x298 + i*4]
//   19b. uint32 -> game_state[+0x2cc + i*4]
//
//   HORSE ROSTER:
//   - vector resize / capacity adjust on game_state[+0x280..+0x288] (stride 0x24)
//   - for each horse:
//       uint32 read into horse[+0x4]
//       uint32 read into horse[+0x8]
//       if (save_version > 11) uint32 read into horse[+0xc]
//       uint32 read into horse[+0x10]
//       // (more fields including name follow but truncated in our snippet)
//
//   TRAILING FIELDS:
//   - uint32 -> game_state[+0x278]
//   - uint32 -> game_state[+0x27c]
//
//   TILE NAME INIT: After load, initialize sub-state with "Water", "Plain" tile
//   labels. These are likely tile-rendering setup, not save-format data.
//
// HORSEY MOD IMPLICATION:
//   - DAT_1403fb0e0 is the loaded save version. We can detect what save format
//     is loaded by reading this.
//   - To save-edit a value (e.g. money), the binary offset can be derived by
//     replaying the writer's sequence with known field sizes. We know money is
//     7th uint32 in the global block (after header). Exact byte offset:
//       4 (version) + 4 (timestamp) + 4 (separator) + 4*3 (header fields) +
//       4*1 (sleeps comes 1st in the field block, so... actually let me re-count)
//     The cleanest way: parse the save file with a python reader using the
//     same sequence.
// =============================================================================

int load_game(longlong *param_1, int param_2)
{
  FUN_14008d760(local_58, "save%d.dat", param_2);
  uVar6 = FUN_1400c4df0();
  uVar6 = FUN_14006f590(&local_78, uVar6);
  cVar4 = FUN_1400753f0(0, uVar6);   // open file for reading

  if (cVar4 == '\0') return 0;       // file not found

  DAT_1403fb0e0 = FUN_140075da0();   // read save version (uint32)
  FUN_1400c8010();                   // read timestamp

  // === HEADER FIELDS ===
  FUN_140075b80((longlong)param_1 + 0x254);   // frame_tick
  FUN_140075b80((longlong)param_1 + 0x314);   // year
  FUN_140075b80(param_1 + 0x4d);              // = +0x268
  FUN_140075ed0((longlong)param_1 + 0x114);   // read uint8 -> +0x114
  FUN_140075b80(param_1 + 99);                // = +0x318 sleeps
  FUN_140075b80(param_1 + 0x61);              // = +0x308 money
  FUN_140075b80(param_1 + 0x88);              // = +0x440
  FUN_140075e80((longlong)param_1 + 0x414);   // flag uint8
  FUN_140075e80((longlong)param_1 + 0x415);   // flag uint8
  FUN_140075b80((longlong)param_1 + 0x37c);   // ?
  FUN_140075e80(local_res20);                 // discarded uint8
  FUN_140075b80(param_1 + 0x83);              // = +0x418
  FUN_140075e80((longlong)param_1 + 0x41c);   // flag uint8
  FUN_140075f20(&local_res18, (longlong)param_1 + 0x39c);  // 8-byte field
  FUN_140075b80(param_1 + 0x82);              // = +0x410

  // === SUPPLIES (6 entries; 6 bytes each on disk) ===
  for (int i = 0, ptr = param_1 + 0x31c; i < 6; i++, ptr += 8) {
    FUN_140075e80(ptr + 5);     // flag at +5
    FUN_140075b80(ptr);         // count at +0
    FUN_140075e80(ptr + 4);     // flag at +4
  }

  // === MISC 13 PAIRS (8 bytes each) ===
  for (int i = 0, ptr = param_1 + 0x2cc; i < 13; i++, ptr += 4) {
    FUN_140075b80(ptr - 0x34);  // = +0x298 + i*4
    FUN_140075b80(ptr);         // = +0x2cc + i*4
  }

  // === HORSE ROSTER ===
  // Resize the horse vector at param_1[+0x280..+0x288] (stride 0x24).
  int horse_count = FUN_140075da0();
  // ... resize logic ...
  for (each of horse_count horses) {
    FUN_140075cb0(horse + 0x4);     // string (probably name)
    FUN_140075cb0(horse + 0x8);     // string or field
    if (DAT_1403fb0e0 > 11) FUN_140075cb0(horse + 0xc);   // version 12+ field
    FUN_140075cb0(horse + 0x10);
  }

  // === TRAILING ===
  FUN_140075b80(param_1 + 0x4f);              // = +0x278
  FUN_140075b80((longlong)param_1 + 0x27c);

  // ... (after this, terrain tile names like "Water" / "Plain" are initialized;
  //      this is not save-format data, just post-load engine setup) ...
}
