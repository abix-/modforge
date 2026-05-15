// Address: 0x1401a8110
// Ghidra name: FUN_1401a8110
// ============ 0x1401a8110 FUN_1401a8110 (size=84) ============


int * FUN_1401a8110(int param_1)



{

  int iVar1;

  int *piVar2;

  

  if ((param_1 != 0) && (iVar1 = 0, piVar2 = DAT_1403fcd50, 0 < DAT_1403fcd44)) {

    do {

      if (*piVar2 == param_1) {

        return DAT_1403fcd50 + (longlong)iVar1 * 0x18;

      }

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 0x18;

    } while (iVar1 < DAT_1403fcd44);

  }

  FUN_14012e850("Invalid pen instance ID");

  return (int *)0x0;

}




