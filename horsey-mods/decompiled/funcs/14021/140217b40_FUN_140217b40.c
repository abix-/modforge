// Address: 0x140217b40
// Ghidra name: FUN_140217b40
// ============ 0x140217b40 FUN_140217b40 (size=66) ============


void FUN_140217b40(longlong *param_1)



{

  longlong lVar1;

  

  lVar1 = *param_1;

  *param_1 = 0;

  param_1[1] = 0;

  param_1[3] = 0;

  while (lVar1 != 0) {

    lVar1 = *(longlong *)(lVar1 + 0x20);

    FUN_140217700(param_1);

  }

  return;

}




