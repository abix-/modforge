// Address: 0x1400a9360
// Ghidra name: FUN_1400a9360
// ============ 0x1400a9360 FUN_1400a9360 (size=502) ============


longlong FUN_1400a9360(undefined8 param_1,float *param_2,float param_3,float param_4,float param_5,

                      float param_6,undefined4 param_7,float param_8)



{

  float fVar1;

  char cVar2;

  longlong lVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float local_c8;

  float local_c4;

  float local_c0;

  float local_bc;

  float local_b8;

  float local_b4;

  float local_b0;

  float local_ac;

  

  fVar4 = param_5 * param_6 * param_8;

  if (fVar4 < DAT_14039ca0c) {

    param_8 = DAT_14039ca0c / (param_5 * param_6);

  }

  lVar3 = FUN_1400a9180(fVar4,param_7,param_8);

  fVar4 = param_2[3];

  fVar1 = param_2[2];

  local_b0 = *param_2;

  local_ac = param_2[1];

  fVar6 = fVar4 * (param_3 + param_5);

  local_c8 = (fVar4 * param_3 - fVar1 * param_4) + local_b0;

  fVar5 = fVar1 * (param_3 + param_5);

  fVar8 = fVar4 * (param_4 + param_6);

  fVar7 = fVar1 * (param_4 + param_6);

  local_c4 = fVar4 * param_4 + fVar1 * param_3 + local_ac;

  local_c0 = (fVar6 - fVar1 * param_4) + local_b0;

  local_b8 = (fVar6 - fVar7) + local_b0;

  local_b0 = (fVar4 * param_3 - fVar7) + local_b0;

  local_bc = fVar5 + fVar4 * param_4 + local_ac;

  local_b4 = fVar8 + fVar5 + local_ac;

  local_ac = fVar8 + fVar1 * param_3 + local_ac;

  cVar2 = FUN_14000e0e0(lVar3,&local_c8,4);

  if (cVar2 == '\0') {

    *(undefined1 *)(lVar3 + 0x160) = 0;

  }

  return lVar3;

}




