// Address: 0x1402e4450
// Ghidra name: FUN_1402e4450
// ============ 0x1402e4450 FUN_1402e4450 (size=1242) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



double FUN_1402e4450(undefined8 param_1,undefined8 param_2)



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

  ulonglong uVar11;

  ulonglong uVar12;

  double dVar13;

  double dVar14;

  undefined1 auVar15 [16];

  undefined1 auVar16 [16];

  undefined1 auVar17 [16];

  undefined1 in_ZMM0 [64];

  double dVar18;

  undefined1 auVar19 [16];

  double dVar20;

  undefined1 auVar21 [16];

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

  

  dVar14 = in_ZMM0._0_8_;

  auVar15 = in_ZMM0._0_16_;

  if (DAT_1403ff158 == 0) {

    dVar13 = ABS(dVar14);

    if ((ulonglong)dVar13 < (ulonglong)DAT_14038bf40) {

      dVar34 = (double)(int)(((ulonglong)dVar14 >> 0x34) - _DAT_14038bf90);

      dVar20 = (double)((ulonglong)dVar14 & (ulonglong)DAT_14038bf80);

      dVar18 = dVar14;

      if (dVar34 == DAT_14038c090) {

        dVar20 = (double)((ulonglong)dVar20 | (ulonglong)DAT_14038bfe0) - DAT_14038bfe0;

        dVar18 = (double)((ulonglong)dVar20 & (ulonglong)DAT_14038bf80);

        dVar34 = (double)(int)((uint)((ulonglong)dVar20 >> 0x34) - _DAT_14038c0a0);

        dVar20 = dVar18;

      }

      uVar11 = ((ulonglong)dVar18 & _DAT_14038bfb0) + ((ulonglong)dVar18 & _DAT_14038bfc0) * 2;

      if ((double)((ulonglong)(dVar14 - DAT_14038bfe0) & _DAT_14038c0c0) < DAT_14038c0b0) {

        dVar14 = dVar14 - DAT_14038bfe0;

        dVar13 = dVar14 / (DAT_14038bfd0 + dVar14);

        dVar18 = dVar13 + dVar13;

        dVar20 = dVar18 * dVar18;

        dVar34 = dVar20 * dVar18;

        return dVar14 + (((DAT_14038c0e0 * dVar20 + DAT_14038c0d0) * dVar34 +

                         (DAT_14038c100 * dVar20 + DAT_14038c0f0) * dVar34 * dVar34 * dVar18) -

                        dVar14 * dVar13);

      }

      uVar12 = uVar11 >> 0x2c;

      if (0.0 < dVar14) {

        dVar13 = ((double)(uVar11 | (ulonglong)DAT_14038c010) -

                 (double)((ulonglong)dVar20 | (ulonglong)DAT_14038c010)) *

                 *(double *)(&DAT_140391a20 + uVar12 * 8);

        dVar14 = dVar13 * dVar13;

        return *(double *)(&DAT_140393560 + uVar12 * 8) + DAT_14038c110 * dVar34 +

               *(double *)(&DAT_140393d70 + uVar12 * 8) +

               (DAT_14038c120 * dVar34 -

               ((DAT_14038c050 * dVar13 + DAT_14038c040) * dVar14 + dVar13 +

               ((DAT_14038c080 * dVar13 + DAT_14038c070) * dVar13 + DAT_14038c060) * dVar14 * dVar14

               ));

      }

      if (dVar14 == 0.0) {

        dVar14 = (double)FUN_1402ecfe0(dVar13,param_2,DAT_14038c130);

        return dVar14;

      }

    }

    else {

      if (dVar14 == DAT_14038bf40) {

        return dVar14;

      }

      if (dVar14 != DAT_14038bf30) {

        return (double)((ulonglong)dVar14 | _DAT_14038bf60);

      }

    }

    dVar14 = (double)FUN_1402ecfe0(dVar13,param_2,DAT_14038c134);

    return dVar14;

  }

  auVar23 = vpsrlq_avx(auVar15,0x34);

  auVar33._8_8_ = _UNK_14038bf98;

  auVar33._0_8_ = _DAT_14038bf90;

  auVar33 = vpsubq_avx(auVar23,auVar33);

  auVar33 = vcvtdq2pd_avx(auVar33);

  auVar23._8_8_ = _UNK_14038bf48;

  auVar23._0_8_ = DAT_14038bf40;

  auVar23 = vpand_avx(auVar15,auVar23);

  if (auVar23._0_8_ == DAT_14038bf40) {

    if (dVar14 != DAT_14038bf40) {

      if (dVar14 == DAT_14038bf30) goto LAB_1402e4920;

      dVar14 = (double)FUN_1402ecfe0(param_1,(ulonglong)dVar14 | _DAT_14038bf60,DAT_14038c138);

    }

    return dVar14;

  }

  if (0.0 < dVar14) {

    auVar23 = vpand_avx(auVar15,_DAT_14038bf80);

    if (auVar33._0_8_ == DAT_14038c090) {

      auVar15._8_8_ = _UNK_14038bfe8;

      auVar15._0_8_ = DAT_14038bfe0;

      auVar15 = vpor_avx(auVar23,auVar15);

      auVar24._8_8_ = 0;

      auVar24._0_8_ = auVar15._0_8_ - DAT_14038bfe0;

      auVar33 = vpsrlq_avx(auVar24,0x34);

      auVar15 = vpand_avx(auVar24,_DAT_14038bf80);

      auVar7._4_12_ = _UNK_14038c0a4;

      auVar7._0_4_ = _DAT_14038c0a0;

      auVar33 = vpsubd_avx(auVar33,auVar7);

      auVar33 = vcvtdq2pd_avx(auVar33);

      auVar23 = auVar15;

    }

    auVar8._8_8_ = _UNK_14038bfb8;

    auVar8._0_8_ = _DAT_14038bfb0;

    auVar7 = vpand_avx(auVar15,auVar8);

    auVar9._8_8_ = _UNK_14038bfc8;

    auVar9._0_8_ = _DAT_14038bfc0;

    auVar24 = vpand_avx(auVar15,auVar9);

    auVar24 = vpsllq_avx(auVar24,1);

    auVar7 = vpaddq_avx(auVar24,auVar7);

    auVar26._8_8_ = 0;

    auVar26._0_8_ = dVar14 - DAT_14038bfe0;

    auVar10._8_8_ = _UNK_14038c0c8;

    auVar10._0_8_ = _DAT_14038c0c0;

    auVar24 = vpand_avx(auVar26,auVar10);

    if (auVar24._0_8_ < DAT_14038c0b0) {

      dVar18 = auVar15._0_8_ - DAT_14038bfe0;

      dVar20 = dVar18 / (DAT_14038bfd0 + dVar18);

      auVar28._8_8_ = 0;

      auVar28._0_8_ = DAT_14038c0e0;

      auVar32._8_8_ = 0;

      auVar32._0_8_ = DAT_14038c100;

      dVar14 = dVar20 + dVar20;

      auVar5._8_8_ = 0;

      auVar5._0_8_ = DAT_14038c0d0;

      auVar21._8_8_ = 0;

      auVar21._0_8_ = dVar14 * dVar14;

      auVar15 = vfmadd213sd_fma(auVar28,auVar21,auVar5);

      auVar6._8_8_ = 0;

      auVar6._0_8_ = DAT_14038c0f0;

      auVar33 = vfmadd213sd_fma(auVar32,auVar21,auVar6);

      dVar13 = dVar14 * dVar14 * dVar14;

      auVar22._8_8_ = 0;

      auVar22._0_8_ = dVar13 * dVar13 * dVar14;

      auVar29._8_8_ = 0;

      auVar29._0_8_ = auVar15._0_8_ * dVar13;

      auVar15 = vfmadd231sd_fma(auVar29,auVar33,auVar22);

      return dVar18 + (auVar15._0_8_ - dVar18 * dVar20);

    }

    uVar11 = auVar7._0_8_ >> 0x2c;

    auVar15 = vpor_avx(auVar23,_DAT_14038c010);

    auVar23 = vpor_avx(auVar7,_DAT_14038c010);

    dVar14 = (auVar23._0_8_ - auVar15._0_8_) * *(double *)(&DAT_140391a20 + uVar11 * 8);

    dVar13 = dVar14 * dVar14;

    auVar25._8_8_ = 0;

    auVar25._0_8_ = DAT_14038c080;

    auVar30._8_8_ = 0;

    auVar30._0_8_ = DAT_14038c050;

    auVar1._8_8_ = 0;

    auVar1._0_8_ = DAT_14038c070;

    auVar19._8_8_ = 0;

    auVar19._0_8_ = dVar14;

    auVar15 = vfmadd213sd_fma(auVar25,auVar19,auVar1);

    auVar2._8_8_ = 0;

    auVar2._0_8_ = DAT_14038c040;

    auVar23 = vfmadd213sd_fma(auVar30,auVar19,auVar2);

    auVar3._8_8_ = 0;

    auVar3._0_8_ = DAT_14038c060;

    auVar15 = vfmadd213sd_fma(auVar15,auVar19,auVar3);

    auVar16._8_8_ = 0;

    auVar16._0_8_ = dVar13;

    auVar23 = vfmadd231sd_fma(auVar19,auVar23,auVar16);

    auVar27._8_8_ = 0;

    auVar27._0_8_ = dVar13 * dVar13;

    auVar15 = vfmadd231sd_fma(auVar23,auVar15,auVar27);

    auVar31._8_8_ = 0;

    auVar31._0_8_ = DAT_14038c120;

    auVar23 = vfmsub213sd_fma(auVar31,auVar33,auVar15);

    auVar17._8_8_ = 0;

    auVar17._0_8_ = *(ulonglong *)(&DAT_140393560 + uVar11 * 8);

    auVar4._8_8_ = 0;

    auVar4._0_8_ = DAT_14038c110;

    auVar15 = vfmadd231sd_fma(auVar17,auVar33,auVar4);

    return auVar15._0_8_ + *(double *)(&DAT_140393d70 + uVar11 * 8) + auVar23._0_8_;

  }

  if (dVar14 == 0.0) {

    dVar14 = (double)FUN_1402ecfe0(param_1,DAT_14038bf30,DAT_14038c130);

    return dVar14;

  }

LAB_1402e4920:

  dVar14 = (double)FUN_1402ecfe0(param_1,DAT_14038bf50,DAT_14038c134);

  return dVar14;

}




