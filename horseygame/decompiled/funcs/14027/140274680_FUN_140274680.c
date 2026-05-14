// Address: 0x140274680
// Ghidra name: FUN_140274680
// ============ 0x140274680 FUN_140274680 (size=69) ============


void FUN_140274680(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = FUN_1401841a0(1,0x60);

  if (lVar1 == 0) {

    return;

  }

  *(longlong *)(param_1 + 0x70) = lVar1;

  FUN_1402083c0(param_1,"NVIDIA SHIELD Controller");

  FUN_140208110(param_1,0);

  return;

}




