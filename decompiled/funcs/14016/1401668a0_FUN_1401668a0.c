// Address: 0x1401668a0
// Ghidra name: FUN_1401668a0
// ============ 0x1401668a0 FUN_1401668a0 (size=304) ============


void FUN_1401668a0(longlong param_1,longlong param_2,int param_3)



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

  float *pfVar10;

  float *pfVar11;

  float fVar12;

  

  fVar9 = DAT_1403345a4;

  fVar8 = DAT_140334594;

  fVar7 = DAT_140334570;

  fVar6 = DAT_140334508;

  fVar5 = DAT_1403344b0;

  if (param_3 != 0) {

    pfVar10 = (float *)(param_2 + 0x1c);

    pfVar11 = (float *)(param_1 + 8);

    do {

      fVar2 = pfVar10[-1];

      fVar3 = *pfVar10;

      fVar4 = pfVar10[-5];

      fVar12 = pfVar10[-4] * fVar5;

      pfVar11[-2] = pfVar10[-7] * fVar9 + fVar4 * fVar7 + fVar12 + fVar2 * fVar6;

      pfVar11[-1] = pfVar10[-6] * fVar9 + fVar4 * fVar7 + fVar12 + fVar3 * fVar6;

      *pfVar11 = pfVar10[-3] * fVar9 + fVar12 + fVar2 * fVar8;

      pfVar1 = pfVar10 + -2;

      pfVar10 = pfVar10 + 8;

      pfVar11[1] = *pfVar1 * fVar9 + fVar12 + fVar3 * fVar8;

      pfVar11 = pfVar11 + 4;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}




