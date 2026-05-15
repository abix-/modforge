// Address: 0x140087f70
// Ghidra name: FUN_140087f70
// ============ 0x140087f70 FUN_140087f70 (size=130) ============


void FUN_140087f70(longlong *param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = *param_1;

  if (lVar1 != 0) {

    lVar2 = lVar1;

    if ((0xfff < (ulonglong)(((param_1[2] - lVar1) / 3) * 3)) &&

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




