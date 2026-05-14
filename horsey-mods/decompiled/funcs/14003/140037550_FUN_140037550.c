// Address: 0x140037550
// Ghidra name: FUN_140037550
// ============ 0x140037550 FUN_140037550 (size=296) ============


void FUN_140037550(longlong *param_1,ulonglong param_2)



{

  longlong lVar1;

  longlong lVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  

  lVar2 = param_1[1];

  lVar1 = *param_1;

  uVar5 = lVar2 - lVar1 >> 3;

  if (param_2 < uVar5) {

    param_1[1] = lVar1 + param_2 * 8;

  }

  else if (uVar5 < param_2) {

    uVar3 = param_1[2] - lVar1 >> 3;

    if (uVar3 < param_2) {

      if (0x1fffffffffffffff < param_2) {

                    /* WARNING: Subroutine does not return */

        FUN_14002f0d0();

      }

      if (0x1fffffffffffffff - (uVar3 >> 1) < uVar3) {

        uVar4 = 0x1fffffffffffffff;

      }

      else {

        uVar3 = uVar3 + (uVar3 >> 1);

        uVar4 = param_2;

        if ((param_2 <= uVar3) && (uVar4 = uVar3, 0x1fffffffffffffff < uVar3)) {

                    /* WARNING: Subroutine does not return */

          FUN_140024090();

        }

      }

      lVar2 = FUN_1400285e0(uVar4 * 8);

      FUN_1402f94c0(lVar2 + uVar5 * 8,0,(param_2 - uVar5) * 8);

      FUN_1402f8e20(lVar2,*param_1,param_1[1] - *param_1);

      FUN_140037380(param_1,lVar2,param_2,uVar4);

    }

    else {

      lVar1 = (param_2 - uVar5) * 8;

      FUN_1402f94c0(lVar2,0,lVar1);

      param_1[1] = lVar1 + lVar2;

    }

  }

  return;

}




