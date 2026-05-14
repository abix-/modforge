// Address: 0x140226860
// Ghidra name: FUN_140226860
// ============ 0x140226860 FUN_140226860 (size=108) ============


undefined8 FUN_140226860(longlong param_1)



{

  int iVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 0x54);

  iVar1 = FUN_140226d70();

  if (iVar1 == 1) {

    if (iVar2 == 0) {

      return 1;

    }

    if (iVar2 != 1) {

      if (iVar2 == 2) {

        return 2;

      }

      if (iVar2 == 3) {

        return 4;

      }

      return 0;

    }

  }

  else if (iVar2 != 0) {

    if (iVar2 == 1) {

      return 2;

    }

    if (iVar2 != 2) {

      if (iVar2 == 3) {

        return 1;

      }

      return 0;

    }

    return 4;

  }

  return 3;

}




