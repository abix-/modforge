// =============================================================================
// FUN_14006dc80 @ 0x14006dc80 -- proposed name: save_game_writer
//
// PURPOSE:
//   Writes the entire game state to save<N>.dat where <N> = param_2. This is
//   the source of truth for the save file format. We've been reverse-engineering
//   the file layout statically; this function tells us EXACTLY what each byte
//   means and in what order.
//
// CALLED BY: save-game UI action handler.
// SIZE: 2,026 bytes.
//
// FORMAT FROM THE WRITER (in order; helper functions decoded by signature):
//
//   FUN_140075670(x)  -- write uint32
//   FUN_140075750(x)  -- write uint8
//   FUN_140075730(x)  -- write count/length (uint32)
//   FUN_140075790(x)  -- write uint64
//   FUN_140075770()   -- write separator (probably uint8 or padding)
//   FUN_140075650()   -- write separator (likely uint8 = 0)
//   FUN_1400c7d80()   -- write timestamp (the fd b9 1b 62 at file offset 4)
//   FUN_1400755a0(N)  -- pre-allocate N bytes for the save buffer (250000 here)
//
// HEADER (first ~20 bytes):
//   1. version       uint32 = 12 = 0x0c            (FUN_140075670(0xc))
//   2. timestamp     uint32 = 1645984253           (FUN_1400c7d80)
//   3. separator     uint32 = 0                    (FUN_140075650)
//   4. frame_tick    uint32 = game_state[+0x254]
//   5. year          uint32 = game_state[+0x314]   (we identified this earlier)
//   6. unknown       uint32 = game_state[+0x268]
//
// AFTER HEADER:
//   - separator      uint32 = 0
//   - sleeps         uint32 = game_state[+0x318]
//   - money          uint32 = game_state[+0x308]   (Money cheat target)
//   - field_0x440    uint32 = game_state[+0x440]
//   - flag_0x414     uint8  = game_state[+0x414]
//   - flag_0x415     uint8  = game_state[+0x415]
//   - field_0x37c    uint32 = game_state[+0x37c]
//   - zero           uint8  = 0
//   - field_0x418    uint32 = game_state[+0x418]
//   - flag_0x41c     uint8  = game_state[+0x41c]
//   - field_0x39c    uint64 = game_state[+0x39c]   (8 bytes!)
//   - field_0x410    uint32 = game_state[+0x410]
//
//   SUPPLIES BLOCK (6 iterations, each 6 bytes):
//     for i in 0..5:
//       uint8  = supplies[i].flag_after          (game_state[0x31c + i*8 + 5])
//       uint32 = supplies[i].count               (game_state[0x31c + i*8])
//       uint8  = supplies[i].flag_before         (game_state[0x31c + i*8 + 1])
//   (Note: 6 iterations + Loaded cheat sets 7 supplies. The 7th is probably
//    written elsewhere or this is 6 of 7. Need to re-check.)
//
//   MISC BLOCK (13 iterations, each 8 bytes):
//     for i in 0..12:
//       uint32 = game_state[+0x294 + i*4]        (puVar6[-0xd] when puVar6 starts at 0x2cc)
//       uint32 = game_state[+0x2cc + i*4]
//
//   - separator      uint32 = 0
//
//   HORSE ROSTER:
//     uint32 = horse_count = (game_state[+0x288] - game_state[+0x280]) / 0x24
//     // each horse record is 0x24 = 36 bytes in MEMORY, but written as variable
//     // bytes in the file (length-prefixed strings + fixed trailer; this matches
//     // the per-horse record format we walked statically).
//     for each horse:
//       (writes happen in the loop body that follows at line 64500+ -- not
//        captured in this annotation pass)
//
// KEY GAME-STATE FIELDS DISCOVERED HERE:
//   +0x254  frame_tick      (pause-screen / overall ticker)
//   +0x268  unknown_uint32
//   +0x280  horses_begin    pointer (vector begin)
//   +0x288  horses_end      pointer (vector end)
//   +0x37c  unknown_uint32
//   +0x39c  unknown_uint64  (8 bytes)
//   +0x410  unknown_uint32
//   +0x414  unknown_uint8
//   +0x415  unknown_uint8
//   +0x418  unknown_uint32
//   +0x41c  unknown_uint8
//   +0x440  unknown_uint32
//   +0x294..0x2cc  13 uint32s
//
// HORSEY MOD IMPLICATION:
//   - We now know the EXACT save layout. A python save reader/writer is trivial
//     to implement.
//   - The "_saving_" debug print at the top means the save is logged in debug.
//   - The pre-allocation of 250000 bytes matches our save file size of ~245KB.
//     The save is allocated up-front, not streamed, so the buffer is bounded.
// =============================================================================

void save_game_writer(longlong param_1, int param_2)
{
  FUN_1400c4320("_saving_");                  // debug print

  // ... handle special pre-save modes (mode 0x1c = championship?, mode -1 = ???) ...

  // Build "save<N>.dat" path.
  FUN_14008d760(&local_48, "save%d.dat", param_2);

  // ... open file, prep writer state ...

  // Pre-allocate 250KB buffer.
  FUN_1400755a0(250000);

  // === HEADER ===
  FUN_140075670(0xc);                                       // save version
  FUN_1400c7d80();                                          // timestamp
  FUN_140075650();                                          // 0 separator
  FUN_140075670(*(uint32_t *)(param_1 + 0x254));            // frame_tick
  FUN_140075670(*(uint32_t *)(param_1 + 0x314));            // year
  FUN_140075670(*(uint32_t *)(param_1 + 0x268));            // ?
  FUN_140075770();                                          // separator

  // === GLOBAL FIELDS ===
  FUN_140075670(*(uint32_t *)(param_1 + 0x318));            // sleeps
  FUN_140075670(*(uint32_t *)(param_1 + 0x308));            // money
  FUN_140075670(*(uint32_t *)(param_1 + 0x440));            // ?
  FUN_140075750(*(uint8_t  *)(param_1 + 0x414));            // flag
  FUN_140075750(*(uint8_t  *)(param_1 + 0x415));            // flag
  FUN_140075670(*(uint32_t *)(param_1 + 0x37c));            // ?
  FUN_140075750(0);                                         // 0 byte
  FUN_140075670(*(uint32_t *)(param_1 + 0x418));            // ?
  FUN_140075750(*(uint8_t  *)(param_1 + 0x41c));            // flag
  FUN_140075790(*(uint64_t *)(param_1 + 0x39c));            // 8 bytes
  FUN_140075670(*(uint32_t *)(param_1 + 0x410));            // ?

  // === SUPPLIES (6 entries; each 6 bytes) ===
  // game_state[+0x31c + i*8] = count;
  // game_state[+0x320 + i*8] = flag_a;
  // game_state[+0x321 + i*8] = flag_b;
  uint32_t *p = (uint32_t *)(param_1 + 0x31c);
  for (int i = 0; i < 6; i++) {
    FUN_140075750(*(uint8_t *)((char *)p + 5));   // flag_b at p+5
    FUN_140075670(*p);                            // count at p+0
    FUN_140075750(*(uint8_t *)(p + 1));           // flag_a at p+4
    p += 2;                                        // stride 8 bytes
  }

  // === MISC 13 PAIRS (each 8 bytes) ===
  uint32_t *q = (uint32_t *)(param_1 + 0x2cc);
  for (int i = 0; i < 13; i++) {
    FUN_140075670(q[-0xd]);     // game_state[+0x294 + i*4]
    FUN_140075670(*q);          // game_state[+0x2cc + i*4]
    q++;
  }

  FUN_140075650();                                          // separator

  // === HORSE ROSTER ===
  size_t horse_count = (game_state[+0x288] - game_state[+0x280]) / 0x24;
  FUN_140075730(horse_count);
  // ... loop writes each horse's name + parents + flags + children ...
  // ... (continues at line 64500+; not captured here) ...
}
