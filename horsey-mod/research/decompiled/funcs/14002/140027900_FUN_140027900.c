// Address: 0x140027900
// Ghidra name: FUN_140027900
// ============ 0x140027900 FUN_140027900 (size=112) ============


void FUN_140027900(longlong *param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  if (0xf < (ulonglong)param_1[3]) {

    lVar1 = *param_1;

    lVar2 = lVar1;

    if ((0xfff < param_1[3] + 1U) &&

       (lVar2 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar2) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar2);

  }

  param_1[2] = 0;

  param_1[3] = 0xf;

  *(undefined1 *)param_1 = 0;

  return;

}




