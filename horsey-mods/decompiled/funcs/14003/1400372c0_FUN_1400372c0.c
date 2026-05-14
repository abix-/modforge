// Address: 0x1400372c0
// Ghidra name: FUN_1400372c0
// ============ 0x1400372c0 FUN_1400372c0 (size=95) ============


void FUN_1400372c0(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = *(longlong *)(param_1 + 8);

  if (lVar1 == 0) {

    return;

  }

  lVar2 = lVar1;

  if ((0xfff < (ulonglong)(*(longlong *)(param_1 + 0x10) * 8)) &&

     (lVar2 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar2) - 8U)) {

                    /* WARNING: Subroutine does not return */

    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

  }

  FUN_1402c7088(lVar2);

  return;

}




