// Address: 0x1401ec8b0
// Ghidra name: FUN_1401ec8b0
// ============ 0x1401ec8b0 FUN_1401ec8b0 (size=59) ============


void FUN_1401ec8b0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_2 + 0x10);

  if (lVar1 != 0) {

    (**(code **)(*(longlong *)(param_1 + 0x2e0) + 0x88))(1,lVar1);

    FUN_1401841e0(lVar1);

    return;

  }

  return;

}




