// Address: 0x1400c5580
// Ghidra name: FUN_1400c5580
// ============ 0x1400c5580 FUN_1400c5580 (size=155) ============


longlong * FUN_1400c5580(longlong *param_1,longlong *param_2)



{

  longlong lVar1;

  longlong lVar2;

  

  if (param_1 != param_2) {

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

    param_1[3] = 0xf;

    param_1[2] = 0;

    *(undefined1 *)param_1 = 0;

    lVar1 = param_2[1];

    *param_1 = *param_2;

    param_1[1] = lVar1;

    lVar1 = param_2[3];

    param_1[2] = param_2[2];

    param_1[3] = lVar1;

    param_2[2] = 0;

    param_2[3] = 0xf;

    *(undefined1 *)param_2 = 0;

  }

  return param_1;

}




