// Address: 0x1402f25f0
// Ghidra name: FUN_1402f25f0
// ============ 0x1402f25f0 FUN_1402f25f0 (size=534) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



double FUN_1402f25f0(void)



{

  undefined1 auVar1 [16];

  undefined1 auVar2 [16];

  undefined1 auVar3 [16];

  undefined1 auVar4 [16];

  undefined1 auVar5 [16];

  undefined1 auVar6 [16];

  undefined1 auVar7 [16];

  undefined1 auVar8 [16];

  double dVar9;

  undefined1 auVar10 [16];

  ulonglong uVar11;

  bool bVar12;

  double dVar13;

  double dVar14;

  undefined1 auVar15 [16];

  undefined1 in_ZMM0 [64];

  undefined1 auVar16 [16];

  undefined1 auVar17 [16];

  undefined1 auVar18 [16];

  undefined1 auVar19 [16];

  undefined1 auVar20 [16];

  undefined1 auVar21 [16];

  ulonglong uVar22;

  double dVar23;

  

  auVar15 = in_ZMM0._0_16_;

  uVar22 = in_ZMM0._0_8_;

  uVar11 = uVar22 & 0x7fffffffffffffff;

  bVar12 = uVar22 != uVar11;

  if (bVar12) {

    auVar15._0_8_ = uVar22 ^ DAT_140305470;

    auVar15._8_8_ = in_ZMM0._8_8_ ^ _UNK_140305478;

  }

  dVar13 = auVar15._0_8_;

  if (uVar11 < 0x4003800000000001) {

    if (uVar11 < 0x3ff3000000000001) {

      if (uVar11 < 0x3fe6000000000001) {

        if (uVar11 < 0x3fdc000000000001) {

          dVar14 = 0.0;

          dVar23 = 0.0;

        }

        else {

          dVar13 = ((dVar13 + dVar13) - DAT_140304b90) / (dVar13 + DAT_14030ec18);

          dVar23 = DAT_14038ac80;

          dVar14 = DAT_14038acd0;

        }

      }

      else {

        dVar13 = (dVar13 - DAT_140304b90) / (dVar13 + DAT_140304b90);

        dVar23 = DAT_14038ac88;

        dVar14 = DAT_14038ac58;

      }

    }

    else {

      auVar16._8_8_ = 0;

      auVar16._0_8_ = DAT_140304b98;

      auVar10._8_8_ = 0;

      auVar10._0_8_ = DAT_140304b90;

      auVar15 = vfmadd213sd_fma(auVar16,auVar15,auVar10);

      dVar13 = (dVar13 - DAT_140304b98) / auVar15._0_8_;

      dVar23 = DAT_14038ac78;

      dVar14 = DAT_14038ace0;

    }

  }

  else {

    if (0x7ff0000000000000 < uVar11) {

      dVar13 = (double)FUN_1402f56e0(0);

      return dVar13;

    }

    if (DAT_14038acf8 < dVar13) {

      if (bVar12) {

        FUN_1402e8cc0(0x20);

        return DAT_14038ac60;

      }

      FUN_1402e8cc0(0x20);

      return DAT_140388af0;

    }

    dVar13 = DAT_140388e08 / dVar13;

    dVar23 = DAT_14038ac90;

    dVar14 = DAT_140388af0;

  }

  auVar17._8_8_ = 0;

  auVar17._0_8_ = DAT_14038ac98;

  dVar9 = dVar13 * dVar13;

  auVar1._8_8_ = 0;

  auVar1._0_8_ = DAT_14038aca0;

  auVar19._8_8_ = 0;

  auVar19._0_8_ = dVar9;

  auVar15 = vfmadd213sd_fma(auVar17,auVar19,auVar1);

  auVar2._8_8_ = 0;

  auVar2._0_8_ = DAT_14038acb0;

  auVar15 = vfmadd213sd_fma(auVar15,auVar19,auVar2);

  auVar3._8_8_ = 0;

  auVar3._0_8_ = DAT_14038acc8;

  auVar20._8_8_ = 0;

  auVar20._0_8_ = dVar9;

  auVar15 = vfmadd213sd_fma(auVar15,auVar20,auVar3);

  auVar4._8_8_ = 0;

  auVar4._0_8_ = DAT_14038acb8;

  auVar15 = vfmadd213sd_fma(auVar15,auVar20,auVar4);

  auVar18._8_8_ = 0;

  auVar18._0_8_ = DAT_14038aca8;

  auVar5._8_8_ = 0;

  auVar5._0_8_ = DAT_14038acc0;

  auVar10 = vfmadd213sd_fma(auVar18,auVar20,auVar5);

  auVar6._8_8_ = 0;

  auVar6._0_8_ = DAT_14038ace8;

  auVar10 = vfmadd213sd_fma(auVar10,auVar20,auVar6);

  auVar7._8_8_ = 0;

  auVar7._0_8_ = DAT_14038acf0;

  auVar21._8_8_ = 0;

  auVar21._0_8_ = dVar9;

  auVar10 = vfmadd213sd_fma(auVar10,auVar21,auVar7);

  auVar8._8_8_ = 0;

  auVar8._0_8_ = DAT_14038acd8;

  auVar10 = vfmadd213sd_fma(auVar10,auVar21,auVar8);

  dVar14 = dVar14 - (((auVar15._0_8_ * dVar9 * dVar13) / auVar10._0_8_ - dVar23) - dVar13);

  if (bVar12) {

    dVar14 = (double)((ulonglong)dVar14 ^ DAT_140305470);

  }

  return dVar14;

}




