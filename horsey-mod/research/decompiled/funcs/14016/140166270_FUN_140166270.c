// Address: 0x140166270
// Ghidra name: FUN_140166270
// ============ 0x140166270 FUN_140166270 (size=308) ============


void FUN_140166270(float *param_1,longlong param_2,int param_3)



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

  float *pfVar10;

  float fVar11;

  float fVar12;

  

  fVar9 = DAT_14033454c;

  fVar8 = DAT_14033453c;

  fVar7 = DAT_14033450c;

  fVar6 = DAT_1403344d4;

  fVar5 = DAT_1403344c4;

  if (param_3 != 0) {

    pfVar10 = (float *)(param_2 + 0x18);

    do {

      fVar2 = pfVar10[-1];

      fVar3 = *pfVar10;

      fVar4 = pfVar10[-3];

      fVar12 = pfVar10[-4] * fVar7;

      fVar11 = pfVar10[-2] * fVar7;

      *param_1 = pfVar10[-6] * fVar9 + fVar12 + fVar4 * fVar5 + fVar11 + fVar2 * fVar8 +

                 fVar3 * fVar6;

      pfVar1 = pfVar10 + -5;

      pfVar10 = pfVar10 + 7;

      param_1[1] = *pfVar1 * fVar9 + fVar12 + fVar4 * fVar5 + fVar11 + fVar2 * fVar6 + fVar3 * fVar8

      ;

      param_1 = param_1 + 2;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}




