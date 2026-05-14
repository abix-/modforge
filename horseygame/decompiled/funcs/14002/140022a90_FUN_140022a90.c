// Address: 0x140022a90
// Ghidra name: FUN_140022a90
// ============ 0x140022a90 FUN_140022a90 (size=948) ============


void FUN_140022a90(undefined8 *param_1,longlong param_2,float *param_3,longlong param_4,

                  float *param_5)



{

  float fVar1;

  float fVar2;

  int iVar3;

  float *pfVar4;

  longlong lVar5;

  int iVar6;

  int iVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  

  *(undefined4 *)((longlong)param_1 + 0x3c) = 0;

  fVar9 = *(float *)(param_2 + 0xc) + *(float *)(param_4 + 0xc);

  iVar7 = 0;

  fVar10 = ((*(float *)(param_4 + 0x10) * param_5[3] - *(float *)(param_4 + 0x14) * param_5[2]) +

           *param_5) - *param_3;

  fVar12 = (*(float *)(param_4 + 0x14) * param_5[3] + *(float *)(param_4 + 0x10) * param_5[2] +

           param_5[1]) - param_3[1];

  iVar3 = 0;

  fVar14 = fVar10 * param_3[3] + fVar12 * param_3[2];

  fVar12 = fVar12 * param_3[3] - fVar10 * param_3[2];

  fVar10 = DAT_14039ca8c;

  if (0 < (longlong)*(int *)(param_2 + 0x98)) {

    lVar5 = 0;

    pfVar4 = (float *)(param_2 + 0x5c);

    iVar6 = iVar3;

    do {

      fVar8 = (fVar14 - pfVar4[-0x11]) * pfVar4[-1] + (fVar12 - pfVar4[-0x10]) * *pfVar4;

      if (fVar9 < fVar8) {

        return;

      }

      iVar3 = iVar7;

      if (fVar8 <= fVar10) {

        iVar3 = iVar6;

        fVar8 = fVar10;

      }

      fVar10 = fVar8;

      iVar7 = iVar7 + 1;

      lVar5 = lVar5 + 1;

      pfVar4 = pfVar4 + 2;

      iVar6 = iVar3;

    } while (lVar5 < *(int *)(param_2 + 0x98));

  }

  iVar7 = iVar3 + 1;

  if (*(int *)(param_2 + 0x98) <= iVar3 + 1) {

    iVar7 = 0;

  }

  lVar5 = (longlong)iVar3;

  fVar8 = *(float *)(param_2 + 0x18 + (longlong)iVar7 * 8);

  fVar13 = *(float *)(param_2 + 0x1c + (longlong)iVar7 * 8);

  fVar1 = *(float *)(param_2 + 0x18 + lVar5 * 8);

  fVar2 = *(float *)(param_2 + 0x1c + lVar5 * 8);

  if (fVar10 < DAT_14039c9f0) {

    *(undefined4 *)((longlong)param_1 + 0x3c) = 1;

    *(undefined4 *)(param_1 + 7) = 1;

    param_1[5] = *(undefined8 *)(param_2 + 0x58 + lVar5 * 8);

    fVar10 = (fVar13 + fVar2) * DAT_14039ca34;

    *(float *)(param_1 + 6) = (fVar8 + fVar1) * DAT_14039ca34;

    *(float *)((longlong)param_1 + 0x34) = fVar10;

    *param_1 = *(undefined8 *)(param_4 + 0x10);

    *(undefined4 *)(param_1 + 2) = 0;

  }

  else {

    fVar16 = fVar12 - fVar2;

    fVar15 = fVar14 - fVar1;

    fVar10 = fVar14 - fVar8;

    fVar11 = fVar12 - fVar13;

    if (0.0 < (fVar13 - fVar2) * fVar16 + (fVar8 - fVar1) * fVar15) {

      if (0.0 < fVar10 * (fVar1 - fVar8) + fVar11 * (fVar2 - fVar13)) {

        fVar8 = (fVar8 + fVar1) * DAT_14039ca34;

        fVar13 = (fVar13 + fVar2) * DAT_14039ca34;

        if (fVar9 < (fVar12 - fVar13) * *(float *)(param_2 + 0x5c + lVar5 * 8) +

                    (fVar14 - fVar8) * *(float *)(param_2 + 0x58 + lVar5 * 8)) {

          return;

        }

        *(undefined4 *)((longlong)param_1 + 0x3c) = 1;

        *(undefined4 *)(param_1 + 7) = 1;

        param_1[5] = *(undefined8 *)(param_2 + 0x58 + lVar5 * 8);

      }

      else {

        if (fVar9 * fVar9 < fVar10 * fVar10 + fVar11 * fVar11) {

          return;

        }

        *(undefined4 *)((longlong)param_1 + 0x3c) = 1;

        *(float *)(param_1 + 5) = fVar10;

        *(float *)((longlong)param_1 + 0x2c) = fVar11;

        *(undefined4 *)(param_1 + 7) = 1;

        FUN_1400058e0();

      }

      *(float *)((longlong)param_1 + 0x34) = fVar13;

      *(float *)(param_1 + 6) = fVar8;

    }

    else {

      if (fVar9 * fVar9 < fVar15 * fVar15 + fVar16 * fVar16) {

        return;

      }

      *(undefined4 *)((longlong)param_1 + 0x3c) = 1;

      *(float *)(param_1 + 5) = fVar15;

      *(float *)((longlong)param_1 + 0x2c) = fVar16;

      *(undefined4 *)(param_1 + 7) = 1;

      FUN_1400058e0();

      *(float *)(param_1 + 6) = fVar1;

      *(float *)((longlong)param_1 + 0x34) = fVar2;

    }

    *param_1 = *(undefined8 *)(param_4 + 0x10);

    *(undefined4 *)(param_1 + 2) = 0;

  }

  return;

}




