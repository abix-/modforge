// Address: 0x1400b6820
// Ghidra name: FUN_1400b6820
// ============ 0x1400b6820 FUN_1400b6820 (size=101) ============


void FUN_1400b6820(longlong param_1,float param_2,float param_3)



{

  float fVar1;

  float local_res8;

  float local_resc;

  

  fVar1 = *(float *)(param_1 + 0x124);

  local_resc = (param_3 + *(float *)(param_1 + 0x128)) - *(float *)(param_1 + 0x130);

  if (*(char *)(param_1 + 0x1a) != '\0') {

    local_res8 = (param_2 - fVar1) + *(float *)(param_1 + 300);

    FUN_1400b6610(fVar1,&local_res8);

    return;

  }

  local_res8 = (fVar1 + param_2) - *(float *)(param_1 + 300);

  FUN_1400b6610(local_res8,&local_res8);

  return;

}




