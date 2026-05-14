// Address: 0x1400748b0
// Ghidra name: FUN_1400748b0
// ============ 0x1400748b0 FUN_1400748b0 (size=246) ============


undefined8 * FUN_1400748b0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)



{

  ulonglong uVar1;

  ulonglong uVar2;

  longlong lVar3;

  undefined8 *puVar4;

  ulonglong uVar5;

  

  uVar2 = param_3[2];

  lVar3 = param_2[2];

  if (uVar2 <= 0x7fffffffffffffffU - lVar3) {

    if (0xf < (ulonglong)param_2[3]) {

      param_2 = (undefined8 *)*param_2;

    }

    if (0xf < (ulonglong)param_3[3]) {

      param_3 = (undefined8 *)*param_3;

    }

    uVar1 = lVar3 + uVar2;

    *param_1 = 0;

    param_1[1] = 0;

    uVar5 = 0xf;

    param_1[2] = 0;

    param_1[3] = 0;

    puVar4 = param_1;

    if (0xf < uVar1) {

      uVar5 = uVar1 | 0xf;

      if (uVar5 < 0x8000000000000000) {

        if (uVar5 < 0x16) {

          uVar5 = 0x16;

        }

      }

      else {

        uVar5 = 0x7fffffffffffffff;

      }

      puVar4 = (undefined8 *)FUN_1400285e0(uVar5 + 1);

      *param_1 = puVar4;

    }

    param_1[2] = uVar1;

    param_1[3] = uVar5;

    FUN_1402f8e20(puVar4,param_2,lVar3);

    FUN_1402f8e20((longlong)puVar4 + lVar3,param_3,uVar2);

    *(undefined1 *)((longlong)puVar4 + uVar1) = 0;

    return param_1;

  }

                    /* WARNING: Subroutine does not return */

  FUN_140024130();

}




