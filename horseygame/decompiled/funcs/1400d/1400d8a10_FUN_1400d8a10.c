// Address: 0x1400d8a10
// Ghidra name: FUN_1400d8a10
// ============ 0x1400d8a10 FUN_1400d8a10 (size=151) ============


void FUN_1400d8a10(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  if (*(longlong *)(param_1 + 8) == 0) {

    return;

  }

  lVar1 = *(longlong *)(param_1 + 0x20);

  for (lVar2 = *(longlong *)(param_1 + 0x18); lVar2 != lVar1; lVar2 = lVar2 + 0x20) {

    FUN_140027900(lVar2);

  }

  lVar2 = *(longlong *)(param_1 + 8);

  lVar1 = lVar2;

  if ((0xfff < (ulonglong)(*(longlong *)(param_1 + 0x10) * 0x20)) &&

     (lVar1 = *(longlong *)(lVar2 + -8), 0x1f < (lVar2 - lVar1) - 8U)) {

                    /* WARNING: Subroutine does not return */

    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

  }

  FUN_1402c7088(lVar1);

  return;

}




