// Address: 0x140023180
// Ghidra name: FUN_140023180
// ============ 0x140023180 FUN_140023180 (size=853) ============


undefined8

FUN_140023180(int *param_1,longlong param_2,float *param_3,longlong param_4,float *param_5)



{

  int iVar1;

  float *pfVar2;

  int iVar3;

  longlong lVar4;

  int iVar5;

  int iVar6;

  longlong lVar7;

  longlong lVar8;

  undefined8 uVar9;

  undefined8 uVar10;

  undefined8 uVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  

  iVar1 = *(int *)(param_2 + 0x98);

  lVar8 = (longlong)iVar1;

  fVar12 = param_3[3];

  fVar16 = param_3[2];

  iVar5 = 0;

  iVar3 = 0;

  lVar4 = 0;

  fVar14 = ((*(float *)(param_4 + 0x10) * param_5[3] - *(float *)(param_4 + 0x14) * param_5[2]) +

           *param_5) -

           ((*(float *)(param_2 + 0x10) * fVar12 - *(float *)(param_2 + 0x14) * fVar16) + *param_3);

  fVar15 = (*(float *)(param_4 + 0x14) * param_5[3] + *(float *)(param_4 + 0x10) * param_5[2] +

           param_5[1]) -

           (*(float *)(param_2 + 0x14) * fVar12 + *(float *)(param_2 + 0x10) * fVar16 + param_3[1]);

  fVar13 = fVar14 * fVar12 + fVar15 * fVar16;

  fVar16 = fVar15 * fVar12 - fVar14 * fVar16;

  fVar12 = DAT_14039ca8c;

  if (3 < lVar8) {

    pfVar2 = (float *)(param_2 + 100);

    lVar7 = (lVar8 - 4U >> 2) + 1;

    lVar4 = lVar7 * 4;

    do {

      fVar15 = fVar16 * pfVar2[-2] + fVar13 * pfVar2[-3];

      fVar14 = fVar12;

      if (fVar12 < fVar15) {

        fVar14 = fVar15;

      }

      iVar6 = iVar3;

      if (fVar15 <= fVar12) {

        iVar6 = iVar5;

      }

      fVar15 = fVar13 * pfVar2[-1] + fVar16 * *pfVar2;

      fVar12 = fVar14;

      if (fVar14 < fVar15) {

        fVar12 = fVar15;

      }

      iVar5 = iVar3 + 1;

      if (fVar15 <= fVar14) {

        iVar5 = iVar6;

      }

      fVar15 = fVar16 * pfVar2[2] + fVar13 * pfVar2[1];

      fVar14 = fVar12;

      if (fVar12 < fVar15) {

        fVar14 = fVar15;

      }

      iVar6 = iVar3 + 2;

      if (fVar15 <= fVar12) {

        iVar6 = iVar5;

      }

      fVar12 = fVar16 * pfVar2[4] + fVar13 * pfVar2[3];

      iVar5 = iVar3 + 3;

      if (fVar12 <= fVar14) {

        iVar5 = iVar6;

        fVar12 = fVar14;

      }

      iVar3 = iVar3 + 4;

      pfVar2 = pfVar2 + 8;

      lVar7 = lVar7 + -1;

    } while (lVar7 != 0);

  }

  for (; lVar4 < lVar8; lVar4 = lVar4 + 1) {

    fVar14 = fVar16 * *(float *)(param_2 + 0x5c + lVar4 * 8) +

             fVar13 * *(float *)(param_2 + 0x58 + lVar4 * 8);

    iVar6 = iVar3;

    if (fVar14 <= fVar12) {

      iVar6 = iVar5;

      fVar14 = fVar12;

    }

    iVar3 = iVar3 + 1;

    fVar12 = fVar14;

    iVar5 = iVar6;

  }

  uVar9 = FUN_140022e50(param_2,param_3,iVar5,param_4,param_5);

  iVar3 = iVar5;

  if (iVar5 + -1 < 0) {

    iVar3 = iVar1;

  }

  uVar10 = FUN_140022e50(param_2,param_3,iVar3 + -1,param_4,param_5);

  iVar6 = iVar5 + 1;

  if (iVar1 <= iVar6) {

    iVar6 = 0;

  }

  uVar11 = FUN_140022e50(param_2,param_3,iVar6,param_4,param_5);

  if (((float)uVar10 <= (float)uVar9) || ((float)uVar10 <= (float)uVar11)) {

    if ((float)uVar11 <= (float)uVar9) {

      *param_1 = iVar5;

      return uVar9;

    }

    lVar4 = 1;

  }

  else {

    lVar4 = -1;

    iVar6 = iVar3 + -1;

    uVar11 = uVar10;

  }

  do {

    uVar9 = uVar11;

    iVar5 = iVar6;

    if (lVar4 == -1) {

      iVar3 = iVar5;

      if (iVar5 + -1 < 0) {

        iVar3 = iVar1;

      }

      iVar6 = iVar3 + -1;

    }

    else {

      iVar6 = 0;

      if (iVar5 + 1 < iVar1) {

        iVar6 = iVar5 + 1;

      }

    }

    uVar11 = FUN_140022e50(param_2,param_3,iVar6,param_4,param_5);

  } while ((float)uVar9 < (float)uVar11);

  *param_1 = iVar5;

  return uVar9;

}




