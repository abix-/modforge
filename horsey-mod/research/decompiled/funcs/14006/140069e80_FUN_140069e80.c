// Address: 0x140069e80
// Ghidra name: FUN_140069e80
// ============ 0x140069e80 FUN_140069e80 (size=83) ============


undefined8 * FUN_140069e80(undefined8 *param_1,ulonglong param_2)



{

  *param_1 = &PTR_FUN_140309998;

  if (*(int *)(param_1 + 0x4f) != -1) {

    FUN_140040ea0();

  }

  FUN_1400c97f0(param_1);

  if ((param_2 & 1) != 0) {

    FUN_1402c7088(param_1,0x288);

  }

  return param_1;

}




