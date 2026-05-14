// Address: 0x140166130
// Ghidra name: FUN_140166130
// ============ 0x140166130 FUN_140166130 (size=314) ============


void FUN_140166130(longlong param_1,longlong param_2,int param_3)



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

  float fVar11;

  float fVar12;

  float fVar13;

  

  fVar8 = DAT_1403345a0;

  fVar7 = DAT_14033458c;

  fVar6 = DAT_14033456c;

  fVar5 = DAT_140334504;

  fVar4 = DAT_1403344b4;

  if (param_3 != 0) {

    pfVar9 = (float *)(param_2 + 0x14);

    pfVar10 = (float *)(param_1 + 8);

    do {

      fVar1 = *pfVar9;

      fVar2 = pfVar9[1];

      fVar12 = pfVar9[-2] * fVar4;

      fVar11 = pfVar9[-3] * fVar6;

      fVar13 = pfVar9[-1] * fVar6 + fVar12;

      pfVar10[-2] = pfVar9[-5] * fVar8 + fVar11 + fVar12 + fVar1 * fVar5;

      fVar3 = pfVar9[-4];

      pfVar9 = pfVar9 + 7;

      *pfVar10 = fVar1 * fVar7 + fVar13;

      pfVar10[1] = fVar2 * fVar7 + fVar13;

      pfVar10[-1] = fVar3 * fVar8 + fVar11 + fVar12 + fVar2 * fVar5;

      pfVar10 = pfVar10 + 4;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}




