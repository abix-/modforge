// Address: 0x14009c330
// Ghidra name: FUN_14009c330
// ============ 0x14009c330 FUN_14009c330 (size=84) ============


void FUN_14009c330(undefined8 param_1,longlong param_2,longlong param_3)



{

  longlong lVar1;

  

  lVar1 = param_2;

  if ((0xfff < (ulonglong)(param_3 * 8)) &&

     (lVar1 = *(longlong *)(param_2 + -8), 0x1f < (param_2 - lVar1) - 8U)) {

                    /* WARNING: Subroutine does not return */

    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

  }

  FUN_1402c7088(lVar1);

  return;

}




