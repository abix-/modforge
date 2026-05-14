// Address: 0x1402d03e0
// Ghidra name: FUN_1402d03e0
// ============ 0x1402d03e0 FUN_1402d03e0 (size=432) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_1402d03e0(undefined8 param_1,undefined8 param_2)



{

  float fVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  ulonglong uVar5;

  undefined1 in_XMM0 [16];

  undefined1 auVar6 [16];

  undefined1 auVar7 [16];

  float fVar8;

  float fVar9;

  

  uVar5 = in_XMM0._0_8_;

  fVar1 = in_XMM0._0_4_;

  if ((uint)ABS(fVar1) < 0x7f800000) {

    if (0.0 < fVar1) {

      uVar2 = (uint)fVar1 & 0x7fffff;

      uVar3 = (uint)ABS(fVar1) >> 0x17;

      if (uVar3 == 0) {

        fVar8 = (float)(uVar2 | 0x3f800000) - DAT_140388e10;

        uVar2 = (uint)fVar8 & 0x7fffff;

        iVar4 = ((uint)fVar8 >> 0x17) - _DAT_140388ea0;

      }

      else {

        iVar4 = uVar3 - 0x7f;

      }

      auVar7._4_12_ = in_XMM0._4_12_;

      if (DAT_140388f3c <= (float)((uint)(fVar1 - DAT_140388e10) & _DAT_140388e70)) {

        uVar3 = (uVar2 >> 0x10) + (uint)((uVar2 >> 0xf & 1) != 0);

        uVar5 = (ulonglong)uVar3;

        fVar1 = ((float)(uVar3 * 0x10000 | 0x3f000000) - (float)(uVar2 | 0x3f000000)) *

                *(float *)(&DAT_14038f3a0 + uVar5 * 4);

        auVar6._4_12_ = DAT_140388ef0._4_12_;

        auVar6._0_4_ = (float)DAT_140388ef0 * (float)iVar4 + *(float *)(&DAT_14038ef80 + uVar5 * 4)

                       + (_DAT_140388f00 * (float)iVar4 -

                         (fVar1 + (fVar1 * _DAT_140388f20 + DAT_140388f30) * fVar1 * fVar1)) +

                         *(float *)(&DAT_14038f190 + uVar5 * 4);

        return auVar6._0_8_;

      }

      fVar1 = fVar1 - DAT_140388e10;

      fVar8 = fVar1 / (_DAT_140388e20 + fVar1);

      fVar9 = fVar8 + fVar8;

      auVar7._0_4_ = fVar1 + ((fVar9 * fVar9 * _DAT_140388ee0 + DAT_140388ed0) *

                              fVar9 * fVar9 * fVar9 - fVar1 * fVar8);

      return auVar7._0_8_;

    }

    if (fVar1 == 0.0) {

      uVar5 = FUN_1402ed0a0(param_1,param_2,DAT_140388f40);

      return uVar5;

    }

LAB_1402d056a:

    uVar5 = FUN_1402ed0a0(param_1,param_2,DAT_140388f44);

    return uVar5;

  }

  if (fVar1 != INFINITY) {

    if (fVar1 == -INFINITY) goto LAB_1402d056a;

    uVar5 = (ulonglong)((uint)fVar1 | 0x400000);

  }

  return uVar5;

}




