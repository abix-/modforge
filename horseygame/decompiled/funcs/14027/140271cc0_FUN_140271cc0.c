// Address: 0x140271cc0
// Ghidra name: FUN_140271cc0
// ============ 0x140271cc0 FUN_140271cc0 (size=71) ============


void FUN_140271cc0(longlong param_1,int param_2)



{

  if (param_2 == 1) {

    FUN_140271bc0(param_1);

  }

  else if (param_2 == 2) {

    FUN_140271bf0(param_1);

    *(undefined4 *)(param_1 + 0x1c) = 2;

    return;

  }

  *(int *)(param_1 + 0x1c) = param_2;

  return;

}




