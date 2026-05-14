// Address: 0x14000e620
// Ghidra name: FUN_14000e620
// ============ 0x14000e620 FUN_14000e620 (size=369) ============


void FUN_14000e620(longlong param_1,float *param_2,float *param_3)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float *pfVar4;

  ulonglong uVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  

  fVar2 = param_3[2];

  fVar3 = param_3[3];

  fVar9 = (*(float *)(param_1 + 0x18) * fVar3 - *(float *)(param_1 + 0x1c) * fVar2) + *param_3;

  fVar8 = *(float *)(param_1 + 0x1c) * fVar3 + *(float *)(param_1 + 0x18) * fVar2 + param_3[1];

  fVar10 = fVar8;

  fVar11 = fVar9;

  if (1 < *(int *)(param_1 + 0x98)) {

    pfVar4 = (float *)(param_1 + 0x20);

    uVar5 = (ulonglong)(*(int *)(param_1 + 0x98) - 1);

    do {

      pfVar1 = pfVar4 + 1;

      fVar6 = *pfVar4;

      pfVar4 = pfVar4 + 2;

      fVar7 = (fVar6 * fVar3 - *pfVar1 * fVar2) + *param_3;

      fVar6 = *pfVar1 * fVar3 + fVar6 * fVar2 + param_3[1];

      if (fVar7 <= fVar9) {

        fVar9 = fVar7;

      }

      if (fVar11 <= fVar7) {

        fVar11 = fVar7;

      }

      if (fVar6 <= fVar8) {

        fVar8 = fVar6;

      }

      if (fVar10 <= fVar6) {

        fVar10 = fVar6;

      }

      uVar5 = uVar5 - 1;

    } while (uVar5 != 0);

  }

  fVar2 = *(float *)(param_1 + 0xc);

  *param_2 = fVar9 - fVar2;

  param_2[1] = fVar8 - fVar2;

  param_2[2] = fVar2 + fVar11;

  param_2[3] = fVar2 + fVar10;

  return;

}




