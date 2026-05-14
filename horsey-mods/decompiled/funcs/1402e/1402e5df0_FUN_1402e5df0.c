// Address: 0x1402e5df0
// Ghidra name: FUN_1402e5df0
// ============ 0x1402e5df0 FUN_1402e5df0 (size=722) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1402e5df0(void)



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

  bool bVar10;

  bool bVar11;

  undefined1 auVar12 [16];

  undefined1 auVar13 [16];

  undefined1 auVar14 [16];

  undefined1 auVar15 [16];

  undefined1 auVar16 [16];

  undefined1 auVar17 [16];

  undefined1 auVar18 [16];

  undefined1 auVar19 [16];

  undefined1 auVar20 [16];

  undefined1 auVar21 [16];

  undefined1 auVar22 [16];

  undefined1 auVar23 [16];

  undefined1 auVar24 [16];

  undefined1 auVar25 [16];

  undefined1 auVar26 [16];

  undefined1 auVar27 [16];

  undefined1 auVar28 [16];

  float fVar29;

  ulonglong uVar30;

  ulonglong uVar31;

  sbyte sVar32;

  byte bVar33;

  ulonglong uVar34;

  longlong lVar35;

  longlong lVar36;

  ulonglong uVar37;

  double dVar38;

  longlong lVar39;

  ulonglong uVar40;

  ulonglong uVar41;

  undefined1 auVar44 [16];

  undefined1 auVar45 [16];

  undefined1 auVar46 [16];

  undefined1 auVar47 [16];

  float fVar42;

  undefined1 auVar48 [16];

  undefined1 auVar49 [16];

  undefined1 auVar50 [16];

  undefined1 auVar51 [16];

  undefined1 auVar52 [16];

  undefined8 uVar43;

  undefined1 auVar53 [64];

  undefined1 auVar54 [64];

  undefined1 auVar55 [64];

  undefined1 auVar56 [64];

  undefined1 auVar57 [64];

  undefined1 auVar58 [64];

  undefined1 auVar59 [64];

  undefined1 auVar60 [64];

  undefined1 auVar61 [64];

  undefined1 auVar62 [64];

  undefined1 in_ZMM0 [64];

  double dVar63;

  undefined1 auVar64 [16];

  undefined1 auVar65 [16];

  undefined1 auVar66 [16];

  undefined1 auVar67 [16];

  undefined1 auVar68 [16];

  undefined1 auVar69 [16];

  undefined1 auVar70 [16];

  undefined1 auVar71 [16];

  undefined1 auVar72 [16];

  undefined1 auVar73 [16];

  undefined1 auVar74 [16];

  undefined1 auVar75 [16];

  undefined1 auVar76 [16];

  uint uVar77;

  double dVar78;

  ulonglong in_XMM5_Qb;

  undefined1 auVar79 [16];

  

  fVar42 = in_ZMM0._0_4_;

  if (DAT_1403ff158 == 0) {

    fVar29 = ABS(fVar42);

    if (0x7f7fffff < (uint)fVar29) {

      uVar43 = FUN_1402e9530();

      return uVar43;

    }

    dVar78 = (double)fVar42;

    dVar38 = ABS(dVar78);

    auVar53._16_48_ = in_ZMM0._16_48_;

    if ((uint)fVar29 < 0x3f490fdc) {

      if ((uint)fVar29 < 0x39000000) {

        if ((uint)fVar29 < 0x32000000) {

          return in_ZMM0._0_8_;

        }

        auVar53._8_8_ = in_XMM5_Qb;

        auVar53._0_8_ = dVar78 * dVar78;

        auVar54._8_56_ = auVar53._8_56_;

        auVar54._0_8_ = dVar78 * dVar78 * dVar78 * DAT_14038c7c8 + dVar78;

      }

      else {

        auVar55._8_8_ = in_XMM5_Qb;

        auVar55._0_8_ = dVar78;

        auVar55._16_48_ = auVar53._16_48_;

        dVar38 = dVar78 * dVar78;

        auVar54._8_56_ = auVar55._8_56_;

        auVar54._0_8_ =

             dVar78 + dVar38 * dVar78 *

                      ((DAT_14038c798 * dVar38 + DAT_14038c790) /

                      ((DAT_14038c7b0 * dVar38 + DAT_14038c7a8) * dVar38 + DAT_14038c7a0));

      }

      auVar62._4_60_ = auVar54._4_60_;

      auVar62._0_4_ = (float)auVar54._0_8_;

      return auVar62._0_8_;

    }

    if ((longlong)dVar38 < DAT_14038c7b8) {

      uVar77 = (uint)(_DAT_14038c750 * (double)((ulonglong)dVar38 & _DAT_14038c740) + DAT_14038c7e0)

      ;

      dVar63 = (double)(int)uVar77;

      uVar77 = uVar77 & _DAT_14038c760;

      dVar38 = dVar38 - dVar63 * DAT_14038c7e8;

      auVar56._8_8_ = 0;

      auVar56._0_8_ = dVar38;

      auVar56._16_48_ = auVar53._16_48_;

      auVar57._8_56_ = auVar56._8_56_;

      auVar57._0_8_ = dVar38 - dVar63 * DAT_14038c7f0;

    }

    else {

      uVar41 = ((ulonglong)dVar38 >> 0x34) - 0x3ff;

      lVar39 = -((uVar41 >> 3) - 0x86);

      uVar34 = (ulonglong)dVar38 & 0xfffffffffffff | 0x10000000000000;

      auVar47._8_8_ = 0;

      auVar47._0_8_ = *(ulonglong *)(&DAT_14038e000 + lVar39);

      auVar15._8_8_ = 0;

      auVar15._0_8_ = uVar34;

      auVar23._8_8_ = 0;

      auVar23._0_8_ = SUB168(auVar47 * auVar15,8);

      uVar30 = SUB168(auVar47 * auVar15,0);

      auVar21._8_8_ = 0;

      auVar21._0_8_ = *(ulonglong *)(&UNK_14038e008 + lVar39);

      auVar16._8_8_ = 0;

      auVar16._0_8_ = uVar34;

      uVar41 = uVar41 & 7;

      auVar23 = auVar21 * auVar16 + auVar23;

      uVar31 = auVar23._0_8_;

      auVar22._8_8_ = 0;

      auVar22._0_8_ = *(ulonglong *)(&UNK_14038e010 + lVar39);

      auVar17._8_8_ = 0;

      auVar17._0_8_ = uVar34;

      uVar40 = auVar23._8_8_ + SUB168(auVar22 * auVar17,0);

      uVar37 = 0;

      bVar33 = (byte)(0x36 - uVar41) & 0x3f;

      uVar34 = uVar40 >> bVar33;

      bVar10 = (0x36 - uVar41 & 0x3f) != 0;

      bVar11 = (uVar40 >> bVar33 - 1 & 1) != 0;

      if (bVar10 && bVar11) {

        uVar40 = ~uVar40;

        uVar31 = ~uVar31;

        uVar30 = ~uVar30;

        uVar37 = 0x8000000000000000;

      }

      uVar77 = (int)uVar34 + (uint)(bVar10 && bVar11) & 3;

      sVar32 = (char)uVar41 + 10;

      uVar34 = (uVar40 << sVar32) >> sVar32;

      lVar35 = uVar41 - 0x36;

      lVar39 = 0x3f;

      if (uVar34 != 0) {

        for (; uVar34 >> lVar39 == 0; lVar39 = lVar39 + -1) {

        }

      }

      uVar40 = uVar31;

      if (uVar34 == 0) {

        lVar39 = 0x3f;

        if (uVar31 != 0) {

          for (; uVar31 >> lVar39 == 0; lVar39 = lVar39 + -1) {

          }

        }

        lVar35 = uVar41 - 0x76;

        uVar40 = uVar30;

        uVar34 = uVar31;

      }

      lVar36 = lVar39 + -0x34;

      if (lVar36 < 0) {

        bVar33 = -(byte)lVar36;

        uVar34 = uVar34 << (bVar33 & 0x3f) | uVar40 >> (-(bVar33 - 0x40) & 0x3f);

      }

      else if (lVar36 != 0) {

        uVar34 = uVar34 >> ((byte)lVar36 & 0x3f);

      }

      dVar38 = (double)(uVar34 & 0xffefffffffffffff | uVar37 | lVar35 + lVar39 + 0x3ff << 0x34);

      auVar58._8_8_ = 0;

      auVar58._0_8_ = dVar38;

      auVar58._16_48_ = auVar53._16_48_;

      auVar57._8_56_ = auVar58._8_56_;

      auVar57._0_8_ = dVar38 * DAT_14038c7f8;

    }

    dVar38 = auVar57._0_8_;

    dVar63 = dVar38 * dVar38;

    auVar59._8_56_ = auVar57._8_56_;

    auVar59._0_8_ =

         dVar38 + dVar63 * dVar38 *

                  ((DAT_14038c798 * dVar63 + DAT_14038c790) /

                  ((DAT_14038c7b0 * dVar63 + DAT_14038c7a8) * dVar63 + DAT_14038c7a0));

    if ((uVar77 & 1) == 1) {

      auVar59._16_48_ = auVar57._16_48_;

      auVar59._8_8_ = 0;

      auVar59._0_8_ = DAT_14038c800 / auVar59._0_8_;

    }

    auVar60._0_8_ = (double)(auVar59._0_8_ ^ (ulonglong)dVar78 & _DAT_14038c780);

    auVar60._16_48_ = auVar59._16_48_;

    auVar60._8_8_ = auVar59._8_8_ ^ in_XMM5_Qb & _UNK_14038c788;

    auVar61._4_60_ = auVar60._4_60_;

    auVar61._0_4_ = (float)auVar60._0_8_;

    return auVar61._0_8_;

  }

  fVar29 = ABS(fVar42);

  if (0x7f7fffff < (uint)fVar29) {

    uVar43 = FUN_1402e9530();

    return uVar43;

  }

  auVar79._0_8_ = (double)fVar42;

  auVar45._8_8_ = in_ZMM0._8_8_;

  auVar79._8_8_ = auVar45._8_8_;

  dVar38 = ABS(auVar79._0_8_);

  if ((uint)fVar29 < 0x3f490fdc) {

    if ((uint)fVar29 < 0x39000000) {

      if ((uint)fVar29 < 0x32000000) {

        return in_ZMM0._0_8_;

      }

      auVar1._8_8_ = 0;

      auVar1._0_8_ = DAT_14038c7c8;

      auVar44._8_8_ = 0;

      auVar44._0_8_ = auVar79._0_8_ * auVar79._0_8_ * auVar79._0_8_;

      auVar47 = vfmadd132sd_fma(auVar44,auVar79,auVar1);

    }

    else {

      auVar45._0_8_ = auVar79._0_8_;

      dVar38 = auVar79._0_8_ * auVar79._0_8_;

      auVar73._8_8_ = 0;

      auVar73._0_8_ = DAT_14038c798;

      auVar2._8_8_ = 0;

      auVar2._0_8_ = DAT_14038c790;

      auVar64._8_8_ = 0;

      auVar64._0_8_ = dVar38;

      auVar47 = vfmadd213sd_fma(auVar73,auVar64,auVar2);

      auVar70._8_8_ = 0;

      auVar70._0_8_ = DAT_14038c7b0;

      auVar3._8_8_ = 0;

      auVar3._0_8_ = DAT_14038c7a8;

      auVar21 = vfmadd213sd_fma(auVar70,auVar64,auVar3);

      auVar4._8_8_ = 0;

      auVar4._0_8_ = DAT_14038c7a0;

      auVar65._8_8_ = 0;

      auVar65._0_8_ = dVar38;

      auVar21 = vfmadd213sd_fma(auVar21,auVar65,auVar4);

      auVar74._0_8_ = auVar47._0_8_ / auVar21._0_8_;

      auVar74._8_8_ = auVar47._8_8_;

      auVar66._8_8_ = 0;

      auVar66._0_8_ = dVar38 * auVar79._0_8_;

      auVar47 = vfmadd231sd_fma(auVar45,auVar66,auVar74);

    }

    auVar52._0_4_ = (float)auVar47._0_8_;

    auVar52._4_12_ = auVar47._4_12_;

    return auVar52._0_8_;

  }

  if ((longlong)dVar38 < DAT_14038c7c0) {

    auVar46._8_8_ = 0;

    auVar46._0_8_ = dVar38;

    auVar25._8_8_ = _UNK_14038c748;

    auVar25._0_8_ = _DAT_14038c740;

    auVar47 = vandpd_avx(auVar46,auVar25);

    auVar26._8_8_ = _UNK_14038c758;

    auVar26._0_8_ = _DAT_14038c750;

    auVar5._8_8_ = 0;

    auVar5._0_8_ = DAT_14038c7e0;

    auVar47 = vfmadd213sd_fma(auVar26,auVar47,auVar5);

    auVar71._0_4_ = (int)auVar47._0_8_;

    auVar71._4_4_ = (int)auVar47._8_8_;

    auVar71._8_8_ = 0;

    auVar21 = vpmovsxdq_avx(auVar71);

    auVar27._4_12_ = _UNK_14038c764;

    auVar27._0_4_ = _DAT_14038c760;

    auVar47 = vandpd_avx(auVar21,auVar27);

    auVar21 = vshufps_avx(auVar21,auVar21,8);

    auVar21 = vcvtdq2pd_avx(auVar21);

    auVar6._8_8_ = 0;

    auVar6._0_8_ = DAT_14038c7e8;

    auVar22 = vfnmadd231sd_fma(auVar46,auVar21,auVar6);

    dVar38 = auVar22._0_8_ - auVar21._0_8_ * DAT_14038c7f0;

  }

  else {

    uVar41 = ((ulonglong)dVar38 >> 0x34) - 0x3ff;

    lVar39 = -((uVar41 >> 3) - 0x86);

    uVar34 = (ulonglong)auVar79._0_8_ & 0xfffffffffffff | 0x10000000000000;

    auVar12._8_8_ = 0;

    auVar12._0_8_ = *(ulonglong *)(&DAT_14038e000 + lVar39);

    auVar18._8_8_ = 0;

    auVar18._0_8_ = uVar34;

    auVar24._8_8_ = 0;

    auVar24._0_8_ = SUB168(auVar12 * auVar18,8);

    uVar30 = SUB168(auVar12 * auVar18,0);

    auVar13._8_8_ = 0;

    auVar13._0_8_ = SUB168(*(undefined1 (*) [16])(&UNK_14038e008 + lVar39),0);

    auVar19._8_8_ = 0;

    auVar19._0_8_ = uVar34;

    uVar41 = uVar41 & 7;

    auVar47 = vpsrldq_avx(*(undefined1 (*) [16])(&UNK_14038e008 + lVar39),8);

    auVar24 = auVar13 * auVar19 + auVar24;

    uVar31 = auVar24._0_8_;

    auVar14._8_8_ = 0;

    auVar14._0_8_ = auVar47._0_8_;

    auVar20._8_8_ = 0;

    auVar20._0_8_ = uVar34;

    uVar40 = auVar24._8_8_ + SUB168(auVar14 * auVar20,0);

    uVar37 = 0;

    bVar33 = (byte)(0x36 - uVar41) & 0x3f;

    uVar34 = uVar40 >> bVar33;

    bVar10 = (0x36 - uVar41 & 0x3f) != 0;

    bVar11 = (uVar40 >> bVar33 - 1 & 1) != 0;

    if (bVar10 && bVar11) {

      uVar40 = ~uVar40;

      uVar31 = ~uVar31;

      uVar30 = ~uVar30;

      uVar37 = 0x8000000000000000;

    }

    auVar47 = ZEXT416((int)uVar34 + (uint)(bVar10 && bVar11) & 3);

    sVar32 = (char)uVar41 + 10;

    uVar34 = (uVar40 << sVar32) >> sVar32;

    lVar35 = uVar41 - 0x36;

    lVar39 = 0x3f;

    if (uVar34 != 0) {

      for (; uVar34 >> lVar39 == 0; lVar39 = lVar39 + -1) {

      }

    }

    uVar40 = uVar31;

    if (uVar34 == 0) {

      lVar39 = 0x3f;

      if (uVar31 != 0) {

        for (; uVar31 >> lVar39 == 0; lVar39 = lVar39 + -1) {

        }

      }

      lVar35 = uVar41 - 0x76;

      uVar40 = uVar30;

      uVar34 = uVar31;

    }

    lVar36 = lVar39 + -0x34;

    if (lVar36 < 0) {

      bVar33 = -(byte)lVar36;

      uVar34 = uVar34 << (bVar33 & 0x3f) | uVar40 >> (-(bVar33 - 0x40) & 0x3f);

    }

    else if (lVar36 != 0) {

      uVar34 = uVar34 >> ((byte)lVar36 & 0x3f);

    }

    dVar38 = (double)(uVar34 & 0xffefffffffffffff | uVar37 | lVar35 + lVar39 + 0x3ff << 0x34) *

             DAT_14038c7f8;

  }

  auVar47 = vandpd_avx(auVar47,_DAT_14038c770);

  dVar78 = dVar38 * dVar38;

  auVar75._8_8_ = 0;

  auVar75._0_8_ = DAT_14038c798;

  auVar7._8_8_ = 0;

  auVar7._0_8_ = DAT_14038c790;

  auVar67._8_8_ = 0;

  auVar67._0_8_ = dVar78;

  auVar21 = vfmadd213sd_fma(auVar75,auVar67,auVar7);

  auVar72._8_8_ = 0;

  auVar72._0_8_ = DAT_14038c7b0;

  auVar8._8_8_ = 0;

  auVar8._0_8_ = DAT_14038c7a8;

  auVar22 = vfmadd213sd_fma(auVar72,auVar67,auVar8);

  auVar9._8_8_ = 0;

  auVar9._0_8_ = DAT_14038c7a0;

  auVar68._8_8_ = 0;

  auVar68._0_8_ = dVar78;

  auVar22 = vfmadd213sd_fma(auVar22,auVar68,auVar9);

  auVar76._0_8_ = auVar21._0_8_ / auVar22._0_8_;

  auVar76._8_8_ = auVar21._8_8_;

  auVar48._8_8_ = 0;

  auVar48._0_8_ = dVar38;

  auVar69._8_8_ = 0;

  auVar69._0_8_ = dVar78 * dVar38;

  auVar49 = vfmadd231sd_fma(auVar48,auVar69,auVar76);

  if (auVar47._0_4_ == 1) {

    auVar49._0_8_ = DAT_14038c800 / auVar49._0_8_;

    auVar49._8_8_ = 0;

  }

  auVar28._8_8_ = _UNK_14038c788;

  auVar28._0_8_ = _DAT_14038c780;

  auVar47 = vandpd_avx(auVar79,auVar28);

  auVar50._0_8_ = (double)(auVar49._0_8_ ^ auVar47._0_8_);

  auVar50._8_8_ = auVar49._8_8_ ^ auVar47._8_8_;

  auVar51._0_4_ = (float)auVar50._0_8_;

  auVar51._4_12_ = auVar50._4_12_;

  return auVar51._0_8_;

}




