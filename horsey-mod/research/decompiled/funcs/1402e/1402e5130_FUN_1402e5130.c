// Address: 0x1402e5130
// Ghidra name: FUN_1402e5130
// ============ 0x1402e5130 FUN_1402e5130 (size=490) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_1402e5130(undefined8 param_1,undefined8 param_2)



{

  undefined1 auVar1 [16];

  uint uVar2;

  int iVar3;

  uint uVar4;

  ulonglong uVar5;

  undefined1 auVar6 [64];

  undefined1 auVar7 [64];

  undefined1 auVar8 [64];

  undefined1 auVar9 [64];

  undefined1 auVar10 [64];

  undefined1 in_ZMM0 [64];

  float fVar11;

  float fVar12;

  float fVar13;

  undefined1 auVar14 [16];

  undefined1 auVar15 [16];

  

  uVar5 = in_ZMM0._0_8_;

  fVar11 = in_ZMM0._0_4_;

  auVar6._16_48_ = in_ZMM0._16_48_;

  if (DAT_1403ff158 == 0) {

    if ((uint)ABS(fVar11) < 0x7f800000) {

      if (0.0 < fVar11) {

        uVar2 = (uint)fVar11 & 0x7fffff;

        uVar4 = (uint)ABS(fVar11) >> 0x17;

        if (uVar4 == 0) {

          fVar12 = (float)(uVar2 | 0x3f800000) - DAT_14038c390;

          uVar2 = (uint)fVar12 & 0x7fffff;

          iVar3 = ((uint)fVar12 >> 0x17) - _DAT_14038c530;

        }

        else {

          iVar3 = uVar4 - 0x7f;

        }

        auVar8._4_60_ = in_ZMM0._4_60_;

        if (DAT_14038c540 <= (float)((uint)(fVar11 - DAT_14038c390) & _DAT_14038c410)) {

          uVar4 = (uVar2 >> 0x10) + (uint)((uVar2 >> 0xf & 1) != 0);

          uVar5 = (ulonglong)uVar4;

          fVar11 = ((float)(uVar4 * 0x10000 | 0x3f000000) - (float)(uVar2 | 0x3f000000)) *

                   *(float *)(&DAT_14038f3a0 + uVar5 * 4);

          auVar6._0_16_ = ZEXT416((uint)DAT_14038c4e0);

          auVar7._4_60_ = auVar6._4_60_;

          auVar7._0_4_ = DAT_14038c4e0 * (float)iVar3 + *(float *)(&DAT_1403955a0 + uVar5 * 4) +

                         (DAT_14038c4f0 * (float)iVar3 -

                         (fVar11 + (fVar11 * _DAT_14038c580 + _DAT_14038c590) * fVar11 * fVar11) *

                         DAT_14038c500) + *(float *)(&DAT_1403957b0 + uVar5 * 4);

          return auVar7._0_8_;

        }

        auVar8._0_4_ = fVar11 - DAT_14038c390;

        fVar11 = auVar8._0_4_ / (DAT_14038c3a0 + auVar8._0_4_);

        fVar12 = fVar11 + fVar11;

        auVar14 = auVar8._0_16_ & _DAT_14038c510;

        fVar13 = auVar14._0_4_;

        fVar11 = ((fVar12 * fVar12 * DAT_14038c480 + DAT_14038c470) * fVar12 * fVar12 * fVar12 -

                 auVar8._0_4_ * fVar11) + (auVar8._0_4_ - fVar13);

        auVar9._16_48_ = auVar6._16_48_;

        auVar9._0_16_ = auVar14;

        auVar10._4_60_ = auVar9._4_60_;

        auVar10._0_4_ =

             fVar13 * DAT_14038c4d0 + fVar11 * DAT_14038c4d0 + fVar11 * DAT_14038c4c0 +

             fVar13 * DAT_14038c4c0;

        return auVar10._0_8_;

      }

      if (fVar11 == 0.0) {

        uVar5 = FUN_1402ecfc0(param_1,param_2,DAT_14038c5a0);

        return uVar5;

      }

LAB_1402e5100:

      uVar5 = FUN_1402ecfc0(param_1,param_2,DAT_14038c5a4);

      return uVar5;

    }

    if (fVar11 != INFINITY) {

      if (fVar11 == -INFINITY) goto LAB_1402e5100;

      uVar5 = (ulonglong)((uint)fVar11 | 0x400000);

    }

    return uVar5;

  }

  if ((uint)ABS(fVar11) < 0x7f800000) {

    if (0.0 < fVar11) {

      uVar2 = (uint)fVar11 & 0x7fffff;

      uVar4 = (uint)ABS(fVar11) >> 0x17;

      if (uVar4 == 0) {

        auVar14 = vpor_avx(ZEXT416(uVar2),ZEXT416((uint)DAT_14038c390));

        auVar14 = ZEXT416((uint)(auVar14._0_4_ - DAT_14038c390));

        auVar15 = vpsrld_avx(auVar14,0x17);

        auVar14 = vpand_avx(auVar14,_DAT_14038c430);

        in_ZMM0 = ZEXT1664(auVar14);

        uVar2 = auVar14._0_4_;

        auVar14._4_12_ = _UNK_14038c534;

        auVar14._0_4_ = _DAT_14038c530;

        auVar14 = vpsubd_avx(auVar15,auVar14);

        auVar14 = vcvtdq2ps_avx(auVar14);

      }

      else {

        auVar14 = vcvtdq2ps_avx(ZEXT416(uVar4 - 0x7f));

      }

      auVar15._4_12_ = _UNK_14038c414;

      auVar15._0_4_ = _DAT_14038c410;

      auVar15 = vandps_avx(ZEXT416((uint)(in_ZMM0._0_4_ - DAT_14038c390)),auVar15);

      if (DAT_14038c540 <= auVar15._0_4_) {

        uVar4 = (uVar2 >> 0x10) + (uint)((uVar2 >> 0xf & 1) != 0);

        uVar5 = (ulonglong)uVar4;

        fVar11 = ((float)(uVar4 * 0x10000 | 0x3f000000) - (float)(uVar2 | 0x3f000000)) *

                 *(float *)(&DAT_14038f3a0 + uVar5 * 4);

        auVar1._4_12_ = _UNK_14038c584;

        auVar1._0_4_ = _DAT_14038c580;

        auVar15 = vfmadd213ss_fma(auVar1,ZEXT416((uint)fVar11),ZEXT416(DAT_14038c4b0));

        auVar15 = vfmadd231ss_fma(ZEXT416((uint)fVar11),auVar15,ZEXT416((uint)(fVar11 * fVar11)));

        auVar15 = vfmsub213ss_fma(ZEXT416((uint)DAT_14038c4f0),auVar14,

                                  ZEXT416((uint)(auVar15._0_4_ * DAT_14038c500)));

        auVar14 = vfmadd213ss_fma(ZEXT416((uint)DAT_14038c4e0),auVar14,

                                  ZEXT416(*(uint *)(&DAT_1403955a0 + uVar5 * 4)));

        return (ulonglong)

               (uint)(auVar14._0_4_ + auVar15._0_4_ + *(float *)(&DAT_1403957b0 + uVar5 * 4));

      }

      fVar12 = in_ZMM0._0_4_ - DAT_14038c390;

      fVar13 = fVar12 / (DAT_14038c3a0 + fVar12);

      fVar11 = fVar13 + fVar13;

      auVar14 = vfmadd213ss_fma(ZEXT416((uint)(fVar11 * fVar11)),ZEXT416((uint)DAT_14038c480),

                                ZEXT416((uint)DAT_14038c470));

      auVar15 = vfmsub213ss_fma(auVar14,ZEXT416((uint)(fVar11 * fVar11 * fVar11)),

                                ZEXT416((uint)(fVar12 * fVar13)));

      auVar14 = vpand_avx(ZEXT416((uint)fVar12),_DAT_14038c510);

      fVar13 = auVar14._0_4_;

      fVar11 = auVar15._0_4_ + (fVar12 - fVar13);

      auVar14 = vfmadd231ss_fma(ZEXT416((uint)(fVar13 * DAT_14038c4d0)),ZEXT416((uint)fVar11),

                                ZEXT416((uint)DAT_14038c4d0));

      return (ulonglong)(uint)(auVar14._0_4_ + fVar11 * DAT_14038c4c0 + fVar13 * DAT_14038c4c0);

    }

    if (fVar11 == 0.0) {

      uVar5 = FUN_1402ecfc0(param_1,DAT_14038c3b0,DAT_14038c5a0);

      return uVar5;

    }

LAB_1402e52f8:

    uVar5 = FUN_1402ecfc0(param_1,DAT_14038c3f0,DAT_14038c5a4);

    return uVar5;

  }

  if (fVar11 != INFINITY) {

    if (fVar11 == -INFINITY) goto LAB_1402e52f8;

    uVar5 = (ulonglong)((uint)fVar11 | 0x400000);

  }

  return uVar5;

}




