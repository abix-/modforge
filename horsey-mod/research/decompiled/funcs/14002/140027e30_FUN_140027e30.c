// Address: 0x140027e30
// Ghidra name: FUN_140027e30
// ============ 0x140027e30 FUN_140027e30 (size=284) ============


void FUN_140027e30(ulonglong *param_1,undefined8 param_2,ulonglong param_3)



{

  ulonglong uVar1;

  longlong lVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  

  uVar4 = 0x7fffffffffffffff;

  if (0x7fffffffffffffff < param_3) {

                    /* WARNING: Subroutine does not return */

    FUN_140024130();

  }

  if (param_3 < 0x10) {

    param_1[2] = param_3;

    param_1[3] = 0xf;

    FUN_1402f8e20();

    *(undefined1 *)(param_3 + (longlong)param_1) = 0;

    return;

  }

  uVar1 = param_3 | 0xf;

  if (uVar1 < 0x8000000000000000) {

    if (uVar1 < 0x16) {

      uVar1 = 0x16;

    }

    if (uVar1 == 0xffffffffffffffff) {

      uVar3 = 0;

      goto LAB_140027ef4;

    }

    if (uVar1 + 1 < 0x1000) {

      uVar3 = FUN_1402c704c();

      goto LAB_140027ef4;

    }

    uVar4 = uVar1;

    if (uVar1 + 0x28 <= uVar1 + 1) {

                    /* WARNING: Subroutine does not return */

      FUN_140024090();

    }

  }

  lVar2 = FUN_1402c704c();

  if (lVar2 == 0) {

                    /* WARNING: Subroutine does not return */

    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

  }

  uVar3 = lVar2 + 0x27U & 0xffffffffffffffe0;

  *(longlong *)(uVar3 - 8) = lVar2;

  uVar1 = uVar4;

LAB_140027ef4:

  *param_1 = uVar3;

  param_1[2] = param_3;

  param_1[3] = uVar1;

  FUN_1402f8e20(uVar3,param_2,param_3);

  *(undefined1 *)(uVar3 + param_3) = 0;

  return;

}




