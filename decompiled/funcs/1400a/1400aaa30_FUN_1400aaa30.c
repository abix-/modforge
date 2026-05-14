// Address: 0x1400aaa30
// Ghidra name: FUN_1400aaa30
// ============ 0x1400aaa30 FUN_1400aaa30 (size=363) ============


void FUN_1400aaa30(undefined8 param_1,float *param_2,float param_3,float param_4,float param_5,

                  undefined4 param_6)



{

  float fVar1;

  float fVar2;

  char cVar3;

  longlong lVar4;

  float fVar5;

  float fVar6;

  float local_88;

  float local_84;

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  

  lVar4 = FUN_1400a9180(param_1,5,0);

  fVar1 = param_2[3];

  fVar2 = param_2[2];

  fVar5 = param_5 * DAT_140303354 + param_3;

  fVar6 = param_5 * DAT_140303354 + param_4;

  local_88 = (fVar1 * param_3 - fVar2 * param_4) + *param_2;

  local_84 = fVar1 * param_4 + fVar2 * param_3 + param_2[1];

  local_80 = (fVar1 * fVar5 - fVar2 * param_4) + *param_2;

  local_7c = fVar5 * fVar2 + fVar1 * param_4 + param_2[1];

  local_74 = fVar1 * fVar6 + fVar2 * param_3 + param_2[1];

  local_78 = (fVar1 * param_3 - fVar6 * fVar2) + *param_2;

  cVar3 = FUN_14000e0e0(lVar4,&local_88,3);

  *(undefined4 *)(lVar4 + 0x14c) = param_6;

  if (cVar3 == '\0') {

    *(undefined1 *)(lVar4 + 0x160) = 0;

  }

  return;

}




