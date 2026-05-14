// Address: 0x140165f10
// Ghidra name: FUN_140165f10
// ============ 0x140165f10 FUN_140165f10 (size=246) ============


void FUN_140165f10(longlong param_1,longlong param_2,int param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float *pfVar9;

  float *pfVar10;

  

  fVar8 = DAT_1403345c4;

  fVar7 = DAT_1403345bc;

  fVar6 = DAT_140334590;

  fVar5 = DAT_140334538;

  if (param_3 != 0) {

    pfVar10 = (float *)(param_1 + 8);

    pfVar9 = (float *)(param_2 + 0x14);

    do {

      fVar1 = *pfVar9;

      fVar2 = pfVar9[1];

      fVar3 = pfVar9[-1];

      pfVar10[-2] = pfVar9[-5] * fVar8 + fVar1 * fVar5;

      pfVar10[-1] = pfVar9[-4] * fVar8 + fVar2 * fVar5;

      *pfVar10 = pfVar9[-3] * fVar8;

      fVar4 = pfVar9[-2];

      pfVar9 = pfVar9 + 7;

      pfVar10[2] = fVar1 * fVar7 + fVar3 * fVar6;

      pfVar10[3] = fVar2 * fVar7 + fVar3 * fVar6;

      pfVar10[1] = fVar4;

      pfVar10 = pfVar10 + 6;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}




