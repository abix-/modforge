// Address: 0x140274220
// Ghidra name: FUN_140274220
// ============ 0x140274220 FUN_140274220 (size=71) ============


void FUN_140274220(longlong param_1,int param_2)



{

  if (param_2 == 1) {

    FUN_140274110(param_1);

  }

  else if (param_2 == 2) {

    FUN_140274150(param_1);

    *(undefined4 *)(param_1 + 0x1c) = 2;

    return;

  }

  *(int *)(param_1 + 0x1c) = param_2;

  return;

}




