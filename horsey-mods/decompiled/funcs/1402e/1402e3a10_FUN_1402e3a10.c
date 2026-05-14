// Address: 0x1402e3a10
// Ghidra name: FUN_1402e3a10
// ============ 0x1402e3a10 FUN_1402e3a10 (size=903) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



double FUN_1402e3a10(undefined8 param_1)



{

  undefined1 auVar1 [16];

  undefined1 auVar2 [16];

  undefined1 auVar3 [16];

  undefined1 auVar4 [16];

  undefined1 auVar5 [16];

  undefined1 auVar6 [16];

  undefined1 auVar7 [16];

  bool bVar8;

  undefined1 auVar9 [16];

  ulonglong uVar10;

  uint uVar11;

  double dVar12;

  double in_XMM0_Qa;

  undefined1 auVar13 [16];

  undefined1 auVar14 [16];

  undefined1 auVar15 [16];

  undefined1 auVar16 [16];

  uint uVar17;

  double dVar18;

  undefined1 auVar19 [16];

  undefined1 auVar20 [16];

  undefined1 auVar21 [16];

  

  auVar13._8_8_ = 0;

  auVar13._0_8_ = in_XMM0_Qa;

  dVar12 = ABS(in_XMM0_Qa);

  if ((longlong)dVar12 < (longlong)DAT_14038be40) {

    if (DAT_1403ff158 != 0) {

      auVar1._8_8_ = 0;

      auVar1._0_8_ = DAT_14038be20;

      auVar1 = vcmpsd_avx(auVar13,auVar1,2);

      auVar2._8_8_ = 0;

      auVar2._0_8_ = DAT_14038be28;

      auVar2 = vcmpsd_avx(auVar13,auVar2,5);

      auVar1 = vandps_avx(auVar2,auVar1);

      if (NAN(auVar1._0_8_)) {

        if ((ulonglong)ABS(in_XMM0_Qa) <= (ulonglong)DAT_14038be80) {

          return in_XMM0_Qa + DAT_14038be78;

        }

        auVar16._8_8_ = 0;

        auVar16._0_8_ = in_XMM0_Qa * DAT_14038be38;

        auVar1 = vroundsd_avx(auVar16,auVar16,3);

        uVar11 = (uint)(in_XMM0_Qa * DAT_14038be38);

        auVar3._8_8_ = 0;

        auVar3._0_8_ = DAT_14038be60;

        auVar13 = vfmadd231sd_fma(auVar13,auVar1,auVar3);

        dVar12 = auVar1._0_8_ * DAT_14038be68 + auVar13._0_8_;

        uVar10 = (ulonglong)(uVar11 & 0x3f);

        uVar11 = (int)uVar11 >> 6;

        auVar9._8_8_ = _UNK_14038bdb8;

        auVar9._0_8_ = _DAT_14038bdb0;

        auVar4._8_8_ = 0;

        auVar4._0_8_ = DAT_14038bdc0;

        auVar19._8_8_ = 0;

        auVar19._0_8_ = dVar12;

        auVar13 = vfmadd213sd_fma(auVar9,auVar19,auVar4);

        auVar5._8_8_ = 0;

        auVar5._0_8_ = DAT_14038bdf0;

        auVar13 = vfmadd213sd_fma(auVar13,auVar19,auVar5);

        auVar6._8_8_ = 0;

        auVar6._0_8_ = DAT_14038bdd0;

        auVar20._8_8_ = 0;

        auVar20._0_8_ = dVar12;

        auVar13 = vfmadd213sd_fma(auVar13,auVar20,auVar6);

        auVar7._8_8_ = 0;

        auVar7._0_8_ = DAT_14038bde0;

        auVar13 = vfmadd213sd_fma(auVar13,auVar20,auVar7);

        auVar14._8_8_ = 0;

        auVar14._0_8_ = dVar12 * dVar12;

        auVar13 = vfmadd213sd_fma(auVar14,auVar13,auVar20);

        dVar12 = auVar13._0_8_ * *(double *)(&DAT_14038ed30 + uVar10 * 8) +

                 *(double *)(&DAT_140393360 + uVar10 * 8) + *(double *)(&DAT_140393160 + uVar10 * 8)

        ;

        if ((-0x3fe < (int)uVar11) || ((-0x3ff < (int)uVar11 && (DAT_14038be78 <= dVar12)))) {

          auVar15._8_8_ = 0;

          auVar15._0_8_ = dVar12;

          auVar21._8_8_ = 0;

          auVar21._0_8_ = (ulonglong)uVar11 << 0x34;

          auVar13 = vpaddq_avx(auVar15,auVar21);

          return auVar13._0_8_;

        }

        dVar12 = dVar12 * (double)(1L << ((char)uVar11 + 0x32U & 0x3f));

      }

      else if (DAT_14038be20 < in_XMM0_Qa) {

        dVar12 = (double)FUN_1402ecde0(param_1,0x7ff0000000000000,DAT_14038bda8);

      }

      else {

        dVar12 = _DAT_14038be70;

        if (in_XMM0_Qa < DAT_14038be30) {

          dVar12 = (double)FUN_1402ecde0(param_1,0,DAT_14038bda4);

        }

      }

      return dVar12;

    }

    if (NAN((double)-(ulonglong)(in_XMM0_Qa <= DAT_14038be20 && DAT_14038be28 <= in_XMM0_Qa))) {

      if ((ulonglong)ABS(in_XMM0_Qa) <= (ulonglong)DAT_14038be80) {

        return in_XMM0_Qa + DAT_14038be78;

      }

      uVar17 = (uint)(in_XMM0_Qa * DAT_14038be38);

      uVar10 = (ulonglong)(uVar17 & 0x3f);

      uVar11 = (int)uVar17 >> 6;

      dVar18 = (double)(int)uVar17 * DAT_14038be68 +

               in_XMM0_Qa + (double)(int)uVar17 * DAT_14038be60;

      dVar12 = dVar18 * dVar18;

      in_XMM0_Qa = ((DAT_14038bdd0 * dVar18 + DAT_14038bde0) * dVar12 + dVar18 +

                   ((_DAT_14038bdb0 * dVar18 + DAT_14038bdc0) * dVar18 + DAT_14038bdf0) *

                   dVar12 * dVar12) * *(double *)(&DAT_14038ed30 + uVar10 * 8) +

                   *(double *)(&DAT_140393360 + uVar10 * 8) +

                   *(double *)(&DAT_140393160 + uVar10 * 8);

      if ((-0x3fe < (int)uVar11) || ((-0x3ff < (int)uVar11 && (DAT_14038be78 <= in_XMM0_Qa)))) {

        return (double)((longlong)in_XMM0_Qa + ((ulonglong)uVar11 << 0x34));

      }

      in_XMM0_Qa = in_XMM0_Qa * (double)(1L << ((char)uVar11 + 0x32U & 0x3f));

    }

    else if (DAT_14038be20 < in_XMM0_Qa) {

      in_XMM0_Qa = (double)FUN_1402ecde0(param_1,dVar12,DAT_14038bda8);

    }

    else {

      bVar8 = in_XMM0_Qa < DAT_14038be30;

      in_XMM0_Qa = _DAT_14038be70;

      if (bVar8) {

        in_XMM0_Qa = (double)FUN_1402ecde0(param_1,dVar12,DAT_14038bda4);

      }

    }

  }

  else if (in_XMM0_Qa != DAT_14038be40) {

    if (in_XMM0_Qa == DAT_14038be48) {

      return 0.0;

    }

    in_XMM0_Qa = (double)((ulonglong)in_XMM0_Qa | _DAT_14038be50);

  }

  return in_XMM0_Qa;

}




