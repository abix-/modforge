// Address: 0x1401798b0
// Ghidra name: FUN_1401798b0
// ============ 0x1401798b0 FUN_1401798b0 (size=70) ============


void FUN_1401798b0(longlong param_1)



{

  DWORD DVar1;

  

  DVar1 = GetCurrentThreadId();

  if (*(DWORD *)(param_1 + 0xc) == DVar1) {

    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;

    return;

  }

  (*DAT_1403fc540)(param_1);

  *(DWORD *)(param_1 + 0xc) = DVar1;

  *(undefined4 *)(param_1 + 8) = 1;

  return;

}




