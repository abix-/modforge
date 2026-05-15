// =============================================================================
// FUN_1400dcab0 @ 0x1400dcab0 -- proposed name: compute_horse_price
//
// PURPOSE:
//   Computes a horse's sale/buy/sale-back price. The formula in the debug log
//   string is:
//
//     price = (rand + nice + record) * years + deco;     // base
//     price += 5 if horse->+0x205 == 0;                  // not-tired bonus
//     price = max(price, 1);                             // floor
//     // if horse->+0x204 == 0 (not on track? or "for sale"):
//     price *= 2;                                        // double for sale
//     if (player_horse->+0x1c == 2) {                    // some buyer type
//         iVar9 = FUN_1400c6580((price/4) + 1);          // RNG between 0 and (p/4+1)
//         price = max(price - iVar9, 1);                 // subtract; floor 1
//         if (FUN_1400c6580(40) == 0) {                  // 1-in-40 chance
//             price += FUN_1400c6580(10000);             // bonus 0..9999
//         }
//     }
//
//   "%s = (%d rand + %d nice + %d record) * %d years + %d deco   gdist=%.3f"
//
// CALLED BY: market / sale UI handlers.
// SIZE: 4,986 bytes.
//
// VARIABLE MEANINGS (FROM DEBUG FORMAT):
//   rand     = local_80 & 0xffffffff   -- randomized component
//   nice     = local_res20             -- "niceness" multiplier
//   record   = local_b0                -- race-record component
//   years    = local_b4                -- horse age in years (= horse->+0x1fc? or different)
//   deco     = local_res8              -- decoration / cosmetic value
//   gdist    = fVar23                  -- "genetic distance" (similarity to common ancestor?)
//
// HORSE STRUCT FIELDS REFERENCED:
//   horse + 0x1f8   -- horse name ID  (passed to FUN_1400c78c0)
//   horse + 0x204   -- "on track / unavailable" flag (* 2 multiplier when 0)
//   horse + 0x205   -- tiredness flag (+5 to price when 0 = not tired)
//
// PLAYER/CONTEXT STRUCT FIELDS:
//   param_1 + 0x148  -- active horse pointer (the BUYER's horse, in trade?)
//   param_1 + 0x450  -- output: stores the final price (int)
//   param_1 + 600    -- current mode (4 == some specific sale path)
//
// DEBUG GATE:
//   DAT_1403d9526 must be set to print the formula debug line.
//
// HORSEY MOD IMPLICATION:
//   To always sell horses for max price, override the FUN_1400c6580 random
//   subtractor to return 0 (or alter the *piVar16 store at line 128805 to a
//   fixed large value). The +5 "not tired" bonus already incentivizes the No
//   Tire cheat for selling horses.
// =============================================================================

void compute_horse_price(longlong param_1, ...)
{
  // ... 0x15 (21) iterations of some pre-loop accumulating local_b0, local_80, etc.
  // -- this is probably computing the "record" component from race history ...

  // ===== PRICE FORMULA =====
  piVar16 = (int *)(param_1 + 0x450);
  iVar22 = local_res8 + 5 + (local_res20 + local_b0 + (int)local_80) * local_b4;
  // Translation:
  //   iVar22 = deco + 5 + (nice + record + rand) * years;
  // Note: the +5 here is part of the base, NOT the not-tired bonus. The
  // not-tired bonus is below.
  *piVar16 = iVar22;     // save initial price

  // ===== NOT-TIRED BONUS =====
  if (*(char *)(lVar1 + 0x205) == '\0') {
    iVar22 = iVar22 + 5;
    *piVar16 = iVar22;
  }

  // ===== FLOOR PRICE >= 2 =====
  iVar9 = FUN_1400c6e80(iVar22, 2);
  iVar22 = 1;
  if (1 < iVar9) iVar22 = iVar9;
  *piVar16 = iVar22;

  // ===== DEBUG LOG =====
  if (DAT_1403d9526 != '\0') {
    uVar14 = FUN_1400c78c0(horse->name_id);   // resolve name
    log("%s = (%d rand + %d nice + %d record) * %d years + %d deco   gdist=%.3f",
        horse_name, rand, nice, record, years, deco, gdist);
  }

  // ===== ON-TRACK MULTIPLIER =====
  if (*(char *)(lVar1 + 0x204) == '\0') {
    // Horse is NOT on track => for-sale price doubled.
    iVar22 = *piVar16 * 2;
    *piVar16 = iVar22;

    // Buyer-specific haggle.
    if (*(int *)(*(longlong *)(param_1 + 0x148) + 0x1c) == 2) {  // buyer type 2
      iVar9 = FUN_1400c6580(((int)((iVar22 >> 0x1f & 3U) + iVar22) >> 2) + 1);
      // Subtract a random 0..(price/4+1) from price; floor at 1.
      iVar10 = 1;
      if (1 < iVar22 - iVar9) iVar10 = iVar22 - iVar9;
      *piVar16 = iVar10;
      // 1-in-40 chance: bonus 0..9999.
      iVar22 = FUN_1400c6580(0x28);
      if (iVar22 == 0) {
        *piVar20 = FUN_1400c6580(10000) + *piVar20;
      }
    }
    // ... mode 4 branch handles championship buying differently ...
  }
}
