// Address: 0x1401663b0
// Ghidra name: FUN_1401663b0
// ============ 0x1401663b0 FUN_1401663b0 (size=358) ============


void FUN_1401663b0(longlong param_1,longlong param_2,int param_3)



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

  float fVar11;

  float fVar12;

  float *pfVar13;

  float *pfVar14;

  

  fVar12 = DAT_140334540;

  fVar11 = DAT_140334528;

  fVar10 = DAT_14033451c;

  fVar9 = DAT_1403344fc;

  fVar8 = DAT_1403344e4;

  fVar7 = DAT_1403344d0;

  if (param_3 != 0) {

    pfVar14 = (float *)(param_1 + 8);

    pfVar13 = (float *)(param_2 + 0x14);

    do {

      fVar2 = pfVar13[-1];

      fVar3 = *pfVar13;

      fVar4 = pfVar13[1];

      fVar5 = pfVar13[2];

      fVar6 = pfVar13[-3];

      pfVar14[-2] = pfVar13[-5] * fVar12 + fVar6 * fVar9 + fVar2 * fVar10 + fVar3 * fVar8 +

                    fVar4 * fVar11 + fVar5 * fVar7;

      pfVar14[-1] = pfVar13[-4] * fVar12 + fVar6 * fVar9 + fVar2 * fVar8 + fVar3 * fVar10 +

                    fVar4 * fVar7 + fVar5 * fVar11;

      pfVar1 = pfVar13 + -2;

      pfVar13 = pfVar13 + 8;

      *pfVar14 = *pfVar1;

      pfVar14 = pfVar14 + 3;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}




