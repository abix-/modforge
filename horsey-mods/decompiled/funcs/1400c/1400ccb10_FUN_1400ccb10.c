// Address: 0x1400ccb10
// Ghidra name: FUN_1400ccb10
// ============ 0x1400ccb10 FUN_1400ccb10 (size=181) ============


void FUN_1400ccb10(longlong param_1,longlong *param_2,char param_3)



{

  float *pfVar1;

  longlong lVar2;

  undefined4 uVar3;

  float fVar4;

  float fVar5;

  longlong *local_res10;

  

  pfVar1 = *(float **)(param_1 + 0x78);

  local_res10 = param_2;

  fVar4 = (float)FUN_1400c6940(DAT_14039ca34,pfVar1[2] - DAT_14039ca44);

  uVar3 = DAT_14030338c;

  lVar2 = *(longlong *)(param_1 + 0x78);

  *(float *)(param_2 + 5) = fVar4 + *pfVar1;

  fVar4 = *(float *)(lVar2 + 4);

  fVar5 = (float)FUN_1400c6940(DAT_14039ca34,uVar3);

  *(float *)((longlong)param_2 + 0x2c) = fVar5 + fVar4;

  FUN_14003e600(param_1 + 0xb8,&local_res10);

  if (param_3 == '\0') {

    (**(code **)(*param_2 + 8))(param_2,0);

  }

  return;

}




