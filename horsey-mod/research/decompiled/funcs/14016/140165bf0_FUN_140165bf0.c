// Address: 0x140165bf0
// Ghidra name: FUN_140165bf0
// ============ 0x140165bf0 FUN_140165bf0 (size=262) ============


void FUN_140165bf0(float *param_1,longlong param_2,int param_3)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float *pfVar11;

  

  fVar10 = DAT_140334560;

  fVar9 = DAT_140334550;

  fVar8 = DAT_14033452c;

  fVar7 = DAT_1403344f8;

  fVar6 = DAT_1403344cc;

  if (param_3 != 0) {

    pfVar11 = (float *)(param_2 + 0x14);

    do {

      fVar2 = pfVar11[-1];

      fVar3 = *pfVar11;

      fVar4 = pfVar11[-3];

      fVar5 = pfVar11[-2];

      *param_1 = pfVar11[-5] * fVar10 + fVar4 * fVar8 + fVar5 * fVar6 + fVar2 * fVar9 +

                 fVar3 * fVar7;

      pfVar1 = pfVar11 + -4;

      pfVar11 = pfVar11 + 6;

      param_1[1] = *pfVar1 * fVar10 + fVar4 * fVar8 + fVar5 * fVar6 + fVar2 * fVar7 + fVar3 * fVar9;

      param_1 = param_1 + 2;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}




