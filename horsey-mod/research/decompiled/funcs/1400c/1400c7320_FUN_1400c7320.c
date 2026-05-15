// Address: 0x1400c7320
// Ghidra name: FUN_1400c7320
// ============ 0x1400c7320 FUN_1400c7320 (size=438) ============


void FUN_1400c7320(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  int iVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  

  if (param_1 != 0) {

    FUN_1400c6500();

  }

  DAT_1403f34b0 = FUN_1400c6570();

  lVar2 = DAT_1403f34d0;

  uVar6 = DAT_1403f3500 - DAT_1403f34f8 >> 3;

  uVar5 = DAT_1403f34d0 - DAT_1403f34c8 >> 2;

  if (uVar6 < uVar5) {

    DAT_1403f34d0 = DAT_1403f34c8 + uVar6 * 4;

  }

  else if (uVar5 < uVar6) {

    uVar4 = DAT_1403f34d8 - DAT_1403f34c8 >> 2;

    if (uVar4 < uVar6) {

      if (0x3fffffffffffffff < uVar6) {

                    /* WARNING: Subroutine does not return */

        FUN_14002f0d0();

      }

      if (0x3fffffffffffffff - (uVar4 >> 1) < uVar4) {

        uVar7 = 0x3fffffffffffffff;

      }

      else {

        uVar4 = uVar4 + (uVar4 >> 1);

        uVar7 = uVar6;

        if ((uVar6 <= uVar4) && (uVar7 = uVar4, 0x3fffffffffffffff < uVar4)) {

                    /* WARNING: Subroutine does not return */

          FUN_140024090();

        }

      }

      lVar2 = FUN_1400285e0(uVar7 * 4);

      FUN_1402f94c0(lVar2 + uVar5 * 4,0,(uVar6 - uVar5) * 4);

      FUN_1402f8e20(lVar2,DAT_1403f34c8,DAT_1403f34d0 - DAT_1403f34c8);

      FUN_1400642e0(&DAT_1403f34c8,lVar2,uVar6,uVar7);

    }

    else {

      lVar1 = (uVar6 - uVar5) * 4;

      FUN_1402f94c0(DAT_1403f34d0,0,lVar1);

      DAT_1403f34d0 = lVar2 + lVar1;

    }

  }

  iVar3 = 0;

  if (DAT_1403f34d0 - DAT_1403f34c8 >> 2 != 0) {

    lVar2 = 0;

    do {

      *(int *)(lVar2 + DAT_1403f34c8) = iVar3;

      lVar2 = lVar2 + 4;

      iVar3 = iVar3 + 1;

    } while ((ulonglong)(longlong)iVar3 < (ulonglong)(DAT_1403f34d0 - DAT_1403f34c8 >> 2));

  }

  FUN_1400c5c80(DAT_1403f34c8,DAT_1403f34d0 - DAT_1403f34c8 >> 2 & 0xffffffff);

  return;

}




