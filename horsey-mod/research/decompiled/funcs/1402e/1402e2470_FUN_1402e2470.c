// Address: 0x1402e2470
// Ghidra name: FUN_1402e2470
// ============ 0x1402e2470 FUN_1402e2470 (size=22) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



double FUN_1402e2470(void)



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

  double dVar10;

  uint uVar11;

  double dVar12;

  undefined1 auVar13 [16];

  undefined1 auVar14 [16];

  undefined1 auVar15 [16];

  undefined1 auVar16 [16];

  undefined1 in_ZMM0 [64];

  double dVar17;

  undefined1 auVar18 [16];

  undefined1 auVar19 [16];

  undefined1 auVar20 [16];

  undefined1 auVar21 [16];

  undefined1 auVar22 [16];

  undefined1 auVar23 [16];

  double dVar24;

  undefined1 auVar25 [64];

  undefined1 auVar26 [16];

  

  if (((byte)DAT_1403ff158 & 3) != 3) {

    dVar12 = (double)FUN_1402e2490();

    return dVar12;

  }

  auVar13 = in_ZMM0._0_16_;

  auVar25 = ZEXT1664(auVar13);

  dVar24 = in_ZMM0._0_8_;

  uVar11 = in_ZMM0._4_4_ >> 0x14 & 0x7ff;

  dVar12 = 0.0;

  if (0x7ff0000000000000 < (ulonglong)ABS(dVar24)) {

    dVar12 = (double)FUN_1402f56e0(0);

    return dVar12;

  }

  if (uVar11 < 0x3e3) {

    FUN_1402e8cc0(0x20);

    return auVar25._0_8_;

  }

  if (0x3fe < uVar11) {

    if (dVar24 == DAT_140304b90) {

      FUN_1402e8cc0(0x20);

      return DAT_140388af0;

    }

    if (dVar24 != DAT_140388e08) {

      dVar12 = (double)FUN_1402e8e00(&DAT_14038ac50,0xe,0xfff8000000000000,1,8,0x21);

      return dVar12;

    }

    FUN_1402e8cc0(0x20);

    return DAT_14038ac60;

  }

  if ((longlong)dVar24 < 0) {

    auVar13._0_8_ = (ulonglong)dVar24 ^ DAT_140305470;

    auVar13._8_8_ = in_ZMM0._8_8_ ^ _UNK_140305478;

  }

  dVar10 = auVar13._0_8_;

  if (uVar11 < 0x3fe) {

    dVar10 = dVar10 * dVar10;

  }

  else {

    dVar10 = (DAT_140304b90 - dVar10) * DAT_140304b70;

    auVar18._8_8_ = 0;

    auVar18._0_8_ = dVar10;

    auVar13 = vsqrtsd_avx(auVar18,auVar18);

    dVar12 = auVar13._0_8_;

  }

  auVar14._8_8_ = 0;

  auVar14._0_8_ = DAT_14038abd8;

  auVar1._8_8_ = 0;

  auVar1._0_8_ = DAT_14038abe0;

  auVar19._8_8_ = 0;

  auVar19._0_8_ = dVar10;

  auVar18 = vfmadd213sd_fma(auVar14,auVar19,auVar1);

  auVar2._8_8_ = 0;

  auVar2._0_8_ = DAT_14038abe8;

  auVar18 = vfmsub213sd_fma(auVar18,auVar19,auVar2);

  auVar3._8_8_ = 0;

  auVar3._0_8_ = DAT_14038ac00;

  auVar20._8_8_ = 0;

  auVar20._0_8_ = dVar10;

  auVar18 = vfmadd213sd_fma(auVar18,auVar20,auVar3);

  auVar4._8_8_ = 0;

  auVar4._0_8_ = DAT_14038ac08;

  auVar18 = vfmsub213sd_fma(auVar18,auVar20,auVar4);

  auVar5._8_8_ = 0;

  auVar5._0_8_ = DAT_14038abf8;

  auVar18 = vfmadd213sd_fma(auVar18,auVar20,auVar5);

  auVar15._8_8_ = 0;

  auVar15._0_8_ = DAT_14038abf0;

  auVar6._8_8_ = 0;

  auVar6._0_8_ = DAT_14038ac10;

  auVar1 = vfmsub213sd_fma(auVar15,auVar20,auVar6);

  auVar7._8_8_ = 0;

  auVar7._0_8_ = DAT_14038ac20;

  auVar21._8_8_ = 0;

  auVar21._0_8_ = dVar10;

  auVar1 = vfmadd213sd_fma(auVar1,auVar21,auVar7);

  auVar8._8_8_ = 0;

  auVar8._0_8_ = DAT_14038ac28;

  auVar1 = vfmsub213sd_fma(auVar1,auVar21,auVar8);

  auVar9._8_8_ = 0;

  auVar9._0_8_ = DAT_14038ac18;

  auVar1 = vfmadd213sd_fma(auVar1,auVar21,auVar9);

  auVar26._0_8_ = (auVar18._0_8_ * dVar10) / auVar1._0_8_;

  auVar26._8_8_ = 0;

  if (uVar11 < 0x3fe) {

    auVar13 = vfmadd231sd_fma(auVar13,auVar26,auVar13);

    dVar12 = auVar13._0_8_;

  }

  else {

    dVar10 = (double)((ulonglong)dVar12 & 0xffffffff00000000);

    auVar23._8_8_ = 0;

    auVar23._0_8_ = dVar10;

    auVar13 = vfnmadd231sd_fma(auVar21,auVar23,auVar23);

    dVar17 = auVar13._0_8_ / (dVar10 + dVar12);

    auVar16._8_8_ = 0;

    auVar16._0_8_ = dVar12 + dVar12;

    auVar22._8_8_ = 0;

    auVar22._0_8_ = DAT_14038abd0 - (dVar17 + dVar17);

    auVar13 = vfmsub231sd_fma(auVar22,auVar26,auVar16);

    dVar12 = DAT_14038ac58 - (auVar13._0_8_ - (DAT_14038ac58 - (dVar10 + dVar10)));

  }

  if ((longlong)dVar24 < 0) {

    dVar12 = (double)((ulonglong)dVar12 ^ DAT_140305470);

  }

  return dVar12;

}




