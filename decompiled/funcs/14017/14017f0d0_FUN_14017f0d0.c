// Address: 0x14017f0d0
// Ghidra name: FUN_14017f0d0
// ============ 0x14017f0d0 FUN_14017f0d0 (size=28) ============


void FUN_14017f0d0(longlong param_1)



{

  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;

  if (*(int *)(param_1 + 4) == 1) {

    *(longlong *)(param_1 + 0x28) = DAT_1403fc670;

    DAT_1403fc670 = param_1;

  }

  return;

}




