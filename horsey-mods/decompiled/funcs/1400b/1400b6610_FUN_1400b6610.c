// Address: 0x1400b6610
// Ghidra name: FUN_1400b6610
// ============ 0x1400b6610 FUN_1400b6610 (size=518) ============


void FUN_1400b6610(longlong param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  undefined8 uVar3;

  longlong lVar4;

  ulonglong uVar5;

  longlong lVar6;

  uint uVar7;

  ulonglong uVar8;

  float fVar9;

  float fVar10;

  

  fVar9 = *param_2;

  if ((((DAT_14039ca90 < fVar9) && (fVar9 < DAT_14039ca68)) &&

      (fVar10 = param_2[1], DAT_14039ca90 < fVar10)) && (fVar10 < DAT_14039ca68)) {

    fVar9 = fVar9 - *(float *)(param_1 + 0x124);

    fVar10 = fVar10 - *(float *)(param_1 + 0x128);

    lVar6 = *(longlong *)(param_1 + 0x40);

    if ((lVar6 != *(longlong *)(param_1 + 0x48)) && (*(longlong *)(lVar6 + 0x30) != 0)) {

      uVar3 = *(undefined8 *)(*(longlong *)(lVar6 + 0x30) + 0x58);

      FUN_1400b47e0(param_1);

      lVar6 = *(longlong *)(param_1 + 0x40);

      lVar4 = *(longlong *)(param_1 + 0x48) - lVar6;

      uVar5 = 0;

      fVar1 = *(float *)(lVar6 + 0x50);

      fVar2 = *(float *)(lVar6 + 0x54);

      lVar4 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar4),8) + lVar4;

      uVar8 = uVar5;

      if (lVar4 >> 7 != lVar4 >> 0x3f) {

        do {

          uVar7 = (int)uVar8 + 1;

          *(undefined4 *)(uVar5 + 0x48 + lVar6) = *(undefined4 *)(uVar5 + 0x58 + lVar6);

          *(float *)(uVar5 + 0x44 + lVar6) = (fVar10 - fVar2) + *(float *)(uVar5 + 0x54 + lVar6);

          *(float *)(uVar5 + 0x40 + lVar6) = (fVar9 - fVar1) + *(float *)(uVar5 + 0x50 + lVar6);

          uVar5 = uVar5 + 0xb8;

          lVar6 = *(longlong *)(param_1 + 0x40);

          lVar4 = *(longlong *)(param_1 + 0x48) - lVar6;

          lVar4 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar4),8) + lVar4;

          uVar8 = (ulonglong)uVar7;

        } while ((ulonglong)(longlong)(int)uVar7 < (ulonglong)((lVar4 >> 7) - (lVar4 >> 0x3f)));

      }

      FUN_1400b3dc0(param_1,uVar3);

      return;

    }

    fVar1 = *(float *)(lVar6 + 0x50);

    fVar2 = *(float *)(lVar6 + 0x54);

    lVar4 = *(longlong *)(param_1 + 0x48) - lVar6;

    uVar5 = 0;

    lVar4 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar4),8) + lVar4;

    uVar8 = uVar5;

    if (lVar4 >> 7 != lVar4 >> 0x3f) {

      do {

        uVar7 = (int)uVar8 + 1;

        *(float *)(uVar5 + 0x44 + lVar6) = (fVar10 - fVar2) + *(float *)(uVar5 + 0x54 + lVar6);

        *(float *)(uVar5 + 0x40 + lVar6) = (fVar9 - fVar1) + *(float *)(uVar5 + 0x50 + lVar6);

        uVar5 = uVar5 + 0xb8;

        lVar6 = *(longlong *)(param_1 + 0x40);

        lVar4 = *(longlong *)(param_1 + 0x48) - lVar6;

        lVar4 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar4),8) + lVar4;

        uVar8 = (ulonglong)uVar7;

      } while ((ulonglong)(longlong)(int)uVar7 < (ulonglong)((lVar4 >> 7) - (lVar4 >> 0x3f)));

    }

  }

  return;

}




