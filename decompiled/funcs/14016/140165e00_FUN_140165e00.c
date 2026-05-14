// Address: 0x140165e00
// Ghidra name: FUN_140165e00
// ============ 0x140165e00 FUN_140165e00 (size=260) ============


void FUN_140165e00(longlong param_1,longlong param_2,int param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float *pfVar7;

  float *pfVar8;

  float fVar9;

  float fVar10;

  

  fVar6 = DAT_1403345ac;

  fVar5 = DAT_140334598;

  fVar4 = DAT_140334574;

  fVar3 = DAT_140334510;

  if (param_3 != 0) {

    pfVar8 = (float *)(param_1 + 8);

    pfVar7 = (float *)(param_2 + 0x14);

    do {

      fVar1 = *pfVar7;

      fVar2 = pfVar7[1];

      fVar9 = pfVar7[-3] * fVar4;

      fVar10 = pfVar7[-1] * fVar4;

      pfVar8[-2] = pfVar7[-5] * fVar6 + fVar9 + fVar1 * fVar3;

      pfVar8[-1] = pfVar7[-4] * fVar6 + fVar9 + fVar2 * fVar3;

      fVar9 = pfVar7[-2];

      pfVar7 = pfVar7 + 7;

      pfVar8[1] = fVar1 * fVar5 + fVar10;

      pfVar8[2] = fVar2 * fVar5 + fVar10;

      *pfVar8 = fVar9;

      pfVar8 = pfVar8 + 5;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}




