// Address: 0x14009c0d0
// Ghidra name: FUN_14009c0d0
// ============ 0x14009c0d0 FUN_14009c0d0 (size=583) ============


void FUN_14009c0d0(longlong *param_1,ulonglong param_2,undefined8 *param_3)



{

  longlong lVar1;

  ulonglong uVar2;

  undefined8 *puVar3;

  undefined8 *puVar4;

  longlong lVar5;

  undefined8 *puVar6;

  

  puVar4 = (undefined8 *)*param_1;

  uVar2 = param_1[2] - (longlong)puVar4 >> 5;

  if (uVar2 < param_2) {

    if (0x7ffffffffffffff < param_2) {

                    /* WARNING: Subroutine does not return */

      FUN_14002f0d0();

    }

    if (0x7ffffffffffffff - (uVar2 >> 1) < uVar2) {

      uVar2 = 0x7ffffffffffffff;

    }

    else {

      uVar2 = uVar2 + (uVar2 >> 1);

      if (uVar2 < param_2) {

        uVar2 = param_2;

      }

    }

    if (puVar4 != (undefined8 *)0x0) {

      puVar6 = (undefined8 *)param_1[1];

      for (; puVar4 != puVar6; puVar4 = puVar4 + 4) {

        FUN_140027900(puVar4);

      }

      lVar1 = *param_1;

      lVar5 = lVar1;

      if ((0xfff < (param_1[2] - lVar1 & 0xffffffffffffffe0U)) &&

         (lVar5 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar5) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088(lVar5);

      *param_1 = 0;

      param_1[1] = 0;

      param_1[2] = 0;

    }

    if (0x7ffffffffffffff < uVar2) {

                    /* WARNING: Subroutine does not return */

      FUN_140024090();

    }

    lVar1 = FUN_1400285e0(uVar2 * 0x20);

    *param_1 = lVar1;

    param_1[1] = lVar1;

    param_1[2] = uVar2 * 0x20 + lVar1;

    for (; param_2 != 0; param_2 = param_2 - 1) {

      FUN_1400279c0(lVar1,param_3);

      lVar1 = lVar1 + 0x20;

    }

    param_1[1] = lVar1;

  }

  else {

    puVar6 = (undefined8 *)param_1[1];

    uVar2 = (longlong)puVar6 - (longlong)puVar4 >> 5;

    if (uVar2 < param_2) {

      for (; puVar4 != puVar6; puVar4 = puVar4 + 4) {

        if (puVar4 != param_3) {

          puVar3 = param_3;

          if (0xf < (ulonglong)param_3[3]) {

            puVar3 = (undefined8 *)*param_3;

          }

          FUN_140027f50(puVar4,puVar3,param_3[2]);

        }

      }

      lVar1 = param_1[1];

      for (lVar5 = param_2 - uVar2; lVar5 != 0; lVar5 = lVar5 + -1) {

        FUN_1400279c0(lVar1,param_3);

        lVar1 = lVar1 + 0x20;

      }

      param_1[1] = lVar1;

    }

    else {

      puVar6 = puVar4 + param_2 * 4;

      for (; puVar4 != puVar6; puVar4 = puVar4 + 4) {

        if (puVar4 != param_3) {

          puVar3 = param_3;

          if (0xf < (ulonglong)param_3[3]) {

            puVar3 = (undefined8 *)*param_3;

          }

          FUN_140027f50(puVar4,puVar3,param_3[2]);

        }

      }

      puVar4 = (undefined8 *)param_1[1];

      for (puVar3 = puVar6; puVar3 != puVar4; puVar3 = puVar3 + 4) {

        FUN_140027900(puVar3);

      }

      param_1[1] = (longlong)puVar6;

    }

  }

  return;

}




