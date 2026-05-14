// Address: 0x140074c20
// Ghidra name: FUN_140074c20
// ============ 0x140074c20 FUN_140074c20 (size=370) ============


void FUN_140074c20(longlong *param_1,ulonglong param_2)



{

  longlong lVar1;

  ulonglong uVar2;

  undefined8 *puVar3;

  longlong lVar4;

  ulonglong uVar5;

  longlong lVar6;

  

  if (0x7ffffffffffffff < param_2) {

                    /* WARNING: Subroutine does not return */

    FUN_14002f0d0();

  }

  uVar2 = param_1[2] - *param_1 >> 5;

  lVar6 = param_1[1] - *param_1 >> 5;

  if (0x7ffffffffffffff - (uVar2 >> 1) < uVar2) {

    uVar5 = 0x7ffffffffffffff;

  }

  else {

    uVar2 = (uVar2 >> 1) + uVar2;

    uVar5 = param_2;

    if ((param_2 <= uVar2) && (uVar5 = uVar2, 0x7ffffffffffffff < uVar2)) {

                    /* WARNING: Subroutine does not return */

      FUN_140024090();

    }

  }

  lVar1 = FUN_1400285e0(uVar5 * 0x20);

  puVar3 = (undefined8 *)(lVar6 * 0x20 + lVar1);

  for (lVar6 = param_2 - lVar6; lVar6 != 0; lVar6 = lVar6 + -1) {

    *puVar3 = 0;

    puVar3[1] = 0;

    *(undefined4 *)(puVar3 + 2) = 0x3f800000;

    *(undefined4 *)((longlong)puVar3 + 0x14) = 0x3f800000;

    *(undefined4 *)(puVar3 + 3) = 0x3f800000;

    *(undefined4 *)((longlong)puVar3 + 0x1c) = 0x3f800000;

    puVar3 = puVar3 + 4;

  }

  FUN_1402f8e20(lVar1);

  lVar6 = *param_1;

  if (lVar6 != 0) {

    lVar4 = lVar6;

    if ((0xfff < (param_1[2] - lVar6 & 0xffffffffffffffe0U)) &&

       (lVar4 = *(longlong *)(lVar6 + -8), 0x1f < (lVar6 - lVar4) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar4);

  }

  *param_1 = lVar1;

  param_1[1] = param_2 * 0x20 + lVar1;

  param_1[2] = uVar5 * 0x20 + lVar1;

  return;

}




