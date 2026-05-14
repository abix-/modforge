// Address: 0x1402d0770
// Ghidra name: FUN_1402d0770
// ============ 0x1402d0770 FUN_1402d0770 (size=22) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



double FUN_1402d0770(double param_1)



{

  undefined1 auVar1 [16];

  undefined1 auVar2 [16];

  undefined1 auVar3 [16];

  undefined1 auVar4 [16];

  undefined1 auVar5 [16];

  undefined1 auVar6 [16];

  undefined1 auVar7 [16];

  undefined1 auVar8 [16];

  undefined1 auVar9 [16];

  undefined1 auVar10 [16];

  uint uVar11;

  int iVar12;

  double dVar13;

  ulonglong uVar14;

  uint uVar15;

  ulonglong uVar16;

  longlong lVar17;

  longlong lVar18;

  uint uVar19;

  uint uVar20;

  double dVar21;

  undefined1 auVar22 [16];

  undefined1 auVar23 [16];

  undefined1 auVar24 [16];

  undefined1 auVar25 [16];

  undefined1 auVar26 [16];

  undefined1 auVar27 [16];

  undefined1 auVar28 [16];

  undefined1 auVar29 [16];

  undefined1 auVar30 [16];

  undefined1 auVar31 [16];

  undefined1 auVar32 [16];

  undefined1 auVar33 [16];

  double dVar34;

  undefined1 auVar35 [16];

  undefined1 auVar36 [16];

  undefined1 auVar37 [16];

  undefined1 in_ZMM1 [64];

  undefined1 auVar38 [16];

  undefined1 auVar39 [16];

  undefined1 auVar40 [16];

  undefined1 auVar41 [16];

  undefined1 auVar42 [16];

  undefined1 auVar43 [16];

  undefined1 auVar44 [16];

  undefined1 auVar45 [16];

  undefined1 auVar46 [16];

  double dVar47;

  undefined1 auVar48 [16];

  undefined1 auVar49 [16];

  undefined1 auVar50 [16];

  double dVar51;

  undefined1 auVar52 [16];

  undefined1 auVar53 [16];

  undefined1 auVar54 [16];

  

  if (((byte)DAT_1403ff158 & 3) != 3) {

    dVar21 = (double)FUN_1402d0790();

    return dVar21;

  }

  lVar18 = 0;

  lVar17 = 0;

  dVar21 = in_ZMM1._0_8_;

  uVar19 = (uint)((ulonglong)param_1 >> 0x20);

  uVar15 = uVar19 >> 0x14;

  uVar11 = in_ZMM1._4_4_;

  uVar20 = uVar11 >> 0x14;

  dVar34 = param_1;

  if ((0x7fd < uVar15 - 1) || (0x7f < (uVar20 & 0x7ff) - 0x3be)) {

    uVar14 = (longlong)dVar21 * 2;

    if (0xffdffffffffffffe < uVar14 - 1) {

      if ((uVar14 == 0) || (dVar34 = dVar21, param_1 == 1.0)) {

        if (((ulonglong)dVar34 ^ 0x8000000000000) * 2 < 0xfff0000000000001) {

          return DAT_140304b90;

        }

      }

      else {

        uVar16 = (longlong)param_1 * 2;

        if ((uVar16 < 0xffe0000000000001) && (uVar14 < 0xffe0000000000001)) {

          if (uVar16 == 0x7fe0000000000000) {

            return DAT_140304b90;

          }

          if ((uint)(uVar16 < 0x7fe0000000000000) == (uVar11 >> 0x1f ^ 1)) {

            return 0.0;

          }

          return dVar21 * dVar21;

        }

      }

      return param_1 + dVar21;

    }

    if (0xffdffffffffffffe < (longlong)param_1 * 2 - 1U) {

      dVar34 = param_1 * param_1;

      if ((((((ulonglong)param_1 & 0x8000000000000000) != 0) &&

           (uVar15 = uVar11 >> 0x14 & 0x7ff, lVar18 = lVar17, uVar15 - 0x3ff < 0x35)) &&

          (uVar14 = 1L << ((ulonglong)(0x433 - uVar15) & 0x3f),

          ((ulonglong)dVar21 & uVar14 - 1) == 0)) && (((ulonglong)dVar21 & uVar14) != 0)) {

        dVar34 = (double)((ulonglong)dVar34 ^ DAT_140305470);

        lVar18 = 1;

      }

      if ((longlong)param_1 * 2 == 0) {

        if (((ulonglong)dVar21 & 0x8000000000000000) == 0) {

          return dVar34;

        }

        dVar21 = (double)FUN_1402ed930(lVar18);

        return dVar21;

      }

      if (((ulonglong)dVar21 & 0x8000000000000000) == 0) {

        return dVar34;

      }

      return DAT_140304b90 / dVar34;

    }

    if (((ulonglong)param_1 & 0x8000000000000000) != 0) {

      uVar15 = uVar11 >> 0x14 & 0x7ff;

      if (uVar15 < 0x3ff) {

LAB_1402ed440:

        dVar21 = (double)FUN_1402ed990();

        return dVar21;

      }

      if (uVar15 < 0x434) {

        uVar14 = 1L << ((ulonglong)(0x433 - uVar15) & 0x3f);

        if (((ulonglong)dVar21 & uVar14 - 1) != 0) goto LAB_1402ed440;

        iVar12 = 2 - (uint)((uVar14 & (ulonglong)dVar21) != 0);

      }

      else {

        iVar12 = 2;

      }

      dVar34 = ABS(param_1);

      uVar15 = uVar19 >> 0x14 & 0x7ff;

      lVar18 = 0x80000;

      if (iVar12 != 1) {

        lVar18 = 0;

      }

    }

    if (0x7f < (uVar20 & 0x7ff) - 0x3be) {

      if (dVar34 == 1.0) {

        return DAT_140304b90;

      }

      if ((uVar20 & 0x7ff) < 0x3be) {

        if (0x3ff0000000000000 < (ulonglong)dVar34) {

          return dVar21 + DAT_140304b90;

        }

        return DAT_140304b90 - dVar21;

      }

      if (0x3ff0000000000000 < (ulonglong)dVar34 == uVar20 < 0x800) {

        dVar21 = (double)FUN_1402ed9d0();

        return dVar21;

      }

      dVar21 = (double)FUN_1402eda20(0);

      return dVar21;

    }

    if (uVar15 == 0) {

      dVar34 = (double)((longlong)ABS(param_1 * DAT_140388f58) + 0xfcc0000000000000);

    }

  }

  auVar50._8_8_ = 0;

  auVar50._0_8_ = DAT_140390640;

  auVar54._8_8_ = 0;

  auVar54._0_8_ = DAT_140388e08;

  uVar15 = (uint)((longlong)dVar34 + 0xc0196aab00000000U >> 0x20);

  lVar17 = (ulonglong)(uVar15 >> 0xd & 0x7f) * 0x20;

  auVar53._0_8_ = (double)((int)uVar15 >> 0x14);

  auVar53._8_8_ = 0;

  auVar52._8_8_ = 0;

  auVar52._0_8_ = *(ulonglong *)(&DAT_140390688 + lVar17);

  auVar1._8_8_ = 0;

  auVar1._0_8_ = *(ulonglong *)(&DAT_140390698 + lVar17);

  auVar1 = vfmadd213sd_fma(auVar50,auVar53,auVar1);

  auVar22._8_8_ = 0;

  auVar22._0_8_ = (longlong)dVar34 - ((longlong)dVar34 + 0xc0196aab00000000U & 0xfff0000000000000);

  auVar10 = vfmadd213sd_fma(auVar52,auVar22,auVar54);

  dVar51 = auVar10._0_8_;

  auVar23._8_8_ = 0;

  auVar23._0_8_ = DAT_140390660;

  dVar47 = dVar51 * DAT_140390650 * dVar51;

  dVar34 = auVar1._0_8_ + dVar51;

  dVar13 = dVar47 + dVar34;

  auVar2._8_8_ = 0;

  auVar2._0_8_ = DAT_140390658;

  auVar2 = vfmadd213sd_fma(auVar10,auVar23,auVar2);

  auVar24._8_8_ = 0;

  auVar24._0_8_ = DAT_140390670;

  auVar3._8_8_ = 0;

  auVar3._0_8_ = DAT_140390668;

  auVar3 = vfmadd213sd_fma(auVar10,auVar24,auVar3);

  auVar25._8_8_ = 0;

  auVar25._0_8_ = DAT_140390680;

  auVar4._8_8_ = 0;

  auVar4._0_8_ = DAT_140390678;

  auVar4 = vfmadd213sd_fma(auVar10,auVar25,auVar4);

  auVar26._0_8_ = (ulonglong)dVar47 ^ DAT_140305470;

  auVar26._8_8_ = _UNK_140305478;

  auVar43._8_8_ = 0;

  auVar43._0_8_ = dVar47;

  auVar4 = vfmadd231sd_fma(auVar3,auVar43,auVar4);

  auVar40._8_8_ = 0;

  auVar40._0_8_ = dVar51 * DAT_140390650;

  auVar3 = vfmadd213sd_fma(auVar40,auVar10,auVar26);

  auVar4 = vfmadd231sd_fma(auVar2,auVar43,auVar4);

  auVar38._8_8_ = 0;

  auVar38._0_8_ = DAT_140390648;

  auVar10._8_8_ = 0;

  auVar10._0_8_ = *(ulonglong *)(&DAT_1403906a0 + lVar17);

  auVar2 = vfmadd213sd_fma(auVar38,auVar53,auVar10);

  auVar44._8_8_ = 0;

  auVar44._0_8_ =

       auVar3._0_8_ + auVar2._0_8_ + (auVar1._0_8_ - dVar34) + dVar51 + (dVar34 - dVar13) + dVar47;

  auVar48._8_8_ = 0;

  auVar48._0_8_ = dVar47 * dVar51;

  auVar2 = vfmadd231sd_fma(auVar44,auVar48,auVar4);

  dVar34 = auVar2._0_8_ + dVar13;

  dVar21 = dVar34 * dVar21;

  auVar27._0_8_ = (ulonglong)dVar21 ^ DAT_140305470;

  auVar27._8_8_ = _UNK_140305478;

  uVar19 = (uint)((ulonglong)dVar21 >> 0x34) & 0x7ff;

  auVar35._8_8_ = 0;

  auVar35._0_8_ = dVar34;

  auVar1 = vfmadd213sd_fma(in_ZMM1._0_16_,auVar35,auVar27);

  auVar36._8_8_ = 0;

  auVar36._0_8_ = (dVar13 - dVar34) + auVar2._0_8_;

  auVar1 = vfmadd231sd_fma(auVar1,in_ZMM1._0_16_,auVar36);

  uVar15 = uVar19;

  if (0x3e < uVar19 - 0x3c9) {

    if (0x7fffffff < uVar19 - 0x3c9) {

      if ((int)lVar18 == 0) {

        return dVar21 + DAT_140304b90;

      }

      return (double)((ulonglong)(dVar21 + DAT_140304b90) ^ DAT_140305470);

    }

    uVar15 = 0;

    if (0x408 < uVar19) {

      if (((ulonglong)dVar21 & 0x8000000000000000) != 0) {

        dVar21 = (double)FUN_1402eda20();

        return dVar21;

      }

      dVar21 = (double)FUN_1402ed9d0(lVar18);

      return dVar21;

    }

  }

  auVar28._8_8_ = 0;

  auVar28._0_8_ = DAT_14038f5d0;

  auVar41._8_8_ = 0;

  auVar41._0_8_ = dVar21;

  auVar5._8_8_ = 0;

  auVar5._0_8_ = DAT_14038f5d8;

  auVar2 = vfmadd213sd_fma(auVar41,auVar28,auVar5);

  uVar16 = auVar2._0_8_ >> 0x10;

  auVar29._0_8_ = (double)auVar2._2_4_;

  auVar29._8_8_ = SUB168(ZEXT816(0),4);

  auVar6._8_8_ = 0;

  auVar6._0_8_ = DAT_14038f5e0;

  auVar2 = vfmadd231sd_fma(auVar41,auVar29,auVar6);

  auVar7._8_8_ = 0;

  auVar7._0_8_ = DAT_14038f5e8;

  auVar2 = vfmadd231sd_fma(auVar2,auVar29,auVar7);

  auVar30._8_8_ = 0;

  auVar30._0_8_ = DAT_14038f608;

  dVar21 = auVar2._0_8_ + auVar1._0_8_;

  auVar37._8_8_ = 0;

  auVar37._0_8_ = DAT_14038f5f8;

  dVar34 = dVar21 * dVar21;

  auVar45._8_8_ = 0;

  auVar45._0_8_ = dVar21;

  auVar8._8_8_ = 0;

  auVar8._0_8_ = DAT_14038f5f0;

  auVar1 = vfmadd213sd_fma(auVar45,auVar37,auVar8);

  uVar14 = (lVar18 + uVar16 << 0x2c) + *(longlong *)(&DAT_14038f648 + (uVar16 & 0xff) * 0x10);

  auVar9._8_8_ = 0;

  auVar9._0_8_ = DAT_14038f600;

  auVar2 = vfmadd213sd_fma(auVar45,auVar30,auVar9);

  auVar42._8_8_ = 0;

  auVar42._0_8_ = dVar34;

  auVar49._8_8_ = 0;

  auVar49._0_8_ = dVar21 + *(double *)(&DAT_14038f640 + (uVar16 & 0xff) * 0x10);

  auVar1 = vfmadd231sd_fma(auVar49,auVar42,auVar1);

  auVar31._8_8_ = 0;

  auVar31._0_8_ = dVar34 * dVar34;

  auVar1 = vfmadd231sd_fma(auVar1,auVar31,auVar2);

  if (uVar15 == 0) {

    if ((uVar16 & 0x80000000) == 0) {

      auVar32._8_8_ = 0;

      auVar32._0_8_ = uVar14 + 0xc0f0000000000000;

      auVar1 = vfmadd231sd_fma(auVar32,auVar1,auVar32);

      dVar21 = (double)FUN_1402ed8c0(auVar1._0_8_ * DAT_140388f60);

    }

    else {

      auVar46._8_8_ = 0;

      auVar46._0_8_ = DAT_140304b90;

      dVar13 = (double)(uVar14 + 0x3fe0000000000000);

      dVar34 = dVar13 * auVar1._0_8_;

      dVar21 = dVar13 + dVar34;

      auVar39._8_8_ = 0;

      auVar39._0_8_ = dVar21;

      auVar1 = vandpd_avx(auVar39,_DAT_140313bc0);

      if (auVar1._0_8_ < DAT_140304b90) {

        auVar1 = vcmpsd_avx(auVar39,ZEXT816(0) << 0x40,1);

        auVar1 = vblendvpd_avx(auVar46,auVar54,auVar1);

        dVar47 = auVar1._0_8_;

        dVar21 = ((dVar13 - dVar21) + dVar34 + (dVar47 - (dVar47 + dVar21)) + dVar21 +

                 dVar47 + dVar21) - dVar47;

        if (dVar21 == 0.0) {

          dVar21 = (double)((ulonglong)dVar13 & 0x8000000000000000);

        }

      }

      dVar21 = (double)FUN_1402ed900(dVar21 * DAT_140388f50);

    }

  }

  else {

    auVar33._8_8_ = 0;

    auVar33._0_8_ = uVar14;

    auVar1 = vfmadd231sd_fma(auVar33,auVar33,auVar1);

    dVar21 = auVar1._0_8_;

  }

  return dVar21;

}




