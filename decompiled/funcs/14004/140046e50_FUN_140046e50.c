// Address: 0x140046e50
// Ghidra name: FUN_140046e50
// ============ 0x140046e50 FUN_140046e50 (size=506) ============


undefined8 * FUN_140046e50(longlong *param_1,longlong param_2,undefined8 *param_3)



{

  undefined8 *puVar1;

  longlong lVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  longlong lVar5;

  longlong lVar6;

  ulonglong uVar7;

  

  lVar5 = *param_1;

  lVar6 = param_1[1] - lVar5 >> 6;

  if (lVar6 == 0x3ffffffffffffff) {

                    /* WARNING: Subroutine does not return */

    FUN_14002f0d0();

  }

  uVar7 = lVar6 + 1;

  uVar3 = param_1[2] - lVar5 >> 6;

  if (0x3ffffffffffffff - (uVar3 >> 1) < uVar3) {

    uVar4 = 0x3ffffffffffffff;

  }

  else {

    uVar3 = (uVar3 >> 1) + uVar3;

    uVar4 = uVar7;

    if (uVar7 <= uVar3) {

      uVar4 = uVar3;

    }

    if (0x3ffffffffffffff < uVar4) {

                    /* WARNING: Subroutine does not return */

      FUN_140024090();

    }

  }

  lVar2 = FUN_1400285e0(uVar4 * 0x40);

  puVar1 = (undefined8 *)((param_2 - lVar5 & 0xffffffffffffffc0U) + lVar2);

  *puVar1 = *param_3;

  FUN_1400279c0(puVar1 + 1,param_3 + 1);

  *(undefined4 *)(puVar1 + 5) = *(undefined4 *)(param_3 + 5);

  *(undefined4 *)((longlong)puVar1 + 0x2c) = *(undefined4 *)((longlong)param_3 + 0x2c);

  *(undefined4 *)(puVar1 + 6) = *(undefined4 *)(param_3 + 6);

  *(undefined4 *)((longlong)puVar1 + 0x34) = *(undefined4 *)((longlong)param_3 + 0x34);

  *(undefined1 *)(puVar1 + 7) = *(undefined1 *)(param_3 + 7);

  lVar6 = param_1[1];

  lVar5 = *param_1;

  if (param_2 != lVar6) {

    FUN_1400471e0(lVar5,param_2,lVar2,param_1);

    lVar6 = param_1[1];

    lVar5 = param_2;

  }

  FUN_1400471e0(lVar5,lVar6);

  lVar5 = *param_1;

  if (lVar5 != 0) {

    lVar6 = param_1[1];

    for (; lVar5 != lVar6; lVar5 = lVar5 + 0x40) {

      FUN_140027900(lVar5 + 8);

    }

    lVar5 = *param_1;

    lVar6 = lVar5;

    if ((0xfff < (param_1[2] - lVar5 & 0xffffffffffffffc0U)) &&

       (lVar6 = *(longlong *)(lVar5 + -8), 0x1f < (lVar5 - lVar6) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar6);

  }

  *param_1 = lVar2;

  param_1[1] = uVar7 * 0x40 + lVar2;

  param_1[2] = uVar4 * 0x40 + lVar2;

  return puVar1;

}




