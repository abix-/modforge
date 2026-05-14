// Address: 0x1402e5330
// Ghidra name: FUN_1402e5330
// ============ 0x1402e5330 FUN_1402e5330 (size=1354) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



double FUN_1402e5330(void)



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

  undefined1 auVar11 [16];

  undefined1 auVar12 [16];

  undefined1 auVar13 [16];

  undefined1 auVar14 [16];

  undefined1 auVar15 [16];

  ulonglong uVar16;

  double dVar17;

  uint uVar18;

  double dVar19;

  undefined8 extraout_XMM0_Qa;

  double dVar20;

  undefined8 extraout_XMM0_Qa_00;

  undefined1 auVar21 [16];

  undefined1 auVar22 [16];

  undefined1 in_ZMM0 [64];

  undefined1 extraout_var [56];

  undefined1 extraout_var_00 [56];

  undefined1 auVar25 [16];

  undefined1 auVar26 [16];

  undefined1 in_ZMM1 [64];

  undefined1 auVar27 [16];

  undefined1 auVar28 [16];

  undefined1 auVar29 [16];

  undefined1 auVar30 [16];

  undefined1 auVar31 [16];

  undefined1 auVar32 [16];

  undefined1 auVar33 [16];

  undefined1 auVar34 [16];

  undefined1 auVar35 [16];

  undefined1 auVar36 [16];

  undefined1 auVar37 [16];

  undefined1 auVar38 [16];

  undefined1 auVar39 [16];

  undefined1 auVar40 [16];

  undefined1 auVar41 [16];

  undefined1 auVar42 [16];

  undefined1 auVar43 [16];

  undefined1 auVar23 [64];

  undefined1 auVar24 [64];

  

  dVar19 = in_ZMM0._0_8_;

  auVar21 = in_ZMM0._0_16_;

  if (DAT_1403ff158 == 0) {

    dVar17 = ABS(dVar19);

    if ((ulonglong)DAT_14038c680 < (ulonglong)dVar17) {

      if ((ulonglong)DAT_14038c6e0 <= (ulonglong)dVar17) {

        dVar19 = (double)FUN_1402e9510();

        return dVar19;

      }

      if (DAT_14038c728 <= (double)((ulonglong)dVar19 & _DAT_14038c5c0)) {

        FUN_1402eda40();

      }

      uVar18 = (uint)(dVar17 != dVar19);

      dVar19 = (double)FUN_1402e58f0();

      if (uVar18 != 0) {

        dVar19 = (double)((ulonglong)dVar19 ^ _DAT_14038c5b0);

      }

      return dVar19;

    }

    if ((ulonglong)dVar17 < (ulonglong)DAT_14038c6d8) {

      if ((ulonglong)DAT_14038c6d0 <= (ulonglong)dVar17) {

        return dVar19 * dVar19 * dVar19 * _DAT_14038c5f0 + dVar19;

      }

    }

    else {

      dVar19 = (double)FUN_1402e58f0();

    }

    return dVar19;

  }

  dVar17 = ABS(dVar19);

  if ((ulonglong)dVar17 < (ulonglong)DAT_14038c680) {

    if ((ulonglong)DAT_14038c6f0 < (ulonglong)dVar17) {

      if (dVar19 < DAT_14038c700) {

        auVar21._8_8_ = 0;

        auVar21._0_8_ = DAT_14038c680 + dVar19 + DAT_14038c690;

        dVar20 = DAT_14038c710;

      }

      else {

        auVar21._8_8_ = 0;

        auVar21._0_8_ = (DAT_14038c680 - dVar19) + DAT_14038c690;

        dVar20 = DAT_14038c708;

      }

    }

    else {

      dVar20 = 0.0;

      if ((longlong)dVar17 < (longlong)DAT_14038c6d0) {

        return dVar19;

      }

    }

    auVar38._8_8_ = 0;

    auVar38._0_8_ = DAT_14038c660;

    auVar35._8_8_ = 0;

    auVar35._0_8_ = DAT_14038c620;

    dVar19 = auVar21._0_8_ * auVar21._0_8_;

    auVar1._8_8_ = 0;

    auVar1._0_8_ = DAT_14038c650;

    auVar27._8_8_ = 0;

    auVar27._0_8_ = dVar19;

    auVar22 = vfmadd213sd_fma(auVar38,auVar27,auVar1);

    auVar2._8_8_ = 0;

    auVar2._0_8_ = DAT_14038c610;

    auVar25 = vfmadd213sd_fma(auVar35,auVar27,auVar2);

    auVar3._8_8_ = 0;

    auVar3._0_8_ = DAT_14038c640;

    auVar28._8_8_ = 0;

    auVar28._0_8_ = dVar19;

    auVar22 = vfmadd213sd_fma(auVar22,auVar28,auVar3);

    auVar4._8_8_ = 0;

    auVar4._0_8_ = DAT_14038c600;

    auVar25 = vfmadd213sd_fma(auVar25,auVar28,auVar4);

    auVar5._8_8_ = 0;

    auVar5._0_8_ = DAT_14038c630;

    auVar22 = vfmadd213sd_fma(auVar22,auVar28,auVar5);

    auVar36._8_8_ = 0;

    auVar36._0_8_ = (auVar25._0_8_ / auVar22._0_8_) * dVar19;

    auVar21 = vfmadd132sd_fma(auVar21,auVar21,auVar36);

    dVar19 = auVar21._0_8_;

    if (dVar20 != DAT_14038c700) {

      auVar37._8_8_ = 0;

      auVar37._0_8_ = DAT_14038c708;

      auVar43._0_8_ = dVar19 / (dVar19 + DAT_14038c708);

      auVar43._8_8_ = auVar21._8_8_;

      auVar6._8_8_ = 0;

      auVar6._0_8_ = DAT_14038c718;

      auVar21 = vfnmadd231sd_fma(auVar37,auVar43,auVar6);

      dVar19 = auVar21._0_8_ * dVar20;

    }

    return dVar19;

  }

  if ((ulonglong)dVar17 < (ulonglong)DAT_14038c6e0) {

    if ((longlong)dVar17 < DAT_14038c730) {

      uVar16 = FUN_1402ecd60(dVar17);

      auVar25 = in_ZMM1._0_16_;

      auVar23._8_56_ = extraout_var;

      auVar23._0_8_ = extraout_XMM0_Qa;

      auVar22 = auVar23._0_16_;

    }

    else {

      uVar16 = FUN_1402ecb70();

      auVar25 = in_ZMM1._0_16_;

      auVar24._8_56_ = extraout_var_00;

      auVar24._0_8_ = extraout_XMM0_Qa_00;

      auVar22 = auVar24._0_16_;

    }

    dVar19 = 0.0;

    dVar17 = auVar22._0_8_;

    if (dVar17 <= DAT_14038c6f0) {

      if (dVar17 < DAT_14038c6f8) {

        auVar22._8_8_ = 0;

        auVar22._0_8_ = DAT_14038c680 + dVar17 + DAT_14038c690 + auVar25._0_8_;

        auVar25 = ZEXT816(0);

        dVar19 = DAT_14038c710;

      }

    }

    else {

      auVar22._8_8_ = 0;

      auVar22._0_8_ = (DAT_14038c680 - dVar17) + (DAT_14038c690 - auVar25._0_8_);

      auVar25 = ZEXT816(0);

      dVar19 = DAT_14038c708;

    }

    dVar20 = auVar22._0_8_;

    auVar7._8_8_ = 0;

    auVar7._0_8_ = DAT_14038c718;

    auVar29._8_8_ = 0;

    auVar29._0_8_ = dVar20 * dVar20;

    auVar42._8_8_ = 0;

    auVar42._0_8_ = auVar25._0_8_ * dVar20;

    auVar7 = vfmadd132sd_fma(auVar42,auVar29,auVar7);

    auVar30._8_8_ = 0;

    auVar30._0_8_ = DAT_14038c620;

    auVar8._8_8_ = 0;

    auVar8._0_8_ = DAT_14038c610;

    auVar8 = vfmadd213sd_fma(auVar30,auVar7,auVar8);

    auVar9._8_8_ = 0;

    auVar9._0_8_ = DAT_14038c600;

    auVar8 = vfmadd213sd_fma(auVar8,auVar7,auVar9);

    auVar39._8_8_ = 0;

    auVar39._0_8_ = DAT_14038c660;

    auVar10._8_8_ = 0;

    auVar10._0_8_ = DAT_14038c650;

    auVar9 = vfmadd213sd_fma(auVar39,auVar7,auVar10);

    auVar11._8_8_ = 0;

    auVar11._0_8_ = DAT_14038c640;

    auVar9 = vfmadd213sd_fma(auVar9,auVar7,auVar11);

    auVar12._8_8_ = 0;

    auVar12._0_8_ = DAT_14038c630;

    auVar9 = vfmadd213sd_fma(auVar9,auVar7,auVar12);

    auVar31._8_8_ = 0;

    auVar31._0_8_ = (auVar8._0_8_ / auVar9._0_8_) * auVar7._0_8_;

    auVar22 = vfmadd213sd_fma(auVar31,auVar22,auVar25);

    dVar17 = dVar20 + auVar22._0_8_;

    if (dVar19 == 0.0) {

      if ((uVar16 & 1) != 0) {

        auVar26._8_8_ = 0;

        auVar26._0_8_ = dVar17;

        auVar7 = vandpd_avx(auVar26,_DAT_14038c670);

        auVar34._0_8_ = DAT_14038c710 / dVar17;

        auVar34._8_8_ = 0;

        auVar8 = vandpd_avx(auVar34,_DAT_14038c670);

        auVar25._8_8_ = 0;

        auVar25._0_8_ = DAT_14038c708;

        auVar25 = vfmadd213sd_fma(auVar7,auVar8,auVar25);

        auVar41._8_8_ = 0;

        auVar41._0_8_ = auVar22._0_8_ - (auVar7._0_8_ - dVar20);

        auVar22 = vfmadd231sd_fma(auVar25,auVar41,auVar8);

        auVar22 = vfmadd213sd_fma(auVar22,auVar34,auVar8);

        dVar17 = auVar22._0_8_;

      }

    }

    else {

      auVar40._8_8_ = 0;

      auVar40._0_8_ = DAT_14038c708;

      if ((uVar16 & 1) == 0) {

        auVar32._0_8_ = dVar17 / (dVar17 + DAT_14038c708);

        auVar32._8_8_ = 0;

        auVar13._8_8_ = 0;

        auVar13._0_8_ = DAT_14038c718;

        auVar22 = vfnmadd132sd_fma(auVar32,auVar40,auVar13);

        dVar17 = auVar22._0_8_ * dVar19;

      }

      else {

        auVar33._0_8_ = dVar17 / (dVar17 - DAT_14038c708);

        auVar33._8_8_ = 0;

        auVar14._8_8_ = 0;

        auVar14._0_8_ = DAT_14038c718;

        auVar22 = vfmsub132sd_fma(auVar33,auVar40,auVar14);

        dVar17 = auVar22._0_8_ * dVar19;

      }

    }

    auVar15._8_8_ = _UNK_14038c5b8;

    auVar15._0_8_ = _DAT_14038c5b0;

    auVar21 = vandpd_avx(auVar21,auVar15);

    return (double)((ulonglong)dVar17 ^ auVar21._0_8_);

  }

  dVar19 = (double)FUN_1402e9510();

  return dVar19;

}




