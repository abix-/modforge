// Address: 0x1400fb8c0
// Ghidra name: FUN_1400fb8c0
// ============ 0x1400fb8c0 FUN_1400fb8c0 (size=109) ============


void FUN_1400fb8c0(longlong param_1,undefined8 param_2)



{

  undefined4 local_res8;

  undefined4 uStackX_c;

  

  if (*(int *)(param_1 + 0x90) != -1) {

    FUN_140040ea0();

    *(undefined4 *)(param_1 + 0x90) = 0xffffffff;

  }

  FUN_1400a89f0(param_1);

  local_res8 = (float)param_2;

  uStackX_c = (float)((ulonglong)param_2 >> 0x20);

  local_res8 = local_res8 + DAT_140303398;

  uStackX_c = uStackX_c + DAT_140303390;

  *(undefined4 *)(param_1 + 0x38) = 1;

  *(undefined4 *)(param_1 + 0x98) = 0;

  *(float *)(param_1 + 0x28) = local_res8;

  *(float *)(param_1 + 0x2c) = uStackX_c;

  return;

}




