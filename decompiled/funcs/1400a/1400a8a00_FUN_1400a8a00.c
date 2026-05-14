// Address: 0x1400a8a00
// Ghidra name: FUN_1400a8a00
// ============ 0x1400a8a00 FUN_1400a8a00 (size=99) ============


undefined4 FUN_1400a8a00(longlong param_1)



{

  undefined4 uVar1;

  int iVar2;

  

  if (*(int *)(param_1 + 0x24) < 1) {

    return 1;

  }

  iVar2 = *(int *)(param_1 + 0x24) + -1;

  *(int *)(param_1 + 0x24) = iVar2;

  *(float *)(param_1 + 0x28) = *(float *)(param_1 + 0x1c) + *(float *)(param_1 + 0x28);

  *(float *)(param_1 + 0x2c) = *(float *)(param_1 + 0x20) + *(float *)(param_1 + 0x2c);

  uVar1 = 0xffffffff;

  if (0.0 < *(float *)(param_1 + 0x1c)) {

    uVar1 = 1;

  }

  *(undefined4 *)(param_1 + 0x38) = uVar1;

  if (iVar2 == 0) {

    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x68);

    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x6c);

    return 1;

  }

  return 0;

}




