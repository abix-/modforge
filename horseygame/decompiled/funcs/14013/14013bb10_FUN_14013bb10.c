// Address: 0x14013bb10
// Ghidra name: FUN_14013bb10
// ============ 0x14013bb10 FUN_14013bb10 (size=92) ============


void FUN_14013bb10(longlong *param_1,longlong param_2)



{

  longlong lVar1;

  

  if (*param_1 == param_2) {

    *param_1 = *(longlong *)(param_2 + 0x10);

  }

  if (param_1[1] == param_2) {

    param_1[1] = *(longlong *)(param_2 + 8);

  }

  if (*(longlong *)(param_2 + 8) != 0) {

    *(undefined8 *)(*(longlong *)(param_2 + 8) + 0x10) = *(undefined8 *)(param_2 + 0x10);

  }

  lVar1 = *(longlong *)(param_2 + 0x10);

  if (lVar1 != 0) {

    *(undefined8 *)(lVar1 + 8) = *(undefined8 *)(param_2 + 8);

    *(longlong *)(param_2 + 0x10) = 0;

    *(undefined8 *)(param_2 + 8) = 0;

    return;

  }

  *(undefined8 *)(param_2 + 0x10) = 0;

  *(undefined8 *)(param_2 + 8) = 0;

  return;

}




