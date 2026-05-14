// Address: 0x140083ff0
// Ghidra name: FUN_140083ff0
// ============ 0x140083ff0 FUN_140083ff0 (size=103) ============


void FUN_140083ff0(longlong param_1,undefined4 param_2)



{

  char cVar1;

  

  if (*(int *)(param_1 + 8) == 2) {

    cVar1 = FUN_140009e00();

    if (cVar1 == '\0') {

      FUN_140009e10(param_1,1);

    }

    FUN_140009e60(param_1,param_2);

    return;

  }

  cVar1 = FUN_14000b290();

  if (cVar1 == '\0') {

    FUN_14000b2a0(param_1,1);

  }

  FUN_14000b2f0(param_1,param_2);

  return;

}




