// =============================================================================
// FUN_140094a20 @ 0x140094a20 -- proposed name: betting_and_race_state_machine
//
// PURPOSE:
//   Track-and-betting state machine. Drives the full race-track interaction:
//   placing bets, queuing the next race, "Click Race when ready!", warning
//   dialogs ("But the odds are slim"), the race itself (RaceGetSet, RaceGo),
//   crossing the finish line, awarding the prize, etc.
//
// CALLED BY: per-frame update when player is on the Track location.
// SIZE: 13,205 bytes (one of the largest game functions; 7th by size overall).
//
// STATE MACHINE: dispatches on iVar10 = *(int *)(param_1 + 0x3d4) (or similar).
//
// OBSERVED STATES (from string anchors):
//   0  -- "How much will you bet?"
//   1  -- "Click Race when ready!"                  (sets state -> 2)
//   2  -- Pre-race; waiting for player to start
//   3  -- "RaceGetSet" sound trigger
//   4  -- "RaceGo" sound trigger; race in progress
//   5  -- "But the odds are slim" dialog
//   6  -- "Won race" handling
//   ...
//
// KEY STATE FIELDS (param_1):
//   param_1 + 0x60     -- pointer to the Track sub-state
//   param_1 + 0x1f8    -- some mode int (set to 1 in multiple branches)
//   param_1 + 0x3d4    -- main state index (the iVar10 above)
//   param_1 + 0xa1d (relative to substate at +0x60)  -- "race started" byte flag
//
// HORSEY MOD IMPLICATION:
//   This is where the actual race outcomes are computed. The race uses horse
//   speed + skill stats (we already know +0x21c is skill) and a few RNG calls.
//   For "always win" mods, this function is the patch target.
//
//   NOT addressing fatigue: race entry eligibility is checked elsewhere
//   (FUN_1400dde40); this function assumes a horse is eligible already.
// =============================================================================
// (Full body in all_functions.c lines 88680+. State machine cases are dense
//  with std::string construction boilerplate per case; the per-case payload is
//  small.)
