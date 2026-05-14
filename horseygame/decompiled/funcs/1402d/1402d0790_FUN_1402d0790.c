// Address: 0x1402d0790
// Ghidra name: FUN_1402d0790
// ============ 0x1402d0790 FUN_1402d0790 (size=2022) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1402d0790(double param_1)



{

  double dVar1;

  uint uVar2;

  int iVar3;

  longlong lVar4;

  ulonglong uVar5;

  uint uVar6;

  uint uVar7;

  uint uVar8;

  double dVar9;

  longlong lVar10;

  double dVar11;

  double dVar12;

  undefined1 in_XMM1 [16];

  double dVar13;

  double dVar14;

  double dVar15;

  double dVar16;

  double dVar17;

  double dVar18;

  undefined4 uVar19;

  undefined4 uVar20;

  

  lVar4 = 0;

  lVar10 = 0;

  dVar15 = in_XMM1._0_8_;

  uVar8 = (uint)((ulonglong)param_1 >> 0x20);

  uVar7 = uVar8 >> 0x14;

  uVar2 = in_XMM1._4_4_;

  uVar6 = uVar2 >> 0x14;

  dVar12 = param_1;

  if ((0x7fd < uVar7 - 1) || (0x7f < (uVar6 & 0x7ff) - 0x3be)) {

    if (0xffdffffffffffffe < (longlong)dVar15 * 2 - 1U) {

      return;

    }

    if (0xffdffffffffffffe < (longlong)param_1 * 2 - 1U) {

      if ((((((ulonglong)param_1 & 0x8000000000000000) != 0) &&

           (uVar7 = uVar2 >> 0x14 & 0x7ff, lVar4 = lVar10, uVar7 - 0x3ff < 0x35)) &&

          (uVar5 = 1L << (0x33U - (char)uVar7 & 0x3f), ((ulonglong)dVar15 & uVar5 - 1) == 0)) &&

         (((ulonglong)dVar15 & uVar5) != 0)) {

        lVar4 = 1;

      }

      if ((longlong)param_1 * 2 != 0) {

        return;

      }

      if (((ulonglong)dVar15 & 0x8000000000000000) == 0) {

        return;

      }

      FUN_1402ed930(lVar4);

      return;

    }

    if (((ulonglong)param_1 & 0x8000000000000000) != 0) {

      uVar7 = uVar2 >> 0x14 & 0x7ff;

      if (uVar7 < 0x3ff) {

LAB_1402d0a3b:

        FUN_1402ed990();

        return;

      }

      if (uVar7 < 0x434) {

        uVar5 = 1L << (0x33U - (char)uVar7 & 0x3f);

        if (((ulonglong)dVar15 & uVar5 - 1) != 0) goto LAB_1402d0a3b;

        iVar3 = 2 - (uint)((uVar5 & (ulonglong)dVar15) != 0);

      }

      else {

        iVar3 = 2;

      }

      dVar12 = ABS(param_1);

      uVar7 = uVar8 >> 0x14 & 0x7ff;

      lVar4 = 0x80000;

      if (iVar3 != 1) {

        lVar4 = 0;

      }

    }

    if (0x7f < (uVar6 & 0x7ff) - 0x3be) {

      if (dVar12 == 1.0) {

        return;

      }

      if ((uVar6 & 0x7ff) < 0x3be) {

        return;

      }

      if (0x3ff0000000000000 < (ulonglong)dVar12 == uVar6 < 0x800) {

        FUN_1402ed9d0();

        return;

      }

      FUN_1402eda20(0);

      return;

    }

    if (uVar7 == 0) {

      dVar12 = (double)((longlong)ABS(param_1 * DAT_140388f58) + 0xfcc0000000000000);

    }

  }

  uVar19 = SUB84(DAT_140304b90,0);

  uVar20 = (undefined4)((ulonglong)DAT_140304b90 >> 0x20);

  dVar9 = (double)((longlong)dVar12 - ((longlong)dVar12 + 0xc0196aab00000000U & 0xfff0000000000000))

  ;

  uVar7 = (uint)((longlong)dVar12 + 0xc0196aab00000000U >> 0x20);

  lVar10 = (ulonglong)(uVar7 >> 0xd & 0x7f) * 0x20;

  dVar16 = (double)((int)uVar7 >> 0x14);

  uVar5 = (longlong)dVar9 + 0x80000000;

  dVar18 = (dVar9 - (double)(uVar5 & 0xffffffff00000000)) * *(double *)(&DAT_140390688 + lVar10);

  dVar13 = (double)(uVar5 & 0xffffffff00000000) * *(double *)(&DAT_140390688 + lVar10) -

           DAT_140304b90;

  dVar12 = dVar16 * DAT_140390640 + *(double *)(&DAT_140390698 + lVar10);

  dVar9 = dVar18 + dVar13;

  dVar14 = dVar12 + dVar9;

  dVar17 = dVar13 * DAT_140390650 * dVar13;

  dVar1 = dVar17 + dVar14;

  dVar11 = dVar9 * DAT_140390650 * dVar9;

  dVar12 = (((dVar9 * DAT_140390680 + DAT_140390678) * dVar11 +

            dVar9 * DAT_140390670 + DAT_140390668) * dVar11 + dVar9 * DAT_140390660 + DAT_140390658)

           * dVar11 * dVar9 +

           dVar16 * DAT_140390648 + *(double *)(&DAT_1403906a0 + lVar10) + (dVar12 - dVar14) + dVar9

           + (dVar13 * DAT_140390650 + dVar9 * DAT_140390650) * dVar18 + (dVar14 - dVar1) + dVar17;

  dVar14 = dVar12 + dVar1;

  dVar9 = (double)((ulonglong)dVar14 & 0xfffffffff8000000);

  dVar16 = (double)(CONCAT44((int)((ulonglong)dVar9 >> 0x20),SUB84(dVar14,0)) & 0xfffffffff8000000)

           * (double)((ulonglong)dVar15 & 0xfffffffff8000000);

  uVar8 = (uint)((ulonglong)dVar16 >> 0x34) & 0x7ff;

  uVar7 = uVar8;

  if (0x3e < uVar8 - 0x3c9) {

    if (0x7fffffff < uVar8 - 0x3c9) {

      return;

    }

    uVar7 = 0;

    if (0x408 < uVar8) {

      if (((ulonglong)dVar16 & 0x8000000000000000) != 0) {

        FUN_1402eda20();

        return;

      }

      FUN_1402ed9d0(lVar4);

      return;

    }

  }

  dVar11 = dVar16 * DAT_14038f5d0 + DAT_14038f5d8;

  uVar5 = (ulonglong)dVar11 >> 0x10;

  dVar11 = (double)(int)((ulonglong)dVar11 >> 0x10);

  lVar4 = (lVar4 + uVar5 << 0x2c) + *(longlong *)(&DAT_14038f648 + (uVar5 & 0xff) * 0x10);

  dVar15 = dVar11 * DAT_14038f5e0 + dVar16 + dVar11 * DAT_14038f5e8 +

           ((dVar1 - dVar14) + dVar12 + (dVar14 - dVar9)) * dVar15 +

           (dVar15 - (double)((ulonglong)dVar15 & 0xfffffffff8000000)) * dVar9;

  dVar12 = dVar15 * dVar15;

  dVar12 = (dVar15 * DAT_14038f5f8 + DAT_14038f5f0) * dVar12 +

           *(double *)(&DAT_14038f640 + (uVar5 & 0xff) * 0x10) + dVar15 +

           (dVar15 * DAT_14038f608 + DAT_14038f600) * dVar12 * dVar12;

  if (uVar7 == 0) {

    if ((uVar5 & 0x80000000) == 0) {

      FUN_1402ed8c0(((double)(lVar4 + -0x3f10000000000000) * dVar12 +

                    (double)(lVar4 + -0x3f10000000000000)) * DAT_140388f60);

    }

    else {

      dVar15 = (double)(lVar4 + 0x3fe0000000000000);

      dVar12 = dVar15 * dVar12;

      dVar9 = dVar15 + dVar12;

      if ((double)CONCAT44((uint)((ulonglong)dVar9 >> 0x20) & _UNK_140313bc4,

                           SUB84(dVar9,0) & _DAT_140313bc0) < DAT_140304b90) {

        if (dVar9 < 0.0) {

          uVar19 = (undefined4)DAT_140388e08;

          uVar20 = (undefined4)((ulonglong)DAT_140388e08 >> 0x20);

        }

        dVar14 = (double)CONCAT44(uVar20,uVar19) + dVar9;

        dVar9 = ((dVar15 - dVar9) + dVar12 + ((double)CONCAT44(uVar20,uVar19) - dVar14) + dVar9 +

                dVar14) - (double)CONCAT44(uVar20,uVar19);

        if (dVar9 == 0.0) {

          dVar9 = (double)((ulonglong)dVar15 & 0x8000000000000000);

        }

      }

      FUN_1402ed900(lVar4,uVar5,dVar9 * DAT_140388f50);

    }

  }

  return;

}




