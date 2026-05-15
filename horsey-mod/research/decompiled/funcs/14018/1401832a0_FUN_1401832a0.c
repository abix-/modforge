// Address: 0x1401832a0
// Ghidra name: FUN_1401832a0
// ============ 0x1401832a0 FUN_1401832a0 (size=42) ============


int FUN_1401832a0(int param_1)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  piVar2 = DAT_1403fcb10;

  if (0 < DAT_1403fcb08) {

    do {

      if (param_1 == *piVar2) {

        return iVar1;

      }

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 1;

    } while (iVar1 < DAT_1403fcb08);

  }

  return -1;

}




