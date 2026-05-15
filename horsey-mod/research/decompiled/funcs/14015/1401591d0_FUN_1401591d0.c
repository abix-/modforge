// Address: 0x1401591d0
// Ghidra name: FUN_1401591d0
// ============ 0x1401591d0 FUN_1401591d0 (size=48) ============


int FUN_1401591d0(int param_1)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  piVar2 = DAT_1403fc078;

  if (0 < DAT_1403fc06c) {

    do {

      if (param_1 == *piVar2) break;

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 1;

    } while (iVar1 < DAT_1403fc06c);

  }

  if (iVar1 == DAT_1403fc06c) {

    iVar1 = -1;

  }

  return iVar1;

}




