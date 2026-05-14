// Address: 0x140075120
// Ghidra name: FUN_140075120
// ============ 0x140075120 FUN_140075120 (size=359) ============


undefined8 * FUN_140075120(longlong param_1,undefined8 *param_2,float *param_3)



{

  float fVar1;

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

  longlong lVar14;

  

  fVar1 = *param_3;

  fVar2 = param_3[1];

  fVar3 = param_3[2];

  fVar4 = param_3[3];

  fVar5 = param_3[4];

  fVar6 = param_3[5];

  param_1 = param_1 - (longlong)param_2;

  fVar7 = param_3[6];

  fVar8 = param_3[7];

  *param_2 = 0;

  param_2[1] = 0;

  fVar9 = param_3[8];

  lVar14 = 3;

  param_2[2] = 0;

  param_2[3] = 0;

  *(undefined4 *)(param_2 + 4) = 0;

  pfVar13 = (float *)((longlong)param_2 + 4);

  do {

    fVar10 = *(float *)(param_1 + -4 + (longlong)pfVar13);

    fVar11 = *(float *)(param_1 + (longlong)pfVar13);

    fVar12 = *(float *)(param_1 + 4 + (longlong)pfVar13);

    pfVar13[-1] = fVar10 * fVar1 + pfVar13[-1] + fVar11 * fVar4 + fVar12 * fVar7;

    *pfVar13 = fVar10 * fVar2 + *pfVar13 + fVar11 * fVar5 + fVar12 * fVar8;

    pfVar13[1] = fVar3 * fVar10 + pfVar13[1] + fVar11 * fVar6 + fVar12 * fVar9;

    pfVar13 = pfVar13 + 3;

    lVar14 = lVar14 + -1;

  } while (lVar14 != 0);

  return param_2;

}




