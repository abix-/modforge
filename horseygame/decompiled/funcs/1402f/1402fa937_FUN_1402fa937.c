// Address: 0x1402fa937
// Ghidra name: FUN_1402fa937
// ============ 0x1402fa937 FUN_1402fa937 (size=44) ============


void FUN_1402fa937(undefined8 param_1,longlong param_2)



{

  if ((*(uint *)(param_2 + 0xf0) & 2) != 0) {

    *(uint *)(param_2 + 0xf0) = *(uint *)(param_2 + 0xf0) & 0xfffffffd;

    FUN_140027900(param_2 + 0x50);

  }

  return;

}




