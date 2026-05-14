// Address: 0x1400c6f10
// Ghidra name: FUN_1400c6f10
// ============ 0x1400c6f10 FUN_1400c6f10 (size=270) ============


float * FUN_1400c6f10(float *param_1,float *param_2,float *param_3,float param_4,float param_5,

                     float param_6)



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

  

  fVar1 = *param_2;

  fVar2 = *param_3;

  fVar7 = DAT_14039ca44 - param_6;

  fVar9 = param_6 * param_6 * param_6;

  fVar6 = fVar7 * fVar7 * fVar7;

  fVar5 = fVar7 * fVar7 * DAT_14030338c * param_6;

  fVar3 = param_2[1];

  fVar8 = fVar7 * DAT_14030338c * param_6 * param_6;

  fVar7 = param_3[1];

  fVar4 = param_3[1];

  *param_1 = (fVar1 + 0.0) * fVar5 + fVar6 * fVar1 + ((fVar1 - fVar2) * param_5 + fVar2) * fVar8 +

             fVar9 * fVar2;

  param_1[1] = ((param_3[1] - param_2[1]) * param_4 + param_2[1]) * fVar5 + fVar6 * fVar3 +

               (fVar4 + 0.0) * fVar8 + fVar9 * fVar7;

  return param_1;

}




