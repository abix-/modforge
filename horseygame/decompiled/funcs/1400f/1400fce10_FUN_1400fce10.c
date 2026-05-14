// Address: 0x1400fce10
// Ghidra name: FUN_1400fce10
// ============ 0x1400fce10 FUN_1400fce10 (size=83) ============


undefined8 * FUN_1400fce10(undefined8 *param_1,ulonglong param_2)



{

  *param_1 = &PTR_FUN_140313130;

  if (*(int *)(param_1 + 0x12) != -1) {

    FUN_140040ea0();

  }

  FUN_1400a8730(param_1);

  if ((param_2 & 1) != 0) {

    FUN_1402c7088(param_1,0xb0);

  }

  return param_1;

}




