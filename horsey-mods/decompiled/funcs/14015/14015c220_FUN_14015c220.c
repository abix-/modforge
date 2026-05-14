// Address: 0x14015c220
// Ghidra name: FUN_14015c220
// ============ 0x14015c220 FUN_14015c220 (size=34) ============


bool FUN_14015c220(longlong param_1)



{

  int iVar1;

  

  if (param_1 == 0) {

    return false;

  }

  iVar1 = *(int *)(param_1 + 0x14);

  if (iVar1 != 7) {

    if (1 < iVar1 - 8U) {

      return iVar1 == 10;

    }

  }

  return true;

}




