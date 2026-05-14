// Address: 0x140165810
// Ghidra name: FUN_140165810
// ============ 0x140165810 FUN_140165810 (size=223) ============


void FUN_140165810(longlong param_1,longlong param_2,int param_3)



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

  float *pfVar10;

  

  fVar8 = DAT_140334568;

  fVar7 = DAT_140334558;

  fVar6 = DAT_140334544;

  fVar5 = DAT_14030cd1c;

  if (param_3 != 0) {

    pfVar10 = (float *)(param_1 + 8);

    pfVar9 = (float *)(param_2 + 0x14);

    do {

      fVar2 = pfVar9[-1];

      fVar3 = *pfVar9;

      fVar4 = pfVar9[-3];

      pfVar10[-2] = pfVar9[-5] * fVar8 + fVar4 * fVar6 + fVar2 * fVar7 + fVar3 * fVar5;

      pfVar10[-1] = pfVar9[-4] * fVar8 + fVar4 * fVar6 + fVar2 * fVar5 + fVar3 * fVar7;

      pfVar1 = pfVar9 + -2;

      pfVar9 = pfVar9 + 6;

      *pfVar10 = *pfVar1;

      pfVar10 = pfVar10 + 3;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}




