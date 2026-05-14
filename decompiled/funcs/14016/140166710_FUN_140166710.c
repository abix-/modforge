// Address: 0x140166710
// Ghidra name: FUN_140166710
// ============ 0x140166710 FUN_140166710 (size=226) ============


void FUN_140166710(longlong param_1,longlong param_2,int param_3)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float *pfVar7;

  float *pfVar8;

  

  fVar6 = DAT_1403345b4;

  fVar5 = DAT_14033459c;

  fVar4 = DAT_14033455c;

  if (param_3 != 0) {

    pfVar8 = (float *)(param_1 + 8);

    pfVar7 = (float *)(param_2 + 0x14);

    do {

      fVar2 = pfVar7[-1];

      fVar3 = *pfVar7;

      pfVar8[-2] = pfVar7[-5] * fVar6;

      pfVar8[-1] = pfVar7[-4] * fVar6;

      *pfVar8 = pfVar7[-3] * fVar6;

      pfVar8[1] = pfVar7[-2];

      pfVar8[2] = fVar2 * fVar4 + fVar3 * fVar4;

      pfVar8[3] = pfVar7[1] * fVar6 + fVar2 * fVar5;

      pfVar1 = pfVar7 + 2;

      pfVar7 = pfVar7 + 8;

      pfVar8[4] = *pfVar1 * fVar6 + fVar3 * fVar5;

      pfVar8 = pfVar8 + 7;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}




