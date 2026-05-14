// Address: 0x1402f1ca0
// Ghidra name: FUN_1402f1ca0
// ============ 0x1402f1ca0 FUN_1402f1ca0 (size=628) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



double FUN_1402f1ca0(void)



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

  double dVar12;

  uint uVar13;

  double dVar14;

  undefined1 auVar15 [16];

  undefined1 auVar16 [16];

  undefined1 in_ZMM0 [64];

  undefined1 auVar17 [16];

  undefined1 auVar18 [16];

  undefined1 auVar19 [16];

  undefined1 auVar20 [16];

  undefined1 auVar21 [16];

  undefined1 auVar22 [16];

  undefined1 auVar23 [16];

  double dVar24;

  undefined1 auVar25 [16];

  undefined1 auVar26 [16];

  

  dVar12 = in_ZMM0._0_8_;

  uVar13 = in_ZMM0._4_4_ >> 0x14 & 0x7ff;

  dVar14 = 0.0;

  if (0x7ff0000000000000 < (ulonglong)ABS(dVar12)) {

    dVar14 = (double)FUN_1402f56e0(dVar12,0,dVar12);

    return dVar14;

  }

  if (uVar13 < 0x3c7) {

    FUN_1402e8cc0(0x20);

    return DAT_140388af0;

  }

  if (uVar13 < 0x3ff) {

    auVar25 = in_ZMM0._0_16_;

    if ((longlong)dVar12 < 0) {

      auVar25._0_8_ = (ulonglong)dVar12 ^ DAT_140305470;

      auVar25._8_8_ = in_ZMM0._8_8_ ^ _UNK_140305478;

    }

    dVar24 = auVar25._0_8_;

    if (uVar13 < 0x3fe) {

      dVar24 = dVar24 * dVar24;

    }

    else {

      dVar24 = (DAT_140304b90 - dVar24) * DAT_140304b70;

      auVar18._8_8_ = 0;

      auVar18._0_8_ = dVar24;

      auVar25 = vsqrtsd_avx(auVar18,auVar18);

      dVar14 = auVar25._0_8_;

    }

    auVar15._8_8_ = 0;

    auVar15._0_8_ = DAT_14038abd8;

    auVar1._8_8_ = 0;

    auVar1._0_8_ = DAT_14038abe0;

    auVar19._8_8_ = 0;

    auVar19._0_8_ = dVar24;

    auVar18 = vfmadd213sd_fma(auVar15,auVar19,auVar1);

    auVar2._8_8_ = 0;

    auVar2._0_8_ = DAT_14038abe8;

    auVar18 = vfmsub213sd_fma(auVar18,auVar19,auVar2);

    auVar3._8_8_ = 0;

    auVar3._0_8_ = DAT_14038ac00;

    auVar20._8_8_ = 0;

    auVar20._0_8_ = dVar24;

    auVar18 = vfmadd213sd_fma(auVar18,auVar20,auVar3);

    auVar4._8_8_ = 0;

    auVar4._0_8_ = DAT_14038ac08;

    auVar18 = vfmsub213sd_fma(auVar18,auVar20,auVar4);

    auVar5._8_8_ = 0;

    auVar5._0_8_ = DAT_14038abf8;

    auVar18 = vfmadd213sd_fma(auVar18,auVar20,auVar5);

    auVar16._8_8_ = 0;

    auVar16._0_8_ = DAT_14038abf0;

    auVar6._8_8_ = 0;

    auVar6._0_8_ = DAT_14038ac10;

    auVar1 = vfmsub213sd_fma(auVar16,auVar20,auVar6);

    auVar7._8_8_ = 0;

    auVar7._0_8_ = DAT_14038ac20;

    auVar21._8_8_ = 0;

    auVar21._0_8_ = dVar24;

    auVar1 = vfmadd213sd_fma(auVar1,auVar21,auVar7);

    auVar8._8_8_ = 0;

    auVar8._0_8_ = DAT_14038ac28;

    auVar1 = vfmsub213sd_fma(auVar1,auVar21,auVar8);

    auVar9._8_8_ = 0;

    auVar9._0_8_ = DAT_14038ac18;

    auVar1 = vfmadd213sd_fma(auVar1,auVar21,auVar9);

    auVar26._0_8_ = (auVar18._0_8_ * dVar24) / auVar1._0_8_;

    auVar26._8_8_ = 0;

    if (uVar13 >= 0x3fe) {

      if ((longlong)dVar12 < 0) {

        auVar10._8_8_ = 0;

        auVar10._0_8_ = DAT_14038abd0;

        auVar25 = vfmsub213sd_fma(auVar26,auVar25,auVar10);

        dVar14 = auVar25._0_8_ + dVar14;

        return DAT_140333080 - (dVar14 + dVar14);

      }

      dVar12 = (double)((ulonglong)dVar14 & 0xffffffff00000000);

      auVar23._8_8_ = 0;

      auVar23._0_8_ = dVar12;

      auVar18 = vfnmadd231sd_fma(auVar21,auVar23,auVar23);

      dVar14 = auVar18._0_8_ / (dVar12 + dVar14);

      auVar17._8_8_ = 0;

      auVar17._0_8_ = auVar25._0_8_ + auVar25._0_8_;

      auVar22._8_8_ = 0;

      auVar22._0_8_ = dVar14 + dVar14;

      auVar25 = vfmadd231sd_fma(auVar22,auVar26,auVar17);

      return auVar25._0_8_ + dVar12 + dVar12;

    }

    auVar11._8_8_ = 0;

    auVar11._0_8_ = DAT_14038abd0;

    auVar25 = vfnmadd213sd_fma(in_ZMM0._0_16_,auVar26,auVar11);

    return DAT_140388af0 - (dVar12 - auVar25._0_8_);

  }

  if (dVar12 == DAT_140304b90) {

    return 0.0;

  }

  if (dVar12 == DAT_140388e08) {

    FUN_1402e8cc0(0x20);

    return DAT_140333080;

  }

  dVar14 = (double)FUN_1402e8e00(&DAT_14038abc8,0xd,0xfff8000000000000,1,8,0x21);

  return dVar14;

}




