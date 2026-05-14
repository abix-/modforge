// Address: 0x1400366e0
// Ghidra name: FUN_1400366e0
// ============ 0x1400366e0 FUN_1400366e0 (size=356) ============


void FUN_1400366e0(longlong *param_1,longlong param_2,ulonglong param_3)



{

  longlong lVar1;

  longlong lVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  

  lVar1 = *param_1;

  uVar4 = (param_1[2] - lVar1) / 0xc;

  if (uVar4 < param_3) {

    if (0x1555555555555555 < param_3) {

                    /* WARNING: Subroutine does not return */

      FUN_14002f0d0();

    }

    if (0x1555555555555555 - (uVar4 >> 1) < uVar4) {

      uVar3 = 0x1555555555555555;

    }

    else {

      uVar3 = uVar4 + (uVar4 >> 1);

      if (uVar3 < param_3) {

        uVar3 = param_3;

      }

    }

    if (lVar1 != 0) {

      FUN_1400374f0(param_1,lVar1,uVar4);

      *param_1 = 0;

      param_1[1] = 0;

      param_1[2] = 0;

    }

    if (0x1555555555555555 < uVar3) {

                    /* WARNING: Subroutine does not return */

      FUN_140024090();

    }

    lVar1 = FUN_1400285e0(uVar3 * 0xc);

    *param_1 = lVar1;

    param_1[1] = lVar1;

    param_1[2] = lVar1 + uVar3 * 0xc;

  }

  else {

    lVar2 = (param_1[1] - lVar1) / 6 + (param_1[1] - lVar1 >> 0x3f);

    uVar4 = (lVar2 >> 1) - (lVar2 >> 0x3f);

    if (uVar4 < param_3) {

      FUN_1402f8e20(lVar1,param_2,uVar4 * 0xc);

      lVar1 = param_1[1];

      param_2 = uVar4 * 0xc + param_2;

      param_3 = param_3 - uVar4;

    }

  }

  FUN_1402f8e20(lVar1,param_2,param_3 * 0xc);

  param_1[1] = param_3 * 0xc + lVar1;

  return;

}




