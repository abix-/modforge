// Address: 0x1402cffc0
// Ghidra name: FUN_1402cffc0
// ============ 0x1402cffc0 FUN_1402cffc0 (size=302) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1402cffc0(undefined8 param_1)



{

  float fVar1;

  float fVar2;

  undefined8 in_XMM0_Qa;

  undefined8 uVar3;

  double in_XMM0_Qb;

  double dVar6;

  undefined1 auVar4 [16];

  undefined1 auVar5 [16];

  double dVar7;

  uint uVar8;

  

  fVar1 = (float)in_XMM0_Qa;

  fVar2 = ABS(fVar1);

  if ((uint)fVar2 < 0x42b00000) {

    dVar7 = DAT_140388db0 * (double)fVar1;

  }

  else {

    if (0x7f7fffff < (uint)fVar2) {

      if (fVar1 == INFINITY) {

        return in_XMM0_Qa;

      }

      if (fVar1 == -INFINITY) {

        return 0;

      }

      uVar3 = FUN_1402ece80(param_1,(uint)fVar1 | 0x400000,DAT_140388dfc);

      return uVar3;

    }

    dVar7 = DAT_140388db0 * (double)fVar1;

    if (DAT_140388d90 <= dVar7) {

      uVar3 = FUN_1402ece80(fVar2,fVar2,DAT_140388e04);

      return uVar3;

    }

    if (dVar7 < DAT_140388da0) {

      uVar3 = FUN_1402ece80(fVar2,fVar2,DAT_140388e00);

      return uVar3;

    }

  }

  uVar8 = (uint)dVar7;

  dVar7 = (double)fVar1 - DAT_140388dc0 * (double)(int)uVar8;

  dVar6 = in_XMM0_Qb - _UNK_140388dc8 * (double)(int)_UNK_140388db8;

  auVar4._0_8_ = ((dVar7 * dVar7 * (_DAT_140388dd0 * dVar7 + DAT_140388de0) + dVar7) *

                  *(double *)(&DAT_14038ed30 + (ulonglong)(uVar8 & 0x3f) * 8) +

                 *(double *)(&DAT_14038ed30 + (ulonglong)(uVar8 & 0x3f) * 8)) *

                 (double)((ulonglong)(uint)((int)(uVar8 - (uVar8 & 0x3f)) >> 6) + 0x3ff << 0x34);

  auVar4._8_8_ = ((dVar6 * dVar6 * (_UNK_140388dd8 * dVar6 + _UNK_140388de8) + dVar6) * 0.0 + 0.0) *

                 0.0;

  auVar5._4_12_ = auVar4._4_12_;

  auVar5._0_4_ = (float)auVar4._0_8_;

  return auVar5._0_8_;

}




