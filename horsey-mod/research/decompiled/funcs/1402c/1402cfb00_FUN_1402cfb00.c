// Address: 0x1402cfb00
// Ghidra name: FUN_1402cfb00
// ============ 0x1402cfb00 FUN_1402cfb00 (size=631) ============


undefined8

FUN_1402cfb00(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  float fVar1;

  uint uVar2;

  ulonglong uVar3;

  double dVar4;

  float in_XMM0_Da;

  undefined8 extraout_XMM0_Qa;

  undefined8 uVar5;

  undefined8 in_XMM0_Qb;

  undefined1 auVar6 [16];

  undefined8 extraout_XMM0_Qb;

  undefined1 auVar7 [16];

  double dVar8;

  double dVar9;

  double dVar10;

  

  fVar1 = ABS(in_XMM0_Da);

  if (0x7f7fffff < (uint)fVar1) {

    uVar5 = FUN_1402e9320(param_1,param_2,0);

    return uVar5;

  }

  auVar6._0_8_ = (double)in_XMM0_Da;

  auVar6._8_8_ = in_XMM0_Qb;

  dVar4 = ABS(auVar6._0_8_);

  if ((uint)fVar1 < 0x3f490fdc) {

    uVar2 = 0;

  }

  else if ((uint)fVar1 < 0x48f42400) {

    uVar2 = (uint)(dVar4 * DAT_140388c80 + DAT_140388c70);

    dVar8 = (double)(int)uVar2;

    dVar10 = dVar4 - DAT_140388cb0 * dVar8;

    dVar9 = dVar10 - DAT_140388cc0 * dVar8;

    uVar3 = (ulonglong)ABS(dVar9) >> 0x34;

    if (0xf < (longlong)(((ulonglong)dVar4 >> 0x34) - uVar3)) {

      dVar9 = dVar10 - DAT_140388cd0 * dVar8;

      dVar9 = dVar9 - (DAT_140388ce0 * dVar8 - ((dVar10 - dVar9) - DAT_140388cd0 * dVar8));

    }

    auVar6._8_8_ = 0;

    auVar6._0_8_ = dVar9;

    if (uVar3 < 0x3f2) {

      if (uVar3 < 0x3df) {

        if ((uVar2 & 1) == 0) {

          auVar6._8_8_ = 0;

          auVar6._0_8_ = DAT_140388c60;

        }

      }

      else if ((uVar2 & 1) == 0) {

        auVar6._0_8_ = DAT_140388c60 - dVar9 * dVar9 * DAT_140388c70;

        auVar6._8_8_ = 0;

      }

      else {

        auVar6._0_8_ = dVar9 - DAT_140388c90 * dVar9 * dVar9 * dVar9;

        auVar6._8_8_ = 0;

      }

      goto LAB_1402cfd74;

    }

  }

  else {

    uVar2 = FUN_1402eca20(dVar4,auVar6._0_8_,1,param_4,auVar6._0_8_);

    auVar6._8_8_ = extraout_XMM0_Qb;

    auVar6._0_8_ = (double)extraout_XMM0_Qa;

  }

  dVar4 = auVar6._0_8_;

  dVar9 = dVar4 * dVar4;

  if ((uVar2 & 1) == 0) {

    auVar6._0_8_ = DAT_14038dfb0 * dVar9 + DAT_140388c60 +

                   ((DAT_14038dfd0 * dVar9 + DAT_14038dfc8) * dVar9 * dVar9 +

                   DAT_14038dfc0 * dVar9 + DAT_14038dfb8) * dVar9 * dVar9;

    auVar6._8_8_ = 0;

  }

  else {

    auVar6._0_8_ = dVar4 + ((DAT_14038dff8 * dVar9 + DAT_14038dff0) * dVar9 * dVar9 +

                           DAT_14038dfe8 * dVar9 + DAT_14038dfe0) * dVar4 * dVar9;

  }

LAB_1402cfd74:

  if ((uVar2 + 1 & 2) != 0) {

    dVar4 = auVar6._0_8_;

    auVar6._8_8_ = 0;

    auVar6._0_8_ = 0.0 - dVar4;

  }

  auVar7._4_12_ = auVar6._4_12_;

  auVar7._0_4_ = (float)auVar6._0_8_;

  return auVar7._0_8_;

}




