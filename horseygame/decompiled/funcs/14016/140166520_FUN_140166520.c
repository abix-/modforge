// Address: 0x140166520
// Ghidra name: FUN_140166520
// ============ 0x140166520 FUN_140166520 (size=257) ============


void FUN_140166520(longlong param_1,longlong param_2,int param_3)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float *pfVar9;

  float *pfVar10;

  

  fVar8 = DAT_1403345ac;

  fVar7 = DAT_140334598;

  fVar6 = DAT_140334574;

  fVar5 = DAT_140334510;

  if (param_3 != 0) {

    pfVar10 = (float *)(param_1 + 8);

    pfVar9 = (float *)(param_2 + 0x1c);

    do {

      fVar2 = pfVar9[-1];

      fVar3 = *pfVar9;

      fVar4 = pfVar9[-5];

      pfVar10[-2] = pfVar9[-7] * fVar8 + fVar4 * fVar6 + fVar2 * fVar5;

      pfVar10[-1] = pfVar9[-6] * fVar8 + fVar4 * fVar6 + fVar3 * fVar5;

      *pfVar10 = pfVar9[-4];

      pfVar10[1] = pfVar9[-3] * fVar8 + fVar2 * fVar7;

      pfVar1 = pfVar9 + -2;

      pfVar9 = pfVar9 + 8;

      pfVar10[2] = *pfVar1 * fVar8 + fVar3 * fVar7;

      pfVar10 = pfVar10 + 5;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}




