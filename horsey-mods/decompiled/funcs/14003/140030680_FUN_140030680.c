// Address: 0x140030680
// Ghidra name: FUN_140030680
// ============ 0x140030680 FUN_140030680 (size=366) ============


longlong FUN_140030680(longlong *param_1,longlong param_2,undefined8 *param_3)



{

  ulonglong uVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  longlong lVar7;

  

  lVar2 = *param_1;

  lVar7 = param_2 - lVar2 >> 3;

  lVar3 = param_1[1] - lVar2 >> 3;

  if (lVar3 == 0x1fffffffffffffff) {

                    /* WARNING: Subroutine does not return */

    FUN_14002f0d0();

  }

  uVar5 = param_1[2] - lVar2 >> 3;

  uVar1 = lVar3 + 1;

  if (0x1fffffffffffffff - (uVar5 >> 1) < uVar5) {

    uVar6 = 0x1fffffffffffffff;

  }

  else {

    uVar5 = (uVar5 >> 1) + uVar5;

    uVar6 = uVar1;

    if (uVar1 <= uVar5) {

      uVar6 = uVar5;

    }

    if (0x1fffffffffffffff < uVar6) {

                    /* WARNING: Subroutine does not return */

      FUN_140024090();

    }

  }

  lVar4 = FUN_1400285e0(uVar6 * 8);

  *(undefined8 *)(lVar4 + lVar7 * 8) = *param_3;

  lVar3 = *param_1;

  lVar2 = lVar4 + lVar7 * 8;

  lVar7 = lVar4;

  if (param_2 != param_1[1]) {

    FUN_1402f8e20(lVar4,lVar3,param_2 - lVar3);

    lVar7 = lVar2 + 8;

    lVar3 = param_2;

  }

  FUN_1402f8e20(lVar7,lVar3);

  lVar3 = *param_1;

  if (lVar3 != 0) {

    lVar7 = lVar3;

    if ((0xfff < (param_1[2] - lVar3 & 0xfffffffffffffff8U)) &&

       (lVar7 = *(longlong *)(lVar3 + -8), 0x1f < (lVar3 - lVar7) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar7);

  }

  *param_1 = lVar4;

  param_1[1] = lVar4 + uVar1 * 8;

  param_1[2] = uVar6 * 8 + lVar4;

  return lVar2;

}




