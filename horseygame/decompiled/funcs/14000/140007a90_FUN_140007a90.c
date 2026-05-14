// Address: 0x140007a90
// Ghidra name: FUN_140007a90
// ============ 0x140007a90 FUN_140007a90 (size=521) ============


float * FUN_140007a90(float *param_1,float *param_2,float *param_3)



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

  float fVar13;

  float fVar14;

  

  fVar1 = param_1[7];

  fVar2 = param_1[5];

  fVar3 = param_1[8];

  fVar4 = param_1[4];

  fVar5 = param_1[3];

  fVar6 = param_1[6];

  fVar11 = fVar4 * fVar3 - fVar2 * fVar1;

  fVar13 = fVar6 * fVar2 - fVar5 * fVar3;

  fVar14 = fVar5 * fVar1 - fVar6 * fVar4;

  fVar12 = param_1[1] * fVar13 + *param_1 * fVar11 + param_1[2] * fVar14;

  if (fVar12 != 0.0) {

    fVar12 = DAT_14039ca44 / fVar12;

  }

  fVar7 = param_3[1];

  fVar8 = *param_3;

  fVar9 = param_3[2];

  fVar10 = *param_1;

  *param_2 = (fVar8 * fVar11 + fVar7 * fVar13 + fVar9 * fVar14) * fVar12;

  fVar11 = *param_1;

  fVar13 = param_1[1];

  fVar14 = param_1[2];

  param_2[1] = ((fVar7 * fVar3 - fVar9 * fVar1) * fVar10 +

                (fVar9 * fVar6 - fVar8 * fVar3) * param_1[1] +

               (fVar8 * fVar1 - fVar7 * fVar6) * param_1[2]) * fVar12;

  param_2[2] = ((fVar9 * fVar4 - fVar7 * fVar2) * fVar11 + (fVar8 * fVar2 - fVar9 * fVar5) * fVar13

               + (fVar7 * fVar5 - fVar8 * fVar4) * fVar14) * fVar12;

  return param_2;

}




