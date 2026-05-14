// Address: 0x140213000
// Ghidra name: FUN_140213000
// ============ 0x140213000 FUN_140213000 (size=215) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140213000(float *param_1,float param_2,float param_3,float param_4,float param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  

  fVar1 = DAT_140304be0;

  fVar6 = param_3 * DAT_140303fbc;

  fVar2 = param_2 * DAT_14030562c;

  fVar4 = param_4 * DAT_140304be0;

  *param_1 = param_2;

  fVar8 = param_3 * DAT_14030a7e0;

  fVar3 = param_2 * DAT_140303fbc;

  fVar7 = param_4 * DAT_14030a7e0;

  param_3 = param_3 * _DAT_1403539b8;

  param_4 = param_4 * DAT_140304c08;

  fVar5 = param_5 * fVar1;

  param_1[1] = ((fVar6 - fVar2) - fVar4) + param_5;

  param_1[2] = ((fVar3 - param_3) + param_4) - fVar5;

  param_1[3] = ((fVar8 - param_2 * fVar1) - fVar7) + fVar5;

  return;

}




