// Address: 0x140167290
// Ghidra name: FUN_140167290
// ============ 0x140167290 FUN_140167290 (size=152) ============


void FUN_140167290(float *param_1,longlong param_2,int param_3)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float *pfVar7;

  

  fVar6 = DAT_140334588;

  fVar5 = DAT_140334578;

  fVar4 = DAT_140334534;

  if (param_3 != 0) {

    pfVar7 = (float *)(param_2 + 0xc);

    do {

      fVar2 = pfVar7[-1];

      fVar3 = *pfVar7;

      *param_1 = pfVar7[-3] * fVar6 + fVar2 * fVar5 + fVar3 * fVar4;

      pfVar1 = pfVar7 + -2;

      pfVar7 = pfVar7 + 4;

      param_1[1] = *pfVar1 * fVar6 + fVar2 * fVar4 + fVar3 * fVar5;

      param_1 = param_1 + 2;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}




