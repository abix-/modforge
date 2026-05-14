// Address: 0x140083f90
// Ghidra name: FUN_140083f90
// ============ 0x140083f90 FUN_140083f90 (size=87) ============


void FUN_140083f90(longlong param_1,char param_2)



{

  char cVar1;

  

  if (*(int *)(param_1 + 8) == 2) {

    cVar1 = FUN_140009e00();

    if (cVar1 != param_2) {

      FUN_140009e10(param_1,param_2);

      return;

    }

  }

  else {

    cVar1 = FUN_14000b290();

    if (cVar1 != param_2) {

      FUN_14000b2a0(param_1,param_2);

    }

  }

  return;

}




