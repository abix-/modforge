// Address: 0x14009bbf0
// Ghidra name: FUN_14009bbf0
// ============ 0x14009bbf0 FUN_14009bbf0 (size=199) ============


void FUN_14009bbf0(longlong *param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = *param_1;

  if (lVar1 != 0) {

    lVar2 = param_1[1];

    for (; lVar1 != lVar2; lVar1 = lVar1 + 0x70) {

      FUN_140027900(lVar1 + 0x50);

      FUN_140027900(lVar1 + 0x30);

    }

    lVar1 = *param_1;

    lVar2 = lVar1;

    if ((0xfff < (ulonglong)(((param_1[2] - lVar1) / 0x70) * 0x70)) &&

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




