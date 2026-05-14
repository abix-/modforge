// Address: 0x140225bd0
// Ghidra name: FUN_140225bd0
// ============ 0x140225bd0 FUN_140225bd0 (size=96) ============


void FUN_140225bd0(undefined1 param_1)



{

  HKL pHVar1;

  longlong lVar2;

  

  pHVar1 = GetKeyboardLayout(0);

  lVar2 = FUN_1402254e0(pHVar1);

  if (lVar2 == 0) {

    lVar2 = FUN_140225180();

    if (lVar2 != 0) {

      FUN_140225440(pHVar1,lVar2);

    }

  }

  FUN_140183f10(lVar2,param_1);

  return;

}




