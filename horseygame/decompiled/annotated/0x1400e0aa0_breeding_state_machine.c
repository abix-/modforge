// =============================================================================
// FUN_1400e0aa0 @ 0x1400e0aa0 -- proposed name: breeding_state_machine
//
// PURPOSE:
//   Animation state machine that runs when the player initiates a mating
//   between two horses (in the barn). Drives the BarnDoorClose / BarnMating
//   sequence, marks both parents as "in breeding" (horse + 0x207 = 1), and at
//   the final frame applies a litter to produce children.
//
// CALLED BY: barn-mating action handler.
// SIZE: 6,908 bytes.
//
// STATE FIELDS (param_1 = the barn-mating sub-state struct):
//   param_1[0x88]    -- parent A horse pointer        (offset 0x440)
//   param_1[0x89]    -- parent B horse pointer        (offset 0x448)
//   param_1[0x8a]+   -- additional state ...
//   param_1[0xf]     -- the barn building object (used for position fVar34..fVar1)
//   param_1 + 0x254  -- frame counter
//   param_1 + 0x461  -- "doors closing" flag (set to 0x100 at frame 0x1e)
//   param_1 + 0x462  -- "active mating" flag (1 = will produce offspring; 0 = canceled)
//
// HORSE STRUCT FIELDS REFERENCED:
//   horse + 0x1c     -- type/species (compared to 2, 4, 6 for different paths)
//   horse + 0x207    -- "in breeding" byte flag (set to 1 on both parents)
//   horse + 0x254    -- the parent's mating-stat (probably LITTER_SIZE-derived)
//
// FRAMES (key transitions):
//   0x1e (30):  Play BarnDoorClose sound. Set horse->+0x207=1 on both parents.
//               If either parent is type 6 OR type 4, set param_1->+0x462=0
//               (cancel - probably means inter-species). If still active, play
//               BarnMating sound.
//   0x96 (150): Compute litter size = min(parent_A.+0x254, parent_B.+0x254).
//               1-in-20 chance to bump litter size by 1 (mutation bonus, gated
//               on sleeps > 1). Save final count to local_res20.
//   ...later... spawn offspring horses (loop over local_res20 iterations).
//
// HORSEY MOD IMPLICATION (litter size):
//   LITTER_SIZE is a HORSE STAT at horse->+0x254. It's set from the LITTER_SIZE
//   gene's allele at horse creation. The actual children-per-mating is:
//
//     children = min(parentA.LITTER_SIZE, parentB.LITTER_SIZE)
//                + (rand_20 == 0 && sleeps > 1 ? 1 : 0)
//
//   To get many children, both parents need a high LITTER_SIZE allele. The gene
//   values are g0=1, g1=2, g2=3, g3=5 in vanilla. Modding genes.xml to make all
//   four alleles = 10 would maximize children per breeding.
//
//   ALTERNATIVELY: patch this function to ignore the parents' stat and use a
//   fixed large number.
//
// BARN-MATING CANCEL CONDITION (interesting):
//   If either parent is of type 4 or 6, the +0x462 flag goes to 0 (canceled).
//   So same-species pairs only (or specific compatible types).
// =============================================================================

void breeding_state_machine(longlong *param_1)
{
  // ... per-frame iVar9 increment from elsewhere ...

  if (iVar9 == 0x1e /* 30 */) {
    play_sound("BarnDoorClose");
    *(uint16_t *)((char *)param_1 + 0x461) = 0x100;          // doors-closing animation tag

    // Mark both parents as in-breeding.
    *(uint8_t *)(param_1[0x88] + 0x207) = 1;
    *(uint8_t *)(param_1[0x89] + 0x207) = 1;

    // Type-2 parents call a special hook (probably pregnancy-state setter).
    if (*(int *)(param_1[0x88] + 0x1c) == 2) FUN_1400b8f90(param_1[0x88], 4);
    if (*(int *)(param_1[0x89] + 0x1c) == 2) FUN_1400b8f90(param_1[0x89], 4);

    // Type-4 or type-6 cancellation: clears the "active mating" flag.
    if ((*(int*)(param_1[0x88] + 0x1c) == 6) ||
        (*(int*)(param_1[0x89] + 0x1c) == 6) ||
        (*(int*)(param_1[0x88] + 0x1c) == 4) ||
        (*(int*)(param_1[0x89] + 0x1c) == 4)) {
      *((char *)param_1 + 0x462) = 0;
    }

    if (*((char *)param_1 + 0x462) != '\0') {
      play_sound("BarnMating");
      // ... advance state machine ...
    }
  } else if (iVar9 == 0x96 /* 150 */) {
    // === LITTER COUNT ===
    // iVar9 = min(parent_A.litter_stat, parent_B.litter_stat)
    iVar9 = *(int *)(*(param_1 + 0x88) + 0x254);
    if (*(int *)(param_1[0x89] + 0x254) < iVar9) {
      iVar9 = *(int *)(param_1[0x89] + 0x254);
    }
    // 1-in-20 chance to bump (gated on game_state.sleeps > 1)
    int rand_check = FUN_1400c6580(0x14);
    if (rand_check == 0 && *(int *)(DAT_1403fb0d8 + 0x318) > 1) {
      iVar9 = iVar9 + 1;
    }
    // Only use this count if breeding wasn't canceled.
    int litter_size = 0;
    if (*((char *)param_1 + 0x462) != '\0') {
      litter_size = iVar9;
    }
    // ... (continues with loop spawning litter_size offspring;
    //      each offspring inherits genome from both parents) ...
  }
}
