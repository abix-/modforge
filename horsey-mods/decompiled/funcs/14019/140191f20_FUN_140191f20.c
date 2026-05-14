// Address: 0x140191f20
// Ghidra name: FUN_140191f20
// ============ 0x140191f20 FUN_140191f20 (size=35) ============


longlong FUN_140191f20(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x88);

  if (lVar1 == 0) {

    FUN_140196b60(param_1,L"NULL device info");

    lVar1 = 0;

  }

  return lVar1;

}




