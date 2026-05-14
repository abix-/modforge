// Address: 0x1400bc560
// Ghidra name: FUN_1400bc560
// ============ 0x1400bc560 FUN_1400bc560 (size=16) ============


void FUN_1400bc560(longlong param_1,int param_2)



{

  if (*(int *)(param_1 + 0xc) != param_2) {

    *(int *)(param_1 + 0xc) = param_2;

    *(undefined4 *)(param_1 + 0x10) = 0;

  }

  return;

}




