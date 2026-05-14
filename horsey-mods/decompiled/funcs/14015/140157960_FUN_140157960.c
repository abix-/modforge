// Address: 0x140157960
// Ghidra name: FUN_140157960
// ============ 0x140157960 FUN_140157960 (size=35) ============


void FUN_140157960(void)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  piVar2 = DAT_1403fc078;

  if (0 < DAT_1403fc06c) {

    do {

      if (*piVar2 == 0) {

        return;

      }

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 1;

    } while (iVar1 < DAT_1403fc06c);

  }

  return;

}




