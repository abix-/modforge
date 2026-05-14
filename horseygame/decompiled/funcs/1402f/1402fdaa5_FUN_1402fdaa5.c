// Address: 0x1402fdaa5
// Ghidra name: FUN_1402fdaa5
// ============ 0x1402fdaa5 FUN_1402fdaa5 (size=44) ============


void FUN_1402fdaa5(undefined8 param_1,longlong param_2)



{

  if ((*(uint *)(param_2 + 0xf0) & 2) != 0) {

    *(uint *)(param_2 + 0xf0) = *(uint *)(param_2 + 0xf0) & 0xfffffffd;

    FUN_140027900(param_2 + 0x30);

  }

  return;

}




