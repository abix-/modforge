// Address: 0x1400bf970
// Ghidra name: FUN_1400bf970
// ============ 0x1400bf970 FUN_1400bf970 (size=281) ============


void FUN_1400bf970(longlong *param_1,undefined4 *param_2)



{

  ulonglong uVar1;

  undefined4 *puVar2;

  longlong lVar3;

  ulonglong uVar4;

  undefined4 *puVar5;

  ulonglong uVar6;

  longlong lVar7;

  longlong lVar8;

  

  puVar5 = (undefined4 *)param_1[1];

  if (puVar5 != (undefined4 *)param_1[2]) {

    *puVar5 = *param_2;

    param_1[1] = param_1[1] + 4;

    return;

  }

  lVar7 = (longlong)puVar5 - *param_1 >> 2;

  if (lVar7 == 0x3fffffffffffffff) {

                    /* WARNING: Subroutine does not return */

    FUN_14002f0d0();

  }

  uVar4 = param_1[2] - *param_1 >> 2;

  uVar1 = lVar7 + 1;

  if (0x3fffffffffffffff - (uVar4 >> 1) < uVar4) {

    uVar6 = 0x3fffffffffffffff;

  }

  else {

    uVar4 = (uVar4 >> 1) + uVar4;

    uVar6 = uVar1;

    if (uVar1 <= uVar4) {

      uVar6 = uVar4;

    }

    if (0x3fffffffffffffff < uVar6) {

                    /* WARNING: Subroutine does not return */

      FUN_140024090();

    }

  }

  lVar3 = FUN_1400285e0(uVar6 * 4);

  *(undefined4 *)(lVar3 + lVar7 * 4) = *param_2;

  puVar2 = (undefined4 *)*param_1;

  if (puVar5 == (undefined4 *)param_1[1]) {

    lVar8 = param_1[1] - (longlong)puVar2;

    lVar7 = lVar3;

    puVar5 = puVar2;

  }

  else {

    FUN_1402f8e20(lVar3,puVar2,(longlong)puVar5 - (longlong)puVar2);

    lVar8 = param_1[1] - (longlong)puVar5;

    lVar7 = lVar3 + (lVar7 + 1) * 4;

  }

  FUN_1402f8e20(lVar7,puVar5,lVar8);

  FUN_1400642e0(param_1,lVar3,uVar1,uVar6);

  return;

}




