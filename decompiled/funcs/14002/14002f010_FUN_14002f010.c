// Address: 0x14002f010
// Ghidra name: FUN_14002f010
// ============ 0x14002f010 FUN_14002f010 (size=107) ============


void FUN_14002f010(longlong *param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = *param_1;

  if (lVar1 != 0) {

    lVar2 = lVar1;

    if ((0xfff < (param_1[2] - lVar1 & 0xffffffffffffffe0U)) &&

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




