// Address: 0x1402d8d60
// Ghidra name: FUN_1402d8d60
// ============ 0x1402d8d60 FUN_1402d8d60 (size=3443) ============


/* WARNING: Removing unreachable block (ram,0x0001402d922f) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_1402d8d60(undefined8 param_1,double param_2,undefined8 param_3)



{

  undefined1 auVar1 [16];

  undefined1 auVar2 [16];

  undefined1 auVar3 [16];

  undefined1 auVar4 [16];

  undefined1 auVar5 [16];

  undefined1 auVar6 [60];

  undefined1 auVar7 [16];

  undefined1 auVar8 [16];

  undefined1 auVar9 [16];

  float fVar10;

  float fVar11;

  uint uVar12;

  uint uVar13;

  undefined1 auVar15 [16];

  undefined1 auVar16 [16];

  undefined1 auVar17 [16];

  ulonglong uVar14;

  undefined1 in_ZMM0 [64];

  undefined4 uVar21;

  undefined1 auVar18 [64];

  undefined1 auVar19 [64];

  undefined1 auVar20 [64];

  float fVar22;

  double dVar23;

  undefined8 uVar24;

  undefined1 auVar25 [16];

  undefined1 auVar26 [16];

  undefined1 auVar27 [16];

  undefined1 in_ZMM1 [64];

  undefined1 auVar28 [64];

  float fVar31;

  float fVar32;

  double dVar33;

  undefined1 auVar34 [16];

  undefined1 auVar35 [16];

  undefined1 auVar36 [16];

  undefined1 auVar37 [16];

  undefined1 in_ZMM2 [64];

  undefined1 auVar38 [16];

  undefined1 auVar39 [16];

  undefined1 auVar40 [16];

  undefined1 in_ZMM3 [64];

  undefined1 auVar41 [64];

  undefined1 auVar42 [16];

  undefined1 auVar43 [16];

  double dVar44;

  undefined1 auVar45 [16];

  double dVar46;

  undefined1 auVar29 [64];

  undefined1 auVar30 [64];

  

  fVar31 = in_ZMM0._0_4_;

  auVar20._16_48_ = in_ZMM0._16_48_;

  auVar35 = in_ZMM2._0_16_;

  if (DAT_1403ff158 != 0) {

    auVar27 = vpunpckldq_avx(in_ZMM1._0_16_,in_ZMM0._0_16_);

    auVar37 = (undefined1  [16])0x0;

    auVar36 = (undefined1  [16])0x0;

    fVar22 = auVar27._0_4_;

    fVar10 = ABS(fVar22);

    fVar11 = ABS(fVar31);

    uVar24 = auVar27._0_8_;

    if ((uint)fVar10 < 0x7f800000) {

      if ((uint)fVar10 < 0x3f800001) {

        if (fVar10 == 0.0) {

          if ((uint)fVar11 < 0x7f800001) {

            return 0x3f800000;

          }

          if (0x7fbfffff < (uint)fVar11) {

            return 0x3f800000;

          }

          uVar14 = FUN_1402f08b0(fVar11,(uint)fVar11 | 0x400000,(uint)fVar11 | 0x400000,

                                 DAT_140389338);

          return uVar14;

        }

        if (fVar22 == 1.0) {

          if ((uint)fVar11 < 0x7f800001) {

            return in_ZMM0._0_8_;

          }

          uVar14 = FUN_1402f08b0(fVar11,(uint)fVar31 | 0x400000,(uint)fVar31 | 0x400000,

                                 DAT_140389338);

          return uVar14;

        }

      }

      if ((uint)fVar11 < 0x7f800000) {

        auVar45 = vcvtps2pd_avx(auVar27);

        auVar20 = ZEXT1664(auVar45);

        if ((int)fVar31 < 0x3f880000) {

          auVar36 = auVar37;

          if ((int)fVar31 < 1) {

            if (fVar11 == 0.0) {

              fVar10 = fVar22;

              if ((int)fVar22 < 0) {

                fVar10 = INFINITY;

              }

              fVar11 = 0.0;

              if ((int)fVar22 < 0) {

                fVar11 = INFINITY;

              }

              uVar12 = 0;

              if (0 < (int)fVar22) {

                fVar10 = 0.0;

              }

              if (((uint)fVar22 & 0x7f800000) < 0x4b000001) {

                auVar35 = vroundss_avx(auVar35,auVar27,8);

                uVar12 = 0;

                if (auVar35._0_4_ == fVar22) {

                  if (((int)ROUND(fVar22) & 1U) == 0) {

                    uVar12 = 0;

                  }

                  else {

                    uVar12 = (uint)fVar31 & 0x80000000;

                  }

                }

              }

              uVar12 = uVar12 | (uint)fVar10;

              if (fVar11 == 0.0) {

                return (ulonglong)uVar12;

              }

              uVar14 = FUN_1402f08b0(uVar12,uVar24,uVar12,DAT_140389334);

              return uVar14;

            }

            if (((uint)fVar22 & 0x7f800000) < 0x4b000001) {

              auVar35 = vroundss_avx(auVar35,auVar27,8);

              if (auVar35._0_4_ != fVar22) {

                uVar14 = FUN_1402f08b0(fVar11,0xffc00000,0xffc00000,DAT_140389344);

                return uVar14;

              }

              if (((int)ROUND(fVar22) & 1U) != 0) {

                auVar36 = ZEXT416(DAT_14038939c);

              }

            }

          }

          auVar35 = vpshufd_avx(auVar45,0xee);

          dVar23 = auVar35._0_8_ - DAT_14038938c;

          param_2 = ABS(dVar23);

          if ((ulonglong)param_2 < (ulonglong)DAT_140389384) {

            vpshufd_avx(auVar36,0x44);

            dVar44 = dVar23 / (dVar23 + DAT_140389394);

            dVar33 = dVar44 + dVar44;

            dVar46 = dVar33 * dVar33;

            auVar35._8_8_ = 0;

            auVar35._0_8_ = dVar46;

            auVar35 = vpshufd_avx(auVar35,0x44);

            auVar27._8_8_ = 0;

            auVar27._0_8_ = dVar46 * dVar46 * dVar33 * dVar46;

            auVar36._8_8_ = 0;

            auVar36._0_8_ = dVar33 * dVar46;

            auVar27 = vunpcklpd_avx(auVar36,auVar27);

            auVar37._0_8_ = auVar27._0_8_ * (auVar35._0_8_ * _DAT_1403893b0 + _DAT_1403893c0);

            auVar37._8_8_ = auVar27._8_8_ * (auVar35._8_8_ * _UNK_1403893b8 + _UNK_1403893c8);

            auVar35 = vpshufd_avx(auVar37,0xee);

            auVar45._8_8_ = 0;

            auVar45._0_8_ = dVar44 * dVar23;

            auVar27 = vpshufd_avx(auVar45,0xee);

            uVar14 = auVar27._0_8_;

            dVar23 = dVar23 + ((auVar35._0_8_ + auVar37._0_8_) - dVar44 * dVar23);

            goto LAB_1402d8e5e;

          }

        }

        auVar35 = vpshufd_avx(auVar45,0xee);

        auVar35 = vpand_avx(auVar35,_DAT_140389410);

        uVar12 = (auVar35._4_4_ >> 0xc) + (uint)((auVar35._0_8_ >> 0x2b & 1) != 0);

        auVar8._8_8_ = _UNK_1403893f8;

        auVar8._0_8_ = DAT_1403893f0;

        auVar27 = vpor_avx(auVar35,auVar8);

        auVar35 = vpshufd_avx(auVar27,0xee);

        auVar35 = vpsrlq_avx(auVar35,0x34);

        auVar9._8_8_ = _UNK_140389408;

        auVar9._0_8_ = _DAT_140389400;

        auVar35 = vpsubq_avx(auVar35,auVar9);

        auVar35 = vcvtdq2pd_avx(auVar35);

        dVar23 = ((double)((ulonglong)(uVar12 | 0x3fe00) << 0x2c) - auVar27._0_8_) *

                 *(double *)(&DAT_140391a20 + (ulonglong)uVar12 * 8);

        auVar25._8_8_ = 0;

        auVar25._0_8_ = dVar23;

        auVar43._8_8_ = 0;

        auVar43._0_8_ = DAT_140389354;

        auVar1._8_8_ = 0;

        auVar1._0_8_ = DAT_1403893f0;

        auVar27 = vfmadd213sd_fma(auVar43,auVar25,auVar1);

        auVar2._8_8_ = 0;

        auVar2._0_8_ = DAT_14038938c;

        auVar26._8_8_ = 0;

        auVar26._0_8_ = dVar23;

        auVar27 = vfmadd213sd_fma(auVar27,auVar26,auVar2);

        dVar23 = dVar23 * auVar27._0_8_;

        dVar33 = auVar45._0_8_ *

                 ((auVar35._0_8_ * DAT_14038935c +

                  *(double *)(&DAT_140389420 + (ulonglong)uVar12 * 8)) - dVar23);

        if (DAT_140389364 < dVar33) {

          auVar35 = vorps_avx(ZEXT416(0x7f800000),auVar36);

          uVar14 = FUN_1402f08b0(&DAT_140389420,0x7f800000,auVar35._0_8_,DAT_140389350);

          return uVar14;

        }

        if (DAT_14038936c < dVar33) {

          auVar38._0_8_ = dVar33 * _DAT_1403893e0;

          auVar38._8_8_ = _UNK_1403893e8 * 0.0;

          auVar27 = vcvtpd2dq_avx(auVar38);

          auVar35 = vcvtdq2pd_avx(auVar27);

          auVar3._8_8_ = 0;

          auVar3._0_8_ = DAT_140389374;

          auVar15._8_8_ = 0;

          auVar15._0_8_ = dVar33;

          auVar37 = vfnmadd231sd_fma(auVar15,auVar35,auVar3);

          auVar39._8_8_ = 0;

          auVar39._0_8_ = DAT_14038937c;

          auVar4._8_8_ = 0;

          auVar4._0_8_ = DAT_1403893f0;

          auVar35 = vfmadd213sd_fma(auVar39,auVar37,auVar4);

          auVar5._8_8_ = 0;

          auVar5._0_8_ = DAT_14038938c;

          auVar35 = vfmadd213sd_fma(auVar35,auVar37,auVar5);

          auVar40._8_8_ = 0;

          auVar40._0_8_ = *(ulonglong *)(&DAT_14038ed30 + (ulonglong)(auVar27._0_4_ & 0x3f) * 8);

          auVar16._8_8_ = 0;

          auVar16._0_8_ = auVar37._0_8_ * auVar35._0_8_;

          auVar37 = vfmadd213sd_fma(auVar16,auVar40,auVar40);

          auVar35 = vpsrad_avx(auVar27,6);

          auVar35 = vpsllq_avx(auVar35,0x34);

          auVar35 = vpaddq_avx(auVar35,auVar37);

          auVar17._0_4_ = (float)auVar35._0_8_;

          auVar17._4_12_ = auVar37._4_12_;

          auVar35 = vorps_avx(auVar17,auVar36);

          return auVar35._0_8_;

        }

        auVar35 = vorps_avx((undefined1  [16])0x0,auVar36);

        uVar14 = FUN_1402f08b0(&DAT_140389420,dVar23,auVar35._0_8_,DAT_140389348);

        return uVar14;

      }

      if (fVar10 == 0.0) {

        return 0x3f800000;

      }

      if (fVar31 == INFINITY) {

        if (-1 < (int)fVar22) {

          return 0x7f800000;

        }

        return 0;

      }

      if (fVar31 == -INFINITY) {

        uVar12 = 0;

        fVar31 = fVar22;

        if ((int)fVar22 < 0) {

          fVar31 = 0.0;

        }

        if (0 < (int)fVar22) {

          fVar31 = INFINITY;

        }

        if (((uint)fVar22 & 0x7f800000) < 0x4b000001) {

          auVar35 = vroundss_avx(auVar35,auVar27,8);

          uVar12 = 0;

          if ((auVar35._0_4_ == fVar22) && (uVar12 = 0x80000000, ((int)ROUND(fVar22) & 1U) == 0)) {

            uVar12 = 0;

          }

        }

        return (ulonglong)(uVar12 | (uint)fVar31);

      }

    }

    else {

      if (0x7f800000 < (uint)fVar10) {

        if (0x7f800000 < (uint)fVar11) {

          if (fVar31 != -NAN) {

            uVar14 = FUN_1402f08b0((uint)fVar31 | 0x400000,uVar24,(uint)fVar31 | 0x400000,

                                   DAT_140389340);

            return uVar14;

          }

          uVar14 = FUN_1402f08b0(0x7fc00000,uVar24,(uint)fVar22 | 0x400000,DAT_140389340);

          return uVar14;

        }

        if (fVar31 == 1.0) {

          if (0x7fbfffff < (uint)fVar10) {

            return 0x3f800000;

          }

          uVar14 = FUN_1402f08b0(0x3f800000,0x3f800000,0x3f800000,DAT_14038933c);

          return uVar14;

        }

        uVar14 = FUN_1402f08b0(uVar24,uVar24,(uint)fVar22 | 0x400000,DAT_14038933c);

        return uVar14;

      }

      if ((uint)fVar11 < 0x7f800001) {

        if (fVar11 == 1.0) {

          return 0x3f800000;

        }

        if (-1 < (int)fVar22) {

          if (0x3f7fffff < (uint)fVar11) {

            return 0x7f800000;

          }

          return 0;

        }

        uVar12 = 0;

        if ((uint)fVar11 < 0x3f800000) {

          uVar12 = 0x7f800000;

        }

        return (ulonglong)uVar12;

      }

    }

    uVar14 = FUN_1402f08b0((uint)fVar31 | 0x400000,uVar24,(uint)fVar31 | 0x400000,DAT_140389338);

    return uVar14;

  }

  auVar30._16_48_ = in_ZMM1._16_48_;

  auVar30._0_12_ = in_ZMM1._0_12_;

  auVar30._12_4_ = in_ZMM0._4_4_;

  auVar29._12_52_ = auVar30._12_52_;

  auVar29._0_8_ = in_ZMM1._0_8_;

  auVar29._8_4_ = in_ZMM1._4_4_;

  auVar28._8_56_ = auVar29._8_56_;

  fVar22 = in_ZMM1._0_4_;

  auVar28._0_8_ = CONCAT44(fVar31,fVar22);

  uVar14 = 0;

  fVar10 = ABS(fVar22);

  fVar11 = ABS(fVar31);

  auVar27 = auVar28._0_16_;

  if (0x7f7fffff < (uint)fVar10) {

    if (0x7f800000 < (uint)fVar10) {

      if (0x7f800000 < (uint)fVar11) {

        if (fVar31 != -NAN) {

          uVar14 = FUN_1402f08b0((uint)fVar31 | 0x400000,auVar28._0_8_,param_3,DAT_140389340);

          return uVar14;

        }

        uVar14 = FUN_1402f08b0(0x7fc00000,auVar28._0_8_,param_3,DAT_140389340);

        return uVar14;

      }

      if (fVar31 == 1.0) {

        if (0x7fbfffff < (uint)fVar10) {

          return 0x3f800000;

        }

        uVar14 = FUN_1402f08b0(0x3f800000,0x3f800000,param_3,DAT_14038933c);

        return uVar14;

      }

      uVar14 = FUN_1402f08b0(fVar11,auVar28._0_8_,param_3,DAT_14038933c);

      return uVar14;

    }

    if ((uint)fVar11 < 0x7f800001) {

      if (fVar11 == 1.0) {

        return 0x3f800000;

      }

      if ((int)fVar22 < 0) {

        if (fVar11 != 0.0) {

          uVar12 = 0;

          if ((uint)fVar11 < 0x3f800000) {

            uVar12 = 0x7f800000;

          }

          return (ulonglong)uVar12;

        }

      }

      else if ((uint)fVar11 < 0x3f800000) {

        return 0;

      }

      return 0x7f800000;

    }

LAB_1402d93d0:

    uVar14 = FUN_1402f08b0((uint)fVar31 | 0x400000,auVar28._0_8_,param_3,DAT_140389338);

    return uVar14;

  }

  if ((uint)fVar10 < 0x3f800001) {

    if (fVar10 == 0.0) {

      if ((uint)fVar11 < 0x7f800001) {

        return 0x3f800000;

      }

      if (0x7fbfffff < (uint)fVar11) {

        return 0x3f800000;

      }

      uVar14 = FUN_1402f08b0(fVar11,(uint)fVar11 | 0x400000,param_3,DAT_140389338);

      return uVar14;

    }

    param_2 = (double)(auVar29._0_8_ & 0xffffffff);

    if (fVar22 == 1.0) {

      if ((uint)ABS(fVar31) < 0x7f800001) {

        return in_ZMM0._0_8_;

      }

      uVar14 = FUN_1402f08b0(fVar11,(uint)fVar31 | 0x400000,param_3,DAT_140389338);

      return uVar14;

    }

  }

  if (0x7f7fffff < (uint)fVar11) {

    if (fVar10 == 0.0) {

      return 0x3f800000;

    }

    if (fVar31 == INFINITY) {

      if (-1 < (int)fVar22) {

        return 0x7f800000;

      }

      return 0;

    }

    if (fVar31 == -INFINITY) {

      uVar12 = 0;

      fVar31 = fVar22;

      if ((int)fVar22 < 0) {

        fVar31 = 0.0;

      }

      if (0 < (int)fVar22) {

        fVar31 = INFINITY;

      }

      if (((uint)fVar22 & 0x7f800000) < 0x4b000001) {

        if (DAT_1403e8ad0 < 2) {

          fVar10 = (float)(int)ROUND(fVar22);

        }

        else {

          auVar35 = roundss(auVar35,auVar27,8);

          fVar10 = auVar35._0_4_;

        }

        uVar12 = 0;

        if ((fVar10 == fVar22) && (uVar12 = 0x80000000, ((int)ROUND(fVar22) & 1U) == 0)) {

          uVar12 = 0;

        }

      }

      return (ulonglong)(uVar12 | (uint)fVar31);

    }

    goto LAB_1402d93d0;

  }

  auVar20._0_8_ = (double)fVar22;

  auVar20._8_8_ = (double)fVar31;

  uVar21 = (undefined4)((ulonglong)auVar20._8_8_ >> 0x20);

  if ((int)fVar31 < 0x3f880000) {

    if ((int)fVar31 < 1) {

      if (fVar11 == 0.0) {

        fVar10 = fVar22;

        if ((int)fVar22 < 0) {

          fVar10 = INFINITY;

        }

        fVar11 = 0.0;

        if ((int)fVar22 < 0) {

          fVar11 = INFINITY;

        }

        uVar12 = 0;

        if (0 < (int)fVar22) {

          fVar10 = 0.0;

        }

        uVar13 = (uint)fVar22 & 0x7f800000;

        if (uVar13 < 0x4b000001) {

          if (DAT_1403e8ad0 < 2) {

            uVar13 = (uint)ROUND(fVar22);

            fVar32 = (float)(int)uVar13;

          }

          else {

            auVar35 = roundss(auVar35,auVar27,8);

            fVar32 = auVar35._0_4_;

          }

          uVar12 = 0;

          if (fVar32 == fVar22) {

            uVar13 = (uint)(int)ROUND(fVar22) >> 1 | (uint)(fVar32 < fVar22) << 0x1f;

            if (((int)ROUND(fVar22) & 1U) == 0) {

              uVar12 = 0;

            }

            else {

              uVar12 = (uint)fVar31 & 0x80000000;

            }

          }

        }

        uVar14 = (ulonglong)(uVar12 | (uint)fVar10);

        if (fVar11 != 0.0) {

          uVar14 = FUN_1402f08b0(uVar12 | (uint)fVar10,auVar28._0_8_,uVar13,DAT_140389334);

        }

        return uVar14;

      }

      if (((uint)fVar22 & 0x7f800000) < 0x4b000001) {

        if (DAT_1403e8ad0 < 2) {

          fVar31 = (float)(int)ROUND(fVar22);

        }

        else {

          auVar35 = roundss(auVar35,auVar27,8);

          fVar31 = auVar35._0_4_;

        }

        if (fVar31 != fVar22) {

          uVar14 = FUN_1402f08b0(fVar11,0xffc00000,param_3,DAT_140389344);

          return uVar14;

        }

        if (((int)ROUND(fVar22) & 1U) != 0) {

          uVar14 = (ulonglong)DAT_14038939c;

        }

      }

    }

    auVar41._8_4_ = SUB84(auVar20._8_8_,0);

    auVar41._0_8_ = auVar20._8_8_;

    auVar41._16_48_ = in_ZMM3._16_48_;

    auVar41._12_4_ = uVar21;

    in_ZMM3._8_56_ = auVar41._8_56_;

    in_ZMM3._0_8_ = auVar20._8_8_ - DAT_14038938c;

    param_2 = ABS(in_ZMM3._0_8_);

    if ((ulonglong)param_2 < (ulonglong)DAT_140389384) {

      dVar46 = in_ZMM3._0_8_ / (in_ZMM3._0_8_ + DAT_140389394);

      dVar33 = dVar46 + dVar46;

      dVar23 = dVar33 * dVar33;

      auVar42._8_4_ = SUB84(dVar23,0);

      auVar42._0_8_ = dVar23;

      auVar42._12_4_ = (int)((ulonglong)dVar23 >> 0x20);

      dVar23 = in_ZMM3._0_8_ +

               ((dVar33 * dVar23 * (dVar23 * _DAT_1403893b0 + _DAT_1403893c0) +

                dVar23 * dVar23 * dVar33 * dVar23 *

                (auVar42._8_8_ * _UNK_1403893b8 + _UNK_1403893c8)) - dVar46 * in_ZMM3._0_8_);

      goto LAB_1402d8e5e;

    }

  }

  auVar34._8_4_ = SUB84(auVar20._8_8_,0);

  auVar34._0_8_ = auVar20._8_8_;

  auVar34._12_4_ = uVar21;

  auVar34 = auVar34 & _DAT_140389410;

  uVar12 = (auVar34._4_4_ >> 0xc) + (uint)((auVar34._0_8_ >> 0x2b & 1) != 0);

  auVar7._8_8_ = _UNK_1403893f8;

  auVar7._0_8_ = DAT_1403893f0;

  auVar6._4_56_ = in_ZMM3._8_56_;

  auVar6._0_4_ = SUB164(auVar34 | auVar7,0xc);

  dVar23 = ((double)((ulonglong)(uVar12 | 0x3fe00) << 0x2c) - SUB168(auVar34 | auVar7,0)) *

           *(double *)(&DAT_140391a20 + (ulonglong)uVar12 * 8);

  dVar23 = ((double)(int)(((auVar6._0_8_ & 0xffffffff) >> 0x14) - _DAT_140389400) * DAT_14038935c +

           *(double *)(&DAT_140389420 + (ulonglong)uVar12 * 8)) -

           (dVar23 * dVar23 * (DAT_140389354 * dVar23 + DAT_1403893f0) + dVar23);

LAB_1402d8e5e:

  auVar18._8_56_ = auVar20._8_56_;

  dVar23 = auVar20._0_8_ * dVar23;

  if (DAT_140389364 < dVar23) {

    uVar14 = FUN_1402f08b0(dVar23,0x7f800000,param_3,DAT_140389350);

    return uVar14;

  }

  if (DAT_14038936c < dVar23) {

    uVar12 = (uint)(dVar23 * _DAT_1403893e0);

    dVar23 = dVar23 - (double)(int)uVar12 * DAT_140389374;

    auVar18._0_8_ =

         (dVar23 * dVar23 * (DAT_14038937c * dVar23 + DAT_1403893f0) + dVar23) *

         *(double *)(&DAT_14038ed30 + (ulonglong)(uVar12 & 0x3f) * 8) +

         *(double *)(&DAT_14038ed30 + (ulonglong)(uVar12 & 0x3f) * 8);

    auVar19._4_60_ = auVar18._4_60_;

    auVar19._0_4_ =

         (float)(double)(((ulonglong)(uint)((int)uVar12 >> 6) << 0x34) + (longlong)auVar18._0_8_);

    return auVar19._0_8_ | uVar14;

  }

  uVar14 = FUN_1402f08b0(dVar23,param_2,param_3,DAT_140389348);

  return uVar14;

}




