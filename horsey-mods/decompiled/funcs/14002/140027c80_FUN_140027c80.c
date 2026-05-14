// Address: 0x140027c80
// Ghidra name: FUN_140027c80
// ============ 0x140027c80 FUN_140027c80 (size=415) ============


ulonglong *

FUN_140027c80(ulonglong *param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4,

             longlong param_5)



{

  ulonglong uVar1;

  ulonglong uVar2;

  longlong lVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  

  uVar6 = param_1[2];

  uVar5 = 0x7fffffffffffffff;

  if (0x7fffffffffffffff - uVar6 < param_2) {

                    /* WARNING: Subroutine does not return */

    FUN_140024130();

  }

  uVar4 = uVar6 + param_2 | 0xf;

  uVar2 = param_1[3];

  if ((uVar4 < 0x8000000000000000) && (uVar2 <= 0x7fffffffffffffff - (uVar2 >> 1))) {

    uVar1 = uVar2 + (uVar2 >> 1);

    uVar5 = uVar4;

    if (uVar4 < uVar1) {

      uVar5 = uVar1;

    }

    if (uVar5 == 0xffffffffffffffff) {

      uVar4 = 0;

    }

    else {

      if (0xfff < uVar5 + 1) {

        if (uVar5 + 0x28 <= uVar5 + 1) {

                    /* WARNING: Subroutine does not return */

          FUN_140024090();

        }

        goto LAB_140027d28;

      }

      uVar4 = FUN_1402c704c();

    }

  }

  else {

LAB_140027d28:

    lVar3 = FUN_1402c704c();

    if (lVar3 == 0) goto LAB_140027dfd;

    uVar4 = lVar3 + 0x27U & 0xffffffffffffffe0;

    *(longlong *)(uVar4 - 8) = lVar3;

  }

  param_1[2] = uVar6 + param_2;

  lVar3 = uVar4 + uVar6;

  param_1[3] = uVar5;

  if (uVar2 < 0x10) {

    FUN_1402f8e20(uVar4,param_1,uVar6);

    FUN_1402f8e20(lVar3,param_4,param_5);

    *(undefined1 *)(lVar3 + param_5) = 0;

  }

  else {

    uVar5 = *param_1;

    FUN_1402f8e20(uVar4,uVar5,uVar6);

    FUN_1402f8e20(lVar3,param_4);

    *(undefined1 *)(lVar3 + param_5) = 0;

    uVar6 = uVar5;

    if ((0xfff < uVar2 + 1) && (uVar6 = *(ulonglong *)(uVar5 - 8), 0x1f < (uVar5 - uVar6) - 8)) {

LAB_140027dfd:

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(uVar6);

  }

  *param_1 = uVar4;

  return param_1;

}




