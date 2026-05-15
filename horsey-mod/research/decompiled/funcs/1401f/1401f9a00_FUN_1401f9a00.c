// Address: 0x1401f9a00
// Ghidra name: FUN_1401f9a00
// ============ 0x1401f9a00 FUN_1401f9a00 (size=70) ============


void FUN_1401f9a00(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  if (lVar1 != 0) {

    if (*(longlong *)(lVar1 + 0x660) != 0) {

      (*DAT_1403fd030)();

      FUN_1401f9010(param_1);

    }

    FUN_1401841e0(lVar1);

  }

  return;

}




