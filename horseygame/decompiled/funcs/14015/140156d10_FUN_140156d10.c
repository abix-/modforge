// Address: 0x140156d10
// Ghidra name: FUN_140156d10
// ============ 0x140156d10 FUN_140156d10 (size=197) ============


void FUN_140156d10(longlong param_1)



{

  float fVar1;

  float fVar2;

  int local_res8 [2];

  int local_res10 [2];

  

  local_res8[0] = 0;

  local_res10[0] = 0;

  if (*(longlong *)(param_1 + 0x118) != 0) {

    FUN_14016ed40(*(longlong *)(param_1 + 0x118),local_res8,local_res10);

  }

  FUN_14014e850(param_1,param_1 + 0x140,param_1 + 0x144);

  fVar2 = DAT_14039ca44;

  fVar1 = DAT_14039ca44;

  if ((0 < local_res8[0]) && (0 < local_res10[0])) {

    fVar2 = (float)*(int *)(param_1 + 0x140) / (float)local_res8[0];

    fVar1 = (float)*(int *)(param_1 + 0x144) / (float)local_res10[0];

  }

  *(float *)(param_1 + 0x1d8) = fVar2;

  *(float *)(param_1 + 0x1dc) = fVar1;

  FUN_140156e80(param_1,param_1 + 0x140);

  return;

}




