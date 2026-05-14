// Address: 0x140076910
// Ghidra name: FUN_140076910
// ============ 0x140076910 FUN_140076910 (size=255) ============


void FUN_140076910(longlong *param_1,ulonglong param_2,undefined1 *param_3)



{

  longlong lVar1;

  longlong lVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  

  lVar2 = param_1[1];

  lVar1 = *param_1;

  uVar5 = lVar2 - lVar1;

  if (param_2 < uVar5) {

    param_1[1] = lVar1 + param_2;

  }

  else if (uVar5 < param_2) {

    uVar3 = param_1[2] - lVar1;

    if (uVar3 < param_2) {

      if (0x7fffffffffffffff < param_2) {

                    /* WARNING: Subroutine does not return */

        FUN_14002f0d0();

      }

      uVar4 = 0x7fffffffffffffff;

      if ((uVar3 <= 0x7fffffffffffffff - (uVar3 >> 1)) &&

         (uVar4 = uVar3 + (uVar3 >> 1), uVar4 < param_2)) {

        uVar4 = param_2;

      }

      lVar2 = FUN_1400285e0(uVar4);

      FUN_1402f94c0(uVar5 + lVar2,*param_3,param_2 - uVar5);

      FUN_1402f8e20(lVar2,*param_1,param_1[1] - *param_1);

      FUN_1400766f0(param_1,lVar2,param_2,uVar4);

    }

    else {

      FUN_1402f94c0(lVar2,*param_3,param_2 - uVar5);

      param_1[1] = (param_2 - uVar5) + lVar2;

    }

  }

  return;

}




