// Address: 0x1400a9750
// Ghidra name: FUN_1400a9750
// ============ 0x1400a9750 FUN_1400a9750 (size=570) ============


longlong FUN_1400a9750(undefined8 param_1,float *param_2,float param_3,float param_4,float param_5,

                      float param_6,float param_7,float param_8,undefined4 param_9,

                      undefined8 param_10,float param_11)



{

  float fVar1;

  float fVar2;

  char cVar3;

  longlong lVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  undefined4 uVar10;

  float fVar11;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_9c;

  float local_98;

  float local_94;

  float local_90;

  float local_8c;

  

  if (param_5 * param_6 * param_11 < DAT_14039ca0c) {

    param_11 = DAT_14039ca0c / (param_5 * param_6);

  }

  fVar8 = param_5;

  fVar9 = param_6 * param_7;

  uVar10 = param_9;

  fVar11 = param_11;

  FUN_1400a9360();

  lVar4 = FUN_1400a9180(param_1,param_9,param_11);

  fVar1 = param_2[2];

  fVar7 = param_6 * param_7 + param_4;

  fVar2 = param_2[3];

  local_90 = *param_2;

  fVar5 = fVar1 * fVar7;

  param_5 = param_3 + param_5;

  fVar7 = fVar2 * fVar7;

  local_94 = param_2[1];

  local_a8 = (fVar2 * param_3 - fVar5) + local_90;

  local_a4 = fVar1 * param_3 + fVar7 + local_94;

  fVar6 = fVar1 * (param_4 + param_6);

  local_a0 = (fVar2 * param_5 - fVar5) + local_90;

  local_9c = fVar1 * param_5 + fVar7 + local_94;

  fVar5 = fVar2 * (param_4 + param_6);

  local_98 = (fVar2 * (param_5 + param_8) - fVar6) + local_90;

  local_8c = fVar1 * (param_3 + param_8) + fVar5 + local_94;

  local_94 = (param_5 + param_8) * fVar1 + fVar5 + local_94;

  local_90 = (fVar2 * (param_3 + param_8) - fVar6) + local_90;

  cVar3 = FUN_14000e0e0(lVar4,&local_a8,4,fVar7,fVar8,fVar9,uVar10,fVar11);

  if (cVar3 == '\0') {

    *(undefined1 *)(lVar4 + 0x160) = 0;

  }

  return lVar4;

}




