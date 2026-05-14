// Address: 0x140112210
// Ghidra name: FUN_140112210
// ============ 0x140112210 FUN_140112210 (size=194) ============


void FUN_140112210(longlong *param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = *param_1;

  if (lVar1 != 0) {

    lVar2 = param_1[1];

    for (; lVar1 != lVar2; lVar1 = lVar1 + 0x30) {

      FUN_140087ec0(lVar1 + 0x18);

    }

    lVar1 = *param_1;

    lVar2 = lVar1;

    if ((0xfff < (ulonglong)(((param_1[2] - lVar1) / 0x30) * 0x30)) &&

       (lVar2 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar2) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar2);

    *param_1 = 0;

    param_1[1] = 0;

    param_1[2] = 0;

  }

  return;

}




