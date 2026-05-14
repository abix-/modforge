// Address: 0x140165d00
// Ghidra name: FUN_140165d00
// ============ 0x140165d00 FUN_140165d00 (size=256) ============


void FUN_140165d00(longlong param_1,longlong param_2,int param_3)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float *pfVar8;

  float *pfVar9;

  float fVar10;

  float fVar11;

  

  fVar7 = DAT_140334554;

  fVar6 = DAT_140334548;

  fVar5 = DAT_140334518;

  fVar4 = DAT_1403344d8;

  if (param_3 != 0) {

    pfVar9 = (float *)(param_1 + 8);

    pfVar8 = (float *)(param_2 + 0x18);

    do {

      fVar2 = pfVar8[-1];

      fVar3 = *pfVar8;

      fVar11 = pfVar8[-4] * fVar5;

      fVar10 = pfVar8[-2] * fVar5;

      pfVar9[-2] = pfVar8[-6] * fVar7 + fVar11 + fVar10 + fVar2 * fVar6 + fVar3 * fVar4;

      pfVar9[-1] = pfVar8[-5] * fVar7 + fVar11 + fVar10 + fVar2 * fVar4 + fVar3 * fVar6;

      pfVar1 = pfVar8 + -3;

      pfVar8 = pfVar8 + 7;

      *pfVar9 = *pfVar1;

      pfVar9 = pfVar9 + 3;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}




