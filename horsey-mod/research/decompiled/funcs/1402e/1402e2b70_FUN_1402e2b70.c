// Address: 0x1402e2b70
// Ghidra name: FUN_1402e2b70
// ============ 0x1402e2b70 FUN_1402e2b70 (size=22) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



double FUN_1402e2b70(undefined8 param_1,undefined8 param_2)



{

  undefined1 auVar1 [16];

  undefined1 auVar2 [16];

  undefined1 auVar3 [16];

  undefined1 auVar4 [16];

  undefined1 auVar5 [16];

  undefined1 auVar6 [16];

  bool bVar7;

  double dVar8;

  double dVar9;

  uint uVar10;

  int iVar11;

  double dVar12;

  int iVar13;

  ulonglong uVar14;

  uint uVar15;

  double dVar16;

  undefined1 auVar17 [16];

  undefined1 auVar18 [16];

  undefined1 auVar19 [16];

  undefined1 auVar20 [16];

  undefined1 auVar21 [16];

  undefined1 auVar22 [16];

  undefined1 auVar23 [16];

  undefined1 in_ZMM0 [64];

  ulonglong uVar24;

  undefined1 auVar25 [16];

  undefined1 auVar26 [16];

  undefined1 auVar27 [16];

  undefined1 auVar28 [16];

  undefined1 auVar29 [16];

  undefined1 in_ZMM1 [64];

  double dVar30;

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

  undefined1 auVar44 [16];

  ulonglong uVar46;

  undefined1 auVar45 [64];

  undefined1 auVar47 [16];

  undefined1 auVar48 [64];

  

  if (((byte)DAT_1403ff158 & 3) != 3) {

    auVar41._0_8_ = (double)FUN_1402e2b90();

    return auVar41._0_8_;

  }

  uVar24 = in_ZMM1._0_8_;

  dVar16 = in_ZMM0._0_8_;

  uVar15 = in_ZMM0._4_4_ >> 0x14 & 0x7ff;

  uVar10 = in_ZMM1._4_4_ >> 0x14 & 0x7ff;

  iVar11 = uVar15 - uVar10;

  uVar14 = uVar24 & 0x7fffffffffffffff;

  auVar41._0_8_ = ABS(dVar16);

  auVar25 = in_ZMM1._0_16_;

  auVar48 = ZEXT1664(auVar25);

  auVar17 = in_ZMM0._0_16_;

  auVar45 = ZEXT1664(auVar17);

  if (0x7ff0000000000000 < uVar14) {

    auVar41._0_8_ = (double)FUN_1402f56e0(uVar24,param_2,0);

    return auVar41._0_8_;

  }

  if (0x7ff0000000000000 < (ulonglong)auVar41._0_8_) {

    auVar41._0_8_ = (double)FUN_1402f56e0(dVar16,param_2,0);

    return auVar41._0_8_;

  }

  if (auVar41._0_8_ == 0.0) {

    if (-1 < (longlong)uVar24) {

      return dVar16;

    }

  }

  else {

    if (uVar14 == 0) {

      FUN_1402e8cc0();

      auVar17 = auVar45._0_16_;

      auVar25 = auVar48._0_16_;

      if ((longlong)dVar16 < 0) {

        return DAT_14038ac60;

      }

    }

    if ((uVar10 < 0x3fd) && (uVar15 < 0x3fd)) {

      if ((uVar24 & 0x7ff0000000000000) == 0) {

        if ((longlong)uVar24 < 0) {

          dVar30 = (double)(uVar24 | 0x4010000000000000) + DAT_14038bc58;

        }

        else {

          dVar30 = (double)(uVar24 | 0x4010000000000000) + DAT_14038bc80;

        }

      }

      else {

        dVar30 = (double)(uVar24 + 0x4000000000000000);

      }

      if (((ulonglong)dVar16 & 0x7ff0000000000000) == 0) {

        if ((longlong)dVar16 < 0) {

          dVar12 = (double)((ulonglong)dVar16 | 0x4010000000000000) + DAT_14038bc58;

        }

        else {

          dVar12 = (double)((ulonglong)dVar16 | 0x4010000000000000) + DAT_14038bc80;

        }

      }

      else {

        dVar12 = (double)((longlong)dVar16 + 0x4000000000000000);

      }

      auVar17._8_8_ = 0;

      auVar17._0_8_ = (ulonglong)dVar12;

      auVar25._8_8_ = 0;

      auVar25._0_8_ = dVar30;

      iVar11 = ((uint)((ulonglong)dVar12 >> 0x34) & 0x7ff) -

               ((uint)((ulonglong)dVar30 >> 0x34) & 0x7ff);

    }

    if (0x38 < iVar11) {

      FUN_1402e8cc0(0x20);

      if ((longlong)dVar16 < 0) {

        return DAT_14038ac60;

      }

      return DAT_140388af0;

    }

    dVar30 = auVar25._0_8_;

    dVar12 = auVar17._0_8_;

    uVar46 = auVar17._8_8_;

    if ((iVar11 < -0x1c) && (-1 < (longlong)uVar24)) {

      if (iVar11 < -0x432) {

        FUN_1402e8cc0(0x20);

        if ((longlong)dVar16 < 0) {

          return DAT_14038bc60;

        }

        return 0.0;

      }

      if (-0x3ff < iVar11) {

        return dVar12 / dVar30;

      }

      dVar30 = (dVar12 * 1.2676506002282294e+30) / dVar30;

      uVar14 = (ulonglong)ABS(dVar30) >> 0x34;

      uVar10 = (uint)((ulonglong)ABS(dVar30) >> 0x34);

      if (uVar10 < 0x65) {

        if ((int)(0x65 - uVar10) < 0x37) {

          uVar14 = ((ulonglong)dVar30 & 0x1fffffffffffff | 0x10000000000000) >>

                   (100 - uVar14 & 0x3f);

          uVar14 = (uVar14 >> 1) + (ulonglong)((uint)uVar14 & 1);

        }

        else {

          uVar14 = 0;

        }

      }

      else {

        uVar14 = uVar14 - 100 << 0x34 | (ulonglong)dVar30 & 0xfffffffffffff;

      }

      auVar41._0_8_ = (double)((ulonglong)dVar30 & 0x8000000000000000 | uVar14);

      if ((uVar14 & 0x7ff0000000000000) != 0) {

        return auVar41._0_8_;

      }

      FUN_1402e8cc0(0x20);

      return auVar41._0_8_;

    }

    if ((-0x39 < iVar11) || (-1 < (longlong)uVar24)) {

      if ((auVar41._0_8_ != INFINITY) || (uVar14 != 0x7ff0000000000000)) {

        auVar47 = auVar25;

        if ((longlong)uVar24 < 0) {

          auVar47._0_8_ = (ulonglong)dVar30 ^ DAT_140305470;

          auVar47._8_8_ = auVar25._8_8_ ^ _UNK_140305478;

        }

        if ((longlong)dVar16 < 0) {

          auVar17._0_8_ = (ulonglong)dVar12 ^ DAT_140305470;

          auVar17._8_8_ = uVar46 ^ _UNK_140305478;

        }

        bVar7 = auVar47._0_8_ < auVar17._0_8_;

        auVar31._0_8_ = -(ulonglong)!bVar7;

        auVar31._8_8_ = 0xffffffffffffffff;

        auVar25 = vblendvpd_avx(auVar47,auVar17,auVar31);

        auVar32._0_8_ = -(ulonglong)!bVar7;

        auVar32._8_8_ = 0xffffffffffffffff;

        auVar17 = vblendvpd_avx(auVar17,auVar47,auVar32);

        dVar30 = auVar17._0_8_;

        auVar41._0_8_ = auVar25._0_8_ / dVar30;

        auVar41._8_8_ = auVar25._8_8_;

        if (auVar41._0_8_ <= DAT_14030d9a0) {

          dVar12 = 0.0;

          if (DAT_14038bc18 <= auVar41._0_8_) {

            dVar8 = auVar41._0_8_ * auVar41._0_8_;

            auVar27._8_8_ = 0;

            auVar27._0_8_ = (ulonglong)auVar41._0_8_ & 0xffffffff00000000;

            auVar35._8_8_ = 0;

            auVar35._0_8_ = (ulonglong)dVar30 & 0xffffffff00000000;

            auVar25 = vfnmadd231sd_fma(auVar25,auVar35,auVar27);

            auVar22._8_8_ = 0;

            auVar22._0_8_ = dVar30 - (double)((ulonglong)dVar30 & 0xffffffff00000000);

            auVar25 = vfnmadd231sd_fma(auVar25,auVar27,auVar22);

            auVar28._8_8_ = 0;

            auVar28._0_8_ = auVar41._0_8_ - (double)((ulonglong)auVar41._0_8_ & 0xffffffff00000000);

            auVar25 = vfnmadd231sd_fma(auVar25,auVar17,auVar28);

            auVar29._8_8_ = 0;

            auVar29._0_8_ = DAT_14038bc30;

            auVar3._8_8_ = 0;

            auVar3._0_8_ = DAT_14038bc38;

            auVar39._8_8_ = 0;

            auVar39._0_8_ = dVar8;

            auVar17 = vfnmadd213sd_fma(auVar29,auVar39,auVar3);

            auVar4._8_8_ = 0;

            auVar4._0_8_ = DAT_140388ad0;

            auVar17 = vfnmadd213sd_fma(auVar17,auVar39,auVar4);

            auVar5._8_8_ = 0;

            auVar5._0_8_ = DAT_140388ad8;

            auVar40._8_8_ = 0;

            auVar40._0_8_ = dVar8;

            auVar17 = vfnmadd213sd_fma(auVar17,auVar40,auVar5);

            auVar6._8_8_ = 0;

            auVar6._0_8_ = DAT_140388ae8;

            auVar17 = vfnmadd213sd_fma(auVar17,auVar40,auVar6);

            auVar36._0_8_ = auVar25._0_8_ / dVar30;

            auVar36._8_8_ = auVar25._8_8_;

            auVar23._8_8_ = 0;

            auVar23._0_8_ = dVar8 * auVar41._0_8_;

            auVar17 = vfnmadd231sd_fma(auVar36,auVar23,auVar17);

            auVar41._0_8_ = auVar17._0_8_ + auVar41._0_8_;

          }

        }

        else {

          auVar18._8_8_ = 0;

          auVar18._0_8_ = DAT_140388b00;

          auVar1._8_8_ = 0;

          auVar1._0_8_ = DAT_140304b70;

          auVar41 = vfmadd213sd_fma(auVar18,auVar41,auVar1);

          uVar10 = (int)auVar41._0_8_ - 0x10;

          dVar12 = *(double *)(&DAT_140392240 + (ulonglong)uVar10 * 8);

          auVar41._0_8_ = (double)(uint)(int)auVar41._0_8_ * DAT_14038bc28;

          iVar13 = 0x3ff - (auVar17._4_4_ >> 0x14 & 0x7ff);

          iVar11 = iVar13 / 2;

          dVar9 = (double)((longlong)iVar11 + 0x3ff << 0x34);

          dVar8 = (double)((longlong)(iVar13 - iVar11) + 0x3ff << 0x34);

          dVar30 = dVar30 * dVar9 * dVar8;

          auVar33._8_8_ = 0;

          auVar33._0_8_ = auVar25._0_8_ * dVar9 * dVar8;

          auVar26._8_8_ = 0;

          auVar26._0_8_ = (ulonglong)dVar30 & 0xfffffffff8000000;

          auVar42._8_8_ = 0;

          auVar42._0_8_ = auVar41._0_8_;

          auVar17 = vfnmadd231sd_fma(auVar33,auVar26,auVar42);

          auVar19._8_8_ = 0;

          auVar19._0_8_ = dVar30 - (double)((ulonglong)dVar30 & 0xfffffffff8000000);

          auVar17 = vfnmadd231sd_fma(auVar17,auVar42,auVar19);

          auVar20._8_8_ = 0;

          auVar20._0_8_ = DAT_14038bc40;

          auVar37._8_8_ = 0;

          auVar37._0_8_ = dVar30;

          auVar43._8_8_ = 0;

          auVar43._0_8_ = auVar41._0_8_;

          auVar41 = vfmadd231sd_fma(auVar37,auVar33,auVar43);

          auVar38._0_8_ = auVar17._0_8_ / auVar41._0_8_;

          auVar38._8_8_ = auVar17._8_8_;

          auVar2._8_8_ = 0;

          auVar2._0_8_ = DAT_140388ae0;

          auVar34._8_8_ = 0;

          auVar34._0_8_ = auVar38._0_8_ * auVar38._0_8_;

          auVar41 = vfnmadd213sd_fma(auVar20,auVar34,auVar2);

          auVar21._8_8_ = 0;

          auVar21._0_8_ = auVar41._0_8_ * auVar38._0_8_ * auVar38._0_8_;

          auVar44._8_8_ = 0;

          auVar44._0_8_ = auVar38._0_8_ + *(double *)(&DAT_1403929d0 + (ulonglong)uVar10 * 8);

          auVar41 = vfnmadd231sd_fma(auVar44,auVar38,auVar21);

        }

        if (bVar7) {

          dVar12 = DAT_140388af0 - dVar12;

          auVar41._0_8_ = DAT_14038abd0 - auVar41._0_8_;

        }

        if ((longlong)uVar24 < 0) {

          dVar12 = DAT_14038bc50 - dVar12;

          auVar41._0_8_ = DAT_14038bc20 - auVar41._0_8_;

        }

        if (-1 < (longlong)dVar16) {

          return dVar12 + auVar41._0_8_;

        }

        return (double)((ulonglong)(dVar12 + auVar41._0_8_) ^ DAT_140305470);

      }

      FUN_1402e8cc0(0x20);

      if (-1 < (longlong)uVar24) {

        if (-1 < (longlong)dVar16) {

          return DAT_14038ac58;

        }

        return DAT_14038bc68;

      }

      if (-1 < (longlong)dVar16) {

        return DAT_14038bc48;

      }

      return DAT_14038bc70;

    }

  }

  FUN_1402e8cc0(0x20);

  auVar41._0_8_ = DAT_140333080;

  if ((longlong)dVar16 < 0) {

    auVar41._0_8_ = DAT_14038bc78;

  }

  return auVar41._0_8_;

}




