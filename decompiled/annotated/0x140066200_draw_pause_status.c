// =============================================================================
// FUN_140066200 @ 0x140066200 -- proposed name: draw_pause_status
//
// PURPOSE:
//   Renders the pause-screen overlay. In normal mode shows "< Simulation Paused
//   - Year %d >". In DEBUG mode, shows "< Simulation Paused - Year %d  Sleeps
//   %d  Races %d >" and the cheat-menu buttons ("Betting Mode", "Gong", "Money",
//   "Loaded", "No Tire" / "Yes Tire").
//
//   Also implements the DEBUG MODE UNLOCK: a character-by-character matcher for
//   the literal string "debug" typed in the pause menu. When complete, sets
//   DAT_1403d959b = 1 which enables the debug status line and the cheat menu.
//
// CALLED BY: render loop (when the game is paused).
// SIZE: 4,188 bytes.
//
// THE CHEATS WE EXPOSED:
//   1. "debug" string unlock           (line 60371 of all_functions.c)
//   2. "No Tire" / "Yes Tire" toggle   (line 60434, sets DAT_1403d95c5)
//   3. "Money" button                  (line 60473: game_state[+0x308] += 1000)
//   4. "Loaded" button                 (line 60446-60470: 7 supply counters +20)
//   5. "Betting Mode" button           (mode swap)
//   6. "Gong" button                   (whatever the gong does)
//
// CONFIRMED BY JumboDS64 Steam guide: "enable debug mode by spelling d-e-b-u-g
// in the pause menu, then press 5 while in the hot air balloon" -- the "press
// 5" part is in a different function (balloon controller).
//
// KEY GLOBALS:
//   DAT_1403d959b -- debug mode active flag (set by "debug" string match)
//   DAT_1403d95c5 -- "No Tire" toggle (per-frame fatigue reset, see FUN_1400ce6c0)
//   DAT_1403eab10 -- progress counter for "debug" character match (0..5)
//   DAT_1403ed5d0 -- some character validity table (indexed by 'd','e','b','u','g')
//   DAT_1403fb0d8 -- main game-state struct base
//
// HORSEY MOD IMPLICATION:
//   This is the answer to the user's fatigue complaint: type d-e-b-u-g during
//   pause, then toggle "No Tire". No mod required.
// =============================================================================

void draw_pause_status(longlong param_1)
{
  // ... lots of UI rendering setup (X/Y coords, font, etc.) ...

  // ====== TIME ELAPSED / FRAME CHECK ======
  // Increment pause-screen tick counter.
  *(int *)(param_1 + 0x250) = *(int *)(param_1 + 0x250) + 1;

  // ... pause-screen mouse hover / dismissal logic ...

  // ====== DEBUG MODE UNLOCK ======
  // If progress < 5 AND the validity table at DAT_1403ed5d0 says the next
  // character of "debug" is valid right now, bump progress. When progress
  // hits 5, enable debug mode.
  if (((DAT_1403eab10 < 5) && ((&DAT_1403ed5d0)["debug"[DAT_1403eab10]] != '\0')) &&
     (DAT_1403eab10 = DAT_1403eab10 + 1, DAT_1403eab10 == 5)) {
    DAT_1403d959b = '\x01';           // <-- DEBUG MODE NOW ACTIVE
    DAT_1403d9522 = 0;
  }

  // ====== DRAW MENU ======
  // ... draw "Continue" button ...
  // ... draw "Reset Game" button ...

  if (DAT_1403d959b != '\0') {
    // ===== DEBUG MODE EXTRAS =====
    // Print debug status line.
    if (DAT_1403d959b == '\0' /* normal */) {
      sprintf(buf, "< Simulation Paused - Year %d >", year + 1);
    } else {
      sprintf(buf, "< Simulation Paused - Year %d  Sleeps %d  Races %d >",
              game_state.year + 1, game_state.sleeps, races_global);
    }
    draw_centered_text(buf);

    // ===== CHEAT BUTTONS =====
    if (button("Betting Mode")) { /* swap to betting mode */ }
    else if (button("Gong")) { /* play gong sound */ }
    else if (button("Money")) {
      // +$1000 cheat
      *(int *)(DAT_1403fb0d8 + 0x308) += 1000;
    }
    else if (button("Loaded")) {
      // +20 to each of 7 supply counters, set associated flag bytes.
      // The pattern is: for i in 0..6:
      //   *(uint8*)(state + 0x320 + i*8 + 1) = 1;
      //   *(uint8*)(state + 0x320 + i*8 + 0) = 1;
      //   *(int*)(state + 0x31c + i*8) += 20;
      //   FUN_140104370(state);   // probably re-renders supply UI
      // 7 supplies = 7 game resources (hay/apple/beer/hotsauce/plutonium/fossil/manure?)
    }
    else {
      // "No Tire" / "Yes Tire" toggle.
      const char *label = (DAT_1403d95c5 != '\0') ? "Yes Tire" : "No Tire";
      if (button(label)) {
        DAT_1403d95c5 = !DAT_1403d95c5;   // toggle fatigue-disable flag
      }
    }
  }
}
