// Address: 0x140166630
// Ghidra name: FUN_140166630
// ============ 0x140166630 FUN_140166630 (size=224) ============


void FUN_140166630(longlong param_1,longlong param_2,int param_3)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float *pfVar7;

  float *pfVar8;

  

  fVar6 = DAT_1403345b0;

  fVar5 = DAT_1403345a8;

  fVar4 = DAT_140334518;

  if (param_3 != 0) {

    pfVar8 = (float *)(param_1 + 8);

    pfVar7 = (float *)(param_2 + 0x1c);

    do {

      fVar2 = pfVar7[-1];

      fVar3 = *pfVar7;

      pfVar8[-2] = pfVar7[-7] * fVar6 + fVar2 * fVar4;

      pfVar8[-1] = pfVar7[-6] * fVar6 + fVar3 * fVar4;

      *pfVar8 = pfVar7[-5] * fVar6;

      pfVar8[1] = pfVar7[-4];

      pfVar8[2] = pfVar7[-3] * fVar6 + fVar2 * fVar5;

      pfVar1 = pfVar7 + -2;

      pfVar7 = pfVar7 + 8;

      pfVar8[3] = *pfVar1 * fVar6 + fVar3 * fVar5;

      pfVar8 = pfVar8 + 6;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}




