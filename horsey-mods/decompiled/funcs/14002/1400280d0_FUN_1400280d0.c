// Address: 0x1400280d0
// Ghidra name: FUN_1400280d0
// ============ 0x1400280d0 FUN_1400280d0 (size=379) ============


ulonglong *

FUN_1400280d0(ulonglong *param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4)



{

  ulonglong uVar1;

  ulonglong uVar2;

  longlong lVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  

  uVar6 = param_1[2];

  uVar5 = 0x7fffffffffffffff;

  if (uVar6 == 0x7fffffffffffffff) {

                    /* WARNING: Subroutine does not return */

    FUN_140024130();

  }

  uVar2 = param_1[3];

  uVar4 = uVar6 + 1 | 0xf;

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

        goto LAB_140028177;

      }

      uVar4 = FUN_1402c704c();

    }

  }

  else {

LAB_140028177:

    lVar3 = FUN_1402c704c();

    if (lVar3 == 0) goto LAB_140028229;

    uVar4 = lVar3 + 0x27U & 0xffffffffffffffe0;

    *(longlong *)(uVar4 - 8) = lVar3;

  }

  param_1[2] = uVar6 + 1;

  param_1[3] = uVar5;

  if (uVar2 < 0x10) {

    FUN_1402f8e20(uVar4,param_1);

    *(undefined1 *)(uVar4 + uVar6) = param_4;

    *(undefined1 *)(uVar4 + 1 + uVar6) = 0;

  }

  else {

    uVar5 = *param_1;

    FUN_1402f8e20(uVar4,uVar5);

    *(undefined1 *)(uVar4 + uVar6) = param_4;

    *(undefined1 *)(uVar4 + 1 + uVar6) = 0;

    uVar6 = uVar5;

    if ((0xfff < uVar2 + 1) && (uVar6 = *(ulonglong *)(uVar5 - 8), 0x1f < (uVar5 - uVar6) - 8)) {

LAB_140028229:

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(uVar6);

  }

  *param_1 = uVar4;

  return param_1;

}




