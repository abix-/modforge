// Address: 0x1400a8750
// Ghidra name: FUN_1400a8750
// ============ 0x1400a8750 FUN_1400a8750 (size=45) ============


undefined1 FUN_1400a8750(longlong param_1,float param_2,float param_3)



{

  float fVar1;

  

  fVar1 = param_3 * DAT_1403033ac + DAT_140303fd0;

  *(float *)(param_1 + 0x28) = param_2 * DAT_1403033ac + DAT_140303fd0;

  *(float *)(param_1 + 0x2c) = fVar1;

  return 1;

}




