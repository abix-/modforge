// Address: 0x1400d8db0
// Ghidra name: FUN_1400d8db0
// ============ 0x1400d8db0 FUN_1400d8db0 (size=72) ============


void FUN_1400d8db0(longlong *param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = param_1[1];

  lVar2 = *param_1;

  if (lVar2 != lVar1) {

    do {

      FUN_140027900(lVar2);

      lVar2 = lVar2 + 0x20;

    } while (lVar2 != lVar1);

    param_1[1] = *param_1;

  }

  return;

}




