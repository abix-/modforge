// Address: 0x14012c500
// Ghidra name: FUN_14012c500
// ============ 0x14012c500 FUN_14012c500 (size=329) ============


longlong FUN_14012c500(longlong param_1,longlong *param_2,char param_3)



{

  ulonglong uVar1;

  int iVar2;

  ulonglong uVar3;

  longlong lVar4;

  longlong lVar5;

  longlong lVar6;

  longlong lVar7;

  ulonglong uVar8;

  

  lVar5 = 0;

  lVar7 = 0;

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403141a4);

  }

  else {

    uVar3 = FUN_14012be60();

    if ((longlong)uVar3 < 0) {

      uVar8 = 0x400;

    }

    else {

      uVar8 = uVar3;

      if (0xfffffffffffffffd < uVar3) goto LAB_14012c615;

    }

    lVar4 = FUN_1401841f0(uVar8 + 1);

    lVar5 = lVar4;

    if (lVar4 != 0) {

      while( true ) {

        while( true ) {

          lVar5 = lVar4;

          if ((((longlong)uVar3 < 0) && (uVar1 = lVar7 + 0x400, (longlong)uVar8 < (longlong)uVar1))

             && ((0xfffffffffffffffd < uVar1 ||

                 (lVar5 = FUN_140184230(lVar4,lVar7 + 0x401), uVar8 = uVar1, lVar5 == 0)))) {

            FUN_1401841e0(lVar4);

            lVar5 = 0;

            goto LAB_14012c615;

          }

          lVar6 = FUN_14012c730(param_1,(undefined1 *)(lVar5 + lVar7),uVar8 - lVar7);

          lVar4 = lVar5;

          if (lVar6 == 0) break;

          lVar7 = lVar7 + lVar6;

        }

        iVar2 = FUN_14012bf10(param_1);

        if (iVar2 != 3) break;

        FUN_1401492f0(1);

      }

      *(undefined1 *)(lVar5 + lVar7) = 0;

    }

  }

LAB_14012c615:

  if (param_2 != (longlong *)0x0) {

    *param_2 = lVar7;

  }

  if ((param_3 != '\0') && (param_1 != 0)) {

    FUN_14012bd50(param_1);

  }

  return lVar5;

}




