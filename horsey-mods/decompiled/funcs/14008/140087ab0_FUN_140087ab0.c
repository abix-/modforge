// Address: 0x140087ab0
// Ghidra name: FUN_140087ab0
// ============ 0x140087ab0 FUN_140087ab0 (size=440) ============


undefined2 * FUN_140087ab0(longlong *param_1,longlong param_2,undefined2 *param_3)



{

  ulonglong uVar1;

  undefined2 *puVar2;

  ulonglong uVar3;

  longlong lVar4;

  longlong lVar5;

  ulonglong uVar6;

  longlong lVar7;

  longlong lVar8;

  

  lVar4 = *param_1;

  lVar5 = (param_1[1] - lVar4) / 3;

  if (lVar5 == 0x5555555555555555) {

                    /* WARNING: Subroutine does not return */

    FUN_14002f0d0();

  }

  uVar1 = lVar5 + 1;

  uVar3 = (param_1[2] - lVar4) / 3;

  if (0x5555555555555555 - (uVar3 >> 1) < uVar3) {

    uVar6 = 0x5555555555555555;

  }

  else {

    uVar3 = (uVar3 >> 1) + uVar3;

    uVar6 = uVar1;

    if (uVar1 <= uVar3) {

      uVar6 = uVar3;

    }

    if (0x5555555555555555 < uVar6) {

                    /* WARNING: Subroutine does not return */

      FUN_140024090();

    }

  }

  lVar5 = FUN_1400285e0(uVar6 * 3);

  puVar2 = (undefined2 *)(lVar5 + ((param_2 - lVar4) / 3) * 3);

  *puVar2 = *param_3;

  *(undefined1 *)(puVar2 + 1) = *(undefined1 *)(param_3 + 1);

  lVar4 = *param_1;

  if (param_2 == param_1[1]) {

    lVar8 = param_1[1] - lVar4;

    lVar7 = lVar5;

    param_2 = lVar4;

  }

  else {

    FUN_1402f8e20(lVar5,lVar4,param_2 - lVar4);

    lVar7 = (longlong)puVar2 + 3;

    lVar8 = param_1[1] - param_2;

  }

  FUN_1402f8e20(lVar7,param_2,lVar8);

  lVar4 = *param_1;

  if (lVar4 != 0) {

    lVar7 = lVar4;

    if ((0xfff < (ulonglong)(((param_1[2] - lVar4) / 3) * 3)) &&

       (lVar7 = *(longlong *)(lVar4 + -8), 0x1f < (lVar4 - lVar7) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar7);

  }

  *param_1 = lVar5;

  param_1[1] = lVar5 + uVar1 * 3;

  param_1[2] = uVar6 * 3 + lVar5;

  return puVar2;

}




