// Address: 0x1401f1350
// Ghidra name: FUN_1401f1350
// ============ 0x1401f1350 FUN_1401f1350 (size=56) ============


void FUN_1401f1350(longlong param_1,longlong param_2)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_2 + 0x10);

  if (lVar1 != 0) {

    (**(code **)(*(longlong *)(param_1 + 0x2e0) + 0x78))(1,lVar1);

    FUN_1401841e0(lVar1);

    return;

  }

  return;

}




