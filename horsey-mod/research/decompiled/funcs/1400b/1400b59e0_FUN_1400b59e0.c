// Address: 0x1400b59e0
// Ghidra name: FUN_1400b59e0
// ============ 0x1400b59e0 FUN_1400b59e0 (size=352) ============


void FUN_1400b59e0(longlong param_1,undefined1 *param_2,undefined1 *param_3)



{

  float fVar1;

  float fVar2;

  longlong lVar3;

  int iVar4;

  longlong lVar5;

  longlong lVar6;

  undefined4 uVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  

  *param_2 = 0;

  *param_3 = 0;

  fVar2 = DAT_140307a44;

  fVar1 = DAT_140303384;

  lVar6 = *(longlong *)(param_1 + 0x40);

  iVar4 = 0;

  lVar5 = *(longlong *)(param_1 + 0x48) - lVar6;

  lVar5 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar5),8) + lVar5;

  if (lVar5 >> 7 != lVar5 >> 0x3f) {

    lVar5 = 0;

    do {

      if (*(int *)(lVar5 + 8 + lVar6) == 7) {

        uVar7 = FUN_1400c5f10(*(undefined4 *)(lVar5 + 0x48 + lVar6));

        fVar8 = (float)FUN_1402cfda0();

        fVar10 = *(float *)(param_1 + 0x13c);

        fVar9 = (float)FUN_1402cdc50(uVar7);

        fVar10 = fVar8 * fVar10 + fVar9 * *(float *)(param_1 + 0x138) +

                 *(float *)(*(longlong *)(param_1 + 0x40) + 0x44 + lVar5);

        if (fVar10 < *(float *)(param_1 + 0x130) - fVar1) {

          *param_3 = 1;

        }

        if (*(float *)(param_1 + 0x130) - fVar2 < fVar10) {

          *param_2 = 1;

        }

      }

      lVar6 = *(longlong *)(param_1 + 0x40);

      iVar4 = iVar4 + 1;

      lVar3 = *(longlong *)(param_1 + 0x48) - lVar6;

      lVar5 = lVar5 + 0xb8;

      lVar3 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar3),8) + lVar3;

    } while ((ulonglong)(longlong)iVar4 < (ulonglong)((lVar3 >> 7) - (lVar3 >> 0x3f)));

  }

  return;

}




