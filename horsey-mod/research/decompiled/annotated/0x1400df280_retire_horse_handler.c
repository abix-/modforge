// =============================================================================
// FUN_1400df280 @ 0x1400df280 -- proposed name: retire_horse_handler
//
// PURPOSE:
//   Picks up to one horse from the active track horse list and retires it.
//   Three retirement reasons:
//     - (old)     -- horse has a record (won races): "%s retired %s (old) ch %d races %d wins %d%s"
//     - (bails)   -- horse has skill but never won: "%s retired %s (bails) age %d ch %d"
//     - (useless) -- horse has no skill: "%s retired %s (useless) age %d ch %d"
//   Optionally releases the horse "into the wild" if it still has lifespan left
//   AND the year is past 3 AND a 1-in-4 RNG check passes.
//
// CALLED BY: FUN_1400dbe10 (post-race wrap-up). Gated to once per game year.
// SIZE: 4,364 bytes.
//
// KEY HORSE STRUCT FIELDS:
//   horse + 0x1fc   -- age (int32)              -- compared as `< max_age - 1` for release-to-wild
//   horse + 0x21c   -- skill / fitness count
//   horse + 0x3f * 8 = +0x1f8  -- horse name ID (passed to FUN_1400c78c0 lookup)
//   *(int*)(puVar21 + 0x40) i.e. horse[+0x200] -- max_age (int32)
//
// KEY STATS STRUCT (lVar9 from FUN_1400c7520):
//   stats + 0x50   -- race wins count
//   stats + 0x54   -- something nonzero = "has record"
//   stats + 0x58   -- byte flag = "good horse suffix" (toggles trailing %s)
//   stats + 0x70 / 0x78 -- begin/end of races array (count = (end - begin) / 4)
//
// KEY GAME-STATE FIELDS (param_1):
//   param_1 + 0x130 / 0x138 -- horse list begin/end
//   param_1 + 0x148        -- skip-this-horse pointer (player's active horse)
//   param_1 + 0x464        -- last_retirement_year (gates one retirement/year)
//   param_1 + 0x468        -- retirement-attempts counter (increments every call)
//   param_1 + 600 (0x258)  -- current mode (race/etc.)
//   DAT_1403fb0d8 + 0x314  -- current year (global)
//   DAT_1403d9526          -- debug log flag (gates "%s retired ..." prints)
//   DAT_1403eded8          -- races counter global (checked > 0x3b = 59 for dachshund spawn?)
//
// HORSEY MOD IMPLICATION:
//   The retirement here is FITNESS-BASED, not age-based directly. The age field
//   only gates the release-to-wild alternative. To prevent retirement entirely,
//   ensure horse + 0x21c (skill) stays high or hook this function to return
//   without acting. Alternatively, set last_retirement_year to a future year.
// =============================================================================

void retire_horse_handler(longlong param_1, char param_2)
{
  // GUARD: only run if mode != 0.
  if (*(int *)(param_1 + 600) == 0) return;

  // Bump the attempt counter.
  *(int *)(param_1 + 0x468) = *(int *)(param_1 + 0x468) + 1;

  // GUARD: horse list empty? exit.
  lVar9 = *(longlong *)(param_1 + 0x130);
  if (lVar9 == *(longlong *)(param_1 + 0x138)) return;

  // STAMP "last retirement year" with the current year. This means the gate in
  // the caller (FUN_1400dbe10) will only let retirement run once per year.
  *(undefined4 *)(param_1 + 0x464) = *(undefined4 *)(DAT_1403fb0d8 + 0x314);

  // Count horses in the active list.
  uVar26 = (param_1->horse_list_end - param_1->horse_list_begin) / 8;
  iVar3 = 6 - (int)uVar26;   // 6 is the max-on-track threshold

  // Iterate horses; first one that fails skill/wins thresholds gets retired.
  for (each horse at index uVar31 in list) {
    puVar21 = horse_list[uVar31];

    // Skip the player's active horse.
    if (puVar21 == game.player_horse) continue;

    // Look up the horse's stats struct.
    lVar9 = FUN_1400c7520(*(undefined4 *)(puVar21 + 0x3f));
    cVar2 = FUN_1400b76a0(puVar21);    // "has a record?" check

    if (cVar2 == '\0') {                              // no record path
      if (uVar26 < 6) goto NEXT_HORSE;                // < 6 horses: don't retire anyone yet
      if (*(int *)(puVar21 + 0x21c) < (mode != 4 ? 2 : 1)) {
        // SKILL TOO LOW path -- might be useless or bails
        if (stats.wins < (mode != 4 ? 4 : 3) || stats.has_record != 0) goto NEXT_HORSE;
        if (debug_logging) {
          log("%s retired %s (useless) age %d ch %d", player.name, horse.name, horse.age, race_count);
        }
      } else if (debug_logging) {
        log("%s retired %s (bails) age %d ch %d", player.name, horse.name, horse.age, race_count);
      }
    } else if (debug_logging) {                       // had a record path
      const char *suffix = (stats.byte_0x58 != 0) ? "great-horse-suffix" : "blank";
      log("%s retired %s (old) ch %d races %d wins %d%s",
          player.name, horse.name, stats.wins, stats.race_count, ..., suffix);
    }

    // -------------------------------------------------------------------
    // If param_2 != 0 (the gated path), also emit the "%s%s retired %s"
    // user-facing dialog and play the retirement event.
    // -------------------------------------------------------------------
    if (param_2 != '\0') {
      // ... build and broadcast "%s%s retired %s" message ...
    }

    // Remove this horse from the active list (pop_back).
    *(longlong *)(param_1 + 0x138) -= 8;

    // RELEASE-TO-WILD branch.
    if (horse.age < horse.max_age - 1 &&
        DAT_1403fb0d8.year > 3 &&
        FUN_1400c6580(4) == 0 /* 1-in-4 RNG */) {
      if (debug_logging) log(" - released into the wild");
      FUN_140100e30(DAT_1403fb0d8, puVar21);  // release
    } else {
      // Otherwise: invoke horse vtable[0] (destructor). Horse is gone.
      (**(code **)*puVar21)(puVar21, 1);
    }
    break;  // only retire one horse per call
NEXT_HORSE:
    continue;
  }

  // ... possibly spawn a special "dachshund" or "dino" later (lines 130204+) ...
}
