// Address: 0x140278570
// Ghidra name: FUN_140278570
// ============ 0x140278570 FUN_140278570 (size=42) ============


void FUN_140278570(longlong param_1)



{

  undefined8 uVar1;

  

  if (*(int *)(param_1 + 0x1c) == 0x81) {

    FUN_1402785a0(param_1,5);

    return;

  }

  uVar1 = 4;

  if (*(int *)(param_1 + 0x1c) == 0x82) {

    uVar1 = 7;

  }

  FUN_1402785a0(param_1,uVar1);

  return;

}




