// Address: 0x14014dd50
// Ghidra name: FUN_14014dd50
// ============ 0x14014dd50 FUN_14014dd50 (size=91) ============


void FUN_14014dd50(longlong param_1)



{

  char cVar1;

  

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,3);

      if (cVar1 == '\0') goto LAB_14014dd8d;

    }

    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;

    if (*(int *)(param_1 + 0xc) < 1) {

      FUN_14014dc20(param_1,0);

      return;

    }

    return;

  }

LAB_14014dd8d:

  FUN_14012e850("Parameter \'%s\' is invalid","texture");

  return;

}




