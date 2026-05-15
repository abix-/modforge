// Address: 0x14009bcc0
// Ghidra name: FUN_14009bcc0
// ============ 0x14009bcc0 FUN_14009bcc0 (size=168) ============


longlong * FUN_14009bcc0(longlong *param_1,longlong *param_2)



{

  longlong lVar1;

  longlong lVar2;

  

  if (param_1 != param_2) {

    lVar1 = *param_1;

    if (lVar1 != 0) {

      lVar2 = lVar1;

      if ((0xfff < (param_1[2] - lVar1 & 0xfffffffffffffff8U)) &&

         (lVar2 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar2) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088(lVar2);

      *param_1 = 0;

      param_1[1] = 0;

      param_1[2] = 0;

    }

    *param_1 = *param_2;

    param_1[1] = param_2[1];

    param_1[2] = param_2[2];

    *param_2 = 0;

    param_2[1] = 0;

    param_2[2] = 0;

  }

  return param_1;

}




