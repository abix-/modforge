// Address: 0x140165510
// Ghidra name: FUN_140165510
// ============ 0x140165510 FUN_140165510 (size=194) ============


void FUN_140165510(longlong param_1,longlong param_2,int param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float *pfVar6;

  float *pfVar7;

  

  fVar5 = DAT_14039ca34;

  fVar4 = DAT_1403345cc;

  fVar3 = DAT_14030d01c;

  pfVar7 = (float *)(param_2 + -0x14 + (longlong)(param_3 * 5) * 4);

  pfVar6 = (float *)(param_1 + (longlong)(param_3 * 7 + -7) * 4);

  for (; param_3 != 0; param_3 = param_3 + -1) {

    fVar1 = pfVar7[3];

    fVar2 = pfVar7[4];

    pfVar6[5] = fVar1 * fVar4;

    pfVar6[6] = fVar2 * fVar4;

    pfVar6[4] = fVar1 * fVar5 + fVar2 * fVar5;

    pfVar6[3] = pfVar7[2];

    pfVar6[2] = 0.0;

    pfVar6[1] = pfVar7[1] * fVar3;

    fVar1 = *pfVar7;

    pfVar7 = pfVar7 + -5;

    *pfVar6 = fVar1 * fVar3;

    pfVar6 = pfVar6 + -7;

  }

  return;

}




