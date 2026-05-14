// Address: 0x1402e4f30
// Ghidra name: FUN_1402e4f30
// ============ 0x1402e4f30 FUN_1402e4f30 (size=512) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_1402e4f30(undefined8 param_1,undefined8 param_2)



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

        fVar8 = (float)(uVar2 | 0x3f800000) - DAT_14038c390;

        uVar2 = (uint)fVar8 & 0x7fffff;

        iVar4 = ((uint)fVar8 >> 0x17) - _DAT_14038c530;

      }

      else {

        iVar4 = uVar3 - 0x7f;

      }

      auVar6._4_12_ = in_XMM0._4_12_;

      if (DAT_14038c540 <= (float)((uint)(fVar1 - DAT_14038c390) & _DAT_14038c410)) {

        uVar3 = (uVar2 >> 0x10) + (uint)((uVar2 >> 0xf & 1) != 0);

        uVar5 = (ulonglong)uVar3;

        fVar1 = ((float)(uVar3 * 0x10000 | 0x3f000000) - (float)(uVar2 | 0x3f000000)) *

                *(float *)(&DAT_14038f3a0 + uVar5 * 4);

        return (ulonglong)

               (uint)(DAT_14038c4e0 * (float)iVar4 + *(float *)(&DAT_1403955a0 + uVar5 * 4) +

                     (DAT_14038c4f0 * (float)iVar4 -

                     (fVar1 + (fVar1 * _DAT_14038c580 + _DAT_14038c590) * fVar1 * fVar1) *

                     DAT_14038c500) + *(float *)(&DAT_1403957b0 + uVar5 * 4));

      }

      auVar6._0_4_ = fVar1 - DAT_14038c390;

      fVar1 = auVar6._0_4_ / (DAT_14038c3a0 + auVar6._0_4_);

      fVar8 = fVar1 + fVar1;

      fVar9 = SUB164(auVar6 & _DAT_14038c510,0);

      fVar1 = ((fVar8 * fVar8 * DAT_14038c480 + DAT_14038c470) * fVar8 * fVar8 * fVar8 -

              auVar6._0_4_ * fVar1) + (auVar6._0_4_ - fVar9);

      auVar7._4_12_ = SUB1612(auVar6 & _DAT_14038c510,4);

      auVar7._0_4_ = fVar9 * DAT_14038c4d0 + fVar1 * DAT_14038c4d0 + fVar1 * DAT_14038c4c0 +

                     fVar9 * DAT_14038c4c0;

      return auVar7._0_8_;

    }

    if (fVar1 == 0.0) {

      uVar5 = FUN_1402ecfc0(param_1,param_2,DAT_14038c5a0);

      return uVar5;

    }

LAB_1402e5100:

    uVar5 = FUN_1402ecfc0(param_1,param_2,DAT_14038c5a4);

    return uVar5;

  }

  if (fVar1 != INFINITY) {

    if (fVar1 == -INFINITY) goto LAB_1402e5100;

    uVar5 = (ulonglong)((uint)fVar1 | 0x400000);

  }

  return uVar5;

}




