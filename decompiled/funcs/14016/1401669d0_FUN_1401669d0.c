// Address: 0x1401669d0
// Ghidra name: FUN_1401669d0
// ============ 0x1401669d0 FUN_1401669d0 (size=404) ============


void FUN_1401669d0(float *param_1,longlong param_2,int param_3)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float *pfVar15;

  

  fVar14 = DAT_140334530;

  fVar13 = DAT_140334520;

  fVar12 = DAT_140334514;

  fVar11 = DAT_1403344f4;

  fVar10 = DAT_1403344dc;

  fVar9 = DAT_1403344c8;

  fVar8 = DAT_1403344c0;

  if (param_3 != 0) {

    pfVar15 = (float *)(param_2 + 0x14);

    do {

      fVar2 = pfVar15[-1];

      fVar3 = *pfVar15;

      fVar4 = pfVar15[1];

      fVar5 = pfVar15[2];

      fVar6 = pfVar15[-3];

      fVar7 = pfVar15[-2];

      *param_1 = pfVar15[-5] * fVar14 + fVar6 * fVar11 + fVar7 * fVar8 + fVar2 * fVar12 +

                 fVar3 * fVar10 + fVar4 * fVar13 + fVar5 * fVar9;

      pfVar1 = pfVar15 + -4;

      pfVar15 = pfVar15 + 8;

      param_1[1] = *pfVar1 * fVar14 + fVar6 * fVar11 + fVar7 * fVar8 + fVar2 * fVar10 +

                   fVar3 * fVar12 + fVar4 * fVar9 + fVar5 * fVar13;

      param_1 = param_1 + 2;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}




