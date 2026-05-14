// Address: 0x1400228d0
// Ghidra name: FUN_1400228d0
// ============ 0x1400228d0 FUN_1400228d0 (size=437) ============


undefined4 * FUN_1400228d0(longlong param_1,undefined4 *param_2)



{

  char cVar1;

  float *pfVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  

  lVar5 = (longlong)*(int *)(param_1 + 0x80);

  lVar3 = 0;

  cVar1 = *(char *)(param_1 + 0xf8);

  *param_2 = 1;

  param_2[1] = (uint)(cVar1 == '\0');

  param_2[2] = 0x7f7fffff;

  fVar6 = DAT_14039ca64;

  if (lVar5 < 4) {

    if (0 < lVar5) {

      fVar8 = *(float *)(param_1 + 0xa4);

      fVar9 = *(float *)(param_1 + 0xa8);

      fVar10 = *(float *)(param_1 + 0xd4);

      fVar11 = *(float *)(param_1 + 0xd8);

      goto LAB_140022a3e;

    }

  }

  else {

    fVar8 = *(float *)(param_1 + 0xa4);

    fVar9 = *(float *)(param_1 + 0xa8);

    pfVar2 = (float *)(param_1 + 8);

    fVar10 = *(float *)(param_1 + 0xd4);

    fVar11 = *(float *)(param_1 + 0xd8);

    lVar4 = (lVar5 - 4U >> 2) + 1;

    lVar3 = lVar4 * 4;

    do {

      fVar7 = (pfVar2[-1] - fVar9) * fVar11 + (pfVar2[-2] - fVar8) * fVar10;

      if (fVar7 < fVar6) {

        param_2[2] = fVar7;

        fVar6 = fVar7;

      }

      fVar7 = (pfVar2[1] - fVar9) * fVar11 + (*pfVar2 - fVar8) * fVar10;

      if (fVar7 < fVar6) {

        param_2[2] = fVar7;

        fVar6 = fVar7;

      }

      fVar7 = (pfVar2[3] - fVar9) * fVar11 + (pfVar2[2] - fVar8) * fVar10;

      if (fVar7 < fVar6) {

        param_2[2] = fVar7;

        fVar6 = fVar7;

      }

      fVar7 = (pfVar2[5] - fVar9) * fVar11 + (pfVar2[4] - fVar8) * fVar10;

      if (fVar7 < fVar6) {

        param_2[2] = fVar7;

        fVar6 = fVar7;

      }

      pfVar2 = pfVar2 + 8;

      lVar4 = lVar4 + -1;

    } while (lVar4 != 0);

    for (; lVar3 < lVar5; lVar3 = lVar3 + 1) {

LAB_140022a3e:

      fVar7 = (*(float *)(param_1 + 4 + lVar3 * 8) - fVar9) * fVar11 +

              (*(float *)(param_1 + lVar3 * 8) - fVar8) * fVar10;

      if (fVar7 < fVar6) {

        param_2[2] = fVar7;

        fVar6 = fVar7;

      }

    }

  }

  return param_2;

}




