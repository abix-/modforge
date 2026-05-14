// Address: 0x140190200
// Ghidra name: thunk_FUN_1402e3490
// ============ 0x140190200 thunk_FUN_1402e3490 (size=5) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



double thunk_FUN_1402e3490(void)



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

  undefined1 auVar16 [16];

  undefined1 auVar17 [16];

  undefined1 auVar18 [16];

  undefined1 auVar19 [16];

  undefined1 auVar20 [16];

  ulonglong uVar21;

  double dVar22;

  uint uVar23;

  double dVar24;

  double extraout_XMM0_Qa;

  undefined8 extraout_XMM0_Qa_01;

  undefined1 auVar25 [16];

  undefined1 in_ZMM0 [64];

  undefined1 extraout_var_00 [56];

  double dVar28;

  undefined1 auVar29 [16];

  undefined1 auVar30 [16];

  undefined1 in_ZMM1 [64];

  double dVar31;

  undefined1 auVar32 [16];

  undefined1 auVar33 [16];

  undefined1 auVar34 [16];

  undefined1 auVar35 [16];

  undefined1 auVar36 [16];

  undefined1 auVar37 [16];

  undefined1 auVar38 [16];

  undefined1 auVar39 [16];

  double dVar40;

  double dVar41;

  undefined1 auVar42 [16];

  undefined8 extraout_XMM0_Qa_00;

  undefined1 auVar26 [64];

  undefined1 auVar27 [64];

  undefined1 extraout_var [56];

  

  dVar24 = in_ZMM0._0_8_;

  if (DAT_1403ff158 != 0) {

    uVar21 = (ulonglong)dVar24 & _DAT_14038bd80;

    if ((longlong)DAT_14038bd68 < (longlong)uVar21) {

      if ((double)((ulonglong)dVar24 & (ulonglong)DAT_14038bd88) != DAT_14038bd88) {

        if (uVar21 < DAT_14038bd78) {

          uVar23 = FUN_1402ecd60(uVar21);

          auVar42 = in_ZMM1._0_16_;

          auVar26._8_56_ = extraout_var;

          auVar26._0_8_ = extraout_XMM0_Qa_00;

          auVar25 = auVar26._0_16_;

        }

        else {

          uVar23 = FUN_1402ecb70();

          auVar42 = in_ZMM1._0_16_;

          auVar27._8_56_ = extraout_var_00;

          auVar27._0_8_ = extraout_XMM0_Qa_01;

          auVar25 = auVar27._0_16_;

        }

        dVar24 = auVar25._0_8_;

        if ((uVar23 & 1) == 0) {

          dVar24 = dVar24 * dVar24;

          dVar22 = DAT_14038bd00 - dVar24 * DAT_14038bd48;

          auVar18._8_8_ = _UNK_1403916d8;

          auVar18._0_8_ = DAT_1403916d0;

          auVar32._8_8_ = 0;

          auVar32._0_8_ = (DAT_14038bd00 - dVar22) - dVar24 * DAT_14038bd48;

          auVar42 = vfnmadd231sd_fma(auVar32,auVar25,auVar42);

          auVar9._8_8_ = 0;

          auVar9._0_8_ = DAT_1403916e0;

          auVar37._8_8_ = 0;

          auVar37._0_8_ = dVar24;

          auVar25 = vfmadd231sd_fma(auVar18,auVar37,auVar9);

          auVar10._8_8_ = 0;

          auVar10._0_8_ = DAT_1403916c0;

          auVar25 = vfmadd213sd_fma(auVar25,auVar37,auVar10);

          auVar11._8_8_ = 0;

          auVar11._0_8_ = DAT_1403916b0;

          auVar25 = vfmadd213sd_fma(auVar25,auVar37,auVar11);

          auVar12._8_8_ = 0;

          auVar12._0_8_ = DAT_1403916a0;

          auVar25 = vfmadd213sd_fma(auVar25,auVar37,auVar12);

          auVar13._8_8_ = 0;

          auVar13._0_8_ = DAT_140391690;

          auVar25 = vfmadd213sd_fma(auVar25,auVar37,auVar13);

          auVar30._8_8_ = 0;

          auVar30._0_8_ = dVar24 * dVar24;

          auVar25 = vfmadd213sd_fma(auVar25,auVar30,auVar42);

          dVar22 = auVar25._0_8_ + dVar22;

        }

        else {

          auVar20._8_8_ = _UNK_140391738;

          auVar20._0_8_ = DAT_140391730;

          dVar22 = dVar24 * dVar24;

          auVar25._8_8_ = 0;

          auVar25._0_8_ = DAT_140391740;

          auVar38._8_8_ = 0;

          auVar38._0_8_ = dVar22;

          auVar25 = vfmadd231sd_fma(auVar20,auVar38,auVar25);

          auVar14._8_8_ = 0;

          auVar14._0_8_ = DAT_140391720;

          auVar25 = vfmadd213sd_fma(auVar25,auVar38,auVar14);

          auVar15._8_8_ = 0;

          auVar15._0_8_ = DAT_140391710;

          auVar39._8_8_ = 0;

          auVar39._0_8_ = dVar22;

          auVar25 = vfmadd213sd_fma(auVar25,auVar39,auVar15);

          auVar16._8_8_ = 0;

          auVar16._0_8_ = DAT_140391700;

          auVar25 = vfmadd213sd_fma(auVar25,auVar39,auVar16);

          auVar17._8_8_ = 0;

          auVar17._0_8_ = DAT_1403916f0;

          auVar33._8_8_ = 0;

          auVar33._0_8_ =

               dVar22 * (auVar42._0_8_ * DAT_14038bd48 - dVar24 * dVar22 * auVar25._0_8_) -

               auVar42._0_8_;

          auVar42._8_8_ = 0;

          auVar42._0_8_ = dVar24 * dVar22;

          auVar25 = vfnmadd231sd_fma(auVar33,auVar42,auVar17);

          dVar22 = dVar24 - auVar25._0_8_;

        }

        uVar21 = 0;

        if ((uVar23 + 1 & 2) != 0) {

          uVar21 = DAT_14038bd10;

        }

        return (double)((ulonglong)dVar22 ^ uVar21);

      }

      dVar24 = (double)FUN_1402e9300();

      return dVar24;

    }

    if ((longlong)uVar21 < (longlong)DAT_14038bd60) {

      if ((longlong)uVar21 < (longlong)DAT_14038bd58) {

        return DAT_14038bd00;

      }

      auVar1._8_8_ = 0;

      auVar1._0_8_ = DAT_14038bd00;

      auVar29._8_8_ = 0;

      auVar29._0_8_ = dVar24 * DAT_14038bd48;

      auVar25 = vfnmadd213sd_fma(in_ZMM0._0_16_,auVar29,auVar1);

      return auVar25._0_8_;

    }

    dVar24 = dVar24 * dVar24;

    auVar19._8_8_ = _UNK_1403916e8;

    auVar19._0_8_ = DAT_1403916e0;

    auVar2._8_8_ = 0;

    auVar2._0_8_ = DAT_1403916d0;

    auVar34._8_8_ = 0;

    auVar34._0_8_ = dVar24;

    auVar25 = vfmadd213sd_fma(auVar19,auVar34,auVar2);

    auVar3._8_8_ = 0;

    auVar3._0_8_ = DAT_1403916c0;

    auVar25 = vfmadd213sd_fma(auVar25,auVar34,auVar3);

    auVar4._8_8_ = 0;

    auVar4._0_8_ = DAT_1403916b0;

    auVar35._8_8_ = 0;

    auVar35._0_8_ = dVar24;

    auVar25 = vfmadd213sd_fma(auVar25,auVar35,auVar4);

    auVar5._8_8_ = 0;

    auVar5._0_8_ = DAT_1403916a0;

    auVar25 = vfmadd213sd_fma(auVar25,auVar35,auVar5);

    auVar6._8_8_ = 0;

    auVar6._0_8_ = DAT_140391690;

    auVar25 = vfmadd213sd_fma(auVar25,auVar35,auVar6);

    auVar7._8_8_ = 0;

    auVar7._0_8_ = DAT_14038bd48;

    auVar25 = vfmsub213sd_fma(auVar25,auVar35,auVar7);

    auVar8._8_8_ = 0;

    auVar8._0_8_ = DAT_14038bd00;

    auVar36._8_8_ = 0;

    auVar36._0_8_ = dVar24;

    auVar25 = vfmadd213sd_fma(auVar25,auVar36,auVar8);

    return auVar25._0_8_;

  }

  dVar22 = ABS(dVar24);

  if ((ulonglong)DAT_14038bd68 <= (ulonglong)dVar22) {

    if ((ulonglong)dVar22 < (ulonglong)DAT_14038bd70) {

      uVar23 = (uint)(dVar22 * _DAT_14038bd40 + DAT_14038bd48);

      dVar31 = (double)(int)uVar23;

      dVar40 = dVar22 - DAT_14038bcc0 * dVar31;

      dVar28 = DAT_14038bcd0 * dVar31;

      dVar24 = dVar40 - dVar28;

      dVar41 = dVar40;

      if (0xf < (longlong)(((ulonglong)dVar22 >> 0x34) - ((ulonglong)ABS(dVar24) >> 0x34))) {

        dVar41 = dVar40 - DAT_14038bce0 * dVar31;

        dVar28 = DAT_14038bcf0 * dVar31 - ((dVar40 - dVar41) - DAT_14038bce0 * dVar31);

        dVar24 = dVar41 - dVar28;

      }

      dVar28 = (dVar41 - dVar24) - dVar28;

    }

    else {

      if ((ulonglong)DAT_14038bd88 <= (ulonglong)dVar22) {

        dVar24 = (double)FUN_1402e9300();

        return dVar24;

      }

      uVar23 = FUN_1402eda40();

      dVar28 = in_ZMM1._0_8_;

      dVar24 = extraout_XMM0_Qa;

    }

    dVar22 = dVar24 * dVar24;

    if ((uVar23 & 1) == 0) {

      dVar24 = (((DAT_1403916b0 * dVar22 + DAT_1403916a0) * dVar22 + DAT_140391690 +

                ((DAT_1403916e0 * dVar22 + DAT_1403916d0) * dVar22 + DAT_1403916c0) *

                dVar22 * dVar22 * dVar22) * dVar22 * dVar22 +

               ((((DAT_14038bd48 * dVar22 - DAT_14038bd00) + DAT_14038bd00) - dVar22 * DAT_14038bd48

                ) - dVar28 * dVar24)) - (dVar22 * DAT_14038bd48 - DAT_14038bd00);

    }

    else {

      dVar24 = dVar28 + (dVar24 * dVar22 *

                         (((DAT_140391740 * dVar22 + DAT_140391730) * dVar22 + DAT_140391720) *

                          dVar22 * dVar22 * dVar22 +

                         (DAT_140391710 * dVar22 + DAT_140391700) * dVar22 + DAT_1403916f0) -

                        dVar22 * DAT_14038bd48 * dVar28) + dVar24;

    }

    if ((uVar23 + 1 & 2) != 0) {

      dVar24 = 0.0 - dVar24;

    }

    return dVar24;

  }

  if ((ulonglong)DAT_14038bd60 <= (ulonglong)dVar22) {

    dVar24 = dVar24 * dVar24;

    dVar28 = dVar24 * dVar24;

    dVar22 = dVar24 * _DAT_14038bd50 + DAT_14038bd00;

    return (DAT_14038bd00 - dVar22) + dVar24 * _DAT_14038bd50 +

           (DAT_1403916a0 * dVar24 + DAT_140391690) * dVar28 +

           (DAT_1403916c0 * dVar24 + DAT_1403916b0) * dVar28 * dVar28 +

           dVar28 * dVar28 * dVar28 * (DAT_1403916e0 * dVar24 + DAT_1403916d0) + dVar22;

  }

  if ((ulonglong)DAT_14038bd58 <= (ulonglong)dVar22) {

    return DAT_14038bd00 - dVar24 * dVar24 * DAT_14038bd48;

  }

  return DAT_14038bd00;

}




