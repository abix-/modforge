// Address: 0x1400d8ab0
// Ghidra name: FUN_1400d8ab0
// ============ 0x1400d8ab0 FUN_1400d8ab0 (size=319) ============


longlong * FUN_1400d8ab0(longlong *param_1,longlong *param_2)



{

  longlong lVar1;

  longlong lVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  

  if (param_1 != param_2) {

    lVar2 = *param_2;

    lVar1 = *param_1;

    uVar3 = param_2[1] - lVar2 >> 3;

    uVar4 = param_1[2] - lVar1 >> 3;

    if (uVar4 < uVar3) {

      if (0x1fffffffffffffff < uVar3) {

                    /* WARNING: Subroutine does not return */

        FUN_14002f0d0();

      }

      if (0x1fffffffffffffff - (uVar4 >> 1) < uVar4) {

        uVar4 = 0x1fffffffffffffff;

      }

      else {

        uVar4 = uVar4 + (uVar4 >> 1);

        if (uVar4 < uVar3) {

          uVar4 = uVar3;

        }

      }

      if (lVar1 != 0) {

        FUN_14009c330(param_1,lVar1);

        *param_1 = 0;

        param_1[1] = 0;

        param_1[2] = 0;

      }

      if (0x1fffffffffffffff < uVar4) {

                    /* WARNING: Subroutine does not return */

        FUN_140024090();

      }

      lVar1 = FUN_1400285e0(uVar4 * 8);

      *param_1 = lVar1;

      param_1[1] = lVar1;

      param_1[2] = uVar4 * 8 + lVar1;

    }

    else {

      uVar4 = param_1[1] - lVar1 >> 3;

      if (uVar4 < uVar3) {

        FUN_1402f8e20(lVar1,lVar2,uVar4 * 8);

        lVar1 = param_1[1];

        lVar2 = uVar4 * 8 + lVar2;

        uVar3 = uVar3 - uVar4;

      }

    }

    FUN_1402f8e20(lVar1,lVar2,uVar3 * 8);

    param_1[1] = uVar3 * 8 + lVar1;

  }

  return param_1;

}




