// Address: 0x14008d2d0
// Ghidra name: FUN_14008d2d0
// ============ 0x14008d2d0 FUN_14008d2d0 (size=202) ============


undefined8 * FUN_14008d2d0(undefined8 *param_1)



{

  ulonglong uVar1;

  ulonglong uVar2;

  undefined8 uVar3;

  undefined8 *puVar4;

  ulonglong uVar5;

  

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  uVar1 = DAT_1403d9eb0;

  puVar4 = &DAT_1403d9ea0;

  if (0xf < DAT_1403d9eb8) {

    puVar4 = DAT_1403d9ea0;

  }

  if (DAT_1403d9eb0 < 0x8000000000000000) {

    if (DAT_1403d9eb0 < 0x10) {

      param_1[2] = DAT_1403d9eb0;

      param_1[3] = 0xf;

      uVar3 = puVar4[1];

      *param_1 = *puVar4;

      param_1[1] = uVar3;

    }

    else {

      uVar2 = DAT_1403d9eb0 | 0xf;

      uVar5 = 0x7fffffffffffffff;

      if ((uVar2 < 0x8000000000000000) && (uVar5 = uVar2, uVar2 < 0x16)) {

        uVar5 = 0x16;

      }

      uVar3 = FUN_1400285e0(uVar5 + 1);

      *param_1 = uVar3;

      param_1[2] = uVar1;

      param_1[3] = uVar5;

      FUN_1402f8e20(uVar3,puVar4,uVar1 + 1);

    }

    return param_1;

  }

                    /* WARNING: Subroutine does not return */

  FUN_140024130();

}




