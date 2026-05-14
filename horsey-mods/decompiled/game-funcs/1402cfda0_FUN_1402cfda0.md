# `FUN_1402cfda0` @ 0x1402cfda0

**Size**: 502 bytes
**Role**: `lab_location` (string-anchored)
**Domain**: `world_event` - world location / event / action
**Pattern**: `float_math` - Float-heavy math (geometry / physics / genetics)
**Evidence**: 18 float vars, 47 consts

**Game callers** (29): [`FUN_140006950`](140006950_FUN_140006950.md), [`FUN_14000d4e0`](14000d4e0_FUN_14000d4e0.md), [`FUN_14000f8d0`](14000f8d0_FUN_14000f8d0.md), [`FUN_140010010`](140010010_FUN_140010010.md), [`FUN_140010240`](140010240_FUN_140010240.md), [`FUN_140012ba0`](140012ba0_FUN_140012ba0.md), [`FUN_140013290`](140013290_FUN_140013290.md), [`FUN_1400138c0`](1400138c0_FUN_1400138c0.md), [`FUN_140013d80`](140013d80_FUN_140013d80.md), [`FUN_140017910`](140017910_FUN_140017910.md)
  ... +19 more

**Game callees** (5): [`FUN_1402cfda0`](1402cfda0_FUN_1402cfda0.md), [`FUN_1402e9320`](1402e9320_FUN_1402e9320.md), [`FUN_1402eca20`](1402eca20_FUN_1402eca20.md), [`FUN_1402ecb70`](1402ecb70_FUN_1402ecb70.md), [`FUN_1402ecd60`](1402ecd60_FUN_1402ecd60.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_1402cfda0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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

  uint uVar14;

  float fVar15;

  ulonglong uVar16;

  double dVar17;

  float fVar18;

  undefined1 auVar19 [16];

  undefined1 auVar20 [16];

  undefined1 auVar21 [16];

  undefined1 auVar22 [16];

  undefined1 auVar23 [16];

  undefined8 extraout_XMM0_Qa_00;

  undefined8 extraout_XMM0_Qa_01;

  undefined1 auVar24 [16];

  undefined1 auVar25 [16];

  undefined8 extraout_XMM0_Qa;

  undefined1 auVar26 [64];

  undefined1 auVar27 [64];

  undefined1 auVar28 [64];

  undefined1 auVar29 [64];

  undefined1 extraout_var [56];

  undefined1 auVar30 [64];

  undefined1 auVar31 [64];

  undefined1 in_ZMM0 [64];

  undefined1 extraout_var_00 [56];

  undefined1 extraout_var_01 [56];

  undefined1 auVar34 [16];

  undefined1 auVar35 [16];

  undefined1 auVar36 [16];

  double dVar37;

  undefined1 auVar38 [16];

  undefined1 auVar39 [16];

  undefined1 auVar40 [16];

  undefined1 auVar41 [16];

  undefined1 auVar42 [16];

  undefined1 auVar43 [16];

  undefined1 auVar44 [16];

  undefined1 auVar45 [16];

  undefined1 auVar46 [16];

  undefined1 auVar47 [16];

  double dVar48;

  undefined1 auVar49 [16];

  undefined1 auVar32 [64];

  undefined1 auVar33 [64];

  fVar18 = in_ZMM0._0_4_;

  auVar26._8_56_ = in_ZMM0._8_56_;

  auVar27._16_48_ = in_ZMM0._16_48_;

  if (DAT_1403ff158 != 0) {

    fVar15 = ABS(fVar18);

    if (0x7f7fffff < (uint)fVar15) {

      uVar16 = FUN_1402e9320();

      return uVar16;

    }

    auVar49._0_8_ = (double)fVar18;

    auVar49._8_8_ = in_ZMM0._8_8_;

    if (0x3f490fdb < (uint)fVar15) {

      if ((uint)fVar15 < 0x4f490fdb) {

        auVar22._8_8_ = 0;

        auVar22._0_8_ = ABS(auVar49._0_8_);

        auVar49 = vandpd_avx(auVar22,_DAT_140388d10);

        auVar13._8_8_ = _UNK_140388c88;

        auVar13._0_8_ = DAT_140388c80;

        auVar5._8_8_ = 0;

        auVar5._0_8_ = DAT_140388c70;

        auVar49 = vfmadd213sd_fma(auVar13,auVar49,auVar5);

        auVar39._0_4_ = (int)auVar49._0_8_;

        auVar39._4_4_ = (int)auVar49._8_8_;

        auVar39._8_8_ = 0;

        auVar23 = vpmovsxdq_avx(auVar39);

        auVar49 = vandpd_avx(auVar23,_DAT_140388d20);

        auVar23 = vshufps_avx(auVar23,auVar23,8);

        auVar5 = vcvtdq2pd_avx(auVar23);

        auVar6._8_8_ = 0;

        auVar6._0_8_ = DAT_140388cb0;

        auVar6 = vfnmadd231sd_fma(auVar22,auVar5,auVar6);

        auVar23._8_8_ = 0;

        auVar23._0_8_ = auVar6._0_8_ - auVar5._0_8_ * DAT_140388cc0;

        uVar16 = auVar49._0_8_;

      }

      else if ((uint)fVar15 < 0x4f490fdb) {

        uVar16 = FUN_1402ecd60(ABS(auVar49._0_8_));

        auVar32._8_56_ = extraout_var_00;

        auVar32._0_8_ = extraout_XMM0_Qa_00;

        auVar23 = auVar32._0_16_;

      }

      else {

        uVar16 = FUN_1402ecb70();

        auVar33._8_56_ = extraout_var_01;

        auVar33._0_8_ = extraout_XMM0_Qa_01;

        auVar23 = auVar33._0_16_;

      }

      dVar17 = auVar23._0_8_;

      if ((uVar16 & 1) == 0) {

        dVar17 = dVar17 * dVar17;

        auVar36._8_8_ = 0;

        auVar36._0_8_ = DAT_14038dfc8;

        auVar10._8_8_ = 0;

        auVar10._0_8_ = DAT_14038dfd0;

        auVar46._8_8_ = 0;

        auVar46._0_8_ = dVar17;

        auVar49 = vfmadd231sd_fma(auVar36,auVar46,auVar10);

        auVar11._8_8_ = 0;

        auVar11._0_8_ = DAT_14038dfc0;

        auVar49 = vfmadd213sd_fma(auVar49,auVar46,auVar11);

        auVar12._8_8_ = 0;

        auVar12._0_8_ = DAT_14038dfb8;

        auVar49 = vfmadd213sd_fma(auVar49,auVar46,auVar12);

        auVar40._8_8_ = 0;

        auVar40._0_8_ = DAT_140388c60 - dVar17 * DAT_140388c70;

        auVar47._8_8_ = 0;

        auVar47._0_8_ = dVar17 * dVar17;

        auVar49 = vfmadd231sd_fma(auVar40,auVar49,auVar47);

      }

      else {

        auVar35._8_8_ = 0;

        auVar35._0_8_ = DAT_14038dff0;

        dVar37 = dVar17 * dVar17;

        auVar7._8_8_ = 0;

        auVar7._0_8_ = DAT_14038dff8;

        auVar43._8_8_ = 0;

        auVar43._0_8_ = dVar37;

        auVar49 = vfmadd231sd_fma(auVar35,auVar43,auVar7);

        auVar8._8_8_ = 0;

        auVar8._0_8_ = DAT_14038dfe8;

        auVar49 = vfmadd213sd_fma(auVar49,auVar43,auVar8);

        auVar9._8_8_ = 0;

        auVar9._0_8_ = DAT_14038dfe0;

        auVar44._8_8_ = 0;

        auVar44._0_8_ = dVar37;

        auVar49 = vfmadd213sd_fma(auVar49,auVar44,auVar9);

        auVar45._8_8_ = 0;

        auVar45._0_8_ = dVar17 * dVar37;

        auVar49 = vfmadd231sd_fma(auVar23,auVar49,auVar45);

      }

      auVar24._0_8_ = (double)(auVar49._0_8_ ^ (uVar16 + 1 >> 1) << 0x3f);

      auVar24._8_8_ = auVar49._8_8_;

      auVar25._0_4_ = (float)auVar24._0_8_;

      auVar25._4_12_ = auVar24._4_12_;

      return auVar25._0_8_;

    }

    if (0x3bffffff < (uint)fVar15) {

      dVar17 = auVar49._0_8_ * auVar49._0_8_;

      auVar34._8_8_ = 0;

      auVar34._0_8_ = DAT_14038dfc8;

      auVar2._8_8_ = 0;

      auVar2._0_8_ = DAT_14038dfd0;

      auVar41._8_8_ = 0;

      auVar41._0_8_ = dVar17;

      auVar49 = vfmadd231sd_fma(auVar34,auVar41,auVar2);

      auVar3._8_8_ = 0;

      auVar3._0_8_ = DAT_14038dfc0;

      auVar49 = vfmadd213sd_fma(auVar49,auVar41,auVar3);

      auVar4._8_8_ = 0;

      auVar4._0_8_ = DAT_14038dfb8;

      auVar49 = vfmadd213sd_fma(auVar49,auVar41,auVar4);

      auVar38._8_8_ = 0;

      auVar38._0_8_ = DAT_140388c60 - dVar17 * DAT_140388c70;

      auVar42._8_8_ = 0;

      auVar42._0_8_ = dVar17 * dVar17;

      auVar49 = vfmadd231sd_fma(auVar38,auVar49,auVar42);

      auVar21._0_4_ = (float)auVar49._0_8_;

      auVar21._4_12_ = auVar49._4_12_;

      return auVar21._0_8_;

    }

    if ((uint)fVar15 < 0x39000000) {

      return (ulonglong)DAT_140388d68;

    }

    auVar1._8_8_ = 0;

    auVar1._0_8_ = DAT_140388c60;

    auVar19._8_8_ = 0;

    auVar19._0_8_ = auVar49._0_8_ * DAT_140388c70;

    auVar49 = vfnmadd213sd_fma(auVar19,auVar49,auVar1);

    auVar20._0_4_ = (float)auVar49._0_8_;

    auVar20._4_12_ = auVar49._4_12_;

    return auVar20._0_8_;

  }

  fVar15 = ABS(fVar18);

  if (0x7f7fffff < (uint)fVar15) {

    uVar16 = FUN_1402e9320();

    return uVar16;

  }

  auVar26._0_8_ = (double)fVar18;

  dVar17 = ABS(auVar26._0_8_);

  if ((uint)fVar15 < 0x3f490fdc) {

    uVar14 = 0;

  }

  else if ((uint)fVar15 < 0x48f42400) {

    uVar14 = (uint)(dVar17 * DAT_140388c80 + DAT_140388c70);

    dVar37 = (double)(int)uVar14;

    dVar48 = dVar17 - DAT_140388cb0 * dVar37;

    auVar27._8_8_ = 0;

    auVar27._0_8_ = dVar48;

    auVar26._8_56_ = auVar27._8_56_;

    auVar26._0_8_ = dVar48 - DAT_140388cc0 * dVar37;

    uVar16 = (ulonglong)ABS(auVar26._0_8_) >> 0x34;

    if (0xf < (longlong)(((ulonglong)dVar17 >> 0x34) - uVar16)) {

      dVar17 = dVar48 - DAT_140388cd0 * dVar37;

      auVar28._8_8_ = 0;

      auVar28._0_8_ = dVar17;

      auVar28._16_48_ = auVar27._16_48_;

      auVar26._8_56_ = auVar28._8_56_;

      auVar26._0_8_ =

           dVar17 - (DAT_140388ce0 * dVar37 - ((dVar48 - dVar17) - DAT_140388cd0 * dVar37));

    }

    if (uVar16 < 0x3f2) {

      auVar29._16_48_ = auVar26._16_48_;

      if (uVar16 < 0x3df) {

        if ((uVar14 & 1) == 0) {

          auVar26._8_8_ = 0;

          auVar26._0_8_ = DAT_140388c60;

          auVar26._16_48_ = auVar29._16_48_;

        }

      }

      else {

        dVar17 = auVar26._0_8_;

        if ((uVar14 & 1) == 0) {

          auVar29._8_8_ = 0;

          auVar29._0_8_ = DAT_140388c60;

          auVar26._8_56_ = auVar29._8_56_;

          auVar26._0_8_ = DAT_140388c60 - dVar17 * dVar17 * DAT_140388c70;

        }

        else {

          auVar26._0_8_ = dVar17 - DAT_140388c90 * dVar17 * dVar17 * dVar17;

        }

      }

      goto LAB_1402cfd74;

    }

  }

  else {

    uVar14 = FUN_1402eca20(param_1,auVar26._0_8_,1,param_4,auVar26._0_8_);

    auVar26._8_56_ = extraout_var;

    auVar26._0_8_ = (double)extraout_XMM0_Qa;

  }

  dVar17 = auVar26._0_8_;

  dVar37 = dVar17 * dVar17;

  if ((uVar14 & 1) == 0) {

    auVar30._16_48_ = auVar26._16_48_;

    auVar30._8_8_ = 0;

    auVar30._0_8_ = DAT_14038dfb0;

    auVar26._8_56_ = auVar30._8_56_;

    auVar26._0_8_ =

         DAT_14038dfb0 * dVar37 + DAT_140388c60 +

         ((DAT_14038dfd0 * dVar37 + DAT_14038dfc8) * dVar37 * dVar37 +

         DAT_14038dfc0 * dVar37 + DAT_14038dfb8) * dVar37 * dVar37;

  }

  else {

    auVar26._0_8_ =

         dVar17 + ((DAT_14038dff8 * dVar37 + DAT_14038dff0) * dVar37 * dVar37 +

                  DAT_14038dfe8 * dVar37 + DAT_14038dfe0) * dVar17 * dVar37;

  }

LAB_1402cfd74:

  if ((uVar14 + 1 & 2) != 0) {

    dVar17 = auVar26._0_8_;

    auVar26._8_8_ = 0;

    auVar26._0_8_ = 0.0 - dVar17;

  }

  auVar31._4_60_ = auVar26._4_60_;

  auVar31._0_4_ = (float)auVar26._0_8_;

  return auVar31._0_8_;

}
```