// Address: 0x1402fa90b
// Ghidra name: FUN_1402fa90b
// ============ 0x1402fa90b FUN_1402fa90b (size=44) ============


void FUN_1402fa90b(undefined8 param_1,longlong param_2)



{

  if ((*(uint *)(param_2 + 0xf0) & 1) != 0) {

    *(uint *)(param_2 + 0xf0) = *(uint *)(param_2 + 0xf0) & 0xfffffffe;

    FUN_140027900(param_2 + 0x70);

  }

  return;

}




