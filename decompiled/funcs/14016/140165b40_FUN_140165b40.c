// Address: 0x140165b40
// Ghidra name: FUN_140165b40
// ============ 0x140165b40 FUN_140165b40 (size=168) ============


void FUN_140165b40(longlong param_1,longlong param_2,int param_3)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float *pfVar6;

  float *pfVar7;

  float fVar8;

  

  fVar5 = DAT_1403345b8;

  fVar4 = DAT_140334580;

  fVar3 = DAT_1403344b8;

  if (param_3 != 0) {

    pfVar6 = (float *)(param_2 + 0xc);

    pfVar7 = (float *)(param_1 + 8);

    do {

      fVar2 = pfVar6[-1];

      fVar8 = *pfVar6 * fVar3;

      pfVar7[-2] = pfVar6[-3] * fVar5 + fVar2 * fVar4 + fVar8;

      pfVar7[-1] = pfVar6[-2] * fVar5 + fVar2 * fVar4 + fVar8;

      *pfVar7 = pfVar6[1] * fVar5 + fVar8;

      pfVar1 = pfVar6 + 2;

      pfVar6 = pfVar6 + 6;

      pfVar7[1] = *pfVar1 * fVar5 + fVar8;

      pfVar7 = pfVar7 + 4;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}




