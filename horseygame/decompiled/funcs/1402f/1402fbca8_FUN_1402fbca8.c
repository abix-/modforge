// Address: 0x1402fbca8
// Ghidra name: FUN_1402fbca8
// ============ 0x1402fbca8 FUN_1402fbca8 (size=44) ============


void FUN_1402fbca8(undefined8 param_1,longlong param_2)



{

  if ((*(uint *)(param_2 + 0xf0) & 1) != 0) {

    *(uint *)(param_2 + 0xf0) = *(uint *)(param_2 + 0xf0) & 0xfffffffe;

    FUN_140027900(param_2 + 0x60);

  }

  return;

}




