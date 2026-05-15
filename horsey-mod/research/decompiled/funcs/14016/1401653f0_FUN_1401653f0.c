// Address: 0x1401653f0
// Ghidra name: FUN_1401653f0
// ============ 0x1401653f0 FUN_1401653f0 (size=175) ============


void FUN_1401653f0(longlong param_1,longlong param_2,int param_3)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float *pfVar7;

  float *pfVar8;

  

  fVar6 = DAT_140334588;

  fVar5 = DAT_140334578;

  fVar4 = DAT_140334534;

  if (param_3 != 0) {

    pfVar8 = (float *)(param_1 + 8);

    pfVar7 = (float *)(param_2 + 0x10);

    do {

      fVar2 = pfVar7[-1];

      fVar3 = *pfVar7;

      pfVar8[-2] = pfVar7[-4] * fVar6 + fVar2 * fVar5 + fVar3 * fVar4;

      pfVar8[-1] = pfVar7[-3] * fVar6 + fVar2 * fVar4 + fVar3 * fVar5;

      pfVar1 = pfVar7 + -2;

      pfVar7 = pfVar7 + 5;

      *pfVar8 = *pfVar1;

      pfVar8 = pfVar8 + 3;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}




