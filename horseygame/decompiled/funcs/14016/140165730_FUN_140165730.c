// Address: 0x140165730
// Ghidra name: FUN_140165730
// ============ 0x140165730 FUN_140165730 (size=214) ============


void FUN_140165730(float *param_1,longlong param_2,int param_3)



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

  

  fVar8 = DAT_14033457c;

  fVar7 = DAT_140334564;

  fVar6 = DAT_140334524;

  fVar5 = DAT_1403344e0;

  if (param_3 != 0) {

    pfVar9 = (float *)(param_2 + 0x10);

    do {

      fVar2 = pfVar9[-1];

      fVar3 = *pfVar9;

      fVar4 = pfVar9[-2];

      *param_1 = pfVar9[-4] * fVar8 + fVar4 * fVar5 + fVar2 * fVar7 + fVar3 * fVar6;

      pfVar1 = pfVar9 + -3;

      pfVar9 = pfVar9 + 5;

      param_1[1] = *pfVar1 * fVar8 + fVar4 * fVar5 + fVar2 * fVar6 + fVar3 * fVar7;

      param_1 = param_1 + 2;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}




