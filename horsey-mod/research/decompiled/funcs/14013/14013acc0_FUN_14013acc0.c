// Address: 0x14013acc0
// Ghidra name: FUN_14013acc0
// ============ 0x14013acc0 FUN_14013acc0 (size=42) ============


void FUN_14013acc0(longlong *param_1,longlong param_2)



{

  *(longlong *)(param_2 + 8) = param_1[1];

  *(undefined8 *)(param_2 + 0x10) = 0;

  if (param_1[1] != 0) {

    *(longlong *)(param_1[1] + 0x10) = param_2;

    param_1[1] = param_2;

    return;

  }

  *param_1 = param_2;

  param_1[1] = param_2;

  return;

}




