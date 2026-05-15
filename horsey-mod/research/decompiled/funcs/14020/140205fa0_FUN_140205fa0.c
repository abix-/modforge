// Address: 0x140205fa0
// Ghidra name: FUN_140205fa0
// ============ 0x140205fa0 FUN_140205fa0 (size=1110) ============


undefined8 FUN_140205fa0(int *param_1,int *param_2,longlong param_3,int param_4)



{

  int iVar1;

  int iVar2;

  undefined8 uVar3;

  longlong lVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  longlong lVar9;

  longlong lVar10;

  

  lVar9 = (longlong)param_4;

  iVar6 = *param_1;

  if (iVar6 < 0x3259555a) {

    if (iVar6 == 0x32595559) goto LAB_14020638e;

    if ((iVar6 == 0x3132564e) || (iVar6 == 0x3231564e)) {

      if ((*param_2 != 0) ||

         (((param_2[1] != 0 || (iVar6 = param_1[3], param_2[2] != iVar6)) ||

          (iVar1 = param_1[4], param_2[3] != iVar1)))) {

        iVar6 = param_1[3];

        iVar8 = 0;

        iVar1 = param_2[3];

        iVar2 = 0;

        iVar7 = param_2[2];

        lVar4 = (longlong)(iVar6 * param_2[1]) + (longlong)*param_2 + *(longlong *)(param_1 + 6);

        lVar10 = param_3;

        if (0 < iVar1) {

          do {

            FUN_1402f8e20(lVar4,lVar10,(longlong)iVar7);

            iVar6 = param_1[3];

            iVar1 = param_2[3];

            lVar4 = lVar4 + iVar6;

            iVar2 = iVar2 + 1;

            lVar10 = lVar10 + lVar9;

          } while (iVar2 < iVar1);

        }

        param_3 = iVar1 * param_4 + param_3;

        iVar7 = param_2[2];

        lVar9 = (longlong)((((iVar6 + 1) / 2) * ((param_2[1] + 1) / 2) + *param_2 / 2) * 2) +

                (longlong)(iVar6 * param_1[4]) + *(longlong *)(param_1 + 6);

        if ((iVar1 + 1) / 2 < 1) {

          return 1;

        }

        do {

          FUN_1402f8e20(lVar9,param_3,(longlong)iVar7 + 1U & 0xfffffffffffffffe);

          param_3 = param_3 + ((param_4 + 1) / 2) * 2;

          iVar8 = iVar8 + 1;

          lVar9 = lVar9 + ((param_1[3] + 1) / 2) * 2;

        } while (iVar8 < (param_2[3] + 1) / 2);

        return 1;

      }

      goto LAB_140206226;

    }

    if (iVar6 != 0x32315659) {

LAB_140206380:

      uVar3 = FUN_14012e850("Unsupported YUV format");

      return uVar3;

    }

  }

  else {

    if (iVar6 == 0x55595659) {

LAB_14020638e:

      iVar1 = 0;

      iVar6 = param_2[2];

      lVar10 = (longlong)(param_2[1] * param_1[8]) + (longlong)(*param_2 * 2) +

               *(longlong *)(param_1 + 0xc);

      if (0 < param_2[3]) {

        do {

          FUN_1402f8e20(lVar10,param_3,((longlong)iVar6 + 1U >> 1) << 2);

          param_3 = param_3 + lVar9;

          lVar10 = lVar10 + param_1[8];

          iVar1 = iVar1 + 1;

        } while (iVar1 < param_2[3]);

      }

      return 1;

    }

    if (iVar6 != 0x56555949) {

      if (iVar6 != 0x59565955) goto LAB_140206380;

      goto LAB_14020638e;

    }

  }

  if (((*param_2 != 0) || (param_2[1] != 0)) ||

     ((iVar6 = param_1[3], param_2[2] != iVar6 || (iVar1 = param_1[4], param_2[3] != iVar1)))) {

    iVar7 = param_1[3];

    iVar6 = param_2[3];

    iVar8 = 0;

    iVar1 = param_2[2];

    lVar4 = (longlong)(iVar7 * param_2[1]) + (longlong)*param_2 + *(longlong *)(param_1 + 6);

    lVar10 = param_3;

    if (0 < iVar6) {

      do {

        FUN_1402f8e20(lVar4,lVar10,(longlong)iVar1);

        iVar7 = param_1[3];

        iVar6 = param_2[3];

        lVar4 = lVar4 + iVar7;

        iVar8 = iVar8 + 1;

        lVar10 = lVar10 + lVar9;

      } while (iVar8 < iVar6);

    }

    iVar8 = 0;

    lVar10 = iVar6 * param_4 + param_3;

    iVar1 = param_2[2];

    lVar9 = (longlong)(((iVar7 + 1) / 2) * (param_2[1] / 2) + *param_2 / 2) +

            (longlong)(iVar7 * param_1[4]) + *(longlong *)(param_1 + 6);

    if (0 < (iVar6 + 1) / 2) {

      do {

        FUN_1402f8e20(lVar9,lVar10,(longlong)((iVar1 + 1) / 2));

        iVar7 = param_1[3];

        lVar10 = lVar10 + (param_4 + 1) / 2;

        iVar6 = param_2[3];

        iVar8 = iVar8 + 1;

        lVar9 = lVar9 + (iVar7 + 1) / 2;

      } while (iVar8 < (iVar6 + 1) / 2);

    }

    iVar5 = 0;

    iVar1 = (iVar6 + 1) / 2;

    iVar8 = (param_4 + 1) / 2;

    lVar10 = (longlong)(iVar1 * iVar8) + param_3 + iVar6 * param_4;

    iVar2 = (iVar7 + 1) / 2;

    iVar6 = param_2[2];

    lVar9 = (longlong)((param_2[1] / 2) * iVar2 + *param_2 / 2) +

            (longlong)(((param_1[4] + 1) / 2) * iVar2) + (longlong)(param_1[4] * iVar7) +

            *(longlong *)(param_1 + 6);

    if (iVar1 < 1) {

      return 1;

    }

    do {

      FUN_1402f8e20(lVar9,lVar10,(longlong)((iVar6 + 1) / 2));

      lVar10 = lVar10 + iVar8;

      iVar5 = iVar5 + 1;

      lVar9 = lVar9 + (param_1[3] + 1) / 2;

    } while (iVar5 < (param_2[3] + 1) / 2);

    return 1;

  }

LAB_140206226:

  FUN_1402f8e20(*(undefined8 *)(param_1 + 6),param_3,

                (longlong)(((iVar6 + 1) / 2) * ((iVar1 + 1) / 2) * 2) + (longlong)(iVar6 * iVar1));

  return 1;

}




