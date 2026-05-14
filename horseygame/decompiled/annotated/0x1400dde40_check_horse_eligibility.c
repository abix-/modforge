// =============================================================================
// FUN_1400dde40 @ 0x1400dde40 -- proposed name: check_horse_eligibility
//
// PURPOSE:
//   The central "can this horse do this action?" function. Branches on a state
//   field of the game/player struct (param_1+0x258 = action mode) and on each
//   horse's status fields. Produces popup messages:
//     - "Horse is too tired!"
//     - "Horse is too old!"
//     - "Horse is too young!"
//     - "Horse is too hungry!"
//     - "Why not go home and rest your horse"
//     - other guidance dialog
//
// CALLED BY: FUN_1400de0e0 (action-button handler), once.
// SIZE: 5,159 bytes (large, complex branching).
//
// KEY HORSE STRUCT FIELDS REFERENCED:
//   horse + 0x204   -- some boolean state flag (probably "is on the track")
//   horse + 0x205   -- tiredness flag A (zeroed by Yes Tire cheat)
//   horse + 0x206   -- tiredness flag B (zeroed by Yes Tire cheat)
//   horse + 0x21c   -- skill / fitness counter
//   horse + 0x1fc   -- age (from retirement-handler analysis)
//
// KEY GAME-STATE FIELDS:
//   param_1 + 0x130 / 0x138   -- horse list begin/end (vector of pointers)
//   param_1 + 0x184 / 0x188   -- target cursor x/y in world coords
//   param_1 + 0x258           -- current action mode (race/buy/etc.)
//   param_1 + 0x350           -- some "current horse index" sentinel
//   param_1 + 0x39c / 0x3a0   -- some float thresholds (FOV? screen pos?)
//   param_1 + 0x450           -- some mode flag
//   param_1 + 0x464           -- last_retirement_year (also touched here)
//
// HORSEY MOD IMPLICATION:
//   Patching this function (or hooking it) lets us BYPASS individual eligibility
//   checks. Cleaner than the "Yes Tire" flag because it works without entering
//   debug mode. Specifically: returning a fixed "OK" value from the fatigue
//   branch would always allow racing regardless of horse state.
// =============================================================================

// (Full body in decompiled/all_functions.c lines 130000-135159. Key annotated
// regions follow.)

undefined1 check_horse_eligibility(longlong param_1, int param_2, int param_3)
{
  // ... unpack horse pointer at horse_list[param_2] ...
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8);

  // GUARD 1: if current mode != 0 AND horse flag at +0x204 is 0, do
  //          a viewport bounds check (probably "is the horse on-screen?").
  if ((*(int *)(param_1 + 600) != 0) && (*(char *)(lVar1 + 0x204) == '\0')) {
    // ... viewport bounds calculation against fixed horse rectangle ...
    // If horse is OUT of view, return without further checks.
  }

  // -----------------------------------------------------------------------
  // BRANCH: if param_3 == 0, do the FULL action-eligibility tree below.
  // Otherwise (param_3 != 0) take a different code path (probably just-status).
  // -----------------------------------------------------------------------
  if (param_3 == 0) {
    // SUB-BRANCH: if mode 6, iterate horse list and count those matching
    //             type==3 AND subtype==4. This is the "Champion race entry"
    //             count check ("Only one Champion entry at a time please").
    if (*(int *)(param_1 + 600) == 6) {
      // ... iterate horses, count type==3 subtype==4 ...
      // ... emit "%s is already a Champion horse!" if dup ...
    }
    // ...other mode-specific eligibility checks...
  }

  // ... (continues for ~5KB more with branches for each action mode) ...

  // The "Horse is too tired!" branch is reached when the horse's tiredness
  // bytes at +0x205 / +0x206 are non-zero. With the Yes Tire cheat active,
  // those bytes are zeroed every frame so this branch never fires.
}
