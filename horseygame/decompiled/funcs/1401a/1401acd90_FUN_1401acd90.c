// Address: 0x1401acd90
// Ghidra name: FUN_1401acd90
// ============ 0x1401acd90 FUN_1401acd90 (size=51) ============


undefined * FUN_1401acd90(int param_1)



{

  ulonglong uVar1;

  int *piVar2;

  

  uVar1 = 0;

  piVar2 = &DAT_14033ccd8;

  do {

    if (*piVar2 == param_1) {

      return (&PTR_DAT_14033ccd0)[uVar1 * 2];

    }

    uVar1 = uVar1 + 1;

    piVar2 = piVar2 + 4;

  } while (uVar1 < 0xe);

  return (undefined *)0x0;

}




